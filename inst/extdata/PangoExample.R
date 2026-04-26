library(Rgtk4)
gtkInit()
gtkStartEventLoop()

# Create window
window <- gtkWindowNew()
gtkWindowSetTitle(window, "Pango Text Demo")
gtkWindowSetDefaultSize(window, 600L, 500L)

# Create scrolled box for multiple examples
scrolled <- gtkScrolledWindowNew()
box <- gtkBoxNew(1L, 20L)
gtkScrolledWindowSetChild(scrolled, box)
gtkWindowSetChild(window, scrolled)

# Example 1: Pango Markup
label1 <- gtkLabelNew("")
markup1 <- paste0(
  "<span font='24' weight='bold' foreground='#2196F3'>Pango Markup Examples</span>\n\n",
  "<span font='16'>Basic formatting: <b>bold</b>, <i>italic</i>, <u>underline</u></span>\n",
  "<span font='16'>Colors: <span foreground='red'>red</span> ",
  "<span foreground='#00AA00'>green</span> ",
  "<span foreground='blue' background='yellow'>blue on yellow</span></span>\n",
  "<span font='14' font_family='monospace' background='#f0f0f0'>  code: fn <- function(x) x + 1  </span>\n"
)
gtkLabelSetMarkup(label1, markup1)
gtkLabelSetSelectable(label1, TRUE)
gtkBoxAppend(box, label1)

# Example 2: Font variations
label2 <- gtkLabelNew("")
markup2 <- paste0(
  "<span font='20' weight='bold'>Font Weights and Styles</span>\n\n",
  "<span font='14' weight='ultralight'>Ultralight</span>  ",
  "<span font='14' weight='light'>Light</span>  ",
  "<span font='14' weight='normal'>Normal</span>  ",
  "<span font='14' weight='bold'>Bold</span>  ",
  "<span font='14' weight='ultrabold'>Ultrabold</span>  ",
  "<span font='14' weight='heavy'>Heavy</span>\n",
  "<span font='14' style='normal'>Normal</span>  ",
  "<span font='14' style='italic'>Italic</span>  ",
  "<span font='14' style='oblique'>Oblique</span>"
)
gtkLabelSetMarkup(label2, markup2)
gtkBoxAppend(box, label2)

# Example 3: Text decorations
label3 <- gtkLabelNew("")
markup3 <- paste0(
  "<span font='20' weight='bold'>Text Decorations</span>\n\n",
  "<span font='16' underline='single'>Single underline</span>\n",
  "<span font='16' underline='double'>Double underline</span>\n",
  "<span font='16' underline='error'>Error underline</span>\n",
  "<span font='16' strikethrough='true'>Strikethrough text</span>\n",
  "<span font='16' overline='single'>Overline text</span>"
)
gtkLabelSetMarkup(label3, markup3)
gtkBoxAppend(box, label3)

# Example 4: Superscript and subscript
label4 <- gtkLabelNew("")
markup4 <- paste0(
  "<span font='20' weight='bold'>Super and Subscript</span>\n\n",
  "<span font='16'>E = mc<span rise='5000' size='small'>2</span></span>\n",
  "<span font='16'>H<span rise='-5000' size='small'>2</span>O</span>\n",
  "<span font='16'>x<span rise='5000' size='small'>n</span> + x<span rise='5000' size='small'>n-1</span></span>"
)
gtkLabelSetMarkup(label4, markup4)
gtkBoxAppend(box, label4)

# Example 5: Letter spacing and sizes
label5 <- gtkLabelNew("")
markup5 <- paste0(
  "<span font='20' weight='bold'>Spacing and Sizes</span>\n\n",
  "<span font='16' letter_spacing='1000'>S p a c e d   t e x t</span>\n",
  "<span size='xx-small'>xx-small</span>  ",
  "<span size='x-small'>x-small</span>  ",
  "<span size='small'>small</span>  ",
  "<span size='medium'>medium</span>  ",
  "<span size='large'>large</span>  ",
  "<span size='x-large'>x-large</span>  ",
  "<span size='xx-large'>xx-large</span>"
)
gtkLabelSetMarkup(label5, markup5)
gtkBoxAppend(box, label5)

# Example 6: Font families
label6 <- gtkLabelNew("")
markup6 <- paste0(
  "<span font='20' weight='bold'>Font Families</span>\n\n",
  "<span font='14' font_family='sans'>Sans-serif font</span>\n",
  "<span font='14' font_family='serif'>Serif font</span>\n",
  "<span font='14' font_family='monospace'>Monospace font</span>\n",
  "<span font='14' font_family='cursive'>Cursive font</span>"
)
gtkLabelSetMarkup(label6, markup6)
gtkBoxAppend(box, label6)

# Example 7: Programmatic attributes (without markup)
label7 <- gtkLabelNew("Programmatic Pango Attributes")

# This would need the Pango attribute functions to be generated
# For now, just show it's possible
gtkBoxAppend(box, label7)

# Show window
gtkWindowPresent(window)
gtkWindowTrack(window)

cat("Pango markup demo ready!\n")
cat("All examples use Pango markup tags\n")
cat("Scroll to see all formatting options\n")
