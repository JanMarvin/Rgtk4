# R/helpers.R - Helper functions for Rgtk4
# These wrap the C functions from rgtk4_helpers.c, rgtk4_eventloop.c, and rgtk4_signals.c

#' Start the GTK4/R event loop integration
#'
#' On Unix/macOS, integrates GTK event loop with R's input handlers.
#' On Windows, requires the 'later' package for proper event processing.
#'
#' @export
gtkStartEventLoop <- function() {
  result <- .Call('R_gtk_start_event_loop')

  # On Windows, set up periodic event processing
  if (.Platform$OS.type == "windows") {
    if (!exists(".rgtk4_windows_timer", envir = .GlobalEnv)) {
      # Check for later package (required for Windows)
      if (requireNamespace("later", quietly = TRUE)) {
        .GlobalEnv$.rgtk4_windows_timer <- TRUE

        # Set up later loop for continuous event processing (16ms = ~60fps)
        process_events <- function() {
          if (isTRUE(.GlobalEnv$.rgtk4_windows_timer)) {
            tryCatch({
              .Call('R_gtk_main_iteration', PACKAGE = "Rgtk4")
            }, error = function(e) NULL)
            later::later(process_events, delay = 0.016)
          }
        }
        later::later(process_events, delay = 0.016)
      } else {
        warning(
          "The 'later' package is required for GTK on Windows.\n",
          "Install with: install.packages('later')"
        )
      }
    }
  }

  invisible(result)
}

#' Stop the GTK4/R event loop integration
#' @export
gtkStopEventLoop <- function() {
  # Remove Windows event processing
  if (.Platform$OS.type == "windows") {
    if (exists(".rgtk4_windows_timer", envir = .GlobalEnv)) {
      rm(.rgtk4_windows_timer, envir = .GlobalEnv)
    }
  }

  invisible(.Call('R_gtk_stop_event_loop'))
}

#' Force GTK window to foreground (macOS)
#' @export
gtkForceForeground <- function() {
  invisible(.Call('R_gtk_force_foreground'))
}

#' Hide application from dock (macOS)
#' @export
gtkHideFromDock <- function() {
  invisible(.Call('R_gtk_hide_from_dock'))
}

#' Set application icon
#'
#' Sets a custom application icon. On macOS, sets the Dock icon.
#' On Linux, sets the default window icon. Windows support TBD.
#'
#' @param icon_path Path to icon file (.png, .icns, or .ico)
#' @export
gtkSetAppIcon <- function(icon_path) {
  if (!file.exists(icon_path)) {
    stop("Icon file not found: ", icon_path)
  }

  os <- Sys.info()["sysname"]

  if (os == "Darwin") {
    invisible(.Call("R_macos_set_app_icon", normalizePath(icon_path)))
  } else if (os == "Linux") {
    # On Linux, set default window icon from file
    # pixbuf <- gdkPixbufNewFromFile(icon_path)
    # gtkWindowSetDefaultIconList(list(pixbuf))
  } else if (os == "Windows") {
    # Windows: set default icon (GTK4 handles this via window class)
    # pixbuf <- gdkPixbufNewFromFile(icon_path)
    # gtkWindowSetDefaultIconList(list(pixbuf))
  } else {
    warning("gtkSetAppIcon: unsupported platform ", os)
  }

  invisible(NULL)
}

#' Track window for dock icon management (macOS)
#'
#' Automatically shows dock icon when first window appears and hides
#' it when the last window closes. Call this for each window you create.
#'
#' @param window GtkWindow pointer
#' @export
gtkWindowTrack <- function(window) {
  invisible(.Call('R_gtk_window_track', window))
}

#' Create GtkStringList from R character vector
#' @param strings Character vector
#' @return External pointer to GtkStringList
#' @export
gtkStringListFromVector <- function(strings) {
  if (!is.character(strings) || length(strings) == 0) {
    stop('strings must be a non-empty character vector')
  }
  .Call('R_gtk_string_list_new_from_vector', strings)
}

#' Connect an R function to a GObject signal
#'
#' Automatically detects the signal signature and handles callbacks with
#' different numbers of arguments.
#'
#' @param obj External pointer to a GObject
#' @param signal Signal name (character)
#' @param fun R function to invoke on signal. For signals that expect a boolean return
#'   (like "close-request"), your function should return TRUE to stop propagation or
#'   FALSE to allow default behavior.
#' @return handler id (numeric) - invisibly
#' @export
gSignalConnectR <- function(obj, signal, fun) {
  invisible(.Call('R_g_signal_connect_r', obj, signal, fun))
}

#' Add keyboard shortcut to close window
#'
#' Adds Cmd+W (macOS) or Ctrl+W (Windows/Linux) to close the window.
#'
#' @param window External pointer to GtkWindow
#' @export
gtkWindowAddCloseShortcut <- function(window) {
  invisible(.Call('R_gtk_window_add_close_shortcut', window))
}

