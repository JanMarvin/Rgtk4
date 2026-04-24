# R/compat.R - GTK3-style compatibility helpers

#' GTK3-Style Compatibility Helpers
#'
#' GTK3-style blocking APIs that are simpler alternatives to GTK4's async patterns.
#' These functions provide familiar interfaces for users migrating from GTK3/RGtk2.
#'
#' @name gtk3-compat
#' @rdname gtk3-compat
NULL

#' @rdname gtk3-compat
#' @param interval Interval in milliseconds between calls
#' @param fun R function to call. Should return TRUE to continue, FALSE to stop.
#' @return For \code{gTimeoutAdd} and \code{gIdleAdd}: source ID (invisibly) that
#'   can be passed to \code{gSourceRemove()} to cancel the callback.
#' @export
gTimeoutAdd <- function(interval, fun) {
  if (!is.function(fun)) {
    stop("fun must be a function")
  }
  invisible(.Call("R_g_timeout_add", as.integer(interval), fun, PACKAGE = "Rgtk4"))
}

#' @rdname gtk3-compat
#' @export
gIdleAdd <- function(fun) {
  if (!is.function(fun)) {
    stop("fun must be a function")
  }
  invisible(.Call("R_g_idle_add", fun, PACKAGE = "Rgtk4"))
}

#' @rdname gtk3-compat
#' @param dialog GtkDialog external pointer
#' @return For \code{gtkDialogRun}: integer response code (GTK_RESPONSE_ACCEPT,
#'   GTK_RESPONSE_CANCEL, etc.)
#' @export
gtkDialogRun <- function(dialog) {
  .Call("R_gtk_dialog_run", dialog, PACKAGE = "Rgtk4")
}

#' @rdname gtk3-compat
#' @param parent Parent window (external pointer) or NULL
#' @param title Dialog title string
#' @param action File chooser action: 0 = open file, 1 = save file, 2 = select folder
#' @return For \code{gtkFileChooserDialogRun}: list with \code{response} (integer)
#'   and \code{file} (selected file path or NULL if cancelled)
#' @export
gtkFileChooserDialogRun <- function(parent = NULL, title = "Choose File", action = 0L) {
  .Call("R_gtk_file_chooser_dialog_run", parent, title, as.integer(action), PACKAGE = "Rgtk4")
}
