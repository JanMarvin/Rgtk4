# RGtk4

Modern GTK4 bindings for R with comprehensive platform integration.

## Overview

RGtk4 provides complete, automatically-generated R bindings for GTK4, GLib, GObject, Gio, Pango, GdkPixbuf, and Cairo. Unlike traditional hand-written bindings, RGtk4 uses GObject Introspection (GIR) to generate bindings directly from GTK's metadata, ensuring complete API coverage and easy updates.

## Acknowledgments

**This project builds on the pioneering work of the RGtk2 team**, particularly **Michael Lawrence**, whose original RGtk2 package demonstrated the viability of GTK bindings for R and established many of the patterns used here. The RGtk2 developers' suggestion to explore GIR-based binding generation was instrumental in making RGtk4 possible. Their work proved that R and GTK can work together beautifully, and RGtk4 continues that tradition for the modern GTK4 era.

## Features

- **Complete API Coverage**: Auto-generated from GIR files - every GTK4 function, signal, and property is available
- **Meaningful Parameter Names**: No more `arg1`, `arg2` - parameters use descriptive names from GIR metadata
- **Platform-Specific Filtering**: Unix-only functions automatically excluded on Windows/macOS
- **Event Loop Integration**: Native R event loop integration for responsive UIs
- **macOS Integration**: 
  - Automatic dock icon management
  - Cmd+W keyboard shortcuts
  - Native window behavior
- **Clean Architecture**: Generator only generates; all helpers and infrastructure in the main package

## Installation

### Prerequisites

#### macOS
```bash
# Install GTK4 and dependencies via Homebrew
brew install gtk4 gobject-introspection pkg-config

# For development/building from source
brew install r
```

#### Linux (Ubuntu/Debian)
```bash
# Install GTK4 and development files
sudo apt-get update
sudo apt-get install libgtk-4-dev gobject-introspection \
  libgirepository1.0-dev pkg-config r-base-dev

# Optional: Additional components
sudo apt-get install libpango1.0-dev libcairo2-dev \
  libgdk-pixbuf-2.0-dev
```

#### Linux (Fedora/RHEL)
```bash
# Install GTK4 and development files
sudo dnf install gtk4-devel gobject-introspection-devel \
  pkgconfig R-devel

# Optional: Additional components
sudo dnf install pango-devel cairo-devel gdk-pixbuf2-devel
```

#### Windows
```bash
# Install via MSYS2 (https://www.msys2.org/)
pacman -S mingw-w64-x86_64-gtk4 \
  mingw-w64-x86_64-gobject-introspection \
  mingw-w64-x86_64-pkg-config \
  mingw-w64-x86_64-gcc

# Install R from CRAN
# https://cran.r-project.org/bin/windows/base/
```

### Building RGtk4

1. **Generate Bindings** (RGirGen package)

This creates all auto-generated bindings in the Rgtk4 package.

2. **Build and Install Rgtk4**:
```r
# From R
install.packages("Rgtk4", repos = NULL, type = "source")

# Or from command line
R CMD build Rgtk4
R CMD INSTALL Rgtk4_0.1.0.tar.gz
```

## Quick Start

```r
library(Rgtk4)

# Initialize GTK and start event loop
gtkInit()
gtkStartEventLoop()

# Create a window
window <- gtkWindowNew()
gtkWindowSetTitle(window, "Hello RGtk4!")
gtkWindowSetDefaultSize(window, 400L, 300L)

# macOS: Show dock icon when window appears
gtkForceForeground()

# Add some content
box <- gtkBoxNew(1L, 10L)  # 1 = vertical orientation
gtkWindowSetChild(window, box)

label <- gtkLabelNew("Welcome to RGtk4!")
gtkBoxAppend(box, label)

button <- gtkButtonNew()
gtkButtonSetLabel(button, "Click Me")
gtkBoxAppend(box, button)

# Connect signals
gSignalConnectR(button, "clicked", function(w) {
  print("Button clicked!")
})

gSignalConnectR(window, "close-request", function(w) {
  gtkHideFromDock()  # macOS: Hide from dock when closed
  return(FALSE)  # Allow window to close
})

# Show the window
gtkWindowPresent(window)
```

## Architecture

RGtk4 uses a clean two-package architecture:

### RGirGen (Generator)
- Parses GIR XML files from GObject Introspection
- Generates C wrappers with proper type conversions
- Generates R functions with meaningful parameter names
- Filters platform-specific functions (Unix/Windows/macOS)
- **Only generates** - doesn't include any helpers or infrastructure

### Rgtk4 (Package)
- Contains all auto-generated bindings
- Provides custom helpers (event loop, macOS integration, signal handling)
- Includes utility functions (GtkStringList helpers, keyboard shortcuts)
- Owns all infrastructure and R-specific functionality

## Platform-Specific Features

