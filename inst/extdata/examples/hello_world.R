# Simple Hello World Demo for RGtk4

library(Rgtk4)

# Initialize GTK and start event loop
gtkInit()
gtkStartEventLoop()

# Create main window
window <- gtkWindowNew()
gtkWindowSetTitle(window, "Hello World - RGtk4")
gtkWindowSetDefaultSize(window, 300L, 200L)
gtkWindowAddCloseShortcut(window)  # Ctrl+W (Cmd+W on macOS)

# Create a vertical box container
box <- gtkBoxNew(1L, 20L)  # 1 = vertical
gtkWidgetSetMarginTop(box, 30L)
gtkWidgetSetMarginBottom(box, 30L)
gtkWidgetSetMarginStart(box, 30L)
gtkWidgetSetMarginEnd(box, 30L)
gtkWindowSetChild(window, box)

# Add a label
label <- gtkLabelNew("Hello, RGtk4!")
gtkBoxAppend(box, label)

# Add a button
button <- gtkButtonNew()
gtkButtonSetLabel(button, "Click Me!")
gtkBoxAppend(box, button)

# Counter for button clicks
click_count <- 0

# Connect button signal
gSignalConnectR(button, "clicked", function(w) {
  click_count <<- click_count + 1
  gtkLabelSetText(label, sprintf("Button clicked %d time%s!",
                                 click_count,
                                 if(click_count == 1) "" else "s"))
})

# Show the window
gtkWindowPresent(window)
