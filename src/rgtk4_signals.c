// src/rgtk4_signals.c - GTK signal connection for R callbacks
#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <gio/gio.h>
#include <gtk/gtk.h>
#include <string.h>

typedef struct { SEXP fun; } RClosure;

static inline void* get_ptr_internal(SEXP s, const char* func) {
  if (s == R_NilValue) return NULL;

  if (TYPEOF(s) != EXTPTRSXP) {
    Rf_error("%s: expected external pointer, got %s", func, Rf_type2char(TYPEOF(s)));
  }

  void* ptr = R_ExternalPtrAddr(s);
  if (!ptr) {
    Rf_error("%s: NULL pointer", func);
  }

  return ptr;
}

#define get_ptr(s) get_ptr_internal(s, __func__)

// GTK signal callbacks receive the widget as first parameter
static void _rgtk_r_callback(GtkWidget *widget, gpointer user_data) {
  RClosure *rc = (RClosure *)user_data;
  if (!rc || rc->fun == R_NilValue) return;

  // Create external pointer for the widget
  SEXP s_widget = PROTECT(R_MakeExternalPtr(widget, R_NilValue, R_NilValue));

  // Use R_tryEval instead of Rf_eval for safety
  int error_occurred = 0;
  SEXP call = PROTECT(Rf_lang2(rc->fun, s_widget));
  R_tryEval(call, R_GlobalEnv, &error_occurred);

  if (error_occurred) {
    REprintf("Error in GTK callback function\n");
  }

  UNPROTECT(2);
}

// Signal callback with two GObject arguments (for factory setup/bind signals)
static void _rgtk_r_callback_two_args(gpointer arg1, gpointer arg2, gpointer user_data) {
  RClosure *rc = (RClosure *)user_data;
  if (!rc || rc->fun == R_NilValue) return;

  SEXP s_arg1 = PROTECT(R_MakeExternalPtr(arg1, R_NilValue, R_NilValue));
  SEXP s_arg2 = PROTECT(R_MakeExternalPtr(arg2, R_NilValue, R_NilValue));

  int error_occurred = 0;
  SEXP call = PROTECT(Rf_lang3(rc->fun, s_arg1, s_arg2));
  R_tryEval(call, R_GlobalEnv, &error_occurred);

  if (error_occurred) {
    REprintf("Error in GTK two-arg callback function\n");
  }

  UNPROTECT(3);
}

// Signal callback with three arguments
static void _rgtk_r_callback_three_args(gpointer arg1, gpointer arg2, gpointer arg3, gpointer user_data) {
  RClosure *rc = (RClosure *)user_data;
  if (!rc || rc->fun == R_NilValue) return;

  SEXP s_arg1 = PROTECT(R_MakeExternalPtr(arg1, R_NilValue, R_NilValue));
  SEXP s_arg2 = PROTECT(R_MakeExternalPtr(arg2, R_NilValue, R_NilValue));
  SEXP s_arg3 = PROTECT(R_MakeExternalPtr(arg3, R_NilValue, R_NilValue));

  int error_occurred = 0;
  SEXP call = PROTECT(Rf_lang4(rc->fun, s_arg1, s_arg2, s_arg3));
  R_tryEval(call, R_GlobalEnv, &error_occurred);

  if (error_occurred) {
    REprintf("Error in GTK three-arg callback function\n");
  }

  UNPROTECT(4);
}

// Signal callback with four arguments
static void _rgtk_r_callback_four_args(gpointer arg1, gpointer arg2, gpointer arg3, gpointer arg4, gpointer user_data) {
  RClosure *rc = (RClosure *)user_data;
  if (!rc || rc->fun == R_NilValue) return;

  SEXP s_arg1 = PROTECT(R_MakeExternalPtr(arg1, R_NilValue, R_NilValue));
  SEXP s_arg2 = PROTECT(R_MakeExternalPtr(arg2, R_NilValue, R_NilValue));
  SEXP s_arg3 = PROTECT(R_MakeExternalPtr(arg3, R_NilValue, R_NilValue));
  SEXP s_arg4 = PROTECT(R_MakeExternalPtr(arg4, R_NilValue, R_NilValue));

  int error_occurred = 0;
  SEXP call = PROTECT(Rf_lang5(rc->fun, s_arg1, s_arg2, s_arg3, s_arg4));
  R_tryEval(call, R_GlobalEnv, &error_occurred);

  if (error_occurred) {
    REprintf("Error in GTK four-arg callback function\n");
  }

  UNPROTECT(5);
}

