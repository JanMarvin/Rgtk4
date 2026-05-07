#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <stdint.h>
#include <string.h>
#include "rgtk4_callbacks.h"
#include "rgtk4_autogen_callbacks.h"

/* Suppress pedantic warnings in auto-generated GTK glue code */
#pragma GCC diagnostic ignored "-Wpedantic"

/* Agnostic numeric extraction helper */
static inline double _unbox_numeric(SEXP s) {
  if (TYPEOF(s) == REALSXP) return REAL(s)[0];
  if (TYPEOF(s) == INTSXP)  return (double)INTEGER(s)[0];
  if (TYPEOF(s) == LGLSXP)  return (double)LOGICAL(s)[0];
  return 0.0;
}

/* Bounded numeric extraction. NA and out-of-range values throw. */
static inline gint64 _unbox_int_range(SEXP s, gint64 lo, gint64 hi, const char *func) __attribute__((unused));
static inline gint64 _unbox_int_range(SEXP s, gint64 lo, gint64 hi, const char *func) {
  double v;
  if (TYPEOF(s) == INTSXP) {
    int iv = INTEGER(s)[0];
    if (iv == NA_INTEGER) Rf_error("%s: NA not allowed for integer argument", func);
    v = (double)iv;
  } else if (TYPEOF(s) == REALSXP) {
    v = REAL(s)[0];
    if (!R_finite(v)) Rf_error("%s: NA/Inf not allowed for integer argument", func);
  } else if (TYPEOF(s) == LGLSXP) {
    int lv = LOGICAL(s)[0];
    if (lv == NA_LOGICAL) Rf_error("%s: NA not allowed for integer argument", func);
    v = (double)lv;
  } else {
    Rf_error("%s: expected numeric scalar, got %s", func, Rf_type2char(TYPEOF(s)));
  }
  if (v < (double)lo || v > (double)hi) {
    Rf_error("%s: value %.0f out of range [%lld, %lld]", func, v, (long long)lo, (long long)hi);
  }
  return (gint64)v;
}

static inline double _unbox_real(SEXP s, const char *func) __attribute__((unused));
static inline double _unbox_real(SEXP s, const char *func) {
  if (TYPEOF(s) == REALSXP) {
    double v = REAL(s)[0];
    if (ISNA(v)) Rf_error("%s: NA not allowed for numeric argument", func);
    return v;
  }
  if (TYPEOF(s) == INTSXP) {
    int iv = INTEGER(s)[0];
    if (iv == NA_INTEGER) Rf_error("%s: NA not allowed for numeric argument", func);
    return (double)iv;
  }
  if (TYPEOF(s) == LGLSXP) {
    int lv = LOGICAL(s)[0];
    if (lv == NA_LOGICAL) Rf_error("%s: NA not allowed for numeric argument", func);
    return (double)lv;
  }
  Rf_error("%s: expected numeric scalar, got %s", func, Rf_type2char(TYPEOF(s)));
  return 0.0;  /* unreachable */
}

#define _UNBOX_GINT(s)   ((gint)  _unbox_int_range((s), G_MININT,    G_MAXINT,    __func__))
#define _UNBOX_GUINT(s)  ((guint) _unbox_int_range((s), 0,           G_MAXUINT,   __func__))
#define _UNBOX_GINT8(s)  ((gint8) _unbox_int_range((s), G_MININT8,   G_MAXINT8,   __func__))
#define _UNBOX_GUINT8(s) ((guint8)_unbox_int_range((s), 0,           G_MAXUINT8,  __func__))
#define _UNBOX_GINT16(s) ((gint16)_unbox_int_range((s), G_MININT16,  G_MAXINT16,  __func__))
#define _UNBOX_GUINT16(s)((guint16)_unbox_int_range((s),0,           G_MAXUINT16, __func__))
#define _UNBOX_GINT32(s) ((gint32)_unbox_int_range((s), G_MININT32,  G_MAXINT32,  __func__))
#define _UNBOX_GUINT32(s)((guint32)_unbox_int_range((s),0,           G_MAXUINT32, __func__))
#define _UNBOX_GINT64(s) ((gint64)_unbox_int_range((s), G_MININT64,  G_MAXINT64,  __func__))
#define _UNBOX_GSIZE(s)  ((gsize) _unbox_int_range((s), 0,           G_MAXINT64,  __func__))
#define _UNBOX_GBOOL(s)  ((gboolean)(Rf_asLogical(s) == TRUE))

/* Safe pointer extraction with validation */
static inline void* get_ptr_internal(SEXP s, const char* func) __attribute__((unused));
static inline void* get_ptr_internal(SEXP s, const char* func) {
  if (s == R_NilValue) return NULL;
  if (TYPEOF(s) != EXTPTRSXP) {
    Rf_error("%s: expected external pointer, got %s", func, Rf_type2char(TYPEOF(s)));
  }
  void *addr = R_ExternalPtrAddr(s);
  if (!addr) {
    Rf_error("%s: external pointer is NULL (object may have been destroyed)", func);
  }
  return addr;
}
#define get_ptr(s) get_ptr_internal(s, __func__)

