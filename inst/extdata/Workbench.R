# R/workbench.R - Four-window workbench for Rgtk4
# Code is typed at the terminal R console or run from the editor; panes
# auto-refresh after each top-level command via addTaskCallback().

.wb <- new.env(parent = emptyenv())

# GTK boolean getters return $result as integer 0/1, not a logical. isTRUE()
# is FALSE for integer 1, so every getter result must be coerced before use
# in a condition. This was the dark-mode bug: isTRUE(getActive()) was always
# FALSE.
.wbBool <- function(x) isTRUE(as.logical(x))


# Editor appearance config. Mutated by the config popover; read by every
# editor tab on creation and on restyle. Persisted between sessions.
.wb$cfg <- list(font = "Monospace", size = 11L, dark = FALSE,
                tab_width = 2L, soft_tabs = TRUE)

# Per-user config file. tools::R_user_dir gives the platform-correct
# location (~/.config/R/Rgtk4 on Linux, Library/... on macOS, AppData on
# Windows).
.wbConfigFile <- function() {
  dir <- tools::R_user_dir("Rgtk4", which = "config")
  file.path(dir, "workbench-config.rds")
}

# Load persisted config over the defaults; missing or unreadable file just
# leaves the defaults in place. Only known keys are taken, so an old file
# cannot inject unexpected fields.
.wbLoadConfig <- function() {
  f <- .wbConfigFile()
  if (!file.exists(f)) return(invisible())
  saved <- tryCatch(readRDS(f), error = function(e) NULL)
  if (!is.list(saved)) return(invisible())
  for (k in names(.wb$cfg)) {
    if (!is.null(saved[[k]])) .wb$cfg[[k]] <- saved[[k]]
  }
  invisible()
}

.wbSaveConfig <- function() {
  f <- .wbConfigFile()
  tryCatch({
    dir.create(dirname(f), recursive = TRUE, showWarnings = FALSE)
    saveRDS(.wb$cfg, f)
  }, error = function(e) NULL)
  invisible()
}

# Command history (in-memory; newest last). .wb$historyView, when set by
# the history panel, is refreshed after each run.
.wb$history <- character(0)

# Directory for periodic autosaves of unsaved editor buffers. Recovered
# manually after a crash; cleaned up on a clean shutdown.
.wb$autosaveDir <- file.path(tempdir(), "rgtk4_workbench_autosave")

# Live file dialogs are held here so R's garbage collector cannot finalize
# a native dialog while it is still on screen.
.wb$liveDialogs <- list()

.wbObjectInfo <- function(name, env) {
  val <- get0(name, envir = env, inherits = FALSE)
  cls <- paste(class(val), collapse = ", ")
  dim_str <- if (!is.null(dim(val))) {
    paste(dim(val), collapse = " x ")
  } else if (is.atomic(val) || is.list(val)) {
    as.character(length(val))
  } else {
    ""
  }
  size <- format(utils::object.size(val), units = "auto")
  list(name = name, class = cls, dim = dim_str, size = size,
       is_df = is.data.frame(val))
}

.wbColumnView <- function(rows, columns, on_activate = NULL) {
  view <- gtkColumnViewNew(NULL)
  gtkWidgetSetHexpand(view, TRUE)
  gtkWidgetSetVexpand(view, TRUE)
  model <- gtkStringListNew(NULL)
  for (i in seq_along(rows)) {
    gtkStringListAppend(model, as.character(i))
  }
  selection <- gtkSingleSelectionNew(model)
  gtkColumnViewSetModel(view, selection)

  data_env <- new.env(parent = emptyenv())
  data_env$rows <- rows

  make_column <- function(key, title, expand) {
    force(key)
    force(title)
    factory <- gtkSignalListItemFactoryNew()
    gSignalConnectR(factory, "setup", function(f, item) {
      label <- gtkLabelNew("")
      gtkLabelSetXalign(label, 0)
      gtkListItemSetChild(item, label)
    })
    gSignalConnectR(factory, "bind", function(f, item) {
      label <- gtkListItemGetChild(item)
      pos <- gtkListItemGetPosition(item)
      row <- data_env$rows[[pos + 1L]]
      gtkLabelSetText(label, as.character(row[[key]]))
    })
    column <- gtkColumnViewColumnNew(title, factory)
    gtkColumnViewColumnSetExpand(column, expand)
    column
  }

  for (col in columns) {
    expand <- isTRUE(col$expand)
    gtkColumnViewAppendColumn(view, make_column(col$key, col$title, expand))
  }

  if (!is.null(on_activate)) {
    gSignalConnectR(view, "activate", function(v, position) {
      row <- data_env$rows[[position + 1L]]
      on_activate(row)
    })
  }

  scrolled <- gtkScrolledWindowNew()
  gtkScrolledWindowSetChild(scrolled, view)
  gtkScrolledWindowSetPolicy(scrolled, 1L, 1L)
  gtkWidgetSetHexpand(scrolled, TRUE)
  gtkWidgetSetVexpand(scrolled, TRUE)
  list(widget = scrolled, data_env = data_env, model = model,
       selection = selection)
}

.wbEnvironmentWindow <- function() {
  window <- gtkWindowNew()
  gtkWindowSetTitle(window, "Environment - Rgtk4 Workbench")
  gtkWindowSetDefaultSize(window, 480L, 400L)
  gtkWindowAddCloseShortcut(window)
  gtkWindowSetHideOnClose(window, TRUE)

  box <- gtkBoxNew(1L, 6L)
  gtkWindowSetChild(window, box)

  toolbar <- gtkBoxNew(0L, 6L)
  gtkWidgetSetMarginTop(toolbar, 6L)
  gtkWidgetSetMarginStart(toolbar, 6L)
  gtkWidgetSetMarginEnd(toolbar, 6L)
  refresh <- gtkButtonNewWithLabel("Refresh")
  gtkBoxAppend(toolbar, refresh)
  gtkBoxAppend(box, toolbar)

  holder <- gtkBoxNew(1L, 0L)
  gtkWidgetSetHexpand(holder, TRUE)
  gtkWidgetSetVexpand(holder, TRUE)
  gtkBoxAppend(box, holder)

  state <- new.env(parent = emptyenv())
  state$current <- NULL

  rebuild <- function() {
    if (!is.null(state$current)) {
      gtkBoxRemove(holder, state$current)
      state$current <- NULL
    }
    names <- sort(ls(envir = globalenv()))
    if (length(names) == 0L) {
      empty <- gtkLabelNew("Environment is empty")
      gtkWidgetSetVexpand(empty, TRUE)
      gtkBoxAppend(holder, empty)
      state$current <- empty
      return(invisible())
    }
    rows <- lapply(names, .wbObjectInfo, env = globalenv())
    cv <- .wbColumnView(
      rows,
      list(list(key = "name",  title = "Name",       expand = TRUE),
           list(key = "class", title = "Class",      expand = TRUE),
           list(key = "dim",   title = "Dim/Length", expand = FALSE),
           list(key = "size",  title = "Size",       expand = FALSE)),
      on_activate = function(row) {
        if (isTRUE(row$is_df)) {
          val <- get(row$name, envir = globalenv())
          dfwin <- gtkWindowNew()
          gtkWindowSetTitle(dfwin, paste("Data:", row$name))
          gtkWindowSetDefaultSize(dfwin, 600L, 400L)
          gtkWindowAddCloseShortcut(dfwin)
          gtkWindowSetChild(dfwin, gtkDataFrameView(val))
          gtkWindowTrack(dfwin)
          gtkWindowPresent(dfwin)
        }
      })
    gtkBoxAppend(holder, cv$widget)
    state$current <- cv$widget
  }

  gSignalConnectR(refresh, "clicked", function(w) rebuild())
  rebuild()
  .wb$refreshEnv <- rebuild
  window
}