// Signal callback with five arguments
static void _rgtk_r_callback_five_args(gpointer arg1, gpointer arg2, gpointer arg3, gpointer arg4, gpointer arg5, gpointer user_data) {
  RClosure *rc = (RClosure *)user_data;
  if (!rc || rc->fun == R_NilValue) return;

  SEXP s_arg1 = PROTECT(R_MakeExternalPtr(arg1, R_NilValue, R_NilValue));
  SEXP s_arg2 = PROTECT(R_MakeExternalPtr(arg2, R_NilValue, R_NilValue));
  SEXP s_arg3 = PROTECT(R_MakeExternalPtr(arg3, R_NilValue, R_NilValue));
  SEXP s_arg4 = PROTECT(R_MakeExternalPtr(arg4, R_NilValue, R_NilValue));
  SEXP s_arg5 = PROTECT(R_MakeExternalPtr(arg5, R_NilValue, R_NilValue));

  int error_occurred = 0;
  SEXP call = PROTECT(Rf_lang6(rc->fun, s_arg1, s_arg2, s_arg3, s_arg4, s_arg5));
  R_tryEval(call, R_GlobalEnv, &error_occurred);

  if (error_occurred) {
    REprintf("Error in GTK five-arg callback function\n");
  }

  UNPROTECT(6);
}

// Signal callback that returns gboolean (for close-request, etc.)
static gboolean _rgtk_r_callback_boolean(GtkWidget *widget, gpointer user_data) {
  RClosure *rc = (RClosure *)user_data;
  if (!rc || rc->fun == R_NilValue) return FALSE;

  // Create external pointer for the widget
  SEXP s_widget = PROTECT(R_MakeExternalPtr(widget, R_NilValue, R_NilValue));

  // Use R_tryEval instead of Rf_eval for safety
  int error_occurred = 0;
  SEXP call = PROTECT(Rf_lang2(rc->fun, s_widget));
  SEXP result = R_tryEval(call, R_GlobalEnv, &error_occurred);

  gboolean ret = FALSE;
  if (!error_occurred && result != R_NilValue) {
    // Convert R result to boolean
    ret = (gboolean)Rf_asLogical(result);
  }

  UNPROTECT(2);
  return ret;
}

static void _rgtk_r_closure_free(gpointer user_data) {
  RClosure *rc = (RClosure *)user_data;
  if (rc && rc->fun != R_NilValue) {
    R_ReleaseObject(rc->fun);
  }
  g_free(rc);
}

// Callback for "response" signal (dialog, response_id)
static void _rgtk_r_callback_response(gpointer dialog, gint response_id, gpointer user_data) {
  RClosure *rc = (RClosure *)user_data;
  if (!rc || rc->fun == R_NilValue) return;

  // Create external pointer for the dialog
  SEXP s_dialog = PROTECT(R_MakeExternalPtr(dialog, R_NilValue, R_NilValue));
  SEXP s_response = PROTECT(Rf_ScalarInteger(response_id));

  // Call R function with 2 arguments: dialog, response_id
  int error_occurred = 0;
  SEXP call = PROTECT(Rf_lang3(rc->fun, s_dialog, s_response));
  R_tryEval(call, R_GlobalEnv, &error_occurred);

  if (error_occurred) {
    REprintf("Error in GTK response callback function\n");
  }

  UNPROTECT(3);
}

