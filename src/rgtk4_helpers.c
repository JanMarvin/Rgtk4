// src/rgtk4_helpers.c - Custom helper functions for Rgtk4
#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <string.h>

static inline void* get_ptr_internal(SEXP s, const char* func) {
  if (s == R_NilValue) return NULL;
  if (TYPEOF(s) != EXTPTRSXP) {
    Rf_error("%s: expected external pointer, got %s", func, Rf_type2char(TYPEOF(s)));
  }
  return R_ExternalPtrAddr(s);
}

#define get_ptr(s) get_ptr_internal(s, __func__)

static const char *string_or_null(SEXP s) {
  if (s == R_NilValue) return NULL;
  if (TYPEOF(s) != STRSXP || Rf_length(s) < 1) return NULL;
  SEXP elt = STRING_ELT(s, 0);
  if (elt == NA_STRING) return NULL;
  return CHAR(elt);
}

// Forward decl — used by both gobject_finalizer (R-side GC) and as the
// weak-notify target (GLib-side finalize).
static void gobject_weak_notify(gpointer data, GObject *where_the_obj_was);

// Finalizer for R-managed GObject extptrs. Runs when R GCs the SEXP.
// Detaches our weak-ref (so it doesn't fire on already-dead R memory)
// and drops our refcount on the GObject.
static void gobject_finalizer(SEXP ext_ptr) {
  GObject *obj = R_ExternalPtrAddr(ext_ptr);
  if (obj && G_IS_OBJECT(obj)) {
    g_object_weak_unref(obj, gobject_weak_notify, ext_ptr);
    g_object_unref(obj);
  }
  R_ClearExternalPtr(ext_ptr);
}

// Weak-ref notify: GLib invokes this when the GObject is finalized
// before R's finalizer runs. Clears the extptr address so subsequent
// access via RGTK4_GET_PTR fails with "may have been destroyed" instead
// of dereferencing freed memory.
static void gobject_weak_notify(gpointer data, GObject *where_the_obj_was) {
  (void)where_the_obj_was;
  SEXP ext_ptr = (SEXP)data;
  R_SetExternalPtrAddr(ext_ptr, NULL);
  R_ReleaseObject(ext_ptr);
}

// Silent log handler — discards messages.
static void _silent_log_handler(const gchar *log_domain, GLogLevelFlags level,
                                const gchar *message, gpointer user_data) {
  (void)log_domain; (void)level; (void)message; (void)user_data;
}

SEXP make_gobject_ptr(gpointer obj) {
  if (!obj) return R_NilValue;

  // G_IS_OBJECT logs a GLib-GObject CRITICAL when called on a pointer
  // that is not a valid GTypeInstance. The result is still FALSE
  // (correct), but the log noise is unhelpful. Suppress for the check.
  guint h = g_log_set_handler("GLib-GObject",
                              (GLogLevelFlags)(G_LOG_LEVEL_CRITICAL | G_LOG_LEVEL_WARNING |
                                G_LOG_FLAG_FATAL | G_LOG_FLAG_RECURSION),
                                _silent_log_handler, NULL);

  gboolean is_obj = FALSE;
  if ((uintptr_t)obj >= 0x10000) {
    GTypeInstance *inst = (GTypeInstance *)obj;
    GTypeClass *klass = inst->g_class;
    if (klass != NULL && (uintptr_t)klass >= 0x10000) {
      is_obj = G_IS_OBJECT(obj);
    }
  }

  g_log_remove_handler("GLib-GObject", h);

  if (is_obj) {
    if (g_object_is_floating(obj)) {
      g_object_ref_sink(obj);
    } else {
      g_object_ref(obj);
    }
    SEXP ptr = PROTECT(R_MakeExternalPtr(obj, R_NilValue, R_NilValue));
    R_RegisterCFinalizerEx(ptr, gobject_finalizer, TRUE);

    // Weak-notify clears the extptr address when GLib finalizes the
    // GObject. R_PreserveObject keeps the SEXP alive until the notify
    // (or our finalizer) calls R_ReleaseObject.
    R_PreserveObject(ptr);
    g_object_weak_ref(obj, gobject_weak_notify, ptr);

    SEXP classes = PROTECT(Rf_allocVector(STRSXP, 3));
    SET_STRING_ELT(classes, 0, Rf_mkChar(G_OBJECT_TYPE_NAME(obj)));
    SET_STRING_ELT(classes, 1, Rf_mkChar("GObject"));
    SET_STRING_ELT(classes, 2, Rf_mkChar("RGtkObject"));
    Rf_setAttrib(ptr, R_ClassSymbol, classes);
    UNPROTECT(2);
    return ptr;
  }

  return R_MakeExternalPtr(obj, R_NilValue, R_NilValue);
}