#' Get UI widget states
#' @param widgets Single widget pointer or named list of widget pointers
#' @return For single widget: list with state fields (e.g., text, value, active, selected)
#'         For list of widgets: named list where each element is a widget's state list
#' @details
#' Supported widgets and their returned fields:
#' - GtkEntry: list(text = "...")
#' - GtkTextView: list(text = "...")
#' - GtkSpinButton: list(value = 123.45)
#' - GtkDropDown: list(selected = 2L, text = "option")
#' - GtkCheckButton: list(active = TRUE/FALSE)
#' @export
gtkGetUiState <- function(widgets) {
  .Call('R_gtk_get_ui_state', widgets)
}

#' Launch RGtk4 demo selector
#' @export
launch_rgtk_demo <- function() {
  gtkInit()
  gtkStartEventLoop()

  window <- gtkWindowNew()
  gtkWindowSetTitle(window, "RGtk4 Demo Launcher")
  gtkWindowSetDefaultSize(window, 600L, 500L)

  # Track this window for dock management
  gtkWindowTrack(window)

  main_box <- gtkBoxNew(1L, 10L)
  gtkWidgetSetMarginTop(main_box, 15L)
  gtkWidgetSetMarginBottom(main_box, 15L)
  gtkWidgetSetMarginStart(main_box, 15L)
  gtkWidgetSetMarginEnd(main_box, 15L)
  gtkWindowSetChild(window, main_box)

  # Title
  title_lbl <- gtkLabelNew("")
  gtkLabelSetMarkup(title_lbl, "<span size=\"x-large\" weight=\"bold\">RGtk4 Demo Launcher</span>")
  gtkBoxAppend(main_box, title_lbl)

  gtkBoxAppend(main_box, gtkSeparatorNew(0L))

  # Demo selector
  demo_label <- gtkLabelNew("Select a demo:")
  gtkWidgetSetHalign(demo_label, 1L)  # GTK_ALIGN_START
  gtkBoxAppend(main_box, demo_label)

  demo_dropdown <- gtkDropDownNew(gtkStringListFromVector(c(
    "Comprehensive Demo",
    "Simple Hello World",
    "Data Harvest Example"
  )), NULL)
  gtkBoxAppend(main_box, demo_dropdown)

  launch_btn <- gtkButtonNew()
  gtkButtonSetLabel(launch_btn, "Launch Selected Demo")
  gtkBoxAppend(main_box, launch_btn)

  gSignalConnectR(launch_btn, "clicked", function(w) {
    selected <- gtkDropDownGetSelected(demo_dropdown)
    if (selected == 0L) {
      source(system.file("extdata/examples/comprehensive_demo.R", package = "Rgtk4"))
    } else if (selected == 1L) {
      source(system.file("extdata/examples/hello_world.R", package = "Rgtk4"))
    } else if (selected == 2L) {
      source(system.file("extdata/examples/harvest_example.R", package = "Rgtk4"))
    }
  })

  gtkBoxAppend(main_box, gtkSeparatorNew(0L))

  # R Code Editor section
  editor_label <- gtkLabelNew("")
  gtkLabelSetMarkup(editor_label, "<span weight=\"bold\">R Code Editor</span>")
  gtkWidgetSetHalign(editor_label, 1L)
  gtkBoxAppend(main_box, editor_label)

  # Scrolled window for text view
  scrolled <- gtkScrolledWindowNew()
  gtkWidgetSetVexpand(scrolled, TRUE)
  gtkScrolledWindowSetPolicy(scrolled, 1L, 1L)  # GTK_POLICY_AUTOMATIC
  gtkBoxAppend(main_box, scrolled)

  # Text view for code
  text_view <- gtkTextViewNew()
  gtkTextViewSetMonospace(text_view, TRUE)
  gtkTextViewSetWrapMode(text_view, 0L)  # GTK_WRAP_NONE
  gtkScrolledWindowSetChild(scrolled, text_view)

  # Set initial code
  buffer <- gtkTextViewGetBuffer(text_view)
  initial_code <- "# Enter R code here
library(Rgtk4)

# Example:
print('Hello from RGtk4!')
x <- 1:10
print(mean(x))
"
  gtkTextBufferSetText(buffer, initial_code, -1L)

  # Run button
  run_btn <- gtkButtonNew()
  gtkButtonSetLabel(run_btn, "Run Code in R Console")
  gtkBoxAppend(main_box, run_btn)

  gSignalConnectR(run_btn, "clicked", function(w) {
    state <- gtkGetUiState(text_view)
    code <- state$text

    cat("\n=== Running code from RGtk4 demo ===\n")
    tryCatch({
      eval(parse(text = code), envir = .GlobalEnv)
    }, error = function(e) {
      cat("Error:", conditionMessage(e), "\n")
    })
    cat("=== Code execution complete ===\n\n")
  })

  gtkWindowPresent(window)

  # On Windows, explicitly activate the window to bring it to front
  if (.Platform$OS.type == "windows") {
    # Give GTK a moment to create the window, then activate
    Sys.sleep(0.1)
    gtkWindowPresent(window)  # Call again to force focus
  }
}