.wbPackagesWindow <- function() {
  window <- gtkWindowNew()
  gtkWindowSetTitle(window, "Packages - Rgtk4 Workbench")
  gtkWindowSetDefaultSize(window, 520L, 480L)
  gtkWindowAddCloseShortcut(window)
  gtkWindowSetHideOnClose(window, TRUE)

  box <- gtkBoxNew(1L, 6L)
  gtkWindowSetChild(window, box)

  install_bar <- gtkBoxNew(0L, 6L)
  gtkWidgetSetMarginTop(install_bar, 6L)
  gtkWidgetSetMarginStart(install_bar, 6L)
  gtkWidgetSetMarginEnd(install_bar, 6L)
  entry <- gtkEntryNew()
  gtkEntrySetPlaceholderText(entry, "package name")
  gtkWidgetSetHexpand(entry, TRUE)
  install_btn <- gtkButtonNewWithLabel("Install")
  load_btn <- gtkButtonNewWithLabel("Load selected")
  gtkBoxAppend(install_bar, entry)
  gtkBoxAppend(install_bar, install_btn)
  gtkBoxAppend(install_bar, load_btn)
  gtkBoxAppend(box, install_bar)

  holder <- gtkBoxNew(1L, 0L)
  gtkWidgetSetHexpand(holder, TRUE)
  gtkWidgetSetVexpand(holder, TRUE)
  gtkBoxAppend(box, holder)

  state <- new.env(parent = emptyenv())
  state$current <- NULL
  state$cv <- NULL

  rebuild <- function() {
    if (!is.null(state$current)) {
      gtkBoxRemove(holder, state$current)
    }
    ip <- utils::installed.packages()
    loaded <- loadedNamespaces()
    rows <- lapply(seq_len(nrow(ip)), function(i) {
      pkg <- ip[i, "Package"]
      list(name = pkg,
           version = ip[i, "Version"],
           loaded = if (pkg %in% loaded) "yes" else "")
    })
    cv <- .wbColumnView(
      rows,
      list(list(key = "name",    title = "Package", expand = TRUE),
           list(key = "version", title = "Version", expand = FALSE),
           list(key = "loaded",  title = "Loaded",  expand = FALSE)))
    gtkBoxAppend(holder, cv$widget)
    state$current <- cv$widget
    state$cv <- cv
  }

  gSignalConnectR(load_btn, "clicked", function(w) {
    cv <- state$cv
    if (is.null(cv)) return(invisible())
    pos <- gtkSingleSelectionGetSelected(cv$selection)
    if (pos < 0L) return(invisible())
    pkg <- cv$data_env$rows[[pos + 1L]]$name
    tryCatch({
      suppressWarnings(library(pkg, character.only = TRUE))
      message("Loaded package: ", pkg)
    }, error = function(e) message("Load failed: ", conditionMessage(e)))
    rebuild()
  })

  gSignalConnectR(install_btn, "clicked", function(w) {
    pkg <- gtkEditableGetText(entry)
    if (!nzchar(pkg)) return(invisible())
    message("Installing: ", pkg, " ...")
    tryCatch({
      utils::install.packages(pkg)
      rebuild()
    }, error = function(e) message("Install failed: ", conditionMessage(e)))
  })

  rebuild()
  window
}

.wbPlotsWindow <- function() {
  window <- gtkWindowNew()
  gtkWindowSetTitle(window, "Plots - Rgtk4 Workbench")
  gtkWindowSetDefaultSize(window, 560L, 480L)
  gtkWindowAddCloseShortcut(window)
  gtkWindowSetHideOnClose(window, TRUE)

  box <- gtkBoxNew(1L, 6L)
  gtkWindowSetChild(window, box)

  nav <- gtkBoxNew(0L, 6L)
  gtkWidgetSetMarginTop(nav, 6L)
  gtkWidgetSetMarginStart(nav, 6L)
  gtkWidgetSetMarginEnd(nav, 6L)
  prev_btn <- gtkButtonNewWithLabel("Previous")
  next_btn <- gtkButtonNewWithLabel("Next")
  status <- gtkLabelNew("No plots yet")
  gtkBoxAppend(nav, prev_btn)
  gtkBoxAppend(nav, next_btn)
  gtkBoxAppend(nav, status)
  gtkBoxAppend(box, nav)

  # GtkPicture, not GtkImage: GtkImage is for icons and downscales anything
  # large to icon size. GtkPicture displays an image at natural size and
  # scales it to fill its allocation. content-fit 1 = CONTAIN (keep aspect).
  image <- gtkPictureNew()
  gtkPictureSetCanShrink(image, TRUE)
  gtkPictureSetContentFit(image, 1L)
  gtkWidgetSetSizeRequest(image, 400L, 300L)
  gtkWidgetSetHexpand(image, TRUE)
  gtkWidgetSetVexpand(image, TRUE)
  gtkBoxAppend(box, image)

  state <- new.env(parent = emptyenv())
  state$snaps <- list()       # recorded plots (recordPlot objects)
  state$index <- 0L
  state$last <- NULL
  state$dir <- tempfile("rgtk4_plots_")
  dir.create(state$dir)

  # Render the current snapshot to a PNG sized to the image widget and show
  # it. Because replayPlot re-runs R's drawing at the requested size, this
  # reflows the plot to the pane (axes, text, margins re-laid out) rather
  # than bitmap-scaling it - the RStudio-style behaviour.
  render_current <- function() {
    n <- length(state$snaps)
    if (n == 0L || state$index < 1L) {
      gtkLabelSetText(status, "No plots yet")
      return(invisible())
    }
    w <- gtkWidgetGetWidth(image)
    h <- gtkWidgetGetHeight(image)
    if (w < 50L) w <- 520L
    if (h < 50L) h <- 400L
    f <- file.path(state$dir, sprintf("render_%03d_%dx%d.png",
                                      state$index, w, h))
    ok <- tryCatch({
      grDevices::png(f, width = w, height = h, res = 96)
      grDevices::replayPlot(state$snaps[[state$index]])
      grDevices::dev.off()
      TRUE
    }, error = function(e) FALSE)
    if (isTRUE(ok) && file.exists(f)) {
      gtkPictureSetFilename(image, f)
    }
    gtkLabelSetText(status, sprintf("Plot %d of %d", state$index, n))
  }
  show_current <- render_current

  gSignalConnectR(prev_btn, "clicked", function(w) {
    if (state$index > 1L) {
      state$index <- state$index - 1L
      render_current()
    }
  })
  gSignalConnectR(next_btn, "clicked", function(w) {
    if (state$index < length(state$snaps)) {
      state$index <- state$index + 1L
      render_current()
    }
  })

  # Re-render at the new size when the window is resized.
  gSignalConnectR(window, "notify::default-width", function(w, p) {
    render_current()
  })
  gSignalConnectR(window, "notify::default-height", function(w, p) {
    render_current()
  })

  # Capture only when something new was drawn. recordPlot() of an empty
  # device errors; the tryCatch guards that. The snapshot is compared to
  # the previous one so unchanged plots are not duplicated. Snapshots are
  # kept so they can be re-rendered at any size later.
  capture <- function() {
    snap <- tryCatch(grDevices::recordPlot(), error = function(e) NULL)
    if (is.null(snap)) return(invisible())
    if (!is.null(state$last) && identical(snap[[1]], state$last[[1]])) {
      return(invisible())
    }
    state$last <- snap
    state$snaps <- c(state$snaps, list(snap))
    state$index <- length(state$snaps)
    render_current()
    gtkWindowPresent(window)
  }

  .wb$capturePlot <- capture
  window
}

.wbBufferText <- function(buffer) {
  start <- gtkTextBufferGetStartIter(buffer)
  end <- gtkTextBufferGetEndIter(buffer)
  gtkTextBufferGetText(buffer, start, end, TRUE)
}

# Keep a native dialog referenced for its lifetime so the garbage collector
# cannot finalize it mid-display, then drop the reference once it responds.
# Returns a function to register as the dialog's "response" handler wrapper.
.wbKeepDialog <- function(dialog, handler) {
  key <- as.character(length(.wb$liveDialogs) + 1L)
  .wb$liveDialogs[[key]] <- dialog
  function(dlg, response_id) {
    on.exit(.wb$liveDialogs[[key]] <- NULL, add = TRUE)
    handler(dlg, response_id)
  }
}

# Write every open editor buffer to the autosave directory. Each file is
# named by tab index; a manifest records the intended filename so a crash
# recovery can tell which buffers were unsaved scratch vs named files.
.wbAutosave <- function() {
  tabs <- if (!is.null(.wb$tabsEnv)) .wb$tabsEnv$tabs else list()
  if (length(tabs) == 0L) return(TRUE)
  dir <- .wb$autosaveDir
  if (!dir.exists(dir)) dir.create(dir, recursive = TRUE)
  manifest <- character(0)
  for (i in seq_along(tabs)) {
    t <- tabs[[i]]
    txt <- tryCatch(.wbBufferText(t$buffer), error = function(e) NULL)
    if (is.null(txt)) next
    f <- file.path(dir, sprintf("buffer_%03d.R", i))
    tryCatch(writeLines(txt, f, useBytes = TRUE), error = function(e) NULL)
    manifest <- c(manifest, sprintf("%03d\t%s", i, t$filename))
  }
  tryCatch(
    writeLines(manifest, file.path(dir, "manifest.tsv"), useBytes = TRUE),
    error = function(e) NULL)
  TRUE
}

# Shut the workbench down: stop the autosave timer and task callback, clear
# the autosave directory (a clean exit means nothing to recover), and quit.
.wbShutdown <- function() {
  .wbSaveConfig()
  if (!is.null(.wb$autosaveId)) {
    tryCatch(gSourceRemove(.wb$autosaveId), error = function(e) NULL)
    .wb$autosaveId <- NULL
  }
  if (!is.null(.wb$taskId)) {
    tryCatch(removeTaskCallback("rgtk4_workbench"), error = function(e) NULL)
    .wb$taskId <- NULL
  }
  if (dir.exists(.wb$autosaveDir)) {
    tryCatch(unlink(.wb$autosaveDir, recursive = TRUE),
             error = function(e) NULL)
  }
  for (w in .wb$windows) {
    tryCatch(gtkWindowDestroy(w), error = function(e) NULL)
  }
  invisible()
}

