#!/usr/bin/env Rscript
# debug_window.R - Step-by-step window creation with diagnostics

library(Rgtk4)

cat("=== Debug Window Creation ===\n\n")

# 1. Initialize GTK
cat("1. Initializing GTK...\n")
gtkInit()
cat("   ✓ GTK initialized\n\n")

# 2. Create window
cat("2. Creating window...\n")
window <- gtkWindowNew()
cat("   Window object created\n")
cat("   ✓ Window created\n\n")

# 3. Set basic properties
cat("3. Setting window properties...\n")
gtkWindowSetTitle(window, "Debug Window")
gtkWindowSetDefaultSize(window, 400L, 300L)
gtkWindowSetResizable(window, TRUE)
cat("   ✓ Properties set\n\n")

# 4. Add content
cat("4. Adding content...\n")
label <- gtkLabelNew("If you see this, the window is working!")
gtkWindowSetChild(window, label)
cat("   ✓ Content added\n\n")

# 5. Force macOS activation FIRST
cat("5. Forcing macOS activation...\n")
gtkForceForeground()
cat("   ✓ NSApplication activated\n\n")

# 6. Present window
cat("6. Presenting window...\n")
gtkWindowPresent(window)
cat("   ✓ Window presented\n\n")

# 7. Check visibility
cat("7. Checking window state...\n")
visible <- gtkWidgetGetVisible(window)
cat("   Visible:", visible, "\n")
realized <- gtkWidgetGetRealized(window)
cat("   Realized:", realized, "\n")
mapped <- gtkWidgetGetMapped(window)
cat("   Mapped:", mapped, "\n\n")

# 8. Start event loop
cat("8. Starting event loop...\n")
gtkStartEventLoop()
cat("   ✓ Event loop started\n\n")

# 9. Force some event iterations
cat("9. Processing pending events...\n")
for (i in 1:10) {
  gMainContextIteration(NULL, FALSE)
  Sys.sleep(0.05)
}
cat("   ✓ Processed events\n\n")

# 10. Try to raise/focus the window
cat("10. Attempting to raise window...\n")
gtkWindowPresent(window)
gtkForceForeground()
cat("    ✓ Raise attempted\n\n")

cat("=== Status ===\n")
cat("If you don't see a window:\n")
cat("1. Check if something appeared briefly in the Dock\n")
cat("2. Try Cmd+Tab to see if the app is there\n")
cat("3. Check Mission Control (swipe up with 3 fingers)\n\n")

cat("Keeping R interactive. The window should be visible now.\n")
cat("Type 'gtkWindowPresent(window)' to try showing it again.\n\n")

# Keep processing events manually
cat("Processing events manually (Ctrl+C to stop)...\n")
tryCatch({
  while(TRUE) {
    gMainContextIteration(NULL, FALSE)
    Sys.sleep(0.05)
  }
}, interrupt = function(e) {
  cat("\nStopped event loop.\n")
})
