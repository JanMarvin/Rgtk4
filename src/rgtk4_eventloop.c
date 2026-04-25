// src/rgtk4_eventloop.c - GTK4/R event loop integration
#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

#ifndef G_OS_WIN32
#include <R_ext/eventloop.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#endif

#ifdef __APPLE__
#include <objc/objc.h>
#include <objc/runtime.h>
#include <objc/message.h>
#include <CoreFoundation/CoreFoundation.h>

static void _rgtk_macos_set_policy(long policy) {
  Class nsapp_class = objc_getClass("NSApplication");
  SEL shared_app_sel = sel_registerName("sharedApplication");
  SEL set_policy_sel = sel_registerName("setActivationPolicy:");

  id (*sharedAppFn)(Class, SEL) = (id (*)(Class, SEL))objc_msgSend;
  id app = sharedAppFn(nsapp_class, shared_app_sel);

  void (*setPolicyFn)(id, SEL, long) = (void (*)(id, SEL, long))objc_msgSend;
  setPolicyFn(app, set_policy_sel, policy);
}

static void _rgtk_macos_activate(void) {
  Class nsapp_class = objc_getClass("NSApplication");
  SEL shared_app_sel = sel_registerName("sharedApplication");
  SEL activate_sel = sel_registerName("activateIgnoringOtherApps:");

  id (*sharedAppFn)(Class, SEL) = (id (*)(Class, SEL))objc_msgSend;
  id app = sharedAppFn(nsapp_class, shared_app_sel);

  void (*activateFn)(id, SEL, bool) = (void (*)(id, SEL, bool))objc_msgSend;
  activateFn(app, activate_sel, true);
}

static void _rgtk_macos_finish_launching(void) {
  Class nsapp_class = objc_getClass("NSApplication");
  SEL shared_app_sel = sel_registerName("sharedApplication");
  SEL finish_sel = sel_registerName("finishLaunching");

  id (*sharedAppFn)(Class, SEL) = (id (*)(Class, SEL))objc_msgSend;
  id app = sharedAppFn(nsapp_class, shared_app_sel);

  void (*finishFn)(id, SEL) = (void (*)(id, SEL))objc_msgSend;
  finishFn(app, finish_sel);
}

// Drain pending AppKit / CFRunLoop sources. GLib's main context iteration on
// macOS does not pump these, so window-server events (snap menu, dock updates,
// activation transitions) need this to be serviced.
static void _rgtk_macos_pump_cfrunloop(void) {
  while (CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.0, true)
           == kCFRunLoopRunHandledSource) {
  }
}

static bool _rgtk_macos_set_app_icon(const char* icon_path) {
  Class nsimage_class = objc_getClass("NSImage");
  Class nsapp_class = objc_getClass("NSApplication");
  Class nsstring_class = objc_getClass("NSString");

  SEL string_with_utf8_sel = sel_registerName("stringWithUTF8String:");
  SEL alloc_sel = sel_registerName("alloc");
  SEL init_with_path_sel = sel_registerName("initWithContentsOfFile:");
  SEL shared_app_sel = sel_registerName("sharedApplication");
  SEL set_icon_sel = sel_registerName("setApplicationIconImage:");

  id (*stringFn)(Class, SEL, const char*) = (id (*)(Class, SEL, const char*))objc_msgSend;
  id path_string = stringFn(nsstring_class, string_with_utf8_sel, icon_path);

  id (*allocFn)(Class, SEL) = (id (*)(Class, SEL))objc_msgSend;
  id image = allocFn(nsimage_class, alloc_sel);

  id (*initFn)(id, SEL, id) = (id (*)(id, SEL, id))objc_msgSend;
  image = initFn(image, init_with_path_sel, path_string);

  if (!image) return false;

  id (*sharedAppFn)(Class, SEL) = (id (*)(Class, SEL))objc_msgSend;
  id app = sharedAppFn(nsapp_class, shared_app_sel);

  void (*setIconFn)(id, SEL, id) = (void (*)(id, SEL, id))objc_msgSend;
  setIconFn(app, set_icon_sel, image);

  // Force the dock to actually pick up the change. Without pumping the
  // CFRunLoop the icon update may not appear until the next event arrives.
  _rgtk_macos_pump_cfrunloop();
  return true;
}
#endif

static inline void* get_ptr_internal(SEXP s, const char* func) {
  if (s == R_NilValue) return NULL;

  if (TYPEOF(s) != EXTPTRSXP) {
    Rf_error("%s: expected external pointer, got %s", func, Rf_type2char(TYPEOF(s)));
  }

  return R_ExternalPtrAddr(s);
}

#define get_ptr(s) get_ptr_internal(s, __func__)

#ifndef G_OS_WIN32
// Unix/macOS event loop implementation
static int _rgtk_ifd = -1, _rgtk_ofd = -1;
static InputHandler *_rgtk_handler = NULL;
static gboolean _rgtk_running = FALSE;
static pthread_t _rgtk_thread;
static GMainLoop *_rgtk_loop = NULL;