static void boxed_struct_finalizer(SEXP ext_ptr) {
  void *ptr = R_ExternalPtrAddr(ext_ptr);
  if (ptr) {
    g_free(ptr);
    R_ClearExternalPtr(ext_ptr);
  }
}

SEXP make_boxed_struct(const void *src, size_t size) {
  if (!src) return R_NilValue;

  void *dest = g_malloc0(size);
  memcpy(dest, src, size);

  SEXP ptr = PROTECT(R_MakeExternalPtr(dest, R_NilValue, R_NilValue));
  R_RegisterCFinalizerEx(ptr, boxed_struct_finalizer, TRUE);
  UNPROTECT(1);
  return ptr;
}

SEXP R_extptr_address(SEXP s) {
  if (TYPEOF(s) != EXTPTRSXP) {
    return R_NilValue;
  }
  void *ptr = R_ExternalPtrAddr(s);
  char buf[32];
  snprintf(buf, sizeof(buf), "%p", ptr);
  return Rf_mkString(buf);
}

static gboolean key_pressed_cb(GtkEventControllerKey *controller,
                               guint keyval,
                               guint keycode,
                               GdkModifierType state,
                               gpointer user_data) {
  (void)controller;
  (void)keycode;
  GtkWindow *window = GTK_WINDOW(user_data);

  gboolean is_w = (keyval == GDK_KEY_w || keyval == GDK_KEY_W);
  if (!is_w) return FALSE;

#ifdef __APPLE__
  gboolean has_modifier = (state & GDK_META_MASK) || (state & GDK_SUPER_MASK);
#else
  gboolean has_modifier = (state & GDK_CONTROL_MASK) != 0;
#endif

  if (has_modifier) {
    gtk_window_close(window);
    return TRUE;
  }
  return FALSE;
}

SEXP R_gtk_window_add_close_shortcut(SEXP s_window) {
  GtkWindow *window = (GtkWindow*)get_ptr(s_window);
  if (!window) {
    Rf_error("Invalid GtkWindow pointer");
  }

  GtkEventController *controller = gtk_event_controller_key_new();
  g_signal_connect(controller, "key-pressed", G_CALLBACK(key_pressed_cb), window);
  gtk_widget_add_controller(GTK_WIDGET(window), controller);

  return R_NilValue;
}

