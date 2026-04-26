library(Rgtk4)

# Initialize GTK and start event loop
gtkInit()
gtkStartEventLoop()

# Fetch CRAN mirrors dynamically
mirrors <- getCRANmirrors(all = TRUE, local.only = FALSE)

# Create a window
window <- gtkWindowNew()
gtkWindowSetTitle(window, "CRAN Mirror Selector")
gtkWindowSetDefaultSize(window, 500L, 400L)

# Add some content
box <- gtkBoxNew(1L, 10L) # 1 = vertical orientation
gtkWindowSetChild(window, box)

label <- gtkLabelNew("Select a CRAN mirror from the list:")
gtkBoxAppend(box, label)

# Create a scrolled area for the list
scrolled <- gtkScrolledWindowNew()
gtkWidgetSetVexpand(scrolled, TRUE)
gtkBoxAppend(box, scrolled)

list_box <- gtkListBoxNew()
gtkScrolledWindowSetChild(scrolled, list_box)

# Populate the list dynamically
for (i in seq_len(nrow(mirrors))) {
  # Create a label for each mirror name
  row_label <- gtkLabelNew(mirrors$Name[i])
  gtkWidgetSetHalign(row_label, 1L)
  gtkWidgetSetMarginStart(row_label, 10L)
  gtkWidgetSetMarginEnd(row_label, 10L)
  gtkWidgetSetMarginTop(row_label, 5L)
  gtkWidgetSetMarginBottom(row_label, 5L)

  # Appending a widget to a ListBox automatically wraps it in a Row
  gtkListBoxAppend(list_box, row_label)
}

button <- gtkButtonNewWithLabel("Confirm Selection")
gtkBoxAppend(box, button)

# Connect signals
gSignalConnectR(button, "clicked", function(w) {
  selected_row <- gtkListBoxGetSelectedRow(list_box)

  if (!is.null(selected_row)) {
    # GTK indices are 0-based; R is 1-based
    index <- gtkListBoxRowGetIndex(selected_row) + 1

    selected_name <- mirrors$Name[index]
    selected_url  <- mirrors$URL[index]

    cat(sprintf("Selected: %s\nURL: %s\n", selected_name, selected_url))
  } else {
    cat("No mirror selected.\n")
  }
})

# Show the window
gtkWindowPresent(window)
gtkForceForeground()
