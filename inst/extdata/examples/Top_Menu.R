library(Rgtk4)

gSetPrgname("My Custom App")
app <- gtkApplicationNew("com.example.menubar", 0L)

# 1. The Startup Signal: This is where the Menu is born
gSignalConnectR(app, "startup", function(a) {
  menubar <- gMenuNew()
  file_menu <- gMenuNew()

  # Add items
  gMenuAppend(file_menu, "New Project", "app.new")
  gMenuAppend(file_menu, "Quit", "app.quit")
  gMenuAppendSubmenu(menubar, "File", file_menu)

  # Now it's safe to set the menubar
  gtkApplicationSetMenubar(a, menubar)
})

# 2. The Activate Signal: This is where the Window is born
gSignalConnectR(app, "activate", function(a) {
  window <- gtkApplicationWindowNew(a)
  gtkWindowSetTitle(window, "Mac Global Menu")
  gtkWindowSetDefaultSize(window, 400L, 300L)

  label <- gtkLabelNew("Look at the top of your screen!")
  gtkWindowSetChild(window, label)

  gtkWindowPresent(window)
})

# 3. Start the app
gApplicationRun(app, 0L, NULL)
