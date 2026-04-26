library(Rgtk4)
gtkInit()
gtkStartEventLoop()

# Create window
window <- gtkWindowNew()
gtkWindowSetTitle(window, "App with Headerbar")
gtkWindowSetDefaultSize(window, 600L, 400L)

# Create headerbar (native toolbar)
headerbar <- gtkHeaderBarNew()
gtkHeaderBarSetShowTitleButtons(headerbar, TRUE)  # Show close/minimize/maximize
gtkHeaderBarSetTitleWidget(headerbar, gtkLabelNew("My Application"))

# Add buttons to headerbar
new_button <- gtkButtonNewFromIconName("document-new")
gtkHeaderBarPackStart(headerbar, new_button)

open_button <- gtkButtonNewFromIconName("document-open")
gtkHeaderBarPackStart(headerbar, open_button)

menu_button <- gtkButtonNewFromIconName("open-menu")
gtkHeaderBarPackEnd(headerbar, menu_button)

# Set headerbar as window titlebar (replaces default titlebar)
gtkWindowSetTitlebar(window, headerbar)

# Add main content
box <- gtkBoxNew(1L, 10L)
gtkWindowSetChild(window, box)

label <- gtkLabelNew("Content area below the headerbar")
gtkBoxAppend(box, label)

# Show window
gtkWindowPresent(window)
gtkWindowTrack(window)
