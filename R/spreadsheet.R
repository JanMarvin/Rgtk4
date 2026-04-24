# R/spreadsheet.R - Data.frame spreadsheet-like view helper

#' Create a proper table view from a data.frame
#'
#' Creates a GTK4 ColumnView displaying a data.frame with proper columns.
#'
#' @param df A data.frame to display
#' @param height Requested height in pixels (default: 300)
#' @param width Requested width in pixels (default: 400)
#' @return GtkScrolledWindow containing the table
#' @export
gtkDataFrameView <- function(df, height = 300L, width = 400L) {
  if (!is.data.frame(df)) {
    stop("df must be a data.frame")
  }

  n_rows <- nrow(df)
  n_cols <- ncol(df)
  col_names <- names(df)

  # Store data in environment
  data_env <- new.env(parent = emptyenv())
  data_env$df <- df

  # Create column view
  column_view <- gtkColumnViewNew(NULL)

  # Create string list model
  string_list <- gtkStringListNew(NULL)

  # Populate with row data (tab-separated for now, but won't be displayed)
  for (i in seq_len(n_rows)) {
    row_str <- paste(df[i, ], collapse = "\t")
    gtkStringListAppend(string_list, row_str)
  }

  selection_model <- gtkSingleSelectionNew(string_list)
  gtkColumnViewSetModel(column_view, selection_model)

  # Add columns - FIX: Force evaluation of col_idx in closure
  make_column <- function(col_idx, col_name) {
    # Force evaluation NOW, not later
    force(col_idx)
    force(col_name)

    factory <- gtkSignalListItemFactoryNew()

    # Setup callback
    gSignalConnectR(factory, "setup", function(f, item) {
      label <- gtkLabelNew("")
      gtkLabelSetXalign(label, 0)
      gtkListItemSetChild(item, label)
    })

    # Bind callback - col_idx is now captured with its current value
    gSignalConnectR(factory, "bind", function(f, item) {
      label <- gtkListItemGetChild(item)
      position <- gtkListItemGetPosition(item)

      # Get value from the captured col_idx
      value <- data_env$df[position + 1, col_idx]
      gtkLabelSetText(label, as.character(value))
    })

    # Create and return column
    column <- gtkColumnViewColumnNew(col_name, factory)
    column
  }

  # Create columns using the factory function
  for (col_idx in seq_len(n_cols)) {
    column <- make_column(col_idx, col_names[col_idx])
    gtkColumnViewAppendColumn(column_view, column)
  }

  # Wrap in scrolled window
  scrolled <- gtkScrolledWindowNew()
  gtkScrolledWindowSetChild(scrolled, column_view)
  gtkScrolledWindowSetPolicy(scrolled, 1L, 1L)
  gtkWidgetSetSizeRequest(scrolled, as.integer(width), as.integer(height))

  scrolled
}