# If a single expression is a help request - ?topic, ?pkg::topic, or
# help(topic) - return the topic string; otherwise NULL.
.wbHelpRequest <- function(expr) {
  if (!is.call(expr)) return(NULL)
  head <- expr[[1L]]
  if (identical(head, as.name("?")) && length(expr) == 2L) {
    arg <- expr[[2L]]
    if (is.name(arg)) return(as.character(arg))
    # ?pkg::topic  ->  the topic part
    if (is.call(arg) && identical(arg[[1L]], as.name("::"))) {
      return(as.character(arg[[3L]]))
    }
    if (is.character(arg)) return(arg)
  }
  if (identical(head, as.name("help")) && length(expr) >= 2L) {
    arg <- expr[[2L]]
    if (is.name(arg)) return(as.character(arg))
    if (is.character(arg)) return(arg)
  }
  NULL
}

# Evaluate a chunk of code in the global environment, echoing the source
# and any visible result the way the terminal REPL would. Used by all three
# send modes. A lone help request (?topic) opens the Help window instead of
# evaluating. Refreshes the Environment and Plots panes afterwards.
.wbRunCode <- function(code) {
  code <- trimws(code, which = "right")
  if (!nzchar(trimws(code))) return(invisible())
  for (ln in strsplit(code, "\n", fixed = TRUE)[[1]]) {
    cat("> ", ln, "\n", sep = "")
  }
  tryCatch({
    exprs <- parse(text = code)
    for (e in exprs) {
      topic <- .wbHelpRequest(e)
      if (!is.null(topic) && !is.null(.wb$showHelp)) {
        .wb$showHelp(topic)
        next
      }
      value <- withVisible(eval(e, envir = globalenv()))
      if (value$visible) print(value$value)
    }
  }, error = function(e) message("Error: ", conditionMessage(e)))
  .wb$history <- c(.wb$history, code)
  if (!is.null(.wb$refreshHistory)) .wb$refreshHistory()
  if (!is.null(.wb$refreshEnv)) .wb$refreshEnv()
  if (!is.null(.wb$capturePlot)) .wb$capturePlot()
  invisible()
}

# Send the current selection if there is one, otherwise the cursor's line.
.wbSendLineOrSelection <- function(buffer) {
  sel <- gtkTextBufferGetSelectionBounds(buffer)
  if (isTRUE(as.logical(sel$result))) {
    code <- gtkTextBufferGetText(buffer, sel$start, sel$end, TRUE)
  } else {
    full <- .wbBufferText(buffer)
    mark <- gtkTextBufferGetInsert(buffer)
    cur <- gtkTextBufferGetIterAtMark(buffer, mark)
    line_no <- gtkTextIterGetLine(cur)
    lines <- strsplit(full, "\n", fixed = TRUE)[[1]]
    code <- if (line_no + 1L <= length(lines)) lines[[line_no + 1L]] else ""
  }
  .wbRunCode(code)
}

# Send the whole buffer.
.wbSendFile <- function(buffer) {
  .wbRunCode(.wbBufferText(buffer))
}

# Send everything from the start of the buffer up to and including the
# cursor's line.
.wbSendToCursor <- function(buffer) {
  full <- .wbBufferText(buffer)
  mark <- gtkTextBufferGetInsert(buffer)
  cur <- gtkTextBufferGetIterAtMark(buffer, mark)
  line_no <- gtkTextIterGetLine(cur)
  lines <- strsplit(full, "\n", fixed = TRUE)[[1]]
  upto <- lines[seq_len(min(line_no + 1L, length(lines)))]
  .wbRunCode(paste(upto, collapse = "\n"))
}

# Parse a buffer's text for top-level definitions - `name <- function(...)`,
# `name = function(...)`, and setMethod/setGeneric - returning a data frame
# of name and 0-based line number for the outline panel. Uses a regex scan
# rather than parse() so a syntactically incomplete buffer still outlines.
.wbOutline <- function(text) {
  lines <- strsplit(text, "\n", fixed = TRUE)[[1]]
  if (length(lines) == 0L) {
    return(data.frame(name = character(0), line = integer(0)))
  }
  pat <- "^\\s*([a-zA-Z.][a-zA-Z0-9._]*)\\s*(<-|=)\\s*function\\b"
  hits <- regmatches(lines, regexec(pat, lines))
  out_name <- character(0)
  out_line <- integer(0)
  for (i in seq_along(hits)) {
    h <- hits[[i]]
    if (length(h) >= 2L) {
      out_name <- c(out_name, h[[2L]])
      out_line <- c(out_line, i - 1L)
    }
  }
  data.frame(name = out_name, line = out_line,
             stringsAsFactors = FALSE)
}

# Move the cursor of an editor to a 0-based line and scroll it into view.
.wbGotoLine <- function(tab, line) {
  res <- gtkTextBufferGetIterAtLine(tab$buffer, line)
  it <- res$iter
  if (is.null(it)) return(invisible())
  gtkTextBufferPlaceCursor(tab$buffer, it)
  mark <- gtkTextBufferGetInsert(tab$buffer)
  gtkTextViewScrollToMark(tab$editor, mark, 0.1, TRUE, 0, 0.3)
  gtkWidgetGrabFocus(tab$editor)
  invisible()
}

# Creates a new tab inside the Notebook containing a configured code editor.
# Push the current font config into one editor tab's CSS provider.
.wbApplyEditorStyle <- function(tab) {
  cfg <- .wb$cfg
  css <- sprintf("textview { font-family: \"%s\"; font-size: %dpt; }",
                 cfg$font, cfg$size)
  gtkCssProviderLoadFromData(tab$provider, css, -1L)
}

# Re-apply font config to every open editor tab and switch the source-view
# colour scheme and GTK dark theme to match the dark/light setting.
.wbRestyleAllEditors <- function() {
  # Dark mode via the GTK settings hint - this is what worked before and is
  # honoured by themes that ship a dark variant. The earlier CSS-provider
  # approach fought the theme and is removed.
  settings <- gtkSettingsGetDefault()
  gObjectSetBoolean(settings, "gtk-application-prefer-dark-theme",
                    isTRUE(.wb$cfg$dark))
  if (is.null(.wb$tabsEnv)) return(invisible())
  scheme_mgr <- gtkSourceStyleSchemeManagerGetDefault()
  scheme_name <- if (isTRUE(.wb$cfg$dark)) "oblivion" else "classic"
  scheme <- gtkSourceStyleSchemeManagerGetScheme(scheme_mgr, scheme_name)
  for (t in .wb$tabsEnv$tabs) {
    .wbApplyEditorStyle(t)
    gtkSourceViewSetInsertSpacesInsteadOfTabs(t$editor,
                                              isTRUE(.wb$cfg$soft_tabs))
    gtkSourceViewSetTabWidth(t$editor, .wb$cfg$tab_width)
    gtkSourceViewSetIndentWidth(t$editor, .wb$cfg$tab_width)
    if (!is.null(scheme)) gtkSourceBufferSetStyleScheme(t$buffer, scheme)
  }
  invisible()
}

