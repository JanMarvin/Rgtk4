// src/rgtk4_callbacks.h - Shared declarations for callback trampolines.

#ifndef RGTK4_CALLBACKS_H
#define RGTK4_CALLBACKS_H

#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <glib.h>

typedef struct {
  SEXP fun;
} RCallbackClosure;

RCallbackClosure *rgtk4_closure_new(SEXP fun);
void rgtk4_closure_free(gpointer data);
SEXP rgtk4_eval_callback(RCallbackClosure *rc, int nargs, SEXP *args);

// Thread-local "current closure" register, used by trampolines whose C
// signature has no user_data slot. The binding sets this before the GTK
// call and restores it after. Trampolines read it via rgtk4_current_closure.
RCallbackClosure *rgtk4_current_closure(void);
RCallbackClosure *rgtk4_set_current_closure(RCallbackClosure *rc);

#endif
