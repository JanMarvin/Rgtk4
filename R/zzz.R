# R/zzz.R - Package initialization

#' @importFrom utils globalVariables
NULL

# Suppress R CMD check notes about global variables used in event loop
utils::globalVariables(c(".rgtk4_windows_timer"))
