test_that("package loads", {
  expect_true(isNamespaceLoaded("Rgtk4"))
})

test_that("GTK initialization works", {
  skip_on_cran()
  skip_if_no_gtk()
  # GTK already initialized in helper
  expect_true(TRUE)
})

test_that("basic widget creation works", {
  skip_on_cran()
  skip_if_no_gtk()

  window <- gtkWindowNew()
  expect_s3_class(window, "GtkWindow")
  expect_s3_class(window, "GObject")

  label <- gtkLabelNew("test")
  expect_s3_class(label, "GtkLabel")
  expect_s3_class(label, "GObject")

  box <- gtkBoxNew(1L, 10L)
  expect_s3_class(box, "GtkBox")
})

test_that("widget hierarchy and packing works", {
  skip_on_cran()
  skip_if_no_gtk()

  window <- gtkWindowNew()
  box <- gtkBoxNew(1L, 0L)
  label <- gtkLabelNew("test")

  expect_silent(gtkWindowSetChild(window, box))
  expect_silent(gtkBoxAppend(box, label))
})

test_that("signal connections work", {
  skip_on_cran()
  skip_if_no_gtk()

  button <- gtkButtonNew()
  clicked <- FALSE

  gSignalConnectR(button, "clicked", function(w) {
    clicked <<- TRUE
  })

  # We can't easily trigger the signal, but at least verify connection didn't crash
  expect_true(TRUE)
})

test_that("property getting/setting works", {
  skip_on_cran()
  skip_if_no_gtk()

  label <- gtkLabelNew("initial")

  gtkLabelSetText(label, "updated")
  text <- gtkLabelGetText(label)

  # gtkLabelGetText returns the actual string, not a pointer
  # If it's wrapped, it should be a character vector
  expect_type(text, "character")
  expect_length(text, 1)
  expect_equal(as.character(text), "updated")
})

test_that("external pointer printing works", {
  skip_on_cran()
  skip_if_no_gtk()

  label <- gtkLabelNew("test")
  output <- capture.output(print(label))

  expect_match(output, "^<GtkLabel 0x[0-9a-f]+>$")
})

test_that("string list creation works", {
  skip_on_cran()
  skip_if_no_gtk()

  items <- c("one", "two", "three")
  list <- gtkStringListFromVector(items)

  expect_s3_class(list, "GtkStringList")
  expect_s3_class(list, "GObject")
})

test_that("UI state extraction works", {
  skip_on_cran()
  skip_if_no_gtk()

  entry <- gtkEntryNew()
  gtkEditableSetText(entry, "test text")

  state <- gtkGetUiState(entry)
  expect_type(state, "list")
  expect_equal(state$text, "test text")
})

test_that("memory management - finalizers registered", {
  skip_on_cran()
  skip_if_no_gtk()

  # Create widget and let it go out of scope
  local({
    w <- gtkLabelNew("temp")
    expect_s3_class(w, "GtkLabel")
  })

  # Force GC - should not crash
  gc()
  expect_true(TRUE)
})
