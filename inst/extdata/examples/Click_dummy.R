#!/usr/bin/env Rscript
# final_working.R - Complete working GTK4 demo with threaded event loop

library(Rgtk4)

cat("=== RGtk4 Interactive Demo ===\n\n")

# 1. Initialize GTK
cat("Initializing GTK...\n")
gtkInit()

# 2. Start threaded event loop (non-blocking, processes events in background)
cat("Starting event loop...\n")
gtkStartEventLoop()

# 3. Force macOS to bring window to front
cat("Activating macOS foreground...\n")
gtkForceForeground()

# 4. Create window
cat("Creating window...\n")
window <- gtkWindowNew()
gtkWindowSetTitle(window, "RGtk4 - Working Demo")
gtkWindowSetDefaultSize(window, 600L, 400L)
gtkWindowSetResizable(window, TRUE)
gtkWindowSetDeletable(window, TRUE)

# 5. Build UI
vbox <- gtkBoxNew(1L, 12L)
gtkWidgetSetMarginTop(vbox, 20L)
gtkWidgetSetMarginBottom(vbox, 20L)
gtkWidgetSetMarginStart(vbox, 20L)
gtkWidgetSetMarginEnd(vbox, 20L)
gtkWindowSetChild(window, vbox)

# Header
header <- gtkLabelNew("")
gtkLabelSetMarkup(header, "<span size='xx-large' weight='bold'>🎉 RGtk4 Works! 🎉</span>")
gtkBoxAppend(vbox, header)

# Description
desc <- gtkLabelNew("This window runs in the background.\nYou can use R interactively while it's open!")
gtkLabelSetJustify(desc, 1L)
gtkBoxAppend(vbox, desc)

gtkBoxAppend(vbox, gtkSeparatorNew(0L))

# Counter
counter_label <- gtkLabelNew("Clicks: 0")
gtkBoxAppend(vbox, counter_label)

counter <- 0

# Button
btn <- gtkButtonNewWithLabel("Click Me!")
gtkWidgetSetSizeRequest(btn, 200L, 50L)
gtkWidgetSetHalign(btn, 3L)
gtkBoxAppend(vbox, btn)

# Connect button
gSignalConnectR(btn, "clicked", function(w) {
  counter <<- counter + 1
  gtkLabelSetText(counter_label, paste("Clicks:", counter))
  message("Button clicked! Total: ", counter)
})

# Entry
entry <- gtkEntryNew()
gtkEntrySetPlaceholderText(entry, "Type anything...")
gtkBoxAppend(vbox, entry)

# Checkbox
check <- gtkCheckButtonNewWithLabel("Enable experimental mode")
gtkBoxAppend(vbox, check)

gtkBoxAppend(vbox, gtkSeparatorNew(0L))

# Info
info <- gtkLabelNew("Window features:\n✓ Resizable  ✓ Interactive  ✓ Background event loop")
gtkBoxAppend(vbox, info)

# 6. Present window
cat("Presenting window...\n")
gtkWindowPresent(window)

cat("\n=== SUCCESS ===\n")
cat("The window should now be visible and fully interactive!\n\n")

cat("You can:\n")
cat("  - Click the button (watch the counter)\n")
cat("  - Resize the window\n")
cat("  - Type in the entry field\n")
cat("  - Use R commands at the prompt\n\n")

cat("Try these R commands:\n")
cat("  counter                    # Check click count\n")
cat("  gtkWindowSetTitle(window, 'New Title')\n")
cat("  gtkLabelSetText(info, 'Custom message!')\n")
cat("  gtkWindowClose(window)     # Close the window\n\n")

cat("The window runs in a background thread.\n")
cat("R remains fully interactive!\n\n")