#ifdef __APPLE__
// Window counting for dock icon management (macOS only)
static int _rgtk_window_count = 0;
static pthread_mutex_t _rgtk_window_mutex = PTHREAD_MUTEX_INITIALIZER;
#endif

// GTK event handler called from R input handler
static void _rgtk_input_cb(void *userData) {
  (void)userData;
  char buf[64];
  if (read(_rgtk_ifd, buf, sizeof(buf)) < 0) return;

  // Process all pending GTK events
  GMainContext *ctx = g_main_context_default();
  while (g_main_context_iteration(ctx, FALSE));

#ifdef __APPLE__
  _rgtk_macos_pump_cfrunloop();
#endif
}

// Timer callback running in separate thread - pokes the pipe to wake R
static gboolean _rgtk_timer_cb(gpointer data) {
  (void)data;
  if (_rgtk_ofd != -1) {
    char b = 0;
    if (write(_rgtk_ofd, &b, 1) < 0) { }
  }
  return G_SOURCE_CONTINUE;
}

// Thread function that runs the timer
static void *_rgtk_thread_func(void *data) {
  (void)data;
  GMainContext *ctx = g_main_context_new();
  _rgtk_loop = g_main_loop_new(ctx, FALSE);

  // ~120 Hz: smooth UI without measurable idle CPU on a sleeping context
  GSource *timer = g_timeout_source_new(8);
  g_source_set_callback(timer, _rgtk_timer_cb, NULL, NULL);
  g_source_attach(timer, ctx);

  g_main_loop_run(_rgtk_loop);

  g_source_destroy(timer);
  g_source_unref(timer);
  g_main_loop_unref(_rgtk_loop);
  g_main_context_unref(ctx);

  return NULL;
}
#endif  // G_OS_WIN32

// Event loop functions - defined on all platforms
SEXP R_gtk_start_event_loop(void) {
#ifdef G_OS_WIN32
  // GTK4 uses CSD by default, which omits WS_THICKFRAME on the native
  // window and breaks aero snap. Force server-side decorations so the
  // OS draws the titlebar. Must be set before gtk_init() to take effect;
  // setting here is a fallback for users who haven't set it externally.
  if (!getenv("GTK_CSD")) {
    _putenv_s("GTK_CSD", "0");
  }
#endif

#ifndef G_OS_WIN32
  if (_rgtk_running) return Rf_ScalarLogical(TRUE);

  int fds[2];
  if (pipe(fds) != 0) {
    Rf_error("RGtk4: pipe() failed");
    return Rf_ScalarLogical(FALSE);
  }

  _rgtk_ifd = fds[0];
  _rgtk_ofd = fds[1];

  // Set non-blocking
  fcntl(_rgtk_ifd, F_SETFL, O_NONBLOCK);
  fcntl(_rgtk_ofd, F_SETFL, O_NONBLOCK);

  // Register R input handler
  _rgtk_handler = addInputHandler(R_InputHandlers, _rgtk_ifd, _rgtk_input_cb, 0);

  // Start timer thread
  pthread_create(&_rgtk_thread, NULL, _rgtk_thread_func, NULL);

  _rgtk_running = TRUE;

#ifdef __APPLE__
  // Start as accessory (no dock icon until window is shown). NSApp must
  // be finished launching before AppKit will deliver window-management
  // events (green-button tile menu, Stage Manager, dock updates).
  _rgtk_macos_set_policy(1);  // NSApplicationActivationPolicyAccessory
  _rgtk_macos_finish_launching();
  _rgtk_macos_activate();
  _rgtk_macos_pump_cfrunloop();
#endif

  return Rf_ScalarLogical(TRUE);
#else
  // Windows: Process GTK events in the main context
  // We can't use R's input handlers on Windows, so just process pending events
  GMainContext *ctx = g_main_context_default();
  while (g_main_context_iteration(ctx, FALSE));

  return Rf_ScalarLogical(TRUE);
#endif
}

SEXP R_gtk_stop_event_loop(void) {
#ifndef G_OS_WIN32
  if (!_rgtk_running) return R_NilValue;

  // Stop the timer loop
  if (_rgtk_loop) {
    g_main_loop_quit(_rgtk_loop);
    pthread_join(_rgtk_thread, NULL);
  }

  // Remove input handler
  if (_rgtk_handler) {
    removeInputHandler(&R_InputHandlers, _rgtk_handler);
    _rgtk_handler = NULL;
  }

  // Close pipes
  if (_rgtk_ifd != -1) {
    if (close(_rgtk_ifd) < 0) {
      REprintf("RGtk4: Warning - failed to close input fd\n");
    }
  }
  if (_rgtk_ofd != -1) {
    if (close(_rgtk_ofd) < 0) {
      REprintf("RGtk4: Warning - failed to close output fd\n");
    }
  }
  _rgtk_ifd = _rgtk_ofd = -1;

  _rgtk_running = FALSE;
  return R_NilValue;
#else
  // Windows: Process any remaining events
  GMainContext *ctx = g_main_context_default();
  while (g_main_context_pending(ctx)) {
    g_main_context_iteration(ctx, FALSE);
  }
  return R_NilValue;
#endif
}

