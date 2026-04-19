generate_init_c <- function(src_dir = "src", output_file = "src/init.c") {

  cat("Generating init.c for package registration...\n")

  # Find all C files
  c_files <- list.files(src_dir, pattern = "\\.c$", full.names = TRUE)
  c_files <- c_files[!grepl("init\\.c$", c_files)]  # Exclude init.c itself

  cat("Scanning", length(c_files), "C files...\n")

  # Read all C files
  all_lines <- unlist(lapply(c_files, readLines))

  # Extract function signatures starting with "SEXP R_"
  func_lines <- grep("^SEXP R_", all_lines, value = TRUE)

  # Remove everything after the opening brace
  signatures <- sub("\\s*\\{.*$", "", func_lines)

  cat("Found", length(signatures), "functions to register\n")

  # Extract function names and count arguments
  externs <- character(length(signatures))
  entries <- character(length(signatures))

  for (i in seq_along(signatures)) {
    sig <- signatures[i]

    # External declaration
    externs[i] <- paste0("extern ", sig, ";")

    # Extract function name
    name <- sub("^SEXP\\s+", "", sig)
    name <- sub("\\(.*$", "", name)

    # Count arguments
    if (grepl("\\(void\\)|\\(\\)", sig)) {
      # No arguments
      nargs <- 0
    } else {
      # Count SEXP occurrences in parentheses
      param_part <- sub("^[^(]*\\(", "", sig)
      param_part <- sub("\\).*$", "", param_part)
      nargs <- length(gregexpr("SEXP", param_part)[[1]])
      if (nargs == -1) nargs <- 0  # No match returns -1
    }

    # Entry line
    entries[i] <- sprintf('    {"%s", (DL_FUNC) &%s, %d},', name, name, nargs)
  }

  # Write init.c
  cat("Writing", output_file, "...\n")

  writeLines(c(
    "#include <R.h>",
    "#include <Rinternals.h>",
    "#include <R_ext/Rdynload.h>",
    "",
    "/* Declarations */",
    externs,
    "",
    "static const R_CallMethodDef CallEntries[] = {",
    entries,
    "    {NULL, NULL, 0}",
    "};",
    "",
    "void R_init_Rgtk4(DllInfo *dll) {",
    "    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);",
    "    R_useDynamicSymbols(dll, FALSE);",
    "}"
  ), output_file)

  cat("Done! Generated", length(readLines(output_file)), "lines in", output_file, "\n")
  cat("Registered", length(signatures), "functions\n")

  invisible(output_file)
}

args <- commandArgs(trailingOnly = TRUE)
src_dir <- if (length(args) > 0) args[1] else "src"
output_file <- if (length(args) > 1) args[2] else file.path(src_dir, "init.c")

generate_init_c(src_dir, output_file)
