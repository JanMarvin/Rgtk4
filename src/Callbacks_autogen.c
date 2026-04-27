#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <stdint.h>
#include "rgtk4_callbacks.h"
#include "rgtk4_autogen_callbacks.h"

#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void _rgtk4_cb_CacheDestroyFunc(gpointer value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gpointer _rgtk4_cb_CacheDupFunc(gpointer value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gpointer _rgtk4_cb_CacheNewFunc(gpointer key) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)key, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_ChildWatchFunc(GPid pid, gint wait_status, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(Rf_ScalarInteger((int)(size_t)(pid)));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(wait_status)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_ClearHandleFunc(guint handle_id) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(Rf_ScalarInteger((int)(size_t)(handle_id)));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gint _rgtk4_cb_CompareDataFunc(gconstpointer a, gconstpointer b, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)a, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)b, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gint _result = (gint)Rf_asInteger(_r);
  UNPROTECT(3);
  return _result;
}
gint _rgtk4_cb_CompareFunc(gconstpointer a, gconstpointer b) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)a, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)b, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gint _result = (gint)Rf_asInteger(_r);
  UNPROTECT(3);
  return _result;
}
gchar* _rgtk4_cb_CompletionFunc(gpointer item) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)item, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gchar* _result = (gchar*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
gint _rgtk4_cb_CompletionStrncmpFunc(const gchar* s1, const gchar* s2, gsize n) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(Rf_mkString(s1 ? (const char*)s1 : ""));
  SEXP _a2 = PROTECT(Rf_mkString(s2 ? (const char*)s2 : ""));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(n)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gint _result = (gint)Rf_asInteger(_r);
  UNPROTECT(4);
  return _result;
}
gpointer _rgtk4_cb_CopyFunc(gconstpointer src, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)src, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_DataForeachFunc(GQuark key_id, gpointer data, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(Rf_ScalarInteger((int)(size_t)(key_id)));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)data, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_DestroyNotify(gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
gpointer _rgtk4_cb_DuplicateFunc(gpointer data, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)data, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_EqualFunc(gconstpointer a, gconstpointer b) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)a, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)b, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_EqualFuncFull(gconstpointer a, gconstpointer b, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)a, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)b, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_ErrorClearFunc(GError* error) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)error, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_ErrorCopyFunc(const GError* src_error, GError* dest_error) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)src_error, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)dest_error, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_ErrorInitFunc(GError* error) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)error, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_FreeFunc(gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_Func(gpointer data, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)data, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_HFunc(gpointer key, gpointer value, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)key, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_HRFunc(gpointer key, gpointer value, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)key, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
guint _rgtk4_cb_HashFunc(gconstpointer key) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)key, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  guint _result = (guint)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_HookCheckFunc(gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(1);
  return _result;
}
gboolean _rgtk4_cb_HookCheckMarshaller(GHook* hook, gpointer marshal_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)hook, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)marshal_data, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gint _rgtk4_cb_HookCompareFunc(GHook* new_hook, GHook* sibling) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)new_hook, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)sibling, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gint _result = (gint)Rf_asInteger(_r);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_HookFinalizeFunc(GHookList* hook_list, GHook* hook) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)hook_list, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)hook, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_HookFindFunc(GHook* hook, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)hook, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_HookFunc(gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_HookMarshaller(GHook* hook, gpointer marshal_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)hook, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)marshal_data, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_IOFunc(GIOChannel* source, GIOCondition condition, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)source, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(condition)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
GSource* _rgtk4_cb_io_create_watch(GIOChannel* channel, GIOCondition condition) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)channel, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(condition)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GSource* _result = (GSource*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_io_free(GIOChannel* channel) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)channel, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
GIOFlags _rgtk4_cb_io_get_flags(GIOChannel* channel) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)channel, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GIOFlags _result = (GIOFlags)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : INTEGER(_r)[0]);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_LogFunc(const gchar* log_domain, GLogLevelFlags log_level, const gchar* message, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(Rf_mkString(log_domain ? (const char*)log_domain : ""));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(log_level)));
  SEXP _a3 = PROTECT(Rf_mkString(message ? (const char*)message : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
GLogWriterOutput _rgtk4_cb_LogWriterFunc(GLogLevelFlags log_level, const GLogField* fields, gsize n_fields, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(Rf_ScalarInteger((int)(size_t)(log_level)));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)fields, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(n_fields)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GLogWriterOutput _result = (GLogWriterOutput)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : INTEGER(_r)[0]);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_error(GtkBuildableParseContext* context, GError* error, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)error, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gpointer _rgtk4_cb_malloc(gsize n_bytes) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(Rf_ScalarReal((double)(size_t)(n_bytes)));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gpointer _rgtk4_cb_realloc(gpointer mem, gsize n_bytes) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mem, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(n_bytes)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_free(gpointer mem) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mem, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gpointer _rgtk4_cb_calloc(gsize n_blocks, gsize n_block_bytes) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(Rf_ScalarReal((double)(size_t)(n_blocks)));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(n_block_bytes)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
gpointer _rgtk4_cb_try_malloc(gsize n_bytes) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(Rf_ScalarReal((double)(size_t)(n_bytes)));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gpointer _rgtk4_cb_try_realloc(gpointer mem, gsize n_bytes) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mem, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(n_bytes)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_NodeForeachFunc(GNode* node, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)node, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_NodeTraverseFunc(GNode* node, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)node, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gint _rgtk4_cb_PollFunc(GPollFD* ufds, guint nfsd, gint timeout_) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)ufds, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(nfsd)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(timeout_)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gint _result = (gint)Rf_asInteger(_r);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_PrintFunc(const gchar* string) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(Rf_mkString(string ? (const char*)string : ""));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_RegexEvalCallback(const GMatchInfo* match_info, GString* result, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)match_info, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)result, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_ScannerMsgFunc(GScanner* scanner, gchar* message, gboolean error) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)scanner, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(message ? (const char*)message : ""));
  SEXP _a3 = PROTECT(Rf_ScalarLogical((int)(size_t)(error)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gint _rgtk4_cb_SequenceIterCompareFunc(GSequenceIter* a, GSequenceIter* b, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)a, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)b, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gint _result = (gint)Rf_asInteger(_r);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_ref(gpointer cb_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cb_data, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_unref(gpointer cb_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cb_data, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_SourceDisposeFunc(GSource* source) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)source, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_SourceDummyMarshal() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
gboolean _rgtk4_cb_SourceFunc(gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(1);
  return _result;
}
gboolean _rgtk4_cb_SourceFuncsCheckFunc(GSource* source) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)source, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_SourceFuncsFinalizeFunc(GSource* source) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)source, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_SourceFuncsPrepareFunc(GSource* source, gint* timeout_) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)source, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)timeout_, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_SourceOnceFunc(gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_SpawnChildSetupFunc(gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_TestDataFunc(gconstpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_TestFixtureFunc(gpointer fixture, gconstpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fixture, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_TestFunc() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
gboolean _rgtk4_cb_TestLogFatalFunc(const gchar* log_domain, GLogLevelFlags log_level, const gchar* message, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(Rf_mkString(log_domain ? (const char*)log_domain : ""));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(log_level)));
  SEXP _a3 = PROTECT(Rf_mkString(message ? (const char*)message : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gpointer _rgtk4_cb_ThreadFunc(gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(1);
  return _result;
}
GMutex* _rgtk4_cb_mutex_new() {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  GMutex* _result = (GMutex*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(1);
  return _result;
}
void _rgtk4_cb_mutex_lock(GMutex* mutex) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mutex, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_mutex_trylock(GMutex* mutex) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mutex, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_mutex_unlock(GMutex* mutex) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mutex, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_mutex_free(GMutex* mutex) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mutex, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
GCond* _rgtk4_cb_cond_new() {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  GCond* _result = (GCond*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(1);
  return _result;
}
void _rgtk4_cb_cond_signal(GCond* cond) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cond, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_cond_broadcast(GCond* cond) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cond, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_cond_wait(GCond* cond, GMutex* mutex) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cond, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)mutex, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_cond_timed_wait(GCond* cond, GMutex* mutex, GTimeVal* end_time) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cond, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)mutex, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)end_time, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_cond_free(GCond* cond) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cond, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
GPrivate* _rgtk4_cb_private_new(GDestroyNotify destructor) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)destructor, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GPrivate* _result = (GPrivate*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gpointer _rgtk4_cb_private_get(GPrivate* private_key) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)private_key, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_private_set(GPrivate* private_key, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)private_key, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_thread_yield() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_thread_join(gpointer thread) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)thread, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_thread_exit() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_thread_self(gpointer thread) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)thread, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_thread_equal(gpointer thread1, gpointer thread2) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)thread1, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)thread2, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
const gchar* _rgtk4_cb_TranslateFunc(const gchar* str, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(Rf_mkString(str ? (const char*)str : ""));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const gchar* _result = (const gchar*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_TraverseFunc(gpointer key, gpointer value, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)key, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_TraverseNodeFunc(GTreeNode* node, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)node, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_VoidFunc() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_BaseFinalizeFunc(gpointer g_class) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)g_class, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_BaseInitFunc(gpointer g_class) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)g_class, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_BindingTransformFunc(GBinding* binding, const GValue* from_value, GValue* to_value, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)binding, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)from_value, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)to_value, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gpointer _rgtk4_cb_BoxedCopyFunc(gpointer boxed) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)boxed, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_BoxedFreeFunc(gpointer boxed) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)boxed, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_Callback() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_ClassFinalizeFunc(gpointer g_class, gpointer class_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)g_class, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)class_data, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_ClassInitFunc(gpointer g_class, gpointer class_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)g_class, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)class_data, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_marshal(GClosure* closure, GValue* return_value, guint n_param_values, const GValue* param_values, gpointer invocation_hint, gpointer marshal_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)closure, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)return_value, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_param_values)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)param_values, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)invocation_hint, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)marshal_data, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_ClosureMarshal(GClosure* closure, GValue* return_value, guint n_param_values, const GValue* param_values, gpointer invocation_hint, gpointer marshal_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)closure, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)return_value, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_param_values)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)param_values, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)invocation_hint, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)marshal_data, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_ClosureNotify(gpointer data, GClosure* closure) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)closure, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a2 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_set_property(GObject* object, guint property_id, const GValue* value, GParamSpec* pspec) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(property_id)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_get_property(GObject* object, guint property_id, GValue* value, GParamSpec* pspec) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(property_id)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_dispose(GObject* object) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_finalize(GParamSpec* pspec) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_dispatch_properties_changed(GObject* object, guint n_pspecs, GParamSpec** pspecs) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_pspecs)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)pspecs, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_notify(GObject* object, GParamSpec* pspec) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_constructed(GObject* object) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_InstanceInitFunc(GTypeInstance* instance, gpointer g_class) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)instance, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)g_class, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_InterfaceFinalizeFunc(gpointer g_iface, gpointer iface_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)g_iface, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iface_data, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_InterfaceInitFunc(gpointer g_iface, gpointer iface_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)g_iface, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iface_data, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_ObjectFinalizeFunc(GObject* object) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_ObjectGetPropertyFunc(GObject* object, guint property_id, GValue* value, GParamSpec* pspec) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(property_id)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_ObjectSetPropertyFunc(GObject* object, guint property_id, const GValue* value, GParamSpec* pspec) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(property_id)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_value_set_default(GParamSpec* pspec, GValue* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_value_validate(GParamSpec* pspec, GValue* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gint _rgtk4_cb_values_cmp(GParamSpec* pspec, const GValue* value1, const GValue* value2) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)value1, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value2, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gint _result = (gint)Rf_asInteger(_r);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_value_is_valid(GParamSpec* pspec, const GValue* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_instance_init(GParamSpec* pspec) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_SignalAccumulator(GSignalInvocationHint* ihint, GValue* return_accu, const GValue* handler_return, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)ihint, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)return_accu, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)handler_return, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_SignalEmissionHook(GSignalInvocationHint* ihint, guint n_param_values, const GValue* param_values, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)ihint, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_param_values)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)param_values, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_ToggleNotify(gpointer data, GObject* object, gboolean is_last_ref) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarLogical((int)(size_t)(is_last_ref)));
  SEXP _argv[2] = { _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_TypeClassCacheFunc(gpointer cache_data, GTypeClass* g_class) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cache_data, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)g_class, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_TypeInterfaceCheckFunc(gpointer check_data, gpointer g_iface) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)check_data, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)g_iface, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_unload(GTypeModule* module) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)module, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_reserved1() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_reserved2() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_reserved3() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_reserved4() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_TypePluginCompleteInterfaceInfo(GTypePlugin* plugin, GType instance_type, GType interface_type, GInterfaceInfo* info) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)plugin, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(instance_type)));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(interface_type)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)info, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_TypePluginCompleteTypeInfo(GTypePlugin* plugin, GType g_type, GTypeInfo* info, GTypeValueTable* value_table) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)plugin, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(g_type)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)info, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)value_table, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_TypePluginUnuse(GTypePlugin* plugin) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)plugin, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_TypePluginUse(GTypePlugin* plugin) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)plugin, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gchar* _rgtk4_cb_TypeValueCollectFunc(GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_collect_values)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)collect_values, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(collect_flags)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  gchar* _result = (gchar*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(5);
  return _result;
}
void _rgtk4_cb_TypeValueCopyFunc(const GValue* src_value, GValue* dest_value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)src_value, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)dest_value, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_TypeValueFreeFunc(GValue* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_TypeValueInitFunc(GValue* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gchar* _rgtk4_cb_TypeValueLCopyFunc(const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_collect_values)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)collect_values, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(collect_flags)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  gchar* _result = (gchar*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(5);
  return _result;
}
gpointer _rgtk4_cb_TypeValuePeekPointerFunc(const GValue* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_ValueTransform(const GValue* src_value, GValue* dest_value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)src_value, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)dest_value, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_WeakNotify(gpointer data, GObject* where_the_object_was) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)where_the_object_was, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a2 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_activate(GtkListBoxRow* row) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)row, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_change_state(GAction* action, GVariant* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_has_action(GActionGroup* action_group, const gchar* action_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gchar** _rgtk4_cb_list_actions(GActionGroup* action_group) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gchar** _result = (gchar**)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_get_action_enabled(GActionGroup* action_group, const gchar* action_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
const GVariantType* _rgtk4_cb_get_action_parameter_type(GActionGroup* action_group, const gchar* action_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  const GVariantType* _result = (const GVariantType*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
const GVariantType* _rgtk4_cb_get_action_state_type(GActionGroup* action_group, const gchar* action_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  const GVariantType* _result = (const GVariantType*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
GVariant* _rgtk4_cb_get_action_state_hint(GActionGroup* action_group, const gchar* action_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GVariant* _result = (GVariant*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
GVariant* _rgtk4_cb_get_action_state(GActionGroup* action_group, const gchar* action_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GVariant* _result = (GVariant*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_change_action_state(GActionGroup* action_group, const gchar* action_name, GVariant* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_activate_action(GActionGroup* action_group, const gchar* action_name, GVariant* parameter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)parameter, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_action_added(GActionGroup* action_group, const gchar* action_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_action_removed(GActionGroup* action_group, const gchar* action_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_action_enabled_changed(GActionGroup* action_group, const gchar* action_name, gboolean enabled) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _a3 = PROTECT(Rf_ScalarLogical((int)(size_t)(enabled)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_action_state_changed(GActionGroup* action_group, const gchar* action_name, GVariant* state) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)state, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_query_action(GActionGroup* action_group, const gchar* action_name, gboolean* enabled, const GVariantType** parameter_type, const GVariantType** state_type, GVariant** state_hint, GVariant** state) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_group, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)enabled, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)parameter_type, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)state_type, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)state_hint, R_NilValue, R_NilValue));
  SEXP _a7 = PROTECT(R_MakeExternalPtr((void*)state, R_NilValue, R_NilValue));
  SEXP _argv[7] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 7, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(8);
  return _result;
}
const char* _rgtk4_cb_get_name(PangoFontFamily* family) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)family, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const char* _result = (const char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
const GVariantType* _rgtk4_cb_get_parameter_type(GAction* action) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const GVariantType* _result = (const GVariantType*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
const GVariantType* _rgtk4_cb_get_state_type(GAction* action) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const GVariantType* _result = (const GVariantType*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GVariant* _rgtk4_cb_get_state_hint(GAction* action) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GVariant* _result = (GVariant*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_get_enabled(GAction* action) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
GVariant* _rgtk4_cb_get_state(GAction* action) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GVariant* _result = (GVariant*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GAction* _rgtk4_cb_lookup_action(GActionMap* action_map, const gchar* action_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_map, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GAction* _result = (GAction*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_add_action(GActionMap* action_map, GAction* action) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_map, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)action, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_remove_action(GActionMap* action_map, const gchar* action_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)action_map, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
GFile* _rgtk4_cb_dup(GFile* file) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GFile* _result = (GFile*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_equal(const PangoAttribute* attr1, const PangoAttribute* attr2) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)attr1, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)attr2, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
const char* _rgtk4_cb_get_id(GtkBuildable* buildable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buildable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const char* _result = (const char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
const char* _rgtk4_cb_get_description(GAppInfo* appinfo) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const char* _result = (const char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
const char* _rgtk4_cb_get_executable(GAppInfo* appinfo) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const char* _result = (const char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
GIcon* _rgtk4_cb_get_icon(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GIcon* _result = (GIcon*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_supports_uris(GAppInfo* appinfo) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_supports_files(GAppInfo* appinfo) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_should_show(GAppInfo* appinfo) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_can_remove_supports_type(GAppInfo* appinfo) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_can_delete(GAppInfo* appinfo) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_do_delete(GAppInfo* appinfo) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
const char* _rgtk4_cb_get_commandline(GAppInfo* appinfo) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const char* _result = (const char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
const char* _rgtk4_cb_get_display_name(GAppInfo* appinfo) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const char* _result = (const char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
const char** _rgtk4_cb_get_supported_types(GAppInfo* appinfo) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const char** _result = (const char**)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_launch_uris_async(GAppInfo* appinfo, GList* uris, GAppLaunchContext* context, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)appinfo, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)uris, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
char* _rgtk4_cb_get_display(GAppLaunchContext* context, GAppInfo* info, GList* files) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)info, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)files, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(4);
  return _result;
}
char* _rgtk4_cb_get_startup_notify_id(GAppLaunchContext* context, GAppInfo* info, GList* files) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)info, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)files, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_launch_failed(GAppLaunchContext* context, const char* startup_notify_id) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(startup_notify_id ? (const char*)startup_notify_id : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_launched(GAppLaunchContext* context, GAppInfo* info, GVariant* platform_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)info, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)platform_data, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_launch_started(GAppLaunchContext* context, GAppInfo* info, GVariant* platform_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)info, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)platform_data, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb__g_reserved1() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__g_reserved2() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__g_reserved3() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_startup(GApplication* application) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_open(GtkMediaFile* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
int _rgtk4_cb_command_line(GApplication* application, GApplicationCommandLine* command_line) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)command_line, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_local_command_line(GApplication* application, gchar*** arguments, int* exit_status) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)arguments, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)exit_status, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_before_emit(GApplication* application, GVariant* platform_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)platform_data, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_after_emit(GApplication* application, GVariant* platform_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)platform_data, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_add_platform_data(GApplication* application, GVariantBuilder* builder) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)builder, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_quit_mainloop(GApplication* application) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_run_mainloop(GApplication* application) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gint _rgtk4_cb_handle_local_options(GApplication* application, GVariantDict* options) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)options, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gint _result = (gint)Rf_asInteger(_r);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_name_lost(GApplication* application) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_print_literal(GApplicationCommandLine* cmdline, const gchar* message) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cmdline, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(message ? (const char*)message : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_printerr_literal(GApplicationCommandLine* cmdline, const gchar* message) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cmdline, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(message ? (const char*)message : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
GInputStream* _rgtk4_cb_get_stdin(GApplicationCommandLine* cmdline) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cmdline, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GInputStream* _result = (GInputStream*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_init_async(GAsyncInitable* initable, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)initable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_AsyncReadyCallback(GObject* source_object, GAsyncResult* res, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)source_object, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)res, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gpointer _rgtk4_cb_get_user_data(GAsyncResult* res) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)res, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GObject* _rgtk4_cb_get_source_object(GAsyncResult* res) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)res, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GObject* _result = (GObject*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_is_tagged(GAsyncResult* res, gpointer source_tag) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)res, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)source_tag, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_fill_async(GBufferedInputStream* stream, gssize count, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(ssize_t)(count)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb__g_reserved4() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__g_reserved5() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_cancelled(GCancellable* cancellable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_CancellableSourceFunc(GCancellable* cancellable, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_reset(GtkIMContext* context) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
GDBusObject* _rgtk4_cb_get_object(GDBusObjectManager* manager, const gchar* object_path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)manager, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(object_path ? (const char*)object_path : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GDBusObject* _result = (GDBusObject*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_set_object(GDBusInterface* interface_, GDBusObject* object) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)interface_, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
GDBusObject* _rgtk4_cb_dup_object(GDBusInterface* interface_) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)interface_, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GDBusObject* _result = (GDBusObject*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GDBusInterfaceVTable* _rgtk4_cb_get_vtable(GDBusInterfaceSkeleton* interface_) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)interface_, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GDBusInterfaceVTable* _result = (GDBusInterfaceVTable*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GVariant* _rgtk4_cb_get_properties(GDBusInterfaceSkeleton* interface_) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)interface_, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GVariant* _result = (GVariant*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
const gchar* _rgtk4_cb_get_object_path(GDBusObjectManager* manager) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)manager, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const gchar* _result = (const gchar*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
GList* _rgtk4_cb_get_interfaces(GDBusObject* object) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GList* _result = (GList*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GDBusInterface* _rgtk4_cb_get_interface(GDBusObjectManager* manager, const gchar* object_path, const gchar* interface_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)manager, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(object_path ? (const char*)object_path : ""));
  SEXP _a3 = PROTECT(Rf_mkString(interface_name ? (const char*)interface_name : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GDBusInterface* _result = (GDBusInterface*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_interface_added(GDBusObjectManager* manager, GDBusObject* object, GDBusInterface* interface_) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)manager, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)interface_, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_interface_removed(GDBusObjectManager* manager, GDBusObject* object, GDBusInterface* interface_) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)manager, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)interface_, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
GList* _rgtk4_cb_get_objects(GDBusObjectManager* manager) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)manager, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GList* _result = (GList*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_object_added(GDBusObjectManager* manager, GDBusObject* object) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)manager, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_object_removed(GDBusObjectManager* manager, GDBusObject* object) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)manager, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_g_properties_changed(GDBusProxy* proxy, GVariant* changed_properties, const gchar* const* invalidated_properties) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)proxy, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)changed_properties, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_mkString(invalidated_properties ? (const char*)invalidated_properties : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_g_signal(GDBusProxy* proxy, const gchar* sender_name, const gchar* signal_name, GVariant* parameters) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)proxy, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(sender_name ? (const char*)sender_name : ""));
  SEXP _a3 = PROTECT(Rf_mkString(signal_name ? (const char*)signal_name : ""));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)parameters, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
GType _rgtk4_cb_DBusProxyTypeFunc(GDBusObjectManagerClient* manager, const gchar* object_path, const gchar* interface_name, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)manager, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(object_path ? (const char*)object_path : ""));
  SEXP _a3 = PROTECT(Rf_mkString(interface_name ? (const char*)interface_name : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GType _result = (GType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : REAL(_r)[0]);
  UNPROTECT(4);
  return _result;
}
GSource* _rgtk4_cb_create_source(GPollableOutputStream* stream, GCancellable* cancellable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GSource* _result = (GSource*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
GIOCondition _rgtk4_cb_condition_check(GDatagramBased* datagram_based, GIOCondition condition) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)datagram_based, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(condition)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GIOCondition _result = (GIOCondition)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : INTEGER(_r)[0]);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_DatagramBasedSourceFunc(GDatagramBased* datagram_based, GIOCondition condition, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)datagram_based, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(condition)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_changed(PangoFontMap* fontmap) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontmap, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_disconnected(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_eject_button(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_has_volumes(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
GList* _rgtk4_cb_get_volumes(GVolumeMonitor* volume_monitor) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GList* _result = (GList*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_is_media_removable(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_has_media(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_is_media_check_automatic(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_can_eject(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_can_poll_for_media(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_eject(GVolume* volume, GMountUnmountFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_poll_for_media(GDrive* drive, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
char* _rgtk4_cb_get_identifier(GVolume* volume, const char* kind) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(kind ? (const char*)kind : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(3);
  return _result;
}
char** _rgtk4_cb_enumerate_identifiers(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  char** _result = (char**)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
GDriveStartStopType _rgtk4_cb_get_start_stop_type(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GDriveStartStopType _result = (GDriveStartStopType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : INTEGER(_r)[0]);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_can_start(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_can_start_degraded(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_start(GDrive* drive, GDriveStartFlags flags, GMountOperation* mount_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mount_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
gboolean _rgtk4_cb_can_stop(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_stop(GDrive* drive, GMountUnmountFlags flags, GMountOperation* mount_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mount_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_stop_button(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_eject_with_operation(GVolume* volume, GMountUnmountFlags flags, GMountOperation* mount_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mount_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
const gchar* _rgtk4_cb_get_sort_key(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const gchar* _result = (const gchar*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
GIcon* _rgtk4_cb_get_symbolic_icon(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GIcon* _result = (GIcon*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_is_removable(GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_next_files_async(GFileEnumerator* enumerator, int num_files, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)enumerator, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(num_files)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_close_async(GOutputStream* stream, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb__g_reserved6() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__g_reserved7() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
goffset _rgtk4_cb_tell(GSeekable* seekable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)seekable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  goffset _result = (goffset)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_can_seek(GSeekable* seekable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)seekable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_seek(GtkMediaStream* self, gint64 timestamp) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(timestamp)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_can_truncate(GSeekable* seekable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)seekable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_query_info_async(GFileOutputStream* stream, const char* attributes, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(attributes ? (const char*)attributes : ""));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
char* _rgtk4_cb_get_etag(GFileOutputStream* stream) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
guint _rgtk4_cb_hash(GIcon* icon) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)icon, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  guint _result = (guint)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_is_native(GFile* file) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_has_uri_scheme(GFile* file, const char* uri_scheme) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(uri_scheme ? (const char*)uri_scheme : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
char* _rgtk4_cb_get_uri_scheme(GFile* file) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
char* _rgtk4_cb_get_basename(GFile* file) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
GtkTreePath* _rgtk4_cb_get_path(GtkTreeModel* tree_model, GtkTreeIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GtkTreePath* _result = (GtkTreePath*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
char* _rgtk4_cb_get_uri(GFile* file) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
char* _rgtk4_cb_get_parse_name(GFile* file) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
GFile* _rgtk4_cb_get_parent(GFile* file) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GFile* _result = (GFile*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_prefix_matches(GFile* prefix, GFile* file) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)prefix, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
char* _rgtk4_cb_get_relative_path(GFile* parent, GFile* descendant) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)parent, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)descendant, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(3);
  return _result;
}
GFile* _rgtk4_cb_resolve_relative_path(GFile* file, const char* relative_path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(relative_path ? (const char*)relative_path : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GFile* _result = (GFile*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_enumerate_children_async(GFile* file, const char* attributes, GFileQueryInfoFlags flags, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(attributes ? (const char*)attributes : ""));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_query_filesystem_info_async(GFile* file, const char* attributes, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(attributes ? (const char*)attributes : ""));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_find_enclosing_mount_async(GFile* file, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_set_display_name_async(GFile* file, const char* display_name, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(display_name ? (const char*)display_name : ""));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb__query_settable_attributes_async() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__query_settable_attributes_finish() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__query_writable_namespaces_async() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__query_writable_namespaces_finish() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_set_attributes_async(GFile* file, GFileInfo* info, GFileQueryInfoFlags flags, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)info, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_read_async(GInputStream* stream, void* buffer, gsize count, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(count)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_append_to_async(GFile* file, GFileCreateFlags flags, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_create_async(GFile* file, GFileCreateFlags flags, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_replace_async(GFile* file, const char* etag, gboolean make_backup, GFileCreateFlags flags, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(etag ? (const char*)etag : ""));
  SEXP _a3 = PROTECT(Rf_ScalarLogical((int)(size_t)(make_backup)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a7 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[7] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7 };
  (void)rgtk4_eval_callback(rc, 7, _argv);
  UNPROTECT(7);
}
void _rgtk4_cb_delete_file_async(GFile* file, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_trash_async(GFile* file, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_make_directory_async(GFile* file, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_make_symbolic_link_async(GFile* file, const char* symlink_value, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(symlink_value ? (const char*)symlink_value : ""));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
PangoAttribute* _rgtk4_cb_copy(const PangoAttribute* attr) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)attr, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  PangoAttribute* _result = (PangoAttribute*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_copy_async(GFile* source, GFile* destination, GFileCopyFlags flags, int io_priority, GCancellable* cancellable, GFileProgressCallback progress_callback, gpointer progress_callback_data, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)source, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)destination, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)progress_callback, R_NilValue, R_NilValue));
  SEXP _a7 = PROTECT(R_MakeExternalPtr((void*)progress_callback_data, R_NilValue, R_NilValue));
  SEXP _a8 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[8] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7, _a8 };
  (void)rgtk4_eval_callback(rc, 8, _argv);
  UNPROTECT(8);
}
void _rgtk4_cb_move_async(GFile* source, GFile* destination, GFileCopyFlags flags, int io_priority, GCancellable* cancellable, GFileProgressCallback progress_callback, gpointer progress_callback_data, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)source, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)destination, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)progress_callback, R_NilValue, R_NilValue));
  SEXP _a7 = PROTECT(R_MakeExternalPtr((void*)progress_callback_data, R_NilValue, R_NilValue));
  SEXP _a8 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[8] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7, _a8 };
  (void)rgtk4_eval_callback(rc, 8, _argv);
  UNPROTECT(8);
}
void _rgtk4_cb_mount_mountable(GFile* file, GMountMountFlags flags, GMountOperation* mount_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mount_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_unmount_mountable(GFile* file, GMountUnmountFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_eject_mountable(GFile* file, GMountUnmountFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_mount_enclosing_volume(GFile* location, GMountMountFlags flags, GMountOperation* mount_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)location, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mount_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_open_readwrite_async(GFile* file, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_create_readwrite_async(GFile* file, GFileCreateFlags flags, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_replace_readwrite_async(GFile* file, const char* etag, gboolean make_backup, GFileCreateFlags flags, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(etag ? (const char*)etag : ""));
  SEXP _a3 = PROTECT(Rf_ScalarLogical((int)(size_t)(make_backup)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a7 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[7] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7 };
  (void)rgtk4_eval_callback(rc, 7, _argv);
  UNPROTECT(7);
}
void _rgtk4_cb_start_mountable(GFile* file, GDriveStartFlags flags, GMountOperation* start_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)start_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_stop_mountable(GFile* file, GMountUnmountFlags flags, GMountOperation* mount_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mount_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_unmount_mountable_with_operation(GFile* file, GMountUnmountFlags flags, GMountOperation* mount_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mount_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_eject_mountable_with_operation(GFile* file, GMountUnmountFlags flags, GMountOperation* mount_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mount_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_poll_mountable(GFile* file, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_query_exists(GFile* file, GCancellable* cancellable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)file, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_FileMeasureProgressCallback(gboolean reporting, guint64 current_size, guint64 num_dirs, guint64 num_files, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(Rf_ScalarLogical((int)(size_t)(reporting)));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(current_size)));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(num_dirs)));
  SEXP _a4 = PROTECT(Rf_ScalarReal((double)(size_t)(num_files)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
gboolean _rgtk4_cb_cancel(GFileMonitor* monitor) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)monitor, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_FileProgressCallback(goffset current_num_bytes, goffset total_num_bytes, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(Rf_ScalarReal((double)(size_t)(current_num_bytes)));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(total_num_bytes)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_FileReadMoreCallback(const char* file_contents, goffset file_size, gpointer callback_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(Rf_mkString(file_contents ? (const char*)file_contents : ""));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(file_size)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)callback_data, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_got_completion_data(GFilenameCompleter* filename_completer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)filename_completer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_IOSchedulerJobFunc(GIOSchedulerJob* job, GCancellable* cancellable, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)job, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
GInputStream* _rgtk4_cb_get_input_stream(GIOStream* stream) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GInputStream* _result = (GInputStream*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GOutputStream* _rgtk4_cb_get_output_stream(GIOStream* stream) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GOutputStream* _result = (GOutputStream*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb__g_reserved8() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__g_reserved9() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__g_reserved10() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
gboolean _rgtk4_cb_to_tokens(GIcon* icon, GPtrArray* tokens, gint* out_version) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)icon, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)tokens, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)out_version, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_serialize(GSocketControlMessage* message, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)message, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gchar* _rgtk4_cb_to_string(GSocketConnectable* connectable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)connectable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gchar* _result = (gchar*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
const guint8* _rgtk4_cb_to_bytes(GInetAddress* address) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)address, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const guint8* _result = (const guint8*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_skip_async(GInputStream* stream, gsize count, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(count)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
GType _rgtk4_cb_get_item_type(GListModel* list) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)list, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GType _result = (GType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : REAL(_r)[0]);
  UNPROTECT(2);
  return _result;
}
gint _rgtk4_cb_get_n_items(GMenuModel* model) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gint _result = (gint)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
gpointer _rgtk4_cb_get_item(GListModel* list, guint position) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)list, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_load_async(GLoadableIcon* icon, int size, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)icon, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(size)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_low_memory_warning(GMemoryMonitor* monitor, GMemoryMonitorWarningLevel level) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(level)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_get_next(GMenuLinkIter* iter, const gchar** out_link, GMenuModel** value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(out_link ? (const char*)out_link : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_is_mutable(GMenuModel* model) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_get_item_attributes(GMenuModel* model, gint item_index, GHashTable** attributes) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(item_index)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)attributes, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
GMenuAttributeIter* _rgtk4_cb_iterate_item_attributes(GMenuModel* model, gint item_index) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(item_index)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GMenuAttributeIter* _result = (GMenuAttributeIter*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
GVariant* _rgtk4_cb_get_item_attribute_value(GMenuModel* model, gint item_index, const gchar* attribute, const GVariantType* expected_type) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(item_index)));
  SEXP _a3 = PROTECT(Rf_mkString(attribute ? (const char*)attribute : ""));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)expected_type, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  GVariant* _result = (GVariant*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(5);
  return _result;
}
void _rgtk4_cb_get_item_links(GMenuModel* model, gint item_index, GHashTable** links) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(item_index)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)links, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
GMenuLinkIter* _rgtk4_cb_iterate_item_links(GMenuModel* model, gint item_index) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(item_index)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GMenuLinkIter* _result = (GMenuLinkIter*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
GMenuModel* _rgtk4_cb_get_item_link(GMenuModel* model, gint item_index, const gchar* link) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(item_index)));
  SEXP _a3 = PROTECT(Rf_mkString(link ? (const char*)link : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GMenuModel* _result = (GMenuModel*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_unmounted(GMount* mount) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
GFile* _rgtk4_cb_get_root(GMount* mount) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GFile* _result = (GFile*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
char* _rgtk4_cb_get_uuid(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
GVolume* _rgtk4_cb_get_volume(GMount* mount) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GVolume* _result = (GVolume*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GDrive* _rgtk4_cb_get_drive(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GDrive* _result = (GDrive*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_can_unmount(GMount* mount) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_unmount(GMount* mount, GMountUnmountFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_remount(GMount* mount, GMountMountFlags flags, GMountOperation* mount_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mount_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_guess_content_type(GMount* mount, gboolean force_rescan, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarLogical((int)(size_t)(force_rescan)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_pre_unmount(GMount* mount) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_unmount_with_operation(GMount* mount, GMountUnmountFlags flags, GMountOperation* mount_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mount_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
GFile* _rgtk4_cb_get_default_location(GMount* mount) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GFile* _result = (GFile*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_ask_question(GMountOperation* op, const char* message, const char** choices) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)op, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(message ? (const char*)message : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)choices, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_reply(GMountOperation* op, GMountOperationResult result) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)op, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(result)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_aborted(GMountOperation* op) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)op, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_show_processes(GMountOperation* op, const gchar* message, GArray* processes, const gchar** choices) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)op, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(message ? (const char*)message : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)processes, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)choices, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_show_unmount_progress(GMountOperation* op, const gchar* message, gint64 time_left, gint64 bytes_left) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)op, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(message ? (const char*)message : ""));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(time_left)));
  SEXP _a4 = PROTECT(Rf_ScalarReal((double)(size_t)(bytes_left)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_network_changed(GNetworkMonitor* monitor, gboolean network_available) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarLogical((int)(size_t)(network_available)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_can_reach_async(GNetworkMonitor* monitor, GSocketConnectable* connectable, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)connectable, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_write_async(GOutputStream* stream, void* buffer, gsize count, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(count)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_splice_async(GOutputStream* stream, GInputStream* source, GOutputStreamSpliceFlags flags, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)source, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_flush_async(GOutputStream* stream, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_writev_async(GOutputStream* stream, const GOutputVector* vectors, gsize n_vectors, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)vectors, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(n_vectors)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_acquire_async(GPermission* permission, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)permission, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_release_async(GPermission* permission, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)permission, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_can_poll(GPollableOutputStream* stream) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_is_readable(GPollableInputStream* stream) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_is_writable(GPollableOutputStream* stream) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_PollableSourceFunc(GObject* pollable_stream, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)pollable_stream, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_connect_async(GProxy* proxy, GIOStream* connection, GProxyAddress* proxy_address, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)proxy, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)connection, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)proxy_address, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
gboolean _rgtk4_cb_supports_hostname(GProxy* proxy) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)proxy, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_is_supported() {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(1);
  return _result;
}
void _rgtk4_cb_lookup_async(GProxyResolver* resolver, const gchar* uri, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)resolver, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(uri ? (const char*)uri : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
gpointer _rgtk4_cb_ReallocFunc(gpointer data, gsize size) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(size)));
  SEXP _argv[1] = { _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_activate_action_full(GRemoteActionGroup* remote, const gchar* action_name, GVariant* parameter, GVariant* platform_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)remote, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)parameter, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)platform_data, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_change_action_state_full(GRemoteActionGroup* remote, const gchar* action_name, GVariant* value, GVariant* platform_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)remote, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)platform_data, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_reload(GResolver* resolver) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)resolver, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_lookup_by_name_async(GResolver* resolver, const gchar* hostname, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)resolver, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(hostname ? (const char*)hostname : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_lookup_by_address_async(GResolver* resolver, GInetAddress* address, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)resolver, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)address, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_lookup_service_async(GResolver* resolver, const gchar* rrname, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)resolver, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(rrname ? (const char*)rrname : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_lookup_records_async(GResolver* resolver, const gchar* rrname, GResolverRecordType record_type, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)resolver, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(rrname ? (const char*)rrname : ""));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(record_type)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_lookup_by_name_with_flags_async(GResolver* resolver, const gchar* hostname, GResolverNameLookupFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)resolver, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(hostname ? (const char*)hostname : ""));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
GVariant* _rgtk4_cb_read(GSettingsBackend* backend, const gchar* key, const GVariantType* expected_type, gboolean default_value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)backend, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(key ? (const char*)key : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)expected_type, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarLogical((int)(size_t)(default_value)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  GVariant* _result = (GVariant*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(5);
  return _result;
}
gboolean _rgtk4_cb_get_writable(GSettingsBackend* backend, const gchar* key) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)backend, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(key ? (const char*)key : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_write(GSettingsBackend* backend, const gchar* key, GVariant* value, gpointer origin_tag) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)backend, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(key ? (const char*)key : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)origin_tag, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(5);
  return _result;
}
gboolean _rgtk4_cb_write_tree(GSettingsBackend* backend, GTree* tree, gpointer origin_tag) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)backend, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)tree, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)origin_tag, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_subscribe(GSettingsBackend* backend, const gchar* name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)backend, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(name ? (const char*)name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_unsubscribe(GSettingsBackend* backend, const gchar* name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)backend, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(name ? (const char*)name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_sync(GSettingsBackend* backend) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)backend, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
GVariant* _rgtk4_cb_read_user_value(GSettingsBackend* backend, const gchar* key, const GVariantType* expected_type) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)backend, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(key ? (const char*)key : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)expected_type, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GVariant* _result = (GVariant*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_SettingsBindGetMapping(GValue* value, GVariant* variant, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)variant, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
GVariant* _rgtk4_cb_SettingsBindSetMapping(const GValue* value, const GVariantType* expected_type, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)expected_type, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GVariant* _result = (GVariant*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_writable_changed(GSettings* settings, const gchar* key) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)settings, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(key ? (const char*)key : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_writable_change_event(GSettings* settings, GQuark key) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)settings, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(key)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_change_event(GSettings* settings, const GQuark* keys, gint n_keys) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)settings, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)keys, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_keys)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_SettingsGetMapping(GVariant* value, gpointer* result, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)result, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_SimpleAsyncThreadFunc(GSimpleAsyncResult* res, GObject* object, GCancellable* cancellable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)res, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)object, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
PangoFontFamily* _rgtk4_cb_get_family(PangoFontMap* fontmap, const char* name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontmap, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(name ? (const char*)name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  PangoFontFamily* _result = (PangoFontFamily*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
gssize _rgtk4_cb_get_native_size(GSocketAddress* address) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)address, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gssize _result = (gssize)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_next_async(GSocketAddressEnumerator* enumerator, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)enumerator, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
int _rgtk4_cb_event(GtkCellArea* area, GtkCellAreaContext* context, GtkWidget* widget, GdkEvent* event, const GdkRectangle* cell_area, GtkCellRendererState flags) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)event, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cell_area, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 6, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(7);
  return _result;
}
GSocketAddressEnumerator* _rgtk4_cb_enumerate(GSocketConnectable* connectable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)connectable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GSocketAddressEnumerator* _result = (GSocketAddressEnumerator*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GSocketAddressEnumerator* _rgtk4_cb_proxy_enumerate(GSocketConnectable* connectable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)connectable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GSocketAddressEnumerator* _result = (GSocketAddressEnumerator*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_get_size(GdkPixbufAnimation* animation, int* width, int* height) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)animation, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)width, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)height, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
int _rgtk4_cb_get_level(GSocketControlMessage* message) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)message, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
int _rgtk4_cb_get_type(GSocketControlMessage* message) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)message, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_incoming(GSocketService* service, GSocketConnection* connection, GObject* source_object) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)service, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)connection, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)source_object, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_SocketSourceFunc(GSocket* socket, GIOCondition condition, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)socket, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(condition)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_TaskThreadFunc(GTask* task, gpointer source_object, gpointer task_data, GCancellable* cancellable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)task, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)source_object, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)task_data, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
gboolean _rgtk4_cb_run(GThreadedSocketService* service, GSocketConnection* connection, GObject* source_object) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)service, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)connection, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)source_object, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_supports_tls(GTlsBackend* backend) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)backend, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
GType _rgtk4_cb_get_certificate_type() {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  GType _result = (GType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : REAL(_r)[0]);
  UNPROTECT(1);
  return _result;
}
GType _rgtk4_cb_get_client_connection_type() {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  GType _result = (GType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : REAL(_r)[0]);
  UNPROTECT(1);
  return _result;
}
GType _rgtk4_cb_get_server_connection_type() {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  GType _result = (GType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : REAL(_r)[0]);
  UNPROTECT(1);
  return _result;
}
GType _rgtk4_cb_get_file_database_type() {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  GType _result = (GType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : REAL(_r)[0]);
  UNPROTECT(1);
  return _result;
}
GTlsDatabase* _rgtk4_cb_get_default_database(GTlsBackend* backend) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)backend, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GTlsDatabase* _result = (GTlsDatabase*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_supports_dtls(GTlsBackend* backend) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)backend, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
GType _rgtk4_cb_get_dtls_client_connection_type() {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  GType _result = (GType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : REAL(_r)[0]);
  UNPROTECT(1);
  return _result;
}
GType _rgtk4_cb_get_dtls_server_connection_type() {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  GType _result = (GType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : REAL(_r)[0]);
  UNPROTECT(1);
  return _result;
}
GTlsCertificateFlags _rgtk4_cb_verify(GTlsCertificate* cert, GSocketConnectable* identity, GTlsCertificate* trusted_ca) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cert, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)identity, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)trusted_ca, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GTlsCertificateFlags _result = (GTlsCertificateFlags)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : INTEGER(_r)[0]);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_copy_session_state(GTlsClientConnection* conn, GTlsClientConnection* source) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)conn, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)source, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_verify_chain_async(GTlsDatabase* self, GTlsCertificate* chain, const gchar* purpose, GSocketConnectable* identity, GTlsInteraction* interaction, GTlsDatabaseVerifyFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)chain, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_mkString(purpose ? (const char*)purpose : ""));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)identity, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)interaction, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a7 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a8 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[8] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7, _a8 };
  (void)rgtk4_eval_callback(rc, 8, _argv);
  UNPROTECT(8);
}
gchar* _rgtk4_cb_create_certificate_handle(GTlsDatabase* self, GTlsCertificate* certificate) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)certificate, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gchar* _result = (gchar*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_lookup_certificate_for_handle_async(GTlsDatabase* self, const gchar* handle, GTlsInteraction* interaction, GTlsDatabaseLookupFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(handle ? (const char*)handle : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)interaction, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_lookup_certificate_issuer_async(GTlsDatabase* self, GTlsCertificate* certificate, GTlsInteraction* interaction, GTlsDatabaseLookupFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)certificate, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)interaction, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_lookup_certificates_issued_by_async(GTlsDatabase* self, GByteArray* issuer_raw_dn, GTlsInteraction* interaction, GTlsDatabaseLookupFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)issuer_raw_dn, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)interaction, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_ask_password_async(GTlsInteraction* interaction, GTlsPassword* password, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)interaction, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)password, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_get_value(GtkTreeModel* tree_model, GtkTreeIter* iter, int column, GValue* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(column)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_set_value(GTlsPassword* password, guchar* value, gssize length, GDestroyNotify destroy) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)password, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(ssize_t)(length)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)destroy, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
const gchar* _rgtk4_cb_get_default_warning(GTlsPassword* password) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)password, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const gchar* _result = (const gchar*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_is_active(GVfs* vfs) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)vfs, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
GFile* _rgtk4_cb_get_file_for_path(GVfs* vfs, const char* path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)vfs, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(path ? (const char*)path : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GFile* _result = (GFile*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
GFile* _rgtk4_cb_get_file_for_uri(GVfs* vfs, const char* uri) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)vfs, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(uri ? (const char*)uri : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GFile* _result = (GFile*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
const gchar* const* _rgtk4_cb_get_supported_uri_schemes(GVfs* vfs) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)vfs, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const gchar* const* _result = (const gchar* const*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
GFile* _rgtk4_cb_parse_name(GVfs* vfs, const char* parse_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)vfs, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(parse_name ? (const char*)parse_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GFile* _result = (GFile*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_local_file_add_info(GVfs* vfs, const char* filename, guint64 device, GFileAttributeMatcher* attribute_matcher, GFileInfo* info, GCancellable* cancellable, gpointer* extra_data, GDestroyNotify* free_extra_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)vfs, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(filename ? (const char*)filename : ""));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(device)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)attribute_matcher, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)info, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a7 = PROTECT(R_MakeExternalPtr((void*)extra_data, R_NilValue, R_NilValue));
  SEXP _a8 = PROTECT(R_MakeExternalPtr((void*)free_extra_data, R_NilValue, R_NilValue));
  SEXP _argv[8] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7, _a8 };
  (void)rgtk4_eval_callback(rc, 8, _argv);
  UNPROTECT(8);
}
void _rgtk4_cb_add_writable_namespaces(GVfs* vfs, GFileAttributeInfoList* list) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)vfs, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)list, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_local_file_removed(GVfs* vfs, const char* filename) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)vfs, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(filename ? (const char*)filename : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_local_file_moved(GVfs* vfs, const char* source, const char* dest) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)vfs, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(source ? (const char*)source : ""));
  SEXP _a3 = PROTECT(Rf_mkString(dest ? (const char*)dest : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
GFile* _rgtk4_cb_VfsFileLookupFunc(GVfs* vfs, const char* identifier, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)vfs, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(identifier ? (const char*)identifier : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GFile* _result = (GFile*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_removed(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
GMount* _rgtk4_cb_get_mount(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GMount* _result = (GMount*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_can_mount(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_mount_fn(GVolume* volume, GMountMountFlags flags, GMountOperation* mount_operation, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mount_operation, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
gboolean _rgtk4_cb_should_automount(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
GFile* _rgtk4_cb_get_activation_root(GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GFile* _result = (GFile*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_volume_added(GVolumeMonitor* volume_monitor, GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_volume_removed(GVolumeMonitor* volume_monitor, GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_volume_changed(GVolumeMonitor* volume_monitor, GVolume* volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)volume, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_mount_added(GVolumeMonitor* volume_monitor, GMount* mount) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_mount_removed(GVolumeMonitor* volume_monitor, GMount* mount) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_mount_pre_unmount(GVolumeMonitor* volume_monitor, GMount* mount) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_mount_changed(GVolumeMonitor* volume_monitor, GMount* mount) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)mount, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_drive_connected(GVolumeMonitor* volume_monitor, GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_drive_disconnected(GVolumeMonitor* volume_monitor, GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_drive_changed(GVolumeMonitor* volume_monitor, GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
GList* _rgtk4_cb_get_connected_drives(GVolumeMonitor* volume_monitor) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GList* _result = (GList*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GList* _rgtk4_cb_get_mounts(GVolumeMonitor* volume_monitor) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GList* _result = (GList*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GVolume* _rgtk4_cb_get_volume_for_uuid(GVolumeMonitor* volume_monitor, const char* uuid) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(uuid ? (const char*)uuid : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GVolume* _result = (GVolume*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
GMount* _rgtk4_cb_get_mount_for_uuid(GVolumeMonitor* volume_monitor, const char* uuid) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(uuid ? (const char*)uuid : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GMount* _result = (GMount*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_drive_eject_button(GVolumeMonitor* volume_monitor, GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_drive_stop_button(GVolumeMonitor* volume_monitor, GDrive* drive) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)volume_monitor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)drive, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_ContentDeserializeFunc(GdkContentDeserializer* deserializer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)deserializer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_content_changed(GdkContentProvider* provider) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)provider, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_attach_clipboard(GdkContentProvider* provider, GdkClipboard* clipboard) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)provider, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)clipboard, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_detach_clipboard(GdkContentProvider* provider, GdkClipboard* clipboard) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)provider, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)clipboard, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
GdkContentFormats* _rgtk4_cb_ref_formats(GdkContentProvider* provider) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)provider, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GdkContentFormats* _result = (GdkContentFormats*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GdkContentFormats* _rgtk4_cb_ref_storable_formats(GdkContentProvider* provider) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)provider, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GdkContentFormats* _result = (GdkContentFormats*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_write_mime_type_async(GdkContentProvider* provider, const char* mime_type, GOutputStream* stream, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)provider, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(mime_type ? (const char*)mime_type : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)stream, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(io_priority)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)cancellable, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_ContentSerializeFunc(GdkContentSerializer* serializer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)serializer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
GdkTexture* _rgtk4_cb_CursorGetTextureCallback(GdkCursor* cursor, int cursor_size, double scale, int* width, int* height, int* hotspot_x, int* hotspot_y, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cursor, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(cursor_size)));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(scale)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)width, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)height, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)hotspot_x, R_NilValue, R_NilValue));
  SEXP _a7 = PROTECT(R_MakeExternalPtr((void*)hotspot_y, R_NilValue, R_NilValue));
  SEXP _argv[7] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 7, _argv));
  GdkTexture* _result = (GdkTexture*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(8);
  return _result;
}
void _rgtk4_cb_snapshot(GtkWidget* widget, GtkSnapshot* snapshot) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)snapshot, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
GdkPaintable* _rgtk4_cb_get_current_image(GdkPaintable* paintable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)paintable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GdkPaintable* _result = (GdkPaintable*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GtkTreeModelFlags _rgtk4_cb_get_flags(GtkTreeModel* tree_model) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkTreeModelFlags _result = (GtkTreeModelFlags)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : INTEGER(_r)[0]);
  UNPROTECT(2);
  return _result;
}
int _rgtk4_cb_get_intrinsic_width(GdkPaintable* paintable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)paintable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
int _rgtk4_cb_get_intrinsic_height(GdkPaintable* paintable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)paintable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
double _rgtk4_cb_get_intrinsic_aspect_ratio(GdkPaintable* paintable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)paintable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  double _result = (double)Rf_asReal(_r);
  UNPROTECT(2);
  return _result;
}
unsigned int _rgtk4_cb_get_n_links(GtkAccessibleHypertext* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  unsigned int _result = (unsigned int)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
GtkAccessibleHyperlink* _rgtk4_cb_get_link(GtkAccessibleHypertext* self, unsigned int index) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(index)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GtkAccessibleHyperlink* _result = (GtkAccessibleHyperlink*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
unsigned int _rgtk4_cb_get_link_at(GtkAccessibleHypertext* self, unsigned int offset) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(offset)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  unsigned int _result = (unsigned int)Rf_asInteger(_r);
  UNPROTECT(3);
  return _result;
}
GtkATContext* _rgtk4_cb_get_at_context(GtkAccessible* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkATContext* _result = (GtkATContext*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_get_platform_state(GtkAccessible* self, GtkAccessiblePlatformState state) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(state)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
GtkAccessible* _rgtk4_cb_get_accessible_parent(GtkAccessible* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkAccessible* _result = (GtkAccessible*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GtkAccessible* _rgtk4_cb_get_first_accessible_child(GtkAccessible* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkAccessible* _result = (GtkAccessible*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GtkAccessible* _rgtk4_cb_get_next_accessible_sibling(GtkAccessible* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkAccessible* _result = (GtkAccessible*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_get_bounds(GtkAccessible* self, int* x, int* y, int* width, int* height) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)x, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)y, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)width, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)height, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 5, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(6);
  return _result;
}
char* _rgtk4_cb_get_accessible_id(GtkAccessible* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_set_current_value(GtkAccessibleRange* self, double value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(value)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
GBytes* _rgtk4_cb_get_contents(GtkAccessibleText* self, unsigned int start, unsigned int end) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(start)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(end)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GBytes* _result = (GBytes*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(4);
  return _result;
}
GBytes* _rgtk4_cb_get_contents_at(GtkAccessibleText* self, unsigned int offset, GtkAccessibleTextGranularity granularity, unsigned int* start, unsigned int* end) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(offset)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(granularity)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)start, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)end, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 5, _argv));
  GBytes* _result = (GBytes*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(6);
  return _result;
}
unsigned int _rgtk4_cb_get_caret_position(GtkAccessibleText* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  unsigned int _result = (unsigned int)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_get_selection(GtkAccessibleText* self, gsize* n_ranges, GtkAccessibleTextRange** ranges) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)n_ranges, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)ranges, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_get_attributes(GtkAccessibleText* self, unsigned int offset, gsize* n_ranges, GtkAccessibleTextRange** ranges, char*** attribute_names, char*** attribute_values) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(offset)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)n_ranges, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)ranges, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)attribute_names, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)attribute_values, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 6, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(7);
  return _result;
}
void _rgtk4_cb_get_default_attributes(GtkAccessibleText* self, char*** attribute_names, char*** attribute_values) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)attribute_names, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)attribute_values, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_get_extents(GtkAccessibleText* self, unsigned int start, unsigned int end, graphene_rect_t* extents) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(start)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(end)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)extents, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(5);
  return _result;
}
gboolean _rgtk4_cb_get_offset(GtkAccessibleText* self, const graphene_point_t* point, unsigned int* offset) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)point, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)offset, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_set_caret_position(GtkAccessibleText* self, unsigned int offset) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(offset)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_set_selection(GtkSelectionModel* model, GtkBitset* selected, GtkBitset* mask) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)selected, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mask, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
const char* _rgtk4_cb_get_action_name(GtkActionable* actionable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)actionable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const char* _result = (const char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_set_action_name(GtkActionable* actionable, const char* action_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)actionable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
GVariant* _rgtk4_cb_get_action_target_value(GtkActionable* actionable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)actionable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GVariant* _result = (GVariant*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_set_action_target_value(GtkActionable* actionable, GVariant* target_value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)actionable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)target_value, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_value_changed(GtkScaleButton* button, double value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)button, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(value)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb__gtk_reserved1() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__gtk_reserved2() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__gtk_reserved3() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__gtk_reserved4() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_window_added(GtkApplication* application, GtkWindow* window) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)window, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_window_removed(GtkApplication* application, GtkWindow* window) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)application, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)window, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
int _rgtk4_cb_AssistantPageFunc(int current_page, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(Rf_ScalarInteger((int)(size_t)(current_page)));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_set_id(GtkBuildable* buildable, const char* id) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buildable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(id ? (const char*)id : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_add_child(GtkBuildable* buildable, GtkBuilder* builder, GObject* child, const char* type) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buildable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)builder, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)child, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_mkString(type ? (const char*)type : ""));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_set_buildable_property(GtkBuildable* buildable, GtkBuilder* builder, const char* name, const GValue* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buildable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)builder, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_mkString(name ? (const char*)name : ""));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
gboolean _rgtk4_cb_custom_tag_start(GtkBuildable* buildable, GtkBuilder* builder, GObject* child, const char* tagname, GtkBuildableParser* parser, gpointer* data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buildable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)builder, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)child, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_mkString(tagname ? (const char*)tagname : ""));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)parser, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)data, R_NilValue, R_NilValue));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 6, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(7);
  return _result;
}
void _rgtk4_cb_custom_tag_end(GtkBuildable* buildable, GtkBuilder* builder, GObject* child, const char* tagname, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buildable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)builder, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)child, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_mkString(tagname ? (const char*)tagname : ""));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_custom_finished(GtkBuildable* buildable, GtkBuilder* builder, GObject* child, const char* tagname, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buildable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)builder, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)child, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_mkString(tagname ? (const char*)tagname : ""));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_parser_finished(GtkBuildable* buildable, GtkBuilder* builder) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buildable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)builder, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
GObject* _rgtk4_cb_get_internal_child(GtkBuildable* buildable, GtkBuilder* builder, const char* childname) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buildable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)builder, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_mkString(childname ? (const char*)childname : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GObject* _result = (GObject*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(4);
  return _result;
}
GType _rgtk4_cb_get_type_from_name(GtkBuilderScope* self, GtkBuilder* builder, const char* type_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)builder, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_mkString(type_name ? (const char*)type_name : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GType _result = (GType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : REAL(_r)[0]);
  UNPROTECT(4);
  return _result;
}
GType _rgtk4_cb_get_type_from_function(GtkBuilderScope* self, GtkBuilder* builder, const char* function_name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)builder, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_mkString(function_name ? (const char*)function_name : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GType _result = (GType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : REAL(_r)[0]);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_clicked(GtkButton* button) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)button, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_CellAllocCallback(GtkCellRenderer* renderer, const GdkRectangle* cell_area, const GdkRectangle* cell_background, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cell_area, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cell_background, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_add(GtkCellArea* area, GtkCellRenderer* renderer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_remove(GtkCellArea* area, GtkCellRenderer* renderer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_foreach(PangoFontset* fontset, PangoFontsetForeachFunc func, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontset, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)func, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_foreach_alloc(GtkCellArea* area, GtkCellAreaContext* context, GtkWidget* widget, const GdkRectangle* cell_area, const GdkRectangle* background_area, GtkCellAllocCallback callback, gpointer callback_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cell_area, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)background_area, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)callback, R_NilValue, R_NilValue));
  SEXP _a7 = PROTECT(R_MakeExternalPtr((void*)callback_data, R_NilValue, R_NilValue));
  SEXP _argv[7] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7 };
  (void)rgtk4_eval_callback(rc, 7, _argv);
  UNPROTECT(7);
}
void _rgtk4_cb_apply_attributes(GtkCellArea* area, GtkTreeModel* tree_model, GtkTreeIter* iter, gboolean is_expander, gboolean is_expanded) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarLogical((int)(size_t)(is_expander)));
  SEXP _a5 = PROTECT(Rf_ScalarLogical((int)(size_t)(is_expanded)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
GtkCellAreaContext* _rgtk4_cb_create_context(GtkCellArea* area) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkCellAreaContext* _result = (GtkCellAreaContext*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GtkCellAreaContext* _rgtk4_cb_copy_context(GtkCellArea* area, GtkCellAreaContext* context) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GtkCellAreaContext* _result = (GtkCellAreaContext*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
GtkSizeRequestMode _rgtk4_cb_get_request_mode(GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkSizeRequestMode _result = (GtkSizeRequestMode)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : INTEGER(_r)[0]);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_get_preferred_width(GtkCellRenderer* cell, GtkWidget* widget, int* minimum_size, int* natural_size) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)minimum_size, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)natural_size, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_get_preferred_height_for_width(GtkCellRenderer* cell, GtkWidget* widget, int width, int* minimum_height, int* natural_height) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(width)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)minimum_height, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)natural_height, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_get_preferred_height(GtkCellRenderer* cell, GtkWidget* widget, int* minimum_size, int* natural_size) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)minimum_size, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)natural_size, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_get_preferred_width_for_height(GtkCellRenderer* cell, GtkWidget* widget, int height, int* minimum_width, int* natural_width) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(height)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)minimum_width, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)natural_width, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_set_cell_property(GtkCellArea* area, GtkCellRenderer* renderer, guint property_id, const GValue* value, GParamSpec* pspec) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(property_id)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_get_cell_property(GtkCellArea* area, GtkCellRenderer* renderer, guint property_id, GValue* value, GParamSpec* pspec) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(property_id)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)pspec, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
gboolean _rgtk4_cb_focus(GtkWidget* widget, GtkDirectionType direction) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(direction)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_is_activatable(GtkCellArea* area) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_allocate(GtkLayoutManager* manager, GtkWidget* widget, int width, int height, int baseline) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)manager, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(width)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(height)));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(baseline)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
gboolean _rgtk4_cb_CellCallback(GtkCellRenderer* renderer, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_editing_done(GtkCellEditable* cell_editable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_editable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_remove_widget(GtkCellEditable* cell_editable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_editable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
GtkCellEditable* _rgtk4_cb_start_editing(GtkCellRenderer* cell, GdkEvent* event, GtkWidget* widget, const char* path, const GdkRectangle* background_area, const GdkRectangle* cell_area, GtkCellRendererState flags) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)event, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_mkString(path ? (const char*)path : ""));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)background_area, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)cell_area, R_NilValue, R_NilValue));
  SEXP _a7 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _argv[7] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 7, _argv));
  GtkCellEditable* _result = (GtkCellEditable*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(8);
  return _result;
}
void _rgtk4_cb_CellLayoutDataFunc(GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_layout, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_pack_start(GtkCellLayout* cell_layout, GtkCellRenderer* cell, gboolean expand) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_layout, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarLogical((int)(size_t)(expand)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_pack_end(GtkCellLayout* cell_layout, GtkCellRenderer* cell, gboolean expand) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_layout, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarLogical((int)(size_t)(expand)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_clear(GtkCellLayout* cell_layout) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_layout, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_add_attribute(GtkCellLayout* cell_layout, GtkCellRenderer* cell, const char* attribute, int column) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_layout, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_mkString(attribute ? (const char*)attribute : ""));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(column)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_set_cell_data_func(GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkCellLayoutDataFunc func, gpointer func_data, GDestroyNotify destroy) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_layout, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)func, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)func_data, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)destroy, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_clear_attributes(GtkCellLayout* cell_layout, GtkCellRenderer* cell) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_layout, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_reorder(GtkCellLayout* cell_layout, GtkCellRenderer* cell, int position) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_layout, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
GList* _rgtk4_cb_get_cells(GtkCellLayout* cell_layout) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_layout, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GList* _result = (GList*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
GtkCellArea* _rgtk4_cb_get_area(GtkCellLayout* cell_layout) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_layout, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkCellArea* _result = (GtkCellArea*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_get_aligned_area(GtkCellRenderer* cell, GtkWidget* widget, GtkCellRendererState flags, const GdkRectangle* cell_area, GdkRectangle* aligned_area) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cell_area, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)aligned_area, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_editing_canceled(GtkCellRenderer* cell) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_editing_started(GtkCellRenderer* cell, GtkCellEditable* editable, const char* path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)editable, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_mkString(path ? (const char*)path : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_edited(GtkCellRendererText* cell_renderer_text, const char* path, const char* new_text) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)cell_renderer_text, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(path ? (const char*)path : ""));
  SEXP _a3 = PROTECT(Rf_mkString(new_text ? (const char*)new_text : ""));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_toggled(GtkToggleButton* toggle_button) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)toggle_button, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_get_rgba(GtkColorChooser* chooser, GdkRGBA* color) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)chooser, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)color, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_set_rgba(GtkColorChooser* chooser, const GdkRGBA* color) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)chooser, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)color, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_add_palette(GtkColorChooser* chooser, GtkOrientation orientation, int colors_per_line, int n_colors, GdkRGBA* colors) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)chooser, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(orientation)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(colors_per_line)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_colors)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)colors, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_color_activated(GtkColorChooser* chooser, const GdkRGBA* color) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)chooser, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)color, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
