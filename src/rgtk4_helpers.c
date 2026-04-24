// src/rgtk4_helpers.c - Custom helper functions for Rgtk4
#include <R.h>
#include <Rinternals.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

// ============================================================================
// GObject Reference Counting
// ============================================================================

// Finalizer for GObject external pointers
static void gobject_finalizer(SEXP ext_ptr) {
  GObject *obj = R_ExternalPtrAddr(ext_ptr);
  if (obj && G_IS_OBJECT(obj)) {
    g_object_unref(obj);
    R_ClearExternalPtr(ext_ptr);
  }
}

// Helper to create external pointer with finalizer
SEXP make_gobject_ptr(gpointer obj) {
  if (!obj) return R_NilValue;

  // g_object_ref_sink if it's a floating reference
  if (G_IS_OBJECT(obj) && g_object_is_floating(obj)) {
    g_object_ref_sink(obj);
  } else if (G_IS_OBJECT(obj)) {
    g_object_ref(obj);
  }

  SEXP ptr = PROTECT(R_MakeExternalPtr(obj, R_NilValue, R_NilValue));
  R_RegisterCFinalizerEx(ptr, gobject_finalizer, TRUE);
  UNPROTECT(1);
  return ptr;
}

// ============================================================================
// Boxed Structs (GtkTextIter, etc.)
// ============================================================================

// Finalizer for heap-allocated structs
static void boxed_struct_finalizer(SEXP ext_ptr) {
  void *ptr = R_ExternalPtrAddr(ext_ptr);
  if (ptr) {
    g_free(ptr); // Structs are allocated with g_malloc/g_new
    R_ClearExternalPtr(ext_ptr);
  }
}

// Helper to copy a stack struct to the heap and wrap it for R
SEXP make_boxed_struct(const void *src, size_t size) {
  if (!src) return R_NilValue;

  // Allocate persistent memory on the heap
  void *dest = g_malloc0(size);
  memcpy(dest, src, size);

  SEXP ptr = PROTECT(R_MakeExternalPtr(dest, R_NilValue, R_NilValue));
  R_RegisterCFinalizerEx(ptr, boxed_struct_finalizer, TRUE);
  UNPROTECT(1);
  return ptr;
}

// ============================================================================
// Keyboard Shortcuts
// ============================================================================

// Keyboard shortcut callback
static gboolean key_pressed_cb(GtkEventControllerKey *controller,
                               guint keyval,
                               guint keycode,
                               GdkModifierType state,
                               gpointer user_data) {
  GtkWindow *window = GTK_WINDOW(user_data);

  // Check for W key (handles both lowercase and uppercase)
  gboolean is_w = (keyval == GDK_KEY_w || keyval == GDK_KEY_W);

  if (!is_w) return FALSE;

  // Platform-specific modifier check
#ifdef __APPLE__
  // macOS: Cmd+W (Super/Meta key)
  gboolean has_modifier = (state & GDK_META_MASK) || (state & GDK_SUPER_MASK);
#else
  // Linux/Windows: Ctrl+W
  gboolean has_modifier = (state & GDK_CONTROL_MASK);
#endif

  if (has_modifier) {
    gtk_window_close(window);
    return TRUE;
  }

  return FALSE;
}

// Add close shortcut to window
SEXP R_gtk_window_add_close_shortcut(SEXP s_window) {
  GtkWindow *window = (GtkWindow *)R_ExternalPtrAddr(s_window);
  if (!window || !GTK_IS_WINDOW(window)) {
    Rf_error("Invalid GtkWindow pointer");
  }

  GtkEventController *controller = gtk_event_controller_key_new();
  g_signal_connect(controller, "key-pressed", G_CALLBACK(key_pressed_cb), window);
  gtk_widget_add_controller(GTK_WIDGET(window), controller);

  return R_NilValue;
}

// ============================================================================
// UI State Extraction
// ============================================================================

