library(Rgtk4)

# Shared plot/image dimensions
PLOT_WIDTH <- 800L
PLOT_HEIGHT <- 500L

user_messages <- character(0)
plot_zoom <- 1.0
live_zoom <- 1.0
note_text <- ""

gtkInit()
gtkStartEventLoop()

window <- gtkWindowNew()
gtkWindowSetTitle(window, "RGtk4 - Advanced Demo")
gtkWindowSetDefaultSize(window, 1100L, 850L)
gtkWindowSetResizable(window, TRUE)

# Track this window for dock management
gtkWindowTrack(window)

# Make window properly decorated and movable
gtkWindowSetDecorated(window, TRUE)
gtkWindowSetDeletable(window, TRUE)

# These settings help with window manager integration
gtkWindowSetModal(window, FALSE)
gtkWindowSetHideOnClose(window, FALSE)

# Add keyboard shortcut to close window (Ctrl+W on Windows/Linux, Cmd+W on macOS)
gtkWindowAddCloseShortcut(window)

main_vbox <- gtkBoxNew(1L, 0L)
gtkWindowSetChild(window, main_vbox)

# === MENU BAR ===
menu_bar <- gtkBoxNew(0L, 6L)
gtkWidgetSetMarginStart(menu_bar, 10L)
gtkWidgetSetMarginEnd(menu_bar, 10L)
gtkWidgetSetMarginTop(menu_bar, 6L)
gtkWidgetSetMarginBottom(menu_bar, 6L)
gtkBoxAppend(main_vbox, menu_bar)

file_btn <- gtkMenuButtonNew()
gtkMenuButtonSetLabel(file_btn, "File")
gtkBoxAppend(menu_bar, file_btn)

help_btn <- gtkMenuButtonNew()
gtkMenuButtonSetLabel(help_btn, "Help")
gtkBoxAppend(menu_bar, help_btn)

# Create Help menu popover
help_popover <- gtkPopoverNew()
gtkMenuButtonSetPopover(help_btn, help_popover)

help_box <- gtkBoxNew(1L, 6L)
gtkWidgetSetMarginTop(help_box, 10L)
gtkWidgetSetMarginBottom(help_box, 10L)
gtkWidgetSetMarginStart(help_box, 10L)
gtkWidgetSetMarginEnd(help_box, 10L)
gtkPopoverSetChild(help_popover, help_box)

about_btn <- gtkButtonNew()
gtkButtonSetLabel(about_btn, "About")
gtkBoxAppend(help_box, about_btn)

gSignalConnectR(about_btn, "clicked", function(w) {
  # Get GTK version
  gtk_major <- gtkGetMajorVersion()
  gtk_minor <- gtkGetMinorVersion()
  gtk_micro <- gtkGetMicroVersion()

  about_dialog <- gtkWindowNew()
  gtkWindowSetTitle(about_dialog, "About RGtk4 Demo")
  gtkWindowSetDefaultSize(about_dialog, 400L, 300L)
  gtkWindowSetModal(about_dialog, TRUE)
  gtkWindowSetTransientFor(about_dialog, window)

  about_box <- gtkBoxNew(1L, 12L)
  gtkWidgetSetMarginTop(about_box, 20L)
  gtkWidgetSetMarginBottom(about_box, 20L)
  gtkWidgetSetMarginStart(about_box, 20L)
  gtkWidgetSetMarginEnd(about_box, 20L)
  gtkWindowSetChild(about_dialog, about_box)

  title_lbl <- gtkLabelNew("")
  gtkLabelSetMarkup(title_lbl, "<span size=\"x-large\" weight=\"bold\">RGtk4 Demo</span>")
  gtkBoxAppend(about_box, title_lbl)

  version_lbl <- gtkLabelNew("")
  gtkLabelSetMarkup(version_lbl, sprintf("<span size=\"large\">Version 0.1.0</span>"))
  gtkBoxAppend(about_box, version_lbl)

  gtkBoxAppend(about_box, gtkSeparatorNew(0L))

  gtk_version_lbl <- gtkLabelNew("")
  gtk_version_text <- sprintf("GTK Version: %d.%d.%d", gtk_major, gtk_minor, gtk_micro)
  gtkLabelSetMarkup(gtk_version_lbl, sprintf("<span font=\"monospace\">%s</span>", gtk_version_text))
  gtkBoxAppend(about_box, gtk_version_lbl)

  gtkBoxAppend(about_box, gtkSeparatorNew(0L))

  info_lbl <- gtkLabelNew("GTK4 bindings for R\nwith macOS integration")
  gtkBoxAppend(about_box, info_lbl)

  close_btn <- gtkButtonNew()
  gtkButtonSetLabel(close_btn, "Close")
  gtkBoxAppend(about_box, close_btn)

  gSignalConnectR(close_btn, "clicked", function(w) {
    gtkWindowDestroy(about_dialog)
  })

  gtkWindowPresent(about_dialog)
  gtkPopoverPopdown(help_popover)
})