.wbCreateEditorTab <- function(notebook, filename = "Untitled", content = "") {
  editor <- gtkSourceViewNew()
  gtkTextViewSetMonospace(editor, TRUE)
  gtkTextViewSetWrapMode(editor, 2L)
  gtkSourceViewSetShowLineNumbers(editor, TRUE)
  gtkSourceViewSetHighlightCurrentLine(editor, TRUE)
  gtkSourceViewSetEnableSnippets(editor, TRUE)
  gtkSourceViewSetAutoIndent(editor, TRUE)
  gtkSourceViewSetIndentOnTab(editor, TRUE)
  gtkSourceViewSetInsertSpacesInsteadOfTabs(editor,
                                            isTRUE(.wb$cfg$soft_tabs))
  gtkSourceViewSetTabWidth(editor, .wb$cfg$tab_width)
  gtkSourceViewSetIndentWidth(editor, .wb$cfg$tab_width)

  buffer <- gtkTextViewGetBuffer(editor)
  lang_mgr <- gtkSourceLanguageManagerGetDefault()
  r_lang <- gtkSourceLanguageManagerGetLanguage(lang_mgr, "r")
  if (!is.null(r_lang)) {
    gtkSourceBufferSetLanguage(buffer, r_lang)
  }

  if (nzchar(content)) {
    gtkTextBufferSetText(buffer, content, -1L)
  }

  # Keep the outline in sync as the buffer is edited.
  gSignalConnectR(buffer, "changed", function(buf) {
    if (!is.null(.wb$refreshOutline)) .wb$refreshOutline()
  })

  # Auto-closing brackets and quote pairs, with overtype. Two behaviours:
  #  - typing an opening char inserts the matching closer and keeps the
  #    cursor between them;
  #  - typing a closing char when that same char is already immediately
  #    after the cursor just steps over it instead of inserting a copy,
  #    so the closer auto-pairing added is never duplicated.
  # The handler runs in insert-text (which sees the resolved character,
  # unlike raw keyvals). It blocks itself by handler id while inserting,
  # and stops the default emission when overtyping.
  closers <- c("(" = ")", "{" = "}", "[" = "]", "\"" = "\"", "'" = "'")
  pair_env <- new.env(parent = emptyenv())
  pair_env$id <- NULL
  pair_env$id <- gSignalConnectR(buffer, "insert-text",
                                 function(buf, iter, text, len) {
                                   if (len != 1L || is.null(pair_env$id)) return(invisible())

                                   # Overtype: char after the cursor equals the closer being typed.
                                   if (text %in% closers) {
                                     after <- gtkTextIterCopy(iter)
                                     if (!.wbBool(gtkTextIterEndsLine(after))) {
                                       nxt <- intToUtf8(gtkTextIterGetChar(after))
                                       if (identical(nxt, text)) {
                                         gSignalStopEmissionByName(buf, "insert-text")
                                         gtkTextIterForwardChar(after)
                                         gtkTextBufferPlaceCursor(buf, after)
                                         return(invisible())
                                       }
                                     }
                                   }

                                   # Auto-close: opening char inserts its matching closer.
                                   if (text %in% names(closers)) {
                                     match <- closers[[text]]
                                     gSignalStopEmissionByName(buf, "insert-text")
                                     gSignalHandlerBlock(buf, pair_env$id)
                                     gtkTextBufferInsertAtCursor(buf, paste0(text, match), -1L)
                                     mark <- gtkTextBufferGetInsert(buf)
                                     it <- gtkTextBufferGetIterAtMark(buf, mark)
                                     gtkTextIterBackwardChars(it, 1L)
                                     gtkTextBufferPlaceCursor(buf, it)
                                     gSignalHandlerUnblock(buf, pair_env$id)
                                   }
                                   invisible()
                                 })

  key_ctrl <- gtkEventControllerKeyNew()
  gtkEventControllerSetPropagationPhase(key_ctrl, 1L)
  gtkWidgetAddController(editor, key_ctrl)

  gSignalConnectR(key_ctrl, "key-pressed",
                  function(ctrl, keyval, keycode, modifier_state) {
                    mods <- as.integer(modifier_state)
                    accel <- bitwAnd(mods, 4L) != 0L || bitwAnd(mods, 268435456L) != 0L
                    shift <- bitwAnd(mods, 1L) != 0L
                    is_return <- keyval == 0xff0dL || keyval == 0xff8dL

                    if (accel && is_return) {
                      if (shift) {
                        .wbSendFile(buffer)
                      } else {
                        .wbSendLineOrSelection(buffer)
                      }
                      return(TRUE)
                    }

                    if (keyval == 0xff09L) {
                      mark <- gtkTextBufferGetInsert(buffer)
                      cur_iter <- gtkTextBufferGetIterAtMark(buffer, mark)
                      pos <- gtkTextIterGetOffset(cur_iter)
                      prefix_text <- substr(.wbBufferText(buffer), 1L, pos)
                      token <- regmatches(prefix_text,
                                          regexpr("[a-zA-Z0-9_.]+$", prefix_text))
                      if (length(token) > 0L && nzchar(token)) {
                        candidates <- c(ls(envir = globalenv()), ls(envir = baseenv()),
                                        "function", "if", "else", "for", "while",
                                        "return", "library")
                        matches <- candidates[startsWith(candidates, token)]
                        if (length(matches) > 0L) {
                          remainder <- substr(matches[1L], nchar(token) + 1L,
                                              nchar(matches[1L]))
                          gtkTextBufferInsertAtCursor(buffer, remainder, -1L)
                          return(TRUE)
                        }
                      }
                    }
                    FALSE
                  })

  scroll <- gtkScrolledWindowNew()
  gtkScrolledWindowSetChild(scroll, editor)
  gtkScrolledWindowSetPolicy(scroll, 1L, 1L)
  gtkWidgetSetHexpand(scroll, TRUE)
  gtkWidgetSetVexpand(scroll, TRUE)

  tab_label <- gtkLabelNew(basename(filename))
  page_id <- gtkNotebookAppendPage(notebook, scroll, tab_label)
  gtkNotebookSetCurrentPage(notebook, page_id)

  # Per-editor CSS provider so the font family and size can be restyled
  # later. gtkSourceView is a GtkTextView subclass; the textview node
  # carries the font.
  provider <- gtkCssProviderNew()
  ctx <- gtkWidgetGetStyleContext(editor)
  gtkStyleContextAddProvider(ctx, provider, 600L)

  tab <- new.env(parent = emptyenv())
  tab$scroll <- scroll
  tab$editor <- editor
  tab$buffer <- buffer
  tab$label <- tab_label
  tab$filename <- filename
  tab$provider <- provider
  .wbApplyEditorStyle(tab)
  # Apply the current source colour scheme so a tab opened while dark mode
  # is on is dark too.
  local({
    mgr <- gtkSourceStyleSchemeManagerGetDefault()
    nm <- if (isTRUE(.wb$cfg$dark)) "oblivion" else "classic"
    sch <- gtkSourceStyleSchemeManagerGetScheme(mgr, nm)
    if (!is.null(sch)) gtkSourceBufferSetStyleScheme(buffer, sch)
  })
  tab
}

# Outline window: a clickable list of top-level function definitions in the
# active editor tab; selecting one jumps that editor to the definition.
# Reads the active tab via .wb$activeTab, set by the Code window.
.wbOutlineWindow <- function() {
  window <- gtkWindowNew()
  gtkWindowSetTitle(window, "Outline - Rgtk4 Workbench")
  gtkWindowSetDefaultSize(window, 240L, 420L)
  gtkWindowAddCloseShortcut(window)
  gtkWindowSetHideOnClose(window, TRUE)

  outline_list <- gtkListBoxNew()
  rows <- new.env(parent = emptyenv())
  rows$lines <- integer(0)
  scroll <- gtkScrolledWindowNew()
  gtkScrolledWindowSetChild(scroll, outline_list)
  gtkWidgetSetVexpand(scroll, TRUE)
  gtkWindowSetChild(window, scroll)

  refresh <- function() {
    gtkListBoxRemoveAll(outline_list)
    tab <- if (!is.null(.wb$activeTab)) .wb$activeTab() else NULL
    if (is.null(tab)) return(invisible())
    df <- .wbOutline(.wbBufferText(tab$buffer))
    rows$lines <- df$line
    for (i in seq_len(nrow(df))) {
      lbl <- gtkLabelNew(df$name[[i]])
      gtkLabelSetXalign(lbl, 0)
      gtkWidgetSetMarginStart(lbl, 4L)
      gtkWidgetSetMarginEnd(lbl, 4L)
      gtkListBoxAppend(outline_list, lbl)
    }
  }

  gSignalConnectR(outline_list, "row-activated", function(lb, row) {
    idx <- gtkListBoxRowGetIndex(row)
    tab <- if (!is.null(.wb$activeTab)) .wb$activeTab() else NULL
    if (!is.null(tab) && idx >= 0L &&
        idx + 1L <= length(rows$lines)) {
      .wbGotoLine(tab, rows$lines[[idx + 1L]])
    }
  })

  .wb$refreshOutline <- refresh
  refresh()
  window
}

# History window: every command run via .wbRunCode, newest last. Selecting
# an entry inserts it at the active editor's cursor.
.wbHistoryWindow <- function() {
  window <- gtkWindowNew()
  gtkWindowSetTitle(window, "History - Rgtk4 Workbench")
  gtkWindowSetDefaultSize(window, 360L, 420L)
  gtkWindowAddCloseShortcut(window)
  gtkWindowSetHideOnClose(window, TRUE)

  history_list <- gtkListBoxNew()
  scroll <- gtkScrolledWindowNew()
  gtkScrolledWindowSetChild(scroll, history_list)
  gtkWidgetSetVexpand(scroll, TRUE)
  gtkWindowSetChild(window, scroll)

  refresh <- function() {
    gtkListBoxRemoveAll(history_list)
    for (cmd in .wb$history) {
      first <- strsplit(cmd, "\n", fixed = TRUE)[[1]][[1]]
      lbl <- gtkLabelNew(first)
      gtkLabelSetXalign(lbl, 0)
      gtkWidgetSetMarginStart(lbl, 4L)
      gtkWidgetSetMarginEnd(lbl, 4L)
      gtkListBoxAppend(history_list, lbl)
    }
  }

  gSignalConnectR(history_list, "row-activated", function(lb, row) {
    idx <- gtkListBoxRowGetIndex(row)
    if (idx >= 0L && idx + 1L <= length(.wb$history) &&
        !is.null(.wb$insertIntoEditor)) {
      .wb$insertIntoEditor(.wb$history[[idx + 1L]])
    }
  })

  .wb$refreshHistory <- refresh
  refresh()
  window
}

