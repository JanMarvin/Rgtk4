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

#ifdef G_OS_WIN32
#include <windows.h>
#include <gdk/win32/gdkwin32.h>
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
// macOS does not pump these, so window-server events need this to be serviced.
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
static int _rgtk_ifd = -1, _rgtk_ofd = -1;
static InputHandler *_rgtk_handler = NULL;
static gboolean _rgtk_running = FALSE;
static gboolean _rgtk_thread_started = FALSE;
static pthread_t _rgtk_thread;
static GMainLoop *_rgtk_loop = NULL;

#ifdef __APPLE__
static int _rgtk_window_count = 0;
static pthread_mutex_t _rgtk_window_mutex = PTHREAD_MUTEX_INITIALIZER;
#endif

static void _rgtk_input_cb(void *userData) {
  (void)userData;
  char buf[64];
  while (read(_rgtk_ifd, buf, sizeof(buf)) > 0) { }

  GMainContext *ctx = g_main_context_default();
  while (g_main_context_iteration(ctx, FALSE)) { }

#ifdef __APPLE__
  _rgtk_macos_pump_cfrunloop();
#endif
}

// Runs on the timer thread — must NOT touch the default GMainContext or any
// GDK/AppKit state, both of which are main-thread-only on macOS. We just poke
// the pipe; the main thread decides whether there's work via its own
// iteration in _rgtk_input_cb.
static gboolean _rgtk_timer_cb(gpointer data) {
  (void)data;
  if (_rgtk_ofd != -1) {
    char b = 0;
    ssize_t n = write(_rgtk_ofd, &b, 1);
    (void)n;
  }
  return G_SOURCE_CONTINUE;
}

static void *_rgtk_thread_func(void *data) {
  (void)data;
  GMainContext *ctx = g_main_context_new();
  _rgtk_loop = g_main_loop_new(ctx, FALSE);

  GSource *timer = g_timeout_source_new(8);
  g_source_set_callback(timer, _rgtk_timer_cb, NULL, NULL);
  g_source_attach(timer, ctx);

  g_main_loop_run(_rgtk_loop);

  g_source_destroy(timer);
  g_source_unref(timer);
  g_main_loop_unref(_rgtk_loop);
  _rgtk_loop = NULL;
  g_main_context_unref(ctx);

  return NULL;
}
#endif

SEXP R_gtk_start_event_loop(void) {
#ifdef G_OS_WIN32
  if (!getenv("GTK_CSD")) {
    _putenv_s("GTK_CSD", "0");
  }
  // No background event-loop integration on Windows; users should
  // drive iteration via R_gtk_main_iteration / later::later().
  GMainContext *ctx = g_main_context_default();
  while (g_main_context_iteration(ctx, FALSE)) { }
  return Rf_ScalarLogical(TRUE);
#else
  if (_rgtk_running) return Rf_ScalarLogical(TRUE);

  int fds[2];
  if (pipe(fds) != 0) {
    Rf_error("RGtk4: pipe() failed");
  }

  _rgtk_ifd = fds[0];
  _rgtk_ofd = fds[1];

  if (fcntl(_rgtk_ifd, F_SETFL, O_NONBLOCK) != 0 ||
      fcntl(_rgtk_ofd, F_SETFL, O_NONBLOCK) != 0) {
    close(_rgtk_ifd);
    close(_rgtk_ofd);
    _rgtk_ifd = _rgtk_ofd = -1;
    Rf_error("RGtk4: fcntl() failed");
  }

  _rgtk_handler = addInputHandler(R_InputHandlers, _rgtk_ifd, _rgtk_input_cb, 0);
  if (!_rgtk_handler) {
    close(_rgtk_ifd);
    close(_rgtk_ofd);
    _rgtk_ifd = _rgtk_ofd = -1;
    Rf_error("RGtk4: addInputHandler() failed");
  }

  int rc = pthread_create(&_rgtk_thread, NULL, _rgtk_thread_func, NULL);
  if (rc != 0) {
    removeInputHandler(&R_InputHandlers, _rgtk_handler);
    _rgtk_handler = NULL;
    close(_rgtk_ifd);
    close(_rgtk_ofd);
    _rgtk_ifd = _rgtk_ofd = -1;
    Rf_error("RGtk4: pthread_create() failed: %d", rc);
  }
  _rgtk_thread_started = TRUE;
  _rgtk_running = TRUE;

#ifdef __APPLE__
  _rgtk_macos_set_policy(1);
  _rgtk_macos_finish_launching();
  _rgtk_macos_activate();
  _rgtk_macos_pump_cfrunloop();
#endif

  return Rf_ScalarLogical(TRUE);
#endif
}