gtkBoxAppend(main_vbox, gtkSeparatorNew(0L))

# === NOTEBOOK (TABS) ===
notebook <- gtkNotebookNew()
gtkNotebookSetScrollable(notebook, TRUE)
gtkWidgetSetVexpand(notebook, TRUE)
gtkBoxAppend(main_vbox, notebook)

# ============ TAB 1: Welcome with SVG ============
tab1_scroll <- gtkScrolledWindowNew()
gtkScrolledWindowSetPolicy(tab1_scroll, 1L, 1L)

tab1_box <- gtkBoxNew(1L, 20L)
gtkWidgetSetMarginTop(tab1_box, 40L)
gtkWidgetSetMarginBottom(tab1_box, 40L)
gtkWidgetSetMarginStart(tab1_box, 40L)
gtkWidgetSetMarginEnd(tab1_box, 40L)
gtkScrolledWindowSetChild(tab1_scroll, tab1_box)

tab1_label <- gtkLabelNew("🏠 Welcome")
gtkNotebookAppendPage(notebook, tab1_scroll, tab1_label)

title <- gtkLabelNew("")
gtkLabelSetMarkup(title, "<span size=\"xx-large\" weight=\"bold\">Welcome to RGtk4</span>")
gtkBoxAppend(tab1_box, title)

subtitle <- gtkLabelNew("Interactive GTK4 bindings for R with advanced graphics")
gtkBoxAppend(tab1_box, subtitle)

gtkBoxAppend(tab1_box, gtkSeparatorNew(0L))

