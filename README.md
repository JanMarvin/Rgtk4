
<!-- README.md is generated from README.Rmd. Please edit that file -->

# Rgtk4

Modern GTK4 bindings for R with comprehensive platform integration.

## Overview

Rgtk4 provides complete, automatically-generated R bindings for GTK4,
GLib, GObject, and Gio. (The same pattern could be used for Pango,
GdkPixbuf, and Cairo). Unlike traditional hand-written bindings, Rgtk4
uses GObject Introspection (GIR) to generate bindings directly from
GTK’s metadata, ensuring complete API coverage and easy updates.

## Acknowledgments

**This project builds on the pioneering work of the RGtk2 team**,
particularly **Michael Lawrence**, whose original RGtk2 package
demonstrated the viability of GTK bindings for R. Without RGtk2, Rgtk4
would not exist.

## Features

- **Complete API Coverage**: Auto-generated from GIR files
- **Meaningful Parameter Names**: Parameters use descriptive names from
  GIR metadata
- **Event Loop Integration**: Native R event loop integration for
  responsive UIs
- **macOS Integration**: Automatic dock icon management and native
  shortcuts
- **Clean Architecture**: Separate generator and package for
  maintainability

## Installation

### Prerequisites

#### Debian/Ubuntu

``` bash
sudo apt-get update
sudo apt-get install libgtk-4-dev gobject-introspection \
  libgirepository1.0-dev pkg-config r-base-dev
```

#### Arch Linux

``` bash
sudo pacman -S gtk4 gobject-introspection pkgconf r
```

#### Windows

Needs [MSYS2](https://www.msys2.org/)

``` bash
pacman -S mingw-w64-ucrt-x86_64-gtk \
          mingw-w64-ucrt-x86_64-gobject-introspection \
          mingw-w64-ucrt-x86_64-pkg-config
```

### Building Rgtk4

1.  **Generate Bindings** (RGirGen package)

This creates all auto-generated bindings in the Rgtk4 package.

2.  **Build and Install Rgtk4**:

``` r
# From R
install.packages("Rgtk4", repos = NULL, type = "source")

# Or from command line
R CMD build Rgtk4
R CMD INSTALL Rgtk4_0.1.0.tar.gz
```

## Quick Start

``` r
library(Rgtk4)

# Initialize GTK and start event loop
gtkInit()
gtkStartEventLoop()

# Create a window
window <- gtkWindowNew()
gtkWindowSetTitle(window, "Hello Rgtk4!")
gtkWindowSetDefaultSize(window, 400L, 300L)

# Add some content
box <- gtkBoxNew(1L, 10L)  # 1 = vertical orientation
gtkWindowSetChild(window, box)

label <- gtkLabelNew("Welcome to Rgtk4!")
gtkBoxAppend(box, label)

button <- gtkButtonNew()
gtkButtonSetLabel(button, "Click Me")
gtkBoxAppend(box, button)

# Connect signals
gSignalConnectR(button, "clicked", function(w) {
  print("Button clicked!")
})

# Show the window
gtkWindowPresent(window)
```

## Architecture

Rgtk4 uses a two-package architecture:

### RGirGen (Generator)

- Parses GIR XML files from GObject Introspection
- Generates C wrappers with proper type conversions
- Generates R functions with meaningful parameter names
- Filters platform-specific functions

### Rgtk4 (Package)

- Contains all auto-generated bindings
- Provides custom helpers (event loop, macOS integration, signal
  handling)
- Includes utility functions

## Documentation

- GTK4 Documentation: <https://docs.gtk.org/gtk4/>
- GObject Introspection: <https://gi.readthedocs.io/>

## Contributing

Contributions welcome! The clean architecture makes it easy to add new
helper functions or improve the generator.

## License

GPL-2 \| GPL-3 (following R and GTK licensing)

## Version

0.1.0 - Initial release

## System Requirements

- R \>= 4.0.0
- GTK4 \>= 4.0.0
- GObject Introspection \>= 1.0.0

## Troubleshooting

### “GTK not found” errors

Ensure `pkg-config --modversion gtk4` returns a version number. If not,
GTK4 is not properly installed or not in your PATH.

## Credits

- **RGtk2 Team** - Original GTK bindings for R
- **Michael Lawrence** - RGtk2 lead developer
- **GTK Team** - GTK toolkit and GObject Introspection
- **R Core Team** - R language and development tools