SEXP R_g_signal_connect_r(SEXP s_obj, SEXP s_signal, SEXP s_fun) {
  gpointer obj = get_ptr(s_obj);

  if (TYPEOF(s_signal) != STRSXP || LENGTH(s_signal) != 1) {
    Rf_error("signal must be a single character string");
  }
  const char *sig = CHAR(STRING_ELT(s_signal, 0));

  if (!Rf_isFunction(s_fun)) {
    Rf_error("fun must be a function");
  }

  // Query the signal to determine argument count
  guint signal_id = g_signal_lookup(sig, G_OBJECT_TYPE(obj));
  if (signal_id == 0) {
    Rf_error("Signal '%s' not found on object", sig);
  }

  GSignalQuery query;
  g_signal_query(signal_id, &query);

  RClosure *rc = g_new0(RClosure, 1);
  rc->fun = s_fun;
  R_PreserveObject(s_fun);

  gulong id;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
  // Dispatch based on number of parameters (excluding user_data)
  if (strcmp(sig, "response") == 0) {
    // Special case: dialog response has int parameter
    id = g_signal_connect_data(obj, sig, G_CALLBACK(_rgtk_r_callback_response),
                               rc, (GClosureNotify)_rgtk_r_closure_free, 0);
  } else if (strcmp(sig, "close-request") == 0) {
    // Special case: close-request expects boolean return
    id = g_signal_connect_data(obj, sig, G_CALLBACK(_rgtk_r_callback_boolean),
                               rc, (GClosureNotify)_rgtk_r_closure_free, 0);
  } else if (query.n_params == 0) {
    // No parameters beyond the object itself
    id = g_signal_connect_data(obj, sig, G_CALLBACK(_rgtk_r_callback),
                               rc, (GClosureNotify)_rgtk_r_closure_free, 0);
  } else if (query.n_params == 1) {
    // One additional parameter (e.g., factory signals: factory, list_item)
    id = g_signal_connect_data(obj, sig, G_CALLBACK(_rgtk_r_callback_two_args),
                               rc, (GClosureNotify)_rgtk_r_closure_free, 0);
  } else if (query.n_params == 2) {
    id = g_signal_connect_data(obj, sig, G_CALLBACK(_rgtk_r_callback_three_args),
                               rc, (GClosureNotify)_rgtk_r_closure_free, 0);
  } else if (query.n_params == 3) {
    id = g_signal_connect_data(obj, sig, G_CALLBACK(_rgtk_r_callback_four_args),
                               rc, (GClosureNotify)_rgtk_r_closure_free, 0);
  } else if (query.n_params == 4) {
    id = g_signal_connect_data(obj, sig, G_CALLBACK(_rgtk_r_callback_five_args),
                               rc, (GClosureNotify)_rgtk_r_closure_free, 0);
  } else {
    // More than 5 parameters - unsupported for now
    R_ReleaseObject(s_fun);
    g_free(rc);
    Rf_error("Signal '%s' has %d parameters - only up to 5 are supported", sig, query.n_params);
  }
#pragma GCC diagnostic pop

  return Rf_ScalarReal((double)id);
}

SEXP R_g_signal_connect_r_boolean(SEXP s_obj, SEXP s_signal, SEXP s_fun) {
  gpointer obj = get_ptr(s_obj);

  if (TYPEOF(s_signal) != STRSXP || LENGTH(s_signal) != 1) {
    Rf_error("signal must be a single character string");
  }
  const char *sig = CHAR(STRING_ELT(s_signal, 0));

  if (!Rf_isFunction(s_fun)) {
    Rf_error("fun must be a function");
  }

  RClosure *rc = g_new0(RClosure, 1);
  rc->fun = s_fun;

  R_PreserveObject(s_fun);

  gulong id = g_signal_connect_data(obj, sig, G_CALLBACK(_rgtk_r_callback_boolean),
                                    rc, (GClosureNotify)_rgtk_r_closure_free, 0);

  return Rf_ScalarReal((double)id);
}
