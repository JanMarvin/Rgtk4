// src/rgtk4_callbacks.h - Shared declarations for callback trampolines.

#ifndef RGTK4_CALLBACKS_H
#define RGTK4_CALLBACKS_H

#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <glib.h>

// Magic stored at the start of every RCallbackClosure. Trampolines verify
// this before dispatching to catch stale or corrupted user_data pointers
// (e.g. a callback that fires after its source was destroyed). Chosen
// arbitrarily; just needs to be unlikely to occur in random memory.
#define RGTK4_CB_MAGIC 0x52474B43u  // "RGKC"

typedef struct {
  guint32 magic;
  SEXP fun;
} RCallbackClosure;

RCallbackClosure *rgtk4_closure_new(SEXP fun);
void rgtk4_closure_free(gpointer data);

// Validates the magic. Returns rc if valid, NULL if not (and logs a
// g_critical for the bad case).
RCallbackClosure *rgtk4_closure_check(gconstpointer data);

SEXP rgtk4_eval_callback(RCallbackClosure *rc, int nargs, SEXP *args);

RCallbackClosure *rgtk4_current_closure(void);
RCallbackClosure *rgtk4_set_current_closure(RCallbackClosure *rc);

#endif
