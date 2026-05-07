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

static SEXP gvalue_to_sexp(const GValue *v) {
  GType t = G_VALUE_TYPE(v);
  switch (G_TYPE_FUNDAMENTAL(t)) {
  case G_TYPE_INVALID:
  case G_TYPE_NONE:
    return R_NilValue;
  case G_TYPE_BOOLEAN:
    return Rf_ScalarLogical(g_value_get_boolean(v));
  case G_TYPE_CHAR:
    return Rf_ScalarInteger(g_value_get_schar(v));
  case G_TYPE_UCHAR:
    return Rf_ScalarInteger(g_value_get_uchar(v));
  case G_TYPE_INT:
    return Rf_ScalarInteger(g_value_get_int(v));
  case G_TYPE_UINT:
    return Rf_ScalarReal((double)g_value_get_uint(v));
  case G_TYPE_LONG:
    return Rf_ScalarReal((double)g_value_get_long(v));
  case G_TYPE_ULONG:
    return Rf_ScalarReal((double)g_value_get_ulong(v));
  case G_TYPE_INT64:
    return Rf_ScalarReal((double)g_value_get_int64(v));
  case G_TYPE_UINT64:
    return Rf_ScalarReal((double)g_value_get_uint64(v));
  case G_TYPE_FLOAT:
    return Rf_ScalarReal((double)g_value_get_float(v));
  case G_TYPE_DOUBLE:
    return Rf_ScalarReal(g_value_get_double(v));
  case G_TYPE_ENUM:
    return Rf_ScalarInteger(g_value_get_enum(v));
  case G_TYPE_FLAGS:
    return Rf_ScalarReal((double)g_value_get_flags(v));
  case G_TYPE_STRING: {
    const char *s = g_value_get_string(v);
    return s ? Rf_mkString(s) : R_NilValue;
  }
  case G_TYPE_OBJECT:
    return R_MakeExternalPtr(g_value_get_object(v), R_NilValue, R_NilValue);
  case G_TYPE_BOXED:
    return R_MakeExternalPtr(g_value_get_boxed(v), R_NilValue, R_NilValue);
  case G_TYPE_POINTER:
    return R_MakeExternalPtr(g_value_get_pointer(v), R_NilValue, R_NilValue);
  default:
    return R_MakeExternalPtr(NULL, R_NilValue, R_NilValue);
  }
}

static void _rgtk_marshal(GClosure *closure, GValue *return_value,
                          guint n_param_values, const GValue *param_values,
                          gpointer invocation_hint, gpointer marshal_data) {
  (void)invocation_hint;
  (void)marshal_data;

  RClosure *rc = (RClosure *)closure->data;
  if (!rc || rc->fun == R_NilValue) return;

  SEXP args[16];
  int nargs = (int)(n_param_values < 16 ? n_param_values : 16);
  int nprot = 0;

  for (int i = 0; i < nargs; i++) {
    args[i] = PROTECT(gvalue_to_sexp(&param_values[i]));
    nprot++;
  }

  SEXP call = PROTECT(Rf_allocVector(LANGSXP, nargs + 1));
  nprot++;

  SETCAR(call, rc->fun);
  SEXP tail = CDR(call);
  for (int i = 0; i < nargs; i++) {
    SETCAR(tail, args[i]);
    tail = CDR(tail);
  }

  int err = 0;
  SEXP result = R_tryEval(call, R_GlobalEnv, &err);

  if (err) {
    REprintf("Error in GTK callback function\n");
  } else if (return_value && G_VALUE_TYPE(return_value) != G_TYPE_NONE && result != R_NilValue) {
    switch (G_TYPE_FUNDAMENTAL(G_VALUE_TYPE(return_value))) {
    case G_TYPE_BOOLEAN: {
      int lv = Rf_asLogical(result);
      g_value_set_boolean(return_value, lv == TRUE);
      break;
    }
    case G_TYPE_INT:
      g_value_set_int(return_value, Rf_asInteger(result));
      break;
    case G_TYPE_DOUBLE:
      g_value_set_double(return_value, Rf_asReal(result));
      break;
    default:
      break;
    }
  }

  UNPROTECT(nprot);
}

static void _rgtk_r_closure_finalize(gpointer data, GClosure *closure) {
  (void)closure;
  RClosure *rc = (RClosure *)data;
  if (rc && rc->fun != R_NilValue) {
    R_ReleaseObject(rc->fun);
    rc->fun = R_NilValue;
  }
  g_free(rc);
}

SEXP R_g_signal_connect_r(SEXP s_obj, SEXP s_signal, SEXP s_fun) {
  gpointer obj = get_ptr(s_obj);

  if (TYPEOF(s_signal) != STRSXP || LENGTH(s_signal) != 1) {
    Rf_error("signal must be a single character string");
  }
  const char *sig = CHAR(STRING_ELT(s_signal, 0));

  if (TYPEOF(s_fun) == PROMSXP) s_fun = Rf_eval(s_fun, R_GlobalEnv);
  if (!Rf_isFunction(s_fun)) {
    Rf_error("fun must be a function");
  }

  guint signal_id = 0;
  GQuark detail = 0;
  if (!g_signal_parse_name(sig, G_OBJECT_TYPE(obj), &signal_id, &detail, TRUE)) {
    Rf_error("Signal '%s' not found on object", sig);
  }

  RClosure *rc = g_new0(RClosure, 1);
  rc->fun = s_fun;
  R_PreserveObject(rc->fun);

  GClosure *closure = g_closure_new_simple(sizeof(GClosure), rc);
  g_closure_set_marshal(closure, _rgtk_marshal);
  g_closure_add_finalize_notifier(closure, rc, _rgtk_r_closure_finalize);

  gulong id = g_signal_connect_closure(obj, sig, closure, FALSE);
  return Rf_ScalarReal((double)id);
}

SEXP R_g_signal_connect_r_boolean(SEXP s_obj, SEXP s_signal, SEXP s_fun) {
  return R_g_signal_connect_r(s_obj, s_signal, s_fun);
}
