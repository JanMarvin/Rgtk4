library(Rgtk4)

# Initialize
gtkInit()
gtkStartEventLoop()

# 1. Create the Dialog Window
dialog <- gtkWindowNew()
gtkWindowSetTitle(dialog, "Confirmation")
gtkWindowSetModal(dialog, TRUE)
gtkWindowSetDefaultSize(dialog, 300L, 150L)

# 2. Main Layout
main_box <- gtkBoxNew(1L, 15L) # Vertical
gtkWidgetSetMarginStart(main_box, 20L)
gtkWidgetSetMarginEnd(main_box, 20L)
gtkWidgetSetMarginTop(main_box, 20L)
gtkWidgetSetMarginBottom(main_box, 20L)
gtkWindowSetChild(dialog, main_box)

# 3. Content Area
content_box <- gtkBoxNew(0L, 15L) # Horizontal
gtkBoxAppend(main_box, content_box)

# Use 'dialog-question' without the '-symbolic' suffix.
# This typically renders as the classic Glade/GTK yellow alert sign.
image <- gtkImageNewFromIconName("dialog-question")
gtkWidgetSetSizeRequest(image, 64L, 64L) # Slightly larger to show the 'sign' detail
gtkBoxAppend(content_box, image)

label <- gtkLabelNew("Would you like to proceed?")
gtkBoxAppend(content_box, label)

# 4. Action Area
button_box <- gtkBoxNew(0L, 10L)
gtkWidgetSetHalign(button_box, 3L)
gtkBoxAppend(main_box, button_box)

create_colored_button <- function(label_text) {
  btn <- gtkButtonNew()
  btn_content <- gtkBoxNew(0L, 8L)

  # Keeping the dots as requested
  dot_icon <- gtkImageNewFromIconName("media-record-symbolic")
  gtkWidgetSetSizeRequest(dot_icon, 12L, 12L)

  btn_label <- gtkLabelNew(label_text)
  gtkBoxAppend(btn_content, dot_icon)
  gtkBoxAppend(btn_content, btn_label)
  gtkButtonSetChild(btn, btn_content)

  return(list(button = btn, icon = dot_icon))
}

yes_item <- create_colored_button("Yes")
no_item  <- create_colored_button("No")

gtkBoxAppend(button_box, yes_item$button)
gtkBoxAppend(button_box, no_item$button)

# 5. CSS (Toned down Forest Green)
css_provider <- gtkCssProviderNew()
css_data <- "
  .green-dot { color: #228B22; }
  .red-dot { color: #cc0000; }
"
gtkCssProviderLoadFromData(css_provider, css_data, -1.0)

context_yes <- gtkWidgetGetStyleContext(yes_item$icon)
gtkStyleContextAddProvider(context_yes, css_provider, 800L)
gtkStyleContextAddClass(context_yes, "green-dot")

context_no <- gtkWidgetGetStyleContext(no_item$icon)
gtkStyleContextAddProvider(context_no, css_provider, 800L)
gtkStyleContextAddClass(context_no, "red-dot")

# 6. Signals
gSignalConnectR(yes_item$button, "clicked", function(w) {
  print("Confirmed: Yes")
  gtkWindowDestroy(dialog)
})

gSignalConnectR(no_item$button, "clicked", function(w) {
  print("Confirmed: No")
  gtkWindowDestroy(dialog)
})

gtkWindowPresent(dialog)
