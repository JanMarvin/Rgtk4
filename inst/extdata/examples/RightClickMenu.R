library(Rgtk4)
gtkInit()
gtkStartEventLoop()

window <- gtkWindowNew()
gtkWindowSetTitle(window, "Right-Click Test")
gtkWindowSetDefaultSize(window, 400L, 300L)

area <- gtkBoxNew(1L, 0L)
gtkWidgetSetVexpand(area, TRUE)
gtkWindowSetChild(window, area)
gtkBoxAppend(area, gtkLabelNew("Right-click anywhere"))

menu_model   <- gMenuNew()
action_group <- gSimpleActionGroupNew()
for (item in list(
  list(label = "Action One", name = "one"),
  list(label = "Action Two", name = "two"),
  list(label = "Delete",     name = "del")
)) {
  gMenuAppend(menu_model, item$label, paste0("ctx.", item$name))
  action <- gSimpleActionNew(item$name, NULL)
  local({
    n <- item$name
    gSignalConnectR(action, "activate", function(a, p) message(n, " triggered!"))
  })
  gActionMapAddAction(action_group, action)
}
gtkWidgetInsertActionGroup(window, "ctx", action_group)

popover <- gtkPopoverMenuNewFromModel(menu_model)
gtkWidgetSetParent(popover, window)
gtkPopoverSetHasArrow(popover, FALSE)
gtkPopoverSetPosition(popover, 3L)  # BOTTOM

g <- gtkGestureClickNew()
gtkGestureSingleSetButton(g, 0L)
gtkEventControllerSetPropagationPhase(g, 1L)
gSignalConnectR(g, "released", function(gest, n_press, x, y) {
  event     <- tryCatch(gtkEventControllerGetCurrentEvent(gest), error = function(e) NULL)
  event_btn <- tryCatch(gdkButtonEventGetButton(event), error = function(e) 0L)
  if (!isTRUE(event_btn == 3L)) return()

  res <- tryCatch(
    gtkWidgetTranslateCoordinates(area, window, as.integer(x), as.integer(y)),
    error = function(e) NULL)
  wx <- if (!is.null(res)) res$dest_x else as.integer(x)
  wy <- if (!is.null(res)) res$dest_y else as.integer(y)

  ww <- gtkWidgetGetWidth(window)
  wh <- gtkWidgetGetHeight(window)

  # Shift right so cursor is to the left of menu (native macOS feel)
  # Shift up so top of menu aligns with cursor rather than below it
  x_off <- as.integer(wx - ww / 2) + 40L   # 40px right of cursor
  y_off <- as.integer(-(wh - wy)) - 10L     # 10px above default

  tryCatch(gtkPopoverSetOffset(popover, x_off, y_off), error = function(e) {})
  gtkPopoverPopup(popover)
})
gtkWidgetAddController(area, g)

gtkWindowPresent(window)
gtkForceForeground()