static SEXP get_widget_state(GObject *obj) {
  SEXP state, names;

  if (GTK_IS_ENTRY(obj)) {
    state = PROTECT(Rf_allocVector(VECSXP, 1));
    names = PROTECT(Rf_allocVector(STRSXP, 1));
    GtkEntryBuffer *buf = gtk_entry_get_buffer(GTK_ENTRY(obj));
    const char *text = gtk_entry_buffer_get_text(buf);
    SET_VECTOR_ELT(state, 0, Rf_mkString(text ? text : ""));
    SET_STRING_ELT(names, 0, Rf_mkChar("text"));

  } else if (GTK_IS_TEXT_VIEW(obj)) {
    state = PROTECT(Rf_allocVector(VECSXP, 1));
    names = PROTECT(Rf_allocVector(STRSXP, 1));
    GtkTextBuffer *buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(obj));
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buf, &start, &end);
    char *text = gtk_text_buffer_get_text(buf, &start, &end, FALSE);
    SET_VECTOR_ELT(state, 0, Rf_mkString(text ? text : ""));
    SET_STRING_ELT(names, 0, Rf_mkChar("text"));
    g_free(text);

  } else if (GTK_IS_SPIN_BUTTON(obj)) {
    state = PROTECT(Rf_allocVector(VECSXP, 1));
    names = PROTECT(Rf_allocVector(STRSXP, 1));
    double val = gtk_spin_button_get_value(GTK_SPIN_BUTTON(obj));
    SET_VECTOR_ELT(state, 0, Rf_ScalarReal(val));
    SET_STRING_ELT(names, 0, Rf_mkChar("value"));

  } else if (GTK_IS_DROP_DOWN(obj)) {
    state = PROTECT(Rf_allocVector(VECSXP, 2));
    names = PROTECT(Rf_allocVector(STRSXP, 2));

    guint idx = gtk_drop_down_get_selected(GTK_DROP_DOWN(obj));
    if (idx == GTK_INVALID_LIST_POSITION) {
      SET_VECTOR_ELT(state, 0, Rf_ScalarInteger(NA_INTEGER));
      SET_VECTOR_ELT(state, 1, R_NilValue);
    } else {
      GListModel *m = gtk_drop_down_get_model(GTK_DROP_DOWN(obj));
      const char *str = NULL;
      if (m && GTK_IS_STRING_LIST(m)) {
        str = gtk_string_list_get_string(GTK_STRING_LIST(m), idx);
      }
      SET_VECTOR_ELT(state, 0, Rf_ScalarInteger((int)idx));
      SET_VECTOR_ELT(state, 1, Rf_mkString(str ? str : ""));
    }
    SET_STRING_ELT(names, 0, Rf_mkChar("selected"));
    SET_STRING_ELT(names, 1, Rf_mkChar("text"));

  } else if (GTK_IS_CHECK_BUTTON(obj)) {
    state = PROTECT(Rf_allocVector(VECSXP, 1));
    names = PROTECT(Rf_allocVector(STRSXP, 1));
    gboolean active = gtk_check_button_get_active(GTK_CHECK_BUTTON(obj));
    SET_VECTOR_ELT(state, 0, Rf_ScalarLogical(active));
    SET_STRING_ELT(names, 0, Rf_mkChar("active"));

  } else {
    state = PROTECT(Rf_allocVector(VECSXP, 0));
    names = PROTECT(Rf_allocVector(STRSXP, 0));
  }

  Rf_setAttrib(state, R_NamesSymbol, names);
  UNPROTECT(2);
  return state;
}

SEXP R_gtk_get_ui_state(SEXP s_widgets) {
  int is_list = TYPEOF(s_widgets) == VECSXP;

  if (!is_list) {
    if (s_widgets == R_NilValue || TYPEOF(s_widgets) != EXTPTRSXP) {
      return R_NilValue;
    }
    GObject *obj = (GObject*)get_ptr(s_widgets);
    if (!obj) return R_NilValue;
    return get_widget_state(obj);
  }

  int n = Rf_length(s_widgets);
  SEXP result = PROTECT(Rf_allocVector(VECSXP, n));

  for (int i = 0; i < n; i++) {
    SEXP widget_ptr = VECTOR_ELT(s_widgets, i);
    if (widget_ptr == R_NilValue || TYPEOF(widget_ptr) != EXTPTRSXP) {
      SET_VECTOR_ELT(result, i, R_NilValue);
      continue;
    }
    GObject *obj = (GObject*)get_ptr(widget_ptr);
    if (!obj) {
      SET_VECTOR_ELT(result, i, R_NilValue);
      continue;
    }
    SET_VECTOR_ELT(result, i, get_widget_state(obj));
  }

  SEXP input_names = Rf_getAttrib(s_widgets, R_NamesSymbol);
  if (!Rf_isNull(input_names)) {
    Rf_setAttrib(result, R_NamesSymbol, input_names);
  }

  UNPROTECT(1);
  return result;
}