// Extract UI state from widgets - returns a named list with widget states
SEXP R_gtk_get_ui_state(SEXP s_widgets) {
  // Handle both single widget and list of widgets
  int is_list = TYPEOF(s_widgets) == VECSXP;
  int n = is_list ? length(s_widgets) : 1;

  SEXP result = PROTECT(allocVector(VECSXP, n));

  for (int i = 0; i < n; i++) {
    SEXP widget_ptr = is_list ? VECTOR_ELT(s_widgets, i) : s_widgets;

    // Check if it's an external pointer
    if (TYPEOF(widget_ptr) != EXTPTRSXP) {
      SET_VECTOR_ELT(result, i, R_NilValue);
      continue;
    }

    GObject *obj = G_OBJECT(R_ExternalPtrAddr(widget_ptr));

    if (!obj) {
      SET_VECTOR_ELT(result, i, R_NilValue);
      continue;
    }

    // Create a list for this widget's state
    SEXP widget_state;
    SEXP widget_state_names;

    if (GTK_IS_ENTRY(obj)) {
      // Entry: return text
      widget_state = PROTECT(allocVector(VECSXP, 1));
      widget_state_names = PROTECT(allocVector(STRSXP, 1));

      GtkEntryBuffer *buf = gtk_entry_get_buffer(GTK_ENTRY(obj));
      const char *text = gtk_entry_buffer_get_text(buf);
      SET_VECTOR_ELT(widget_state, 0, mkString(text));
      SET_STRING_ELT(widget_state_names, 0, mkChar("text"));

    } else if (GTK_IS_TEXT_VIEW(obj)) {
      // TextView: return text
      widget_state = PROTECT(allocVector(VECSXP, 1));
      widget_state_names = PROTECT(allocVector(STRSXP, 1));

      GtkTextBuffer *buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(obj));
      GtkTextIter start, end;
      gtk_text_buffer_get_bounds(buf, &start, &end);
      char *text = gtk_text_buffer_get_text(buf, &start, &end, FALSE);
      SET_VECTOR_ELT(widget_state, 0, mkString(text ? text : ""));
      SET_STRING_ELT(widget_state_names, 0, mkChar("text"));
      g_free(text);

    } else if (GTK_IS_SPIN_BUTTON(obj)) {
      // SpinButton: return value
      widget_state = PROTECT(allocVector(VECSXP, 1));
      widget_state_names = PROTECT(allocVector(STRSXP, 1));

      double val = gtk_spin_button_get_value(GTK_SPIN_BUTTON(obj));
      SET_VECTOR_ELT(widget_state, 0, ScalarReal(val));
      SET_STRING_ELT(widget_state_names, 0, mkChar("value"));

    } else if (GTK_IS_DROP_DOWN(obj)) {
      // DropDown: return selected index and string
      widget_state = PROTECT(allocVector(VECSXP, 2));
      widget_state_names = PROTECT(allocVector(STRSXP, 2));

      guint idx = gtk_drop_down_get_selected(GTK_DROP_DOWN(obj));
      GListModel *m = gtk_drop_down_get_model(GTK_DROP_DOWN(obj));
      const char *str = gtk_string_list_get_string(GTK_STRING_LIST(m), idx);

      SET_VECTOR_ELT(widget_state, 0, ScalarInteger(idx));
      SET_VECTOR_ELT(widget_state, 1, mkString(str ? str : ""));
      SET_STRING_ELT(widget_state_names, 0, mkChar("selected"));
      SET_STRING_ELT(widget_state_names, 1, mkChar("text"));

    } else if (GTK_IS_CHECK_BUTTON(obj)) {
      // CheckButton: return active state
      widget_state = PROTECT(allocVector(VECSXP, 1));
      widget_state_names = PROTECT(allocVector(STRSXP, 1));

      gboolean active = gtk_check_button_get_active(GTK_CHECK_BUTTON(obj));
      SET_VECTOR_ELT(widget_state, 0, ScalarLogical(active));
      SET_STRING_ELT(widget_state_names, 0, mkChar("active"));

    } else {
      // Unknown widget type - return empty list
      widget_state = PROTECT(allocVector(VECSXP, 0));
      widget_state_names = PROTECT(allocVector(STRSXP, 0));
    }

    setAttrib(widget_state, R_NamesSymbol, widget_state_names);
    SET_VECTOR_ELT(result, i, widget_state);
    UNPROTECT(2);
  }

  // Set names if we had a named list
  if (is_list) {
    SEXP input_names = getAttrib(s_widgets, R_NamesSymbol);
    if (!isNull(input_names)) {
      setAttrib(result, R_NamesSymbol, input_names);
    }
    UNPROTECT(1);
    return result;
  } else {
    // Single widget - return the widget state directly, not wrapped in a list
    SEXP single_result = VECTOR_ELT(result, 0);
    UNPROTECT(1);
    return single_result;
  }
}

