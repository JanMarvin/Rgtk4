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

/* Autogenerated for Graphene */
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#ifdef __clang__
#pragma GCC diagnostic ignored "-Wimplicit-enum-enum-cast"
#endif


SEXP R_graphene_box_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_box_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_contains_box(SEXP s1, SEXP s2) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  const graphene_box_t* v2 = (const graphene_box_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_box_contains_box(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_contains_point(SEXP s1, SEXP s2) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_box_contains_point(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_equal(SEXP s1, SEXP s2) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  const graphene_box_t* v2 = (const graphene_box_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_box_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_expand(SEXP s1, SEXP s2) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  graphene_box_t _out_res = {0}; (void)_out_res;
  graphene_box_expand(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_box_t), "graphene_box_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_expand_scalar(SEXP s1, SEXP s2) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_box_t _out_res = {0}; (void)_out_res;
  graphene_box_expand_scalar(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_box_t), "graphene_box_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_expand_vec3(SEXP s1, SEXP s2) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  graphene_box_t _out_res = {0}; (void)_out_res;
  graphene_box_expand_vec3(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_box_t), "graphene_box_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_free(SEXP s1) {
  graphene_box_t* v1 = (graphene_box_t*)(get_ptr(s1)); (void)v1;
  graphene_box_free(v1);
  return R_NilValue;
}


SEXP R_graphene_box_get_bounding_sphere(SEXP s1) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  graphene_sphere_t _out_sphere = {0}; (void)_out_sphere;
  graphene_box_get_bounding_sphere(v1, &_out_sphere);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_sphere, sizeof(graphene_sphere_t), "graphene_sphere_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Sphere"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("sphere"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_get_center(SEXP s1) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  graphene_point3d_t _out_center = {0}; (void)_out_center;
  graphene_box_get_center(v1, &_out_center);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_center, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("center"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_get_depth(SEXP s1) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_box_get_depth(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_get_height(SEXP s1) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_box_get_height(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_get_max(SEXP s1) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  graphene_point3d_t _out_max = {0}; (void)_out_max;
  graphene_box_get_max(v1, &_out_max);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_max, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("max"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_get_min(SEXP s1) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  graphene_point3d_t _out_min = {0}; (void)_out_min;
  graphene_box_get_min(v1, &_out_min);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_min, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("min"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_get_size(SEXP s1) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_size = {0}; (void)_out_size;
  graphene_box_get_size(v1, &_out_size);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_size, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("size"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_get_vertices(SEXP s1) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_vertices = {0}; (void)_out_vertices;
  graphene_box_get_vertices(v1, &_out_vertices);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_vertices, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("vertices"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_get_width(SEXP s1) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_box_get_width(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_init(SEXP s1, SEXP s2, SEXP s3) {
  graphene_box_t* v1 = (graphene_box_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (s2 != R_NilValue) ? (const graphene_point3d_t*)(get_ptr(s2)) : NULL; (void)v2;
  const graphene_point3d_t* v3 = (s3 != R_NilValue) ? (const graphene_point3d_t*)(get_ptr(s3)) : NULL; (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_box_init(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_init_from_box(SEXP s1, SEXP s2) {
  graphene_box_t* v1 = (graphene_box_t*)(get_ptr(s1)); (void)v1;
  const graphene_box_t* v2 = (const graphene_box_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_box_init_from_box(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_init_from_points(SEXP s1, SEXP s2, SEXP s3) {
  graphene_box_t* v1 = (graphene_box_t*)(get_ptr(s1)); (void)v1;
  guint v2 = (guint)((guint)_unbox_numeric(s2)); (void)v2;
  const graphene_point3d_t* v3 = (const graphene_point3d_t*)(get_ptr(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_box_init_from_points(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_init_from_vec3(SEXP s1, SEXP s2, SEXP s3) {
  graphene_box_t* v1 = (graphene_box_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (s2 != R_NilValue) ? (const graphene_vec3_t*)(get_ptr(s2)) : NULL; (void)v2;
  const graphene_vec3_t* v3 = (s3 != R_NilValue) ? (const graphene_vec3_t*)(get_ptr(s3)) : NULL; (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_box_init_from_vec3(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_init_from_vectors(SEXP s1, SEXP s2, SEXP s3) {
  graphene_box_t* v1 = (graphene_box_t*)(get_ptr(s1)); (void)v1;
  guint v2 = (guint)((guint)_unbox_numeric(s2)); (void)v2;
  const graphene_vec3_t* v3 = (const graphene_vec3_t*)(get_ptr(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_box_init_from_vectors(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_intersection(SEXP s1, SEXP s2) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  const graphene_box_t* v2 = (const graphene_box_t*)(get_ptr(s2)); (void)v2;
  graphene_box_t _out_res = {0}; (void)_out_res;
  _Bool _ret = (_Bool)graphene_box_intersection(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, make_boxed_struct(&_out_res, sizeof(graphene_box_t), "graphene_box_t"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_union(SEXP s1, SEXP s2) {
  const graphene_box_t* v1 = (const graphene_box_t*)(get_ptr(s1)); (void)v1;
  const graphene_box_t* v2 = (const graphene_box_t*)(get_ptr(s2)); (void)v2;
  graphene_box_t _out_res = {0}; (void)_out_res;
  graphene_box_union(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_box_t), "graphene_box_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_empty(void) {

  gconstpointer _ret = (gconstpointer)graphene_box_empty();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_infinite(void) {

  gconstpointer _ret = (gconstpointer)graphene_box_infinite();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_minus_one(void) {

  gconstpointer _ret = (gconstpointer)graphene_box_minus_one();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_one(void) {

  gconstpointer _ret = (gconstpointer)graphene_box_one();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_one_minus_one(void) {

  gconstpointer _ret = (gconstpointer)graphene_box_one_minus_one();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_box_zero(void) {

  gconstpointer _ret = (gconstpointer)graphene_box_zero();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_box_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Box"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_euler_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_euler_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Euler"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Euler"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_equal(SEXP s1, SEXP s2) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  const graphene_euler_t* v2 = (const graphene_euler_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_euler_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_free(SEXP s1) {
  graphene_euler_t* v1 = (graphene_euler_t*)(get_ptr(s1)); (void)v1;
  graphene_euler_free(v1);
  return R_NilValue;
}


SEXP R_graphene_euler_get_alpha(SEXP s1) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_euler_get_alpha(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_get_beta(SEXP s1) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_euler_get_beta(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_get_gamma(SEXP s1) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_euler_get_gamma(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_get_order(SEXP s1) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  graphene_euler_order_t _ret = (graphene_euler_order_t)graphene_euler_get_order(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(R_MakeExternalPtr((void*)(_ret), R_NilValue, R_NilValue), "EulerOrder"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("EulerOrder"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_get_x(SEXP s1) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_euler_get_x(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_get_y(SEXP s1) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_euler_get_y(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_get_z(SEXP s1) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_euler_get_z(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_init(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_euler_t* v1 = (graphene_euler_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_euler_init(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_euler_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Euler"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Euler"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_init_from_euler(SEXP s1, SEXP s2) {
  graphene_euler_t* v1 = (graphene_euler_t*)(get_ptr(s1)); (void)v1;
  const graphene_euler_t* v2 = (s2 != R_NilValue) ? (const graphene_euler_t*)(get_ptr(s2)) : NULL; (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_euler_init_from_euler(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_euler_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Euler"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Euler"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_init_from_matrix(SEXP s1, SEXP s2, SEXP s3) {
  graphene_euler_t* v1 = (graphene_euler_t*)(get_ptr(s1)); (void)v1;
  const graphene_matrix_t* v2 = (s2 != R_NilValue) ? (const graphene_matrix_t*)(get_ptr(s2)) : NULL; (void)v2;
  graphene_euler_order_t v3 = (graphene_euler_order_t)((graphene_euler_order_t)(TYPEOF(s3)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s3) : INTEGER(s3)[0])); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_euler_init_from_matrix(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_euler_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Euler"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Euler"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_init_from_quaternion(SEXP s1, SEXP s2, SEXP s3) {
  graphene_euler_t* v1 = (graphene_euler_t*)(get_ptr(s1)); (void)v1;
  const graphene_quaternion_t* v2 = (s2 != R_NilValue) ? (const graphene_quaternion_t*)(get_ptr(s2)) : NULL; (void)v2;
  graphene_euler_order_t v3 = (graphene_euler_order_t)((graphene_euler_order_t)(TYPEOF(s3)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s3) : INTEGER(s3)[0])); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_euler_init_from_quaternion(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_euler_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Euler"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Euler"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_init_from_radians(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  graphene_euler_t* v1 = (graphene_euler_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  graphene_euler_order_t v5 = (graphene_euler_order_t)((graphene_euler_order_t)(TYPEOF(s5)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s5) : INTEGER(s5)[0])); (void)v5;
  gconstpointer _ret = (gconstpointer)graphene_euler_init_from_radians(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_euler_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Euler"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Euler"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_init_from_vec3(SEXP s1, SEXP s2, SEXP s3) {
  graphene_euler_t* v1 = (graphene_euler_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (s2 != R_NilValue) ? (const graphene_vec3_t*)(get_ptr(s2)) : NULL; (void)v2;
  graphene_euler_order_t v3 = (graphene_euler_order_t)((graphene_euler_order_t)(TYPEOF(s3)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s3) : INTEGER(s3)[0])); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_euler_init_from_vec3(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_euler_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Euler"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Euler"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_init_with_order(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  graphene_euler_t* v1 = (graphene_euler_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  graphene_euler_order_t v5 = (graphene_euler_order_t)((graphene_euler_order_t)(TYPEOF(s5)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s5) : INTEGER(s5)[0])); (void)v5;
  gconstpointer _ret = (gconstpointer)graphene_euler_init_with_order(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_euler_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Euler"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Euler"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_reorder(SEXP s1, SEXP s2) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  graphene_euler_order_t v2 = (graphene_euler_order_t)((graphene_euler_order_t)(TYPEOF(s2)==EXTPTRSXP ? (size_t)R_ExternalPtrAddr(s2) : INTEGER(s2)[0])); (void)v2;
  graphene_euler_t _out_res = {0}; (void)_out_res;
  graphene_euler_reorder(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_euler_t), "graphene_euler_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Euler"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_to_matrix(SEXP s1) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  graphene_matrix_t _out_res = {0}; (void)_out_res;
  graphene_euler_to_matrix(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_matrix_t), "graphene_matrix_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_to_quaternion(SEXP s1) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  graphene_quaternion_t _out_res = {0}; (void)_out_res;
  graphene_euler_to_quaternion(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_quaternion_t), "graphene_quaternion_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_euler_to_vec3(SEXP s1) {
  const graphene_euler_t* v1 = (const graphene_euler_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_euler_to_vec3(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_frustum_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_frustum_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_frustum_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Frustum"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Frustum"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_frustum_contains_point(SEXP s1, SEXP s2) {
  const graphene_frustum_t* v1 = (const graphene_frustum_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_frustum_contains_point(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_frustum_equal(SEXP s1, SEXP s2) {
  const graphene_frustum_t* v1 = (const graphene_frustum_t*)(get_ptr(s1)); (void)v1;
  const graphene_frustum_t* v2 = (const graphene_frustum_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_frustum_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_frustum_free(SEXP s1) {
  graphene_frustum_t* v1 = (graphene_frustum_t*)(get_ptr(s1)); (void)v1;
  graphene_frustum_free(v1);
  return R_NilValue;
}


SEXP R_graphene_frustum_get_planes(SEXP s1) {
  const graphene_frustum_t* v1 = (const graphene_frustum_t*)(get_ptr(s1)); (void)v1;
  graphene_plane_t _out_planes = {0}; (void)_out_planes;
  graphene_frustum_get_planes(v1, &_out_planes);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_planes, sizeof(graphene_plane_t), "graphene_plane_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Plane"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("planes"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_frustum_init(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7) {
  graphene_frustum_t* v1 = (graphene_frustum_t*)(get_ptr(s1)); (void)v1;
  const graphene_plane_t* v2 = (const graphene_plane_t*)(get_ptr(s2)); (void)v2;
  const graphene_plane_t* v3 = (const graphene_plane_t*)(get_ptr(s3)); (void)v3;
  const graphene_plane_t* v4 = (const graphene_plane_t*)(get_ptr(s4)); (void)v4;
  const graphene_plane_t* v5 = (const graphene_plane_t*)(get_ptr(s5)); (void)v5;
  const graphene_plane_t* v6 = (const graphene_plane_t*)(get_ptr(s6)); (void)v6;
  const graphene_plane_t* v7 = (const graphene_plane_t*)(get_ptr(s7)); (void)v7;
  gconstpointer _ret = (gconstpointer)graphene_frustum_init(v1, v2, v3, v4, v5, v6, v7);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_frustum_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Frustum"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Frustum"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_frustum_init_from_frustum(SEXP s1, SEXP s2) {
  graphene_frustum_t* v1 = (graphene_frustum_t*)(get_ptr(s1)); (void)v1;
  const graphene_frustum_t* v2 = (const graphene_frustum_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_frustum_init_from_frustum(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_frustum_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Frustum"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Frustum"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_frustum_init_from_matrix(SEXP s1, SEXP s2) {
  graphene_frustum_t* v1 = (graphene_frustum_t*)(get_ptr(s1)); (void)v1;
  const graphene_matrix_t* v2 = (const graphene_matrix_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_frustum_init_from_matrix(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_frustum_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Frustum"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Frustum"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_frustum_intersects_box(SEXP s1, SEXP s2) {
  const graphene_frustum_t* v1 = (const graphene_frustum_t*)(get_ptr(s1)); (void)v1;
  const graphene_box_t* v2 = (const graphene_box_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_frustum_intersects_box(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_frustum_intersects_sphere(SEXP s1, SEXP s2) {
  const graphene_frustum_t* v1 = (const graphene_frustum_t*)(get_ptr(s1)); (void)v1;
  const graphene_sphere_t* v2 = (const graphene_sphere_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_frustum_intersects_sphere(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_matrix_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_decompose(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_translate = {0}; (void)_out_translate;
  graphene_vec3_t _out_scale = {0}; (void)_out_scale;
  graphene_quaternion_t _out_rotate = {0}; (void)_out_rotate;
  graphene_vec3_t _out_shear = {0}; (void)_out_shear;
  graphene_vec4_t _out_perspective = {0}; (void)_out_perspective;
  _Bool _ret = (_Bool)graphene_matrix_decompose(v1, &_out_translate, &_out_scale, &_out_rotate, &_out_shear, &_out_perspective);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 6));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 6));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, make_boxed_struct(&_out_translate, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("translate"));
  SET_VECTOR_ELT(_ans, 2, make_boxed_struct(&_out_scale, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 2) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 2), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 2, Rf_mkChar("scale"));
  SET_VECTOR_ELT(_ans, 3, make_boxed_struct(&_out_rotate, sizeof(graphene_quaternion_t), "graphene_quaternion_t"));
  if (VECTOR_ELT(_ans, 3) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 3), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 3, Rf_mkChar("rotate"));
  SET_VECTOR_ELT(_ans, 4, make_boxed_struct(&_out_shear, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 4) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 4), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 4, Rf_mkChar("shear"));
  SET_VECTOR_ELT(_ans, 5, make_boxed_struct(&_out_perspective, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 5) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 5), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 5, Rf_mkChar("perspective"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_determinant(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_matrix_determinant(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_equal(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_matrix_t* v2 = (const graphene_matrix_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_matrix_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_equal_fast(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_matrix_t* v2 = (const graphene_matrix_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_matrix_equal_fast(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_free(SEXP s1) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  graphene_matrix_free(v1);
  return R_NilValue;
}


SEXP R_graphene_matrix_get_row(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  guint v2 = (guint)((guint)_unbox_numeric(s2)); (void)v2;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_matrix_get_row(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_get_value(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  guint v2 = (guint)((guint)_unbox_numeric(s2)); (void)v2;
  guint v3 = (guint)((guint)_unbox_numeric(s3)); (void)v3;
  float _ret = (float)graphene_matrix_get_value(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_get_x_scale(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_matrix_get_x_scale(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_get_x_translation(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_matrix_get_x_translation(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_get_y_scale(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_matrix_get_y_scale(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_get_y_translation(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_matrix_get_y_translation(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_get_z_scale(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_matrix_get_z_scale(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_get_z_translation(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_matrix_get_z_translation(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_from_2d(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gdouble v2 = (gdouble)((gdouble)_unbox_numeric(s2)); (void)v2;
  gdouble v3 = (gdouble)((gdouble)_unbox_numeric(s3)); (void)v3;
  gdouble v4 = (gdouble)((gdouble)_unbox_numeric(s4)); (void)v4;
  gdouble v5 = (gdouble)((gdouble)_unbox_numeric(s5)); (void)v5;
  gdouble v6 = (gdouble)((gdouble)_unbox_numeric(s6)); (void)v6;
  gdouble v7 = (gdouble)((gdouble)_unbox_numeric(s7)); (void)v7;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_from_2d(v1, v2, v3, v4, v5, v6, v7);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_from_float(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const float* v2 = (const float*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_from_float(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_from_matrix(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_matrix_t* v2 = (const graphene_matrix_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_from_matrix(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_from_vec4(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  const graphene_vec4_t* v3 = (const graphene_vec4_t*)(get_ptr(s3)); (void)v3;
  const graphene_vec4_t* v4 = (const graphene_vec4_t*)(get_ptr(s4)); (void)v4;
  const graphene_vec4_t* v5 = (const graphene_vec4_t*)(get_ptr(s5)); (void)v5;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_from_vec4(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_frustum(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gfloat v5 = (gfloat)((gfloat)_unbox_numeric(s5)); (void)v5;
  gfloat v6 = (gfloat)((gfloat)_unbox_numeric(s6)); (void)v6;
  gfloat v7 = (gfloat)((gfloat)_unbox_numeric(s7)); (void)v7;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_frustum(v1, v2, v3, v4, v5, v6, v7);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_identity(SEXP s1) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_identity(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_look_at(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  const graphene_vec3_t* v3 = (const graphene_vec3_t*)(get_ptr(s3)); (void)v3;
  const graphene_vec3_t* v4 = (const graphene_vec3_t*)(get_ptr(s4)); (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_look_at(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_ortho(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gfloat v5 = (gfloat)((gfloat)_unbox_numeric(s5)); (void)v5;
  gfloat v6 = (gfloat)((gfloat)_unbox_numeric(s6)); (void)v6;
  gfloat v7 = (gfloat)((gfloat)_unbox_numeric(s7)); (void)v7;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_ortho(v1, v2, v3, v4, v5, v6, v7);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_perspective(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gfloat v5 = (gfloat)((gfloat)_unbox_numeric(s5)); (void)v5;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_perspective(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_rotate(SEXP s1, SEXP s2, SEXP s3) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  const graphene_vec3_t* v3 = (const graphene_vec3_t*)(get_ptr(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_rotate(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_scale(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_scale(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_skew(SEXP s1, SEXP s2, SEXP s3) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_skew(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_init_translate(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_matrix_init_translate(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_matrix_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Matrix"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_interpolate(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_matrix_t* v2 = (const graphene_matrix_t*)(get_ptr(s2)); (void)v2;
  gdouble v3 = (gdouble)((gdouble)_unbox_numeric(s3)); (void)v3;
  graphene_matrix_t _out_res = {0}; (void)_out_res;
  graphene_matrix_interpolate(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_matrix_t), "graphene_matrix_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_inverse(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  graphene_matrix_t _out_res = {0}; (void)_out_res;
  _Bool _ret = (_Bool)graphene_matrix_inverse(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, make_boxed_struct(&_out_res, sizeof(graphene_matrix_t), "graphene_matrix_t"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_is_2d(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  _Bool _ret = (_Bool)graphene_matrix_is_2d(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_is_backface_visible(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  _Bool _ret = (_Bool)graphene_matrix_is_backface_visible(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_is_identity(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  _Bool _ret = (_Bool)graphene_matrix_is_identity(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_is_singular(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  _Bool _ret = (_Bool)graphene_matrix_is_singular(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_multiply(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_matrix_t* v2 = (const graphene_matrix_t*)(get_ptr(s2)); (void)v2;
  graphene_matrix_t _out_res = {0}; (void)_out_res;
  graphene_matrix_multiply(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_matrix_t), "graphene_matrix_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_near(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_matrix_t* v2 = (const graphene_matrix_t*)(get_ptr(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  _Bool _ret = (_Bool)graphene_matrix_near(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_normalize(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  graphene_matrix_t _out_res = {0}; (void)_out_res;
  graphene_matrix_normalize(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_matrix_t), "graphene_matrix_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_perspective(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_matrix_t _out_res = {0}; (void)_out_res;
  graphene_matrix_perspective(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_matrix_t), "graphene_matrix_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_print(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  graphene_matrix_print(v1);
  return R_NilValue;
}


SEXP R_graphene_matrix_project_point(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  graphene_point_t _out_res = {0}; (void)_out_res;
  graphene_matrix_project_point(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point_t), "graphene_point_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_project_rect(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  graphene_quad_t _out_res = {0}; (void)_out_res;
  graphene_matrix_project_rect(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(R_MakeExternalPtr((void*)(&_out_res), R_NilValue, R_NilValue), "Quad"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quad"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_project_rect_bounds(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_matrix_project_rect_bounds(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_rotate(SEXP s1, SEXP s2, SEXP s3) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  const graphene_vec3_t* v3 = (const graphene_vec3_t*)(get_ptr(s3)); (void)v3;
  graphene_matrix_rotate(v1, v2, v3);
  return R_NilValue;
}


SEXP R_graphene_matrix_rotate_euler(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_euler_t* v2 = (const graphene_euler_t*)(get_ptr(s2)); (void)v2;
  graphene_matrix_rotate_euler(v1, v2);
  return R_NilValue;
}


SEXP R_graphene_matrix_rotate_quaternion(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_quaternion_t* v2 = (const graphene_quaternion_t*)(get_ptr(s2)); (void)v2;
  graphene_matrix_rotate_quaternion(v1, v2);
  return R_NilValue;
}


SEXP R_graphene_matrix_rotate_x(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_matrix_rotate_x(v1, v2);
  return R_NilValue;
}


SEXP R_graphene_matrix_rotate_y(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_matrix_rotate_y(v1, v2);
  return R_NilValue;
}


SEXP R_graphene_matrix_rotate_z(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_matrix_rotate_z(v1, v2);
  return R_NilValue;
}


SEXP R_graphene_matrix_scale(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  graphene_matrix_scale(v1, v2, v3, v4);
  return R_NilValue;
}


SEXP R_graphene_matrix_skew_xy(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_matrix_skew_xy(v1, v2);
  return R_NilValue;
}


SEXP R_graphene_matrix_skew_xz(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_matrix_skew_xz(v1, v2);
  return R_NilValue;
}


SEXP R_graphene_matrix_skew_yz(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_matrix_skew_yz(v1, v2);
  return R_NilValue;
}


SEXP R_graphene_matrix_to_2d(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  double _out_xx = 0; (void)_out_xx;
  double _out_yx = 0; (void)_out_yx;
  double _out_xy = 0; (void)_out_xy;
  double _out_yy = 0; (void)_out_yy;
  double _out_x_0 = 0; (void)_out_x_0;
  double _out_y_0 = 0; (void)_out_y_0;
  _Bool _ret = (_Bool)graphene_matrix_to_2d(v1, &_out_xx, &_out_yx, &_out_xy, &_out_yy, &_out_x_0, &_out_y_0);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 7));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 7));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, Rf_ScalarReal((double)(size_t)(_out_xx)));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("gdouble"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("xx"));
  SET_VECTOR_ELT(_ans, 2, Rf_ScalarReal((double)(size_t)(_out_yx)));
  if (VECTOR_ELT(_ans, 2) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 2), Rf_install("glib_type"), Rf_mkString("gdouble"));
  }
  SET_STRING_ELT(_ans_names, 2, Rf_mkChar("yx"));
  SET_VECTOR_ELT(_ans, 3, Rf_ScalarReal((double)(size_t)(_out_xy)));
  if (VECTOR_ELT(_ans, 3) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 3), Rf_install("glib_type"), Rf_mkString("gdouble"));
  }
  SET_STRING_ELT(_ans_names, 3, Rf_mkChar("xy"));
  SET_VECTOR_ELT(_ans, 4, Rf_ScalarReal((double)(size_t)(_out_yy)));
  if (VECTOR_ELT(_ans, 4) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 4), Rf_install("glib_type"), Rf_mkString("gdouble"));
  }
  SET_STRING_ELT(_ans_names, 4, Rf_mkChar("yy"));
  SET_VECTOR_ELT(_ans, 5, Rf_ScalarReal((double)(size_t)(_out_x_0)));
  if (VECTOR_ELT(_ans, 5) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 5), Rf_install("glib_type"), Rf_mkString("gdouble"));
  }
  SET_STRING_ELT(_ans_names, 5, Rf_mkChar("x_0"));
  SET_VECTOR_ELT(_ans, 6, Rf_ScalarReal((double)(size_t)(_out_y_0)));
  if (VECTOR_ELT(_ans, 6) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 6), Rf_install("glib_type"), Rf_mkString("gdouble"));
  }
  SET_STRING_ELT(_ans_names, 6, Rf_mkChar("y_0"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_to_float(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  float _out_v = 0; (void)_out_v;
  graphene_matrix_to_float(v1, &_out_v);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_out_v)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("v"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_transform_bounds(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_matrix_transform_bounds(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_transform_box(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_box_t* v2 = (const graphene_box_t*)(get_ptr(s2)); (void)v2;
  graphene_box_t _out_res = {0}; (void)_out_res;
  graphene_matrix_transform_box(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_box_t), "graphene_box_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_transform_point(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  graphene_point_t _out_res = {0}; (void)_out_res;
  graphene_matrix_transform_point(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point_t), "graphene_point_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_transform_point3d(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  graphene_point3d_t _out_res = {0}; (void)_out_res;
  graphene_matrix_transform_point3d(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_transform_ray(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_ray_t* v2 = (const graphene_ray_t*)(get_ptr(s2)); (void)v2;
  graphene_ray_t _out_res = {0}; (void)_out_res;
  graphene_matrix_transform_ray(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_ray_t), "graphene_ray_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Ray"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_transform_rect(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  graphene_quad_t _out_res = {0}; (void)_out_res;
  graphene_matrix_transform_rect(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(R_MakeExternalPtr((void*)(&_out_res), R_NilValue, R_NilValue), "Quad"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quad"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_transform_sphere(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_sphere_t* v2 = (const graphene_sphere_t*)(get_ptr(s2)); (void)v2;
  graphene_sphere_t _out_res = {0}; (void)_out_res;
  graphene_matrix_transform_sphere(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_sphere_t), "graphene_sphere_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Sphere"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_transform_vec3(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_matrix_transform_vec3(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_transform_vec4(SEXP s1, SEXP s2) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_matrix_transform_vec4(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_translate(SEXP s1, SEXP s2) {
  graphene_matrix_t* v1 = (graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  graphene_matrix_translate(v1, v2);
  return R_NilValue;
}


SEXP R_graphene_matrix_transpose(SEXP s1) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  graphene_matrix_t _out_res = {0}; (void)_out_res;
  graphene_matrix_transpose(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_matrix_t), "graphene_matrix_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_unproject_point3d(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_matrix_t* v2 = (const graphene_matrix_t*)(get_ptr(s2)); (void)v2;
  const graphene_point3d_t* v3 = (const graphene_point3d_t*)(get_ptr(s3)); (void)v3;
  graphene_point3d_t _out_res = {0}; (void)_out_res;
  graphene_matrix_unproject_point3d(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_untransform_bounds(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  const graphene_rect_t* v3 = (const graphene_rect_t*)(get_ptr(s3)); (void)v3;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_matrix_untransform_bounds(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_matrix_untransform_point(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_matrix_t* v1 = (const graphene_matrix_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  const graphene_rect_t* v3 = (const graphene_rect_t*)(get_ptr(s3)); (void)v3;
  graphene_point_t _out_res = {0}; (void)_out_res;
  _Bool _ret = (_Bool)graphene_matrix_untransform_point(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, make_boxed_struct(&_out_res, sizeof(graphene_point_t), "graphene_point_t"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_plane_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_plane_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Plane"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Plane"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_distance(SEXP s1, SEXP s2) {
  const graphene_plane_t* v1 = (const graphene_plane_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  float _ret = (float)graphene_plane_distance(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_equal(SEXP s1, SEXP s2) {
  const graphene_plane_t* v1 = (const graphene_plane_t*)(get_ptr(s1)); (void)v1;
  const graphene_plane_t* v2 = (const graphene_plane_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_plane_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_free(SEXP s1) {
  graphene_plane_t* v1 = (graphene_plane_t*)(get_ptr(s1)); (void)v1;
  graphene_plane_free(v1);
  return R_NilValue;
}


SEXP R_graphene_plane_get_constant(SEXP s1) {
  const graphene_plane_t* v1 = (const graphene_plane_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_plane_get_constant(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_get_normal(SEXP s1) {
  const graphene_plane_t* v1 = (const graphene_plane_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_normal = {0}; (void)_out_normal;
  graphene_plane_get_normal(v1, &_out_normal);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_normal, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("normal"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_init(SEXP s1, SEXP s2, SEXP s3) {
  graphene_plane_t* v1 = (graphene_plane_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (s2 != R_NilValue) ? (const graphene_vec3_t*)(get_ptr(s2)) : NULL; (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_plane_init(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_plane_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Plane"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Plane"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_init_from_plane(SEXP s1, SEXP s2) {
  graphene_plane_t* v1 = (graphene_plane_t*)(get_ptr(s1)); (void)v1;
  const graphene_plane_t* v2 = (const graphene_plane_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_plane_init_from_plane(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_plane_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Plane"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Plane"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_init_from_point(SEXP s1, SEXP s2, SEXP s3) {
  graphene_plane_t* v1 = (graphene_plane_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  const graphene_point3d_t* v3 = (const graphene_point3d_t*)(get_ptr(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_plane_init_from_point(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_plane_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Plane"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Plane"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_init_from_points(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_plane_t* v1 = (graphene_plane_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  const graphene_point3d_t* v3 = (const graphene_point3d_t*)(get_ptr(s3)); (void)v3;
  const graphene_point3d_t* v4 = (const graphene_point3d_t*)(get_ptr(s4)); (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_plane_init_from_points(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_plane_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Plane"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Plane"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_init_from_vec4(SEXP s1, SEXP s2) {
  graphene_plane_t* v1 = (graphene_plane_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_plane_init_from_vec4(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_plane_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Plane"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Plane"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_negate(SEXP s1) {
  const graphene_plane_t* v1 = (const graphene_plane_t*)(get_ptr(s1)); (void)v1;
  graphene_plane_t _out_res = {0}; (void)_out_res;
  graphene_plane_negate(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_plane_t), "graphene_plane_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Plane"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_normalize(SEXP s1) {
  const graphene_plane_t* v1 = (const graphene_plane_t*)(get_ptr(s1)); (void)v1;
  graphene_plane_t _out_res = {0}; (void)_out_res;
  graphene_plane_normalize(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_plane_t), "graphene_plane_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Plane"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_plane_transform(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_plane_t* v1 = (const graphene_plane_t*)(get_ptr(s1)); (void)v1;
  const graphene_matrix_t* v2 = (const graphene_matrix_t*)(get_ptr(s2)); (void)v2;
  const graphene_matrix_t* v3 = (s3 != R_NilValue) ? (const graphene_matrix_t*)(get_ptr(s3)) : NULL; (void)v3;
  graphene_plane_t _out_res = {0}; (void)_out_res;
  graphene_plane_transform(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_plane_t), "graphene_plane_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Plane"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_point_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_point_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Point"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point_distance(SEXP s1, SEXP s2) {
  const graphene_point_t* v1 = (const graphene_point_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  float _out_d_x = 0; (void)_out_d_x;
  float _out_d_y = 0; (void)_out_d_y;
  float _ret = (float)graphene_point_distance(v1, v2, &_out_d_x, &_out_d_y);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 3));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 3));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, Rf_ScalarReal((double)(size_t)(_out_d_x)));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("d_x"));
  SET_VECTOR_ELT(_ans, 2, Rf_ScalarReal((double)(size_t)(_out_d_y)));
  if (VECTOR_ELT(_ans, 2) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 2), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 2, Rf_mkChar("d_y"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point_equal(SEXP s1, SEXP s2) {
  const graphene_point_t* v1 = (const graphene_point_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_point_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point_free(SEXP s1) {
  graphene_point_t* v1 = (graphene_point_t*)(get_ptr(s1)); (void)v1;
  graphene_point_free(v1);
  return R_NilValue;
}


SEXP R_graphene_point_init(SEXP s1, SEXP s2, SEXP s3) {
  graphene_point_t* v1 = (graphene_point_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_point_init(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_point_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Point"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point_init_from_point(SEXP s1, SEXP s2) {
  graphene_point_t* v1 = (graphene_point_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_point_init_from_point(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_point_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Point"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point_init_from_vec2(SEXP s1, SEXP s2) {
  graphene_point_t* v1 = (graphene_point_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_point_init_from_vec2(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_point_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Point"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point_interpolate(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_point_t* v1 = (const graphene_point_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  gdouble v3 = (gdouble)((gdouble)_unbox_numeric(s3)); (void)v3;
  graphene_point_t _out_res = {0}; (void)_out_res;
  graphene_point_interpolate(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point_t), "graphene_point_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point_near(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_point_t* v1 = (const graphene_point_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  _Bool _ret = (_Bool)graphene_point_near(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point_to_vec2(SEXP s1) {
  const graphene_point_t* v1 = (const graphene_point_t*)(get_ptr(s1)); (void)v1;
  graphene_vec2_t _out_v = {0}; (void)_out_v;
  graphene_point_to_vec2(v1, &_out_v);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_v, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("v"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point_zero(void) {

  gconstpointer _ret = (gconstpointer)graphene_point_zero();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_point_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Point"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_point3d_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_point3d_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Point3D"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_cross(SEXP s1, SEXP s2) {
  const graphene_point3d_t* v1 = (const graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  graphene_point3d_t _out_res = {0}; (void)_out_res;
  graphene_point3d_cross(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_distance(SEXP s1, SEXP s2) {
  const graphene_point3d_t* v1 = (const graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  graphene_vec3_t _out_delta = {0}; (void)_out_delta;
  float _ret = (float)graphene_point3d_distance(v1, v2, &_out_delta);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, make_boxed_struct(&_out_delta, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("delta"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_dot(SEXP s1, SEXP s2) {
  const graphene_point3d_t* v1 = (const graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  float _ret = (float)graphene_point3d_dot(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_equal(SEXP s1, SEXP s2) {
  const graphene_point3d_t* v1 = (const graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_point3d_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_free(SEXP s1) {
  graphene_point3d_t* v1 = (graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  graphene_point3d_free(v1);
  return R_NilValue;
}


SEXP R_graphene_point3d_init(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_point3d_t* v1 = (graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_point3d_init(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_point3d_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Point3D"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_init_from_point(SEXP s1, SEXP s2) {
  graphene_point3d_t* v1 = (graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_point3d_init_from_point(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_point3d_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Point3D"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_init_from_vec3(SEXP s1, SEXP s2) {
  graphene_point3d_t* v1 = (graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_point3d_init_from_vec3(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_point3d_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Point3D"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_interpolate(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_point3d_t* v1 = (const graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  gdouble v3 = (gdouble)((gdouble)_unbox_numeric(s3)); (void)v3;
  graphene_point3d_t _out_res = {0}; (void)_out_res;
  graphene_point3d_interpolate(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_length(SEXP s1) {
  const graphene_point3d_t* v1 = (const graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_point3d_length(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_near(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_point3d_t* v1 = (const graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  _Bool _ret = (_Bool)graphene_point3d_near(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_normalize(SEXP s1) {
  const graphene_point3d_t* v1 = (const graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  graphene_point3d_t _out_res = {0}; (void)_out_res;
  graphene_point3d_normalize(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_normalize_viewport(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  const graphene_point3d_t* v1 = (const graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  graphene_point3d_t _out_res = {0}; (void)_out_res;
  graphene_point3d_normalize_viewport(v1, v2, v3, v4, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_scale(SEXP s1, SEXP s2) {
  const graphene_point3d_t* v1 = (const graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_point3d_t _out_res = {0}; (void)_out_res;
  graphene_point3d_scale(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_to_vec3(SEXP s1) {
  const graphene_point3d_t* v1 = (const graphene_point3d_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_v = {0}; (void)_out_v;
  graphene_point3d_to_vec3(v1, &_out_v);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_v, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("v"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_point3d_zero(void) {

  gconstpointer _ret = (gconstpointer)graphene_point3d_zero();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_point3d_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Point3D"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quad_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_quad_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quad"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quad_bounds(SEXP s1) {
  const graphene_quad_t* v1 = (const graphene_quad_t*)(get_ptr(s1)); (void)v1;
  graphene_rect_t _out_r = {0}; (void)_out_r;
  graphene_quad_bounds(v1, &_out_r);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_r, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("r"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quad_contains(SEXP s1, SEXP s2) {
  const graphene_quad_t* v1 = (const graphene_quad_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_quad_contains(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quad_free(SEXP s1) {
  graphene_quad_t* v1 = (graphene_quad_t*)(get_ptr(s1)); (void)v1;
  graphene_quad_free(v1);
  return R_NilValue;
}


SEXP R_graphene_quad_get_point(SEXP s1, SEXP s2) {
  const graphene_quad_t* v1 = (const graphene_quad_t*)(get_ptr(s1)); (void)v1;
  guint v2 = (guint)((guint)_unbox_numeric(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_quad_get_point(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_point_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Point"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quad_init(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  graphene_quad_t* v1 = (graphene_quad_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  const graphene_point_t* v3 = (const graphene_point_t*)(get_ptr(s3)); (void)v3;
  const graphene_point_t* v4 = (const graphene_point_t*)(get_ptr(s4)); (void)v4;
  const graphene_point_t* v5 = (const graphene_point_t*)(get_ptr(s5)); (void)v5;
  gconstpointer _ret = (gconstpointer)graphene_quad_init(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quad"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quad_init_from_points(SEXP s1, SEXP s2) {
  graphene_quad_t* v1 = (graphene_quad_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_quad_init_from_points(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quad"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quad_init_from_rect(SEXP s1, SEXP s2) {
  graphene_quad_t* v1 = (graphene_quad_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_quad_init_from_rect(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : make_gobject_ptr((gpointer)_ret));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quad"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_quaternion_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_quaternion_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Quaternion"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_add(SEXP s1, SEXP s2) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  const graphene_quaternion_t* v2 = (const graphene_quaternion_t*)(get_ptr(s2)); (void)v2;
  graphene_quaternion_t _out_res = {0}; (void)_out_res;
  graphene_quaternion_add(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_quaternion_t), "graphene_quaternion_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_dot(SEXP s1, SEXP s2) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  const graphene_quaternion_t* v2 = (const graphene_quaternion_t*)(get_ptr(s2)); (void)v2;
  float _ret = (float)graphene_quaternion_dot(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_equal(SEXP s1, SEXP s2) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  const graphene_quaternion_t* v2 = (const graphene_quaternion_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_quaternion_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_free(SEXP s1) {
  graphene_quaternion_t* v1 = (graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  graphene_quaternion_free(v1);
  return R_NilValue;
}


SEXP R_graphene_quaternion_init(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  graphene_quaternion_t* v1 = (graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gfloat v5 = (gfloat)((gfloat)_unbox_numeric(s5)); (void)v5;
  gconstpointer _ret = (gconstpointer)graphene_quaternion_init(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_quaternion_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Quaternion"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_init_from_angle_vec3(SEXP s1, SEXP s2, SEXP s3) {
  graphene_quaternion_t* v1 = (graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  const graphene_vec3_t* v3 = (const graphene_vec3_t*)(get_ptr(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_quaternion_init_from_angle_vec3(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_quaternion_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Quaternion"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_init_from_angles(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_quaternion_t* v1 = (graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_quaternion_init_from_angles(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_quaternion_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Quaternion"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_init_from_euler(SEXP s1, SEXP s2) {
  graphene_quaternion_t* v1 = (graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  const graphene_euler_t* v2 = (const graphene_euler_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_quaternion_init_from_euler(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_quaternion_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Quaternion"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_init_from_matrix(SEXP s1, SEXP s2) {
  graphene_quaternion_t* v1 = (graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  const graphene_matrix_t* v2 = (const graphene_matrix_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_quaternion_init_from_matrix(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_quaternion_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Quaternion"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_init_from_quaternion(SEXP s1, SEXP s2) {
  graphene_quaternion_t* v1 = (graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  const graphene_quaternion_t* v2 = (const graphene_quaternion_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_quaternion_init_from_quaternion(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_quaternion_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Quaternion"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_init_from_radians(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_quaternion_t* v1 = (graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_quaternion_init_from_radians(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_quaternion_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Quaternion"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_init_from_vec4(SEXP s1, SEXP s2) {
  graphene_quaternion_t* v1 = (graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_quaternion_init_from_vec4(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_quaternion_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Quaternion"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_init_identity(SEXP s1) {
  graphene_quaternion_t* v1 = (graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)graphene_quaternion_init_identity(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_quaternion_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Quaternion"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_invert(SEXP s1) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  graphene_quaternion_t _out_res = {0}; (void)_out_res;
  graphene_quaternion_invert(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_quaternion_t), "graphene_quaternion_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_multiply(SEXP s1, SEXP s2) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  const graphene_quaternion_t* v2 = (const graphene_quaternion_t*)(get_ptr(s2)); (void)v2;
  graphene_quaternion_t _out_res = {0}; (void)_out_res;
  graphene_quaternion_multiply(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_quaternion_t), "graphene_quaternion_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_normalize(SEXP s1) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  graphene_quaternion_t _out_res = {0}; (void)_out_res;
  graphene_quaternion_normalize(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_quaternion_t), "graphene_quaternion_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_scale(SEXP s1, SEXP s2) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_quaternion_t _out_res = {0}; (void)_out_res;
  graphene_quaternion_scale(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_quaternion_t), "graphene_quaternion_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_slerp(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  const graphene_quaternion_t* v2 = (const graphene_quaternion_t*)(get_ptr(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  graphene_quaternion_t _out_res = {0}; (void)_out_res;
  graphene_quaternion_slerp(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_quaternion_t), "graphene_quaternion_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Quaternion"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_to_angle_vec3(SEXP s1) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  float _out_angle = 0; (void)_out_angle;
  graphene_vec3_t _out_axis = {0}; (void)_out_axis;
  graphene_quaternion_to_angle_vec3(v1, &_out_angle, &_out_axis);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_out_angle)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("angle"));
  SET_VECTOR_ELT(_ans, 1, make_boxed_struct(&_out_axis, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("axis"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_to_angles(SEXP s1) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  float _out_deg_x = 0; (void)_out_deg_x;
  float _out_deg_y = 0; (void)_out_deg_y;
  float _out_deg_z = 0; (void)_out_deg_z;
  graphene_quaternion_to_angles(v1, &_out_deg_x, &_out_deg_y, &_out_deg_z);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 3));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 3));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_out_deg_x)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("deg_x"));
  SET_VECTOR_ELT(_ans, 1, Rf_ScalarReal((double)(size_t)(_out_deg_y)));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("deg_y"));
  SET_VECTOR_ELT(_ans, 2, Rf_ScalarReal((double)(size_t)(_out_deg_z)));
  if (VECTOR_ELT(_ans, 2) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 2), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 2, Rf_mkChar("deg_z"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_to_matrix(SEXP s1) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  graphene_matrix_t _out_m = {0}; (void)_out_m;
  graphene_quaternion_to_matrix(v1, &_out_m);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_m, sizeof(graphene_matrix_t), "graphene_matrix_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Matrix"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("m"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_to_radians(SEXP s1) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  float _out_rad_x = 0; (void)_out_rad_x;
  float _out_rad_y = 0; (void)_out_rad_y;
  float _out_rad_z = 0; (void)_out_rad_z;
  graphene_quaternion_to_radians(v1, &_out_rad_x, &_out_rad_y, &_out_rad_z);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 3));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 3));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_out_rad_x)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("rad_x"));
  SET_VECTOR_ELT(_ans, 1, Rf_ScalarReal((double)(size_t)(_out_rad_y)));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("rad_y"));
  SET_VECTOR_ELT(_ans, 2, Rf_ScalarReal((double)(size_t)(_out_rad_z)));
  if (VECTOR_ELT(_ans, 2) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 2), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 2, Rf_mkChar("rad_z"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_quaternion_to_vec4(SEXP s1) {
  const graphene_quaternion_t* v1 = (const graphene_quaternion_t*)(get_ptr(s1)); (void)v1;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_quaternion_to_vec4(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_ray_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_ray_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Ray"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Ray"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_equal(SEXP s1, SEXP s2) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_ray_t* v2 = (const graphene_ray_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_ray_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_free(SEXP s1) {
  graphene_ray_t* v1 = (graphene_ray_t*)(get_ptr(s1)); (void)v1;
  graphene_ray_free(v1);
  return R_NilValue;
}


SEXP R_graphene_ray_get_closest_point_to_point(SEXP s1, SEXP s2) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  graphene_point3d_t _out_res = {0}; (void)_out_res;
  graphene_ray_get_closest_point_to_point(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_get_direction(SEXP s1) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_direction = {0}; (void)_out_direction;
  graphene_ray_get_direction(v1, &_out_direction);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_direction, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("direction"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_get_distance_to_plane(SEXP s1, SEXP s2) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_plane_t* v2 = (const graphene_plane_t*)(get_ptr(s2)); (void)v2;
  float _ret = (float)graphene_ray_get_distance_to_plane(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_get_distance_to_point(SEXP s1, SEXP s2) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  float _ret = (float)graphene_ray_get_distance_to_point(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_get_origin(SEXP s1) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  graphene_point3d_t _out_origin = {0}; (void)_out_origin;
  graphene_ray_get_origin(v1, &_out_origin);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_origin, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("origin"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_get_position_at(SEXP s1, SEXP s2) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_point3d_t _out_position = {0}; (void)_out_position;
  graphene_ray_get_position_at(v1, v2, &_out_position);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_position, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("position"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_init(SEXP s1, SEXP s2, SEXP s3) {
  graphene_ray_t* v1 = (graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (s2 != R_NilValue) ? (const graphene_point3d_t*)(get_ptr(s2)) : NULL; (void)v2;
  const graphene_vec3_t* v3 = (s3 != R_NilValue) ? (const graphene_vec3_t*)(get_ptr(s3)) : NULL; (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_ray_init(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_ray_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Ray"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Ray"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_init_from_ray(SEXP s1, SEXP s2) {
  graphene_ray_t* v1 = (graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_ray_t* v2 = (const graphene_ray_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_ray_init_from_ray(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_ray_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Ray"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Ray"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_init_from_vec3(SEXP s1, SEXP s2, SEXP s3) {
  graphene_ray_t* v1 = (graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (s2 != R_NilValue) ? (const graphene_vec3_t*)(get_ptr(s2)) : NULL; (void)v2;
  const graphene_vec3_t* v3 = (s3 != R_NilValue) ? (const graphene_vec3_t*)(get_ptr(s3)) : NULL; (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_ray_init_from_vec3(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_ray_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Ray"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Ray"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_intersect_box(SEXP s1, SEXP s2) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_box_t* v2 = (const graphene_box_t*)(get_ptr(s2)); (void)v2;
  float _out_t_out = 0; (void)_out_t_out;
  graphene_ray_intersection_kind_t _ret = (graphene_ray_intersection_kind_t)graphene_ray_intersect_box(v1, v2, &_out_t_out);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(R_MakeExternalPtr((void*)(_ret), R_NilValue, R_NilValue), "RayIntersectionKind"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("RayIntersectionKind"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, Rf_ScalarReal((double)(size_t)(_out_t_out)));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("t_out"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_intersect_sphere(SEXP s1, SEXP s2) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_sphere_t* v2 = (const graphene_sphere_t*)(get_ptr(s2)); (void)v2;
  float _out_t_out = 0; (void)_out_t_out;
  graphene_ray_intersection_kind_t _ret = (graphene_ray_intersection_kind_t)graphene_ray_intersect_sphere(v1, v2, &_out_t_out);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(R_MakeExternalPtr((void*)(_ret), R_NilValue, R_NilValue), "RayIntersectionKind"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("RayIntersectionKind"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, Rf_ScalarReal((double)(size_t)(_out_t_out)));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("t_out"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_intersect_triangle(SEXP s1, SEXP s2) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_triangle_t* v2 = (const graphene_triangle_t*)(get_ptr(s2)); (void)v2;
  float _out_t_out = 0; (void)_out_t_out;
  graphene_ray_intersection_kind_t _ret = (graphene_ray_intersection_kind_t)graphene_ray_intersect_triangle(v1, v2, &_out_t_out);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(R_MakeExternalPtr((void*)(_ret), R_NilValue, R_NilValue), "RayIntersectionKind"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("RayIntersectionKind"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, Rf_ScalarReal((double)(size_t)(_out_t_out)));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("t_out"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_intersects_box(SEXP s1, SEXP s2) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_box_t* v2 = (const graphene_box_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_ray_intersects_box(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_intersects_sphere(SEXP s1, SEXP s2) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_sphere_t* v2 = (const graphene_sphere_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_ray_intersects_sphere(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_ray_intersects_triangle(SEXP s1, SEXP s2) {
  const graphene_ray_t* v1 = (const graphene_ray_t*)(get_ptr(s1)); (void)v1;
  const graphene_triangle_t* v2 = (const graphene_triangle_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_ray_intersects_triangle(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_contains_point(SEXP s1, SEXP s2) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_rect_contains_point(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_contains_rect(SEXP s1, SEXP s2) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_rect_contains_rect(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_equal(SEXP s1, SEXP s2) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_rect_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_expand(SEXP s1, SEXP s2) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  const graphene_point_t* v2 = (const graphene_point_t*)(get_ptr(s2)); (void)v2;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_rect_expand(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_free(SEXP s1) {
  graphene_rect_t* v1 = (graphene_rect_t*)(get_ptr(s1)); (void)v1;
  graphene_rect_free(v1);
  return R_NilValue;
}


SEXP R_graphene_rect_get_area(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_rect_get_area(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_get_bottom_left(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  graphene_point_t _out_p = {0}; (void)_out_p;
  graphene_rect_get_bottom_left(v1, &_out_p);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_p, sizeof(graphene_point_t), "graphene_point_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("p"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_get_bottom_right(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  graphene_point_t _out_p = {0}; (void)_out_p;
  graphene_rect_get_bottom_right(v1, &_out_p);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_p, sizeof(graphene_point_t), "graphene_point_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("p"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_get_center(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  graphene_point_t _out_p = {0}; (void)_out_p;
  graphene_rect_get_center(v1, &_out_p);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_p, sizeof(graphene_point_t), "graphene_point_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("p"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_get_height(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_rect_get_height(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_get_top_left(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  graphene_point_t _out_p = {0}; (void)_out_p;
  graphene_rect_get_top_left(v1, &_out_p);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_p, sizeof(graphene_point_t), "graphene_point_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("p"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_get_top_right(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  graphene_point_t _out_p = {0}; (void)_out_p;
  graphene_rect_get_top_right(v1, &_out_p);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_p, sizeof(graphene_point_t), "graphene_point_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("p"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_get_vertices(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  graphene_vec2_t _out_vertices = {0}; (void)_out_vertices;
  graphene_rect_get_vertices(v1, &_out_vertices);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_vertices, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("vertices"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_get_width(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_rect_get_width(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_get_x(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_rect_get_x(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_get_y(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_rect_get_y(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_init(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  graphene_rect_t* v1 = (graphene_rect_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gfloat v5 = (gfloat)((gfloat)_unbox_numeric(s5)); (void)v5;
  gconstpointer _ret = (gconstpointer)graphene_rect_init(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_rect_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Rect"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_init_from_rect(SEXP s1, SEXP s2) {
  graphene_rect_t* v1 = (graphene_rect_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_rect_init_from_rect(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_rect_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Rect"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_inset(SEXP s1, SEXP s2, SEXP s3) {
  graphene_rect_t* v1 = (graphene_rect_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_rect_inset(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_rect_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Rect"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_inset_r(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_rect_inset_r(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_interpolate(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  gdouble v3 = (gdouble)((gdouble)_unbox_numeric(s3)); (void)v3;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_rect_interpolate(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_intersection(SEXP s1, SEXP s2) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  _Bool _ret = (_Bool)graphene_rect_intersection(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_normalize(SEXP s1) {
  graphene_rect_t* v1 = (graphene_rect_t*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)graphene_rect_normalize(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_rect_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Rect"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_normalize_r(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_rect_normalize_r(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_offset(SEXP s1, SEXP s2, SEXP s3) {
  graphene_rect_t* v1 = (graphene_rect_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_rect_offset(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_rect_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Rect"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_offset_r(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_rect_offset_r(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_round(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_rect_round(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_round_extents(SEXP s1) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_rect_round_extents(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_round_to_pixel(SEXP s1) {
  graphene_rect_t* v1 = (graphene_rect_t*)(get_ptr(s1)); (void)v1;
  gconstpointer _ret = (gconstpointer)graphene_rect_round_to_pixel(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_rect_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Rect"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_scale(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_rect_scale(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_union(SEXP s1, SEXP s2) {
  const graphene_rect_t* v1 = (const graphene_rect_t*)(get_ptr(s1)); (void)v1;
  const graphene_rect_t* v2 = (const graphene_rect_t*)(get_ptr(s2)); (void)v2;
  graphene_rect_t _out_res = {0}; (void)_out_res;
  graphene_rect_union(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_rect_t), "graphene_rect_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_rect_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_rect_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Rect"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_rect_zero(void) {

  gconstpointer _ret = (gconstpointer)graphene_rect_zero();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_rect_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Rect"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Rect"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_size_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_size_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_size_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Size"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Size"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_size_equal(SEXP s1, SEXP s2) {
  const graphene_size_t* v1 = (const graphene_size_t*)(get_ptr(s1)); (void)v1;
  const graphene_size_t* v2 = (const graphene_size_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_size_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_size_free(SEXP s1) {
  graphene_size_t* v1 = (graphene_size_t*)(get_ptr(s1)); (void)v1;
  graphene_size_free(v1);
  return R_NilValue;
}


SEXP R_graphene_size_init(SEXP s1, SEXP s2, SEXP s3) {
  graphene_size_t* v1 = (graphene_size_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_size_init(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_size_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Size"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Size"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_size_init_from_size(SEXP s1, SEXP s2) {
  graphene_size_t* v1 = (graphene_size_t*)(get_ptr(s1)); (void)v1;
  const graphene_size_t* v2 = (const graphene_size_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_size_init_from_size(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_size_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Size"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Size"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_size_interpolate(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_size_t* v1 = (const graphene_size_t*)(get_ptr(s1)); (void)v1;
  const graphene_size_t* v2 = (const graphene_size_t*)(get_ptr(s2)); (void)v2;
  gdouble v3 = (gdouble)((gdouble)_unbox_numeric(s3)); (void)v3;
  graphene_size_t _out_res = {0}; (void)_out_res;
  graphene_size_interpolate(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_size_t), "graphene_size_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Size"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_size_scale(SEXP s1, SEXP s2) {
  const graphene_size_t* v1 = (const graphene_size_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_size_t _out_res = {0}; (void)_out_res;
  graphene_size_scale(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_size_t), "graphene_size_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Size"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_size_zero(void) {

  gconstpointer _ret = (gconstpointer)graphene_size_zero();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_size_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Size"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Size"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_sphere_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_sphere_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Sphere"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Sphere"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_contains_point(SEXP s1, SEXP s2) {
  const graphene_sphere_t* v1 = (const graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_sphere_contains_point(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_distance(SEXP s1, SEXP s2) {
  const graphene_sphere_t* v1 = (const graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  float _ret = (float)graphene_sphere_distance(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_equal(SEXP s1, SEXP s2) {
  const graphene_sphere_t* v1 = (const graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  const graphene_sphere_t* v2 = (const graphene_sphere_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_sphere_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_free(SEXP s1) {
  graphene_sphere_t* v1 = (graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  graphene_sphere_free(v1);
  return R_NilValue;
}


SEXP R_graphene_sphere_get_bounding_box(SEXP s1) {
  const graphene_sphere_t* v1 = (const graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  graphene_box_t _out_box = {0}; (void)_out_box;
  graphene_sphere_get_bounding_box(v1, &_out_box);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_box, sizeof(graphene_box_t), "graphene_box_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("box"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_get_center(SEXP s1) {
  const graphene_sphere_t* v1 = (const graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  graphene_point3d_t _out_center = {0}; (void)_out_center;
  graphene_sphere_get_center(v1, &_out_center);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_center, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("center"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_get_radius(SEXP s1) {
  const graphene_sphere_t* v1 = (const graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_sphere_get_radius(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_init(SEXP s1, SEXP s2, SEXP s3) {
  graphene_sphere_t* v1 = (graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (s2 != R_NilValue) ? (const graphene_point3d_t*)(get_ptr(s2)) : NULL; (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_sphere_init(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_sphere_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Sphere"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Sphere"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_init_from_points(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_sphere_t* v1 = (graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  guint v2 = (guint)((guint)_unbox_numeric(s2)); (void)v2;
  const graphene_point3d_t* v3 = (const graphene_point3d_t*)(get_ptr(s3)); (void)v3;
  const graphene_point3d_t* v4 = (s4 != R_NilValue) ? (const graphene_point3d_t*)(get_ptr(s4)) : NULL; (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_sphere_init_from_points(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_sphere_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Sphere"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Sphere"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_init_from_vectors(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_sphere_t* v1 = (graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  guint v2 = (guint)((guint)_unbox_numeric(s2)); (void)v2;
  const graphene_vec3_t* v3 = (const graphene_vec3_t*)(get_ptr(s3)); (void)v3;
  const graphene_point3d_t* v4 = (s4 != R_NilValue) ? (const graphene_point3d_t*)(get_ptr(s4)) : NULL; (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_sphere_init_from_vectors(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_sphere_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Sphere"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Sphere"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_is_empty(SEXP s1) {
  const graphene_sphere_t* v1 = (const graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  _Bool _ret = (_Bool)graphene_sphere_is_empty(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_sphere_translate(SEXP s1, SEXP s2) {
  const graphene_sphere_t* v1 = (const graphene_sphere_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  graphene_sphere_t _out_res = {0}; (void)_out_res;
  graphene_sphere_translate(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_sphere_t), "graphene_sphere_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Sphere"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_triangle_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_triangle_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Triangle"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Triangle"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_contains_point(SEXP s1, SEXP s2) {
  const graphene_triangle_t* v1 = (const graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (const graphene_point3d_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_triangle_contains_point(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_equal(SEXP s1, SEXP s2) {
  const graphene_triangle_t* v1 = (const graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  const graphene_triangle_t* v2 = (const graphene_triangle_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_triangle_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_free(SEXP s1) {
  graphene_triangle_t* v1 = (graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  graphene_triangle_free(v1);
  return R_NilValue;
}


SEXP R_graphene_triangle_get_area(SEXP s1) {
  const graphene_triangle_t* v1 = (const graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_triangle_get_area(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_get_barycoords(SEXP s1, SEXP s2) {
  const graphene_triangle_t* v1 = (const graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (s2 != R_NilValue) ? (const graphene_point3d_t*)(get_ptr(s2)) : NULL; (void)v2;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  _Bool _ret = (_Bool)graphene_triangle_get_barycoords(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_get_bounding_box(SEXP s1) {
  const graphene_triangle_t* v1 = (const graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  graphene_box_t _out_res = {0}; (void)_out_res;
  graphene_triangle_get_bounding_box(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_box_t), "graphene_box_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Box"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_get_midpoint(SEXP s1) {
  const graphene_triangle_t* v1 = (const graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  graphene_point3d_t _out_res = {0}; (void)_out_res;
  graphene_triangle_get_midpoint(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_get_normal(SEXP s1) {
  const graphene_triangle_t* v1 = (const graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_triangle_get_normal(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_get_plane(SEXP s1) {
  const graphene_triangle_t* v1 = (const graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  graphene_plane_t _out_res = {0}; (void)_out_res;
  graphene_triangle_get_plane(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_plane_t), "graphene_plane_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Plane"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_get_points(SEXP s1) {
  const graphene_triangle_t* v1 = (const graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  graphene_point3d_t _out_a = {0}; (void)_out_a;
  graphene_point3d_t _out_b = {0}; (void)_out_b;
  graphene_point3d_t _out_c = {0}; (void)_out_c;
  graphene_triangle_get_points(v1, &_out_a, &_out_b, &_out_c);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 3));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 3));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_a, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("a"));
  SET_VECTOR_ELT(_ans, 1, make_boxed_struct(&_out_b, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("b"));
  SET_VECTOR_ELT(_ans, 2, make_boxed_struct(&_out_c, sizeof(graphene_point3d_t), "graphene_point3d_t"));
  if (VECTOR_ELT(_ans, 2) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 2), Rf_install("glib_type"), Rf_mkString("Point3D"));
  }
  SET_STRING_ELT(_ans_names, 2, Rf_mkChar("c"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_get_uv(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  const graphene_triangle_t* v1 = (const graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (s2 != R_NilValue) ? (const graphene_point3d_t*)(get_ptr(s2)) : NULL; (void)v2;
  const graphene_vec2_t* v3 = (const graphene_vec2_t*)(get_ptr(s3)); (void)v3;
  const graphene_vec2_t* v4 = (const graphene_vec2_t*)(get_ptr(s4)); (void)v4;
  const graphene_vec2_t* v5 = (const graphene_vec2_t*)(get_ptr(s5)); (void)v5;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  _Bool _ret = (_Bool)graphene_triangle_get_uv(v1, v2, v3, v4, v5, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 2));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  SET_VECTOR_ELT(_ans, 1, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_get_vertices(SEXP s1) {
  const graphene_triangle_t* v1 = (const graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_a = {0}; (void)_out_a;
  graphene_vec3_t _out_b = {0}; (void)_out_b;
  graphene_vec3_t _out_c = {0}; (void)_out_c;
  graphene_triangle_get_vertices(v1, &_out_a, &_out_b, &_out_c);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 3));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 3));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_a, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("a"));
  SET_VECTOR_ELT(_ans, 1, make_boxed_struct(&_out_b, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 1) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 1), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 1, Rf_mkChar("b"));
  SET_VECTOR_ELT(_ans, 2, make_boxed_struct(&_out_c, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 2) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 2), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 2, Rf_mkChar("c"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_init_from_float(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_triangle_t* v1 = (graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  const float* v2 = (const float*)(get_ptr(s2)); (void)v2;
  const float* v3 = (const float*)(get_ptr(s3)); (void)v3;
  const float* v4 = (const float*)(get_ptr(s4)); (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_triangle_init_from_float(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_triangle_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Triangle"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Triangle"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_init_from_point3d(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_triangle_t* v1 = (graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  const graphene_point3d_t* v2 = (s2 != R_NilValue) ? (const graphene_point3d_t*)(get_ptr(s2)) : NULL; (void)v2;
  const graphene_point3d_t* v3 = (s3 != R_NilValue) ? (const graphene_point3d_t*)(get_ptr(s3)) : NULL; (void)v3;
  const graphene_point3d_t* v4 = (s4 != R_NilValue) ? (const graphene_point3d_t*)(get_ptr(s4)) : NULL; (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_triangle_init_from_point3d(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_triangle_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Triangle"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Triangle"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_triangle_init_from_vec3(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_triangle_t* v1 = (graphene_triangle_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (s2 != R_NilValue) ? (const graphene_vec3_t*)(get_ptr(s2)) : NULL; (void)v2;
  const graphene_vec3_t* v3 = (s3 != R_NilValue) ? (const graphene_vec3_t*)(get_ptr(s3)) : NULL; (void)v3;
  const graphene_vec3_t* v4 = (s4 != R_NilValue) ? (const graphene_vec3_t*)(get_ptr(s4)) : NULL; (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_triangle_init_from_vec3(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_triangle_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Triangle"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Triangle"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec2_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec2_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec2"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_add(SEXP s1, SEXP s2) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec2_add(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_divide(SEXP s1, SEXP s2) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec2_divide(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_dot(SEXP s1, SEXP s2) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  float _ret = (float)graphene_vec2_dot(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_equal(SEXP s1, SEXP s2) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_vec2_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_free(SEXP s1) {
  graphene_vec2_t* v1 = (graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  graphene_vec2_free(v1);
  return R_NilValue;
}


SEXP R_graphene_vec2_get_x(SEXP s1) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec2_get_x(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_get_y(SEXP s1) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec2_get_y(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_init(SEXP s1, SEXP s2, SEXP s3) {
  graphene_vec2_t* v1 = (graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_vec2_init(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec2_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec2"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_init_from_float(SEXP s1, SEXP s2) {
  graphene_vec2_t* v1 = (graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const float* v2 = (const float*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_vec2_init_from_float(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec2_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec2"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_init_from_vec2(SEXP s1, SEXP s2) {
  graphene_vec2_t* v1 = (graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_vec2_init_from_vec2(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec2_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec2"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_interpolate(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  gdouble v3 = (gdouble)((gdouble)_unbox_numeric(s3)); (void)v3;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec2_interpolate(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_length(SEXP s1) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec2_length(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_max(SEXP s1, SEXP s2) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec2_max(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_min(SEXP s1, SEXP s2) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec2_min(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_multiply(SEXP s1, SEXP s2) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec2_multiply(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_near(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  _Bool _ret = (_Bool)graphene_vec2_near(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_negate(SEXP s1) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec2_negate(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_normalize(SEXP s1) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec2_normalize(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_scale(SEXP s1, SEXP s2) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec2_scale(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_subtract(SEXP s1, SEXP s2) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec2_subtract(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_to_float(SEXP s1) {
  const graphene_vec2_t* v1 = (const graphene_vec2_t*)(get_ptr(s1)); (void)v1;
  float _out_dest = 0; (void)_out_dest;
  graphene_vec2_to_float(v1, &_out_dest);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_out_dest)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("dest"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_one(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec2_one();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec2_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec2"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_x_axis(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec2_x_axis();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec2_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec2"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_y_axis(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec2_y_axis();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec2_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec2"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec2_zero(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec2_zero();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec2_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec2"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec3_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec3_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec3"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_add(SEXP s1, SEXP s2) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_add(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_cross(SEXP s1, SEXP s2) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_cross(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_divide(SEXP s1, SEXP s2) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_divide(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_dot(SEXP s1, SEXP s2) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  float _ret = (float)graphene_vec3_dot(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_equal(SEXP s1, SEXP s2) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_vec3_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_free(SEXP s1) {
  graphene_vec3_t* v1 = (graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_free(v1);
  return R_NilValue;
}


SEXP R_graphene_vec3_get_x(SEXP s1) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec3_get_x(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_get_xy(SEXP s1) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec3_get_xy(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_get_xy0(SEXP s1) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_get_xy0(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_get_xyz0(SEXP s1) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec3_get_xyz0(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_get_xyz1(SEXP s1) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec3_get_xyz1(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_get_xyzw(SEXP s1, SEXP s2) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec3_get_xyzw(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_get_y(SEXP s1) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec3_get_y(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_get_z(SEXP s1) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec3_get_z(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_init(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_vec3_t* v1 = (graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_vec3_init(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec3_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec3"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_init_from_float(SEXP s1, SEXP s2) {
  graphene_vec3_t* v1 = (graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const float* v2 = (const float*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_vec3_init_from_float(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec3_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec3"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_init_from_vec3(SEXP s1, SEXP s2) {
  graphene_vec3_t* v1 = (graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_vec3_init_from_vec3(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec3_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec3"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_interpolate(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  gdouble v3 = (gdouble)((gdouble)_unbox_numeric(s3)); (void)v3;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_interpolate(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_length(SEXP s1) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec3_length(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_max(SEXP s1, SEXP s2) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_max(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_min(SEXP s1, SEXP s2) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_min(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_multiply(SEXP s1, SEXP s2) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_multiply(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_near(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  _Bool _ret = (_Bool)graphene_vec3_near(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_negate(SEXP s1) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_negate(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_normalize(SEXP s1) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_normalize(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_scale(SEXP s1, SEXP s2) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_scale(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_subtract(SEXP s1, SEXP s2) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec3_subtract(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_to_float(SEXP s1) {
  const graphene_vec3_t* v1 = (const graphene_vec3_t*)(get_ptr(s1)); (void)v1;
  float _out_dest = 0; (void)_out_dest;
  graphene_vec3_to_float(v1, &_out_dest);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_out_dest)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("dest"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_one(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec3_one();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec3_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec3"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_x_axis(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec3_x_axis();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec3_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec3"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_y_axis(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec3_y_axis();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec3_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec3"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_z_axis(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec3_z_axis();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec3_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec3"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec3_zero(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec3_zero();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec3_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec3"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_alloc(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec4_alloc();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_add(SEXP s1, SEXP s2) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec4_add(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_divide(SEXP s1, SEXP s2) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec4_divide(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_dot(SEXP s1, SEXP s2) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  float _ret = (float)graphene_vec4_dot(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_equal(SEXP s1, SEXP s2) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  _Bool _ret = (_Bool)graphene_vec4_equal(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_free(SEXP s1) {
  graphene_vec4_t* v1 = (graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  graphene_vec4_free(v1);
  return R_NilValue;
}


SEXP R_graphene_vec4_get_w(SEXP s1) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec4_get_w(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_get_x(SEXP s1) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec4_get_x(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_get_xy(SEXP s1) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  graphene_vec2_t _out_res = {0}; (void)_out_res;
  graphene_vec4_get_xy(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec2_t), "graphene_vec2_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec2"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_get_xyz(SEXP s1) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  graphene_vec3_t _out_res = {0}; (void)_out_res;
  graphene_vec4_get_xyz(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec3_t), "graphene_vec3_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec3"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_get_y(SEXP s1) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec4_get_y(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_get_z(SEXP s1) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec4_get_z(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_init(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5) {
  graphene_vec4_t* v1 = (graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gfloat v5 = (gfloat)((gfloat)_unbox_numeric(s5)); (void)v5;
  gconstpointer _ret = (gconstpointer)graphene_vec4_init(v1, v2, v3, v4, v5);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_init_from_float(SEXP s1, SEXP s2) {
  graphene_vec4_t* v1 = (graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const float* v2 = (const float*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_vec4_init_from_float(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_init_from_vec2(SEXP s1, SEXP s2, SEXP s3, SEXP s4) {
  graphene_vec4_t* v1 = (graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec2_t* v2 = (const graphene_vec2_t*)(get_ptr(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gfloat v4 = (gfloat)((gfloat)_unbox_numeric(s4)); (void)v4;
  gconstpointer _ret = (gconstpointer)graphene_vec4_init_from_vec2(v1, v2, v3, v4);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_init_from_vec3(SEXP s1, SEXP s2, SEXP s3) {
  graphene_vec4_t* v1 = (graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec3_t* v2 = (const graphene_vec3_t*)(get_ptr(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  gconstpointer _ret = (gconstpointer)graphene_vec4_init_from_vec3(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_init_from_vec4(SEXP s1, SEXP s2) {
  graphene_vec4_t* v1 = (graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  gconstpointer _ret = (gconstpointer)graphene_vec4_init_from_vec4(v1, v2);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_interpolate(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  gdouble v3 = (gdouble)((gdouble)_unbox_numeric(s3)); (void)v3;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec4_interpolate(v1, v2, v3, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_length(SEXP s1) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  float _ret = (float)graphene_vec4_length(v1);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_ret)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_max(SEXP s1, SEXP s2) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec4_max(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_min(SEXP s1, SEXP s2) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec4_min(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_multiply(SEXP s1, SEXP s2) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec4_multiply(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_near(SEXP s1, SEXP s2, SEXP s3) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  gfloat v3 = (gfloat)((gfloat)_unbox_numeric(s3)); (void)v3;
  _Bool _ret = (_Bool)graphene_vec4_near(v1, v2, v3);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, tag_pointer(Rf_ScalarLogical((int)(size_t)(_ret)), "gboolean"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gboolean"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_negate(SEXP s1) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec4_negate(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_normalize(SEXP s1) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec4_normalize(v1, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_scale(SEXP s1, SEXP s2) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  gfloat v2 = (gfloat)((gfloat)_unbox_numeric(s2)); (void)v2;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec4_scale(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_subtract(SEXP s1, SEXP s2) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  const graphene_vec4_t* v2 = (const graphene_vec4_t*)(get_ptr(s2)); (void)v2;
  graphene_vec4_t _out_res = {0}; (void)_out_res;
  graphene_vec4_subtract(v1, v2, &_out_res);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, make_boxed_struct(&_out_res, sizeof(graphene_vec4_t), "graphene_vec4_t"));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("res"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_to_float(SEXP s1) {
  const graphene_vec4_t* v1 = (const graphene_vec4_t*)(get_ptr(s1)); (void)v1;
  float _out_dest = 0; (void)_out_dest;
  graphene_vec4_to_float(v1, &_out_dest);
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, Rf_ScalarReal((double)(size_t)(_out_dest)));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("gfloat"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("dest"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_one(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec4_one();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_w_axis(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec4_w_axis();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_x_axis(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec4_x_axis();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_y_axis(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec4_y_axis();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_z_axis(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec4_z_axis();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}


SEXP R_graphene_vec4_zero(void) {

  gconstpointer _ret = (gconstpointer)graphene_vec4_zero();
  SEXP _ans = PROTECT(Rf_allocVector(VECSXP, 1));
  SEXP _ans_names = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_VECTOR_ELT(_ans, 0, (_ret == NULL) ? R_NilValue : R_MakeExternalPtr((void*)_ret, Rf_mkChar("graphene_vec4_t"), R_NilValue));
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    SEXP _cls0 = PROTECT(Rf_allocVector(STRSXP, 2));
    SET_STRING_ELT(_cls0, 0, Rf_mkChar("Vec4"));
    SET_STRING_ELT(_cls0, 1, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(VECTOR_ELT(_ans, 0), R_ClassSymbol, _cls0);
    UNPROTECT(1);
  }
  if (VECTOR_ELT(_ans, 0) != R_NilValue) {
    Rf_setAttrib(VECTOR_ELT(_ans, 0), Rf_install("glib_type"), Rf_mkString("Vec4"));
  }
  SET_STRING_ELT(_ans_names, 0, Rf_mkChar("result"));
  Rf_setAttrib(_ans, R_NamesSymbol, _ans_names);
  UNPROTECT(2);
  return _ans;
}

