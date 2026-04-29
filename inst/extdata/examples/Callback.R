library(Rgtk4)
gtkInit()
gtkStartEventLoop()

win <- gtkWindowNew()
gtkWindowSetDefaultSize(win, 300, 200)
area <- gtkDrawingAreaNew()
gtkWindowSetChild(win, area)

gtkDrawingAreaSetDrawFunc(area, function(area, cr, w, h) {
  cat("draw", w, "x", h, "\n")
})

gtkWindowPresent(win)
gtkWindowTrack(win)
gtkForceForeground()