// ============================================================================
// GtkStringList Helper
// ============================================================================

// Create GtkStringList from R character vector
SEXP R_gtk_string_list_new_from_vector(SEXP s_strings) {
  if (TYPEOF(s_strings) != STRSXP) {
    Rf_error("Expected character vector");
    return R_NilValue;
  }

  int n = LENGTH(s_strings);
  if (n == 0) {
    Rf_error("Character vector must have at least one element");
    return R_NilValue;
  }

  // Create NULL-terminated array of strings
  const char **strings = (const char **)malloc((n + 1) * sizeof(char *));
  if (!strings) {
    Rf_error("Memory allocation failed");
    return R_NilValue;
  }

  for (int i = 0; i < n; i++) {
    strings[i] = CHAR(STRING_ELT(s_strings, i));
  }
  strings[n] = NULL;

  // Create GtkStringList
  GtkStringList *list = gtk_string_list_new(strings);

  free(strings);

  // Use our helper to create external pointer with proper refcounting
  return make_gobject_ptr(list);
}

SEXP R_gtk_text_buffer_create_tag_simple(SEXP s_buffer, SEXP s_tag_name) {
  GtkTextBuffer* buffer = (GtkTextBuffer*)R_ExternalPtrAddr(s_buffer);
  const char* tag_name = (s_tag_name == R_NilValue) ? NULL : CHAR(STRING_ELT(s_tag_name, 0));
  GtkTextTag* tag = gtk_text_buffer_create_tag(buffer, tag_name, NULL);
  return R_MakeExternalPtr((void*)tag, R_NilValue, R_NilValue);
}

SEXP R_g_object_set_string(SEXP s1, SEXP s2, SEXP s3) {
  GObject* v1 = (GObject*)(R_ExternalPtrAddr(s1));
  const char* property_name = (const char*)(CHAR(STRING_ELT(s2,0)));
  const char* value = (const char*)(CHAR(STRING_ELT(s3,0)));

  // Use g_object_set which handles the string-to-GValue conversion for you
  g_object_set(v1, property_name, value, NULL);

  return R_NilValue;
}


// ============================================================================
// GtkStringList Helper
// ============================================================================

// Manual wrapper to avoid variadic issues
SEXP R_gtk_message_dialog_new_safe(SEXP parent_ptr, SEXP flags, SEXP type, SEXP buttons, SEXP message) {
  GtkWindow *parent = (parent_ptr == R_NilValue) ? NULL : (GtkWindow*)R_ExternalPtrAddr(parent_ptr);
  const char *msg = CHAR(STRING_ELT(message, 0));

  // We pass "%s" as the format to ensure 'msg' is treated as literal text
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  GtkWidget *dialog = gtk_message_dialog_new(parent,
                                             asInteger(flags),
                                             asInteger(type),
                                             asInteger(buttons),
                                             "%s", msg);
#pragma GCC diagnostic pop

  // Use your existing logic to wrap the GObject
  return make_gobject_ptr(dialog);
}