char* _rgtk4_cb_format_entry_text(GtkComboBox* combo_box, const char* path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)combo_box, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(path ? (const char*)path : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_CustomAllocateFunc(GtkWidget* widget, int width, int height, int baseline) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(width)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(height)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(baseline)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
gboolean _rgtk4_cb_CustomFilterFunc(gpointer item, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)item, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_CustomMeasureFunc(GtkWidget* widget, GtkOrientation orientation, int for_size, int* minimum, int* natural, int* minimum_baseline, int* natural_baseline) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(orientation)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(for_size)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)minimum, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)natural, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)minimum_baseline, R_NilValue, R_NilValue));
  SEXP _a7 = PROTECT(R_MakeExternalPtr((void*)natural_baseline, R_NilValue, R_NilValue));
  SEXP _argv[7] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7 };
  (void)rgtk4_eval_callback(rc, 7, _argv);
  UNPROTECT(7);
}
GtkSizeRequestMode _rgtk4_cb_CustomRequestModeFunc(GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkSizeRequestMode _result = (GtkSizeRequestMode)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : INTEGER(_r)[0]);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_response(GtkNativeDialog* self, int response_id) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(response_id)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_close(GtkMediaFile* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_resize(GtkGLArea* area, int width, int height) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(width)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(height)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_DrawingAreaDrawFunc(GtkDrawingArea* drawing_area, cairo_t* cr, int width, int height, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drawing_area, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cr, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(width)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(height)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_insert_text(GtkTextBuffer* buffer, GtkTextIter* pos, const char* new_text, int new_text_length) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)pos, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_mkString(new_text ? (const char*)new_text : ""));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(new_text_length)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
guint _rgtk4_cb_delete_text(GtkEntryBuffer* buffer, guint position, guint n_chars) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_chars)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  guint _result = (guint)Rf_asInteger(_r);
  UNPROTECT(4);
  return _result;
}
const char* _rgtk4_cb_get_text(GtkEntryBuffer* buffer, gsize* n_bytes) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)n_bytes, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  const char* _result = (const char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_do_insert_text(GtkEditable* editable, const char* text, int length, int* position) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)editable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(text ? (const char*)text : ""));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(length)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)position, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_do_delete_text(GtkEditable* editable, int start_pos, int end_pos) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)editable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(start_pos)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(end_pos)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_get_selection_bounds(GtkEditable* editable, int* start_pos, int* end_pos) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)editable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)start_pos, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)end_pos, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_set_selection_bounds(GtkEditable* editable, int start_pos, int end_pos) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)editable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(start_pos)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(end_pos)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
GtkEditable* _rgtk4_cb_get_delegate(GtkEditable* editable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)editable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkEditable* _result = (GtkEditable*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_inserted_text(GtkEntryBuffer* buffer, guint position, const char* chars, guint n_chars) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _a3 = PROTECT(Rf_mkString(chars ? (const char*)chars : ""));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_chars)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_deleted_text(GtkEntryBuffer* buffer, guint position, guint n_chars) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_chars)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
guint _rgtk4_cb_get_length(GtkEntryBuffer* buffer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  guint _result = (guint)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb__gtk_reserved5() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__gtk_reserved6() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__gtk_reserved7() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__gtk_reserved8() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
gboolean _rgtk4_cb_EntryCompletionMatchFunc(GtkEntryCompletion* completion, const char* key, GtkTreeIter* iter, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)completion, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(key ? (const char*)key : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_ExpressionNotify(gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
gboolean _rgtk4_cb_match(GtkFilter* self, gpointer item) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)item, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
GtkFilterMatch _rgtk4_cb_get_strictness(GtkFilter* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkFilterMatch _result = (GtkFilterMatch)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : INTEGER(_r)[0]);
  UNPROTECT(2);
  return _result;
}
GtkWidget* _rgtk4_cb_FlowBoxCreateWidgetFunc(gpointer item, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)item, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkWidget* _result = (GtkWidget*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_FlowBoxFilterFunc(GtkFlowBoxChild* child, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)child, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_FlowBoxForeachFunc(GtkFlowBox* box, GtkFlowBoxChild* child, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)box, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)child, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
int _rgtk4_cb_FlowBoxSortFunc(GtkFlowBoxChild* child1, GtkFlowBoxChild* child2, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)child1, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)child2, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(3);
  return _result;
}
PangoFontFamily* _rgtk4_cb_get_font_family(GtkFontChooser* fontchooser) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontchooser, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  PangoFontFamily* _result = (PangoFontFamily*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
PangoFontFace* _rgtk4_cb_get_font_face(GtkFontChooser* fontchooser) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontchooser, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  PangoFontFace* _result = (PangoFontFace*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
int _rgtk4_cb_get_font_size(GtkFontChooser* fontchooser) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontchooser, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_set_filter_func(GtkFontChooser* fontchooser, GtkFontFilterFunc filter, gpointer user_data, GDestroyNotify destroy) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontchooser, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)filter, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)destroy, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a4 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_font_activated(GtkFontChooser* chooser, const char* fontname) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)chooser, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(fontname ? (const char*)fontname : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_set_font_map(GtkFontChooser* fontchooser, PangoFontMap* fontmap) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontchooser, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)fontmap, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
PangoFontMap* _rgtk4_cb_get_font_map(PangoFont* font) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)font, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  PangoFontMap* _result = (PangoFontMap*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_FontFilterFunc(const PangoFontFamily* family, const PangoFontFace* face, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)family, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)face, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_compute_child_allocation(GtkFrame* frame, GtkAllocation* allocation) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)frame, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)allocation, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_render(GtkGLArea* area, GdkGLContext* context) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_preedit_start(GtkIMContext* context) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_preedit_end(GtkIMContext* context) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_preedit_changed(GtkIMContext* context) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_commit(GtkIMContext* context, const char* str) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(str ? (const char*)str : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_retrieve_surrounding(GtkIMContext* context) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_delete_surrounding(GtkIMContext* context, int offset, int n_chars) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(offset)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_chars)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_set_client_widget(GtkIMContext* context, GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_get_preedit_string(GtkIMContext* context, char** str, PangoAttrList** attrs, int* cursor_pos) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(str ? (const char*)str : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)attrs, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)cursor_pos, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
gboolean _rgtk4_cb_filter_keypress(GtkIMContext* context, GdkEvent* event) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)event, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_focus_in(GtkIMContext* context) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_focus_out(GtkIMContext* context) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_set_cursor_location(GtkIMContext* context, GdkRectangle* area) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)area, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_set_use_preedit(GtkIMContext* context, gboolean use_preedit) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarLogical((int)(size_t)(use_preedit)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_set_surrounding(GtkIMContext* context, const char* text, int len, int cursor_index) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(text ? (const char*)text : ""));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(len)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(cursor_index)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
gboolean _rgtk4_cb_get_surrounding(GtkIMContext* context, char** text, int* cursor_index) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(text ? (const char*)text : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cursor_index, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_set_surrounding_with_selection(GtkIMContext* context, const char* text, int len, int cursor_index, int anchor_index) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(text ? (const char*)text : ""));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(len)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(cursor_index)));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(anchor_index)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
gboolean _rgtk4_cb_get_surrounding_with_selection(GtkIMContext* context, char** text, int* cursor_index, int* anchor_index) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(text ? (const char*)text : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)cursor_index, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)anchor_index, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(5);
  return _result;
}
void _rgtk4_cb_activate_osk(GtkIMContext* context) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_activate_osk_with_event(GtkIMContext* context, GdkEvent* event) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)event, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_invalid_composition(GtkIMContext* context, const char* str) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(str ? (const char*)str : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_IconViewForeachFunc(GtkIconView* icon_view, GtkTreePath* path, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)icon_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_measure(GtkWidget* widget, GtkOrientation orientation, int for_size, int* minimum, int* natural, int* minimum_baseline, int* natural_baseline) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(orientation)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(for_size)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)minimum, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)natural, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(R_MakeExternalPtr((void*)minimum_baseline, R_NilValue, R_NilValue));
  SEXP _a7 = PROTECT(R_MakeExternalPtr((void*)natural_baseline, R_NilValue, R_NilValue));
  SEXP _argv[7] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7 };
  (void)rgtk4_eval_callback(rc, 7, _argv);
  UNPROTECT(7);
}
GtkLayoutChild* _rgtk4_cb_create_layout_child(GtkLayoutManager* manager, GtkWidget* widget, GtkWidget* for_child) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)manager, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)for_child, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GtkLayoutChild* _result = (GtkLayoutChild*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_root(GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_unroot(GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
GtkWidget* _rgtk4_cb_ListBoxCreateWidgetFunc(gpointer item, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)item, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkWidget* _result = (GtkWidget*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_ListBoxFilterFunc(GtkListBoxRow* row, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)row, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_ListBoxForeachFunc(GtkListBox* box, GtkListBoxRow* row, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)box, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)row, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
int _rgtk4_cb_ListBoxSortFunc(GtkListBoxRow* row1, GtkListBoxRow* row2, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)row1, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)row2, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_ListBoxUpdateHeaderFunc(GtkListBoxRow* row, GtkListBoxRow* before, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)row, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)before, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gpointer _rgtk4_cb_MapListModelMapFunc(gpointer item, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)item, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_play(GtkMediaStream* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_pause(GtkMediaStream* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_update_audio(GtkMediaStream* self, gboolean muted, double volume) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarLogical((int)(size_t)(muted)));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(volume)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_realize(GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_unrealize(GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_MenuButtonCreatePopupFunc(GtkMenuButton* menu_button, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)menu_button, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_show(GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_hide(GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_closed(GdkPixbufLoader* loader) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)loader, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_activate_default(GtkWindow* window) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)window, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_is_selected(GtkSelectionModel* model, guint position) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_PrintSettingsFunc(const char* key, const char* value, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(Rf_mkString(key ? (const char*)key : ""));
  SEXP _a2 = PROTECT(Rf_mkString(value ? (const char*)value : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_adjust_bounds(GtkRange* range, double new_value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)range, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(new_value)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_move_slider(GtkRange* range, GtkScrollType scroll) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)range, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(scroll)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_get_range_border(GtkRange* range, GtkBorder* border_) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)range, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)border_, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_change_value(GtkRange* range, GtkScrollType scroll, double new_value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)range, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(scroll)));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(new_value)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb__gtk_recent1() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__gtk_recent2() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__gtk_recent3() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__gtk_recent4() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_get_layout_offsets(GtkScale* scale, int* x, int* y) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)scale, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)x, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)y, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