# Keyboard-shortcut cheat sheet. GtkShortcutsWindow is not in the bindings,
# so this is a plain window styled to resemble it: sections with headers,
# a themed icon per row, and key combos rendered with GTK's built-in
# .keycap CSS class. Opened by F1 or the toolbar ? button; built lazily
# and reused.
.wbShowShortcuts <- function() {
  if (!is.null(.wb$shortcutsWindow)) {
    gtkWindowPresent(.wb$shortcutsWindow)
    return(invisible())
  }
  window <- gtkWindowNew()
  gtkWindowSetTitle(window, "Keyboard Shortcuts")
  gtkWindowSetDefaultSize(window, 460L, 520L)
  gtkWindowAddCloseShortcut(window)
  gtkWindowSetHideOnClose(window, TRUE)

  scroll <- gtkScrolledWindowNew()
  gtkScrolledWindowSetPolicy(scroll, 1L, 1L)
  gtkWindowSetChild(window, scroll)

  outer <- gtkBoxNew(1L, 18L)
  gtkWidgetSetMarginTop(outer, 18L)
  gtkWidgetSetMarginBottom(outer, 18L)
  gtkWidgetSetMarginStart(outer, 20L)
  gtkWidgetSetMarginEnd(outer, 20L)
  gtkScrolledWindowSetChild(scroll, outer)

  # section title, then rows of: icon name, key combo, description.
  sections <- list(
    list("Files", list(
      c("tab-new-symbolic",        "Ctrl/Cmd + N", "New editor tab"),
      c("document-open-symbolic",  "Ctrl/Cmd + O", "Open file"),
      c("media-floppy-symbolic",   "Ctrl/Cmd + S", "Save file"))),
    list("Editing", list(
      c("edit-find-symbolic",      "Ctrl/Cmd + F", "Find / replace"))),
    list("Running code", list(
      c("media-playback-start-symbolic", "Ctrl/Cmd + Enter",
        "Run line or selection"),
      c("media-seek-forward-symbolic",   "Ctrl/Cmd + R",
        "Run to cursor"))),
    list("Windows", list(
      c("utilities-terminal-symbolic", "Ctrl/Cmd + E",
        "Environment window"),
      c("system-software-install-symbolic", "Ctrl/Cmd + P",
        "Packages window"),
      c("view-list-symbolic",      "Ctrl/Cmd + L", "Outline window"),
      c("document-open-recent-symbolic", "Ctrl/Cmd + H",
        "History window"),
      c("help-about-symbolic",     "F1",           "This overlay"))),
    list("Appearance", list(
      c("weather-clear-night-symbolic", "Ctrl/Cmd + D",
        "Toggle dark mode")))
  )

  add_keycaps <- function(row_box, combo) {
    parts <- strsplit(combo, " + ", fixed = TRUE)[[1]]
    for (j in seq_along(parts)) {
      cap <- gtkLabelNew(parts[[j]])
      gtkWidgetAddCssClass(cap, "keycap")
      gtkBoxAppend(row_box, cap)
      if (j < length(parts)) gtkBoxAppend(row_box, gtkLabelNew("+"))
    }
  }

  for (sec in sections) {
    header <- gtkLabelNew("")
    gtkLabelSetMarkup(header, sprintf("<b>%s</b>", sec[[1]]))
    gtkLabelSetXalign(header, 0)
    gtkBoxAppend(outer, header)

    for (r in sec[[2]]) {
      row <- gtkBoxNew(0L, 10L)
      icon <- gtkImageNewFromIconName(r[[1]])
      gtkBoxAppend(row, icon)
      keys <- gtkBoxNew(0L, 4L)
      add_keycaps(keys, r[[2]])
      gtkWidgetSetSizeRequest(keys, 170L, -1L)
      gtkBoxAppend(row, keys)
      desc <- gtkLabelNew(r[[3]])
      gtkLabelSetXalign(desc, 0)
      gtkBoxAppend(row, desc)
      gtkBoxAppend(outer, row)
    }
  }

  .wb$shortcutsWindow <- window
  gtkWindowTrack(window)
  gtkWindowPresent(window)
  invisible()

}