#' Process GTK Events
#'
#' Manually process pending GTK events. Useful on Windows where automatic
#' event processing may not work as expected.
#'
#' @return Logical indicating if events were processed
#' @export
gtkMainIteration <- function() {
  .Call("R_gtk_main_iteration", PACKAGE = "Rgtk4")
}

#' Process All GTK Events
#'
#' Process all pending GTK events in a loop.
#'
#' @param blocking Whether to block until an event occurs
#' @return Number of events processed
#' @export
gtkMainIterationDo <- function(blocking = FALSE) {
  .Call("R_gtk_main_iteration_do", as.logical(blocking), PACKAGE = "Rgtk4")
}

#' Present window with automatic event processing on Windows
#'
#' Wrapper around gtkWindowPresent that processes GTK events on Windows
#' to ensure the window renders properly.
#'
#' @param window GtkWindow pointer
#' @export
gtkWindowPresentAndProcess <- function(window) {
  gtkWindowPresent(window)

  # On Windows, process events to ensure rendering
  if (.Platform$OS.type == "windows") {
    for (i in 1:10) {
      gtkMainIteration()
      Sys.sleep(0.01)
    }
  }

  invisible(NULL)
}

# varadic template function that is not generated - internal use only
#' Create a text tag with properties
#'
#' Convenience wrapper for creating GtkTextTag with properties.
#'
#' @param buffer GtkTextBuffer
#' @param tag_name Tag name (character) or NULL for anonymous tag
#' @param ... Named properties to set (e.g., foreground = "red", font = "Monospace 12")
#' @return GtkTextTag
#' @export
gtkTextBufferCreateTag <- function(buffer, tag_name = NULL, ...) {
  tag <- .Call("R_gtk_text_buffer_create_tag_simple", buffer, tag_name)
  if (is.null(tag)) return(NULL)
  props <- list(...)
  if (length(props) > 0) {
    for (p in names(props)) {
      gObjectSetProperty(tag, p, props[[p]])
    }
  }
  tag
}

#' Create a GtkMessageDialog
#'
#' @param parent The parent GtkWindow (pointer)
#' @param flags Dialog flags (e.g., MODAL = 1L)
#' @param message_type Icon/Message type (e.g., QUESTION = 2L)
#' @param buttons_type Button set (e.g., YES_NO = 4L)
#' @param message The text message to display
#' @export
gtkMessageDialogNew <- function(parent, flags, message_type, buttons_type, message) {

  flags <- as.integer(flags)
  message_type <- as.integer(message_type)
  buttons_type <- as.integer(buttons_type)
  message <- as.character(message)

  # This manual implementation is provided to handle variadic C arguments that
  # are not supported by the static generator
  ptr <- .Call("R_gtk_message_dialog_new_safe",
               parent,
               flags,
               message_type,
               buttons_type,
               message)

  if (!is.null(ptr)) {
    attr(ptr, "glib_type") <- "GtkMessageDialog"
    class(ptr) <- c("GtkMessageDialog", "GtkDialog", "GtkWidget", "GObject")
  }

  return(ptr)
}

#' GObject Property Setters
#'
#' These convenience functions allow you to set properties on a GObject by
#' explicitly defining the data type. This ensures the underlying C logic
#' correctly casts the R values to the appropriate GTK types.
#'
#' @param object GObject external pointer
#' @param property Property name (character)
#' @param value The value to set (type-specific)
#' @name gObjectSetters
NULL

#' @rdname gObjectSetters
#' @export
gObjectSetString <- function(object, property, value) {
  invisible(.Call("R_g_object_set_string", object, property, value))
}

#' @rdname gObjectSetters
#' @export
gObjectSetBoolean <- function(object, property, value) {
  invisible(.Call("R_g_object_set_boolean", object, property, as.logical(value)))
}

#' @rdname gObjectSetters
#' @export
gObjectSetInt <- function(object, property, value) {
  invisible(.Call("R_g_object_set_int", object, property, as.integer(value)))
}

#' @rdname gObjectSetters
#' @export
gObjectSetDouble <- function(object, property, value) {
  invisible(.Call("R_g_object_set_double", object, property, as.numeric(value)))
}

#' Pretty-print method for RGtk4 wrapped pointers.
#'
#' All extptrs returned from auto-generated bindings carry a trailing class
#' "RGtkObject" plus the GLib type name. This method prints them as
#'   <TypeName 0x...>
#' instead of the default base-R "<pointer: 0x...>" with a noisy attribute
#' dump.
#'
#' @export
print.RGtkObject <- function(x, ...) {
  type <- class(x)[1]
  addr <- .Call("R_extptr_address", x, PACKAGE = "Rgtk4")
  cat(sprintf("<%s %s>\n", type, if (is.null(addr)) "?" else addr))
  invisible(x)
}