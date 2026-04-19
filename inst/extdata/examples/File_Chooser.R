#!/usr/bin/env Rscript
library(Rgtk4)

cat("=== File Picker with Proper Exit ===\n")
gtkInit()

# Track if app should keep running
keep_running <- TRUE

# 1. Main Window
window <- gtkWindowNew()
gtkWindowSetTitle(window, "RGtk4 File Chooser")
gtkWindowSetDefaultSize(window, 300L, 200L)

# Handle window close - this stops the loop
gSignalConnectR(window, "close-request", function(w) {
  cat("\nWindow closing...\n")
  keep_running <<- FALSE
  return(TRUE)  # Allow window to close
})

# 2. Layout Container
box <- gtkBoxNew(1L, 10L)
gtkWindowSetChild(window, box)

# 3. Content
label <- gtkLabelNew("Press the button to select a file")
gtkBoxAppend(box, label)

button <- gtkButtonNewWithLabel("Select File")
gtkBoxAppend(box, button)

# 4. File Chooser Logic
on_click <- function(btn) {
  cat("\nOpening File Chooser...\n")

  # 0L = GTK_FILE_CHOOSER_ACTION_OPEN
  dialog <- gtkFileChooserNativeNew(
    "Select a File",
    window,
    0L,
    "_Open",
    "_Cancel"
  )

  # Response handler
  response_handler <- function(dlg, response_id) {
    cat("Response ID:", response_id, "\n")

    # GTK_RESPONSE_ACCEPT = -3
    if (response_id == -3L) {
      tryCatch({
        gfile_obj <- gtkFileChooserGetFile(dlg)

        if (!is.null(gfile_obj)) {
          path <- gFileGetPath(gfile_obj)

          if (!is.null(path) && nchar(path) > 0) {
            cat("Selected:", path, "\n")
            gtkLabelSetText(label, paste("Selected:", basename(path)))
          } else {
            gtkLabelSetText(label, "Error: Could not get path")
          }
        } else {
          gtkLabelSetText(label, "Error: No file selected")
        }
      }, error = function(e) {
        cat("ERROR:", e$message, "\n")
        gtkLabelSetText(label, paste("Error:", e$message))
      })
    } else {
      cat("Cancelled\n")
      gtkLabelSetText(label, "No file selected")
    }
  }

  gSignalConnectR(dialog, "response", response_handler)
  gtkNativeDialogShow(dialog)
}

# Connect button click
gSignalConnectR(button, "clicked", on_click)

# 5. Show and Run
gtkWindowPresent(window)
cat("=== GUI Started ===\n")
cat("Close the window to exit (or press Ctrl+C)\n")

# Run event loop - exits when window closes
while (keep_running) {
  gMainContextIteration(NULL, TRUE)
}

cat("Exited cleanly\n")
