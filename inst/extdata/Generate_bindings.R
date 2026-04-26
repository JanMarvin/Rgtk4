RGirGen::generate_bindings(
  gir_paths = c(
    # "/opt/homebrew/share/gir-1.0/GLib-2.0.gir",
    # "/opt/homebrew/share/gir-1.0/GObject-2.0.gir",
    # "/opt/homebrew/share/gir-1.0/Gio-2.0.gir",
    # "/opt/homebrew/share/gir-1.0/Gdk-4.0.gir",
    # "/opt/homebrew/share/gir-1.0/Gtk-4.0.gir"
    ## run these independently PangoVariants otherwise get added to gtk
    # "/opt/homebrew/share/gir-1.0/Pango-1.0.gir"
    # "/opt/homebrew/share/gir-1.0/GdkPixbuf-2.0.gir"
  ),
  out_dir = "."
)