### macOS
- **Dock Icon Management**: Automatically appears/disappears with windows
  - `gtkForceForeground()` - Show dock icon
  - `gtkHideFromDock()` - Hide dock icon
  - `gtkWindowTrack(window)` - Automatic tracking (recommended)
- **Keyboard Shortcuts**: Native Cmd+W support via `gtkWindowAddCloseShortcut()`
- **Window Snapping**: Requires GTK 4.23+ or 4.24+ for Rectangle/native macOS snapping support

### Linux
- Standard GTK4 behavior
- Full Wayland and X11 support
- Native window manager integration

### Windows
- Standard GTK4 behavior
- Windows theme integration
- Native window decorations
- **Requires `later` package** for event loop: `install.packages("later")`
- **Unix-specific functions**: Automatically return stubs with warnings (e.g., `g_unix_*`, `g_subprocess_*`)

## Known Limitations

1. **macOS Window Snapping**: GTK 4.22.x does not support Rectangle or native macOS window snapping. This requires GTK 4.23+ (unstable) or GTK 4.24+ (next stable) which includes [this patch](https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/8501) that uses native `performWindowDragWithEvent:` instead of custom edge snapping.

2. **Multi-Parameter Signals**: `gSignalConnectR()` currently only handles simple signals. For complex signals with multiple parameters (like `key-pressed`), use the C-level helpers.

3. **Client-Side Decorations**: GTK4 manages window chrome on most platforms, which can limit some native platform integrations.

4. **Async Callback Functions**: Some modern GTK4 async APIs (like `GtkFileDialog`) are not yet wrapped because they require callback parameters. The bindings currently use older signal-based APIs (like `GtkFileChooserNative`) which work identically but are marked deprecated in GTK 4.10+. These deprecated functions will continue to work for the foreseeable future.

   **Functions affected:**
   - File dialogs - use `gtkFileChooserNativeNew()` instead of `gtkFileDialogNew()`
   - Some GIO async operations - use synchronous versions or signal-based APIs
   
   **Workaround:** The generator blocks functions with callback parameters to avoid complex C-to-R function pointer wrapping. Support for `GAsyncReadyCallback` and similar patterns could be added with manual wrappers (~50-200 lines of C per callback type).
   
   **Impact:** Minimal - signal-based APIs provide equivalent functionality and are stable across GTK versions.

## Examples

See `comprehensive_demo.R` for a full-featured example including:
- Animated SVG graphics
- Zoomable scatter plots
- Live webcam capture
- Simulation with controls
- Tabbed notes interface
- Help menu with About dialog

## Documentation

- GTK4 Documentation: https://docs.gtk.org/gtk4/
- GObject Introspection: https://gi.readthedocs.io/
- RGtk2 (predecessor): https://www.rforge.net/RGtk2/

## Comparison with RGtk2

RGtk4 differs from RGtk2 in several key ways:

| Feature | RGtk2 | RGtk4 |
|---------|-------|-------|
| GTK Version | GTK2 | GTK4 |
| Binding Generation | Hand-written + some code gen | Fully auto-generated from GIR |
| API Coverage | Partial | Complete |
| Parameter Names | Often generic (arg1, arg2) | Meaningful from metadata |
| Platform Filtering | Manual | Automatic |
| Update Process | Manual maintenance | Re-run generator |
| Architecture | Monolithic | Generator + Package |

## Contributing

Contributions welcome! The clean architecture makes it easy to:
- Add new helper functions to Rgtk4
- Improve the generator for better bindings
- Add platform-specific integrations
- Improve documentation and examples

## License

GPL-2 | GPL-3 (following R and GTK licensing)

## Version

0.1.0 - Initial release

## System Requirements

- R >= 4.0.0
- GTK4 >= 4.0.0 (4.22.3+ recommended)
- GObject Introspection >= 1.0.0
- Platform-specific requirements per installation instructions above

## Troubleshooting

### "GTK not found" errors
Ensure `pkg-config --modversion gtk4` returns a version number. If not, GTK4 is not properly installed or not in your PATH.

### macOS: "Library not loaded" errors
```bash
# Check GTK4 location
brew list gtk4

# Ensure PKG_CONFIG_PATH is set
export PKG_CONFIG_PATH="/opt/homebrew/lib/pkgconfig:$PKG_CONFIG_PATH"
```

### Linux: Missing GIR files
```bash
# Ubuntu/Debian
sudo apt-get install gir1.2-gtk-4.0

# Fedora/RHEL  
sudo dnf install gtk4-devel
```

### Windows: Compilation errors
Ensure you're using the correct MSYS2 environment (MINGW64) and that all paths are properly set in your `.Renviron` file.

## Credits

- **RGtk2 Team** - Original GTK bindings for R, conceptual foundation
- **Michael Lawrence** - RGtk2 lead developer, GIR suggestion
- **GTK Team** - GTK toolkit and GObject Introspection
- **R Core Team** - R language and development tools
