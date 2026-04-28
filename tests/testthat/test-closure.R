test_that("callbacks survive timer ticks (was: segfault on second tick)", {
  gtkInit()
  gtkStartEventLoop()
  n <- 0
  gIdleAdd(function() { n <<- n + 1L; n < 3 })
  Sys.sleep(0.5)
  for (i in 1:50) gtkMainIteration()
  expect_gte(n, 3)
})

test_that("graphene_rect_alloc/init does not crash (was: G_IS_OBJECT on non-GObject)", {
  rect <- grapheneRectAlloc()
  grapheneRectInit(rect, 1, 2, 3, 4)
  expect_equal(as.numeric(grapheneRectGetWidth(rect)), 3)
  expect_equal(as.numeric(grapheneRectGetHeight(rect)), 4)
})