char* _rgtk4_cb_ScaleFormatValueFunc(GtkScale* scale, double value, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)scale, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(value)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  char* _result = (char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_get_border(GtkScrollable* scrollable, GtkBorder* border) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)scrollable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)border, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_get_section(GtkSectionModel* self, guint position, guint* out_start, guint* out_end) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)out_start, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)out_end, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
GtkBitset* _rgtk4_cb_get_selection_in_range(GtkSelectionModel* model, guint position, guint n_items) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_items)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GtkBitset* _result = (GtkBitset*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_select_item(GtkSelectionModel* model, guint position, gboolean unselect_rest) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _a3 = PROTECT(Rf_ScalarLogical((int)(size_t)(unselect_rest)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_unselect_item(GtkSelectionModel* model, guint position) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_select_range(GtkSelectionModel* model, guint position, guint n_items, gboolean unselect_rest) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_items)));
  SEXP _a4 = PROTECT(Rf_ScalarLogical((int)(size_t)(unselect_rest)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(5);
  return _result;
}
gboolean _rgtk4_cb_unselect_range(GtkSelectionModel* model, guint position, guint n_items) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(n_items)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_select_all(GtkTreeView* tree_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_unselect_all(GtkTreeView* tree_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_ShortcutFunc(GtkWidget* widget, GVariant* args, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)args, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_add_controller(GtkShortcutManager* self, GtkShortcutController* controller) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)controller, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_remove_controller(GtkShortcutManager* self, GtkShortcutController* controller) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)controller, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
GtkOrdering _rgtk4_cb_compare(GtkSorter* self, gpointer item1, gpointer item2) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)item1, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)item2, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  GtkOrdering _result = (GtkOrdering)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : INTEGER(_r)[0]);
  UNPROTECT(4);
  return _result;
}
GtkSorterOrder _rgtk4_cb_get_order(GtkSorter* self) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GtkSorterOrder _result = (GtkSorterOrder)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : INTEGER(_r)[0]);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_snapshot_symbolic(GtkSymbolicPaintable* paintable, GdkSnapshot* snapshot, double width, double height, const GdkRGBA* colors, gsize n_colors) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)paintable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)snapshot, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(width)));
  SEXP _a4 = PROTECT(Rf_ScalarReal((double)(size_t)(height)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)colors, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(Rf_ScalarReal((double)(size_t)(n_colors)));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_snapshot_with_weight(GtkSymbolicPaintable* paintable, GdkSnapshot* snapshot, double width, double height, const GdkRGBA* colors, gsize n_colors, double weight) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)paintable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)snapshot, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(width)));
  SEXP _a4 = PROTECT(Rf_ScalarReal((double)(size_t)(height)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)colors, R_NilValue, R_NilValue));
  SEXP _a6 = PROTECT(Rf_ScalarReal((double)(size_t)(n_colors)));
  SEXP _a7 = PROTECT(Rf_ScalarReal((double)(size_t)(weight)));
  SEXP _argv[7] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7 };
  (void)rgtk4_eval_callback(rc, 7, _argv);
  UNPROTECT(7);
}
void _rgtk4_cb_insert_paintable(GtkTextBuffer* buffer, GtkTextIter* iter, GdkPaintable* paintable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)paintable, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_insert_child_anchor(GtkTextBuffer* buffer, GtkTextIter* iter, GtkTextChildAnchor* anchor) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)anchor, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_delete_range(GtkTextBuffer* buffer, GtkTextIter* start, GtkTextIter* end) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)start, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)end, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_modified_changed(GtkTextBuffer* buffer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_mark_set(GtkTextBuffer* buffer, const GtkTextIter* location, GtkTextMark* mark) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)location, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)mark, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_mark_deleted(GtkTextBuffer* buffer, GtkTextMark* mark) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)mark, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_apply_tag(GtkTextBuffer* buffer, GtkTextTag* tag, const GtkTextIter* start, const GtkTextIter* end) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)tag, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)start, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)end, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_remove_tag(GtkTextBuffer* buffer, GtkTextTag* tag, const GtkTextIter* start, const GtkTextIter* end) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)tag, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)start, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)end, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_begin_user_action(GtkTextBuffer* buffer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_end_user_action(GtkTextBuffer* buffer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_paste_done(GtkTextBuffer* buffer, GdkClipboard* clipboard) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)clipboard, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_undo(GtkTextBuffer* buffer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_redo(GtkTextBuffer* buffer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_TextBufferCommitNotify(GtkTextBuffer* buffer, GtkTextBufferNotifyFlags flags, guint position, guint length, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buffer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(flags)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(position)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(length)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
gboolean _rgtk4_cb_TextCharPredicate(gunichar ch, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(Rf_ScalarInteger((int)(size_t)(ch)));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_TextTagTableForeach(GtkTextTag* tag, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tag, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_move_cursor(GtkTreeView* tree_view, GtkMovementStep step, int count, gboolean extend, gboolean modify) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(step)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(count)));
  SEXP _a4 = PROTECT(Rf_ScalarLogical((int)(size_t)(extend)));
  SEXP _a5 = PROTECT(Rf_ScalarLogical((int)(size_t)(modify)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 5, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(6);
  return _result;
}
void _rgtk4_cb_set_anchor(GtkTextView* text_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)text_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_insert_at_cursor(GtkTextView* text_view, const char* str) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)text_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(str ? (const char*)str : ""));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_delete_from_cursor(GtkTextView* text_view, GtkDeleteType type, int count) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)text_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(type)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(count)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_backspace(GtkTextView* text_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)text_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_cut_clipboard(GtkTextView* text_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)text_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_copy_clipboard(GtkTextView* text_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)text_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_paste_clipboard(GtkTextView* text_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)text_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_toggle_overwrite(GtkTextView* text_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)text_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_snapshot_layer(GtkTextView* text_view, GtkTextViewLayer layer, GtkSnapshot* snapshot) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)text_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(layer)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)snapshot, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_extend_selection(GtkTextView* text_view, GtkTextExtendSelection granularity, const GtkTextIter* location, GtkTextIter* start, GtkTextIter* end) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)text_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(granularity)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)location, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)start, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)end, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 5, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(6);
  return _result;
}
void _rgtk4_cb_insert_emoji(GtkTextView* text_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)text_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_TickCallback(GtkWidget* widget, GdkFrameClock* frame_clock, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)frame_clock, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_TreeCellDataFunc(GtkTreeViewColumn* tree_column, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_column, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)cell, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
gboolean _rgtk4_cb_drag_data_received(GtkTreeDragDest* drag_dest, GtkTreePath* dest, const GValue* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drag_dest, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)dest, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_row_drop_possible(GtkTreeDragDest* drag_dest, GtkTreePath* dest_path, const GValue* value) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drag_dest, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)dest_path, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_row_draggable(GtkTreeDragSource* drag_source, GtkTreePath* path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drag_source, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
GdkContentProvider* _rgtk4_cb_drag_data_get(GtkTreeDragSource* drag_source, GtkTreePath* path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drag_source, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GdkContentProvider* _result = (GdkContentProvider*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_drag_data_delete(GtkTreeDragSource* drag_source, GtkTreePath* path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)drag_source, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
int _rgtk4_cb_TreeIterCompareFunc(GtkTreeModel* model, GtkTreeIter* a, GtkTreeIter* b, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)a, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)b, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(4);
  return _result;
}
GListModel* _rgtk4_cb_TreeListModelCreateModelFunc(gpointer item, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)item, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GListModel* _result = (GListModel*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_visible(GtkTreeModelFilter* self, GtkTreeModel* child_model, GtkTreeIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)child_model, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_modify(GtkTreeModelFilter* self, GtkTreeModel* child_model, GtkTreeIter* iter, GValue* value, int column) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)self, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)child_model, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(column)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_TreeModelFilterModifyFunc(GtkTreeModel* model, GtkTreeIter* iter, GValue* value, int column, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)value, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(column)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
gboolean _rgtk4_cb_TreeModelFilterVisibleFunc(GtkTreeModel* model, GtkTreeIter* iter, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_TreeModelForeachFunc(GtkTreeModel* model, GtkTreePath* path, GtkTreeIter* iter, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_row_changed(GtkTreeModel* tree_model, GtkTreePath* path, GtkTreeIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_row_inserted(GtkTreeModel* tree_model, GtkTreePath* path, GtkTreeIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_row_has_child_toggled(GtkTreeModel* tree_model, GtkTreePath* path, GtkTreeIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_row_deleted(GtkTreeModel* tree_model, GtkTreePath* path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_rows_reordered(GtkTreeModel* tree_model, GtkTreePath* path, GtkTreeIter* iter, int* new_order) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)new_order, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
int _rgtk4_cb_get_n_columns(GtkTreeModel* tree_model) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
GType _rgtk4_cb_get_column_type(GtkTreeModel* tree_model, int index_) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(index_)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GType _result = (GType)(TYPEOF(_r)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(_r) : REAL(_r)[0]);
  UNPROTECT(3);
  return _result;
}
GdkPixbufAnimationIter* _rgtk4_cb_get_iter(GdkPixbufAnimation* animation, const GTimeVal* start_time) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)animation, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)start_time, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GdkPixbufAnimationIter* _result = (GdkPixbufAnimationIter*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_iter_next(GtkTreeModel* tree_model, GtkTreeIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_iter_previous(GtkTreeModel* tree_model, GtkTreeIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_iter_children(GtkTreeModel* tree_model, GtkTreeIter* iter, GtkTreeIter* parent) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)parent, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_iter_has_child(GtkTreeModel* tree_model, GtkTreeIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
int _rgtk4_cb_iter_n_children(GtkTreeModel* tree_model, GtkTreeIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_iter_nth_child(GtkTreeModel* tree_model, GtkTreeIter* iter, GtkTreeIter* parent, int n) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)parent, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(n)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(5);
  return _result;
}
gboolean _rgtk4_cb_iter_parent(GtkTreeModel* tree_model, GtkTreeIter* iter, GtkTreeIter* child) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)child, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_ref_node(GtkTreeModel* tree_model, GtkTreeIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_unref_node(GtkTreeModel* tree_model, GtkTreeIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_TreeSelectionForeachFunc(GtkTreeModel* model, GtkTreePath* path, GtkTreeIter* iter, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_TreeSelectionFunc(GtkTreeSelection* selection, GtkTreeModel* model, GtkTreePath* path, gboolean path_currently_selected, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)selection, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarLogical((int)(size_t)(path_currently_selected)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(5);
  return _result;
}
void _rgtk4_cb_sort_column_changed(GtkTreeSortable* sortable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)sortable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_get_sort_column_id(GtkTreeSortable* sortable, int* sort_column_id, GtkSortType* order) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)sortable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)sort_column_id, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)order, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_set_sort_column_id(GtkTreeSortable* sortable, int sort_column_id, GtkSortType order) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)sortable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(sort_column_id)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(order)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_set_sort_func(GtkTreeSortable* sortable, int sort_column_id, GtkTreeIterCompareFunc sort_func, gpointer user_data, GDestroyNotify destroy) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)sortable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(sort_column_id)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)sort_func, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)destroy, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a5 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_set_default_sort_func(GtkTreeSortable* sortable, GtkTreeIterCompareFunc sort_func, gpointer user_data, GDestroyNotify destroy) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)sortable, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)sort_func, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)destroy, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a4 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_has_default_sort_func(GtkTreeSortable* sortable) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)sortable, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_row_activated(GtkTreeView* tree_view, GtkTreePath* path, GtkTreeViewColumn* column) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)column, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_test_expand_row(GtkTreeView* tree_view, GtkTreeIter* iter, GtkTreePath* path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
gboolean _rgtk4_cb_test_collapse_row(GtkTreeView* tree_view, GtkTreeIter* iter, GtkTreePath* path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_row_expanded(GtkTreeView* tree_view, GtkTreeIter* iter, GtkTreePath* path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_row_collapsed(GtkTreeView* tree_view, GtkTreeIter* iter, GtkTreePath* path) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_columns_changed(GtkTreeView* tree_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_cursor_changed(GtkTreeView* tree_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_select_cursor_row(GtkTreeView* tree_view, gboolean start_editing) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarLogical((int)(size_t)(start_editing)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_toggle_cursor_row(GtkTreeView* tree_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_expand_collapse_cursor_row(GtkTreeView* tree_view, gboolean logical, gboolean expand, gboolean open_all) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarLogical((int)(size_t)(logical)));
  SEXP _a3 = PROTECT(Rf_ScalarLogical((int)(size_t)(expand)));
  SEXP _a4 = PROTECT(Rf_ScalarLogical((int)(size_t)(open_all)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(5);
  return _result;
}
gboolean _rgtk4_cb_select_cursor_parent(GtkTreeView* tree_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_start_interactive_search(GtkTreeView* tree_view) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_TreeViewColumnDropFunc(GtkTreeView* tree_view, GtkTreeViewColumn* column, GtkTreeViewColumn* prev_column, GtkTreeViewColumn* next_column, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)column, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)prev_column, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)next_column, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(5);
  return _result;
}
void _rgtk4_cb_TreeViewMappingFunc(GtkTreeView* tree_view, GtkTreePath* path, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)tree_view, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)path, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_TreeViewRowSeparatorFunc(GtkTreeModel* model, GtkTreeIter* iter, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_TreeViewSearchEqualFunc(GtkTreeModel* model, int column, const char* key, GtkTreeIter* iter, gpointer search_data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)model, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(column)));
  SEXP _a3 = PROTECT(Rf_mkString(key ? (const char*)key : ""));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)search_data, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 5, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(6);
  return _result;
}
void _rgtk4_cb_WidgetActionActivateFunc(GtkWidget* widget, const char* action_name, GVariant* parameter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(action_name ? (const char*)action_name : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)parameter, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_map(GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_unmap(GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_size_allocate(GtkWidget* widget, int width, int height, int baseline) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(width)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(height)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(baseline)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_state_flags_changed(GtkWidget* widget, GtkStateFlags previous_state_flags) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(previous_state_flags)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_direction_changed(GtkWidget* widget, GtkTextDirection previous_direction) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(previous_direction)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_mnemonic_activate(GtkWidget* widget, gboolean group_cycling) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarLogical((int)(size_t)(group_cycling)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_grab_focus(GtkWidget* widget) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_set_focus_child(GtkWidget* widget, GtkWidget* child) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)child, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_move_focus(GtkWidget* widget, GtkDirectionType direction) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(direction)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_keynav_failed(GtkWidget* widget, GtkDirectionType direction) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(direction)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_query_tooltip(GtkWidget* widget, int x, int y, gboolean keyboard_tooltip, GtkTooltip* tooltip) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(x)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(y)));
  SEXP _a4 = PROTECT(Rf_ScalarLogical((int)(size_t)(keyboard_tooltip)));
  SEXP _a5 = PROTECT(R_MakeExternalPtr((void*)tooltip, R_NilValue, R_NilValue));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 5, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(6);
  return _result;
}
void _rgtk4_cb_compute_expand(GtkWidget* widget, gboolean* hexpand_p, gboolean* vexpand_p) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)hexpand_p, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)vexpand_p, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_css_changed(GtkWidget* widget, GtkCssStyleChange* change) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)change, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_system_setting_changed(GtkWidget* widget, GtkSystemSetting settings) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(settings)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_contains(GtkWidget* widget, double x, double y) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)widget, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(x)));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(y)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_activate_focus(GtkWindow* window) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)window, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_keys_changed(GtkWindow* window) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)window, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gboolean _rgtk4_cb_enable_debugging(GtkWindow* window, gboolean toggle) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)window, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarLogical((int)(size_t)(toggle)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
gboolean _rgtk4_cb_close_request(GtkWindow* window) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)window, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_destroy(PangoAttribute* attr) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)attr, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
gpointer _rgtk4_cb_AttrDataCopyFunc(gconstpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 0, NULL));
  gpointer _result = (gpointer)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(1);
  return _result;
}
gboolean _rgtk4_cb_AttrFilterFunc(PangoAttribute* attribute, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)attribute, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
PangoFontDescription* _rgtk4_cb_describe(PangoFontFace* face) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)face, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  PangoFontDescription* _result = (PangoFontDescription*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
PangoCoverage* _rgtk4_cb_get_coverage(PangoFont* font, PangoLanguage* language) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)font, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)language, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  PangoCoverage* _result = (PangoCoverage*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_get_glyph_extents(PangoFont* font, PangoGlyph glyph, PangoRectangle* ink_rect, PangoRectangle* logical_rect) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)font, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(glyph)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)ink_rect, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)logical_rect, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
PangoFontMetrics* _rgtk4_cb_get_metrics(PangoFontset* fontset) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontset, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  PangoFontMetrics* _result = (PangoFontMetrics*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
PangoFontDescription* _rgtk4_cb_describe_absolute(PangoFont* font) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)font, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  PangoFontDescription* _result = (PangoFontDescription*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_get_features(PangoFont* font, hb_feature_t* features, guint len, guint* num_features) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)font, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)features, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(len)));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)num_features, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
hb_font_t* _rgtk4_cb_create_hb_font(PangoFont* font) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)font, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  hb_font_t* _result = (hb_font_t*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
const char* _rgtk4_cb_get_face_name(PangoFontFace* face) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)face, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  const char* _result = (const char*)((_r == R_NilValue || TYPEOF(_r) != STRSXP || Rf_length(_r) == 0 || STRING_ELT(_r, 0) == NA_STRING) ? NULL : g_strdup(CHAR(STRING_ELT(_r, 0))));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_list_sizes(PangoFontFace* face, int** sizes, int* n_sizes) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)face, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)sizes, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)n_sizes, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_is_synthesized(PangoFontFace* face) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)face, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb__pango_reserved3() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__pango_reserved4() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_list_faces(PangoFontFamily* family, PangoFontFace*** faces, int* n_faces) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)family, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)faces, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)n_faces, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_is_monospace(PangoFontFamily* family) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)family, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_is_variable(PangoFontFamily* family) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)family, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
PangoFontFace* _rgtk4_cb_get_face(PangoFontFamily* family, const char* name) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)family, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(name ? (const char*)name : ""));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  PangoFontFace* _result = (PangoFontFace*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb__pango_reserved2() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
PangoFont* _rgtk4_cb_load_font(PangoFontMap* fontmap, PangoContext* context, const PangoFontDescription* desc) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontmap, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)desc, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  PangoFont* _result = (PangoFont*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_list_families(PangoFontMap* fontmap, PangoFontFamily*** families, int* n_families) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontmap, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)families, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)n_families, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
PangoFontset* _rgtk4_cb_load_fontset(PangoFontMap* fontmap, PangoContext* context, const PangoFontDescription* desc, PangoLanguage* language) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontmap, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)context, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)desc, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)language, R_NilValue, R_NilValue));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  PangoFontset* _result = (PangoFontset*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(5);
  return _result;
}
guint _rgtk4_cb_get_serial(PangoFontMap* fontmap) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontmap, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  guint _result = (guint)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
PangoFont* _rgtk4_cb_get_font(PangoFontset* fontset, guint wc) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontset, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(wc)));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  PangoFont* _result = (PangoFont*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
PangoLanguage* _rgtk4_cb_get_language(PangoFontset* fontset) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontset, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  PangoLanguage* _result = (PangoLanguage*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb__pango_reserved1() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
gboolean _rgtk4_cb_FontsetForeachFunc(PangoFontset* fontset, PangoFont* font, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)fontset, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)font, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_draw_glyphs(PangoRenderer* renderer, PangoFont* font, PangoGlyphString* glyphs, int x, int y) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)font, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)glyphs, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(x)));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(y)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_draw_rectangle(PangoRenderer* renderer, PangoRenderPart part, int x, int y, int width, int height) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(part)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(x)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(y)));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(width)));
  SEXP _a6 = PROTECT(Rf_ScalarInteger((int)(size_t)(height)));
  SEXP _argv[6] = { _a1, _a2, _a3, _a4, _a5, _a6 };
  (void)rgtk4_eval_callback(rc, 6, _argv);
  UNPROTECT(6);
}
void _rgtk4_cb_draw_error_underline(PangoRenderer* renderer, int x, int y, int width, int height) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(x)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(y)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(width)));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(height)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_draw_shape(PangoRenderer* renderer, PangoAttrShape* attr, int x, int y) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)attr, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(x)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(y)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  (void)rgtk4_eval_callback(rc, 4, _argv);
  UNPROTECT(4);
}
void _rgtk4_cb_draw_trapezoid(PangoRenderer* renderer, PangoRenderPart part, double y1_, double x11, double x21, double y2, double x12, double x22) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(part)));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(y1_)));
  SEXP _a4 = PROTECT(Rf_ScalarReal((double)(size_t)(x11)));
  SEXP _a5 = PROTECT(Rf_ScalarReal((double)(size_t)(x21)));
  SEXP _a6 = PROTECT(Rf_ScalarReal((double)(size_t)(y2)));
  SEXP _a7 = PROTECT(Rf_ScalarReal((double)(size_t)(x12)));
  SEXP _a8 = PROTECT(Rf_ScalarReal((double)(size_t)(x22)));
  SEXP _argv[8] = { _a1, _a2, _a3, _a4, _a5, _a6, _a7, _a8 };
  (void)rgtk4_eval_callback(rc, 8, _argv);
  UNPROTECT(8);
}
void _rgtk4_cb_draw_glyph(PangoRenderer* renderer, PangoFont* font, PangoGlyph glyph, double x, double y) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)font, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(glyph)));
  SEXP _a4 = PROTECT(Rf_ScalarReal((double)(size_t)(x)));
  SEXP _a5 = PROTECT(Rf_ScalarReal((double)(size_t)(y)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb_part_changed(PangoRenderer* renderer, PangoRenderPart part) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(part)));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_begin(PangoRenderer* renderer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_end(PangoRenderer* renderer) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_prepare_run(PangoRenderer* renderer, PangoLayoutRun* run) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)run, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_draw_glyph_item(PangoRenderer* renderer, const char* text, PangoGlyphItem* glyph_item, int x, int y) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)renderer, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_mkString(text ? (const char*)text : ""));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)glyph_item, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(x)));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(y)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
