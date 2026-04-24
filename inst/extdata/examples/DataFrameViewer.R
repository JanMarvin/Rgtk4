# example_spreadsheet.R - Test the data.frame table view

library(Rgtk4)

# Initialize GTK
gtkInit()
gtkStartEventLoop()
gtkForceForeground()

# Create sample data
df <- mtcars

# Create the table view (returns widget directly)
table_widget <- gtkDataFrameView(df)

# Create window
window <- gtkWindowNew()
gtkWindowSetTitle(window, "Data Frame View Test")
gtkWindowSetDefaultSize(window, 600L, 400L)

# Add table to window
gtkWindowSetChild(window, table_widget)

# Handle close
gSignalConnectR(window, "close-request", function(w) {
  cat("Window closing\n")
  return(FALSE)  # Allow close
})

# Show window
gtkWindowPresent(window)

cat("Window should show the data.frame in a monospaced text view.\n")
