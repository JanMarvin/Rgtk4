// src/rgtk4_callbacks.c - Runtime support for R callbacks passed to GTK
// function-pointer APIs (GtkDrawingAreaDrawFunc, GCompareDataFunc, etc.).
//
// Each generated trampoline matches one callback signature and dispatches
// into a single R closure. Callback lifetime is tied to a destroy_notify
// that GTK invokes when the registration goes away.
//
// For callbacks with no user_data slot (GCompareFunc, GHFunc, etc.) we use
// a thread-local "current closure" register — set before the GTK call,
// trampoline reads it, restored on return. Only safe for synchronous
// callbacks that don't outlive the call that registered them.

#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <glib.h>
#include <glib-object.h>

#include "rgtk4_callbacks.h"

static __thread RCallbackClosure *_rgtk4_current_closure = NULL;

RCallbackClosure *rgtk4_current_closure(void) {
  return _rgtk4_current_closure;
}

RCallbackClosure *rgtk4_set_current_closure(RCallbackClosure *rc) {
  RCallbackClosure *prev = _rgtk4_current_closure;
  _rgtk4_current_closure = rc;
  return prev;
}

RCallbackClosure *rgtk4_closure_new(SEXP fun) {
  if (TYPEOF(fun) == PROMSXP) fun = Rf_eval(fun, R_GlobalEnv);
  if (!Rf_isFunction(fun)) {
    Rf_error("callback argument must be a function");
  }
  RCallbackClosure *rc = g_new0(RCallbackClosure, 1);
  rc->magic = RGTK4_CB_MAGIC;
  rc->fun = fun;
  R_PreserveObject(rc->fun);
  return rc;
}

void rgtk4_closure_free(gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  if (!rc) return;
  if (rc->magic != RGTK4_CB_MAGIC) {
    g_critical("rgtk4_closure_free: bad magic 0x%08x — refusing to free",
               (unsigned)rc->magic);
    return;
  }
  if (rc->fun != R_NilValue) {
    R_ReleaseObject(rc->fun);
    rc->fun = R_NilValue;
  }
  rc->magic = 0;  // make any subsequent dispatch fail the magic check
  g_free(rc);
}

RCallbackClosure *rgtk4_closure_check(gconstpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  if (!rc) return NULL;
  if (rc->magic != RGTK4_CB_MAGIC) {
    g_critical("rgtk4 callback dispatch: bad magic 0x%08x — stale or "
                 "corrupted user_data, callback skipped", (unsigned)rc->magic);
    return NULL;
  }
  return rc;
}

SEXP rgtk4_eval_callback(RCallbackClosure *rc, int nargs, SEXP *args) {
  if (!rc || rc->fun == R_NilValue) return R_NilValue;

  SEXP call = PROTECT(Rf_allocVector(LANGSXP, nargs + 1));
  SETCAR(call, rc->fun);
  SEXP tail = CDR(call);
  for (int i = 0; i < nargs; i++) {
    SETCAR(tail, args[i]);
    tail = CDR(tail);
  }

  int err = 0;
  SEXP result = R_tryEval(call, R_GlobalEnv, &err);
  UNPROTECT(1);
  if (err) {
    REprintf("Error in R callback\n");
    return R_NilValue;
  }
  return result;
}
