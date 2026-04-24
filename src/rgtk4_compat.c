// src/rgtk4_compat.c - GTK3-style compatibility helpers
#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <gtk/gtk.h>
#include <string.h>

// Safe pointer extraction helper (same as in other files)
static inline void* get_ptr_internal(SEXP s, const char* func) {
  if (s == R_NilValue) return NULL;

  if (TYPEOF(s) != EXTPTRSXP) {
    Rf_error("%s: expected external pointer, got %s", func, Rf_type2char(TYPEOF(s)));
  }

  return R_ExternalPtrAddr(s);
}

#define get_ptr(s) get_ptr_internal(s, __func__)

// ============================================================================
// Timeout and Idle Callbacks with R Functions
// ============================================================================

typedef struct {
  SEXP fun;
  guint source_id;
} RTimeoutClosure;

static gboolean _rgtk_timeout_callback(gpointer user_data) {
  RTimeoutClosure *rc = (RTimeoutClosure *)user_data;
  if (!rc || rc->fun == R_NilValue) return G_SOURCE_REMOVE;

  int error_occurred = 0;
  SEXP call = PROTECT(Rf_lang1(rc->fun));
  SEXP result = R_tryEval(call, R_GlobalEnv, &error_occurred);

  gboolean continue_running = TRUE;
  if (!error_occurred && result != R_NilValue) {
    continue_running = (gboolean)Rf_asLogical(result);
  }

  UNPROTECT(1);

  if (!continue_running) {
    R_ReleaseObject(rc->fun);
    g_free(rc);
  }

  return continue_running ? G_SOURCE_CONTINUE : G_SOURCE_REMOVE;
}

SEXP R_g_timeout_add(SEXP s_interval, SEXP s_fun) {
  if (TYPEOF(s_interval) != INTSXP && TYPEOF(s_interval) != REALSXP) {
    Rf_error("interval must be numeric");
  }

  if (!Rf_isFunction(s_fun)) {
    Rf_error("fun must be a function");
  }

  guint interval = (guint)Rf_asInteger(s_interval);

  RTimeoutClosure *rc = g_new0(RTimeoutClosure, 1);
  rc->fun = s_fun;

  R_PreserveObject(s_fun);

  rc->source_id = g_timeout_add(interval, _rgtk_timeout_callback, rc);

  return Rf_ScalarInteger((int)rc->source_id);
}

SEXP R_g_idle_add(SEXP s_fun) {
  if (!Rf_isFunction(s_fun)) {
    Rf_error("fun must be a function");
  }

  RTimeoutClosure *rc = g_new0(RTimeoutClosure, 1);
  rc->fun = s_fun;

  R_PreserveObject(s_fun);

  rc->source_id = g_idle_add(_rgtk_timeout_callback, rc);

  return Rf_ScalarInteger((int)rc->source_id);
}

// ============================================================================
// Blocking Dialog Execution (GTK3-style)
// ============================================================================

typedef struct {
  gint *response_ptr;
} DialogResponseData;

static void _rgtk_dialog_response_cb(GtkDialog *dialog, gint response, gpointer user_data) {
  DialogResponseData *data = (DialogResponseData *)user_data;
  *(data->response_ptr) = response;
}

SEXP R_gtk_dialog_run(SEXP s_dialog) {
  GtkDialog *dialog = (GtkDialog*)get_ptr(s_dialog);
  if (!dialog || !GTK_IS_DIALOG(dialog)) {
    Rf_error("Invalid GtkDialog pointer");
  }

  gint response = GTK_RESPONSE_NONE;
  DialogResponseData data = { .response_ptr = &response };
  GMainLoop *loop = g_main_loop_new(NULL, FALSE);

  gulong quit_handler = g_signal_connect_swapped(dialog, "response",
                                                 G_CALLBACK(g_main_loop_quit), loop);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
  gulong response_handler = g_signal_connect(dialog, "response",
                                             G_CALLBACK(_rgtk_dialog_response_cb), &data);
#pragma GCC diagnostic pop

  gtk_window_present(GTK_WINDOW(dialog));

  g_main_loop_run(loop);

  g_signal_handler_disconnect(dialog, quit_handler);
  g_signal_handler_disconnect(dialog, response_handler);
  g_main_loop_unref(loop);

  return Rf_ScalarInteger(response);
}

// ============================================================================
// File Chooser Dialog with Blocking Run
// ============================================================================

SEXP R_gtk_file_chooser_dialog_run(SEXP s_parent, SEXP s_title, SEXP s_action) {
  GtkWindow *parent = NULL;
  if (s_parent != R_NilValue) {
    parent = (GtkWindow*)get_ptr(s_parent);
  }

  if (TYPEOF(s_title) != STRSXP || LENGTH(s_title) != 1) {
    Rf_error("title must be a single character string");
  }
  const char *title = CHAR(STRING_ELT(s_title, 0));

  GtkFileChooserAction action = (GtkFileChooserAction)Rf_asInteger(s_action);

  const char *accept_label = (action == GTK_FILE_CHOOSER_ACTION_SAVE) ?
  "_Save" : "_Open";

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  GtkWidget *dialog = gtk_file_chooser_dialog_new(
    title,
    parent,
    action,
    "_Cancel", GTK_RESPONSE_CANCEL,
    accept_label, GTK_RESPONSE_ACCEPT,
    NULL
  );
#pragma GCC diagnostic pop

  gtk_window_present(GTK_WINDOW(dialog));

  gint response = GTK_RESPONSE_NONE;
  DialogResponseData data = { .response_ptr = &response };
  GMainLoop *loop = g_main_loop_new(NULL, FALSE);

  gulong quit_handler = g_signal_connect_swapped(dialog, "response",
                                                 G_CALLBACK(g_main_loop_quit), loop);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
  gulong response_handler = g_signal_connect(dialog, "response",
                                             G_CALLBACK(_rgtk_dialog_response_cb), &data);
#pragma GCC diagnostic pop

  g_main_loop_run(loop);

  g_signal_handler_disconnect(dialog, quit_handler);
  g_signal_handler_disconnect(dialog, response_handler);
  g_main_loop_unref(loop);

  SEXP result = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP result_names = PROTECT(Rf_allocVector(STRSXP, 2));

  SET_VECTOR_ELT(result, 0, Rf_ScalarInteger(response));
  SET_STRING_ELT(result_names, 0, Rf_mkChar("response"));

  if (response == GTK_RESPONSE_ACCEPT) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    GFile *file = gtk_file_chooser_get_file(GTK_FILE_CHOOSER(dialog));
#pragma GCC diagnostic pop
    if (file) {
      char *path = g_file_get_path(file);
      SET_VECTOR_ELT(result, 1, path ? Rf_mkString(path) : R_NilValue);
      g_free(path);
      g_object_unref(file);
    } else {
      SET_VECTOR_ELT(result, 1, R_NilValue);
    }
  } else {
    SET_VECTOR_ELT(result, 1, R_NilValue);
  }
  SET_STRING_ELT(result_names, 1, Rf_mkChar("file"));

  Rf_setAttrib(result, R_NamesSymbol, result_names);

  gtk_window_destroy(GTK_WINDOW(dialog));

  UNPROTECT(2);
  return result;
}
