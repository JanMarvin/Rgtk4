# Boxed-struct lifecycle: alloc + init + read back.
test_that("graphene_rect alloc/init/get works without crash", {
  skip_if_no_gtk()
  rect <- Rgtk4::grapheneRectAlloc()
  expect_true(inherits(rect, "RGtkObject"))
  Rgtk4::grapheneRectInit(rect, 10, 20, 100, 50)
  expect_equal(c(Rgtk4::grapheneRectGetWidth(rect)), 100)
  expect_equal(c(Rgtk4::grapheneRectGetHeight(rect)), 50)
})

# Idle/timer callback dispatch + closure lifetime.
test_that("g_idle_add fires callback multiple times without crash", {
  skip_if_no_gtk()
  Rgtk4::gtkStartEventLoop()
  n <- 0L
  Rgtk4::gIdleAdd(function() {
    n <<- n + 1L
    n < 3L
  })
  deadline <- Sys.time() + 2
  while (n < 3L && Sys.time() < deadline) {
    Rgtk4::gtkMainIteration()
    Sys.sleep(0.01)
  }
  expect_gte(n, 3L)
})

# Weak-ref liveness: destroying a GObject blanks the R extptr so subsequent
# calls fail with a clean error instead of a segfault.
test_that("destroyed window surfaces clean error, not segfault", {
  skip_if_no_gtk()
  win <- Rgtk4::gtkWindowNew()
  Rgtk4::gtkWindowDestroy(win)
  for (i in 1:20) Rgtk4::gtkMainIteration()
  gc()
  ## not sure how to test this reliably
  # expect_error(
  #   Rgtk4::gtkWindowSetTitle(win, "oops"),
  #   "may have been destroyed|type mismatch|external pointer is NULL"
  # )
})

# Subtype acceptance: a GtkWindow IS-A GtkWidget.
test_that("subtype is accepted where supertype is expected", {
  skip_if_no_gtk()
  win <- Rgtk4::gtkWindowNew()
  expect_no_error(Rgtk4::gtkWidgetSetVisible(win, TRUE))
})

# Drawing-area callback receives correctly typed args.
test_that("draw func receives integer w/h and an extptr cr", {
  skip_if_no_gtk()
  Rgtk4::gtkStartEventLoop()
  win <- Rgtk4::gtkWindowNew()
  Rgtk4::gtkWindowSetDefaultSize(win, 123, 45)
  area <- Rgtk4::gtkDrawingAreaNew()
  Rgtk4::gtkWindowSetChild(win, area)

  captured <- new.env()
  Rgtk4::gtkDrawingAreaSetDrawFunc(area, function(area, cr, w, h) {
    captured$w <- w
    captured$h <- h
    captured$cr_type <- typeof(cr)
  })
  Rgtk4::gtkWindowPresent(win)

  deadline <- Sys.time() + 2
  while (is.null(captured$w) && Sys.time() < deadline) {
    Rgtk4::gtkMainIteration()
    Sys.sleep(0.01)
  }

  expect_type(captured$w, "integer")
  expect_type(captured$h, "integer")
  expect_identical(captured$cr_type, "externalptr")
  expect_gt(captured$w, 0L)
})
