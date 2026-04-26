library(Rgtk4)

gtkInit()
gtkStartEventLoop()
gtkForceForeground()

settings <- gtkSettingsGetDefault()
gObjectSetBoolean(settings, "gtk-application-prefer-dark-theme", TRUE)

# 1. Setup the Application Identity
gSetPrgname("My Custom App")
app <- gtkApplicationNew("com.example.menubar", 0L)

# 2. Manually Register the app (Crucial for macOS Global Menu)
# This replaces the need for gApplicationRun() to "start" the app
gApplicationRegister(app, NULL)

# 3. Define the Menu (Since we aren't using signals, we can do this directly)
menubar <- gMenuNew()
file_menu <- gMenuNew()

gMenuAppend(file_menu, "New Project", "app.new")
gMenuAppend(file_menu, "Quit", "app.quit")
gMenuAppendSubmenu(menubar, "File", file_menu)

# Set the menubar
gtkApplicationSetMenubar(app, menubar)

# 4. Create the Window
# We use gtkApplicationWindowNew so it remains linked to our registered app
window <- gtkApplicationWindowNew(app)
gtkWindowSetTitle(window, "Interactive Mac Menu")
gtkWindowSetDefaultSize(window, 400L, 300L)

label <- gtkLabelNew("The menu bar should be active at the top of your screen!")
gtkWindowSetChild(window, label)

# 5. Bring everything to life
gtkWindowPresent(window)

# Your R console is now free!
# You can type commands here while the window is open.
