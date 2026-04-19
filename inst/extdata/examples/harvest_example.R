# Data Harvest Example - RGtk4
# Demonstrates collecting structured data through a GUI form

library(Rgtk4)

# Initialize GTK
gtkInit()
gtkStartEventLoop()

# Create main window
window <- gtkWindowNew()
gtkWindowSetTitle(window, "Data Harvest - RGtk4")
gtkWindowSetDefaultSize(window, 500L, 400L)
gtkWindowAddCloseShortcut(window)  # Ctrl+W (Cmd+W on macOS)

# Main container
main_box <- gtkBoxNew(1L, 10L)
gtkWidgetSetMarginTop(main_box, 15L)
gtkWidgetSetMarginBottom(main_box, 15L)
gtkWidgetSetMarginStart(main_box, 15L)
gtkWidgetSetMarginEnd(main_box, 15L)
gtkWindowSetChild(window, main_box)

# Title
title_lbl <- gtkLabelNew("")
gtkLabelSetMarkup(title_lbl, "<span size=\"x-large\" weight=\"bold\">User Registration Form</span>")
gtkBoxAppend(main_box, title_lbl)

gtkBoxAppend(main_box, gtkSeparatorNew(0L))

# Name field
name_box <- gtkBoxNew(0L, 5L)  # Horizontal
name_lbl <- gtkLabelNew("Name:")
gtkWidgetSetSizeRequest(name_lbl, 100L, -1L)
gtkWidgetSetHalign(name_lbl, 1L)  # START
gtkBoxAppend(name_box, name_lbl)

name_entry <- gtkEntryNew()
gtkWidgetSetHexpand(name_entry, TRUE)
gtkBoxAppend(name_box, name_entry)
gtkBoxAppend(main_box, name_box)

# Email field
email_box <- gtkBoxNew(0L, 5L)
email_lbl <- gtkLabelNew("Email:")
gtkWidgetSetSizeRequest(email_lbl, 100L, -1L)
gtkWidgetSetHalign(email_lbl, 1L)
gtkBoxAppend(email_box, email_lbl)

email_entry <- gtkEntryNew()
gtkWidgetSetHexpand(email_entry, TRUE)
gtkBoxAppend(email_box, email_entry)
gtkBoxAppend(main_box, email_box)

# Age field
age_box <- gtkBoxNew(0L, 5L)
age_lbl <- gtkLabelNew("Age:")
gtkWidgetSetSizeRequest(age_lbl, 100L, -1L)
gtkWidgetSetHalign(age_lbl, 1L)
gtkBoxAppend(age_box, age_lbl)

age_spin <- gtkSpinButtonNewWithRange(1, 120, 1)
gtkSpinButtonSetValue(age_spin, 25)
gtkBoxAppend(age_box, age_spin)
gtkBoxAppend(main_box, age_box)

# Country dropdown
country_box <- gtkBoxNew(0L, 5L)
country_lbl <- gtkLabelNew("Country:")
gtkWidgetSetSizeRequest(country_lbl, 100L, -1L)
gtkWidgetSetHalign(country_lbl, 1L)
gtkBoxAppend(country_box, country_lbl)

countries <- c("USA", "Canada", "UK", "Germany", "France", "Japan", "Australia", "Other")
country_dropdown <- gtkDropDownNew(gtkStringListFromVector(countries), NULL)
gtkBoxAppend(country_box, country_dropdown)
gtkBoxAppend(main_box, country_box)

# Newsletter checkbox
newsletter_check <- gtkCheckButtonNew()
gtkCheckButtonSetLabel(newsletter_check, "Subscribe to newsletter")
gtkCheckButtonSetActive(newsletter_check, TRUE)
gtkBoxAppend(main_box, newsletter_check)

gtkBoxAppend(main_box, gtkSeparatorNew(0L))

# Submit button
submit_btn <- gtkButtonNew()
gtkButtonSetLabel(submit_btn, "Submit Registration")
gtkBoxAppend(main_box, submit_btn)

# Results display
results_label <- gtkLabelNew("")
gtkLabelSetWrapMode(results_label, 2L)  # WORD
gtkBoxAppend(main_box, results_label)

# Handle submit
gSignalConnectR(submit_btn, "clicked", function(w) {
  # Collect data using gtkGetUiState
  state <- gtkGetUiState(list(
    name = name_entry,
    email = email_entry,
    age = age_spin,
    country = country_dropdown,
    newsletter = newsletter_check
  ))

  # Build results
  name_val <- state$name$text
  email_val <- state$email$text
  age_val <- state$age$value
  country_val <- countries[state$country$selected + 1]
  newsletter_val <- state$newsletter$active

  # Display in label
  result_text <- sprintf(
    "<b>Registration Submitted:</b>\n\nName: %s\nEmail: %s\nAge: %.0f\nCountry: %s\nNewsletter: %s",
    name_val,
    email_val,
    age_val,
    country_val,
    if(newsletter_val) "Yes" else "No"
  )
  gtkLabelSetMarkup(results_label, result_text)

  # Also print to R console
  cat("\n=== Registration Data ===\n")
  cat("Name:", name_val, "\n")
  cat("Email:", email_val, "\n")
  cat("Age:", age_val, "\n")
  cat("Country:", country_val, "\n")
  cat("Newsletter:", newsletter_val, "\n")
  cat("========================\n\n")

  # Create data frame in global environment
  registration_data <<- data.frame(
    name = name_val,
    email = email_val,
    age = age_val,
    country = country_val,
    newsletter = newsletter_val,
    timestamp = Sys.time(),
    stringsAsFactors = FALSE
  )

  cat("Data saved to: registration_data\n")
})

gtkWindowPresent(window)
