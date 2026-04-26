library(Rgtk4)

# Initialize
gtkInit()
gtkStartEventLoop()

# 1. Create the Dialog Window
dialog <- gtkWindowNew()
gtkWindowSetTitle(dialog, "Confirmation")
gtkWindowSetModal(dialog, TRUE)
gtkWindowSetDefaultSize(dialog, 350L, 200L)

# 2. Main Layout
main_box <- gtkBoxNew(1L, 15L) # Vertical
gtkWidgetSetMarginStart(main_box, 20L)
gtkWidgetSetMarginEnd(main_box, 20L)
gtkWidgetSetMarginTop(main_box, 20L)
gtkWidgetSetMarginBottom(main_box, 20L)
gtkWindowSetChild(dialog, main_box)

# 3. Content Area
content_box <- gtkBoxNew(0L, 15L)
gtkBoxAppend(main_box, content_box)

# 'dialog-warning-symbolic' usually renders as the triangular alert sign
image <- gtkImageNewFromIconName("dialog-warning-symbolic")
gtkWidgetSetSizeRequest(image, 48L, 48L)
gtkBoxAppend(content_box, image)

label <- gtkLabelNew("Please select an option:")
gtkBoxAppend(content_box, label)

# 4. Radio Button Group
radio_box <- gtkBoxNew(1L, 5L) # Vertical box for radios
gtkBoxAppend(main_box, radio_box)

# Create the first button
rb_yes <- gtkCheckButtonNewWithLabel("Yes")
gtkBoxAppend(radio_box, rb_yes)

# Create the others and group them to the first one
rb_no <- gtkCheckButtonNewWithLabel("No")
gtkCheckButtonSetGroup(rb_no, rb_yes)
gtkBoxAppend(radio_box, rb_no)

rb_maybe <- gtkCheckButtonNewWithLabel("Maybe later")
gtkCheckButtonSetGroup(rb_maybe, rb_yes)
gtkBoxAppend(radio_box, rb_maybe)

# 5. Action Area (Confirm Button)
button_box <- gtkBoxNew(0L, 10L)
gtkWidgetSetHalign(button_box, 3L)
gtkBoxAppend(main_box, button_box)

create_colored_button <- function(label_text, color_class) {
  btn <- gtkButtonNew()
  btn_content <- gtkBoxNew(0L, 8L)
  dot_icon <- gtkImageNewFromIconName("media-record-symbolic")
  gtkWidgetSetSizeRequest(dot_icon, 12L, 12L)

  # Apply color class to the icon
  context <- gtkWidgetGetStyleContext(dot_icon)
  gtkStyleContextAddClass(context, color_class)

  btn_label <- gtkLabelNew(label_text)
  gtkBoxAppend(btn_content, dot_icon)
  gtkBoxAppend(btn_content, btn_label)
  gtkButtonSetChild(btn, btn_content)

  return(list(button = btn, icon = dot_icon))
}

# Submit button with a Forest Green dot
submit_item <- create_colored_button("Confirm", "green-dot")
gtkBoxAppend(button_box, submit_item$button)

# 6. CSS
css_provider <- gtkCssProviderNew()
css_data <- "
  .green-dot { color: #228B22; }
"
gtkCssProviderLoadFromData(css_provider, css_data, -1.0)
gtkStyleContextAddProviderForDisplay(gdkDisplayGetDefault(), css_provider, 800L)

# 7. Signal for the Submit Button
gSignalConnectR(submit_item$button, "clicked", function(w) {
  if (gtkCheckButtonGetActive(rb_yes)) {
    print("Selected: Yes")
  } else if (gtkCheckButtonGetActive(rb_no)) {
    print("Selected: No")
  } else {
    print("Selected: Maybe later")
  }
  gtkWindowDestroy(dialog)
})

gtkWindowPresent(dialog)