SEXP R_gtk_string_list_new_from_vector(SEXP s_strings) {
  if (TYPEOF(s_strings) != STRSXP) {
    Rf_error("Expected character vector");
  }

  int n = Rf_length(s_strings);
  if (n == 0) {
    Rf_error("Character vector must have at least one element");
  }

  const char **strings = (const char **)g_malloc(((gsize)n + 1) * sizeof(char *));
  for (int i = 0; i < n; i++) {
    SEXP elt = STRING_ELT(s_strings, i);
    strings[i] = (elt == NA_STRING) ? "" : CHAR(elt);
  }
  strings[n] = NULL;

  GtkStringList *list = gtk_string_list_new(strings);
  g_free(strings);

  return make_gobject_ptr(list);
}

SEXP R_gtk_text_buffer_create_tag_simple(SEXP s_buffer, SEXP s_tag_name) {
  GtkTextBuffer* buffer = (GtkTextBuffer*)get_ptr(s_buffer);
  if (!buffer) {
    Rf_error("Invalid GtkTextBuffer pointer");
  }
  const char* tag_name = string_or_null(s_tag_name);
  GtkTextTag* tag = gtk_text_buffer_create_tag(buffer, tag_name, NULL);
  return R_MakeExternalPtr((void*)tag, R_NilValue, R_NilValue);
}

static const char *get_property_name(SEXP s) {
  if (TYPEOF(s) != STRSXP || Rf_length(s) < 1) {
    Rf_error("property_name must be a character string");
  }
  SEXP elt = STRING_ELT(s, 0);
  if (elt == NA_STRING) {
    Rf_error("property_name must not be NA");
  }
  return CHAR(elt);
}

SEXP R_g_object_set_string(SEXP s1, SEXP s2, SEXP s3) {
  GObject* v1 = (GObject*)get_ptr(s1);
  if (!v1) Rf_error("Invalid GObject pointer");

  const char* property_name = get_property_name(s2);
  const char* value = string_or_null(s3);
  g_object_set(v1, property_name, value, NULL);
  return R_NilValue;
}

SEXP R_g_object_set_boolean(SEXP s1, SEXP s2, SEXP s3) {
  GObject* v1 = (GObject*)get_ptr(s1);
  if (!v1) Rf_error("Invalid GObject pointer");

  const char* property_name = get_property_name(s2);
  int lv = Rf_asLogical(s3);
  if (lv == NA_LOGICAL) Rf_error("value must be TRUE or FALSE");
  gboolean value = (lv == TRUE);
  g_object_set(v1, property_name, value, NULL);
  return R_NilValue;
}

SEXP R_g_object_set_int(SEXP s1, SEXP s2, SEXP s3) {
  GObject* v1 = (GObject*)get_ptr(s1);
  if (!v1) Rf_error("Invalid GObject pointer");

  const char* property_name = get_property_name(s2);
  int value = Rf_asInteger(s3);
  if (value == NA_INTEGER) Rf_error("value must not be NA");
  g_object_set(v1, property_name, value, NULL);
  return R_NilValue;
}

SEXP R_g_object_set_double(SEXP s1, SEXP s2, SEXP s3) {
  GObject* v1 = (GObject*)get_ptr(s1);
  if (!v1) Rf_error("Invalid GObject pointer");

  const char* property_name = get_property_name(s2);
  double value = Rf_asReal(s3);
  if (!R_finite(value)) Rf_error("value must be finite");
  g_object_set(v1, property_name, value, NULL);
  return R_NilValue;
}