# Create fancy SVG graphic
svg_file <- tempfile(fileext = ".svg")
svg_code <- sprintf('<?xml version="1.0" encoding="UTF-8"?>
<svg width="%d" height="%d" xmlns="http://www.w3.org/2000/svg">
  <defs>
    <linearGradient id="grad1" x1="0%%" y1="0%%" x2="100%%" y2="100%%">
      <stop offset="0%%" style="stop-color:rgb(59,130,246);stop-opacity:1" />
      <stop offset="100%%" style="stop-color:rgb(147,51,234);stop-opacity:1" />
    </linearGradient>
  </defs>

  <rect width="%d" height="%d" fill="url(#grad1)" rx="20"/>

  <circle cx="150" cy="250" r="80" fill="rgba(255,255,255,0.3)">
    <animate attributeName="r" values="80;100;80" dur="2s" repeatCount="indefinite"/>
  </circle>

  <circle cx="400" cy="250" r="70" fill="rgba(255,255,255,0.4)">
    <animate attributeName="cy" values="250;220;250" dur="3s" repeatCount="indefinite"/>
  </circle>

  <circle cx="650" cy="250" r="75" fill="rgba(255,255,255,0.35)">
    <animate attributeName="r" values="75;90;75" dur="2.5s" repeatCount="indefinite"/>
  </circle>

  <text x="400" y="350" font-size="48" font-weight="bold" fill="white" text-anchor="middle">
    RGtk4 Demo
  </text>

  <text x="400" y="400" font-size="24" fill="rgba(255,255,255,0.9)" text-anchor="middle">
    Interactive GTK4 for R
  </text>
</svg>', PLOT_WIDTH, PLOT_HEIGHT, PLOT_WIDTH, PLOT_HEIGHT)

writeLines(svg_code, svg_file)

svg_center_box <- gtkBoxNew(1L, 0L)
gtkWidgetSetHalign(svg_center_box, 3L)
gtkBoxAppend(tab1_box, svg_center_box)

svg_img <- gtkImageNewFromFile(svg_file)
gtkWidgetSetSizeRequest(svg_img, PLOT_WIDTH, PLOT_HEIGHT)
gtkImageSetPixelSize(svg_img, PLOT_WIDTH)
gtkBoxAppend(svg_center_box, svg_img)

features_label <- gtkLabelNew("")
gtkLabelSetMarkup(features_label,
                  "<span size=\"large\">Features:\n\n✓ Animated SVG graphics\n✓ Zoomable plots\n✓ Live plot capture\n✓ Markdown notes\n✓ Simulation with progress</span>")
gtkBoxAppend(tab1_box, features_label)

# ============ TAB 2: Zoomable Plots ============
tab2_scroll <- gtkScrolledWindowNew()
gtkScrolledWindowSetPolicy(tab2_scroll, 1L, 1L)

tab2_box <- gtkBoxNew(1L, 12L)
gtkWidgetSetMarginTop(tab2_box, 20L)
gtkWidgetSetMarginBottom(tab2_box, 20L)
gtkWidgetSetMarginStart(tab2_box, 20L)
gtkWidgetSetMarginEnd(tab2_box, 20L)
gtkScrolledWindowSetChild(tab2_scroll, tab2_box)

tab2_label <- gtkLabelNew("📊 Plots")
gtkNotebookAppendPage(notebook, tab2_scroll, tab2_label)

plot_title <- gtkLabelNew("")
gtkLabelSetMarkup(plot_title, "<span size=\"x-large\" weight=\"bold\">Zoomable R Plots</span>")
gtkBoxAppend(tab2_box, plot_title)

gtkBoxAppend(tab2_box, gtkSeparatorNew(0L))

# Zoom slider
zoom_label <- gtkLabelNew("Zoom: 100%")
gtkBoxAppend(tab2_box, zoom_label)

zoom_slider <- gtkScaleNewWithRange(0L, 0.5, 2.0, 0.1)
gtkRangeSetValue(zoom_slider, 1.0)
gtkWidgetSetSizeRequest(zoom_slider, 400L, -1L)
gtkScaleSetDrawValue(zoom_slider, TRUE)
gtkBoxAppend(tab2_box, zoom_slider)

plot_container <- gtkBoxNew(1L, 0L)
gtkWidgetSetHalign(plot_container, 3L)
gtkBoxAppend(tab2_box, plot_container)

temp_plot <- tempfile(fileext = ".png")

plot_img <- gtkImageNew()
gtkWidgetSetSizeRequest(plot_img, PLOT_WIDTH, PLOT_HEIGHT)
gtkImageSetPixelSize(plot_img, PLOT_WIDTH)
gtkBoxAppend(plot_container, plot_img)

# Radio buttons
r1 <- gtkCheckButtonNewWithLabel("📈 Sine Wave")
gtkCheckButtonSetActive(r1, TRUE)
gtkBoxAppend(tab2_box, r1)

r2 <- gtkCheckButtonNewWithLabel("🔵 Scatter")
gtkCheckButtonSetGroup(r2, r1)
gtkBoxAppend(tab2_box, r2)

r3 <- gtkCheckButtonNewWithLabel("📊 Histogram")
gtkCheckButtonSetGroup(r3, r1)
gtkBoxAppend(tab2_box, r3)

r4 <- gtkCheckButtonNewWithLabel("📦 Boxplot")
gtkCheckButtonSetGroup(r4, r1)
gtkBoxAppend(tab2_box, r4)

update_plot_zoom <- function() {
  width <- as.integer(PLOT_WIDTH * plot_zoom)
  height <- as.integer(PLOT_HEIGHT * plot_zoom)

  png(temp_plot, width = width, height = height, res = 96)
  par(mar = c(4,4,3,1))

  if (gtkCheckButtonGetActive(r1)) {
    x <- seq(0, 2*pi, length.out = 100)
    plot(x, sin(x), type = "l", col = "blue", lwd = 3,
         main = "Sine Wave", xlab = "x", ylab = "sin(x)")
    grid()
  } else if (gtkCheckButtonGetActive(r2)) {
    plot(runif(100), runif(100), col = rainbow(100), pch = 19, cex = 2,
         main = "Random Scatter", xlab = "X", ylab = "Y")
  } else if (gtkCheckButtonGetActive(r3)) {
    hist(rnorm(1000), col = "lightblue", border = "white",
         main = "Normal Distribution", xlab = "Value", breaks = 40)
  } else {
    boxplot(list(A = rnorm(100), B = rnorm(100, 1), C = rnorm(100, 2)),
            col = c("red", "green", "blue"), main = "Boxplot")
  }

  dev.off()

  gtkImageSetFromFile(plot_img, temp_plot)
  gtkWidgetSetSizeRequest(plot_img, width, height)
  gtkImageSetPixelSize(plot_img, width)
}

update_plot_zoom()

gSignalConnectR(zoom_slider, "value-changed", function(w) {
  plot_zoom <<- gtkRangeGetValue(zoom_slider)
  gtkLabelSetText(zoom_label, sprintf("Zoom: %d%%", as.integer(plot_zoom * 100)))
  update_plot_zoom()
})

for (radio in list(r1, r2, r3, r4)) {
  gSignalConnectR(radio, "toggled", function(w) {
    update_plot_zoom()
  })
}

# ============ TAB 3: Live Capture ============
tab3_scroll <- gtkScrolledWindowNew()
gtkScrolledWindowSetPolicy(tab3_scroll, 1L, 1L)

tab3_box <- gtkBoxNew(1L, 12L)
gtkWidgetSetMarginTop(tab3_box, 20L)
gtkWidgetSetMarginBottom(tab3_box, 20L)
gtkWidgetSetMarginStart(tab3_box, 20L)
gtkWidgetSetMarginEnd(tab3_box, 20L)
gtkScrolledWindowSetChild(tab3_scroll, tab3_box)

tab3_label <- gtkLabelNew("📸 Capture")
gtkNotebookAppendPage(notebook, tab3_scroll, tab3_label)

live_title <- gtkLabelNew("")
gtkLabelSetMarkup(live_title, "<span size=\"x-large\" weight=\"bold\">Live R Plot Capture</span>")
gtkBoxAppend(tab3_box, live_title)

gtkBoxAppend(tab3_box, gtkSeparatorNew(0L))

live_zoom_label <- gtkLabelNew("Size: 100%")
gtkBoxAppend(tab3_box, live_zoom_label)

live_zoom_slider <- gtkScaleNewWithRange(0L, 0.5, 2.0, 0.1)
gtkRangeSetValue(live_zoom_slider, 1.0)
gtkWidgetSetSizeRequest(live_zoom_slider, 400L, -1L)
gtkBoxAppend(tab3_box, live_zoom_slider)

live_container <- gtkBoxNew(1L, 0L)
gtkWidgetSetHalign(live_container, 3L)
gtkBoxAppend(tab3_box, live_container)

temp_live <- tempfile(fileext = ".png")
png(temp_live, width = PLOT_WIDTH, height = PLOT_HEIGHT)
plot.new()
text(0.5, 0.5, "No plot yet\n\nTry: plot(cars)", cex = 2)
dev.off()

live_img <- gtkImageNewFromFile(temp_live)
gtkWidgetSetSizeRequest(live_img, PLOT_WIDTH, PLOT_HEIGHT)
gtkImageSetPixelSize(live_img, PLOT_WIDTH)
gtkBoxAppend(live_container, live_img)

capture_btn <- gtkButtonNewWithLabel("📸 Capture Current R Plot")
gtkBoxAppend(tab3_box, capture_btn)

gSignalConnectR(capture_btn, "clicked", function(w) {
  tryCatch({
    width <- as.integer(PLOT_WIDTH * live_zoom)
    height <- as.integer(PLOT_HEIGHT * live_zoom)

    dev.copy(png, temp_live, width = width, height = height, res = 96)
    dev.off()

    gtkImageSetFromFile(live_img, temp_live)
    gtkWidgetSetSizeRequest(live_img, width, height)
    gtkImageSetPixelSize(live_img, width)

    message("✓ Captured!")
  }, error = function(e) {
    message("✗ No plot. Try: plot(cars)")
  })
})

gSignalConnectR(live_zoom_slider, "value-changed", function(w) {
  live_zoom <<- gtkRangeGetValue(live_zoom_slider)
  gtkLabelSetText(live_zoom_label, sprintf("Size: %d%%", as.integer(live_zoom * 100)))
})

example_btn <- gtkButtonNewWithLabel("▶ Run Example")
gtkBoxAppend(tab3_box, example_btn)

gSignalConnectR(example_btn, "clicked", function(w) {
  width <- as.integer(PLOT_WIDTH * live_zoom)
  height <- as.integer(PLOT_HEIGHT * live_zoom)

  plot(pressure, main = "Pressure vs Temperature",
       col = "darkred", pch = 19, cex = 2)

  dev.copy(png, temp_live, width = width, height = height, res = 96)
  dev.off()

  gtkImageSetFromFile(live_img, temp_live)
  gtkWidgetSetSizeRequest(live_img, width, height)
  gtkImageSetPixelSize(live_img, width)
})

# ============ TAB 4: Simulation ============
tab4_box <- gtkBoxNew(1L, 12L)
gtkWidgetSetMarginTop(tab4_box, 20L)
gtkWidgetSetMarginBottom(tab4_box, 20L)
gtkWidgetSetMarginStart(tab4_box, 20L)
gtkWidgetSetMarginEnd(tab4_box, 20L)

tab4_label <- gtkLabelNew("⚙️ Simulation")
gtkNotebookAppendPage(notebook, tab4_box, tab4_label)

sim_title <- gtkLabelNew("")
gtkLabelSetMarkup(sim_title, "<span size=\"x-large\" weight=\"bold\">Run Simulation</span>")
gtkBoxAppend(tab4_box, sim_title)

gtkBoxAppend(tab4_box, gtkSeparatorNew(0L))

sim_desc <- gtkLabelNew("Configure and run a simulation with progress tracking")
gtkBoxAppend(tab4_box, sim_desc)

# Simulation parameters
param_label <- gtkLabelNew("Number of iterations:")
gtkWidgetSetHalign(param_label, 1L)
gtkBoxAppend(tab4_box, param_label)

iter_slider <- gtkScaleNewWithRange(0L, 10, 100, 10)
gtkRangeSetValue(iter_slider, 50)
gtkScaleSetDrawValue(iter_slider, TRUE)
gtkBoxAppend(tab4_box, iter_slider)

# Checkboxes
check_verbose <- gtkCheckButtonNewWithLabel("Verbose output")
gtkCheckButtonSetActive(check_verbose, TRUE)
gtkBoxAppend(tab4_box, check_verbose)

check_plot <- gtkCheckButtonNewWithLabel("Generate plot at end")
gtkBoxAppend(tab4_box, check_plot)

gtkBoxAppend(tab4_box, gtkSeparatorNew(0L))

# Progress bar
progress_label <- gtkLabelNew("Progress:")
gtkWidgetSetHalign(progress_label, 1L)
gtkBoxAppend(tab4_box, progress_label)

progress <- gtkProgressBarNew()
gtkProgressBarSetShowText(progress, TRUE)
gtkProgressBarSetFraction(progress, 0.0)
gtkProgressBarSetText(progress, "Ready")
gtkBoxAppend(tab4_box, progress)

sim_btn <- gtkButtonNewWithLabel("▶ Run Simulation")
gtkBoxAppend(tab4_box, sim_btn)

gSignalConnectR(sim_btn, "clicked", function(w) {
  verbose <- gtkCheckButtonGetActive(check_verbose)
  iterations <- as.integer(gtkRangeGetValue(iter_slider))

  if (verbose) message("Starting simulation with ", iterations, " iterations...")

  for (i in 1:iterations) {
    Sys.sleep(0.05)
    frac <- i / iterations
    gtkProgressBarSetFraction(progress, frac)
    gtkProgressBarSetText(progress, sprintf("%d/%d", i, iterations))
    while (gMainContextIteration(NULL, FALSE)) {}
  }

  gtkProgressBarSetText(progress, "Complete!")

  if (gtkCheckButtonGetActive(check_plot)) {
    # Switch to plot tab and show result
    plot(cumsum(rnorm(iterations)), type = "l",
         main = "Simulation Result", col = "blue", lwd = 2)
  }

  if (verbose) message("Simulation complete!")
})

# ============ TAB 5: Markdown Notes ============
tab5_box <- gtkBoxNew(1L, 12L)
gtkWidgetSetMarginTop(tab5_box, 20L)
gtkWidgetSetMarginBottom(tab5_box, 20L)
gtkWidgetSetMarginStart(tab5_box, 20L)
gtkWidgetSetMarginEnd(tab5_box, 20L)

tab5_label <- gtkLabelNew("📝 Notes")
gtkNotebookAppendPage(notebook, tab5_box, tab5_label)

notes_title <- gtkLabelNew("")
gtkLabelSetMarkup(notes_title, "<span size=\"x-large\" weight=\"bold\">Markdown Notes</span>")
gtkBoxAppend(tab5_box, notes_title)

notes_desc <- gtkLabelNew("Enter text with basic Markdown formatting")
gtkBoxAppend(tab5_box, notes_desc)

gtkBoxAppend(tab5_box, gtkSeparatorNew(0L))

# Text input
text_scroll <- gtkScrolledWindowNew()
gtkScrolledWindowSetPolicy(text_scroll, 1L, 1L)
gtkWidgetSetVexpand(text_scroll, TRUE)
gtkWidgetSetSizeRequest(text_scroll, -1L, 200L)
gtkBoxAppend(tab5_box, text_scroll)

text_view <- gtkTextViewNew()
gtkTextViewSetWrapMode(text_view, 2L)  # Word wrap
gtkScrolledWindowSetChild(text_scroll, text_view)

text_buffer <- gtkTextViewGetBuffer(text_view)

# Render button
render_btn <- gtkButtonNewWithLabel("🔄 Render Preview")
gtkBoxAppend(tab5_box, render_btn)

gtkBoxAppend(tab5_box, gtkSeparatorNew(0L))

# Preview area
preview_label <- gtkLabelNew("Preview:")
gtkWidgetSetHalign(preview_label, 1L)
gtkBoxAppend(tab5_box, preview_label)

preview_scroll <- gtkScrolledWindowNew()
gtkScrolledWindowSetPolicy(preview_scroll, 1L, 1L)
gtkWidgetSetVexpand(preview_scroll, TRUE)
gtkBoxAppend(tab5_box, preview_scroll)

preview_text <- gtkLabelNew("Your formatted text will appear here...")
gtkLabelSetWrap(preview_text, TRUE)
gtkWidgetSetHalign(preview_text, 1L)
gtkScrolledWindowSetChild(preview_scroll, preview_text)

# Note: Getting text from GtkTextBuffer requires a C helper
# For demo, we'll use a simple approach
gSignalConnectR(render_btn, "clicked", function(w) {
  # In a real implementation, you'd extract text from buffer
  # For now, show a formatted example
  example_text <- "<b>Example Note</b>\n\nThis would show your formatted text.\nIn a full implementation, we'd parse Markdown:\n\n• <b>Bold</b> text\n• <i>Italic</i> text\n• Lists and more"
  gtkLabelSetMarkup(preview_text, example_text)
  message("Preview updated!")
})

# Present window
gtkWindowPresent(window)

cat("\n✨ Full demo launched!\n")
cat("All plots and images use consistent ", PLOT_WIDTH, "x", PLOT_HEIGHT, " size\n\n")

invisible(window)