.wbCodeWindow <- function() {
  window <- gtkWindowNew()
  gtkWindowSetTitle(window, "Code - Rgtk4 Workbench")
  gtkWindowSetDefaultSize(window, 750L, 550L)
  gtkWindowAddCloseShortcut(window)
  gtkWindowSetHideOnClose(window, TRUE)

  box <- gtkBoxNew(1L, 4L)
  gtkWindowSetChild(window, box)

  file_bar <- gtkBoxNew(0L, 6L)
  gtkWidgetSetMarginTop(file_bar, 4L)
  gtkWidgetSetMarginStart(file_bar, 6L)
  gtkWidgetSetMarginEnd(file_bar, 6L)
  open_btn <- gtkButtonNewFromIconName("document-open-symbolic")
  gtkWidgetSetTooltipText(open_btn, "Open")
  save_btn <- gtkButtonNewFromIconName("media-floppy-symbolic")
  gtkWidgetSetTooltipText(save_btn, "Save")
  gtkBoxAppend(file_bar, open_btn)
  gtkBoxAppend(file_bar, save_btn)

  # View menu: opens the Environment and Packages windows on demand.
  view_btn <- gtkMenuButtonNew()
  gtkMenuButtonSetLabel(view_btn, "View")
  view_pop <- gtkPopoverNew()
  view_box <- gtkBoxNew(1L, 4L)
  gtkWidgetSetMarginTop(view_box, 6L)
  gtkWidgetSetMarginBottom(view_box, 6L)
  gtkWidgetSetMarginStart(view_box, 6L)
  gtkWidgetSetMarginEnd(view_box, 6L)
  env_item <- gtkButtonNewWithLabel("Environment")
  pkg_item <- gtkButtonNewWithLabel("Packages")
  outline_item <- gtkButtonNewWithLabel("Outline")
  history_item <- gtkButtonNewWithLabel("History")
  gtkBoxAppend(view_box, env_item)
  gtkBoxAppend(view_box, pkg_item)
  gtkBoxAppend(view_box, outline_item)
  gtkBoxAppend(view_box, history_item)
  gtkPopoverSetChild(view_pop, view_box)
  gtkMenuButtonSetPopover(view_btn, view_pop)
  present_window <- function(name) {
    if (!is.null(.wb$windows[[name]])) {
      gtkWindowPresent(.wb$windows[[name]])
    }
    gtkPopoverPopdown(view_pop)
  }
  gSignalConnectR(env_item, "clicked",
                  function(w) present_window("Environment"))
  gSignalConnectR(pkg_item, "clicked",
                  function(w) present_window("Packages"))
  gSignalConnectR(outline_item, "clicked", function(w) {
    if (!is.null(.wb$refreshOutline)) .wb$refreshOutline()
    present_window("Outline")
  })
  gSignalConnectR(history_item, "clicked", function(w) {
    if (!is.null(.wb$refreshHistory)) .wb$refreshHistory()
    present_window("History")
  })

  # Settings menu: font family, font size, dark mode.
  cfg_btn <- gtkMenuButtonNew()
  gtkMenuButtonSetLabel(cfg_btn, "Settings")
  cfg_pop <- gtkPopoverNew()
  cfg_box <- gtkBoxNew(1L, 6L)
  gtkWidgetSetMarginTop(cfg_box, 8L)
  gtkWidgetSetMarginBottom(cfg_box, 8L)
  gtkWidgetSetMarginStart(cfg_box, 8L)
  gtkWidgetSetMarginEnd(cfg_box, 8L)

  font_row <- gtkBoxNew(0L, 6L)
  gtkBoxAppend(font_row, gtkLabelNew("Font:"))
  font_entry <- gtkEntryNew()
  gtkEditableSetText(font_entry, .wb$cfg$font)
  gtkBoxAppend(font_row, font_entry)
  gtkBoxAppend(cfg_box, font_row)

  size_row <- gtkBoxNew(0L, 6L)
  gtkBoxAppend(size_row, gtkLabelNew("Size:"))
  size_spin <- gtkSpinButtonNewWithRange(6, 32, 1)
  gtkSpinButtonSetValue(size_spin, .wb$cfg$size)
  gtkBoxAppend(size_row, size_spin)
  gtkBoxAppend(cfg_box, size_row)

  tab_row <- gtkBoxNew(0L, 6L)
  gtkBoxAppend(tab_row, gtkLabelNew("Tab width:"))
  tab_spin <- gtkSpinButtonNewWithRange(1, 8, 1)
  gtkSpinButtonSetValue(tab_spin, .wb$cfg$tab_width)
  gtkBoxAppend(tab_row, tab_spin)
  gtkBoxAppend(cfg_box, tab_row)

  soft_check <- gtkCheckButtonNew()
  gtkCheckButtonSetLabel(soft_check, "Insert spaces, not tabs")
  gtkCheckButtonSetActive(soft_check, isTRUE(.wb$cfg$soft_tabs))
  gtkBoxAppend(cfg_box, soft_check)

  dark_check <- gtkCheckButtonNew()
  gtkCheckButtonSetLabel(dark_check, "Dark Mode")
  gtkCheckButtonSetActive(dark_check, isTRUE(.wb$cfg$dark))
  gtkBoxAppend(cfg_box, dark_check)

  apply_btn <- gtkButtonNewWithLabel("Apply")
  gtkBoxAppend(cfg_box, apply_btn)
  gtkPopoverSetChild(cfg_pop, cfg_box)
  gtkMenuButtonSetPopover(cfg_btn, cfg_pop)

  # Run menu: execution scopes beyond the keyboard shortcuts.
  run_btn <- gtkMenuButtonNew()
  gtkMenuButtonSetLabel(run_btn, "Run")
  run_pop <- gtkPopoverNew()
  run_box <- gtkBoxNew(1L, 4L)
  gtkWidgetSetMarginTop(run_box, 6L)
  gtkWidgetSetMarginBottom(run_box, 6L)
  gtkWidgetSetMarginStart(run_box, 6L)
  gtkWidgetSetMarginEnd(run_box, 6L)
  run_line_item <- gtkButtonNewWithLabel("Run line / selection")
  run_cursor_item <- gtkButtonNewWithLabel("Run to cursor")
  run_file_item <- gtkButtonNewWithLabel("Run whole file")
  gtkBoxAppend(run_box, run_line_item)
  gtkBoxAppend(run_box, run_cursor_item)
  gtkBoxAppend(run_box, run_file_item)
  gtkPopoverSetChild(run_pop, run_box)
  gtkMenuButtonSetPopover(run_btn, run_pop)

  # Workspace menu: save/load .RData and clear the global environment.
  ws_btn <- gtkMenuButtonNew()
  gtkMenuButtonSetLabel(ws_btn, "Workspace")
  ws_pop <- gtkPopoverNew()
  ws_box <- gtkBoxNew(1L, 4L)
  gtkWidgetSetMarginTop(ws_box, 6L)
  gtkWidgetSetMarginBottom(ws_box, 6L)
  gtkWidgetSetMarginStart(ws_box, 6L)
  gtkWidgetSetMarginEnd(ws_box, 6L)
  ws_save_item <- gtkButtonNewWithLabel("Save workspace...")
  ws_load_item <- gtkButtonNewWithLabel("Load workspace...")
  ws_clear_item <- gtkButtonNewWithLabel("Clear environment")
  gtkBoxAppend(ws_box, ws_save_item)
  gtkBoxAppend(ws_box, ws_load_item)
  gtkBoxAppend(ws_box, ws_clear_item)
  gtkPopoverSetChild(ws_pop, ws_box)
  gtkMenuButtonSetPopover(ws_btn, ws_pop)

  gtkBoxAppend(file_bar, view_btn)
  gtkBoxAppend(file_bar, run_btn)
  gtkBoxAppend(file_bar, ws_btn)
  gtkBoxAppend(file_bar, cfg_btn)
  help_btn <- gtkButtonNewFromIconName("help-about-symbolic")
  gtkWidgetSetTooltipText(help_btn, "Keyboard shortcuts")
  gSignalConnectR(help_btn, "clicked", function(w) .wbShowShortcuts())
  gtkBoxAppend(file_bar, help_btn)
  hint <- gtkLabelNew("Run: Ctrl/Cmd+Enter  -  Whole file: +Shift")
  gtkWidgetSetHexpand(hint, TRUE)
  gtkLabelSetXalign(hint, 1)
  gtkBoxAppend(file_bar, hint)
  gtkBoxAppend(box, file_bar)

  # Find / Replace bar - hidden until Ctrl/Cmd+F. A GtkSourceSearchContext
  # is created per editor tab on first use and cached on the tab.
  find_bar <- gtkBoxNew(0L, 6L)
  gtkWidgetSetMarginStart(find_bar, 6L)
  gtkWidgetSetMarginEnd(find_bar, 6L)
  find_entry <- gtkEntryNew()
  gtkEntrySetPlaceholderText(find_entry, "Find")
  gtkWidgetSetHexpand(find_entry, TRUE)
  find_next <- gtkButtonNewWithLabel("Next")
  find_prev <- gtkButtonNewWithLabel("Prev")
  repl_entry <- gtkEntryNew()
  gtkEntrySetPlaceholderText(repl_entry, "Replace with")
  gtkWidgetSetHexpand(repl_entry, TRUE)
  repl_one <- gtkButtonNewWithLabel("Replace")
  repl_all <- gtkButtonNewWithLabel("Replace All")
  find_close <- gtkButtonNewWithLabel("Close")
  for (wgt in list(find_entry, find_prev, find_next, repl_entry,
                   repl_one, repl_all, find_close)) {
    gtkBoxAppend(find_bar, wgt)
  }
  gtkWidgetSetVisible(find_bar, FALSE)
  gtkBoxAppend(box, find_bar)

  notebook <- gtkNotebookNew()
  gtkWidgetSetHexpand(notebook, TRUE)
  gtkWidgetSetVexpand(notebook, TRUE)

  tabs_env <- new.env(parent = emptyenv())
  tabs_env$tabs <- list()
  .wb$tabsEnv <- tabs_env

  active_tab <- function() {
    idx <- gtkNotebookGetCurrentPage(notebook)
    if (idx < 0L || idx + 1L > length(tabs_env$tabs)) return(NULL)
    tabs_env$tabs[[idx + 1L]]
  }
  .wb$activeTab <- active_tab

  .wb$insertIntoEditor <- function(text) {
    tab <- active_tab()
    if (!is.null(tab)) {
      gtkTextBufferInsertAtCursor(tab$buffer, text, -1L)
      gtkWidgetGrabFocus(tab$editor)
    }
  }

  gtkBoxAppend(box, notebook)

  initial_tab <- .wbCreateEditorTab(notebook, "Untitled")
  tabs_env$tabs[[1L]] <- initial_tab
  if (!is.null(.wb$refreshOutline)) .wb$refreshOutline()

  # Refresh the Outline window when the user switches editor tabs.
  gSignalConnectR(notebook, "switch-page", function(nb, page, num) {
    if (!is.null(.wb$refreshOutline)) .wb$refreshOutline()
  })

  run_with_active <- function(fn) {
    tab <- active_tab()
    if (!is.null(tab)) fn(tab$buffer)
  }
  gSignalConnectR(run_line_item, "clicked", function(w) {
    run_with_active(.wbSendLineOrSelection)
    gtkPopoverPopdown(run_pop)
  })
  gSignalConnectR(run_cursor_item, "clicked", function(w) {
    run_with_active(.wbSendToCursor)
    gtkPopoverPopdown(run_pop)
  })
  gSignalConnectR(run_file_item, "clicked", function(w) {
    run_with_active(.wbSendFile)
    gtkPopoverPopdown(run_pop)
  })

  gSignalConnectR(ws_save_item, "clicked", function(w) {
    gtkPopoverPopdown(ws_pop)
    chooser <- gtkFileChooserNativeNew("Save Workspace", window, 1L,
                                       "Save", "Cancel")
    gtkFileChooserSetCurrentName(chooser, ".RData")
    gSignalConnectR(chooser, "response", .wbKeepDialog(chooser,
                                                       function(dialog, response_id) {
                                                         if (response_id == -3L) {
                                                           path <- gFileGetPath(gtkFileChooserGetFile(dialog))
                                                           tryCatch({
                                                             save(list = ls(envir = globalenv()), file = path,
                                                                  envir = globalenv())
                                                             message("Workspace saved: ", path)
                                                           }, error = function(e) message("Save failed: ",
                                                                                          conditionMessage(e)))
                                                         }
                                                         gtkNativeDialogDestroy(dialog)
                                                       }))
    gtkNativeDialogShow(chooser)
  })
  gSignalConnectR(ws_load_item, "clicked", function(w) {
    gtkPopoverPopdown(ws_pop)
    chooser <- gtkFileChooserNativeNew("Load Workspace", window, 0L,
                                       "Open", "Cancel")
    gSignalConnectR(chooser, "response", .wbKeepDialog(chooser,
                                                       function(dialog, response_id) {
                                                         if (response_id == -3L) {
                                                           path <- gFileGetPath(gtkFileChooserGetFile(dialog))
                                                           tryCatch({
                                                             load(path, envir = globalenv())
                                                             message("Workspace loaded: ", path)
                                                             if (!is.null(.wb$refreshEnv)) .wb$refreshEnv()
                                                           }, error = function(e) message("Load failed: ",
                                                                                          conditionMessage(e)))
                                                         }
                                                         gtkNativeDialogDestroy(dialog)
                                                       }))
    gtkNativeDialogShow(chooser)
  })
  gSignalConnectR(ws_clear_item, "clicked", function(w) {
    gtkPopoverPopdown(ws_pop)
    rm(list = ls(envir = globalenv()), envir = globalenv())
    message("Environment cleared.")
    if (!is.null(.wb$refreshEnv)) .wb$refreshEnv()
  })

  # Return the active tab's search context, building it (and its settings)
  # on first use. Settings are kept on the tab so wrap-around persists.
  search_ctx <- function(tab) {
    if (is.null(tab$search)) {
      settings <- gtkSourceSearchSettingsNew()
      gtkSourceSearchSettingsSetWrapAround(settings, TRUE)
      tab$searchSettings <- settings
      tab$search <- gtkSourceSearchContextNew(tab$buffer, settings)
    }
    tab$search
  }

  do_find <- function(forward) {
    tab <- active_tab()
    if (is.null(tab)) return(invisible())
    ctx <- search_ctx(tab)
    gtkSourceSearchSettingsSetSearchText(tab$searchSettings,
                                         gtkEditableGetText(find_entry))
    mark <- gtkTextBufferGetInsert(tab$buffer)
    cur <- gtkTextBufferGetIterAtMark(tab$buffer, mark)
    res <- if (forward) {
      gtkSourceSearchContextForward(ctx, cur)
    } else {
      gtkSourceSearchContextBackward(ctx, cur)
    }
    if (isTRUE(as.logical(res$result))) {
      gtkTextBufferSelectRange(tab$buffer, res$match_start, res$match_end)
      gtkTextViewScrollToMark(tab$editor,
                              gtkTextBufferGetInsert(tab$buffer),
                              0.1, TRUE, 0, 0.3)
    }
  }

  gSignalConnectR(find_next, "clicked", function(w) do_find(TRUE))
  gSignalConnectR(find_prev, "clicked", function(w) do_find(FALSE))
  gSignalConnectR(find_entry, "activate", function(w) do_find(TRUE))

  gSignalConnectR(repl_one, "clicked", function(w) {
    tab <- active_tab()
    if (is.null(tab)) return(invisible())
    ctx <- search_ctx(tab)
    gtkSourceSearchSettingsSetSearchText(tab$searchSettings,
                                         gtkEditableGetText(find_entry))
    sel <- gtkTextBufferGetSelectionBounds(tab$buffer)
    if (isTRUE(as.logical(sel$result))) {
      repl <- gtkEditableGetText(repl_entry)
      gtkSourceSearchContextReplace(ctx, sel$start, sel$end, repl, -1L)
    }
    do_find(TRUE)
  })

  gSignalConnectR(repl_all, "clicked", function(w) {
    tab <- active_tab()
    if (is.null(tab)) return(invisible())
    ctx <- search_ctx(tab)
    gtkSourceSearchSettingsSetSearchText(tab$searchSettings,
                                         gtkEditableGetText(find_entry))
    n <- gtkSourceSearchContextReplaceAll(ctx,
                                          gtkEditableGetText(repl_entry),
                                          -1L)
    message("Replaced ", n, " occurrence(s).")
  })

  gSignalConnectR(find_close, "clicked", function(w) {
    gtkWidgetSetVisible(find_bar, FALSE)
  })

  write_tab <- function(tab, path) {
    tryCatch({
      writeLines(.wbBufferText(tab$buffer), path, useBytes = TRUE)
      tab$filename <- path
      gtkLabelSetText(tab$label, basename(path))
      message("Saved: ", path)
    }, error = function(e) message("Error saving file: ",
                                   conditionMessage(e)))
  }

  gSignalConnectR(open_btn, "clicked", function(w) {
    chooser <- gtkFileChooserNativeNew("Open R Script", window, 0L,
                                       "Open", "Cancel")
    filter <- gtkFileFilterNew()
    gtkFileFilterSetName(filter, "R Scripts (*.R)")
    gtkFileFilterAddPattern(filter, "*.R")
    gtkFileChooserAddFilter(chooser, filter)

    gSignalConnectR(chooser, "response", .wbKeepDialog(chooser,
                                                       function(dialog, response_id) {
                                                         if (response_id == -3L) {
                                                           path <- gFileGetPath(gtkFileChooserGetFile(dialog))
                                                           tryCatch({
                                                             content <- readChar(path, file.info(path)$size, useBytes = TRUE)
                                                             new_tab <- .wbCreateEditorTab(notebook, path, content)
                                                             tabs_env$tabs <- c(tabs_env$tabs, list(new_tab))
                                                             message("Opened: ", path)
                                                           }, error = function(e) message("Error opening file: ",
                                                                                          conditionMessage(e)))
                                                         }
                                                         gtkNativeDialogDestroy(dialog)
                                                       }))
    gtkNativeDialogShow(chooser)
  })

  gSignalConnectR(save_btn, "clicked", function(w) {
    idx <- gtkNotebookGetCurrentPage(notebook)
    if (idx < 0L) return(invisible())
    current_tab <- tabs_env$tabs[[idx + 1L]]

    if (nzchar(current_tab$filename) &&
        current_tab$filename != "Untitled") {
      write_tab(current_tab, current_tab$filename)
      return(invisible())
    }

    chooser <- gtkFileChooserNativeNew("Save R Script", window, 1L,
                                       "Save", "Cancel")
    gtkFileChooserSetCurrentName(chooser, "script.R")
    gSignalConnectR(chooser, "response", .wbKeepDialog(chooser,
                                                       function(dialog, response_id) {
                                                         if (response_id == -3L) {
                                                           path <- gFileGetPath(gtkFileChooserGetFile(dialog))
                                                           write_tab(current_tab, path)
                                                         }
                                                         gtkNativeDialogDestroy(dialog)
                                                       }))
    gtkNativeDialogShow(chooser)
  })

  gSignalConnectR(apply_btn, "clicked", function(w) {
    fam <- trimws(gtkEditableGetText(font_entry))
    if (nzchar(fam)) .wb$cfg$font <- fam
    .wb$cfg$size <- as.integer(gtkSpinButtonGetValue(size_spin))
    .wb$cfg$tab_width <- as.integer(gtkSpinButtonGetValue(tab_spin))
    .wb$cfg$soft_tabs <- .wbBool(gtkCheckButtonGetActive(soft_check))
    .wb$cfg$dark <- .wbBool(gtkCheckButtonGetActive(dark_check))
    .wbRestyleAllEditors()
    .wbSaveConfig()
    gtkPopoverPopdown(cfg_pop)
  })

  # Keyboard shortcuts. accel = Ctrl (Windows/Linux) or Cmd (macOS).
  # The shortcuts overlay opens on F1. The controller runs in the capture
  # phase (1L) so global shortcuts are seen before the focused editor,
  # which would otherwise consume them.
  win_keys <- gtkEventControllerKeyNew()
  gtkEventControllerSetPropagationPhase(win_keys, 1L)
  gtkWidgetAddController(window, win_keys)
  gSignalConnectR(win_keys, "key-pressed",
                  function(ctrl, keyval, keycode, modifier_state) {
                    mods <- as.integer(modifier_state)
                    accel <- bitwAnd(mods, 4L) != 0L || bitwAnd(mods, 268435456L) != 0L
                    kv <- bitwOr(keyval, 32L)  # fold to lower case

                    if (keyval == 0xffbeL) {  # F1 - shortcuts overlay
                      .wbShowShortcuts()
                      return(TRUE)
                    }
                    if (accel) {
                      hit <- TRUE
                      present <- function(nm) {
                        if (!is.null(.wb$windows[[nm]])) gtkWindowPresent(.wb$windows[[nm]])
                      }
                      if      (kv == 0x06eL) {                       # N - new tab
                        new_tab <- .wbCreateEditorTab(notebook, "Untitled")
                        tabs_env$tabs <- c(tabs_env$tabs, list(new_tab))
                      }
                      else if (kv == 0x06fL) gtkWidgetActivate(open_btn)   # O - open dialog
                      else if (kv == 0x073L) gtkWidgetActivate(save_btn)   # S - save dialog
                      else if (kv == 0x066L) {                             # F - find
                        gtkWidgetSetVisible(find_bar, TRUE)
                        gtkWidgetGrabFocus(find_entry)
                      }
                      else if (kv == 0x065L) present("Environment")        # E
                      else if (kv == 0x070L) present("Packages")           # P
                      else if (kv == 0x06cL) {                             # L - outline
                        if (!is.null(.wb$refreshOutline)) .wb$refreshOutline()
                        present("Outline")
                      }
                      else if (kv == 0x068L) {                             # H - history
                        if (!is.null(.wb$refreshHistory)) .wb$refreshHistory()
                        present("History")
                      }
                      else if (kv == 0x072L) {                             # R - run to cursor
                        tab <- active_tab()
                        if (!is.null(tab)) .wbSendToCursor(tab$buffer)
                      }
                      else if (kv == 0x064L) {                             # D - dark toggle
                        .wb$cfg$dark <- !isTRUE(.wb$cfg$dark)
                        gtkCheckButtonSetActive(dark_check, .wb$cfg$dark)
                        .wbRestyleAllEditors()
                      }
                      else hit <- FALSE
                      if (hit) return(TRUE)
                    }
                    FALSE
                  })

  window
}