SEXP R_g_object_set_enum(SEXP s1, SEXP s2, SEXP s3) {
  GObject* v1 = (GObject*)get_ptr(s1);
  if (!v1) Rf_error("Invalid GObject pointer");

  const char* property_name = get_property_name(s2);
  int value = Rf_asInteger(s3);
  if (value == NA_INTEGER) Rf_error("value must not be NA");

  GObjectClass* klass = G_OBJECT_GET_CLASS(v1);
  GParamSpec* pspec = g_object_class_find_property(klass, property_name);
  if (!pspec)
    Rf_error("object has no property '%s'", property_name);

  GValue gval = G_VALUE_INIT;
  GType ptype = G_PARAM_SPEC_VALUE_TYPE(pspec);
  g_value_init(&gval, ptype);

  GType fundamental = G_TYPE_FUNDAMENTAL(ptype);
  if (fundamental == G_TYPE_INT)
    g_value_set_int(&gval, value);
  else if (fundamental == G_TYPE_UINT)
    g_value_set_uint(&gval, (guint)value);
  else if (fundamental == G_TYPE_LONG)
    g_value_set_long(&gval, (glong)value);
  else if (fundamental == G_TYPE_ULONG)
    g_value_set_ulong(&gval, (gulong)value);
  else if (fundamental == G_TYPE_ENUM)
    g_value_set_enum(&gval, value);
  else if (fundamental == G_TYPE_FLAGS)
    g_value_set_flags(&gval, (guint)value);
  else if (fundamental == G_TYPE_BOOLEAN)
    g_value_set_boolean(&gval, (gboolean)(value != 0));
  else {
    g_value_unset(&gval);
    Rf_error("property '%s' has type '%s' which is not an integer/enum type",
             property_name, g_type_name(ptype));
  }

  g_object_set_property(v1, property_name, &gval);
  g_value_unset(&gval);
  return R_NilValue;
}

SEXP R_gtk_message_dialog_new_safe(SEXP parent_ptr, SEXP flags, SEXP type, SEXP buttons, SEXP message) {
  GtkWindow *parent = NULL;
  if (parent_ptr != R_NilValue) {
    parent = (GtkWindow*)get_ptr(parent_ptr);
  }
  const char *msg = string_or_null(message);
  if (!msg) Rf_error("message must be a character string");

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  GtkWidget *dialog = gtk_message_dialog_new(parent,
                                             (GtkDialogFlags)Rf_asInteger(flags),
                                             (GtkMessageType)Rf_asInteger(type),
                                             (GtkButtonsType)Rf_asInteger(buttons),
                                             "%s", msg);
#pragma GCC diagnostic pop
  return make_gobject_ptr(dialog);
}

SEXP R_raw_to_extptr(SEXP s) {
  if (TYPEOF(s) != RAWSXP) Rf_error("expected raw vector");
  return R_MakeExternalPtr(RAW(s), s, R_NilValue);
}

extern SEXP make_gobject_ptr(gpointer obj);

SEXP R_glist_to_r_list(SEXP s_glist, SEXP s_free_list) {
  GList *list = (GList *)(s_glist == R_NilValue ? NULL : R_ExternalPtrAddr(s_glist));
  int free_list = Rf_asLogical(s_free_list);

  int n = 0;
  for (GList *l = list; l != NULL; l = l->next) n++;

  SEXP result = PROTECT(Rf_allocVector(VECSXP, n));
  int i = 0;
  for (GList *l = list; l != NULL; l = l->next, i++) {
    SET_VECTOR_ELT(result, i, make_gobject_ptr(l->data));
  }

  if (free_list && list)
    g_list_free(list);

  UNPROTECT(1);
  return result;
}

SEXP R_gtk_list_box_get_selected_rows_unpacked(SEXP s1) {
  GtkListBox *box = (GtkListBox *)R_ExternalPtrAddr(s1);
  if (!box) Rf_error("Invalid GtkListBox pointer");
  GList *list = gtk_list_box_get_selected_rows(box);

  int n = 0;
  for (GList *l = list; l != NULL; l = l->next) n++;

  SEXP result = PROTECT(Rf_allocVector(VECSXP, n));
  int i = 0;
  for (GList *l = list; l != NULL; l = l->next, i++) {
    SET_VECTOR_ELT(result, i, make_gobject_ptr(l->data));
  }
  g_list_free(list);

  UNPROTECT(1);
  return result;
}