SEXP R_gtk_stop_event_loop(void) {
#ifndef G_OS_WIN32
  if (!_rgtk_running) return R_NilValue;

  if (_rgtk_loop) {
    g_main_loop_quit(_rgtk_loop);
  }
  if (_rgtk_thread_started) {
    pthread_join(_rgtk_thread, NULL);
    _rgtk_thread_started = FALSE;
  }

  if (_rgtk_handler) {
    removeInputHandler(&R_InputHandlers, _rgtk_handler);
    _rgtk_handler = NULL;
  }

  if (_rgtk_ifd != -1 && close(_rgtk_ifd) < 0) {
    REprintf("RGtk4: Warning - failed to close input fd\n");
  }
  if (_rgtk_ofd != -1 && close(_rgtk_ofd) < 0) {
    REprintf("RGtk4: Warning - failed to close output fd\n");
  }
  _rgtk_ifd = _rgtk_ofd = -1;

  _rgtk_running = FALSE;
  return R_NilValue;
#else
  GMainContext *ctx = g_main_context_default();
  while (g_main_context_pending(ctx)) {
    g_main_context_iteration(ctx, FALSE);
  }
  return R_NilValue;
#endif
}

SEXP R_gtk_force_foreground(void) {
#ifdef __APPLE__
  _rgtk_macos_set_policy(0);
  _rgtk_macos_activate();
  _rgtk_macos_pump_cfrunloop();
#elif defined(G_OS_WIN32)
  GListModel *toplevels = gtk_window_get_toplevels();
  guint n = g_list_model_get_n_items(toplevels);

  for (guint i = 0; i < n; i++) {
    GtkWindow *window = g_list_model_get_item(toplevels, i);
    if (window) {
      gtk_window_present(window);

      GdkSurface *surface = gtk_native_get_surface(GTK_NATIVE(window));
      if (surface) {
        HWND hwnd = (HWND)gdk_win32_surface_get_handle(surface);
        if (hwnd) {
          HWND fg = GetForegroundWindow();
          DWORD fg_tid = fg ? GetWindowThreadProcessId(fg, NULL) : 0;
          DWORD my_tid = GetCurrentThreadId();

          if (fg_tid && fg_tid != my_tid) {
            AttachThreadInput(my_tid, fg_tid, TRUE);
            SetForegroundWindow(hwnd);
            BringWindowToTop(hwnd);
            SetFocus(hwnd);
            AttachThreadInput(my_tid, fg_tid, FALSE);
          } else {
            SetForegroundWindow(hwnd);
            BringWindowToTop(hwnd);
            SetFocus(hwnd);
          }

          if (IsIconic(hwnd)) {
            ShowWindow(hwnd, SW_RESTORE);
          }
        }
      }

      g_object_unref(window);
    }
  }
#endif
  return R_NilValue;
}

SEXP R_gtk_hide_from_dock(void) {
#ifdef __APPLE__
  _rgtk_macos_set_policy(1);
#endif
  return R_NilValue;
}

#if defined(__APPLE__) && !defined(G_OS_WIN32)
// Matches the unrealize signal signature: (GtkWidget *self, gpointer user_data)
static void _rgtk_window_untrack_cb(GtkWidget *widget, gpointer user_data) {
  (void)widget;
  (void)user_data;

  pthread_mutex_lock(&_rgtk_window_mutex);
  _rgtk_window_count--;
  int count = _rgtk_window_count;
  pthread_mutex_unlock(&_rgtk_window_mutex);

  if (count == 0) {
    _rgtk_macos_set_policy(1);
  }
}
#endif

SEXP R_gtk_window_untrack(SEXP s_window) {
#if defined(__APPLE__) && !defined(G_OS_WIN32)
  GtkWindow *window = (GtkWindow*)get_ptr(s_window);
  if (!window) return R_NilValue;
  _rgtk_window_untrack_cb(GTK_WIDGET(window), NULL);
#else
  (void)s_window;
#endif
  return R_NilValue;
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

  g_signal_connect(window, "unrealize",
                   G_CALLBACK(_rgtk_window_untrack_cb), NULL);
#else
  (void)s_window;
#endif
  return R_NilValue;
}

SEXP R_gtk_main_iteration(void) {
  GMainContext *ctx = g_main_context_default();
  gboolean processed = g_main_context_iteration(ctx, FALSE);

#ifdef __APPLE__
  _rgtk_macos_pump_cfrunloop();
#endif

  return Rf_ScalarLogical(processed);
}

SEXP R_gtk_main_iteration_do(SEXP s_blocking) {
  gboolean blocking = (gboolean)Rf_asLogical(s_blocking);
  GMainContext *ctx = g_main_context_default();

  int count = 0;
  while (g_main_context_iteration(ctx, blocking && count == 0)) {
    count++;
    if (!blocking && count > 100) break;
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