# Render an R help topic to plain text. Uses the same Rd database lookup
# that ? performs, formatted with tools::Rd2txt. Rd2txt emits terminal
# overstrike codes for a pager: underline as "_\bX" and bold as "X\bX",
# where \b is a literal backspace byte. In a regex \b means word boundary,
# so the backspace must be matched as \010 (octal). Returns NULL when
# nothing matches.
.wbStripOverstrike <- function(txt) {
  prev <- ""
  while (!identical(prev, txt)) {
    prev <- txt
    txt <- gsub("_\010", "", txt)            # underline: _, BS, char
    txt <- gsub("(.)\010_", "", txt)         # underline: char, BS, _
    txt <- gsub("(.)\010\\1", "\\1", txt)    # bold: char, BS, same char
  }
  txt
}

.wbHelpText <- function(topic) {
  topic <- trimws(topic)
  if (!nzchar(topic)) return(NULL)
  paths <- tryCatch(
    utils::help((topic), help_type = "text", try.all.packages = FALSE),
    error = function(e) character(0))
  if (length(paths) == 0L) return(NULL)
  rd_file <- as.character(paths)[[1L]]
  pkg <- basename(dirname(dirname(rd_file)))
  tryCatch({
    rdb <- file.path(dirname(rd_file), pkg)
    rd <- tools:::fetchRdDB(rdb, basename(rd_file))
    txt <- utils::capture.output(
      tools::Rd2txt(rd, package = pkg, outputEncoding = "UTF-8"))
    .wbStripOverstrike(paste(txt, collapse = "\n"))
  }, error = function(e) NULL)
}

