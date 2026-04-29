library(Rgtk4)

# 1. Setup the background loop so R stays interactive
gtkInit()
gtkStartEventLoop()
gtkForceForeground()

# 2. Create the Application Object
# We need this object to "own" the global menu, but we won't call gApplicationRun()
app <- gtkApplicationNew("com.example.globalmenu", 0L)
gApplicationRegister(app, NULL)

# 3. Create the Menu Model
menubar_model <- gMenuNew()
file_menu <- gMenuNew()

gMenuAppend(file_menu, "New Project", "app.new")
gMenuAppend(file_menu, "Quit", "app.quit")
gMenuAppendSubmenu(menubar_model, "File", file_menu)

# 4. Attach the menu to the Application
# This is what moves it to the top of your screen
gtkApplicationSetMenubar(app, menubar_model)

# 5. Define Actions
# Since the menu items use "app.new", we attach actions to the 'app' object
act_new <- gSimpleActionNew("new", NULL)
gSignalConnectR(act_new, "activate", function(a, p) message("New Project clicked!"))
gActionMapAddAction(app, act_new)

act_quit <- gSimpleActionNew("quit", NULL)
gSignalConnectR(act_quit, "activate", function(a, p) gtkWindowClose(win))
gActionMapAddAction(app, act_quit)

# 6. Create the Window
# Use gtkApplicationWindowNew so it's linked to the app that owns the menu
win <- gtkApplicationWindowNew(app)
gtkWindowSetTitle(win, "Native Menu Demo")
gtkWindowSetDefaultSize(win, 400L, 300L)

label <- gtkLabelNew("Check the very top of your screen!")
gtkWindowSetChild(win, label)

gtkWindowPresent(win)

cat("=== Global Menu Active ===\n")
cat("The menu is now in the OS system bar.\n")
cat("R console is still yours to use.\n")
