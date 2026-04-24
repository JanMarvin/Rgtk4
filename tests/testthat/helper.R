# Check if GTK/display is available without actually initializing
# This runs when helper loads and sets a flag
.gtk_likely_available <- local({
  # On Unix, need DISPLAY set
  if (.Platform$OS.type == "unix" && Sys.getenv("DISPLAY") == "") {
    return(FALSE)
  }
  # On Windows, need interactive session
  if (.Platform$OS.type == "windows" && !interactive()) {
    return(FALSE)
  }
  # If we get here, display might be available
  return(TRUE)
})

skip_if_no_gtk <- function() {
  if (!.gtk_likely_available) {
    skip("GTK not available (no display server)")
  }

  # Additional safety: try to init GTK if not already done
  if (!exists(".gtk_initialized", envir = .GlobalEnv)) {
    tryCatch({
      gtkInit()
      assign(".gtk_initialized", TRUE, envir = .GlobalEnv)
    }, error = function(e) {
      skip(paste("GTK initialization failed:", e$message))
    })
  }
}