gboolean _rgtk4_cb_is_static_image(GdkPixbufAnimation* animation) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)animation, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
GdkPixbuf* _rgtk4_cb_get_static_image(GdkPixbufAnimation* animation) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)animation, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GdkPixbuf* _result = (GdkPixbuf*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
int _rgtk4_cb_get_delay_time(GdkPixbufAnimationIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  int _result = (int)Rf_asInteger(_r);
  UNPROTECT(2);
  return _result;
}
GdkPixbuf* _rgtk4_cb_get_pixbuf(GdkPixbufAnimationIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GdkPixbuf* _result = (GdkPixbuf*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_on_currently_loading_frame(GdkPixbufAnimationIter* iter) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
gboolean _rgtk4_cb_advance(GdkPixbufAnimationIter* iter, const GTimeVal* current_time) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)iter, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)current_time, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(3);
  return _result;
}
void _rgtk4_cb_PixbufDestroyNotify(guchar* pixels, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)pixels, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_size_prepared(GdkPixbufLoader* loader, int width, int height) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)loader, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(width)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(height)));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
void _rgtk4_cb_area_prepared(GdkPixbufLoader* loader) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)loader, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
void _rgtk4_cb_area_updated(GdkPixbufLoader* loader, int x, int y, int width, int height) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)loader, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(x)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(y)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(width)));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(height)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
void _rgtk4_cb__reserved1() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__reserved2() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__reserved3() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb__reserved4() {
  RCallbackClosure *rc = rgtk4_current_closure();
  (void)rgtk4_eval_callback(rc, 0, NULL);
}
void _rgtk4_cb_PixbufModuleFillInfoFunc(GdkPixbufFormat* info) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)info, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  (void)rgtk4_eval_callback(rc, 1, _argv);
  UNPROTECT(1);
}
GdkPixbuf* _rgtk4_cb_PixbufModuleLoadXpmDataFunc(const char** data) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)data, R_NilValue, R_NilValue));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  GdkPixbuf* _result = (GdkPixbuf*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_PixbufModulePreparedFunc(GdkPixbuf* pixbuf, GdkPixbufAnimation* anim, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)pixbuf, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)anim, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
gboolean _rgtk4_cb_PixbufModuleSaveOptionSupportedFunc(const gchar* option_key) {
  RCallbackClosure *rc = rgtk4_current_closure();
  SEXP _a1 = PROTECT(Rf_mkString(option_key ? (const char*)option_key : ""));
  SEXP _argv[1] = { _a1 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 1, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(2);
  return _result;
}
void _rgtk4_cb_PixbufModuleSizeFunc(gint* width, gint* height, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)width, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)height, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  (void)rgtk4_eval_callback(rc, 2, _argv);
  UNPROTECT(2);
}
void _rgtk4_cb_PixbufModuleUpdatedFunc(GdkPixbuf* pixbuf, int x, int y, int width, int height, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)pixbuf, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarInteger((int)(size_t)(x)));
  SEXP _a3 = PROTECT(Rf_ScalarInteger((int)(size_t)(y)));
  SEXP _a4 = PROTECT(Rf_ScalarInteger((int)(size_t)(width)));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(height)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  (void)rgtk4_eval_callback(rc, 5, _argv);
  UNPROTECT(5);
}
gboolean _rgtk4_cb_PixbufSaveFunc(const gchar* buf, gsize count, GError** error, gpointer data) {
  RCallbackClosure *rc = (RCallbackClosure *)data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)buf, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(Rf_ScalarReal((double)(size_t)(count)));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)error, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 3, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(4);
  return _result;
}
void _rgtk4_cb_ParseErrorFunc(const GskParseLocation* start, const GskParseLocation* end, const GError* error, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)start, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)end, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)error, R_NilValue, R_NilValue));
  SEXP _argv[3] = { _a1, _a2, _a3 };
  (void)rgtk4_eval_callback(rc, 3, _argv);
  UNPROTECT(3);
}
gboolean _rgtk4_cb_PathForeachFunc(GskPathOperation op, const graphene_point_t* pts, gsize n_pts, float weight, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(Rf_ScalarInteger((int)(size_t)(op)));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)pts, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(Rf_ScalarReal((double)(size_t)(n_pts)));
  SEXP _a4 = PROTECT(Rf_ScalarReal((double)(size_t)(weight)));
  SEXP _argv[4] = { _a1, _a2, _a3, _a4 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 4, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(5);
  return _result;
}
gboolean _rgtk4_cb_PathIntersectionFunc(GskPath* path1, const GskPathPoint* point1, GskPath* path2, const GskPathPoint* point2, GskPathIntersection kind, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)path1, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)point1, R_NilValue, R_NilValue));
  SEXP _a3 = PROTECT(R_MakeExternalPtr((void*)path2, R_NilValue, R_NilValue));
  SEXP _a4 = PROTECT(R_MakeExternalPtr((void*)point2, R_NilValue, R_NilValue));
  SEXP _a5 = PROTECT(Rf_ScalarInteger((int)(size_t)(kind)));
  SEXP _argv[5] = { _a1, _a2, _a3, _a4, _a5 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 5, _argv));
  gboolean _result = (gboolean)(Rf_asLogical(_r) == TRUE);
  UNPROTECT(6);
  return _result;
}
PangoFont* _rgtk4_cb_RenderReplayFontFilter(GskRenderReplay* replay, PangoFont* font, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)replay, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)font, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  PangoFont* _result = (PangoFont*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
GskRenderNode* _rgtk4_cb_RenderReplayNodeFilter(GskRenderReplay* replay, GskRenderNode* node, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)replay, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)node, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GskRenderNode* _result = (GskRenderNode*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
GdkTexture* _rgtk4_cb_RenderReplayTextureFilter(GskRenderReplay* replay, GdkTexture* texture, gpointer user_data) {
  RCallbackClosure *rc = (RCallbackClosure *)user_data;
  SEXP _a1 = PROTECT(R_MakeExternalPtr((void*)replay, R_NilValue, R_NilValue));
  SEXP _a2 = PROTECT(R_MakeExternalPtr((void*)texture, R_NilValue, R_NilValue));
  SEXP _argv[2] = { _a1, _a2 };
  SEXP _r = PROTECT(rgtk4_eval_callback(rc, 2, _argv));
  GdkTexture* _result = (GdkTexture*)(_r == R_NilValue ? NULL : R_ExternalPtrAddr(_r));
  UNPROTECT(3);
  return _result;
}