/* GTK init guard. Bindings that touch GTK/GDK call
   RGTK4_REQUIRE_INIT at entry to surface a clean error rather than
   crash on uninitialized state. Uses gtk_is_initialized() directly. */
#define RGTK4_REQUIRE_INIT() do { \
  if (!gtk_is_initialized()) { \
    Rf_error("%s: gtkInit() has not been called — call gtkInit() first", __func__); \
  } \
} while (0)

static void _finalizer_g_free(SEXP s) __attribute__((unused));
static void _finalizer_g_free(SEXP s) {
  void *p = R_ExternalPtrAddr(s);
  if (p) g_free(p);
}

extern SEXP make_gobject_ptr(gpointer obj);
extern SEXP make_boxed_struct(const void *src, size_t size, const char *type_name);

static SEXP _box_GStrv(char **strv) __attribute__((unused));
static SEXP _box_GStrv(char **strv) {
  if (!strv) return R_NilValue;
  int n = g_strv_length(strv);
  SEXP res = PROTECT(Rf_allocVector(STRSXP, n));
  for (int i = 0; i < n; i++) SET_STRING_ELT(res, i, Rf_mkChar(strv[i]));
  UNPROTECT(1);
  return res;
}

static SEXP tag_pointer(SEXP ptr, const char* fallback_name) {
  if (ptr == R_NilValue || TYPEOF(ptr) != EXTPTRSXP) return ptr;
  void *obj = R_ExternalPtrAddr(ptr);
  if ((uintptr_t)obj < 0x1000) {
    R_SetExternalPtrTag(ptr, Rf_mkChar(fallback_name));
    SEXP classes = PROTECT(Rf_allocVector(STRSXP, 3));
    SET_STRING_ELT(classes, 0, Rf_mkChar(fallback_name));
    SET_STRING_ELT(classes, 1, Rf_mkChar("GObject"));
    SET_STRING_ELT(classes, 2, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(ptr, R_ClassSymbol, classes);
    UNPROTECT(1);
    return ptr;
  }
  if (G_IS_OBJECT(obj)) {
    const char *tn = G_OBJECT_TYPE_NAME(obj);
    R_SetExternalPtrTag(ptr, Rf_mkChar(tn ? tn : fallback_name));
    SEXP classes = PROTECT(Rf_allocVector(STRSXP, 3));
    SET_STRING_ELT(classes, 0, Rf_mkChar(tn ? tn : fallback_name));
    SET_STRING_ELT(classes, 1, Rf_mkChar("GObject"));
    SET_STRING_ELT(classes, 2, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(ptr, R_ClassSymbol, classes);
    UNPROTECT(1);
  } else {
    R_SetExternalPtrTag(ptr, Rf_mkChar(fallback_name));
    SEXP classes = PROTECT(Rf_allocVector(STRSXP, 3));
    SET_STRING_ELT(classes, 0, Rf_mkChar(fallback_name));
    SET_STRING_ELT(classes, 1, Rf_mkChar("GObject"));
    SET_STRING_ELT(classes, 2, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(ptr, R_ClassSymbol, classes);
    UNPROTECT(1);
  }
  return ptr;
}

/* Autogenerated for GdkPixbuf */
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#ifdef __clang__
#pragma GCC diagnostic ignored "-Wimplicit-enum-enum-cast"
#endif


SEXP R_gdk_pixbuf_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  RGTK4_REQUIRE_INIT();
  GdkColorspace v1 = (GdkColorspace)((GdkColorspace)(TYPEOF(s1)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s1) : INTEGER(s1)[0])); (void)v1;
  gboolean v2 = (gboolean)((gboolean)LOGICAL(s2)[0]); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gint v4 = (gint)((gint)_unbox_numeric(s4)); (void)v4;
  gint v5 = (gint)((gint)_unbox_numeric(s5)); (void)v5;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_bytes(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7) {
  RGTK4_REQUIRE_INIT();
  GBytes* v1 = (GBytes*)(get_ptr(s1)); (void)v1;
  GdkColorspace v2 = (GdkColorspace)((GdkColorspace)(TYPEOF(s2)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s2) : INTEGER(s2)[0])); (void)v2;
  gboolean v3 = (gboolean)((gboolean)LOGICAL(s3)[0]); (void)v3;
  gint v4 = (gint)((gint)_unbox_numeric(s4)); (void)v4;
  gint v5 = (gint)((gint)_unbox_numeric(s5)); (void)v5;
  gint v6 = (gint)((gint)_unbox_numeric(s6)); (void)v6;
  gint v7 = (gint)((gint)_unbox_numeric(s7)); (void)v7;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_bytes(v1, v2, v3, v4, v5, v6, v7);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_data(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8, SEXP s9) {
  RGTK4_REQUIRE_INIT();
  const guchar* v1 = (const guchar*)(get_ptr(s1)); (void)v1;
  GdkColorspace v2 = (GdkColorspace)((GdkColorspace)(TYPEOF(s2)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s2) : INTEGER(s2)[0])); (void)v2;
  gboolean v3 = (gboolean)((gboolean)LOGICAL(s3)[0]); (void)v3;
  gint v4 = (gint)((gint)_unbox_numeric(s4)); (void)v4;
  gint v5 = (gint)((gint)_unbox_numeric(s5)); (void)v5;
  gint v6 = (gint)((gint)_unbox_numeric(s6)); (void)v6;
  gint v7 = (gint)((gint)_unbox_numeric(s7)); (void)v7;
  GdkPixbufDestroyNotify v8 = (s8 != R_NilValue) ? (GdkPixbufDestroyNotify)(get_ptr(s8)) : NULL; (void)v8;
  gpointer v9 = (s9 != R_NilValue) ? (gpointer)(get_ptr(s9)) : NULL; (void)v9;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_data(v1, v2, v3, v4, v5, v6, v7, v8, v9);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_file(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_file(v1, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_file_at_scale(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  gint v2 = (gint)((gint)_unbox_numeric(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gboolean v4 = (gboolean)((gboolean)LOGICAL(s4)[0]); (void)v4;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_file_at_scale(v1, v2, v3, v4, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_file_at_size(SEXP s1, SEXP s2, SEXP s3) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  gint v2 = (gint)((gint)_unbox_numeric(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_file_at_size(v1, v2, v3, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_inline(SEXP s1, SEXP s2, SEXP s3) {
  RGTK4_REQUIRE_INIT();
  gint v1 = (gint)((gint)_unbox_numeric(s1)); (void)v1;
  const guint8* v2 = (const guint8*)(get_ptr(s2)); (void)v2;
  gboolean v3 = (gboolean)((gboolean)LOGICAL(s3)[0]); (void)v3;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_inline(v1, v2, v3, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_resource(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_resource(v1, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_resource_at_scale(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  gint v2 = (gint)((gint)_unbox_numeric(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gboolean v4 = (gboolean)((gboolean)LOGICAL(s4)[0]); (void)v4;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_resource_at_scale(v1, v2, v3, v4, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_stream(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GInputStream* v1 = (GInputStream*)(get_ptr(s1)); (void)v1;
  GCancellable* v2 = (s2 != R_NilValue) ? (GCancellable*)(get_ptr(s2)) : NULL; (void)v2;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_stream(v1, v2, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_stream_at_scale(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  RGTK4_REQUIRE_INIT();
  GInputStream* v1 = (GInputStream*)(get_ptr(s1)); (void)v1;
  gint v2 = (gint)((gint)_unbox_numeric(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gboolean v4 = (gboolean)((gboolean)LOGICAL(s4)[0]); (void)v4;
  GCancellable* v5 = (s5 != R_NilValue) ? (GCancellable*)(get_ptr(s5)) : NULL; (void)v5;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_stream_at_scale(v1, v2, v3, v4, v5, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_stream_finish(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GAsyncResult* v1 = (GAsyncResult*)(get_ptr(s1)); (void)v1;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_stream_finish(v1, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_xpm_data(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const char** v1 = (const char**)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_from_xpm_data(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_calculate_rowstride(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  RGTK4_REQUIRE_INIT();
  GdkColorspace v1 = (GdkColorspace)((GdkColorspace)(TYPEOF(s1)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s1) : INTEGER(s1)[0])); (void)v1;
  gboolean v2 = (gboolean)((gboolean)LOGICAL(s2)[0]); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gint v4 = (gint)((gint)_unbox_numeric(s4)); (void)v4;
  gint v5 = (gint)((gint)_unbox_numeric(s5)); (void)v5;
  gint _ret = (gint)gdk_pixbuf_calculate_rowstride(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_file_info(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  gint _out_width = 0; (void)_out_width;
  gint _out_height = 0; (void)_out_height;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_get_file_info(v1, &_out_width, &_out_height);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 3));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 3));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufFormat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, Rf_ScalarInteger((int)(_out_width)));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("width"));
  SET_VECTOR_ELT(_ans, 2, Rf_ScalarInteger((int)(_out_height)));
  if (VECTOR_ELT(_ans, 2) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 2), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 2, Rf_mkChar("height"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_file_info_async(SEXP s1, SEXP s2, SEXP s3) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  GCancellable* v2 = (s2 != R_NilValue) ? (GCancellable*)(get_ptr(s2)) : NULL; (void)v2;
  RCallbackClosure *_cb_closure_3 = (s3 == R_NilValue) ? NULL : rgtk4_closure_new(s3); (void)_cb_closure_3;
  gdk_pixbuf_get_file_info_async(v1, v2, (GAsyncReadyCallback)(_cb_closure_3 ? _rgtk4_cb_AsyncReadyCallback : NULL), _cb_closure_3);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_get_file_info_finish(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GAsyncResult* v1 = (GAsyncResult*)(get_ptr(s1)); (void)v1;
  gint _out_width = 0; (void)_out_width;
  gint _out_height = 0; (void)_out_height;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_get_file_info_finish(v1, &_out_width, &_out_height, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 3));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 3));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufFormat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, Rf_ScalarInteger((int)(_out_width)));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("width"));
  SET_VECTOR_ELT(_ans, 2, Rf_ScalarInteger((int)(_out_height)));
  if (VECTOR_ELT(_ans, 2) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 2), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 2, Rf_mkChar("height"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_formats(void) {
  RGTK4_REQUIRE_INIT();

  gconstpointer _ret = (gconstpointer)gdk_pixbuf_get_formats();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("GLib.SList"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_init_modules(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  GError *_err = NULL;
  gboolean _ret = (gboolean)gdk_pixbuf_init_modules(v1, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_from_stream_async(SEXP s1, SEXP s2, SEXP s3) {
  RGTK4_REQUIRE_INIT();
  GInputStream* v1 = (GInputStream*)(get_ptr(s1)); (void)v1;
  GCancellable* v2 = (s2 != R_NilValue) ? (GCancellable*)(get_ptr(s2)) : NULL; (void)v2;
  RCallbackClosure *_cb_closure_3 = (s3 == R_NilValue) ? NULL : rgtk4_closure_new(s3); (void)_cb_closure_3;
  gdk_pixbuf_new_from_stream_async(v1, v2, (GAsyncReadyCallback)(_cb_closure_3 ? _rgtk4_cb_AsyncReadyCallback : NULL), _cb_closure_3);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_new_from_stream_at_scale_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6) {
  RGTK4_REQUIRE_INIT();
  GInputStream* v1 = (GInputStream*)(get_ptr(s1)); (void)v1;
  gint v2 = (gint)((gint)_unbox_numeric(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gboolean v4 = (gboolean)((gboolean)LOGICAL(s4)[0]); (void)v4;
  GCancellable* v5 = (s5 != R_NilValue) ? (GCancellable*)(get_ptr(s5)) : NULL; (void)v5;
  RCallbackClosure *_cb_closure_6 = (s6 == R_NilValue) ? NULL : rgtk4_closure_new(s6); (void)_cb_closure_6;
  gdk_pixbuf_new_from_stream_at_scale_async(v1, v2, v3, v4, v5, (GAsyncReadyCallback)(_cb_closure_6 ? _rgtk4_cb_AsyncReadyCallback : NULL), _cb_closure_6);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_save_to_stream_finish(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GAsyncResult* v1 = (GAsyncResult*)(get_ptr(s1)); (void)v1;
  GError *_err = NULL;
  gboolean _ret = (gboolean)gdk_pixbuf_save_to_stream_finish(v1, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_add_alpha(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gboolean v2 = (gboolean)((gboolean)LOGICAL(s2)[0]); (void)v2;
  guint8 v3 = (guint8)((guint8)_unbox_numeric(s3)); (void)v3;
  guint8 v4 = (guint8)((guint8)_unbox_numeric(s4)); (void)v4;
  guint8 v5 = (guint8)((guint8)_unbox_numeric(s5)); (void)v5;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_add_alpha(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_apply_embedded_orientation(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_apply_embedded_orientation(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_composite(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8, SEXP s9, SEXP s10, SEXP s11, SEXP s12) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  GdkPixbuf* v2 = (GdkPixbuf*)(get_ptr(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gint v4 = (gint)((gint)_unbox_numeric(s4)); (void)v4;
  gint v5 = (gint)((gint)_unbox_numeric(s5)); (void)v5;
  gint v6 = (gint)((gint)_unbox_numeric(s6)); (void)v6;
  gdouble v7 = (gdouble)((gdouble)_unbox_numeric(s7)); (void)v7;
  gdouble v8 = (gdouble)((gdouble)_unbox_numeric(s8)); (void)v8;
  gdouble v9 = (gdouble)((gdouble)_unbox_numeric(s9)); (void)v9;
  gdouble v10 = (gdouble)((gdouble)_unbox_numeric(s10)); (void)v10;
  GdkInterpType v11 = (GdkInterpType)((GdkInterpType)(TYPEOF(s11)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s11) : INTEGER(s11)[0])); (void)v11;
  gint v12 = (gint)((gint)_unbox_numeric(s12)); (void)v12;
  gdk_pixbuf_composite(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_composite_color(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8, SEXP s9, SEXP s10, SEXP s11, SEXP s12, SEXP s13, SEXP s14, SEXP s15, SEXP s16, SEXP s17) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  GdkPixbuf* v2 = (GdkPixbuf*)(get_ptr(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gint v4 = (gint)((gint)_unbox_numeric(s4)); (void)v4;
  gint v5 = (gint)((gint)_unbox_numeric(s5)); (void)v5;
  gint v6 = (gint)((gint)_unbox_numeric(s6)); (void)v6;
  gdouble v7 = (gdouble)((gdouble)_unbox_numeric(s7)); (void)v7;
  gdouble v8 = (gdouble)((gdouble)_unbox_numeric(s8)); (void)v8;
  gdouble v9 = (gdouble)((gdouble)_unbox_numeric(s9)); (void)v9;
  gdouble v10 = (gdouble)((gdouble)_unbox_numeric(s10)); (void)v10;
  GdkInterpType v11 = (GdkInterpType)((GdkInterpType)(TYPEOF(s11)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s11) : INTEGER(s11)[0])); (void)v11;
  gint v12 = (gint)((gint)_unbox_numeric(s12)); (void)v12;
  gint v13 = (gint)((gint)_unbox_numeric(s13)); (void)v13;
  gint v14 = (gint)((gint)_unbox_numeric(s14)); (void)v14;
  gint v15 = (gint)((gint)_unbox_numeric(s15)); (void)v15;
  guint32 v16 = (guint32)((guint32)_unbox_numeric(s16)); (void)v16;
  guint32 v17 = (guint32)((guint32)_unbox_numeric(s17)); (void)v17;
  gdk_pixbuf_composite_color(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_composite_color_simple(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gint v2 = (gint)((gint)_unbox_numeric(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  GdkInterpType v4 = (GdkInterpType)((GdkInterpType)(TYPEOF(s4)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s4) : INTEGER(s4)[0])); (void)v4;
  gint v5 = (gint)((gint)_unbox_numeric(s5)); (void)v5;
  gint v6 = (gint)((gint)_unbox_numeric(s6)); (void)v6;
  guint32 v7 = (guint32)((guint32)_unbox_numeric(s7)); (void)v7;
  guint32 v8 = (guint32)((guint32)_unbox_numeric(s8)); (void)v8;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_composite_color_simple(v1, v2, v3, v4, v5, v6, v7, v8);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_copy(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_copy(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_copy_area(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gint v2 = (gint)((gint)_unbox_numeric(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gint v4 = (gint)((gint)_unbox_numeric(s4)); (void)v4;
  gint v5 = (gint)((gint)_unbox_numeric(s5)); (void)v5;
  GdkPixbuf* v6 = (GdkPixbuf*)(get_ptr(s6)); (void)v6;
  gint v7 = (gint)((gint)_unbox_numeric(s7)); (void)v7;
  gint v8 = (gint)((gint)_unbox_numeric(s8)); (void)v8;
  gdk_pixbuf_copy_area(v1, v2, v3, v4, v5, v6, v7, v8);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_copy_options(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  GdkPixbuf* v2 = (GdkPixbuf*)(get_ptr(s2)); (void)v2;
  gboolean _ret = (gboolean)gdk_pixbuf_copy_options(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_fill(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  guint32 v2 = (guint32)((guint32)_unbox_numeric(s2)); (void)v2;
  gdk_pixbuf_fill(v1, v2);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_flip(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gboolean v2 = (gboolean)((gboolean)LOGICAL(s2)[0]); (void)v2;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_flip(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_bits_per_sample(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  int _ret = (int)gdk_pixbuf_get_bits_per_sample(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_byte_length(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gsize _ret = (gsize)gdk_pixbuf_get_byte_length(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gsize"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_colorspace(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  GdkColorspace _ret = (GdkColorspace)gdk_pixbuf_get_colorspace(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(R_MakeExternalPtr((void*)(_ret), R_NilValue, R_NilValue), "Colorspace"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Colorspace"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_has_alpha(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gboolean _ret = (gboolean)gdk_pixbuf_get_has_alpha(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_height(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  int _ret = (int)gdk_pixbuf_get_height(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_n_channels(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  int _ret = (int)gdk_pixbuf_get_n_channels(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_option(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  const char* v2 = (const char*)(CHAR(STRING_ELT(s2,0))); (void)v2;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_get_option(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : Rf_mkString(_ret ? (const char*)_ret : ""));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("utf8"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_options(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_get_options(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("GLib.HashTable"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_pixels(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_get_pixels(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : tag_pointer(Rf_ScalarInteger((int)(_ret)), "guint8"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("guint8"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_pixels_with_length(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  guint _out_length = 0; (void)_out_length;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_get_pixels_with_length(v1, &_out_length);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : tag_pointer(Rf_ScalarInteger((int)(_ret)), "guint8"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("guint8"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, Rf_ScalarInteger((int)(_out_length)));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("guint"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("length"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_rowstride(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  int _ret = (int)gdk_pixbuf_get_rowstride(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_get_width(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  int _ret = (int)gdk_pixbuf_get_width(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_new_subpixbuf(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gint v2 = (gint)((gint)_unbox_numeric(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gint v4 = (gint)((gint)_unbox_numeric(s4)); (void)v4;
  gint v5 = (gint)((gint)_unbox_numeric(s5)); (void)v5;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_new_subpixbuf(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_read_pixel_bytes(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_read_pixel_bytes(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("GLib.Bytes"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_read_pixels(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_read_pixels(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : tag_pointer(Rf_ScalarInteger((int)(_ret)), "guint8"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("guint8"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_remove_option(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  const char* v2 = (const char*)(CHAR(STRING_ELT(s2,0))); (void)v2;
  gboolean _ret = (gboolean)gdk_pixbuf_remove_option(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_rotate_simple(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  GdkPixbufRotation v2 = (GdkPixbufRotation)((GdkPixbufRotation)(TYPEOF(s2)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s2) : INTEGER(s2)[0])); (void)v2;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_rotate_simple(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_saturate_and_pixelate(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  GdkPixbuf* v2 = (GdkPixbuf*)(get_ptr(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gboolean v4 = (gboolean)((gboolean)LOGICAL(s4)[0]); (void)v4;
  gdk_pixbuf_saturate_and_pixelate(v1, v2, v3, v4);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_save_to_bufferv(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gchar* _out_buffer = 0; (void)_out_buffer;
  gsize _out_buffer_size = 0; (void)_out_buffer_size;
  const char* v2 = (const char*)(CHAR(STRING_ELT(s2,0))); (void)v2;
  char** v3 = (s3 != R_NilValue) ? (char**)(get_ptr(s3)) : NULL; (void)v3;
  char** v4 = (s4 != R_NilValue) ? (char**)(get_ptr(s4)) : NULL; (void)v4;
  GError *_err = NULL;
  gboolean _ret = (gboolean)gdk_pixbuf_save_to_bufferv(v1, &_out_buffer, &_out_buffer_size, v2, v3, v4, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 3));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 3));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, (_out_buffer == NULL) ? R_NilValue : tag_pointer(Rf_ScalarInteger((int)(_out_buffer)), "guint8"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("guint8"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("buffer"));
  SET_VECTOR_ELT(_ans, 2, Rf_ScalarInteger((int)(_out_buffer_size)));
  if (VECTOR_ELT(_ans, 2) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 2), Rf_install("glib_type"), Rf_mkString("gsize"));
  }
  SET_STRING_ELT(_ans_names, 2, Rf_mkChar("buffer_size"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_save_to_callbackv(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  RCallbackClosure *_cb_closure_2 = (s2 == R_NilValue) ? NULL : rgtk4_closure_new(s2); (void)_cb_closure_2;
  const char* v3 = (const char*)(CHAR(STRING_ELT(s3,0))); (void)v3;
  char** v4 = (s4 != R_NilValue) ? (char**)(get_ptr(s4)) : NULL; (void)v4;
  char** v5 = (s5 != R_NilValue) ? (char**)(get_ptr(s5)) : NULL; (void)v5;
  GError *_err = NULL;
  gboolean _ret = (gboolean)gdk_pixbuf_save_to_callbackv(v1, (GdkPixbufSaveFunc)(_cb_closure_2 ? _rgtk4_cb_PixbufSaveFunc : NULL), _cb_closure_2, v3, v4, v5, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_save_to_streamv(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  GOutputStream* v2 = (GOutputStream*)(get_ptr(s2)); (void)v2;
  const char* v3 = (const char*)(CHAR(STRING_ELT(s3,0))); (void)v3;
  char** v4 = (s4 != R_NilValue) ? (char**)(get_ptr(s4)) : NULL; (void)v4;
  char** v5 = (s5 != R_NilValue) ? (char**)(get_ptr(s5)) : NULL; (void)v5;
  GCancellable* v6 = (s6 != R_NilValue) ? (GCancellable*)(get_ptr(s6)) : NULL; (void)v6;
  GError *_err = NULL;
  gboolean _ret = (gboolean)gdk_pixbuf_save_to_streamv(v1, v2, v3, v4, v5, v6, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_save_to_streamv_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  GOutputStream* v2 = (GOutputStream*)(get_ptr(s2)); (void)v2;
  const char* v3 = (const char*)(CHAR(STRING_ELT(s3,0))); (void)v3;
  gchar** v4 = (s4 != R_NilValue) ? (gchar**)(get_ptr(s4)) : NULL; (void)v4;
  gchar** v5 = (s5 != R_NilValue) ? (gchar**)(get_ptr(s5)) : NULL; (void)v5;
  GCancellable* v6 = (s6 != R_NilValue) ? (GCancellable*)(get_ptr(s6)) : NULL; (void)v6;
  RCallbackClosure *_cb_closure_7 = (s7 == R_NilValue) ? NULL : rgtk4_closure_new(s7); (void)_cb_closure_7;
  gdk_pixbuf_save_to_streamv_async(v1, v2, v3, v4, v5, v6, (GAsyncReadyCallback)(_cb_closure_7 ? _rgtk4_cb_AsyncReadyCallback : NULL), _cb_closure_7);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_savev(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  const char* v2 = (const char*)(CHAR(STRING_ELT(s2,0))); (void)v2;
  const char* v3 = (const char*)(CHAR(STRING_ELT(s3,0))); (void)v3;
  char** v4 = (s4 != R_NilValue) ? (char**)(get_ptr(s4)) : NULL; (void)v4;
  char** v5 = (s5 != R_NilValue) ? (char**)(get_ptr(s5)) : NULL; (void)v5;
  GError *_err = NULL;
  gboolean _ret = (gboolean)gdk_pixbuf_savev(v1, v2, v3, v4, v5, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_scale(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8, SEXP s9, SEXP s10, SEXP s11) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  GdkPixbuf* v2 = (GdkPixbuf*)(get_ptr(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gint v4 = (gint)((gint)_unbox_numeric(s4)); (void)v4;
  gint v5 = (gint)((gint)_unbox_numeric(s5)); (void)v5;
  gint v6 = (gint)((gint)_unbox_numeric(s6)); (void)v6;
  gdouble v7 = (gdouble)((gdouble)_unbox_numeric(s7)); (void)v7;
  gdouble v8 = (gdouble)((gdouble)_unbox_numeric(s8)); (void)v8;
  gdouble v9 = (gdouble)((gdouble)_unbox_numeric(s9)); (void)v9;
  gdouble v10 = (gdouble)((gdouble)_unbox_numeric(s10)); (void)v10;
  GdkInterpType v11 = (GdkInterpType)((GdkInterpType)(TYPEOF(s11)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s11) : INTEGER(s11)[0])); (void)v11;
  gdk_pixbuf_scale(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_scale_simple(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbuf* v1 = (const GdkPixbuf*)(get_ptr(s1)); (void)v1;
  gint v2 = (gint)((gint)_unbox_numeric(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  GdkInterpType v4 = (GdkInterpType)((GdkInterpType)(TYPEOF(s4)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s4) : INTEGER(s4)[0])); (void)v4;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_scale_simple(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_set_option(SEXP s1, SEXP s2, SEXP s3) {
  RGTK4_REQUIRE_INIT();
  GdkPixbuf* v1 = (GdkPixbuf*)(get_ptr(s1)); (void)v1;
  const char* v2 = (const char*)(CHAR(STRING_ELT(s2,0))); (void)v2;
  const char* v3 = (const char*)(CHAR(STRING_ELT(s3,0))); (void)v3;
  gboolean _ret = (gboolean)gdk_pixbuf_set_option(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_new_from_file(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_animation_new_from_file(v1, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufAnimation"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_new_from_resource(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_animation_new_from_resource(v1, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufAnimation"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_new_from_stream(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GInputStream* v1 = (GInputStream*)(get_ptr(s1)); (void)v1;
  GCancellable* v2 = (s2 != R_NilValue) ? (GCancellable*)(get_ptr(s2)) : NULL; (void)v2;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_animation_new_from_stream(v1, v2, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufAnimation"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_new_from_stream_finish(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GAsyncResult* v1 = (GAsyncResult*)(get_ptr(s1)); (void)v1;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_animation_new_from_stream_finish(v1, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufAnimation"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_new_from_stream_async(SEXP s1, SEXP s2, SEXP s3) {
  RGTK4_REQUIRE_INIT();
  GInputStream* v1 = (GInputStream*)(get_ptr(s1)); (void)v1;
  GCancellable* v2 = (s2 != R_NilValue) ? (GCancellable*)(get_ptr(s2)) : NULL; (void)v2;
  RCallbackClosure *_cb_closure_3 = (s3 == R_NilValue) ? NULL : rgtk4_closure_new(s3); (void)_cb_closure_3;
  gdk_pixbuf_animation_new_from_stream_async(v1, v2, (GAsyncReadyCallback)(_cb_closure_3 ? _rgtk4_cb_AsyncReadyCallback : NULL), _cb_closure_3);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_animation_get_height(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufAnimation* v1 = (GdkPixbufAnimation*)(get_ptr(s1)); (void)v1;
  int _ret = (int)gdk_pixbuf_animation_get_height(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_get_iter(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufAnimation* v1 = (GdkPixbufAnimation*)(get_ptr(s1)); (void)v1;
  const GTimeVal* v2 = (s2 != R_NilValue) ? (const GTimeVal*)(get_ptr(s2)) : NULL; (void)v2;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_animation_get_iter(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufAnimationIter"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_get_static_image(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufAnimation* v1 = (GdkPixbufAnimation*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_animation_get_static_image(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_get_width(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufAnimation* v1 = (GdkPixbufAnimation*)(get_ptr(s1)); (void)v1;
  int _ret = (int)gdk_pixbuf_animation_get_width(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_is_static_image(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufAnimation* v1 = (GdkPixbufAnimation*)(get_ptr(s1)); (void)v1;
  gboolean _ret = (gboolean)gdk_pixbuf_animation_is_static_image(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_iter_advance(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufAnimationIter* v1 = (GdkPixbufAnimationIter*)(get_ptr(s1)); (void)v1;
  const GTimeVal* v2 = (s2 != R_NilValue) ? (const GTimeVal*)(get_ptr(s2)) : NULL; (void)v2;
  gboolean _ret = (gboolean)gdk_pixbuf_animation_iter_advance(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_iter_get_delay_time(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufAnimationIter* v1 = (GdkPixbufAnimationIter*)(get_ptr(s1)); (void)v1;
  int _ret = (int)gdk_pixbuf_animation_iter_get_delay_time(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gint"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_iter_get_pixbuf(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufAnimationIter* v1 = (GdkPixbufAnimationIter*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_animation_iter_get_pixbuf(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_animation_iter_on_currently_loading_frame(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufAnimationIter* v1 = (GdkPixbufAnimationIter*)(get_ptr(s1)); (void)v1;
  gboolean _ret = (gboolean)gdk_pixbuf_animation_iter_on_currently_loading_frame(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_error_quark(void) {
  RGTK4_REQUIRE_INIT();

  GQuark _ret = (GQuark)gdk_pixbuf_error_quark();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("GLib.Quark"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_format_copy(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const GdkPixbufFormat* v1 = (const GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_format_copy(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufFormat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_format_free(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufFormat* v1 = (GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  gdk_pixbuf_format_free(v1);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_format_get_description(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufFormat* v1 = (GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_format_get_description(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : Rf_mkString(_ret ? (const char*)_ret : ""));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("utf8"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_format_get_extensions(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufFormat* v1 = (GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_format_get_extensions(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : tag_pointer(Rf_mkString(_ret ? (const char*)_ret : ""), "utf8"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("utf8"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_format_get_license(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufFormat* v1 = (GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_format_get_license(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : Rf_mkString(_ret ? (const char*)_ret : ""));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("utf8"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_format_get_mime_types(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufFormat* v1 = (GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_format_get_mime_types(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : tag_pointer(Rf_mkString(_ret ? (const char*)_ret : ""), "utf8"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("utf8"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_format_get_name(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufFormat* v1 = (GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_format_get_name(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : Rf_mkString(_ret ? (const char*)_ret : ""));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("utf8"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_format_is_disabled(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufFormat* v1 = (GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  gboolean _ret = (gboolean)gdk_pixbuf_format_is_disabled(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_format_is_save_option_supported(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufFormat* v1 = (GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  const char* v2 = (const char*)(CHAR(STRING_ELT(s2,0))); (void)v2;
  gboolean _ret = (gboolean)gdk_pixbuf_format_is_save_option_supported(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_format_is_scalable(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufFormat* v1 = (GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  gboolean _ret = (gboolean)gdk_pixbuf_format_is_scalable(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_format_is_writable(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufFormat* v1 = (GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  gboolean _ret = (gboolean)gdk_pixbuf_format_is_writable(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_format_set_disabled(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufFormat* v1 = (GdkPixbufFormat*)(get_ptr(s1)); (void)v1;
  gboolean v2 = (gboolean)((gboolean)LOGICAL(s2)[0]); (void)v2;
  gdk_pixbuf_format_set_disabled(v1, v2);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_loader_new(void) {
  RGTK4_REQUIRE_INIT();

  gconstpointer _ret = (gconstpointer)gdk_pixbuf_loader_new();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufLoader"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_loader_new_with_mime_type(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_loader_new_with_mime_type(v1, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufLoader"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_loader_new_with_type(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  const char* v1 = (const char*)(CHAR(STRING_ELT(s1,0))); (void)v1;
  GError *_err = NULL;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_loader_new_with_type(v1, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufLoader"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_loader_close(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufLoader* v1 = (GdkPixbufLoader*)(get_ptr(s1)); (void)v1;
  GError *_err = NULL;
  gboolean _ret = (gboolean)gdk_pixbuf_loader_close(v1, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_loader_get_animation(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufLoader* v1 = (GdkPixbufLoader*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_loader_get_animation(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufAnimation"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_loader_get_format(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufLoader* v1 = (GdkPixbufLoader*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_loader_get_format(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufFormat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_loader_get_pixbuf(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufLoader* v1 = (GdkPixbufLoader*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_loader_get_pixbuf(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Pixbuf"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_loader_set_size(SEXP s1, SEXP s2, SEXP s3) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufLoader* v1 = (GdkPixbufLoader*)(get_ptr(s1)); (void)v1;
  gint v2 = (gint)((gint)_unbox_numeric(s2)); (void)v2;
  gint v3 = (gint)((gint)_unbox_numeric(s3)); (void)v3;
  gdk_pixbuf_loader_set_size(v1, v2, v3);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_loader_write(SEXP s1, SEXP s2, SEXP s3) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufLoader* v1 = (GdkPixbufLoader*)(get_ptr(s1)); (void)v1;
  const guchar* v2 = (const guchar*)(get_ptr(s2)); (void)v2;
  gsize v3 = (gsize)((gsize)_unbox_numeric(s3)); (void)v3;
  GError *_err = NULL;
  gboolean _ret = (gboolean)gdk_pixbuf_loader_write(v1, v2, v3, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_loader_write_bytes(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufLoader* v1 = (GdkPixbufLoader*)(get_ptr(s1)); (void)v1;
  GBytes* v2 = (GBytes*)(get_ptr(s2)); (void)v2;
  GError *_err = NULL;
  gboolean _ret = (gboolean)gdk_pixbuf_loader_write_bytes(v1, v2, &_err);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_simple_anim_new(SEXP s1, SEXP s2, SEXP s3) {
  RGTK4_REQUIRE_INIT();
  gint v1 = (gint)((gint)_unbox_numeric(s1)); (void)v1;
  gint v2 = (gint)((gint)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)gdk_pixbuf_simple_anim_new(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("PixbufSimpleAnim"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_simple_anim_add_frame(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufSimpleAnim* v1 = (GdkPixbufSimpleAnim*)(get_ptr(s1)); (void)v1;
  GdkPixbuf* v2 = (GdkPixbuf*)(get_ptr(s2)); (void)v2;
  gdk_pixbuf_simple_anim_add_frame(v1, v2);
  return R_NilValue;
}


SEXP R_gdk_pixbuf_simple_anim_get_loop(SEXP s1) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufSimpleAnim* v1 = (GdkPixbufSimpleAnim*)(get_ptr(s1)); (void)v1;
  gboolean _ret = (gboolean)gdk_pixbuf_simple_anim_get_loop(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarInteger((int)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_gdk_pixbuf_simple_anim_set_loop(SEXP s1, SEXP s2) {
  RGTK4_REQUIRE_INIT();
  GdkPixbufSimpleAnim* v1 = (GdkPixbufSimpleAnim*)(get_ptr(s1)); (void)v1;
  gboolean v2 = (gboolean)((gboolean)LOGICAL(s2)[0]); (void)v2;
  gdk_pixbuf_simple_anim_set_loop(v1, v2);
  return R_NilValue;
}