SEXP R_gtk_force_foreground(void) {
#ifdef __APPLE__
  // Switch to regular mode (show dock icon) and activate
  _rgtk_macos_set_policy(0);  // NSApplicationActivationPolicyRegular
  _rgtk_macos_activate();
  _rgtk_macos_pump_cfrunloop();
#elif defined(G_OS_WIN32)
  // On Windows, bring all GTK windows to foreground
  GListModel *toplevels = gtk_window_get_toplevels();
  guint n = g_list_model_get_n_items(toplevels);

  for (guint i = 0; i < n; i++) {
    GtkWindow *window = g_list_model_get_item(toplevels, i);
    if (window) {
      gtk_window_present(window);
      g_object_unref(window);
    }
  }
#endif
  return R_NilValue;
}

SEXP R_gtk_hide_from_dock(void) {
#ifdef __APPLE__
  // Switch to accessory mode (hide dock icon)
  _rgtk_macos_set_policy(1);  // NSApplicationActivationPolicyAccessory
#endif
  return R_NilValue;
}

static void _rgtk_window_untrack_cb(gpointer window, gpointer user_data) __attribute__((unused));
static void _rgtk_window_untrack_cb(gpointer window, gpointer user_data) {
#if defined(__APPLE__) && !defined(G_OS_WIN32)
  (void)window;
  (void)user_data;

  pthread_mutex_lock(&_rgtk_window_mutex);
  _rgtk_window_count--;
  int count = _rgtk_window_count;
  pthread_mutex_unlock(&_rgtk_window_mutex);

  if (count == 0) {
    _rgtk_macos_set_policy(1);
  }
#else
  (void)window;
  (void)user_data;
#endif
}

void R_gtk_window_untrack(SEXP s_window) {
#if defined(__APPLE__) && !defined(G_OS_WIN32)
  GtkWindow *window = (GtkWindow*)get_ptr(s_window);
  if (!window) return;

  _rgtk_window_untrack_cb(window, NULL);
#else
  (void)s_window;
#endif
}

SEXP R_gtk_window_track(SEXP s_window) {
#if defined(__APPLE__) && !defined(G_OS_WIN32)
  GtkWindow *window = (GtkWindow*)get_ptr(s_window);
  if (!window) {
    Rf_error("Invalid GtkWindow pointer");
  }

  pthread_mutex_lock(&_rgtk_window_mutex);
  _rgtk_window_count++;
  int count = _rgtk_window_count;
  pthread_mutex_unlock(&_rgtk_window_mutex);

  if (count == 1) {
    _rgtk_macos_set_policy(0);
    _rgtk_macos_activate();
    _rgtk_macos_pump_cfrunloop();
  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
  g_signal_connect(window, "unrealize",
                   G_CALLBACK(_rgtk_window_untrack_cb),
                   NULL);
#pragma GCC diagnostic pop
#else
  (void)s_window;
#endif
  return R_NilValue;
}

// Process pending GTK events (useful on Windows)
SEXP R_gtk_main_iteration(void) {
  GMainContext *ctx = g_main_context_default();

  // Always iterate to allow GTK to process paint events, timers, etc.
  gboolean processed = g_main_context_iteration(ctx, FALSE);

#ifdef __APPLE__
  _rgtk_macos_pump_cfrunloop();
#endif

  return Rf_ScalarLogical(processed);
}

// Process all pending GTK events (useful on Windows)
SEXP R_gtk_main_iteration_do(SEXP s_blocking) {
  gboolean blocking = (gboolean)Rf_asLogical(s_blocking);
  GMainContext *ctx = g_main_context_default();

  int count = 0;
  while (g_main_context_iteration(ctx, blocking && count == 0)) {
    count++;
    if (!blocking && count > 100) break; // Safety limit
  }

#ifdef __APPLE__
  _rgtk_macos_pump_cfrunloop();
#endif

  return Rf_ScalarInteger(count);
}

SEXP R_macos_set_app_icon(SEXP s_path) {
#ifdef __APPLE__
  if (TYPEOF(s_path) != STRSXP || Rf_length(s_path) != 1) {
    Rf_error("icon_path must be a single string");
  }
  const char* path = CHAR(STRING_ELT(s_path, 0));
  bool ok = _rgtk_macos_set_app_icon(path);
  return Rf_ScalarLogical(ok);
#else
  (void)s_path;
  return Rf_ScalarLogical(FALSE);
#endif
}