.wbHelpWindow <- function() {
  window <- gtkWindowNew()
  gtkWindowSetTitle(window, "Help - Rgtk4 Workbench")
  gtkWindowSetDefaultSize(window, 620L, 520L)
  gtkWindowAddCloseShortcut(window)
  gtkWindowSetHideOnClose(window, TRUE)

  box <- gtkBoxNew(1L, 6L)
  gtkWindowSetChild(window, box)

  bar <- gtkBoxNew(0L, 6L)
  gtkWidgetSetMarginTop(bar, 6L)
  gtkWidgetSetMarginStart(bar, 6L)
  gtkWidgetSetMarginEnd(bar, 6L)
  entry <- gtkEntryNew()
  gtkEntrySetPlaceholderText(entry, "Help topic (e.g., lm, data.frame)")
  gtkWidgetSetHexpand(entry, TRUE)
  go_btn <- gtkButtonNewWithLabel("Show Help")
  gtkBoxAppend(bar, entry)
  gtkBoxAppend(bar, go_btn)
  gtkBoxAppend(box, bar)

  view <- gtkTextViewNew()
  gtkTextViewSetMonospace(view, TRUE)
  gtkTextViewSetEditable(view, FALSE)
  gtkTextViewSetWrapMode(view, 2L)
  buffer <- gtkTextViewGetBuffer(view)
  scroll <- gtkScrolledWindowNew()
  gtkScrolledWindowSetChild(scroll, view)
  gtkScrolledWindowSetPolicy(scroll, 1L, 1L)
  gtkWidgetSetHexpand(scroll, TRUE)
  gtkWidgetSetVexpand(scroll, TRUE)
  gtkBoxAppend(box, scroll)

  show_topic <- function() {
    topic <- gtkEditableGetText(entry)
    txt <- .wbHelpText(topic)
    if (is.null(txt)) {
      txt <- sprintf("No help found for '%s'.", trimws(topic))
    }
    gtkTextBufferSetText(buffer, txt, -1L)
  }

  gSignalConnectR(go_btn, "clicked", function(w) show_topic())
  gSignalConnectR(entry, "activate", function(w) show_topic())

  .wb$showHelp <- function(topic) {
    gtkEditableSetText(entry, topic)
    show_topic()
    if (!is.null(.wb$windows$Help)) {
      gtkWindowPresent(.wb$windows$Help)
    }
  }
  window
}

#' Launch the Rgtk4 workbench
#'
#' Opens the source editor. The plot viewer appears when a plot is drawn,
#' the help browser when help is requested; the environment browser and
#' package manager open from the editor's menu. Code can be run from the
#' editor or typed at the terminal. Editor output prints to the terminal.
#'
#' @return Invisibly, an environment holding the workbench windows.
#' @export
workbenchLaunch <- function() {
  gtkInit()
  gtkStartEventLoop()
  gtkForceForeground()

  # Restore persisted settings before anything reads .wb$cfg.
  .wbLoadConfig()

  # Apply the dark-theme setting before any window is created - on macOS the
  # prefer-dark-theme hint reliably themes windows only when set up front,
  # which is what the DarkMode example does.
  gObjectSetBoolean(gtkSettingsGetDefault(),
                    "gtk-application-prefer-dark-theme",
                    isTRUE(.wb$cfg$dark))

  # All windows are constructed up front so their callbacks (.wb$capturePlot,
  # .wb$showHelp, .wb$refreshEnv) exist, but only the editor is presented.
  # The rest are shown on demand - Plots by .wbPlotsWindow's capture(),
  # Help by .wb$showHelp(), Environment and Packages from the editor menu.
  windows <- list(
    Code        = .wbCodeWindow(),
    Environment = .wbEnvironmentWindow(),
    Packages    = .wbPackagesWindow(),
    Plots       = .wbPlotsWindow(),
    Help        = .wbHelpWindow(),
    Outline     = .wbOutlineWindow(),
    History     = .wbHistoryWindow()
  )
  .wb$windows <- windows
  # Track every window for macOS dock-icon management (show on first
  # window, hide when the last closes).
  for (w in windows) gtkWindowTrack(w)
  gtkWindowPresent(windows$Code)

  # After each top-level console command: refresh the panes. If the global
  # environment had objects and now has none, the user cleared it from the
  # console - treat that as a request to end the session and shut down
  # gracefully rather than rebuilding the pane to an empty state (which is
  # also where the empty-environment crash used to happen).
  .wb$envWasPopulated <- length(ls(envir = globalenv())) > 0L
  refresh_all <- function(expr, value, ok, visible) {
    if (isTRUE(.wb$shuttingDown)) return(FALSE)
    n <- length(ls(envir = globalenv()))
    if (isTRUE(.wb$envWasPopulated) && n == 0L) {
      .wb$shuttingDown <- TRUE
      tryCatch(.wbShutdown(), error = function(e) NULL)
      return(FALSE)   # unregister this callback
    }
    .wb$envWasPopulated <- n > 0L
    tryCatch({
      if (!is.null(.wb$refreshEnv)) .wb$refreshEnv()
      if (!is.null(.wb$capturePlot)) .wb$capturePlot()
    }, error = function(e) NULL)
    TRUE
  }
  .wb$taskId <- addTaskCallback(refresh_all, name = "rgtk4_workbench")

  # A leftover autosave directory means the previous session did not exit
  # cleanly; point the user at it before this session starts overwriting.
  if (dir.exists(.wb$autosaveDir) &&
      length(list.files(.wb$autosaveDir)) > 0L) {
    message("Recovered autosave files from a previous session in:\n  ",
            .wb$autosaveDir)
  }

  # Periodic autosave of unsaved buffers every 30s, recoverable after a
  # crash from .wb$autosaveDir.
  .wb$autosaveId <- gTimeoutAdd(30000L, function() {
    tryCatch(.wbAutosave(), error = function(e) NULL)
    TRUE
  })

  # Closing the Code window - or the Environment window - ends the session.
  gSignalConnectR(windows$Code, "close-request", function(w) {
    .wbShutdown()
    FALSE
  })
  gSignalConnectR(windows$Environment, "close-request", function(w) {
    .wbShutdown()
    FALSE
  })

  invisible(.wb)
}

#' Shut down the Rgtk4 workbench
#'
#' Stops the autosave timer and refresh callback, clears the autosave
#' directory, and closes all workbench windows.
#'
#' @export
workbenchClose <- function() {
  .wbShutdown()
  invisible(NULL)
}
