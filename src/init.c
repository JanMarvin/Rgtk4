#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

/* Declarations */
extern SEXP R_gdk_app_launch_context_get_display(SEXP s1);
extern SEXP R_gdk_app_launch_context_set_desktop(SEXP s1, SEXP s2);
extern SEXP R_gdk_app_launch_context_set_icon(SEXP s1, SEXP s2);
extern SEXP R_gdk_app_launch_context_set_icon_name(SEXP s1, SEXP s2);
extern SEXP R_gdk_app_launch_context_set_timestamp(SEXP s1, SEXP s2);
extern SEXP R_gdk_button_event_get_button(SEXP s1);
extern SEXP R_gdk_cairo_context_cairo_create(SEXP s1);
extern SEXP R_gdk_clipboard_get_content(SEXP s1);
extern SEXP R_gdk_clipboard_get_display(SEXP s1);
extern SEXP R_gdk_clipboard_get_formats(SEXP s1);
extern SEXP R_gdk_clipboard_is_local(SEXP s1);
extern SEXP R_gdk_clipboard_read_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gdk_clipboard_read_finish(SEXP s1, SEXP s2);
extern SEXP R_gdk_clipboard_read_text_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gdk_clipboard_read_text_finish(SEXP s1, SEXP s2);
extern SEXP R_gdk_clipboard_read_texture_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gdk_clipboard_read_texture_finish(SEXP s1, SEXP s2);
extern SEXP R_gdk_clipboard_read_value_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gdk_clipboard_read_value_finish(SEXP s1, SEXP s2);
extern SEXP R_gdk_clipboard_set_content(SEXP s1, SEXP s2);
extern SEXP R_gdk_clipboard_set_value(SEXP s1, SEXP s2);
extern SEXP R_gdk_clipboard_store_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gdk_clipboard_store_finish(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_deserializer_get_cancellable(SEXP s1);
extern SEXP R_gdk_content_deserializer_get_gtype(SEXP s1);
extern SEXP R_gdk_content_deserializer_get_input_stream(SEXP s1);
extern SEXP R_gdk_content_deserializer_get_mime_type(SEXP s1);
extern SEXP R_gdk_content_deserializer_get_priority(SEXP s1);
extern SEXP R_gdk_content_deserializer_get_task_data(SEXP s1);
extern SEXP R_gdk_content_deserializer_get_user_data(SEXP s1);
extern SEXP R_gdk_content_deserializer_get_value(SEXP s1);
extern SEXP R_gdk_content_deserializer_return_error(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_deserializer_return_success(SEXP s1);
extern SEXP R_gdk_content_deserializer_set_task_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_content_formats_new(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_formats_new_for_gtype(SEXP s1);
extern SEXP R_gdk_content_formats_contain_gtype(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_formats_contain_mime_type(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_formats_get_gtypes(SEXP s1);
extern SEXP R_gdk_content_formats_get_mime_types(SEXP s1);
extern SEXP R_gdk_content_formats_match(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_formats_match_gtype(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_formats_match_mime_type(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_formats_print(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_formats_ref(SEXP s1);
extern SEXP R_gdk_content_formats_to_string(SEXP s1);
extern SEXP R_gdk_content_formats_union(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_formats_union_deserialize_gtypes(SEXP s1);
extern SEXP R_gdk_content_formats_union_deserialize_mime_types(SEXP s1);
extern SEXP R_gdk_content_formats_union_serialize_gtypes(SEXP s1);
extern SEXP R_gdk_content_formats_union_serialize_mime_types(SEXP s1);
extern SEXP R_gdk_content_formats_unref(SEXP s1);
extern SEXP R_gdk_content_formats_parse(SEXP s1);
extern SEXP R_gdk_content_formats_builder_new(void);
extern SEXP R_gdk_content_formats_builder_add_formats(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_formats_builder_add_gtype(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_formats_builder_add_mime_type(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_formats_builder_ref(SEXP s1);
extern SEXP R_gdk_content_formats_builder_to_formats(SEXP s1);
extern SEXP R_gdk_content_formats_builder_unref(SEXP s1);
extern SEXP R_gdk_content_provider_new_for_bytes(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_provider_new_for_value(SEXP s1);
extern SEXP R_gdk_content_provider_new_union(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_provider_content_changed(SEXP s1);
extern SEXP R_gdk_content_provider_get_value(SEXP s1);
extern SEXP R_gdk_content_provider_ref_formats(SEXP s1);
extern SEXP R_gdk_content_provider_ref_storable_formats(SEXP s1);
extern SEXP R_gdk_content_provider_write_mime_type_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gdk_content_provider_write_mime_type_finish(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_serializer_get_cancellable(SEXP s1);
extern SEXP R_gdk_content_serializer_get_gtype(SEXP s1);
extern SEXP R_gdk_content_serializer_get_mime_type(SEXP s1);
extern SEXP R_gdk_content_serializer_get_output_stream(SEXP s1);
extern SEXP R_gdk_content_serializer_get_priority(SEXP s1);
extern SEXP R_gdk_content_serializer_get_task_data(SEXP s1);
extern SEXP R_gdk_content_serializer_get_user_data(SEXP s1);
extern SEXP R_gdk_content_serializer_get_value(SEXP s1);
extern SEXP R_gdk_content_serializer_return_error(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_serializer_return_success(SEXP s1);
extern SEXP R_gdk_content_serializer_set_task_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_crossing_event_get_detail(SEXP s1);
extern SEXP R_gdk_crossing_event_get_focus(SEXP s1);
extern SEXP R_gdk_crossing_event_get_mode(SEXP s1);
extern SEXP R_gdk_cursor_new_from_name(SEXP s1, SEXP s2);
extern SEXP R_gdk_cursor_new_from_texture(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gdk_cursor_get_fallback(SEXP s1);
extern SEXP R_gdk_cursor_get_hotspot_x(SEXP s1);
extern SEXP R_gdk_cursor_get_hotspot_y(SEXP s1);
extern SEXP R_gdk_cursor_get_name(SEXP s1);
extern SEXP R_gdk_cursor_get_texture(SEXP s1);
extern SEXP R_gdk_dnd_event_get_drop(SEXP s1);
extern SEXP R_gdk_device_get_caps_lock_state(SEXP s1);
extern SEXP R_gdk_device_get_device_tool(SEXP s1);
extern SEXP R_gdk_device_get_direction(SEXP s1);
extern SEXP R_gdk_device_get_display(SEXP s1);
extern SEXP R_gdk_device_get_has_cursor(SEXP s1);
extern SEXP R_gdk_device_get_modifier_state(SEXP s1);
extern SEXP R_gdk_device_get_name(SEXP s1);
extern SEXP R_gdk_device_get_num_lock_state(SEXP s1);
extern SEXP R_gdk_device_get_num_touches(SEXP s1);
extern SEXP R_gdk_device_get_product_id(SEXP s1);
extern SEXP R_gdk_device_get_scroll_lock_state(SEXP s1);
extern SEXP R_gdk_device_get_seat(SEXP s1);
extern SEXP R_gdk_device_get_source(SEXP s1);
extern SEXP R_gdk_device_get_surface_at_position(SEXP s1);
extern SEXP R_gdk_device_get_timestamp(SEXP s1);
extern SEXP R_gdk_device_get_vendor_id(SEXP s1);
extern SEXP R_gdk_device_has_bidi_layouts(SEXP s1);
extern SEXP R_gdk_device_pad_get_feature_group(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_device_pad_get_group_n_modes(SEXP s1, SEXP s2);
extern SEXP R_gdk_device_pad_get_n_features(SEXP s1, SEXP s2);
extern SEXP R_gdk_device_pad_get_n_groups(SEXP s1);
extern SEXP R_gdk_device_tool_get_axes(SEXP s1);
extern SEXP R_gdk_device_tool_get_hardware_id(SEXP s1);
extern SEXP R_gdk_device_tool_get_serial(SEXP s1);
extern SEXP R_gdk_device_tool_get_tool_type(SEXP s1);
extern SEXP R_gdk_display_get_default(void);
extern SEXP R_gdk_display_open(SEXP s1);
extern SEXP R_gdk_display_beep(SEXP s1);
extern SEXP R_gdk_display_close(SEXP s1);
extern SEXP R_gdk_display_create_gl_context(SEXP s1);
extern SEXP R_gdk_display_device_is_grabbed(SEXP s1, SEXP s2);
extern SEXP R_gdk_display_flush(SEXP s1);
extern SEXP R_gdk_display_get_app_launch_context(SEXP s1);
extern SEXP R_gdk_display_get_clipboard(SEXP s1);
extern SEXP R_gdk_display_get_default_seat(SEXP s1);
extern SEXP R_gdk_display_get_monitor_at_surface(SEXP s1, SEXP s2);
extern SEXP R_gdk_display_get_monitors(SEXP s1);
extern SEXP R_gdk_display_get_name(SEXP s1);
extern SEXP R_gdk_display_get_primary_clipboard(SEXP s1);
extern SEXP R_gdk_display_get_setting(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_display_get_startup_notification_id(SEXP s1);
extern SEXP R_gdk_display_is_closed(SEXP s1);
extern SEXP R_gdk_display_is_composited(SEXP s1);
extern SEXP R_gdk_display_is_rgba(SEXP s1);
extern SEXP R_gdk_display_list_seats(SEXP s1);
extern SEXP R_gdk_display_map_keycode(SEXP s1, SEXP s2);
extern SEXP R_gdk_display_map_keyval(SEXP s1, SEXP s2);
extern SEXP R_gdk_display_notify_startup_complete(SEXP s1, SEXP s2);
extern SEXP R_gdk_display_prepare_gl(SEXP s1);
extern SEXP R_gdk_display_put_event(SEXP s1, SEXP s2);
extern SEXP R_gdk_display_supports_input_shapes(SEXP s1);
extern SEXP R_gdk_display_sync(SEXP s1);
extern SEXP R_gdk_display_translate_key(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gdk_display_manager_get(void);
extern SEXP R_gdk_display_manager_get_default_display(SEXP s1);
extern SEXP R_gdk_display_manager_list_displays(SEXP s1);
extern SEXP R_gdk_display_manager_open_display(SEXP s1, SEXP s2);
extern SEXP R_gdk_display_manager_set_default_display(SEXP s1, SEXP s2);
extern SEXP R_gdk_dmabuf_error_quark(void);
extern SEXP R_gdk_drag_begin(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gdk_drag_drop_done(SEXP s1, SEXP s2);
extern SEXP R_gdk_drag_get_actions(SEXP s1);
extern SEXP R_gdk_drag_get_content(SEXP s1);
extern SEXP R_gdk_drag_get_device(SEXP s1);
extern SEXP R_gdk_drag_get_display(SEXP s1);
extern SEXP R_gdk_drag_get_drag_surface(SEXP s1);
extern SEXP R_gdk_drag_get_formats(SEXP s1);
extern SEXP R_gdk_drag_get_selected_action(SEXP s1);
extern SEXP R_gdk_drag_get_surface(SEXP s1);
extern SEXP R_gdk_drag_set_hotspot(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_drag_action_is_unique(SEXP s1);
extern SEXP R_gdk_drag_surface_present(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_drag_surface_size_set_size(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_draw_context_begin_frame(SEXP s1, SEXP s2);
extern SEXP R_gdk_draw_context_end_frame(SEXP s1);
extern SEXP R_gdk_draw_context_get_display(SEXP s1);
extern SEXP R_gdk_draw_context_get_frame_region(SEXP s1);
extern SEXP R_gdk_draw_context_get_surface(SEXP s1);
extern SEXP R_gdk_draw_context_is_in_frame(SEXP s1);
extern SEXP R_gdk_drop_finish(SEXP s1, SEXP s2);
extern SEXP R_gdk_drop_get_actions(SEXP s1);
extern SEXP R_gdk_drop_get_device(SEXP s1);
extern SEXP R_gdk_drop_get_display(SEXP s1);
extern SEXP R_gdk_drop_get_drag(SEXP s1);
extern SEXP R_gdk_drop_get_formats(SEXP s1);
extern SEXP R_gdk_drop_get_surface(SEXP s1);
extern SEXP R_gdk_drop_read_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gdk_drop_read_finish(SEXP s1, SEXP s2);
extern SEXP R_gdk_drop_read_value_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gdk_drop_read_value_finish(SEXP s1, SEXP s2);
extern SEXP R_gdk_drop_status(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_event_get_axes(SEXP s1);
extern SEXP R_gdk_event_get_axis(SEXP s1, SEXP s2);
extern SEXP R_gdk_event_get_device(SEXP s1);
extern SEXP R_gdk_event_get_device_tool(SEXP s1);
extern SEXP R_gdk_event_get_display(SEXP s1);
extern SEXP R_gdk_event_get_event_sequence(SEXP s1);
extern SEXP R_gdk_event_get_event_type(SEXP s1);
extern SEXP R_gdk_event_get_history(SEXP s1);
extern SEXP R_gdk_event_get_modifier_state(SEXP s1);
extern SEXP R_gdk_event_get_pointer_emulated(SEXP s1);
extern SEXP R_gdk_event_get_position(SEXP s1);
extern SEXP R_gdk_event_get_seat(SEXP s1);
extern SEXP R_gdk_event_get_surface(SEXP s1);
extern SEXP R_gdk_event_get_time(SEXP s1);
extern SEXP R_gdk_event_ref(SEXP s1);
extern SEXP R_gdk_event_triggers_context_menu(SEXP s1);
extern SEXP R_gdk_event_unref(SEXP s1);
extern SEXP R_gdk_file_list_new_from_array(SEXP s1, SEXP s2);
extern SEXP R_gdk_file_list_new_from_list(SEXP s1);
extern SEXP R_gdk_file_list_get_files(SEXP s1);
extern SEXP R_gdk_focus_event_get_in(SEXP s1);
extern SEXP R_gdk_frame_clock_begin_updating(SEXP s1);
extern SEXP R_gdk_frame_clock_end_updating(SEXP s1);
extern SEXP R_gdk_frame_clock_get_current_timings(SEXP s1);
extern SEXP R_gdk_frame_clock_get_fps(SEXP s1);
extern SEXP R_gdk_frame_clock_get_frame_counter(SEXP s1);
extern SEXP R_gdk_frame_clock_get_frame_time(SEXP s1);
extern SEXP R_gdk_frame_clock_get_history_start(SEXP s1);
extern SEXP R_gdk_frame_clock_get_refresh_info(SEXP s1, SEXP s2);
extern SEXP R_gdk_frame_clock_get_timings(SEXP s1, SEXP s2);
extern SEXP R_gdk_frame_clock_request_phase(SEXP s1, SEXP s2);
extern SEXP R_gdk_frame_timings_get_complete(SEXP s1);
extern SEXP R_gdk_frame_timings_get_frame_counter(SEXP s1);
extern SEXP R_gdk_frame_timings_get_frame_time(SEXP s1);
extern SEXP R_gdk_frame_timings_get_predicted_presentation_time(SEXP s1);
extern SEXP R_gdk_frame_timings_get_presentation_time(SEXP s1);
extern SEXP R_gdk_frame_timings_get_refresh_interval(SEXP s1);
extern SEXP R_gdk_frame_timings_ref(SEXP s1);
extern SEXP R_gdk_frame_timings_unref(SEXP s1);
extern SEXP R_gdk_gl_context_clear_current(void);
extern SEXP R_gdk_gl_context_get_current(void);
extern SEXP R_gdk_gl_context_get_allowed_apis(SEXP s1);
extern SEXP R_gdk_gl_context_get_api(SEXP s1);
extern SEXP R_gdk_gl_context_get_debug_enabled(SEXP s1);
extern SEXP R_gdk_gl_context_get_display(SEXP s1);
extern SEXP R_gdk_gl_context_get_forward_compatible(SEXP s1);
extern SEXP R_gdk_gl_context_get_required_version(SEXP s1);
extern SEXP R_gdk_gl_context_get_shared_context(SEXP s1);
extern SEXP R_gdk_gl_context_get_surface(SEXP s1);
extern SEXP R_gdk_gl_context_get_use_es(SEXP s1);
extern SEXP R_gdk_gl_context_get_version(SEXP s1);
extern SEXP R_gdk_gl_context_is_legacy(SEXP s1);
extern SEXP R_gdk_gl_context_is_shared(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_context_make_current(SEXP s1);
extern SEXP R_gdk_gl_context_realize(SEXP s1);
extern SEXP R_gdk_gl_context_set_allowed_apis(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_context_set_debug_enabled(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_context_set_forward_compatible(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_context_set_required_version(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_gl_context_set_use_es(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_error_quark(void);
extern SEXP R_gdk_gl_texture_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gdk_gl_texture_release(SEXP s1);
extern SEXP R_gdk_gl_texture_builder_new(void);
extern SEXP R_gdk_gl_texture_builder_build(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_gl_texture_builder_get_context(SEXP s1);
extern SEXP R_gdk_gl_texture_builder_get_format(SEXP s1);
extern SEXP R_gdk_gl_texture_builder_get_has_mipmap(SEXP s1);
extern SEXP R_gdk_gl_texture_builder_get_height(SEXP s1);
extern SEXP R_gdk_gl_texture_builder_get_id(SEXP s1);
extern SEXP R_gdk_gl_texture_builder_get_sync(SEXP s1);
extern SEXP R_gdk_gl_texture_builder_get_update_region(SEXP s1);
extern SEXP R_gdk_gl_texture_builder_get_update_texture(SEXP s1);
extern SEXP R_gdk_gl_texture_builder_get_width(SEXP s1);
extern SEXP R_gdk_gl_texture_builder_set_context(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_texture_builder_set_format(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_texture_builder_set_has_mipmap(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_texture_builder_set_height(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_texture_builder_set_id(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_texture_builder_set_sync(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_texture_builder_set_update_region(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_texture_builder_set_update_texture(SEXP s1, SEXP s2);
extern SEXP R_gdk_gl_texture_builder_set_width(SEXP s1, SEXP s2);
extern SEXP R_gdk_grab_broken_event_get_grab_surface(SEXP s1);
extern SEXP R_gdk_grab_broken_event_get_implicit(SEXP s1);
extern SEXP R_gdk_key_event_get_consumed_modifiers(SEXP s1);
extern SEXP R_gdk_key_event_get_keycode(SEXP s1);
extern SEXP R_gdk_key_event_get_keyval(SEXP s1);
extern SEXP R_gdk_key_event_get_layout(SEXP s1);
extern SEXP R_gdk_key_event_get_level(SEXP s1);
extern SEXP R_gdk_key_event_get_match(SEXP s1);
extern SEXP R_gdk_key_event_is_modifier(SEXP s1);
extern SEXP R_gdk_key_event_matches(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_memory_texture_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gdk_monitor_get_connector(SEXP s1);
extern SEXP R_gdk_monitor_get_description(SEXP s1);
extern SEXP R_gdk_monitor_get_display(SEXP s1);
extern SEXP R_gdk_monitor_get_geometry(SEXP s1);
extern SEXP R_gdk_monitor_get_height_mm(SEXP s1);
extern SEXP R_gdk_monitor_get_manufacturer(SEXP s1);
extern SEXP R_gdk_monitor_get_model(SEXP s1);
extern SEXP R_gdk_monitor_get_refresh_rate(SEXP s1);
extern SEXP R_gdk_monitor_get_scale_factor(SEXP s1);
extern SEXP R_gdk_monitor_get_subpixel_layout(SEXP s1);
extern SEXP R_gdk_monitor_get_width_mm(SEXP s1);
extern SEXP R_gdk_monitor_is_valid(SEXP s1);
extern SEXP R_gdk_pad_event_get_axis_value(SEXP s1);
extern SEXP R_gdk_pad_event_get_button(SEXP s1);
extern SEXP R_gdk_pad_event_get_group_mode(SEXP s1);
extern SEXP R_gdk_paintable_new_empty(SEXP s1, SEXP s2);
extern SEXP R_gdk_paintable_compute_concrete_size(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gdk_paintable_get_current_image(SEXP s1);
extern SEXP R_gdk_paintable_get_flags(SEXP s1);
extern SEXP R_gdk_paintable_get_intrinsic_aspect_ratio(SEXP s1);
extern SEXP R_gdk_paintable_get_intrinsic_height(SEXP s1);
extern SEXP R_gdk_paintable_get_intrinsic_width(SEXP s1);
extern SEXP R_gdk_paintable_invalidate_contents(SEXP s1);
extern SEXP R_gdk_paintable_invalidate_size(SEXP s1);
extern SEXP R_gdk_paintable_snapshot(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gdk_popup_get_autohide(SEXP s1);
extern SEXP R_gdk_popup_get_parent(SEXP s1);
extern SEXP R_gdk_popup_get_position_x(SEXP s1);
extern SEXP R_gdk_popup_get_position_y(SEXP s1);
extern SEXP R_gdk_popup_get_rect_anchor(SEXP s1);
extern SEXP R_gdk_popup_get_surface_anchor(SEXP s1);
extern SEXP R_gdk_popup_present(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gdk_popup_layout_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_popup_layout_copy(SEXP s1);
extern SEXP R_gdk_popup_layout_equal(SEXP s1, SEXP s2);
extern SEXP R_gdk_popup_layout_get_anchor_hints(SEXP s1);
extern SEXP R_gdk_popup_layout_get_anchor_rect(SEXP s1);
extern SEXP R_gdk_popup_layout_get_offset(SEXP s1);
extern SEXP R_gdk_popup_layout_get_rect_anchor(SEXP s1);
extern SEXP R_gdk_popup_layout_get_shadow_width(SEXP s1);
extern SEXP R_gdk_popup_layout_get_surface_anchor(SEXP s1);
extern SEXP R_gdk_popup_layout_ref(SEXP s1);
extern SEXP R_gdk_popup_layout_set_anchor_hints(SEXP s1, SEXP s2);
extern SEXP R_gdk_popup_layout_set_anchor_rect(SEXP s1, SEXP s2);
extern SEXP R_gdk_popup_layout_set_offset(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_popup_layout_set_rect_anchor(SEXP s1, SEXP s2);
extern SEXP R_gdk_popup_layout_set_shadow_width(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gdk_popup_layout_set_surface_anchor(SEXP s1, SEXP s2);
extern SEXP R_gdk_popup_layout_unref(SEXP s1);
extern SEXP R_gdk_rgba_copy(SEXP s1);
extern SEXP R_gdk_rgba_equal(SEXP s1, SEXP s2);
extern SEXP R_gdk_rgba_free(SEXP s1);
extern SEXP R_gdk_rgba_hash(SEXP s1);
extern SEXP R_gdk_rgba_is_clear(SEXP s1);
extern SEXP R_gdk_rgba_is_opaque(SEXP s1);
extern SEXP R_gdk_rgba_parse(SEXP s1, SEXP s2);
extern SEXP R_gdk_rgba_to_string(SEXP s1);
extern SEXP R_gdk_rectangle_contains_point(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_rectangle_equal(SEXP s1, SEXP s2);
extern SEXP R_gdk_rectangle_intersect(SEXP s1, SEXP s2);
extern SEXP R_gdk_rectangle_union(SEXP s1, SEXP s2);
extern SEXP R_gdk_scroll_event_get_deltas(SEXP s1);
extern SEXP R_gdk_scroll_event_get_direction(SEXP s1);
extern SEXP R_gdk_scroll_event_get_unit(SEXP s1);
extern SEXP R_gdk_scroll_event_is_stop(SEXP s1);
extern SEXP R_gdk_seat_get_capabilities(SEXP s1);
extern SEXP R_gdk_seat_get_devices(SEXP s1, SEXP s2);
extern SEXP R_gdk_seat_get_display(SEXP s1);
extern SEXP R_gdk_seat_get_keyboard(SEXP s1);
extern SEXP R_gdk_seat_get_pointer(SEXP s1);
extern SEXP R_gdk_seat_get_tools(SEXP s1);
extern SEXP R_gdk_surface_new_popup(SEXP s1, SEXP s2);
extern SEXP R_gdk_surface_new_toplevel(SEXP s1);
extern SEXP R_gdk_surface_beep(SEXP s1);
extern SEXP R_gdk_surface_create_cairo_context(SEXP s1);
extern SEXP R_gdk_surface_create_gl_context(SEXP s1);
extern SEXP R_gdk_surface_create_similar_surface(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gdk_surface_create_vulkan_context(SEXP s1);
extern SEXP R_gdk_surface_destroy(SEXP s1);
extern SEXP R_gdk_surface_get_cursor(SEXP s1);
extern SEXP R_gdk_surface_get_device_cursor(SEXP s1, SEXP s2);
extern SEXP R_gdk_surface_get_device_position(SEXP s1, SEXP s2);
extern SEXP R_gdk_surface_get_display(SEXP s1);
extern SEXP R_gdk_surface_get_frame_clock(SEXP s1);
extern SEXP R_gdk_surface_get_height(SEXP s1);
extern SEXP R_gdk_surface_get_mapped(SEXP s1);
extern SEXP R_gdk_surface_get_scale(SEXP s1);
extern SEXP R_gdk_surface_get_scale_factor(SEXP s1);
extern SEXP R_gdk_surface_get_width(SEXP s1);
extern SEXP R_gdk_surface_hide(SEXP s1);
extern SEXP R_gdk_surface_is_destroyed(SEXP s1);
extern SEXP R_gdk_surface_queue_render(SEXP s1);
extern SEXP R_gdk_surface_request_layout(SEXP s1);
extern SEXP R_gdk_surface_set_cursor(SEXP s1, SEXP s2);
extern SEXP R_gdk_surface_set_device_cursor(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_surface_set_input_region(SEXP s1, SEXP s2);
extern SEXP R_gdk_surface_set_opaque_region(SEXP s1, SEXP s2);
extern SEXP R_gdk_surface_translate_coordinates(SEXP s1, SEXP s2);
extern SEXP R_gdk_texture_new_for_pixbuf(SEXP s1);
extern SEXP R_gdk_texture_new_from_bytes(SEXP s1);
extern SEXP R_gdk_texture_new_from_file(SEXP s1);
extern SEXP R_gdk_texture_new_from_filename(SEXP s1);
extern SEXP R_gdk_texture_new_from_resource(SEXP s1);
extern SEXP R_gdk_texture_download(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_texture_get_format(SEXP s1);
extern SEXP R_gdk_texture_get_height(SEXP s1);
extern SEXP R_gdk_texture_get_width(SEXP s1);
extern SEXP R_gdk_texture_save_to_png(SEXP s1, SEXP s2);
extern SEXP R_gdk_texture_save_to_png_bytes(SEXP s1);
extern SEXP R_gdk_texture_save_to_tiff(SEXP s1, SEXP s2);
extern SEXP R_gdk_texture_save_to_tiff_bytes(SEXP s1);
extern SEXP R_gdk_texture_downloader_new(SEXP s1);
extern SEXP R_gdk_texture_downloader_copy(SEXP s1);
extern SEXP R_gdk_texture_downloader_download_bytes(SEXP s1);
extern SEXP R_gdk_texture_downloader_download_into(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_texture_downloader_free(SEXP s1);
extern SEXP R_gdk_texture_downloader_get_format(SEXP s1);
extern SEXP R_gdk_texture_downloader_get_texture(SEXP s1);
extern SEXP R_gdk_texture_downloader_set_format(SEXP s1, SEXP s2);
extern SEXP R_gdk_texture_downloader_set_texture(SEXP s1, SEXP s2);
extern SEXP R_gdk_texture_error_quark(void);
extern SEXP R_gdk_toplevel_begin_move(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gdk_toplevel_begin_resize(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gdk_toplevel_focus(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_get_state(SEXP s1);
extern SEXP R_gdk_toplevel_inhibit_system_shortcuts(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_lower(SEXP s1);
extern SEXP R_gdk_toplevel_minimize(SEXP s1);
extern SEXP R_gdk_toplevel_present(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_restore_system_shortcuts(SEXP s1);
extern SEXP R_gdk_toplevel_set_decorated(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_set_deletable(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_set_icon_list(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_set_modal(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_set_startup_id(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_set_title(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_set_transient_for(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_show_window_menu(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_supports_edge_constraints(SEXP s1);
extern SEXP R_gdk_toplevel_titlebar_gesture(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_layout_new(void);
extern SEXP R_gdk_toplevel_layout_copy(SEXP s1);
extern SEXP R_gdk_toplevel_layout_equal(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_layout_get_fullscreen(SEXP s1);
extern SEXP R_gdk_toplevel_layout_get_fullscreen_monitor(SEXP s1);
extern SEXP R_gdk_toplevel_layout_get_maximized(SEXP s1);
extern SEXP R_gdk_toplevel_layout_get_resizable(SEXP s1);
extern SEXP R_gdk_toplevel_layout_ref(SEXP s1);
extern SEXP R_gdk_toplevel_layout_set_fullscreen(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_toplevel_layout_set_maximized(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_layout_set_resizable(SEXP s1, SEXP s2);
extern SEXP R_gdk_toplevel_layout_unref(SEXP s1);
extern SEXP R_gdk_toplevel_size_get_bounds(SEXP s1);
extern SEXP R_gdk_toplevel_size_set_min_size(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_toplevel_size_set_shadow_width(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gdk_toplevel_size_set_size(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gdk_touch_event_get_emulating_pointer(SEXP s1);
extern SEXP R_gdk_touchpad_event_get_deltas(SEXP s1);
extern SEXP R_gdk_touchpad_event_get_gesture_phase(SEXP s1);
extern SEXP R_gdk_touchpad_event_get_n_fingers(SEXP s1);
extern SEXP R_gdk_touchpad_event_get_pinch_angle_delta(SEXP s1);
extern SEXP R_gdk_touchpad_event_get_pinch_scale(SEXP s1);
extern SEXP R_gdk_vulkan_error_quark(void);
extern SEXP R_gdk_cairo_draw_from_gl(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8, SEXP s9);
extern SEXP R_gdk_cairo_rectangle(SEXP s1, SEXP s2);
extern SEXP R_gdk_cairo_region(SEXP s1, SEXP s2);
extern SEXP R_gdk_cairo_region_create_from_surface(SEXP s1);
extern SEXP R_gdk_cairo_set_source_pixbuf(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gdk_cairo_set_source_rgba(SEXP s1, SEXP s2);
extern SEXP R_gdk_content_deserialize_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gdk_content_deserialize_finish(SEXP s1);
extern SEXP R_gdk_content_register_deserializer(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gdk_content_register_serializer(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gdk_content_serialize_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gdk_content_serialize_finish(SEXP s1);
extern SEXP R_gdk_intern_mime_type(SEXP s1);
extern SEXP R_gdk_keyval_convert_case(SEXP s1);
extern SEXP R_gdk_keyval_from_name(SEXP s1);
extern SEXP R_gdk_keyval_is_lower(SEXP s1);
extern SEXP R_gdk_keyval_is_upper(SEXP s1);
extern SEXP R_gdk_keyval_name(SEXP s1);
extern SEXP R_gdk_keyval_to_lower(SEXP s1);
extern SEXP R_gdk_keyval_to_unicode(SEXP s1);
extern SEXP R_gdk_keyval_to_upper(SEXP s1);
extern SEXP R_gdk_pixbuf_get_from_surface(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gdk_pixbuf_get_from_texture(SEXP s1);
extern SEXP R_gdk_set_allowed_backends(SEXP s1);
extern SEXP R_gdk_unicode_to_keyval(SEXP s1);
extern SEXP R_g_action_name_is_valid(SEXP s1);
extern SEXP R_g_action_parse_detailed_name(SEXP s1);
extern SEXP R_g_action_print_detailed_name(SEXP s1, SEXP s2);
extern SEXP R_g_action_activate(SEXP s1, SEXP s2);
extern SEXP R_g_action_change_state(SEXP s1, SEXP s2);
extern SEXP R_g_action_get_enabled(SEXP s1);
extern SEXP R_g_action_get_name(SEXP s1);
extern SEXP R_g_action_get_parameter_type(SEXP s1);
extern SEXP R_g_action_get_state(SEXP s1);
extern SEXP R_g_action_get_state_hint(SEXP s1);
extern SEXP R_g_action_get_state_type(SEXP s1);
extern SEXP R_g_action_group_action_added(SEXP s1, SEXP s2);
extern SEXP R_g_action_group_action_enabled_changed(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_action_group_action_removed(SEXP s1, SEXP s2);
extern SEXP R_g_action_group_action_state_changed(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_action_group_activate_action(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_action_group_change_action_state(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_action_group_get_action_enabled(SEXP s1, SEXP s2);
extern SEXP R_g_action_group_get_action_parameter_type(SEXP s1, SEXP s2);
extern SEXP R_g_action_group_get_action_state(SEXP s1, SEXP s2);
extern SEXP R_g_action_group_get_action_state_hint(SEXP s1, SEXP s2);
extern SEXP R_g_action_group_get_action_state_type(SEXP s1, SEXP s2);
extern SEXP R_g_action_group_has_action(SEXP s1, SEXP s2);
extern SEXP R_g_action_group_list_actions(SEXP s1);
extern SEXP R_g_action_group_query_action(SEXP s1, SEXP s2);
extern SEXP R_g_action_map_add_action(SEXP s1, SEXP s2);
extern SEXP R_g_action_map_add_action_entries(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_action_map_lookup_action(SEXP s1, SEXP s2);
extern SEXP R_g_action_map_remove_action(SEXP s1, SEXP s2);
extern SEXP R_g_app_info_create_from_commandline(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_app_info_get_all(void);
extern SEXP R_g_app_info_get_all_for_type(SEXP s1);
extern SEXP R_g_app_info_get_default_for_type(SEXP s1, SEXP s2);
extern SEXP R_g_app_info_get_default_for_uri_scheme(SEXP s1);
extern SEXP R_g_app_info_get_fallback_for_type(SEXP s1);
extern SEXP R_g_app_info_get_recommended_for_type(SEXP s1);
extern SEXP R_g_app_info_launch_default_for_uri(SEXP s1, SEXP s2);
extern SEXP R_g_app_info_launch_default_for_uri_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_app_info_launch_default_for_uri_finish(SEXP s1);
extern SEXP R_g_app_info_reset_type_associations(SEXP s1);
extern SEXP R_g_app_info_add_supports_type(SEXP s1, SEXP s2);
extern SEXP R_g_app_info_can_delete(SEXP s1);
extern SEXP R_g_app_info_can_remove_supports_type(SEXP s1);
extern SEXP R_g_app_info_delete(SEXP s1);
extern SEXP R_g_app_info_dup(SEXP s1);
extern SEXP R_g_app_info_equal(SEXP s1, SEXP s2);
extern SEXP R_g_app_info_get_commandline(SEXP s1);
extern SEXP R_g_app_info_get_description(SEXP s1);
extern SEXP R_g_app_info_get_display_name(SEXP s1);
extern SEXP R_g_app_info_get_executable(SEXP s1);
extern SEXP R_g_app_info_get_icon(SEXP s1);
extern SEXP R_g_app_info_get_id(SEXP s1);
extern SEXP R_g_app_info_get_name(SEXP s1);
extern SEXP R_g_app_info_get_supported_types(SEXP s1);
extern SEXP R_g_app_info_launch(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_app_info_launch_uris(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_app_info_remove_supports_type(SEXP s1, SEXP s2);
extern SEXP R_g_app_info_set_as_default_for_extension(SEXP s1, SEXP s2);
extern SEXP R_g_app_info_set_as_default_for_type(SEXP s1, SEXP s2);
extern SEXP R_g_app_info_set_as_last_used_for_type(SEXP s1, SEXP s2);
extern SEXP R_g_app_info_should_show(SEXP s1);
extern SEXP R_g_app_info_supports_files(SEXP s1);
extern SEXP R_g_app_info_supports_uris(SEXP s1);
extern SEXP R_g_app_info_monitor_get(void);
extern SEXP R_g_app_launch_context_new(void);
extern SEXP R_g_app_launch_context_get_display(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_app_launch_context_get_environment(SEXP s1);
extern SEXP R_g_app_launch_context_get_startup_notify_id(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_app_launch_context_launch_failed(SEXP s1, SEXP s2);
extern SEXP R_g_app_launch_context_setenv(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_app_launch_context_unsetenv(SEXP s1, SEXP s2);
extern SEXP R_g_application_new(SEXP s1, SEXP s2);
extern SEXP R_g_application_get_default(void);
extern SEXP R_g_application_id_is_valid(SEXP s1);
extern SEXP R_g_application_activate(SEXP s1);
extern SEXP R_g_application_add_main_option(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_application_add_main_option_entries(SEXP s1, SEXP s2);
extern SEXP R_g_application_add_option_group(SEXP s1, SEXP s2);
extern SEXP R_g_application_bind_busy_property(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_application_get_application_id(SEXP s1);
extern SEXP R_g_application_get_dbus_connection(SEXP s1);
extern SEXP R_g_application_get_dbus_object_path(SEXP s1);
extern SEXP R_g_application_get_flags(SEXP s1);
extern SEXP R_g_application_get_inactivity_timeout(SEXP s1);
extern SEXP R_g_application_get_is_busy(SEXP s1);
extern SEXP R_g_application_get_is_registered(SEXP s1);
extern SEXP R_g_application_get_is_remote(SEXP s1);
extern SEXP R_g_application_get_resource_base_path(SEXP s1);
extern SEXP R_g_application_hold(SEXP s1);
extern SEXP R_g_application_mark_busy(SEXP s1);
extern SEXP R_g_application_open(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_application_quit(SEXP s1);
extern SEXP R_g_application_register(SEXP s1, SEXP s2);
extern SEXP R_g_application_release(SEXP s1);
extern SEXP R_g_application_run(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_application_send_notification(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_application_set_action_group(SEXP s1, SEXP s2);
extern SEXP R_g_application_set_application_id(SEXP s1, SEXP s2);
extern SEXP R_g_application_set_default(SEXP s1);
extern SEXP R_g_application_set_flags(SEXP s1, SEXP s2);
extern SEXP R_g_application_set_inactivity_timeout(SEXP s1, SEXP s2);
extern SEXP R_g_application_set_option_context_description(SEXP s1, SEXP s2);
extern SEXP R_g_application_set_option_context_parameter_string(SEXP s1, SEXP s2);
extern SEXP R_g_application_set_option_context_summary(SEXP s1, SEXP s2);
extern SEXP R_g_application_set_resource_base_path(SEXP s1, SEXP s2);
extern SEXP R_g_application_unbind_busy_property(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_application_unmark_busy(SEXP s1);
extern SEXP R_g_application_withdraw_notification(SEXP s1, SEXP s2);
extern SEXP R_g_application_command_line_create_file_for_arg(SEXP s1, SEXP s2);
extern SEXP R_g_application_command_line_get_arguments(SEXP s1);
extern SEXP R_g_application_command_line_get_cwd(SEXP s1);
extern SEXP R_g_application_command_line_get_environ(SEXP s1);
extern SEXP R_g_application_command_line_get_exit_status(SEXP s1);
extern SEXP R_g_application_command_line_get_is_remote(SEXP s1);
extern SEXP R_g_application_command_line_get_options_dict(SEXP s1);
extern SEXP R_g_application_command_line_get_platform_data(SEXP s1);
extern SEXP R_g_application_command_line_get_stdin(SEXP s1);
extern SEXP R_g_application_command_line_getenv(SEXP s1, SEXP s2);
extern SEXP R_g_application_command_line_set_exit_status(SEXP s1, SEXP s2);
extern SEXP R_g_async_initable_newv_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_async_initable_init_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_async_initable_init_finish(SEXP s1, SEXP s2);
extern SEXP R_g_async_initable_new_finish(SEXP s1, SEXP s2);
extern SEXP R_g_async_result_get_source_object(SEXP s1);
extern SEXP R_g_async_result_get_user_data(SEXP s1);
extern SEXP R_g_async_result_is_tagged(SEXP s1, SEXP s2);
extern SEXP R_g_async_result_legacy_propagate_error(SEXP s1);
extern SEXP R_g_buffered_input_stream_new(SEXP s1);
extern SEXP R_g_buffered_input_stream_new_sized(SEXP s1, SEXP s2);
extern SEXP R_g_buffered_input_stream_fill(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_buffered_input_stream_fill_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_buffered_input_stream_fill_finish(SEXP s1, SEXP s2);
extern SEXP R_g_buffered_input_stream_get_available(SEXP s1);
extern SEXP R_g_buffered_input_stream_get_buffer_size(SEXP s1);
extern SEXP R_g_buffered_input_stream_peek(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_buffered_input_stream_peek_buffer(SEXP s1);
extern SEXP R_g_buffered_input_stream_read_byte(SEXP s1, SEXP s2);
extern SEXP R_g_buffered_input_stream_set_buffer_size(SEXP s1, SEXP s2);
extern SEXP R_g_buffered_output_stream_new(SEXP s1);
extern SEXP R_g_buffered_output_stream_new_sized(SEXP s1, SEXP s2);
extern SEXP R_g_buffered_output_stream_get_auto_grow(SEXP s1);
extern SEXP R_g_buffered_output_stream_get_buffer_size(SEXP s1);
extern SEXP R_g_buffered_output_stream_set_auto_grow(SEXP s1, SEXP s2);
extern SEXP R_g_buffered_output_stream_set_buffer_size(SEXP s1, SEXP s2);
extern SEXP R_g_bytes_icon_new(SEXP s1);
extern SEXP R_g_bytes_icon_get_bytes(SEXP s1);
extern SEXP R_g_cancellable_new(void);
extern SEXP R_g_cancellable_get_current(void);
extern SEXP R_g_cancellable_cancel(SEXP s1);
extern SEXP R_g_cancellable_connect(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_cancellable_disconnect(SEXP s1, SEXP s2);
extern SEXP R_g_cancellable_get_fd(SEXP s1);
extern SEXP R_g_cancellable_is_cancelled(SEXP s1);
extern SEXP R_g_cancellable_make_pollfd(SEXP s1, SEXP s2);
extern SEXP R_g_cancellable_pop_current(SEXP s1);
extern SEXP R_g_cancellable_push_current(SEXP s1);
extern SEXP R_g_cancellable_release_fd(SEXP s1);
extern SEXP R_g_cancellable_reset(SEXP s1);
extern SEXP R_g_cancellable_set_error_if_cancelled(SEXP s1);
extern SEXP R_g_cancellable_source_new(SEXP s1);
extern SEXP R_g_charset_converter_new(SEXP s1, SEXP s2);
extern SEXP R_g_charset_converter_get_num_fallbacks(SEXP s1);
extern SEXP R_g_charset_converter_get_use_fallback(SEXP s1);
extern SEXP R_g_charset_converter_set_use_fallback(SEXP s1, SEXP s2);
extern SEXP R_g_converter_convert(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_converter_reset(SEXP s1);
extern SEXP R_g_converter_input_stream_new(SEXP s1, SEXP s2);
extern SEXP R_g_converter_input_stream_get_converter(SEXP s1);
extern SEXP R_g_converter_output_stream_new(SEXP s1, SEXP s2);
extern SEXP R_g_converter_output_stream_get_converter(SEXP s1);
extern SEXP R_g_credentials_new(void);
extern SEXP R_g_credentials_is_same_user(SEXP s1, SEXP s2);
extern SEXP R_g_credentials_set_native(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_credentials_to_string(SEXP s1);
extern SEXP R_g_data_input_stream_new(SEXP s1);
extern SEXP R_g_data_input_stream_get_byte_order(SEXP s1);
extern SEXP R_g_data_input_stream_get_newline_type(SEXP s1);
extern SEXP R_g_data_input_stream_read_byte(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_int16(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_int32(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_int64(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_line(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_line_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_data_input_stream_read_line_finish(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_line_finish_utf8(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_line_utf8(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_uint16(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_uint32(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_uint64(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_until(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_data_input_stream_read_until_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_data_input_stream_read_until_finish(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_read_upto(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_data_input_stream_read_upto_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_data_input_stream_read_upto_finish(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_set_byte_order(SEXP s1, SEXP s2);
extern SEXP R_g_data_input_stream_set_newline_type(SEXP s1, SEXP s2);
extern SEXP R_g_data_output_stream_new(SEXP s1);
extern SEXP R_g_data_output_stream_get_byte_order(SEXP s1);
extern SEXP R_g_data_output_stream_put_byte(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_data_output_stream_put_int16(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_data_output_stream_put_int32(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_data_output_stream_put_int64(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_data_output_stream_put_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_data_output_stream_put_uint16(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_data_output_stream_put_uint32(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_data_output_stream_put_uint64(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_data_output_stream_set_byte_order(SEXP s1, SEXP s2);
extern SEXP R_g_datagram_based_condition_check(SEXP s1, SEXP s2);
extern SEXP R_g_datagram_based_condition_wait(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_datagram_based_create_source(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_datagram_based_receive_messages(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_datagram_based_send_messages(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_drive_can_eject(SEXP s1);
extern SEXP R_g_drive_can_poll_for_media(SEXP s1);
extern SEXP R_g_drive_can_start(SEXP s1);
extern SEXP R_g_drive_can_start_degraded(SEXP s1);
extern SEXP R_g_drive_can_stop(SEXP s1);
extern SEXP R_g_drive_eject(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_drive_eject_finish(SEXP s1, SEXP s2);
extern SEXP R_g_drive_eject_with_operation(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_drive_eject_with_operation_finish(SEXP s1, SEXP s2);
extern SEXP R_g_drive_enumerate_identifiers(SEXP s1);
extern SEXP R_g_drive_get_icon(SEXP s1);
extern SEXP R_g_drive_get_identifier(SEXP s1, SEXP s2);
extern SEXP R_g_drive_get_name(SEXP s1);
extern SEXP R_g_drive_get_sort_key(SEXP s1);
extern SEXP R_g_drive_get_start_stop_type(SEXP s1);
extern SEXP R_g_drive_get_symbolic_icon(SEXP s1);
extern SEXP R_g_drive_get_volumes(SEXP s1);
extern SEXP R_g_drive_has_media(SEXP s1);
extern SEXP R_g_drive_has_volumes(SEXP s1);
extern SEXP R_g_drive_is_media_check_automatic(SEXP s1);
extern SEXP R_g_drive_is_media_removable(SEXP s1);
extern SEXP R_g_drive_is_removable(SEXP s1);
extern SEXP R_g_drive_poll_for_media(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_drive_poll_for_media_finish(SEXP s1, SEXP s2);
extern SEXP R_g_drive_start(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_drive_start_finish(SEXP s1, SEXP s2);
extern SEXP R_g_drive_stop(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_drive_stop_finish(SEXP s1, SEXP s2);
extern SEXP R_g_emblem_new(SEXP s1);
extern SEXP R_g_emblem_new_with_origin(SEXP s1, SEXP s2);
extern SEXP R_g_emblem_get_icon(SEXP s1);
extern SEXP R_g_emblem_get_origin(SEXP s1);
extern SEXP R_g_emblemed_icon_new(SEXP s1, SEXP s2);
extern SEXP R_g_emblemed_icon_add_emblem(SEXP s1, SEXP s2);
extern SEXP R_g_emblemed_icon_clear_emblems(SEXP s1);
extern SEXP R_g_emblemed_icon_get_emblems(SEXP s1);
extern SEXP R_g_emblemed_icon_get_icon(SEXP s1);
extern SEXP R_g_file_new_for_commandline_arg(SEXP s1);
extern SEXP R_g_file_new_for_commandline_arg_and_cwd(SEXP s1, SEXP s2);
extern SEXP R_g_file_new_for_path(SEXP s1);
extern SEXP R_g_file_new_for_uri(SEXP s1);
extern SEXP R_g_file_new_tmp(SEXP s1);
extern SEXP R_g_file_parse_name(SEXP s1);
extern SEXP R_g_file_append_to(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_append_to_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_append_to_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_copy(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_copy_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8, SEXP s9);
extern SEXP R_g_file_copy_attributes(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_file_copy_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_create(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_create_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_create_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_create_readwrite(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_create_readwrite_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_create_readwrite_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_delete(SEXP s1, SEXP s2);
extern SEXP R_g_file_delete_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_delete_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_dup(SEXP s1);
extern SEXP R_g_file_eject_mountable(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_eject_mountable_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_eject_mountable_with_operation(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_eject_mountable_with_operation_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_enumerate_children(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_file_enumerate_children_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_file_enumerate_children_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_equal(SEXP s1, SEXP s2);
extern SEXP R_g_file_find_enclosing_mount(SEXP s1, SEXP s2);
extern SEXP R_g_file_find_enclosing_mount_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_find_enclosing_mount_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_get_basename(SEXP s1);
extern SEXP R_g_file_get_child(SEXP s1, SEXP s2);
extern SEXP R_g_file_get_child_for_display_name(SEXP s1, SEXP s2);
extern SEXP R_g_file_get_parent(SEXP s1);
extern SEXP R_g_file_get_parse_name(SEXP s1);
extern SEXP R_g_file_get_path(SEXP s1);
extern SEXP R_g_file_get_relative_path(SEXP s1, SEXP s2);
extern SEXP R_g_file_get_uri(SEXP s1);
extern SEXP R_g_file_get_uri_scheme(SEXP s1);
extern SEXP R_g_file_has_parent(SEXP s1, SEXP s2);
extern SEXP R_g_file_has_prefix(SEXP s1, SEXP s2);
extern SEXP R_g_file_has_uri_scheme(SEXP s1, SEXP s2);
extern SEXP R_g_file_hash(SEXP s1);
extern SEXP R_g_file_is_native(SEXP s1);
extern SEXP R_g_file_load_bytes(SEXP s1, SEXP s2);
extern SEXP R_g_file_load_bytes_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_file_load_bytes_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_load_contents(SEXP s1, SEXP s2);
extern SEXP R_g_file_load_contents_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_file_load_contents_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_load_partial_contents_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_make_directory(SEXP s1, SEXP s2);
extern SEXP R_g_file_make_directory_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_make_directory_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_make_directory_with_parents(SEXP s1, SEXP s2);
extern SEXP R_g_file_make_symbolic_link(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_measure_disk_usage(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_measure_disk_usage_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_monitor(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_monitor_directory(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_monitor_file(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_mount_enclosing_volume(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_mount_enclosing_volume_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_mount_mountable(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_mount_mountable_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_move(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_open_readwrite(SEXP s1, SEXP s2);
extern SEXP R_g_file_open_readwrite_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_open_readwrite_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_peek_path(SEXP s1);
extern SEXP R_g_file_poll_mountable(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_file_poll_mountable_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_query_default_handler(SEXP s1, SEXP s2);
extern SEXP R_g_file_query_exists(SEXP s1, SEXP s2);
extern SEXP R_g_file_query_file_type(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_query_filesystem_info(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_query_filesystem_info_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_query_filesystem_info_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_query_info(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_file_query_info_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_file_query_info_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_query_settable_attributes(SEXP s1, SEXP s2);
extern SEXP R_g_file_query_writable_namespaces(SEXP s1, SEXP s2);
extern SEXP R_g_file_read(SEXP s1, SEXP s2);
extern SEXP R_g_file_read_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_read_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_replace(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_replace_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_g_file_replace_contents(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_file_replace_contents_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8, SEXP s9);
extern SEXP R_g_file_replace_contents_bytes_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_g_file_replace_contents_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_replace_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_replace_readwrite(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_replace_readwrite_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_g_file_replace_readwrite_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_resolve_relative_path(SEXP s1, SEXP s2);
extern SEXP R_g_file_set_attribute(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_set_attribute_byte_string(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_set_attribute_int32(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_set_attribute_int64(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_set_attribute_string(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_set_attribute_uint32(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_set_attribute_uint64(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_set_attributes_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_file_set_attributes_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_set_attributes_from_info(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_file_set_display_name(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_set_display_name_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_set_display_name_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_start_mountable(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_start_mountable_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_stop_mountable(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_stop_mountable_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_supports_thread_contexts(SEXP s1);
extern SEXP R_g_file_trash(SEXP s1, SEXP s2);
extern SEXP R_g_file_trash_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_trash_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_unmount_mountable(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_unmount_mountable_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_unmount_mountable_with_operation(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_unmount_mountable_with_operation_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_attribute_info_list_new(void);
extern SEXP R_g_file_attribute_info_list_add(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_file_attribute_info_list_dup(SEXP s1);
extern SEXP R_g_file_attribute_info_list_lookup(SEXP s1, SEXP s2);
extern SEXP R_g_file_attribute_info_list_ref(SEXP s1);
extern SEXP R_g_file_attribute_info_list_unref(SEXP s1);
extern SEXP R_g_file_attribute_matcher_new(SEXP s1);
extern SEXP R_g_file_attribute_matcher_enumerate_namespace(SEXP s1, SEXP s2);
extern SEXP R_g_file_attribute_matcher_enumerate_next(SEXP s1);
extern SEXP R_g_file_attribute_matcher_matches(SEXP s1, SEXP s2);
extern SEXP R_g_file_attribute_matcher_matches_only(SEXP s1, SEXP s2);
extern SEXP R_g_file_attribute_matcher_ref(SEXP s1);
extern SEXP R_g_file_attribute_matcher_subtract(SEXP s1, SEXP s2);
extern SEXP R_g_file_attribute_matcher_to_string(SEXP s1);
extern SEXP R_g_file_attribute_matcher_unref(SEXP s1);
extern SEXP R_g_file_enumerator_close(SEXP s1, SEXP s2);
extern SEXP R_g_file_enumerator_close_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_file_enumerator_close_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_enumerator_get_child(SEXP s1, SEXP s2);
extern SEXP R_g_file_enumerator_get_container(SEXP s1);
extern SEXP R_g_file_enumerator_has_pending(SEXP s1);
extern SEXP R_g_file_enumerator_is_closed(SEXP s1);
extern SEXP R_g_file_enumerator_iterate(SEXP s1, SEXP s2);
extern SEXP R_g_file_enumerator_next_file(SEXP s1, SEXP s2);
extern SEXP R_g_file_enumerator_next_files_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_enumerator_next_files_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_enumerator_set_pending(SEXP s1, SEXP s2);
extern SEXP R_g_file_io_stream_get_etag(SEXP s1);
extern SEXP R_g_file_io_stream_query_info(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_io_stream_query_info_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_io_stream_query_info_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_icon_new(SEXP s1);
extern SEXP R_g_file_icon_get_file(SEXP s1);
extern SEXP R_g_file_info_new(void);
extern SEXP R_g_file_info_clear_status(SEXP s1);
extern SEXP R_g_file_info_copy_into(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_dup(SEXP s1);
extern SEXP R_g_file_info_get_attribute_as_string(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_boolean(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_byte_string(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_data(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_int32(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_int64(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_object(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_status(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_string(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_stringv(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_type(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_uint32(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_attribute_uint64(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_get_content_type(SEXP s1);
extern SEXP R_g_file_info_get_deletion_date(SEXP s1);
extern SEXP R_g_file_info_get_display_name(SEXP s1);
extern SEXP R_g_file_info_get_edit_name(SEXP s1);
extern SEXP R_g_file_info_get_etag(SEXP s1);
extern SEXP R_g_file_info_get_file_type(SEXP s1);
extern SEXP R_g_file_info_get_icon(SEXP s1);
extern SEXP R_g_file_info_get_is_backup(SEXP s1);
extern SEXP R_g_file_info_get_is_hidden(SEXP s1);
extern SEXP R_g_file_info_get_is_symlink(SEXP s1);
extern SEXP R_g_file_info_get_modification_time(SEXP s1);
extern SEXP R_g_file_info_get_name(SEXP s1);
extern SEXP R_g_file_info_get_size(SEXP s1);
extern SEXP R_g_file_info_get_sort_order(SEXP s1);
extern SEXP R_g_file_info_get_symbolic_icon(SEXP s1);
extern SEXP R_g_file_info_get_symlink_target(SEXP s1);
extern SEXP R_g_file_info_has_attribute(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_has_namespace(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_list_attributes(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_remove_attribute(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_attribute(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_file_info_set_attribute_boolean(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_info_set_attribute_byte_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_info_set_attribute_int32(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_info_set_attribute_int64(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_info_set_attribute_mask(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_attribute_object(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_info_set_attribute_status(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_info_set_attribute_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_info_set_attribute_stringv(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_info_set_attribute_uint32(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_info_set_attribute_uint64(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_info_set_content_type(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_display_name(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_edit_name(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_file_type(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_icon(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_is_hidden(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_is_symlink(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_modification_time(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_name(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_size(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_sort_order(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_symbolic_icon(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_set_symlink_target(SEXP s1, SEXP s2);
extern SEXP R_g_file_info_unset_attribute_mask(SEXP s1);
extern SEXP R_g_file_input_stream_query_info(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_input_stream_query_info_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_input_stream_query_info_finish(SEXP s1, SEXP s2);
extern SEXP R_g_file_monitor_cancel(SEXP s1);
extern SEXP R_g_file_monitor_emit_event(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_file_monitor_is_cancelled(SEXP s1);
extern SEXP R_g_file_monitor_set_rate_limit(SEXP s1, SEXP s2);
extern SEXP R_g_file_output_stream_get_etag(SEXP s1);
extern SEXP R_g_file_output_stream_query_info(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_output_stream_query_info_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_file_output_stream_query_info_finish(SEXP s1, SEXP s2);
extern SEXP R_g_filename_completer_new(void);
extern SEXP R_g_filename_completer_get_completion_suffix(SEXP s1, SEXP s2);
extern SEXP R_g_filename_completer_get_completions(SEXP s1, SEXP s2);
extern SEXP R_g_filename_completer_set_dirs_only(SEXP s1, SEXP s2);
extern SEXP R_g_filter_input_stream_get_base_stream(SEXP s1);
extern SEXP R_g_filter_input_stream_get_close_base_stream(SEXP s1);
extern SEXP R_g_filter_input_stream_set_close_base_stream(SEXP s1, SEXP s2);
extern SEXP R_g_filter_output_stream_get_base_stream(SEXP s1);
extern SEXP R_g_filter_output_stream_get_close_base_stream(SEXP s1);
extern SEXP R_g_filter_output_stream_set_close_base_stream(SEXP s1, SEXP s2);
extern SEXP R_g_io_extension_get_name(SEXP s1);
extern SEXP R_g_io_extension_get_priority(SEXP s1);
extern SEXP R_g_io_extension_get_type(SEXP s1);
extern SEXP R_g_io_extension_point_get_extension_by_name(SEXP s1, SEXP s2);
extern SEXP R_g_io_extension_point_get_extensions(SEXP s1);
extern SEXP R_g_io_extension_point_get_required_type(SEXP s1);
extern SEXP R_g_io_extension_point_set_required_type(SEXP s1, SEXP s2);
extern SEXP R_g_io_extension_point_implement(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_io_extension_point_lookup(SEXP s1);
extern SEXP R_g_io_extension_point_register(SEXP s1);
extern SEXP R_g_io_scheduler_job_send_to_mainloop(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_io_scheduler_job_send_to_mainloop_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_io_stream_splice_finish(SEXP s1);
extern SEXP R_g_io_stream_clear_pending(SEXP s1);
extern SEXP R_g_io_stream_close(SEXP s1, SEXP s2);
extern SEXP R_g_io_stream_close_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_io_stream_close_finish(SEXP s1, SEXP s2);
extern SEXP R_g_io_stream_get_input_stream(SEXP s1);
extern SEXP R_g_io_stream_get_output_stream(SEXP s1);
extern SEXP R_g_io_stream_has_pending(SEXP s1);
extern SEXP R_g_io_stream_is_closed(SEXP s1);
extern SEXP R_g_io_stream_set_pending(SEXP s1);
extern SEXP R_g_io_stream_splice_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_icon_deserialize(SEXP s1);
extern SEXP R_g_icon_new_for_string(SEXP s1);
extern SEXP R_g_icon_equal(SEXP s1, SEXP s2);
extern SEXP R_g_icon_hash(SEXP s1);
extern SEXP R_g_icon_serialize(SEXP s1);
extern SEXP R_g_icon_to_string(SEXP s1);
extern SEXP R_g_inet_address_new_any(SEXP s1);
extern SEXP R_g_inet_address_new_from_bytes(SEXP s1, SEXP s2);
extern SEXP R_g_inet_address_new_from_string(SEXP s1);
extern SEXP R_g_inet_address_new_loopback(SEXP s1);
extern SEXP R_g_inet_address_equal(SEXP s1, SEXP s2);
extern SEXP R_g_inet_address_get_family(SEXP s1);
extern SEXP R_g_inet_address_get_is_any(SEXP s1);
extern SEXP R_g_inet_address_get_is_link_local(SEXP s1);
extern SEXP R_g_inet_address_get_is_loopback(SEXP s1);
extern SEXP R_g_inet_address_get_is_mc_global(SEXP s1);
extern SEXP R_g_inet_address_get_is_mc_link_local(SEXP s1);
extern SEXP R_g_inet_address_get_is_mc_node_local(SEXP s1);
extern SEXP R_g_inet_address_get_is_mc_org_local(SEXP s1);
extern SEXP R_g_inet_address_get_is_mc_site_local(SEXP s1);
extern SEXP R_g_inet_address_get_is_multicast(SEXP s1);
extern SEXP R_g_inet_address_get_is_site_local(SEXP s1);
extern SEXP R_g_inet_address_get_native_size(SEXP s1);
extern SEXP R_g_inet_address_to_string(SEXP s1);
extern SEXP R_g_inet_address_mask_new(SEXP s1, SEXP s2);
extern SEXP R_g_inet_address_mask_new_from_string(SEXP s1);
extern SEXP R_g_inet_address_mask_equal(SEXP s1, SEXP s2);
extern SEXP R_g_inet_address_mask_get_address(SEXP s1);
extern SEXP R_g_inet_address_mask_get_family(SEXP s1);
extern SEXP R_g_inet_address_mask_get_length(SEXP s1);
extern SEXP R_g_inet_address_mask_matches(SEXP s1, SEXP s2);
extern SEXP R_g_inet_address_mask_to_string(SEXP s1);
extern SEXP R_g_inet_socket_address_new(SEXP s1, SEXP s2);
extern SEXP R_g_inet_socket_address_new_from_string(SEXP s1, SEXP s2);
extern SEXP R_g_inet_socket_address_get_address(SEXP s1);
extern SEXP R_g_inet_socket_address_get_flowinfo(SEXP s1);
extern SEXP R_g_inet_socket_address_get_port(SEXP s1);
extern SEXP R_g_inet_socket_address_get_scope_id(SEXP s1);
extern SEXP R_g_initable_newv(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_initable_init(SEXP s1, SEXP s2);
extern SEXP R_g_input_stream_clear_pending(SEXP s1);
extern SEXP R_g_input_stream_close(SEXP s1, SEXP s2);
extern SEXP R_g_input_stream_close_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_input_stream_close_finish(SEXP s1, SEXP s2);
extern SEXP R_g_input_stream_has_pending(SEXP s1);
extern SEXP R_g_input_stream_is_closed(SEXP s1);
extern SEXP R_g_input_stream_read(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_input_stream_read_all(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_input_stream_read_all_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_input_stream_read_all_finish(SEXP s1, SEXP s2);
extern SEXP R_g_input_stream_read_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_input_stream_read_bytes(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_input_stream_read_bytes_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_input_stream_read_bytes_finish(SEXP s1, SEXP s2);
extern SEXP R_g_input_stream_read_finish(SEXP s1, SEXP s2);
extern SEXP R_g_input_stream_set_pending(SEXP s1);
extern SEXP R_g_input_stream_skip(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_input_stream_skip_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_input_stream_skip_finish(SEXP s1, SEXP s2);
extern SEXP R_g_list_model_get_item_type(SEXP s1);
extern SEXP R_g_list_model_get_n_items(SEXP s1);
extern SEXP R_g_list_model_get_object(SEXP s1, SEXP s2);
extern SEXP R_g_list_model_items_changed(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_list_store_new(SEXP s1);
extern SEXP R_g_list_store_append(SEXP s1, SEXP s2);
extern SEXP R_g_list_store_insert(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_list_store_insert_sorted(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_list_store_remove(SEXP s1, SEXP s2);
extern SEXP R_g_list_store_remove_all(SEXP s1);
extern SEXP R_g_list_store_sort(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_list_store_splice(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_loadable_icon_load(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_loadable_icon_load_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_loadable_icon_load_finish(SEXP s1, SEXP s2);
extern SEXP R_g_memory_input_stream_new(void);
extern SEXP R_g_memory_input_stream_new_from_bytes(SEXP s1);
extern SEXP R_g_memory_input_stream_new_from_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_memory_input_stream_add_bytes(SEXP s1, SEXP s2);
extern SEXP R_g_memory_input_stream_add_data(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_memory_output_stream_new_resizable(void);
extern SEXP R_g_memory_output_stream_get_data(SEXP s1);
extern SEXP R_g_memory_output_stream_get_data_size(SEXP s1);
extern SEXP R_g_memory_output_stream_get_size(SEXP s1);
extern SEXP R_g_memory_output_stream_steal_as_bytes(SEXP s1);
extern SEXP R_g_memory_output_stream_steal_data(SEXP s1);
extern SEXP R_g_menu_new(void);
extern SEXP R_g_menu_append(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_append_item(SEXP s1, SEXP s2);
extern SEXP R_g_menu_append_section(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_append_submenu(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_freeze(SEXP s1);
extern SEXP R_g_menu_insert(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_menu_insert_item(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_insert_section(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_menu_insert_submenu(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_menu_prepend(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_prepend_item(SEXP s1, SEXP s2);
extern SEXP R_g_menu_prepend_section(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_prepend_submenu(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_remove(SEXP s1, SEXP s2);
extern SEXP R_g_menu_remove_all(SEXP s1);
extern SEXP R_g_menu_attribute_iter_get_name(SEXP s1);
extern SEXP R_g_menu_attribute_iter_get_next(SEXP s1);
extern SEXP R_g_menu_attribute_iter_get_value(SEXP s1);
extern SEXP R_g_menu_attribute_iter_next(SEXP s1);
extern SEXP R_g_menu_item_new(SEXP s1, SEXP s2);
extern SEXP R_g_menu_item_new_from_model(SEXP s1, SEXP s2);
extern SEXP R_g_menu_item_new_section(SEXP s1, SEXP s2);
extern SEXP R_g_menu_item_new_submenu(SEXP s1, SEXP s2);
extern SEXP R_g_menu_item_get_attribute_value(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_item_get_link(SEXP s1, SEXP s2);
extern SEXP R_g_menu_item_set_action_and_target_value(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_item_set_attribute_value(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_item_set_detailed_action(SEXP s1, SEXP s2);
extern SEXP R_g_menu_item_set_icon(SEXP s1, SEXP s2);
extern SEXP R_g_menu_item_set_label(SEXP s1, SEXP s2);
extern SEXP R_g_menu_item_set_link(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_item_set_section(SEXP s1, SEXP s2);
extern SEXP R_g_menu_item_set_submenu(SEXP s1, SEXP s2);
extern SEXP R_g_menu_link_iter_get_name(SEXP s1);
extern SEXP R_g_menu_link_iter_get_next(SEXP s1);
extern SEXP R_g_menu_link_iter_get_value(SEXP s1);
extern SEXP R_g_menu_link_iter_next(SEXP s1);
extern SEXP R_g_menu_model_get_item_attribute_value(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_menu_model_get_item_link(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_menu_model_get_n_items(SEXP s1);
extern SEXP R_g_menu_model_is_mutable(SEXP s1);
extern SEXP R_g_menu_model_items_changed(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_menu_model_iterate_item_attributes(SEXP s1, SEXP s2);
extern SEXP R_g_menu_model_iterate_item_links(SEXP s1, SEXP s2);
extern SEXP R_g_mount_can_eject(SEXP s1);
extern SEXP R_g_mount_can_unmount(SEXP s1);
extern SEXP R_g_mount_eject(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_mount_eject_finish(SEXP s1, SEXP s2);
extern SEXP R_g_mount_eject_with_operation(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_mount_eject_with_operation_finish(SEXP s1, SEXP s2);
extern SEXP R_g_mount_get_default_location(SEXP s1);
extern SEXP R_g_mount_get_drive(SEXP s1);
extern SEXP R_g_mount_get_icon(SEXP s1);
extern SEXP R_g_mount_get_name(SEXP s1);
extern SEXP R_g_mount_get_root(SEXP s1);
extern SEXP R_g_mount_get_sort_key(SEXP s1);
extern SEXP R_g_mount_get_symbolic_icon(SEXP s1);
extern SEXP R_g_mount_get_uuid(SEXP s1);
extern SEXP R_g_mount_get_volume(SEXP s1);
extern SEXP R_g_mount_guess_content_type(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_mount_guess_content_type_finish(SEXP s1, SEXP s2);
extern SEXP R_g_mount_guess_content_type_sync(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_mount_is_shadowed(SEXP s1);
extern SEXP R_g_mount_remount(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_mount_remount_finish(SEXP s1, SEXP s2);
extern SEXP R_g_mount_shadow(SEXP s1);
extern SEXP R_g_mount_unmount(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_mount_unmount_finish(SEXP s1, SEXP s2);
extern SEXP R_g_mount_unmount_with_operation(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_mount_unmount_with_operation_finish(SEXP s1, SEXP s2);
extern SEXP R_g_mount_unshadow(SEXP s1);
extern SEXP R_g_mount_operation_new(void);
extern SEXP R_g_mount_operation_get_anonymous(SEXP s1);
extern SEXP R_g_mount_operation_get_choice(SEXP s1);
extern SEXP R_g_mount_operation_get_domain(SEXP s1);
extern SEXP R_g_mount_operation_get_password(SEXP s1);
extern SEXP R_g_mount_operation_get_password_save(SEXP s1);
extern SEXP R_g_mount_operation_get_username(SEXP s1);
extern SEXP R_g_mount_operation_reply(SEXP s1, SEXP s2);
extern SEXP R_g_mount_operation_set_anonymous(SEXP s1, SEXP s2);
extern SEXP R_g_mount_operation_set_choice(SEXP s1, SEXP s2);
extern SEXP R_g_mount_operation_set_domain(SEXP s1, SEXP s2);
extern SEXP R_g_mount_operation_set_password(SEXP s1, SEXP s2);
extern SEXP R_g_mount_operation_set_password_save(SEXP s1, SEXP s2);
extern SEXP R_g_mount_operation_set_username(SEXP s1, SEXP s2);
extern SEXP R_g_native_socket_address_new(SEXP s1, SEXP s2);
extern SEXP R_g_network_address_new(SEXP s1, SEXP s2);
extern SEXP R_g_network_address_new_loopback(SEXP s1);
extern SEXP R_g_network_address_parse(SEXP s1, SEXP s2);
extern SEXP R_g_network_address_parse_uri(SEXP s1, SEXP s2);
extern SEXP R_g_network_address_get_hostname(SEXP s1);
extern SEXP R_g_network_address_get_port(SEXP s1);
extern SEXP R_g_network_address_get_scheme(SEXP s1);
extern SEXP R_g_network_monitor_get_default(void);
extern SEXP R_g_network_monitor_can_reach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_network_monitor_can_reach_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_network_monitor_can_reach_finish(SEXP s1, SEXP s2);
extern SEXP R_g_network_monitor_get_connectivity(SEXP s1);
extern SEXP R_g_network_monitor_get_network_available(SEXP s1);
extern SEXP R_g_network_monitor_get_network_metered(SEXP s1);
extern SEXP R_g_network_service_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_network_service_get_domain(SEXP s1);
extern SEXP R_g_network_service_get_protocol(SEXP s1);
extern SEXP R_g_network_service_get_scheme(SEXP s1);
extern SEXP R_g_network_service_get_service(SEXP s1);
extern SEXP R_g_network_service_set_scheme(SEXP s1, SEXP s2);
extern SEXP R_g_notification_new(SEXP s1);
extern SEXP R_g_notification_add_button(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_notification_add_button_with_target_value(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_notification_set_body(SEXP s1, SEXP s2);
extern SEXP R_g_notification_set_default_action(SEXP s1, SEXP s2);
extern SEXP R_g_notification_set_default_action_and_target_value(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_notification_set_icon(SEXP s1, SEXP s2);
extern SEXP R_g_notification_set_priority(SEXP s1, SEXP s2);
extern SEXP R_g_notification_set_title(SEXP s1, SEXP s2);
extern SEXP R_g_notification_set_urgent(SEXP s1, SEXP s2);
extern SEXP R_g_output_stream_clear_pending(SEXP s1);
extern SEXP R_g_output_stream_close(SEXP s1, SEXP s2);
extern SEXP R_g_output_stream_close_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_output_stream_close_finish(SEXP s1, SEXP s2);
extern SEXP R_g_output_stream_flush(SEXP s1, SEXP s2);
extern SEXP R_g_output_stream_flush_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_output_stream_flush_finish(SEXP s1, SEXP s2);
extern SEXP R_g_output_stream_has_pending(SEXP s1);
extern SEXP R_g_output_stream_is_closed(SEXP s1);
extern SEXP R_g_output_stream_is_closing(SEXP s1);
extern SEXP R_g_output_stream_set_pending(SEXP s1);
extern SEXP R_g_output_stream_splice(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_output_stream_splice_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_output_stream_splice_finish(SEXP s1, SEXP s2);
extern SEXP R_g_output_stream_write(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_output_stream_write_all(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_output_stream_write_all_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_output_stream_write_all_finish(SEXP s1, SEXP s2);
extern SEXP R_g_output_stream_write_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_output_stream_write_bytes(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_output_stream_write_bytes_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_output_stream_write_bytes_finish(SEXP s1, SEXP s2);
extern SEXP R_g_output_stream_write_finish(SEXP s1, SEXP s2);
extern SEXP R_g_permission_acquire(SEXP s1, SEXP s2);
extern SEXP R_g_permission_acquire_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_permission_acquire_finish(SEXP s1, SEXP s2);
extern SEXP R_g_permission_get_allowed(SEXP s1);
extern SEXP R_g_permission_get_can_acquire(SEXP s1);
extern SEXP R_g_permission_get_can_release(SEXP s1);
extern SEXP R_g_permission_impl_update(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_permission_release(SEXP s1, SEXP s2);
extern SEXP R_g_permission_release_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_permission_release_finish(SEXP s1, SEXP s2);
extern SEXP R_g_pollable_input_stream_can_poll(SEXP s1);
extern SEXP R_g_pollable_input_stream_create_source(SEXP s1, SEXP s2);
extern SEXP R_g_pollable_input_stream_is_readable(SEXP s1);
extern SEXP R_g_pollable_input_stream_read_nonblocking(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_pollable_output_stream_can_poll(SEXP s1);
extern SEXP R_g_pollable_output_stream_create_source(SEXP s1, SEXP s2);
extern SEXP R_g_pollable_output_stream_is_writable(SEXP s1);
extern SEXP R_g_pollable_output_stream_write_nonblocking(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_property_action_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_proxy_get_default_for_protocol(SEXP s1);
extern SEXP R_g_proxy_connect(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_proxy_connect_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_proxy_connect_finish(SEXP s1, SEXP s2);
extern SEXP R_g_proxy_supports_hostname(SEXP s1);
extern SEXP R_g_proxy_address_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_proxy_address_get_destination_hostname(SEXP s1);
extern SEXP R_g_proxy_address_get_destination_port(SEXP s1);
extern SEXP R_g_proxy_address_get_destination_protocol(SEXP s1);
extern SEXP R_g_proxy_address_get_password(SEXP s1);
extern SEXP R_g_proxy_address_get_protocol(SEXP s1);
extern SEXP R_g_proxy_address_get_uri(SEXP s1);
extern SEXP R_g_proxy_address_get_username(SEXP s1);
extern SEXP R_g_proxy_resolver_get_default(void);
extern SEXP R_g_proxy_resolver_is_supported(SEXP s1);
extern SEXP R_g_proxy_resolver_lookup(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_proxy_resolver_lookup_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_proxy_resolver_lookup_finish(SEXP s1, SEXP s2);
extern SEXP R_g_remote_action_group_activate_action_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_remote_action_group_change_action_state_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_resolver_get_default(void);
extern SEXP R_g_resolver_lookup_by_address(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_resolver_lookup_by_address_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_resolver_lookup_by_address_finish(SEXP s1, SEXP s2);
extern SEXP R_g_resolver_lookup_by_name(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_resolver_lookup_by_name_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_resolver_lookup_by_name_finish(SEXP s1, SEXP s2);
extern SEXP R_g_resolver_lookup_records(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_resolver_lookup_records_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_resolver_lookup_records_finish(SEXP s1, SEXP s2);
extern SEXP R_g_resolver_lookup_service(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_resolver_lookup_service_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_resolver_lookup_service_finish(SEXP s1, SEXP s2);
extern SEXP R_g_resolver_set_default(SEXP s1);
extern SEXP R_g_resolver_error_quark(void);
extern SEXP R_g_resource_new_from_data(SEXP s1);
extern SEXP R_g_resource_enumerate_children(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_resource_get_info(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_resource_lookup_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_resource_open_stream(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_resource_ref(SEXP s1);
extern SEXP R_g_resource_unref(SEXP s1);
extern SEXP R_g_resource_load(SEXP s1);
extern SEXP R_g_resource_error_quark(void);
extern SEXP R_g_seekable_can_seek(SEXP s1);
extern SEXP R_g_seekable_can_truncate(SEXP s1);
extern SEXP R_g_seekable_seek(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_seekable_tell(SEXP s1);
extern SEXP R_g_seekable_truncate(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_new(SEXP s1);
extern SEXP R_g_settings_new_full(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_new_with_backend(SEXP s1, SEXP s2);
extern SEXP R_g_settings_new_with_backend_and_path(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_new_with_path(SEXP s1, SEXP s2);
extern SEXP R_g_settings_list_relocatable_schemas(void);
extern SEXP R_g_settings_list_schemas(void);
extern SEXP R_g_settings_sync(void);
extern SEXP R_g_settings_unbind(SEXP s1, SEXP s2);
extern SEXP R_g_settings_apply(SEXP s1);
extern SEXP R_g_settings_bind(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_settings_bind_writable(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_settings_create_action(SEXP s1, SEXP s2);
extern SEXP R_g_settings_delay(SEXP s1);
extern SEXP R_g_settings_get_boolean(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_child(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_default_value(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_double(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_enum(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_flags(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_has_unapplied(SEXP s1);
extern SEXP R_g_settings_get_int(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_int64(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_mapped(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_settings_get_range(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_string(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_strv(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_uint(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_uint64(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_user_value(SEXP s1, SEXP s2);
extern SEXP R_g_settings_get_value(SEXP s1, SEXP s2);
extern SEXP R_g_settings_is_writable(SEXP s1, SEXP s2);
extern SEXP R_g_settings_list_children(SEXP s1);
extern SEXP R_g_settings_list_keys(SEXP s1);
extern SEXP R_g_settings_range_check(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_reset(SEXP s1, SEXP s2);
extern SEXP R_g_settings_revert(SEXP s1);
extern SEXP R_g_settings_set_boolean(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_set_double(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_set_enum(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_set_flags(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_set_int(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_set_int64(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_set_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_set_strv(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_set_uint(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_set_uint64(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_set_value(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_backend_flatten_tree(SEXP s1);
extern SEXP R_g_settings_backend_get_default(void);
extern SEXP R_g_settings_backend_changed(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_backend_changed_tree(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_backend_keys_changed(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_settings_backend_path_changed(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_backend_path_writable_changed(SEXP s1, SEXP s2);
extern SEXP R_g_settings_backend_writable_changed(SEXP s1, SEXP s2);
extern SEXP R_g_settings_schema_get_id(SEXP s1);
extern SEXP R_g_settings_schema_get_key(SEXP s1, SEXP s2);
extern SEXP R_g_settings_schema_get_path(SEXP s1);
extern SEXP R_g_settings_schema_has_key(SEXP s1, SEXP s2);
extern SEXP R_g_settings_schema_list_children(SEXP s1);
extern SEXP R_g_settings_schema_list_keys(SEXP s1);
extern SEXP R_g_settings_schema_ref(SEXP s1);
extern SEXP R_g_settings_schema_unref(SEXP s1);
extern SEXP R_g_settings_schema_key_get_default_value(SEXP s1);
extern SEXP R_g_settings_schema_key_get_description(SEXP s1);
extern SEXP R_g_settings_schema_key_get_name(SEXP s1);
extern SEXP R_g_settings_schema_key_get_range(SEXP s1);
extern SEXP R_g_settings_schema_key_get_summary(SEXP s1);
extern SEXP R_g_settings_schema_key_get_value_type(SEXP s1);
extern SEXP R_g_settings_schema_key_range_check(SEXP s1, SEXP s2);
extern SEXP R_g_settings_schema_key_ref(SEXP s1);
extern SEXP R_g_settings_schema_key_unref(SEXP s1);
extern SEXP R_g_settings_schema_source_new_from_directory(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_schema_source_list_schemas(SEXP s1, SEXP s2);
extern SEXP R_g_settings_schema_source_lookup(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_settings_schema_source_ref(SEXP s1);
extern SEXP R_g_settings_schema_source_unref(SEXP s1);
extern SEXP R_g_settings_schema_source_get_default(void);
extern SEXP R_g_simple_action_new(SEXP s1, SEXP s2);
extern SEXP R_g_simple_action_new_stateful(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_simple_action_set_enabled(SEXP s1, SEXP s2);
extern SEXP R_g_simple_action_set_state(SEXP s1, SEXP s2);
extern SEXP R_g_simple_action_set_state_hint(SEXP s1, SEXP s2);
extern SEXP R_g_simple_action_group_new(void);
extern SEXP R_g_simple_action_group_add_entries(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_simple_action_group_insert(SEXP s1, SEXP s2);
extern SEXP R_g_simple_action_group_lookup(SEXP s1, SEXP s2);
extern SEXP R_g_simple_action_group_remove(SEXP s1, SEXP s2);
extern SEXP R_g_simple_async_result_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_simple_async_result_new_from_error(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_simple_async_result_is_valid(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_simple_async_result_complete(SEXP s1);
extern SEXP R_g_simple_async_result_complete_in_idle(SEXP s1);
extern SEXP R_g_simple_async_result_get_op_res_gboolean(SEXP s1);
extern SEXP R_g_simple_async_result_get_op_res_gssize(SEXP s1);
extern SEXP R_g_simple_async_result_propagate_error(SEXP s1);
extern SEXP R_g_simple_async_result_set_check_cancellable(SEXP s1, SEXP s2);
extern SEXP R_g_simple_async_result_set_from_error(SEXP s1, SEXP s2);
extern SEXP R_g_simple_async_result_set_handle_cancellation(SEXP s1, SEXP s2);
extern SEXP R_g_simple_async_result_set_op_res_gboolean(SEXP s1, SEXP s2);
extern SEXP R_g_simple_async_result_set_op_res_gssize(SEXP s1, SEXP s2);
extern SEXP R_g_simple_io_stream_new(SEXP s1, SEXP s2);
extern SEXP R_g_simple_permission_new(SEXP s1);
extern SEXP R_g_simple_proxy_resolver_new(SEXP s1, SEXP s2);
extern SEXP R_g_simple_proxy_resolver_set_default_proxy(SEXP s1, SEXP s2);
extern SEXP R_g_simple_proxy_resolver_set_ignore_hosts(SEXP s1, SEXP s2);
extern SEXP R_g_simple_proxy_resolver_set_uri_proxy(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_new_from_fd(SEXP s1);
extern SEXP R_g_socket_accept(SEXP s1, SEXP s2);
extern SEXP R_g_socket_bind(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_check_connect_result(SEXP s1);
extern SEXP R_g_socket_close(SEXP s1);
extern SEXP R_g_socket_condition_check(SEXP s1, SEXP s2);
extern SEXP R_g_socket_condition_timed_wait(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_condition_wait(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_connect(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_connection_factory_create_connection(SEXP s1);
extern SEXP R_g_socket_get_available_bytes(SEXP s1);
extern SEXP R_g_socket_get_blocking(SEXP s1);
extern SEXP R_g_socket_get_broadcast(SEXP s1);
extern SEXP R_g_socket_get_credentials(SEXP s1);
extern SEXP R_g_socket_get_family(SEXP s1);
extern SEXP R_g_socket_get_fd(SEXP s1);
extern SEXP R_g_socket_get_keepalive(SEXP s1);
extern SEXP R_g_socket_get_listen_backlog(SEXP s1);
extern SEXP R_g_socket_get_local_address(SEXP s1);
extern SEXP R_g_socket_get_multicast_loopback(SEXP s1);
extern SEXP R_g_socket_get_multicast_ttl(SEXP s1);
extern SEXP R_g_socket_get_option(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_get_protocol(SEXP s1);
extern SEXP R_g_socket_get_remote_address(SEXP s1);
extern SEXP R_g_socket_get_socket_type(SEXP s1);
extern SEXP R_g_socket_get_timeout(SEXP s1);
extern SEXP R_g_socket_get_ttl(SEXP s1);
extern SEXP R_g_socket_is_closed(SEXP s1);
extern SEXP R_g_socket_is_connected(SEXP s1);
extern SEXP R_g_socket_join_multicast_group(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_join_multicast_group_ssm(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_leave_multicast_group(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_leave_multicast_group_ssm(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_listen(SEXP s1);
extern SEXP R_g_socket_receive(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_receive_from(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_receive_message(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_receive_messages(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_socket_receive_with_blocking(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_send(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_send_message(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_g_socket_send_messages(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_socket_send_to(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_socket_send_with_blocking(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_socket_set_blocking(SEXP s1, SEXP s2);
extern SEXP R_g_socket_set_broadcast(SEXP s1, SEXP s2);
extern SEXP R_g_socket_set_keepalive(SEXP s1, SEXP s2);
extern SEXP R_g_socket_set_listen_backlog(SEXP s1, SEXP s2);
extern SEXP R_g_socket_set_multicast_loopback(SEXP s1, SEXP s2);
extern SEXP R_g_socket_set_multicast_ttl(SEXP s1, SEXP s2);
extern SEXP R_g_socket_set_option(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_set_timeout(SEXP s1, SEXP s2);
extern SEXP R_g_socket_set_ttl(SEXP s1, SEXP s2);
extern SEXP R_g_socket_shutdown(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_speaks_ipv4(SEXP s1);
extern SEXP R_g_socket_address_new_from_native(SEXP s1, SEXP s2);
extern SEXP R_g_socket_address_get_family(SEXP s1);
extern SEXP R_g_socket_address_get_native_size(SEXP s1);
extern SEXP R_g_socket_address_to_native(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_address_enumerator_next(SEXP s1, SEXP s2);
extern SEXP R_g_socket_address_enumerator_next_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_address_enumerator_next_finish(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_new(void);
extern SEXP R_g_socket_client_add_application_proxy(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_connect(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_client_connect_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_socket_client_connect_finish(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_connect_to_host(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_client_connect_to_host_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_socket_client_connect_to_host_finish(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_connect_to_service(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_client_connect_to_service_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_socket_client_connect_to_service_finish(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_connect_to_uri(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_client_connect_to_uri_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_socket_client_connect_to_uri_finish(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_get_enable_proxy(SEXP s1);
extern SEXP R_g_socket_client_get_family(SEXP s1);
extern SEXP R_g_socket_client_get_local_address(SEXP s1);
extern SEXP R_g_socket_client_get_protocol(SEXP s1);
extern SEXP R_g_socket_client_get_proxy_resolver(SEXP s1);
extern SEXP R_g_socket_client_get_socket_type(SEXP s1);
extern SEXP R_g_socket_client_get_timeout(SEXP s1);
extern SEXP R_g_socket_client_get_tls(SEXP s1);
extern SEXP R_g_socket_client_get_tls_validation_flags(SEXP s1);
extern SEXP R_g_socket_client_set_enable_proxy(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_set_family(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_set_local_address(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_set_protocol(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_set_proxy_resolver(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_set_socket_type(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_set_timeout(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_set_tls(SEXP s1, SEXP s2);
extern SEXP R_g_socket_client_set_tls_validation_flags(SEXP s1, SEXP s2);
extern SEXP R_g_socket_connectable_enumerate(SEXP s1);
extern SEXP R_g_socket_connectable_proxy_enumerate(SEXP s1);
extern SEXP R_g_socket_connectable_to_string(SEXP s1);
extern SEXP R_g_socket_connection_factory_lookup_type(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_connection_factory_register_type(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_connection_connect(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_connection_connect_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_socket_connection_connect_finish(SEXP s1, SEXP s2);
extern SEXP R_g_socket_connection_get_local_address(SEXP s1);
extern SEXP R_g_socket_connection_get_remote_address(SEXP s1);
extern SEXP R_g_socket_connection_get_socket(SEXP s1);
extern SEXP R_g_socket_connection_is_connected(SEXP s1);
extern SEXP R_g_socket_control_message_deserialize(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_control_message_get_level(SEXP s1);
extern SEXP R_g_socket_control_message_get_msg_type(SEXP s1);
extern SEXP R_g_socket_control_message_get_size(SEXP s1);
extern SEXP R_g_socket_control_message_serialize(SEXP s1, SEXP s2);
extern SEXP R_g_socket_listener_new(void);
extern SEXP R_g_socket_listener_accept(SEXP s1, SEXP s2);
extern SEXP R_g_socket_listener_accept_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_listener_accept_finish(SEXP s1, SEXP s2);
extern SEXP R_g_socket_listener_accept_socket(SEXP s1, SEXP s2);
extern SEXP R_g_socket_listener_accept_socket_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_socket_listener_accept_socket_finish(SEXP s1, SEXP s2);
extern SEXP R_g_socket_listener_add_address(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_socket_listener_add_any_inet_port(SEXP s1, SEXP s2);
extern SEXP R_g_socket_listener_add_inet_port(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_listener_add_socket(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_socket_listener_close(SEXP s1);
extern SEXP R_g_socket_listener_set_backlog(SEXP s1, SEXP s2);
extern SEXP R_g_socket_service_new(void);
extern SEXP R_g_socket_service_is_active(SEXP s1);
extern SEXP R_g_socket_service_start(SEXP s1);
extern SEXP R_g_socket_service_stop(SEXP s1);
extern SEXP R_g_srv_target_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_srv_target_copy(SEXP s1);
extern SEXP R_g_srv_target_free(SEXP s1);
extern SEXP R_g_srv_target_get_hostname(SEXP s1);
extern SEXP R_g_srv_target_get_port(SEXP s1);
extern SEXP R_g_srv_target_get_priority(SEXP s1);
extern SEXP R_g_srv_target_get_weight(SEXP s1);
extern SEXP R_g_static_resource_fini(SEXP s1);
extern SEXP R_g_static_resource_get_resource(SEXP s1);
extern SEXP R_g_static_resource_init(SEXP s1);
extern SEXP R_g_task_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_task_is_valid(SEXP s1, SEXP s2);
extern SEXP R_g_task_report_error(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_task_get_cancellable(SEXP s1);
extern SEXP R_g_task_get_check_cancellable(SEXP s1);
extern SEXP R_g_task_get_completed(SEXP s1);
extern SEXP R_g_task_get_context(SEXP s1);
extern SEXP R_g_task_get_priority(SEXP s1);
extern SEXP R_g_task_get_return_on_cancel(SEXP s1);
extern SEXP R_g_task_get_source_object(SEXP s1);
extern SEXP R_g_task_get_source_tag(SEXP s1);
extern SEXP R_g_task_get_task_data(SEXP s1);
extern SEXP R_g_task_had_error(SEXP s1);
extern SEXP R_g_task_propagate_boolean(SEXP s1);
extern SEXP R_g_task_propagate_int(SEXP s1);
extern SEXP R_g_task_propagate_pointer(SEXP s1);
extern SEXP R_g_task_return_boolean(SEXP s1, SEXP s2);
extern SEXP R_g_task_return_error(SEXP s1, SEXP s2);
extern SEXP R_g_task_return_error_if_cancelled(SEXP s1);
extern SEXP R_g_task_return_int(SEXP s1, SEXP s2);
extern SEXP R_g_task_return_pointer(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_task_run_in_thread(SEXP s1, SEXP s2);
extern SEXP R_g_task_run_in_thread_sync(SEXP s1, SEXP s2);
extern SEXP R_g_task_set_check_cancellable(SEXP s1, SEXP s2);
extern SEXP R_g_task_set_priority(SEXP s1, SEXP s2);
extern SEXP R_g_task_set_return_on_cancel(SEXP s1, SEXP s2);
extern SEXP R_g_task_set_source_tag(SEXP s1, SEXP s2);
extern SEXP R_g_task_set_task_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_tcp_connection_get_graceful_disconnect(SEXP s1);
extern SEXP R_g_tcp_connection_set_graceful_disconnect(SEXP s1, SEXP s2);
extern SEXP R_g_tcp_wrapper_connection_new(SEXP s1, SEXP s2);
extern SEXP R_g_tcp_wrapper_connection_get_base_io_stream(SEXP s1);
extern SEXP R_g_test_dbus_new(SEXP s1);
extern SEXP R_g_test_dbus_unset(void);
extern SEXP R_g_test_dbus_add_service_dir(SEXP s1, SEXP s2);
extern SEXP R_g_test_dbus_down(SEXP s1);
extern SEXP R_g_test_dbus_get_bus_address(SEXP s1);
extern SEXP R_g_test_dbus_get_flags(SEXP s1);
extern SEXP R_g_test_dbus_stop(SEXP s1);
extern SEXP R_g_test_dbus_up(SEXP s1);
extern SEXP R_g_themed_icon_new(SEXP s1);
extern SEXP R_g_themed_icon_new_from_names(SEXP s1, SEXP s2);
extern SEXP R_g_themed_icon_new_with_default_fallbacks(SEXP s1);
extern SEXP R_g_themed_icon_append_name(SEXP s1, SEXP s2);
extern SEXP R_g_themed_icon_get_names(SEXP s1);
extern SEXP R_g_themed_icon_prepend_name(SEXP s1, SEXP s2);
extern SEXP R_g_threaded_socket_service_new(SEXP s1);
extern SEXP R_g_vfs_get_default(void);
extern SEXP R_g_vfs_get_local(void);
extern SEXP R_g_vfs_get_file_for_path(SEXP s1, SEXP s2);
extern SEXP R_g_vfs_get_file_for_uri(SEXP s1, SEXP s2);
extern SEXP R_g_vfs_get_supported_uri_schemes(SEXP s1);
extern SEXP R_g_vfs_is_active(SEXP s1);
extern SEXP R_g_vfs_parse_name(SEXP s1, SEXP s2);
extern SEXP R_g_vfs_register_uri_scheme(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_g_vfs_unregister_uri_scheme(SEXP s1, SEXP s2);
extern SEXP R_g_volume_can_eject(SEXP s1);
extern SEXP R_g_volume_can_mount(SEXP s1);
extern SEXP R_g_volume_eject(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_volume_eject_finish(SEXP s1, SEXP s2);
extern SEXP R_g_volume_eject_with_operation(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_volume_eject_with_operation_finish(SEXP s1, SEXP s2);
extern SEXP R_g_volume_enumerate_identifiers(SEXP s1);
extern SEXP R_g_volume_get_activation_root(SEXP s1);
extern SEXP R_g_volume_get_drive(SEXP s1);
extern SEXP R_g_volume_get_icon(SEXP s1);
extern SEXP R_g_volume_get_identifier(SEXP s1, SEXP s2);
extern SEXP R_g_volume_get_mount(SEXP s1);
extern SEXP R_g_volume_get_name(SEXP s1);
extern SEXP R_g_volume_get_sort_key(SEXP s1);
extern SEXP R_g_volume_get_symbolic_icon(SEXP s1);
extern SEXP R_g_volume_get_uuid(SEXP s1);
extern SEXP R_g_volume_mount(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_volume_mount_finish(SEXP s1, SEXP s2);
extern SEXP R_g_volume_should_automount(SEXP s1);
extern SEXP R_g_volume_monitor_adopt_orphan_mount(SEXP s1);
extern SEXP R_g_volume_monitor_get(void);
extern SEXP R_g_volume_monitor_get_connected_drives(SEXP s1);
extern SEXP R_g_volume_monitor_get_mount_for_uuid(SEXP s1, SEXP s2);
extern SEXP R_g_volume_monitor_get_mounts(SEXP s1);
extern SEXP R_g_volume_monitor_get_volume_for_uuid(SEXP s1, SEXP s2);
extern SEXP R_g_volume_monitor_get_volumes(SEXP s1);
extern SEXP R_g_zlib_compressor_new(SEXP s1, SEXP s2);
extern SEXP R_g_zlib_compressor_get_file_info(SEXP s1);
extern SEXP R_g_zlib_compressor_set_file_info(SEXP s1, SEXP s2);
extern SEXP R_g_zlib_decompressor_new(SEXP s1);
extern SEXP R_g_zlib_decompressor_get_file_info(SEXP s1);
extern SEXP R_g_bus_get(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_bus_get_finish(SEXP s1);
extern SEXP R_g_bus_get_sync(SEXP s1, SEXP s2);
extern SEXP R_g_bus_own_name(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_g_bus_own_name_on_connection(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_bus_own_name_on_connection_with_closures(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_bus_own_name_with_closures(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_bus_unown_name(SEXP s1);
extern SEXP R_g_bus_unwatch_name(SEXP s1);
extern SEXP R_g_bus_watch_name(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_bus_watch_name_on_connection(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_bus_watch_name_on_connection_with_closures(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_bus_watch_name_with_closures(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_content_type_can_be_executable(SEXP s1);
extern SEXP R_g_content_type_equals(SEXP s1, SEXP s2);
extern SEXP R_g_content_type_from_mime_type(SEXP s1);
extern SEXP R_g_content_type_get_description(SEXP s1);
extern SEXP R_g_content_type_get_generic_icon_name(SEXP s1);
extern SEXP R_g_content_type_get_icon(SEXP s1);
extern SEXP R_g_content_type_get_mime_type(SEXP s1);
extern SEXP R_g_content_type_get_symbolic_icon(SEXP s1);
extern SEXP R_g_content_type_guess(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_content_type_guess_for_tree(SEXP s1);
extern SEXP R_g_content_type_is_a(SEXP s1, SEXP s2);
extern SEXP R_g_content_type_is_mime_type(SEXP s1, SEXP s2);
extern SEXP R_g_content_type_is_unknown(SEXP s1);
extern SEXP R_g_content_types_get_registered(void);
extern SEXP R_g_io_error_from_errno(SEXP s1);
extern SEXP R_g_io_error_quark(void);
extern SEXP R_g_io_modules_load_all_in_directory(SEXP s1);
extern SEXP R_g_io_modules_load_all_in_directory_with_scope(SEXP s1, SEXP s2);
extern SEXP R_g_io_modules_scan_all_in_directory(SEXP s1);
extern SEXP R_g_io_modules_scan_all_in_directory_with_scope(SEXP s1, SEXP s2);
extern SEXP R_g_io_scheduler_cancel_all_jobs(void);
extern SEXP R_g_io_scheduler_push_job(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_keyfile_settings_backend_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_memory_settings_backend_new(void);
extern SEXP R_g_networking_init(void);
extern SEXP R_g_null_settings_backend_new(void);
extern SEXP R_g_pollable_source_new(SEXP s1);
extern SEXP R_g_pollable_source_new_full(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_pollable_stream_read(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_pollable_stream_write(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_pollable_stream_write_all(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_resources_enumerate_children(SEXP s1, SEXP s2);
extern SEXP R_g_resources_get_info(SEXP s1, SEXP s2);
extern SEXP R_g_resources_lookup_data(SEXP s1, SEXP s2);
extern SEXP R_g_resources_open_stream(SEXP s1, SEXP s2);
extern SEXP R_g_simple_async_report_gerror_in_idle(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_allocator_free(SEXP s1);
extern SEXP R_g_async_queue_length(SEXP s1);
extern SEXP R_g_async_queue_length_unlocked(SEXP s1);
extern SEXP R_g_async_queue_lock(SEXP s1);
extern SEXP R_g_async_queue_pop(SEXP s1);
extern SEXP R_g_async_queue_pop_unlocked(SEXP s1);
extern SEXP R_g_async_queue_push(SEXP s1, SEXP s2);
extern SEXP R_g_async_queue_push_front(SEXP s1, SEXP s2);
extern SEXP R_g_async_queue_push_front_unlocked(SEXP s1, SEXP s2);
extern SEXP R_g_async_queue_push_sorted(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_async_queue_push_sorted_unlocked(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_async_queue_push_unlocked(SEXP s1, SEXP s2);
extern SEXP R_g_async_queue_ref(SEXP s1);
extern SEXP R_g_async_queue_ref_unlocked(SEXP s1);
extern SEXP R_g_async_queue_remove(SEXP s1, SEXP s2);
extern SEXP R_g_async_queue_remove_unlocked(SEXP s1, SEXP s2);
extern SEXP R_g_async_queue_sort(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_async_queue_sort_unlocked(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_async_queue_timed_pop(SEXP s1, SEXP s2);
extern SEXP R_g_async_queue_timed_pop_unlocked(SEXP s1, SEXP s2);
extern SEXP R_g_async_queue_timeout_pop(SEXP s1, SEXP s2);
extern SEXP R_g_async_queue_timeout_pop_unlocked(SEXP s1, SEXP s2);
extern SEXP R_g_async_queue_try_pop(SEXP s1);
extern SEXP R_g_async_queue_try_pop_unlocked(SEXP s1);
extern SEXP R_g_async_queue_unlock(SEXP s1);
extern SEXP R_g_async_queue_unref(SEXP s1);
extern SEXP R_g_async_queue_unref_and_unlock(SEXP s1);
extern SEXP R_g_async_queue_new(void);
extern SEXP R_g_async_queue_new_full(SEXP s1);
extern SEXP R_g_bookmark_file_new(void);
extern SEXP R_g_bookmark_file_add_application(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_bookmark_file_add_group(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_free(SEXP s1);
extern SEXP R_g_bookmark_file_get_added(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_get_app_info(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_get_applications(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_get_description(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_get_groups(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_get_icon(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_get_is_private(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_get_mime_type(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_get_modified(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_get_size(SEXP s1);
extern SEXP R_g_bookmark_file_get_title(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_get_uris(SEXP s1);
extern SEXP R_g_bookmark_file_get_visited(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_has_application(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_has_group(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_has_item(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_load_from_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_load_from_data_dirs(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_load_from_file(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_move_item(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_remove_application(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_remove_group(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_remove_item(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_set_added(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_set_app_info(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_bookmark_file_set_description(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_set_groups(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_bookmark_file_set_icon(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_bookmark_file_set_is_private(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_set_mime_type(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_set_modified(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_set_title(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_set_visited(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bookmark_file_to_data(SEXP s1);
extern SEXP R_g_bookmark_file_to_file(SEXP s1, SEXP s2);
extern SEXP R_g_bookmark_file_error_quark(void);
extern SEXP R_g_byte_array_append(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_byte_array_free(SEXP s1, SEXP s2);
extern SEXP R_g_byte_array_free_to_bytes(SEXP s1);
extern SEXP R_g_byte_array_new(void);
extern SEXP R_g_byte_array_new_take(SEXP s1, SEXP s2);
extern SEXP R_g_byte_array_prepend(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_byte_array_ref(SEXP s1);
extern SEXP R_g_byte_array_remove_index(SEXP s1, SEXP s2);
extern SEXP R_g_byte_array_remove_index_fast(SEXP s1, SEXP s2);
extern SEXP R_g_byte_array_remove_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_byte_array_set_size(SEXP s1, SEXP s2);
extern SEXP R_g_byte_array_sized_new(SEXP s1);
extern SEXP R_g_byte_array_sort(SEXP s1, SEXP s2);
extern SEXP R_g_byte_array_sort_with_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_byte_array_unref(SEXP s1);
extern SEXP R_g_bytes_new(SEXP s1, SEXP s2);
extern SEXP R_g_bytes_new_from_bytes(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_bytes_new_take(SEXP s1, SEXP s2);
extern SEXP R_g_bytes_compare(SEXP s1, SEXP s2);
extern SEXP R_g_bytes_equal(SEXP s1, SEXP s2);
extern SEXP R_g_bytes_get_data(SEXP s1);
extern SEXP R_g_bytes_get_size(SEXP s1);
extern SEXP R_g_bytes_hash(SEXP s1);
extern SEXP R_g_bytes_ref(SEXP s1);
extern SEXP R_g_bytes_unref(SEXP s1);
extern SEXP R_g_bytes_unref_to_array(SEXP s1);
extern SEXP R_g_bytes_unref_to_data(SEXP s1);
extern SEXP R_g_cache_destroy(SEXP s1);
extern SEXP R_g_cache_insert(SEXP s1, SEXP s2);
extern SEXP R_g_cache_key_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_cache_remove(SEXP s1, SEXP s2);
extern SEXP R_g_cache_value_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_checksum_new(SEXP s1);
extern SEXP R_g_checksum_copy(SEXP s1);
extern SEXP R_g_checksum_free(SEXP s1);
extern SEXP R_g_checksum_get_string(SEXP s1);
extern SEXP R_g_checksum_reset(SEXP s1);
extern SEXP R_g_checksum_update(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_checksum_type_get_length(SEXP s1);
extern SEXP R_g_completion_clear_items(SEXP s1);
extern SEXP R_g_completion_complete_utf8(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_completion_free(SEXP s1);
extern SEXP R_g_cond_broadcast(SEXP s1);
extern SEXP R_g_cond_clear(SEXP s1);
extern SEXP R_g_cond_init(SEXP s1);
extern SEXP R_g_cond_signal(SEXP s1);
extern SEXP R_g_cond_wait(SEXP s1, SEXP s2);
extern SEXP R_g_cond_wait_until(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_date_new(void);
extern SEXP R_g_date_new_dmy(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_date_new_julian(SEXP s1);
extern SEXP R_g_date_add_days(SEXP s1, SEXP s2);
extern SEXP R_g_date_add_months(SEXP s1, SEXP s2);
extern SEXP R_g_date_add_years(SEXP s1, SEXP s2);
extern SEXP R_g_date_clamp(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_date_clear(SEXP s1, SEXP s2);
extern SEXP R_g_date_compare(SEXP s1, SEXP s2);
extern SEXP R_g_date_copy(SEXP s1);
extern SEXP R_g_date_days_between(SEXP s1, SEXP s2);
extern SEXP R_g_date_free(SEXP s1);
extern SEXP R_g_date_get_day(SEXP s1);
extern SEXP R_g_date_get_day_of_year(SEXP s1);
extern SEXP R_g_date_get_iso8601_week_of_year(SEXP s1);
extern SEXP R_g_date_get_julian(SEXP s1);
extern SEXP R_g_date_get_monday_week_of_year(SEXP s1);
extern SEXP R_g_date_get_month(SEXP s1);
extern SEXP R_g_date_get_sunday_week_of_year(SEXP s1);
extern SEXP R_g_date_get_weekday(SEXP s1);
extern SEXP R_g_date_get_year(SEXP s1);
extern SEXP R_g_date_is_first_of_month(SEXP s1);
extern SEXP R_g_date_is_last_of_month(SEXP s1);
extern SEXP R_g_date_order(SEXP s1, SEXP s2);
extern SEXP R_g_date_set_day(SEXP s1, SEXP s2);
extern SEXP R_g_date_set_dmy(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_date_set_julian(SEXP s1, SEXP s2);
extern SEXP R_g_date_set_month(SEXP s1, SEXP s2);
extern SEXP R_g_date_set_parse(SEXP s1, SEXP s2);
extern SEXP R_g_date_set_time(SEXP s1, SEXP s2);
extern SEXP R_g_date_set_time_t(SEXP s1, SEXP s2);
extern SEXP R_g_date_set_time_val(SEXP s1, SEXP s2);
extern SEXP R_g_date_set_year(SEXP s1, SEXP s2);
extern SEXP R_g_date_subtract_days(SEXP s1, SEXP s2);
extern SEXP R_g_date_subtract_months(SEXP s1, SEXP s2);
extern SEXP R_g_date_subtract_years(SEXP s1, SEXP s2);
extern SEXP R_g_date_to_struct_tm(SEXP s1, SEXP s2);
extern SEXP R_g_date_valid(SEXP s1);
extern SEXP R_g_date_get_days_in_month(SEXP s1, SEXP s2);
extern SEXP R_g_date_get_monday_weeks_in_year(SEXP s1);
extern SEXP R_g_date_get_sunday_weeks_in_year(SEXP s1);
extern SEXP R_g_date_is_leap_year(SEXP s1);
extern SEXP R_g_date_strftime(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_date_valid_day(SEXP s1);
extern SEXP R_g_date_valid_dmy(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_date_valid_julian(SEXP s1);
extern SEXP R_g_date_valid_month(SEXP s1);
extern SEXP R_g_date_valid_weekday(SEXP s1);
extern SEXP R_g_date_valid_year(SEXP s1);
extern SEXP R_g_date_time_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_date_time_new_from_iso8601(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_new_from_timeval_local(SEXP s1);
extern SEXP R_g_date_time_new_from_timeval_utc(SEXP s1);
extern SEXP R_g_date_time_new_from_unix_local(SEXP s1);
extern SEXP R_g_date_time_new_from_unix_utc(SEXP s1);
extern SEXP R_g_date_time_new_local(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_date_time_new_now(SEXP s1);
extern SEXP R_g_date_time_new_now_local(void);
extern SEXP R_g_date_time_new_now_utc(void);
extern SEXP R_g_date_time_new_utc(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_date_time_add(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_add_days(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_add_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_date_time_add_hours(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_add_minutes(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_add_months(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_add_seconds(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_add_weeks(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_add_years(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_compare(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_difference(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_equal(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_format(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_get_day_of_month(SEXP s1);
extern SEXP R_g_date_time_get_day_of_week(SEXP s1);
extern SEXP R_g_date_time_get_day_of_year(SEXP s1);
extern SEXP R_g_date_time_get_hour(SEXP s1);
extern SEXP R_g_date_time_get_microsecond(SEXP s1);
extern SEXP R_g_date_time_get_minute(SEXP s1);
extern SEXP R_g_date_time_get_month(SEXP s1);
extern SEXP R_g_date_time_get_second(SEXP s1);
extern SEXP R_g_date_time_get_seconds(SEXP s1);
extern SEXP R_g_date_time_get_timezone_abbreviation(SEXP s1);
extern SEXP R_g_date_time_get_utc_offset(SEXP s1);
extern SEXP R_g_date_time_get_week_numbering_year(SEXP s1);
extern SEXP R_g_date_time_get_week_of_year(SEXP s1);
extern SEXP R_g_date_time_get_year(SEXP s1);
extern SEXP R_g_date_time_get_ymd(SEXP s1);
extern SEXP R_g_date_time_hash(SEXP s1);
extern SEXP R_g_date_time_is_daylight_savings(SEXP s1);
extern SEXP R_g_date_time_ref(SEXP s1);
extern SEXP R_g_date_time_to_local(SEXP s1);
extern SEXP R_g_date_time_to_timeval(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_to_timezone(SEXP s1, SEXP s2);
extern SEXP R_g_date_time_to_unix(SEXP s1);
extern SEXP R_g_date_time_to_utc(SEXP s1);
extern SEXP R_g_date_time_unref(SEXP s1);
extern SEXP R_g_dir_open(SEXP s1, SEXP s2);
extern SEXP R_g_dir_close(SEXP s1);
extern SEXP R_g_dir_read_name(SEXP s1);
extern SEXP R_g_dir_rewind(SEXP s1);
extern SEXP R_g_dir_make_tmp(SEXP s1);
extern SEXP R_g_error_new_literal(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_error_copy(SEXP s1);
extern SEXP R_g_error_free(SEXP s1);
extern SEXP R_g_error_matches(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_hash_table_add(SEXP s1, SEXP s2);
extern SEXP R_g_hash_table_contains(SEXP s1, SEXP s2);
extern SEXP R_g_hash_table_destroy(SEXP s1);
extern SEXP R_g_hash_table_find(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_hash_table_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_hash_table_foreach_remove(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_hash_table_foreach_steal(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_hash_table_insert(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_hash_table_lookup(SEXP s1, SEXP s2);
extern SEXP R_g_hash_table_lookup_extended(SEXP s1, SEXP s2);
extern SEXP R_g_hash_table_ref(SEXP s1);
extern SEXP R_g_hash_table_remove(SEXP s1, SEXP s2);
extern SEXP R_g_hash_table_remove_all(SEXP s1);
extern SEXP R_g_hash_table_replace(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_hash_table_size(SEXP s1);
extern SEXP R_g_hash_table_steal(SEXP s1, SEXP s2);
extern SEXP R_g_hash_table_steal_all(SEXP s1);
extern SEXP R_g_hash_table_unref(SEXP s1);
extern SEXP R_g_hash_table_iter_get_hash_table(SEXP s1);
extern SEXP R_g_hash_table_iter_init(SEXP s1, SEXP s2);
extern SEXP R_g_hash_table_iter_next(SEXP s1);
extern SEXP R_g_hash_table_iter_remove(SEXP s1);
extern SEXP R_g_hash_table_iter_replace(SEXP s1, SEXP s2);
extern SEXP R_g_hash_table_iter_steal(SEXP s1);
extern SEXP R_g_hmac_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_hmac_copy(SEXP s1);
extern SEXP R_g_hmac_get_digest(SEXP s1, SEXP s2);
extern SEXP R_g_hmac_get_string(SEXP s1);
extern SEXP R_g_hmac_ref(SEXP s1);
extern SEXP R_g_hmac_unref(SEXP s1);
extern SEXP R_g_hmac_update(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_hook_compare_ids(SEXP s1, SEXP s2);
extern SEXP R_g_hook_destroy(SEXP s1, SEXP s2);
extern SEXP R_g_hook_destroy_link(SEXP s1, SEXP s2);
extern SEXP R_g_hook_free(SEXP s1, SEXP s2);
extern SEXP R_g_hook_insert_before(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_hook_insert_sorted(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_hook_prepend(SEXP s1, SEXP s2);
extern SEXP R_g_hook_unref(SEXP s1, SEXP s2);
extern SEXP R_g_hook_list_clear(SEXP s1);
extern SEXP R_g_hook_list_init(SEXP s1, SEXP s2);
extern SEXP R_g_hook_list_invoke(SEXP s1, SEXP s2);
extern SEXP R_g_hook_list_invoke_check(SEXP s1, SEXP s2);
extern SEXP R_g_hook_list_marshal(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_hook_list_marshal_check(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_io_channel_new_file(SEXP s1, SEXP s2);
extern SEXP R_g_io_channel_unix_new(SEXP s1);
extern SEXP R_g_io_channel_close(SEXP s1);
extern SEXP R_g_io_channel_flush(SEXP s1);
extern SEXP R_g_io_channel_get_buffer_condition(SEXP s1);
extern SEXP R_g_io_channel_get_buffer_size(SEXP s1);
extern SEXP R_g_io_channel_get_buffered(SEXP s1);
extern SEXP R_g_io_channel_get_close_on_unref(SEXP s1);
extern SEXP R_g_io_channel_get_encoding(SEXP s1);
extern SEXP R_g_io_channel_get_flags(SEXP s1);
extern SEXP R_g_io_channel_get_line_term(SEXP s1);
extern SEXP R_g_io_channel_init(SEXP s1);
extern SEXP R_g_io_channel_read(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_io_channel_read_chars(SEXP s1, SEXP s2);
extern SEXP R_g_io_channel_read_line(SEXP s1);
extern SEXP R_g_io_channel_read_line_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_io_channel_read_to_end(SEXP s1);
extern SEXP R_g_io_channel_read_unichar(SEXP s1);
extern SEXP R_g_io_channel_ref(SEXP s1);
extern SEXP R_g_io_channel_seek(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_io_channel_seek_position(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_io_channel_set_buffer_size(SEXP s1, SEXP s2);
extern SEXP R_g_io_channel_set_buffered(SEXP s1, SEXP s2);
extern SEXP R_g_io_channel_set_close_on_unref(SEXP s1, SEXP s2);
extern SEXP R_g_io_channel_set_encoding(SEXP s1, SEXP s2);
extern SEXP R_g_io_channel_set_flags(SEXP s1, SEXP s2);
extern SEXP R_g_io_channel_set_line_term(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_io_channel_shutdown(SEXP s1, SEXP s2);
extern SEXP R_g_io_channel_unix_get_fd(SEXP s1);
extern SEXP R_g_io_channel_unref(SEXP s1);
extern SEXP R_g_io_channel_write(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_io_channel_write_chars(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_io_channel_write_unichar(SEXP s1, SEXP s2);
extern SEXP R_g_io_channel_error_from_errno(SEXP s1);
extern SEXP R_g_io_channel_error_quark(void);
extern SEXP R_g_key_file_new(void);
extern SEXP R_g_key_file_get_boolean(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_get_boolean_list(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_get_comment(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_get_double(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_get_double_list(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_get_groups(SEXP s1);
extern SEXP R_g_key_file_get_int64(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_get_integer(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_get_integer_list(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_get_keys(SEXP s1, SEXP s2);
extern SEXP R_g_key_file_get_locale_for_key(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_get_locale_string(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_get_locale_string_list(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_get_start_group(SEXP s1);
extern SEXP R_g_key_file_get_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_get_string_list(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_get_uint64(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_get_value(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_has_group(SEXP s1, SEXP s2);
extern SEXP R_g_key_file_load_from_bytes(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_load_from_data(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_load_from_data_dirs(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_load_from_dirs(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_load_from_file(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_remove_comment(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_remove_group(SEXP s1, SEXP s2);
extern SEXP R_g_key_file_remove_key(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_key_file_save_to_file(SEXP s1, SEXP s2);
extern SEXP R_g_key_file_set_boolean(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_set_boolean_list(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_key_file_set_comment(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_set_double(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_set_double_list(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_key_file_set_int64(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_set_integer(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_set_integer_list(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_key_file_set_list_separator(SEXP s1, SEXP s2);
extern SEXP R_g_key_file_set_locale_string(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_key_file_set_locale_string_list(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_key_file_set_string(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_set_string_list(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_key_file_set_uint64(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_set_value(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_key_file_to_data(SEXP s1);
extern SEXP R_g_key_file_unref(SEXP s1);
extern SEXP R_g_key_file_error_quark(void);
extern SEXP R_g_list_pop_allocator(void);
extern SEXP R_g_list_push_allocator(SEXP s1);
extern SEXP R_g_main_context_new(void);
extern SEXP R_g_main_context_acquire(SEXP s1);
extern SEXP R_g_main_context_add_poll(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_main_context_check(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_main_context_dispatch(SEXP s1);
extern SEXP R_g_main_context_find_source_by_funcs_user_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_main_context_find_source_by_id(SEXP s1, SEXP s2);
extern SEXP R_g_main_context_find_source_by_user_data(SEXP s1, SEXP s2);
extern SEXP R_g_main_context_invoke_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_main_context_is_owner(SEXP s1);
extern SEXP R_g_main_context_iteration(SEXP s1, SEXP s2);
extern SEXP R_g_main_context_pending(SEXP s1);
extern SEXP R_g_main_context_pop_thread_default(SEXP s1);
extern SEXP R_g_main_context_prepare(SEXP s1);
extern SEXP R_g_main_context_push_thread_default(SEXP s1);
extern SEXP R_g_main_context_query(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_main_context_ref(SEXP s1);
extern SEXP R_g_main_context_release(SEXP s1);
extern SEXP R_g_main_context_remove_poll(SEXP s1, SEXP s2);
extern SEXP R_g_main_context_unref(SEXP s1);
extern SEXP R_g_main_context_wait(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_main_context_wakeup(SEXP s1);
extern SEXP R_g_main_context_default(void);
extern SEXP R_g_main_context_get_thread_default(void);
extern SEXP R_g_main_context_ref_thread_default(void);
extern SEXP R_g_main_loop_new(SEXP s1, SEXP s2);
extern SEXP R_g_main_loop_get_context(SEXP s1);
extern SEXP R_g_main_loop_is_running(SEXP s1);
extern SEXP R_g_main_loop_quit(SEXP s1);
extern SEXP R_g_main_loop_ref(SEXP s1);
extern SEXP R_g_main_loop_run(SEXP s1);
extern SEXP R_g_main_loop_unref(SEXP s1);
extern SEXP R_g_mapped_file_new(SEXP s1, SEXP s2);
extern SEXP R_g_mapped_file_new_from_fd(SEXP s1, SEXP s2);
extern SEXP R_g_mapped_file_free(SEXP s1);
extern SEXP R_g_mapped_file_get_bytes(SEXP s1);
extern SEXP R_g_mapped_file_get_contents(SEXP s1);
extern SEXP R_g_mapped_file_get_length(SEXP s1);
extern SEXP R_g_mapped_file_ref(SEXP s1);
extern SEXP R_g_mapped_file_unref(SEXP s1);
extern SEXP R_g_markup_parse_context_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_markup_parse_context_end_parse(SEXP s1);
extern SEXP R_g_markup_parse_context_free(SEXP s1);
extern SEXP R_g_markup_parse_context_get_element(SEXP s1);
extern SEXP R_g_markup_parse_context_get_element_stack(SEXP s1);
extern SEXP R_g_markup_parse_context_get_position(SEXP s1);
extern SEXP R_g_markup_parse_context_get_user_data(SEXP s1);
extern SEXP R_g_markup_parse_context_parse(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_markup_parse_context_pop(SEXP s1);
extern SEXP R_g_markup_parse_context_push(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_markup_parse_context_ref(SEXP s1);
extern SEXP R_g_markup_parse_context_unref(SEXP s1);
extern SEXP R_g_match_info_expand_references(SEXP s1, SEXP s2);
extern SEXP R_g_match_info_fetch(SEXP s1, SEXP s2);
extern SEXP R_g_match_info_fetch_all(SEXP s1);
extern SEXP R_g_match_info_fetch_named(SEXP s1, SEXP s2);
extern SEXP R_g_match_info_fetch_named_pos(SEXP s1, SEXP s2);
extern SEXP R_g_match_info_fetch_pos(SEXP s1, SEXP s2);
extern SEXP R_g_match_info_free(SEXP s1);
extern SEXP R_g_match_info_get_match_count(SEXP s1);
extern SEXP R_g_match_info_get_regex(SEXP s1);
extern SEXP R_g_match_info_get_string(SEXP s1);
extern SEXP R_g_match_info_is_partial_match(SEXP s1);
extern SEXP R_g_match_info_matches(SEXP s1);
extern SEXP R_g_match_info_next(SEXP s1);
extern SEXP R_g_match_info_ref(SEXP s1);
extern SEXP R_g_match_info_unref(SEXP s1);
extern SEXP R_g_mem_chunk_alloc(SEXP s1);
extern SEXP R_g_mem_chunk_alloc0(SEXP s1);
extern SEXP R_g_mem_chunk_clean(SEXP s1);
extern SEXP R_g_mem_chunk_destroy(SEXP s1);
extern SEXP R_g_mem_chunk_free(SEXP s1, SEXP s2);
extern SEXP R_g_mem_chunk_print(SEXP s1);
extern SEXP R_g_mem_chunk_reset(SEXP s1);
extern SEXP R_g_mem_chunk_info(void);
extern SEXP R_g_mutex_clear(SEXP s1);
extern SEXP R_g_mutex_init(SEXP s1);
extern SEXP R_g_mutex_lock(SEXP s1);
extern SEXP R_g_mutex_trylock(SEXP s1);
extern SEXP R_g_mutex_unlock(SEXP s1);
extern SEXP R_g_node_child_index(SEXP s1, SEXP s2);
extern SEXP R_g_node_child_position(SEXP s1, SEXP s2);
extern SEXP R_g_node_children_foreach(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_node_depth(SEXP s1);
extern SEXP R_g_node_destroy(SEXP s1);
extern SEXP R_g_node_is_ancestor(SEXP s1, SEXP s2);
extern SEXP R_g_node_max_height(SEXP s1);
extern SEXP R_g_node_n_children(SEXP s1);
extern SEXP R_g_node_n_nodes(SEXP s1, SEXP s2);
extern SEXP R_g_node_reverse_children(SEXP s1);
extern SEXP R_g_node_traverse(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_node_unlink(SEXP s1);
extern SEXP R_g_node_pop_allocator(void);
extern SEXP R_g_node_push_allocator(SEXP s1);
extern SEXP R_g_option_context_add_group(SEXP s1, SEXP s2);
extern SEXP R_g_option_context_add_main_entries(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_option_context_free(SEXP s1);
extern SEXP R_g_option_context_get_description(SEXP s1);
extern SEXP R_g_option_context_get_help(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_option_context_get_help_enabled(SEXP s1);
extern SEXP R_g_option_context_get_ignore_unknown_options(SEXP s1);
extern SEXP R_g_option_context_get_main_group(SEXP s1);
extern SEXP R_g_option_context_get_strict_posix(SEXP s1);
extern SEXP R_g_option_context_get_summary(SEXP s1);
extern SEXP R_g_option_context_parse(SEXP s1);
extern SEXP R_g_option_context_parse_strv(SEXP s1);
extern SEXP R_g_option_context_set_description(SEXP s1, SEXP s2);
extern SEXP R_g_option_context_set_help_enabled(SEXP s1, SEXP s2);
extern SEXP R_g_option_context_set_ignore_unknown_options(SEXP s1, SEXP s2);
extern SEXP R_g_option_context_set_main_group(SEXP s1, SEXP s2);
extern SEXP R_g_option_context_set_strict_posix(SEXP s1, SEXP s2);
extern SEXP R_g_option_context_set_summary(SEXP s1, SEXP s2);
extern SEXP R_g_option_context_set_translate_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_option_context_set_translation_domain(SEXP s1, SEXP s2);
extern SEXP R_g_option_group_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_option_group_add_entries(SEXP s1, SEXP s2);
extern SEXP R_g_option_group_free(SEXP s1);
extern SEXP R_g_option_group_ref(SEXP s1);
extern SEXP R_g_option_group_set_translate_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_option_group_set_translation_domain(SEXP s1, SEXP s2);
extern SEXP R_g_option_group_unref(SEXP s1);
extern SEXP R_g_pattern_spec_new(SEXP s1);
extern SEXP R_g_pattern_spec_equal(SEXP s1, SEXP s2);
extern SEXP R_g_pattern_spec_free(SEXP s1);
extern SEXP R_g_private_get(SEXP s1);
extern SEXP R_g_private_replace(SEXP s1, SEXP s2);
extern SEXP R_g_private_set(SEXP s1, SEXP s2);
extern SEXP R_g_queue_clear(SEXP s1);
extern SEXP R_g_queue_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_queue_free(SEXP s1);
extern SEXP R_g_queue_free_full(SEXP s1, SEXP s2);
extern SEXP R_g_queue_get_length(SEXP s1);
extern SEXP R_g_queue_index(SEXP s1, SEXP s2);
extern SEXP R_g_queue_init(SEXP s1);
extern SEXP R_g_queue_insert_sorted(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_queue_is_empty(SEXP s1);
extern SEXP R_g_queue_peek_head(SEXP s1);
extern SEXP R_g_queue_peek_nth(SEXP s1, SEXP s2);
extern SEXP R_g_queue_peek_tail(SEXP s1);
extern SEXP R_g_queue_pop_head(SEXP s1);
extern SEXP R_g_queue_pop_nth(SEXP s1, SEXP s2);
extern SEXP R_g_queue_pop_tail(SEXP s1);
extern SEXP R_g_queue_push_head(SEXP s1, SEXP s2);
extern SEXP R_g_queue_push_nth(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_queue_push_tail(SEXP s1, SEXP s2);
extern SEXP R_g_queue_remove(SEXP s1, SEXP s2);
extern SEXP R_g_queue_remove_all(SEXP s1, SEXP s2);
extern SEXP R_g_queue_reverse(SEXP s1);
extern SEXP R_g_queue_sort(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_rw_lock_clear(SEXP s1);
extern SEXP R_g_rw_lock_init(SEXP s1);
extern SEXP R_g_rw_lock_reader_lock(SEXP s1);
extern SEXP R_g_rw_lock_reader_trylock(SEXP s1);
extern SEXP R_g_rw_lock_reader_unlock(SEXP s1);
extern SEXP R_g_rw_lock_writer_lock(SEXP s1);
extern SEXP R_g_rw_lock_writer_trylock(SEXP s1);
extern SEXP R_g_rw_lock_writer_unlock(SEXP s1);
extern SEXP R_g_rand_new(void);
extern SEXP R_g_rand_new_with_seed(SEXP s1);
extern SEXP R_g_rand_new_with_seed_array(SEXP s1, SEXP s2);
extern SEXP R_g_rand_copy(SEXP s1);
extern SEXP R_g_rand_double(SEXP s1);
extern SEXP R_g_rand_double_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_rand_free(SEXP s1);
extern SEXP R_g_rand_int(SEXP s1);
extern SEXP R_g_rand_int_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_rand_set_seed(SEXP s1, SEXP s2);
extern SEXP R_g_rand_set_seed_array(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_rec_mutex_clear(SEXP s1);
extern SEXP R_g_rec_mutex_init(SEXP s1);
extern SEXP R_g_rec_mutex_lock(SEXP s1);
extern SEXP R_g_rec_mutex_trylock(SEXP s1);
extern SEXP R_g_rec_mutex_unlock(SEXP s1);
extern SEXP R_g_regex_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_regex_get_capture_count(SEXP s1);
extern SEXP R_g_regex_get_compile_flags(SEXP s1);
extern SEXP R_g_regex_get_has_cr_or_lf(SEXP s1);
extern SEXP R_g_regex_get_match_flags(SEXP s1);
extern SEXP R_g_regex_get_max_backref(SEXP s1);
extern SEXP R_g_regex_get_max_lookbehind(SEXP s1);
extern SEXP R_g_regex_get_pattern(SEXP s1);
extern SEXP R_g_regex_get_string_number(SEXP s1, SEXP s2);
extern SEXP R_g_regex_match(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_regex_match_all(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_regex_match_all_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_regex_match_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_regex_ref(SEXP s1);
extern SEXP R_g_regex_replace(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_regex_replace_eval(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_regex_replace_literal(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_regex_split(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_regex_split_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_regex_unref(SEXP s1);
extern SEXP R_g_regex_check_replacement(SEXP s1);
extern SEXP R_g_regex_error_quark(void);
extern SEXP R_g_regex_escape_nul(SEXP s1, SEXP s2);
extern SEXP R_g_regex_escape_string(SEXP s1, SEXP s2);
extern SEXP R_g_regex_match_simple(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_regex_split_simple(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_relation_count(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_relation_delete(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_relation_destroy(SEXP s1);
extern SEXP R_g_relation_print(SEXP s1);
extern SEXP R_g_slist_pop_allocator(void);
extern SEXP R_g_slist_push_allocator(SEXP s1);
extern SEXP R_g_scanner_cur_line(SEXP s1);
extern SEXP R_g_scanner_cur_position(SEXP s1);
extern SEXP R_g_scanner_cur_token(SEXP s1);
extern SEXP R_g_scanner_destroy(SEXP s1);
extern SEXP R_g_scanner_eof(SEXP s1);
extern SEXP R_g_scanner_get_next_token(SEXP s1);
extern SEXP R_g_scanner_input_file(SEXP s1, SEXP s2);
extern SEXP R_g_scanner_input_text(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_scanner_lookup_symbol(SEXP s1, SEXP s2);
extern SEXP R_g_scanner_peek_next_token(SEXP s1);
extern SEXP R_g_scanner_scope_add_symbol(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_scanner_scope_foreach_symbol(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_scanner_scope_lookup_symbol(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_scanner_scope_remove_symbol(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_scanner_set_scope(SEXP s1, SEXP s2);
extern SEXP R_g_scanner_sync_file_offset(SEXP s1);
extern SEXP R_g_scanner_unexp_token(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_sequence_append(SEXP s1, SEXP s2);
extern SEXP R_g_sequence_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_sequence_free(SEXP s1);
extern SEXP R_g_sequence_get_begin_iter(SEXP s1);
extern SEXP R_g_sequence_get_end_iter(SEXP s1);
extern SEXP R_g_sequence_get_iter_at_pos(SEXP s1, SEXP s2);
extern SEXP R_g_sequence_get_length(SEXP s1);
extern SEXP R_g_sequence_insert_sorted(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_sequence_insert_sorted_iter(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_sequence_is_empty(SEXP s1);
extern SEXP R_g_sequence_lookup(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_sequence_lookup_iter(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_sequence_prepend(SEXP s1, SEXP s2);
extern SEXP R_g_sequence_search(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_sequence_search_iter(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_sequence_sort(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_sequence_sort_iter(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_sequence_foreach_range(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_sequence_get(SEXP s1);
extern SEXP R_g_sequence_insert_before(SEXP s1, SEXP s2);
extern SEXP R_g_sequence_move(SEXP s1, SEXP s2);
extern SEXP R_g_sequence_move_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_sequence_range_get_midpoint(SEXP s1, SEXP s2);
extern SEXP R_g_sequence_remove(SEXP s1);
extern SEXP R_g_sequence_remove_range(SEXP s1, SEXP s2);
extern SEXP R_g_sequence_set(SEXP s1, SEXP s2);
extern SEXP R_g_sequence_sort_changed(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_sequence_sort_changed_iter(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_sequence_swap(SEXP s1, SEXP s2);
extern SEXP R_g_sequence_iter_compare(SEXP s1, SEXP s2);
extern SEXP R_g_sequence_iter_get_position(SEXP s1);
extern SEXP R_g_sequence_iter_get_sequence(SEXP s1);
extern SEXP R_g_sequence_iter_is_begin(SEXP s1);
extern SEXP R_g_sequence_iter_is_end(SEXP s1);
extern SEXP R_g_sequence_iter_move(SEXP s1, SEXP s2);
extern SEXP R_g_sequence_iter_next(SEXP s1);
extern SEXP R_g_sequence_iter_prev(SEXP s1);
extern SEXP R_g_source_new(SEXP s1, SEXP s2);
extern SEXP R_g_source_add_child_source(SEXP s1, SEXP s2);
extern SEXP R_g_source_add_poll(SEXP s1, SEXP s2);
extern SEXP R_g_source_attach(SEXP s1, SEXP s2);
extern SEXP R_g_source_destroy(SEXP s1);
extern SEXP R_g_source_get_can_recurse(SEXP s1);
extern SEXP R_g_source_get_context(SEXP s1);
extern SEXP R_g_source_get_current_time(SEXP s1, SEXP s2);
extern SEXP R_g_source_get_id(SEXP s1);
extern SEXP R_g_source_get_name(SEXP s1);
extern SEXP R_g_source_get_priority(SEXP s1);
extern SEXP R_g_source_get_ready_time(SEXP s1);
extern SEXP R_g_source_get_time(SEXP s1);
extern SEXP R_g_source_is_destroyed(SEXP s1);
extern SEXP R_g_source_ref(SEXP s1);
extern SEXP R_g_source_remove_child_source(SEXP s1, SEXP s2);
extern SEXP R_g_source_remove_poll(SEXP s1, SEXP s2);
extern SEXP R_g_source_set_callback(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_source_set_callback_indirect(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_source_set_can_recurse(SEXP s1, SEXP s2);
extern SEXP R_g_source_set_funcs(SEXP s1, SEXP s2);
extern SEXP R_g_source_set_name(SEXP s1, SEXP s2);
extern SEXP R_g_source_set_priority(SEXP s1, SEXP s2);
extern SEXP R_g_source_set_ready_time(SEXP s1, SEXP s2);
extern SEXP R_g_source_unref(SEXP s1);
extern SEXP R_g_source_remove(SEXP s1);
extern SEXP R_g_source_remove_by_funcs_user_data(SEXP s1, SEXP s2);
extern SEXP R_g_source_remove_by_user_data(SEXP s1);
extern SEXP R_g_source_set_name_by_id(SEXP s1, SEXP s2);
extern SEXP R_g_static_mutex_get_mutex_impl(SEXP s1);
extern SEXP R_g_string_new(SEXP s1);
extern SEXP R_g_string_new_len(SEXP s1, SEXP s2);
extern SEXP R_g_string_sized_new(SEXP s1);
extern SEXP R_g_string_append(SEXP s1, SEXP s2);
extern SEXP R_g_string_append_c(SEXP s1, SEXP s2);
extern SEXP R_g_string_append_len(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_string_append_unichar(SEXP s1, SEXP s2);
extern SEXP R_g_string_append_uri_escaped(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_string_ascii_down(SEXP s1);
extern SEXP R_g_string_ascii_up(SEXP s1);
extern SEXP R_g_string_assign(SEXP s1, SEXP s2);
extern SEXP R_g_string_down(SEXP s1);
extern SEXP R_g_string_equal(SEXP s1, SEXP s2);
extern SEXP R_g_string_erase(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_string_free(SEXP s1, SEXP s2);
extern SEXP R_g_string_free_to_bytes(SEXP s1);
extern SEXP R_g_string_hash(SEXP s1);
extern SEXP R_g_string_insert(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_string_insert_c(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_string_insert_len(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_string_insert_unichar(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_string_overwrite(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_string_overwrite_len(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_string_prepend(SEXP s1, SEXP s2);
extern SEXP R_g_string_prepend_c(SEXP s1, SEXP s2);
extern SEXP R_g_string_prepend_len(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_string_prepend_unichar(SEXP s1, SEXP s2);
extern SEXP R_g_string_set_size(SEXP s1, SEXP s2);
extern SEXP R_g_string_truncate(SEXP s1, SEXP s2);
extern SEXP R_g_string_up(SEXP s1);
extern SEXP R_g_string_chunk_clear(SEXP s1);
extern SEXP R_g_string_chunk_free(SEXP s1);
extern SEXP R_g_string_chunk_insert(SEXP s1, SEXP s2);
extern SEXP R_g_string_chunk_insert_const(SEXP s1, SEXP s2);
extern SEXP R_g_string_chunk_insert_len(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_strv_builder_add(SEXP s1, SEXP s2);
extern SEXP R_g_strv_builder_addv(SEXP s1, SEXP s2);
extern SEXP R_g_strv_builder_end(SEXP s1);
extern SEXP R_g_strv_builder_take(SEXP s1, SEXP s2);
extern SEXP R_g_test_log_buffer_free(SEXP s1);
extern SEXP R_g_test_log_buffer_push(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_test_log_msg_free(SEXP s1);
extern SEXP R_g_test_suite_add(SEXP s1, SEXP s2);
extern SEXP R_g_test_suite_add_suite(SEXP s1, SEXP s2);
extern SEXP R_g_thread_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_thread_try_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_thread_join(SEXP s1);
extern SEXP R_g_thread_ref(SEXP s1);
extern SEXP R_g_thread_unref(SEXP s1);
extern SEXP R_g_thread_error_quark(void);
extern SEXP R_g_thread_exit(SEXP s1);
extern SEXP R_g_thread_self(void);
extern SEXP R_g_thread_yield(void);
extern SEXP R_g_thread_pool_free(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_thread_pool_get_max_threads(SEXP s1);
extern SEXP R_g_thread_pool_get_num_threads(SEXP s1);
extern SEXP R_g_thread_pool_move_to_front(SEXP s1, SEXP s2);
extern SEXP R_g_thread_pool_push(SEXP s1, SEXP s2);
extern SEXP R_g_thread_pool_set_max_threads(SEXP s1, SEXP s2);
extern SEXP R_g_thread_pool_unprocessed(SEXP s1);
extern SEXP R_g_thread_pool_get_max_idle_time(void);
extern SEXP R_g_thread_pool_get_max_unused_threads(void);
extern SEXP R_g_thread_pool_get_num_unused_threads(void);
extern SEXP R_g_thread_pool_set_max_idle_time(SEXP s1);
extern SEXP R_g_thread_pool_set_max_unused_threads(SEXP s1);
extern SEXP R_g_thread_pool_stop_unused_threads(void);
extern SEXP R_g_time_val_add(SEXP s1, SEXP s2);
extern SEXP R_g_time_val_to_iso8601(SEXP s1);
extern SEXP R_g_time_val_from_iso8601(SEXP s1);
extern SEXP R_g_time_zone_new(SEXP s1);
extern SEXP R_g_time_zone_new_local(void);
extern SEXP R_g_time_zone_new_utc(void);
extern SEXP R_g_time_zone_adjust_time(SEXP s1, SEXP s2);
extern SEXP R_g_time_zone_find_interval(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_time_zone_get_abbreviation(SEXP s1, SEXP s2);
extern SEXP R_g_time_zone_get_offset(SEXP s1, SEXP s2);
extern SEXP R_g_time_zone_is_dst(SEXP s1, SEXP s2);
extern SEXP R_g_time_zone_ref(SEXP s1);
extern SEXP R_g_time_zone_unref(SEXP s1);
extern SEXP R_g_timer_continue(SEXP s1);
extern SEXP R_g_timer_destroy(SEXP s1);
extern SEXP R_g_timer_elapsed(SEXP s1, SEXP s2);
extern SEXP R_g_timer_reset(SEXP s1);
extern SEXP R_g_timer_start(SEXP s1);
extern SEXP R_g_timer_stop(SEXP s1);
extern SEXP R_g_trash_stack_height(SEXP s1);
extern SEXP R_g_trash_stack_peek(SEXP s1);
extern SEXP R_g_trash_stack_pop(SEXP s1);
extern SEXP R_g_trash_stack_push(SEXP s1, SEXP s2);
extern SEXP R_g_tree_new_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_tree_destroy(SEXP s1);
extern SEXP R_g_tree_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_tree_height(SEXP s1);
extern SEXP R_g_tree_insert(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_tree_lookup(SEXP s1, SEXP s2);
extern SEXP R_g_tree_lookup_extended(SEXP s1, SEXP s2);
extern SEXP R_g_tree_nnodes(SEXP s1);
extern SEXP R_g_tree_ref(SEXP s1);
extern SEXP R_g_tree_remove(SEXP s1, SEXP s2);
extern SEXP R_g_tree_replace(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_tree_search(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_tree_steal(SEXP s1, SEXP s2);
extern SEXP R_g_tree_traverse(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_tree_unref(SEXP s1);
extern SEXP R_g_tuples_destroy(SEXP s1);
extern SEXP R_g_tuples_index(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_unicode_script_from_iso15924(SEXP s1);
extern SEXP R_g_unicode_script_to_iso15924(SEXP s1);
extern SEXP R_g_uri_error_quark(void);
extern SEXP R_g_uri_escape_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_uri_list_extract_uris(SEXP s1);
extern SEXP R_g_uri_parse_scheme(SEXP s1);
extern SEXP R_g_uri_unescape_segment(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_uri_unescape_string(SEXP s1, SEXP s2);
extern SEXP R_g_variant_new_array(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_variant_new_boolean(SEXP s1);
extern SEXP R_g_variant_new_byte(SEXP s1);
extern SEXP R_g_variant_new_bytestring(SEXP s1);
extern SEXP R_g_variant_new_bytestring_array(SEXP s1, SEXP s2);
extern SEXP R_g_variant_new_dict_entry(SEXP s1, SEXP s2);
extern SEXP R_g_variant_new_double(SEXP s1);
extern SEXP R_g_variant_new_fixed_array(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_variant_new_from_bytes(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_variant_new_from_data(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_variant_new_handle(SEXP s1);
extern SEXP R_g_variant_new_int16(SEXP s1);
extern SEXP R_g_variant_new_int32(SEXP s1);
extern SEXP R_g_variant_new_int64(SEXP s1);
extern SEXP R_g_variant_new_maybe(SEXP s1, SEXP s2);
extern SEXP R_g_variant_new_object_path(SEXP s1);
extern SEXP R_g_variant_new_objv(SEXP s1, SEXP s2);
extern SEXP R_g_variant_new_signature(SEXP s1);
extern SEXP R_g_variant_new_string(SEXP s1);
extern SEXP R_g_variant_new_strv(SEXP s1, SEXP s2);
extern SEXP R_g_variant_new_tuple(SEXP s1, SEXP s2);
extern SEXP R_g_variant_new_uint16(SEXP s1);
extern SEXP R_g_variant_new_uint32(SEXP s1);
extern SEXP R_g_variant_new_uint64(SEXP s1);
extern SEXP R_g_variant_new_variant(SEXP s1);
extern SEXP R_g_variant_byteswap(SEXP s1);
extern SEXP R_g_variant_check_format_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_variant_classify(SEXP s1);
extern SEXP R_g_variant_compare(SEXP s1, SEXP s2);
extern SEXP R_g_variant_dup_bytestring(SEXP s1);
extern SEXP R_g_variant_dup_bytestring_array(SEXP s1);
extern SEXP R_g_variant_dup_objv(SEXP s1);
extern SEXP R_g_variant_dup_string(SEXP s1);
extern SEXP R_g_variant_dup_strv(SEXP s1);
extern SEXP R_g_variant_equal(SEXP s1, SEXP s2);
extern SEXP R_g_variant_get_boolean(SEXP s1);
extern SEXP R_g_variant_get_byte(SEXP s1);
extern SEXP R_g_variant_get_bytestring(SEXP s1);
extern SEXP R_g_variant_get_bytestring_array(SEXP s1);
extern SEXP R_g_variant_get_child_value(SEXP s1, SEXP s2);
extern SEXP R_g_variant_get_data(SEXP s1);
extern SEXP R_g_variant_get_data_as_bytes(SEXP s1);
extern SEXP R_g_variant_get_double(SEXP s1);
extern SEXP R_g_variant_get_handle(SEXP s1);
extern SEXP R_g_variant_get_int16(SEXP s1);
extern SEXP R_g_variant_get_int32(SEXP s1);
extern SEXP R_g_variant_get_int64(SEXP s1);
extern SEXP R_g_variant_get_maybe(SEXP s1);
extern SEXP R_g_variant_get_normal_form(SEXP s1);
extern SEXP R_g_variant_get_objv(SEXP s1);
extern SEXP R_g_variant_get_size(SEXP s1);
extern SEXP R_g_variant_get_string(SEXP s1);
extern SEXP R_g_variant_get_strv(SEXP s1);
extern SEXP R_g_variant_get_type(SEXP s1);
extern SEXP R_g_variant_get_type_string(SEXP s1);
extern SEXP R_g_variant_get_uint16(SEXP s1);
extern SEXP R_g_variant_get_uint32(SEXP s1);
extern SEXP R_g_variant_get_uint64(SEXP s1);
extern SEXP R_g_variant_get_variant(SEXP s1);
extern SEXP R_g_variant_hash(SEXP s1);
extern SEXP R_g_variant_is_container(SEXP s1);
extern SEXP R_g_variant_is_floating(SEXP s1);
extern SEXP R_g_variant_is_normal_form(SEXP s1);
extern SEXP R_g_variant_is_of_type(SEXP s1, SEXP s2);
extern SEXP R_g_variant_lookup_value(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_variant_n_children(SEXP s1);
extern SEXP R_g_variant_print(SEXP s1, SEXP s2);
extern SEXP R_g_variant_ref(SEXP s1);
extern SEXP R_g_variant_ref_sink(SEXP s1);
extern SEXP R_g_variant_store(SEXP s1, SEXP s2);
extern SEXP R_g_variant_take_ref(SEXP s1);
extern SEXP R_g_variant_unref(SEXP s1);
extern SEXP R_g_variant_is_object_path(SEXP s1);
extern SEXP R_g_variant_is_signature(SEXP s1);
extern SEXP R_g_variant_parse(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_variant_parse_error_print_context(SEXP s1, SEXP s2);
extern SEXP R_g_variant_parse_error_quark(void);
extern SEXP R_g_variant_parser_get_error_quark(void);
extern SEXP R_g_variant_builder_new(SEXP s1);
extern SEXP R_g_variant_builder_add_value(SEXP s1, SEXP s2);
extern SEXP R_g_variant_builder_close(SEXP s1);
extern SEXP R_g_variant_builder_end(SEXP s1);
extern SEXP R_g_variant_builder_open(SEXP s1, SEXP s2);
extern SEXP R_g_variant_builder_ref(SEXP s1);
extern SEXP R_g_variant_builder_unref(SEXP s1);
extern SEXP R_g_variant_dict_new(SEXP s1);
extern SEXP R_g_variant_dict_clear(SEXP s1);
extern SEXP R_g_variant_dict_contains(SEXP s1, SEXP s2);
extern SEXP R_g_variant_dict_end(SEXP s1);
extern SEXP R_g_variant_dict_insert_value(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_variant_dict_lookup_value(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_variant_dict_ref(SEXP s1);
extern SEXP R_g_variant_dict_remove(SEXP s1, SEXP s2);
extern SEXP R_g_variant_dict_unref(SEXP s1);
extern SEXP R_g_variant_iter_free(SEXP s1);
extern SEXP R_g_variant_iter_n_children(SEXP s1);
extern SEXP R_g_variant_iter_next_value(SEXP s1);
extern SEXP R_g_variant_type_new(SEXP s1);
extern SEXP R_g_variant_type_new_array(SEXP s1);
extern SEXP R_g_variant_type_new_dict_entry(SEXP s1, SEXP s2);
extern SEXP R_g_variant_type_new_maybe(SEXP s1);
extern SEXP R_g_variant_type_new_tuple(SEXP s1, SEXP s2);
extern SEXP R_g_variant_type_copy(SEXP s1);
extern SEXP R_g_variant_type_dup_string(SEXP s1);
extern SEXP R_g_variant_type_element(SEXP s1);
extern SEXP R_g_variant_type_equal(SEXP s1, SEXP s2);
extern SEXP R_g_variant_type_first(SEXP s1);
extern SEXP R_g_variant_type_free(SEXP s1);
extern SEXP R_g_variant_type_get_string_length(SEXP s1);
extern SEXP R_g_variant_type_hash(SEXP s1);
extern SEXP R_g_variant_type_is_array(SEXP s1);
extern SEXP R_g_variant_type_is_basic(SEXP s1);
extern SEXP R_g_variant_type_is_container(SEXP s1);
extern SEXP R_g_variant_type_is_definite(SEXP s1);
extern SEXP R_g_variant_type_is_dict_entry(SEXP s1);
extern SEXP R_g_variant_type_is_maybe(SEXP s1);
extern SEXP R_g_variant_type_is_subtype_of(SEXP s1, SEXP s2);
extern SEXP R_g_variant_type_is_tuple(SEXP s1);
extern SEXP R_g_variant_type_is_variant(SEXP s1);
extern SEXP R_g_variant_type_key(SEXP s1);
extern SEXP R_g_variant_type_n_items(SEXP s1);
extern SEXP R_g_variant_type_next(SEXP s1);
extern SEXP R_g_variant_type_value(SEXP s1);
extern SEXP R_g_variant_type_checked_(SEXP s1);
extern SEXP R_g_variant_type_string_get_depth_(SEXP s1);
extern SEXP R_g_variant_type_string_is_valid(SEXP s1);
extern SEXP R_g_variant_type_string_scan(SEXP s1, SEXP s2);
extern SEXP R_g_access(SEXP s1, SEXP s2);
extern SEXP R_g_ascii_digit_value(SEXP s1);
extern SEXP R_g_ascii_dtostr(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_ascii_formatd(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_ascii_strcasecmp(SEXP s1, SEXP s2);
extern SEXP R_g_ascii_strdown(SEXP s1, SEXP s2);
extern SEXP R_g_ascii_string_to_signed(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_ascii_string_to_unsigned(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_ascii_strncasecmp(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_ascii_strtod(SEXP s1);
extern SEXP R_g_ascii_strtoll(SEXP s1, SEXP s2);
extern SEXP R_g_ascii_strtoull(SEXP s1, SEXP s2);
extern SEXP R_g_ascii_strup(SEXP s1, SEXP s2);
extern SEXP R_g_ascii_tolower(SEXP s1);
extern SEXP R_g_ascii_toupper(SEXP s1);
extern SEXP R_g_ascii_xdigit_value(SEXP s1);
extern SEXP R_g_assert_warning(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_assertion_message(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_assertion_message_cmpint(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8, SEXP s9);
extern SEXP R_g_assertion_message_cmpstr(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_g_assertion_message_cmpstrv(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_g_assertion_message_error(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_g_atexit(SEXP s1);
extern SEXP R_g_base64_decode(SEXP s1);
extern SEXP R_g_base64_decode_inplace(void);
extern SEXP R_g_base64_encode(SEXP s1, SEXP s2);
extern SEXP R_g_base64_encode_close(SEXP s1);
extern SEXP R_g_base64_encode_step(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_basename(SEXP s1);
extern SEXP R_g_bit_lock(SEXP s1, SEXP s2);
extern SEXP R_g_bit_nth_lsf(SEXP s1, SEXP s2);
extern SEXP R_g_bit_nth_msf(SEXP s1, SEXP s2);
extern SEXP R_g_bit_storage(SEXP s1);
extern SEXP R_g_bit_trylock(SEXP s1, SEXP s2);
extern SEXP R_g_bit_unlock(SEXP s1, SEXP s2);
extern SEXP R_g_blow_chunks(void);
extern SEXP R_g_build_filenamev(SEXP s1);
extern SEXP R_g_build_pathv(SEXP s1, SEXP s2);
extern SEXP R_g_chdir(SEXP s1);
extern SEXP R_glib_check_version(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_child_watch_add_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_child_watch_source_new(SEXP s1);
extern SEXP R_g_chmod(SEXP s1, SEXP s2);
extern SEXP R_g_clear_error(void);
extern SEXP R_g_close(SEXP s1);
extern SEXP R_g_compute_checksum_for_bytes(SEXP s1, SEXP s2);
extern SEXP R_g_compute_checksum_for_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_compute_checksum_for_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_compute_hmac_for_bytes(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_compute_hmac_for_data(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_compute_hmac_for_string(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_convert(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_convert_error_quark(void);
extern SEXP R_g_convert_with_fallback(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_creat(SEXP s1, SEXP s2);
extern SEXP R_g_datalist_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_datalist_get_data(SEXP s1, SEXP s2);
extern SEXP R_g_datalist_get_flags(SEXP s1);
extern SEXP R_g_datalist_id_get_data(SEXP s1, SEXP s2);
extern SEXP R_g_datalist_set_flags(SEXP s1, SEXP s2);
extern SEXP R_g_datalist_unset_flags(SEXP s1, SEXP s2);
extern SEXP R_g_dataset_destroy(SEXP s1);
extern SEXP R_g_dataset_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_dataset_id_get_data(SEXP s1, SEXP s2);
extern SEXP R_g_dcgettext(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_dgettext(SEXP s1, SEXP s2);
extern SEXP R_g_direct_equal(SEXP s1, SEXP s2);
extern SEXP R_g_direct_hash(SEXP s1);
extern SEXP R_g_dngettext(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_double_equal(SEXP s1, SEXP s2);
extern SEXP R_g_double_hash(SEXP s1);
extern SEXP R_g_dpgettext(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_dpgettext2(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_environ_getenv(SEXP s1, SEXP s2);
extern SEXP R_g_environ_setenv(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_environ_unsetenv(SEXP s1, SEXP s2);
extern SEXP R_g_file_error_from_errno(SEXP s1);
extern SEXP R_g_file_error_quark(void);
extern SEXP R_g_file_get_contents(SEXP s1);
extern SEXP R_g_file_open_tmp(SEXP s1);
extern SEXP R_g_file_read_link(SEXP s1);
extern SEXP R_g_file_set_contents(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_file_test(SEXP s1, SEXP s2);
extern SEXP R_g_filename_display_basename(SEXP s1);
extern SEXP R_g_filename_display_name(SEXP s1);
extern SEXP R_g_filename_from_uri(SEXP s1);
extern SEXP R_g_filename_from_utf8(SEXP s1, SEXP s2);
extern SEXP R_g_filename_to_uri(SEXP s1, SEXP s2);
extern SEXP R_g_filename_to_utf8(SEXP s1, SEXP s2);
extern SEXP R_g_find_program_in_path(SEXP s1);
extern SEXP R_g_fopen(SEXP s1, SEXP s2);
extern SEXP R_g_format_size(SEXP s1);
extern SEXP R_g_format_size_for_display(SEXP s1);
extern SEXP R_g_format_size_full(SEXP s1, SEXP s2);
extern SEXP R_g_free(SEXP s1);
extern SEXP R_g_freopen(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_get_application_name(void);
extern SEXP R_g_get_charset(void);
extern SEXP R_g_get_codeset(void);
extern SEXP R_g_get_current_dir(void);
extern SEXP R_g_get_current_time(SEXP s1);
extern SEXP R_g_get_environ(void);
extern SEXP R_g_get_filename_charsets(void);
extern SEXP R_g_get_home_dir(void);
extern SEXP R_g_get_host_name(void);
extern SEXP R_g_get_language_names(void);
extern SEXP R_g_get_locale_variants(SEXP s1);
extern SEXP R_g_get_monotonic_time(void);
extern SEXP R_g_get_num_processors(void);
extern SEXP R_g_get_prgname(void);
extern SEXP R_g_get_real_name(void);
extern SEXP R_g_get_real_time(void);
extern SEXP R_g_get_system_config_dirs(void);
extern SEXP R_g_get_system_data_dirs(void);
extern SEXP R_g_get_tmp_dir(void);
extern SEXP R_g_get_user_cache_dir(void);
extern SEXP R_g_get_user_config_dir(void);
extern SEXP R_g_get_user_data_dir(void);
extern SEXP R_g_get_user_name(void);
extern SEXP R_g_get_user_runtime_dir(void);
extern SEXP R_g_get_user_special_dir(SEXP s1);
extern SEXP R_g_getenv(SEXP s1);
extern SEXP R_g_hostname_is_ascii_encoded(SEXP s1);
extern SEXP R_g_hostname_is_ip_address(SEXP s1);
extern SEXP R_g_hostname_is_non_ascii(SEXP s1);
extern SEXP R_g_hostname_to_ascii(SEXP s1);
extern SEXP R_g_hostname_to_unicode(SEXP s1);
extern SEXP R_g_idle_add_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_idle_remove_by_data(SEXP s1);
extern SEXP R_g_idle_source_new(void);
extern SEXP R_g_int64_equal(SEXP s1, SEXP s2);
extern SEXP R_g_int64_hash(SEXP s1);
extern SEXP R_g_int_equal(SEXP s1, SEXP s2);
extern SEXP R_g_int_hash(SEXP s1);
extern SEXP R_g_intern_static_string(SEXP s1);
extern SEXP R_g_intern_string(SEXP s1);
extern SEXP R_g_io_add_watch_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_io_create_watch(SEXP s1, SEXP s2);
extern SEXP R_g_listenv(void);
extern SEXP R_g_locale_from_utf8(SEXP s1, SEXP s2);
extern SEXP R_g_locale_to_utf8(SEXP s1, SEXP s2);
extern SEXP R_g_log_default_handler(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_log_remove_handler(SEXP s1, SEXP s2);
extern SEXP R_g_log_set_always_fatal(SEXP s1);
extern SEXP R_g_log_set_fatal_mask(SEXP s1, SEXP s2);
extern SEXP R_g_log_set_handler_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_log_set_writer_func(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_log_structured_array(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_log_variant(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_log_writer_default(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_log_writer_format_fields(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_log_writer_is_journald(SEXP s1);
extern SEXP R_g_log_writer_journald(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_log_writer_standard_streams(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_log_writer_supports_color(SEXP s1);
extern SEXP R_g_lstat(SEXP s1, SEXP s2);
extern SEXP R_g_main_current_source(void);
extern SEXP R_g_main_depth(void);
extern SEXP R_g_malloc(SEXP s1);
extern SEXP R_g_malloc0(SEXP s1);
extern SEXP R_g_malloc0_n(SEXP s1, SEXP s2);
extern SEXP R_g_malloc_n(SEXP s1, SEXP s2);
extern SEXP R_g_markup_error_quark(void);
extern SEXP R_g_markup_escape_text(SEXP s1, SEXP s2);
extern SEXP R_g_mem_is_system_malloc(void);
extern SEXP R_g_mem_profile(void);
extern SEXP R_g_mem_set_vtable(SEXP s1);
extern SEXP R_g_memdup(SEXP s1, SEXP s2);
extern SEXP R_g_mkdir(SEXP s1, SEXP s2);
extern SEXP R_g_mkdir_with_parents(SEXP s1, SEXP s2);
extern SEXP R_g_nullify_pointer(SEXP s1);
extern SEXP R_g_number_parser_error_quark(void);
extern SEXP R_g_on_error_query(SEXP s1);
extern SEXP R_g_on_error_stack_trace(SEXP s1);
extern SEXP R_g_open(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_option_error_quark(void);
extern SEXP R_g_parse_debug_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_path_get_basename(SEXP s1);
extern SEXP R_g_path_get_dirname(SEXP s1);
extern SEXP R_g_path_is_absolute(SEXP s1);
extern SEXP R_g_path_skip_root(SEXP s1);
extern SEXP R_g_pattern_match_simple(SEXP s1, SEXP s2);
extern SEXP R_g_poll(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_propagate_error(SEXP s1);
extern SEXP R_g_qsort_with_data(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_quark_from_static_string(SEXP s1);
extern SEXP R_g_quark_from_string(SEXP s1);
extern SEXP R_g_quark_to_string(SEXP s1);
extern SEXP R_g_quark_try_string(SEXP s1);
extern SEXP R_g_random_double(void);
extern SEXP R_g_random_double_range(SEXP s1, SEXP s2);
extern SEXP R_g_random_int(void);
extern SEXP R_g_random_int_range(SEXP s1, SEXP s2);
extern SEXP R_g_random_set_seed(SEXP s1);
extern SEXP R_g_realloc(SEXP s1, SEXP s2);
extern SEXP R_g_realloc_n(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_reload_user_special_dirs_cache(void);
extern SEXP R_g_remove(SEXP s1);
extern SEXP R_g_rename(SEXP s1, SEXP s2);
extern SEXP R_g_rmdir(SEXP s1);
extern SEXP R_g_set_application_name(SEXP s1);
extern SEXP R_g_set_error_literal(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_set_prgname(SEXP s1);
extern SEXP R_g_setenv(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_shell_error_quark(void);
extern SEXP R_g_shell_parse_argv(SEXP s1);
extern SEXP R_g_shell_quote(SEXP s1);
extern SEXP R_g_shell_unquote(SEXP s1);
extern SEXP R_g_slice_alloc(SEXP s1);
extern SEXP R_g_slice_alloc0(SEXP s1);
extern SEXP R_g_slice_copy(SEXP s1, SEXP s2);
extern SEXP R_g_slice_free1(SEXP s1, SEXP s2);
extern SEXP R_g_slice_free_chain_with_offset(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_slice_get_config(SEXP s1);
extern SEXP R_g_slice_get_config_state(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_slice_set_config(SEXP s1, SEXP s2);
extern SEXP R_g_spaced_primes_closest(SEXP s1);
extern SEXP R_g_spawn_async(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_spawn_async_with_pipes(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_spawn_check_exit_status(SEXP s1);
extern SEXP R_g_spawn_close_pid(SEXP s1);
extern SEXP R_g_spawn_command_line_async(SEXP s1);
extern SEXP R_g_spawn_command_line_sync(SEXP s1);
extern SEXP R_g_spawn_error_quark(void);
extern SEXP R_g_spawn_exit_error_quark(void);
extern SEXP R_g_spawn_sync(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_stat(SEXP s1, SEXP s2);
extern SEXP R_g_stpcpy(SEXP s1, SEXP s2);
extern SEXP R_g_str_equal(SEXP s1, SEXP s2);
extern SEXP R_g_str_has_prefix(SEXP s1, SEXP s2);
extern SEXP R_g_str_has_suffix(SEXP s1, SEXP s2);
extern SEXP R_g_str_hash(SEXP s1);
extern SEXP R_g_str_is_ascii(SEXP s1);
extern SEXP R_g_str_match_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_str_to_ascii(SEXP s1, SEXP s2);
extern SEXP R_g_str_tokenize_and_fold(SEXP s1, SEXP s2);
extern SEXP R_g_strcanon(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_strcasecmp(SEXP s1, SEXP s2);
extern SEXP R_g_strchomp(SEXP s1);
extern SEXP R_g_strchug(SEXP s1);
extern SEXP R_g_strcmp0(SEXP s1, SEXP s2);
extern SEXP R_g_strcompress(SEXP s1);
extern SEXP R_g_strdelimit(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_strdown(SEXP s1);
extern SEXP R_g_strdup(SEXP s1);
extern SEXP R_g_strdupv(SEXP s1);
extern SEXP R_g_strerror(SEXP s1);
extern SEXP R_g_strescape(SEXP s1, SEXP s2);
extern SEXP R_g_strfreev(SEXP s1);
extern SEXP R_g_strip_context(SEXP s1, SEXP s2);
extern SEXP R_g_strjoinv(SEXP s1, SEXP s2);
extern SEXP R_g_strlcat(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_strlcpy(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_strncasecmp(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_strndup(SEXP s1, SEXP s2);
extern SEXP R_g_strnfill(SEXP s1, SEXP s2);
extern SEXP R_g_strreverse(SEXP s1);
extern SEXP R_g_strrstr(SEXP s1, SEXP s2);
extern SEXP R_g_strrstr_len(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_strsignal(SEXP s1);
extern SEXP R_g_strsplit(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_strsplit_set(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_strstr_len(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_strtod(SEXP s1);
extern SEXP R_g_strup(SEXP s1);
extern SEXP R_g_strv_contains(SEXP s1, SEXP s2);
extern SEXP R_g_strv_get_type(void);
extern SEXP R_g_strv_length(SEXP s1);
extern SEXP R_g_test_add_data_func(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_test_add_data_func_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_test_add_func(SEXP s1, SEXP s2);
extern SEXP R_g_test_assert_expected_messages_internal(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_test_bug(SEXP s1);
extern SEXP R_g_test_bug_base(SEXP s1);
extern SEXP R_g_test_expect_message(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_test_fail(void);
extern SEXP R_g_test_failed(void);
extern SEXP R_g_test_get_dir(SEXP s1);
extern SEXP R_g_test_incomplete(SEXP s1);
extern SEXP R_g_test_log_type_name(SEXP s1);
extern SEXP R_g_test_queue_destroy(SEXP s1, SEXP s2);
extern SEXP R_g_test_queue_free(SEXP s1);
extern SEXP R_g_test_rand_double(void);
extern SEXP R_g_test_rand_double_range(SEXP s1, SEXP s2);
extern SEXP R_g_test_rand_int(void);
extern SEXP R_g_test_rand_int_range(SEXP s1, SEXP s2);
extern SEXP R_g_test_run(void);
extern SEXP R_g_test_run_suite(SEXP s1);
extern SEXP R_g_test_set_nonfatal_assertions(void);
extern SEXP R_g_test_skip(SEXP s1);
extern SEXP R_g_test_subprocess(void);
extern SEXP R_g_test_timer_elapsed(void);
extern SEXP R_g_test_timer_last(void);
extern SEXP R_g_test_timer_start(void);
extern SEXP R_g_test_trap_assertions(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_test_trap_fork(SEXP s1, SEXP s2);
extern SEXP R_g_test_trap_has_passed(void);
extern SEXP R_g_test_trap_reached_timeout(void);
extern SEXP R_g_test_trap_subprocess(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_timeout_add_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_timeout_add_seconds_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_timeout_source_new(SEXP s1);
extern SEXP R_g_timeout_source_new_seconds(SEXP s1);
extern SEXP R_g_try_malloc(SEXP s1);
extern SEXP R_g_try_malloc0(SEXP s1);
extern SEXP R_g_try_malloc0_n(SEXP s1, SEXP s2);
extern SEXP R_g_try_malloc_n(SEXP s1, SEXP s2);
extern SEXP R_g_try_realloc(SEXP s1, SEXP s2);
extern SEXP R_g_try_realloc_n(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_ucs4_to_utf16(SEXP s1, SEXP s2);
extern SEXP R_g_ucs4_to_utf8(SEXP s1, SEXP s2);
extern SEXP R_g_unichar_break_type(SEXP s1);
extern SEXP R_g_unichar_combining_class(SEXP s1);
extern SEXP R_g_unichar_compose(SEXP s1, SEXP s2);
extern SEXP R_g_unichar_decompose(SEXP s1);
extern SEXP R_g_unichar_digit_value(SEXP s1);
extern SEXP R_g_unichar_fully_decompose(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_unichar_get_mirror_char(SEXP s1);
extern SEXP R_g_unichar_get_script(SEXP s1);
extern SEXP R_g_unichar_isalnum(SEXP s1);
extern SEXP R_g_unichar_isalpha(SEXP s1);
extern SEXP R_g_unichar_iscntrl(SEXP s1);
extern SEXP R_g_unichar_isdefined(SEXP s1);
extern SEXP R_g_unichar_isdigit(SEXP s1);
extern SEXP R_g_unichar_isgraph(SEXP s1);
extern SEXP R_g_unichar_islower(SEXP s1);
extern SEXP R_g_unichar_ismark(SEXP s1);
extern SEXP R_g_unichar_isprint(SEXP s1);
extern SEXP R_g_unichar_ispunct(SEXP s1);
extern SEXP R_g_unichar_isspace(SEXP s1);
extern SEXP R_g_unichar_istitle(SEXP s1);
extern SEXP R_g_unichar_isupper(SEXP s1);
extern SEXP R_g_unichar_iswide(SEXP s1);
extern SEXP R_g_unichar_iswide_cjk(SEXP s1);
extern SEXP R_g_unichar_isxdigit(SEXP s1);
extern SEXP R_g_unichar_iszerowidth(SEXP s1);
extern SEXP R_g_unichar_to_utf8(SEXP s1);
extern SEXP R_g_unichar_tolower(SEXP s1);
extern SEXP R_g_unichar_totitle(SEXP s1);
extern SEXP R_g_unichar_toupper(SEXP s1);
extern SEXP R_g_unichar_type(SEXP s1);
extern SEXP R_g_unichar_validate(SEXP s1);
extern SEXP R_g_unichar_xdigit_value(SEXP s1);
extern SEXP R_g_unicode_canonical_decomposition(SEXP s1, SEXP s2);
extern SEXP R_g_unicode_canonical_ordering(SEXP s1, SEXP s2);
extern SEXP R_g_unlink(SEXP s1);
extern SEXP R_g_unsetenv(SEXP s1);
extern SEXP R_g_usleep(SEXP s1);
extern SEXP R_g_utf16_to_ucs4(SEXP s1, SEXP s2);
extern SEXP R_g_utf16_to_utf8(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_casefold(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_collate(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_collate_key(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_collate_key_for_filename(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_find_next_char(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_find_prev_char(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_get_char(SEXP s1);
extern SEXP R_g_utf8_get_char_validated(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_make_valid(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_normalize(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_utf8_offset_to_pointer(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_pointer_to_offset(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_prev_char(SEXP s1);
extern SEXP R_g_utf8_strchr(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_utf8_strdown(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_strlen(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_strncpy(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_utf8_strrchr(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_utf8_strreverse(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_strup(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_substring(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_utf8_to_ucs4(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_to_ucs4_fast(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_to_utf16(SEXP s1, SEXP s2);
extern SEXP R_g_utf8_validate(SEXP s1, SEXP s2);
extern SEXP R_g_utime(SEXP s1, SEXP s2);
extern SEXP R_g_uuid_string_is_valid(SEXP s1);
extern SEXP R_g_uuid_string_random(void);
extern SEXP R_g_variant_get_gtype(void);
extern SEXP R_g_binding_get_flags(SEXP s1);
extern SEXP R_g_binding_get_source(SEXP s1);
extern SEXP R_g_binding_get_source_property(SEXP s1);
extern SEXP R_g_binding_get_target(SEXP s1);
extern SEXP R_g_binding_get_target_property(SEXP s1);
extern SEXP R_g_binding_unbind(SEXP s1);
extern SEXP R_g_cclosure_marshal_BOOLEAN__BOXED_BOXED(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_BOOLEAN__FLAGS(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_STRING__OBJECT_POINTER(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__BOOLEAN(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__BOXED(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__CHAR(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__DOUBLE(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__ENUM(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__FLAGS(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__FLOAT(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__INT(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__LONG(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__OBJECT(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__PARAM(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__POINTER(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__STRING(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__UCHAR(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__UINT(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__UINT_POINTER(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__ULONG(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__VARIANT(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_VOID__VOID(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_cclosure_marshal_generic(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_closure_new_object(SEXP s1, SEXP s2);
extern SEXP R_g_closure_new_simple(SEXP s1, SEXP s2);
extern SEXP R_g_closure_invalidate(SEXP s1);
extern SEXP R_g_closure_invoke(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_closure_ref(SEXP s1);
extern SEXP R_g_closure_sink(SEXP s1);
extern SEXP R_g_closure_unref(SEXP s1);
extern SEXP R_g_object_newv(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_object_compat_control(SEXP s1, SEXP s2);
extern SEXP R_g_object_interface_find_property(SEXP s1, SEXP s2);
extern SEXP R_g_object_interface_install_property(SEXP s1, SEXP s2);
extern SEXP R_g_object_interface_list_properties(SEXP s1);
extern SEXP R_g_object_bind_property(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_object_bind_property_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8, SEXP s9);
extern SEXP R_g_object_bind_property_with_closures(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_object_force_floating(SEXP s1);
extern SEXP R_g_object_freeze_notify(SEXP s1);
extern SEXP R_g_object_get_data(SEXP s1, SEXP s2);
extern SEXP R_g_object_get_property(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_object_get_qdata(SEXP s1, SEXP s2);
extern SEXP R_g_object_getv(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_object_is_floating(SEXP s1);
extern SEXP R_g_object_notify(SEXP s1, SEXP s2);
extern SEXP R_g_object_notify_by_pspec(SEXP s1, SEXP s2);
extern SEXP R_g_object_ref(SEXP s1);
extern SEXP R_g_object_ref_sink(SEXP s1);
extern SEXP R_g_object_run_dispose(SEXP s1);
extern SEXP R_g_object_set_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_object_set_property(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_object_steal_data(SEXP s1, SEXP s2);
extern SEXP R_g_object_steal_qdata(SEXP s1, SEXP s2);
extern SEXP R_g_object_thaw_notify(SEXP s1);
extern SEXP R_g_object_unref(SEXP s1);
extern SEXP R_g_object_watch_closure(SEXP s1, SEXP s2);
extern SEXP R_g_object_class_find_property(SEXP s1, SEXP s2);
extern SEXP R_g_object_class_install_properties(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_object_class_install_property(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_object_class_list_properties(SEXP s1);
extern SEXP R_g_object_class_override_property(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_param_spec_get_blurb(SEXP s1);
extern SEXP R_g_param_spec_get_default_value(SEXP s1);
extern SEXP R_g_param_spec_get_name(SEXP s1);
extern SEXP R_g_param_spec_get_name_quark(SEXP s1);
extern SEXP R_g_param_spec_get_nick(SEXP s1);
extern SEXP R_g_param_spec_get_qdata(SEXP s1, SEXP s2);
extern SEXP R_g_param_spec_get_redirect_target(SEXP s1);
extern SEXP R_g_param_spec_set_qdata(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_param_spec_sink(SEXP s1);
extern SEXP R_g_param_spec_steal_qdata(SEXP s1, SEXP s2);
extern SEXP R_g_param_spec_pool_insert(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_param_spec_pool_list(SEXP s1, SEXP s2);
extern SEXP R_g_param_spec_pool_list_owned(SEXP s1, SEXP s2);
extern SEXP R_g_param_spec_pool_lookup(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_param_spec_pool_remove(SEXP s1, SEXP s2);
extern SEXP R_g_source_set_closure(SEXP s1, SEXP s2);
extern SEXP R_g_source_set_dummy_callback(SEXP s1);
extern SEXP R_g_type_class_add_private(SEXP s1, SEXP s2);
extern SEXP R_g_type_class_get_private(SEXP s1, SEXP s2);
extern SEXP R_g_type_class_peek_parent(SEXP s1);
extern SEXP R_g_type_class_unref(SEXP s1);
extern SEXP R_g_type_class_adjust_private_offset(SEXP s1, SEXP s2);
extern SEXP R_g_type_class_peek(SEXP s1);
extern SEXP R_g_type_class_peek_static(SEXP s1);
extern SEXP R_g_type_class_ref(SEXP s1);
extern SEXP R_g_type_instance_get_private(SEXP s1, SEXP s2);
extern SEXP R_g_type_interface_peek_parent(SEXP s1);
extern SEXP R_g_type_interface_add_prerequisite(SEXP s1, SEXP s2);
extern SEXP R_g_type_interface_get_plugin(SEXP s1, SEXP s2);
extern SEXP R_g_type_interface_peek(SEXP s1, SEXP s2);
extern SEXP R_g_type_interface_prerequisites(SEXP s1);
extern SEXP R_g_type_module_add_interface(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_type_module_register_enum(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_type_module_register_flags(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_type_module_register_type(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_type_module_set_name(SEXP s1, SEXP s2);
extern SEXP R_g_type_module_unuse(SEXP s1);
extern SEXP R_g_type_module_use(SEXP s1);
extern SEXP R_g_type_plugin_complete_interface_info(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_type_plugin_complete_type_info(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_type_plugin_unuse(SEXP s1);
extern SEXP R_g_type_plugin_use(SEXP s1);
extern SEXP R_g_value_copy(SEXP s1, SEXP s2);
extern SEXP R_g_value_dup_object(SEXP s1);
extern SEXP R_g_value_dup_string(SEXP s1);
extern SEXP R_g_value_dup_variant(SEXP s1);
extern SEXP R_g_value_fits_pointer(SEXP s1);
extern SEXP R_g_value_get_boolean(SEXP s1);
extern SEXP R_g_value_get_boxed(SEXP s1);
extern SEXP R_g_value_get_char(SEXP s1);
extern SEXP R_g_value_get_double(SEXP s1);
extern SEXP R_g_value_get_enum(SEXP s1);
extern SEXP R_g_value_get_flags(SEXP s1);
extern SEXP R_g_value_get_float(SEXP s1);
extern SEXP R_g_value_get_gtype(SEXP s1);
extern SEXP R_g_value_get_int(SEXP s1);
extern SEXP R_g_value_get_int64(SEXP s1);
extern SEXP R_g_value_get_long(SEXP s1);
extern SEXP R_g_value_get_object(SEXP s1);
extern SEXP R_g_value_get_param(SEXP s1);
extern SEXP R_g_value_get_pointer(SEXP s1);
extern SEXP R_g_value_get_schar(SEXP s1);
extern SEXP R_g_value_get_string(SEXP s1);
extern SEXP R_g_value_get_uchar(SEXP s1);
extern SEXP R_g_value_get_uint(SEXP s1);
extern SEXP R_g_value_get_uint64(SEXP s1);
extern SEXP R_g_value_get_ulong(SEXP s1);
extern SEXP R_g_value_get_variant(SEXP s1);
extern SEXP R_g_value_init(SEXP s1, SEXP s2);
extern SEXP R_g_value_init_from_instance(SEXP s1, SEXP s2);
extern SEXP R_g_value_peek_pointer(SEXP s1);
extern SEXP R_g_value_reset(SEXP s1);
extern SEXP R_g_value_set_boolean(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_boxed(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_boxed_take_ownership(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_char(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_double(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_enum(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_flags(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_float(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_gtype(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_instance(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_int(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_int64(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_long(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_object(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_param(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_pointer(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_schar(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_static_boxed(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_static_string(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_string(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_string_take_ownership(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_uchar(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_uint(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_uint64(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_ulong(SEXP s1, SEXP s2);
extern SEXP R_g_value_set_variant(SEXP s1, SEXP s2);
extern SEXP R_g_value_take_boxed(SEXP s1, SEXP s2);
extern SEXP R_g_value_take_string(SEXP s1, SEXP s2);
extern SEXP R_g_value_take_variant(SEXP s1, SEXP s2);
extern SEXP R_g_value_transform(SEXP s1, SEXP s2);
extern SEXP R_g_value_unset(SEXP s1);
extern SEXP R_g_value_type_compatible(SEXP s1, SEXP s2);
extern SEXP R_g_value_type_transformable(SEXP s1, SEXP s2);
extern SEXP R_g_value_array_new(SEXP s1);
extern SEXP R_g_value_array_append(SEXP s1, SEXP s2);
extern SEXP R_g_value_array_copy(SEXP s1);
extern SEXP R_g_value_array_get_nth(SEXP s1, SEXP s2);
extern SEXP R_g_value_array_insert(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_value_array_prepend(SEXP s1, SEXP s2);
extern SEXP R_g_value_array_remove(SEXP s1, SEXP s2);
extern SEXP R_g_value_array_sort(SEXP s1, SEXP s2);
extern SEXP R_g_value_array_sort_with_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_boxed_copy(SEXP s1, SEXP s2);
extern SEXP R_g_boxed_free(SEXP s1, SEXP s2);
extern SEXP R_g_boxed_type_register_static(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_enum_complete_type_info(SEXP s1, SEXP s2);
extern SEXP R_g_enum_get_value(SEXP s1, SEXP s2);
extern SEXP R_g_enum_get_value_by_name(SEXP s1, SEXP s2);
extern SEXP R_g_enum_get_value_by_nick(SEXP s1, SEXP s2);
extern SEXP R_g_enum_register_static(SEXP s1, SEXP s2);
extern SEXP R_g_enum_to_string(SEXP s1, SEXP s2);
extern SEXP R_g_flags_complete_type_info(SEXP s1, SEXP s2);
extern SEXP R_g_flags_get_first_value(SEXP s1, SEXP s2);
extern SEXP R_g_flags_get_value_by_name(SEXP s1, SEXP s2);
extern SEXP R_g_flags_get_value_by_nick(SEXP s1, SEXP s2);
extern SEXP R_g_flags_register_static(SEXP s1, SEXP s2);
extern SEXP R_g_flags_to_string(SEXP s1, SEXP s2);
extern SEXP R_g_gtype_get_type(void);
extern SEXP R_g_param_spec_boolean(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_param_spec_boxed(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_param_spec_char(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_param_spec_double(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_param_spec_enum(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_param_spec_flags(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_param_spec_float(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_param_spec_gtype(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_param_spec_int(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_param_spec_int64(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_param_spec_long(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_param_spec_object(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_param_spec_param(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_param_spec_pointer(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_param_spec_string(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_param_spec_uchar(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_param_spec_uint(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_param_spec_uint64(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_param_spec_ulong(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_param_spec_unichar(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_param_spec_variant(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_g_param_type_register_static(SEXP s1, SEXP s2);
extern SEXP R_g_param_value_convert(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_param_value_defaults(SEXP s1, SEXP s2);
extern SEXP R_g_param_value_set_default(SEXP s1, SEXP s2);
extern SEXP R_g_param_value_validate(SEXP s1, SEXP s2);
extern SEXP R_g_param_values_cmp(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_pointer_type_register_static(SEXP s1);
extern SEXP R_g_signal_accumulator_first_wins(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_signal_accumulator_true_handled(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_signal_add_emission_hook(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_signal_chain_from_overridden(SEXP s1, SEXP s2);
extern SEXP R_g_signal_connect_closure(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_signal_connect_closure_by_id(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_signal_emitv(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_signal_get_invocation_hint(SEXP s1);
extern SEXP R_g_signal_handler_block(SEXP s1, SEXP s2);
extern SEXP R_g_signal_handler_disconnect(SEXP s1, SEXP s2);
extern SEXP R_g_signal_handler_find(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_signal_handler_is_connected(SEXP s1, SEXP s2);
extern SEXP R_g_signal_handler_unblock(SEXP s1, SEXP s2);
extern SEXP R_g_signal_handlers_block_matched(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_signal_handlers_destroy(SEXP s1);
extern SEXP R_g_signal_handlers_disconnect_matched(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_signal_handlers_unblock_matched(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_g_signal_has_handler_pending(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_signal_list_ids(SEXP s1);
extern SEXP R_g_signal_lookup(SEXP s1, SEXP s2);
extern SEXP R_g_signal_name(SEXP s1);
extern SEXP R_g_signal_override_class_closure(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_signal_override_class_handler(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_signal_parse_name(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_signal_query(SEXP s1);
extern SEXP R_g_signal_remove_emission_hook(SEXP s1, SEXP s2);
extern SEXP R_g_signal_stop_emission(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_signal_stop_emission_by_name(SEXP s1, SEXP s2);
extern SEXP R_g_signal_type_cclosure_new(SEXP s1, SEXP s2);
extern SEXP R_g_strdup_value_contents(SEXP s1);
extern SEXP R_g_type_add_class_private(SEXP s1, SEXP s2);
extern SEXP R_g_type_add_instance_private(SEXP s1, SEXP s2);
extern SEXP R_g_type_add_interface_dynamic(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_type_add_interface_static(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_type_check_class_is_a(SEXP s1, SEXP s2);
extern SEXP R_g_type_check_instance(SEXP s1);
extern SEXP R_g_type_check_instance_is_a(SEXP s1, SEXP s2);
extern SEXP R_g_type_check_instance_is_fundamentally_a(SEXP s1, SEXP s2);
extern SEXP R_g_type_check_is_value_type(SEXP s1);
extern SEXP R_g_type_check_value(SEXP s1);
extern SEXP R_g_type_check_value_holds(SEXP s1, SEXP s2);
extern SEXP R_g_type_children(SEXP s1);
extern SEXP R_g_type_default_interface_peek(SEXP s1);
extern SEXP R_g_type_default_interface_ref(SEXP s1);
extern SEXP R_g_type_default_interface_unref(SEXP s1);
extern SEXP R_g_type_depth(SEXP s1);
extern SEXP R_g_type_ensure(SEXP s1);
extern SEXP R_g_type_free_instance(SEXP s1);
extern SEXP R_g_type_from_name(SEXP s1);
extern SEXP R_g_type_fundamental(SEXP s1);
extern SEXP R_g_type_fundamental_next(void);
extern SEXP R_g_type_get_instance_count(SEXP s1);
extern SEXP R_g_type_get_plugin(SEXP s1);
extern SEXP R_g_type_get_qdata(SEXP s1, SEXP s2);
extern SEXP R_g_type_get_type_registration_serial(void);
extern SEXP R_g_type_init(void);
extern SEXP R_g_type_init_with_debug_flags(SEXP s1);
extern SEXP R_g_type_interfaces(SEXP s1);
extern SEXP R_g_type_is_a(SEXP s1, SEXP s2);
extern SEXP R_g_type_name(SEXP s1);
extern SEXP R_g_type_name_from_class(SEXP s1);
extern SEXP R_g_type_name_from_instance(SEXP s1);
extern SEXP R_g_type_next_base(SEXP s1, SEXP s2);
extern SEXP R_g_type_parent(SEXP s1);
extern SEXP R_g_type_qname(SEXP s1);
extern SEXP R_g_type_query(SEXP s1);
extern SEXP R_g_type_register_dynamic(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_type_register_fundamental(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_g_type_register_static(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_g_type_set_qdata(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_g_type_test_flags(SEXP s1, SEXP s2);
extern SEXP R_gtk_at_context_create(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_at_context_get_accessible(SEXP s1);
extern SEXP R_gtk_at_context_get_accessible_role(SEXP s1);
extern SEXP R_gtk_about_dialog_new(void);
extern SEXP R_gtk_about_dialog_add_credit_section(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_about_dialog_get_artists(SEXP s1);
extern SEXP R_gtk_about_dialog_get_authors(SEXP s1);
extern SEXP R_gtk_about_dialog_get_comments(SEXP s1);
extern SEXP R_gtk_about_dialog_get_copyright(SEXP s1);
extern SEXP R_gtk_about_dialog_get_documenters(SEXP s1);
extern SEXP R_gtk_about_dialog_get_license(SEXP s1);
extern SEXP R_gtk_about_dialog_get_license_type(SEXP s1);
extern SEXP R_gtk_about_dialog_get_logo(SEXP s1);
extern SEXP R_gtk_about_dialog_get_logo_icon_name(SEXP s1);
extern SEXP R_gtk_about_dialog_get_program_name(SEXP s1);
extern SEXP R_gtk_about_dialog_get_system_information(SEXP s1);
extern SEXP R_gtk_about_dialog_get_translator_credits(SEXP s1);
extern SEXP R_gtk_about_dialog_get_version(SEXP s1);
extern SEXP R_gtk_about_dialog_get_website(SEXP s1);
extern SEXP R_gtk_about_dialog_get_website_label(SEXP s1);
extern SEXP R_gtk_about_dialog_get_wrap_license(SEXP s1);
extern SEXP R_gtk_about_dialog_set_artists(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_authors(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_comments(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_copyright(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_documenters(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_license(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_license_type(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_logo(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_logo_icon_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_program_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_system_information(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_translator_credits(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_version(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_website(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_website_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_about_dialog_set_wrap_license(SEXP s1, SEXP s2);
extern SEXP R_gtk_accessible_get_accessible_parent(SEXP s1);
extern SEXP R_gtk_accessible_get_accessible_role(SEXP s1);
extern SEXP R_gtk_accessible_get_at_context(SEXP s1);
extern SEXP R_gtk_accessible_get_bounds(SEXP s1);
extern SEXP R_gtk_accessible_get_first_accessible_child(SEXP s1);
extern SEXP R_gtk_accessible_get_next_accessible_sibling(SEXP s1);
extern SEXP R_gtk_accessible_get_platform_state(SEXP s1, SEXP s2);
extern SEXP R_gtk_accessible_reset_property(SEXP s1, SEXP s2);
extern SEXP R_gtk_accessible_reset_relation(SEXP s1, SEXP s2);
extern SEXP R_gtk_accessible_reset_state(SEXP s1, SEXP s2);
extern SEXP R_gtk_accessible_set_accessible_parent(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_accessible_update_next_accessible_sibling(SEXP s1, SEXP s2);
extern SEXP R_gtk_accessible_update_property_value(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_accessible_update_relation_value(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_accessible_update_state_value(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_accessible_property_init_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_accessible_relation_init_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_accessible_state_init_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_action_bar_new(void);
extern SEXP R_gtk_action_bar_get_center_widget(SEXP s1);
extern SEXP R_gtk_action_bar_get_revealed(SEXP s1);
extern SEXP R_gtk_action_bar_pack_end(SEXP s1, SEXP s2);
extern SEXP R_gtk_action_bar_pack_start(SEXP s1, SEXP s2);
extern SEXP R_gtk_action_bar_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_action_bar_set_center_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_action_bar_set_revealed(SEXP s1, SEXP s2);
extern SEXP R_gtk_actionable_get_action_name(SEXP s1);
extern SEXP R_gtk_actionable_get_action_target_value(SEXP s1);
extern SEXP R_gtk_actionable_set_action_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_actionable_set_action_target_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_actionable_set_detailed_action_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_activate_action_get(void);
extern SEXP R_gtk_adjustment_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_adjustment_clamp_page(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_adjustment_configure(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gtk_adjustment_get_lower(SEXP s1);
extern SEXP R_gtk_adjustment_get_minimum_increment(SEXP s1);
extern SEXP R_gtk_adjustment_get_page_increment(SEXP s1);
extern SEXP R_gtk_adjustment_get_page_size(SEXP s1);
extern SEXP R_gtk_adjustment_get_step_increment(SEXP s1);
extern SEXP R_gtk_adjustment_get_upper(SEXP s1);
extern SEXP R_gtk_adjustment_get_value(SEXP s1);
extern SEXP R_gtk_adjustment_set_lower(SEXP s1, SEXP s2);
extern SEXP R_gtk_adjustment_set_page_increment(SEXP s1, SEXP s2);
extern SEXP R_gtk_adjustment_set_page_size(SEXP s1, SEXP s2);
extern SEXP R_gtk_adjustment_set_step_increment(SEXP s1, SEXP s2);
extern SEXP R_gtk_adjustment_set_upper(SEXP s1, SEXP s2);
extern SEXP R_gtk_adjustment_set_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_alert_dialog_choose(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_alert_dialog_choose_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_alert_dialog_get_buttons(SEXP s1);
extern SEXP R_gtk_alert_dialog_get_cancel_button(SEXP s1);
extern SEXP R_gtk_alert_dialog_get_default_button(SEXP s1);
extern SEXP R_gtk_alert_dialog_get_detail(SEXP s1);
extern SEXP R_gtk_alert_dialog_get_message(SEXP s1);
extern SEXP R_gtk_alert_dialog_get_modal(SEXP s1);
extern SEXP R_gtk_alert_dialog_set_buttons(SEXP s1, SEXP s2);
extern SEXP R_gtk_alert_dialog_set_cancel_button(SEXP s1, SEXP s2);
extern SEXP R_gtk_alert_dialog_set_default_button(SEXP s1, SEXP s2);
extern SEXP R_gtk_alert_dialog_set_detail(SEXP s1, SEXP s2);
extern SEXP R_gtk_alert_dialog_set_message(SEXP s1, SEXP s2);
extern SEXP R_gtk_alert_dialog_set_modal(SEXP s1, SEXP s2);
extern SEXP R_gtk_alert_dialog_show(SEXP s1, SEXP s2);
extern SEXP R_gtk_alternative_trigger_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_alternative_trigger_get_first(SEXP s1);
extern SEXP R_gtk_alternative_trigger_get_second(SEXP s1);
extern SEXP R_gtk_any_filter_new(void);
extern SEXP R_gtk_app_chooser_get_app_info(SEXP s1);
extern SEXP R_gtk_app_chooser_get_content_type(SEXP s1);
extern SEXP R_gtk_app_chooser_refresh(SEXP s1);
extern SEXP R_gtk_app_chooser_button_new(SEXP s1);
extern SEXP R_gtk_app_chooser_button_append_custom_item(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_app_chooser_button_append_separator(SEXP s1);
extern SEXP R_gtk_app_chooser_button_get_heading(SEXP s1);
extern SEXP R_gtk_app_chooser_button_get_modal(SEXP s1);
extern SEXP R_gtk_app_chooser_button_get_show_default_item(SEXP s1);
extern SEXP R_gtk_app_chooser_button_get_show_dialog_item(SEXP s1);
extern SEXP R_gtk_app_chooser_button_set_active_custom_item(SEXP s1, SEXP s2);
extern SEXP R_gtk_app_chooser_button_set_heading(SEXP s1, SEXP s2);
extern SEXP R_gtk_app_chooser_button_set_modal(SEXP s1, SEXP s2);
extern SEXP R_gtk_app_chooser_button_set_show_default_item(SEXP s1, SEXP s2);
extern SEXP R_gtk_app_chooser_button_set_show_dialog_item(SEXP s1, SEXP s2);
extern SEXP R_gtk_app_chooser_dialog_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_app_chooser_dialog_new_for_content_type(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_app_chooser_dialog_get_heading(SEXP s1);
extern SEXP R_gtk_app_chooser_dialog_get_widget(SEXP s1);
extern SEXP R_gtk_app_chooser_dialog_set_heading(SEXP s1, SEXP s2);
extern SEXP R_gtk_app_chooser_widget_new(SEXP s1);
extern SEXP R_gtk_app_chooser_widget_get_default_text(SEXP s1);
extern SEXP R_gtk_app_chooser_widget_get_show_all(SEXP s1);
extern SEXP R_gtk_app_chooser_widget_get_show_default(SEXP s1);
extern SEXP R_gtk_app_chooser_widget_get_show_fallback(SEXP s1);
extern SEXP R_gtk_app_chooser_widget_get_show_other(SEXP s1);
extern SEXP R_gtk_app_chooser_widget_get_show_recommended(SEXP s1);
extern SEXP R_gtk_app_chooser_widget_set_default_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_app_chooser_widget_set_show_all(SEXP s1, SEXP s2);
extern SEXP R_gtk_app_chooser_widget_set_show_default(SEXP s1, SEXP s2);
extern SEXP R_gtk_app_chooser_widget_set_show_fallback(SEXP s1, SEXP s2);
extern SEXP R_gtk_app_chooser_widget_set_show_other(SEXP s1, SEXP s2);
extern SEXP R_gtk_app_chooser_widget_set_show_recommended(SEXP s1, SEXP s2);
extern SEXP R_gtk_application_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_application_add_window(SEXP s1, SEXP s2);
extern SEXP R_gtk_application_get_accels_for_action(SEXP s1, SEXP s2);
extern SEXP R_gtk_application_get_actions_for_accel(SEXP s1, SEXP s2);
extern SEXP R_gtk_application_get_active_window(SEXP s1);
extern SEXP R_gtk_application_get_menu_by_id(SEXP s1, SEXP s2);
extern SEXP R_gtk_application_get_menubar(SEXP s1);
extern SEXP R_gtk_application_get_window_by_id(SEXP s1, SEXP s2);
extern SEXP R_gtk_application_get_windows(SEXP s1);
extern SEXP R_gtk_application_inhibit(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_application_list_action_descriptions(SEXP s1);
extern SEXP R_gtk_application_remove_window(SEXP s1, SEXP s2);
extern SEXP R_gtk_application_set_accels_for_action(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_application_set_menubar(SEXP s1, SEXP s2);
extern SEXP R_gtk_application_uninhibit(SEXP s1, SEXP s2);
extern SEXP R_gtk_application_window_new(SEXP s1);
extern SEXP R_gtk_application_window_get_help_overlay(SEXP s1);
extern SEXP R_gtk_application_window_get_id(SEXP s1);
extern SEXP R_gtk_application_window_get_show_menubar(SEXP s1);
extern SEXP R_gtk_application_window_set_help_overlay(SEXP s1, SEXP s2);
extern SEXP R_gtk_application_window_set_show_menubar(SEXP s1, SEXP s2);
extern SEXP R_gtk_aspect_frame_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_aspect_frame_get_child(SEXP s1);
extern SEXP R_gtk_aspect_frame_get_obey_child(SEXP s1);
extern SEXP R_gtk_aspect_frame_get_ratio(SEXP s1);
extern SEXP R_gtk_aspect_frame_get_xalign(SEXP s1);
extern SEXP R_gtk_aspect_frame_get_yalign(SEXP s1);
extern SEXP R_gtk_aspect_frame_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_aspect_frame_set_obey_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_aspect_frame_set_ratio(SEXP s1, SEXP s2);
extern SEXP R_gtk_aspect_frame_set_xalign(SEXP s1, SEXP s2);
extern SEXP R_gtk_aspect_frame_set_yalign(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_new(void);
extern SEXP R_gtk_assistant_add_action_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_append_page(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_commit(SEXP s1);
extern SEXP R_gtk_assistant_get_current_page(SEXP s1);
extern SEXP R_gtk_assistant_get_n_pages(SEXP s1);
extern SEXP R_gtk_assistant_get_nth_page(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_get_page(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_get_page_complete(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_get_page_title(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_get_page_type(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_get_pages(SEXP s1);
extern SEXP R_gtk_assistant_insert_page(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_assistant_next_page(SEXP s1);
extern SEXP R_gtk_assistant_prepend_page(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_previous_page(SEXP s1);
extern SEXP R_gtk_assistant_remove_action_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_remove_page(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_set_current_page(SEXP s1, SEXP s2);
extern SEXP R_gtk_assistant_set_forward_page_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_assistant_set_page_complete(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_assistant_set_page_title(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_assistant_set_page_type(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_assistant_update_buttons_state(SEXP s1);
extern SEXP R_gtk_assistant_page_get_child(SEXP s1);
extern SEXP R_gtk_bin_layout_new(void);
extern SEXP R_gtk_bitset_new_empty(void);
extern SEXP R_gtk_bitset_new_range(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_add(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_add_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_bitset_add_range_closed(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_bitset_add_rectangle(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_bitset_contains(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_copy(SEXP s1);
extern SEXP R_gtk_bitset_difference(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_equals(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_get_maximum(SEXP s1);
extern SEXP R_gtk_bitset_get_minimum(SEXP s1);
extern SEXP R_gtk_bitset_get_nth(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_get_size(SEXP s1);
extern SEXP R_gtk_bitset_get_size_in_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_bitset_intersect(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_is_empty(SEXP s1);
extern SEXP R_gtk_bitset_ref(SEXP s1);
extern SEXP R_gtk_bitset_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_remove_all(SEXP s1);
extern SEXP R_gtk_bitset_remove_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_bitset_remove_range_closed(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_bitset_remove_rectangle(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_bitset_shift_left(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_shift_right(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_splice(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_bitset_subtract(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_union(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_unref(SEXP s1);
extern SEXP R_gtk_bitset_iter_get_value(SEXP s1);
extern SEXP R_gtk_bitset_iter_is_valid(SEXP s1);
extern SEXP R_gtk_bitset_iter_next(SEXP s1);
extern SEXP R_gtk_bitset_iter_previous(SEXP s1);
extern SEXP R_gtk_bitset_iter_init_at(SEXP s1, SEXP s2);
extern SEXP R_gtk_bitset_iter_init_first(SEXP s1);
extern SEXP R_gtk_bitset_iter_init_last(SEXP s1);
extern SEXP R_gtk_bookmark_list_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_bookmark_list_get_attributes(SEXP s1);
extern SEXP R_gtk_bookmark_list_get_filename(SEXP s1);
extern SEXP R_gtk_bookmark_list_get_io_priority(SEXP s1);
extern SEXP R_gtk_bookmark_list_is_loading(SEXP s1);
extern SEXP R_gtk_bookmark_list_set_attributes(SEXP s1, SEXP s2);
extern SEXP R_gtk_bookmark_list_set_io_priority(SEXP s1, SEXP s2);
extern SEXP R_gtk_bool_filter_new(SEXP s1);
extern SEXP R_gtk_bool_filter_get_expression(SEXP s1);
extern SEXP R_gtk_bool_filter_get_invert(SEXP s1);
extern SEXP R_gtk_bool_filter_set_expression(SEXP s1, SEXP s2);
extern SEXP R_gtk_bool_filter_set_invert(SEXP s1, SEXP s2);
extern SEXP R_gtk_border_new(void);
extern SEXP R_gtk_border_copy(SEXP s1);
extern SEXP R_gtk_border_free(SEXP s1);
extern SEXP R_gtk_box_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_box_append(SEXP s1, SEXP s2);
extern SEXP R_gtk_box_get_baseline_child(SEXP s1);
extern SEXP R_gtk_box_get_baseline_position(SEXP s1);
extern SEXP R_gtk_box_get_homogeneous(SEXP s1);
extern SEXP R_gtk_box_get_spacing(SEXP s1);
extern SEXP R_gtk_box_insert_child_after(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_box_prepend(SEXP s1, SEXP s2);
extern SEXP R_gtk_box_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_box_reorder_child_after(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_box_set_baseline_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_box_set_baseline_position(SEXP s1, SEXP s2);
extern SEXP R_gtk_box_set_homogeneous(SEXP s1, SEXP s2);
extern SEXP R_gtk_box_set_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_box_layout_new(SEXP s1);
extern SEXP R_gtk_box_layout_get_baseline_child(SEXP s1);
extern SEXP R_gtk_box_layout_get_baseline_position(SEXP s1);
extern SEXP R_gtk_box_layout_get_homogeneous(SEXP s1);
extern SEXP R_gtk_box_layout_get_spacing(SEXP s1);
extern SEXP R_gtk_box_layout_set_baseline_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_box_layout_set_baseline_position(SEXP s1, SEXP s2);
extern SEXP R_gtk_box_layout_set_homogeneous(SEXP s1, SEXP s2);
extern SEXP R_gtk_box_layout_set_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_buildable_get_buildable_id(SEXP s1);
extern SEXP R_gtk_buildable_parse_context_get_element(SEXP s1);
extern SEXP R_gtk_buildable_parse_context_get_element_stack(SEXP s1);
extern SEXP R_gtk_buildable_parse_context_get_position(SEXP s1);
extern SEXP R_gtk_buildable_parse_context_pop(SEXP s1);
extern SEXP R_gtk_buildable_parse_context_push(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_builder_new(void);
extern SEXP R_gtk_builder_new_from_file(SEXP s1);
extern SEXP R_gtk_builder_new_from_resource(SEXP s1);
extern SEXP R_gtk_builder_new_from_string(SEXP s1, SEXP s2);
extern SEXP R_gtk_builder_add_from_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_builder_add_from_resource(SEXP s1, SEXP s2);
extern SEXP R_gtk_builder_add_from_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_builder_add_objects_from_file(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_builder_add_objects_from_resource(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_builder_add_objects_from_string(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_builder_create_closure(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_builder_expose_object(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_builder_extend_with_template(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_builder_get_current_object(SEXP s1);
extern SEXP R_gtk_builder_get_object(SEXP s1, SEXP s2);
extern SEXP R_gtk_builder_get_objects(SEXP s1);
extern SEXP R_gtk_builder_get_scope(SEXP s1);
extern SEXP R_gtk_builder_get_translation_domain(SEXP s1);
extern SEXP R_gtk_builder_get_type_from_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_builder_set_current_object(SEXP s1, SEXP s2);
extern SEXP R_gtk_builder_set_scope(SEXP s1, SEXP s2);
extern SEXP R_gtk_builder_set_translation_domain(SEXP s1, SEXP s2);
extern SEXP R_gtk_builder_value_from_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_builder_value_from_string_type(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_builder_cscope_new(void);
extern SEXP R_gtk_builder_cscope_add_callback_symbol(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_builder_error_quark(void);
extern SEXP R_gtk_builder_list_item_factory_new_from_bytes(SEXP s1, SEXP s2);
extern SEXP R_gtk_builder_list_item_factory_new_from_resource(SEXP s1, SEXP s2);
extern SEXP R_gtk_builder_list_item_factory_get_bytes(SEXP s1);
extern SEXP R_gtk_builder_list_item_factory_get_resource(SEXP s1);
extern SEXP R_gtk_builder_list_item_factory_get_scope(SEXP s1);
extern SEXP R_gtk_button_new(void);
extern SEXP R_gtk_button_new_from_icon_name(SEXP s1);
extern SEXP R_gtk_button_new_with_label(SEXP s1);
extern SEXP R_gtk_button_new_with_mnemonic(SEXP s1);
extern SEXP R_gtk_button_get_can_shrink(SEXP s1);
extern SEXP R_gtk_button_get_child(SEXP s1);
extern SEXP R_gtk_button_get_has_frame(SEXP s1);
extern SEXP R_gtk_button_get_icon_name(SEXP s1);
extern SEXP R_gtk_button_get_label(SEXP s1);
extern SEXP R_gtk_button_get_use_underline(SEXP s1);
extern SEXP R_gtk_button_set_can_shrink(SEXP s1, SEXP s2);
extern SEXP R_gtk_button_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_button_set_has_frame(SEXP s1, SEXP s2);
extern SEXP R_gtk_button_set_icon_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_button_set_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_button_set_use_underline(SEXP s1, SEXP s2);
extern SEXP R_gtk_cclosure_expression_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gtk_calendar_new(void);
extern SEXP R_gtk_calendar_clear_marks(SEXP s1);
extern SEXP R_gtk_calendar_get_date(SEXP s1);
extern SEXP R_gtk_calendar_get_day_is_marked(SEXP s1, SEXP s2);
extern SEXP R_gtk_calendar_get_show_day_names(SEXP s1);
extern SEXP R_gtk_calendar_get_show_heading(SEXP s1);
extern SEXP R_gtk_calendar_get_show_week_numbers(SEXP s1);
extern SEXP R_gtk_calendar_mark_day(SEXP s1, SEXP s2);
extern SEXP R_gtk_calendar_select_day(SEXP s1, SEXP s2);
extern SEXP R_gtk_calendar_set_show_day_names(SEXP s1, SEXP s2);
extern SEXP R_gtk_calendar_set_show_heading(SEXP s1, SEXP s2);
extern SEXP R_gtk_calendar_set_show_week_numbers(SEXP s1, SEXP s2);
extern SEXP R_gtk_calendar_unmark_day(SEXP s1, SEXP s2);
extern SEXP R_gtk_callback_action_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_activate(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_cell_area_activate_cell(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_cell_area_add(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_add_focus_sibling(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_apply_attributes(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_cell_area_attribute_connect(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_cell_area_attribute_disconnect(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_attribute_get_column(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_cell_get_property(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_cell_area_cell_set_property(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_cell_area_copy_context(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_create_context(SEXP s1);
extern SEXP R_gtk_cell_area_event(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_cell_area_focus(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_foreach_alloc(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gtk_cell_area_get_cell_allocation(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_cell_area_get_cell_at_position(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_cell_area_get_current_path_string(SEXP s1);
extern SEXP R_gtk_cell_area_get_edit_widget(SEXP s1);
extern SEXP R_gtk_cell_area_get_edited_cell(SEXP s1);
extern SEXP R_gtk_cell_area_get_focus_cell(SEXP s1);
extern SEXP R_gtk_cell_area_get_focus_from_sibling(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_get_focus_siblings(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_get_preferred_height(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_get_preferred_height_for_width(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_cell_area_get_preferred_width(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_get_preferred_width_for_height(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_cell_area_get_request_mode(SEXP s1);
extern SEXP R_gtk_cell_area_has_renderer(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_inner_cell_area(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_is_activatable(SEXP s1);
extern SEXP R_gtk_cell_area_is_focus_sibling(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_remove_focus_sibling(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_request_renderer(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_cell_area_set_focus_cell(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_snapshot(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_gtk_cell_area_stop_editing(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_box_new(void);
extern SEXP R_gtk_cell_area_box_get_spacing(SEXP s1);
extern SEXP R_gtk_cell_area_box_pack_end(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_cell_area_box_pack_start(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_cell_area_box_set_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_class_find_cell_property(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_class_install_cell_property(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_class_list_cell_properties(SEXP s1);
extern SEXP R_gtk_cell_area_context_allocate(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_context_get_allocation(SEXP s1);
extern SEXP R_gtk_cell_area_context_get_area(SEXP s1);
extern SEXP R_gtk_cell_area_context_get_preferred_height(SEXP s1);
extern SEXP R_gtk_cell_area_context_get_preferred_height_for_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_context_get_preferred_width(SEXP s1);
extern SEXP R_gtk_cell_area_context_get_preferred_width_for_height(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_area_context_push_preferred_height(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_context_push_preferred_width(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_area_context_reset(SEXP s1);
extern SEXP R_gtk_cell_editable_editing_done(SEXP s1);
extern SEXP R_gtk_cell_editable_remove_widget(SEXP s1);
extern SEXP R_gtk_cell_editable_start_editing(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_layout_add_attribute(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_cell_layout_clear(SEXP s1);
extern SEXP R_gtk_cell_layout_clear_attributes(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_layout_get_area(SEXP s1);
extern SEXP R_gtk_cell_layout_get_cells(SEXP s1);
extern SEXP R_gtk_cell_layout_pack_end(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_layout_pack_start(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_layout_reorder(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_layout_set_cell_data_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_cell_renderer_activate(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gtk_cell_renderer_get_aligned_area(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_cell_renderer_get_alignment(SEXP s1);
extern SEXP R_gtk_cell_renderer_get_fixed_size(SEXP s1);
extern SEXP R_gtk_cell_renderer_get_is_expanded(SEXP s1);
extern SEXP R_gtk_cell_renderer_get_is_expander(SEXP s1);
extern SEXP R_gtk_cell_renderer_get_padding(SEXP s1);
extern SEXP R_gtk_cell_renderer_get_preferred_height(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_renderer_get_preferred_height_for_width(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_renderer_get_preferred_size(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_renderer_get_preferred_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_renderer_get_preferred_width_for_height(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_renderer_get_request_mode(SEXP s1);
extern SEXP R_gtk_cell_renderer_get_sensitive(SEXP s1);
extern SEXP R_gtk_cell_renderer_get_state(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_renderer_get_visible(SEXP s1);
extern SEXP R_gtk_cell_renderer_is_activatable(SEXP s1);
extern SEXP R_gtk_cell_renderer_set_alignment(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_renderer_set_fixed_size(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_renderer_set_is_expanded(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_renderer_set_is_expander(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_renderer_set_padding(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_cell_renderer_set_sensitive(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_renderer_set_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_renderer_snapshot(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_cell_renderer_start_editing(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gtk_cell_renderer_stop_editing(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_renderer_accel_new(void);
extern SEXP R_gtk_cell_renderer_combo_new(void);
extern SEXP R_gtk_cell_renderer_pixbuf_new(void);
extern SEXP R_gtk_cell_renderer_progress_new(void);
extern SEXP R_gtk_cell_renderer_spin_new(void);
extern SEXP R_gtk_cell_renderer_spinner_new(void);
extern SEXP R_gtk_cell_renderer_text_new(void);
extern SEXP R_gtk_cell_renderer_text_set_fixed_height_from_font(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_renderer_toggle_new(void);
extern SEXP R_gtk_cell_renderer_toggle_get_activatable(SEXP s1);
extern SEXP R_gtk_cell_renderer_toggle_get_active(SEXP s1);
extern SEXP R_gtk_cell_renderer_toggle_get_radio(SEXP s1);
extern SEXP R_gtk_cell_renderer_toggle_set_activatable(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_renderer_toggle_set_active(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_renderer_toggle_set_radio(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_view_new(void);
extern SEXP R_gtk_cell_view_new_with_context(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_view_new_with_markup(SEXP s1);
extern SEXP R_gtk_cell_view_new_with_text(SEXP s1);
extern SEXP R_gtk_cell_view_new_with_texture(SEXP s1);
extern SEXP R_gtk_cell_view_get_displayed_row(SEXP s1);
extern SEXP R_gtk_cell_view_get_draw_sensitive(SEXP s1);
extern SEXP R_gtk_cell_view_get_fit_model(SEXP s1);
extern SEXP R_gtk_cell_view_get_model(SEXP s1);
extern SEXP R_gtk_cell_view_set_displayed_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_view_set_draw_sensitive(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_view_set_fit_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_cell_view_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_center_box_new(void);
extern SEXP R_gtk_center_box_get_baseline_position(SEXP s1);
extern SEXP R_gtk_center_box_get_center_widget(SEXP s1);
extern SEXP R_gtk_center_box_get_end_widget(SEXP s1);
extern SEXP R_gtk_center_box_get_shrink_center_last(SEXP s1);
extern SEXP R_gtk_center_box_get_start_widget(SEXP s1);
extern SEXP R_gtk_center_box_set_baseline_position(SEXP s1, SEXP s2);
extern SEXP R_gtk_center_box_set_center_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_center_box_set_end_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_center_box_set_shrink_center_last(SEXP s1, SEXP s2);
extern SEXP R_gtk_center_box_set_start_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_center_layout_new(void);
extern SEXP R_gtk_center_layout_get_baseline_position(SEXP s1);
extern SEXP R_gtk_center_layout_get_center_widget(SEXP s1);
extern SEXP R_gtk_center_layout_get_end_widget(SEXP s1);
extern SEXP R_gtk_center_layout_get_orientation(SEXP s1);
extern SEXP R_gtk_center_layout_get_shrink_center_last(SEXP s1);
extern SEXP R_gtk_center_layout_get_start_widget(SEXP s1);
extern SEXP R_gtk_center_layout_set_baseline_position(SEXP s1, SEXP s2);
extern SEXP R_gtk_center_layout_set_center_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_center_layout_set_end_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_center_layout_set_orientation(SEXP s1, SEXP s2);
extern SEXP R_gtk_center_layout_set_shrink_center_last(SEXP s1, SEXP s2);
extern SEXP R_gtk_center_layout_set_start_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_check_button_new(void);
extern SEXP R_gtk_check_button_new_with_label(SEXP s1);
extern SEXP R_gtk_check_button_new_with_mnemonic(SEXP s1);
extern SEXP R_gtk_check_button_get_active(SEXP s1);
extern SEXP R_gtk_check_button_get_child(SEXP s1);
extern SEXP R_gtk_check_button_get_inconsistent(SEXP s1);
extern SEXP R_gtk_check_button_get_label(SEXP s1);
extern SEXP R_gtk_check_button_get_use_underline(SEXP s1);
extern SEXP R_gtk_check_button_set_active(SEXP s1, SEXP s2);
extern SEXP R_gtk_check_button_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_check_button_set_group(SEXP s1, SEXP s2);
extern SEXP R_gtk_check_button_set_inconsistent(SEXP s1, SEXP s2);
extern SEXP R_gtk_check_button_set_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_check_button_set_use_underline(SEXP s1, SEXP s2);
extern SEXP R_gtk_closure_expression_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_color_button_new(void);
extern SEXP R_gtk_color_button_new_with_rgba(SEXP s1);
extern SEXP R_gtk_color_button_get_modal(SEXP s1);
extern SEXP R_gtk_color_button_get_title(SEXP s1);
extern SEXP R_gtk_color_button_set_modal(SEXP s1, SEXP s2);
extern SEXP R_gtk_color_button_set_title(SEXP s1, SEXP s2);
extern SEXP R_gtk_color_chooser_add_palette(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_color_chooser_get_rgba(SEXP s1);
extern SEXP R_gtk_color_chooser_get_use_alpha(SEXP s1);
extern SEXP R_gtk_color_chooser_set_rgba(SEXP s1, SEXP s2);
extern SEXP R_gtk_color_chooser_set_use_alpha(SEXP s1, SEXP s2);
extern SEXP R_gtk_color_chooser_dialog_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_color_chooser_widget_new(void);
extern SEXP R_gtk_color_dialog_new(void);
extern SEXP R_gtk_color_dialog_choose_rgba(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_color_dialog_choose_rgba_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_color_dialog_get_modal(SEXP s1);
extern SEXP R_gtk_color_dialog_get_title(SEXP s1);
extern SEXP R_gtk_color_dialog_get_with_alpha(SEXP s1);
extern SEXP R_gtk_color_dialog_set_modal(SEXP s1, SEXP s2);
extern SEXP R_gtk_color_dialog_set_title(SEXP s1, SEXP s2);
extern SEXP R_gtk_color_dialog_set_with_alpha(SEXP s1, SEXP s2);
extern SEXP R_gtk_color_dialog_button_new(SEXP s1);
extern SEXP R_gtk_color_dialog_button_get_dialog(SEXP s1);
extern SEXP R_gtk_color_dialog_button_get_rgba(SEXP s1);
extern SEXP R_gtk_color_dialog_button_set_dialog(SEXP s1, SEXP s2);
extern SEXP R_gtk_color_dialog_button_set_rgba(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_new(SEXP s1);
extern SEXP R_gtk_column_view_append_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_get_columns(SEXP s1);
extern SEXP R_gtk_column_view_get_enable_rubberband(SEXP s1);
extern SEXP R_gtk_column_view_get_header_factory(SEXP s1);
extern SEXP R_gtk_column_view_get_model(SEXP s1);
extern SEXP R_gtk_column_view_get_reorderable(SEXP s1);
extern SEXP R_gtk_column_view_get_row_factory(SEXP s1);
extern SEXP R_gtk_column_view_get_show_column_separators(SEXP s1);
extern SEXP R_gtk_column_view_get_show_row_separators(SEXP s1);
extern SEXP R_gtk_column_view_get_single_click_activate(SEXP s1);
extern SEXP R_gtk_column_view_get_sorter(SEXP s1);
extern SEXP R_gtk_column_view_get_tab_behavior(SEXP s1);
extern SEXP R_gtk_column_view_insert_column(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_column_view_remove_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_scroll_to(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_column_view_set_enable_rubberband(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_set_header_factory(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_set_reorderable(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_set_row_factory(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_set_show_column_separators(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_set_show_row_separators(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_set_single_click_activate(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_set_tab_behavior(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_sort_by_column(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_column_view_cell_get_child(SEXP s1);
extern SEXP R_gtk_column_view_cell_get_focusable(SEXP s1);
extern SEXP R_gtk_column_view_cell_get_item(SEXP s1);
extern SEXP R_gtk_column_view_cell_get_position(SEXP s1);
extern SEXP R_gtk_column_view_cell_get_selected(SEXP s1);
extern SEXP R_gtk_column_view_cell_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_cell_set_focusable(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_column_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_column_get_column_view(SEXP s1);
extern SEXP R_gtk_column_view_column_get_expand(SEXP s1);
extern SEXP R_gtk_column_view_column_get_factory(SEXP s1);
extern SEXP R_gtk_column_view_column_get_fixed_width(SEXP s1);
extern SEXP R_gtk_column_view_column_get_header_menu(SEXP s1);
extern SEXP R_gtk_column_view_column_get_id(SEXP s1);
extern SEXP R_gtk_column_view_column_get_resizable(SEXP s1);
extern SEXP R_gtk_column_view_column_get_sorter(SEXP s1);
extern SEXP R_gtk_column_view_column_get_title(SEXP s1);
extern SEXP R_gtk_column_view_column_get_visible(SEXP s1);
extern SEXP R_gtk_column_view_column_set_expand(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_column_set_factory(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_column_set_fixed_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_column_set_header_menu(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_column_set_id(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_column_set_resizable(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_column_set_sorter(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_column_set_title(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_column_set_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_row_get_accessible_description(SEXP s1);
extern SEXP R_gtk_column_view_row_get_accessible_label(SEXP s1);
extern SEXP R_gtk_column_view_row_get_activatable(SEXP s1);
extern SEXP R_gtk_column_view_row_get_focusable(SEXP s1);
extern SEXP R_gtk_column_view_row_get_item(SEXP s1);
extern SEXP R_gtk_column_view_row_get_position(SEXP s1);
extern SEXP R_gtk_column_view_row_get_selectable(SEXP s1);
extern SEXP R_gtk_column_view_row_get_selected(SEXP s1);
extern SEXP R_gtk_column_view_row_set_accessible_description(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_row_set_accessible_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_row_set_activatable(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_row_set_focusable(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_row_set_selectable(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_sorter_get_n_sort_columns(SEXP s1);
extern SEXP R_gtk_column_view_sorter_get_nth_sort_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_column_view_sorter_get_primary_sort_column(SEXP s1);
extern SEXP R_gtk_column_view_sorter_get_primary_sort_order(SEXP s1);
extern SEXP R_gtk_combo_box_new(void);
extern SEXP R_gtk_combo_box_new_with_entry(void);
extern SEXP R_gtk_combo_box_new_with_model(SEXP s1);
extern SEXP R_gtk_combo_box_new_with_model_and_entry(SEXP s1);
extern SEXP R_gtk_combo_box_get_active(SEXP s1);
extern SEXP R_gtk_combo_box_get_active_id(SEXP s1);
extern SEXP R_gtk_combo_box_get_active_iter(SEXP s1);
extern SEXP R_gtk_combo_box_get_button_sensitivity(SEXP s1);
extern SEXP R_gtk_combo_box_get_child(SEXP s1);
extern SEXP R_gtk_combo_box_get_entry_text_column(SEXP s1);
extern SEXP R_gtk_combo_box_get_has_entry(SEXP s1);
extern SEXP R_gtk_combo_box_get_id_column(SEXP s1);
extern SEXP R_gtk_combo_box_get_model(SEXP s1);
extern SEXP R_gtk_combo_box_get_popup_fixed_width(SEXP s1);
extern SEXP R_gtk_combo_box_popdown(SEXP s1);
extern SEXP R_gtk_combo_box_popup(SEXP s1);
extern SEXP R_gtk_combo_box_popup_for_device(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_set_active(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_set_active_id(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_set_active_iter(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_set_button_sensitivity(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_set_entry_text_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_set_id_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_set_popup_fixed_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_set_row_separator_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_combo_box_text_new(void);
extern SEXP R_gtk_combo_box_text_new_with_entry(void);
extern SEXP R_gtk_combo_box_text_append(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_combo_box_text_append_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_text_get_active_text(SEXP s1);
extern SEXP R_gtk_combo_box_text_insert(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_combo_box_text_insert_text(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_combo_box_text_prepend(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_combo_box_text_prepend_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_text_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_combo_box_text_remove_all(SEXP s1);
extern SEXP R_gtk_constant_expression_new_for_value(SEXP s1);
extern SEXP R_gtk_constant_expression_get_value(SEXP s1);
extern SEXP R_gtk_constraint_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_gtk_constraint_new_constant(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_constraint_get_constant(SEXP s1);
extern SEXP R_gtk_constraint_get_multiplier(SEXP s1);
extern SEXP R_gtk_constraint_get_relation(SEXP s1);
extern SEXP R_gtk_constraint_get_source(SEXP s1);
extern SEXP R_gtk_constraint_get_source_attribute(SEXP s1);
extern SEXP R_gtk_constraint_get_strength(SEXP s1);
extern SEXP R_gtk_constraint_get_target(SEXP s1);
extern SEXP R_gtk_constraint_get_target_attribute(SEXP s1);
extern SEXP R_gtk_constraint_is_attached(SEXP s1);
extern SEXP R_gtk_constraint_is_constant(SEXP s1);
extern SEXP R_gtk_constraint_is_required(SEXP s1);
extern SEXP R_gtk_constraint_guide_new(void);
extern SEXP R_gtk_constraint_guide_get_max_size(SEXP s1);
extern SEXP R_gtk_constraint_guide_get_min_size(SEXP s1);
extern SEXP R_gtk_constraint_guide_get_name(SEXP s1);
extern SEXP R_gtk_constraint_guide_get_nat_size(SEXP s1);
extern SEXP R_gtk_constraint_guide_get_strength(SEXP s1);
extern SEXP R_gtk_constraint_guide_set_max_size(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_constraint_guide_set_min_size(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_constraint_guide_set_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_constraint_guide_set_nat_size(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_constraint_guide_set_strength(SEXP s1, SEXP s2);
extern SEXP R_gtk_constraint_layout_new(void);
extern SEXP R_gtk_constraint_layout_add_constraint(SEXP s1, SEXP s2);
extern SEXP R_gtk_constraint_layout_add_constraints_from_descriptionv(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_constraint_layout_add_guide(SEXP s1, SEXP s2);
extern SEXP R_gtk_constraint_layout_observe_constraints(SEXP s1);
extern SEXP R_gtk_constraint_layout_observe_guides(SEXP s1);
extern SEXP R_gtk_constraint_layout_remove_all_constraints(SEXP s1);
extern SEXP R_gtk_constraint_layout_remove_constraint(SEXP s1, SEXP s2);
extern SEXP R_gtk_constraint_layout_remove_guide(SEXP s1, SEXP s2);
extern SEXP R_gtk_constraint_vfl_parser_error_quark(void);
extern SEXP R_gtk_css_provider_new(void);
extern SEXP R_gtk_css_provider_load_from_bytes(SEXP s1, SEXP s2);
extern SEXP R_gtk_css_provider_load_from_data(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_css_provider_load_from_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_css_provider_load_from_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_css_provider_load_from_resource(SEXP s1, SEXP s2);
extern SEXP R_gtk_css_provider_load_from_string(SEXP s1, SEXP s2);
extern SEXP R_gtk_css_provider_load_named(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_css_provider_to_string(SEXP s1);
extern SEXP R_gtk_css_section_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_css_section_get_end_location(SEXP s1);
extern SEXP R_gtk_css_section_get_file(SEXP s1);
extern SEXP R_gtk_css_section_get_parent(SEXP s1);
extern SEXP R_gtk_css_section_get_start_location(SEXP s1);
extern SEXP R_gtk_css_section_print(SEXP s1, SEXP s2);
extern SEXP R_gtk_css_section_ref(SEXP s1);
extern SEXP R_gtk_css_section_to_string(SEXP s1);
extern SEXP R_gtk_css_section_unref(SEXP s1);
extern SEXP R_gtk_custom_filter_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_custom_filter_set_filter_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_custom_layout_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_custom_sorter_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_custom_sorter_set_sort_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_dialog_new(void);
extern SEXP R_gtk_dialog_add_action_widget(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_dialog_add_button(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_dialog_get_content_area(SEXP s1);
extern SEXP R_gtk_dialog_get_header_bar(SEXP s1);
extern SEXP R_gtk_dialog_get_response_for_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_dialog_get_widget_for_response(SEXP s1, SEXP s2);
extern SEXP R_gtk_dialog_response(SEXP s1, SEXP s2);
extern SEXP R_gtk_dialog_set_default_response(SEXP s1, SEXP s2);
extern SEXP R_gtk_dialog_set_response_sensitive(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_dialog_error_quark(void);
extern SEXP R_gtk_directory_list_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_directory_list_get_attributes(SEXP s1);
extern SEXP R_gtk_directory_list_get_error(SEXP s1);
extern SEXP R_gtk_directory_list_get_file(SEXP s1);
extern SEXP R_gtk_directory_list_get_io_priority(SEXP s1);
extern SEXP R_gtk_directory_list_get_monitored(SEXP s1);
extern SEXP R_gtk_directory_list_is_loading(SEXP s1);
extern SEXP R_gtk_directory_list_set_attributes(SEXP s1, SEXP s2);
extern SEXP R_gtk_directory_list_set_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_directory_list_set_io_priority(SEXP s1, SEXP s2);
extern SEXP R_gtk_directory_list_set_monitored(SEXP s1, SEXP s2);
extern SEXP R_gtk_drag_icon_get_for_drag(SEXP s1);
extern SEXP R_gtk_drag_icon_create_widget_for_value(SEXP s1);
extern SEXP R_gtk_drag_icon_set_from_paintable(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_drag_icon_get_child(SEXP s1);
extern SEXP R_gtk_drag_icon_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_drag_source_new(void);
extern SEXP R_gtk_drag_source_drag_cancel(SEXP s1);
extern SEXP R_gtk_drag_source_get_actions(SEXP s1);
extern SEXP R_gtk_drag_source_get_content(SEXP s1);
extern SEXP R_gtk_drag_source_get_drag(SEXP s1);
extern SEXP R_gtk_drag_source_set_actions(SEXP s1, SEXP s2);
extern SEXP R_gtk_drag_source_set_content(SEXP s1, SEXP s2);
extern SEXP R_gtk_drag_source_set_icon(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_drawing_area_new(void);
extern SEXP R_gtk_drawing_area_get_content_height(SEXP s1);
extern SEXP R_gtk_drawing_area_get_content_width(SEXP s1);
extern SEXP R_gtk_drawing_area_set_content_height(SEXP s1, SEXP s2);
extern SEXP R_gtk_drawing_area_set_content_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_drawing_area_set_draw_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_drop_controller_motion_new(void);
extern SEXP R_gtk_drop_controller_motion_contains_pointer(SEXP s1);
extern SEXP R_gtk_drop_controller_motion_get_drop(SEXP s1);
extern SEXP R_gtk_drop_controller_motion_is_pointer(SEXP s1);
extern SEXP R_gtk_drop_down_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_down_new_from_strings(SEXP s1);
extern SEXP R_gtk_drop_down_get_enable_search(SEXP s1);
extern SEXP R_gtk_drop_down_get_expression(SEXP s1);
extern SEXP R_gtk_drop_down_get_factory(SEXP s1);
extern SEXP R_gtk_drop_down_get_header_factory(SEXP s1);
extern SEXP R_gtk_drop_down_get_list_factory(SEXP s1);
extern SEXP R_gtk_drop_down_get_model(SEXP s1);
extern SEXP R_gtk_drop_down_get_search_match_mode(SEXP s1);
extern SEXP R_gtk_drop_down_get_selected(SEXP s1);
extern SEXP R_gtk_drop_down_get_selected_item(SEXP s1);
extern SEXP R_gtk_drop_down_get_show_arrow(SEXP s1);
extern SEXP R_gtk_drop_down_set_enable_search(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_down_set_expression(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_down_set_factory(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_down_set_header_factory(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_down_set_list_factory(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_down_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_down_set_search_match_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_down_set_selected(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_down_set_show_arrow(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_target_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_target_get_actions(SEXP s1);
extern SEXP R_gtk_drop_target_get_current_drop(SEXP s1);
extern SEXP R_gtk_drop_target_get_drop(SEXP s1);
extern SEXP R_gtk_drop_target_get_formats(SEXP s1);
extern SEXP R_gtk_drop_target_get_gtypes(SEXP s1);
extern SEXP R_gtk_drop_target_get_preload(SEXP s1);
extern SEXP R_gtk_drop_target_get_value(SEXP s1);
extern SEXP R_gtk_drop_target_reject(SEXP s1);
extern SEXP R_gtk_drop_target_set_actions(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_target_set_gtypes(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_drop_target_set_preload(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_target_async_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_target_async_get_actions(SEXP s1);
extern SEXP R_gtk_drop_target_async_get_formats(SEXP s1);
extern SEXP R_gtk_drop_target_async_reject_drop(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_target_async_set_actions(SEXP s1, SEXP s2);
extern SEXP R_gtk_drop_target_async_set_formats(SEXP s1, SEXP s2);
extern SEXP R_gtk_editable_delegate_get_property(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_editable_delegate_set_property(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_editable_install_properties(SEXP s1, SEXP s2);
extern SEXP R_gtk_editable_delegate_get_accessible_platform_state(SEXP s1, SEXP s2);
extern SEXP R_gtk_editable_delete_selection(SEXP s1);
extern SEXP R_gtk_editable_delete_text(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_editable_finish_delegate(SEXP s1);
extern SEXP R_gtk_editable_get_alignment(SEXP s1);
extern SEXP R_gtk_editable_get_chars(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_editable_get_delegate(SEXP s1);
extern SEXP R_gtk_editable_get_editable(SEXP s1);
extern SEXP R_gtk_editable_get_enable_undo(SEXP s1);
extern SEXP R_gtk_editable_get_max_width_chars(SEXP s1);
extern SEXP R_gtk_editable_get_position(SEXP s1);
extern SEXP R_gtk_editable_get_selection_bounds(SEXP s1);
extern SEXP R_gtk_editable_get_text(SEXP s1);
extern SEXP R_gtk_editable_get_width_chars(SEXP s1);
extern SEXP R_gtk_editable_init_delegate(SEXP s1);
extern SEXP R_gtk_editable_insert_text(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_editable_select_region(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_editable_set_alignment(SEXP s1, SEXP s2);
extern SEXP R_gtk_editable_set_editable(SEXP s1, SEXP s2);
extern SEXP R_gtk_editable_set_enable_undo(SEXP s1, SEXP s2);
extern SEXP R_gtk_editable_set_max_width_chars(SEXP s1, SEXP s2);
extern SEXP R_gtk_editable_set_position(SEXP s1, SEXP s2);
extern SEXP R_gtk_editable_set_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_editable_set_width_chars(SEXP s1, SEXP s2);
extern SEXP R_gtk_editable_label_new(SEXP s1);
extern SEXP R_gtk_editable_label_get_editing(SEXP s1);
extern SEXP R_gtk_editable_label_start_editing(SEXP s1);
extern SEXP R_gtk_editable_label_stop_editing(SEXP s1, SEXP s2);
extern SEXP R_gtk_emoji_chooser_new(void);
extern SEXP R_gtk_entry_new(void);
extern SEXP R_gtk_entry_new_with_buffer(SEXP s1);
extern SEXP R_gtk_entry_get_activates_default(SEXP s1);
extern SEXP R_gtk_entry_get_alignment(SEXP s1);
extern SEXP R_gtk_entry_get_attributes(SEXP s1);
extern SEXP R_gtk_entry_get_buffer(SEXP s1);
extern SEXP R_gtk_entry_get_completion(SEXP s1);
extern SEXP R_gtk_entry_get_current_icon_drag_source(SEXP s1);
extern SEXP R_gtk_entry_get_extra_menu(SEXP s1);
extern SEXP R_gtk_entry_get_has_frame(SEXP s1);
extern SEXP R_gtk_entry_get_icon_activatable(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_get_icon_area(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_get_icon_at_pos(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_entry_get_icon_gicon(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_get_icon_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_get_icon_paintable(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_get_icon_sensitive(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_get_icon_storage_type(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_get_icon_tooltip_markup(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_get_icon_tooltip_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_get_input_hints(SEXP s1);
extern SEXP R_gtk_entry_get_input_purpose(SEXP s1);
extern SEXP R_gtk_entry_get_invisible_char(SEXP s1);
extern SEXP R_gtk_entry_get_max_length(SEXP s1);
extern SEXP R_gtk_entry_get_overwrite_mode(SEXP s1);
extern SEXP R_gtk_entry_get_placeholder_text(SEXP s1);
extern SEXP R_gtk_entry_get_progress_fraction(SEXP s1);
extern SEXP R_gtk_entry_get_progress_pulse_step(SEXP s1);
extern SEXP R_gtk_entry_get_tabs(SEXP s1);
extern SEXP R_gtk_entry_get_text_length(SEXP s1);
extern SEXP R_gtk_entry_get_visibility(SEXP s1);
extern SEXP R_gtk_entry_grab_focus_without_selecting(SEXP s1);
extern SEXP R_gtk_entry_progress_pulse(SEXP s1);
extern SEXP R_gtk_entry_reset_im_context(SEXP s1);
extern SEXP R_gtk_entry_set_activates_default(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_alignment(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_attributes(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_buffer(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_completion(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_extra_menu(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_has_frame(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_icon_activatable(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_entry_set_icon_drag_source(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_entry_set_icon_from_gicon(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_entry_set_icon_from_icon_name(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_entry_set_icon_from_paintable(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_entry_set_icon_sensitive(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_entry_set_icon_tooltip_markup(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_entry_set_icon_tooltip_text(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_entry_set_input_hints(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_input_purpose(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_invisible_char(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_max_length(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_overwrite_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_placeholder_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_progress_fraction(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_progress_pulse_step(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_tabs(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_set_visibility(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_unset_invisible_char(SEXP s1);
extern SEXP R_gtk_entry_buffer_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_buffer_delete_text(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_entry_buffer_emit_deleted_text(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_entry_buffer_emit_inserted_text(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_entry_buffer_get_bytes(SEXP s1);
extern SEXP R_gtk_entry_buffer_get_length(SEXP s1);
extern SEXP R_gtk_entry_buffer_get_max_length(SEXP s1);
extern SEXP R_gtk_entry_buffer_get_text(SEXP s1);
extern SEXP R_gtk_entry_buffer_insert_text(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_entry_buffer_set_max_length(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_buffer_set_text(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_entry_completion_new(void);
extern SEXP R_gtk_entry_completion_new_with_area(SEXP s1);
extern SEXP R_gtk_entry_completion_complete(SEXP s1);
extern SEXP R_gtk_entry_completion_compute_prefix(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_completion_get_completion_prefix(SEXP s1);
extern SEXP R_gtk_entry_completion_get_entry(SEXP s1);
extern SEXP R_gtk_entry_completion_get_inline_completion(SEXP s1);
extern SEXP R_gtk_entry_completion_get_inline_selection(SEXP s1);
extern SEXP R_gtk_entry_completion_get_minimum_key_length(SEXP s1);
extern SEXP R_gtk_entry_completion_get_model(SEXP s1);
extern SEXP R_gtk_entry_completion_get_popup_completion(SEXP s1);
extern SEXP R_gtk_entry_completion_get_popup_set_width(SEXP s1);
extern SEXP R_gtk_entry_completion_get_popup_single_match(SEXP s1);
extern SEXP R_gtk_entry_completion_get_text_column(SEXP s1);
extern SEXP R_gtk_entry_completion_insert_prefix(SEXP s1);
extern SEXP R_gtk_entry_completion_set_inline_completion(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_completion_set_inline_selection(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_completion_set_match_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_entry_completion_set_minimum_key_length(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_completion_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_completion_set_popup_completion(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_completion_set_popup_set_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_completion_set_popup_single_match(SEXP s1, SEXP s2);
extern SEXP R_gtk_entry_completion_set_text_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_event_controller_get_current_event(SEXP s1);
extern SEXP R_gtk_event_controller_get_current_event_device(SEXP s1);
extern SEXP R_gtk_event_controller_get_current_event_state(SEXP s1);
extern SEXP R_gtk_event_controller_get_current_event_time(SEXP s1);
extern SEXP R_gtk_event_controller_get_name(SEXP s1);
extern SEXP R_gtk_event_controller_get_propagation_limit(SEXP s1);
extern SEXP R_gtk_event_controller_get_propagation_phase(SEXP s1);
extern SEXP R_gtk_event_controller_get_widget(SEXP s1);
extern SEXP R_gtk_event_controller_reset(SEXP s1);
extern SEXP R_gtk_event_controller_set_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_event_controller_set_propagation_limit(SEXP s1, SEXP s2);
extern SEXP R_gtk_event_controller_set_propagation_phase(SEXP s1, SEXP s2);
extern SEXP R_gtk_event_controller_set_static_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_event_controller_focus_new(void);
extern SEXP R_gtk_event_controller_focus_contains_focus(SEXP s1);
extern SEXP R_gtk_event_controller_focus_is_focus(SEXP s1);
extern SEXP R_gtk_event_controller_key_new(void);
extern SEXP R_gtk_event_controller_key_forward(SEXP s1, SEXP s2);
extern SEXP R_gtk_event_controller_key_get_group(SEXP s1);
extern SEXP R_gtk_event_controller_key_get_im_context(SEXP s1);
extern SEXP R_gtk_event_controller_key_set_im_context(SEXP s1, SEXP s2);
extern SEXP R_gtk_event_controller_legacy_new(void);
extern SEXP R_gtk_event_controller_motion_new(void);
extern SEXP R_gtk_event_controller_motion_contains_pointer(SEXP s1);
extern SEXP R_gtk_event_controller_motion_is_pointer(SEXP s1);
extern SEXP R_gtk_event_controller_scroll_new(SEXP s1);
extern SEXP R_gtk_event_controller_scroll_get_flags(SEXP s1);
extern SEXP R_gtk_event_controller_scroll_get_unit(SEXP s1);
extern SEXP R_gtk_event_controller_scroll_set_flags(SEXP s1, SEXP s2);
extern SEXP R_gtk_every_filter_new(void);
extern SEXP R_gtk_expander_new(SEXP s1);
extern SEXP R_gtk_expander_new_with_mnemonic(SEXP s1);
extern SEXP R_gtk_expander_get_child(SEXP s1);
extern SEXP R_gtk_expander_get_expanded(SEXP s1);
extern SEXP R_gtk_expander_get_label(SEXP s1);
extern SEXP R_gtk_expander_get_label_widget(SEXP s1);
extern SEXP R_gtk_expander_get_resize_toplevel(SEXP s1);
extern SEXP R_gtk_expander_get_use_markup(SEXP s1);
extern SEXP R_gtk_expander_get_use_underline(SEXP s1);
extern SEXP R_gtk_expander_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_expander_set_expanded(SEXP s1, SEXP s2);
extern SEXP R_gtk_expander_set_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_expander_set_label_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_expander_set_resize_toplevel(SEXP s1, SEXP s2);
extern SEXP R_gtk_expander_set_use_markup(SEXP s1, SEXP s2);
extern SEXP R_gtk_expander_set_use_underline(SEXP s1, SEXP s2);
extern SEXP R_gtk_expression_bind(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_expression_evaluate(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_expression_get_value_type(SEXP s1);
extern SEXP R_gtk_expression_is_static(SEXP s1);
extern SEXP R_gtk_expression_ref(SEXP s1);
extern SEXP R_gtk_expression_unref(SEXP s1);
extern SEXP R_gtk_expression_watch(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_expression_watch_evaluate(SEXP s1, SEXP s2);
extern SEXP R_gtk_expression_watch_ref(SEXP s1);
extern SEXP R_gtk_expression_watch_unref(SEXP s1);
extern SEXP R_gtk_expression_watch_unwatch(SEXP s1);
extern SEXP R_gtk_file_chooser_add_choice(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_file_chooser_add_filter(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_add_shortcut_folder(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_get_action(SEXP s1);
extern SEXP R_gtk_file_chooser_get_choice(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_get_create_folders(SEXP s1);
extern SEXP R_gtk_file_chooser_get_current_folder(SEXP s1);
extern SEXP R_gtk_file_chooser_get_current_name(SEXP s1);
extern SEXP R_gtk_file_chooser_get_file(SEXP s1);
extern SEXP R_gtk_file_chooser_get_files(SEXP s1);
extern SEXP R_gtk_file_chooser_get_filter(SEXP s1);
extern SEXP R_gtk_file_chooser_get_filters(SEXP s1);
extern SEXP R_gtk_file_chooser_get_select_multiple(SEXP s1);
extern SEXP R_gtk_file_chooser_get_shortcut_folders(SEXP s1);
extern SEXP R_gtk_file_chooser_remove_choice(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_remove_filter(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_remove_shortcut_folder(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_set_action(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_set_choice(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_file_chooser_set_create_folders(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_set_current_folder(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_set_current_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_set_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_set_filter(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_set_select_multiple(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_error_quark(void);
extern SEXP R_gtk_file_chooser_native_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_file_chooser_native_get_accept_label(SEXP s1);
extern SEXP R_gtk_file_chooser_native_get_cancel_label(SEXP s1);
extern SEXP R_gtk_file_chooser_native_set_accept_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_native_set_cancel_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_chooser_widget_new(SEXP s1);
extern SEXP R_gtk_file_dialog_new(void);
extern SEXP R_gtk_file_dialog_get_accept_label(SEXP s1);
extern SEXP R_gtk_file_dialog_get_default_filter(SEXP s1);
extern SEXP R_gtk_file_dialog_get_filters(SEXP s1);
extern SEXP R_gtk_file_dialog_get_initial_file(SEXP s1);
extern SEXP R_gtk_file_dialog_get_initial_folder(SEXP s1);
extern SEXP R_gtk_file_dialog_get_initial_name(SEXP s1);
extern SEXP R_gtk_file_dialog_get_modal(SEXP s1);
extern SEXP R_gtk_file_dialog_get_title(SEXP s1);
extern SEXP R_gtk_file_dialog_open(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_file_dialog_open_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_open_multiple(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_file_dialog_open_multiple_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_save(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_file_dialog_save_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_select_folder(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_file_dialog_select_folder_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_select_multiple_folders(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_file_dialog_select_multiple_folders_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_set_accept_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_set_default_filter(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_set_filters(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_set_initial_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_set_initial_folder(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_set_initial_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_set_modal(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_dialog_set_title(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_filter_new(void);
extern SEXP R_gtk_file_filter_new_from_gvariant(SEXP s1);
extern SEXP R_gtk_file_filter_add_mime_type(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_filter_add_pattern(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_filter_add_pixbuf_formats(SEXP s1);
extern SEXP R_gtk_file_filter_add_suffix(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_filter_get_attributes(SEXP s1);
extern SEXP R_gtk_file_filter_get_name(SEXP s1);
extern SEXP R_gtk_file_filter_set_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_filter_to_gvariant(SEXP s1);
extern SEXP R_gtk_file_launcher_new(SEXP s1);
extern SEXP R_gtk_file_launcher_get_always_ask(SEXP s1);
extern SEXP R_gtk_file_launcher_get_file(SEXP s1);
extern SEXP R_gtk_file_launcher_launch(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_file_launcher_launch_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_launcher_open_containing_folder(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_file_launcher_open_containing_folder_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_launcher_set_always_ask(SEXP s1, SEXP s2);
extern SEXP R_gtk_file_launcher_set_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_filter_changed(SEXP s1, SEXP s2);
extern SEXP R_gtk_filter_get_strictness(SEXP s1);
extern SEXP R_gtk_filter_match(SEXP s1, SEXP s2);
extern SEXP R_gtk_filter_list_model_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_filter_list_model_get_filter(SEXP s1);
extern SEXP R_gtk_filter_list_model_get_incremental(SEXP s1);
extern SEXP R_gtk_filter_list_model_get_model(SEXP s1);
extern SEXP R_gtk_filter_list_model_get_pending(SEXP s1);
extern SEXP R_gtk_filter_list_model_set_filter(SEXP s1, SEXP s2);
extern SEXP R_gtk_filter_list_model_set_incremental(SEXP s1, SEXP s2);
extern SEXP R_gtk_filter_list_model_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_fixed_new(void);
extern SEXP R_gtk_fixed_get_child_position(SEXP s1, SEXP s2);
extern SEXP R_gtk_fixed_get_child_transform(SEXP s1, SEXP s2);
extern SEXP R_gtk_fixed_move(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_fixed_put(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_fixed_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_fixed_set_child_transform(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_fixed_layout_new(void);
extern SEXP R_gtk_fixed_layout_child_get_transform(SEXP s1);
extern SEXP R_gtk_fixed_layout_child_set_transform(SEXP s1, SEXP s2);
extern SEXP R_gtk_flatten_list_model_new(SEXP s1);
extern SEXP R_gtk_flatten_list_model_get_model(SEXP s1);
extern SEXP R_gtk_flatten_list_model_get_model_for_item(SEXP s1, SEXP s2);
extern SEXP R_gtk_flatten_list_model_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_new(void);
extern SEXP R_gtk_flow_box_append(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_bind_model(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_flow_box_get_activate_on_single_click(SEXP s1);
extern SEXP R_gtk_flow_box_get_child_at_index(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_get_child_at_pos(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_flow_box_get_column_spacing(SEXP s1);
extern SEXP R_gtk_flow_box_get_homogeneous(SEXP s1);
extern SEXP R_gtk_flow_box_get_max_children_per_line(SEXP s1);
extern SEXP R_gtk_flow_box_get_min_children_per_line(SEXP s1);
extern SEXP R_gtk_flow_box_get_row_spacing(SEXP s1);
extern SEXP R_gtk_flow_box_get_selected_children(SEXP s1);
extern SEXP R_gtk_flow_box_get_selection_mode(SEXP s1);
extern SEXP R_gtk_flow_box_insert(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_flow_box_invalidate_filter(SEXP s1);
extern SEXP R_gtk_flow_box_invalidate_sort(SEXP s1);
extern SEXP R_gtk_flow_box_prepend(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_remove_all(SEXP s1);
extern SEXP R_gtk_flow_box_select_all(SEXP s1);
extern SEXP R_gtk_flow_box_select_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_selected_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_flow_box_set_activate_on_single_click(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_set_column_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_set_filter_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_flow_box_set_hadjustment(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_set_homogeneous(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_set_max_children_per_line(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_set_min_children_per_line(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_set_row_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_set_selection_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_set_sort_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_flow_box_set_vadjustment(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_unselect_all(SEXP s1);
extern SEXP R_gtk_flow_box_unselect_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_flow_box_child_new(void);
extern SEXP R_gtk_flow_box_child_changed(SEXP s1);
extern SEXP R_gtk_flow_box_child_get_child(SEXP s1);
extern SEXP R_gtk_flow_box_child_get_index(SEXP s1);
extern SEXP R_gtk_flow_box_child_is_selected(SEXP s1);
extern SEXP R_gtk_flow_box_child_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_button_new(void);
extern SEXP R_gtk_font_button_new_with_font(SEXP s1);
extern SEXP R_gtk_font_button_get_modal(SEXP s1);
extern SEXP R_gtk_font_button_get_title(SEXP s1);
extern SEXP R_gtk_font_button_get_use_font(SEXP s1);
extern SEXP R_gtk_font_button_get_use_size(SEXP s1);
extern SEXP R_gtk_font_button_set_modal(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_button_set_title(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_button_set_use_font(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_button_set_use_size(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_chooser_get_font(SEXP s1);
extern SEXP R_gtk_font_chooser_get_font_desc(SEXP s1);
extern SEXP R_gtk_font_chooser_get_font_face(SEXP s1);
extern SEXP R_gtk_font_chooser_get_font_family(SEXP s1);
extern SEXP R_gtk_font_chooser_get_font_features(SEXP s1);
extern SEXP R_gtk_font_chooser_get_font_map(SEXP s1);
extern SEXP R_gtk_font_chooser_get_font_size(SEXP s1);
extern SEXP R_gtk_font_chooser_get_language(SEXP s1);
extern SEXP R_gtk_font_chooser_get_level(SEXP s1);
extern SEXP R_gtk_font_chooser_get_preview_text(SEXP s1);
extern SEXP R_gtk_font_chooser_get_show_preview_entry(SEXP s1);
extern SEXP R_gtk_font_chooser_set_filter_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_font_chooser_set_font(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_chooser_set_font_desc(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_chooser_set_font_map(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_chooser_set_language(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_chooser_set_level(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_chooser_set_preview_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_chooser_set_show_preview_entry(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_chooser_dialog_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_chooser_widget_new(void);
extern SEXP R_gtk_font_dialog_new(void);
extern SEXP R_gtk_font_dialog_choose_face(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_font_dialog_choose_face_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_choose_family(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_font_dialog_choose_family_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_choose_font(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_font_dialog_choose_font_and_features(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_font_dialog_choose_font_and_features_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_choose_font_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_get_filter(SEXP s1);
extern SEXP R_gtk_font_dialog_get_font_map(SEXP s1);
extern SEXP R_gtk_font_dialog_get_language(SEXP s1);
extern SEXP R_gtk_font_dialog_get_modal(SEXP s1);
extern SEXP R_gtk_font_dialog_get_title(SEXP s1);
extern SEXP R_gtk_font_dialog_set_filter(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_set_font_map(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_set_language(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_set_modal(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_set_title(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_button_new(SEXP s1);
extern SEXP R_gtk_font_dialog_button_get_dialog(SEXP s1);
extern SEXP R_gtk_font_dialog_button_get_font_desc(SEXP s1);
extern SEXP R_gtk_font_dialog_button_get_font_features(SEXP s1);
extern SEXP R_gtk_font_dialog_button_get_language(SEXP s1);
extern SEXP R_gtk_font_dialog_button_get_level(SEXP s1);
extern SEXP R_gtk_font_dialog_button_get_use_font(SEXP s1);
extern SEXP R_gtk_font_dialog_button_get_use_size(SEXP s1);
extern SEXP R_gtk_font_dialog_button_set_dialog(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_button_set_font_desc(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_button_set_font_features(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_button_set_language(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_button_set_level(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_button_set_use_font(SEXP s1, SEXP s2);
extern SEXP R_gtk_font_dialog_button_set_use_size(SEXP s1, SEXP s2);
extern SEXP R_gtk_frame_new(SEXP s1);
extern SEXP R_gtk_frame_get_child(SEXP s1);
extern SEXP R_gtk_frame_get_label(SEXP s1);
extern SEXP R_gtk_frame_get_label_align(SEXP s1);
extern SEXP R_gtk_frame_get_label_widget(SEXP s1);
extern SEXP R_gtk_frame_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_frame_set_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_frame_set_label_align(SEXP s1, SEXP s2);
extern SEXP R_gtk_frame_set_label_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_gl_area_new(void);
extern SEXP R_gtk_gl_area_attach_buffers(SEXP s1);
extern SEXP R_gtk_gl_area_get_allowed_apis(SEXP s1);
extern SEXP R_gtk_gl_area_get_api(SEXP s1);
extern SEXP R_gtk_gl_area_get_auto_render(SEXP s1);
extern SEXP R_gtk_gl_area_get_context(SEXP s1);
extern SEXP R_gtk_gl_area_get_error(SEXP s1);
extern SEXP R_gtk_gl_area_get_has_depth_buffer(SEXP s1);
extern SEXP R_gtk_gl_area_get_has_stencil_buffer(SEXP s1);
extern SEXP R_gtk_gl_area_get_required_version(SEXP s1);
extern SEXP R_gtk_gl_area_get_use_es(SEXP s1);
extern SEXP R_gtk_gl_area_make_current(SEXP s1);
extern SEXP R_gtk_gl_area_queue_render(SEXP s1);
extern SEXP R_gtk_gl_area_set_allowed_apis(SEXP s1, SEXP s2);
extern SEXP R_gtk_gl_area_set_auto_render(SEXP s1, SEXP s2);
extern SEXP R_gtk_gl_area_set_error(SEXP s1, SEXP s2);
extern SEXP R_gtk_gl_area_set_has_depth_buffer(SEXP s1, SEXP s2);
extern SEXP R_gtk_gl_area_set_has_stencil_buffer(SEXP s1, SEXP s2);
extern SEXP R_gtk_gl_area_set_required_version(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_gl_area_set_use_es(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_get_bounding_box(SEXP s1);
extern SEXP R_gtk_gesture_get_bounding_box_center(SEXP s1);
extern SEXP R_gtk_gesture_get_device(SEXP s1);
extern SEXP R_gtk_gesture_get_group(SEXP s1);
extern SEXP R_gtk_gesture_get_last_event(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_get_last_updated_sequence(SEXP s1);
extern SEXP R_gtk_gesture_get_point(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_get_sequence_state(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_get_sequences(SEXP s1);
extern SEXP R_gtk_gesture_group(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_handles_sequence(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_is_active(SEXP s1);
extern SEXP R_gtk_gesture_is_grouped_with(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_is_recognized(SEXP s1);
extern SEXP R_gtk_gesture_set_sequence_state(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_gesture_set_state(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_ungroup(SEXP s1);
extern SEXP R_gtk_gesture_click_new(void);
extern SEXP R_gtk_gesture_drag_new(void);
extern SEXP R_gtk_gesture_drag_get_offset(SEXP s1);
extern SEXP R_gtk_gesture_drag_get_start_point(SEXP s1);
extern SEXP R_gtk_gesture_long_press_new(void);
extern SEXP R_gtk_gesture_long_press_get_delay_factor(SEXP s1);
extern SEXP R_gtk_gesture_long_press_set_delay_factor(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_pan_new(SEXP s1);
extern SEXP R_gtk_gesture_pan_get_orientation(SEXP s1);
extern SEXP R_gtk_gesture_pan_set_orientation(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_rotate_new(void);
extern SEXP R_gtk_gesture_rotate_get_angle_delta(SEXP s1);
extern SEXP R_gtk_gesture_single_get_button(SEXP s1);
extern SEXP R_gtk_gesture_single_get_current_button(SEXP s1);
extern SEXP R_gtk_gesture_single_get_current_sequence(SEXP s1);
extern SEXP R_gtk_gesture_single_get_exclusive(SEXP s1);
extern SEXP R_gtk_gesture_single_get_touch_only(SEXP s1);
extern SEXP R_gtk_gesture_single_set_button(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_single_set_exclusive(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_single_set_touch_only(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_stylus_new(void);
extern SEXP R_gtk_gesture_stylus_get_axes(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_stylus_get_axis(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_stylus_get_backlog(SEXP s1);
extern SEXP R_gtk_gesture_stylus_get_device_tool(SEXP s1);
extern SEXP R_gtk_gesture_stylus_get_stylus_only(SEXP s1);
extern SEXP R_gtk_gesture_stylus_set_stylus_only(SEXP s1, SEXP s2);
extern SEXP R_gtk_gesture_swipe_new(void);
extern SEXP R_gtk_gesture_swipe_get_velocity(SEXP s1);
extern SEXP R_gtk_gesture_zoom_new(void);
extern SEXP R_gtk_gesture_zoom_get_scale_delta(SEXP s1);
extern SEXP R_gtk_grid_new(void);
extern SEXP R_gtk_grid_attach(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_grid_attach_next_to(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_grid_get_baseline_row(SEXP s1);
extern SEXP R_gtk_grid_get_child_at(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_grid_get_column_homogeneous(SEXP s1);
extern SEXP R_gtk_grid_get_column_spacing(SEXP s1);
extern SEXP R_gtk_grid_get_row_baseline_position(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_get_row_homogeneous(SEXP s1);
extern SEXP R_gtk_grid_get_row_spacing(SEXP s1);
extern SEXP R_gtk_grid_insert_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_insert_next_to(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_grid_insert_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_query_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_remove_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_remove_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_set_baseline_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_set_column_homogeneous(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_set_column_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_set_row_baseline_position(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_grid_set_row_homogeneous(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_set_row_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_layout_new(void);
extern SEXP R_gtk_grid_layout_get_baseline_row(SEXP s1);
extern SEXP R_gtk_grid_layout_get_column_homogeneous(SEXP s1);
extern SEXP R_gtk_grid_layout_get_column_spacing(SEXP s1);
extern SEXP R_gtk_grid_layout_get_row_baseline_position(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_layout_get_row_homogeneous(SEXP s1);
extern SEXP R_gtk_grid_layout_get_row_spacing(SEXP s1);
extern SEXP R_gtk_grid_layout_set_baseline_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_layout_set_column_homogeneous(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_layout_set_column_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_layout_set_row_baseline_position(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_grid_layout_set_row_homogeneous(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_layout_set_row_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_layout_child_get_column(SEXP s1);
extern SEXP R_gtk_grid_layout_child_get_column_span(SEXP s1);
extern SEXP R_gtk_grid_layout_child_get_row(SEXP s1);
extern SEXP R_gtk_grid_layout_child_get_row_span(SEXP s1);
extern SEXP R_gtk_grid_layout_child_set_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_layout_child_set_column_span(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_layout_child_set_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_layout_child_set_row_span(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_view_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_view_get_enable_rubberband(SEXP s1);
extern SEXP R_gtk_grid_view_get_factory(SEXP s1);
extern SEXP R_gtk_grid_view_get_max_columns(SEXP s1);
extern SEXP R_gtk_grid_view_get_min_columns(SEXP s1);
extern SEXP R_gtk_grid_view_get_model(SEXP s1);
extern SEXP R_gtk_grid_view_get_single_click_activate(SEXP s1);
extern SEXP R_gtk_grid_view_get_tab_behavior(SEXP s1);
extern SEXP R_gtk_grid_view_scroll_to(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_grid_view_set_enable_rubberband(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_view_set_factory(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_view_set_max_columns(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_view_set_min_columns(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_view_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_view_set_single_click_activate(SEXP s1, SEXP s2);
extern SEXP R_gtk_grid_view_set_tab_behavior(SEXP s1, SEXP s2);
extern SEXP R_gtk_header_bar_new(void);
extern SEXP R_gtk_header_bar_get_decoration_layout(SEXP s1);
extern SEXP R_gtk_header_bar_get_show_title_buttons(SEXP s1);
extern SEXP R_gtk_header_bar_get_title_widget(SEXP s1);
extern SEXP R_gtk_header_bar_pack_end(SEXP s1, SEXP s2);
extern SEXP R_gtk_header_bar_pack_start(SEXP s1, SEXP s2);
extern SEXP R_gtk_header_bar_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_header_bar_set_decoration_layout(SEXP s1, SEXP s2);
extern SEXP R_gtk_header_bar_set_show_title_buttons(SEXP s1, SEXP s2);
extern SEXP R_gtk_header_bar_set_title_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_im_context_delete_surrounding(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_im_context_filter_key(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_gtk_im_context_filter_keypress(SEXP s1, SEXP s2);
extern SEXP R_gtk_im_context_focus_in(SEXP s1);
extern SEXP R_gtk_im_context_focus_out(SEXP s1);
extern SEXP R_gtk_im_context_get_preedit_string(SEXP s1);
extern SEXP R_gtk_im_context_get_surrounding(SEXP s1);
extern SEXP R_gtk_im_context_get_surrounding_with_selection(SEXP s1);
extern SEXP R_gtk_im_context_reset(SEXP s1);
extern SEXP R_gtk_im_context_set_client_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_im_context_set_cursor_location(SEXP s1, SEXP s2);
extern SEXP R_gtk_im_context_set_surrounding(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_im_context_set_surrounding_with_selection(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_im_context_set_use_preedit(SEXP s1, SEXP s2);
extern SEXP R_gtk_im_context_simple_new(void);
extern SEXP R_gtk_im_context_simple_add_compose_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_im_multicontext_new(void);
extern SEXP R_gtk_im_multicontext_get_context_id(SEXP s1);
extern SEXP R_gtk_im_multicontext_set_context_id(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_paintable_new_for_file(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_icon_paintable_get_file(SEXP s1);
extern SEXP R_gtk_icon_paintable_get_icon_name(SEXP s1);
extern SEXP R_gtk_icon_paintable_is_symbolic(SEXP s1);
extern SEXP R_gtk_icon_theme_new(void);
extern SEXP R_gtk_icon_theme_get_for_display(SEXP s1);
extern SEXP R_gtk_icon_theme_add_resource_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_theme_add_search_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_theme_get_display(SEXP s1);
extern SEXP R_gtk_icon_theme_get_icon_names(SEXP s1);
extern SEXP R_gtk_icon_theme_get_icon_sizes(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_theme_get_resource_path(SEXP s1);
extern SEXP R_gtk_icon_theme_get_search_path(SEXP s1);
extern SEXP R_gtk_icon_theme_get_theme_name(SEXP s1);
extern SEXP R_gtk_icon_theme_has_gicon(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_theme_has_icon(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_theme_lookup_by_gicon(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_icon_theme_lookup_icon(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gtk_icon_theme_set_resource_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_theme_set_search_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_theme_set_theme_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_theme_error_quark(void);
extern SEXP R_gtk_icon_view_new(void);
extern SEXP R_gtk_icon_view_new_with_area(SEXP s1);
extern SEXP R_gtk_icon_view_new_with_model(SEXP s1);
extern SEXP R_gtk_icon_view_create_drag_icon(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_enable_model_drag_dest(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_icon_view_enable_model_drag_source(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_icon_view_get_activate_on_single_click(SEXP s1);
extern SEXP R_gtk_icon_view_get_cell_rect(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_icon_view_get_column_spacing(SEXP s1);
extern SEXP R_gtk_icon_view_get_columns(SEXP s1);
extern SEXP R_gtk_icon_view_get_cursor(SEXP s1);
extern SEXP R_gtk_icon_view_get_dest_item_at_pos(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_icon_view_get_drag_dest_item(SEXP s1);
extern SEXP R_gtk_icon_view_get_item_at_pos(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_icon_view_get_item_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_get_item_orientation(SEXP s1);
extern SEXP R_gtk_icon_view_get_item_padding(SEXP s1);
extern SEXP R_gtk_icon_view_get_item_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_get_item_width(SEXP s1);
extern SEXP R_gtk_icon_view_get_margin(SEXP s1);
extern SEXP R_gtk_icon_view_get_markup_column(SEXP s1);
extern SEXP R_gtk_icon_view_get_model(SEXP s1);
extern SEXP R_gtk_icon_view_get_path_at_pos(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_icon_view_get_pixbuf_column(SEXP s1);
extern SEXP R_gtk_icon_view_get_reorderable(SEXP s1);
extern SEXP R_gtk_icon_view_get_row_spacing(SEXP s1);
extern SEXP R_gtk_icon_view_get_selected_items(SEXP s1);
extern SEXP R_gtk_icon_view_get_selection_mode(SEXP s1);
extern SEXP R_gtk_icon_view_get_spacing(SEXP s1);
extern SEXP R_gtk_icon_view_get_text_column(SEXP s1);
extern SEXP R_gtk_icon_view_get_tooltip_column(SEXP s1);
extern SEXP R_gtk_icon_view_get_tooltip_context(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_icon_view_get_visible_range(SEXP s1);
extern SEXP R_gtk_icon_view_item_activated(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_path_is_selected(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_scroll_to_path(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_icon_view_select_all(SEXP s1);
extern SEXP R_gtk_icon_view_select_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_selected_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_icon_view_set_activate_on_single_click(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_column_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_columns(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_cursor(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_icon_view_set_drag_dest_item(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_icon_view_set_item_orientation(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_item_padding(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_item_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_margin(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_markup_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_pixbuf_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_reorderable(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_row_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_selection_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_text_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_tooltip_cell(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_icon_view_set_tooltip_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_set_tooltip_item(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_icon_view_unselect_all(SEXP s1);
extern SEXP R_gtk_icon_view_unselect_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_icon_view_unset_model_drag_dest(SEXP s1);
extern SEXP R_gtk_icon_view_unset_model_drag_source(SEXP s1);
extern SEXP R_gtk_image_new(void);
extern SEXP R_gtk_image_new_from_file(SEXP s1);
extern SEXP R_gtk_image_new_from_gicon(SEXP s1);
extern SEXP R_gtk_image_new_from_icon_name(SEXP s1);
extern SEXP R_gtk_image_new_from_paintable(SEXP s1);
extern SEXP R_gtk_image_new_from_pixbuf(SEXP s1);
extern SEXP R_gtk_image_new_from_resource(SEXP s1);
extern SEXP R_gtk_image_clear(SEXP s1);
extern SEXP R_gtk_image_get_gicon(SEXP s1);
extern SEXP R_gtk_image_get_icon_name(SEXP s1);
extern SEXP R_gtk_image_get_icon_size(SEXP s1);
extern SEXP R_gtk_image_get_paintable(SEXP s1);
extern SEXP R_gtk_image_get_pixel_size(SEXP s1);
extern SEXP R_gtk_image_get_storage_type(SEXP s1);
extern SEXP R_gtk_image_set_from_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_image_set_from_gicon(SEXP s1, SEXP s2);
extern SEXP R_gtk_image_set_from_icon_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_image_set_from_paintable(SEXP s1, SEXP s2);
extern SEXP R_gtk_image_set_from_pixbuf(SEXP s1, SEXP s2);
extern SEXP R_gtk_image_set_from_resource(SEXP s1, SEXP s2);
extern SEXP R_gtk_image_set_icon_size(SEXP s1, SEXP s2);
extern SEXP R_gtk_image_set_pixel_size(SEXP s1, SEXP s2);
extern SEXP R_gtk_info_bar_new(void);
extern SEXP R_gtk_info_bar_add_action_widget(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_info_bar_add_button(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_info_bar_add_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_info_bar_get_message_type(SEXP s1);
extern SEXP R_gtk_info_bar_get_revealed(SEXP s1);
extern SEXP R_gtk_info_bar_get_show_close_button(SEXP s1);
extern SEXP R_gtk_info_bar_remove_action_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_info_bar_remove_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_info_bar_response(SEXP s1, SEXP s2);
extern SEXP R_gtk_info_bar_set_default_response(SEXP s1, SEXP s2);
extern SEXP R_gtk_info_bar_set_message_type(SEXP s1, SEXP s2);
extern SEXP R_gtk_info_bar_set_response_sensitive(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_info_bar_set_revealed(SEXP s1, SEXP s2);
extern SEXP R_gtk_info_bar_set_show_close_button(SEXP s1, SEXP s2);
extern SEXP R_gtk_inscription_new(SEXP s1);
extern SEXP R_gtk_inscription_get_attributes(SEXP s1);
extern SEXP R_gtk_inscription_get_min_chars(SEXP s1);
extern SEXP R_gtk_inscription_get_min_lines(SEXP s1);
extern SEXP R_gtk_inscription_get_nat_chars(SEXP s1);
extern SEXP R_gtk_inscription_get_nat_lines(SEXP s1);
extern SEXP R_gtk_inscription_get_text(SEXP s1);
extern SEXP R_gtk_inscription_get_text_overflow(SEXP s1);
extern SEXP R_gtk_inscription_get_wrap_mode(SEXP s1);
extern SEXP R_gtk_inscription_get_xalign(SEXP s1);
extern SEXP R_gtk_inscription_get_yalign(SEXP s1);
extern SEXP R_gtk_inscription_set_attributes(SEXP s1, SEXP s2);
extern SEXP R_gtk_inscription_set_markup(SEXP s1, SEXP s2);
extern SEXP R_gtk_inscription_set_min_chars(SEXP s1, SEXP s2);
extern SEXP R_gtk_inscription_set_min_lines(SEXP s1, SEXP s2);
extern SEXP R_gtk_inscription_set_nat_chars(SEXP s1, SEXP s2);
extern SEXP R_gtk_inscription_set_nat_lines(SEXP s1, SEXP s2);
extern SEXP R_gtk_inscription_set_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_inscription_set_text_overflow(SEXP s1, SEXP s2);
extern SEXP R_gtk_inscription_set_wrap_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_inscription_set_xalign(SEXP s1, SEXP s2);
extern SEXP R_gtk_inscription_set_yalign(SEXP s1, SEXP s2);
extern SEXP R_gtk_keyval_trigger_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_keyval_trigger_get_keyval(SEXP s1);
extern SEXP R_gtk_keyval_trigger_get_modifiers(SEXP s1);
extern SEXP R_gtk_label_new(SEXP s1);
extern SEXP R_gtk_label_new_with_mnemonic(SEXP s1);
extern SEXP R_gtk_label_get_attributes(SEXP s1);
extern SEXP R_gtk_label_get_current_uri(SEXP s1);
extern SEXP R_gtk_label_get_ellipsize(SEXP s1);
extern SEXP R_gtk_label_get_extra_menu(SEXP s1);
extern SEXP R_gtk_label_get_justify(SEXP s1);
extern SEXP R_gtk_label_get_label(SEXP s1);
extern SEXP R_gtk_label_get_layout(SEXP s1);
extern SEXP R_gtk_label_get_layout_offsets(SEXP s1);
extern SEXP R_gtk_label_get_lines(SEXP s1);
extern SEXP R_gtk_label_get_max_width_chars(SEXP s1);
extern SEXP R_gtk_label_get_mnemonic_keyval(SEXP s1);
extern SEXP R_gtk_label_get_mnemonic_widget(SEXP s1);
extern SEXP R_gtk_label_get_natural_wrap_mode(SEXP s1);
extern SEXP R_gtk_label_get_selectable(SEXP s1);
extern SEXP R_gtk_label_get_selection_bounds(SEXP s1);
extern SEXP R_gtk_label_get_single_line_mode(SEXP s1);
extern SEXP R_gtk_label_get_tabs(SEXP s1);
extern SEXP R_gtk_label_get_text(SEXP s1);
extern SEXP R_gtk_label_get_use_markup(SEXP s1);
extern SEXP R_gtk_label_get_use_underline(SEXP s1);
extern SEXP R_gtk_label_get_width_chars(SEXP s1);
extern SEXP R_gtk_label_get_wrap(SEXP s1);
extern SEXP R_gtk_label_get_wrap_mode(SEXP s1);
extern SEXP R_gtk_label_get_xalign(SEXP s1);
extern SEXP R_gtk_label_get_yalign(SEXP s1);
extern SEXP R_gtk_label_select_region(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_label_set_attributes(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_ellipsize(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_extra_menu(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_justify(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_lines(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_markup(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_markup_with_mnemonic(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_max_width_chars(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_mnemonic_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_natural_wrap_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_selectable(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_single_line_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_tabs(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_text_with_mnemonic(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_use_markup(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_use_underline(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_width_chars(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_wrap(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_wrap_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_xalign(SEXP s1, SEXP s2);
extern SEXP R_gtk_label_set_yalign(SEXP s1, SEXP s2);
extern SEXP R_gtk_layout_child_get_child_widget(SEXP s1);
extern SEXP R_gtk_layout_child_get_layout_manager(SEXP s1);
extern SEXP R_gtk_layout_manager_allocate(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_layout_manager_get_layout_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_layout_manager_get_request_mode(SEXP s1);
extern SEXP R_gtk_layout_manager_get_widget(SEXP s1);
extern SEXP R_gtk_layout_manager_layout_changed(SEXP s1);
extern SEXP R_gtk_layout_manager_measure(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_level_bar_new(void);
extern SEXP R_gtk_level_bar_new_for_interval(SEXP s1, SEXP s2);
extern SEXP R_gtk_level_bar_add_offset_value(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_level_bar_get_inverted(SEXP s1);
extern SEXP R_gtk_level_bar_get_max_value(SEXP s1);
extern SEXP R_gtk_level_bar_get_min_value(SEXP s1);
extern SEXP R_gtk_level_bar_get_mode(SEXP s1);
extern SEXP R_gtk_level_bar_get_offset_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_level_bar_get_value(SEXP s1);
extern SEXP R_gtk_level_bar_remove_offset_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_level_bar_set_inverted(SEXP s1, SEXP s2);
extern SEXP R_gtk_level_bar_set_max_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_level_bar_set_min_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_level_bar_set_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_level_bar_set_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_link_button_new(SEXP s1);
extern SEXP R_gtk_link_button_new_with_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_link_button_get_uri(SEXP s1);
extern SEXP R_gtk_link_button_get_visited(SEXP s1);
extern SEXP R_gtk_link_button_set_uri(SEXP s1, SEXP s2);
extern SEXP R_gtk_link_button_set_visited(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_new(void);
extern SEXP R_gtk_list_box_append(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_bind_model(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_list_box_drag_highlight_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_drag_unhighlight_row(SEXP s1);
extern SEXP R_gtk_list_box_get_activate_on_single_click(SEXP s1);
extern SEXP R_gtk_list_box_get_adjustment(SEXP s1);
extern SEXP R_gtk_list_box_get_row_at_index(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_get_row_at_y(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_get_selected_row(SEXP s1);
extern SEXP R_gtk_list_box_get_selected_rows(SEXP s1);
extern SEXP R_gtk_list_box_get_selection_mode(SEXP s1);
extern SEXP R_gtk_list_box_get_show_separators(SEXP s1);
extern SEXP R_gtk_list_box_insert(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_list_box_invalidate_filter(SEXP s1);
extern SEXP R_gtk_list_box_invalidate_headers(SEXP s1);
extern SEXP R_gtk_list_box_invalidate_sort(SEXP s1);
extern SEXP R_gtk_list_box_prepend(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_remove_all(SEXP s1);
extern SEXP R_gtk_list_box_select_all(SEXP s1);
extern SEXP R_gtk_list_box_select_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_selected_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_list_box_set_activate_on_single_click(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_set_adjustment(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_set_filter_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_list_box_set_header_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_list_box_set_placeholder(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_set_selection_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_set_show_separators(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_set_sort_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_list_box_unselect_all(SEXP s1);
extern SEXP R_gtk_list_box_unselect_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_row_new(void);
extern SEXP R_gtk_list_box_row_changed(SEXP s1);
extern SEXP R_gtk_list_box_row_get_activatable(SEXP s1);
extern SEXP R_gtk_list_box_row_get_child(SEXP s1);
extern SEXP R_gtk_list_box_row_get_header(SEXP s1);
extern SEXP R_gtk_list_box_row_get_index(SEXP s1);
extern SEXP R_gtk_list_box_row_get_selectable(SEXP s1);
extern SEXP R_gtk_list_box_row_is_selected(SEXP s1);
extern SEXP R_gtk_list_box_row_set_activatable(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_row_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_row_set_header(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_box_row_set_selectable(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_header_get_child(SEXP s1);
extern SEXP R_gtk_list_header_get_end(SEXP s1);
extern SEXP R_gtk_list_header_get_item(SEXP s1);
extern SEXP R_gtk_list_header_get_n_items(SEXP s1);
extern SEXP R_gtk_list_header_get_start(SEXP s1);
extern SEXP R_gtk_list_header_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_item_get_accessible_description(SEXP s1);
extern SEXP R_gtk_list_item_get_accessible_label(SEXP s1);
extern SEXP R_gtk_list_item_get_activatable(SEXP s1);
extern SEXP R_gtk_list_item_get_child(SEXP s1);
extern SEXP R_gtk_list_item_get_focusable(SEXP s1);
extern SEXP R_gtk_list_item_get_item(SEXP s1);
extern SEXP R_gtk_list_item_get_position(SEXP s1);
extern SEXP R_gtk_list_item_get_selectable(SEXP s1);
extern SEXP R_gtk_list_item_get_selected(SEXP s1);
extern SEXP R_gtk_list_item_set_accessible_description(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_item_set_accessible_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_item_set_activatable(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_item_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_item_set_focusable(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_item_set_selectable(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_store_newv(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_store_append(SEXP s1);
extern SEXP R_gtk_list_store_clear(SEXP s1);
extern SEXP R_gtk_list_store_insert(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_store_insert_after(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_store_insert_before(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_store_insert_with_valuesv(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_list_store_iter_is_valid(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_store_move_after(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_list_store_move_before(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_list_store_prepend(SEXP s1);
extern SEXP R_gtk_list_store_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_store_reorder(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_store_set_column_types(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_list_store_set_value(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_list_store_set_valuesv(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_list_store_swap(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_list_view_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_view_get_enable_rubberband(SEXP s1);
extern SEXP R_gtk_list_view_get_factory(SEXP s1);
extern SEXP R_gtk_list_view_get_header_factory(SEXP s1);
extern SEXP R_gtk_list_view_get_model(SEXP s1);
extern SEXP R_gtk_list_view_get_show_separators(SEXP s1);
extern SEXP R_gtk_list_view_get_single_click_activate(SEXP s1);
extern SEXP R_gtk_list_view_get_tab_behavior(SEXP s1);
extern SEXP R_gtk_list_view_scroll_to(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_list_view_set_enable_rubberband(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_view_set_factory(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_view_set_header_factory(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_view_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_view_set_show_separators(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_view_set_single_click_activate(SEXP s1, SEXP s2);
extern SEXP R_gtk_list_view_set_tab_behavior(SEXP s1, SEXP s2);
extern SEXP R_gtk_lock_button_new(SEXP s1);
extern SEXP R_gtk_lock_button_get_permission(SEXP s1);
extern SEXP R_gtk_lock_button_set_permission(SEXP s1, SEXP s2);
extern SEXP R_gtk_map_list_model_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_map_list_model_get_model(SEXP s1);
extern SEXP R_gtk_map_list_model_has_map(SEXP s1);
extern SEXP R_gtk_map_list_model_set_map_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_map_list_model_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_controls_new(SEXP s1);
extern SEXP R_gtk_media_controls_get_media_stream(SEXP s1);
extern SEXP R_gtk_media_controls_set_media_stream(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_file_new(void);
extern SEXP R_gtk_media_file_new_for_file(SEXP s1);
extern SEXP R_gtk_media_file_new_for_filename(SEXP s1);
extern SEXP R_gtk_media_file_new_for_input_stream(SEXP s1);
extern SEXP R_gtk_media_file_new_for_resource(SEXP s1);
extern SEXP R_gtk_media_file_clear(SEXP s1);
extern SEXP R_gtk_media_file_get_file(SEXP s1);
extern SEXP R_gtk_media_file_get_input_stream(SEXP s1);
extern SEXP R_gtk_media_file_set_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_file_set_filename(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_file_set_input_stream(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_file_set_resource(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_stream_gerror(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_stream_get_duration(SEXP s1);
extern SEXP R_gtk_media_stream_get_ended(SEXP s1);
extern SEXP R_gtk_media_stream_get_error(SEXP s1);
extern SEXP R_gtk_media_stream_get_loop(SEXP s1);
extern SEXP R_gtk_media_stream_get_muted(SEXP s1);
extern SEXP R_gtk_media_stream_get_playing(SEXP s1);
extern SEXP R_gtk_media_stream_get_timestamp(SEXP s1);
extern SEXP R_gtk_media_stream_get_volume(SEXP s1);
extern SEXP R_gtk_media_stream_has_audio(SEXP s1);
extern SEXP R_gtk_media_stream_has_video(SEXP s1);
extern SEXP R_gtk_media_stream_is_prepared(SEXP s1);
extern SEXP R_gtk_media_stream_is_seekable(SEXP s1);
extern SEXP R_gtk_media_stream_is_seeking(SEXP s1);
extern SEXP R_gtk_media_stream_pause(SEXP s1);
extern SEXP R_gtk_media_stream_play(SEXP s1);
extern SEXP R_gtk_media_stream_realize(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_stream_seek(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_stream_seek_failed(SEXP s1);
extern SEXP R_gtk_media_stream_seek_success(SEXP s1);
extern SEXP R_gtk_media_stream_set_loop(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_stream_set_muted(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_stream_set_playing(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_stream_set_volume(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_stream_stream_ended(SEXP s1);
extern SEXP R_gtk_media_stream_stream_prepared(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_media_stream_stream_unprepared(SEXP s1);
extern SEXP R_gtk_media_stream_unrealize(SEXP s1, SEXP s2);
extern SEXP R_gtk_media_stream_update(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_new(void);
extern SEXP R_gtk_menu_button_get_active(SEXP s1);
extern SEXP R_gtk_menu_button_get_always_show_arrow(SEXP s1);
extern SEXP R_gtk_menu_button_get_can_shrink(SEXP s1);
extern SEXP R_gtk_menu_button_get_child(SEXP s1);
extern SEXP R_gtk_menu_button_get_direction(SEXP s1);
extern SEXP R_gtk_menu_button_get_has_frame(SEXP s1);
extern SEXP R_gtk_menu_button_get_icon_name(SEXP s1);
extern SEXP R_gtk_menu_button_get_label(SEXP s1);
extern SEXP R_gtk_menu_button_get_menu_model(SEXP s1);
extern SEXP R_gtk_menu_button_get_popover(SEXP s1);
extern SEXP R_gtk_menu_button_get_primary(SEXP s1);
extern SEXP R_gtk_menu_button_get_use_underline(SEXP s1);
extern SEXP R_gtk_menu_button_popdown(SEXP s1);
extern SEXP R_gtk_menu_button_popup(SEXP s1);
extern SEXP R_gtk_menu_button_set_active(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_set_always_show_arrow(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_set_can_shrink(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_set_create_popup_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_menu_button_set_direction(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_set_has_frame(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_set_icon_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_set_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_set_menu_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_set_popover(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_set_primary(SEXP s1, SEXP s2);
extern SEXP R_gtk_menu_button_set_use_underline(SEXP s1, SEXP s2);
extern SEXP R_gtk_message_dialog_get_message_area(SEXP s1);
extern SEXP R_gtk_message_dialog_set_markup(SEXP s1, SEXP s2);
extern SEXP R_gtk_mnemonic_action_get(void);
extern SEXP R_gtk_mnemonic_trigger_new(SEXP s1);
extern SEXP R_gtk_mnemonic_trigger_get_keyval(SEXP s1);
extern SEXP R_gtk_mount_operation_new(SEXP s1);
extern SEXP R_gtk_mount_operation_get_display(SEXP s1);
extern SEXP R_gtk_mount_operation_get_parent(SEXP s1);
extern SEXP R_gtk_mount_operation_is_showing(SEXP s1);
extern SEXP R_gtk_mount_operation_set_display(SEXP s1, SEXP s2);
extern SEXP R_gtk_mount_operation_set_parent(SEXP s1, SEXP s2);
extern SEXP R_gtk_multi_filter_append(SEXP s1, SEXP s2);
extern SEXP R_gtk_multi_filter_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_multi_selection_new(SEXP s1);
extern SEXP R_gtk_multi_selection_get_model(SEXP s1);
extern SEXP R_gtk_multi_selection_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_multi_sorter_new(void);
extern SEXP R_gtk_multi_sorter_append(SEXP s1, SEXP s2);
extern SEXP R_gtk_multi_sorter_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_named_action_new(SEXP s1);
extern SEXP R_gtk_named_action_get_action_name(SEXP s1);
extern SEXP R_gtk_native_get_for_surface(SEXP s1);
extern SEXP R_gtk_native_get_renderer(SEXP s1);
extern SEXP R_gtk_native_get_surface(SEXP s1);
extern SEXP R_gtk_native_get_surface_transform(SEXP s1);
extern SEXP R_gtk_native_realize(SEXP s1);
extern SEXP R_gtk_native_unrealize(SEXP s1);
extern SEXP R_gtk_native_dialog_destroy(SEXP s1);
extern SEXP R_gtk_native_dialog_get_modal(SEXP s1);
extern SEXP R_gtk_native_dialog_get_title(SEXP s1);
extern SEXP R_gtk_native_dialog_get_transient_for(SEXP s1);
extern SEXP R_gtk_native_dialog_get_visible(SEXP s1);
extern SEXP R_gtk_native_dialog_hide(SEXP s1);
extern SEXP R_gtk_native_dialog_set_modal(SEXP s1, SEXP s2);
extern SEXP R_gtk_native_dialog_set_title(SEXP s1, SEXP s2);
extern SEXP R_gtk_native_dialog_set_transient_for(SEXP s1, SEXP s2);
extern SEXP R_gtk_native_dialog_show(SEXP s1);
extern SEXP R_gtk_never_trigger_get(void);
extern SEXP R_gtk_no_selection_new(SEXP s1);
extern SEXP R_gtk_no_selection_get_model(SEXP s1);
extern SEXP R_gtk_no_selection_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_new(void);
extern SEXP R_gtk_notebook_append_page(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_notebook_append_page_menu(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_notebook_detach_tab(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_get_action_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_get_current_page(SEXP s1);
extern SEXP R_gtk_notebook_get_group_name(SEXP s1);
extern SEXP R_gtk_notebook_get_menu_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_get_menu_label_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_get_n_pages(SEXP s1);
extern SEXP R_gtk_notebook_get_nth_page(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_get_page(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_get_pages(SEXP s1);
extern SEXP R_gtk_notebook_get_scrollable(SEXP s1);
extern SEXP R_gtk_notebook_get_show_border(SEXP s1);
extern SEXP R_gtk_notebook_get_show_tabs(SEXP s1);
extern SEXP R_gtk_notebook_get_tab_detachable(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_get_tab_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_get_tab_label_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_get_tab_pos(SEXP s1);
extern SEXP R_gtk_notebook_get_tab_reorderable(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_insert_page(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_notebook_insert_page_menu(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_notebook_next_page(SEXP s1);
extern SEXP R_gtk_notebook_page_num(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_popup_disable(SEXP s1);
extern SEXP R_gtk_notebook_popup_enable(SEXP s1);
extern SEXP R_gtk_notebook_prepend_page(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_notebook_prepend_page_menu(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_notebook_prev_page(SEXP s1);
extern SEXP R_gtk_notebook_remove_page(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_reorder_child(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_notebook_set_action_widget(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_notebook_set_current_page(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_set_group_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_set_menu_label(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_notebook_set_menu_label_text(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_notebook_set_scrollable(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_set_show_border(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_set_show_tabs(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_set_tab_detachable(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_notebook_set_tab_label(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_notebook_set_tab_label_text(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_notebook_set_tab_pos(SEXP s1, SEXP s2);
extern SEXP R_gtk_notebook_set_tab_reorderable(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_notebook_page_get_child(SEXP s1);
extern SEXP R_gtk_nothing_action_get(void);
extern SEXP R_gtk_numeric_sorter_new(SEXP s1);
extern SEXP R_gtk_numeric_sorter_get_expression(SEXP s1);
extern SEXP R_gtk_numeric_sorter_get_sort_order(SEXP s1);
extern SEXP R_gtk_numeric_sorter_set_expression(SEXP s1, SEXP s2);
extern SEXP R_gtk_numeric_sorter_set_sort_order(SEXP s1, SEXP s2);
extern SEXP R_gtk_object_expression_new(SEXP s1);
extern SEXP R_gtk_object_expression_get_object(SEXP s1);
extern SEXP R_gtk_orientable_get_orientation(SEXP s1);
extern SEXP R_gtk_orientable_set_orientation(SEXP s1, SEXP s2);
extern SEXP R_gtk_overlay_new(void);
extern SEXP R_gtk_overlay_add_overlay(SEXP s1, SEXP s2);
extern SEXP R_gtk_overlay_get_child(SEXP s1);
extern SEXP R_gtk_overlay_get_clip_overlay(SEXP s1, SEXP s2);
extern SEXP R_gtk_overlay_get_measure_overlay(SEXP s1, SEXP s2);
extern SEXP R_gtk_overlay_remove_overlay(SEXP s1, SEXP s2);
extern SEXP R_gtk_overlay_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_overlay_set_clip_overlay(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_overlay_set_measure_overlay(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_overlay_layout_new(void);
extern SEXP R_gtk_overlay_layout_child_get_clip_overlay(SEXP s1);
extern SEXP R_gtk_overlay_layout_child_get_measure(SEXP s1);
extern SEXP R_gtk_overlay_layout_child_set_clip_overlay(SEXP s1, SEXP s2);
extern SEXP R_gtk_overlay_layout_child_set_measure(SEXP s1, SEXP s2);
extern SEXP R_gtk_pad_controller_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_pad_controller_set_action(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_pad_controller_set_action_entries(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_paned_new(SEXP s1);
extern SEXP R_gtk_paned_get_end_child(SEXP s1);
extern SEXP R_gtk_paned_get_position(SEXP s1);
extern SEXP R_gtk_paned_get_resize_end_child(SEXP s1);
extern SEXP R_gtk_paned_get_resize_start_child(SEXP s1);
extern SEXP R_gtk_paned_get_shrink_end_child(SEXP s1);
extern SEXP R_gtk_paned_get_shrink_start_child(SEXP s1);
extern SEXP R_gtk_paned_get_start_child(SEXP s1);
extern SEXP R_gtk_paned_get_wide_handle(SEXP s1);
extern SEXP R_gtk_paned_set_end_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_paned_set_position(SEXP s1, SEXP s2);
extern SEXP R_gtk_paned_set_resize_end_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_paned_set_resize_start_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_paned_set_shrink_end_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_paned_set_shrink_start_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_paned_set_start_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_paned_set_wide_handle(SEXP s1, SEXP s2);
extern SEXP R_gtk_paper_size_new(SEXP s1);
extern SEXP R_gtk_paper_size_new_custom(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_paper_size_new_from_gvariant(SEXP s1);
extern SEXP R_gtk_paper_size_new_from_ipp(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_paper_size_new_from_key_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_paper_size_new_from_ppd(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_paper_size_copy(SEXP s1);
extern SEXP R_gtk_paper_size_free(SEXP s1);
extern SEXP R_gtk_paper_size_get_default_bottom_margin(SEXP s1, SEXP s2);
extern SEXP R_gtk_paper_size_get_default_left_margin(SEXP s1, SEXP s2);
extern SEXP R_gtk_paper_size_get_default_right_margin(SEXP s1, SEXP s2);
extern SEXP R_gtk_paper_size_get_default_top_margin(SEXP s1, SEXP s2);
extern SEXP R_gtk_paper_size_get_display_name(SEXP s1);
extern SEXP R_gtk_paper_size_get_height(SEXP s1, SEXP s2);
extern SEXP R_gtk_paper_size_get_name(SEXP s1);
extern SEXP R_gtk_paper_size_get_ppd_name(SEXP s1);
extern SEXP R_gtk_paper_size_get_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_paper_size_is_custom(SEXP s1);
extern SEXP R_gtk_paper_size_is_equal(SEXP s1, SEXP s2);
extern SEXP R_gtk_paper_size_is_ipp(SEXP s1);
extern SEXP R_gtk_paper_size_set_size(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_paper_size_to_gvariant(SEXP s1);
extern SEXP R_gtk_paper_size_to_key_file(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_paper_size_get_default(void);
extern SEXP R_gtk_paper_size_get_paper_sizes(SEXP s1);
extern SEXP R_gtk_password_entry_new(void);
extern SEXP R_gtk_password_entry_get_extra_menu(SEXP s1);
extern SEXP R_gtk_password_entry_get_show_peek_icon(SEXP s1);
extern SEXP R_gtk_password_entry_set_extra_menu(SEXP s1, SEXP s2);
extern SEXP R_gtk_password_entry_set_show_peek_icon(SEXP s1, SEXP s2);
extern SEXP R_gtk_password_entry_buffer_new(void);
extern SEXP R_gtk_picture_new(void);
extern SEXP R_gtk_picture_new_for_file(SEXP s1);
extern SEXP R_gtk_picture_new_for_filename(SEXP s1);
extern SEXP R_gtk_picture_new_for_paintable(SEXP s1);
extern SEXP R_gtk_picture_new_for_pixbuf(SEXP s1);
extern SEXP R_gtk_picture_new_for_resource(SEXP s1);
extern SEXP R_gtk_picture_get_alternative_text(SEXP s1);
extern SEXP R_gtk_picture_get_can_shrink(SEXP s1);
extern SEXP R_gtk_picture_get_content_fit(SEXP s1);
extern SEXP R_gtk_picture_get_file(SEXP s1);
extern SEXP R_gtk_picture_get_keep_aspect_ratio(SEXP s1);
extern SEXP R_gtk_picture_get_paintable(SEXP s1);
extern SEXP R_gtk_picture_set_alternative_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_picture_set_can_shrink(SEXP s1, SEXP s2);
extern SEXP R_gtk_picture_set_content_fit(SEXP s1, SEXP s2);
extern SEXP R_gtk_picture_set_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_picture_set_filename(SEXP s1, SEXP s2);
extern SEXP R_gtk_picture_set_keep_aspect_ratio(SEXP s1, SEXP s2);
extern SEXP R_gtk_picture_set_paintable(SEXP s1, SEXP s2);
extern SEXP R_gtk_picture_set_pixbuf(SEXP s1, SEXP s2);
extern SEXP R_gtk_picture_set_resource(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_new(void);
extern SEXP R_gtk_popover_get_autohide(SEXP s1);
extern SEXP R_gtk_popover_get_cascade_popdown(SEXP s1);
extern SEXP R_gtk_popover_get_child(SEXP s1);
extern SEXP R_gtk_popover_get_has_arrow(SEXP s1);
extern SEXP R_gtk_popover_get_mnemonics_visible(SEXP s1);
extern SEXP R_gtk_popover_get_offset(SEXP s1);
extern SEXP R_gtk_popover_get_pointing_to(SEXP s1);
extern SEXP R_gtk_popover_get_position(SEXP s1);
extern SEXP R_gtk_popover_popdown(SEXP s1);
extern SEXP R_gtk_popover_popup(SEXP s1);
extern SEXP R_gtk_popover_present(SEXP s1);
extern SEXP R_gtk_popover_set_autohide(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_set_cascade_popdown(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_set_default_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_set_has_arrow(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_set_mnemonics_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_set_offset(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_popover_set_pointing_to(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_set_position(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_menu_new_from_model(SEXP s1);
extern SEXP R_gtk_popover_menu_new_from_model_full(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_menu_add_child(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_popover_menu_get_menu_model(SEXP s1);
extern SEXP R_gtk_popover_menu_remove_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_menu_set_menu_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_menu_bar_new_from_model(SEXP s1);
extern SEXP R_gtk_popover_menu_bar_add_child(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_popover_menu_bar_get_menu_model(SEXP s1);
extern SEXP R_gtk_popover_menu_bar_remove_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_popover_menu_bar_set_menu_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_progress_bar_new(void);
extern SEXP R_gtk_progress_bar_get_ellipsize(SEXP s1);
extern SEXP R_gtk_progress_bar_get_fraction(SEXP s1);
extern SEXP R_gtk_progress_bar_get_inverted(SEXP s1);
extern SEXP R_gtk_progress_bar_get_pulse_step(SEXP s1);
extern SEXP R_gtk_progress_bar_get_show_text(SEXP s1);
extern SEXP R_gtk_progress_bar_get_text(SEXP s1);
extern SEXP R_gtk_progress_bar_pulse(SEXP s1);
extern SEXP R_gtk_progress_bar_set_ellipsize(SEXP s1, SEXP s2);
extern SEXP R_gtk_progress_bar_set_fraction(SEXP s1, SEXP s2);
extern SEXP R_gtk_progress_bar_set_inverted(SEXP s1, SEXP s2);
extern SEXP R_gtk_progress_bar_set_pulse_step(SEXP s1, SEXP s2);
extern SEXP R_gtk_progress_bar_set_show_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_progress_bar_set_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_property_expression_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_property_expression_new_for_pspec(SEXP s1, SEXP s2);
extern SEXP R_gtk_property_expression_get_expression(SEXP s1);
extern SEXP R_gtk_property_expression_get_pspec(SEXP s1);
extern SEXP R_gtk_range_get_adjustment(SEXP s1);
extern SEXP R_gtk_range_get_fill_level(SEXP s1);
extern SEXP R_gtk_range_get_flippable(SEXP s1);
extern SEXP R_gtk_range_get_inverted(SEXP s1);
extern SEXP R_gtk_range_get_range_rect(SEXP s1);
extern SEXP R_gtk_range_get_restrict_to_fill_level(SEXP s1);
extern SEXP R_gtk_range_get_round_digits(SEXP s1);
extern SEXP R_gtk_range_get_show_fill_level(SEXP s1);
extern SEXP R_gtk_range_get_slider_range(SEXP s1);
extern SEXP R_gtk_range_get_slider_size_fixed(SEXP s1);
extern SEXP R_gtk_range_get_value(SEXP s1);
extern SEXP R_gtk_range_set_adjustment(SEXP s1, SEXP s2);
extern SEXP R_gtk_range_set_fill_level(SEXP s1, SEXP s2);
extern SEXP R_gtk_range_set_flippable(SEXP s1, SEXP s2);
extern SEXP R_gtk_range_set_increments(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_range_set_inverted(SEXP s1, SEXP s2);
extern SEXP R_gtk_range_set_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_range_set_restrict_to_fill_level(SEXP s1, SEXP s2);
extern SEXP R_gtk_range_set_round_digits(SEXP s1, SEXP s2);
extern SEXP R_gtk_range_set_show_fill_level(SEXP s1, SEXP s2);
extern SEXP R_gtk_range_set_slider_size_fixed(SEXP s1, SEXP s2);
extern SEXP R_gtk_range_set_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_recent_info_create_app_info(SEXP s1, SEXP s2);
extern SEXP R_gtk_recent_info_exists(SEXP s1);
extern SEXP R_gtk_recent_info_get_added(SEXP s1);
extern SEXP R_gtk_recent_info_get_age(SEXP s1);
extern SEXP R_gtk_recent_info_get_application_info(SEXP s1, SEXP s2);
extern SEXP R_gtk_recent_info_get_applications(SEXP s1);
extern SEXP R_gtk_recent_info_get_description(SEXP s1);
extern SEXP R_gtk_recent_info_get_display_name(SEXP s1);
extern SEXP R_gtk_recent_info_get_gicon(SEXP s1);
extern SEXP R_gtk_recent_info_get_groups(SEXP s1);
extern SEXP R_gtk_recent_info_get_mime_type(SEXP s1);
extern SEXP R_gtk_recent_info_get_modified(SEXP s1);
extern SEXP R_gtk_recent_info_get_private_hint(SEXP s1);
extern SEXP R_gtk_recent_info_get_short_name(SEXP s1);
extern SEXP R_gtk_recent_info_get_uri(SEXP s1);
extern SEXP R_gtk_recent_info_get_uri_display(SEXP s1);
extern SEXP R_gtk_recent_info_get_visited(SEXP s1);
extern SEXP R_gtk_recent_info_has_application(SEXP s1, SEXP s2);
extern SEXP R_gtk_recent_info_has_group(SEXP s1, SEXP s2);
extern SEXP R_gtk_recent_info_is_local(SEXP s1);
extern SEXP R_gtk_recent_info_last_application(SEXP s1);
extern SEXP R_gtk_recent_info_match(SEXP s1, SEXP s2);
extern SEXP R_gtk_recent_info_ref(SEXP s1);
extern SEXP R_gtk_recent_info_unref(SEXP s1);
extern SEXP R_gtk_recent_manager_new(void);
extern SEXP R_gtk_recent_manager_get_default(void);
extern SEXP R_gtk_recent_manager_add_full(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_recent_manager_add_item(SEXP s1, SEXP s2);
extern SEXP R_gtk_recent_manager_get_items(SEXP s1);
extern SEXP R_gtk_recent_manager_has_item(SEXP s1, SEXP s2);
extern SEXP R_gtk_recent_manager_lookup_item(SEXP s1, SEXP s2);
extern SEXP R_gtk_recent_manager_move_item(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_recent_manager_purge_items(SEXP s1);
extern SEXP R_gtk_recent_manager_remove_item(SEXP s1, SEXP s2);
extern SEXP R_gtk_recent_manager_error_quark(void);
extern SEXP R_gtk_requisition_new(void);
extern SEXP R_gtk_requisition_copy(SEXP s1);
extern SEXP R_gtk_requisition_free(SEXP s1);
extern SEXP R_gtk_revealer_new(void);
extern SEXP R_gtk_revealer_get_child(SEXP s1);
extern SEXP R_gtk_revealer_get_child_revealed(SEXP s1);
extern SEXP R_gtk_revealer_get_reveal_child(SEXP s1);
extern SEXP R_gtk_revealer_get_transition_duration(SEXP s1);
extern SEXP R_gtk_revealer_get_transition_type(SEXP s1);
extern SEXP R_gtk_revealer_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_revealer_set_reveal_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_revealer_set_transition_duration(SEXP s1, SEXP s2);
extern SEXP R_gtk_revealer_set_transition_type(SEXP s1, SEXP s2);
extern SEXP R_gtk_root_get_display(SEXP s1);
extern SEXP R_gtk_root_get_focus(SEXP s1);
extern SEXP R_gtk_root_set_focus(SEXP s1, SEXP s2);
extern SEXP R_gtk_scale_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_scale_new_with_range(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_scale_add_mark(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_scale_clear_marks(SEXP s1);
extern SEXP R_gtk_scale_get_digits(SEXP s1);
extern SEXP R_gtk_scale_get_draw_value(SEXP s1);
extern SEXP R_gtk_scale_get_has_origin(SEXP s1);
extern SEXP R_gtk_scale_get_layout(SEXP s1);
extern SEXP R_gtk_scale_get_layout_offsets(SEXP s1);
extern SEXP R_gtk_scale_get_value_pos(SEXP s1);
extern SEXP R_gtk_scale_set_digits(SEXP s1, SEXP s2);
extern SEXP R_gtk_scale_set_draw_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_scale_set_format_value_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_scale_set_has_origin(SEXP s1, SEXP s2);
extern SEXP R_gtk_scale_set_value_pos(SEXP s1, SEXP s2);
extern SEXP R_gtk_scale_button_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_scale_button_get_active(SEXP s1);
extern SEXP R_gtk_scale_button_get_adjustment(SEXP s1);
extern SEXP R_gtk_scale_button_get_minus_button(SEXP s1);
extern SEXP R_gtk_scale_button_get_plus_button(SEXP s1);
extern SEXP R_gtk_scale_button_get_popup(SEXP s1);
extern SEXP R_gtk_scale_button_get_value(SEXP s1);
extern SEXP R_gtk_scale_button_set_adjustment(SEXP s1, SEXP s2);
extern SEXP R_gtk_scale_button_set_icons(SEXP s1, SEXP s2);
extern SEXP R_gtk_scale_button_set_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_scroll_info_new(void);
extern SEXP R_gtk_scroll_info_get_enable_horizontal(SEXP s1);
extern SEXP R_gtk_scroll_info_get_enable_vertical(SEXP s1);
extern SEXP R_gtk_scroll_info_ref(SEXP s1);
extern SEXP R_gtk_scroll_info_set_enable_horizontal(SEXP s1, SEXP s2);
extern SEXP R_gtk_scroll_info_set_enable_vertical(SEXP s1, SEXP s2);
extern SEXP R_gtk_scroll_info_unref(SEXP s1);
extern SEXP R_gtk_scrollable_get_border(SEXP s1);
extern SEXP R_gtk_scrollable_get_hadjustment(SEXP s1);
extern SEXP R_gtk_scrollable_get_hscroll_policy(SEXP s1);
extern SEXP R_gtk_scrollable_get_vadjustment(SEXP s1);
extern SEXP R_gtk_scrollable_get_vscroll_policy(SEXP s1);
extern SEXP R_gtk_scrollable_set_hadjustment(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrollable_set_hscroll_policy(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrollable_set_vadjustment(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrollable_set_vscroll_policy(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrollbar_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrollbar_get_adjustment(SEXP s1);
extern SEXP R_gtk_scrollbar_set_adjustment(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_new(void);
extern SEXP R_gtk_scrolled_window_get_child(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_hadjustment(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_has_frame(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_hscrollbar(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_kinetic_scrolling(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_max_content_height(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_max_content_width(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_min_content_height(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_min_content_width(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_overlay_scrolling(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_placement(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_policy(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_propagate_natural_height(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_propagate_natural_width(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_vadjustment(SEXP s1);
extern SEXP R_gtk_scrolled_window_get_vscrollbar(SEXP s1);
extern SEXP R_gtk_scrolled_window_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_hadjustment(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_has_frame(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_kinetic_scrolling(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_max_content_height(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_max_content_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_min_content_height(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_min_content_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_overlay_scrolling(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_placement(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_policy(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_scrolled_window_set_propagate_natural_height(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_propagate_natural_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_set_vadjustment(SEXP s1, SEXP s2);
extern SEXP R_gtk_scrolled_window_unset_placement(SEXP s1);
extern SEXP R_gtk_search_bar_new(void);
extern SEXP R_gtk_search_bar_connect_entry(SEXP s1, SEXP s2);
extern SEXP R_gtk_search_bar_get_child(SEXP s1);
extern SEXP R_gtk_search_bar_get_key_capture_widget(SEXP s1);
extern SEXP R_gtk_search_bar_get_search_mode(SEXP s1);
extern SEXP R_gtk_search_bar_get_show_close_button(SEXP s1);
extern SEXP R_gtk_search_bar_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_search_bar_set_key_capture_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_search_bar_set_search_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_search_bar_set_show_close_button(SEXP s1, SEXP s2);
extern SEXP R_gtk_search_entry_new(void);
extern SEXP R_gtk_search_entry_get_key_capture_widget(SEXP s1);
extern SEXP R_gtk_search_entry_get_placeholder_text(SEXP s1);
extern SEXP R_gtk_search_entry_get_search_delay(SEXP s1);
extern SEXP R_gtk_search_entry_set_key_capture_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_search_entry_set_placeholder_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_search_entry_set_search_delay(SEXP s1, SEXP s2);
extern SEXP R_gtk_section_model_get_section(SEXP s1, SEXP s2);
extern SEXP R_gtk_section_model_sections_changed(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_selection_filter_model_new(SEXP s1);
extern SEXP R_gtk_selection_filter_model_get_model(SEXP s1);
extern SEXP R_gtk_selection_filter_model_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_selection_model_get_selection(SEXP s1);
extern SEXP R_gtk_selection_model_get_selection_in_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_selection_model_is_selected(SEXP s1, SEXP s2);
extern SEXP R_gtk_selection_model_select_all(SEXP s1);
extern SEXP R_gtk_selection_model_select_item(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_selection_model_select_range(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_selection_model_selection_changed(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_selection_model_set_selection(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_selection_model_unselect_all(SEXP s1);
extern SEXP R_gtk_selection_model_unselect_item(SEXP s1, SEXP s2);
extern SEXP R_gtk_selection_model_unselect_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_separator_new(SEXP s1);
extern SEXP R_gtk_settings_get_default(void);
extern SEXP R_gtk_settings_get_for_display(SEXP s1);
extern SEXP R_gtk_settings_reset_property(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_get_action(SEXP s1);
extern SEXP R_gtk_shortcut_get_arguments(SEXP s1);
extern SEXP R_gtk_shortcut_get_trigger(SEXP s1);
extern SEXP R_gtk_shortcut_set_action(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_set_arguments(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_set_trigger(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_action_parse_string(SEXP s1);
extern SEXP R_gtk_shortcut_action_activate(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_shortcut_action_print(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_action_to_string(SEXP s1);
extern SEXP R_gtk_shortcut_controller_new(void);
extern SEXP R_gtk_shortcut_controller_new_for_model(SEXP s1);
extern SEXP R_gtk_shortcut_controller_add_shortcut(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_controller_get_mnemonics_modifiers(SEXP s1);
extern SEXP R_gtk_shortcut_controller_get_scope(SEXP s1);
extern SEXP R_gtk_shortcut_controller_remove_shortcut(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_controller_set_mnemonics_modifiers(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_controller_set_scope(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_label_new(SEXP s1);
extern SEXP R_gtk_shortcut_label_get_accelerator(SEXP s1);
extern SEXP R_gtk_shortcut_label_get_disabled_text(SEXP s1);
extern SEXP R_gtk_shortcut_label_set_accelerator(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_label_set_disabled_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_trigger_parse_string(SEXP s1);
extern SEXP R_gtk_shortcut_trigger_compare(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_trigger_equal(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_trigger_hash(SEXP s1);
extern SEXP R_gtk_shortcut_trigger_print(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_trigger_print_label(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_shortcut_trigger_to_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_shortcut_trigger_to_string(SEXP s1);
extern SEXP R_gtk_shortcut_trigger_trigger(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_signal_action_new(SEXP s1);
extern SEXP R_gtk_signal_action_get_signal_name(SEXP s1);
extern SEXP R_gtk_signal_list_item_factory_new(void);
extern SEXP R_gtk_single_selection_new(SEXP s1);
extern SEXP R_gtk_single_selection_get_autoselect(SEXP s1);
extern SEXP R_gtk_single_selection_get_can_unselect(SEXP s1);
extern SEXP R_gtk_single_selection_get_model(SEXP s1);
extern SEXP R_gtk_single_selection_get_selected(SEXP s1);
extern SEXP R_gtk_single_selection_get_selected_item(SEXP s1);
extern SEXP R_gtk_single_selection_set_autoselect(SEXP s1, SEXP s2);
extern SEXP R_gtk_single_selection_set_can_unselect(SEXP s1, SEXP s2);
extern SEXP R_gtk_single_selection_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_single_selection_set_selected(SEXP s1, SEXP s2);
extern SEXP R_gtk_size_group_new(SEXP s1);
extern SEXP R_gtk_size_group_add_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_size_group_get_mode(SEXP s1);
extern SEXP R_gtk_size_group_get_widgets(SEXP s1);
extern SEXP R_gtk_size_group_remove_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_size_group_set_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_slice_list_model_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_slice_list_model_get_model(SEXP s1);
extern SEXP R_gtk_slice_list_model_get_offset(SEXP s1);
extern SEXP R_gtk_slice_list_model_get_size(SEXP s1);
extern SEXP R_gtk_slice_list_model_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_slice_list_model_set_offset(SEXP s1, SEXP s2);
extern SEXP R_gtk_slice_list_model_set_size(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_new(void);
extern SEXP R_gtk_snapshot_append_border(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_snapshot_append_cairo(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_append_color(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_snapshot_append_conic_gradient(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_snapshot_append_inset_shadow(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gtk_snapshot_append_layout(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_snapshot_append_linear_gradient(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_snapshot_append_node(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_append_outset_shadow(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gtk_snapshot_append_radial_gradient(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8, SEXP s9);
extern SEXP R_gtk_snapshot_append_repeating_linear_gradient(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_snapshot_append_repeating_radial_gradient(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8, SEXP s9);
extern SEXP R_gtk_snapshot_append_scaled_texture(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_snapshot_append_texture(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_snapshot_gl_shader_pop_texture(SEXP s1);
extern SEXP R_gtk_snapshot_perspective(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_pop(SEXP s1);
extern SEXP R_gtk_snapshot_push_blend(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_push_blur(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_push_clip(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_push_color_matrix(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_snapshot_push_cross_fade(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_push_gl_shader(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_snapshot_push_mask(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_push_opacity(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_push_repeat(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_snapshot_push_rounded_clip(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_push_shadow(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_snapshot_render_background(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_snapshot_render_focus(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_snapshot_render_frame(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_snapshot_render_insertion_cursor(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gtk_snapshot_render_layout(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_snapshot_restore(SEXP s1);
extern SEXP R_gtk_snapshot_rotate(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_rotate_3d(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_snapshot_save(SEXP s1);
extern SEXP R_gtk_snapshot_scale(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_snapshot_scale_3d(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_snapshot_to_node(SEXP s1);
extern SEXP R_gtk_snapshot_to_paintable(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_transform(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_transform_matrix(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_translate(SEXP s1, SEXP s2);
extern SEXP R_gtk_snapshot_translate_3d(SEXP s1, SEXP s2);
extern SEXP R_gtk_sort_list_model_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_sort_list_model_get_incremental(SEXP s1);
extern SEXP R_gtk_sort_list_model_get_model(SEXP s1);
extern SEXP R_gtk_sort_list_model_get_pending(SEXP s1);
extern SEXP R_gtk_sort_list_model_get_section_sorter(SEXP s1);
extern SEXP R_gtk_sort_list_model_get_sorter(SEXP s1);
extern SEXP R_gtk_sort_list_model_set_incremental(SEXP s1, SEXP s2);
extern SEXP R_gtk_sort_list_model_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_sort_list_model_set_section_sorter(SEXP s1, SEXP s2);
extern SEXP R_gtk_sort_list_model_set_sorter(SEXP s1, SEXP s2);
extern SEXP R_gtk_sorter_changed(SEXP s1, SEXP s2);
extern SEXP R_gtk_sorter_compare(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_sorter_get_order(SEXP s1);
extern SEXP R_gtk_spin_button_new(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_spin_button_new_with_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_spin_button_configure(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_spin_button_get_adjustment(SEXP s1);
extern SEXP R_gtk_spin_button_get_climb_rate(SEXP s1);
extern SEXP R_gtk_spin_button_get_digits(SEXP s1);
extern SEXP R_gtk_spin_button_get_increments(SEXP s1);
extern SEXP R_gtk_spin_button_get_numeric(SEXP s1);
extern SEXP R_gtk_spin_button_get_range(SEXP s1);
extern SEXP R_gtk_spin_button_get_snap_to_ticks(SEXP s1);
extern SEXP R_gtk_spin_button_get_update_policy(SEXP s1);
extern SEXP R_gtk_spin_button_get_value(SEXP s1);
extern SEXP R_gtk_spin_button_get_value_as_int(SEXP s1);
extern SEXP R_gtk_spin_button_get_wrap(SEXP s1);
extern SEXP R_gtk_spin_button_set_adjustment(SEXP s1, SEXP s2);
extern SEXP R_gtk_spin_button_set_climb_rate(SEXP s1, SEXP s2);
extern SEXP R_gtk_spin_button_set_digits(SEXP s1, SEXP s2);
extern SEXP R_gtk_spin_button_set_increments(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_spin_button_set_numeric(SEXP s1, SEXP s2);
extern SEXP R_gtk_spin_button_set_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_spin_button_set_snap_to_ticks(SEXP s1, SEXP s2);
extern SEXP R_gtk_spin_button_set_update_policy(SEXP s1, SEXP s2);
extern SEXP R_gtk_spin_button_set_value(SEXP s1, SEXP s2);
extern SEXP R_gtk_spin_button_set_wrap(SEXP s1, SEXP s2);
extern SEXP R_gtk_spin_button_spin(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_spin_button_update(SEXP s1);
extern SEXP R_gtk_spinner_new(void);
extern SEXP R_gtk_spinner_get_spinning(SEXP s1);
extern SEXP R_gtk_spinner_set_spinning(SEXP s1, SEXP s2);
extern SEXP R_gtk_spinner_start(SEXP s1);
extern SEXP R_gtk_spinner_stop(SEXP s1);
extern SEXP R_gtk_stack_new(void);
extern SEXP R_gtk_stack_add_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_add_named(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_stack_add_titled(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_stack_get_child_by_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_get_hhomogeneous(SEXP s1);
extern SEXP R_gtk_stack_get_interpolate_size(SEXP s1);
extern SEXP R_gtk_stack_get_page(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_get_pages(SEXP s1);
extern SEXP R_gtk_stack_get_transition_duration(SEXP s1);
extern SEXP R_gtk_stack_get_transition_running(SEXP s1);
extern SEXP R_gtk_stack_get_transition_type(SEXP s1);
extern SEXP R_gtk_stack_get_vhomogeneous(SEXP s1);
extern SEXP R_gtk_stack_get_visible_child(SEXP s1);
extern SEXP R_gtk_stack_get_visible_child_name(SEXP s1);
extern SEXP R_gtk_stack_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_set_hhomogeneous(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_set_interpolate_size(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_set_transition_duration(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_set_transition_type(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_set_vhomogeneous(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_set_visible_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_set_visible_child_full(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_stack_set_visible_child_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_page_get_child(SEXP s1);
extern SEXP R_gtk_stack_page_get_icon_name(SEXP s1);
extern SEXP R_gtk_stack_page_get_name(SEXP s1);
extern SEXP R_gtk_stack_page_get_needs_attention(SEXP s1);
extern SEXP R_gtk_stack_page_get_title(SEXP s1);
extern SEXP R_gtk_stack_page_get_use_underline(SEXP s1);
extern SEXP R_gtk_stack_page_get_visible(SEXP s1);
extern SEXP R_gtk_stack_page_set_icon_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_page_set_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_page_set_needs_attention(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_page_set_title(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_page_set_use_underline(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_page_set_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_sidebar_new(void);
extern SEXP R_gtk_stack_sidebar_get_stack(SEXP s1);
extern SEXP R_gtk_stack_sidebar_set_stack(SEXP s1, SEXP s2);
extern SEXP R_gtk_stack_switcher_new(void);
extern SEXP R_gtk_stack_switcher_get_stack(SEXP s1);
extern SEXP R_gtk_stack_switcher_set_stack(SEXP s1, SEXP s2);
extern SEXP R_gtk_statusbar_new(void);
extern SEXP R_gtk_statusbar_get_context_id(SEXP s1, SEXP s2);
extern SEXP R_gtk_statusbar_pop(SEXP s1, SEXP s2);
extern SEXP R_gtk_statusbar_push(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_statusbar_remove(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_statusbar_remove_all(SEXP s1, SEXP s2);
extern SEXP R_gtk_string_filter_new(SEXP s1);
extern SEXP R_gtk_string_filter_get_expression(SEXP s1);
extern SEXP R_gtk_string_filter_get_ignore_case(SEXP s1);
extern SEXP R_gtk_string_filter_get_match_mode(SEXP s1);
extern SEXP R_gtk_string_filter_get_search(SEXP s1);
extern SEXP R_gtk_string_filter_set_expression(SEXP s1, SEXP s2);
extern SEXP R_gtk_string_filter_set_ignore_case(SEXP s1, SEXP s2);
extern SEXP R_gtk_string_filter_set_match_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_string_filter_set_search(SEXP s1, SEXP s2);
extern SEXP R_gtk_string_list_new(SEXP s1);
extern SEXP R_gtk_string_list_append(SEXP s1, SEXP s2);
extern SEXP R_gtk_string_list_get_string(SEXP s1, SEXP s2);
extern SEXP R_gtk_string_list_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_string_list_splice(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_string_list_take(SEXP s1, SEXP s2);
extern SEXP R_gtk_string_object_new(SEXP s1);
extern SEXP R_gtk_string_object_get_string(SEXP s1);
extern SEXP R_gtk_string_sorter_new(SEXP s1);
extern SEXP R_gtk_string_sorter_get_collation(SEXP s1);
extern SEXP R_gtk_string_sorter_get_expression(SEXP s1);
extern SEXP R_gtk_string_sorter_get_ignore_case(SEXP s1);
extern SEXP R_gtk_string_sorter_set_collation(SEXP s1, SEXP s2);
extern SEXP R_gtk_string_sorter_set_expression(SEXP s1, SEXP s2);
extern SEXP R_gtk_string_sorter_set_ignore_case(SEXP s1, SEXP s2);
extern SEXP R_gtk_style_context_add_provider_for_display(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_style_context_remove_provider_for_display(SEXP s1, SEXP s2);
extern SEXP R_gtk_style_context_add_class(SEXP s1, SEXP s2);
extern SEXP R_gtk_style_context_add_provider(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_style_context_get_border(SEXP s1);
extern SEXP R_gtk_style_context_get_color(SEXP s1);
extern SEXP R_gtk_style_context_get_display(SEXP s1);
extern SEXP R_gtk_style_context_get_margin(SEXP s1);
extern SEXP R_gtk_style_context_get_padding(SEXP s1);
extern SEXP R_gtk_style_context_get_scale(SEXP s1);
extern SEXP R_gtk_style_context_get_state(SEXP s1);
extern SEXP R_gtk_style_context_has_class(SEXP s1, SEXP s2);
extern SEXP R_gtk_style_context_lookup_color(SEXP s1, SEXP s2);
extern SEXP R_gtk_style_context_remove_class(SEXP s1, SEXP s2);
extern SEXP R_gtk_style_context_remove_provider(SEXP s1, SEXP s2);
extern SEXP R_gtk_style_context_restore(SEXP s1);
extern SEXP R_gtk_style_context_save(SEXP s1);
extern SEXP R_gtk_style_context_set_display(SEXP s1, SEXP s2);
extern SEXP R_gtk_style_context_set_scale(SEXP s1, SEXP s2);
extern SEXP R_gtk_style_context_set_state(SEXP s1, SEXP s2);
extern SEXP R_gtk_style_context_to_string(SEXP s1, SEXP s2);
extern SEXP R_gtk_switch_new(void);
extern SEXP R_gtk_switch_get_active(SEXP s1);
extern SEXP R_gtk_switch_get_state(SEXP s1);
extern SEXP R_gtk_switch_set_active(SEXP s1, SEXP s2);
extern SEXP R_gtk_switch_set_state(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_new(void);
extern SEXP R_gtk_text_new_with_buffer(SEXP s1);
extern SEXP R_gtk_text_compute_cursor_extents(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_get_activates_default(SEXP s1);
extern SEXP R_gtk_text_get_attributes(SEXP s1);
extern SEXP R_gtk_text_get_buffer(SEXP s1);
extern SEXP R_gtk_text_get_enable_emoji_completion(SEXP s1);
extern SEXP R_gtk_text_get_extra_menu(SEXP s1);
extern SEXP R_gtk_text_get_input_hints(SEXP s1);
extern SEXP R_gtk_text_get_input_purpose(SEXP s1);
extern SEXP R_gtk_text_get_invisible_char(SEXP s1);
extern SEXP R_gtk_text_get_max_length(SEXP s1);
extern SEXP R_gtk_text_get_overwrite_mode(SEXP s1);
extern SEXP R_gtk_text_get_placeholder_text(SEXP s1);
extern SEXP R_gtk_text_get_propagate_text_width(SEXP s1);
extern SEXP R_gtk_text_get_tabs(SEXP s1);
extern SEXP R_gtk_text_get_text_length(SEXP s1);
extern SEXP R_gtk_text_get_truncate_multiline(SEXP s1);
extern SEXP R_gtk_text_get_visibility(SEXP s1);
extern SEXP R_gtk_text_grab_focus_without_selecting(SEXP s1);
extern SEXP R_gtk_text_set_activates_default(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_attributes(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_buffer(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_enable_emoji_completion(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_extra_menu(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_input_hints(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_input_purpose(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_invisible_char(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_max_length(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_overwrite_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_placeholder_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_propagate_text_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_tabs(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_truncate_multiline(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_set_visibility(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_unset_invisible_char(SEXP s1);
extern SEXP R_gtk_text_buffer_new(SEXP s1);
extern SEXP R_gtk_text_buffer_add_mark(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_add_selection_clipboard(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_apply_tag(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_apply_tag_by_name(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_backspace(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_begin_irreversible_action(SEXP s1);
extern SEXP R_gtk_text_buffer_begin_user_action(SEXP s1);
extern SEXP R_gtk_text_buffer_copy_clipboard(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_create_child_anchor(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_create_mark(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_cut_clipboard(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_delete(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_delete_interactive(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_delete_mark(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_delete_mark_by_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_delete_selection(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_end_irreversible_action(SEXP s1);
extern SEXP R_gtk_text_buffer_end_user_action(SEXP s1);
extern SEXP R_gtk_text_buffer_get_bounds(SEXP s1);
extern SEXP R_gtk_text_buffer_get_can_redo(SEXP s1);
extern SEXP R_gtk_text_buffer_get_can_undo(SEXP s1);
extern SEXP R_gtk_text_buffer_get_char_count(SEXP s1);
extern SEXP R_gtk_text_buffer_get_enable_undo(SEXP s1);
extern SEXP R_gtk_text_buffer_get_end_iter(SEXP s1);
extern SEXP R_gtk_text_buffer_get_has_selection(SEXP s1);
extern SEXP R_gtk_text_buffer_get_insert(SEXP s1);
extern SEXP R_gtk_text_buffer_get_iter_at_child_anchor(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_get_iter_at_line(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_get_iter_at_line_index(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_get_iter_at_line_offset(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_get_iter_at_mark(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_get_iter_at_offset(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_get_line_count(SEXP s1);
extern SEXP R_gtk_text_buffer_get_mark(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_get_max_undo_levels(SEXP s1);
extern SEXP R_gtk_text_buffer_get_modified(SEXP s1);
extern SEXP R_gtk_text_buffer_get_selection_bound(SEXP s1);
extern SEXP R_gtk_text_buffer_get_selection_bounds(SEXP s1);
extern SEXP R_gtk_text_buffer_get_selection_content(SEXP s1);
extern SEXP R_gtk_text_buffer_get_slice(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_get_start_iter(SEXP s1);
extern SEXP R_gtk_text_buffer_get_tag_table(SEXP s1);
extern SEXP R_gtk_text_buffer_get_text(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_insert(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_insert_at_cursor(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_insert_child_anchor(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_insert_interactive(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_text_buffer_insert_interactive_at_cursor(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_insert_markup(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_insert_paintable(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_insert_range(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_insert_range_interactive(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_text_buffer_move_mark(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_move_mark_by_name(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_paste_clipboard(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_place_cursor(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_redo(SEXP s1);
extern SEXP R_gtk_text_buffer_remove_all_tags(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_remove_selection_clipboard(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_remove_tag(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_remove_tag_by_name(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_buffer_select_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_set_enable_undo(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_set_max_undo_levels(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_set_modified(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_buffer_set_text(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_buffer_undo(SEXP s1);
extern SEXP R_gtk_text_child_anchor_new(void);
extern SEXP R_gtk_text_child_anchor_new_with_replacement(SEXP s1);
extern SEXP R_gtk_text_child_anchor_get_deleted(SEXP s1);
extern SEXP R_gtk_text_child_anchor_get_widgets(SEXP s1);
extern SEXP R_gtk_text_iter_assign(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_backward_char(SEXP s1);
extern SEXP R_gtk_text_iter_backward_chars(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_backward_cursor_position(SEXP s1);
extern SEXP R_gtk_text_iter_backward_cursor_positions(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_backward_find_char(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_iter_backward_line(SEXP s1);
extern SEXP R_gtk_text_iter_backward_lines(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_backward_search(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_iter_backward_sentence_start(SEXP s1);
extern SEXP R_gtk_text_iter_backward_sentence_starts(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_backward_to_tag_toggle(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_backward_visible_cursor_position(SEXP s1);
extern SEXP R_gtk_text_iter_backward_visible_cursor_positions(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_backward_visible_line(SEXP s1);
extern SEXP R_gtk_text_iter_backward_visible_lines(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_backward_visible_word_start(SEXP s1);
extern SEXP R_gtk_text_iter_backward_visible_word_starts(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_backward_word_start(SEXP s1);
extern SEXP R_gtk_text_iter_backward_word_starts(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_can_insert(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_compare(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_copy(SEXP s1);
extern SEXP R_gtk_text_iter_editable(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_ends_line(SEXP s1);
extern SEXP R_gtk_text_iter_ends_sentence(SEXP s1);
extern SEXP R_gtk_text_iter_ends_tag(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_ends_word(SEXP s1);
extern SEXP R_gtk_text_iter_equal(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_forward_char(SEXP s1);
extern SEXP R_gtk_text_iter_forward_chars(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_forward_cursor_position(SEXP s1);
extern SEXP R_gtk_text_iter_forward_cursor_positions(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_forward_find_char(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_iter_forward_line(SEXP s1);
extern SEXP R_gtk_text_iter_forward_lines(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_forward_search(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_iter_forward_sentence_end(SEXP s1);
extern SEXP R_gtk_text_iter_forward_sentence_ends(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_forward_to_end(SEXP s1);
extern SEXP R_gtk_text_iter_forward_to_line_end(SEXP s1);
extern SEXP R_gtk_text_iter_forward_to_tag_toggle(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_forward_visible_cursor_position(SEXP s1);
extern SEXP R_gtk_text_iter_forward_visible_cursor_positions(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_forward_visible_line(SEXP s1);
extern SEXP R_gtk_text_iter_forward_visible_lines(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_forward_visible_word_end(SEXP s1);
extern SEXP R_gtk_text_iter_forward_visible_word_ends(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_forward_word_end(SEXP s1);
extern SEXP R_gtk_text_iter_forward_word_ends(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_free(SEXP s1);
extern SEXP R_gtk_text_iter_get_buffer(SEXP s1);
extern SEXP R_gtk_text_iter_get_bytes_in_line(SEXP s1);
extern SEXP R_gtk_text_iter_get_char(SEXP s1);
extern SEXP R_gtk_text_iter_get_chars_in_line(SEXP s1);
extern SEXP R_gtk_text_iter_get_child_anchor(SEXP s1);
extern SEXP R_gtk_text_iter_get_language(SEXP s1);
extern SEXP R_gtk_text_iter_get_line(SEXP s1);
extern SEXP R_gtk_text_iter_get_line_index(SEXP s1);
extern SEXP R_gtk_text_iter_get_line_offset(SEXP s1);
extern SEXP R_gtk_text_iter_get_marks(SEXP s1);
extern SEXP R_gtk_text_iter_get_offset(SEXP s1);
extern SEXP R_gtk_text_iter_get_paintable(SEXP s1);
extern SEXP R_gtk_text_iter_get_slice(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_get_tags(SEXP s1);
extern SEXP R_gtk_text_iter_get_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_get_toggled_tags(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_get_visible_line_index(SEXP s1);
extern SEXP R_gtk_text_iter_get_visible_line_offset(SEXP s1);
extern SEXP R_gtk_text_iter_get_visible_slice(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_get_visible_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_has_tag(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_in_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_iter_inside_sentence(SEXP s1);
extern SEXP R_gtk_text_iter_inside_word(SEXP s1);
extern SEXP R_gtk_text_iter_is_cursor_position(SEXP s1);
extern SEXP R_gtk_text_iter_is_end(SEXP s1);
extern SEXP R_gtk_text_iter_is_start(SEXP s1);
extern SEXP R_gtk_text_iter_order(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_set_line(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_set_line_index(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_set_line_offset(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_set_offset(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_set_visible_line_index(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_set_visible_line_offset(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_starts_line(SEXP s1);
extern SEXP R_gtk_text_iter_starts_sentence(SEXP s1);
extern SEXP R_gtk_text_iter_starts_tag(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_iter_starts_word(SEXP s1);
extern SEXP R_gtk_text_iter_toggles_tag(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_mark_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_mark_get_buffer(SEXP s1);
extern SEXP R_gtk_text_mark_get_deleted(SEXP s1);
extern SEXP R_gtk_text_mark_get_left_gravity(SEXP s1);
extern SEXP R_gtk_text_mark_get_name(SEXP s1);
extern SEXP R_gtk_text_mark_get_visible(SEXP s1);
extern SEXP R_gtk_text_mark_set_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_tag_new(SEXP s1);
extern SEXP R_gtk_text_tag_changed(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_tag_get_priority(SEXP s1);
extern SEXP R_gtk_text_tag_set_priority(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_tag_table_new(void);
extern SEXP R_gtk_text_tag_table_add(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_tag_table_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_tag_table_get_size(SEXP s1);
extern SEXP R_gtk_text_tag_table_lookup(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_tag_table_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_new(void);
extern SEXP R_gtk_text_view_new_with_buffer(SEXP s1);
extern SEXP R_gtk_text_view_add_child_at_anchor(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_view_add_overlay(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_view_backward_display_line(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_backward_display_line_start(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_buffer_to_window_coords(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_view_forward_display_line(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_forward_display_line_end(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_get_accepts_tab(SEXP s1);
extern SEXP R_gtk_text_view_get_bottom_margin(SEXP s1);
extern SEXP R_gtk_text_view_get_buffer(SEXP s1);
extern SEXP R_gtk_text_view_get_cursor_locations(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_get_cursor_visible(SEXP s1);
extern SEXP R_gtk_text_view_get_editable(SEXP s1);
extern SEXP R_gtk_text_view_get_extra_menu(SEXP s1);
extern SEXP R_gtk_text_view_get_gutter(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_get_indent(SEXP s1);
extern SEXP R_gtk_text_view_get_input_hints(SEXP s1);
extern SEXP R_gtk_text_view_get_input_purpose(SEXP s1);
extern SEXP R_gtk_text_view_get_iter_at_location(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_view_get_iter_at_position(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_view_get_iter_location(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_get_justification(SEXP s1);
extern SEXP R_gtk_text_view_get_left_margin(SEXP s1);
extern SEXP R_gtk_text_view_get_line_at_y(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_get_line_yrange(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_get_ltr_context(SEXP s1);
extern SEXP R_gtk_text_view_get_monospace(SEXP s1);
extern SEXP R_gtk_text_view_get_overwrite(SEXP s1);
extern SEXP R_gtk_text_view_get_pixels_above_lines(SEXP s1);
extern SEXP R_gtk_text_view_get_pixels_below_lines(SEXP s1);
extern SEXP R_gtk_text_view_get_pixels_inside_wrap(SEXP s1);
extern SEXP R_gtk_text_view_get_right_margin(SEXP s1);
extern SEXP R_gtk_text_view_get_rtl_context(SEXP s1);
extern SEXP R_gtk_text_view_get_tabs(SEXP s1);
extern SEXP R_gtk_text_view_get_top_margin(SEXP s1);
extern SEXP R_gtk_text_view_get_visible_rect(SEXP s1);
extern SEXP R_gtk_text_view_get_wrap_mode(SEXP s1);
extern SEXP R_gtk_text_view_im_context_filter_keypress(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_move_mark_onscreen(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_move_overlay(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_text_view_move_visually(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_view_place_cursor_onscreen(SEXP s1);
extern SEXP R_gtk_text_view_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_reset_cursor_blink(SEXP s1);
extern SEXP R_gtk_text_view_reset_im_context(SEXP s1);
extern SEXP R_gtk_text_view_scroll_mark_onscreen(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_scroll_to_iter(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_text_view_scroll_to_mark(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_text_view_set_accepts_tab(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_bottom_margin(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_buffer(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_cursor_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_editable(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_extra_menu(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_gutter(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_text_view_set_indent(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_input_hints(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_input_purpose(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_justification(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_left_margin(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_monospace(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_overwrite(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_pixels_above_lines(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_pixels_below_lines(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_pixels_inside_wrap(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_right_margin(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_tabs(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_top_margin(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_set_wrap_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_starts_display_line(SEXP s1, SEXP s2);
extern SEXP R_gtk_text_view_window_to_buffer_coords(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_toggle_button_new(void);
extern SEXP R_gtk_toggle_button_new_with_label(SEXP s1);
extern SEXP R_gtk_toggle_button_new_with_mnemonic(SEXP s1);
extern SEXP R_gtk_toggle_button_get_active(SEXP s1);
extern SEXP R_gtk_toggle_button_set_active(SEXP s1, SEXP s2);
extern SEXP R_gtk_toggle_button_set_group(SEXP s1, SEXP s2);
extern SEXP R_gtk_toggle_button_toggled(SEXP s1);
extern SEXP R_gtk_tooltip_set_custom(SEXP s1, SEXP s2);
extern SEXP R_gtk_tooltip_set_icon(SEXP s1, SEXP s2);
extern SEXP R_gtk_tooltip_set_icon_from_gicon(SEXP s1, SEXP s2);
extern SEXP R_gtk_tooltip_set_icon_from_icon_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_tooltip_set_markup(SEXP s1, SEXP s2);
extern SEXP R_gtk_tooltip_set_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_tooltip_set_tip_area(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_drag_dest_drag_data_received(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_drag_dest_row_drop_possible(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_drag_source_drag_data_delete(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_drag_source_drag_data_get(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_drag_source_row_draggable(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_expander_new(void);
extern SEXP R_gtk_tree_expander_get_child(SEXP s1);
extern SEXP R_gtk_tree_expander_get_hide_expander(SEXP s1);
extern SEXP R_gtk_tree_expander_get_indent_for_depth(SEXP s1);
extern SEXP R_gtk_tree_expander_get_indent_for_icon(SEXP s1);
extern SEXP R_gtk_tree_expander_get_item(SEXP s1);
extern SEXP R_gtk_tree_expander_get_list_row(SEXP s1);
extern SEXP R_gtk_tree_expander_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_expander_set_hide_expander(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_expander_set_indent_for_depth(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_expander_set_indent_for_icon(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_expander_set_list_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_iter_copy(SEXP s1);
extern SEXP R_gtk_tree_iter_free(SEXP s1);
extern SEXP R_gtk_tree_list_model_new(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_tree_list_model_get_autoexpand(SEXP s1);
extern SEXP R_gtk_tree_list_model_get_child_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_list_model_get_model(SEXP s1);
extern SEXP R_gtk_tree_list_model_get_passthrough(SEXP s1);
extern SEXP R_gtk_tree_list_model_get_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_list_model_set_autoexpand(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_list_row_get_child_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_list_row_get_children(SEXP s1);
extern SEXP R_gtk_tree_list_row_get_depth(SEXP s1);
extern SEXP R_gtk_tree_list_row_get_expanded(SEXP s1);
extern SEXP R_gtk_tree_list_row_get_item(SEXP s1);
extern SEXP R_gtk_tree_list_row_get_parent(SEXP s1);
extern SEXP R_gtk_tree_list_row_get_position(SEXP s1);
extern SEXP R_gtk_tree_list_row_is_expandable(SEXP s1);
extern SEXP R_gtk_tree_list_row_set_expanded(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_list_row_sorter_new(SEXP s1);
extern SEXP R_gtk_tree_list_row_sorter_get_sorter(SEXP s1);
extern SEXP R_gtk_tree_list_row_sorter_set_sorter(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_filter_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_model_get_column_type(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_get_flags(SEXP s1);
extern SEXP R_gtk_tree_model_get_iter(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_get_iter_first(SEXP s1);
extern SEXP R_gtk_tree_model_get_iter_from_string(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_get_n_columns(SEXP s1);
extern SEXP R_gtk_tree_model_get_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_get_string_from_iter(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_get_value(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_model_iter_children(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_iter_has_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_iter_n_children(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_iter_next(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_iter_nth_child(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_model_iter_parent(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_iter_previous(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_ref_node(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_row_changed(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_model_row_deleted(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_row_has_child_toggled(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_model_row_inserted(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_model_rows_reordered_with_length(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_tree_model_unref_node(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_filter_clear_cache(SEXP s1);
extern SEXP R_gtk_tree_model_filter_convert_child_iter_to_iter(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_filter_convert_child_path_to_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_filter_convert_iter_to_child_iter(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_filter_convert_path_to_child_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_filter_get_model(SEXP s1);
extern SEXP R_gtk_tree_model_filter_refilter(SEXP s1);
extern SEXP R_gtk_tree_model_filter_set_modify_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_tree_model_filter_set_visible_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_filter_set_visible_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_tree_model_sort_new_with_model(SEXP s1);
extern SEXP R_gtk_tree_model_sort_clear_cache(SEXP s1);
extern SEXP R_gtk_tree_model_sort_convert_child_iter_to_iter(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_sort_convert_child_path_to_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_sort_convert_iter_to_child_iter(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_sort_convert_path_to_child_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_sort_get_model(SEXP s1);
extern SEXP R_gtk_tree_model_sort_iter_is_valid(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_model_sort_reset_default_sort_func(SEXP s1);
extern SEXP R_gtk_tree_path_new(void);
extern SEXP R_gtk_tree_path_new_first(void);
extern SEXP R_gtk_tree_path_new_from_indicesv(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_path_new_from_string(SEXP s1);
extern SEXP R_gtk_tree_path_append_index(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_path_compare(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_path_copy(SEXP s1);
extern SEXP R_gtk_tree_path_down(SEXP s1);
extern SEXP R_gtk_tree_path_free(SEXP s1);
extern SEXP R_gtk_tree_path_get_depth(SEXP s1);
extern SEXP R_gtk_tree_path_get_indices_with_depth(SEXP s1);
extern SEXP R_gtk_tree_path_is_ancestor(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_path_is_descendant(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_path_next(SEXP s1);
extern SEXP R_gtk_tree_path_prepend_index(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_path_prev(SEXP s1);
extern SEXP R_gtk_tree_path_to_string(SEXP s1);
extern SEXP R_gtk_tree_path_up(SEXP s1);
extern SEXP R_gtk_tree_row_reference_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_row_reference_new_proxy(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_row_reference_copy(SEXP s1);
extern SEXP R_gtk_tree_row_reference_free(SEXP s1);
extern SEXP R_gtk_tree_row_reference_get_model(SEXP s1);
extern SEXP R_gtk_tree_row_reference_get_path(SEXP s1);
extern SEXP R_gtk_tree_row_reference_valid(SEXP s1);
extern SEXP R_gtk_tree_row_reference_deleted(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_row_reference_inserted(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_selection_count_selected_rows(SEXP s1);
extern SEXP R_gtk_tree_selection_get_mode(SEXP s1);
extern SEXP R_gtk_tree_selection_get_selected(SEXP s1);
extern SEXP R_gtk_tree_selection_get_selected_rows(SEXP s1);
extern SEXP R_gtk_tree_selection_get_tree_view(SEXP s1);
extern SEXP R_gtk_tree_selection_iter_is_selected(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_selection_path_is_selected(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_selection_select_all(SEXP s1);
extern SEXP R_gtk_tree_selection_select_iter(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_selection_select_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_selection_select_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_selection_selected_foreach(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_selection_set_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_selection_set_select_function(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_tree_selection_unselect_all(SEXP s1);
extern SEXP R_gtk_tree_selection_unselect_iter(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_selection_unselect_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_selection_unselect_range(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_sortable_get_sort_column_id(SEXP s1);
extern SEXP R_gtk_tree_sortable_has_default_sort_func(SEXP s1);
extern SEXP R_gtk_tree_sortable_set_default_sort_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_tree_sortable_set_sort_column_id(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_sortable_set_sort_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_tree_sortable_sort_column_changed(SEXP s1);
extern SEXP R_gtk_tree_store_newv(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_store_append(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_store_clear(SEXP s1);
extern SEXP R_gtk_tree_store_insert(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_store_insert_after(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_store_insert_before(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_store_insert_with_valuesv(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_tree_store_is_ancestor(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_store_iter_depth(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_store_iter_is_valid(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_store_move_after(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_store_move_before(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_store_prepend(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_store_remove(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_store_set_column_types(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_store_set_value(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_tree_store_set_valuesv(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_tree_store_swap(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_new(void);
extern SEXP R_gtk_tree_view_new_with_model(SEXP s1);
extern SEXP R_gtk_tree_view_append_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_collapse_all(SEXP s1);
extern SEXP R_gtk_tree_view_collapse_row(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_columns_autosize(SEXP s1);
extern SEXP R_gtk_tree_view_convert_bin_window_to_tree_coords(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_convert_bin_window_to_widget_coords(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_convert_tree_to_bin_window_coords(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_convert_tree_to_widget_coords(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_convert_widget_to_bin_window_coords(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_convert_widget_to_tree_coords(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_create_row_drag_icon(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_enable_model_drag_dest(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_enable_model_drag_source(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_tree_view_expand_all(SEXP s1);
extern SEXP R_gtk_tree_view_expand_row(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_expand_to_path(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_get_activate_on_single_click(SEXP s1);
extern SEXP R_gtk_tree_view_get_background_area(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_get_cell_area(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_get_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_get_columns(SEXP s1);
extern SEXP R_gtk_tree_view_get_cursor(SEXP s1);
extern SEXP R_gtk_tree_view_get_dest_row_at_pos(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_get_drag_dest_row(SEXP s1);
extern SEXP R_gtk_tree_view_get_enable_search(SEXP s1);
extern SEXP R_gtk_tree_view_get_enable_tree_lines(SEXP s1);
extern SEXP R_gtk_tree_view_get_expander_column(SEXP s1);
extern SEXP R_gtk_tree_view_get_fixed_height_mode(SEXP s1);
extern SEXP R_gtk_tree_view_get_grid_lines(SEXP s1);
extern SEXP R_gtk_tree_view_get_headers_clickable(SEXP s1);
extern SEXP R_gtk_tree_view_get_headers_visible(SEXP s1);
extern SEXP R_gtk_tree_view_get_hover_expand(SEXP s1);
extern SEXP R_gtk_tree_view_get_hover_selection(SEXP s1);
extern SEXP R_gtk_tree_view_get_level_indentation(SEXP s1);
extern SEXP R_gtk_tree_view_get_model(SEXP s1);
extern SEXP R_gtk_tree_view_get_n_columns(SEXP s1);
extern SEXP R_gtk_tree_view_get_path_at_pos(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_get_reorderable(SEXP s1);
extern SEXP R_gtk_tree_view_get_rubber_banding(SEXP s1);
extern SEXP R_gtk_tree_view_get_search_column(SEXP s1);
extern SEXP R_gtk_tree_view_get_search_entry(SEXP s1);
extern SEXP R_gtk_tree_view_get_selection(SEXP s1);
extern SEXP R_gtk_tree_view_get_show_expanders(SEXP s1);
extern SEXP R_gtk_tree_view_get_tooltip_column(SEXP s1);
extern SEXP R_gtk_tree_view_get_tooltip_context(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_tree_view_get_visible_range(SEXP s1);
extern SEXP R_gtk_tree_view_get_visible_rect(SEXP s1);
extern SEXP R_gtk_tree_view_insert_column(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_insert_column_with_data_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7);
extern SEXP R_gtk_tree_view_is_blank_at_pos(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_is_rubber_banding_active(SEXP s1);
extern SEXP R_gtk_tree_view_map_expanded_rows(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_move_column_after(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_remove_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_row_activated(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_row_expanded(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_scroll_to_cell(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_tree_view_scroll_to_point(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_set_activate_on_single_click(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_column_drag_function(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_tree_view_set_cursor(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_tree_view_set_cursor_on_cell(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_tree_view_set_drag_dest_row(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_set_enable_search(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_enable_tree_lines(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_expander_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_fixed_height_mode(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_grid_lines(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_headers_clickable(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_headers_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_hover_expand(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_hover_selection(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_level_indentation(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_model(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_reorderable(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_row_separator_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_tree_view_set_rubber_banding(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_search_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_search_entry(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_search_equal_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_tree_view_set_show_expanders(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_tooltip_cell(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_tree_view_set_tooltip_column(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_set_tooltip_row(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_unset_rows_drag_dest(SEXP s1);
extern SEXP R_gtk_tree_view_unset_rows_drag_source(SEXP s1);
extern SEXP R_gtk_tree_view_column_new(void);
extern SEXP R_gtk_tree_view_column_new_with_area(SEXP s1);
extern SEXP R_gtk_tree_view_column_add_attribute(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_tree_view_column_cell_get_position(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_cell_get_size(SEXP s1);
extern SEXP R_gtk_tree_view_column_cell_is_visible(SEXP s1);
extern SEXP R_gtk_tree_view_column_cell_set_cell_data(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_tree_view_column_clear(SEXP s1);
extern SEXP R_gtk_tree_view_column_clear_attributes(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_clicked(SEXP s1);
extern SEXP R_gtk_tree_view_column_focus_cell(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_get_alignment(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_button(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_clickable(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_expand(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_fixed_width(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_max_width(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_min_width(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_reorderable(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_resizable(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_sizing(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_sort_column_id(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_sort_indicator(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_sort_order(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_spacing(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_title(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_tree_view(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_visible(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_widget(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_width(SEXP s1);
extern SEXP R_gtk_tree_view_column_get_x_offset(SEXP s1);
extern SEXP R_gtk_tree_view_column_pack_end(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_column_pack_start(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_tree_view_column_queue_resize(SEXP s1);
extern SEXP R_gtk_tree_view_column_set_alignment(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_cell_data_func(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_tree_view_column_set_clickable(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_expand(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_fixed_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_max_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_min_width(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_reorderable(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_resizable(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_sizing(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_sort_column_id(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_sort_indicator(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_sort_order(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_spacing(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_title(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_view_column_set_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_uri_launcher_new(SEXP s1);
extern SEXP R_gtk_uri_launcher_get_uri(SEXP s1);
extern SEXP R_gtk_uri_launcher_launch(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_uri_launcher_launch_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_uri_launcher_set_uri(SEXP s1, SEXP s2);
extern SEXP R_gtk_video_new(void);
extern SEXP R_gtk_video_new_for_file(SEXP s1);
extern SEXP R_gtk_video_new_for_filename(SEXP s1);
extern SEXP R_gtk_video_new_for_media_stream(SEXP s1);
extern SEXP R_gtk_video_new_for_resource(SEXP s1);
extern SEXP R_gtk_video_get_autoplay(SEXP s1);
extern SEXP R_gtk_video_get_file(SEXP s1);
extern SEXP R_gtk_video_get_loop(SEXP s1);
extern SEXP R_gtk_video_get_media_stream(SEXP s1);
extern SEXP R_gtk_video_set_autoplay(SEXP s1, SEXP s2);
extern SEXP R_gtk_video_set_file(SEXP s1, SEXP s2);
extern SEXP R_gtk_video_set_filename(SEXP s1, SEXP s2);
extern SEXP R_gtk_video_set_loop(SEXP s1, SEXP s2);
extern SEXP R_gtk_video_set_media_stream(SEXP s1, SEXP s2);
extern SEXP R_gtk_video_set_resource(SEXP s1, SEXP s2);
extern SEXP R_gtk_viewport_new(SEXP s1, SEXP s2);
extern SEXP R_gtk_viewport_get_child(SEXP s1);
extern SEXP R_gtk_viewport_get_scroll_to_focus(SEXP s1);
extern SEXP R_gtk_viewport_scroll_to(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_viewport_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_viewport_set_scroll_to_focus(SEXP s1, SEXP s2);
extern SEXP R_gtk_volume_button_new(void);
extern SEXP R_gtk_widget_get_default_direction(void);
extern SEXP R_gtk_widget_set_default_direction(SEXP s1);
extern SEXP R_gtk_widget_action_set_enabled(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_activate(SEXP s1);
extern SEXP R_gtk_widget_activate_action_variant(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_activate_default(SEXP s1);
extern SEXP R_gtk_widget_add_controller(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_add_css_class(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_add_mnemonic_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_add_tick_callback(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_widget_allocate(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_widget_child_focus(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_compute_bounds(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_compute_expand(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_compute_point(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_compute_transform(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_contains(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_create_pango_context(SEXP s1);
extern SEXP R_gtk_widget_create_pango_layout(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_dispose_template(SEXP s1, SEXP s2);
extern SEXP R_gtk_drag_check_threshold(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_widget_error_bell(SEXP s1);
extern SEXP R_gtk_widget_get_allocated_baseline(SEXP s1);
extern SEXP R_gtk_widget_get_allocated_height(SEXP s1);
extern SEXP R_gtk_widget_get_allocated_width(SEXP s1);
extern SEXP R_gtk_widget_get_allocation(SEXP s1);
extern SEXP R_gtk_widget_get_ancestor(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_get_baseline(SEXP s1);
extern SEXP R_gtk_widget_get_can_focus(SEXP s1);
extern SEXP R_gtk_widget_get_can_target(SEXP s1);
extern SEXP R_gtk_widget_get_child_visible(SEXP s1);
extern SEXP R_gtk_widget_get_clipboard(SEXP s1);
extern SEXP R_gtk_widget_get_color(SEXP s1);
extern SEXP R_gtk_widget_get_css_classes(SEXP s1);
extern SEXP R_gtk_widget_get_css_name(SEXP s1);
extern SEXP R_gtk_widget_get_cursor(SEXP s1);
extern SEXP R_gtk_widget_get_direction(SEXP s1);
extern SEXP R_gtk_widget_get_display(SEXP s1);
extern SEXP R_gtk_widget_get_first_child(SEXP s1);
extern SEXP R_gtk_widget_get_focus_child(SEXP s1);
extern SEXP R_gtk_widget_get_focus_on_click(SEXP s1);
extern SEXP R_gtk_widget_get_focusable(SEXP s1);
extern SEXP R_gtk_widget_get_font_map(SEXP s1);
extern SEXP R_gtk_widget_get_font_options(SEXP s1);
extern SEXP R_gtk_widget_get_frame_clock(SEXP s1);
extern SEXP R_gtk_widget_get_halign(SEXP s1);
extern SEXP R_gtk_widget_get_has_tooltip(SEXP s1);
extern SEXP R_gtk_widget_get_height(SEXP s1);
extern SEXP R_gtk_widget_get_hexpand(SEXP s1);
extern SEXP R_gtk_widget_get_hexpand_set(SEXP s1);
extern SEXP R_gtk_widget_get_last_child(SEXP s1);
extern SEXP R_gtk_widget_get_layout_manager(SEXP s1);
extern SEXP R_gtk_widget_get_mapped(SEXP s1);
extern SEXP R_gtk_widget_get_margin_bottom(SEXP s1);
extern SEXP R_gtk_widget_get_margin_end(SEXP s1);
extern SEXP R_gtk_widget_get_margin_start(SEXP s1);
extern SEXP R_gtk_widget_get_margin_top(SEXP s1);
extern SEXP R_gtk_widget_get_name(SEXP s1);
extern SEXP R_gtk_widget_get_native(SEXP s1);
extern SEXP R_gtk_widget_get_next_sibling(SEXP s1);
extern SEXP R_gtk_widget_get_opacity(SEXP s1);
extern SEXP R_gtk_widget_get_overflow(SEXP s1);
extern SEXP R_gtk_widget_get_pango_context(SEXP s1);
extern SEXP R_gtk_widget_get_parent(SEXP s1);
extern SEXP R_gtk_widget_get_preferred_size(SEXP s1);
extern SEXP R_gtk_widget_get_prev_sibling(SEXP s1);
extern SEXP R_gtk_widget_get_primary_clipboard(SEXP s1);
extern SEXP R_gtk_widget_get_realized(SEXP s1);
extern SEXP R_gtk_widget_get_receives_default(SEXP s1);
extern SEXP R_gtk_widget_get_request_mode(SEXP s1);
extern SEXP R_gtk_widget_get_root(SEXP s1);
extern SEXP R_gtk_widget_get_scale_factor(SEXP s1);
extern SEXP R_gtk_widget_get_sensitive(SEXP s1);
extern SEXP R_gtk_widget_get_settings(SEXP s1);
extern SEXP R_gtk_widget_get_size(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_get_size_request(SEXP s1);
extern SEXP R_gtk_widget_get_state_flags(SEXP s1);
extern SEXP R_gtk_widget_get_style_context(SEXP s1);
extern SEXP R_gtk_widget_get_template_child(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_get_tooltip_markup(SEXP s1);
extern SEXP R_gtk_widget_get_tooltip_text(SEXP s1);
extern SEXP R_gtk_widget_get_valign(SEXP s1);
extern SEXP R_gtk_widget_get_vexpand(SEXP s1);
extern SEXP R_gtk_widget_get_vexpand_set(SEXP s1);
extern SEXP R_gtk_widget_get_visible(SEXP s1);
extern SEXP R_gtk_widget_get_width(SEXP s1);
extern SEXP R_gtk_widget_grab_focus(SEXP s1);
extern SEXP R_gtk_widget_has_css_class(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_has_default(SEXP s1);
extern SEXP R_gtk_widget_has_focus(SEXP s1);
extern SEXP R_gtk_widget_has_visible_focus(SEXP s1);
extern SEXP R_gtk_widget_hide(SEXP s1);
extern SEXP R_gtk_widget_in_destruction(SEXP s1);
extern SEXP R_gtk_widget_init_template(SEXP s1);
extern SEXP R_gtk_widget_insert_action_group(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_insert_after(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_insert_before(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_is_ancestor(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_is_drawable(SEXP s1);
extern SEXP R_gtk_widget_is_focus(SEXP s1);
extern SEXP R_gtk_widget_is_sensitive(SEXP s1);
extern SEXP R_gtk_widget_is_visible(SEXP s1);
extern SEXP R_gtk_widget_keynav_failed(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_list_mnemonic_labels(SEXP s1);
extern SEXP R_gtk_widget_map(SEXP s1);
extern SEXP R_gtk_widget_measure(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_mnemonic_activate(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_observe_children(SEXP s1);
extern SEXP R_gtk_widget_observe_controllers(SEXP s1);
extern SEXP R_gtk_widget_pick(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_widget_queue_allocate(SEXP s1);
extern SEXP R_gtk_widget_queue_draw(SEXP s1);
extern SEXP R_gtk_widget_queue_resize(SEXP s1);
extern SEXP R_gtk_widget_realize(SEXP s1);
extern SEXP R_gtk_widget_remove_controller(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_remove_css_class(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_remove_mnemonic_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_remove_tick_callback(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_can_focus(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_can_target(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_child_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_css_classes(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_cursor(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_cursor_from_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_direction(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_focus_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_focus_on_click(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_focusable(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_font_map(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_font_options(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_halign(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_has_tooltip(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_hexpand(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_hexpand_set(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_layout_manager(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_margin_bottom(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_margin_end(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_margin_start(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_margin_top(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_opacity(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_overflow(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_parent(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_receives_default(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_sensitive(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_size_request(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_set_state_flags(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_set_tooltip_markup(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_tooltip_text(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_valign(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_vexpand(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_vexpand_set(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_set_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_should_layout(SEXP s1);
extern SEXP R_gtk_widget_show(SEXP s1);
extern SEXP R_gtk_widget_size_allocate(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_snapshot_child(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_translate_coordinates(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_widget_trigger_tooltip_query(SEXP s1);
extern SEXP R_gtk_widget_unmap(SEXP s1);
extern SEXP R_gtk_widget_unparent(SEXP s1);
extern SEXP R_gtk_widget_unrealize(SEXP s1);
extern SEXP R_gtk_widget_unset_state_flags(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_class_add_shortcut(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_class_bind_template_callback_full(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_class_bind_template_child_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_widget_class_get_accessible_role(SEXP s1);
extern SEXP R_gtk_widget_class_get_activate_signal(SEXP s1);
extern SEXP R_gtk_widget_class_get_css_name(SEXP s1);
extern SEXP R_gtk_widget_class_get_layout_manager_type(SEXP s1);
extern SEXP R_gtk_widget_class_install_action(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_widget_class_install_property_action(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_widget_class_query_action(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_class_set_accessible_role(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_class_set_activate_signal(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_class_set_activate_signal_from_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_class_set_css_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_class_set_layout_manager_type(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_class_set_template(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_class_set_template_from_resource(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_class_set_template_scope(SEXP s1, SEXP s2);
extern SEXP R_gtk_widget_paintable_new(SEXP s1);
extern SEXP R_gtk_widget_paintable_get_widget(SEXP s1);
extern SEXP R_gtk_widget_paintable_set_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_new(void);
extern SEXP R_gtk_window_get_default_icon_name(void);
extern SEXP R_gtk_window_get_toplevels(void);
extern SEXP R_gtk_window_list_toplevels(void);
extern SEXP R_gtk_window_set_auto_startup_notification(SEXP s1);
extern SEXP R_gtk_window_set_default_icon_name(SEXP s1);
extern SEXP R_gtk_window_set_interactive_debugging(SEXP s1);
extern SEXP R_gtk_window_close(SEXP s1);
extern SEXP R_gtk_window_destroy(SEXP s1);
extern SEXP R_gtk_window_fullscreen(SEXP s1);
extern SEXP R_gtk_window_fullscreen_on_monitor(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_get_application(SEXP s1);
extern SEXP R_gtk_window_get_child(SEXP s1);
extern SEXP R_gtk_window_get_decorated(SEXP s1);
extern SEXP R_gtk_window_get_default_size(SEXP s1);
extern SEXP R_gtk_window_get_default_widget(SEXP s1);
extern SEXP R_gtk_window_get_deletable(SEXP s1);
extern SEXP R_gtk_window_get_destroy_with_parent(SEXP s1);
extern SEXP R_gtk_window_get_focus(SEXP s1);
extern SEXP R_gtk_window_get_focus_visible(SEXP s1);
extern SEXP R_gtk_window_get_group(SEXP s1);
extern SEXP R_gtk_window_get_handle_menubar_accel(SEXP s1);
extern SEXP R_gtk_window_get_hide_on_close(SEXP s1);
extern SEXP R_gtk_window_get_icon_name(SEXP s1);
extern SEXP R_gtk_window_get_mnemonics_visible(SEXP s1);
extern SEXP R_gtk_window_get_modal(SEXP s1);
extern SEXP R_gtk_window_get_resizable(SEXP s1);
extern SEXP R_gtk_window_get_title(SEXP s1);
extern SEXP R_gtk_window_get_titlebar(SEXP s1);
extern SEXP R_gtk_window_get_transient_for(SEXP s1);
extern SEXP R_gtk_window_has_group(SEXP s1);
extern SEXP R_gtk_window_is_active(SEXP s1);
extern SEXP R_gtk_window_is_fullscreen(SEXP s1);
extern SEXP R_gtk_window_is_maximized(SEXP s1);
extern SEXP R_gtk_window_is_suspended(SEXP s1);
extern SEXP R_gtk_window_maximize(SEXP s1);
extern SEXP R_gtk_window_minimize(SEXP s1);
extern SEXP R_gtk_window_present(SEXP s1);
extern SEXP R_gtk_window_present_with_time(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_application(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_decorated(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_default_size(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_window_set_default_widget(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_deletable(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_destroy_with_parent(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_display(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_focus(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_focus_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_handle_menubar_accel(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_hide_on_close(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_icon_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_mnemonics_visible(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_modal(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_resizable(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_startup_id(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_title(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_titlebar(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_set_transient_for(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_unfullscreen(SEXP s1);
extern SEXP R_gtk_window_unmaximize(SEXP s1);
extern SEXP R_gtk_window_unminimize(SEXP s1);
extern SEXP R_gtk_window_controls_new(SEXP s1);
extern SEXP R_gtk_window_controls_get_decoration_layout(SEXP s1);
extern SEXP R_gtk_window_controls_get_empty(SEXP s1);
extern SEXP R_gtk_window_controls_get_side(SEXP s1);
extern SEXP R_gtk_window_controls_set_decoration_layout(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_controls_set_side(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_group_new(void);
extern SEXP R_gtk_window_group_add_window(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_group_list_windows(SEXP s1);
extern SEXP R_gtk_window_group_remove_window(SEXP s1, SEXP s2);
extern SEXP R_gtk_window_handle_new(void);
extern SEXP R_gtk_window_handle_get_child(SEXP s1);
extern SEXP R_gtk_window_handle_set_child(SEXP s1, SEXP s2);
extern SEXP R_gtk_accelerator_get_default_mod_mask(void);
extern SEXP R_gtk_accelerator_get_label(SEXP s1, SEXP s2);
extern SEXP R_gtk_accelerator_get_label_with_keycode(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_accelerator_name(SEXP s1, SEXP s2);
extern SEXP R_gtk_accelerator_name_with_keycode(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_accelerator_parse(SEXP s1);
extern SEXP R_gtk_accelerator_parse_with_keycode(SEXP s1, SEXP s2);
extern SEXP R_gtk_accelerator_valid(SEXP s1, SEXP s2);
extern SEXP R_gtk_check_version(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_css_parser_error_quark(void);
extern SEXP R_gtk_css_parser_warning_quark(void);
extern SEXP R_gtk_disable_setlocale(void);
extern SEXP R_gtk_distribute_natural_allocation(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_get_binary_age(void);
extern SEXP R_gtk_get_debug_flags(void);
extern SEXP R_gtk_get_default_language(void);
extern SEXP R_gtk_get_interface_age(void);
extern SEXP R_gtk_get_locale_direction(void);
extern SEXP R_gtk_get_major_version(void);
extern SEXP R_gtk_get_micro_version(void);
extern SEXP R_gtk_get_minor_version(void);
extern SEXP R_gtk_hsv_to_rgb(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_init(void);
extern SEXP R_gtk_init_check(void);
extern SEXP R_gtk_is_initialized(void);
extern SEXP R_gtk_param_spec_expression(SEXP s1, SEXP s2, SEXP s3, SEXP s4);
extern SEXP R_gtk_render_activity(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_render_arrow(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_render_background(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_render_check(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_render_expander(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_render_focus(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_render_frame(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_render_handle(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_render_icon(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_render_layout(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5);
extern SEXP R_gtk_render_line(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_render_option(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_rgb_to_hsv(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_set_debug_flags(SEXP s1);
extern SEXP R_gtk_show_uri(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_show_uri_full(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6);
extern SEXP R_gtk_show_uri_full_finish(SEXP s1, SEXP s2);
extern SEXP R_gtk_test_accessible_assertion_message_role(SEXP s1, SEXP s2, SEXP s3, SEXP s4, SEXP s5, SEXP s6, SEXP s7, SEXP s8);
extern SEXP R_gtk_test_accessible_has_property(SEXP s1, SEXP s2);
extern SEXP R_gtk_test_accessible_has_relation(SEXP s1, SEXP s2);
extern SEXP R_gtk_test_accessible_has_role(SEXP s1, SEXP s2);
extern SEXP R_gtk_test_accessible_has_state(SEXP s1, SEXP s2);
extern SEXP R_gtk_test_list_all_types(void);
extern SEXP R_gtk_test_register_all_types(void);
extern SEXP R_gtk_test_widget_wait_for_draw(SEXP s1);
extern SEXP R_gtk_tree_create_row_drag_content(SEXP s1, SEXP s2);
extern SEXP R_gtk_tree_get_row_drag_data(SEXP s1);
extern SEXP R_gtk_value_dup_expression(SEXP s1);
extern SEXP R_gtk_value_get_expression(SEXP s1);
extern SEXP R_gtk_value_set_expression(SEXP s1, SEXP s2);
extern SEXP R_gtk_value_take_expression(SEXP s1, SEXP s2);
extern SEXP R_g_timeout_add(SEXP s_interval, SEXP s_fun);
extern SEXP R_g_idle_add(SEXP s_fun);
extern SEXP R_gtk_dialog_run(SEXP s_dialog);
extern SEXP R_gtk_file_chooser_dialog_run(SEXP s_parent, SEXP s_title, SEXP s_action);
extern SEXP R_gtk_start_event_loop(void);
extern SEXP R_gtk_stop_event_loop(void);
extern SEXP R_gtk_force_foreground(void);
extern SEXP R_gtk_hide_from_dock(void);
extern SEXP R_gtk_window_track(SEXP s_window);
extern SEXP R_gtk_main_iteration(void);
extern SEXP R_gtk_main_iteration_do(SEXP s_blocking);
extern SEXP R_macos_set_app_icon(SEXP s_path);
extern SEXP R_extptr_address(SEXP s);
extern SEXP R_gtk_window_add_close_shortcut(SEXP s_window);
extern SEXP R_gtk_get_ui_state(SEXP s_widgets);
extern SEXP R_gtk_string_list_new_from_vector(SEXP s_strings);
extern SEXP R_gtk_text_buffer_create_tag_simple(SEXP s_buffer, SEXP s_tag_name);
extern SEXP R_g_object_set_string(SEXP s1, SEXP s2, SEXP s3);
extern SEXP R_gtk_message_dialog_new_safe(SEXP parent_ptr, SEXP flags, SEXP type, SEXP buttons, SEXP message);
extern SEXP R_g_signal_connect_r(SEXP s_obj, SEXP s_signal, SEXP s_fun);
extern SEXP R_g_signal_connect_r_boolean(SEXP s_obj, SEXP s_signal, SEXP s_fun);

static const R_CallMethodDef CallEntries[] = {
    {"R_gdk_app_launch_context_get_display", (DL_FUNC) &R_gdk_app_launch_context_get_display, 1},
    {"R_gdk_app_launch_context_set_desktop", (DL_FUNC) &R_gdk_app_launch_context_set_desktop, 2},
    {"R_gdk_app_launch_context_set_icon", (DL_FUNC) &R_gdk_app_launch_context_set_icon, 2},
    {"R_gdk_app_launch_context_set_icon_name", (DL_FUNC) &R_gdk_app_launch_context_set_icon_name, 2},
    {"R_gdk_app_launch_context_set_timestamp", (DL_FUNC) &R_gdk_app_launch_context_set_timestamp, 2},
    {"R_gdk_button_event_get_button", (DL_FUNC) &R_gdk_button_event_get_button, 1},
    {"R_gdk_cairo_context_cairo_create", (DL_FUNC) &R_gdk_cairo_context_cairo_create, 1},
    {"R_gdk_clipboard_get_content", (DL_FUNC) &R_gdk_clipboard_get_content, 1},
    {"R_gdk_clipboard_get_display", (DL_FUNC) &R_gdk_clipboard_get_display, 1},
    {"R_gdk_clipboard_get_formats", (DL_FUNC) &R_gdk_clipboard_get_formats, 1},
    {"R_gdk_clipboard_is_local", (DL_FUNC) &R_gdk_clipboard_is_local, 1},
    {"R_gdk_clipboard_read_async", (DL_FUNC) &R_gdk_clipboard_read_async, 6},
    {"R_gdk_clipboard_read_finish", (DL_FUNC) &R_gdk_clipboard_read_finish, 2},
    {"R_gdk_clipboard_read_text_async", (DL_FUNC) &R_gdk_clipboard_read_text_async, 4},
    {"R_gdk_clipboard_read_text_finish", (DL_FUNC) &R_gdk_clipboard_read_text_finish, 2},
    {"R_gdk_clipboard_read_texture_async", (DL_FUNC) &R_gdk_clipboard_read_texture_async, 4},
    {"R_gdk_clipboard_read_texture_finish", (DL_FUNC) &R_gdk_clipboard_read_texture_finish, 2},
    {"R_gdk_clipboard_read_value_async", (DL_FUNC) &R_gdk_clipboard_read_value_async, 6},
    {"R_gdk_clipboard_read_value_finish", (DL_FUNC) &R_gdk_clipboard_read_value_finish, 2},
    {"R_gdk_clipboard_set_content", (DL_FUNC) &R_gdk_clipboard_set_content, 2},
    {"R_gdk_clipboard_set_value", (DL_FUNC) &R_gdk_clipboard_set_value, 2},
    {"R_gdk_clipboard_store_async", (DL_FUNC) &R_gdk_clipboard_store_async, 5},
    {"R_gdk_clipboard_store_finish", (DL_FUNC) &R_gdk_clipboard_store_finish, 2},
    {"R_gdk_content_deserializer_get_cancellable", (DL_FUNC) &R_gdk_content_deserializer_get_cancellable, 1},
    {"R_gdk_content_deserializer_get_gtype", (DL_FUNC) &R_gdk_content_deserializer_get_gtype, 1},
    {"R_gdk_content_deserializer_get_input_stream", (DL_FUNC) &R_gdk_content_deserializer_get_input_stream, 1},
    {"R_gdk_content_deserializer_get_mime_type", (DL_FUNC) &R_gdk_content_deserializer_get_mime_type, 1},
    {"R_gdk_content_deserializer_get_priority", (DL_FUNC) &R_gdk_content_deserializer_get_priority, 1},
    {"R_gdk_content_deserializer_get_task_data", (DL_FUNC) &R_gdk_content_deserializer_get_task_data, 1},
    {"R_gdk_content_deserializer_get_user_data", (DL_FUNC) &R_gdk_content_deserializer_get_user_data, 1},
    {"R_gdk_content_deserializer_get_value", (DL_FUNC) &R_gdk_content_deserializer_get_value, 1},
    {"R_gdk_content_deserializer_return_error", (DL_FUNC) &R_gdk_content_deserializer_return_error, 2},
    {"R_gdk_content_deserializer_return_success", (DL_FUNC) &R_gdk_content_deserializer_return_success, 1},
    {"R_gdk_content_deserializer_set_task_data", (DL_FUNC) &R_gdk_content_deserializer_set_task_data, 3},
    {"R_gdk_content_formats_new", (DL_FUNC) &R_gdk_content_formats_new, 2},
    {"R_gdk_content_formats_new_for_gtype", (DL_FUNC) &R_gdk_content_formats_new_for_gtype, 1},
    {"R_gdk_content_formats_contain_gtype", (DL_FUNC) &R_gdk_content_formats_contain_gtype, 2},
    {"R_gdk_content_formats_contain_mime_type", (DL_FUNC) &R_gdk_content_formats_contain_mime_type, 2},
    {"R_gdk_content_formats_get_gtypes", (DL_FUNC) &R_gdk_content_formats_get_gtypes, 1},
    {"R_gdk_content_formats_get_mime_types", (DL_FUNC) &R_gdk_content_formats_get_mime_types, 1},
    {"R_gdk_content_formats_match", (DL_FUNC) &R_gdk_content_formats_match, 2},
    {"R_gdk_content_formats_match_gtype", (DL_FUNC) &R_gdk_content_formats_match_gtype, 2},
    {"R_gdk_content_formats_match_mime_type", (DL_FUNC) &R_gdk_content_formats_match_mime_type, 2},
    {"R_gdk_content_formats_print", (DL_FUNC) &R_gdk_content_formats_print, 2},
    {"R_gdk_content_formats_ref", (DL_FUNC) &R_gdk_content_formats_ref, 1},
    {"R_gdk_content_formats_to_string", (DL_FUNC) &R_gdk_content_formats_to_string, 1},
    {"R_gdk_content_formats_union", (DL_FUNC) &R_gdk_content_formats_union, 2},
    {"R_gdk_content_formats_union_deserialize_gtypes", (DL_FUNC) &R_gdk_content_formats_union_deserialize_gtypes, 1},
    {"R_gdk_content_formats_union_deserialize_mime_types", (DL_FUNC) &R_gdk_content_formats_union_deserialize_mime_types, 1},
    {"R_gdk_content_formats_union_serialize_gtypes", (DL_FUNC) &R_gdk_content_formats_union_serialize_gtypes, 1},
    {"R_gdk_content_formats_union_serialize_mime_types", (DL_FUNC) &R_gdk_content_formats_union_serialize_mime_types, 1},
    {"R_gdk_content_formats_unref", (DL_FUNC) &R_gdk_content_formats_unref, 1},
    {"R_gdk_content_formats_parse", (DL_FUNC) &R_gdk_content_formats_parse, 1},
    {"R_gdk_content_formats_builder_new", (DL_FUNC) &R_gdk_content_formats_builder_new, 0},
    {"R_gdk_content_formats_builder_add_formats", (DL_FUNC) &R_gdk_content_formats_builder_add_formats, 2},
    {"R_gdk_content_formats_builder_add_gtype", (DL_FUNC) &R_gdk_content_formats_builder_add_gtype, 2},
    {"R_gdk_content_formats_builder_add_mime_type", (DL_FUNC) &R_gdk_content_formats_builder_add_mime_type, 2},
    {"R_gdk_content_formats_builder_ref", (DL_FUNC) &R_gdk_content_formats_builder_ref, 1},
    {"R_gdk_content_formats_builder_to_formats", (DL_FUNC) &R_gdk_content_formats_builder_to_formats, 1},
    {"R_gdk_content_formats_builder_unref", (DL_FUNC) &R_gdk_content_formats_builder_unref, 1},
    {"R_gdk_content_provider_new_for_bytes", (DL_FUNC) &R_gdk_content_provider_new_for_bytes, 2},
    {"R_gdk_content_provider_new_for_value", (DL_FUNC) &R_gdk_content_provider_new_for_value, 1},
    {"R_gdk_content_provider_new_union", (DL_FUNC) &R_gdk_content_provider_new_union, 2},
    {"R_gdk_content_provider_content_changed", (DL_FUNC) &R_gdk_content_provider_content_changed, 1},
    {"R_gdk_content_provider_get_value", (DL_FUNC) &R_gdk_content_provider_get_value, 1},
    {"R_gdk_content_provider_ref_formats", (DL_FUNC) &R_gdk_content_provider_ref_formats, 1},
    {"R_gdk_content_provider_ref_storable_formats", (DL_FUNC) &R_gdk_content_provider_ref_storable_formats, 1},
    {"R_gdk_content_provider_write_mime_type_async", (DL_FUNC) &R_gdk_content_provider_write_mime_type_async, 7},
    {"R_gdk_content_provider_write_mime_type_finish", (DL_FUNC) &R_gdk_content_provider_write_mime_type_finish, 2},
    {"R_gdk_content_serializer_get_cancellable", (DL_FUNC) &R_gdk_content_serializer_get_cancellable, 1},
    {"R_gdk_content_serializer_get_gtype", (DL_FUNC) &R_gdk_content_serializer_get_gtype, 1},
    {"R_gdk_content_serializer_get_mime_type", (DL_FUNC) &R_gdk_content_serializer_get_mime_type, 1},
    {"R_gdk_content_serializer_get_output_stream", (DL_FUNC) &R_gdk_content_serializer_get_output_stream, 1},
    {"R_gdk_content_serializer_get_priority", (DL_FUNC) &R_gdk_content_serializer_get_priority, 1},
    {"R_gdk_content_serializer_get_task_data", (DL_FUNC) &R_gdk_content_serializer_get_task_data, 1},
    {"R_gdk_content_serializer_get_user_data", (DL_FUNC) &R_gdk_content_serializer_get_user_data, 1},
    {"R_gdk_content_serializer_get_value", (DL_FUNC) &R_gdk_content_serializer_get_value, 1},
    {"R_gdk_content_serializer_return_error", (DL_FUNC) &R_gdk_content_serializer_return_error, 2},
    {"R_gdk_content_serializer_return_success", (DL_FUNC) &R_gdk_content_serializer_return_success, 1},
    {"R_gdk_content_serializer_set_task_data", (DL_FUNC) &R_gdk_content_serializer_set_task_data, 3},
    {"R_gdk_crossing_event_get_detail", (DL_FUNC) &R_gdk_crossing_event_get_detail, 1},
    {"R_gdk_crossing_event_get_focus", (DL_FUNC) &R_gdk_crossing_event_get_focus, 1},
    {"R_gdk_crossing_event_get_mode", (DL_FUNC) &R_gdk_crossing_event_get_mode, 1},
    {"R_gdk_cursor_new_from_name", (DL_FUNC) &R_gdk_cursor_new_from_name, 2},
    {"R_gdk_cursor_new_from_texture", (DL_FUNC) &R_gdk_cursor_new_from_texture, 4},
    {"R_gdk_cursor_get_fallback", (DL_FUNC) &R_gdk_cursor_get_fallback, 1},
    {"R_gdk_cursor_get_hotspot_x", (DL_FUNC) &R_gdk_cursor_get_hotspot_x, 1},
    {"R_gdk_cursor_get_hotspot_y", (DL_FUNC) &R_gdk_cursor_get_hotspot_y, 1},
    {"R_gdk_cursor_get_name", (DL_FUNC) &R_gdk_cursor_get_name, 1},
    {"R_gdk_cursor_get_texture", (DL_FUNC) &R_gdk_cursor_get_texture, 1},
    {"R_gdk_dnd_event_get_drop", (DL_FUNC) &R_gdk_dnd_event_get_drop, 1},
    {"R_gdk_device_get_caps_lock_state", (DL_FUNC) &R_gdk_device_get_caps_lock_state, 1},
    {"R_gdk_device_get_device_tool", (DL_FUNC) &R_gdk_device_get_device_tool, 1},
    {"R_gdk_device_get_direction", (DL_FUNC) &R_gdk_device_get_direction, 1},
    {"R_gdk_device_get_display", (DL_FUNC) &R_gdk_device_get_display, 1},
    {"R_gdk_device_get_has_cursor", (DL_FUNC) &R_gdk_device_get_has_cursor, 1},
    {"R_gdk_device_get_modifier_state", (DL_FUNC) &R_gdk_device_get_modifier_state, 1},
    {"R_gdk_device_get_name", (DL_FUNC) &R_gdk_device_get_name, 1},
    {"R_gdk_device_get_num_lock_state", (DL_FUNC) &R_gdk_device_get_num_lock_state, 1},
    {"R_gdk_device_get_num_touches", (DL_FUNC) &R_gdk_device_get_num_touches, 1},
    {"R_gdk_device_get_product_id", (DL_FUNC) &R_gdk_device_get_product_id, 1},
    {"R_gdk_device_get_scroll_lock_state", (DL_FUNC) &R_gdk_device_get_scroll_lock_state, 1},
    {"R_gdk_device_get_seat", (DL_FUNC) &R_gdk_device_get_seat, 1},
    {"R_gdk_device_get_source", (DL_FUNC) &R_gdk_device_get_source, 1},
    {"R_gdk_device_get_surface_at_position", (DL_FUNC) &R_gdk_device_get_surface_at_position, 1},
    {"R_gdk_device_get_timestamp", (DL_FUNC) &R_gdk_device_get_timestamp, 1},
    {"R_gdk_device_get_vendor_id", (DL_FUNC) &R_gdk_device_get_vendor_id, 1},
    {"R_gdk_device_has_bidi_layouts", (DL_FUNC) &R_gdk_device_has_bidi_layouts, 1},
    {"R_gdk_device_pad_get_feature_group", (DL_FUNC) &R_gdk_device_pad_get_feature_group, 3},
    {"R_gdk_device_pad_get_group_n_modes", (DL_FUNC) &R_gdk_device_pad_get_group_n_modes, 2},
    {"R_gdk_device_pad_get_n_features", (DL_FUNC) &R_gdk_device_pad_get_n_features, 2},
    {"R_gdk_device_pad_get_n_groups", (DL_FUNC) &R_gdk_device_pad_get_n_groups, 1},
    {"R_gdk_device_tool_get_axes", (DL_FUNC) &R_gdk_device_tool_get_axes, 1},
    {"R_gdk_device_tool_get_hardware_id", (DL_FUNC) &R_gdk_device_tool_get_hardware_id, 1},
    {"R_gdk_device_tool_get_serial", (DL_FUNC) &R_gdk_device_tool_get_serial, 1},
    {"R_gdk_device_tool_get_tool_type", (DL_FUNC) &R_gdk_device_tool_get_tool_type, 1},
    {"R_gdk_display_get_default", (DL_FUNC) &R_gdk_display_get_default, 0},
    {"R_gdk_display_open", (DL_FUNC) &R_gdk_display_open, 1},
    {"R_gdk_display_beep", (DL_FUNC) &R_gdk_display_beep, 1},
    {"R_gdk_display_close", (DL_FUNC) &R_gdk_display_close, 1},
    {"R_gdk_display_create_gl_context", (DL_FUNC) &R_gdk_display_create_gl_context, 1},
    {"R_gdk_display_device_is_grabbed", (DL_FUNC) &R_gdk_display_device_is_grabbed, 2},
    {"R_gdk_display_flush", (DL_FUNC) &R_gdk_display_flush, 1},
    {"R_gdk_display_get_app_launch_context", (DL_FUNC) &R_gdk_display_get_app_launch_context, 1},
    {"R_gdk_display_get_clipboard", (DL_FUNC) &R_gdk_display_get_clipboard, 1},
    {"R_gdk_display_get_default_seat", (DL_FUNC) &R_gdk_display_get_default_seat, 1},
    {"R_gdk_display_get_monitor_at_surface", (DL_FUNC) &R_gdk_display_get_monitor_at_surface, 2},
    {"R_gdk_display_get_monitors", (DL_FUNC) &R_gdk_display_get_monitors, 1},
    {"R_gdk_display_get_name", (DL_FUNC) &R_gdk_display_get_name, 1},
    {"R_gdk_display_get_primary_clipboard", (DL_FUNC) &R_gdk_display_get_primary_clipboard, 1},
    {"R_gdk_display_get_setting", (DL_FUNC) &R_gdk_display_get_setting, 3},
    {"R_gdk_display_get_startup_notification_id", (DL_FUNC) &R_gdk_display_get_startup_notification_id, 1},
    {"R_gdk_display_is_closed", (DL_FUNC) &R_gdk_display_is_closed, 1},
    {"R_gdk_display_is_composited", (DL_FUNC) &R_gdk_display_is_composited, 1},
    {"R_gdk_display_is_rgba", (DL_FUNC) &R_gdk_display_is_rgba, 1},
    {"R_gdk_display_list_seats", (DL_FUNC) &R_gdk_display_list_seats, 1},
    {"R_gdk_display_map_keycode", (DL_FUNC) &R_gdk_display_map_keycode, 2},
    {"R_gdk_display_map_keyval", (DL_FUNC) &R_gdk_display_map_keyval, 2},
    {"R_gdk_display_notify_startup_complete", (DL_FUNC) &R_gdk_display_notify_startup_complete, 2},
    {"R_gdk_display_prepare_gl", (DL_FUNC) &R_gdk_display_prepare_gl, 1},
    {"R_gdk_display_put_event", (DL_FUNC) &R_gdk_display_put_event, 2},
    {"R_gdk_display_supports_input_shapes", (DL_FUNC) &R_gdk_display_supports_input_shapes, 1},
    {"R_gdk_display_sync", (DL_FUNC) &R_gdk_display_sync, 1},
    {"R_gdk_display_translate_key", (DL_FUNC) &R_gdk_display_translate_key, 4},
    {"R_gdk_display_manager_get", (DL_FUNC) &R_gdk_display_manager_get, 0},
    {"R_gdk_display_manager_get_default_display", (DL_FUNC) &R_gdk_display_manager_get_default_display, 1},
    {"R_gdk_display_manager_list_displays", (DL_FUNC) &R_gdk_display_manager_list_displays, 1},
    {"R_gdk_display_manager_open_display", (DL_FUNC) &R_gdk_display_manager_open_display, 2},
    {"R_gdk_display_manager_set_default_display", (DL_FUNC) &R_gdk_display_manager_set_default_display, 2},
    {"R_gdk_dmabuf_error_quark", (DL_FUNC) &R_gdk_dmabuf_error_quark, 0},
    {"R_gdk_drag_begin", (DL_FUNC) &R_gdk_drag_begin, 6},
    {"R_gdk_drag_drop_done", (DL_FUNC) &R_gdk_drag_drop_done, 2},
    {"R_gdk_drag_get_actions", (DL_FUNC) &R_gdk_drag_get_actions, 1},
    {"R_gdk_drag_get_content", (DL_FUNC) &R_gdk_drag_get_content, 1},
    {"R_gdk_drag_get_device", (DL_FUNC) &R_gdk_drag_get_device, 1},
    {"R_gdk_drag_get_display", (DL_FUNC) &R_gdk_drag_get_display, 1},
    {"R_gdk_drag_get_drag_surface", (DL_FUNC) &R_gdk_drag_get_drag_surface, 1},
    {"R_gdk_drag_get_formats", (DL_FUNC) &R_gdk_drag_get_formats, 1},
    {"R_gdk_drag_get_selected_action", (DL_FUNC) &R_gdk_drag_get_selected_action, 1},
    {"R_gdk_drag_get_surface", (DL_FUNC) &R_gdk_drag_get_surface, 1},
    {"R_gdk_drag_set_hotspot", (DL_FUNC) &R_gdk_drag_set_hotspot, 3},
    {"R_gdk_drag_action_is_unique", (DL_FUNC) &R_gdk_drag_action_is_unique, 1},
    {"R_gdk_drag_surface_present", (DL_FUNC) &R_gdk_drag_surface_present, 3},
    {"R_gdk_drag_surface_size_set_size", (DL_FUNC) &R_gdk_drag_surface_size_set_size, 3},
    {"R_gdk_draw_context_begin_frame", (DL_FUNC) &R_gdk_draw_context_begin_frame, 2},
    {"R_gdk_draw_context_end_frame", (DL_FUNC) &R_gdk_draw_context_end_frame, 1},
    {"R_gdk_draw_context_get_display", (DL_FUNC) &R_gdk_draw_context_get_display, 1},
    {"R_gdk_draw_context_get_frame_region", (DL_FUNC) &R_gdk_draw_context_get_frame_region, 1},
    {"R_gdk_draw_context_get_surface", (DL_FUNC) &R_gdk_draw_context_get_surface, 1},
    {"R_gdk_draw_context_is_in_frame", (DL_FUNC) &R_gdk_draw_context_is_in_frame, 1},
    {"R_gdk_drop_finish", (DL_FUNC) &R_gdk_drop_finish, 2},
    {"R_gdk_drop_get_actions", (DL_FUNC) &R_gdk_drop_get_actions, 1},
    {"R_gdk_drop_get_device", (DL_FUNC) &R_gdk_drop_get_device, 1},
    {"R_gdk_drop_get_display", (DL_FUNC) &R_gdk_drop_get_display, 1},
    {"R_gdk_drop_get_drag", (DL_FUNC) &R_gdk_drop_get_drag, 1},
    {"R_gdk_drop_get_formats", (DL_FUNC) &R_gdk_drop_get_formats, 1},
    {"R_gdk_drop_get_surface", (DL_FUNC) &R_gdk_drop_get_surface, 1},
    {"R_gdk_drop_read_async", (DL_FUNC) &R_gdk_drop_read_async, 6},
    {"R_gdk_drop_read_finish", (DL_FUNC) &R_gdk_drop_read_finish, 2},
    {"R_gdk_drop_read_value_async", (DL_FUNC) &R_gdk_drop_read_value_async, 6},
    {"R_gdk_drop_read_value_finish", (DL_FUNC) &R_gdk_drop_read_value_finish, 2},
    {"R_gdk_drop_status", (DL_FUNC) &R_gdk_drop_status, 3},
    {"R_gdk_event_get_axes", (DL_FUNC) &R_gdk_event_get_axes, 1},
    {"R_gdk_event_get_axis", (DL_FUNC) &R_gdk_event_get_axis, 2},
    {"R_gdk_event_get_device", (DL_FUNC) &R_gdk_event_get_device, 1},
    {"R_gdk_event_get_device_tool", (DL_FUNC) &R_gdk_event_get_device_tool, 1},
    {"R_gdk_event_get_display", (DL_FUNC) &R_gdk_event_get_display, 1},
    {"R_gdk_event_get_event_sequence", (DL_FUNC) &R_gdk_event_get_event_sequence, 1},
    {"R_gdk_event_get_event_type", (DL_FUNC) &R_gdk_event_get_event_type, 1},
    {"R_gdk_event_get_history", (DL_FUNC) &R_gdk_event_get_history, 1},
    {"R_gdk_event_get_modifier_state", (DL_FUNC) &R_gdk_event_get_modifier_state, 1},
    {"R_gdk_event_get_pointer_emulated", (DL_FUNC) &R_gdk_event_get_pointer_emulated, 1},
    {"R_gdk_event_get_position", (DL_FUNC) &R_gdk_event_get_position, 1},
    {"R_gdk_event_get_seat", (DL_FUNC) &R_gdk_event_get_seat, 1},
    {"R_gdk_event_get_surface", (DL_FUNC) &R_gdk_event_get_surface, 1},
    {"R_gdk_event_get_time", (DL_FUNC) &R_gdk_event_get_time, 1},
    {"R_gdk_event_ref", (DL_FUNC) &R_gdk_event_ref, 1},
    {"R_gdk_event_triggers_context_menu", (DL_FUNC) &R_gdk_event_triggers_context_menu, 1},
    {"R_gdk_event_unref", (DL_FUNC) &R_gdk_event_unref, 1},
    {"R_gdk_file_list_new_from_array", (DL_FUNC) &R_gdk_file_list_new_from_array, 2},
    {"R_gdk_file_list_new_from_list", (DL_FUNC) &R_gdk_file_list_new_from_list, 1},
    {"R_gdk_file_list_get_files", (DL_FUNC) &R_gdk_file_list_get_files, 1},
    {"R_gdk_focus_event_get_in", (DL_FUNC) &R_gdk_focus_event_get_in, 1},
    {"R_gdk_frame_clock_begin_updating", (DL_FUNC) &R_gdk_frame_clock_begin_updating, 1},
    {"R_gdk_frame_clock_end_updating", (DL_FUNC) &R_gdk_frame_clock_end_updating, 1},
    {"R_gdk_frame_clock_get_current_timings", (DL_FUNC) &R_gdk_frame_clock_get_current_timings, 1},
    {"R_gdk_frame_clock_get_fps", (DL_FUNC) &R_gdk_frame_clock_get_fps, 1},
    {"R_gdk_frame_clock_get_frame_counter", (DL_FUNC) &R_gdk_frame_clock_get_frame_counter, 1},
    {"R_gdk_frame_clock_get_frame_time", (DL_FUNC) &R_gdk_frame_clock_get_frame_time, 1},
    {"R_gdk_frame_clock_get_history_start", (DL_FUNC) &R_gdk_frame_clock_get_history_start, 1},
    {"R_gdk_frame_clock_get_refresh_info", (DL_FUNC) &R_gdk_frame_clock_get_refresh_info, 2},
    {"R_gdk_frame_clock_get_timings", (DL_FUNC) &R_gdk_frame_clock_get_timings, 2},
    {"R_gdk_frame_clock_request_phase", (DL_FUNC) &R_gdk_frame_clock_request_phase, 2},
    {"R_gdk_frame_timings_get_complete", (DL_FUNC) &R_gdk_frame_timings_get_complete, 1},
    {"R_gdk_frame_timings_get_frame_counter", (DL_FUNC) &R_gdk_frame_timings_get_frame_counter, 1},
    {"R_gdk_frame_timings_get_frame_time", (DL_FUNC) &R_gdk_frame_timings_get_frame_time, 1},
    {"R_gdk_frame_timings_get_predicted_presentation_time", (DL_FUNC) &R_gdk_frame_timings_get_predicted_presentation_time, 1},
    {"R_gdk_frame_timings_get_presentation_time", (DL_FUNC) &R_gdk_frame_timings_get_presentation_time, 1},
    {"R_gdk_frame_timings_get_refresh_interval", (DL_FUNC) &R_gdk_frame_timings_get_refresh_interval, 1},
    {"R_gdk_frame_timings_ref", (DL_FUNC) &R_gdk_frame_timings_ref, 1},
    {"R_gdk_frame_timings_unref", (DL_FUNC) &R_gdk_frame_timings_unref, 1},
    {"R_gdk_gl_context_clear_current", (DL_FUNC) &R_gdk_gl_context_clear_current, 0},
    {"R_gdk_gl_context_get_current", (DL_FUNC) &R_gdk_gl_context_get_current, 0},
    {"R_gdk_gl_context_get_allowed_apis", (DL_FUNC) &R_gdk_gl_context_get_allowed_apis, 1},
    {"R_gdk_gl_context_get_api", (DL_FUNC) &R_gdk_gl_context_get_api, 1},
    {"R_gdk_gl_context_get_debug_enabled", (DL_FUNC) &R_gdk_gl_context_get_debug_enabled, 1},
    {"R_gdk_gl_context_get_display", (DL_FUNC) &R_gdk_gl_context_get_display, 1},
    {"R_gdk_gl_context_get_forward_compatible", (DL_FUNC) &R_gdk_gl_context_get_forward_compatible, 1},
    {"R_gdk_gl_context_get_required_version", (DL_FUNC) &R_gdk_gl_context_get_required_version, 1},
    {"R_gdk_gl_context_get_shared_context", (DL_FUNC) &R_gdk_gl_context_get_shared_context, 1},
    {"R_gdk_gl_context_get_surface", (DL_FUNC) &R_gdk_gl_context_get_surface, 1},
    {"R_gdk_gl_context_get_use_es", (DL_FUNC) &R_gdk_gl_context_get_use_es, 1},
    {"R_gdk_gl_context_get_version", (DL_FUNC) &R_gdk_gl_context_get_version, 1},
    {"R_gdk_gl_context_is_legacy", (DL_FUNC) &R_gdk_gl_context_is_legacy, 1},
    {"R_gdk_gl_context_is_shared", (DL_FUNC) &R_gdk_gl_context_is_shared, 2},
    {"R_gdk_gl_context_make_current", (DL_FUNC) &R_gdk_gl_context_make_current, 1},
    {"R_gdk_gl_context_realize", (DL_FUNC) &R_gdk_gl_context_realize, 1},
    {"R_gdk_gl_context_set_allowed_apis", (DL_FUNC) &R_gdk_gl_context_set_allowed_apis, 2},
    {"R_gdk_gl_context_set_debug_enabled", (DL_FUNC) &R_gdk_gl_context_set_debug_enabled, 2},
    {"R_gdk_gl_context_set_forward_compatible", (DL_FUNC) &R_gdk_gl_context_set_forward_compatible, 2},
    {"R_gdk_gl_context_set_required_version", (DL_FUNC) &R_gdk_gl_context_set_required_version, 3},
    {"R_gdk_gl_context_set_use_es", (DL_FUNC) &R_gdk_gl_context_set_use_es, 2},
    {"R_gdk_gl_error_quark", (DL_FUNC) &R_gdk_gl_error_quark, 0},
    {"R_gdk_gl_texture_new", (DL_FUNC) &R_gdk_gl_texture_new, 6},
    {"R_gdk_gl_texture_release", (DL_FUNC) &R_gdk_gl_texture_release, 1},
    {"R_gdk_gl_texture_builder_new", (DL_FUNC) &R_gdk_gl_texture_builder_new, 0},
    {"R_gdk_gl_texture_builder_build", (DL_FUNC) &R_gdk_gl_texture_builder_build, 3},
    {"R_gdk_gl_texture_builder_get_context", (DL_FUNC) &R_gdk_gl_texture_builder_get_context, 1},
    {"R_gdk_gl_texture_builder_get_format", (DL_FUNC) &R_gdk_gl_texture_builder_get_format, 1},
    {"R_gdk_gl_texture_builder_get_has_mipmap", (DL_FUNC) &R_gdk_gl_texture_builder_get_has_mipmap, 1},
    {"R_gdk_gl_texture_builder_get_height", (DL_FUNC) &R_gdk_gl_texture_builder_get_height, 1},
    {"R_gdk_gl_texture_builder_get_id", (DL_FUNC) &R_gdk_gl_texture_builder_get_id, 1},
    {"R_gdk_gl_texture_builder_get_sync", (DL_FUNC) &R_gdk_gl_texture_builder_get_sync, 1},
    {"R_gdk_gl_texture_builder_get_update_region", (DL_FUNC) &R_gdk_gl_texture_builder_get_update_region, 1},
    {"R_gdk_gl_texture_builder_get_update_texture", (DL_FUNC) &R_gdk_gl_texture_builder_get_update_texture, 1},
    {"R_gdk_gl_texture_builder_get_width", (DL_FUNC) &R_gdk_gl_texture_builder_get_width, 1},
    {"R_gdk_gl_texture_builder_set_context", (DL_FUNC) &R_gdk_gl_texture_builder_set_context, 2},
    {"R_gdk_gl_texture_builder_set_format", (DL_FUNC) &R_gdk_gl_texture_builder_set_format, 2},
    {"R_gdk_gl_texture_builder_set_has_mipmap", (DL_FUNC) &R_gdk_gl_texture_builder_set_has_mipmap, 2},
    {"R_gdk_gl_texture_builder_set_height", (DL_FUNC) &R_gdk_gl_texture_builder_set_height, 2},
    {"R_gdk_gl_texture_builder_set_id", (DL_FUNC) &R_gdk_gl_texture_builder_set_id, 2},
    {"R_gdk_gl_texture_builder_set_sync", (DL_FUNC) &R_gdk_gl_texture_builder_set_sync, 2},
    {"R_gdk_gl_texture_builder_set_update_region", (DL_FUNC) &R_gdk_gl_texture_builder_set_update_region, 2},
    {"R_gdk_gl_texture_builder_set_update_texture", (DL_FUNC) &R_gdk_gl_texture_builder_set_update_texture, 2},
    {"R_gdk_gl_texture_builder_set_width", (DL_FUNC) &R_gdk_gl_texture_builder_set_width, 2},
    {"R_gdk_grab_broken_event_get_grab_surface", (DL_FUNC) &R_gdk_grab_broken_event_get_grab_surface, 1},
    {"R_gdk_grab_broken_event_get_implicit", (DL_FUNC) &R_gdk_grab_broken_event_get_implicit, 1},
    {"R_gdk_key_event_get_consumed_modifiers", (DL_FUNC) &R_gdk_key_event_get_consumed_modifiers, 1},
    {"R_gdk_key_event_get_keycode", (DL_FUNC) &R_gdk_key_event_get_keycode, 1},
    {"R_gdk_key_event_get_keyval", (DL_FUNC) &R_gdk_key_event_get_keyval, 1},
    {"R_gdk_key_event_get_layout", (DL_FUNC) &R_gdk_key_event_get_layout, 1},
    {"R_gdk_key_event_get_level", (DL_FUNC) &R_gdk_key_event_get_level, 1},
    {"R_gdk_key_event_get_match", (DL_FUNC) &R_gdk_key_event_get_match, 1},
    {"R_gdk_key_event_is_modifier", (DL_FUNC) &R_gdk_key_event_is_modifier, 1},
    {"R_gdk_key_event_matches", (DL_FUNC) &R_gdk_key_event_matches, 3},
    {"R_gdk_memory_texture_new", (DL_FUNC) &R_gdk_memory_texture_new, 5},
    {"R_gdk_monitor_get_connector", (DL_FUNC) &R_gdk_monitor_get_connector, 1},
    {"R_gdk_monitor_get_description", (DL_FUNC) &R_gdk_monitor_get_description, 1},
    {"R_gdk_monitor_get_display", (DL_FUNC) &R_gdk_monitor_get_display, 1},
    {"R_gdk_monitor_get_geometry", (DL_FUNC) &R_gdk_monitor_get_geometry, 1},
    {"R_gdk_monitor_get_height_mm", (DL_FUNC) &R_gdk_monitor_get_height_mm, 1},
    {"R_gdk_monitor_get_manufacturer", (DL_FUNC) &R_gdk_monitor_get_manufacturer, 1},
    {"R_gdk_monitor_get_model", (DL_FUNC) &R_gdk_monitor_get_model, 1},
    {"R_gdk_monitor_get_refresh_rate", (DL_FUNC) &R_gdk_monitor_get_refresh_rate, 1},
    {"R_gdk_monitor_get_scale_factor", (DL_FUNC) &R_gdk_monitor_get_scale_factor, 1},
    {"R_gdk_monitor_get_subpixel_layout", (DL_FUNC) &R_gdk_monitor_get_subpixel_layout, 1},
    {"R_gdk_monitor_get_width_mm", (DL_FUNC) &R_gdk_monitor_get_width_mm, 1},
    {"R_gdk_monitor_is_valid", (DL_FUNC) &R_gdk_monitor_is_valid, 1},
    {"R_gdk_pad_event_get_axis_value", (DL_FUNC) &R_gdk_pad_event_get_axis_value, 1},
    {"R_gdk_pad_event_get_button", (DL_FUNC) &R_gdk_pad_event_get_button, 1},
    {"R_gdk_pad_event_get_group_mode", (DL_FUNC) &R_gdk_pad_event_get_group_mode, 1},
    {"R_gdk_paintable_new_empty", (DL_FUNC) &R_gdk_paintable_new_empty, 2},
    {"R_gdk_paintable_compute_concrete_size", (DL_FUNC) &R_gdk_paintable_compute_concrete_size, 5},
    {"R_gdk_paintable_get_current_image", (DL_FUNC) &R_gdk_paintable_get_current_image, 1},
    {"R_gdk_paintable_get_flags", (DL_FUNC) &R_gdk_paintable_get_flags, 1},
    {"R_gdk_paintable_get_intrinsic_aspect_ratio", (DL_FUNC) &R_gdk_paintable_get_intrinsic_aspect_ratio, 1},
    {"R_gdk_paintable_get_intrinsic_height", (DL_FUNC) &R_gdk_paintable_get_intrinsic_height, 1},
    {"R_gdk_paintable_get_intrinsic_width", (DL_FUNC) &R_gdk_paintable_get_intrinsic_width, 1},
    {"R_gdk_paintable_invalidate_contents", (DL_FUNC) &R_gdk_paintable_invalidate_contents, 1},
    {"R_gdk_paintable_invalidate_size", (DL_FUNC) &R_gdk_paintable_invalidate_size, 1},
    {"R_gdk_paintable_snapshot", (DL_FUNC) &R_gdk_paintable_snapshot, 4},
    {"R_gdk_popup_get_autohide", (DL_FUNC) &R_gdk_popup_get_autohide, 1},
    {"R_gdk_popup_get_parent", (DL_FUNC) &R_gdk_popup_get_parent, 1},
    {"R_gdk_popup_get_position_x", (DL_FUNC) &R_gdk_popup_get_position_x, 1},
    {"R_gdk_popup_get_position_y", (DL_FUNC) &R_gdk_popup_get_position_y, 1},
    {"R_gdk_popup_get_rect_anchor", (DL_FUNC) &R_gdk_popup_get_rect_anchor, 1},
    {"R_gdk_popup_get_surface_anchor", (DL_FUNC) &R_gdk_popup_get_surface_anchor, 1},
    {"R_gdk_popup_present", (DL_FUNC) &R_gdk_popup_present, 4},
    {"R_gdk_popup_layout_new", (DL_FUNC) &R_gdk_popup_layout_new, 3},
    {"R_gdk_popup_layout_copy", (DL_FUNC) &R_gdk_popup_layout_copy, 1},
    {"R_gdk_popup_layout_equal", (DL_FUNC) &R_gdk_popup_layout_equal, 2},
    {"R_gdk_popup_layout_get_anchor_hints", (DL_FUNC) &R_gdk_popup_layout_get_anchor_hints, 1},
    {"R_gdk_popup_layout_get_anchor_rect", (DL_FUNC) &R_gdk_popup_layout_get_anchor_rect, 1},
    {"R_gdk_popup_layout_get_offset", (DL_FUNC) &R_gdk_popup_layout_get_offset, 1},
    {"R_gdk_popup_layout_get_rect_anchor", (DL_FUNC) &R_gdk_popup_layout_get_rect_anchor, 1},
    {"R_gdk_popup_layout_get_shadow_width", (DL_FUNC) &R_gdk_popup_layout_get_shadow_width, 1},
    {"R_gdk_popup_layout_get_surface_anchor", (DL_FUNC) &R_gdk_popup_layout_get_surface_anchor, 1},
    {"R_gdk_popup_layout_ref", (DL_FUNC) &R_gdk_popup_layout_ref, 1},
    {"R_gdk_popup_layout_set_anchor_hints", (DL_FUNC) &R_gdk_popup_layout_set_anchor_hints, 2},
    {"R_gdk_popup_layout_set_anchor_rect", (DL_FUNC) &R_gdk_popup_layout_set_anchor_rect, 2},
    {"R_gdk_popup_layout_set_offset", (DL_FUNC) &R_gdk_popup_layout_set_offset, 3},
    {"R_gdk_popup_layout_set_rect_anchor", (DL_FUNC) &R_gdk_popup_layout_set_rect_anchor, 2},
    {"R_gdk_popup_layout_set_shadow_width", (DL_FUNC) &R_gdk_popup_layout_set_shadow_width, 5},
    {"R_gdk_popup_layout_set_surface_anchor", (DL_FUNC) &R_gdk_popup_layout_set_surface_anchor, 2},
    {"R_gdk_popup_layout_unref", (DL_FUNC) &R_gdk_popup_layout_unref, 1},
    {"R_gdk_rgba_copy", (DL_FUNC) &R_gdk_rgba_copy, 1},
    {"R_gdk_rgba_equal", (DL_FUNC) &R_gdk_rgba_equal, 2},
    {"R_gdk_rgba_free", (DL_FUNC) &R_gdk_rgba_free, 1},
    {"R_gdk_rgba_hash", (DL_FUNC) &R_gdk_rgba_hash, 1},
    {"R_gdk_rgba_is_clear", (DL_FUNC) &R_gdk_rgba_is_clear, 1},
    {"R_gdk_rgba_is_opaque", (DL_FUNC) &R_gdk_rgba_is_opaque, 1},
    {"R_gdk_rgba_parse", (DL_FUNC) &R_gdk_rgba_parse, 2},
    {"R_gdk_rgba_to_string", (DL_FUNC) &R_gdk_rgba_to_string, 1},
    {"R_gdk_rectangle_contains_point", (DL_FUNC) &R_gdk_rectangle_contains_point, 3},
    {"R_gdk_rectangle_equal", (DL_FUNC) &R_gdk_rectangle_equal, 2},
    {"R_gdk_rectangle_intersect", (DL_FUNC) &R_gdk_rectangle_intersect, 2},
    {"R_gdk_rectangle_union", (DL_FUNC) &R_gdk_rectangle_union, 2},
    {"R_gdk_scroll_event_get_deltas", (DL_FUNC) &R_gdk_scroll_event_get_deltas, 1},
    {"R_gdk_scroll_event_get_direction", (DL_FUNC) &R_gdk_scroll_event_get_direction, 1},
    {"R_gdk_scroll_event_get_unit", (DL_FUNC) &R_gdk_scroll_event_get_unit, 1},
    {"R_gdk_scroll_event_is_stop", (DL_FUNC) &R_gdk_scroll_event_is_stop, 1},
    {"R_gdk_seat_get_capabilities", (DL_FUNC) &R_gdk_seat_get_capabilities, 1},
    {"R_gdk_seat_get_devices", (DL_FUNC) &R_gdk_seat_get_devices, 2},
    {"R_gdk_seat_get_display", (DL_FUNC) &R_gdk_seat_get_display, 1},
    {"R_gdk_seat_get_keyboard", (DL_FUNC) &R_gdk_seat_get_keyboard, 1},
    {"R_gdk_seat_get_pointer", (DL_FUNC) &R_gdk_seat_get_pointer, 1},
    {"R_gdk_seat_get_tools", (DL_FUNC) &R_gdk_seat_get_tools, 1},
    {"R_gdk_surface_new_popup", (DL_FUNC) &R_gdk_surface_new_popup, 2},
    {"R_gdk_surface_new_toplevel", (DL_FUNC) &R_gdk_surface_new_toplevel, 1},
    {"R_gdk_surface_beep", (DL_FUNC) &R_gdk_surface_beep, 1},
    {"R_gdk_surface_create_cairo_context", (DL_FUNC) &R_gdk_surface_create_cairo_context, 1},
    {"R_gdk_surface_create_gl_context", (DL_FUNC) &R_gdk_surface_create_gl_context, 1},
    {"R_gdk_surface_create_similar_surface", (DL_FUNC) &R_gdk_surface_create_similar_surface, 4},
    {"R_gdk_surface_create_vulkan_context", (DL_FUNC) &R_gdk_surface_create_vulkan_context, 1},
    {"R_gdk_surface_destroy", (DL_FUNC) &R_gdk_surface_destroy, 1},
    {"R_gdk_surface_get_cursor", (DL_FUNC) &R_gdk_surface_get_cursor, 1},
    {"R_gdk_surface_get_device_cursor", (DL_FUNC) &R_gdk_surface_get_device_cursor, 2},
    {"R_gdk_surface_get_device_position", (DL_FUNC) &R_gdk_surface_get_device_position, 2},
    {"R_gdk_surface_get_display", (DL_FUNC) &R_gdk_surface_get_display, 1},
    {"R_gdk_surface_get_frame_clock", (DL_FUNC) &R_gdk_surface_get_frame_clock, 1},
    {"R_gdk_surface_get_height", (DL_FUNC) &R_gdk_surface_get_height, 1},
    {"R_gdk_surface_get_mapped", (DL_FUNC) &R_gdk_surface_get_mapped, 1},
    {"R_gdk_surface_get_scale", (DL_FUNC) &R_gdk_surface_get_scale, 1},
    {"R_gdk_surface_get_scale_factor", (DL_FUNC) &R_gdk_surface_get_scale_factor, 1},
    {"R_gdk_surface_get_width", (DL_FUNC) &R_gdk_surface_get_width, 1},
    {"R_gdk_surface_hide", (DL_FUNC) &R_gdk_surface_hide, 1},
    {"R_gdk_surface_is_destroyed", (DL_FUNC) &R_gdk_surface_is_destroyed, 1},
    {"R_gdk_surface_queue_render", (DL_FUNC) &R_gdk_surface_queue_render, 1},
    {"R_gdk_surface_request_layout", (DL_FUNC) &R_gdk_surface_request_layout, 1},
    {"R_gdk_surface_set_cursor", (DL_FUNC) &R_gdk_surface_set_cursor, 2},
    {"R_gdk_surface_set_device_cursor", (DL_FUNC) &R_gdk_surface_set_device_cursor, 3},
    {"R_gdk_surface_set_input_region", (DL_FUNC) &R_gdk_surface_set_input_region, 2},
    {"R_gdk_surface_set_opaque_region", (DL_FUNC) &R_gdk_surface_set_opaque_region, 2},
    {"R_gdk_surface_translate_coordinates", (DL_FUNC) &R_gdk_surface_translate_coordinates, 2},
    {"R_gdk_texture_new_for_pixbuf", (DL_FUNC) &R_gdk_texture_new_for_pixbuf, 1},
    {"R_gdk_texture_new_from_bytes", (DL_FUNC) &R_gdk_texture_new_from_bytes, 1},
    {"R_gdk_texture_new_from_file", (DL_FUNC) &R_gdk_texture_new_from_file, 1},
    {"R_gdk_texture_new_from_filename", (DL_FUNC) &R_gdk_texture_new_from_filename, 1},
    {"R_gdk_texture_new_from_resource", (DL_FUNC) &R_gdk_texture_new_from_resource, 1},
    {"R_gdk_texture_download", (DL_FUNC) &R_gdk_texture_download, 3},
    {"R_gdk_texture_get_format", (DL_FUNC) &R_gdk_texture_get_format, 1},
    {"R_gdk_texture_get_height", (DL_FUNC) &R_gdk_texture_get_height, 1},
    {"R_gdk_texture_get_width", (DL_FUNC) &R_gdk_texture_get_width, 1},
    {"R_gdk_texture_save_to_png", (DL_FUNC) &R_gdk_texture_save_to_png, 2},
    {"R_gdk_texture_save_to_png_bytes", (DL_FUNC) &R_gdk_texture_save_to_png_bytes, 1},
    {"R_gdk_texture_save_to_tiff", (DL_FUNC) &R_gdk_texture_save_to_tiff, 2},
    {"R_gdk_texture_save_to_tiff_bytes", (DL_FUNC) &R_gdk_texture_save_to_tiff_bytes, 1},
    {"R_gdk_texture_downloader_new", (DL_FUNC) &R_gdk_texture_downloader_new, 1},
    {"R_gdk_texture_downloader_copy", (DL_FUNC) &R_gdk_texture_downloader_copy, 1},
    {"R_gdk_texture_downloader_download_bytes", (DL_FUNC) &R_gdk_texture_downloader_download_bytes, 1},
    {"R_gdk_texture_downloader_download_into", (DL_FUNC) &R_gdk_texture_downloader_download_into, 3},
    {"R_gdk_texture_downloader_free", (DL_FUNC) &R_gdk_texture_downloader_free, 1},
    {"R_gdk_texture_downloader_get_format", (DL_FUNC) &R_gdk_texture_downloader_get_format, 1},
    {"R_gdk_texture_downloader_get_texture", (DL_FUNC) &R_gdk_texture_downloader_get_texture, 1},
    {"R_gdk_texture_downloader_set_format", (DL_FUNC) &R_gdk_texture_downloader_set_format, 2},
    {"R_gdk_texture_downloader_set_texture", (DL_FUNC) &R_gdk_texture_downloader_set_texture, 2},
    {"R_gdk_texture_error_quark", (DL_FUNC) &R_gdk_texture_error_quark, 0},
    {"R_gdk_toplevel_begin_move", (DL_FUNC) &R_gdk_toplevel_begin_move, 6},
    {"R_gdk_toplevel_begin_resize", (DL_FUNC) &R_gdk_toplevel_begin_resize, 7},
    {"R_gdk_toplevel_focus", (DL_FUNC) &R_gdk_toplevel_focus, 2},
    {"R_gdk_toplevel_get_state", (DL_FUNC) &R_gdk_toplevel_get_state, 1},
    {"R_gdk_toplevel_inhibit_system_shortcuts", (DL_FUNC) &R_gdk_toplevel_inhibit_system_shortcuts, 2},
    {"R_gdk_toplevel_lower", (DL_FUNC) &R_gdk_toplevel_lower, 1},
    {"R_gdk_toplevel_minimize", (DL_FUNC) &R_gdk_toplevel_minimize, 1},
    {"R_gdk_toplevel_present", (DL_FUNC) &R_gdk_toplevel_present, 2},
    {"R_gdk_toplevel_restore_system_shortcuts", (DL_FUNC) &R_gdk_toplevel_restore_system_shortcuts, 1},
    {"R_gdk_toplevel_set_decorated", (DL_FUNC) &R_gdk_toplevel_set_decorated, 2},
    {"R_gdk_toplevel_set_deletable", (DL_FUNC) &R_gdk_toplevel_set_deletable, 2},
    {"R_gdk_toplevel_set_icon_list", (DL_FUNC) &R_gdk_toplevel_set_icon_list, 2},
    {"R_gdk_toplevel_set_modal", (DL_FUNC) &R_gdk_toplevel_set_modal, 2},
    {"R_gdk_toplevel_set_startup_id", (DL_FUNC) &R_gdk_toplevel_set_startup_id, 2},
    {"R_gdk_toplevel_set_title", (DL_FUNC) &R_gdk_toplevel_set_title, 2},
    {"R_gdk_toplevel_set_transient_for", (DL_FUNC) &R_gdk_toplevel_set_transient_for, 2},
    {"R_gdk_toplevel_show_window_menu", (DL_FUNC) &R_gdk_toplevel_show_window_menu, 2},
    {"R_gdk_toplevel_supports_edge_constraints", (DL_FUNC) &R_gdk_toplevel_supports_edge_constraints, 1},
    {"R_gdk_toplevel_titlebar_gesture", (DL_FUNC) &R_gdk_toplevel_titlebar_gesture, 2},
    {"R_gdk_toplevel_layout_new", (DL_FUNC) &R_gdk_toplevel_layout_new, 0},
    {"R_gdk_toplevel_layout_copy", (DL_FUNC) &R_gdk_toplevel_layout_copy, 1},
    {"R_gdk_toplevel_layout_equal", (DL_FUNC) &R_gdk_toplevel_layout_equal, 2},
    {"R_gdk_toplevel_layout_get_fullscreen", (DL_FUNC) &R_gdk_toplevel_layout_get_fullscreen, 1},
    {"R_gdk_toplevel_layout_get_fullscreen_monitor", (DL_FUNC) &R_gdk_toplevel_layout_get_fullscreen_monitor, 1},
    {"R_gdk_toplevel_layout_get_maximized", (DL_FUNC) &R_gdk_toplevel_layout_get_maximized, 1},
    {"R_gdk_toplevel_layout_get_resizable", (DL_FUNC) &R_gdk_toplevel_layout_get_resizable, 1},
    {"R_gdk_toplevel_layout_ref", (DL_FUNC) &R_gdk_toplevel_layout_ref, 1},
    {"R_gdk_toplevel_layout_set_fullscreen", (DL_FUNC) &R_gdk_toplevel_layout_set_fullscreen, 3},
    {"R_gdk_toplevel_layout_set_maximized", (DL_FUNC) &R_gdk_toplevel_layout_set_maximized, 2},
    {"R_gdk_toplevel_layout_set_resizable", (DL_FUNC) &R_gdk_toplevel_layout_set_resizable, 2},
    {"R_gdk_toplevel_layout_unref", (DL_FUNC) &R_gdk_toplevel_layout_unref, 1},
    {"R_gdk_toplevel_size_get_bounds", (DL_FUNC) &R_gdk_toplevel_size_get_bounds, 1},
    {"R_gdk_toplevel_size_set_min_size", (DL_FUNC) &R_gdk_toplevel_size_set_min_size, 3},
    {"R_gdk_toplevel_size_set_shadow_width", (DL_FUNC) &R_gdk_toplevel_size_set_shadow_width, 5},
    {"R_gdk_toplevel_size_set_size", (DL_FUNC) &R_gdk_toplevel_size_set_size, 3},
    {"R_gdk_touch_event_get_emulating_pointer", (DL_FUNC) &R_gdk_touch_event_get_emulating_pointer, 1},
    {"R_gdk_touchpad_event_get_deltas", (DL_FUNC) &R_gdk_touchpad_event_get_deltas, 1},
    {"R_gdk_touchpad_event_get_gesture_phase", (DL_FUNC) &R_gdk_touchpad_event_get_gesture_phase, 1},
    {"R_gdk_touchpad_event_get_n_fingers", (DL_FUNC) &R_gdk_touchpad_event_get_n_fingers, 1},
    {"R_gdk_touchpad_event_get_pinch_angle_delta", (DL_FUNC) &R_gdk_touchpad_event_get_pinch_angle_delta, 1},
    {"R_gdk_touchpad_event_get_pinch_scale", (DL_FUNC) &R_gdk_touchpad_event_get_pinch_scale, 1},
    {"R_gdk_vulkan_error_quark", (DL_FUNC) &R_gdk_vulkan_error_quark, 0},
    {"R_gdk_cairo_draw_from_gl", (DL_FUNC) &R_gdk_cairo_draw_from_gl, 9},
    {"R_gdk_cairo_rectangle", (DL_FUNC) &R_gdk_cairo_rectangle, 2},
    {"R_gdk_cairo_region", (DL_FUNC) &R_gdk_cairo_region, 2},
    {"R_gdk_cairo_region_create_from_surface", (DL_FUNC) &R_gdk_cairo_region_create_from_surface, 1},
    {"R_gdk_cairo_set_source_pixbuf", (DL_FUNC) &R_gdk_cairo_set_source_pixbuf, 4},
    {"R_gdk_cairo_set_source_rgba", (DL_FUNC) &R_gdk_cairo_set_source_rgba, 2},
    {"R_gdk_content_deserialize_async", (DL_FUNC) &R_gdk_content_deserialize_async, 7},
    {"R_gdk_content_deserialize_finish", (DL_FUNC) &R_gdk_content_deserialize_finish, 1},
    {"R_gdk_content_register_deserializer", (DL_FUNC) &R_gdk_content_register_deserializer, 5},
    {"R_gdk_content_register_serializer", (DL_FUNC) &R_gdk_content_register_serializer, 5},
    {"R_gdk_content_serialize_async", (DL_FUNC) &R_gdk_content_serialize_async, 7},
    {"R_gdk_content_serialize_finish", (DL_FUNC) &R_gdk_content_serialize_finish, 1},
    {"R_gdk_intern_mime_type", (DL_FUNC) &R_gdk_intern_mime_type, 1},
    {"R_gdk_keyval_convert_case", (DL_FUNC) &R_gdk_keyval_convert_case, 1},
    {"R_gdk_keyval_from_name", (DL_FUNC) &R_gdk_keyval_from_name, 1},
    {"R_gdk_keyval_is_lower", (DL_FUNC) &R_gdk_keyval_is_lower, 1},
    {"R_gdk_keyval_is_upper", (DL_FUNC) &R_gdk_keyval_is_upper, 1},
    {"R_gdk_keyval_name", (DL_FUNC) &R_gdk_keyval_name, 1},
    {"R_gdk_keyval_to_lower", (DL_FUNC) &R_gdk_keyval_to_lower, 1},
    {"R_gdk_keyval_to_unicode", (DL_FUNC) &R_gdk_keyval_to_unicode, 1},
    {"R_gdk_keyval_to_upper", (DL_FUNC) &R_gdk_keyval_to_upper, 1},
    {"R_gdk_pixbuf_get_from_surface", (DL_FUNC) &R_gdk_pixbuf_get_from_surface, 5},
    {"R_gdk_pixbuf_get_from_texture", (DL_FUNC) &R_gdk_pixbuf_get_from_texture, 1},
    {"R_gdk_set_allowed_backends", (DL_FUNC) &R_gdk_set_allowed_backends, 1},
    {"R_gdk_unicode_to_keyval", (DL_FUNC) &R_gdk_unicode_to_keyval, 1},
    {"R_g_action_name_is_valid", (DL_FUNC) &R_g_action_name_is_valid, 1},
    {"R_g_action_parse_detailed_name", (DL_FUNC) &R_g_action_parse_detailed_name, 1},
    {"R_g_action_print_detailed_name", (DL_FUNC) &R_g_action_print_detailed_name, 2},
    {"R_g_action_activate", (DL_FUNC) &R_g_action_activate, 2},
    {"R_g_action_change_state", (DL_FUNC) &R_g_action_change_state, 2},
    {"R_g_action_get_enabled", (DL_FUNC) &R_g_action_get_enabled, 1},
    {"R_g_action_get_name", (DL_FUNC) &R_g_action_get_name, 1},
    {"R_g_action_get_parameter_type", (DL_FUNC) &R_g_action_get_parameter_type, 1},
    {"R_g_action_get_state", (DL_FUNC) &R_g_action_get_state, 1},
    {"R_g_action_get_state_hint", (DL_FUNC) &R_g_action_get_state_hint, 1},
    {"R_g_action_get_state_type", (DL_FUNC) &R_g_action_get_state_type, 1},
    {"R_g_action_group_action_added", (DL_FUNC) &R_g_action_group_action_added, 2},
    {"R_g_action_group_action_enabled_changed", (DL_FUNC) &R_g_action_group_action_enabled_changed, 3},
    {"R_g_action_group_action_removed", (DL_FUNC) &R_g_action_group_action_removed, 2},
    {"R_g_action_group_action_state_changed", (DL_FUNC) &R_g_action_group_action_state_changed, 3},
    {"R_g_action_group_activate_action", (DL_FUNC) &R_g_action_group_activate_action, 3},
    {"R_g_action_group_change_action_state", (DL_FUNC) &R_g_action_group_change_action_state, 3},
    {"R_g_action_group_get_action_enabled", (DL_FUNC) &R_g_action_group_get_action_enabled, 2},
    {"R_g_action_group_get_action_parameter_type", (DL_FUNC) &R_g_action_group_get_action_parameter_type, 2},
    {"R_g_action_group_get_action_state", (DL_FUNC) &R_g_action_group_get_action_state, 2},
    {"R_g_action_group_get_action_state_hint", (DL_FUNC) &R_g_action_group_get_action_state_hint, 2},
    {"R_g_action_group_get_action_state_type", (DL_FUNC) &R_g_action_group_get_action_state_type, 2},
    {"R_g_action_group_has_action", (DL_FUNC) &R_g_action_group_has_action, 2},
    {"R_g_action_group_list_actions", (DL_FUNC) &R_g_action_group_list_actions, 1},
    {"R_g_action_group_query_action", (DL_FUNC) &R_g_action_group_query_action, 2},
    {"R_g_action_map_add_action", (DL_FUNC) &R_g_action_map_add_action, 2},
    {"R_g_action_map_add_action_entries", (DL_FUNC) &R_g_action_map_add_action_entries, 4},
    {"R_g_action_map_lookup_action", (DL_FUNC) &R_g_action_map_lookup_action, 2},
    {"R_g_action_map_remove_action", (DL_FUNC) &R_g_action_map_remove_action, 2},
    {"R_g_app_info_create_from_commandline", (DL_FUNC) &R_g_app_info_create_from_commandline, 3},
    {"R_g_app_info_get_all", (DL_FUNC) &R_g_app_info_get_all, 0},
    {"R_g_app_info_get_all_for_type", (DL_FUNC) &R_g_app_info_get_all_for_type, 1},
    {"R_g_app_info_get_default_for_type", (DL_FUNC) &R_g_app_info_get_default_for_type, 2},
    {"R_g_app_info_get_default_for_uri_scheme", (DL_FUNC) &R_g_app_info_get_default_for_uri_scheme, 1},
    {"R_g_app_info_get_fallback_for_type", (DL_FUNC) &R_g_app_info_get_fallback_for_type, 1},
    {"R_g_app_info_get_recommended_for_type", (DL_FUNC) &R_g_app_info_get_recommended_for_type, 1},
    {"R_g_app_info_launch_default_for_uri", (DL_FUNC) &R_g_app_info_launch_default_for_uri, 2},
    {"R_g_app_info_launch_default_for_uri_async", (DL_FUNC) &R_g_app_info_launch_default_for_uri_async, 5},
    {"R_g_app_info_launch_default_for_uri_finish", (DL_FUNC) &R_g_app_info_launch_default_for_uri_finish, 1},
    {"R_g_app_info_reset_type_associations", (DL_FUNC) &R_g_app_info_reset_type_associations, 1},
    {"R_g_app_info_add_supports_type", (DL_FUNC) &R_g_app_info_add_supports_type, 2},
    {"R_g_app_info_can_delete", (DL_FUNC) &R_g_app_info_can_delete, 1},
    {"R_g_app_info_can_remove_supports_type", (DL_FUNC) &R_g_app_info_can_remove_supports_type, 1},
    {"R_g_app_info_delete", (DL_FUNC) &R_g_app_info_delete, 1},
    {"R_g_app_info_dup", (DL_FUNC) &R_g_app_info_dup, 1},
    {"R_g_app_info_equal", (DL_FUNC) &R_g_app_info_equal, 2},
    {"R_g_app_info_get_commandline", (DL_FUNC) &R_g_app_info_get_commandline, 1},
    {"R_g_app_info_get_description", (DL_FUNC) &R_g_app_info_get_description, 1},
    {"R_g_app_info_get_display_name", (DL_FUNC) &R_g_app_info_get_display_name, 1},
    {"R_g_app_info_get_executable", (DL_FUNC) &R_g_app_info_get_executable, 1},
    {"R_g_app_info_get_icon", (DL_FUNC) &R_g_app_info_get_icon, 1},
    {"R_g_app_info_get_id", (DL_FUNC) &R_g_app_info_get_id, 1},
    {"R_g_app_info_get_name", (DL_FUNC) &R_g_app_info_get_name, 1},
    {"R_g_app_info_get_supported_types", (DL_FUNC) &R_g_app_info_get_supported_types, 1},
    {"R_g_app_info_launch", (DL_FUNC) &R_g_app_info_launch, 3},
    {"R_g_app_info_launch_uris", (DL_FUNC) &R_g_app_info_launch_uris, 3},
    {"R_g_app_info_remove_supports_type", (DL_FUNC) &R_g_app_info_remove_supports_type, 2},
    {"R_g_app_info_set_as_default_for_extension", (DL_FUNC) &R_g_app_info_set_as_default_for_extension, 2},
    {"R_g_app_info_set_as_default_for_type", (DL_FUNC) &R_g_app_info_set_as_default_for_type, 2},
    {"R_g_app_info_set_as_last_used_for_type", (DL_FUNC) &R_g_app_info_set_as_last_used_for_type, 2},
    {"R_g_app_info_should_show", (DL_FUNC) &R_g_app_info_should_show, 1},
    {"R_g_app_info_supports_files", (DL_FUNC) &R_g_app_info_supports_files, 1},
    {"R_g_app_info_supports_uris", (DL_FUNC) &R_g_app_info_supports_uris, 1},
    {"R_g_app_info_monitor_get", (DL_FUNC) &R_g_app_info_monitor_get, 0},
    {"R_g_app_launch_context_new", (DL_FUNC) &R_g_app_launch_context_new, 0},
    {"R_g_app_launch_context_get_display", (DL_FUNC) &R_g_app_launch_context_get_display, 3},
    {"R_g_app_launch_context_get_environment", (DL_FUNC) &R_g_app_launch_context_get_environment, 1},
    {"R_g_app_launch_context_get_startup_notify_id", (DL_FUNC) &R_g_app_launch_context_get_startup_notify_id, 3},
    {"R_g_app_launch_context_launch_failed", (DL_FUNC) &R_g_app_launch_context_launch_failed, 2},
    {"R_g_app_launch_context_setenv", (DL_FUNC) &R_g_app_launch_context_setenv, 3},
    {"R_g_app_launch_context_unsetenv", (DL_FUNC) &R_g_app_launch_context_unsetenv, 2},
    {"R_g_application_new", (DL_FUNC) &R_g_application_new, 2},
    {"R_g_application_get_default", (DL_FUNC) &R_g_application_get_default, 0},
    {"R_g_application_id_is_valid", (DL_FUNC) &R_g_application_id_is_valid, 1},
    {"R_g_application_activate", (DL_FUNC) &R_g_application_activate, 1},
    {"R_g_application_add_main_option", (DL_FUNC) &R_g_application_add_main_option, 7},
    {"R_g_application_add_main_option_entries", (DL_FUNC) &R_g_application_add_main_option_entries, 2},
    {"R_g_application_add_option_group", (DL_FUNC) &R_g_application_add_option_group, 2},
    {"R_g_application_bind_busy_property", (DL_FUNC) &R_g_application_bind_busy_property, 3},
    {"R_g_application_get_application_id", (DL_FUNC) &R_g_application_get_application_id, 1},
    {"R_g_application_get_dbus_connection", (DL_FUNC) &R_g_application_get_dbus_connection, 1},
    {"R_g_application_get_dbus_object_path", (DL_FUNC) &R_g_application_get_dbus_object_path, 1},
    {"R_g_application_get_flags", (DL_FUNC) &R_g_application_get_flags, 1},
    {"R_g_application_get_inactivity_timeout", (DL_FUNC) &R_g_application_get_inactivity_timeout, 1},
    {"R_g_application_get_is_busy", (DL_FUNC) &R_g_application_get_is_busy, 1},
    {"R_g_application_get_is_registered", (DL_FUNC) &R_g_application_get_is_registered, 1},
    {"R_g_application_get_is_remote", (DL_FUNC) &R_g_application_get_is_remote, 1},
    {"R_g_application_get_resource_base_path", (DL_FUNC) &R_g_application_get_resource_base_path, 1},
    {"R_g_application_hold", (DL_FUNC) &R_g_application_hold, 1},
    {"R_g_application_mark_busy", (DL_FUNC) &R_g_application_mark_busy, 1},
    {"R_g_application_open", (DL_FUNC) &R_g_application_open, 4},
    {"R_g_application_quit", (DL_FUNC) &R_g_application_quit, 1},
    {"R_g_application_register", (DL_FUNC) &R_g_application_register, 2},
    {"R_g_application_release", (DL_FUNC) &R_g_application_release, 1},
    {"R_g_application_run", (DL_FUNC) &R_g_application_run, 3},
    {"R_g_application_send_notification", (DL_FUNC) &R_g_application_send_notification, 3},
    {"R_g_application_set_action_group", (DL_FUNC) &R_g_application_set_action_group, 2},
    {"R_g_application_set_application_id", (DL_FUNC) &R_g_application_set_application_id, 2},
    {"R_g_application_set_default", (DL_FUNC) &R_g_application_set_default, 1},
    {"R_g_application_set_flags", (DL_FUNC) &R_g_application_set_flags, 2},
    {"R_g_application_set_inactivity_timeout", (DL_FUNC) &R_g_application_set_inactivity_timeout, 2},
    {"R_g_application_set_option_context_description", (DL_FUNC) &R_g_application_set_option_context_description, 2},
    {"R_g_application_set_option_context_parameter_string", (DL_FUNC) &R_g_application_set_option_context_parameter_string, 2},
    {"R_g_application_set_option_context_summary", (DL_FUNC) &R_g_application_set_option_context_summary, 2},
    {"R_g_application_set_resource_base_path", (DL_FUNC) &R_g_application_set_resource_base_path, 2},
    {"R_g_application_unbind_busy_property", (DL_FUNC) &R_g_application_unbind_busy_property, 3},
    {"R_g_application_unmark_busy", (DL_FUNC) &R_g_application_unmark_busy, 1},
    {"R_g_application_withdraw_notification", (DL_FUNC) &R_g_application_withdraw_notification, 2},
    {"R_g_application_command_line_create_file_for_arg", (DL_FUNC) &R_g_application_command_line_create_file_for_arg, 2},
    {"R_g_application_command_line_get_arguments", (DL_FUNC) &R_g_application_command_line_get_arguments, 1},
    {"R_g_application_command_line_get_cwd", (DL_FUNC) &R_g_application_command_line_get_cwd, 1},
    {"R_g_application_command_line_get_environ", (DL_FUNC) &R_g_application_command_line_get_environ, 1},
    {"R_g_application_command_line_get_exit_status", (DL_FUNC) &R_g_application_command_line_get_exit_status, 1},
    {"R_g_application_command_line_get_is_remote", (DL_FUNC) &R_g_application_command_line_get_is_remote, 1},
    {"R_g_application_command_line_get_options_dict", (DL_FUNC) &R_g_application_command_line_get_options_dict, 1},
    {"R_g_application_command_line_get_platform_data", (DL_FUNC) &R_g_application_command_line_get_platform_data, 1},
    {"R_g_application_command_line_get_stdin", (DL_FUNC) &R_g_application_command_line_get_stdin, 1},
    {"R_g_application_command_line_getenv", (DL_FUNC) &R_g_application_command_line_getenv, 2},
    {"R_g_application_command_line_set_exit_status", (DL_FUNC) &R_g_application_command_line_set_exit_status, 2},
    {"R_g_async_initable_newv_async", (DL_FUNC) &R_g_async_initable_newv_async, 7},
    {"R_g_async_initable_init_async", (DL_FUNC) &R_g_async_initable_init_async, 5},
    {"R_g_async_initable_init_finish", (DL_FUNC) &R_g_async_initable_init_finish, 2},
    {"R_g_async_initable_new_finish", (DL_FUNC) &R_g_async_initable_new_finish, 2},
    {"R_g_async_result_get_source_object", (DL_FUNC) &R_g_async_result_get_source_object, 1},
    {"R_g_async_result_get_user_data", (DL_FUNC) &R_g_async_result_get_user_data, 1},
    {"R_g_async_result_is_tagged", (DL_FUNC) &R_g_async_result_is_tagged, 2},
    {"R_g_async_result_legacy_propagate_error", (DL_FUNC) &R_g_async_result_legacy_propagate_error, 1},
    {"R_g_buffered_input_stream_new", (DL_FUNC) &R_g_buffered_input_stream_new, 1},
    {"R_g_buffered_input_stream_new_sized", (DL_FUNC) &R_g_buffered_input_stream_new_sized, 2},
    {"R_g_buffered_input_stream_fill", (DL_FUNC) &R_g_buffered_input_stream_fill, 3},
    {"R_g_buffered_input_stream_fill_async", (DL_FUNC) &R_g_buffered_input_stream_fill_async, 6},
    {"R_g_buffered_input_stream_fill_finish", (DL_FUNC) &R_g_buffered_input_stream_fill_finish, 2},
    {"R_g_buffered_input_stream_get_available", (DL_FUNC) &R_g_buffered_input_stream_get_available, 1},
    {"R_g_buffered_input_stream_get_buffer_size", (DL_FUNC) &R_g_buffered_input_stream_get_buffer_size, 1},
    {"R_g_buffered_input_stream_peek", (DL_FUNC) &R_g_buffered_input_stream_peek, 4},
    {"R_g_buffered_input_stream_peek_buffer", (DL_FUNC) &R_g_buffered_input_stream_peek_buffer, 1},
    {"R_g_buffered_input_stream_read_byte", (DL_FUNC) &R_g_buffered_input_stream_read_byte, 2},
    {"R_g_buffered_input_stream_set_buffer_size", (DL_FUNC) &R_g_buffered_input_stream_set_buffer_size, 2},
    {"R_g_buffered_output_stream_new", (DL_FUNC) &R_g_buffered_output_stream_new, 1},
    {"R_g_buffered_output_stream_new_sized", (DL_FUNC) &R_g_buffered_output_stream_new_sized, 2},
    {"R_g_buffered_output_stream_get_auto_grow", (DL_FUNC) &R_g_buffered_output_stream_get_auto_grow, 1},
    {"R_g_buffered_output_stream_get_buffer_size", (DL_FUNC) &R_g_buffered_output_stream_get_buffer_size, 1},
    {"R_g_buffered_output_stream_set_auto_grow", (DL_FUNC) &R_g_buffered_output_stream_set_auto_grow, 2},
    {"R_g_buffered_output_stream_set_buffer_size", (DL_FUNC) &R_g_buffered_output_stream_set_buffer_size, 2},
    {"R_g_bytes_icon_new", (DL_FUNC) &R_g_bytes_icon_new, 1},
    {"R_g_bytes_icon_get_bytes", (DL_FUNC) &R_g_bytes_icon_get_bytes, 1},
    {"R_g_cancellable_new", (DL_FUNC) &R_g_cancellable_new, 0},
    {"R_g_cancellable_get_current", (DL_FUNC) &R_g_cancellable_get_current, 0},
    {"R_g_cancellable_cancel", (DL_FUNC) &R_g_cancellable_cancel, 1},
    {"R_g_cancellable_connect", (DL_FUNC) &R_g_cancellable_connect, 4},
    {"R_g_cancellable_disconnect", (DL_FUNC) &R_g_cancellable_disconnect, 2},
    {"R_g_cancellable_get_fd", (DL_FUNC) &R_g_cancellable_get_fd, 1},
    {"R_g_cancellable_is_cancelled", (DL_FUNC) &R_g_cancellable_is_cancelled, 1},
    {"R_g_cancellable_make_pollfd", (DL_FUNC) &R_g_cancellable_make_pollfd, 2},
    {"R_g_cancellable_pop_current", (DL_FUNC) &R_g_cancellable_pop_current, 1},
    {"R_g_cancellable_push_current", (DL_FUNC) &R_g_cancellable_push_current, 1},
    {"R_g_cancellable_release_fd", (DL_FUNC) &R_g_cancellable_release_fd, 1},
    {"R_g_cancellable_reset", (DL_FUNC) &R_g_cancellable_reset, 1},
    {"R_g_cancellable_set_error_if_cancelled", (DL_FUNC) &R_g_cancellable_set_error_if_cancelled, 1},
    {"R_g_cancellable_source_new", (DL_FUNC) &R_g_cancellable_source_new, 1},
    {"R_g_charset_converter_new", (DL_FUNC) &R_g_charset_converter_new, 2},
    {"R_g_charset_converter_get_num_fallbacks", (DL_FUNC) &R_g_charset_converter_get_num_fallbacks, 1},
    {"R_g_charset_converter_get_use_fallback", (DL_FUNC) &R_g_charset_converter_get_use_fallback, 1},
    {"R_g_charset_converter_set_use_fallback", (DL_FUNC) &R_g_charset_converter_set_use_fallback, 2},
    {"R_g_converter_convert", (DL_FUNC) &R_g_converter_convert, 6},
    {"R_g_converter_reset", (DL_FUNC) &R_g_converter_reset, 1},
    {"R_g_converter_input_stream_new", (DL_FUNC) &R_g_converter_input_stream_new, 2},
    {"R_g_converter_input_stream_get_converter", (DL_FUNC) &R_g_converter_input_stream_get_converter, 1},
    {"R_g_converter_output_stream_new", (DL_FUNC) &R_g_converter_output_stream_new, 2},
    {"R_g_converter_output_stream_get_converter", (DL_FUNC) &R_g_converter_output_stream_get_converter, 1},
    {"R_g_credentials_new", (DL_FUNC) &R_g_credentials_new, 0},
    {"R_g_credentials_is_same_user", (DL_FUNC) &R_g_credentials_is_same_user, 2},
    {"R_g_credentials_set_native", (DL_FUNC) &R_g_credentials_set_native, 3},
    {"R_g_credentials_to_string", (DL_FUNC) &R_g_credentials_to_string, 1},
    {"R_g_data_input_stream_new", (DL_FUNC) &R_g_data_input_stream_new, 1},
    {"R_g_data_input_stream_get_byte_order", (DL_FUNC) &R_g_data_input_stream_get_byte_order, 1},
    {"R_g_data_input_stream_get_newline_type", (DL_FUNC) &R_g_data_input_stream_get_newline_type, 1},
    {"R_g_data_input_stream_read_byte", (DL_FUNC) &R_g_data_input_stream_read_byte, 2},
    {"R_g_data_input_stream_read_int16", (DL_FUNC) &R_g_data_input_stream_read_int16, 2},
    {"R_g_data_input_stream_read_int32", (DL_FUNC) &R_g_data_input_stream_read_int32, 2},
    {"R_g_data_input_stream_read_int64", (DL_FUNC) &R_g_data_input_stream_read_int64, 2},
    {"R_g_data_input_stream_read_line", (DL_FUNC) &R_g_data_input_stream_read_line, 2},
    {"R_g_data_input_stream_read_line_async", (DL_FUNC) &R_g_data_input_stream_read_line_async, 5},
    {"R_g_data_input_stream_read_line_finish", (DL_FUNC) &R_g_data_input_stream_read_line_finish, 2},
    {"R_g_data_input_stream_read_line_finish_utf8", (DL_FUNC) &R_g_data_input_stream_read_line_finish_utf8, 2},
    {"R_g_data_input_stream_read_line_utf8", (DL_FUNC) &R_g_data_input_stream_read_line_utf8, 2},
    {"R_g_data_input_stream_read_uint16", (DL_FUNC) &R_g_data_input_stream_read_uint16, 2},
    {"R_g_data_input_stream_read_uint32", (DL_FUNC) &R_g_data_input_stream_read_uint32, 2},
    {"R_g_data_input_stream_read_uint64", (DL_FUNC) &R_g_data_input_stream_read_uint64, 2},
    {"R_g_data_input_stream_read_until", (DL_FUNC) &R_g_data_input_stream_read_until, 3},
    {"R_g_data_input_stream_read_until_async", (DL_FUNC) &R_g_data_input_stream_read_until_async, 6},
    {"R_g_data_input_stream_read_until_finish", (DL_FUNC) &R_g_data_input_stream_read_until_finish, 2},
    {"R_g_data_input_stream_read_upto", (DL_FUNC) &R_g_data_input_stream_read_upto, 4},
    {"R_g_data_input_stream_read_upto_async", (DL_FUNC) &R_g_data_input_stream_read_upto_async, 7},
    {"R_g_data_input_stream_read_upto_finish", (DL_FUNC) &R_g_data_input_stream_read_upto_finish, 2},
    {"R_g_data_input_stream_set_byte_order", (DL_FUNC) &R_g_data_input_stream_set_byte_order, 2},
    {"R_g_data_input_stream_set_newline_type", (DL_FUNC) &R_g_data_input_stream_set_newline_type, 2},
    {"R_g_data_output_stream_new", (DL_FUNC) &R_g_data_output_stream_new, 1},
    {"R_g_data_output_stream_get_byte_order", (DL_FUNC) &R_g_data_output_stream_get_byte_order, 1},
    {"R_g_data_output_stream_put_byte", (DL_FUNC) &R_g_data_output_stream_put_byte, 3},
    {"R_g_data_output_stream_put_int16", (DL_FUNC) &R_g_data_output_stream_put_int16, 3},
    {"R_g_data_output_stream_put_int32", (DL_FUNC) &R_g_data_output_stream_put_int32, 3},
    {"R_g_data_output_stream_put_int64", (DL_FUNC) &R_g_data_output_stream_put_int64, 3},
    {"R_g_data_output_stream_put_string", (DL_FUNC) &R_g_data_output_stream_put_string, 3},
    {"R_g_data_output_stream_put_uint16", (DL_FUNC) &R_g_data_output_stream_put_uint16, 3},
    {"R_g_data_output_stream_put_uint32", (DL_FUNC) &R_g_data_output_stream_put_uint32, 3},
    {"R_g_data_output_stream_put_uint64", (DL_FUNC) &R_g_data_output_stream_put_uint64, 3},
    {"R_g_data_output_stream_set_byte_order", (DL_FUNC) &R_g_data_output_stream_set_byte_order, 2},
    {"R_g_datagram_based_condition_check", (DL_FUNC) &R_g_datagram_based_condition_check, 2},
    {"R_g_datagram_based_condition_wait", (DL_FUNC) &R_g_datagram_based_condition_wait, 4},
    {"R_g_datagram_based_create_source", (DL_FUNC) &R_g_datagram_based_create_source, 3},
    {"R_g_datagram_based_receive_messages", (DL_FUNC) &R_g_datagram_based_receive_messages, 6},
    {"R_g_datagram_based_send_messages", (DL_FUNC) &R_g_datagram_based_send_messages, 6},
    {"R_g_drive_can_eject", (DL_FUNC) &R_g_drive_can_eject, 1},
    {"R_g_drive_can_poll_for_media", (DL_FUNC) &R_g_drive_can_poll_for_media, 1},
    {"R_g_drive_can_start", (DL_FUNC) &R_g_drive_can_start, 1},
    {"R_g_drive_can_start_degraded", (DL_FUNC) &R_g_drive_can_start_degraded, 1},
    {"R_g_drive_can_stop", (DL_FUNC) &R_g_drive_can_stop, 1},
    {"R_g_drive_eject", (DL_FUNC) &R_g_drive_eject, 5},
    {"R_g_drive_eject_finish", (DL_FUNC) &R_g_drive_eject_finish, 2},
    {"R_g_drive_eject_with_operation", (DL_FUNC) &R_g_drive_eject_with_operation, 6},
    {"R_g_drive_eject_with_operation_finish", (DL_FUNC) &R_g_drive_eject_with_operation_finish, 2},
    {"R_g_drive_enumerate_identifiers", (DL_FUNC) &R_g_drive_enumerate_identifiers, 1},
    {"R_g_drive_get_icon", (DL_FUNC) &R_g_drive_get_icon, 1},
    {"R_g_drive_get_identifier", (DL_FUNC) &R_g_drive_get_identifier, 2},
    {"R_g_drive_get_name", (DL_FUNC) &R_g_drive_get_name, 1},
    {"R_g_drive_get_sort_key", (DL_FUNC) &R_g_drive_get_sort_key, 1},
    {"R_g_drive_get_start_stop_type", (DL_FUNC) &R_g_drive_get_start_stop_type, 1},
    {"R_g_drive_get_symbolic_icon", (DL_FUNC) &R_g_drive_get_symbolic_icon, 1},
    {"R_g_drive_get_volumes", (DL_FUNC) &R_g_drive_get_volumes, 1},
    {"R_g_drive_has_media", (DL_FUNC) &R_g_drive_has_media, 1},
    {"R_g_drive_has_volumes", (DL_FUNC) &R_g_drive_has_volumes, 1},
    {"R_g_drive_is_media_check_automatic", (DL_FUNC) &R_g_drive_is_media_check_automatic, 1},
    {"R_g_drive_is_media_removable", (DL_FUNC) &R_g_drive_is_media_removable, 1},
    {"R_g_drive_is_removable", (DL_FUNC) &R_g_drive_is_removable, 1},
    {"R_g_drive_poll_for_media", (DL_FUNC) &R_g_drive_poll_for_media, 4},
    {"R_g_drive_poll_for_media_finish", (DL_FUNC) &R_g_drive_poll_for_media_finish, 2},
    {"R_g_drive_start", (DL_FUNC) &R_g_drive_start, 6},
    {"R_g_drive_start_finish", (DL_FUNC) &R_g_drive_start_finish, 2},
    {"R_g_drive_stop", (DL_FUNC) &R_g_drive_stop, 6},
    {"R_g_drive_stop_finish", (DL_FUNC) &R_g_drive_stop_finish, 2},
    {"R_g_emblem_new", (DL_FUNC) &R_g_emblem_new, 1},
    {"R_g_emblem_new_with_origin", (DL_FUNC) &R_g_emblem_new_with_origin, 2},
    {"R_g_emblem_get_icon", (DL_FUNC) &R_g_emblem_get_icon, 1},
    {"R_g_emblem_get_origin", (DL_FUNC) &R_g_emblem_get_origin, 1},
    {"R_g_emblemed_icon_new", (DL_FUNC) &R_g_emblemed_icon_new, 2},
    {"R_g_emblemed_icon_add_emblem", (DL_FUNC) &R_g_emblemed_icon_add_emblem, 2},
    {"R_g_emblemed_icon_clear_emblems", (DL_FUNC) &R_g_emblemed_icon_clear_emblems, 1},
    {"R_g_emblemed_icon_get_emblems", (DL_FUNC) &R_g_emblemed_icon_get_emblems, 1},
    {"R_g_emblemed_icon_get_icon", (DL_FUNC) &R_g_emblemed_icon_get_icon, 1},
    {"R_g_file_new_for_commandline_arg", (DL_FUNC) &R_g_file_new_for_commandline_arg, 1},
    {"R_g_file_new_for_commandline_arg_and_cwd", (DL_FUNC) &R_g_file_new_for_commandline_arg_and_cwd, 2},
    {"R_g_file_new_for_path", (DL_FUNC) &R_g_file_new_for_path, 1},
    {"R_g_file_new_for_uri", (DL_FUNC) &R_g_file_new_for_uri, 1},
    {"R_g_file_new_tmp", (DL_FUNC) &R_g_file_new_tmp, 1},
    {"R_g_file_parse_name", (DL_FUNC) &R_g_file_parse_name, 1},
    {"R_g_file_append_to", (DL_FUNC) &R_g_file_append_to, 3},
    {"R_g_file_append_to_async", (DL_FUNC) &R_g_file_append_to_async, 6},
    {"R_g_file_append_to_finish", (DL_FUNC) &R_g_file_append_to_finish, 2},
    {"R_g_file_copy", (DL_FUNC) &R_g_file_copy, 6},
    {"R_g_file_copy_async", (DL_FUNC) &R_g_file_copy_async, 9},
    {"R_g_file_copy_attributes", (DL_FUNC) &R_g_file_copy_attributes, 4},
    {"R_g_file_copy_finish", (DL_FUNC) &R_g_file_copy_finish, 2},
    {"R_g_file_create", (DL_FUNC) &R_g_file_create, 3},
    {"R_g_file_create_async", (DL_FUNC) &R_g_file_create_async, 6},
    {"R_g_file_create_finish", (DL_FUNC) &R_g_file_create_finish, 2},
    {"R_g_file_create_readwrite", (DL_FUNC) &R_g_file_create_readwrite, 3},
    {"R_g_file_create_readwrite_async", (DL_FUNC) &R_g_file_create_readwrite_async, 6},
    {"R_g_file_create_readwrite_finish", (DL_FUNC) &R_g_file_create_readwrite_finish, 2},
    {"R_g_file_delete", (DL_FUNC) &R_g_file_delete, 2},
    {"R_g_file_delete_async", (DL_FUNC) &R_g_file_delete_async, 5},
    {"R_g_file_delete_finish", (DL_FUNC) &R_g_file_delete_finish, 2},
    {"R_g_file_dup", (DL_FUNC) &R_g_file_dup, 1},
    {"R_g_file_eject_mountable", (DL_FUNC) &R_g_file_eject_mountable, 5},
    {"R_g_file_eject_mountable_finish", (DL_FUNC) &R_g_file_eject_mountable_finish, 2},
    {"R_g_file_eject_mountable_with_operation", (DL_FUNC) &R_g_file_eject_mountable_with_operation, 6},
    {"R_g_file_eject_mountable_with_operation_finish", (DL_FUNC) &R_g_file_eject_mountable_with_operation_finish, 2},
    {"R_g_file_enumerate_children", (DL_FUNC) &R_g_file_enumerate_children, 4},
    {"R_g_file_enumerate_children_async", (DL_FUNC) &R_g_file_enumerate_children_async, 7},
    {"R_g_file_enumerate_children_finish", (DL_FUNC) &R_g_file_enumerate_children_finish, 2},
    {"R_g_file_equal", (DL_FUNC) &R_g_file_equal, 2},
    {"R_g_file_find_enclosing_mount", (DL_FUNC) &R_g_file_find_enclosing_mount, 2},
    {"R_g_file_find_enclosing_mount_async", (DL_FUNC) &R_g_file_find_enclosing_mount_async, 5},
    {"R_g_file_find_enclosing_mount_finish", (DL_FUNC) &R_g_file_find_enclosing_mount_finish, 2},
    {"R_g_file_get_basename", (DL_FUNC) &R_g_file_get_basename, 1},
    {"R_g_file_get_child", (DL_FUNC) &R_g_file_get_child, 2},
    {"R_g_file_get_child_for_display_name", (DL_FUNC) &R_g_file_get_child_for_display_name, 2},
    {"R_g_file_get_parent", (DL_FUNC) &R_g_file_get_parent, 1},
    {"R_g_file_get_parse_name", (DL_FUNC) &R_g_file_get_parse_name, 1},
    {"R_g_file_get_path", (DL_FUNC) &R_g_file_get_path, 1},
    {"R_g_file_get_relative_path", (DL_FUNC) &R_g_file_get_relative_path, 2},
    {"R_g_file_get_uri", (DL_FUNC) &R_g_file_get_uri, 1},
    {"R_g_file_get_uri_scheme", (DL_FUNC) &R_g_file_get_uri_scheme, 1},
    {"R_g_file_has_parent", (DL_FUNC) &R_g_file_has_parent, 2},
    {"R_g_file_has_prefix", (DL_FUNC) &R_g_file_has_prefix, 2},
    {"R_g_file_has_uri_scheme", (DL_FUNC) &R_g_file_has_uri_scheme, 2},
    {"R_g_file_hash", (DL_FUNC) &R_g_file_hash, 1},
    {"R_g_file_is_native", (DL_FUNC) &R_g_file_is_native, 1},
    {"R_g_file_load_bytes", (DL_FUNC) &R_g_file_load_bytes, 2},
    {"R_g_file_load_bytes_async", (DL_FUNC) &R_g_file_load_bytes_async, 4},
    {"R_g_file_load_bytes_finish", (DL_FUNC) &R_g_file_load_bytes_finish, 2},
    {"R_g_file_load_contents", (DL_FUNC) &R_g_file_load_contents, 2},
    {"R_g_file_load_contents_async", (DL_FUNC) &R_g_file_load_contents_async, 4},
    {"R_g_file_load_contents_finish", (DL_FUNC) &R_g_file_load_contents_finish, 2},
    {"R_g_file_load_partial_contents_finish", (DL_FUNC) &R_g_file_load_partial_contents_finish, 2},
    {"R_g_file_make_directory", (DL_FUNC) &R_g_file_make_directory, 2},
    {"R_g_file_make_directory_async", (DL_FUNC) &R_g_file_make_directory_async, 5},
    {"R_g_file_make_directory_finish", (DL_FUNC) &R_g_file_make_directory_finish, 2},
    {"R_g_file_make_directory_with_parents", (DL_FUNC) &R_g_file_make_directory_with_parents, 2},
    {"R_g_file_make_symbolic_link", (DL_FUNC) &R_g_file_make_symbolic_link, 3},
    {"R_g_file_measure_disk_usage", (DL_FUNC) &R_g_file_measure_disk_usage, 5},
    {"R_g_file_measure_disk_usage_finish", (DL_FUNC) &R_g_file_measure_disk_usage_finish, 2},
    {"R_g_file_monitor", (DL_FUNC) &R_g_file_monitor, 3},
    {"R_g_file_monitor_directory", (DL_FUNC) &R_g_file_monitor_directory, 3},
    {"R_g_file_monitor_file", (DL_FUNC) &R_g_file_monitor_file, 3},
    {"R_g_file_mount_enclosing_volume", (DL_FUNC) &R_g_file_mount_enclosing_volume, 6},
    {"R_g_file_mount_enclosing_volume_finish", (DL_FUNC) &R_g_file_mount_enclosing_volume_finish, 2},
    {"R_g_file_mount_mountable", (DL_FUNC) &R_g_file_mount_mountable, 6},
    {"R_g_file_mount_mountable_finish", (DL_FUNC) &R_g_file_mount_mountable_finish, 2},
    {"R_g_file_move", (DL_FUNC) &R_g_file_move, 6},
    {"R_g_file_open_readwrite", (DL_FUNC) &R_g_file_open_readwrite, 2},
    {"R_g_file_open_readwrite_async", (DL_FUNC) &R_g_file_open_readwrite_async, 5},
    {"R_g_file_open_readwrite_finish", (DL_FUNC) &R_g_file_open_readwrite_finish, 2},
    {"R_g_file_peek_path", (DL_FUNC) &R_g_file_peek_path, 1},
    {"R_g_file_poll_mountable", (DL_FUNC) &R_g_file_poll_mountable, 4},
    {"R_g_file_poll_mountable_finish", (DL_FUNC) &R_g_file_poll_mountable_finish, 2},
    {"R_g_file_query_default_handler", (DL_FUNC) &R_g_file_query_default_handler, 2},
    {"R_g_file_query_exists", (DL_FUNC) &R_g_file_query_exists, 2},
    {"R_g_file_query_file_type", (DL_FUNC) &R_g_file_query_file_type, 3},
    {"R_g_file_query_filesystem_info", (DL_FUNC) &R_g_file_query_filesystem_info, 3},
    {"R_g_file_query_filesystem_info_async", (DL_FUNC) &R_g_file_query_filesystem_info_async, 6},
    {"R_g_file_query_filesystem_info_finish", (DL_FUNC) &R_g_file_query_filesystem_info_finish, 2},
    {"R_g_file_query_info", (DL_FUNC) &R_g_file_query_info, 4},
    {"R_g_file_query_info_async", (DL_FUNC) &R_g_file_query_info_async, 7},
    {"R_g_file_query_info_finish", (DL_FUNC) &R_g_file_query_info_finish, 2},
    {"R_g_file_query_settable_attributes", (DL_FUNC) &R_g_file_query_settable_attributes, 2},
    {"R_g_file_query_writable_namespaces", (DL_FUNC) &R_g_file_query_writable_namespaces, 2},
    {"R_g_file_read", (DL_FUNC) &R_g_file_read, 2},
    {"R_g_file_read_async", (DL_FUNC) &R_g_file_read_async, 5},
    {"R_g_file_read_finish", (DL_FUNC) &R_g_file_read_finish, 2},
    {"R_g_file_replace", (DL_FUNC) &R_g_file_replace, 5},
    {"R_g_file_replace_async", (DL_FUNC) &R_g_file_replace_async, 8},
    {"R_g_file_replace_contents", (DL_FUNC) &R_g_file_replace_contents, 7},
    {"R_g_file_replace_contents_async", (DL_FUNC) &R_g_file_replace_contents_async, 9},
    {"R_g_file_replace_contents_bytes_async", (DL_FUNC) &R_g_file_replace_contents_bytes_async, 8},
    {"R_g_file_replace_contents_finish", (DL_FUNC) &R_g_file_replace_contents_finish, 2},
    {"R_g_file_replace_finish", (DL_FUNC) &R_g_file_replace_finish, 2},
    {"R_g_file_replace_readwrite", (DL_FUNC) &R_g_file_replace_readwrite, 5},
    {"R_g_file_replace_readwrite_async", (DL_FUNC) &R_g_file_replace_readwrite_async, 8},
    {"R_g_file_replace_readwrite_finish", (DL_FUNC) &R_g_file_replace_readwrite_finish, 2},
    {"R_g_file_resolve_relative_path", (DL_FUNC) &R_g_file_resolve_relative_path, 2},
    {"R_g_file_set_attribute", (DL_FUNC) &R_g_file_set_attribute, 6},
    {"R_g_file_set_attribute_byte_string", (DL_FUNC) &R_g_file_set_attribute_byte_string, 5},
    {"R_g_file_set_attribute_int32", (DL_FUNC) &R_g_file_set_attribute_int32, 5},
    {"R_g_file_set_attribute_int64", (DL_FUNC) &R_g_file_set_attribute_int64, 5},
    {"R_g_file_set_attribute_string", (DL_FUNC) &R_g_file_set_attribute_string, 5},
    {"R_g_file_set_attribute_uint32", (DL_FUNC) &R_g_file_set_attribute_uint32, 5},
    {"R_g_file_set_attribute_uint64", (DL_FUNC) &R_g_file_set_attribute_uint64, 5},
    {"R_g_file_set_attributes_async", (DL_FUNC) &R_g_file_set_attributes_async, 7},
    {"R_g_file_set_attributes_finish", (DL_FUNC) &R_g_file_set_attributes_finish, 2},
    {"R_g_file_set_attributes_from_info", (DL_FUNC) &R_g_file_set_attributes_from_info, 4},
    {"R_g_file_set_display_name", (DL_FUNC) &R_g_file_set_display_name, 3},
    {"R_g_file_set_display_name_async", (DL_FUNC) &R_g_file_set_display_name_async, 6},
    {"R_g_file_set_display_name_finish", (DL_FUNC) &R_g_file_set_display_name_finish, 2},
    {"R_g_file_start_mountable", (DL_FUNC) &R_g_file_start_mountable, 6},
    {"R_g_file_start_mountable_finish", (DL_FUNC) &R_g_file_start_mountable_finish, 2},
    {"R_g_file_stop_mountable", (DL_FUNC) &R_g_file_stop_mountable, 6},
    {"R_g_file_stop_mountable_finish", (DL_FUNC) &R_g_file_stop_mountable_finish, 2},
    {"R_g_file_supports_thread_contexts", (DL_FUNC) &R_g_file_supports_thread_contexts, 1},
    {"R_g_file_trash", (DL_FUNC) &R_g_file_trash, 2},
    {"R_g_file_trash_async", (DL_FUNC) &R_g_file_trash_async, 5},
    {"R_g_file_trash_finish", (DL_FUNC) &R_g_file_trash_finish, 2},
    {"R_g_file_unmount_mountable", (DL_FUNC) &R_g_file_unmount_mountable, 5},
    {"R_g_file_unmount_mountable_finish", (DL_FUNC) &R_g_file_unmount_mountable_finish, 2},
    {"R_g_file_unmount_mountable_with_operation", (DL_FUNC) &R_g_file_unmount_mountable_with_operation, 6},
    {"R_g_file_unmount_mountable_with_operation_finish", (DL_FUNC) &R_g_file_unmount_mountable_with_operation_finish, 2},
    {"R_g_file_attribute_info_list_new", (DL_FUNC) &R_g_file_attribute_info_list_new, 0},
    {"R_g_file_attribute_info_list_add", (DL_FUNC) &R_g_file_attribute_info_list_add, 4},
    {"R_g_file_attribute_info_list_dup", (DL_FUNC) &R_g_file_attribute_info_list_dup, 1},
    {"R_g_file_attribute_info_list_lookup", (DL_FUNC) &R_g_file_attribute_info_list_lookup, 2},
    {"R_g_file_attribute_info_list_ref", (DL_FUNC) &R_g_file_attribute_info_list_ref, 1},
    {"R_g_file_attribute_info_list_unref", (DL_FUNC) &R_g_file_attribute_info_list_unref, 1},
    {"R_g_file_attribute_matcher_new", (DL_FUNC) &R_g_file_attribute_matcher_new, 1},
    {"R_g_file_attribute_matcher_enumerate_namespace", (DL_FUNC) &R_g_file_attribute_matcher_enumerate_namespace, 2},
    {"R_g_file_attribute_matcher_enumerate_next", (DL_FUNC) &R_g_file_attribute_matcher_enumerate_next, 1},
    {"R_g_file_attribute_matcher_matches", (DL_FUNC) &R_g_file_attribute_matcher_matches, 2},
    {"R_g_file_attribute_matcher_matches_only", (DL_FUNC) &R_g_file_attribute_matcher_matches_only, 2},
    {"R_g_file_attribute_matcher_ref", (DL_FUNC) &R_g_file_attribute_matcher_ref, 1},
    {"R_g_file_attribute_matcher_subtract", (DL_FUNC) &R_g_file_attribute_matcher_subtract, 2},
    {"R_g_file_attribute_matcher_to_string", (DL_FUNC) &R_g_file_attribute_matcher_to_string, 1},
    {"R_g_file_attribute_matcher_unref", (DL_FUNC) &R_g_file_attribute_matcher_unref, 1},
    {"R_g_file_enumerator_close", (DL_FUNC) &R_g_file_enumerator_close, 2},
    {"R_g_file_enumerator_close_async", (DL_FUNC) &R_g_file_enumerator_close_async, 5},
    {"R_g_file_enumerator_close_finish", (DL_FUNC) &R_g_file_enumerator_close_finish, 2},
    {"R_g_file_enumerator_get_child", (DL_FUNC) &R_g_file_enumerator_get_child, 2},
    {"R_g_file_enumerator_get_container", (DL_FUNC) &R_g_file_enumerator_get_container, 1},
    {"R_g_file_enumerator_has_pending", (DL_FUNC) &R_g_file_enumerator_has_pending, 1},
    {"R_g_file_enumerator_is_closed", (DL_FUNC) &R_g_file_enumerator_is_closed, 1},
    {"R_g_file_enumerator_iterate", (DL_FUNC) &R_g_file_enumerator_iterate, 2},
    {"R_g_file_enumerator_next_file", (DL_FUNC) &R_g_file_enumerator_next_file, 2},
    {"R_g_file_enumerator_next_files_async", (DL_FUNC) &R_g_file_enumerator_next_files_async, 6},
    {"R_g_file_enumerator_next_files_finish", (DL_FUNC) &R_g_file_enumerator_next_files_finish, 2},
    {"R_g_file_enumerator_set_pending", (DL_FUNC) &R_g_file_enumerator_set_pending, 2},
    {"R_g_file_io_stream_get_etag", (DL_FUNC) &R_g_file_io_stream_get_etag, 1},
    {"R_g_file_io_stream_query_info", (DL_FUNC) &R_g_file_io_stream_query_info, 3},
    {"R_g_file_io_stream_query_info_async", (DL_FUNC) &R_g_file_io_stream_query_info_async, 6},
    {"R_g_file_io_stream_query_info_finish", (DL_FUNC) &R_g_file_io_stream_query_info_finish, 2},
    {"R_g_file_icon_new", (DL_FUNC) &R_g_file_icon_new, 1},
    {"R_g_file_icon_get_file", (DL_FUNC) &R_g_file_icon_get_file, 1},
    {"R_g_file_info_new", (DL_FUNC) &R_g_file_info_new, 0},
    {"R_g_file_info_clear_status", (DL_FUNC) &R_g_file_info_clear_status, 1},
    {"R_g_file_info_copy_into", (DL_FUNC) &R_g_file_info_copy_into, 2},
    {"R_g_file_info_dup", (DL_FUNC) &R_g_file_info_dup, 1},
    {"R_g_file_info_get_attribute_as_string", (DL_FUNC) &R_g_file_info_get_attribute_as_string, 2},
    {"R_g_file_info_get_attribute_boolean", (DL_FUNC) &R_g_file_info_get_attribute_boolean, 2},
    {"R_g_file_info_get_attribute_byte_string", (DL_FUNC) &R_g_file_info_get_attribute_byte_string, 2},
    {"R_g_file_info_get_attribute_data", (DL_FUNC) &R_g_file_info_get_attribute_data, 2},
    {"R_g_file_info_get_attribute_int32", (DL_FUNC) &R_g_file_info_get_attribute_int32, 2},
    {"R_g_file_info_get_attribute_int64", (DL_FUNC) &R_g_file_info_get_attribute_int64, 2},
    {"R_g_file_info_get_attribute_object", (DL_FUNC) &R_g_file_info_get_attribute_object, 2},
    {"R_g_file_info_get_attribute_status", (DL_FUNC) &R_g_file_info_get_attribute_status, 2},
    {"R_g_file_info_get_attribute_string", (DL_FUNC) &R_g_file_info_get_attribute_string, 2},
    {"R_g_file_info_get_attribute_stringv", (DL_FUNC) &R_g_file_info_get_attribute_stringv, 2},
    {"R_g_file_info_get_attribute_type", (DL_FUNC) &R_g_file_info_get_attribute_type, 2},
    {"R_g_file_info_get_attribute_uint32", (DL_FUNC) &R_g_file_info_get_attribute_uint32, 2},
    {"R_g_file_info_get_attribute_uint64", (DL_FUNC) &R_g_file_info_get_attribute_uint64, 2},
    {"R_g_file_info_get_content_type", (DL_FUNC) &R_g_file_info_get_content_type, 1},
    {"R_g_file_info_get_deletion_date", (DL_FUNC) &R_g_file_info_get_deletion_date, 1},
    {"R_g_file_info_get_display_name", (DL_FUNC) &R_g_file_info_get_display_name, 1},
    {"R_g_file_info_get_edit_name", (DL_FUNC) &R_g_file_info_get_edit_name, 1},
    {"R_g_file_info_get_etag", (DL_FUNC) &R_g_file_info_get_etag, 1},
    {"R_g_file_info_get_file_type", (DL_FUNC) &R_g_file_info_get_file_type, 1},
    {"R_g_file_info_get_icon", (DL_FUNC) &R_g_file_info_get_icon, 1},
    {"R_g_file_info_get_is_backup", (DL_FUNC) &R_g_file_info_get_is_backup, 1},
    {"R_g_file_info_get_is_hidden", (DL_FUNC) &R_g_file_info_get_is_hidden, 1},
    {"R_g_file_info_get_is_symlink", (DL_FUNC) &R_g_file_info_get_is_symlink, 1},
    {"R_g_file_info_get_modification_time", (DL_FUNC) &R_g_file_info_get_modification_time, 1},
    {"R_g_file_info_get_name", (DL_FUNC) &R_g_file_info_get_name, 1},
    {"R_g_file_info_get_size", (DL_FUNC) &R_g_file_info_get_size, 1},
    {"R_g_file_info_get_sort_order", (DL_FUNC) &R_g_file_info_get_sort_order, 1},
    {"R_g_file_info_get_symbolic_icon", (DL_FUNC) &R_g_file_info_get_symbolic_icon, 1},
    {"R_g_file_info_get_symlink_target", (DL_FUNC) &R_g_file_info_get_symlink_target, 1},
    {"R_g_file_info_has_attribute", (DL_FUNC) &R_g_file_info_has_attribute, 2},
    {"R_g_file_info_has_namespace", (DL_FUNC) &R_g_file_info_has_namespace, 2},
    {"R_g_file_info_list_attributes", (DL_FUNC) &R_g_file_info_list_attributes, 2},
    {"R_g_file_info_remove_attribute", (DL_FUNC) &R_g_file_info_remove_attribute, 2},
    {"R_g_file_info_set_attribute", (DL_FUNC) &R_g_file_info_set_attribute, 4},
    {"R_g_file_info_set_attribute_boolean", (DL_FUNC) &R_g_file_info_set_attribute_boolean, 3},
    {"R_g_file_info_set_attribute_byte_string", (DL_FUNC) &R_g_file_info_set_attribute_byte_string, 3},
    {"R_g_file_info_set_attribute_int32", (DL_FUNC) &R_g_file_info_set_attribute_int32, 3},
    {"R_g_file_info_set_attribute_int64", (DL_FUNC) &R_g_file_info_set_attribute_int64, 3},
    {"R_g_file_info_set_attribute_mask", (DL_FUNC) &R_g_file_info_set_attribute_mask, 2},
    {"R_g_file_info_set_attribute_object", (DL_FUNC) &R_g_file_info_set_attribute_object, 3},
    {"R_g_file_info_set_attribute_status", (DL_FUNC) &R_g_file_info_set_attribute_status, 3},
    {"R_g_file_info_set_attribute_string", (DL_FUNC) &R_g_file_info_set_attribute_string, 3},
    {"R_g_file_info_set_attribute_stringv", (DL_FUNC) &R_g_file_info_set_attribute_stringv, 3},
    {"R_g_file_info_set_attribute_uint32", (DL_FUNC) &R_g_file_info_set_attribute_uint32, 3},
    {"R_g_file_info_set_attribute_uint64", (DL_FUNC) &R_g_file_info_set_attribute_uint64, 3},
    {"R_g_file_info_set_content_type", (DL_FUNC) &R_g_file_info_set_content_type, 2},
    {"R_g_file_info_set_display_name", (DL_FUNC) &R_g_file_info_set_display_name, 2},
    {"R_g_file_info_set_edit_name", (DL_FUNC) &R_g_file_info_set_edit_name, 2},
    {"R_g_file_info_set_file_type", (DL_FUNC) &R_g_file_info_set_file_type, 2},
    {"R_g_file_info_set_icon", (DL_FUNC) &R_g_file_info_set_icon, 2},
    {"R_g_file_info_set_is_hidden", (DL_FUNC) &R_g_file_info_set_is_hidden, 2},
    {"R_g_file_info_set_is_symlink", (DL_FUNC) &R_g_file_info_set_is_symlink, 2},
    {"R_g_file_info_set_modification_time", (DL_FUNC) &R_g_file_info_set_modification_time, 2},
    {"R_g_file_info_set_name", (DL_FUNC) &R_g_file_info_set_name, 2},
    {"R_g_file_info_set_size", (DL_FUNC) &R_g_file_info_set_size, 2},
    {"R_g_file_info_set_sort_order", (DL_FUNC) &R_g_file_info_set_sort_order, 2},
    {"R_g_file_info_set_symbolic_icon", (DL_FUNC) &R_g_file_info_set_symbolic_icon, 2},
    {"R_g_file_info_set_symlink_target", (DL_FUNC) &R_g_file_info_set_symlink_target, 2},
    {"R_g_file_info_unset_attribute_mask", (DL_FUNC) &R_g_file_info_unset_attribute_mask, 1},
    {"R_g_file_input_stream_query_info", (DL_FUNC) &R_g_file_input_stream_query_info, 3},
    {"R_g_file_input_stream_query_info_async", (DL_FUNC) &R_g_file_input_stream_query_info_async, 6},
    {"R_g_file_input_stream_query_info_finish", (DL_FUNC) &R_g_file_input_stream_query_info_finish, 2},
    {"R_g_file_monitor_cancel", (DL_FUNC) &R_g_file_monitor_cancel, 1},
    {"R_g_file_monitor_emit_event", (DL_FUNC) &R_g_file_monitor_emit_event, 4},
    {"R_g_file_monitor_is_cancelled", (DL_FUNC) &R_g_file_monitor_is_cancelled, 1},
    {"R_g_file_monitor_set_rate_limit", (DL_FUNC) &R_g_file_monitor_set_rate_limit, 2},
    {"R_g_file_output_stream_get_etag", (DL_FUNC) &R_g_file_output_stream_get_etag, 1},
    {"R_g_file_output_stream_query_info", (DL_FUNC) &R_g_file_output_stream_query_info, 3},
    {"R_g_file_output_stream_query_info_async", (DL_FUNC) &R_g_file_output_stream_query_info_async, 6},
    {"R_g_file_output_stream_query_info_finish", (DL_FUNC) &R_g_file_output_stream_query_info_finish, 2},
    {"R_g_filename_completer_new", (DL_FUNC) &R_g_filename_completer_new, 0},
    {"R_g_filename_completer_get_completion_suffix", (DL_FUNC) &R_g_filename_completer_get_completion_suffix, 2},
    {"R_g_filename_completer_get_completions", (DL_FUNC) &R_g_filename_completer_get_completions, 2},
    {"R_g_filename_completer_set_dirs_only", (DL_FUNC) &R_g_filename_completer_set_dirs_only, 2},
    {"R_g_filter_input_stream_get_base_stream", (DL_FUNC) &R_g_filter_input_stream_get_base_stream, 1},
    {"R_g_filter_input_stream_get_close_base_stream", (DL_FUNC) &R_g_filter_input_stream_get_close_base_stream, 1},
    {"R_g_filter_input_stream_set_close_base_stream", (DL_FUNC) &R_g_filter_input_stream_set_close_base_stream, 2},
    {"R_g_filter_output_stream_get_base_stream", (DL_FUNC) &R_g_filter_output_stream_get_base_stream, 1},
    {"R_g_filter_output_stream_get_close_base_stream", (DL_FUNC) &R_g_filter_output_stream_get_close_base_stream, 1},
    {"R_g_filter_output_stream_set_close_base_stream", (DL_FUNC) &R_g_filter_output_stream_set_close_base_stream, 2},
    {"R_g_io_extension_get_name", (DL_FUNC) &R_g_io_extension_get_name, 1},
    {"R_g_io_extension_get_priority", (DL_FUNC) &R_g_io_extension_get_priority, 1},
    {"R_g_io_extension_get_type", (DL_FUNC) &R_g_io_extension_get_type, 1},
    {"R_g_io_extension_point_get_extension_by_name", (DL_FUNC) &R_g_io_extension_point_get_extension_by_name, 2},
    {"R_g_io_extension_point_get_extensions", (DL_FUNC) &R_g_io_extension_point_get_extensions, 1},
    {"R_g_io_extension_point_get_required_type", (DL_FUNC) &R_g_io_extension_point_get_required_type, 1},
    {"R_g_io_extension_point_set_required_type", (DL_FUNC) &R_g_io_extension_point_set_required_type, 2},
    {"R_g_io_extension_point_implement", (DL_FUNC) &R_g_io_extension_point_implement, 4},
    {"R_g_io_extension_point_lookup", (DL_FUNC) &R_g_io_extension_point_lookup, 1},
    {"R_g_io_extension_point_register", (DL_FUNC) &R_g_io_extension_point_register, 1},
    {"R_g_io_scheduler_job_send_to_mainloop", (DL_FUNC) &R_g_io_scheduler_job_send_to_mainloop, 4},
    {"R_g_io_scheduler_job_send_to_mainloop_async", (DL_FUNC) &R_g_io_scheduler_job_send_to_mainloop_async, 4},
    {"R_g_io_stream_splice_finish", (DL_FUNC) &R_g_io_stream_splice_finish, 1},
    {"R_g_io_stream_clear_pending", (DL_FUNC) &R_g_io_stream_clear_pending, 1},
    {"R_g_io_stream_close", (DL_FUNC) &R_g_io_stream_close, 2},
    {"R_g_io_stream_close_async", (DL_FUNC) &R_g_io_stream_close_async, 5},
    {"R_g_io_stream_close_finish", (DL_FUNC) &R_g_io_stream_close_finish, 2},
    {"R_g_io_stream_get_input_stream", (DL_FUNC) &R_g_io_stream_get_input_stream, 1},
    {"R_g_io_stream_get_output_stream", (DL_FUNC) &R_g_io_stream_get_output_stream, 1},
    {"R_g_io_stream_has_pending", (DL_FUNC) &R_g_io_stream_has_pending, 1},
    {"R_g_io_stream_is_closed", (DL_FUNC) &R_g_io_stream_is_closed, 1},
    {"R_g_io_stream_set_pending", (DL_FUNC) &R_g_io_stream_set_pending, 1},
    {"R_g_io_stream_splice_async", (DL_FUNC) &R_g_io_stream_splice_async, 7},
    {"R_g_icon_deserialize", (DL_FUNC) &R_g_icon_deserialize, 1},
    {"R_g_icon_new_for_string", (DL_FUNC) &R_g_icon_new_for_string, 1},
    {"R_g_icon_equal", (DL_FUNC) &R_g_icon_equal, 2},
    {"R_g_icon_hash", (DL_FUNC) &R_g_icon_hash, 1},
    {"R_g_icon_serialize", (DL_FUNC) &R_g_icon_serialize, 1},
    {"R_g_icon_to_string", (DL_FUNC) &R_g_icon_to_string, 1},
    {"R_g_inet_address_new_any", (DL_FUNC) &R_g_inet_address_new_any, 1},
    {"R_g_inet_address_new_from_bytes", (DL_FUNC) &R_g_inet_address_new_from_bytes, 2},
    {"R_g_inet_address_new_from_string", (DL_FUNC) &R_g_inet_address_new_from_string, 1},
    {"R_g_inet_address_new_loopback", (DL_FUNC) &R_g_inet_address_new_loopback, 1},
    {"R_g_inet_address_equal", (DL_FUNC) &R_g_inet_address_equal, 2},
    {"R_g_inet_address_get_family", (DL_FUNC) &R_g_inet_address_get_family, 1},
    {"R_g_inet_address_get_is_any", (DL_FUNC) &R_g_inet_address_get_is_any, 1},
    {"R_g_inet_address_get_is_link_local", (DL_FUNC) &R_g_inet_address_get_is_link_local, 1},
    {"R_g_inet_address_get_is_loopback", (DL_FUNC) &R_g_inet_address_get_is_loopback, 1},
    {"R_g_inet_address_get_is_mc_global", (DL_FUNC) &R_g_inet_address_get_is_mc_global, 1},
    {"R_g_inet_address_get_is_mc_link_local", (DL_FUNC) &R_g_inet_address_get_is_mc_link_local, 1},
    {"R_g_inet_address_get_is_mc_node_local", (DL_FUNC) &R_g_inet_address_get_is_mc_node_local, 1},
    {"R_g_inet_address_get_is_mc_org_local", (DL_FUNC) &R_g_inet_address_get_is_mc_org_local, 1},
    {"R_g_inet_address_get_is_mc_site_local", (DL_FUNC) &R_g_inet_address_get_is_mc_site_local, 1},
    {"R_g_inet_address_get_is_multicast", (DL_FUNC) &R_g_inet_address_get_is_multicast, 1},
    {"R_g_inet_address_get_is_site_local", (DL_FUNC) &R_g_inet_address_get_is_site_local, 1},
    {"R_g_inet_address_get_native_size", (DL_FUNC) &R_g_inet_address_get_native_size, 1},
    {"R_g_inet_address_to_string", (DL_FUNC) &R_g_inet_address_to_string, 1},
    {"R_g_inet_address_mask_new", (DL_FUNC) &R_g_inet_address_mask_new, 2},
    {"R_g_inet_address_mask_new_from_string", (DL_FUNC) &R_g_inet_address_mask_new_from_string, 1},
    {"R_g_inet_address_mask_equal", (DL_FUNC) &R_g_inet_address_mask_equal, 2},
    {"R_g_inet_address_mask_get_address", (DL_FUNC) &R_g_inet_address_mask_get_address, 1},
    {"R_g_inet_address_mask_get_family", (DL_FUNC) &R_g_inet_address_mask_get_family, 1},
    {"R_g_inet_address_mask_get_length", (DL_FUNC) &R_g_inet_address_mask_get_length, 1},
    {"R_g_inet_address_mask_matches", (DL_FUNC) &R_g_inet_address_mask_matches, 2},
    {"R_g_inet_address_mask_to_string", (DL_FUNC) &R_g_inet_address_mask_to_string, 1},
    {"R_g_inet_socket_address_new", (DL_FUNC) &R_g_inet_socket_address_new, 2},
    {"R_g_inet_socket_address_new_from_string", (DL_FUNC) &R_g_inet_socket_address_new_from_string, 2},
    {"R_g_inet_socket_address_get_address", (DL_FUNC) &R_g_inet_socket_address_get_address, 1},
    {"R_g_inet_socket_address_get_flowinfo", (DL_FUNC) &R_g_inet_socket_address_get_flowinfo, 1},
    {"R_g_inet_socket_address_get_port", (DL_FUNC) &R_g_inet_socket_address_get_port, 1},
    {"R_g_inet_socket_address_get_scope_id", (DL_FUNC) &R_g_inet_socket_address_get_scope_id, 1},
    {"R_g_initable_newv", (DL_FUNC) &R_g_initable_newv, 4},
    {"R_g_initable_init", (DL_FUNC) &R_g_initable_init, 2},
    {"R_g_input_stream_clear_pending", (DL_FUNC) &R_g_input_stream_clear_pending, 1},
    {"R_g_input_stream_close", (DL_FUNC) &R_g_input_stream_close, 2},
    {"R_g_input_stream_close_async", (DL_FUNC) &R_g_input_stream_close_async, 5},
    {"R_g_input_stream_close_finish", (DL_FUNC) &R_g_input_stream_close_finish, 2},
    {"R_g_input_stream_has_pending", (DL_FUNC) &R_g_input_stream_has_pending, 1},
    {"R_g_input_stream_is_closed", (DL_FUNC) &R_g_input_stream_is_closed, 1},
    {"R_g_input_stream_read", (DL_FUNC) &R_g_input_stream_read, 3},
    {"R_g_input_stream_read_all", (DL_FUNC) &R_g_input_stream_read_all, 3},
    {"R_g_input_stream_read_all_async", (DL_FUNC) &R_g_input_stream_read_all_async, 6},
    {"R_g_input_stream_read_all_finish", (DL_FUNC) &R_g_input_stream_read_all_finish, 2},
    {"R_g_input_stream_read_async", (DL_FUNC) &R_g_input_stream_read_async, 6},
    {"R_g_input_stream_read_bytes", (DL_FUNC) &R_g_input_stream_read_bytes, 3},
    {"R_g_input_stream_read_bytes_async", (DL_FUNC) &R_g_input_stream_read_bytes_async, 6},
    {"R_g_input_stream_read_bytes_finish", (DL_FUNC) &R_g_input_stream_read_bytes_finish, 2},
    {"R_g_input_stream_read_finish", (DL_FUNC) &R_g_input_stream_read_finish, 2},
    {"R_g_input_stream_set_pending", (DL_FUNC) &R_g_input_stream_set_pending, 1},
    {"R_g_input_stream_skip", (DL_FUNC) &R_g_input_stream_skip, 3},
    {"R_g_input_stream_skip_async", (DL_FUNC) &R_g_input_stream_skip_async, 6},
    {"R_g_input_stream_skip_finish", (DL_FUNC) &R_g_input_stream_skip_finish, 2},
    {"R_g_list_model_get_item_type", (DL_FUNC) &R_g_list_model_get_item_type, 1},
    {"R_g_list_model_get_n_items", (DL_FUNC) &R_g_list_model_get_n_items, 1},
    {"R_g_list_model_get_object", (DL_FUNC) &R_g_list_model_get_object, 2},
    {"R_g_list_model_items_changed", (DL_FUNC) &R_g_list_model_items_changed, 4},
    {"R_g_list_store_new", (DL_FUNC) &R_g_list_store_new, 1},
    {"R_g_list_store_append", (DL_FUNC) &R_g_list_store_append, 2},
    {"R_g_list_store_insert", (DL_FUNC) &R_g_list_store_insert, 3},
    {"R_g_list_store_insert_sorted", (DL_FUNC) &R_g_list_store_insert_sorted, 4},
    {"R_g_list_store_remove", (DL_FUNC) &R_g_list_store_remove, 2},
    {"R_g_list_store_remove_all", (DL_FUNC) &R_g_list_store_remove_all, 1},
    {"R_g_list_store_sort", (DL_FUNC) &R_g_list_store_sort, 3},
    {"R_g_list_store_splice", (DL_FUNC) &R_g_list_store_splice, 5},
    {"R_g_loadable_icon_load", (DL_FUNC) &R_g_loadable_icon_load, 3},
    {"R_g_loadable_icon_load_async", (DL_FUNC) &R_g_loadable_icon_load_async, 5},
    {"R_g_loadable_icon_load_finish", (DL_FUNC) &R_g_loadable_icon_load_finish, 2},
    {"R_g_memory_input_stream_new", (DL_FUNC) &R_g_memory_input_stream_new, 0},
    {"R_g_memory_input_stream_new_from_bytes", (DL_FUNC) &R_g_memory_input_stream_new_from_bytes, 1},
    {"R_g_memory_input_stream_new_from_data", (DL_FUNC) &R_g_memory_input_stream_new_from_data, 3},
    {"R_g_memory_input_stream_add_bytes", (DL_FUNC) &R_g_memory_input_stream_add_bytes, 2},
    {"R_g_memory_input_stream_add_data", (DL_FUNC) &R_g_memory_input_stream_add_data, 4},
    {"R_g_memory_output_stream_new_resizable", (DL_FUNC) &R_g_memory_output_stream_new_resizable, 0},
    {"R_g_memory_output_stream_get_data", (DL_FUNC) &R_g_memory_output_stream_get_data, 1},
    {"R_g_memory_output_stream_get_data_size", (DL_FUNC) &R_g_memory_output_stream_get_data_size, 1},
    {"R_g_memory_output_stream_get_size", (DL_FUNC) &R_g_memory_output_stream_get_size, 1},
    {"R_g_memory_output_stream_steal_as_bytes", (DL_FUNC) &R_g_memory_output_stream_steal_as_bytes, 1},
    {"R_g_memory_output_stream_steal_data", (DL_FUNC) &R_g_memory_output_stream_steal_data, 1},
    {"R_g_menu_new", (DL_FUNC) &R_g_menu_new, 0},
    {"R_g_menu_append", (DL_FUNC) &R_g_menu_append, 3},
    {"R_g_menu_append_item", (DL_FUNC) &R_g_menu_append_item, 2},
    {"R_g_menu_append_section", (DL_FUNC) &R_g_menu_append_section, 3},
    {"R_g_menu_append_submenu", (DL_FUNC) &R_g_menu_append_submenu, 3},
    {"R_g_menu_freeze", (DL_FUNC) &R_g_menu_freeze, 1},
    {"R_g_menu_insert", (DL_FUNC) &R_g_menu_insert, 4},
    {"R_g_menu_insert_item", (DL_FUNC) &R_g_menu_insert_item, 3},
    {"R_g_menu_insert_section", (DL_FUNC) &R_g_menu_insert_section, 4},
    {"R_g_menu_insert_submenu", (DL_FUNC) &R_g_menu_insert_submenu, 4},
    {"R_g_menu_prepend", (DL_FUNC) &R_g_menu_prepend, 3},
    {"R_g_menu_prepend_item", (DL_FUNC) &R_g_menu_prepend_item, 2},
    {"R_g_menu_prepend_section", (DL_FUNC) &R_g_menu_prepend_section, 3},
    {"R_g_menu_prepend_submenu", (DL_FUNC) &R_g_menu_prepend_submenu, 3},
    {"R_g_menu_remove", (DL_FUNC) &R_g_menu_remove, 2},
    {"R_g_menu_remove_all", (DL_FUNC) &R_g_menu_remove_all, 1},
    {"R_g_menu_attribute_iter_get_name", (DL_FUNC) &R_g_menu_attribute_iter_get_name, 1},
    {"R_g_menu_attribute_iter_get_next", (DL_FUNC) &R_g_menu_attribute_iter_get_next, 1},
    {"R_g_menu_attribute_iter_get_value", (DL_FUNC) &R_g_menu_attribute_iter_get_value, 1},
    {"R_g_menu_attribute_iter_next", (DL_FUNC) &R_g_menu_attribute_iter_next, 1},
    {"R_g_menu_item_new", (DL_FUNC) &R_g_menu_item_new, 2},
    {"R_g_menu_item_new_from_model", (DL_FUNC) &R_g_menu_item_new_from_model, 2},
    {"R_g_menu_item_new_section", (DL_FUNC) &R_g_menu_item_new_section, 2},
    {"R_g_menu_item_new_submenu", (DL_FUNC) &R_g_menu_item_new_submenu, 2},
    {"R_g_menu_item_get_attribute_value", (DL_FUNC) &R_g_menu_item_get_attribute_value, 3},
    {"R_g_menu_item_get_link", (DL_FUNC) &R_g_menu_item_get_link, 2},
    {"R_g_menu_item_set_action_and_target_value", (DL_FUNC) &R_g_menu_item_set_action_and_target_value, 3},
    {"R_g_menu_item_set_attribute_value", (DL_FUNC) &R_g_menu_item_set_attribute_value, 3},
    {"R_g_menu_item_set_detailed_action", (DL_FUNC) &R_g_menu_item_set_detailed_action, 2},
    {"R_g_menu_item_set_icon", (DL_FUNC) &R_g_menu_item_set_icon, 2},
    {"R_g_menu_item_set_label", (DL_FUNC) &R_g_menu_item_set_label, 2},
    {"R_g_menu_item_set_link", (DL_FUNC) &R_g_menu_item_set_link, 3},
    {"R_g_menu_item_set_section", (DL_FUNC) &R_g_menu_item_set_section, 2},
    {"R_g_menu_item_set_submenu", (DL_FUNC) &R_g_menu_item_set_submenu, 2},
    {"R_g_menu_link_iter_get_name", (DL_FUNC) &R_g_menu_link_iter_get_name, 1},
    {"R_g_menu_link_iter_get_next", (DL_FUNC) &R_g_menu_link_iter_get_next, 1},
    {"R_g_menu_link_iter_get_value", (DL_FUNC) &R_g_menu_link_iter_get_value, 1},
    {"R_g_menu_link_iter_next", (DL_FUNC) &R_g_menu_link_iter_next, 1},
    {"R_g_menu_model_get_item_attribute_value", (DL_FUNC) &R_g_menu_model_get_item_attribute_value, 4},
    {"R_g_menu_model_get_item_link", (DL_FUNC) &R_g_menu_model_get_item_link, 3},
    {"R_g_menu_model_get_n_items", (DL_FUNC) &R_g_menu_model_get_n_items, 1},
    {"R_g_menu_model_is_mutable", (DL_FUNC) &R_g_menu_model_is_mutable, 1},
    {"R_g_menu_model_items_changed", (DL_FUNC) &R_g_menu_model_items_changed, 4},
    {"R_g_menu_model_iterate_item_attributes", (DL_FUNC) &R_g_menu_model_iterate_item_attributes, 2},
    {"R_g_menu_model_iterate_item_links", (DL_FUNC) &R_g_menu_model_iterate_item_links, 2},
    {"R_g_mount_can_eject", (DL_FUNC) &R_g_mount_can_eject, 1},
    {"R_g_mount_can_unmount", (DL_FUNC) &R_g_mount_can_unmount, 1},
    {"R_g_mount_eject", (DL_FUNC) &R_g_mount_eject, 5},
    {"R_g_mount_eject_finish", (DL_FUNC) &R_g_mount_eject_finish, 2},
    {"R_g_mount_eject_with_operation", (DL_FUNC) &R_g_mount_eject_with_operation, 6},
    {"R_g_mount_eject_with_operation_finish", (DL_FUNC) &R_g_mount_eject_with_operation_finish, 2},
    {"R_g_mount_get_default_location", (DL_FUNC) &R_g_mount_get_default_location, 1},
    {"R_g_mount_get_drive", (DL_FUNC) &R_g_mount_get_drive, 1},
    {"R_g_mount_get_icon", (DL_FUNC) &R_g_mount_get_icon, 1},
    {"R_g_mount_get_name", (DL_FUNC) &R_g_mount_get_name, 1},
    {"R_g_mount_get_root", (DL_FUNC) &R_g_mount_get_root, 1},
    {"R_g_mount_get_sort_key", (DL_FUNC) &R_g_mount_get_sort_key, 1},
    {"R_g_mount_get_symbolic_icon", (DL_FUNC) &R_g_mount_get_symbolic_icon, 1},
    {"R_g_mount_get_uuid", (DL_FUNC) &R_g_mount_get_uuid, 1},
    {"R_g_mount_get_volume", (DL_FUNC) &R_g_mount_get_volume, 1},
    {"R_g_mount_guess_content_type", (DL_FUNC) &R_g_mount_guess_content_type, 5},
    {"R_g_mount_guess_content_type_finish", (DL_FUNC) &R_g_mount_guess_content_type_finish, 2},
    {"R_g_mount_guess_content_type_sync", (DL_FUNC) &R_g_mount_guess_content_type_sync, 3},
    {"R_g_mount_is_shadowed", (DL_FUNC) &R_g_mount_is_shadowed, 1},
    {"R_g_mount_remount", (DL_FUNC) &R_g_mount_remount, 6},
    {"R_g_mount_remount_finish", (DL_FUNC) &R_g_mount_remount_finish, 2},
    {"R_g_mount_shadow", (DL_FUNC) &R_g_mount_shadow, 1},
    {"R_g_mount_unmount", (DL_FUNC) &R_g_mount_unmount, 5},
    {"R_g_mount_unmount_finish", (DL_FUNC) &R_g_mount_unmount_finish, 2},
    {"R_g_mount_unmount_with_operation", (DL_FUNC) &R_g_mount_unmount_with_operation, 6},
    {"R_g_mount_unmount_with_operation_finish", (DL_FUNC) &R_g_mount_unmount_with_operation_finish, 2},
    {"R_g_mount_unshadow", (DL_FUNC) &R_g_mount_unshadow, 1},
    {"R_g_mount_operation_new", (DL_FUNC) &R_g_mount_operation_new, 0},
    {"R_g_mount_operation_get_anonymous", (DL_FUNC) &R_g_mount_operation_get_anonymous, 1},
    {"R_g_mount_operation_get_choice", (DL_FUNC) &R_g_mount_operation_get_choice, 1},
    {"R_g_mount_operation_get_domain", (DL_FUNC) &R_g_mount_operation_get_domain, 1},
    {"R_g_mount_operation_get_password", (DL_FUNC) &R_g_mount_operation_get_password, 1},
    {"R_g_mount_operation_get_password_save", (DL_FUNC) &R_g_mount_operation_get_password_save, 1},
    {"R_g_mount_operation_get_username", (DL_FUNC) &R_g_mount_operation_get_username, 1},
    {"R_g_mount_operation_reply", (DL_FUNC) &R_g_mount_operation_reply, 2},
    {"R_g_mount_operation_set_anonymous", (DL_FUNC) &R_g_mount_operation_set_anonymous, 2},
    {"R_g_mount_operation_set_choice", (DL_FUNC) &R_g_mount_operation_set_choice, 2},
    {"R_g_mount_operation_set_domain", (DL_FUNC) &R_g_mount_operation_set_domain, 2},
    {"R_g_mount_operation_set_password", (DL_FUNC) &R_g_mount_operation_set_password, 2},
    {"R_g_mount_operation_set_password_save", (DL_FUNC) &R_g_mount_operation_set_password_save, 2},
    {"R_g_mount_operation_set_username", (DL_FUNC) &R_g_mount_operation_set_username, 2},
    {"R_g_native_socket_address_new", (DL_FUNC) &R_g_native_socket_address_new, 2},
    {"R_g_network_address_new", (DL_FUNC) &R_g_network_address_new, 2},
    {"R_g_network_address_new_loopback", (DL_FUNC) &R_g_network_address_new_loopback, 1},
    {"R_g_network_address_parse", (DL_FUNC) &R_g_network_address_parse, 2},
    {"R_g_network_address_parse_uri", (DL_FUNC) &R_g_network_address_parse_uri, 2},
    {"R_g_network_address_get_hostname", (DL_FUNC) &R_g_network_address_get_hostname, 1},
    {"R_g_network_address_get_port", (DL_FUNC) &R_g_network_address_get_port, 1},
    {"R_g_network_address_get_scheme", (DL_FUNC) &R_g_network_address_get_scheme, 1},
    {"R_g_network_monitor_get_default", (DL_FUNC) &R_g_network_monitor_get_default, 0},
    {"R_g_network_monitor_can_reach", (DL_FUNC) &R_g_network_monitor_can_reach, 3},
    {"R_g_network_monitor_can_reach_async", (DL_FUNC) &R_g_network_monitor_can_reach_async, 5},
    {"R_g_network_monitor_can_reach_finish", (DL_FUNC) &R_g_network_monitor_can_reach_finish, 2},
    {"R_g_network_monitor_get_connectivity", (DL_FUNC) &R_g_network_monitor_get_connectivity, 1},
    {"R_g_network_monitor_get_network_available", (DL_FUNC) &R_g_network_monitor_get_network_available, 1},
    {"R_g_network_monitor_get_network_metered", (DL_FUNC) &R_g_network_monitor_get_network_metered, 1},
    {"R_g_network_service_new", (DL_FUNC) &R_g_network_service_new, 3},
    {"R_g_network_service_get_domain", (DL_FUNC) &R_g_network_service_get_domain, 1},
    {"R_g_network_service_get_protocol", (DL_FUNC) &R_g_network_service_get_protocol, 1},
    {"R_g_network_service_get_scheme", (DL_FUNC) &R_g_network_service_get_scheme, 1},
    {"R_g_network_service_get_service", (DL_FUNC) &R_g_network_service_get_service, 1},
    {"R_g_network_service_set_scheme", (DL_FUNC) &R_g_network_service_set_scheme, 2},
    {"R_g_notification_new", (DL_FUNC) &R_g_notification_new, 1},
    {"R_g_notification_add_button", (DL_FUNC) &R_g_notification_add_button, 3},
    {"R_g_notification_add_button_with_target_value", (DL_FUNC) &R_g_notification_add_button_with_target_value, 4},
    {"R_g_notification_set_body", (DL_FUNC) &R_g_notification_set_body, 2},
    {"R_g_notification_set_default_action", (DL_FUNC) &R_g_notification_set_default_action, 2},
    {"R_g_notification_set_default_action_and_target_value", (DL_FUNC) &R_g_notification_set_default_action_and_target_value, 3},
    {"R_g_notification_set_icon", (DL_FUNC) &R_g_notification_set_icon, 2},
    {"R_g_notification_set_priority", (DL_FUNC) &R_g_notification_set_priority, 2},
    {"R_g_notification_set_title", (DL_FUNC) &R_g_notification_set_title, 2},
    {"R_g_notification_set_urgent", (DL_FUNC) &R_g_notification_set_urgent, 2},
    {"R_g_output_stream_clear_pending", (DL_FUNC) &R_g_output_stream_clear_pending, 1},
    {"R_g_output_stream_close", (DL_FUNC) &R_g_output_stream_close, 2},
    {"R_g_output_stream_close_async", (DL_FUNC) &R_g_output_stream_close_async, 5},
    {"R_g_output_stream_close_finish", (DL_FUNC) &R_g_output_stream_close_finish, 2},
    {"R_g_output_stream_flush", (DL_FUNC) &R_g_output_stream_flush, 2},
    {"R_g_output_stream_flush_async", (DL_FUNC) &R_g_output_stream_flush_async, 5},
    {"R_g_output_stream_flush_finish", (DL_FUNC) &R_g_output_stream_flush_finish, 2},
    {"R_g_output_stream_has_pending", (DL_FUNC) &R_g_output_stream_has_pending, 1},
    {"R_g_output_stream_is_closed", (DL_FUNC) &R_g_output_stream_is_closed, 1},
    {"R_g_output_stream_is_closing", (DL_FUNC) &R_g_output_stream_is_closing, 1},
    {"R_g_output_stream_set_pending", (DL_FUNC) &R_g_output_stream_set_pending, 1},
    {"R_g_output_stream_splice", (DL_FUNC) &R_g_output_stream_splice, 4},
    {"R_g_output_stream_splice_async", (DL_FUNC) &R_g_output_stream_splice_async, 7},
    {"R_g_output_stream_splice_finish", (DL_FUNC) &R_g_output_stream_splice_finish, 2},
    {"R_g_output_stream_write", (DL_FUNC) &R_g_output_stream_write, 4},
    {"R_g_output_stream_write_all", (DL_FUNC) &R_g_output_stream_write_all, 4},
    {"R_g_output_stream_write_all_async", (DL_FUNC) &R_g_output_stream_write_all_async, 7},
    {"R_g_output_stream_write_all_finish", (DL_FUNC) &R_g_output_stream_write_all_finish, 2},
    {"R_g_output_stream_write_async", (DL_FUNC) &R_g_output_stream_write_async, 7},
    {"R_g_output_stream_write_bytes", (DL_FUNC) &R_g_output_stream_write_bytes, 3},
    {"R_g_output_stream_write_bytes_async", (DL_FUNC) &R_g_output_stream_write_bytes_async, 6},
    {"R_g_output_stream_write_bytes_finish", (DL_FUNC) &R_g_output_stream_write_bytes_finish, 2},
    {"R_g_output_stream_write_finish", (DL_FUNC) &R_g_output_stream_write_finish, 2},
    {"R_g_permission_acquire", (DL_FUNC) &R_g_permission_acquire, 2},
    {"R_g_permission_acquire_async", (DL_FUNC) &R_g_permission_acquire_async, 4},
    {"R_g_permission_acquire_finish", (DL_FUNC) &R_g_permission_acquire_finish, 2},
    {"R_g_permission_get_allowed", (DL_FUNC) &R_g_permission_get_allowed, 1},
    {"R_g_permission_get_can_acquire", (DL_FUNC) &R_g_permission_get_can_acquire, 1},
    {"R_g_permission_get_can_release", (DL_FUNC) &R_g_permission_get_can_release, 1},
    {"R_g_permission_impl_update", (DL_FUNC) &R_g_permission_impl_update, 4},
    {"R_g_permission_release", (DL_FUNC) &R_g_permission_release, 2},
    {"R_g_permission_release_async", (DL_FUNC) &R_g_permission_release_async, 4},
    {"R_g_permission_release_finish", (DL_FUNC) &R_g_permission_release_finish, 2},
    {"R_g_pollable_input_stream_can_poll", (DL_FUNC) &R_g_pollable_input_stream_can_poll, 1},
    {"R_g_pollable_input_stream_create_source", (DL_FUNC) &R_g_pollable_input_stream_create_source, 2},
    {"R_g_pollable_input_stream_is_readable", (DL_FUNC) &R_g_pollable_input_stream_is_readable, 1},
    {"R_g_pollable_input_stream_read_nonblocking", (DL_FUNC) &R_g_pollable_input_stream_read_nonblocking, 3},
    {"R_g_pollable_output_stream_can_poll", (DL_FUNC) &R_g_pollable_output_stream_can_poll, 1},
    {"R_g_pollable_output_stream_create_source", (DL_FUNC) &R_g_pollable_output_stream_create_source, 2},
    {"R_g_pollable_output_stream_is_writable", (DL_FUNC) &R_g_pollable_output_stream_is_writable, 1},
    {"R_g_pollable_output_stream_write_nonblocking", (DL_FUNC) &R_g_pollable_output_stream_write_nonblocking, 4},
    {"R_g_property_action_new", (DL_FUNC) &R_g_property_action_new, 3},
    {"R_g_proxy_get_default_for_protocol", (DL_FUNC) &R_g_proxy_get_default_for_protocol, 1},
    {"R_g_proxy_connect", (DL_FUNC) &R_g_proxy_connect, 4},
    {"R_g_proxy_connect_async", (DL_FUNC) &R_g_proxy_connect_async, 6},
    {"R_g_proxy_connect_finish", (DL_FUNC) &R_g_proxy_connect_finish, 2},
    {"R_g_proxy_supports_hostname", (DL_FUNC) &R_g_proxy_supports_hostname, 1},
    {"R_g_proxy_address_new", (DL_FUNC) &R_g_proxy_address_new, 7},
    {"R_g_proxy_address_get_destination_hostname", (DL_FUNC) &R_g_proxy_address_get_destination_hostname, 1},
    {"R_g_proxy_address_get_destination_port", (DL_FUNC) &R_g_proxy_address_get_destination_port, 1},
    {"R_g_proxy_address_get_destination_protocol", (DL_FUNC) &R_g_proxy_address_get_destination_protocol, 1},
    {"R_g_proxy_address_get_password", (DL_FUNC) &R_g_proxy_address_get_password, 1},
    {"R_g_proxy_address_get_protocol", (DL_FUNC) &R_g_proxy_address_get_protocol, 1},
    {"R_g_proxy_address_get_uri", (DL_FUNC) &R_g_proxy_address_get_uri, 1},
    {"R_g_proxy_address_get_username", (DL_FUNC) &R_g_proxy_address_get_username, 1},
    {"R_g_proxy_resolver_get_default", (DL_FUNC) &R_g_proxy_resolver_get_default, 0},
    {"R_g_proxy_resolver_is_supported", (DL_FUNC) &R_g_proxy_resolver_is_supported, 1},
    {"R_g_proxy_resolver_lookup", (DL_FUNC) &R_g_proxy_resolver_lookup, 3},
    {"R_g_proxy_resolver_lookup_async", (DL_FUNC) &R_g_proxy_resolver_lookup_async, 5},
    {"R_g_proxy_resolver_lookup_finish", (DL_FUNC) &R_g_proxy_resolver_lookup_finish, 2},
    {"R_g_remote_action_group_activate_action_full", (DL_FUNC) &R_g_remote_action_group_activate_action_full, 4},
    {"R_g_remote_action_group_change_action_state_full", (DL_FUNC) &R_g_remote_action_group_change_action_state_full, 4},
    {"R_g_resolver_get_default", (DL_FUNC) &R_g_resolver_get_default, 0},
    {"R_g_resolver_lookup_by_address", (DL_FUNC) &R_g_resolver_lookup_by_address, 3},
    {"R_g_resolver_lookup_by_address_async", (DL_FUNC) &R_g_resolver_lookup_by_address_async, 5},
    {"R_g_resolver_lookup_by_address_finish", (DL_FUNC) &R_g_resolver_lookup_by_address_finish, 2},
    {"R_g_resolver_lookup_by_name", (DL_FUNC) &R_g_resolver_lookup_by_name, 3},
    {"R_g_resolver_lookup_by_name_async", (DL_FUNC) &R_g_resolver_lookup_by_name_async, 5},
    {"R_g_resolver_lookup_by_name_finish", (DL_FUNC) &R_g_resolver_lookup_by_name_finish, 2},
    {"R_g_resolver_lookup_records", (DL_FUNC) &R_g_resolver_lookup_records, 4},
    {"R_g_resolver_lookup_records_async", (DL_FUNC) &R_g_resolver_lookup_records_async, 6},
    {"R_g_resolver_lookup_records_finish", (DL_FUNC) &R_g_resolver_lookup_records_finish, 2},
    {"R_g_resolver_lookup_service", (DL_FUNC) &R_g_resolver_lookup_service, 5},
    {"R_g_resolver_lookup_service_async", (DL_FUNC) &R_g_resolver_lookup_service_async, 7},
    {"R_g_resolver_lookup_service_finish", (DL_FUNC) &R_g_resolver_lookup_service_finish, 2},
    {"R_g_resolver_set_default", (DL_FUNC) &R_g_resolver_set_default, 1},
    {"R_g_resolver_error_quark", (DL_FUNC) &R_g_resolver_error_quark, 0},
    {"R_g_resource_new_from_data", (DL_FUNC) &R_g_resource_new_from_data, 1},
    {"R_g_resource_enumerate_children", (DL_FUNC) &R_g_resource_enumerate_children, 3},
    {"R_g_resource_get_info", (DL_FUNC) &R_g_resource_get_info, 3},
    {"R_g_resource_lookup_data", (DL_FUNC) &R_g_resource_lookup_data, 3},
    {"R_g_resource_open_stream", (DL_FUNC) &R_g_resource_open_stream, 3},
    {"R_g_resource_ref", (DL_FUNC) &R_g_resource_ref, 1},
    {"R_g_resource_unref", (DL_FUNC) &R_g_resource_unref, 1},
    {"R_g_resource_load", (DL_FUNC) &R_g_resource_load, 1},
    {"R_g_resource_error_quark", (DL_FUNC) &R_g_resource_error_quark, 0},
    {"R_g_seekable_can_seek", (DL_FUNC) &R_g_seekable_can_seek, 1},
    {"R_g_seekable_can_truncate", (DL_FUNC) &R_g_seekable_can_truncate, 1},
    {"R_g_seekable_seek", (DL_FUNC) &R_g_seekable_seek, 4},
    {"R_g_seekable_tell", (DL_FUNC) &R_g_seekable_tell, 1},
    {"R_g_seekable_truncate", (DL_FUNC) &R_g_seekable_truncate, 3},
    {"R_g_settings_new", (DL_FUNC) &R_g_settings_new, 1},
    {"R_g_settings_new_full", (DL_FUNC) &R_g_settings_new_full, 3},
    {"R_g_settings_new_with_backend", (DL_FUNC) &R_g_settings_new_with_backend, 2},
    {"R_g_settings_new_with_backend_and_path", (DL_FUNC) &R_g_settings_new_with_backend_and_path, 3},
    {"R_g_settings_new_with_path", (DL_FUNC) &R_g_settings_new_with_path, 2},
    {"R_g_settings_list_relocatable_schemas", (DL_FUNC) &R_g_settings_list_relocatable_schemas, 0},
    {"R_g_settings_list_schemas", (DL_FUNC) &R_g_settings_list_schemas, 0},
    {"R_g_settings_sync", (DL_FUNC) &R_g_settings_sync, 0},
    {"R_g_settings_unbind", (DL_FUNC) &R_g_settings_unbind, 2},
    {"R_g_settings_apply", (DL_FUNC) &R_g_settings_apply, 1},
    {"R_g_settings_bind", (DL_FUNC) &R_g_settings_bind, 5},
    {"R_g_settings_bind_writable", (DL_FUNC) &R_g_settings_bind_writable, 5},
    {"R_g_settings_create_action", (DL_FUNC) &R_g_settings_create_action, 2},
    {"R_g_settings_delay", (DL_FUNC) &R_g_settings_delay, 1},
    {"R_g_settings_get_boolean", (DL_FUNC) &R_g_settings_get_boolean, 2},
    {"R_g_settings_get_child", (DL_FUNC) &R_g_settings_get_child, 2},
    {"R_g_settings_get_default_value", (DL_FUNC) &R_g_settings_get_default_value, 2},
    {"R_g_settings_get_double", (DL_FUNC) &R_g_settings_get_double, 2},
    {"R_g_settings_get_enum", (DL_FUNC) &R_g_settings_get_enum, 2},
    {"R_g_settings_get_flags", (DL_FUNC) &R_g_settings_get_flags, 2},
    {"R_g_settings_get_has_unapplied", (DL_FUNC) &R_g_settings_get_has_unapplied, 1},
    {"R_g_settings_get_int", (DL_FUNC) &R_g_settings_get_int, 2},
    {"R_g_settings_get_int64", (DL_FUNC) &R_g_settings_get_int64, 2},
    {"R_g_settings_get_mapped", (DL_FUNC) &R_g_settings_get_mapped, 4},
    {"R_g_settings_get_range", (DL_FUNC) &R_g_settings_get_range, 2},
    {"R_g_settings_get_string", (DL_FUNC) &R_g_settings_get_string, 2},
    {"R_g_settings_get_strv", (DL_FUNC) &R_g_settings_get_strv, 2},
    {"R_g_settings_get_uint", (DL_FUNC) &R_g_settings_get_uint, 2},
    {"R_g_settings_get_uint64", (DL_FUNC) &R_g_settings_get_uint64, 2},
    {"R_g_settings_get_user_value", (DL_FUNC) &R_g_settings_get_user_value, 2},
    {"R_g_settings_get_value", (DL_FUNC) &R_g_settings_get_value, 2},
    {"R_g_settings_is_writable", (DL_FUNC) &R_g_settings_is_writable, 2},
    {"R_g_settings_list_children", (DL_FUNC) &R_g_settings_list_children, 1},
    {"R_g_settings_list_keys", (DL_FUNC) &R_g_settings_list_keys, 1},
    {"R_g_settings_range_check", (DL_FUNC) &R_g_settings_range_check, 3},
    {"R_g_settings_reset", (DL_FUNC) &R_g_settings_reset, 2},
    {"R_g_settings_revert", (DL_FUNC) &R_g_settings_revert, 1},
    {"R_g_settings_set_boolean", (DL_FUNC) &R_g_settings_set_boolean, 3},
    {"R_g_settings_set_double", (DL_FUNC) &R_g_settings_set_double, 3},
    {"R_g_settings_set_enum", (DL_FUNC) &R_g_settings_set_enum, 3},
    {"R_g_settings_set_flags", (DL_FUNC) &R_g_settings_set_flags, 3},
    {"R_g_settings_set_int", (DL_FUNC) &R_g_settings_set_int, 3},
    {"R_g_settings_set_int64", (DL_FUNC) &R_g_settings_set_int64, 3},
    {"R_g_settings_set_string", (DL_FUNC) &R_g_settings_set_string, 3},
    {"R_g_settings_set_strv", (DL_FUNC) &R_g_settings_set_strv, 3},
    {"R_g_settings_set_uint", (DL_FUNC) &R_g_settings_set_uint, 3},
    {"R_g_settings_set_uint64", (DL_FUNC) &R_g_settings_set_uint64, 3},
    {"R_g_settings_set_value", (DL_FUNC) &R_g_settings_set_value, 3},
    {"R_g_settings_backend_flatten_tree", (DL_FUNC) &R_g_settings_backend_flatten_tree, 1},
    {"R_g_settings_backend_get_default", (DL_FUNC) &R_g_settings_backend_get_default, 0},
    {"R_g_settings_backend_changed", (DL_FUNC) &R_g_settings_backend_changed, 3},
    {"R_g_settings_backend_changed_tree", (DL_FUNC) &R_g_settings_backend_changed_tree, 3},
    {"R_g_settings_backend_keys_changed", (DL_FUNC) &R_g_settings_backend_keys_changed, 4},
    {"R_g_settings_backend_path_changed", (DL_FUNC) &R_g_settings_backend_path_changed, 3},
    {"R_g_settings_backend_path_writable_changed", (DL_FUNC) &R_g_settings_backend_path_writable_changed, 2},
    {"R_g_settings_backend_writable_changed", (DL_FUNC) &R_g_settings_backend_writable_changed, 2},
    {"R_g_settings_schema_get_id", (DL_FUNC) &R_g_settings_schema_get_id, 1},
    {"R_g_settings_schema_get_key", (DL_FUNC) &R_g_settings_schema_get_key, 2},
    {"R_g_settings_schema_get_path", (DL_FUNC) &R_g_settings_schema_get_path, 1},
    {"R_g_settings_schema_has_key", (DL_FUNC) &R_g_settings_schema_has_key, 2},
    {"R_g_settings_schema_list_children", (DL_FUNC) &R_g_settings_schema_list_children, 1},
    {"R_g_settings_schema_list_keys", (DL_FUNC) &R_g_settings_schema_list_keys, 1},
    {"R_g_settings_schema_ref", (DL_FUNC) &R_g_settings_schema_ref, 1},
    {"R_g_settings_schema_unref", (DL_FUNC) &R_g_settings_schema_unref, 1},
    {"R_g_settings_schema_key_get_default_value", (DL_FUNC) &R_g_settings_schema_key_get_default_value, 1},
    {"R_g_settings_schema_key_get_description", (DL_FUNC) &R_g_settings_schema_key_get_description, 1},
    {"R_g_settings_schema_key_get_name", (DL_FUNC) &R_g_settings_schema_key_get_name, 1},
    {"R_g_settings_schema_key_get_range", (DL_FUNC) &R_g_settings_schema_key_get_range, 1},
    {"R_g_settings_schema_key_get_summary", (DL_FUNC) &R_g_settings_schema_key_get_summary, 1},
    {"R_g_settings_schema_key_get_value_type", (DL_FUNC) &R_g_settings_schema_key_get_value_type, 1},
    {"R_g_settings_schema_key_range_check", (DL_FUNC) &R_g_settings_schema_key_range_check, 2},
    {"R_g_settings_schema_key_ref", (DL_FUNC) &R_g_settings_schema_key_ref, 1},
    {"R_g_settings_schema_key_unref", (DL_FUNC) &R_g_settings_schema_key_unref, 1},
    {"R_g_settings_schema_source_new_from_directory", (DL_FUNC) &R_g_settings_schema_source_new_from_directory, 3},
    {"R_g_settings_schema_source_list_schemas", (DL_FUNC) &R_g_settings_schema_source_list_schemas, 2},
    {"R_g_settings_schema_source_lookup", (DL_FUNC) &R_g_settings_schema_source_lookup, 3},
    {"R_g_settings_schema_source_ref", (DL_FUNC) &R_g_settings_schema_source_ref, 1},
    {"R_g_settings_schema_source_unref", (DL_FUNC) &R_g_settings_schema_source_unref, 1},
    {"R_g_settings_schema_source_get_default", (DL_FUNC) &R_g_settings_schema_source_get_default, 0},
    {"R_g_simple_action_new", (DL_FUNC) &R_g_simple_action_new, 2},
    {"R_g_simple_action_new_stateful", (DL_FUNC) &R_g_simple_action_new_stateful, 3},
    {"R_g_simple_action_set_enabled", (DL_FUNC) &R_g_simple_action_set_enabled, 2},
    {"R_g_simple_action_set_state", (DL_FUNC) &R_g_simple_action_set_state, 2},
    {"R_g_simple_action_set_state_hint", (DL_FUNC) &R_g_simple_action_set_state_hint, 2},
    {"R_g_simple_action_group_new", (DL_FUNC) &R_g_simple_action_group_new, 0},
    {"R_g_simple_action_group_add_entries", (DL_FUNC) &R_g_simple_action_group_add_entries, 4},
    {"R_g_simple_action_group_insert", (DL_FUNC) &R_g_simple_action_group_insert, 2},
    {"R_g_simple_action_group_lookup", (DL_FUNC) &R_g_simple_action_group_lookup, 2},
    {"R_g_simple_action_group_remove", (DL_FUNC) &R_g_simple_action_group_remove, 2},
    {"R_g_simple_async_result_new", (DL_FUNC) &R_g_simple_async_result_new, 4},
    {"R_g_simple_async_result_new_from_error", (DL_FUNC) &R_g_simple_async_result_new_from_error, 4},
    {"R_g_simple_async_result_is_valid", (DL_FUNC) &R_g_simple_async_result_is_valid, 3},
    {"R_g_simple_async_result_complete", (DL_FUNC) &R_g_simple_async_result_complete, 1},
    {"R_g_simple_async_result_complete_in_idle", (DL_FUNC) &R_g_simple_async_result_complete_in_idle, 1},
    {"R_g_simple_async_result_get_op_res_gboolean", (DL_FUNC) &R_g_simple_async_result_get_op_res_gboolean, 1},
    {"R_g_simple_async_result_get_op_res_gssize", (DL_FUNC) &R_g_simple_async_result_get_op_res_gssize, 1},
    {"R_g_simple_async_result_propagate_error", (DL_FUNC) &R_g_simple_async_result_propagate_error, 1},
    {"R_g_simple_async_result_set_check_cancellable", (DL_FUNC) &R_g_simple_async_result_set_check_cancellable, 2},
    {"R_g_simple_async_result_set_from_error", (DL_FUNC) &R_g_simple_async_result_set_from_error, 2},
    {"R_g_simple_async_result_set_handle_cancellation", (DL_FUNC) &R_g_simple_async_result_set_handle_cancellation, 2},
    {"R_g_simple_async_result_set_op_res_gboolean", (DL_FUNC) &R_g_simple_async_result_set_op_res_gboolean, 2},
    {"R_g_simple_async_result_set_op_res_gssize", (DL_FUNC) &R_g_simple_async_result_set_op_res_gssize, 2},
    {"R_g_simple_io_stream_new", (DL_FUNC) &R_g_simple_io_stream_new, 2},
    {"R_g_simple_permission_new", (DL_FUNC) &R_g_simple_permission_new, 1},
    {"R_g_simple_proxy_resolver_new", (DL_FUNC) &R_g_simple_proxy_resolver_new, 2},
    {"R_g_simple_proxy_resolver_set_default_proxy", (DL_FUNC) &R_g_simple_proxy_resolver_set_default_proxy, 2},
    {"R_g_simple_proxy_resolver_set_ignore_hosts", (DL_FUNC) &R_g_simple_proxy_resolver_set_ignore_hosts, 2},
    {"R_g_simple_proxy_resolver_set_uri_proxy", (DL_FUNC) &R_g_simple_proxy_resolver_set_uri_proxy, 3},
    {"R_g_socket_new", (DL_FUNC) &R_g_socket_new, 3},
    {"R_g_socket_new_from_fd", (DL_FUNC) &R_g_socket_new_from_fd, 1},
    {"R_g_socket_accept", (DL_FUNC) &R_g_socket_accept, 2},
    {"R_g_socket_bind", (DL_FUNC) &R_g_socket_bind, 3},
    {"R_g_socket_check_connect_result", (DL_FUNC) &R_g_socket_check_connect_result, 1},
    {"R_g_socket_close", (DL_FUNC) &R_g_socket_close, 1},
    {"R_g_socket_condition_check", (DL_FUNC) &R_g_socket_condition_check, 2},
    {"R_g_socket_condition_timed_wait", (DL_FUNC) &R_g_socket_condition_timed_wait, 4},
    {"R_g_socket_condition_wait", (DL_FUNC) &R_g_socket_condition_wait, 3},
    {"R_g_socket_connect", (DL_FUNC) &R_g_socket_connect, 3},
    {"R_g_socket_connection_factory_create_connection", (DL_FUNC) &R_g_socket_connection_factory_create_connection, 1},
    {"R_g_socket_get_available_bytes", (DL_FUNC) &R_g_socket_get_available_bytes, 1},
    {"R_g_socket_get_blocking", (DL_FUNC) &R_g_socket_get_blocking, 1},
    {"R_g_socket_get_broadcast", (DL_FUNC) &R_g_socket_get_broadcast, 1},
    {"R_g_socket_get_credentials", (DL_FUNC) &R_g_socket_get_credentials, 1},
    {"R_g_socket_get_family", (DL_FUNC) &R_g_socket_get_family, 1},
    {"R_g_socket_get_fd", (DL_FUNC) &R_g_socket_get_fd, 1},
    {"R_g_socket_get_keepalive", (DL_FUNC) &R_g_socket_get_keepalive, 1},
    {"R_g_socket_get_listen_backlog", (DL_FUNC) &R_g_socket_get_listen_backlog, 1},
    {"R_g_socket_get_local_address", (DL_FUNC) &R_g_socket_get_local_address, 1},
    {"R_g_socket_get_multicast_loopback", (DL_FUNC) &R_g_socket_get_multicast_loopback, 1},
    {"R_g_socket_get_multicast_ttl", (DL_FUNC) &R_g_socket_get_multicast_ttl, 1},
    {"R_g_socket_get_option", (DL_FUNC) &R_g_socket_get_option, 3},
    {"R_g_socket_get_protocol", (DL_FUNC) &R_g_socket_get_protocol, 1},
    {"R_g_socket_get_remote_address", (DL_FUNC) &R_g_socket_get_remote_address, 1},
    {"R_g_socket_get_socket_type", (DL_FUNC) &R_g_socket_get_socket_type, 1},
    {"R_g_socket_get_timeout", (DL_FUNC) &R_g_socket_get_timeout, 1},
    {"R_g_socket_get_ttl", (DL_FUNC) &R_g_socket_get_ttl, 1},
    {"R_g_socket_is_closed", (DL_FUNC) &R_g_socket_is_closed, 1},
    {"R_g_socket_is_connected", (DL_FUNC) &R_g_socket_is_connected, 1},
    {"R_g_socket_join_multicast_group", (DL_FUNC) &R_g_socket_join_multicast_group, 4},
    {"R_g_socket_join_multicast_group_ssm", (DL_FUNC) &R_g_socket_join_multicast_group_ssm, 4},
    {"R_g_socket_leave_multicast_group", (DL_FUNC) &R_g_socket_leave_multicast_group, 4},
    {"R_g_socket_leave_multicast_group_ssm", (DL_FUNC) &R_g_socket_leave_multicast_group_ssm, 4},
    {"R_g_socket_listen", (DL_FUNC) &R_g_socket_listen, 1},
    {"R_g_socket_receive", (DL_FUNC) &R_g_socket_receive, 3},
    {"R_g_socket_receive_from", (DL_FUNC) &R_g_socket_receive_from, 3},
    {"R_g_socket_receive_message", (DL_FUNC) &R_g_socket_receive_message, 4},
    {"R_g_socket_receive_messages", (DL_FUNC) &R_g_socket_receive_messages, 5},
    {"R_g_socket_receive_with_blocking", (DL_FUNC) &R_g_socket_receive_with_blocking, 4},
    {"R_g_socket_send", (DL_FUNC) &R_g_socket_send, 4},
    {"R_g_socket_send_message", (DL_FUNC) &R_g_socket_send_message, 8},
    {"R_g_socket_send_messages", (DL_FUNC) &R_g_socket_send_messages, 5},
    {"R_g_socket_send_to", (DL_FUNC) &R_g_socket_send_to, 5},
    {"R_g_socket_send_with_blocking", (DL_FUNC) &R_g_socket_send_with_blocking, 5},
    {"R_g_socket_set_blocking", (DL_FUNC) &R_g_socket_set_blocking, 2},
    {"R_g_socket_set_broadcast", (DL_FUNC) &R_g_socket_set_broadcast, 2},
    {"R_g_socket_set_keepalive", (DL_FUNC) &R_g_socket_set_keepalive, 2},
    {"R_g_socket_set_listen_backlog", (DL_FUNC) &R_g_socket_set_listen_backlog, 2},
    {"R_g_socket_set_multicast_loopback", (DL_FUNC) &R_g_socket_set_multicast_loopback, 2},
    {"R_g_socket_set_multicast_ttl", (DL_FUNC) &R_g_socket_set_multicast_ttl, 2},
    {"R_g_socket_set_option", (DL_FUNC) &R_g_socket_set_option, 4},
    {"R_g_socket_set_timeout", (DL_FUNC) &R_g_socket_set_timeout, 2},
    {"R_g_socket_set_ttl", (DL_FUNC) &R_g_socket_set_ttl, 2},
    {"R_g_socket_shutdown", (DL_FUNC) &R_g_socket_shutdown, 3},
    {"R_g_socket_speaks_ipv4", (DL_FUNC) &R_g_socket_speaks_ipv4, 1},
    {"R_g_socket_address_new_from_native", (DL_FUNC) &R_g_socket_address_new_from_native, 2},
    {"R_g_socket_address_get_family", (DL_FUNC) &R_g_socket_address_get_family, 1},
    {"R_g_socket_address_get_native_size", (DL_FUNC) &R_g_socket_address_get_native_size, 1},
    {"R_g_socket_address_to_native", (DL_FUNC) &R_g_socket_address_to_native, 3},
    {"R_g_socket_address_enumerator_next", (DL_FUNC) &R_g_socket_address_enumerator_next, 2},
    {"R_g_socket_address_enumerator_next_async", (DL_FUNC) &R_g_socket_address_enumerator_next_async, 4},
    {"R_g_socket_address_enumerator_next_finish", (DL_FUNC) &R_g_socket_address_enumerator_next_finish, 2},
    {"R_g_socket_client_new", (DL_FUNC) &R_g_socket_client_new, 0},
    {"R_g_socket_client_add_application_proxy", (DL_FUNC) &R_g_socket_client_add_application_proxy, 2},
    {"R_g_socket_client_connect", (DL_FUNC) &R_g_socket_client_connect, 3},
    {"R_g_socket_client_connect_async", (DL_FUNC) &R_g_socket_client_connect_async, 5},
    {"R_g_socket_client_connect_finish", (DL_FUNC) &R_g_socket_client_connect_finish, 2},
    {"R_g_socket_client_connect_to_host", (DL_FUNC) &R_g_socket_client_connect_to_host, 4},
    {"R_g_socket_client_connect_to_host_async", (DL_FUNC) &R_g_socket_client_connect_to_host_async, 6},
    {"R_g_socket_client_connect_to_host_finish", (DL_FUNC) &R_g_socket_client_connect_to_host_finish, 2},
    {"R_g_socket_client_connect_to_service", (DL_FUNC) &R_g_socket_client_connect_to_service, 4},
    {"R_g_socket_client_connect_to_service_async", (DL_FUNC) &R_g_socket_client_connect_to_service_async, 6},
    {"R_g_socket_client_connect_to_service_finish", (DL_FUNC) &R_g_socket_client_connect_to_service_finish, 2},
    {"R_g_socket_client_connect_to_uri", (DL_FUNC) &R_g_socket_client_connect_to_uri, 4},
    {"R_g_socket_client_connect_to_uri_async", (DL_FUNC) &R_g_socket_client_connect_to_uri_async, 6},
    {"R_g_socket_client_connect_to_uri_finish", (DL_FUNC) &R_g_socket_client_connect_to_uri_finish, 2},
    {"R_g_socket_client_get_enable_proxy", (DL_FUNC) &R_g_socket_client_get_enable_proxy, 1},
    {"R_g_socket_client_get_family", (DL_FUNC) &R_g_socket_client_get_family, 1},
    {"R_g_socket_client_get_local_address", (DL_FUNC) &R_g_socket_client_get_local_address, 1},
    {"R_g_socket_client_get_protocol", (DL_FUNC) &R_g_socket_client_get_protocol, 1},
    {"R_g_socket_client_get_proxy_resolver", (DL_FUNC) &R_g_socket_client_get_proxy_resolver, 1},
    {"R_g_socket_client_get_socket_type", (DL_FUNC) &R_g_socket_client_get_socket_type, 1},
    {"R_g_socket_client_get_timeout", (DL_FUNC) &R_g_socket_client_get_timeout, 1},
    {"R_g_socket_client_get_tls", (DL_FUNC) &R_g_socket_client_get_tls, 1},
    {"R_g_socket_client_get_tls_validation_flags", (DL_FUNC) &R_g_socket_client_get_tls_validation_flags, 1},
    {"R_g_socket_client_set_enable_proxy", (DL_FUNC) &R_g_socket_client_set_enable_proxy, 2},
    {"R_g_socket_client_set_family", (DL_FUNC) &R_g_socket_client_set_family, 2},
    {"R_g_socket_client_set_local_address", (DL_FUNC) &R_g_socket_client_set_local_address, 2},
    {"R_g_socket_client_set_protocol", (DL_FUNC) &R_g_socket_client_set_protocol, 2},
    {"R_g_socket_client_set_proxy_resolver", (DL_FUNC) &R_g_socket_client_set_proxy_resolver, 2},
    {"R_g_socket_client_set_socket_type", (DL_FUNC) &R_g_socket_client_set_socket_type, 2},
    {"R_g_socket_client_set_timeout", (DL_FUNC) &R_g_socket_client_set_timeout, 2},
    {"R_g_socket_client_set_tls", (DL_FUNC) &R_g_socket_client_set_tls, 2},
    {"R_g_socket_client_set_tls_validation_flags", (DL_FUNC) &R_g_socket_client_set_tls_validation_flags, 2},
    {"R_g_socket_connectable_enumerate", (DL_FUNC) &R_g_socket_connectable_enumerate, 1},
    {"R_g_socket_connectable_proxy_enumerate", (DL_FUNC) &R_g_socket_connectable_proxy_enumerate, 1},
    {"R_g_socket_connectable_to_string", (DL_FUNC) &R_g_socket_connectable_to_string, 1},
    {"R_g_socket_connection_factory_lookup_type", (DL_FUNC) &R_g_socket_connection_factory_lookup_type, 3},
    {"R_g_socket_connection_factory_register_type", (DL_FUNC) &R_g_socket_connection_factory_register_type, 4},
    {"R_g_socket_connection_connect", (DL_FUNC) &R_g_socket_connection_connect, 3},
    {"R_g_socket_connection_connect_async", (DL_FUNC) &R_g_socket_connection_connect_async, 5},
    {"R_g_socket_connection_connect_finish", (DL_FUNC) &R_g_socket_connection_connect_finish, 2},
    {"R_g_socket_connection_get_local_address", (DL_FUNC) &R_g_socket_connection_get_local_address, 1},
    {"R_g_socket_connection_get_remote_address", (DL_FUNC) &R_g_socket_connection_get_remote_address, 1},
    {"R_g_socket_connection_get_socket", (DL_FUNC) &R_g_socket_connection_get_socket, 1},
    {"R_g_socket_connection_is_connected", (DL_FUNC) &R_g_socket_connection_is_connected, 1},
    {"R_g_socket_control_message_deserialize", (DL_FUNC) &R_g_socket_control_message_deserialize, 4},
    {"R_g_socket_control_message_get_level", (DL_FUNC) &R_g_socket_control_message_get_level, 1},
    {"R_g_socket_control_message_get_msg_type", (DL_FUNC) &R_g_socket_control_message_get_msg_type, 1},
    {"R_g_socket_control_message_get_size", (DL_FUNC) &R_g_socket_control_message_get_size, 1},
    {"R_g_socket_control_message_serialize", (DL_FUNC) &R_g_socket_control_message_serialize, 2},
    {"R_g_socket_listener_new", (DL_FUNC) &R_g_socket_listener_new, 0},
    {"R_g_socket_listener_accept", (DL_FUNC) &R_g_socket_listener_accept, 2},
    {"R_g_socket_listener_accept_async", (DL_FUNC) &R_g_socket_listener_accept_async, 4},
    {"R_g_socket_listener_accept_finish", (DL_FUNC) &R_g_socket_listener_accept_finish, 2},
    {"R_g_socket_listener_accept_socket", (DL_FUNC) &R_g_socket_listener_accept_socket, 2},
    {"R_g_socket_listener_accept_socket_async", (DL_FUNC) &R_g_socket_listener_accept_socket_async, 4},
    {"R_g_socket_listener_accept_socket_finish", (DL_FUNC) &R_g_socket_listener_accept_socket_finish, 2},
    {"R_g_socket_listener_add_address", (DL_FUNC) &R_g_socket_listener_add_address, 5},
    {"R_g_socket_listener_add_any_inet_port", (DL_FUNC) &R_g_socket_listener_add_any_inet_port, 2},
    {"R_g_socket_listener_add_inet_port", (DL_FUNC) &R_g_socket_listener_add_inet_port, 3},
    {"R_g_socket_listener_add_socket", (DL_FUNC) &R_g_socket_listener_add_socket, 3},
    {"R_g_socket_listener_close", (DL_FUNC) &R_g_socket_listener_close, 1},
    {"R_g_socket_listener_set_backlog", (DL_FUNC) &R_g_socket_listener_set_backlog, 2},
    {"R_g_socket_service_new", (DL_FUNC) &R_g_socket_service_new, 0},
    {"R_g_socket_service_is_active", (DL_FUNC) &R_g_socket_service_is_active, 1},
    {"R_g_socket_service_start", (DL_FUNC) &R_g_socket_service_start, 1},
    {"R_g_socket_service_stop", (DL_FUNC) &R_g_socket_service_stop, 1},
    {"R_g_srv_target_new", (DL_FUNC) &R_g_srv_target_new, 4},
    {"R_g_srv_target_copy", (DL_FUNC) &R_g_srv_target_copy, 1},
    {"R_g_srv_target_free", (DL_FUNC) &R_g_srv_target_free, 1},
    {"R_g_srv_target_get_hostname", (DL_FUNC) &R_g_srv_target_get_hostname, 1},
    {"R_g_srv_target_get_port", (DL_FUNC) &R_g_srv_target_get_port, 1},
    {"R_g_srv_target_get_priority", (DL_FUNC) &R_g_srv_target_get_priority, 1},
    {"R_g_srv_target_get_weight", (DL_FUNC) &R_g_srv_target_get_weight, 1},
    {"R_g_static_resource_fini", (DL_FUNC) &R_g_static_resource_fini, 1},
    {"R_g_static_resource_get_resource", (DL_FUNC) &R_g_static_resource_get_resource, 1},
    {"R_g_static_resource_init", (DL_FUNC) &R_g_static_resource_init, 1},
    {"R_g_task_new", (DL_FUNC) &R_g_task_new, 4},
    {"R_g_task_is_valid", (DL_FUNC) &R_g_task_is_valid, 2},
    {"R_g_task_report_error", (DL_FUNC) &R_g_task_report_error, 5},
    {"R_g_task_get_cancellable", (DL_FUNC) &R_g_task_get_cancellable, 1},
    {"R_g_task_get_check_cancellable", (DL_FUNC) &R_g_task_get_check_cancellable, 1},
    {"R_g_task_get_completed", (DL_FUNC) &R_g_task_get_completed, 1},
    {"R_g_task_get_context", (DL_FUNC) &R_g_task_get_context, 1},
    {"R_g_task_get_priority", (DL_FUNC) &R_g_task_get_priority, 1},
    {"R_g_task_get_return_on_cancel", (DL_FUNC) &R_g_task_get_return_on_cancel, 1},
    {"R_g_task_get_source_object", (DL_FUNC) &R_g_task_get_source_object, 1},
    {"R_g_task_get_source_tag", (DL_FUNC) &R_g_task_get_source_tag, 1},
    {"R_g_task_get_task_data", (DL_FUNC) &R_g_task_get_task_data, 1},
    {"R_g_task_had_error", (DL_FUNC) &R_g_task_had_error, 1},
    {"R_g_task_propagate_boolean", (DL_FUNC) &R_g_task_propagate_boolean, 1},
    {"R_g_task_propagate_int", (DL_FUNC) &R_g_task_propagate_int, 1},
    {"R_g_task_propagate_pointer", (DL_FUNC) &R_g_task_propagate_pointer, 1},
    {"R_g_task_return_boolean", (DL_FUNC) &R_g_task_return_boolean, 2},
    {"R_g_task_return_error", (DL_FUNC) &R_g_task_return_error, 2},
    {"R_g_task_return_error_if_cancelled", (DL_FUNC) &R_g_task_return_error_if_cancelled, 1},
    {"R_g_task_return_int", (DL_FUNC) &R_g_task_return_int, 2},
    {"R_g_task_return_pointer", (DL_FUNC) &R_g_task_return_pointer, 3},
    {"R_g_task_run_in_thread", (DL_FUNC) &R_g_task_run_in_thread, 2},
    {"R_g_task_run_in_thread_sync", (DL_FUNC) &R_g_task_run_in_thread_sync, 2},
    {"R_g_task_set_check_cancellable", (DL_FUNC) &R_g_task_set_check_cancellable, 2},
    {"R_g_task_set_priority", (DL_FUNC) &R_g_task_set_priority, 2},
    {"R_g_task_set_return_on_cancel", (DL_FUNC) &R_g_task_set_return_on_cancel, 2},
    {"R_g_task_set_source_tag", (DL_FUNC) &R_g_task_set_source_tag, 2},
    {"R_g_task_set_task_data", (DL_FUNC) &R_g_task_set_task_data, 3},
    {"R_g_tcp_connection_get_graceful_disconnect", (DL_FUNC) &R_g_tcp_connection_get_graceful_disconnect, 1},
    {"R_g_tcp_connection_set_graceful_disconnect", (DL_FUNC) &R_g_tcp_connection_set_graceful_disconnect, 2},
    {"R_g_tcp_wrapper_connection_new", (DL_FUNC) &R_g_tcp_wrapper_connection_new, 2},
    {"R_g_tcp_wrapper_connection_get_base_io_stream", (DL_FUNC) &R_g_tcp_wrapper_connection_get_base_io_stream, 1},
    {"R_g_test_dbus_new", (DL_FUNC) &R_g_test_dbus_new, 1},
    {"R_g_test_dbus_unset", (DL_FUNC) &R_g_test_dbus_unset, 0},
    {"R_g_test_dbus_add_service_dir", (DL_FUNC) &R_g_test_dbus_add_service_dir, 2},
    {"R_g_test_dbus_down", (DL_FUNC) &R_g_test_dbus_down, 1},
    {"R_g_test_dbus_get_bus_address", (DL_FUNC) &R_g_test_dbus_get_bus_address, 1},
    {"R_g_test_dbus_get_flags", (DL_FUNC) &R_g_test_dbus_get_flags, 1},
    {"R_g_test_dbus_stop", (DL_FUNC) &R_g_test_dbus_stop, 1},
    {"R_g_test_dbus_up", (DL_FUNC) &R_g_test_dbus_up, 1},
    {"R_g_themed_icon_new", (DL_FUNC) &R_g_themed_icon_new, 1},
    {"R_g_themed_icon_new_from_names", (DL_FUNC) &R_g_themed_icon_new_from_names, 2},
    {"R_g_themed_icon_new_with_default_fallbacks", (DL_FUNC) &R_g_themed_icon_new_with_default_fallbacks, 1},
    {"R_g_themed_icon_append_name", (DL_FUNC) &R_g_themed_icon_append_name, 2},
    {"R_g_themed_icon_get_names", (DL_FUNC) &R_g_themed_icon_get_names, 1},
    {"R_g_themed_icon_prepend_name", (DL_FUNC) &R_g_themed_icon_prepend_name, 2},
    {"R_g_threaded_socket_service_new", (DL_FUNC) &R_g_threaded_socket_service_new, 1},
    {"R_g_vfs_get_default", (DL_FUNC) &R_g_vfs_get_default, 0},
    {"R_g_vfs_get_local", (DL_FUNC) &R_g_vfs_get_local, 0},
    {"R_g_vfs_get_file_for_path", (DL_FUNC) &R_g_vfs_get_file_for_path, 2},
    {"R_g_vfs_get_file_for_uri", (DL_FUNC) &R_g_vfs_get_file_for_uri, 2},
    {"R_g_vfs_get_supported_uri_schemes", (DL_FUNC) &R_g_vfs_get_supported_uri_schemes, 1},
    {"R_g_vfs_is_active", (DL_FUNC) &R_g_vfs_is_active, 1},
    {"R_g_vfs_parse_name", (DL_FUNC) &R_g_vfs_parse_name, 2},
    {"R_g_vfs_register_uri_scheme", (DL_FUNC) &R_g_vfs_register_uri_scheme, 8},
    {"R_g_vfs_unregister_uri_scheme", (DL_FUNC) &R_g_vfs_unregister_uri_scheme, 2},
    {"R_g_volume_can_eject", (DL_FUNC) &R_g_volume_can_eject, 1},
    {"R_g_volume_can_mount", (DL_FUNC) &R_g_volume_can_mount, 1},
    {"R_g_volume_eject", (DL_FUNC) &R_g_volume_eject, 5},
    {"R_g_volume_eject_finish", (DL_FUNC) &R_g_volume_eject_finish, 2},
    {"R_g_volume_eject_with_operation", (DL_FUNC) &R_g_volume_eject_with_operation, 6},
    {"R_g_volume_eject_with_operation_finish", (DL_FUNC) &R_g_volume_eject_with_operation_finish, 2},
    {"R_g_volume_enumerate_identifiers", (DL_FUNC) &R_g_volume_enumerate_identifiers, 1},
    {"R_g_volume_get_activation_root", (DL_FUNC) &R_g_volume_get_activation_root, 1},
    {"R_g_volume_get_drive", (DL_FUNC) &R_g_volume_get_drive, 1},
    {"R_g_volume_get_icon", (DL_FUNC) &R_g_volume_get_icon, 1},
    {"R_g_volume_get_identifier", (DL_FUNC) &R_g_volume_get_identifier, 2},
    {"R_g_volume_get_mount", (DL_FUNC) &R_g_volume_get_mount, 1},
    {"R_g_volume_get_name", (DL_FUNC) &R_g_volume_get_name, 1},
    {"R_g_volume_get_sort_key", (DL_FUNC) &R_g_volume_get_sort_key, 1},
    {"R_g_volume_get_symbolic_icon", (DL_FUNC) &R_g_volume_get_symbolic_icon, 1},
    {"R_g_volume_get_uuid", (DL_FUNC) &R_g_volume_get_uuid, 1},
    {"R_g_volume_mount", (DL_FUNC) &R_g_volume_mount, 6},
    {"R_g_volume_mount_finish", (DL_FUNC) &R_g_volume_mount_finish, 2},
    {"R_g_volume_should_automount", (DL_FUNC) &R_g_volume_should_automount, 1},
    {"R_g_volume_monitor_adopt_orphan_mount", (DL_FUNC) &R_g_volume_monitor_adopt_orphan_mount, 1},
    {"R_g_volume_monitor_get", (DL_FUNC) &R_g_volume_monitor_get, 0},
    {"R_g_volume_monitor_get_connected_drives", (DL_FUNC) &R_g_volume_monitor_get_connected_drives, 1},
    {"R_g_volume_monitor_get_mount_for_uuid", (DL_FUNC) &R_g_volume_monitor_get_mount_for_uuid, 2},
    {"R_g_volume_monitor_get_mounts", (DL_FUNC) &R_g_volume_monitor_get_mounts, 1},
    {"R_g_volume_monitor_get_volume_for_uuid", (DL_FUNC) &R_g_volume_monitor_get_volume_for_uuid, 2},
    {"R_g_volume_monitor_get_volumes", (DL_FUNC) &R_g_volume_monitor_get_volumes, 1},
    {"R_g_zlib_compressor_new", (DL_FUNC) &R_g_zlib_compressor_new, 2},
    {"R_g_zlib_compressor_get_file_info", (DL_FUNC) &R_g_zlib_compressor_get_file_info, 1},
    {"R_g_zlib_compressor_set_file_info", (DL_FUNC) &R_g_zlib_compressor_set_file_info, 2},
    {"R_g_zlib_decompressor_new", (DL_FUNC) &R_g_zlib_decompressor_new, 1},
    {"R_g_zlib_decompressor_get_file_info", (DL_FUNC) &R_g_zlib_decompressor_get_file_info, 1},
    {"R_g_bus_get", (DL_FUNC) &R_g_bus_get, 4},
    {"R_g_bus_get_finish", (DL_FUNC) &R_g_bus_get_finish, 1},
    {"R_g_bus_get_sync", (DL_FUNC) &R_g_bus_get_sync, 2},
    {"R_g_bus_own_name", (DL_FUNC) &R_g_bus_own_name, 8},
    {"R_g_bus_own_name_on_connection", (DL_FUNC) &R_g_bus_own_name_on_connection, 7},
    {"R_g_bus_own_name_on_connection_with_closures", (DL_FUNC) &R_g_bus_own_name_on_connection_with_closures, 5},
    {"R_g_bus_own_name_with_closures", (DL_FUNC) &R_g_bus_own_name_with_closures, 6},
    {"R_g_bus_unown_name", (DL_FUNC) &R_g_bus_unown_name, 1},
    {"R_g_bus_unwatch_name", (DL_FUNC) &R_g_bus_unwatch_name, 1},
    {"R_g_bus_watch_name", (DL_FUNC) &R_g_bus_watch_name, 7},
    {"R_g_bus_watch_name_on_connection", (DL_FUNC) &R_g_bus_watch_name_on_connection, 7},
    {"R_g_bus_watch_name_on_connection_with_closures", (DL_FUNC) &R_g_bus_watch_name_on_connection_with_closures, 5},
    {"R_g_bus_watch_name_with_closures", (DL_FUNC) &R_g_bus_watch_name_with_closures, 5},
    {"R_g_content_type_can_be_executable", (DL_FUNC) &R_g_content_type_can_be_executable, 1},
    {"R_g_content_type_equals", (DL_FUNC) &R_g_content_type_equals, 2},
    {"R_g_content_type_from_mime_type", (DL_FUNC) &R_g_content_type_from_mime_type, 1},
    {"R_g_content_type_get_description", (DL_FUNC) &R_g_content_type_get_description, 1},
    {"R_g_content_type_get_generic_icon_name", (DL_FUNC) &R_g_content_type_get_generic_icon_name, 1},
    {"R_g_content_type_get_icon", (DL_FUNC) &R_g_content_type_get_icon, 1},
    {"R_g_content_type_get_mime_type", (DL_FUNC) &R_g_content_type_get_mime_type, 1},
    {"R_g_content_type_get_symbolic_icon", (DL_FUNC) &R_g_content_type_get_symbolic_icon, 1},
    {"R_g_content_type_guess", (DL_FUNC) &R_g_content_type_guess, 3},
    {"R_g_content_type_guess_for_tree", (DL_FUNC) &R_g_content_type_guess_for_tree, 1},
    {"R_g_content_type_is_a", (DL_FUNC) &R_g_content_type_is_a, 2},
    {"R_g_content_type_is_mime_type", (DL_FUNC) &R_g_content_type_is_mime_type, 2},
    {"R_g_content_type_is_unknown", (DL_FUNC) &R_g_content_type_is_unknown, 1},
    {"R_g_content_types_get_registered", (DL_FUNC) &R_g_content_types_get_registered, 0},
    {"R_g_io_error_from_errno", (DL_FUNC) &R_g_io_error_from_errno, 1},
    {"R_g_io_error_quark", (DL_FUNC) &R_g_io_error_quark, 0},
    {"R_g_io_modules_load_all_in_directory", (DL_FUNC) &R_g_io_modules_load_all_in_directory, 1},
    {"R_g_io_modules_load_all_in_directory_with_scope", (DL_FUNC) &R_g_io_modules_load_all_in_directory_with_scope, 2},
    {"R_g_io_modules_scan_all_in_directory", (DL_FUNC) &R_g_io_modules_scan_all_in_directory, 1},
    {"R_g_io_modules_scan_all_in_directory_with_scope", (DL_FUNC) &R_g_io_modules_scan_all_in_directory_with_scope, 2},
    {"R_g_io_scheduler_cancel_all_jobs", (DL_FUNC) &R_g_io_scheduler_cancel_all_jobs, 0},
    {"R_g_io_scheduler_push_job", (DL_FUNC) &R_g_io_scheduler_push_job, 5},
    {"R_g_keyfile_settings_backend_new", (DL_FUNC) &R_g_keyfile_settings_backend_new, 3},
    {"R_g_memory_settings_backend_new", (DL_FUNC) &R_g_memory_settings_backend_new, 0},
    {"R_g_networking_init", (DL_FUNC) &R_g_networking_init, 0},
    {"R_g_null_settings_backend_new", (DL_FUNC) &R_g_null_settings_backend_new, 0},
    {"R_g_pollable_source_new", (DL_FUNC) &R_g_pollable_source_new, 1},
    {"R_g_pollable_source_new_full", (DL_FUNC) &R_g_pollable_source_new_full, 3},
    {"R_g_pollable_stream_read", (DL_FUNC) &R_g_pollable_stream_read, 5},
    {"R_g_pollable_stream_write", (DL_FUNC) &R_g_pollable_stream_write, 5},
    {"R_g_pollable_stream_write_all", (DL_FUNC) &R_g_pollable_stream_write_all, 5},
    {"R_g_resources_enumerate_children", (DL_FUNC) &R_g_resources_enumerate_children, 2},
    {"R_g_resources_get_info", (DL_FUNC) &R_g_resources_get_info, 2},
    {"R_g_resources_lookup_data", (DL_FUNC) &R_g_resources_lookup_data, 2},
    {"R_g_resources_open_stream", (DL_FUNC) &R_g_resources_open_stream, 2},
    {"R_g_simple_async_report_gerror_in_idle", (DL_FUNC) &R_g_simple_async_report_gerror_in_idle, 4},
    {"R_g_allocator_free", (DL_FUNC) &R_g_allocator_free, 1},
    {"R_g_async_queue_length", (DL_FUNC) &R_g_async_queue_length, 1},
    {"R_g_async_queue_length_unlocked", (DL_FUNC) &R_g_async_queue_length_unlocked, 1},
    {"R_g_async_queue_lock", (DL_FUNC) &R_g_async_queue_lock, 1},
    {"R_g_async_queue_pop", (DL_FUNC) &R_g_async_queue_pop, 1},
    {"R_g_async_queue_pop_unlocked", (DL_FUNC) &R_g_async_queue_pop_unlocked, 1},
    {"R_g_async_queue_push", (DL_FUNC) &R_g_async_queue_push, 2},
    {"R_g_async_queue_push_front", (DL_FUNC) &R_g_async_queue_push_front, 2},
    {"R_g_async_queue_push_front_unlocked", (DL_FUNC) &R_g_async_queue_push_front_unlocked, 2},
    {"R_g_async_queue_push_sorted", (DL_FUNC) &R_g_async_queue_push_sorted, 4},
    {"R_g_async_queue_push_sorted_unlocked", (DL_FUNC) &R_g_async_queue_push_sorted_unlocked, 4},
    {"R_g_async_queue_push_unlocked", (DL_FUNC) &R_g_async_queue_push_unlocked, 2},
    {"R_g_async_queue_ref", (DL_FUNC) &R_g_async_queue_ref, 1},
    {"R_g_async_queue_ref_unlocked", (DL_FUNC) &R_g_async_queue_ref_unlocked, 1},
    {"R_g_async_queue_remove", (DL_FUNC) &R_g_async_queue_remove, 2},
    {"R_g_async_queue_remove_unlocked", (DL_FUNC) &R_g_async_queue_remove_unlocked, 2},
    {"R_g_async_queue_sort", (DL_FUNC) &R_g_async_queue_sort, 3},
    {"R_g_async_queue_sort_unlocked", (DL_FUNC) &R_g_async_queue_sort_unlocked, 3},
    {"R_g_async_queue_timed_pop", (DL_FUNC) &R_g_async_queue_timed_pop, 2},
    {"R_g_async_queue_timed_pop_unlocked", (DL_FUNC) &R_g_async_queue_timed_pop_unlocked, 2},
    {"R_g_async_queue_timeout_pop", (DL_FUNC) &R_g_async_queue_timeout_pop, 2},
    {"R_g_async_queue_timeout_pop_unlocked", (DL_FUNC) &R_g_async_queue_timeout_pop_unlocked, 2},
    {"R_g_async_queue_try_pop", (DL_FUNC) &R_g_async_queue_try_pop, 1},
    {"R_g_async_queue_try_pop_unlocked", (DL_FUNC) &R_g_async_queue_try_pop_unlocked, 1},
    {"R_g_async_queue_unlock", (DL_FUNC) &R_g_async_queue_unlock, 1},
    {"R_g_async_queue_unref", (DL_FUNC) &R_g_async_queue_unref, 1},
    {"R_g_async_queue_unref_and_unlock", (DL_FUNC) &R_g_async_queue_unref_and_unlock, 1},
    {"R_g_async_queue_new", (DL_FUNC) &R_g_async_queue_new, 0},
    {"R_g_async_queue_new_full", (DL_FUNC) &R_g_async_queue_new_full, 1},
    {"R_g_bookmark_file_new", (DL_FUNC) &R_g_bookmark_file_new, 0},
    {"R_g_bookmark_file_add_application", (DL_FUNC) &R_g_bookmark_file_add_application, 4},
    {"R_g_bookmark_file_add_group", (DL_FUNC) &R_g_bookmark_file_add_group, 3},
    {"R_g_bookmark_file_free", (DL_FUNC) &R_g_bookmark_file_free, 1},
    {"R_g_bookmark_file_get_added", (DL_FUNC) &R_g_bookmark_file_get_added, 2},
    {"R_g_bookmark_file_get_app_info", (DL_FUNC) &R_g_bookmark_file_get_app_info, 3},
    {"R_g_bookmark_file_get_applications", (DL_FUNC) &R_g_bookmark_file_get_applications, 2},
    {"R_g_bookmark_file_get_description", (DL_FUNC) &R_g_bookmark_file_get_description, 2},
    {"R_g_bookmark_file_get_groups", (DL_FUNC) &R_g_bookmark_file_get_groups, 2},
    {"R_g_bookmark_file_get_icon", (DL_FUNC) &R_g_bookmark_file_get_icon, 2},
    {"R_g_bookmark_file_get_is_private", (DL_FUNC) &R_g_bookmark_file_get_is_private, 2},
    {"R_g_bookmark_file_get_mime_type", (DL_FUNC) &R_g_bookmark_file_get_mime_type, 2},
    {"R_g_bookmark_file_get_modified", (DL_FUNC) &R_g_bookmark_file_get_modified, 2},
    {"R_g_bookmark_file_get_size", (DL_FUNC) &R_g_bookmark_file_get_size, 1},
    {"R_g_bookmark_file_get_title", (DL_FUNC) &R_g_bookmark_file_get_title, 2},
    {"R_g_bookmark_file_get_uris", (DL_FUNC) &R_g_bookmark_file_get_uris, 1},
    {"R_g_bookmark_file_get_visited", (DL_FUNC) &R_g_bookmark_file_get_visited, 2},
    {"R_g_bookmark_file_has_application", (DL_FUNC) &R_g_bookmark_file_has_application, 3},
    {"R_g_bookmark_file_has_group", (DL_FUNC) &R_g_bookmark_file_has_group, 3},
    {"R_g_bookmark_file_has_item", (DL_FUNC) &R_g_bookmark_file_has_item, 2},
    {"R_g_bookmark_file_load_from_data", (DL_FUNC) &R_g_bookmark_file_load_from_data, 3},
    {"R_g_bookmark_file_load_from_data_dirs", (DL_FUNC) &R_g_bookmark_file_load_from_data_dirs, 2},
    {"R_g_bookmark_file_load_from_file", (DL_FUNC) &R_g_bookmark_file_load_from_file, 2},
    {"R_g_bookmark_file_move_item", (DL_FUNC) &R_g_bookmark_file_move_item, 3},
    {"R_g_bookmark_file_remove_application", (DL_FUNC) &R_g_bookmark_file_remove_application, 3},
    {"R_g_bookmark_file_remove_group", (DL_FUNC) &R_g_bookmark_file_remove_group, 3},
    {"R_g_bookmark_file_remove_item", (DL_FUNC) &R_g_bookmark_file_remove_item, 2},
    {"R_g_bookmark_file_set_added", (DL_FUNC) &R_g_bookmark_file_set_added, 3},
    {"R_g_bookmark_file_set_app_info", (DL_FUNC) &R_g_bookmark_file_set_app_info, 6},
    {"R_g_bookmark_file_set_description", (DL_FUNC) &R_g_bookmark_file_set_description, 3},
    {"R_g_bookmark_file_set_groups", (DL_FUNC) &R_g_bookmark_file_set_groups, 4},
    {"R_g_bookmark_file_set_icon", (DL_FUNC) &R_g_bookmark_file_set_icon, 4},
    {"R_g_bookmark_file_set_is_private", (DL_FUNC) &R_g_bookmark_file_set_is_private, 3},
    {"R_g_bookmark_file_set_mime_type", (DL_FUNC) &R_g_bookmark_file_set_mime_type, 3},
    {"R_g_bookmark_file_set_modified", (DL_FUNC) &R_g_bookmark_file_set_modified, 3},
    {"R_g_bookmark_file_set_title", (DL_FUNC) &R_g_bookmark_file_set_title, 3},
    {"R_g_bookmark_file_set_visited", (DL_FUNC) &R_g_bookmark_file_set_visited, 3},
    {"R_g_bookmark_file_to_data", (DL_FUNC) &R_g_bookmark_file_to_data, 1},
    {"R_g_bookmark_file_to_file", (DL_FUNC) &R_g_bookmark_file_to_file, 2},
    {"R_g_bookmark_file_error_quark", (DL_FUNC) &R_g_bookmark_file_error_quark, 0},
    {"R_g_byte_array_append", (DL_FUNC) &R_g_byte_array_append, 3},
    {"R_g_byte_array_free", (DL_FUNC) &R_g_byte_array_free, 2},
    {"R_g_byte_array_free_to_bytes", (DL_FUNC) &R_g_byte_array_free_to_bytes, 1},
    {"R_g_byte_array_new", (DL_FUNC) &R_g_byte_array_new, 0},
    {"R_g_byte_array_new_take", (DL_FUNC) &R_g_byte_array_new_take, 2},
    {"R_g_byte_array_prepend", (DL_FUNC) &R_g_byte_array_prepend, 3},
    {"R_g_byte_array_ref", (DL_FUNC) &R_g_byte_array_ref, 1},
    {"R_g_byte_array_remove_index", (DL_FUNC) &R_g_byte_array_remove_index, 2},
    {"R_g_byte_array_remove_index_fast", (DL_FUNC) &R_g_byte_array_remove_index_fast, 2},
    {"R_g_byte_array_remove_range", (DL_FUNC) &R_g_byte_array_remove_range, 3},
    {"R_g_byte_array_set_size", (DL_FUNC) &R_g_byte_array_set_size, 2},
    {"R_g_byte_array_sized_new", (DL_FUNC) &R_g_byte_array_sized_new, 1},
    {"R_g_byte_array_sort", (DL_FUNC) &R_g_byte_array_sort, 2},
    {"R_g_byte_array_sort_with_data", (DL_FUNC) &R_g_byte_array_sort_with_data, 3},
    {"R_g_byte_array_unref", (DL_FUNC) &R_g_byte_array_unref, 1},
    {"R_g_bytes_new", (DL_FUNC) &R_g_bytes_new, 2},
    {"R_g_bytes_new_from_bytes", (DL_FUNC) &R_g_bytes_new_from_bytes, 3},
    {"R_g_bytes_new_take", (DL_FUNC) &R_g_bytes_new_take, 2},
    {"R_g_bytes_compare", (DL_FUNC) &R_g_bytes_compare, 2},
    {"R_g_bytes_equal", (DL_FUNC) &R_g_bytes_equal, 2},
    {"R_g_bytes_get_data", (DL_FUNC) &R_g_bytes_get_data, 1},
    {"R_g_bytes_get_size", (DL_FUNC) &R_g_bytes_get_size, 1},
    {"R_g_bytes_hash", (DL_FUNC) &R_g_bytes_hash, 1},
    {"R_g_bytes_ref", (DL_FUNC) &R_g_bytes_ref, 1},
    {"R_g_bytes_unref", (DL_FUNC) &R_g_bytes_unref, 1},
    {"R_g_bytes_unref_to_array", (DL_FUNC) &R_g_bytes_unref_to_array, 1},
    {"R_g_bytes_unref_to_data", (DL_FUNC) &R_g_bytes_unref_to_data, 1},
    {"R_g_cache_destroy", (DL_FUNC) &R_g_cache_destroy, 1},
    {"R_g_cache_insert", (DL_FUNC) &R_g_cache_insert, 2},
    {"R_g_cache_key_foreach", (DL_FUNC) &R_g_cache_key_foreach, 3},
    {"R_g_cache_remove", (DL_FUNC) &R_g_cache_remove, 2},
    {"R_g_cache_value_foreach", (DL_FUNC) &R_g_cache_value_foreach, 3},
    {"R_g_checksum_new", (DL_FUNC) &R_g_checksum_new, 1},
    {"R_g_checksum_copy", (DL_FUNC) &R_g_checksum_copy, 1},
    {"R_g_checksum_free", (DL_FUNC) &R_g_checksum_free, 1},
    {"R_g_checksum_get_string", (DL_FUNC) &R_g_checksum_get_string, 1},
    {"R_g_checksum_reset", (DL_FUNC) &R_g_checksum_reset, 1},
    {"R_g_checksum_update", (DL_FUNC) &R_g_checksum_update, 3},
    {"R_g_checksum_type_get_length", (DL_FUNC) &R_g_checksum_type_get_length, 1},
    {"R_g_completion_clear_items", (DL_FUNC) &R_g_completion_clear_items, 1},
    {"R_g_completion_complete_utf8", (DL_FUNC) &R_g_completion_complete_utf8, 3},
    {"R_g_completion_free", (DL_FUNC) &R_g_completion_free, 1},
    {"R_g_cond_broadcast", (DL_FUNC) &R_g_cond_broadcast, 1},
    {"R_g_cond_clear", (DL_FUNC) &R_g_cond_clear, 1},
    {"R_g_cond_init", (DL_FUNC) &R_g_cond_init, 1},
    {"R_g_cond_signal", (DL_FUNC) &R_g_cond_signal, 1},
    {"R_g_cond_wait", (DL_FUNC) &R_g_cond_wait, 2},
    {"R_g_cond_wait_until", (DL_FUNC) &R_g_cond_wait_until, 3},
    {"R_g_date_new", (DL_FUNC) &R_g_date_new, 0},
    {"R_g_date_new_dmy", (DL_FUNC) &R_g_date_new_dmy, 3},
    {"R_g_date_new_julian", (DL_FUNC) &R_g_date_new_julian, 1},
    {"R_g_date_add_days", (DL_FUNC) &R_g_date_add_days, 2},
    {"R_g_date_add_months", (DL_FUNC) &R_g_date_add_months, 2},
    {"R_g_date_add_years", (DL_FUNC) &R_g_date_add_years, 2},
    {"R_g_date_clamp", (DL_FUNC) &R_g_date_clamp, 3},
    {"R_g_date_clear", (DL_FUNC) &R_g_date_clear, 2},
    {"R_g_date_compare", (DL_FUNC) &R_g_date_compare, 2},
    {"R_g_date_copy", (DL_FUNC) &R_g_date_copy, 1},
    {"R_g_date_days_between", (DL_FUNC) &R_g_date_days_between, 2},
    {"R_g_date_free", (DL_FUNC) &R_g_date_free, 1},
    {"R_g_date_get_day", (DL_FUNC) &R_g_date_get_day, 1},
    {"R_g_date_get_day_of_year", (DL_FUNC) &R_g_date_get_day_of_year, 1},
    {"R_g_date_get_iso8601_week_of_year", (DL_FUNC) &R_g_date_get_iso8601_week_of_year, 1},
    {"R_g_date_get_julian", (DL_FUNC) &R_g_date_get_julian, 1},
    {"R_g_date_get_monday_week_of_year", (DL_FUNC) &R_g_date_get_monday_week_of_year, 1},
    {"R_g_date_get_month", (DL_FUNC) &R_g_date_get_month, 1},
    {"R_g_date_get_sunday_week_of_year", (DL_FUNC) &R_g_date_get_sunday_week_of_year, 1},
    {"R_g_date_get_weekday", (DL_FUNC) &R_g_date_get_weekday, 1},
    {"R_g_date_get_year", (DL_FUNC) &R_g_date_get_year, 1},
    {"R_g_date_is_first_of_month", (DL_FUNC) &R_g_date_is_first_of_month, 1},
    {"R_g_date_is_last_of_month", (DL_FUNC) &R_g_date_is_last_of_month, 1},
    {"R_g_date_order", (DL_FUNC) &R_g_date_order, 2},
    {"R_g_date_set_day", (DL_FUNC) &R_g_date_set_day, 2},
    {"R_g_date_set_dmy", (DL_FUNC) &R_g_date_set_dmy, 4},
    {"R_g_date_set_julian", (DL_FUNC) &R_g_date_set_julian, 2},
    {"R_g_date_set_month", (DL_FUNC) &R_g_date_set_month, 2},
    {"R_g_date_set_parse", (DL_FUNC) &R_g_date_set_parse, 2},
    {"R_g_date_set_time", (DL_FUNC) &R_g_date_set_time, 2},
    {"R_g_date_set_time_t", (DL_FUNC) &R_g_date_set_time_t, 2},
    {"R_g_date_set_time_val", (DL_FUNC) &R_g_date_set_time_val, 2},
    {"R_g_date_set_year", (DL_FUNC) &R_g_date_set_year, 2},
    {"R_g_date_subtract_days", (DL_FUNC) &R_g_date_subtract_days, 2},
    {"R_g_date_subtract_months", (DL_FUNC) &R_g_date_subtract_months, 2},
    {"R_g_date_subtract_years", (DL_FUNC) &R_g_date_subtract_years, 2},
    {"R_g_date_to_struct_tm", (DL_FUNC) &R_g_date_to_struct_tm, 2},
    {"R_g_date_valid", (DL_FUNC) &R_g_date_valid, 1},
    {"R_g_date_get_days_in_month", (DL_FUNC) &R_g_date_get_days_in_month, 2},
    {"R_g_date_get_monday_weeks_in_year", (DL_FUNC) &R_g_date_get_monday_weeks_in_year, 1},
    {"R_g_date_get_sunday_weeks_in_year", (DL_FUNC) &R_g_date_get_sunday_weeks_in_year, 1},
    {"R_g_date_is_leap_year", (DL_FUNC) &R_g_date_is_leap_year, 1},
    {"R_g_date_strftime", (DL_FUNC) &R_g_date_strftime, 4},
    {"R_g_date_valid_day", (DL_FUNC) &R_g_date_valid_day, 1},
    {"R_g_date_valid_dmy", (DL_FUNC) &R_g_date_valid_dmy, 3},
    {"R_g_date_valid_julian", (DL_FUNC) &R_g_date_valid_julian, 1},
    {"R_g_date_valid_month", (DL_FUNC) &R_g_date_valid_month, 1},
    {"R_g_date_valid_weekday", (DL_FUNC) &R_g_date_valid_weekday, 1},
    {"R_g_date_valid_year", (DL_FUNC) &R_g_date_valid_year, 1},
    {"R_g_date_time_new", (DL_FUNC) &R_g_date_time_new, 7},
    {"R_g_date_time_new_from_iso8601", (DL_FUNC) &R_g_date_time_new_from_iso8601, 2},
    {"R_g_date_time_new_from_timeval_local", (DL_FUNC) &R_g_date_time_new_from_timeval_local, 1},
    {"R_g_date_time_new_from_timeval_utc", (DL_FUNC) &R_g_date_time_new_from_timeval_utc, 1},
    {"R_g_date_time_new_from_unix_local", (DL_FUNC) &R_g_date_time_new_from_unix_local, 1},
    {"R_g_date_time_new_from_unix_utc", (DL_FUNC) &R_g_date_time_new_from_unix_utc, 1},
    {"R_g_date_time_new_local", (DL_FUNC) &R_g_date_time_new_local, 6},
    {"R_g_date_time_new_now", (DL_FUNC) &R_g_date_time_new_now, 1},
    {"R_g_date_time_new_now_local", (DL_FUNC) &R_g_date_time_new_now_local, 0},
    {"R_g_date_time_new_now_utc", (DL_FUNC) &R_g_date_time_new_now_utc, 0},
    {"R_g_date_time_new_utc", (DL_FUNC) &R_g_date_time_new_utc, 6},
    {"R_g_date_time_add", (DL_FUNC) &R_g_date_time_add, 2},
    {"R_g_date_time_add_days", (DL_FUNC) &R_g_date_time_add_days, 2},
    {"R_g_date_time_add_full", (DL_FUNC) &R_g_date_time_add_full, 7},
    {"R_g_date_time_add_hours", (DL_FUNC) &R_g_date_time_add_hours, 2},
    {"R_g_date_time_add_minutes", (DL_FUNC) &R_g_date_time_add_minutes, 2},
    {"R_g_date_time_add_months", (DL_FUNC) &R_g_date_time_add_months, 2},
    {"R_g_date_time_add_seconds", (DL_FUNC) &R_g_date_time_add_seconds, 2},
    {"R_g_date_time_add_weeks", (DL_FUNC) &R_g_date_time_add_weeks, 2},
    {"R_g_date_time_add_years", (DL_FUNC) &R_g_date_time_add_years, 2},
    {"R_g_date_time_compare", (DL_FUNC) &R_g_date_time_compare, 2},
    {"R_g_date_time_difference", (DL_FUNC) &R_g_date_time_difference, 2},
    {"R_g_date_time_equal", (DL_FUNC) &R_g_date_time_equal, 2},
    {"R_g_date_time_format", (DL_FUNC) &R_g_date_time_format, 2},
    {"R_g_date_time_get_day_of_month", (DL_FUNC) &R_g_date_time_get_day_of_month, 1},
    {"R_g_date_time_get_day_of_week", (DL_FUNC) &R_g_date_time_get_day_of_week, 1},
    {"R_g_date_time_get_day_of_year", (DL_FUNC) &R_g_date_time_get_day_of_year, 1},
    {"R_g_date_time_get_hour", (DL_FUNC) &R_g_date_time_get_hour, 1},
    {"R_g_date_time_get_microsecond", (DL_FUNC) &R_g_date_time_get_microsecond, 1},
    {"R_g_date_time_get_minute", (DL_FUNC) &R_g_date_time_get_minute, 1},
    {"R_g_date_time_get_month", (DL_FUNC) &R_g_date_time_get_month, 1},
    {"R_g_date_time_get_second", (DL_FUNC) &R_g_date_time_get_second, 1},
    {"R_g_date_time_get_seconds", (DL_FUNC) &R_g_date_time_get_seconds, 1},
    {"R_g_date_time_get_timezone_abbreviation", (DL_FUNC) &R_g_date_time_get_timezone_abbreviation, 1},
    {"R_g_date_time_get_utc_offset", (DL_FUNC) &R_g_date_time_get_utc_offset, 1},
    {"R_g_date_time_get_week_numbering_year", (DL_FUNC) &R_g_date_time_get_week_numbering_year, 1},
    {"R_g_date_time_get_week_of_year", (DL_FUNC) &R_g_date_time_get_week_of_year, 1},
    {"R_g_date_time_get_year", (DL_FUNC) &R_g_date_time_get_year, 1},
    {"R_g_date_time_get_ymd", (DL_FUNC) &R_g_date_time_get_ymd, 1},
    {"R_g_date_time_hash", (DL_FUNC) &R_g_date_time_hash, 1},
    {"R_g_date_time_is_daylight_savings", (DL_FUNC) &R_g_date_time_is_daylight_savings, 1},
    {"R_g_date_time_ref", (DL_FUNC) &R_g_date_time_ref, 1},
    {"R_g_date_time_to_local", (DL_FUNC) &R_g_date_time_to_local, 1},
    {"R_g_date_time_to_timeval", (DL_FUNC) &R_g_date_time_to_timeval, 2},
    {"R_g_date_time_to_timezone", (DL_FUNC) &R_g_date_time_to_timezone, 2},
    {"R_g_date_time_to_unix", (DL_FUNC) &R_g_date_time_to_unix, 1},
    {"R_g_date_time_to_utc", (DL_FUNC) &R_g_date_time_to_utc, 1},
    {"R_g_date_time_unref", (DL_FUNC) &R_g_date_time_unref, 1},
    {"R_g_dir_open", (DL_FUNC) &R_g_dir_open, 2},
    {"R_g_dir_close", (DL_FUNC) &R_g_dir_close, 1},
    {"R_g_dir_read_name", (DL_FUNC) &R_g_dir_read_name, 1},
    {"R_g_dir_rewind", (DL_FUNC) &R_g_dir_rewind, 1},
    {"R_g_dir_make_tmp", (DL_FUNC) &R_g_dir_make_tmp, 1},
    {"R_g_error_new_literal", (DL_FUNC) &R_g_error_new_literal, 3},
    {"R_g_error_copy", (DL_FUNC) &R_g_error_copy, 1},
    {"R_g_error_free", (DL_FUNC) &R_g_error_free, 1},
    {"R_g_error_matches", (DL_FUNC) &R_g_error_matches, 3},
    {"R_g_hash_table_add", (DL_FUNC) &R_g_hash_table_add, 2},
    {"R_g_hash_table_contains", (DL_FUNC) &R_g_hash_table_contains, 2},
    {"R_g_hash_table_destroy", (DL_FUNC) &R_g_hash_table_destroy, 1},
    {"R_g_hash_table_find", (DL_FUNC) &R_g_hash_table_find, 3},
    {"R_g_hash_table_foreach", (DL_FUNC) &R_g_hash_table_foreach, 3},
    {"R_g_hash_table_foreach_remove", (DL_FUNC) &R_g_hash_table_foreach_remove, 3},
    {"R_g_hash_table_foreach_steal", (DL_FUNC) &R_g_hash_table_foreach_steal, 3},
    {"R_g_hash_table_insert", (DL_FUNC) &R_g_hash_table_insert, 3},
    {"R_g_hash_table_lookup", (DL_FUNC) &R_g_hash_table_lookup, 2},
    {"R_g_hash_table_lookup_extended", (DL_FUNC) &R_g_hash_table_lookup_extended, 2},
    {"R_g_hash_table_ref", (DL_FUNC) &R_g_hash_table_ref, 1},
    {"R_g_hash_table_remove", (DL_FUNC) &R_g_hash_table_remove, 2},
    {"R_g_hash_table_remove_all", (DL_FUNC) &R_g_hash_table_remove_all, 1},
    {"R_g_hash_table_replace", (DL_FUNC) &R_g_hash_table_replace, 3},
    {"R_g_hash_table_size", (DL_FUNC) &R_g_hash_table_size, 1},
    {"R_g_hash_table_steal", (DL_FUNC) &R_g_hash_table_steal, 2},
    {"R_g_hash_table_steal_all", (DL_FUNC) &R_g_hash_table_steal_all, 1},
    {"R_g_hash_table_unref", (DL_FUNC) &R_g_hash_table_unref, 1},
    {"R_g_hash_table_iter_get_hash_table", (DL_FUNC) &R_g_hash_table_iter_get_hash_table, 1},
    {"R_g_hash_table_iter_init", (DL_FUNC) &R_g_hash_table_iter_init, 2},
    {"R_g_hash_table_iter_next", (DL_FUNC) &R_g_hash_table_iter_next, 1},
    {"R_g_hash_table_iter_remove", (DL_FUNC) &R_g_hash_table_iter_remove, 1},
    {"R_g_hash_table_iter_replace", (DL_FUNC) &R_g_hash_table_iter_replace, 2},
    {"R_g_hash_table_iter_steal", (DL_FUNC) &R_g_hash_table_iter_steal, 1},
    {"R_g_hmac_new", (DL_FUNC) &R_g_hmac_new, 3},
    {"R_g_hmac_copy", (DL_FUNC) &R_g_hmac_copy, 1},
    {"R_g_hmac_get_digest", (DL_FUNC) &R_g_hmac_get_digest, 2},
    {"R_g_hmac_get_string", (DL_FUNC) &R_g_hmac_get_string, 1},
    {"R_g_hmac_ref", (DL_FUNC) &R_g_hmac_ref, 1},
    {"R_g_hmac_unref", (DL_FUNC) &R_g_hmac_unref, 1},
    {"R_g_hmac_update", (DL_FUNC) &R_g_hmac_update, 3},
    {"R_g_hook_compare_ids", (DL_FUNC) &R_g_hook_compare_ids, 2},
    {"R_g_hook_destroy", (DL_FUNC) &R_g_hook_destroy, 2},
    {"R_g_hook_destroy_link", (DL_FUNC) &R_g_hook_destroy_link, 2},
    {"R_g_hook_free", (DL_FUNC) &R_g_hook_free, 2},
    {"R_g_hook_insert_before", (DL_FUNC) &R_g_hook_insert_before, 3},
    {"R_g_hook_insert_sorted", (DL_FUNC) &R_g_hook_insert_sorted, 3},
    {"R_g_hook_prepend", (DL_FUNC) &R_g_hook_prepend, 2},
    {"R_g_hook_unref", (DL_FUNC) &R_g_hook_unref, 2},
    {"R_g_hook_list_clear", (DL_FUNC) &R_g_hook_list_clear, 1},
    {"R_g_hook_list_init", (DL_FUNC) &R_g_hook_list_init, 2},
    {"R_g_hook_list_invoke", (DL_FUNC) &R_g_hook_list_invoke, 2},
    {"R_g_hook_list_invoke_check", (DL_FUNC) &R_g_hook_list_invoke_check, 2},
    {"R_g_hook_list_marshal", (DL_FUNC) &R_g_hook_list_marshal, 4},
    {"R_g_hook_list_marshal_check", (DL_FUNC) &R_g_hook_list_marshal_check, 4},
    {"R_g_io_channel_new_file", (DL_FUNC) &R_g_io_channel_new_file, 2},
    {"R_g_io_channel_unix_new", (DL_FUNC) &R_g_io_channel_unix_new, 1},
    {"R_g_io_channel_close", (DL_FUNC) &R_g_io_channel_close, 1},
    {"R_g_io_channel_flush", (DL_FUNC) &R_g_io_channel_flush, 1},
    {"R_g_io_channel_get_buffer_condition", (DL_FUNC) &R_g_io_channel_get_buffer_condition, 1},
    {"R_g_io_channel_get_buffer_size", (DL_FUNC) &R_g_io_channel_get_buffer_size, 1},
    {"R_g_io_channel_get_buffered", (DL_FUNC) &R_g_io_channel_get_buffered, 1},
    {"R_g_io_channel_get_close_on_unref", (DL_FUNC) &R_g_io_channel_get_close_on_unref, 1},
    {"R_g_io_channel_get_encoding", (DL_FUNC) &R_g_io_channel_get_encoding, 1},
    {"R_g_io_channel_get_flags", (DL_FUNC) &R_g_io_channel_get_flags, 1},
    {"R_g_io_channel_get_line_term", (DL_FUNC) &R_g_io_channel_get_line_term, 1},
    {"R_g_io_channel_init", (DL_FUNC) &R_g_io_channel_init, 1},
    {"R_g_io_channel_read", (DL_FUNC) &R_g_io_channel_read, 4},
    {"R_g_io_channel_read_chars", (DL_FUNC) &R_g_io_channel_read_chars, 2},
    {"R_g_io_channel_read_line", (DL_FUNC) &R_g_io_channel_read_line, 1},
    {"R_g_io_channel_read_line_string", (DL_FUNC) &R_g_io_channel_read_line_string, 3},
    {"R_g_io_channel_read_to_end", (DL_FUNC) &R_g_io_channel_read_to_end, 1},
    {"R_g_io_channel_read_unichar", (DL_FUNC) &R_g_io_channel_read_unichar, 1},
    {"R_g_io_channel_ref", (DL_FUNC) &R_g_io_channel_ref, 1},
    {"R_g_io_channel_seek", (DL_FUNC) &R_g_io_channel_seek, 3},
    {"R_g_io_channel_seek_position", (DL_FUNC) &R_g_io_channel_seek_position, 3},
    {"R_g_io_channel_set_buffer_size", (DL_FUNC) &R_g_io_channel_set_buffer_size, 2},
    {"R_g_io_channel_set_buffered", (DL_FUNC) &R_g_io_channel_set_buffered, 2},
    {"R_g_io_channel_set_close_on_unref", (DL_FUNC) &R_g_io_channel_set_close_on_unref, 2},
    {"R_g_io_channel_set_encoding", (DL_FUNC) &R_g_io_channel_set_encoding, 2},
    {"R_g_io_channel_set_flags", (DL_FUNC) &R_g_io_channel_set_flags, 2},
    {"R_g_io_channel_set_line_term", (DL_FUNC) &R_g_io_channel_set_line_term, 3},
    {"R_g_io_channel_shutdown", (DL_FUNC) &R_g_io_channel_shutdown, 2},
    {"R_g_io_channel_unix_get_fd", (DL_FUNC) &R_g_io_channel_unix_get_fd, 1},
    {"R_g_io_channel_unref", (DL_FUNC) &R_g_io_channel_unref, 1},
    {"R_g_io_channel_write", (DL_FUNC) &R_g_io_channel_write, 4},
    {"R_g_io_channel_write_chars", (DL_FUNC) &R_g_io_channel_write_chars, 3},
    {"R_g_io_channel_write_unichar", (DL_FUNC) &R_g_io_channel_write_unichar, 2},
    {"R_g_io_channel_error_from_errno", (DL_FUNC) &R_g_io_channel_error_from_errno, 1},
    {"R_g_io_channel_error_quark", (DL_FUNC) &R_g_io_channel_error_quark, 0},
    {"R_g_key_file_new", (DL_FUNC) &R_g_key_file_new, 0},
    {"R_g_key_file_get_boolean", (DL_FUNC) &R_g_key_file_get_boolean, 3},
    {"R_g_key_file_get_boolean_list", (DL_FUNC) &R_g_key_file_get_boolean_list, 3},
    {"R_g_key_file_get_comment", (DL_FUNC) &R_g_key_file_get_comment, 3},
    {"R_g_key_file_get_double", (DL_FUNC) &R_g_key_file_get_double, 3},
    {"R_g_key_file_get_double_list", (DL_FUNC) &R_g_key_file_get_double_list, 3},
    {"R_g_key_file_get_groups", (DL_FUNC) &R_g_key_file_get_groups, 1},
    {"R_g_key_file_get_int64", (DL_FUNC) &R_g_key_file_get_int64, 3},
    {"R_g_key_file_get_integer", (DL_FUNC) &R_g_key_file_get_integer, 3},
    {"R_g_key_file_get_integer_list", (DL_FUNC) &R_g_key_file_get_integer_list, 3},
    {"R_g_key_file_get_keys", (DL_FUNC) &R_g_key_file_get_keys, 2},
    {"R_g_key_file_get_locale_for_key", (DL_FUNC) &R_g_key_file_get_locale_for_key, 4},
    {"R_g_key_file_get_locale_string", (DL_FUNC) &R_g_key_file_get_locale_string, 4},
    {"R_g_key_file_get_locale_string_list", (DL_FUNC) &R_g_key_file_get_locale_string_list, 4},
    {"R_g_key_file_get_start_group", (DL_FUNC) &R_g_key_file_get_start_group, 1},
    {"R_g_key_file_get_string", (DL_FUNC) &R_g_key_file_get_string, 3},
    {"R_g_key_file_get_string_list", (DL_FUNC) &R_g_key_file_get_string_list, 3},
    {"R_g_key_file_get_uint64", (DL_FUNC) &R_g_key_file_get_uint64, 3},
    {"R_g_key_file_get_value", (DL_FUNC) &R_g_key_file_get_value, 3},
    {"R_g_key_file_has_group", (DL_FUNC) &R_g_key_file_has_group, 2},
    {"R_g_key_file_load_from_bytes", (DL_FUNC) &R_g_key_file_load_from_bytes, 3},
    {"R_g_key_file_load_from_data", (DL_FUNC) &R_g_key_file_load_from_data, 4},
    {"R_g_key_file_load_from_data_dirs", (DL_FUNC) &R_g_key_file_load_from_data_dirs, 3},
    {"R_g_key_file_load_from_dirs", (DL_FUNC) &R_g_key_file_load_from_dirs, 4},
    {"R_g_key_file_load_from_file", (DL_FUNC) &R_g_key_file_load_from_file, 3},
    {"R_g_key_file_remove_comment", (DL_FUNC) &R_g_key_file_remove_comment, 3},
    {"R_g_key_file_remove_group", (DL_FUNC) &R_g_key_file_remove_group, 2},
    {"R_g_key_file_remove_key", (DL_FUNC) &R_g_key_file_remove_key, 3},
    {"R_g_key_file_save_to_file", (DL_FUNC) &R_g_key_file_save_to_file, 2},
    {"R_g_key_file_set_boolean", (DL_FUNC) &R_g_key_file_set_boolean, 4},
    {"R_g_key_file_set_boolean_list", (DL_FUNC) &R_g_key_file_set_boolean_list, 5},
    {"R_g_key_file_set_comment", (DL_FUNC) &R_g_key_file_set_comment, 4},
    {"R_g_key_file_set_double", (DL_FUNC) &R_g_key_file_set_double, 4},
    {"R_g_key_file_set_double_list", (DL_FUNC) &R_g_key_file_set_double_list, 5},
    {"R_g_key_file_set_int64", (DL_FUNC) &R_g_key_file_set_int64, 4},
    {"R_g_key_file_set_integer", (DL_FUNC) &R_g_key_file_set_integer, 4},
    {"R_g_key_file_set_integer_list", (DL_FUNC) &R_g_key_file_set_integer_list, 5},
    {"R_g_key_file_set_list_separator", (DL_FUNC) &R_g_key_file_set_list_separator, 2},
    {"R_g_key_file_set_locale_string", (DL_FUNC) &R_g_key_file_set_locale_string, 5},
    {"R_g_key_file_set_locale_string_list", (DL_FUNC) &R_g_key_file_set_locale_string_list, 6},
    {"R_g_key_file_set_string", (DL_FUNC) &R_g_key_file_set_string, 4},
    {"R_g_key_file_set_string_list", (DL_FUNC) &R_g_key_file_set_string_list, 5},
    {"R_g_key_file_set_uint64", (DL_FUNC) &R_g_key_file_set_uint64, 4},
    {"R_g_key_file_set_value", (DL_FUNC) &R_g_key_file_set_value, 4},
    {"R_g_key_file_to_data", (DL_FUNC) &R_g_key_file_to_data, 1},
    {"R_g_key_file_unref", (DL_FUNC) &R_g_key_file_unref, 1},
    {"R_g_key_file_error_quark", (DL_FUNC) &R_g_key_file_error_quark, 0},
    {"R_g_list_pop_allocator", (DL_FUNC) &R_g_list_pop_allocator, 0},
    {"R_g_list_push_allocator", (DL_FUNC) &R_g_list_push_allocator, 1},
    {"R_g_main_context_new", (DL_FUNC) &R_g_main_context_new, 0},
    {"R_g_main_context_acquire", (DL_FUNC) &R_g_main_context_acquire, 1},
    {"R_g_main_context_add_poll", (DL_FUNC) &R_g_main_context_add_poll, 3},
    {"R_g_main_context_check", (DL_FUNC) &R_g_main_context_check, 4},
    {"R_g_main_context_dispatch", (DL_FUNC) &R_g_main_context_dispatch, 1},
    {"R_g_main_context_find_source_by_funcs_user_data", (DL_FUNC) &R_g_main_context_find_source_by_funcs_user_data, 3},
    {"R_g_main_context_find_source_by_id", (DL_FUNC) &R_g_main_context_find_source_by_id, 2},
    {"R_g_main_context_find_source_by_user_data", (DL_FUNC) &R_g_main_context_find_source_by_user_data, 2},
    {"R_g_main_context_invoke_full", (DL_FUNC) &R_g_main_context_invoke_full, 5},
    {"R_g_main_context_is_owner", (DL_FUNC) &R_g_main_context_is_owner, 1},
    {"R_g_main_context_iteration", (DL_FUNC) &R_g_main_context_iteration, 2},
    {"R_g_main_context_pending", (DL_FUNC) &R_g_main_context_pending, 1},
    {"R_g_main_context_pop_thread_default", (DL_FUNC) &R_g_main_context_pop_thread_default, 1},
    {"R_g_main_context_prepare", (DL_FUNC) &R_g_main_context_prepare, 1},
    {"R_g_main_context_push_thread_default", (DL_FUNC) &R_g_main_context_push_thread_default, 1},
    {"R_g_main_context_query", (DL_FUNC) &R_g_main_context_query, 3},
    {"R_g_main_context_ref", (DL_FUNC) &R_g_main_context_ref, 1},
    {"R_g_main_context_release", (DL_FUNC) &R_g_main_context_release, 1},
    {"R_g_main_context_remove_poll", (DL_FUNC) &R_g_main_context_remove_poll, 2},
    {"R_g_main_context_unref", (DL_FUNC) &R_g_main_context_unref, 1},
    {"R_g_main_context_wait", (DL_FUNC) &R_g_main_context_wait, 3},
    {"R_g_main_context_wakeup", (DL_FUNC) &R_g_main_context_wakeup, 1},
    {"R_g_main_context_default", (DL_FUNC) &R_g_main_context_default, 0},
    {"R_g_main_context_get_thread_default", (DL_FUNC) &R_g_main_context_get_thread_default, 0},
    {"R_g_main_context_ref_thread_default", (DL_FUNC) &R_g_main_context_ref_thread_default, 0},
    {"R_g_main_loop_new", (DL_FUNC) &R_g_main_loop_new, 2},
    {"R_g_main_loop_get_context", (DL_FUNC) &R_g_main_loop_get_context, 1},
    {"R_g_main_loop_is_running", (DL_FUNC) &R_g_main_loop_is_running, 1},
    {"R_g_main_loop_quit", (DL_FUNC) &R_g_main_loop_quit, 1},
    {"R_g_main_loop_ref", (DL_FUNC) &R_g_main_loop_ref, 1},
    {"R_g_main_loop_run", (DL_FUNC) &R_g_main_loop_run, 1},
    {"R_g_main_loop_unref", (DL_FUNC) &R_g_main_loop_unref, 1},
    {"R_g_mapped_file_new", (DL_FUNC) &R_g_mapped_file_new, 2},
    {"R_g_mapped_file_new_from_fd", (DL_FUNC) &R_g_mapped_file_new_from_fd, 2},
    {"R_g_mapped_file_free", (DL_FUNC) &R_g_mapped_file_free, 1},
    {"R_g_mapped_file_get_bytes", (DL_FUNC) &R_g_mapped_file_get_bytes, 1},
    {"R_g_mapped_file_get_contents", (DL_FUNC) &R_g_mapped_file_get_contents, 1},
    {"R_g_mapped_file_get_length", (DL_FUNC) &R_g_mapped_file_get_length, 1},
    {"R_g_mapped_file_ref", (DL_FUNC) &R_g_mapped_file_ref, 1},
    {"R_g_mapped_file_unref", (DL_FUNC) &R_g_mapped_file_unref, 1},
    {"R_g_markup_parse_context_new", (DL_FUNC) &R_g_markup_parse_context_new, 4},
    {"R_g_markup_parse_context_end_parse", (DL_FUNC) &R_g_markup_parse_context_end_parse, 1},
    {"R_g_markup_parse_context_free", (DL_FUNC) &R_g_markup_parse_context_free, 1},
    {"R_g_markup_parse_context_get_element", (DL_FUNC) &R_g_markup_parse_context_get_element, 1},
    {"R_g_markup_parse_context_get_element_stack", (DL_FUNC) &R_g_markup_parse_context_get_element_stack, 1},
    {"R_g_markup_parse_context_get_position", (DL_FUNC) &R_g_markup_parse_context_get_position, 1},
    {"R_g_markup_parse_context_get_user_data", (DL_FUNC) &R_g_markup_parse_context_get_user_data, 1},
    {"R_g_markup_parse_context_parse", (DL_FUNC) &R_g_markup_parse_context_parse, 3},
    {"R_g_markup_parse_context_pop", (DL_FUNC) &R_g_markup_parse_context_pop, 1},
    {"R_g_markup_parse_context_push", (DL_FUNC) &R_g_markup_parse_context_push, 3},
    {"R_g_markup_parse_context_ref", (DL_FUNC) &R_g_markup_parse_context_ref, 1},
    {"R_g_markup_parse_context_unref", (DL_FUNC) &R_g_markup_parse_context_unref, 1},
    {"R_g_match_info_expand_references", (DL_FUNC) &R_g_match_info_expand_references, 2},
    {"R_g_match_info_fetch", (DL_FUNC) &R_g_match_info_fetch, 2},
    {"R_g_match_info_fetch_all", (DL_FUNC) &R_g_match_info_fetch_all, 1},
    {"R_g_match_info_fetch_named", (DL_FUNC) &R_g_match_info_fetch_named, 2},
    {"R_g_match_info_fetch_named_pos", (DL_FUNC) &R_g_match_info_fetch_named_pos, 2},
    {"R_g_match_info_fetch_pos", (DL_FUNC) &R_g_match_info_fetch_pos, 2},
    {"R_g_match_info_free", (DL_FUNC) &R_g_match_info_free, 1},
    {"R_g_match_info_get_match_count", (DL_FUNC) &R_g_match_info_get_match_count, 1},
    {"R_g_match_info_get_regex", (DL_FUNC) &R_g_match_info_get_regex, 1},
    {"R_g_match_info_get_string", (DL_FUNC) &R_g_match_info_get_string, 1},
    {"R_g_match_info_is_partial_match", (DL_FUNC) &R_g_match_info_is_partial_match, 1},
    {"R_g_match_info_matches", (DL_FUNC) &R_g_match_info_matches, 1},
    {"R_g_match_info_next", (DL_FUNC) &R_g_match_info_next, 1},
    {"R_g_match_info_ref", (DL_FUNC) &R_g_match_info_ref, 1},
    {"R_g_match_info_unref", (DL_FUNC) &R_g_match_info_unref, 1},
    {"R_g_mem_chunk_alloc", (DL_FUNC) &R_g_mem_chunk_alloc, 1},
    {"R_g_mem_chunk_alloc0", (DL_FUNC) &R_g_mem_chunk_alloc0, 1},
    {"R_g_mem_chunk_clean", (DL_FUNC) &R_g_mem_chunk_clean, 1},
    {"R_g_mem_chunk_destroy", (DL_FUNC) &R_g_mem_chunk_destroy, 1},
    {"R_g_mem_chunk_free", (DL_FUNC) &R_g_mem_chunk_free, 2},
    {"R_g_mem_chunk_print", (DL_FUNC) &R_g_mem_chunk_print, 1},
    {"R_g_mem_chunk_reset", (DL_FUNC) &R_g_mem_chunk_reset, 1},
    {"R_g_mem_chunk_info", (DL_FUNC) &R_g_mem_chunk_info, 0},
    {"R_g_mutex_clear", (DL_FUNC) &R_g_mutex_clear, 1},
    {"R_g_mutex_init", (DL_FUNC) &R_g_mutex_init, 1},
    {"R_g_mutex_lock", (DL_FUNC) &R_g_mutex_lock, 1},
    {"R_g_mutex_trylock", (DL_FUNC) &R_g_mutex_trylock, 1},
    {"R_g_mutex_unlock", (DL_FUNC) &R_g_mutex_unlock, 1},
    {"R_g_node_child_index", (DL_FUNC) &R_g_node_child_index, 2},
    {"R_g_node_child_position", (DL_FUNC) &R_g_node_child_position, 2},
    {"R_g_node_children_foreach", (DL_FUNC) &R_g_node_children_foreach, 4},
    {"R_g_node_depth", (DL_FUNC) &R_g_node_depth, 1},
    {"R_g_node_destroy", (DL_FUNC) &R_g_node_destroy, 1},
    {"R_g_node_is_ancestor", (DL_FUNC) &R_g_node_is_ancestor, 2},
    {"R_g_node_max_height", (DL_FUNC) &R_g_node_max_height, 1},
    {"R_g_node_n_children", (DL_FUNC) &R_g_node_n_children, 1},
    {"R_g_node_n_nodes", (DL_FUNC) &R_g_node_n_nodes, 2},
    {"R_g_node_reverse_children", (DL_FUNC) &R_g_node_reverse_children, 1},
    {"R_g_node_traverse", (DL_FUNC) &R_g_node_traverse, 6},
    {"R_g_node_unlink", (DL_FUNC) &R_g_node_unlink, 1},
    {"R_g_node_pop_allocator", (DL_FUNC) &R_g_node_pop_allocator, 0},
    {"R_g_node_push_allocator", (DL_FUNC) &R_g_node_push_allocator, 1},
    {"R_g_option_context_add_group", (DL_FUNC) &R_g_option_context_add_group, 2},
    {"R_g_option_context_add_main_entries", (DL_FUNC) &R_g_option_context_add_main_entries, 3},
    {"R_g_option_context_free", (DL_FUNC) &R_g_option_context_free, 1},
    {"R_g_option_context_get_description", (DL_FUNC) &R_g_option_context_get_description, 1},
    {"R_g_option_context_get_help", (DL_FUNC) &R_g_option_context_get_help, 3},
    {"R_g_option_context_get_help_enabled", (DL_FUNC) &R_g_option_context_get_help_enabled, 1},
    {"R_g_option_context_get_ignore_unknown_options", (DL_FUNC) &R_g_option_context_get_ignore_unknown_options, 1},
    {"R_g_option_context_get_main_group", (DL_FUNC) &R_g_option_context_get_main_group, 1},
    {"R_g_option_context_get_strict_posix", (DL_FUNC) &R_g_option_context_get_strict_posix, 1},
    {"R_g_option_context_get_summary", (DL_FUNC) &R_g_option_context_get_summary, 1},
    {"R_g_option_context_parse", (DL_FUNC) &R_g_option_context_parse, 1},
    {"R_g_option_context_parse_strv", (DL_FUNC) &R_g_option_context_parse_strv, 1},
    {"R_g_option_context_set_description", (DL_FUNC) &R_g_option_context_set_description, 2},
    {"R_g_option_context_set_help_enabled", (DL_FUNC) &R_g_option_context_set_help_enabled, 2},
    {"R_g_option_context_set_ignore_unknown_options", (DL_FUNC) &R_g_option_context_set_ignore_unknown_options, 2},
    {"R_g_option_context_set_main_group", (DL_FUNC) &R_g_option_context_set_main_group, 2},
    {"R_g_option_context_set_strict_posix", (DL_FUNC) &R_g_option_context_set_strict_posix, 2},
    {"R_g_option_context_set_summary", (DL_FUNC) &R_g_option_context_set_summary, 2},
    {"R_g_option_context_set_translate_func", (DL_FUNC) &R_g_option_context_set_translate_func, 4},
    {"R_g_option_context_set_translation_domain", (DL_FUNC) &R_g_option_context_set_translation_domain, 2},
    {"R_g_option_group_new", (DL_FUNC) &R_g_option_group_new, 5},
    {"R_g_option_group_add_entries", (DL_FUNC) &R_g_option_group_add_entries, 2},
    {"R_g_option_group_free", (DL_FUNC) &R_g_option_group_free, 1},
    {"R_g_option_group_ref", (DL_FUNC) &R_g_option_group_ref, 1},
    {"R_g_option_group_set_translate_func", (DL_FUNC) &R_g_option_group_set_translate_func, 4},
    {"R_g_option_group_set_translation_domain", (DL_FUNC) &R_g_option_group_set_translation_domain, 2},
    {"R_g_option_group_unref", (DL_FUNC) &R_g_option_group_unref, 1},
    {"R_g_pattern_spec_new", (DL_FUNC) &R_g_pattern_spec_new, 1},
    {"R_g_pattern_spec_equal", (DL_FUNC) &R_g_pattern_spec_equal, 2},
    {"R_g_pattern_spec_free", (DL_FUNC) &R_g_pattern_spec_free, 1},
    {"R_g_private_get", (DL_FUNC) &R_g_private_get, 1},
    {"R_g_private_replace", (DL_FUNC) &R_g_private_replace, 2},
    {"R_g_private_set", (DL_FUNC) &R_g_private_set, 2},
    {"R_g_queue_clear", (DL_FUNC) &R_g_queue_clear, 1},
    {"R_g_queue_foreach", (DL_FUNC) &R_g_queue_foreach, 3},
    {"R_g_queue_free", (DL_FUNC) &R_g_queue_free, 1},
    {"R_g_queue_free_full", (DL_FUNC) &R_g_queue_free_full, 2},
    {"R_g_queue_get_length", (DL_FUNC) &R_g_queue_get_length, 1},
    {"R_g_queue_index", (DL_FUNC) &R_g_queue_index, 2},
    {"R_g_queue_init", (DL_FUNC) &R_g_queue_init, 1},
    {"R_g_queue_insert_sorted", (DL_FUNC) &R_g_queue_insert_sorted, 4},
    {"R_g_queue_is_empty", (DL_FUNC) &R_g_queue_is_empty, 1},
    {"R_g_queue_peek_head", (DL_FUNC) &R_g_queue_peek_head, 1},
    {"R_g_queue_peek_nth", (DL_FUNC) &R_g_queue_peek_nth, 2},
    {"R_g_queue_peek_tail", (DL_FUNC) &R_g_queue_peek_tail, 1},
    {"R_g_queue_pop_head", (DL_FUNC) &R_g_queue_pop_head, 1},
    {"R_g_queue_pop_nth", (DL_FUNC) &R_g_queue_pop_nth, 2},
    {"R_g_queue_pop_tail", (DL_FUNC) &R_g_queue_pop_tail, 1},
    {"R_g_queue_push_head", (DL_FUNC) &R_g_queue_push_head, 2},
    {"R_g_queue_push_nth", (DL_FUNC) &R_g_queue_push_nth, 3},
    {"R_g_queue_push_tail", (DL_FUNC) &R_g_queue_push_tail, 2},
    {"R_g_queue_remove", (DL_FUNC) &R_g_queue_remove, 2},
    {"R_g_queue_remove_all", (DL_FUNC) &R_g_queue_remove_all, 2},
    {"R_g_queue_reverse", (DL_FUNC) &R_g_queue_reverse, 1},
    {"R_g_queue_sort", (DL_FUNC) &R_g_queue_sort, 3},
    {"R_g_rw_lock_clear", (DL_FUNC) &R_g_rw_lock_clear, 1},
    {"R_g_rw_lock_init", (DL_FUNC) &R_g_rw_lock_init, 1},
    {"R_g_rw_lock_reader_lock", (DL_FUNC) &R_g_rw_lock_reader_lock, 1},
    {"R_g_rw_lock_reader_trylock", (DL_FUNC) &R_g_rw_lock_reader_trylock, 1},
    {"R_g_rw_lock_reader_unlock", (DL_FUNC) &R_g_rw_lock_reader_unlock, 1},
    {"R_g_rw_lock_writer_lock", (DL_FUNC) &R_g_rw_lock_writer_lock, 1},
    {"R_g_rw_lock_writer_trylock", (DL_FUNC) &R_g_rw_lock_writer_trylock, 1},
    {"R_g_rw_lock_writer_unlock", (DL_FUNC) &R_g_rw_lock_writer_unlock, 1},
    {"R_g_rand_new", (DL_FUNC) &R_g_rand_new, 0},
    {"R_g_rand_new_with_seed", (DL_FUNC) &R_g_rand_new_with_seed, 1},
    {"R_g_rand_new_with_seed_array", (DL_FUNC) &R_g_rand_new_with_seed_array, 2},
    {"R_g_rand_copy", (DL_FUNC) &R_g_rand_copy, 1},
    {"R_g_rand_double", (DL_FUNC) &R_g_rand_double, 1},
    {"R_g_rand_double_range", (DL_FUNC) &R_g_rand_double_range, 3},
    {"R_g_rand_free", (DL_FUNC) &R_g_rand_free, 1},
    {"R_g_rand_int", (DL_FUNC) &R_g_rand_int, 1},
    {"R_g_rand_int_range", (DL_FUNC) &R_g_rand_int_range, 3},
    {"R_g_rand_set_seed", (DL_FUNC) &R_g_rand_set_seed, 2},
    {"R_g_rand_set_seed_array", (DL_FUNC) &R_g_rand_set_seed_array, 3},
    {"R_g_rec_mutex_clear", (DL_FUNC) &R_g_rec_mutex_clear, 1},
    {"R_g_rec_mutex_init", (DL_FUNC) &R_g_rec_mutex_init, 1},
    {"R_g_rec_mutex_lock", (DL_FUNC) &R_g_rec_mutex_lock, 1},
    {"R_g_rec_mutex_trylock", (DL_FUNC) &R_g_rec_mutex_trylock, 1},
    {"R_g_rec_mutex_unlock", (DL_FUNC) &R_g_rec_mutex_unlock, 1},
    {"R_g_regex_new", (DL_FUNC) &R_g_regex_new, 3},
    {"R_g_regex_get_capture_count", (DL_FUNC) &R_g_regex_get_capture_count, 1},
    {"R_g_regex_get_compile_flags", (DL_FUNC) &R_g_regex_get_compile_flags, 1},
    {"R_g_regex_get_has_cr_or_lf", (DL_FUNC) &R_g_regex_get_has_cr_or_lf, 1},
    {"R_g_regex_get_match_flags", (DL_FUNC) &R_g_regex_get_match_flags, 1},
    {"R_g_regex_get_max_backref", (DL_FUNC) &R_g_regex_get_max_backref, 1},
    {"R_g_regex_get_max_lookbehind", (DL_FUNC) &R_g_regex_get_max_lookbehind, 1},
    {"R_g_regex_get_pattern", (DL_FUNC) &R_g_regex_get_pattern, 1},
    {"R_g_regex_get_string_number", (DL_FUNC) &R_g_regex_get_string_number, 2},
    {"R_g_regex_match", (DL_FUNC) &R_g_regex_match, 3},
    {"R_g_regex_match_all", (DL_FUNC) &R_g_regex_match_all, 3},
    {"R_g_regex_match_all_full", (DL_FUNC) &R_g_regex_match_all_full, 5},
    {"R_g_regex_match_full", (DL_FUNC) &R_g_regex_match_full, 5},
    {"R_g_regex_ref", (DL_FUNC) &R_g_regex_ref, 1},
    {"R_g_regex_replace", (DL_FUNC) &R_g_regex_replace, 6},
    {"R_g_regex_replace_eval", (DL_FUNC) &R_g_regex_replace_eval, 7},
    {"R_g_regex_replace_literal", (DL_FUNC) &R_g_regex_replace_literal, 6},
    {"R_g_regex_split", (DL_FUNC) &R_g_regex_split, 3},
    {"R_g_regex_split_full", (DL_FUNC) &R_g_regex_split_full, 6},
    {"R_g_regex_unref", (DL_FUNC) &R_g_regex_unref, 1},
    {"R_g_regex_check_replacement", (DL_FUNC) &R_g_regex_check_replacement, 1},
    {"R_g_regex_error_quark", (DL_FUNC) &R_g_regex_error_quark, 0},
    {"R_g_regex_escape_nul", (DL_FUNC) &R_g_regex_escape_nul, 2},
    {"R_g_regex_escape_string", (DL_FUNC) &R_g_regex_escape_string, 2},
    {"R_g_regex_match_simple", (DL_FUNC) &R_g_regex_match_simple, 4},
    {"R_g_regex_split_simple", (DL_FUNC) &R_g_regex_split_simple, 4},
    {"R_g_relation_count", (DL_FUNC) &R_g_relation_count, 3},
    {"R_g_relation_delete", (DL_FUNC) &R_g_relation_delete, 3},
    {"R_g_relation_destroy", (DL_FUNC) &R_g_relation_destroy, 1},
    {"R_g_relation_print", (DL_FUNC) &R_g_relation_print, 1},
    {"R_g_slist_pop_allocator", (DL_FUNC) &R_g_slist_pop_allocator, 0},
    {"R_g_slist_push_allocator", (DL_FUNC) &R_g_slist_push_allocator, 1},
    {"R_g_scanner_cur_line", (DL_FUNC) &R_g_scanner_cur_line, 1},
    {"R_g_scanner_cur_position", (DL_FUNC) &R_g_scanner_cur_position, 1},
    {"R_g_scanner_cur_token", (DL_FUNC) &R_g_scanner_cur_token, 1},
    {"R_g_scanner_destroy", (DL_FUNC) &R_g_scanner_destroy, 1},
    {"R_g_scanner_eof", (DL_FUNC) &R_g_scanner_eof, 1},
    {"R_g_scanner_get_next_token", (DL_FUNC) &R_g_scanner_get_next_token, 1},
    {"R_g_scanner_input_file", (DL_FUNC) &R_g_scanner_input_file, 2},
    {"R_g_scanner_input_text", (DL_FUNC) &R_g_scanner_input_text, 3},
    {"R_g_scanner_lookup_symbol", (DL_FUNC) &R_g_scanner_lookup_symbol, 2},
    {"R_g_scanner_peek_next_token", (DL_FUNC) &R_g_scanner_peek_next_token, 1},
    {"R_g_scanner_scope_add_symbol", (DL_FUNC) &R_g_scanner_scope_add_symbol, 4},
    {"R_g_scanner_scope_foreach_symbol", (DL_FUNC) &R_g_scanner_scope_foreach_symbol, 4},
    {"R_g_scanner_scope_lookup_symbol", (DL_FUNC) &R_g_scanner_scope_lookup_symbol, 3},
    {"R_g_scanner_scope_remove_symbol", (DL_FUNC) &R_g_scanner_scope_remove_symbol, 3},
    {"R_g_scanner_set_scope", (DL_FUNC) &R_g_scanner_set_scope, 2},
    {"R_g_scanner_sync_file_offset", (DL_FUNC) &R_g_scanner_sync_file_offset, 1},
    {"R_g_scanner_unexp_token", (DL_FUNC) &R_g_scanner_unexp_token, 7},
    {"R_g_sequence_append", (DL_FUNC) &R_g_sequence_append, 2},
    {"R_g_sequence_foreach", (DL_FUNC) &R_g_sequence_foreach, 3},
    {"R_g_sequence_free", (DL_FUNC) &R_g_sequence_free, 1},
    {"R_g_sequence_get_begin_iter", (DL_FUNC) &R_g_sequence_get_begin_iter, 1},
    {"R_g_sequence_get_end_iter", (DL_FUNC) &R_g_sequence_get_end_iter, 1},
    {"R_g_sequence_get_iter_at_pos", (DL_FUNC) &R_g_sequence_get_iter_at_pos, 2},
    {"R_g_sequence_get_length", (DL_FUNC) &R_g_sequence_get_length, 1},
    {"R_g_sequence_insert_sorted", (DL_FUNC) &R_g_sequence_insert_sorted, 4},
    {"R_g_sequence_insert_sorted_iter", (DL_FUNC) &R_g_sequence_insert_sorted_iter, 4},
    {"R_g_sequence_is_empty", (DL_FUNC) &R_g_sequence_is_empty, 1},
    {"R_g_sequence_lookup", (DL_FUNC) &R_g_sequence_lookup, 4},
    {"R_g_sequence_lookup_iter", (DL_FUNC) &R_g_sequence_lookup_iter, 4},
    {"R_g_sequence_prepend", (DL_FUNC) &R_g_sequence_prepend, 2},
    {"R_g_sequence_search", (DL_FUNC) &R_g_sequence_search, 4},
    {"R_g_sequence_search_iter", (DL_FUNC) &R_g_sequence_search_iter, 4},
    {"R_g_sequence_sort", (DL_FUNC) &R_g_sequence_sort, 3},
    {"R_g_sequence_sort_iter", (DL_FUNC) &R_g_sequence_sort_iter, 3},
    {"R_g_sequence_foreach_range", (DL_FUNC) &R_g_sequence_foreach_range, 4},
    {"R_g_sequence_get", (DL_FUNC) &R_g_sequence_get, 1},
    {"R_g_sequence_insert_before", (DL_FUNC) &R_g_sequence_insert_before, 2},
    {"R_g_sequence_move", (DL_FUNC) &R_g_sequence_move, 2},
    {"R_g_sequence_move_range", (DL_FUNC) &R_g_sequence_move_range, 3},
    {"R_g_sequence_range_get_midpoint", (DL_FUNC) &R_g_sequence_range_get_midpoint, 2},
    {"R_g_sequence_remove", (DL_FUNC) &R_g_sequence_remove, 1},
    {"R_g_sequence_remove_range", (DL_FUNC) &R_g_sequence_remove_range, 2},
    {"R_g_sequence_set", (DL_FUNC) &R_g_sequence_set, 2},
    {"R_g_sequence_sort_changed", (DL_FUNC) &R_g_sequence_sort_changed, 3},
    {"R_g_sequence_sort_changed_iter", (DL_FUNC) &R_g_sequence_sort_changed_iter, 3},
    {"R_g_sequence_swap", (DL_FUNC) &R_g_sequence_swap, 2},
    {"R_g_sequence_iter_compare", (DL_FUNC) &R_g_sequence_iter_compare, 2},
    {"R_g_sequence_iter_get_position", (DL_FUNC) &R_g_sequence_iter_get_position, 1},
    {"R_g_sequence_iter_get_sequence", (DL_FUNC) &R_g_sequence_iter_get_sequence, 1},
    {"R_g_sequence_iter_is_begin", (DL_FUNC) &R_g_sequence_iter_is_begin, 1},
    {"R_g_sequence_iter_is_end", (DL_FUNC) &R_g_sequence_iter_is_end, 1},
    {"R_g_sequence_iter_move", (DL_FUNC) &R_g_sequence_iter_move, 2},
    {"R_g_sequence_iter_next", (DL_FUNC) &R_g_sequence_iter_next, 1},
    {"R_g_sequence_iter_prev", (DL_FUNC) &R_g_sequence_iter_prev, 1},
    {"R_g_source_new", (DL_FUNC) &R_g_source_new, 2},
    {"R_g_source_add_child_source", (DL_FUNC) &R_g_source_add_child_source, 2},
    {"R_g_source_add_poll", (DL_FUNC) &R_g_source_add_poll, 2},
    {"R_g_source_attach", (DL_FUNC) &R_g_source_attach, 2},
    {"R_g_source_destroy", (DL_FUNC) &R_g_source_destroy, 1},
    {"R_g_source_get_can_recurse", (DL_FUNC) &R_g_source_get_can_recurse, 1},
    {"R_g_source_get_context", (DL_FUNC) &R_g_source_get_context, 1},
    {"R_g_source_get_current_time", (DL_FUNC) &R_g_source_get_current_time, 2},
    {"R_g_source_get_id", (DL_FUNC) &R_g_source_get_id, 1},
    {"R_g_source_get_name", (DL_FUNC) &R_g_source_get_name, 1},
    {"R_g_source_get_priority", (DL_FUNC) &R_g_source_get_priority, 1},
    {"R_g_source_get_ready_time", (DL_FUNC) &R_g_source_get_ready_time, 1},
    {"R_g_source_get_time", (DL_FUNC) &R_g_source_get_time, 1},
    {"R_g_source_is_destroyed", (DL_FUNC) &R_g_source_is_destroyed, 1},
    {"R_g_source_ref", (DL_FUNC) &R_g_source_ref, 1},
    {"R_g_source_remove_child_source", (DL_FUNC) &R_g_source_remove_child_source, 2},
    {"R_g_source_remove_poll", (DL_FUNC) &R_g_source_remove_poll, 2},
    {"R_g_source_set_callback", (DL_FUNC) &R_g_source_set_callback, 4},
    {"R_g_source_set_callback_indirect", (DL_FUNC) &R_g_source_set_callback_indirect, 3},
    {"R_g_source_set_can_recurse", (DL_FUNC) &R_g_source_set_can_recurse, 2},
    {"R_g_source_set_funcs", (DL_FUNC) &R_g_source_set_funcs, 2},
    {"R_g_source_set_name", (DL_FUNC) &R_g_source_set_name, 2},
    {"R_g_source_set_priority", (DL_FUNC) &R_g_source_set_priority, 2},
    {"R_g_source_set_ready_time", (DL_FUNC) &R_g_source_set_ready_time, 2},
    {"R_g_source_unref", (DL_FUNC) &R_g_source_unref, 1},
    {"R_g_source_remove", (DL_FUNC) &R_g_source_remove, 1},
    {"R_g_source_remove_by_funcs_user_data", (DL_FUNC) &R_g_source_remove_by_funcs_user_data, 2},
    {"R_g_source_remove_by_user_data", (DL_FUNC) &R_g_source_remove_by_user_data, 1},
    {"R_g_source_set_name_by_id", (DL_FUNC) &R_g_source_set_name_by_id, 2},
    {"R_g_static_mutex_get_mutex_impl", (DL_FUNC) &R_g_static_mutex_get_mutex_impl, 1},
    {"R_g_string_new", (DL_FUNC) &R_g_string_new, 1},
    {"R_g_string_new_len", (DL_FUNC) &R_g_string_new_len, 2},
    {"R_g_string_sized_new", (DL_FUNC) &R_g_string_sized_new, 1},
    {"R_g_string_append", (DL_FUNC) &R_g_string_append, 2},
    {"R_g_string_append_c", (DL_FUNC) &R_g_string_append_c, 2},
    {"R_g_string_append_len", (DL_FUNC) &R_g_string_append_len, 3},
    {"R_g_string_append_unichar", (DL_FUNC) &R_g_string_append_unichar, 2},
    {"R_g_string_append_uri_escaped", (DL_FUNC) &R_g_string_append_uri_escaped, 4},
    {"R_g_string_ascii_down", (DL_FUNC) &R_g_string_ascii_down, 1},
    {"R_g_string_ascii_up", (DL_FUNC) &R_g_string_ascii_up, 1},
    {"R_g_string_assign", (DL_FUNC) &R_g_string_assign, 2},
    {"R_g_string_down", (DL_FUNC) &R_g_string_down, 1},
    {"R_g_string_equal", (DL_FUNC) &R_g_string_equal, 2},
    {"R_g_string_erase", (DL_FUNC) &R_g_string_erase, 3},
    {"R_g_string_free", (DL_FUNC) &R_g_string_free, 2},
    {"R_g_string_free_to_bytes", (DL_FUNC) &R_g_string_free_to_bytes, 1},
    {"R_g_string_hash", (DL_FUNC) &R_g_string_hash, 1},
    {"R_g_string_insert", (DL_FUNC) &R_g_string_insert, 3},
    {"R_g_string_insert_c", (DL_FUNC) &R_g_string_insert_c, 3},
    {"R_g_string_insert_len", (DL_FUNC) &R_g_string_insert_len, 4},
    {"R_g_string_insert_unichar", (DL_FUNC) &R_g_string_insert_unichar, 3},
    {"R_g_string_overwrite", (DL_FUNC) &R_g_string_overwrite, 3},
    {"R_g_string_overwrite_len", (DL_FUNC) &R_g_string_overwrite_len, 4},
    {"R_g_string_prepend", (DL_FUNC) &R_g_string_prepend, 2},
    {"R_g_string_prepend_c", (DL_FUNC) &R_g_string_prepend_c, 2},
    {"R_g_string_prepend_len", (DL_FUNC) &R_g_string_prepend_len, 3},
    {"R_g_string_prepend_unichar", (DL_FUNC) &R_g_string_prepend_unichar, 2},
    {"R_g_string_set_size", (DL_FUNC) &R_g_string_set_size, 2},
    {"R_g_string_truncate", (DL_FUNC) &R_g_string_truncate, 2},
    {"R_g_string_up", (DL_FUNC) &R_g_string_up, 1},
    {"R_g_string_chunk_clear", (DL_FUNC) &R_g_string_chunk_clear, 1},
    {"R_g_string_chunk_free", (DL_FUNC) &R_g_string_chunk_free, 1},
    {"R_g_string_chunk_insert", (DL_FUNC) &R_g_string_chunk_insert, 2},
    {"R_g_string_chunk_insert_const", (DL_FUNC) &R_g_string_chunk_insert_const, 2},
    {"R_g_string_chunk_insert_len", (DL_FUNC) &R_g_string_chunk_insert_len, 3},
    {"R_g_strv_builder_add", (DL_FUNC) &R_g_strv_builder_add, 2},
    {"R_g_strv_builder_addv", (DL_FUNC) &R_g_strv_builder_addv, 2},
    {"R_g_strv_builder_end", (DL_FUNC) &R_g_strv_builder_end, 1},
    {"R_g_strv_builder_take", (DL_FUNC) &R_g_strv_builder_take, 2},
    {"R_g_test_log_buffer_free", (DL_FUNC) &R_g_test_log_buffer_free, 1},
    {"R_g_test_log_buffer_push", (DL_FUNC) &R_g_test_log_buffer_push, 3},
    {"R_g_test_log_msg_free", (DL_FUNC) &R_g_test_log_msg_free, 1},
    {"R_g_test_suite_add", (DL_FUNC) &R_g_test_suite_add, 2},
    {"R_g_test_suite_add_suite", (DL_FUNC) &R_g_test_suite_add_suite, 2},
    {"R_g_thread_new", (DL_FUNC) &R_g_thread_new, 3},
    {"R_g_thread_try_new", (DL_FUNC) &R_g_thread_try_new, 3},
    {"R_g_thread_join", (DL_FUNC) &R_g_thread_join, 1},
    {"R_g_thread_ref", (DL_FUNC) &R_g_thread_ref, 1},
    {"R_g_thread_unref", (DL_FUNC) &R_g_thread_unref, 1},
    {"R_g_thread_error_quark", (DL_FUNC) &R_g_thread_error_quark, 0},
    {"R_g_thread_exit", (DL_FUNC) &R_g_thread_exit, 1},
    {"R_g_thread_self", (DL_FUNC) &R_g_thread_self, 0},
    {"R_g_thread_yield", (DL_FUNC) &R_g_thread_yield, 0},
    {"R_g_thread_pool_free", (DL_FUNC) &R_g_thread_pool_free, 3},
    {"R_g_thread_pool_get_max_threads", (DL_FUNC) &R_g_thread_pool_get_max_threads, 1},
    {"R_g_thread_pool_get_num_threads", (DL_FUNC) &R_g_thread_pool_get_num_threads, 1},
    {"R_g_thread_pool_move_to_front", (DL_FUNC) &R_g_thread_pool_move_to_front, 2},
    {"R_g_thread_pool_push", (DL_FUNC) &R_g_thread_pool_push, 2},
    {"R_g_thread_pool_set_max_threads", (DL_FUNC) &R_g_thread_pool_set_max_threads, 2},
    {"R_g_thread_pool_unprocessed", (DL_FUNC) &R_g_thread_pool_unprocessed, 1},
    {"R_g_thread_pool_get_max_idle_time", (DL_FUNC) &R_g_thread_pool_get_max_idle_time, 0},
    {"R_g_thread_pool_get_max_unused_threads", (DL_FUNC) &R_g_thread_pool_get_max_unused_threads, 0},
    {"R_g_thread_pool_get_num_unused_threads", (DL_FUNC) &R_g_thread_pool_get_num_unused_threads, 0},
    {"R_g_thread_pool_set_max_idle_time", (DL_FUNC) &R_g_thread_pool_set_max_idle_time, 1},
    {"R_g_thread_pool_set_max_unused_threads", (DL_FUNC) &R_g_thread_pool_set_max_unused_threads, 1},
    {"R_g_thread_pool_stop_unused_threads", (DL_FUNC) &R_g_thread_pool_stop_unused_threads, 0},
    {"R_g_time_val_add", (DL_FUNC) &R_g_time_val_add, 2},
    {"R_g_time_val_to_iso8601", (DL_FUNC) &R_g_time_val_to_iso8601, 1},
    {"R_g_time_val_from_iso8601", (DL_FUNC) &R_g_time_val_from_iso8601, 1},
    {"R_g_time_zone_new", (DL_FUNC) &R_g_time_zone_new, 1},
    {"R_g_time_zone_new_local", (DL_FUNC) &R_g_time_zone_new_local, 0},
    {"R_g_time_zone_new_utc", (DL_FUNC) &R_g_time_zone_new_utc, 0},
    {"R_g_time_zone_adjust_time", (DL_FUNC) &R_g_time_zone_adjust_time, 2},
    {"R_g_time_zone_find_interval", (DL_FUNC) &R_g_time_zone_find_interval, 3},
    {"R_g_time_zone_get_abbreviation", (DL_FUNC) &R_g_time_zone_get_abbreviation, 2},
    {"R_g_time_zone_get_offset", (DL_FUNC) &R_g_time_zone_get_offset, 2},
    {"R_g_time_zone_is_dst", (DL_FUNC) &R_g_time_zone_is_dst, 2},
    {"R_g_time_zone_ref", (DL_FUNC) &R_g_time_zone_ref, 1},
    {"R_g_time_zone_unref", (DL_FUNC) &R_g_time_zone_unref, 1},
    {"R_g_timer_continue", (DL_FUNC) &R_g_timer_continue, 1},
    {"R_g_timer_destroy", (DL_FUNC) &R_g_timer_destroy, 1},
    {"R_g_timer_elapsed", (DL_FUNC) &R_g_timer_elapsed, 2},
    {"R_g_timer_reset", (DL_FUNC) &R_g_timer_reset, 1},
    {"R_g_timer_start", (DL_FUNC) &R_g_timer_start, 1},
    {"R_g_timer_stop", (DL_FUNC) &R_g_timer_stop, 1},
    {"R_g_trash_stack_height", (DL_FUNC) &R_g_trash_stack_height, 1},
    {"R_g_trash_stack_peek", (DL_FUNC) &R_g_trash_stack_peek, 1},
    {"R_g_trash_stack_pop", (DL_FUNC) &R_g_trash_stack_pop, 1},
    {"R_g_trash_stack_push", (DL_FUNC) &R_g_trash_stack_push, 2},
    {"R_g_tree_new_full", (DL_FUNC) &R_g_tree_new_full, 4},
    {"R_g_tree_destroy", (DL_FUNC) &R_g_tree_destroy, 1},
    {"R_g_tree_foreach", (DL_FUNC) &R_g_tree_foreach, 3},
    {"R_g_tree_height", (DL_FUNC) &R_g_tree_height, 1},
    {"R_g_tree_insert", (DL_FUNC) &R_g_tree_insert, 3},
    {"R_g_tree_lookup", (DL_FUNC) &R_g_tree_lookup, 2},
    {"R_g_tree_lookup_extended", (DL_FUNC) &R_g_tree_lookup_extended, 2},
    {"R_g_tree_nnodes", (DL_FUNC) &R_g_tree_nnodes, 1},
    {"R_g_tree_ref", (DL_FUNC) &R_g_tree_ref, 1},
    {"R_g_tree_remove", (DL_FUNC) &R_g_tree_remove, 2},
    {"R_g_tree_replace", (DL_FUNC) &R_g_tree_replace, 3},
    {"R_g_tree_search", (DL_FUNC) &R_g_tree_search, 3},
    {"R_g_tree_steal", (DL_FUNC) &R_g_tree_steal, 2},
    {"R_g_tree_traverse", (DL_FUNC) &R_g_tree_traverse, 4},
    {"R_g_tree_unref", (DL_FUNC) &R_g_tree_unref, 1},
    {"R_g_tuples_destroy", (DL_FUNC) &R_g_tuples_destroy, 1},
    {"R_g_tuples_index", (DL_FUNC) &R_g_tuples_index, 3},
    {"R_g_unicode_script_from_iso15924", (DL_FUNC) &R_g_unicode_script_from_iso15924, 1},
    {"R_g_unicode_script_to_iso15924", (DL_FUNC) &R_g_unicode_script_to_iso15924, 1},
    {"R_g_uri_error_quark", (DL_FUNC) &R_g_uri_error_quark, 0},
    {"R_g_uri_escape_string", (DL_FUNC) &R_g_uri_escape_string, 3},
    {"R_g_uri_list_extract_uris", (DL_FUNC) &R_g_uri_list_extract_uris, 1},
    {"R_g_uri_parse_scheme", (DL_FUNC) &R_g_uri_parse_scheme, 1},
    {"R_g_uri_unescape_segment", (DL_FUNC) &R_g_uri_unescape_segment, 3},
    {"R_g_uri_unescape_string", (DL_FUNC) &R_g_uri_unescape_string, 2},
    {"R_g_variant_new_array", (DL_FUNC) &R_g_variant_new_array, 3},
    {"R_g_variant_new_boolean", (DL_FUNC) &R_g_variant_new_boolean, 1},
    {"R_g_variant_new_byte", (DL_FUNC) &R_g_variant_new_byte, 1},
    {"R_g_variant_new_bytestring", (DL_FUNC) &R_g_variant_new_bytestring, 1},
    {"R_g_variant_new_bytestring_array", (DL_FUNC) &R_g_variant_new_bytestring_array, 2},
    {"R_g_variant_new_dict_entry", (DL_FUNC) &R_g_variant_new_dict_entry, 2},
    {"R_g_variant_new_double", (DL_FUNC) &R_g_variant_new_double, 1},
    {"R_g_variant_new_fixed_array", (DL_FUNC) &R_g_variant_new_fixed_array, 4},
    {"R_g_variant_new_from_bytes", (DL_FUNC) &R_g_variant_new_from_bytes, 3},
    {"R_g_variant_new_from_data", (DL_FUNC) &R_g_variant_new_from_data, 6},
    {"R_g_variant_new_handle", (DL_FUNC) &R_g_variant_new_handle, 1},
    {"R_g_variant_new_int16", (DL_FUNC) &R_g_variant_new_int16, 1},
    {"R_g_variant_new_int32", (DL_FUNC) &R_g_variant_new_int32, 1},
    {"R_g_variant_new_int64", (DL_FUNC) &R_g_variant_new_int64, 1},
    {"R_g_variant_new_maybe", (DL_FUNC) &R_g_variant_new_maybe, 2},
    {"R_g_variant_new_object_path", (DL_FUNC) &R_g_variant_new_object_path, 1},
    {"R_g_variant_new_objv", (DL_FUNC) &R_g_variant_new_objv, 2},
    {"R_g_variant_new_signature", (DL_FUNC) &R_g_variant_new_signature, 1},
    {"R_g_variant_new_string", (DL_FUNC) &R_g_variant_new_string, 1},
    {"R_g_variant_new_strv", (DL_FUNC) &R_g_variant_new_strv, 2},
    {"R_g_variant_new_tuple", (DL_FUNC) &R_g_variant_new_tuple, 2},
    {"R_g_variant_new_uint16", (DL_FUNC) &R_g_variant_new_uint16, 1},
    {"R_g_variant_new_uint32", (DL_FUNC) &R_g_variant_new_uint32, 1},
    {"R_g_variant_new_uint64", (DL_FUNC) &R_g_variant_new_uint64, 1},
    {"R_g_variant_new_variant", (DL_FUNC) &R_g_variant_new_variant, 1},
    {"R_g_variant_byteswap", (DL_FUNC) &R_g_variant_byteswap, 1},
    {"R_g_variant_check_format_string", (DL_FUNC) &R_g_variant_check_format_string, 3},
    {"R_g_variant_classify", (DL_FUNC) &R_g_variant_classify, 1},
    {"R_g_variant_compare", (DL_FUNC) &R_g_variant_compare, 2},
    {"R_g_variant_dup_bytestring", (DL_FUNC) &R_g_variant_dup_bytestring, 1},
    {"R_g_variant_dup_bytestring_array", (DL_FUNC) &R_g_variant_dup_bytestring_array, 1},
    {"R_g_variant_dup_objv", (DL_FUNC) &R_g_variant_dup_objv, 1},
    {"R_g_variant_dup_string", (DL_FUNC) &R_g_variant_dup_string, 1},
    {"R_g_variant_dup_strv", (DL_FUNC) &R_g_variant_dup_strv, 1},
    {"R_g_variant_equal", (DL_FUNC) &R_g_variant_equal, 2},
    {"R_g_variant_get_boolean", (DL_FUNC) &R_g_variant_get_boolean, 1},
    {"R_g_variant_get_byte", (DL_FUNC) &R_g_variant_get_byte, 1},
    {"R_g_variant_get_bytestring", (DL_FUNC) &R_g_variant_get_bytestring, 1},
    {"R_g_variant_get_bytestring_array", (DL_FUNC) &R_g_variant_get_bytestring_array, 1},
    {"R_g_variant_get_child_value", (DL_FUNC) &R_g_variant_get_child_value, 2},
    {"R_g_variant_get_data", (DL_FUNC) &R_g_variant_get_data, 1},
    {"R_g_variant_get_data_as_bytes", (DL_FUNC) &R_g_variant_get_data_as_bytes, 1},
    {"R_g_variant_get_double", (DL_FUNC) &R_g_variant_get_double, 1},
    {"R_g_variant_get_handle", (DL_FUNC) &R_g_variant_get_handle, 1},
    {"R_g_variant_get_int16", (DL_FUNC) &R_g_variant_get_int16, 1},
    {"R_g_variant_get_int32", (DL_FUNC) &R_g_variant_get_int32, 1},
    {"R_g_variant_get_int64", (DL_FUNC) &R_g_variant_get_int64, 1},
    {"R_g_variant_get_maybe", (DL_FUNC) &R_g_variant_get_maybe, 1},
    {"R_g_variant_get_normal_form", (DL_FUNC) &R_g_variant_get_normal_form, 1},
    {"R_g_variant_get_objv", (DL_FUNC) &R_g_variant_get_objv, 1},
    {"R_g_variant_get_size", (DL_FUNC) &R_g_variant_get_size, 1},
    {"R_g_variant_get_string", (DL_FUNC) &R_g_variant_get_string, 1},
    {"R_g_variant_get_strv", (DL_FUNC) &R_g_variant_get_strv, 1},
    {"R_g_variant_get_type", (DL_FUNC) &R_g_variant_get_type, 1},
    {"R_g_variant_get_type_string", (DL_FUNC) &R_g_variant_get_type_string, 1},
    {"R_g_variant_get_uint16", (DL_FUNC) &R_g_variant_get_uint16, 1},
    {"R_g_variant_get_uint32", (DL_FUNC) &R_g_variant_get_uint32, 1},
    {"R_g_variant_get_uint64", (DL_FUNC) &R_g_variant_get_uint64, 1},
    {"R_g_variant_get_variant", (DL_FUNC) &R_g_variant_get_variant, 1},
    {"R_g_variant_hash", (DL_FUNC) &R_g_variant_hash, 1},
    {"R_g_variant_is_container", (DL_FUNC) &R_g_variant_is_container, 1},
    {"R_g_variant_is_floating", (DL_FUNC) &R_g_variant_is_floating, 1},
    {"R_g_variant_is_normal_form", (DL_FUNC) &R_g_variant_is_normal_form, 1},
    {"R_g_variant_is_of_type", (DL_FUNC) &R_g_variant_is_of_type, 2},
    {"R_g_variant_lookup_value", (DL_FUNC) &R_g_variant_lookup_value, 3},
    {"R_g_variant_n_children", (DL_FUNC) &R_g_variant_n_children, 1},
    {"R_g_variant_print", (DL_FUNC) &R_g_variant_print, 2},
    {"R_g_variant_ref", (DL_FUNC) &R_g_variant_ref, 1},
    {"R_g_variant_ref_sink", (DL_FUNC) &R_g_variant_ref_sink, 1},
    {"R_g_variant_store", (DL_FUNC) &R_g_variant_store, 2},
    {"R_g_variant_take_ref", (DL_FUNC) &R_g_variant_take_ref, 1},
    {"R_g_variant_unref", (DL_FUNC) &R_g_variant_unref, 1},
    {"R_g_variant_is_object_path", (DL_FUNC) &R_g_variant_is_object_path, 1},
    {"R_g_variant_is_signature", (DL_FUNC) &R_g_variant_is_signature, 1},
    {"R_g_variant_parse", (DL_FUNC) &R_g_variant_parse, 4},
    {"R_g_variant_parse_error_print_context", (DL_FUNC) &R_g_variant_parse_error_print_context, 2},
    {"R_g_variant_parse_error_quark", (DL_FUNC) &R_g_variant_parse_error_quark, 0},
    {"R_g_variant_parser_get_error_quark", (DL_FUNC) &R_g_variant_parser_get_error_quark, 0},
    {"R_g_variant_builder_new", (DL_FUNC) &R_g_variant_builder_new, 1},
    {"R_g_variant_builder_add_value", (DL_FUNC) &R_g_variant_builder_add_value, 2},
    {"R_g_variant_builder_close", (DL_FUNC) &R_g_variant_builder_close, 1},
    {"R_g_variant_builder_end", (DL_FUNC) &R_g_variant_builder_end, 1},
    {"R_g_variant_builder_open", (DL_FUNC) &R_g_variant_builder_open, 2},
    {"R_g_variant_builder_ref", (DL_FUNC) &R_g_variant_builder_ref, 1},
    {"R_g_variant_builder_unref", (DL_FUNC) &R_g_variant_builder_unref, 1},
    {"R_g_variant_dict_new", (DL_FUNC) &R_g_variant_dict_new, 1},
    {"R_g_variant_dict_clear", (DL_FUNC) &R_g_variant_dict_clear, 1},
    {"R_g_variant_dict_contains", (DL_FUNC) &R_g_variant_dict_contains, 2},
    {"R_g_variant_dict_end", (DL_FUNC) &R_g_variant_dict_end, 1},
    {"R_g_variant_dict_insert_value", (DL_FUNC) &R_g_variant_dict_insert_value, 3},
    {"R_g_variant_dict_lookup_value", (DL_FUNC) &R_g_variant_dict_lookup_value, 3},
    {"R_g_variant_dict_ref", (DL_FUNC) &R_g_variant_dict_ref, 1},
    {"R_g_variant_dict_remove", (DL_FUNC) &R_g_variant_dict_remove, 2},
    {"R_g_variant_dict_unref", (DL_FUNC) &R_g_variant_dict_unref, 1},
    {"R_g_variant_iter_free", (DL_FUNC) &R_g_variant_iter_free, 1},
    {"R_g_variant_iter_n_children", (DL_FUNC) &R_g_variant_iter_n_children, 1},
    {"R_g_variant_iter_next_value", (DL_FUNC) &R_g_variant_iter_next_value, 1},
    {"R_g_variant_type_new", (DL_FUNC) &R_g_variant_type_new, 1},
    {"R_g_variant_type_new_array", (DL_FUNC) &R_g_variant_type_new_array, 1},
    {"R_g_variant_type_new_dict_entry", (DL_FUNC) &R_g_variant_type_new_dict_entry, 2},
    {"R_g_variant_type_new_maybe", (DL_FUNC) &R_g_variant_type_new_maybe, 1},
    {"R_g_variant_type_new_tuple", (DL_FUNC) &R_g_variant_type_new_tuple, 2},
    {"R_g_variant_type_copy", (DL_FUNC) &R_g_variant_type_copy, 1},
    {"R_g_variant_type_dup_string", (DL_FUNC) &R_g_variant_type_dup_string, 1},
    {"R_g_variant_type_element", (DL_FUNC) &R_g_variant_type_element, 1},
    {"R_g_variant_type_equal", (DL_FUNC) &R_g_variant_type_equal, 2},
    {"R_g_variant_type_first", (DL_FUNC) &R_g_variant_type_first, 1},
    {"R_g_variant_type_free", (DL_FUNC) &R_g_variant_type_free, 1},
    {"R_g_variant_type_get_string_length", (DL_FUNC) &R_g_variant_type_get_string_length, 1},
    {"R_g_variant_type_hash", (DL_FUNC) &R_g_variant_type_hash, 1},
    {"R_g_variant_type_is_array", (DL_FUNC) &R_g_variant_type_is_array, 1},
    {"R_g_variant_type_is_basic", (DL_FUNC) &R_g_variant_type_is_basic, 1},
    {"R_g_variant_type_is_container", (DL_FUNC) &R_g_variant_type_is_container, 1},
    {"R_g_variant_type_is_definite", (DL_FUNC) &R_g_variant_type_is_definite, 1},
    {"R_g_variant_type_is_dict_entry", (DL_FUNC) &R_g_variant_type_is_dict_entry, 1},
    {"R_g_variant_type_is_maybe", (DL_FUNC) &R_g_variant_type_is_maybe, 1},
    {"R_g_variant_type_is_subtype_of", (DL_FUNC) &R_g_variant_type_is_subtype_of, 2},
    {"R_g_variant_type_is_tuple", (DL_FUNC) &R_g_variant_type_is_tuple, 1},
    {"R_g_variant_type_is_variant", (DL_FUNC) &R_g_variant_type_is_variant, 1},
    {"R_g_variant_type_key", (DL_FUNC) &R_g_variant_type_key, 1},
    {"R_g_variant_type_n_items", (DL_FUNC) &R_g_variant_type_n_items, 1},
    {"R_g_variant_type_next", (DL_FUNC) &R_g_variant_type_next, 1},
    {"R_g_variant_type_value", (DL_FUNC) &R_g_variant_type_value, 1},
    {"R_g_variant_type_checked_", (DL_FUNC) &R_g_variant_type_checked_, 1},
    {"R_g_variant_type_string_get_depth_", (DL_FUNC) &R_g_variant_type_string_get_depth_, 1},
    {"R_g_variant_type_string_is_valid", (DL_FUNC) &R_g_variant_type_string_is_valid, 1},
    {"R_g_variant_type_string_scan", (DL_FUNC) &R_g_variant_type_string_scan, 2},
    {"R_g_access", (DL_FUNC) &R_g_access, 2},
    {"R_g_ascii_digit_value", (DL_FUNC) &R_g_ascii_digit_value, 1},
    {"R_g_ascii_dtostr", (DL_FUNC) &R_g_ascii_dtostr, 3},
    {"R_g_ascii_formatd", (DL_FUNC) &R_g_ascii_formatd, 4},
    {"R_g_ascii_strcasecmp", (DL_FUNC) &R_g_ascii_strcasecmp, 2},
    {"R_g_ascii_strdown", (DL_FUNC) &R_g_ascii_strdown, 2},
    {"R_g_ascii_string_to_signed", (DL_FUNC) &R_g_ascii_string_to_signed, 4},
    {"R_g_ascii_string_to_unsigned", (DL_FUNC) &R_g_ascii_string_to_unsigned, 4},
    {"R_g_ascii_strncasecmp", (DL_FUNC) &R_g_ascii_strncasecmp, 3},
    {"R_g_ascii_strtod", (DL_FUNC) &R_g_ascii_strtod, 1},
    {"R_g_ascii_strtoll", (DL_FUNC) &R_g_ascii_strtoll, 2},
    {"R_g_ascii_strtoull", (DL_FUNC) &R_g_ascii_strtoull, 2},
    {"R_g_ascii_strup", (DL_FUNC) &R_g_ascii_strup, 2},
    {"R_g_ascii_tolower", (DL_FUNC) &R_g_ascii_tolower, 1},
    {"R_g_ascii_toupper", (DL_FUNC) &R_g_ascii_toupper, 1},
    {"R_g_ascii_xdigit_value", (DL_FUNC) &R_g_ascii_xdigit_value, 1},
    {"R_g_assert_warning", (DL_FUNC) &R_g_assert_warning, 5},
    {"R_g_assertion_message", (DL_FUNC) &R_g_assertion_message, 5},
    {"R_g_assertion_message_cmpint", (DL_FUNC) &R_g_assertion_message_cmpint, 9},
    {"R_g_assertion_message_cmpstr", (DL_FUNC) &R_g_assertion_message_cmpstr, 8},
    {"R_g_assertion_message_cmpstrv", (DL_FUNC) &R_g_assertion_message_cmpstrv, 8},
    {"R_g_assertion_message_error", (DL_FUNC) &R_g_assertion_message_error, 8},
    {"R_g_atexit", (DL_FUNC) &R_g_atexit, 1},
    {"R_g_base64_decode", (DL_FUNC) &R_g_base64_decode, 1},
    {"R_g_base64_decode_inplace", (DL_FUNC) &R_g_base64_decode_inplace, 0},
    {"R_g_base64_encode", (DL_FUNC) &R_g_base64_encode, 2},
    {"R_g_base64_encode_close", (DL_FUNC) &R_g_base64_encode_close, 1},
    {"R_g_base64_encode_step", (DL_FUNC) &R_g_base64_encode_step, 3},
    {"R_g_basename", (DL_FUNC) &R_g_basename, 1},
    {"R_g_bit_lock", (DL_FUNC) &R_g_bit_lock, 2},
    {"R_g_bit_nth_lsf", (DL_FUNC) &R_g_bit_nth_lsf, 2},
    {"R_g_bit_nth_msf", (DL_FUNC) &R_g_bit_nth_msf, 2},
    {"R_g_bit_storage", (DL_FUNC) &R_g_bit_storage, 1},
    {"R_g_bit_trylock", (DL_FUNC) &R_g_bit_trylock, 2},
    {"R_g_bit_unlock", (DL_FUNC) &R_g_bit_unlock, 2},
    {"R_g_blow_chunks", (DL_FUNC) &R_g_blow_chunks, 0},
    {"R_g_build_filenamev", (DL_FUNC) &R_g_build_filenamev, 1},
    {"R_g_build_pathv", (DL_FUNC) &R_g_build_pathv, 2},
    {"R_g_chdir", (DL_FUNC) &R_g_chdir, 1},
    {"R_glib_check_version", (DL_FUNC) &R_glib_check_version, 3},
    {"R_g_child_watch_add_full", (DL_FUNC) &R_g_child_watch_add_full, 5},
    {"R_g_child_watch_source_new", (DL_FUNC) &R_g_child_watch_source_new, 1},
    {"R_g_chmod", (DL_FUNC) &R_g_chmod, 2},
    {"R_g_clear_error", (DL_FUNC) &R_g_clear_error, 0},
    {"R_g_close", (DL_FUNC) &R_g_close, 1},
    {"R_g_compute_checksum_for_bytes", (DL_FUNC) &R_g_compute_checksum_for_bytes, 2},
    {"R_g_compute_checksum_for_data", (DL_FUNC) &R_g_compute_checksum_for_data, 3},
    {"R_g_compute_checksum_for_string", (DL_FUNC) &R_g_compute_checksum_for_string, 3},
    {"R_g_compute_hmac_for_bytes", (DL_FUNC) &R_g_compute_hmac_for_bytes, 3},
    {"R_g_compute_hmac_for_data", (DL_FUNC) &R_g_compute_hmac_for_data, 5},
    {"R_g_compute_hmac_for_string", (DL_FUNC) &R_g_compute_hmac_for_string, 5},
    {"R_g_convert", (DL_FUNC) &R_g_convert, 4},
    {"R_g_convert_error_quark", (DL_FUNC) &R_g_convert_error_quark, 0},
    {"R_g_convert_with_fallback", (DL_FUNC) &R_g_convert_with_fallback, 5},
    {"R_g_creat", (DL_FUNC) &R_g_creat, 2},
    {"R_g_datalist_foreach", (DL_FUNC) &R_g_datalist_foreach, 3},
    {"R_g_datalist_get_data", (DL_FUNC) &R_g_datalist_get_data, 2},
    {"R_g_datalist_get_flags", (DL_FUNC) &R_g_datalist_get_flags, 1},
    {"R_g_datalist_id_get_data", (DL_FUNC) &R_g_datalist_id_get_data, 2},
    {"R_g_datalist_set_flags", (DL_FUNC) &R_g_datalist_set_flags, 2},
    {"R_g_datalist_unset_flags", (DL_FUNC) &R_g_datalist_unset_flags, 2},
    {"R_g_dataset_destroy", (DL_FUNC) &R_g_dataset_destroy, 1},
    {"R_g_dataset_foreach", (DL_FUNC) &R_g_dataset_foreach, 3},
    {"R_g_dataset_id_get_data", (DL_FUNC) &R_g_dataset_id_get_data, 2},
    {"R_g_dcgettext", (DL_FUNC) &R_g_dcgettext, 3},
    {"R_g_dgettext", (DL_FUNC) &R_g_dgettext, 2},
    {"R_g_direct_equal", (DL_FUNC) &R_g_direct_equal, 2},
    {"R_g_direct_hash", (DL_FUNC) &R_g_direct_hash, 1},
    {"R_g_dngettext", (DL_FUNC) &R_g_dngettext, 4},
    {"R_g_double_equal", (DL_FUNC) &R_g_double_equal, 2},
    {"R_g_double_hash", (DL_FUNC) &R_g_double_hash, 1},
    {"R_g_dpgettext", (DL_FUNC) &R_g_dpgettext, 3},
    {"R_g_dpgettext2", (DL_FUNC) &R_g_dpgettext2, 3},
    {"R_g_environ_getenv", (DL_FUNC) &R_g_environ_getenv, 2},
    {"R_g_environ_setenv", (DL_FUNC) &R_g_environ_setenv, 4},
    {"R_g_environ_unsetenv", (DL_FUNC) &R_g_environ_unsetenv, 2},
    {"R_g_file_error_from_errno", (DL_FUNC) &R_g_file_error_from_errno, 1},
    {"R_g_file_error_quark", (DL_FUNC) &R_g_file_error_quark, 0},
    {"R_g_file_get_contents", (DL_FUNC) &R_g_file_get_contents, 1},
    {"R_g_file_open_tmp", (DL_FUNC) &R_g_file_open_tmp, 1},
    {"R_g_file_read_link", (DL_FUNC) &R_g_file_read_link, 1},
    {"R_g_file_set_contents", (DL_FUNC) &R_g_file_set_contents, 3},
    {"R_g_file_test", (DL_FUNC) &R_g_file_test, 2},
    {"R_g_filename_display_basename", (DL_FUNC) &R_g_filename_display_basename, 1},
    {"R_g_filename_display_name", (DL_FUNC) &R_g_filename_display_name, 1},
    {"R_g_filename_from_uri", (DL_FUNC) &R_g_filename_from_uri, 1},
    {"R_g_filename_from_utf8", (DL_FUNC) &R_g_filename_from_utf8, 2},
    {"R_g_filename_to_uri", (DL_FUNC) &R_g_filename_to_uri, 2},
    {"R_g_filename_to_utf8", (DL_FUNC) &R_g_filename_to_utf8, 2},
    {"R_g_find_program_in_path", (DL_FUNC) &R_g_find_program_in_path, 1},
    {"R_g_fopen", (DL_FUNC) &R_g_fopen, 2},
    {"R_g_format_size", (DL_FUNC) &R_g_format_size, 1},
    {"R_g_format_size_for_display", (DL_FUNC) &R_g_format_size_for_display, 1},
    {"R_g_format_size_full", (DL_FUNC) &R_g_format_size_full, 2},
    {"R_g_free", (DL_FUNC) &R_g_free, 1},
    {"R_g_freopen", (DL_FUNC) &R_g_freopen, 3},
    {"R_g_get_application_name", (DL_FUNC) &R_g_get_application_name, 0},
    {"R_g_get_charset", (DL_FUNC) &R_g_get_charset, 0},
    {"R_g_get_codeset", (DL_FUNC) &R_g_get_codeset, 0},
    {"R_g_get_current_dir", (DL_FUNC) &R_g_get_current_dir, 0},
    {"R_g_get_current_time", (DL_FUNC) &R_g_get_current_time, 1},
    {"R_g_get_environ", (DL_FUNC) &R_g_get_environ, 0},
    {"R_g_get_filename_charsets", (DL_FUNC) &R_g_get_filename_charsets, 0},
    {"R_g_get_home_dir", (DL_FUNC) &R_g_get_home_dir, 0},
    {"R_g_get_host_name", (DL_FUNC) &R_g_get_host_name, 0},
    {"R_g_get_language_names", (DL_FUNC) &R_g_get_language_names, 0},
    {"R_g_get_locale_variants", (DL_FUNC) &R_g_get_locale_variants, 1},
    {"R_g_get_monotonic_time", (DL_FUNC) &R_g_get_monotonic_time, 0},
    {"R_g_get_num_processors", (DL_FUNC) &R_g_get_num_processors, 0},
    {"R_g_get_prgname", (DL_FUNC) &R_g_get_prgname, 0},
    {"R_g_get_real_name", (DL_FUNC) &R_g_get_real_name, 0},
    {"R_g_get_real_time", (DL_FUNC) &R_g_get_real_time, 0},
    {"R_g_get_system_config_dirs", (DL_FUNC) &R_g_get_system_config_dirs, 0},
    {"R_g_get_system_data_dirs", (DL_FUNC) &R_g_get_system_data_dirs, 0},
    {"R_g_get_tmp_dir", (DL_FUNC) &R_g_get_tmp_dir, 0},
    {"R_g_get_user_cache_dir", (DL_FUNC) &R_g_get_user_cache_dir, 0},
    {"R_g_get_user_config_dir", (DL_FUNC) &R_g_get_user_config_dir, 0},
    {"R_g_get_user_data_dir", (DL_FUNC) &R_g_get_user_data_dir, 0},
    {"R_g_get_user_name", (DL_FUNC) &R_g_get_user_name, 0},
    {"R_g_get_user_runtime_dir", (DL_FUNC) &R_g_get_user_runtime_dir, 0},
    {"R_g_get_user_special_dir", (DL_FUNC) &R_g_get_user_special_dir, 1},
    {"R_g_getenv", (DL_FUNC) &R_g_getenv, 1},
    {"R_g_hostname_is_ascii_encoded", (DL_FUNC) &R_g_hostname_is_ascii_encoded, 1},
    {"R_g_hostname_is_ip_address", (DL_FUNC) &R_g_hostname_is_ip_address, 1},
    {"R_g_hostname_is_non_ascii", (DL_FUNC) &R_g_hostname_is_non_ascii, 1},
    {"R_g_hostname_to_ascii", (DL_FUNC) &R_g_hostname_to_ascii, 1},
    {"R_g_hostname_to_unicode", (DL_FUNC) &R_g_hostname_to_unicode, 1},
    {"R_g_idle_add_full", (DL_FUNC) &R_g_idle_add_full, 4},
    {"R_g_idle_remove_by_data", (DL_FUNC) &R_g_idle_remove_by_data, 1},
    {"R_g_idle_source_new", (DL_FUNC) &R_g_idle_source_new, 0},
    {"R_g_int64_equal", (DL_FUNC) &R_g_int64_equal, 2},
    {"R_g_int64_hash", (DL_FUNC) &R_g_int64_hash, 1},
    {"R_g_int_equal", (DL_FUNC) &R_g_int_equal, 2},
    {"R_g_int_hash", (DL_FUNC) &R_g_int_hash, 1},
    {"R_g_intern_static_string", (DL_FUNC) &R_g_intern_static_string, 1},
    {"R_g_intern_string", (DL_FUNC) &R_g_intern_string, 1},
    {"R_g_io_add_watch_full", (DL_FUNC) &R_g_io_add_watch_full, 6},
    {"R_g_io_create_watch", (DL_FUNC) &R_g_io_create_watch, 2},
    {"R_g_listenv", (DL_FUNC) &R_g_listenv, 0},
    {"R_g_locale_from_utf8", (DL_FUNC) &R_g_locale_from_utf8, 2},
    {"R_g_locale_to_utf8", (DL_FUNC) &R_g_locale_to_utf8, 2},
    {"R_g_log_default_handler", (DL_FUNC) &R_g_log_default_handler, 4},
    {"R_g_log_remove_handler", (DL_FUNC) &R_g_log_remove_handler, 2},
    {"R_g_log_set_always_fatal", (DL_FUNC) &R_g_log_set_always_fatal, 1},
    {"R_g_log_set_fatal_mask", (DL_FUNC) &R_g_log_set_fatal_mask, 2},
    {"R_g_log_set_handler_full", (DL_FUNC) &R_g_log_set_handler_full, 5},
    {"R_g_log_set_writer_func", (DL_FUNC) &R_g_log_set_writer_func, 3},
    {"R_g_log_structured_array", (DL_FUNC) &R_g_log_structured_array, 3},
    {"R_g_log_variant", (DL_FUNC) &R_g_log_variant, 3},
    {"R_g_log_writer_default", (DL_FUNC) &R_g_log_writer_default, 4},
    {"R_g_log_writer_format_fields", (DL_FUNC) &R_g_log_writer_format_fields, 4},
    {"R_g_log_writer_is_journald", (DL_FUNC) &R_g_log_writer_is_journald, 1},
    {"R_g_log_writer_journald", (DL_FUNC) &R_g_log_writer_journald, 4},
    {"R_g_log_writer_standard_streams", (DL_FUNC) &R_g_log_writer_standard_streams, 4},
    {"R_g_log_writer_supports_color", (DL_FUNC) &R_g_log_writer_supports_color, 1},
    {"R_g_lstat", (DL_FUNC) &R_g_lstat, 2},
    {"R_g_main_current_source", (DL_FUNC) &R_g_main_current_source, 0},
    {"R_g_main_depth", (DL_FUNC) &R_g_main_depth, 0},
    {"R_g_malloc", (DL_FUNC) &R_g_malloc, 1},
    {"R_g_malloc0", (DL_FUNC) &R_g_malloc0, 1},
    {"R_g_malloc0_n", (DL_FUNC) &R_g_malloc0_n, 2},
    {"R_g_malloc_n", (DL_FUNC) &R_g_malloc_n, 2},
    {"R_g_markup_error_quark", (DL_FUNC) &R_g_markup_error_quark, 0},
    {"R_g_markup_escape_text", (DL_FUNC) &R_g_markup_escape_text, 2},
    {"R_g_mem_is_system_malloc", (DL_FUNC) &R_g_mem_is_system_malloc, 0},
    {"R_g_mem_profile", (DL_FUNC) &R_g_mem_profile, 0},
    {"R_g_mem_set_vtable", (DL_FUNC) &R_g_mem_set_vtable, 1},
    {"R_g_memdup", (DL_FUNC) &R_g_memdup, 2},
    {"R_g_mkdir", (DL_FUNC) &R_g_mkdir, 2},
    {"R_g_mkdir_with_parents", (DL_FUNC) &R_g_mkdir_with_parents, 2},
    {"R_g_nullify_pointer", (DL_FUNC) &R_g_nullify_pointer, 1},
    {"R_g_number_parser_error_quark", (DL_FUNC) &R_g_number_parser_error_quark, 0},
    {"R_g_on_error_query", (DL_FUNC) &R_g_on_error_query, 1},
    {"R_g_on_error_stack_trace", (DL_FUNC) &R_g_on_error_stack_trace, 1},
    {"R_g_open", (DL_FUNC) &R_g_open, 3},
    {"R_g_option_error_quark", (DL_FUNC) &R_g_option_error_quark, 0},
    {"R_g_parse_debug_string", (DL_FUNC) &R_g_parse_debug_string, 3},
    {"R_g_path_get_basename", (DL_FUNC) &R_g_path_get_basename, 1},
    {"R_g_path_get_dirname", (DL_FUNC) &R_g_path_get_dirname, 1},
    {"R_g_path_is_absolute", (DL_FUNC) &R_g_path_is_absolute, 1},
    {"R_g_path_skip_root", (DL_FUNC) &R_g_path_skip_root, 1},
    {"R_g_pattern_match_simple", (DL_FUNC) &R_g_pattern_match_simple, 2},
    {"R_g_poll", (DL_FUNC) &R_g_poll, 3},
    {"R_g_propagate_error", (DL_FUNC) &R_g_propagate_error, 1},
    {"R_g_qsort_with_data", (DL_FUNC) &R_g_qsort_with_data, 5},
    {"R_g_quark_from_static_string", (DL_FUNC) &R_g_quark_from_static_string, 1},
    {"R_g_quark_from_string", (DL_FUNC) &R_g_quark_from_string, 1},
    {"R_g_quark_to_string", (DL_FUNC) &R_g_quark_to_string, 1},
    {"R_g_quark_try_string", (DL_FUNC) &R_g_quark_try_string, 1},
    {"R_g_random_double", (DL_FUNC) &R_g_random_double, 0},
    {"R_g_random_double_range", (DL_FUNC) &R_g_random_double_range, 2},
    {"R_g_random_int", (DL_FUNC) &R_g_random_int, 0},
    {"R_g_random_int_range", (DL_FUNC) &R_g_random_int_range, 2},
    {"R_g_random_set_seed", (DL_FUNC) &R_g_random_set_seed, 1},
    {"R_g_realloc", (DL_FUNC) &R_g_realloc, 2},
    {"R_g_realloc_n", (DL_FUNC) &R_g_realloc_n, 3},
    {"R_g_reload_user_special_dirs_cache", (DL_FUNC) &R_g_reload_user_special_dirs_cache, 0},
    {"R_g_remove", (DL_FUNC) &R_g_remove, 1},
    {"R_g_rename", (DL_FUNC) &R_g_rename, 2},
    {"R_g_rmdir", (DL_FUNC) &R_g_rmdir, 1},
    {"R_g_set_application_name", (DL_FUNC) &R_g_set_application_name, 1},
    {"R_g_set_error_literal", (DL_FUNC) &R_g_set_error_literal, 3},
    {"R_g_set_prgname", (DL_FUNC) &R_g_set_prgname, 1},
    {"R_g_setenv", (DL_FUNC) &R_g_setenv, 3},
    {"R_g_shell_error_quark", (DL_FUNC) &R_g_shell_error_quark, 0},
    {"R_g_shell_parse_argv", (DL_FUNC) &R_g_shell_parse_argv, 1},
    {"R_g_shell_quote", (DL_FUNC) &R_g_shell_quote, 1},
    {"R_g_shell_unquote", (DL_FUNC) &R_g_shell_unquote, 1},
    {"R_g_slice_alloc", (DL_FUNC) &R_g_slice_alloc, 1},
    {"R_g_slice_alloc0", (DL_FUNC) &R_g_slice_alloc0, 1},
    {"R_g_slice_copy", (DL_FUNC) &R_g_slice_copy, 2},
    {"R_g_slice_free1", (DL_FUNC) &R_g_slice_free1, 2},
    {"R_g_slice_free_chain_with_offset", (DL_FUNC) &R_g_slice_free_chain_with_offset, 3},
    {"R_g_slice_get_config", (DL_FUNC) &R_g_slice_get_config, 1},
    {"R_g_slice_get_config_state", (DL_FUNC) &R_g_slice_get_config_state, 3},
    {"R_g_slice_set_config", (DL_FUNC) &R_g_slice_set_config, 2},
    {"R_g_spaced_primes_closest", (DL_FUNC) &R_g_spaced_primes_closest, 1},
    {"R_g_spawn_async", (DL_FUNC) &R_g_spawn_async, 6},
    {"R_g_spawn_async_with_pipes", (DL_FUNC) &R_g_spawn_async_with_pipes, 6},
    {"R_g_spawn_check_exit_status", (DL_FUNC) &R_g_spawn_check_exit_status, 1},
    {"R_g_spawn_close_pid", (DL_FUNC) &R_g_spawn_close_pid, 1},
    {"R_g_spawn_command_line_async", (DL_FUNC) &R_g_spawn_command_line_async, 1},
    {"R_g_spawn_command_line_sync", (DL_FUNC) &R_g_spawn_command_line_sync, 1},
    {"R_g_spawn_error_quark", (DL_FUNC) &R_g_spawn_error_quark, 0},
    {"R_g_spawn_exit_error_quark", (DL_FUNC) &R_g_spawn_exit_error_quark, 0},
    {"R_g_spawn_sync", (DL_FUNC) &R_g_spawn_sync, 6},
    {"R_g_stat", (DL_FUNC) &R_g_stat, 2},
    {"R_g_stpcpy", (DL_FUNC) &R_g_stpcpy, 2},
    {"R_g_str_equal", (DL_FUNC) &R_g_str_equal, 2},
    {"R_g_str_has_prefix", (DL_FUNC) &R_g_str_has_prefix, 2},
    {"R_g_str_has_suffix", (DL_FUNC) &R_g_str_has_suffix, 2},
    {"R_g_str_hash", (DL_FUNC) &R_g_str_hash, 1},
    {"R_g_str_is_ascii", (DL_FUNC) &R_g_str_is_ascii, 1},
    {"R_g_str_match_string", (DL_FUNC) &R_g_str_match_string, 3},
    {"R_g_str_to_ascii", (DL_FUNC) &R_g_str_to_ascii, 2},
    {"R_g_str_tokenize_and_fold", (DL_FUNC) &R_g_str_tokenize_and_fold, 2},
    {"R_g_strcanon", (DL_FUNC) &R_g_strcanon, 3},
    {"R_g_strcasecmp", (DL_FUNC) &R_g_strcasecmp, 2},
    {"R_g_strchomp", (DL_FUNC) &R_g_strchomp, 1},
    {"R_g_strchug", (DL_FUNC) &R_g_strchug, 1},
    {"R_g_strcmp0", (DL_FUNC) &R_g_strcmp0, 2},
    {"R_g_strcompress", (DL_FUNC) &R_g_strcompress, 1},
    {"R_g_strdelimit", (DL_FUNC) &R_g_strdelimit, 3},
    {"R_g_strdown", (DL_FUNC) &R_g_strdown, 1},
    {"R_g_strdup", (DL_FUNC) &R_g_strdup, 1},
    {"R_g_strdupv", (DL_FUNC) &R_g_strdupv, 1},
    {"R_g_strerror", (DL_FUNC) &R_g_strerror, 1},
    {"R_g_strescape", (DL_FUNC) &R_g_strescape, 2},
    {"R_g_strfreev", (DL_FUNC) &R_g_strfreev, 1},
    {"R_g_strip_context", (DL_FUNC) &R_g_strip_context, 2},
    {"R_g_strjoinv", (DL_FUNC) &R_g_strjoinv, 2},
    {"R_g_strlcat", (DL_FUNC) &R_g_strlcat, 3},
    {"R_g_strlcpy", (DL_FUNC) &R_g_strlcpy, 3},
    {"R_g_strncasecmp", (DL_FUNC) &R_g_strncasecmp, 3},
    {"R_g_strndup", (DL_FUNC) &R_g_strndup, 2},
    {"R_g_strnfill", (DL_FUNC) &R_g_strnfill, 2},
    {"R_g_strreverse", (DL_FUNC) &R_g_strreverse, 1},
    {"R_g_strrstr", (DL_FUNC) &R_g_strrstr, 2},
    {"R_g_strrstr_len", (DL_FUNC) &R_g_strrstr_len, 3},
    {"R_g_strsignal", (DL_FUNC) &R_g_strsignal, 1},
    {"R_g_strsplit", (DL_FUNC) &R_g_strsplit, 3},
    {"R_g_strsplit_set", (DL_FUNC) &R_g_strsplit_set, 3},
    {"R_g_strstr_len", (DL_FUNC) &R_g_strstr_len, 3},
    {"R_g_strtod", (DL_FUNC) &R_g_strtod, 1},
    {"R_g_strup", (DL_FUNC) &R_g_strup, 1},
    {"R_g_strv_contains", (DL_FUNC) &R_g_strv_contains, 2},
    {"R_g_strv_get_type", (DL_FUNC) &R_g_strv_get_type, 0},
    {"R_g_strv_length", (DL_FUNC) &R_g_strv_length, 1},
    {"R_g_test_add_data_func", (DL_FUNC) &R_g_test_add_data_func, 3},
    {"R_g_test_add_data_func_full", (DL_FUNC) &R_g_test_add_data_func_full, 4},
    {"R_g_test_add_func", (DL_FUNC) &R_g_test_add_func, 2},
    {"R_g_test_assert_expected_messages_internal", (DL_FUNC) &R_g_test_assert_expected_messages_internal, 4},
    {"R_g_test_bug", (DL_FUNC) &R_g_test_bug, 1},
    {"R_g_test_bug_base", (DL_FUNC) &R_g_test_bug_base, 1},
    {"R_g_test_expect_message", (DL_FUNC) &R_g_test_expect_message, 3},
    {"R_g_test_fail", (DL_FUNC) &R_g_test_fail, 0},
    {"R_g_test_failed", (DL_FUNC) &R_g_test_failed, 0},
    {"R_g_test_get_dir", (DL_FUNC) &R_g_test_get_dir, 1},
    {"R_g_test_incomplete", (DL_FUNC) &R_g_test_incomplete, 1},
    {"R_g_test_log_type_name", (DL_FUNC) &R_g_test_log_type_name, 1},
    {"R_g_test_queue_destroy", (DL_FUNC) &R_g_test_queue_destroy, 2},
    {"R_g_test_queue_free", (DL_FUNC) &R_g_test_queue_free, 1},
    {"R_g_test_rand_double", (DL_FUNC) &R_g_test_rand_double, 0},
    {"R_g_test_rand_double_range", (DL_FUNC) &R_g_test_rand_double_range, 2},
    {"R_g_test_rand_int", (DL_FUNC) &R_g_test_rand_int, 0},
    {"R_g_test_rand_int_range", (DL_FUNC) &R_g_test_rand_int_range, 2},
    {"R_g_test_run", (DL_FUNC) &R_g_test_run, 0},
    {"R_g_test_run_suite", (DL_FUNC) &R_g_test_run_suite, 1},
    {"R_g_test_set_nonfatal_assertions", (DL_FUNC) &R_g_test_set_nonfatal_assertions, 0},
    {"R_g_test_skip", (DL_FUNC) &R_g_test_skip, 1},
    {"R_g_test_subprocess", (DL_FUNC) &R_g_test_subprocess, 0},
    {"R_g_test_timer_elapsed", (DL_FUNC) &R_g_test_timer_elapsed, 0},
    {"R_g_test_timer_last", (DL_FUNC) &R_g_test_timer_last, 0},
    {"R_g_test_timer_start", (DL_FUNC) &R_g_test_timer_start, 0},
    {"R_g_test_trap_assertions", (DL_FUNC) &R_g_test_trap_assertions, 6},
    {"R_g_test_trap_fork", (DL_FUNC) &R_g_test_trap_fork, 2},
    {"R_g_test_trap_has_passed", (DL_FUNC) &R_g_test_trap_has_passed, 0},
    {"R_g_test_trap_reached_timeout", (DL_FUNC) &R_g_test_trap_reached_timeout, 0},
    {"R_g_test_trap_subprocess", (DL_FUNC) &R_g_test_trap_subprocess, 3},
    {"R_g_timeout_add_full", (DL_FUNC) &R_g_timeout_add_full, 5},
    {"R_g_timeout_add_seconds_full", (DL_FUNC) &R_g_timeout_add_seconds_full, 5},
    {"R_g_timeout_source_new", (DL_FUNC) &R_g_timeout_source_new, 1},
    {"R_g_timeout_source_new_seconds", (DL_FUNC) &R_g_timeout_source_new_seconds, 1},
    {"R_g_try_malloc", (DL_FUNC) &R_g_try_malloc, 1},
    {"R_g_try_malloc0", (DL_FUNC) &R_g_try_malloc0, 1},
    {"R_g_try_malloc0_n", (DL_FUNC) &R_g_try_malloc0_n, 2},
    {"R_g_try_malloc_n", (DL_FUNC) &R_g_try_malloc_n, 2},
    {"R_g_try_realloc", (DL_FUNC) &R_g_try_realloc, 2},
    {"R_g_try_realloc_n", (DL_FUNC) &R_g_try_realloc_n, 3},
    {"R_g_ucs4_to_utf16", (DL_FUNC) &R_g_ucs4_to_utf16, 2},
    {"R_g_ucs4_to_utf8", (DL_FUNC) &R_g_ucs4_to_utf8, 2},
    {"R_g_unichar_break_type", (DL_FUNC) &R_g_unichar_break_type, 1},
    {"R_g_unichar_combining_class", (DL_FUNC) &R_g_unichar_combining_class, 1},
    {"R_g_unichar_compose", (DL_FUNC) &R_g_unichar_compose, 2},
    {"R_g_unichar_decompose", (DL_FUNC) &R_g_unichar_decompose, 1},
    {"R_g_unichar_digit_value", (DL_FUNC) &R_g_unichar_digit_value, 1},
    {"R_g_unichar_fully_decompose", (DL_FUNC) &R_g_unichar_fully_decompose, 3},
    {"R_g_unichar_get_mirror_char", (DL_FUNC) &R_g_unichar_get_mirror_char, 1},
    {"R_g_unichar_get_script", (DL_FUNC) &R_g_unichar_get_script, 1},
    {"R_g_unichar_isalnum", (DL_FUNC) &R_g_unichar_isalnum, 1},
    {"R_g_unichar_isalpha", (DL_FUNC) &R_g_unichar_isalpha, 1},
    {"R_g_unichar_iscntrl", (DL_FUNC) &R_g_unichar_iscntrl, 1},
    {"R_g_unichar_isdefined", (DL_FUNC) &R_g_unichar_isdefined, 1},
    {"R_g_unichar_isdigit", (DL_FUNC) &R_g_unichar_isdigit, 1},
    {"R_g_unichar_isgraph", (DL_FUNC) &R_g_unichar_isgraph, 1},
    {"R_g_unichar_islower", (DL_FUNC) &R_g_unichar_islower, 1},
    {"R_g_unichar_ismark", (DL_FUNC) &R_g_unichar_ismark, 1},
    {"R_g_unichar_isprint", (DL_FUNC) &R_g_unichar_isprint, 1},
    {"R_g_unichar_ispunct", (DL_FUNC) &R_g_unichar_ispunct, 1},
    {"R_g_unichar_isspace", (DL_FUNC) &R_g_unichar_isspace, 1},
    {"R_g_unichar_istitle", (DL_FUNC) &R_g_unichar_istitle, 1},
    {"R_g_unichar_isupper", (DL_FUNC) &R_g_unichar_isupper, 1},
    {"R_g_unichar_iswide", (DL_FUNC) &R_g_unichar_iswide, 1},
    {"R_g_unichar_iswide_cjk", (DL_FUNC) &R_g_unichar_iswide_cjk, 1},
    {"R_g_unichar_isxdigit", (DL_FUNC) &R_g_unichar_isxdigit, 1},
    {"R_g_unichar_iszerowidth", (DL_FUNC) &R_g_unichar_iszerowidth, 1},
    {"R_g_unichar_to_utf8", (DL_FUNC) &R_g_unichar_to_utf8, 1},
    {"R_g_unichar_tolower", (DL_FUNC) &R_g_unichar_tolower, 1},
    {"R_g_unichar_totitle", (DL_FUNC) &R_g_unichar_totitle, 1},
    {"R_g_unichar_toupper", (DL_FUNC) &R_g_unichar_toupper, 1},
    {"R_g_unichar_type", (DL_FUNC) &R_g_unichar_type, 1},
    {"R_g_unichar_validate", (DL_FUNC) &R_g_unichar_validate, 1},
    {"R_g_unichar_xdigit_value", (DL_FUNC) &R_g_unichar_xdigit_value, 1},
    {"R_g_unicode_canonical_decomposition", (DL_FUNC) &R_g_unicode_canonical_decomposition, 2},
    {"R_g_unicode_canonical_ordering", (DL_FUNC) &R_g_unicode_canonical_ordering, 2},
    {"R_g_unlink", (DL_FUNC) &R_g_unlink, 1},
    {"R_g_unsetenv", (DL_FUNC) &R_g_unsetenv, 1},
    {"R_g_usleep", (DL_FUNC) &R_g_usleep, 1},
    {"R_g_utf16_to_ucs4", (DL_FUNC) &R_g_utf16_to_ucs4, 2},
    {"R_g_utf16_to_utf8", (DL_FUNC) &R_g_utf16_to_utf8, 2},
    {"R_g_utf8_casefold", (DL_FUNC) &R_g_utf8_casefold, 2},
    {"R_g_utf8_collate", (DL_FUNC) &R_g_utf8_collate, 2},
    {"R_g_utf8_collate_key", (DL_FUNC) &R_g_utf8_collate_key, 2},
    {"R_g_utf8_collate_key_for_filename", (DL_FUNC) &R_g_utf8_collate_key_for_filename, 2},
    {"R_g_utf8_find_next_char", (DL_FUNC) &R_g_utf8_find_next_char, 2},
    {"R_g_utf8_find_prev_char", (DL_FUNC) &R_g_utf8_find_prev_char, 2},
    {"R_g_utf8_get_char", (DL_FUNC) &R_g_utf8_get_char, 1},
    {"R_g_utf8_get_char_validated", (DL_FUNC) &R_g_utf8_get_char_validated, 2},
    {"R_g_utf8_make_valid", (DL_FUNC) &R_g_utf8_make_valid, 2},
    {"R_g_utf8_normalize", (DL_FUNC) &R_g_utf8_normalize, 3},
    {"R_g_utf8_offset_to_pointer", (DL_FUNC) &R_g_utf8_offset_to_pointer, 2},
    {"R_g_utf8_pointer_to_offset", (DL_FUNC) &R_g_utf8_pointer_to_offset, 2},
    {"R_g_utf8_prev_char", (DL_FUNC) &R_g_utf8_prev_char, 1},
    {"R_g_utf8_strchr", (DL_FUNC) &R_g_utf8_strchr, 3},
    {"R_g_utf8_strdown", (DL_FUNC) &R_g_utf8_strdown, 2},
    {"R_g_utf8_strlen", (DL_FUNC) &R_g_utf8_strlen, 2},
    {"R_g_utf8_strncpy", (DL_FUNC) &R_g_utf8_strncpy, 3},
    {"R_g_utf8_strrchr", (DL_FUNC) &R_g_utf8_strrchr, 3},
    {"R_g_utf8_strreverse", (DL_FUNC) &R_g_utf8_strreverse, 2},
    {"R_g_utf8_strup", (DL_FUNC) &R_g_utf8_strup, 2},
    {"R_g_utf8_substring", (DL_FUNC) &R_g_utf8_substring, 3},
    {"R_g_utf8_to_ucs4", (DL_FUNC) &R_g_utf8_to_ucs4, 2},
    {"R_g_utf8_to_ucs4_fast", (DL_FUNC) &R_g_utf8_to_ucs4_fast, 2},
    {"R_g_utf8_to_utf16", (DL_FUNC) &R_g_utf8_to_utf16, 2},
    {"R_g_utf8_validate", (DL_FUNC) &R_g_utf8_validate, 2},
    {"R_g_utime", (DL_FUNC) &R_g_utime, 2},
    {"R_g_uuid_string_is_valid", (DL_FUNC) &R_g_uuid_string_is_valid, 1},
    {"R_g_uuid_string_random", (DL_FUNC) &R_g_uuid_string_random, 0},
    {"R_g_variant_get_gtype", (DL_FUNC) &R_g_variant_get_gtype, 0},
    {"R_g_binding_get_flags", (DL_FUNC) &R_g_binding_get_flags, 1},
    {"R_g_binding_get_source", (DL_FUNC) &R_g_binding_get_source, 1},
    {"R_g_binding_get_source_property", (DL_FUNC) &R_g_binding_get_source_property, 1},
    {"R_g_binding_get_target", (DL_FUNC) &R_g_binding_get_target, 1},
    {"R_g_binding_get_target_property", (DL_FUNC) &R_g_binding_get_target_property, 1},
    {"R_g_binding_unbind", (DL_FUNC) &R_g_binding_unbind, 1},
    {"R_g_cclosure_marshal_BOOLEAN__BOXED_BOXED", (DL_FUNC) &R_g_cclosure_marshal_BOOLEAN__BOXED_BOXED, 6},
    {"R_g_cclosure_marshal_BOOLEAN__FLAGS", (DL_FUNC) &R_g_cclosure_marshal_BOOLEAN__FLAGS, 6},
    {"R_g_cclosure_marshal_STRING__OBJECT_POINTER", (DL_FUNC) &R_g_cclosure_marshal_STRING__OBJECT_POINTER, 6},
    {"R_g_cclosure_marshal_VOID__BOOLEAN", (DL_FUNC) &R_g_cclosure_marshal_VOID__BOOLEAN, 6},
    {"R_g_cclosure_marshal_VOID__BOXED", (DL_FUNC) &R_g_cclosure_marshal_VOID__BOXED, 6},
    {"R_g_cclosure_marshal_VOID__CHAR", (DL_FUNC) &R_g_cclosure_marshal_VOID__CHAR, 6},
    {"R_g_cclosure_marshal_VOID__DOUBLE", (DL_FUNC) &R_g_cclosure_marshal_VOID__DOUBLE, 6},
    {"R_g_cclosure_marshal_VOID__ENUM", (DL_FUNC) &R_g_cclosure_marshal_VOID__ENUM, 6},
    {"R_g_cclosure_marshal_VOID__FLAGS", (DL_FUNC) &R_g_cclosure_marshal_VOID__FLAGS, 6},
    {"R_g_cclosure_marshal_VOID__FLOAT", (DL_FUNC) &R_g_cclosure_marshal_VOID__FLOAT, 6},
    {"R_g_cclosure_marshal_VOID__INT", (DL_FUNC) &R_g_cclosure_marshal_VOID__INT, 6},
    {"R_g_cclosure_marshal_VOID__LONG", (DL_FUNC) &R_g_cclosure_marshal_VOID__LONG, 6},
    {"R_g_cclosure_marshal_VOID__OBJECT", (DL_FUNC) &R_g_cclosure_marshal_VOID__OBJECT, 6},
    {"R_g_cclosure_marshal_VOID__PARAM", (DL_FUNC) &R_g_cclosure_marshal_VOID__PARAM, 6},
    {"R_g_cclosure_marshal_VOID__POINTER", (DL_FUNC) &R_g_cclosure_marshal_VOID__POINTER, 6},
    {"R_g_cclosure_marshal_VOID__STRING", (DL_FUNC) &R_g_cclosure_marshal_VOID__STRING, 6},
    {"R_g_cclosure_marshal_VOID__UCHAR", (DL_FUNC) &R_g_cclosure_marshal_VOID__UCHAR, 6},
    {"R_g_cclosure_marshal_VOID__UINT", (DL_FUNC) &R_g_cclosure_marshal_VOID__UINT, 6},
    {"R_g_cclosure_marshal_VOID__UINT_POINTER", (DL_FUNC) &R_g_cclosure_marshal_VOID__UINT_POINTER, 6},
    {"R_g_cclosure_marshal_VOID__ULONG", (DL_FUNC) &R_g_cclosure_marshal_VOID__ULONG, 6},
    {"R_g_cclosure_marshal_VOID__VARIANT", (DL_FUNC) &R_g_cclosure_marshal_VOID__VARIANT, 6},
    {"R_g_cclosure_marshal_VOID__VOID", (DL_FUNC) &R_g_cclosure_marshal_VOID__VOID, 6},
    {"R_g_cclosure_marshal_generic", (DL_FUNC) &R_g_cclosure_marshal_generic, 6},
    {"R_g_closure_new_object", (DL_FUNC) &R_g_closure_new_object, 2},
    {"R_g_closure_new_simple", (DL_FUNC) &R_g_closure_new_simple, 2},
    {"R_g_closure_invalidate", (DL_FUNC) &R_g_closure_invalidate, 1},
    {"R_g_closure_invoke", (DL_FUNC) &R_g_closure_invoke, 4},
    {"R_g_closure_ref", (DL_FUNC) &R_g_closure_ref, 1},
    {"R_g_closure_sink", (DL_FUNC) &R_g_closure_sink, 1},
    {"R_g_closure_unref", (DL_FUNC) &R_g_closure_unref, 1},
    {"R_g_object_newv", (DL_FUNC) &R_g_object_newv, 3},
    {"R_g_object_compat_control", (DL_FUNC) &R_g_object_compat_control, 2},
    {"R_g_object_interface_find_property", (DL_FUNC) &R_g_object_interface_find_property, 2},
    {"R_g_object_interface_install_property", (DL_FUNC) &R_g_object_interface_install_property, 2},
    {"R_g_object_interface_list_properties", (DL_FUNC) &R_g_object_interface_list_properties, 1},
    {"R_g_object_bind_property", (DL_FUNC) &R_g_object_bind_property, 5},
    {"R_g_object_bind_property_full", (DL_FUNC) &R_g_object_bind_property_full, 9},
    {"R_g_object_bind_property_with_closures", (DL_FUNC) &R_g_object_bind_property_with_closures, 7},
    {"R_g_object_force_floating", (DL_FUNC) &R_g_object_force_floating, 1},
    {"R_g_object_freeze_notify", (DL_FUNC) &R_g_object_freeze_notify, 1},
    {"R_g_object_get_data", (DL_FUNC) &R_g_object_get_data, 2},
    {"R_g_object_get_property", (DL_FUNC) &R_g_object_get_property, 3},
    {"R_g_object_get_qdata", (DL_FUNC) &R_g_object_get_qdata, 2},
    {"R_g_object_getv", (DL_FUNC) &R_g_object_getv, 4},
    {"R_g_object_is_floating", (DL_FUNC) &R_g_object_is_floating, 1},
    {"R_g_object_notify", (DL_FUNC) &R_g_object_notify, 2},
    {"R_g_object_notify_by_pspec", (DL_FUNC) &R_g_object_notify_by_pspec, 2},
    {"R_g_object_ref", (DL_FUNC) &R_g_object_ref, 1},
    {"R_g_object_ref_sink", (DL_FUNC) &R_g_object_ref_sink, 1},
    {"R_g_object_run_dispose", (DL_FUNC) &R_g_object_run_dispose, 1},
    {"R_g_object_set_data", (DL_FUNC) &R_g_object_set_data, 3},
    {"R_g_object_set_property", (DL_FUNC) &R_g_object_set_property, 3},
    {"R_g_object_steal_data", (DL_FUNC) &R_g_object_steal_data, 2},
    {"R_g_object_steal_qdata", (DL_FUNC) &R_g_object_steal_qdata, 2},
    {"R_g_object_thaw_notify", (DL_FUNC) &R_g_object_thaw_notify, 1},
    {"R_g_object_unref", (DL_FUNC) &R_g_object_unref, 1},
    {"R_g_object_watch_closure", (DL_FUNC) &R_g_object_watch_closure, 2},
    {"R_g_object_class_find_property", (DL_FUNC) &R_g_object_class_find_property, 2},
    {"R_g_object_class_install_properties", (DL_FUNC) &R_g_object_class_install_properties, 3},
    {"R_g_object_class_install_property", (DL_FUNC) &R_g_object_class_install_property, 3},
    {"R_g_object_class_list_properties", (DL_FUNC) &R_g_object_class_list_properties, 1},
    {"R_g_object_class_override_property", (DL_FUNC) &R_g_object_class_override_property, 3},
    {"R_g_param_spec_get_blurb", (DL_FUNC) &R_g_param_spec_get_blurb, 1},
    {"R_g_param_spec_get_default_value", (DL_FUNC) &R_g_param_spec_get_default_value, 1},
    {"R_g_param_spec_get_name", (DL_FUNC) &R_g_param_spec_get_name, 1},
    {"R_g_param_spec_get_name_quark", (DL_FUNC) &R_g_param_spec_get_name_quark, 1},
    {"R_g_param_spec_get_nick", (DL_FUNC) &R_g_param_spec_get_nick, 1},
    {"R_g_param_spec_get_qdata", (DL_FUNC) &R_g_param_spec_get_qdata, 2},
    {"R_g_param_spec_get_redirect_target", (DL_FUNC) &R_g_param_spec_get_redirect_target, 1},
    {"R_g_param_spec_set_qdata", (DL_FUNC) &R_g_param_spec_set_qdata, 3},
    {"R_g_param_spec_sink", (DL_FUNC) &R_g_param_spec_sink, 1},
    {"R_g_param_spec_steal_qdata", (DL_FUNC) &R_g_param_spec_steal_qdata, 2},
    {"R_g_param_spec_pool_insert", (DL_FUNC) &R_g_param_spec_pool_insert, 3},
    {"R_g_param_spec_pool_list", (DL_FUNC) &R_g_param_spec_pool_list, 2},
    {"R_g_param_spec_pool_list_owned", (DL_FUNC) &R_g_param_spec_pool_list_owned, 2},
    {"R_g_param_spec_pool_lookup", (DL_FUNC) &R_g_param_spec_pool_lookup, 4},
    {"R_g_param_spec_pool_remove", (DL_FUNC) &R_g_param_spec_pool_remove, 2},
    {"R_g_source_set_closure", (DL_FUNC) &R_g_source_set_closure, 2},
    {"R_g_source_set_dummy_callback", (DL_FUNC) &R_g_source_set_dummy_callback, 1},
    {"R_g_type_class_add_private", (DL_FUNC) &R_g_type_class_add_private, 2},
    {"R_g_type_class_get_private", (DL_FUNC) &R_g_type_class_get_private, 2},
    {"R_g_type_class_peek_parent", (DL_FUNC) &R_g_type_class_peek_parent, 1},
    {"R_g_type_class_unref", (DL_FUNC) &R_g_type_class_unref, 1},
    {"R_g_type_class_adjust_private_offset", (DL_FUNC) &R_g_type_class_adjust_private_offset, 2},
    {"R_g_type_class_peek", (DL_FUNC) &R_g_type_class_peek, 1},
    {"R_g_type_class_peek_static", (DL_FUNC) &R_g_type_class_peek_static, 1},
    {"R_g_type_class_ref", (DL_FUNC) &R_g_type_class_ref, 1},
    {"R_g_type_instance_get_private", (DL_FUNC) &R_g_type_instance_get_private, 2},
    {"R_g_type_interface_peek_parent", (DL_FUNC) &R_g_type_interface_peek_parent, 1},
    {"R_g_type_interface_add_prerequisite", (DL_FUNC) &R_g_type_interface_add_prerequisite, 2},
    {"R_g_type_interface_get_plugin", (DL_FUNC) &R_g_type_interface_get_plugin, 2},
    {"R_g_type_interface_peek", (DL_FUNC) &R_g_type_interface_peek, 2},
    {"R_g_type_interface_prerequisites", (DL_FUNC) &R_g_type_interface_prerequisites, 1},
    {"R_g_type_module_add_interface", (DL_FUNC) &R_g_type_module_add_interface, 4},
    {"R_g_type_module_register_enum", (DL_FUNC) &R_g_type_module_register_enum, 3},
    {"R_g_type_module_register_flags", (DL_FUNC) &R_g_type_module_register_flags, 3},
    {"R_g_type_module_register_type", (DL_FUNC) &R_g_type_module_register_type, 5},
    {"R_g_type_module_set_name", (DL_FUNC) &R_g_type_module_set_name, 2},
    {"R_g_type_module_unuse", (DL_FUNC) &R_g_type_module_unuse, 1},
    {"R_g_type_module_use", (DL_FUNC) &R_g_type_module_use, 1},
    {"R_g_type_plugin_complete_interface_info", (DL_FUNC) &R_g_type_plugin_complete_interface_info, 4},
    {"R_g_type_plugin_complete_type_info", (DL_FUNC) &R_g_type_plugin_complete_type_info, 4},
    {"R_g_type_plugin_unuse", (DL_FUNC) &R_g_type_plugin_unuse, 1},
    {"R_g_type_plugin_use", (DL_FUNC) &R_g_type_plugin_use, 1},
    {"R_g_value_copy", (DL_FUNC) &R_g_value_copy, 2},
    {"R_g_value_dup_object", (DL_FUNC) &R_g_value_dup_object, 1},
    {"R_g_value_dup_string", (DL_FUNC) &R_g_value_dup_string, 1},
    {"R_g_value_dup_variant", (DL_FUNC) &R_g_value_dup_variant, 1},
    {"R_g_value_fits_pointer", (DL_FUNC) &R_g_value_fits_pointer, 1},
    {"R_g_value_get_boolean", (DL_FUNC) &R_g_value_get_boolean, 1},
    {"R_g_value_get_boxed", (DL_FUNC) &R_g_value_get_boxed, 1},
    {"R_g_value_get_char", (DL_FUNC) &R_g_value_get_char, 1},
    {"R_g_value_get_double", (DL_FUNC) &R_g_value_get_double, 1},
    {"R_g_value_get_enum", (DL_FUNC) &R_g_value_get_enum, 1},
    {"R_g_value_get_flags", (DL_FUNC) &R_g_value_get_flags, 1},
    {"R_g_value_get_float", (DL_FUNC) &R_g_value_get_float, 1},
    {"R_g_value_get_gtype", (DL_FUNC) &R_g_value_get_gtype, 1},
    {"R_g_value_get_int", (DL_FUNC) &R_g_value_get_int, 1},
    {"R_g_value_get_int64", (DL_FUNC) &R_g_value_get_int64, 1},
    {"R_g_value_get_long", (DL_FUNC) &R_g_value_get_long, 1},
    {"R_g_value_get_object", (DL_FUNC) &R_g_value_get_object, 1},
    {"R_g_value_get_param", (DL_FUNC) &R_g_value_get_param, 1},
    {"R_g_value_get_pointer", (DL_FUNC) &R_g_value_get_pointer, 1},
    {"R_g_value_get_schar", (DL_FUNC) &R_g_value_get_schar, 1},
    {"R_g_value_get_string", (DL_FUNC) &R_g_value_get_string, 1},
    {"R_g_value_get_uchar", (DL_FUNC) &R_g_value_get_uchar, 1},
    {"R_g_value_get_uint", (DL_FUNC) &R_g_value_get_uint, 1},
    {"R_g_value_get_uint64", (DL_FUNC) &R_g_value_get_uint64, 1},
    {"R_g_value_get_ulong", (DL_FUNC) &R_g_value_get_ulong, 1},
    {"R_g_value_get_variant", (DL_FUNC) &R_g_value_get_variant, 1},
    {"R_g_value_init", (DL_FUNC) &R_g_value_init, 2},
    {"R_g_value_init_from_instance", (DL_FUNC) &R_g_value_init_from_instance, 2},
    {"R_g_value_peek_pointer", (DL_FUNC) &R_g_value_peek_pointer, 1},
    {"R_g_value_reset", (DL_FUNC) &R_g_value_reset, 1},
    {"R_g_value_set_boolean", (DL_FUNC) &R_g_value_set_boolean, 2},
    {"R_g_value_set_boxed", (DL_FUNC) &R_g_value_set_boxed, 2},
    {"R_g_value_set_boxed_take_ownership", (DL_FUNC) &R_g_value_set_boxed_take_ownership, 2},
    {"R_g_value_set_char", (DL_FUNC) &R_g_value_set_char, 2},
    {"R_g_value_set_double", (DL_FUNC) &R_g_value_set_double, 2},
    {"R_g_value_set_enum", (DL_FUNC) &R_g_value_set_enum, 2},
    {"R_g_value_set_flags", (DL_FUNC) &R_g_value_set_flags, 2},
    {"R_g_value_set_float", (DL_FUNC) &R_g_value_set_float, 2},
    {"R_g_value_set_gtype", (DL_FUNC) &R_g_value_set_gtype, 2},
    {"R_g_value_set_instance", (DL_FUNC) &R_g_value_set_instance, 2},
    {"R_g_value_set_int", (DL_FUNC) &R_g_value_set_int, 2},
    {"R_g_value_set_int64", (DL_FUNC) &R_g_value_set_int64, 2},
    {"R_g_value_set_long", (DL_FUNC) &R_g_value_set_long, 2},
    {"R_g_value_set_object", (DL_FUNC) &R_g_value_set_object, 2},
    {"R_g_value_set_param", (DL_FUNC) &R_g_value_set_param, 2},
    {"R_g_value_set_pointer", (DL_FUNC) &R_g_value_set_pointer, 2},
    {"R_g_value_set_schar", (DL_FUNC) &R_g_value_set_schar, 2},
    {"R_g_value_set_static_boxed", (DL_FUNC) &R_g_value_set_static_boxed, 2},
    {"R_g_value_set_static_string", (DL_FUNC) &R_g_value_set_static_string, 2},
    {"R_g_value_set_string", (DL_FUNC) &R_g_value_set_string, 2},
    {"R_g_value_set_string_take_ownership", (DL_FUNC) &R_g_value_set_string_take_ownership, 2},
    {"R_g_value_set_uchar", (DL_FUNC) &R_g_value_set_uchar, 2},
    {"R_g_value_set_uint", (DL_FUNC) &R_g_value_set_uint, 2},
    {"R_g_value_set_uint64", (DL_FUNC) &R_g_value_set_uint64, 2},
    {"R_g_value_set_ulong", (DL_FUNC) &R_g_value_set_ulong, 2},
    {"R_g_value_set_variant", (DL_FUNC) &R_g_value_set_variant, 2},
    {"R_g_value_take_boxed", (DL_FUNC) &R_g_value_take_boxed, 2},
    {"R_g_value_take_string", (DL_FUNC) &R_g_value_take_string, 2},
    {"R_g_value_take_variant", (DL_FUNC) &R_g_value_take_variant, 2},
    {"R_g_value_transform", (DL_FUNC) &R_g_value_transform, 2},
    {"R_g_value_unset", (DL_FUNC) &R_g_value_unset, 1},
    {"R_g_value_type_compatible", (DL_FUNC) &R_g_value_type_compatible, 2},
    {"R_g_value_type_transformable", (DL_FUNC) &R_g_value_type_transformable, 2},
    {"R_g_value_array_new", (DL_FUNC) &R_g_value_array_new, 1},
    {"R_g_value_array_append", (DL_FUNC) &R_g_value_array_append, 2},
    {"R_g_value_array_copy", (DL_FUNC) &R_g_value_array_copy, 1},
    {"R_g_value_array_get_nth", (DL_FUNC) &R_g_value_array_get_nth, 2},
    {"R_g_value_array_insert", (DL_FUNC) &R_g_value_array_insert, 3},
    {"R_g_value_array_prepend", (DL_FUNC) &R_g_value_array_prepend, 2},
    {"R_g_value_array_remove", (DL_FUNC) &R_g_value_array_remove, 2},
    {"R_g_value_array_sort", (DL_FUNC) &R_g_value_array_sort, 2},
    {"R_g_value_array_sort_with_data", (DL_FUNC) &R_g_value_array_sort_with_data, 3},
    {"R_g_boxed_copy", (DL_FUNC) &R_g_boxed_copy, 2},
    {"R_g_boxed_free", (DL_FUNC) &R_g_boxed_free, 2},
    {"R_g_boxed_type_register_static", (DL_FUNC) &R_g_boxed_type_register_static, 3},
    {"R_g_enum_complete_type_info", (DL_FUNC) &R_g_enum_complete_type_info, 2},
    {"R_g_enum_get_value", (DL_FUNC) &R_g_enum_get_value, 2},
    {"R_g_enum_get_value_by_name", (DL_FUNC) &R_g_enum_get_value_by_name, 2},
    {"R_g_enum_get_value_by_nick", (DL_FUNC) &R_g_enum_get_value_by_nick, 2},
    {"R_g_enum_register_static", (DL_FUNC) &R_g_enum_register_static, 2},
    {"R_g_enum_to_string", (DL_FUNC) &R_g_enum_to_string, 2},
    {"R_g_flags_complete_type_info", (DL_FUNC) &R_g_flags_complete_type_info, 2},
    {"R_g_flags_get_first_value", (DL_FUNC) &R_g_flags_get_first_value, 2},
    {"R_g_flags_get_value_by_name", (DL_FUNC) &R_g_flags_get_value_by_name, 2},
    {"R_g_flags_get_value_by_nick", (DL_FUNC) &R_g_flags_get_value_by_nick, 2},
    {"R_g_flags_register_static", (DL_FUNC) &R_g_flags_register_static, 2},
    {"R_g_flags_to_string", (DL_FUNC) &R_g_flags_to_string, 2},
    {"R_g_gtype_get_type", (DL_FUNC) &R_g_gtype_get_type, 0},
    {"R_g_param_spec_boolean", (DL_FUNC) &R_g_param_spec_boolean, 5},
    {"R_g_param_spec_boxed", (DL_FUNC) &R_g_param_spec_boxed, 5},
    {"R_g_param_spec_char", (DL_FUNC) &R_g_param_spec_char, 7},
    {"R_g_param_spec_double", (DL_FUNC) &R_g_param_spec_double, 7},
    {"R_g_param_spec_enum", (DL_FUNC) &R_g_param_spec_enum, 6},
    {"R_g_param_spec_flags", (DL_FUNC) &R_g_param_spec_flags, 6},
    {"R_g_param_spec_float", (DL_FUNC) &R_g_param_spec_float, 7},
    {"R_g_param_spec_gtype", (DL_FUNC) &R_g_param_spec_gtype, 5},
    {"R_g_param_spec_int", (DL_FUNC) &R_g_param_spec_int, 7},
    {"R_g_param_spec_int64", (DL_FUNC) &R_g_param_spec_int64, 7},
    {"R_g_param_spec_long", (DL_FUNC) &R_g_param_spec_long, 7},
    {"R_g_param_spec_object", (DL_FUNC) &R_g_param_spec_object, 5},
    {"R_g_param_spec_param", (DL_FUNC) &R_g_param_spec_param, 5},
    {"R_g_param_spec_pointer", (DL_FUNC) &R_g_param_spec_pointer, 4},
    {"R_g_param_spec_string", (DL_FUNC) &R_g_param_spec_string, 5},
    {"R_g_param_spec_uchar", (DL_FUNC) &R_g_param_spec_uchar, 7},
    {"R_g_param_spec_uint", (DL_FUNC) &R_g_param_spec_uint, 7},
    {"R_g_param_spec_uint64", (DL_FUNC) &R_g_param_spec_uint64, 7},
    {"R_g_param_spec_ulong", (DL_FUNC) &R_g_param_spec_ulong, 7},
    {"R_g_param_spec_unichar", (DL_FUNC) &R_g_param_spec_unichar, 5},
    {"R_g_param_spec_variant", (DL_FUNC) &R_g_param_spec_variant, 6},
    {"R_g_param_type_register_static", (DL_FUNC) &R_g_param_type_register_static, 2},
    {"R_g_param_value_convert", (DL_FUNC) &R_g_param_value_convert, 4},
    {"R_g_param_value_defaults", (DL_FUNC) &R_g_param_value_defaults, 2},
    {"R_g_param_value_set_default", (DL_FUNC) &R_g_param_value_set_default, 2},
    {"R_g_param_value_validate", (DL_FUNC) &R_g_param_value_validate, 2},
    {"R_g_param_values_cmp", (DL_FUNC) &R_g_param_values_cmp, 3},
    {"R_g_pointer_type_register_static", (DL_FUNC) &R_g_pointer_type_register_static, 1},
    {"R_g_signal_accumulator_first_wins", (DL_FUNC) &R_g_signal_accumulator_first_wins, 4},
    {"R_g_signal_accumulator_true_handled", (DL_FUNC) &R_g_signal_accumulator_true_handled, 4},
    {"R_g_signal_add_emission_hook", (DL_FUNC) &R_g_signal_add_emission_hook, 5},
    {"R_g_signal_chain_from_overridden", (DL_FUNC) &R_g_signal_chain_from_overridden, 2},
    {"R_g_signal_connect_closure", (DL_FUNC) &R_g_signal_connect_closure, 4},
    {"R_g_signal_connect_closure_by_id", (DL_FUNC) &R_g_signal_connect_closure_by_id, 5},
    {"R_g_signal_emitv", (DL_FUNC) &R_g_signal_emitv, 3},
    {"R_g_signal_get_invocation_hint", (DL_FUNC) &R_g_signal_get_invocation_hint, 1},
    {"R_g_signal_handler_block", (DL_FUNC) &R_g_signal_handler_block, 2},
    {"R_g_signal_handler_disconnect", (DL_FUNC) &R_g_signal_handler_disconnect, 2},
    {"R_g_signal_handler_find", (DL_FUNC) &R_g_signal_handler_find, 7},
    {"R_g_signal_handler_is_connected", (DL_FUNC) &R_g_signal_handler_is_connected, 2},
    {"R_g_signal_handler_unblock", (DL_FUNC) &R_g_signal_handler_unblock, 2},
    {"R_g_signal_handlers_block_matched", (DL_FUNC) &R_g_signal_handlers_block_matched, 7},
    {"R_g_signal_handlers_destroy", (DL_FUNC) &R_g_signal_handlers_destroy, 1},
    {"R_g_signal_handlers_disconnect_matched", (DL_FUNC) &R_g_signal_handlers_disconnect_matched, 7},
    {"R_g_signal_handlers_unblock_matched", (DL_FUNC) &R_g_signal_handlers_unblock_matched, 7},
    {"R_g_signal_has_handler_pending", (DL_FUNC) &R_g_signal_has_handler_pending, 4},
    {"R_g_signal_list_ids", (DL_FUNC) &R_g_signal_list_ids, 1},
    {"R_g_signal_lookup", (DL_FUNC) &R_g_signal_lookup, 2},
    {"R_g_signal_name", (DL_FUNC) &R_g_signal_name, 1},
    {"R_g_signal_override_class_closure", (DL_FUNC) &R_g_signal_override_class_closure, 3},
    {"R_g_signal_override_class_handler", (DL_FUNC) &R_g_signal_override_class_handler, 3},
    {"R_g_signal_parse_name", (DL_FUNC) &R_g_signal_parse_name, 3},
    {"R_g_signal_query", (DL_FUNC) &R_g_signal_query, 1},
    {"R_g_signal_remove_emission_hook", (DL_FUNC) &R_g_signal_remove_emission_hook, 2},
    {"R_g_signal_stop_emission", (DL_FUNC) &R_g_signal_stop_emission, 3},
    {"R_g_signal_stop_emission_by_name", (DL_FUNC) &R_g_signal_stop_emission_by_name, 2},
    {"R_g_signal_type_cclosure_new", (DL_FUNC) &R_g_signal_type_cclosure_new, 2},
    {"R_g_strdup_value_contents", (DL_FUNC) &R_g_strdup_value_contents, 1},
    {"R_g_type_add_class_private", (DL_FUNC) &R_g_type_add_class_private, 2},
    {"R_g_type_add_instance_private", (DL_FUNC) &R_g_type_add_instance_private, 2},
    {"R_g_type_add_interface_dynamic", (DL_FUNC) &R_g_type_add_interface_dynamic, 3},
    {"R_g_type_add_interface_static", (DL_FUNC) &R_g_type_add_interface_static, 3},
    {"R_g_type_check_class_is_a", (DL_FUNC) &R_g_type_check_class_is_a, 2},
    {"R_g_type_check_instance", (DL_FUNC) &R_g_type_check_instance, 1},
    {"R_g_type_check_instance_is_a", (DL_FUNC) &R_g_type_check_instance_is_a, 2},
    {"R_g_type_check_instance_is_fundamentally_a", (DL_FUNC) &R_g_type_check_instance_is_fundamentally_a, 2},
    {"R_g_type_check_is_value_type", (DL_FUNC) &R_g_type_check_is_value_type, 1},
    {"R_g_type_check_value", (DL_FUNC) &R_g_type_check_value, 1},
    {"R_g_type_check_value_holds", (DL_FUNC) &R_g_type_check_value_holds, 2},
    {"R_g_type_children", (DL_FUNC) &R_g_type_children, 1},
    {"R_g_type_default_interface_peek", (DL_FUNC) &R_g_type_default_interface_peek, 1},
    {"R_g_type_default_interface_ref", (DL_FUNC) &R_g_type_default_interface_ref, 1},
    {"R_g_type_default_interface_unref", (DL_FUNC) &R_g_type_default_interface_unref, 1},
    {"R_g_type_depth", (DL_FUNC) &R_g_type_depth, 1},
    {"R_g_type_ensure", (DL_FUNC) &R_g_type_ensure, 1},
    {"R_g_type_free_instance", (DL_FUNC) &R_g_type_free_instance, 1},
    {"R_g_type_from_name", (DL_FUNC) &R_g_type_from_name, 1},
    {"R_g_type_fundamental", (DL_FUNC) &R_g_type_fundamental, 1},
    {"R_g_type_fundamental_next", (DL_FUNC) &R_g_type_fundamental_next, 0},
    {"R_g_type_get_instance_count", (DL_FUNC) &R_g_type_get_instance_count, 1},
    {"R_g_type_get_plugin", (DL_FUNC) &R_g_type_get_plugin, 1},
    {"R_g_type_get_qdata", (DL_FUNC) &R_g_type_get_qdata, 2},
    {"R_g_type_get_type_registration_serial", (DL_FUNC) &R_g_type_get_type_registration_serial, 0},
    {"R_g_type_init", (DL_FUNC) &R_g_type_init, 0},
    {"R_g_type_init_with_debug_flags", (DL_FUNC) &R_g_type_init_with_debug_flags, 1},
    {"R_g_type_interfaces", (DL_FUNC) &R_g_type_interfaces, 1},
    {"R_g_type_is_a", (DL_FUNC) &R_g_type_is_a, 2},
    {"R_g_type_name", (DL_FUNC) &R_g_type_name, 1},
    {"R_g_type_name_from_class", (DL_FUNC) &R_g_type_name_from_class, 1},
    {"R_g_type_name_from_instance", (DL_FUNC) &R_g_type_name_from_instance, 1},
    {"R_g_type_next_base", (DL_FUNC) &R_g_type_next_base, 2},
    {"R_g_type_parent", (DL_FUNC) &R_g_type_parent, 1},
    {"R_g_type_qname", (DL_FUNC) &R_g_type_qname, 1},
    {"R_g_type_query", (DL_FUNC) &R_g_type_query, 1},
    {"R_g_type_register_dynamic", (DL_FUNC) &R_g_type_register_dynamic, 4},
    {"R_g_type_register_fundamental", (DL_FUNC) &R_g_type_register_fundamental, 5},
    {"R_g_type_register_static", (DL_FUNC) &R_g_type_register_static, 4},
    {"R_g_type_set_qdata", (DL_FUNC) &R_g_type_set_qdata, 3},
    {"R_g_type_test_flags", (DL_FUNC) &R_g_type_test_flags, 2},
    {"R_gtk_at_context_create", (DL_FUNC) &R_gtk_at_context_create, 3},
    {"R_gtk_at_context_get_accessible", (DL_FUNC) &R_gtk_at_context_get_accessible, 1},
    {"R_gtk_at_context_get_accessible_role", (DL_FUNC) &R_gtk_at_context_get_accessible_role, 1},
    {"R_gtk_about_dialog_new", (DL_FUNC) &R_gtk_about_dialog_new, 0},
    {"R_gtk_about_dialog_add_credit_section", (DL_FUNC) &R_gtk_about_dialog_add_credit_section, 3},
    {"R_gtk_about_dialog_get_artists", (DL_FUNC) &R_gtk_about_dialog_get_artists, 1},
    {"R_gtk_about_dialog_get_authors", (DL_FUNC) &R_gtk_about_dialog_get_authors, 1},
    {"R_gtk_about_dialog_get_comments", (DL_FUNC) &R_gtk_about_dialog_get_comments, 1},
    {"R_gtk_about_dialog_get_copyright", (DL_FUNC) &R_gtk_about_dialog_get_copyright, 1},
    {"R_gtk_about_dialog_get_documenters", (DL_FUNC) &R_gtk_about_dialog_get_documenters, 1},
    {"R_gtk_about_dialog_get_license", (DL_FUNC) &R_gtk_about_dialog_get_license, 1},
    {"R_gtk_about_dialog_get_license_type", (DL_FUNC) &R_gtk_about_dialog_get_license_type, 1},
    {"R_gtk_about_dialog_get_logo", (DL_FUNC) &R_gtk_about_dialog_get_logo, 1},
    {"R_gtk_about_dialog_get_logo_icon_name", (DL_FUNC) &R_gtk_about_dialog_get_logo_icon_name, 1},
    {"R_gtk_about_dialog_get_program_name", (DL_FUNC) &R_gtk_about_dialog_get_program_name, 1},
    {"R_gtk_about_dialog_get_system_information", (DL_FUNC) &R_gtk_about_dialog_get_system_information, 1},
    {"R_gtk_about_dialog_get_translator_credits", (DL_FUNC) &R_gtk_about_dialog_get_translator_credits, 1},
    {"R_gtk_about_dialog_get_version", (DL_FUNC) &R_gtk_about_dialog_get_version, 1},
    {"R_gtk_about_dialog_get_website", (DL_FUNC) &R_gtk_about_dialog_get_website, 1},
    {"R_gtk_about_dialog_get_website_label", (DL_FUNC) &R_gtk_about_dialog_get_website_label, 1},
    {"R_gtk_about_dialog_get_wrap_license", (DL_FUNC) &R_gtk_about_dialog_get_wrap_license, 1},
    {"R_gtk_about_dialog_set_artists", (DL_FUNC) &R_gtk_about_dialog_set_artists, 2},
    {"R_gtk_about_dialog_set_authors", (DL_FUNC) &R_gtk_about_dialog_set_authors, 2},
    {"R_gtk_about_dialog_set_comments", (DL_FUNC) &R_gtk_about_dialog_set_comments, 2},
    {"R_gtk_about_dialog_set_copyright", (DL_FUNC) &R_gtk_about_dialog_set_copyright, 2},
    {"R_gtk_about_dialog_set_documenters", (DL_FUNC) &R_gtk_about_dialog_set_documenters, 2},
    {"R_gtk_about_dialog_set_license", (DL_FUNC) &R_gtk_about_dialog_set_license, 2},
    {"R_gtk_about_dialog_set_license_type", (DL_FUNC) &R_gtk_about_dialog_set_license_type, 2},
    {"R_gtk_about_dialog_set_logo", (DL_FUNC) &R_gtk_about_dialog_set_logo, 2},
    {"R_gtk_about_dialog_set_logo_icon_name", (DL_FUNC) &R_gtk_about_dialog_set_logo_icon_name, 2},
    {"R_gtk_about_dialog_set_program_name", (DL_FUNC) &R_gtk_about_dialog_set_program_name, 2},
    {"R_gtk_about_dialog_set_system_information", (DL_FUNC) &R_gtk_about_dialog_set_system_information, 2},
    {"R_gtk_about_dialog_set_translator_credits", (DL_FUNC) &R_gtk_about_dialog_set_translator_credits, 2},
    {"R_gtk_about_dialog_set_version", (DL_FUNC) &R_gtk_about_dialog_set_version, 2},
    {"R_gtk_about_dialog_set_website", (DL_FUNC) &R_gtk_about_dialog_set_website, 2},
    {"R_gtk_about_dialog_set_website_label", (DL_FUNC) &R_gtk_about_dialog_set_website_label, 2},
    {"R_gtk_about_dialog_set_wrap_license", (DL_FUNC) &R_gtk_about_dialog_set_wrap_license, 2},
    {"R_gtk_accessible_get_accessible_parent", (DL_FUNC) &R_gtk_accessible_get_accessible_parent, 1},
    {"R_gtk_accessible_get_accessible_role", (DL_FUNC) &R_gtk_accessible_get_accessible_role, 1},
    {"R_gtk_accessible_get_at_context", (DL_FUNC) &R_gtk_accessible_get_at_context, 1},
    {"R_gtk_accessible_get_bounds", (DL_FUNC) &R_gtk_accessible_get_bounds, 1},
    {"R_gtk_accessible_get_first_accessible_child", (DL_FUNC) &R_gtk_accessible_get_first_accessible_child, 1},
    {"R_gtk_accessible_get_next_accessible_sibling", (DL_FUNC) &R_gtk_accessible_get_next_accessible_sibling, 1},
    {"R_gtk_accessible_get_platform_state", (DL_FUNC) &R_gtk_accessible_get_platform_state, 2},
    {"R_gtk_accessible_reset_property", (DL_FUNC) &R_gtk_accessible_reset_property, 2},
    {"R_gtk_accessible_reset_relation", (DL_FUNC) &R_gtk_accessible_reset_relation, 2},
    {"R_gtk_accessible_reset_state", (DL_FUNC) &R_gtk_accessible_reset_state, 2},
    {"R_gtk_accessible_set_accessible_parent", (DL_FUNC) &R_gtk_accessible_set_accessible_parent, 3},
    {"R_gtk_accessible_update_next_accessible_sibling", (DL_FUNC) &R_gtk_accessible_update_next_accessible_sibling, 2},
    {"R_gtk_accessible_update_property_value", (DL_FUNC) &R_gtk_accessible_update_property_value, 4},
    {"R_gtk_accessible_update_relation_value", (DL_FUNC) &R_gtk_accessible_update_relation_value, 4},
    {"R_gtk_accessible_update_state_value", (DL_FUNC) &R_gtk_accessible_update_state_value, 4},
    {"R_gtk_accessible_property_init_value", (DL_FUNC) &R_gtk_accessible_property_init_value, 2},
    {"R_gtk_accessible_relation_init_value", (DL_FUNC) &R_gtk_accessible_relation_init_value, 2},
    {"R_gtk_accessible_state_init_value", (DL_FUNC) &R_gtk_accessible_state_init_value, 2},
    {"R_gtk_action_bar_new", (DL_FUNC) &R_gtk_action_bar_new, 0},
    {"R_gtk_action_bar_get_center_widget", (DL_FUNC) &R_gtk_action_bar_get_center_widget, 1},
    {"R_gtk_action_bar_get_revealed", (DL_FUNC) &R_gtk_action_bar_get_revealed, 1},
    {"R_gtk_action_bar_pack_end", (DL_FUNC) &R_gtk_action_bar_pack_end, 2},
    {"R_gtk_action_bar_pack_start", (DL_FUNC) &R_gtk_action_bar_pack_start, 2},
    {"R_gtk_action_bar_remove", (DL_FUNC) &R_gtk_action_bar_remove, 2},
    {"R_gtk_action_bar_set_center_widget", (DL_FUNC) &R_gtk_action_bar_set_center_widget, 2},
    {"R_gtk_action_bar_set_revealed", (DL_FUNC) &R_gtk_action_bar_set_revealed, 2},
    {"R_gtk_actionable_get_action_name", (DL_FUNC) &R_gtk_actionable_get_action_name, 1},
    {"R_gtk_actionable_get_action_target_value", (DL_FUNC) &R_gtk_actionable_get_action_target_value, 1},
    {"R_gtk_actionable_set_action_name", (DL_FUNC) &R_gtk_actionable_set_action_name, 2},
    {"R_gtk_actionable_set_action_target_value", (DL_FUNC) &R_gtk_actionable_set_action_target_value, 2},
    {"R_gtk_actionable_set_detailed_action_name", (DL_FUNC) &R_gtk_actionable_set_detailed_action_name, 2},
    {"R_gtk_activate_action_get", (DL_FUNC) &R_gtk_activate_action_get, 0},
    {"R_gtk_adjustment_new", (DL_FUNC) &R_gtk_adjustment_new, 6},
    {"R_gtk_adjustment_clamp_page", (DL_FUNC) &R_gtk_adjustment_clamp_page, 3},
    {"R_gtk_adjustment_configure", (DL_FUNC) &R_gtk_adjustment_configure, 7},
    {"R_gtk_adjustment_get_lower", (DL_FUNC) &R_gtk_adjustment_get_lower, 1},
    {"R_gtk_adjustment_get_minimum_increment", (DL_FUNC) &R_gtk_adjustment_get_minimum_increment, 1},
    {"R_gtk_adjustment_get_page_increment", (DL_FUNC) &R_gtk_adjustment_get_page_increment, 1},
    {"R_gtk_adjustment_get_page_size", (DL_FUNC) &R_gtk_adjustment_get_page_size, 1},
    {"R_gtk_adjustment_get_step_increment", (DL_FUNC) &R_gtk_adjustment_get_step_increment, 1},
    {"R_gtk_adjustment_get_upper", (DL_FUNC) &R_gtk_adjustment_get_upper, 1},
    {"R_gtk_adjustment_get_value", (DL_FUNC) &R_gtk_adjustment_get_value, 1},
    {"R_gtk_adjustment_set_lower", (DL_FUNC) &R_gtk_adjustment_set_lower, 2},
    {"R_gtk_adjustment_set_page_increment", (DL_FUNC) &R_gtk_adjustment_set_page_increment, 2},
    {"R_gtk_adjustment_set_page_size", (DL_FUNC) &R_gtk_adjustment_set_page_size, 2},
    {"R_gtk_adjustment_set_step_increment", (DL_FUNC) &R_gtk_adjustment_set_step_increment, 2},
    {"R_gtk_adjustment_set_upper", (DL_FUNC) &R_gtk_adjustment_set_upper, 2},
    {"R_gtk_adjustment_set_value", (DL_FUNC) &R_gtk_adjustment_set_value, 2},
    {"R_gtk_alert_dialog_choose", (DL_FUNC) &R_gtk_alert_dialog_choose, 5},
    {"R_gtk_alert_dialog_choose_finish", (DL_FUNC) &R_gtk_alert_dialog_choose_finish, 2},
    {"R_gtk_alert_dialog_get_buttons", (DL_FUNC) &R_gtk_alert_dialog_get_buttons, 1},
    {"R_gtk_alert_dialog_get_cancel_button", (DL_FUNC) &R_gtk_alert_dialog_get_cancel_button, 1},
    {"R_gtk_alert_dialog_get_default_button", (DL_FUNC) &R_gtk_alert_dialog_get_default_button, 1},
    {"R_gtk_alert_dialog_get_detail", (DL_FUNC) &R_gtk_alert_dialog_get_detail, 1},
    {"R_gtk_alert_dialog_get_message", (DL_FUNC) &R_gtk_alert_dialog_get_message, 1},
    {"R_gtk_alert_dialog_get_modal", (DL_FUNC) &R_gtk_alert_dialog_get_modal, 1},
    {"R_gtk_alert_dialog_set_buttons", (DL_FUNC) &R_gtk_alert_dialog_set_buttons, 2},
    {"R_gtk_alert_dialog_set_cancel_button", (DL_FUNC) &R_gtk_alert_dialog_set_cancel_button, 2},
    {"R_gtk_alert_dialog_set_default_button", (DL_FUNC) &R_gtk_alert_dialog_set_default_button, 2},
    {"R_gtk_alert_dialog_set_detail", (DL_FUNC) &R_gtk_alert_dialog_set_detail, 2},
    {"R_gtk_alert_dialog_set_message", (DL_FUNC) &R_gtk_alert_dialog_set_message, 2},
    {"R_gtk_alert_dialog_set_modal", (DL_FUNC) &R_gtk_alert_dialog_set_modal, 2},
    {"R_gtk_alert_dialog_show", (DL_FUNC) &R_gtk_alert_dialog_show, 2},
    {"R_gtk_alternative_trigger_new", (DL_FUNC) &R_gtk_alternative_trigger_new, 2},
    {"R_gtk_alternative_trigger_get_first", (DL_FUNC) &R_gtk_alternative_trigger_get_first, 1},
    {"R_gtk_alternative_trigger_get_second", (DL_FUNC) &R_gtk_alternative_trigger_get_second, 1},
    {"R_gtk_any_filter_new", (DL_FUNC) &R_gtk_any_filter_new, 0},
    {"R_gtk_app_chooser_get_app_info", (DL_FUNC) &R_gtk_app_chooser_get_app_info, 1},
    {"R_gtk_app_chooser_get_content_type", (DL_FUNC) &R_gtk_app_chooser_get_content_type, 1},
    {"R_gtk_app_chooser_refresh", (DL_FUNC) &R_gtk_app_chooser_refresh, 1},
    {"R_gtk_app_chooser_button_new", (DL_FUNC) &R_gtk_app_chooser_button_new, 1},
    {"R_gtk_app_chooser_button_append_custom_item", (DL_FUNC) &R_gtk_app_chooser_button_append_custom_item, 4},
    {"R_gtk_app_chooser_button_append_separator", (DL_FUNC) &R_gtk_app_chooser_button_append_separator, 1},
    {"R_gtk_app_chooser_button_get_heading", (DL_FUNC) &R_gtk_app_chooser_button_get_heading, 1},
    {"R_gtk_app_chooser_button_get_modal", (DL_FUNC) &R_gtk_app_chooser_button_get_modal, 1},
    {"R_gtk_app_chooser_button_get_show_default_item", (DL_FUNC) &R_gtk_app_chooser_button_get_show_default_item, 1},
    {"R_gtk_app_chooser_button_get_show_dialog_item", (DL_FUNC) &R_gtk_app_chooser_button_get_show_dialog_item, 1},
    {"R_gtk_app_chooser_button_set_active_custom_item", (DL_FUNC) &R_gtk_app_chooser_button_set_active_custom_item, 2},
    {"R_gtk_app_chooser_button_set_heading", (DL_FUNC) &R_gtk_app_chooser_button_set_heading, 2},
    {"R_gtk_app_chooser_button_set_modal", (DL_FUNC) &R_gtk_app_chooser_button_set_modal, 2},
    {"R_gtk_app_chooser_button_set_show_default_item", (DL_FUNC) &R_gtk_app_chooser_button_set_show_default_item, 2},
    {"R_gtk_app_chooser_button_set_show_dialog_item", (DL_FUNC) &R_gtk_app_chooser_button_set_show_dialog_item, 2},
    {"R_gtk_app_chooser_dialog_new", (DL_FUNC) &R_gtk_app_chooser_dialog_new, 3},
    {"R_gtk_app_chooser_dialog_new_for_content_type", (DL_FUNC) &R_gtk_app_chooser_dialog_new_for_content_type, 3},
    {"R_gtk_app_chooser_dialog_get_heading", (DL_FUNC) &R_gtk_app_chooser_dialog_get_heading, 1},
    {"R_gtk_app_chooser_dialog_get_widget", (DL_FUNC) &R_gtk_app_chooser_dialog_get_widget, 1},
    {"R_gtk_app_chooser_dialog_set_heading", (DL_FUNC) &R_gtk_app_chooser_dialog_set_heading, 2},
    {"R_gtk_app_chooser_widget_new", (DL_FUNC) &R_gtk_app_chooser_widget_new, 1},
    {"R_gtk_app_chooser_widget_get_default_text", (DL_FUNC) &R_gtk_app_chooser_widget_get_default_text, 1},
    {"R_gtk_app_chooser_widget_get_show_all", (DL_FUNC) &R_gtk_app_chooser_widget_get_show_all, 1},
    {"R_gtk_app_chooser_widget_get_show_default", (DL_FUNC) &R_gtk_app_chooser_widget_get_show_default, 1},
    {"R_gtk_app_chooser_widget_get_show_fallback", (DL_FUNC) &R_gtk_app_chooser_widget_get_show_fallback, 1},
    {"R_gtk_app_chooser_widget_get_show_other", (DL_FUNC) &R_gtk_app_chooser_widget_get_show_other, 1},
    {"R_gtk_app_chooser_widget_get_show_recommended", (DL_FUNC) &R_gtk_app_chooser_widget_get_show_recommended, 1},
    {"R_gtk_app_chooser_widget_set_default_text", (DL_FUNC) &R_gtk_app_chooser_widget_set_default_text, 2},
    {"R_gtk_app_chooser_widget_set_show_all", (DL_FUNC) &R_gtk_app_chooser_widget_set_show_all, 2},
    {"R_gtk_app_chooser_widget_set_show_default", (DL_FUNC) &R_gtk_app_chooser_widget_set_show_default, 2},
    {"R_gtk_app_chooser_widget_set_show_fallback", (DL_FUNC) &R_gtk_app_chooser_widget_set_show_fallback, 2},
    {"R_gtk_app_chooser_widget_set_show_other", (DL_FUNC) &R_gtk_app_chooser_widget_set_show_other, 2},
    {"R_gtk_app_chooser_widget_set_show_recommended", (DL_FUNC) &R_gtk_app_chooser_widget_set_show_recommended, 2},
    {"R_gtk_application_new", (DL_FUNC) &R_gtk_application_new, 2},
    {"R_gtk_application_add_window", (DL_FUNC) &R_gtk_application_add_window, 2},
    {"R_gtk_application_get_accels_for_action", (DL_FUNC) &R_gtk_application_get_accels_for_action, 2},
    {"R_gtk_application_get_actions_for_accel", (DL_FUNC) &R_gtk_application_get_actions_for_accel, 2},
    {"R_gtk_application_get_active_window", (DL_FUNC) &R_gtk_application_get_active_window, 1},
    {"R_gtk_application_get_menu_by_id", (DL_FUNC) &R_gtk_application_get_menu_by_id, 2},
    {"R_gtk_application_get_menubar", (DL_FUNC) &R_gtk_application_get_menubar, 1},
    {"R_gtk_application_get_window_by_id", (DL_FUNC) &R_gtk_application_get_window_by_id, 2},
    {"R_gtk_application_get_windows", (DL_FUNC) &R_gtk_application_get_windows, 1},
    {"R_gtk_application_inhibit", (DL_FUNC) &R_gtk_application_inhibit, 4},
    {"R_gtk_application_list_action_descriptions", (DL_FUNC) &R_gtk_application_list_action_descriptions, 1},
    {"R_gtk_application_remove_window", (DL_FUNC) &R_gtk_application_remove_window, 2},
    {"R_gtk_application_set_accels_for_action", (DL_FUNC) &R_gtk_application_set_accels_for_action, 3},
    {"R_gtk_application_set_menubar", (DL_FUNC) &R_gtk_application_set_menubar, 2},
    {"R_gtk_application_uninhibit", (DL_FUNC) &R_gtk_application_uninhibit, 2},
    {"R_gtk_application_window_new", (DL_FUNC) &R_gtk_application_window_new, 1},
    {"R_gtk_application_window_get_help_overlay", (DL_FUNC) &R_gtk_application_window_get_help_overlay, 1},
    {"R_gtk_application_window_get_id", (DL_FUNC) &R_gtk_application_window_get_id, 1},
    {"R_gtk_application_window_get_show_menubar", (DL_FUNC) &R_gtk_application_window_get_show_menubar, 1},
    {"R_gtk_application_window_set_help_overlay", (DL_FUNC) &R_gtk_application_window_set_help_overlay, 2},
    {"R_gtk_application_window_set_show_menubar", (DL_FUNC) &R_gtk_application_window_set_show_menubar, 2},
    {"R_gtk_aspect_frame_new", (DL_FUNC) &R_gtk_aspect_frame_new, 4},
    {"R_gtk_aspect_frame_get_child", (DL_FUNC) &R_gtk_aspect_frame_get_child, 1},
    {"R_gtk_aspect_frame_get_obey_child", (DL_FUNC) &R_gtk_aspect_frame_get_obey_child, 1},
    {"R_gtk_aspect_frame_get_ratio", (DL_FUNC) &R_gtk_aspect_frame_get_ratio, 1},
    {"R_gtk_aspect_frame_get_xalign", (DL_FUNC) &R_gtk_aspect_frame_get_xalign, 1},
    {"R_gtk_aspect_frame_get_yalign", (DL_FUNC) &R_gtk_aspect_frame_get_yalign, 1},
    {"R_gtk_aspect_frame_set_child", (DL_FUNC) &R_gtk_aspect_frame_set_child, 2},
    {"R_gtk_aspect_frame_set_obey_child", (DL_FUNC) &R_gtk_aspect_frame_set_obey_child, 2},
    {"R_gtk_aspect_frame_set_ratio", (DL_FUNC) &R_gtk_aspect_frame_set_ratio, 2},
    {"R_gtk_aspect_frame_set_xalign", (DL_FUNC) &R_gtk_aspect_frame_set_xalign, 2},
    {"R_gtk_aspect_frame_set_yalign", (DL_FUNC) &R_gtk_aspect_frame_set_yalign, 2},
    {"R_gtk_assistant_new", (DL_FUNC) &R_gtk_assistant_new, 0},
    {"R_gtk_assistant_add_action_widget", (DL_FUNC) &R_gtk_assistant_add_action_widget, 2},
    {"R_gtk_assistant_append_page", (DL_FUNC) &R_gtk_assistant_append_page, 2},
    {"R_gtk_assistant_commit", (DL_FUNC) &R_gtk_assistant_commit, 1},
    {"R_gtk_assistant_get_current_page", (DL_FUNC) &R_gtk_assistant_get_current_page, 1},
    {"R_gtk_assistant_get_n_pages", (DL_FUNC) &R_gtk_assistant_get_n_pages, 1},
    {"R_gtk_assistant_get_nth_page", (DL_FUNC) &R_gtk_assistant_get_nth_page, 2},
    {"R_gtk_assistant_get_page", (DL_FUNC) &R_gtk_assistant_get_page, 2},
    {"R_gtk_assistant_get_page_complete", (DL_FUNC) &R_gtk_assistant_get_page_complete, 2},
    {"R_gtk_assistant_get_page_title", (DL_FUNC) &R_gtk_assistant_get_page_title, 2},
    {"R_gtk_assistant_get_page_type", (DL_FUNC) &R_gtk_assistant_get_page_type, 2},
    {"R_gtk_assistant_get_pages", (DL_FUNC) &R_gtk_assistant_get_pages, 1},
    {"R_gtk_assistant_insert_page", (DL_FUNC) &R_gtk_assistant_insert_page, 3},
    {"R_gtk_assistant_next_page", (DL_FUNC) &R_gtk_assistant_next_page, 1},
    {"R_gtk_assistant_prepend_page", (DL_FUNC) &R_gtk_assistant_prepend_page, 2},
    {"R_gtk_assistant_previous_page", (DL_FUNC) &R_gtk_assistant_previous_page, 1},
    {"R_gtk_assistant_remove_action_widget", (DL_FUNC) &R_gtk_assistant_remove_action_widget, 2},
    {"R_gtk_assistant_remove_page", (DL_FUNC) &R_gtk_assistant_remove_page, 2},
    {"R_gtk_assistant_set_current_page", (DL_FUNC) &R_gtk_assistant_set_current_page, 2},
    {"R_gtk_assistant_set_forward_page_func", (DL_FUNC) &R_gtk_assistant_set_forward_page_func, 4},
    {"R_gtk_assistant_set_page_complete", (DL_FUNC) &R_gtk_assistant_set_page_complete, 3},
    {"R_gtk_assistant_set_page_title", (DL_FUNC) &R_gtk_assistant_set_page_title, 3},
    {"R_gtk_assistant_set_page_type", (DL_FUNC) &R_gtk_assistant_set_page_type, 3},
    {"R_gtk_assistant_update_buttons_state", (DL_FUNC) &R_gtk_assistant_update_buttons_state, 1},
    {"R_gtk_assistant_page_get_child", (DL_FUNC) &R_gtk_assistant_page_get_child, 1},
    {"R_gtk_bin_layout_new", (DL_FUNC) &R_gtk_bin_layout_new, 0},
    {"R_gtk_bitset_new_empty", (DL_FUNC) &R_gtk_bitset_new_empty, 0},
    {"R_gtk_bitset_new_range", (DL_FUNC) &R_gtk_bitset_new_range, 2},
    {"R_gtk_bitset_add", (DL_FUNC) &R_gtk_bitset_add, 2},
    {"R_gtk_bitset_add_range", (DL_FUNC) &R_gtk_bitset_add_range, 3},
    {"R_gtk_bitset_add_range_closed", (DL_FUNC) &R_gtk_bitset_add_range_closed, 3},
    {"R_gtk_bitset_add_rectangle", (DL_FUNC) &R_gtk_bitset_add_rectangle, 5},
    {"R_gtk_bitset_contains", (DL_FUNC) &R_gtk_bitset_contains, 2},
    {"R_gtk_bitset_copy", (DL_FUNC) &R_gtk_bitset_copy, 1},
    {"R_gtk_bitset_difference", (DL_FUNC) &R_gtk_bitset_difference, 2},
    {"R_gtk_bitset_equals", (DL_FUNC) &R_gtk_bitset_equals, 2},
    {"R_gtk_bitset_get_maximum", (DL_FUNC) &R_gtk_bitset_get_maximum, 1},
    {"R_gtk_bitset_get_minimum", (DL_FUNC) &R_gtk_bitset_get_minimum, 1},
    {"R_gtk_bitset_get_nth", (DL_FUNC) &R_gtk_bitset_get_nth, 2},
    {"R_gtk_bitset_get_size", (DL_FUNC) &R_gtk_bitset_get_size, 1},
    {"R_gtk_bitset_get_size_in_range", (DL_FUNC) &R_gtk_bitset_get_size_in_range, 3},
    {"R_gtk_bitset_intersect", (DL_FUNC) &R_gtk_bitset_intersect, 2},
    {"R_gtk_bitset_is_empty", (DL_FUNC) &R_gtk_bitset_is_empty, 1},
    {"R_gtk_bitset_ref", (DL_FUNC) &R_gtk_bitset_ref, 1},
    {"R_gtk_bitset_remove", (DL_FUNC) &R_gtk_bitset_remove, 2},
    {"R_gtk_bitset_remove_all", (DL_FUNC) &R_gtk_bitset_remove_all, 1},
    {"R_gtk_bitset_remove_range", (DL_FUNC) &R_gtk_bitset_remove_range, 3},
    {"R_gtk_bitset_remove_range_closed", (DL_FUNC) &R_gtk_bitset_remove_range_closed, 3},
    {"R_gtk_bitset_remove_rectangle", (DL_FUNC) &R_gtk_bitset_remove_rectangle, 5},
    {"R_gtk_bitset_shift_left", (DL_FUNC) &R_gtk_bitset_shift_left, 2},
    {"R_gtk_bitset_shift_right", (DL_FUNC) &R_gtk_bitset_shift_right, 2},
    {"R_gtk_bitset_splice", (DL_FUNC) &R_gtk_bitset_splice, 4},
    {"R_gtk_bitset_subtract", (DL_FUNC) &R_gtk_bitset_subtract, 2},
    {"R_gtk_bitset_union", (DL_FUNC) &R_gtk_bitset_union, 2},
    {"R_gtk_bitset_unref", (DL_FUNC) &R_gtk_bitset_unref, 1},
    {"R_gtk_bitset_iter_get_value", (DL_FUNC) &R_gtk_bitset_iter_get_value, 1},
    {"R_gtk_bitset_iter_is_valid", (DL_FUNC) &R_gtk_bitset_iter_is_valid, 1},
    {"R_gtk_bitset_iter_next", (DL_FUNC) &R_gtk_bitset_iter_next, 1},
    {"R_gtk_bitset_iter_previous", (DL_FUNC) &R_gtk_bitset_iter_previous, 1},
    {"R_gtk_bitset_iter_init_at", (DL_FUNC) &R_gtk_bitset_iter_init_at, 2},
    {"R_gtk_bitset_iter_init_first", (DL_FUNC) &R_gtk_bitset_iter_init_first, 1},
    {"R_gtk_bitset_iter_init_last", (DL_FUNC) &R_gtk_bitset_iter_init_last, 1},
    {"R_gtk_bookmark_list_new", (DL_FUNC) &R_gtk_bookmark_list_new, 2},
    {"R_gtk_bookmark_list_get_attributes", (DL_FUNC) &R_gtk_bookmark_list_get_attributes, 1},
    {"R_gtk_bookmark_list_get_filename", (DL_FUNC) &R_gtk_bookmark_list_get_filename, 1},
    {"R_gtk_bookmark_list_get_io_priority", (DL_FUNC) &R_gtk_bookmark_list_get_io_priority, 1},
    {"R_gtk_bookmark_list_is_loading", (DL_FUNC) &R_gtk_bookmark_list_is_loading, 1},
    {"R_gtk_bookmark_list_set_attributes", (DL_FUNC) &R_gtk_bookmark_list_set_attributes, 2},
    {"R_gtk_bookmark_list_set_io_priority", (DL_FUNC) &R_gtk_bookmark_list_set_io_priority, 2},
    {"R_gtk_bool_filter_new", (DL_FUNC) &R_gtk_bool_filter_new, 1},
    {"R_gtk_bool_filter_get_expression", (DL_FUNC) &R_gtk_bool_filter_get_expression, 1},
    {"R_gtk_bool_filter_get_invert", (DL_FUNC) &R_gtk_bool_filter_get_invert, 1},
    {"R_gtk_bool_filter_set_expression", (DL_FUNC) &R_gtk_bool_filter_set_expression, 2},
    {"R_gtk_bool_filter_set_invert", (DL_FUNC) &R_gtk_bool_filter_set_invert, 2},
    {"R_gtk_border_new", (DL_FUNC) &R_gtk_border_new, 0},
    {"R_gtk_border_copy", (DL_FUNC) &R_gtk_border_copy, 1},
    {"R_gtk_border_free", (DL_FUNC) &R_gtk_border_free, 1},
    {"R_gtk_box_new", (DL_FUNC) &R_gtk_box_new, 2},
    {"R_gtk_box_append", (DL_FUNC) &R_gtk_box_append, 2},
    {"R_gtk_box_get_baseline_child", (DL_FUNC) &R_gtk_box_get_baseline_child, 1},
    {"R_gtk_box_get_baseline_position", (DL_FUNC) &R_gtk_box_get_baseline_position, 1},
    {"R_gtk_box_get_homogeneous", (DL_FUNC) &R_gtk_box_get_homogeneous, 1},
    {"R_gtk_box_get_spacing", (DL_FUNC) &R_gtk_box_get_spacing, 1},
    {"R_gtk_box_insert_child_after", (DL_FUNC) &R_gtk_box_insert_child_after, 3},
    {"R_gtk_box_prepend", (DL_FUNC) &R_gtk_box_prepend, 2},
    {"R_gtk_box_remove", (DL_FUNC) &R_gtk_box_remove, 2},
    {"R_gtk_box_reorder_child_after", (DL_FUNC) &R_gtk_box_reorder_child_after, 3},
    {"R_gtk_box_set_baseline_child", (DL_FUNC) &R_gtk_box_set_baseline_child, 2},
    {"R_gtk_box_set_baseline_position", (DL_FUNC) &R_gtk_box_set_baseline_position, 2},
    {"R_gtk_box_set_homogeneous", (DL_FUNC) &R_gtk_box_set_homogeneous, 2},
    {"R_gtk_box_set_spacing", (DL_FUNC) &R_gtk_box_set_spacing, 2},
    {"R_gtk_box_layout_new", (DL_FUNC) &R_gtk_box_layout_new, 1},
    {"R_gtk_box_layout_get_baseline_child", (DL_FUNC) &R_gtk_box_layout_get_baseline_child, 1},
    {"R_gtk_box_layout_get_baseline_position", (DL_FUNC) &R_gtk_box_layout_get_baseline_position, 1},
    {"R_gtk_box_layout_get_homogeneous", (DL_FUNC) &R_gtk_box_layout_get_homogeneous, 1},
    {"R_gtk_box_layout_get_spacing", (DL_FUNC) &R_gtk_box_layout_get_spacing, 1},
    {"R_gtk_box_layout_set_baseline_child", (DL_FUNC) &R_gtk_box_layout_set_baseline_child, 2},
    {"R_gtk_box_layout_set_baseline_position", (DL_FUNC) &R_gtk_box_layout_set_baseline_position, 2},
    {"R_gtk_box_layout_set_homogeneous", (DL_FUNC) &R_gtk_box_layout_set_homogeneous, 2},
    {"R_gtk_box_layout_set_spacing", (DL_FUNC) &R_gtk_box_layout_set_spacing, 2},
    {"R_gtk_buildable_get_buildable_id", (DL_FUNC) &R_gtk_buildable_get_buildable_id, 1},
    {"R_gtk_buildable_parse_context_get_element", (DL_FUNC) &R_gtk_buildable_parse_context_get_element, 1},
    {"R_gtk_buildable_parse_context_get_element_stack", (DL_FUNC) &R_gtk_buildable_parse_context_get_element_stack, 1},
    {"R_gtk_buildable_parse_context_get_position", (DL_FUNC) &R_gtk_buildable_parse_context_get_position, 1},
    {"R_gtk_buildable_parse_context_pop", (DL_FUNC) &R_gtk_buildable_parse_context_pop, 1},
    {"R_gtk_buildable_parse_context_push", (DL_FUNC) &R_gtk_buildable_parse_context_push, 3},
    {"R_gtk_builder_new", (DL_FUNC) &R_gtk_builder_new, 0},
    {"R_gtk_builder_new_from_file", (DL_FUNC) &R_gtk_builder_new_from_file, 1},
    {"R_gtk_builder_new_from_resource", (DL_FUNC) &R_gtk_builder_new_from_resource, 1},
    {"R_gtk_builder_new_from_string", (DL_FUNC) &R_gtk_builder_new_from_string, 2},
    {"R_gtk_builder_add_from_file", (DL_FUNC) &R_gtk_builder_add_from_file, 2},
    {"R_gtk_builder_add_from_resource", (DL_FUNC) &R_gtk_builder_add_from_resource, 2},
    {"R_gtk_builder_add_from_string", (DL_FUNC) &R_gtk_builder_add_from_string, 3},
    {"R_gtk_builder_add_objects_from_file", (DL_FUNC) &R_gtk_builder_add_objects_from_file, 3},
    {"R_gtk_builder_add_objects_from_resource", (DL_FUNC) &R_gtk_builder_add_objects_from_resource, 3},
    {"R_gtk_builder_add_objects_from_string", (DL_FUNC) &R_gtk_builder_add_objects_from_string, 4},
    {"R_gtk_builder_create_closure", (DL_FUNC) &R_gtk_builder_create_closure, 4},
    {"R_gtk_builder_expose_object", (DL_FUNC) &R_gtk_builder_expose_object, 3},
    {"R_gtk_builder_extend_with_template", (DL_FUNC) &R_gtk_builder_extend_with_template, 5},
    {"R_gtk_builder_get_current_object", (DL_FUNC) &R_gtk_builder_get_current_object, 1},
    {"R_gtk_builder_get_object", (DL_FUNC) &R_gtk_builder_get_object, 2},
    {"R_gtk_builder_get_objects", (DL_FUNC) &R_gtk_builder_get_objects, 1},
    {"R_gtk_builder_get_scope", (DL_FUNC) &R_gtk_builder_get_scope, 1},
    {"R_gtk_builder_get_translation_domain", (DL_FUNC) &R_gtk_builder_get_translation_domain, 1},
    {"R_gtk_builder_get_type_from_name", (DL_FUNC) &R_gtk_builder_get_type_from_name, 2},
    {"R_gtk_builder_set_current_object", (DL_FUNC) &R_gtk_builder_set_current_object, 2},
    {"R_gtk_builder_set_scope", (DL_FUNC) &R_gtk_builder_set_scope, 2},
    {"R_gtk_builder_set_translation_domain", (DL_FUNC) &R_gtk_builder_set_translation_domain, 2},
    {"R_gtk_builder_value_from_string", (DL_FUNC) &R_gtk_builder_value_from_string, 3},
    {"R_gtk_builder_value_from_string_type", (DL_FUNC) &R_gtk_builder_value_from_string_type, 3},
    {"R_gtk_builder_cscope_new", (DL_FUNC) &R_gtk_builder_cscope_new, 0},
    {"R_gtk_builder_cscope_add_callback_symbol", (DL_FUNC) &R_gtk_builder_cscope_add_callback_symbol, 3},
    {"R_gtk_builder_error_quark", (DL_FUNC) &R_gtk_builder_error_quark, 0},
    {"R_gtk_builder_list_item_factory_new_from_bytes", (DL_FUNC) &R_gtk_builder_list_item_factory_new_from_bytes, 2},
    {"R_gtk_builder_list_item_factory_new_from_resource", (DL_FUNC) &R_gtk_builder_list_item_factory_new_from_resource, 2},
    {"R_gtk_builder_list_item_factory_get_bytes", (DL_FUNC) &R_gtk_builder_list_item_factory_get_bytes, 1},
    {"R_gtk_builder_list_item_factory_get_resource", (DL_FUNC) &R_gtk_builder_list_item_factory_get_resource, 1},
    {"R_gtk_builder_list_item_factory_get_scope", (DL_FUNC) &R_gtk_builder_list_item_factory_get_scope, 1},
    {"R_gtk_button_new", (DL_FUNC) &R_gtk_button_new, 0},
    {"R_gtk_button_new_from_icon_name", (DL_FUNC) &R_gtk_button_new_from_icon_name, 1},
    {"R_gtk_button_new_with_label", (DL_FUNC) &R_gtk_button_new_with_label, 1},
    {"R_gtk_button_new_with_mnemonic", (DL_FUNC) &R_gtk_button_new_with_mnemonic, 1},
    {"R_gtk_button_get_can_shrink", (DL_FUNC) &R_gtk_button_get_can_shrink, 1},
    {"R_gtk_button_get_child", (DL_FUNC) &R_gtk_button_get_child, 1},
    {"R_gtk_button_get_has_frame", (DL_FUNC) &R_gtk_button_get_has_frame, 1},
    {"R_gtk_button_get_icon_name", (DL_FUNC) &R_gtk_button_get_icon_name, 1},
    {"R_gtk_button_get_label", (DL_FUNC) &R_gtk_button_get_label, 1},
    {"R_gtk_button_get_use_underline", (DL_FUNC) &R_gtk_button_get_use_underline, 1},
    {"R_gtk_button_set_can_shrink", (DL_FUNC) &R_gtk_button_set_can_shrink, 2},
    {"R_gtk_button_set_child", (DL_FUNC) &R_gtk_button_set_child, 2},
    {"R_gtk_button_set_has_frame", (DL_FUNC) &R_gtk_button_set_has_frame, 2},
    {"R_gtk_button_set_icon_name", (DL_FUNC) &R_gtk_button_set_icon_name, 2},
    {"R_gtk_button_set_label", (DL_FUNC) &R_gtk_button_set_label, 2},
    {"R_gtk_button_set_use_underline", (DL_FUNC) &R_gtk_button_set_use_underline, 2},
    {"R_gtk_cclosure_expression_new", (DL_FUNC) &R_gtk_cclosure_expression_new, 7},
    {"R_gtk_calendar_new", (DL_FUNC) &R_gtk_calendar_new, 0},
    {"R_gtk_calendar_clear_marks", (DL_FUNC) &R_gtk_calendar_clear_marks, 1},
    {"R_gtk_calendar_get_date", (DL_FUNC) &R_gtk_calendar_get_date, 1},
    {"R_gtk_calendar_get_day_is_marked", (DL_FUNC) &R_gtk_calendar_get_day_is_marked, 2},
    {"R_gtk_calendar_get_show_day_names", (DL_FUNC) &R_gtk_calendar_get_show_day_names, 1},
    {"R_gtk_calendar_get_show_heading", (DL_FUNC) &R_gtk_calendar_get_show_heading, 1},
    {"R_gtk_calendar_get_show_week_numbers", (DL_FUNC) &R_gtk_calendar_get_show_week_numbers, 1},
    {"R_gtk_calendar_mark_day", (DL_FUNC) &R_gtk_calendar_mark_day, 2},
    {"R_gtk_calendar_select_day", (DL_FUNC) &R_gtk_calendar_select_day, 2},
    {"R_gtk_calendar_set_show_day_names", (DL_FUNC) &R_gtk_calendar_set_show_day_names, 2},
    {"R_gtk_calendar_set_show_heading", (DL_FUNC) &R_gtk_calendar_set_show_heading, 2},
    {"R_gtk_calendar_set_show_week_numbers", (DL_FUNC) &R_gtk_calendar_set_show_week_numbers, 2},
    {"R_gtk_calendar_unmark_day", (DL_FUNC) &R_gtk_calendar_unmark_day, 2},
    {"R_gtk_callback_action_new", (DL_FUNC) &R_gtk_callback_action_new, 3},
    {"R_gtk_cell_area_activate", (DL_FUNC) &R_gtk_cell_area_activate, 6},
    {"R_gtk_cell_area_activate_cell", (DL_FUNC) &R_gtk_cell_area_activate_cell, 6},
    {"R_gtk_cell_area_add", (DL_FUNC) &R_gtk_cell_area_add, 2},
    {"R_gtk_cell_area_add_focus_sibling", (DL_FUNC) &R_gtk_cell_area_add_focus_sibling, 3},
    {"R_gtk_cell_area_apply_attributes", (DL_FUNC) &R_gtk_cell_area_apply_attributes, 5},
    {"R_gtk_cell_area_attribute_connect", (DL_FUNC) &R_gtk_cell_area_attribute_connect, 4},
    {"R_gtk_cell_area_attribute_disconnect", (DL_FUNC) &R_gtk_cell_area_attribute_disconnect, 3},
    {"R_gtk_cell_area_attribute_get_column", (DL_FUNC) &R_gtk_cell_area_attribute_get_column, 3},
    {"R_gtk_cell_area_cell_get_property", (DL_FUNC) &R_gtk_cell_area_cell_get_property, 4},
    {"R_gtk_cell_area_cell_set_property", (DL_FUNC) &R_gtk_cell_area_cell_set_property, 4},
    {"R_gtk_cell_area_copy_context", (DL_FUNC) &R_gtk_cell_area_copy_context, 2},
    {"R_gtk_cell_area_create_context", (DL_FUNC) &R_gtk_cell_area_create_context, 1},
    {"R_gtk_cell_area_event", (DL_FUNC) &R_gtk_cell_area_event, 6},
    {"R_gtk_cell_area_focus", (DL_FUNC) &R_gtk_cell_area_focus, 2},
    {"R_gtk_cell_area_foreach", (DL_FUNC) &R_gtk_cell_area_foreach, 3},
    {"R_gtk_cell_area_foreach_alloc", (DL_FUNC) &R_gtk_cell_area_foreach_alloc, 7},
    {"R_gtk_cell_area_get_cell_allocation", (DL_FUNC) &R_gtk_cell_area_get_cell_allocation, 5},
    {"R_gtk_cell_area_get_cell_at_position", (DL_FUNC) &R_gtk_cell_area_get_cell_at_position, 6},
    {"R_gtk_cell_area_get_current_path_string", (DL_FUNC) &R_gtk_cell_area_get_current_path_string, 1},
    {"R_gtk_cell_area_get_edit_widget", (DL_FUNC) &R_gtk_cell_area_get_edit_widget, 1},
    {"R_gtk_cell_area_get_edited_cell", (DL_FUNC) &R_gtk_cell_area_get_edited_cell, 1},
    {"R_gtk_cell_area_get_focus_cell", (DL_FUNC) &R_gtk_cell_area_get_focus_cell, 1},
    {"R_gtk_cell_area_get_focus_from_sibling", (DL_FUNC) &R_gtk_cell_area_get_focus_from_sibling, 2},
    {"R_gtk_cell_area_get_focus_siblings", (DL_FUNC) &R_gtk_cell_area_get_focus_siblings, 2},
    {"R_gtk_cell_area_get_preferred_height", (DL_FUNC) &R_gtk_cell_area_get_preferred_height, 3},
    {"R_gtk_cell_area_get_preferred_height_for_width", (DL_FUNC) &R_gtk_cell_area_get_preferred_height_for_width, 4},
    {"R_gtk_cell_area_get_preferred_width", (DL_FUNC) &R_gtk_cell_area_get_preferred_width, 3},
    {"R_gtk_cell_area_get_preferred_width_for_height", (DL_FUNC) &R_gtk_cell_area_get_preferred_width_for_height, 4},
    {"R_gtk_cell_area_get_request_mode", (DL_FUNC) &R_gtk_cell_area_get_request_mode, 1},
    {"R_gtk_cell_area_has_renderer", (DL_FUNC) &R_gtk_cell_area_has_renderer, 2},
    {"R_gtk_cell_area_inner_cell_area", (DL_FUNC) &R_gtk_cell_area_inner_cell_area, 3},
    {"R_gtk_cell_area_is_activatable", (DL_FUNC) &R_gtk_cell_area_is_activatable, 1},
    {"R_gtk_cell_area_is_focus_sibling", (DL_FUNC) &R_gtk_cell_area_is_focus_sibling, 3},
    {"R_gtk_cell_area_remove", (DL_FUNC) &R_gtk_cell_area_remove, 2},
    {"R_gtk_cell_area_remove_focus_sibling", (DL_FUNC) &R_gtk_cell_area_remove_focus_sibling, 3},
    {"R_gtk_cell_area_request_renderer", (DL_FUNC) &R_gtk_cell_area_request_renderer, 5},
    {"R_gtk_cell_area_set_focus_cell", (DL_FUNC) &R_gtk_cell_area_set_focus_cell, 2},
    {"R_gtk_cell_area_snapshot", (DL_FUNC) &R_gtk_cell_area_snapshot, 8},
    {"R_gtk_cell_area_stop_editing", (DL_FUNC) &R_gtk_cell_area_stop_editing, 2},
    {"R_gtk_cell_area_box_new", (DL_FUNC) &R_gtk_cell_area_box_new, 0},
    {"R_gtk_cell_area_box_get_spacing", (DL_FUNC) &R_gtk_cell_area_box_get_spacing, 1},
    {"R_gtk_cell_area_box_pack_end", (DL_FUNC) &R_gtk_cell_area_box_pack_end, 5},
    {"R_gtk_cell_area_box_pack_start", (DL_FUNC) &R_gtk_cell_area_box_pack_start, 5},
    {"R_gtk_cell_area_box_set_spacing", (DL_FUNC) &R_gtk_cell_area_box_set_spacing, 2},
    {"R_gtk_cell_area_class_find_cell_property", (DL_FUNC) &R_gtk_cell_area_class_find_cell_property, 2},
    {"R_gtk_cell_area_class_install_cell_property", (DL_FUNC) &R_gtk_cell_area_class_install_cell_property, 3},
    {"R_gtk_cell_area_class_list_cell_properties", (DL_FUNC) &R_gtk_cell_area_class_list_cell_properties, 1},
    {"R_gtk_cell_area_context_allocate", (DL_FUNC) &R_gtk_cell_area_context_allocate, 3},
    {"R_gtk_cell_area_context_get_allocation", (DL_FUNC) &R_gtk_cell_area_context_get_allocation, 1},
    {"R_gtk_cell_area_context_get_area", (DL_FUNC) &R_gtk_cell_area_context_get_area, 1},
    {"R_gtk_cell_area_context_get_preferred_height", (DL_FUNC) &R_gtk_cell_area_context_get_preferred_height, 1},
    {"R_gtk_cell_area_context_get_preferred_height_for_width", (DL_FUNC) &R_gtk_cell_area_context_get_preferred_height_for_width, 2},
    {"R_gtk_cell_area_context_get_preferred_width", (DL_FUNC) &R_gtk_cell_area_context_get_preferred_width, 1},
    {"R_gtk_cell_area_context_get_preferred_width_for_height", (DL_FUNC) &R_gtk_cell_area_context_get_preferred_width_for_height, 2},
    {"R_gtk_cell_area_context_push_preferred_height", (DL_FUNC) &R_gtk_cell_area_context_push_preferred_height, 3},
    {"R_gtk_cell_area_context_push_preferred_width", (DL_FUNC) &R_gtk_cell_area_context_push_preferred_width, 3},
    {"R_gtk_cell_area_context_reset", (DL_FUNC) &R_gtk_cell_area_context_reset, 1},
    {"R_gtk_cell_editable_editing_done", (DL_FUNC) &R_gtk_cell_editable_editing_done, 1},
    {"R_gtk_cell_editable_remove_widget", (DL_FUNC) &R_gtk_cell_editable_remove_widget, 1},
    {"R_gtk_cell_editable_start_editing", (DL_FUNC) &R_gtk_cell_editable_start_editing, 2},
    {"R_gtk_cell_layout_add_attribute", (DL_FUNC) &R_gtk_cell_layout_add_attribute, 4},
    {"R_gtk_cell_layout_clear", (DL_FUNC) &R_gtk_cell_layout_clear, 1},
    {"R_gtk_cell_layout_clear_attributes", (DL_FUNC) &R_gtk_cell_layout_clear_attributes, 2},
    {"R_gtk_cell_layout_get_area", (DL_FUNC) &R_gtk_cell_layout_get_area, 1},
    {"R_gtk_cell_layout_get_cells", (DL_FUNC) &R_gtk_cell_layout_get_cells, 1},
    {"R_gtk_cell_layout_pack_end", (DL_FUNC) &R_gtk_cell_layout_pack_end, 3},
    {"R_gtk_cell_layout_pack_start", (DL_FUNC) &R_gtk_cell_layout_pack_start, 3},
    {"R_gtk_cell_layout_reorder", (DL_FUNC) &R_gtk_cell_layout_reorder, 3},
    {"R_gtk_cell_layout_set_cell_data_func", (DL_FUNC) &R_gtk_cell_layout_set_cell_data_func, 5},
    {"R_gtk_cell_renderer_activate", (DL_FUNC) &R_gtk_cell_renderer_activate, 7},
    {"R_gtk_cell_renderer_get_aligned_area", (DL_FUNC) &R_gtk_cell_renderer_get_aligned_area, 4},
    {"R_gtk_cell_renderer_get_alignment", (DL_FUNC) &R_gtk_cell_renderer_get_alignment, 1},
    {"R_gtk_cell_renderer_get_fixed_size", (DL_FUNC) &R_gtk_cell_renderer_get_fixed_size, 1},
    {"R_gtk_cell_renderer_get_is_expanded", (DL_FUNC) &R_gtk_cell_renderer_get_is_expanded, 1},
    {"R_gtk_cell_renderer_get_is_expander", (DL_FUNC) &R_gtk_cell_renderer_get_is_expander, 1},
    {"R_gtk_cell_renderer_get_padding", (DL_FUNC) &R_gtk_cell_renderer_get_padding, 1},
    {"R_gtk_cell_renderer_get_preferred_height", (DL_FUNC) &R_gtk_cell_renderer_get_preferred_height, 2},
    {"R_gtk_cell_renderer_get_preferred_height_for_width", (DL_FUNC) &R_gtk_cell_renderer_get_preferred_height_for_width, 3},
    {"R_gtk_cell_renderer_get_preferred_size", (DL_FUNC) &R_gtk_cell_renderer_get_preferred_size, 2},
    {"R_gtk_cell_renderer_get_preferred_width", (DL_FUNC) &R_gtk_cell_renderer_get_preferred_width, 2},
    {"R_gtk_cell_renderer_get_preferred_width_for_height", (DL_FUNC) &R_gtk_cell_renderer_get_preferred_width_for_height, 3},
    {"R_gtk_cell_renderer_get_request_mode", (DL_FUNC) &R_gtk_cell_renderer_get_request_mode, 1},
    {"R_gtk_cell_renderer_get_sensitive", (DL_FUNC) &R_gtk_cell_renderer_get_sensitive, 1},
    {"R_gtk_cell_renderer_get_state", (DL_FUNC) &R_gtk_cell_renderer_get_state, 3},
    {"R_gtk_cell_renderer_get_visible", (DL_FUNC) &R_gtk_cell_renderer_get_visible, 1},
    {"R_gtk_cell_renderer_is_activatable", (DL_FUNC) &R_gtk_cell_renderer_is_activatable, 1},
    {"R_gtk_cell_renderer_set_alignment", (DL_FUNC) &R_gtk_cell_renderer_set_alignment, 3},
    {"R_gtk_cell_renderer_set_fixed_size", (DL_FUNC) &R_gtk_cell_renderer_set_fixed_size, 3},
    {"R_gtk_cell_renderer_set_is_expanded", (DL_FUNC) &R_gtk_cell_renderer_set_is_expanded, 2},
    {"R_gtk_cell_renderer_set_is_expander", (DL_FUNC) &R_gtk_cell_renderer_set_is_expander, 2},
    {"R_gtk_cell_renderer_set_padding", (DL_FUNC) &R_gtk_cell_renderer_set_padding, 3},
    {"R_gtk_cell_renderer_set_sensitive", (DL_FUNC) &R_gtk_cell_renderer_set_sensitive, 2},
    {"R_gtk_cell_renderer_set_visible", (DL_FUNC) &R_gtk_cell_renderer_set_visible, 2},
    {"R_gtk_cell_renderer_snapshot", (DL_FUNC) &R_gtk_cell_renderer_snapshot, 6},
    {"R_gtk_cell_renderer_start_editing", (DL_FUNC) &R_gtk_cell_renderer_start_editing, 7},
    {"R_gtk_cell_renderer_stop_editing", (DL_FUNC) &R_gtk_cell_renderer_stop_editing, 2},
    {"R_gtk_cell_renderer_accel_new", (DL_FUNC) &R_gtk_cell_renderer_accel_new, 0},
    {"R_gtk_cell_renderer_combo_new", (DL_FUNC) &R_gtk_cell_renderer_combo_new, 0},
    {"R_gtk_cell_renderer_pixbuf_new", (DL_FUNC) &R_gtk_cell_renderer_pixbuf_new, 0},
    {"R_gtk_cell_renderer_progress_new", (DL_FUNC) &R_gtk_cell_renderer_progress_new, 0},
    {"R_gtk_cell_renderer_spin_new", (DL_FUNC) &R_gtk_cell_renderer_spin_new, 0},
    {"R_gtk_cell_renderer_spinner_new", (DL_FUNC) &R_gtk_cell_renderer_spinner_new, 0},
    {"R_gtk_cell_renderer_text_new", (DL_FUNC) &R_gtk_cell_renderer_text_new, 0},
    {"R_gtk_cell_renderer_text_set_fixed_height_from_font", (DL_FUNC) &R_gtk_cell_renderer_text_set_fixed_height_from_font, 2},
    {"R_gtk_cell_renderer_toggle_new", (DL_FUNC) &R_gtk_cell_renderer_toggle_new, 0},
    {"R_gtk_cell_renderer_toggle_get_activatable", (DL_FUNC) &R_gtk_cell_renderer_toggle_get_activatable, 1},
    {"R_gtk_cell_renderer_toggle_get_active", (DL_FUNC) &R_gtk_cell_renderer_toggle_get_active, 1},
    {"R_gtk_cell_renderer_toggle_get_radio", (DL_FUNC) &R_gtk_cell_renderer_toggle_get_radio, 1},
    {"R_gtk_cell_renderer_toggle_set_activatable", (DL_FUNC) &R_gtk_cell_renderer_toggle_set_activatable, 2},
    {"R_gtk_cell_renderer_toggle_set_active", (DL_FUNC) &R_gtk_cell_renderer_toggle_set_active, 2},
    {"R_gtk_cell_renderer_toggle_set_radio", (DL_FUNC) &R_gtk_cell_renderer_toggle_set_radio, 2},
    {"R_gtk_cell_view_new", (DL_FUNC) &R_gtk_cell_view_new, 0},
    {"R_gtk_cell_view_new_with_context", (DL_FUNC) &R_gtk_cell_view_new_with_context, 2},
    {"R_gtk_cell_view_new_with_markup", (DL_FUNC) &R_gtk_cell_view_new_with_markup, 1},
    {"R_gtk_cell_view_new_with_text", (DL_FUNC) &R_gtk_cell_view_new_with_text, 1},
    {"R_gtk_cell_view_new_with_texture", (DL_FUNC) &R_gtk_cell_view_new_with_texture, 1},
    {"R_gtk_cell_view_get_displayed_row", (DL_FUNC) &R_gtk_cell_view_get_displayed_row, 1},
    {"R_gtk_cell_view_get_draw_sensitive", (DL_FUNC) &R_gtk_cell_view_get_draw_sensitive, 1},
    {"R_gtk_cell_view_get_fit_model", (DL_FUNC) &R_gtk_cell_view_get_fit_model, 1},
    {"R_gtk_cell_view_get_model", (DL_FUNC) &R_gtk_cell_view_get_model, 1},
    {"R_gtk_cell_view_set_displayed_row", (DL_FUNC) &R_gtk_cell_view_set_displayed_row, 2},
    {"R_gtk_cell_view_set_draw_sensitive", (DL_FUNC) &R_gtk_cell_view_set_draw_sensitive, 2},
    {"R_gtk_cell_view_set_fit_model", (DL_FUNC) &R_gtk_cell_view_set_fit_model, 2},
    {"R_gtk_cell_view_set_model", (DL_FUNC) &R_gtk_cell_view_set_model, 2},
    {"R_gtk_center_box_new", (DL_FUNC) &R_gtk_center_box_new, 0},
    {"R_gtk_center_box_get_baseline_position", (DL_FUNC) &R_gtk_center_box_get_baseline_position, 1},
    {"R_gtk_center_box_get_center_widget", (DL_FUNC) &R_gtk_center_box_get_center_widget, 1},
    {"R_gtk_center_box_get_end_widget", (DL_FUNC) &R_gtk_center_box_get_end_widget, 1},
    {"R_gtk_center_box_get_shrink_center_last", (DL_FUNC) &R_gtk_center_box_get_shrink_center_last, 1},
    {"R_gtk_center_box_get_start_widget", (DL_FUNC) &R_gtk_center_box_get_start_widget, 1},
    {"R_gtk_center_box_set_baseline_position", (DL_FUNC) &R_gtk_center_box_set_baseline_position, 2},
    {"R_gtk_center_box_set_center_widget", (DL_FUNC) &R_gtk_center_box_set_center_widget, 2},
    {"R_gtk_center_box_set_end_widget", (DL_FUNC) &R_gtk_center_box_set_end_widget, 2},
    {"R_gtk_center_box_set_shrink_center_last", (DL_FUNC) &R_gtk_center_box_set_shrink_center_last, 2},
    {"R_gtk_center_box_set_start_widget", (DL_FUNC) &R_gtk_center_box_set_start_widget, 2},
    {"R_gtk_center_layout_new", (DL_FUNC) &R_gtk_center_layout_new, 0},
    {"R_gtk_center_layout_get_baseline_position", (DL_FUNC) &R_gtk_center_layout_get_baseline_position, 1},
    {"R_gtk_center_layout_get_center_widget", (DL_FUNC) &R_gtk_center_layout_get_center_widget, 1},
    {"R_gtk_center_layout_get_end_widget", (DL_FUNC) &R_gtk_center_layout_get_end_widget, 1},
    {"R_gtk_center_layout_get_orientation", (DL_FUNC) &R_gtk_center_layout_get_orientation, 1},
    {"R_gtk_center_layout_get_shrink_center_last", (DL_FUNC) &R_gtk_center_layout_get_shrink_center_last, 1},
    {"R_gtk_center_layout_get_start_widget", (DL_FUNC) &R_gtk_center_layout_get_start_widget, 1},
    {"R_gtk_center_layout_set_baseline_position", (DL_FUNC) &R_gtk_center_layout_set_baseline_position, 2},
    {"R_gtk_center_layout_set_center_widget", (DL_FUNC) &R_gtk_center_layout_set_center_widget, 2},
    {"R_gtk_center_layout_set_end_widget", (DL_FUNC) &R_gtk_center_layout_set_end_widget, 2},
    {"R_gtk_center_layout_set_orientation", (DL_FUNC) &R_gtk_center_layout_set_orientation, 2},
    {"R_gtk_center_layout_set_shrink_center_last", (DL_FUNC) &R_gtk_center_layout_set_shrink_center_last, 2},
    {"R_gtk_center_layout_set_start_widget", (DL_FUNC) &R_gtk_center_layout_set_start_widget, 2},
    {"R_gtk_check_button_new", (DL_FUNC) &R_gtk_check_button_new, 0},
    {"R_gtk_check_button_new_with_label", (DL_FUNC) &R_gtk_check_button_new_with_label, 1},
    {"R_gtk_check_button_new_with_mnemonic", (DL_FUNC) &R_gtk_check_button_new_with_mnemonic, 1},
    {"R_gtk_check_button_get_active", (DL_FUNC) &R_gtk_check_button_get_active, 1},
    {"R_gtk_check_button_get_child", (DL_FUNC) &R_gtk_check_button_get_child, 1},
    {"R_gtk_check_button_get_inconsistent", (DL_FUNC) &R_gtk_check_button_get_inconsistent, 1},
    {"R_gtk_check_button_get_label", (DL_FUNC) &R_gtk_check_button_get_label, 1},
    {"R_gtk_check_button_get_use_underline", (DL_FUNC) &R_gtk_check_button_get_use_underline, 1},
    {"R_gtk_check_button_set_active", (DL_FUNC) &R_gtk_check_button_set_active, 2},
    {"R_gtk_check_button_set_child", (DL_FUNC) &R_gtk_check_button_set_child, 2},
    {"R_gtk_check_button_set_group", (DL_FUNC) &R_gtk_check_button_set_group, 2},
    {"R_gtk_check_button_set_inconsistent", (DL_FUNC) &R_gtk_check_button_set_inconsistent, 2},
    {"R_gtk_check_button_set_label", (DL_FUNC) &R_gtk_check_button_set_label, 2},
    {"R_gtk_check_button_set_use_underline", (DL_FUNC) &R_gtk_check_button_set_use_underline, 2},
    {"R_gtk_closure_expression_new", (DL_FUNC) &R_gtk_closure_expression_new, 4},
    {"R_gtk_color_button_new", (DL_FUNC) &R_gtk_color_button_new, 0},
    {"R_gtk_color_button_new_with_rgba", (DL_FUNC) &R_gtk_color_button_new_with_rgba, 1},
    {"R_gtk_color_button_get_modal", (DL_FUNC) &R_gtk_color_button_get_modal, 1},
    {"R_gtk_color_button_get_title", (DL_FUNC) &R_gtk_color_button_get_title, 1},
    {"R_gtk_color_button_set_modal", (DL_FUNC) &R_gtk_color_button_set_modal, 2},
    {"R_gtk_color_button_set_title", (DL_FUNC) &R_gtk_color_button_set_title, 2},
    {"R_gtk_color_chooser_add_palette", (DL_FUNC) &R_gtk_color_chooser_add_palette, 5},
    {"R_gtk_color_chooser_get_rgba", (DL_FUNC) &R_gtk_color_chooser_get_rgba, 1},
    {"R_gtk_color_chooser_get_use_alpha", (DL_FUNC) &R_gtk_color_chooser_get_use_alpha, 1},
    {"R_gtk_color_chooser_set_rgba", (DL_FUNC) &R_gtk_color_chooser_set_rgba, 2},
    {"R_gtk_color_chooser_set_use_alpha", (DL_FUNC) &R_gtk_color_chooser_set_use_alpha, 2},
    {"R_gtk_color_chooser_dialog_new", (DL_FUNC) &R_gtk_color_chooser_dialog_new, 2},
    {"R_gtk_color_chooser_widget_new", (DL_FUNC) &R_gtk_color_chooser_widget_new, 0},
    {"R_gtk_color_dialog_new", (DL_FUNC) &R_gtk_color_dialog_new, 0},
    {"R_gtk_color_dialog_choose_rgba", (DL_FUNC) &R_gtk_color_dialog_choose_rgba, 6},
    {"R_gtk_color_dialog_choose_rgba_finish", (DL_FUNC) &R_gtk_color_dialog_choose_rgba_finish, 2},
    {"R_gtk_color_dialog_get_modal", (DL_FUNC) &R_gtk_color_dialog_get_modal, 1},
    {"R_gtk_color_dialog_get_title", (DL_FUNC) &R_gtk_color_dialog_get_title, 1},
    {"R_gtk_color_dialog_get_with_alpha", (DL_FUNC) &R_gtk_color_dialog_get_with_alpha, 1},
    {"R_gtk_color_dialog_set_modal", (DL_FUNC) &R_gtk_color_dialog_set_modal, 2},
    {"R_gtk_color_dialog_set_title", (DL_FUNC) &R_gtk_color_dialog_set_title, 2},
    {"R_gtk_color_dialog_set_with_alpha", (DL_FUNC) &R_gtk_color_dialog_set_with_alpha, 2},
    {"R_gtk_color_dialog_button_new", (DL_FUNC) &R_gtk_color_dialog_button_new, 1},
    {"R_gtk_color_dialog_button_get_dialog", (DL_FUNC) &R_gtk_color_dialog_button_get_dialog, 1},
    {"R_gtk_color_dialog_button_get_rgba", (DL_FUNC) &R_gtk_color_dialog_button_get_rgba, 1},
    {"R_gtk_color_dialog_button_set_dialog", (DL_FUNC) &R_gtk_color_dialog_button_set_dialog, 2},
    {"R_gtk_color_dialog_button_set_rgba", (DL_FUNC) &R_gtk_color_dialog_button_set_rgba, 2},
    {"R_gtk_column_view_new", (DL_FUNC) &R_gtk_column_view_new, 1},
    {"R_gtk_column_view_append_column", (DL_FUNC) &R_gtk_column_view_append_column, 2},
    {"R_gtk_column_view_get_columns", (DL_FUNC) &R_gtk_column_view_get_columns, 1},
    {"R_gtk_column_view_get_enable_rubberband", (DL_FUNC) &R_gtk_column_view_get_enable_rubberband, 1},
    {"R_gtk_column_view_get_header_factory", (DL_FUNC) &R_gtk_column_view_get_header_factory, 1},
    {"R_gtk_column_view_get_model", (DL_FUNC) &R_gtk_column_view_get_model, 1},
    {"R_gtk_column_view_get_reorderable", (DL_FUNC) &R_gtk_column_view_get_reorderable, 1},
    {"R_gtk_column_view_get_row_factory", (DL_FUNC) &R_gtk_column_view_get_row_factory, 1},
    {"R_gtk_column_view_get_show_column_separators", (DL_FUNC) &R_gtk_column_view_get_show_column_separators, 1},
    {"R_gtk_column_view_get_show_row_separators", (DL_FUNC) &R_gtk_column_view_get_show_row_separators, 1},
    {"R_gtk_column_view_get_single_click_activate", (DL_FUNC) &R_gtk_column_view_get_single_click_activate, 1},
    {"R_gtk_column_view_get_sorter", (DL_FUNC) &R_gtk_column_view_get_sorter, 1},
    {"R_gtk_column_view_get_tab_behavior", (DL_FUNC) &R_gtk_column_view_get_tab_behavior, 1},
    {"R_gtk_column_view_insert_column", (DL_FUNC) &R_gtk_column_view_insert_column, 3},
    {"R_gtk_column_view_remove_column", (DL_FUNC) &R_gtk_column_view_remove_column, 2},
    {"R_gtk_column_view_scroll_to", (DL_FUNC) &R_gtk_column_view_scroll_to, 5},
    {"R_gtk_column_view_set_enable_rubberband", (DL_FUNC) &R_gtk_column_view_set_enable_rubberband, 2},
    {"R_gtk_column_view_set_header_factory", (DL_FUNC) &R_gtk_column_view_set_header_factory, 2},
    {"R_gtk_column_view_set_model", (DL_FUNC) &R_gtk_column_view_set_model, 2},
    {"R_gtk_column_view_set_reorderable", (DL_FUNC) &R_gtk_column_view_set_reorderable, 2},
    {"R_gtk_column_view_set_row_factory", (DL_FUNC) &R_gtk_column_view_set_row_factory, 2},
    {"R_gtk_column_view_set_show_column_separators", (DL_FUNC) &R_gtk_column_view_set_show_column_separators, 2},
    {"R_gtk_column_view_set_show_row_separators", (DL_FUNC) &R_gtk_column_view_set_show_row_separators, 2},
    {"R_gtk_column_view_set_single_click_activate", (DL_FUNC) &R_gtk_column_view_set_single_click_activate, 2},
    {"R_gtk_column_view_set_tab_behavior", (DL_FUNC) &R_gtk_column_view_set_tab_behavior, 2},
    {"R_gtk_column_view_sort_by_column", (DL_FUNC) &R_gtk_column_view_sort_by_column, 3},
    {"R_gtk_column_view_cell_get_child", (DL_FUNC) &R_gtk_column_view_cell_get_child, 1},
    {"R_gtk_column_view_cell_get_focusable", (DL_FUNC) &R_gtk_column_view_cell_get_focusable, 1},
    {"R_gtk_column_view_cell_get_item", (DL_FUNC) &R_gtk_column_view_cell_get_item, 1},
    {"R_gtk_column_view_cell_get_position", (DL_FUNC) &R_gtk_column_view_cell_get_position, 1},
    {"R_gtk_column_view_cell_get_selected", (DL_FUNC) &R_gtk_column_view_cell_get_selected, 1},
    {"R_gtk_column_view_cell_set_child", (DL_FUNC) &R_gtk_column_view_cell_set_child, 2},
    {"R_gtk_column_view_cell_set_focusable", (DL_FUNC) &R_gtk_column_view_cell_set_focusable, 2},
    {"R_gtk_column_view_column_new", (DL_FUNC) &R_gtk_column_view_column_new, 2},
    {"R_gtk_column_view_column_get_column_view", (DL_FUNC) &R_gtk_column_view_column_get_column_view, 1},
    {"R_gtk_column_view_column_get_expand", (DL_FUNC) &R_gtk_column_view_column_get_expand, 1},
    {"R_gtk_column_view_column_get_factory", (DL_FUNC) &R_gtk_column_view_column_get_factory, 1},
    {"R_gtk_column_view_column_get_fixed_width", (DL_FUNC) &R_gtk_column_view_column_get_fixed_width, 1},
    {"R_gtk_column_view_column_get_header_menu", (DL_FUNC) &R_gtk_column_view_column_get_header_menu, 1},
    {"R_gtk_column_view_column_get_id", (DL_FUNC) &R_gtk_column_view_column_get_id, 1},
    {"R_gtk_column_view_column_get_resizable", (DL_FUNC) &R_gtk_column_view_column_get_resizable, 1},
    {"R_gtk_column_view_column_get_sorter", (DL_FUNC) &R_gtk_column_view_column_get_sorter, 1},
    {"R_gtk_column_view_column_get_title", (DL_FUNC) &R_gtk_column_view_column_get_title, 1},
    {"R_gtk_column_view_column_get_visible", (DL_FUNC) &R_gtk_column_view_column_get_visible, 1},
    {"R_gtk_column_view_column_set_expand", (DL_FUNC) &R_gtk_column_view_column_set_expand, 2},
    {"R_gtk_column_view_column_set_factory", (DL_FUNC) &R_gtk_column_view_column_set_factory, 2},
    {"R_gtk_column_view_column_set_fixed_width", (DL_FUNC) &R_gtk_column_view_column_set_fixed_width, 2},
    {"R_gtk_column_view_column_set_header_menu", (DL_FUNC) &R_gtk_column_view_column_set_header_menu, 2},
    {"R_gtk_column_view_column_set_id", (DL_FUNC) &R_gtk_column_view_column_set_id, 2},
    {"R_gtk_column_view_column_set_resizable", (DL_FUNC) &R_gtk_column_view_column_set_resizable, 2},
    {"R_gtk_column_view_column_set_sorter", (DL_FUNC) &R_gtk_column_view_column_set_sorter, 2},
    {"R_gtk_column_view_column_set_title", (DL_FUNC) &R_gtk_column_view_column_set_title, 2},
    {"R_gtk_column_view_column_set_visible", (DL_FUNC) &R_gtk_column_view_column_set_visible, 2},
    {"R_gtk_column_view_row_get_accessible_description", (DL_FUNC) &R_gtk_column_view_row_get_accessible_description, 1},
    {"R_gtk_column_view_row_get_accessible_label", (DL_FUNC) &R_gtk_column_view_row_get_accessible_label, 1},
    {"R_gtk_column_view_row_get_activatable", (DL_FUNC) &R_gtk_column_view_row_get_activatable, 1},
    {"R_gtk_column_view_row_get_focusable", (DL_FUNC) &R_gtk_column_view_row_get_focusable, 1},
    {"R_gtk_column_view_row_get_item", (DL_FUNC) &R_gtk_column_view_row_get_item, 1},
    {"R_gtk_column_view_row_get_position", (DL_FUNC) &R_gtk_column_view_row_get_position, 1},
    {"R_gtk_column_view_row_get_selectable", (DL_FUNC) &R_gtk_column_view_row_get_selectable, 1},
    {"R_gtk_column_view_row_get_selected", (DL_FUNC) &R_gtk_column_view_row_get_selected, 1},
    {"R_gtk_column_view_row_set_accessible_description", (DL_FUNC) &R_gtk_column_view_row_set_accessible_description, 2},
    {"R_gtk_column_view_row_set_accessible_label", (DL_FUNC) &R_gtk_column_view_row_set_accessible_label, 2},
    {"R_gtk_column_view_row_set_activatable", (DL_FUNC) &R_gtk_column_view_row_set_activatable, 2},
    {"R_gtk_column_view_row_set_focusable", (DL_FUNC) &R_gtk_column_view_row_set_focusable, 2},
    {"R_gtk_column_view_row_set_selectable", (DL_FUNC) &R_gtk_column_view_row_set_selectable, 2},
    {"R_gtk_column_view_sorter_get_n_sort_columns", (DL_FUNC) &R_gtk_column_view_sorter_get_n_sort_columns, 1},
    {"R_gtk_column_view_sorter_get_nth_sort_column", (DL_FUNC) &R_gtk_column_view_sorter_get_nth_sort_column, 2},
    {"R_gtk_column_view_sorter_get_primary_sort_column", (DL_FUNC) &R_gtk_column_view_sorter_get_primary_sort_column, 1},
    {"R_gtk_column_view_sorter_get_primary_sort_order", (DL_FUNC) &R_gtk_column_view_sorter_get_primary_sort_order, 1},
    {"R_gtk_combo_box_new", (DL_FUNC) &R_gtk_combo_box_new, 0},
    {"R_gtk_combo_box_new_with_entry", (DL_FUNC) &R_gtk_combo_box_new_with_entry, 0},
    {"R_gtk_combo_box_new_with_model", (DL_FUNC) &R_gtk_combo_box_new_with_model, 1},
    {"R_gtk_combo_box_new_with_model_and_entry", (DL_FUNC) &R_gtk_combo_box_new_with_model_and_entry, 1},
    {"R_gtk_combo_box_get_active", (DL_FUNC) &R_gtk_combo_box_get_active, 1},
    {"R_gtk_combo_box_get_active_id", (DL_FUNC) &R_gtk_combo_box_get_active_id, 1},
    {"R_gtk_combo_box_get_active_iter", (DL_FUNC) &R_gtk_combo_box_get_active_iter, 1},
    {"R_gtk_combo_box_get_button_sensitivity", (DL_FUNC) &R_gtk_combo_box_get_button_sensitivity, 1},
    {"R_gtk_combo_box_get_child", (DL_FUNC) &R_gtk_combo_box_get_child, 1},
    {"R_gtk_combo_box_get_entry_text_column", (DL_FUNC) &R_gtk_combo_box_get_entry_text_column, 1},
    {"R_gtk_combo_box_get_has_entry", (DL_FUNC) &R_gtk_combo_box_get_has_entry, 1},
    {"R_gtk_combo_box_get_id_column", (DL_FUNC) &R_gtk_combo_box_get_id_column, 1},
    {"R_gtk_combo_box_get_model", (DL_FUNC) &R_gtk_combo_box_get_model, 1},
    {"R_gtk_combo_box_get_popup_fixed_width", (DL_FUNC) &R_gtk_combo_box_get_popup_fixed_width, 1},
    {"R_gtk_combo_box_popdown", (DL_FUNC) &R_gtk_combo_box_popdown, 1},
    {"R_gtk_combo_box_popup", (DL_FUNC) &R_gtk_combo_box_popup, 1},
    {"R_gtk_combo_box_popup_for_device", (DL_FUNC) &R_gtk_combo_box_popup_for_device, 2},
    {"R_gtk_combo_box_set_active", (DL_FUNC) &R_gtk_combo_box_set_active, 2},
    {"R_gtk_combo_box_set_active_id", (DL_FUNC) &R_gtk_combo_box_set_active_id, 2},
    {"R_gtk_combo_box_set_active_iter", (DL_FUNC) &R_gtk_combo_box_set_active_iter, 2},
    {"R_gtk_combo_box_set_button_sensitivity", (DL_FUNC) &R_gtk_combo_box_set_button_sensitivity, 2},
    {"R_gtk_combo_box_set_child", (DL_FUNC) &R_gtk_combo_box_set_child, 2},
    {"R_gtk_combo_box_set_entry_text_column", (DL_FUNC) &R_gtk_combo_box_set_entry_text_column, 2},
    {"R_gtk_combo_box_set_id_column", (DL_FUNC) &R_gtk_combo_box_set_id_column, 2},
    {"R_gtk_combo_box_set_model", (DL_FUNC) &R_gtk_combo_box_set_model, 2},
    {"R_gtk_combo_box_set_popup_fixed_width", (DL_FUNC) &R_gtk_combo_box_set_popup_fixed_width, 2},
    {"R_gtk_combo_box_set_row_separator_func", (DL_FUNC) &R_gtk_combo_box_set_row_separator_func, 4},
    {"R_gtk_combo_box_text_new", (DL_FUNC) &R_gtk_combo_box_text_new, 0},
    {"R_gtk_combo_box_text_new_with_entry", (DL_FUNC) &R_gtk_combo_box_text_new_with_entry, 0},
    {"R_gtk_combo_box_text_append", (DL_FUNC) &R_gtk_combo_box_text_append, 3},
    {"R_gtk_combo_box_text_append_text", (DL_FUNC) &R_gtk_combo_box_text_append_text, 2},
    {"R_gtk_combo_box_text_get_active_text", (DL_FUNC) &R_gtk_combo_box_text_get_active_text, 1},
    {"R_gtk_combo_box_text_insert", (DL_FUNC) &R_gtk_combo_box_text_insert, 4},
    {"R_gtk_combo_box_text_insert_text", (DL_FUNC) &R_gtk_combo_box_text_insert_text, 3},
    {"R_gtk_combo_box_text_prepend", (DL_FUNC) &R_gtk_combo_box_text_prepend, 3},
    {"R_gtk_combo_box_text_prepend_text", (DL_FUNC) &R_gtk_combo_box_text_prepend_text, 2},
    {"R_gtk_combo_box_text_remove", (DL_FUNC) &R_gtk_combo_box_text_remove, 2},
    {"R_gtk_combo_box_text_remove_all", (DL_FUNC) &R_gtk_combo_box_text_remove_all, 1},
    {"R_gtk_constant_expression_new_for_value", (DL_FUNC) &R_gtk_constant_expression_new_for_value, 1},
    {"R_gtk_constant_expression_get_value", (DL_FUNC) &R_gtk_constant_expression_get_value, 1},
    {"R_gtk_constraint_new", (DL_FUNC) &R_gtk_constraint_new, 8},
    {"R_gtk_constraint_new_constant", (DL_FUNC) &R_gtk_constraint_new_constant, 5},
    {"R_gtk_constraint_get_constant", (DL_FUNC) &R_gtk_constraint_get_constant, 1},
    {"R_gtk_constraint_get_multiplier", (DL_FUNC) &R_gtk_constraint_get_multiplier, 1},
    {"R_gtk_constraint_get_relation", (DL_FUNC) &R_gtk_constraint_get_relation, 1},
    {"R_gtk_constraint_get_source", (DL_FUNC) &R_gtk_constraint_get_source, 1},
    {"R_gtk_constraint_get_source_attribute", (DL_FUNC) &R_gtk_constraint_get_source_attribute, 1},
    {"R_gtk_constraint_get_strength", (DL_FUNC) &R_gtk_constraint_get_strength, 1},
    {"R_gtk_constraint_get_target", (DL_FUNC) &R_gtk_constraint_get_target, 1},
    {"R_gtk_constraint_get_target_attribute", (DL_FUNC) &R_gtk_constraint_get_target_attribute, 1},
    {"R_gtk_constraint_is_attached", (DL_FUNC) &R_gtk_constraint_is_attached, 1},
    {"R_gtk_constraint_is_constant", (DL_FUNC) &R_gtk_constraint_is_constant, 1},
    {"R_gtk_constraint_is_required", (DL_FUNC) &R_gtk_constraint_is_required, 1},
    {"R_gtk_constraint_guide_new", (DL_FUNC) &R_gtk_constraint_guide_new, 0},
    {"R_gtk_constraint_guide_get_max_size", (DL_FUNC) &R_gtk_constraint_guide_get_max_size, 1},
    {"R_gtk_constraint_guide_get_min_size", (DL_FUNC) &R_gtk_constraint_guide_get_min_size, 1},
    {"R_gtk_constraint_guide_get_name", (DL_FUNC) &R_gtk_constraint_guide_get_name, 1},
    {"R_gtk_constraint_guide_get_nat_size", (DL_FUNC) &R_gtk_constraint_guide_get_nat_size, 1},
    {"R_gtk_constraint_guide_get_strength", (DL_FUNC) &R_gtk_constraint_guide_get_strength, 1},
    {"R_gtk_constraint_guide_set_max_size", (DL_FUNC) &R_gtk_constraint_guide_set_max_size, 3},
    {"R_gtk_constraint_guide_set_min_size", (DL_FUNC) &R_gtk_constraint_guide_set_min_size, 3},
    {"R_gtk_constraint_guide_set_name", (DL_FUNC) &R_gtk_constraint_guide_set_name, 2},
    {"R_gtk_constraint_guide_set_nat_size", (DL_FUNC) &R_gtk_constraint_guide_set_nat_size, 3},
    {"R_gtk_constraint_guide_set_strength", (DL_FUNC) &R_gtk_constraint_guide_set_strength, 2},
    {"R_gtk_constraint_layout_new", (DL_FUNC) &R_gtk_constraint_layout_new, 0},
    {"R_gtk_constraint_layout_add_constraint", (DL_FUNC) &R_gtk_constraint_layout_add_constraint, 2},
    {"R_gtk_constraint_layout_add_constraints_from_descriptionv", (DL_FUNC) &R_gtk_constraint_layout_add_constraints_from_descriptionv, 6},
    {"R_gtk_constraint_layout_add_guide", (DL_FUNC) &R_gtk_constraint_layout_add_guide, 2},
    {"R_gtk_constraint_layout_observe_constraints", (DL_FUNC) &R_gtk_constraint_layout_observe_constraints, 1},
    {"R_gtk_constraint_layout_observe_guides", (DL_FUNC) &R_gtk_constraint_layout_observe_guides, 1},
    {"R_gtk_constraint_layout_remove_all_constraints", (DL_FUNC) &R_gtk_constraint_layout_remove_all_constraints, 1},
    {"R_gtk_constraint_layout_remove_constraint", (DL_FUNC) &R_gtk_constraint_layout_remove_constraint, 2},
    {"R_gtk_constraint_layout_remove_guide", (DL_FUNC) &R_gtk_constraint_layout_remove_guide, 2},
    {"R_gtk_constraint_vfl_parser_error_quark", (DL_FUNC) &R_gtk_constraint_vfl_parser_error_quark, 0},
    {"R_gtk_css_provider_new", (DL_FUNC) &R_gtk_css_provider_new, 0},
    {"R_gtk_css_provider_load_from_bytes", (DL_FUNC) &R_gtk_css_provider_load_from_bytes, 2},
    {"R_gtk_css_provider_load_from_data", (DL_FUNC) &R_gtk_css_provider_load_from_data, 3},
    {"R_gtk_css_provider_load_from_file", (DL_FUNC) &R_gtk_css_provider_load_from_file, 2},
    {"R_gtk_css_provider_load_from_path", (DL_FUNC) &R_gtk_css_provider_load_from_path, 2},
    {"R_gtk_css_provider_load_from_resource", (DL_FUNC) &R_gtk_css_provider_load_from_resource, 2},
    {"R_gtk_css_provider_load_from_string", (DL_FUNC) &R_gtk_css_provider_load_from_string, 2},
    {"R_gtk_css_provider_load_named", (DL_FUNC) &R_gtk_css_provider_load_named, 3},
    {"R_gtk_css_provider_to_string", (DL_FUNC) &R_gtk_css_provider_to_string, 1},
    {"R_gtk_css_section_new", (DL_FUNC) &R_gtk_css_section_new, 3},
    {"R_gtk_css_section_get_end_location", (DL_FUNC) &R_gtk_css_section_get_end_location, 1},
    {"R_gtk_css_section_get_file", (DL_FUNC) &R_gtk_css_section_get_file, 1},
    {"R_gtk_css_section_get_parent", (DL_FUNC) &R_gtk_css_section_get_parent, 1},
    {"R_gtk_css_section_get_start_location", (DL_FUNC) &R_gtk_css_section_get_start_location, 1},
    {"R_gtk_css_section_print", (DL_FUNC) &R_gtk_css_section_print, 2},
    {"R_gtk_css_section_ref", (DL_FUNC) &R_gtk_css_section_ref, 1},
    {"R_gtk_css_section_to_string", (DL_FUNC) &R_gtk_css_section_to_string, 1},
    {"R_gtk_css_section_unref", (DL_FUNC) &R_gtk_css_section_unref, 1},
    {"R_gtk_custom_filter_new", (DL_FUNC) &R_gtk_custom_filter_new, 3},
    {"R_gtk_custom_filter_set_filter_func", (DL_FUNC) &R_gtk_custom_filter_set_filter_func, 4},
    {"R_gtk_custom_layout_new", (DL_FUNC) &R_gtk_custom_layout_new, 3},
    {"R_gtk_custom_sorter_new", (DL_FUNC) &R_gtk_custom_sorter_new, 3},
    {"R_gtk_custom_sorter_set_sort_func", (DL_FUNC) &R_gtk_custom_sorter_set_sort_func, 4},
    {"R_gtk_dialog_new", (DL_FUNC) &R_gtk_dialog_new, 0},
    {"R_gtk_dialog_add_action_widget", (DL_FUNC) &R_gtk_dialog_add_action_widget, 3},
    {"R_gtk_dialog_add_button", (DL_FUNC) &R_gtk_dialog_add_button, 3},
    {"R_gtk_dialog_get_content_area", (DL_FUNC) &R_gtk_dialog_get_content_area, 1},
    {"R_gtk_dialog_get_header_bar", (DL_FUNC) &R_gtk_dialog_get_header_bar, 1},
    {"R_gtk_dialog_get_response_for_widget", (DL_FUNC) &R_gtk_dialog_get_response_for_widget, 2},
    {"R_gtk_dialog_get_widget_for_response", (DL_FUNC) &R_gtk_dialog_get_widget_for_response, 2},
    {"R_gtk_dialog_response", (DL_FUNC) &R_gtk_dialog_response, 2},
    {"R_gtk_dialog_set_default_response", (DL_FUNC) &R_gtk_dialog_set_default_response, 2},
    {"R_gtk_dialog_set_response_sensitive", (DL_FUNC) &R_gtk_dialog_set_response_sensitive, 3},
    {"R_gtk_dialog_error_quark", (DL_FUNC) &R_gtk_dialog_error_quark, 0},
    {"R_gtk_directory_list_new", (DL_FUNC) &R_gtk_directory_list_new, 2},
    {"R_gtk_directory_list_get_attributes", (DL_FUNC) &R_gtk_directory_list_get_attributes, 1},
    {"R_gtk_directory_list_get_error", (DL_FUNC) &R_gtk_directory_list_get_error, 1},
    {"R_gtk_directory_list_get_file", (DL_FUNC) &R_gtk_directory_list_get_file, 1},
    {"R_gtk_directory_list_get_io_priority", (DL_FUNC) &R_gtk_directory_list_get_io_priority, 1},
    {"R_gtk_directory_list_get_monitored", (DL_FUNC) &R_gtk_directory_list_get_monitored, 1},
    {"R_gtk_directory_list_is_loading", (DL_FUNC) &R_gtk_directory_list_is_loading, 1},
    {"R_gtk_directory_list_set_attributes", (DL_FUNC) &R_gtk_directory_list_set_attributes, 2},
    {"R_gtk_directory_list_set_file", (DL_FUNC) &R_gtk_directory_list_set_file, 2},
    {"R_gtk_directory_list_set_io_priority", (DL_FUNC) &R_gtk_directory_list_set_io_priority, 2},
    {"R_gtk_directory_list_set_monitored", (DL_FUNC) &R_gtk_directory_list_set_monitored, 2},
    {"R_gtk_drag_icon_get_for_drag", (DL_FUNC) &R_gtk_drag_icon_get_for_drag, 1},
    {"R_gtk_drag_icon_create_widget_for_value", (DL_FUNC) &R_gtk_drag_icon_create_widget_for_value, 1},
    {"R_gtk_drag_icon_set_from_paintable", (DL_FUNC) &R_gtk_drag_icon_set_from_paintable, 4},
    {"R_gtk_drag_icon_get_child", (DL_FUNC) &R_gtk_drag_icon_get_child, 1},
    {"R_gtk_drag_icon_set_child", (DL_FUNC) &R_gtk_drag_icon_set_child, 2},
    {"R_gtk_drag_source_new", (DL_FUNC) &R_gtk_drag_source_new, 0},
    {"R_gtk_drag_source_drag_cancel", (DL_FUNC) &R_gtk_drag_source_drag_cancel, 1},
    {"R_gtk_drag_source_get_actions", (DL_FUNC) &R_gtk_drag_source_get_actions, 1},
    {"R_gtk_drag_source_get_content", (DL_FUNC) &R_gtk_drag_source_get_content, 1},
    {"R_gtk_drag_source_get_drag", (DL_FUNC) &R_gtk_drag_source_get_drag, 1},
    {"R_gtk_drag_source_set_actions", (DL_FUNC) &R_gtk_drag_source_set_actions, 2},
    {"R_gtk_drag_source_set_content", (DL_FUNC) &R_gtk_drag_source_set_content, 2},
    {"R_gtk_drag_source_set_icon", (DL_FUNC) &R_gtk_drag_source_set_icon, 4},
    {"R_gtk_drawing_area_new", (DL_FUNC) &R_gtk_drawing_area_new, 0},
    {"R_gtk_drawing_area_get_content_height", (DL_FUNC) &R_gtk_drawing_area_get_content_height, 1},
    {"R_gtk_drawing_area_get_content_width", (DL_FUNC) &R_gtk_drawing_area_get_content_width, 1},
    {"R_gtk_drawing_area_set_content_height", (DL_FUNC) &R_gtk_drawing_area_set_content_height, 2},
    {"R_gtk_drawing_area_set_content_width", (DL_FUNC) &R_gtk_drawing_area_set_content_width, 2},
    {"R_gtk_drawing_area_set_draw_func", (DL_FUNC) &R_gtk_drawing_area_set_draw_func, 4},
    {"R_gtk_drop_controller_motion_new", (DL_FUNC) &R_gtk_drop_controller_motion_new, 0},
    {"R_gtk_drop_controller_motion_contains_pointer", (DL_FUNC) &R_gtk_drop_controller_motion_contains_pointer, 1},
    {"R_gtk_drop_controller_motion_get_drop", (DL_FUNC) &R_gtk_drop_controller_motion_get_drop, 1},
    {"R_gtk_drop_controller_motion_is_pointer", (DL_FUNC) &R_gtk_drop_controller_motion_is_pointer, 1},
    {"R_gtk_drop_down_new", (DL_FUNC) &R_gtk_drop_down_new, 2},
    {"R_gtk_drop_down_new_from_strings", (DL_FUNC) &R_gtk_drop_down_new_from_strings, 1},
    {"R_gtk_drop_down_get_enable_search", (DL_FUNC) &R_gtk_drop_down_get_enable_search, 1},
    {"R_gtk_drop_down_get_expression", (DL_FUNC) &R_gtk_drop_down_get_expression, 1},
    {"R_gtk_drop_down_get_factory", (DL_FUNC) &R_gtk_drop_down_get_factory, 1},
    {"R_gtk_drop_down_get_header_factory", (DL_FUNC) &R_gtk_drop_down_get_header_factory, 1},
    {"R_gtk_drop_down_get_list_factory", (DL_FUNC) &R_gtk_drop_down_get_list_factory, 1},
    {"R_gtk_drop_down_get_model", (DL_FUNC) &R_gtk_drop_down_get_model, 1},
    {"R_gtk_drop_down_get_search_match_mode", (DL_FUNC) &R_gtk_drop_down_get_search_match_mode, 1},
    {"R_gtk_drop_down_get_selected", (DL_FUNC) &R_gtk_drop_down_get_selected, 1},
    {"R_gtk_drop_down_get_selected_item", (DL_FUNC) &R_gtk_drop_down_get_selected_item, 1},
    {"R_gtk_drop_down_get_show_arrow", (DL_FUNC) &R_gtk_drop_down_get_show_arrow, 1},
    {"R_gtk_drop_down_set_enable_search", (DL_FUNC) &R_gtk_drop_down_set_enable_search, 2},
    {"R_gtk_drop_down_set_expression", (DL_FUNC) &R_gtk_drop_down_set_expression, 2},
    {"R_gtk_drop_down_set_factory", (DL_FUNC) &R_gtk_drop_down_set_factory, 2},
    {"R_gtk_drop_down_set_header_factory", (DL_FUNC) &R_gtk_drop_down_set_header_factory, 2},
    {"R_gtk_drop_down_set_list_factory", (DL_FUNC) &R_gtk_drop_down_set_list_factory, 2},
    {"R_gtk_drop_down_set_model", (DL_FUNC) &R_gtk_drop_down_set_model, 2},
    {"R_gtk_drop_down_set_search_match_mode", (DL_FUNC) &R_gtk_drop_down_set_search_match_mode, 2},
    {"R_gtk_drop_down_set_selected", (DL_FUNC) &R_gtk_drop_down_set_selected, 2},
    {"R_gtk_drop_down_set_show_arrow", (DL_FUNC) &R_gtk_drop_down_set_show_arrow, 2},
    {"R_gtk_drop_target_new", (DL_FUNC) &R_gtk_drop_target_new, 2},
    {"R_gtk_drop_target_get_actions", (DL_FUNC) &R_gtk_drop_target_get_actions, 1},
    {"R_gtk_drop_target_get_current_drop", (DL_FUNC) &R_gtk_drop_target_get_current_drop, 1},
    {"R_gtk_drop_target_get_drop", (DL_FUNC) &R_gtk_drop_target_get_drop, 1},
    {"R_gtk_drop_target_get_formats", (DL_FUNC) &R_gtk_drop_target_get_formats, 1},
    {"R_gtk_drop_target_get_gtypes", (DL_FUNC) &R_gtk_drop_target_get_gtypes, 1},
    {"R_gtk_drop_target_get_preload", (DL_FUNC) &R_gtk_drop_target_get_preload, 1},
    {"R_gtk_drop_target_get_value", (DL_FUNC) &R_gtk_drop_target_get_value, 1},
    {"R_gtk_drop_target_reject", (DL_FUNC) &R_gtk_drop_target_reject, 1},
    {"R_gtk_drop_target_set_actions", (DL_FUNC) &R_gtk_drop_target_set_actions, 2},
    {"R_gtk_drop_target_set_gtypes", (DL_FUNC) &R_gtk_drop_target_set_gtypes, 3},
    {"R_gtk_drop_target_set_preload", (DL_FUNC) &R_gtk_drop_target_set_preload, 2},
    {"R_gtk_drop_target_async_new", (DL_FUNC) &R_gtk_drop_target_async_new, 2},
    {"R_gtk_drop_target_async_get_actions", (DL_FUNC) &R_gtk_drop_target_async_get_actions, 1},
    {"R_gtk_drop_target_async_get_formats", (DL_FUNC) &R_gtk_drop_target_async_get_formats, 1},
    {"R_gtk_drop_target_async_reject_drop", (DL_FUNC) &R_gtk_drop_target_async_reject_drop, 2},
    {"R_gtk_drop_target_async_set_actions", (DL_FUNC) &R_gtk_drop_target_async_set_actions, 2},
    {"R_gtk_drop_target_async_set_formats", (DL_FUNC) &R_gtk_drop_target_async_set_formats, 2},
    {"R_gtk_editable_delegate_get_property", (DL_FUNC) &R_gtk_editable_delegate_get_property, 4},
    {"R_gtk_editable_delegate_set_property", (DL_FUNC) &R_gtk_editable_delegate_set_property, 4},
    {"R_gtk_editable_install_properties", (DL_FUNC) &R_gtk_editable_install_properties, 2},
    {"R_gtk_editable_delegate_get_accessible_platform_state", (DL_FUNC) &R_gtk_editable_delegate_get_accessible_platform_state, 2},
    {"R_gtk_editable_delete_selection", (DL_FUNC) &R_gtk_editable_delete_selection, 1},
    {"R_gtk_editable_delete_text", (DL_FUNC) &R_gtk_editable_delete_text, 3},
    {"R_gtk_editable_finish_delegate", (DL_FUNC) &R_gtk_editable_finish_delegate, 1},
    {"R_gtk_editable_get_alignment", (DL_FUNC) &R_gtk_editable_get_alignment, 1},
    {"R_gtk_editable_get_chars", (DL_FUNC) &R_gtk_editable_get_chars, 3},
    {"R_gtk_editable_get_delegate", (DL_FUNC) &R_gtk_editable_get_delegate, 1},
    {"R_gtk_editable_get_editable", (DL_FUNC) &R_gtk_editable_get_editable, 1},
    {"R_gtk_editable_get_enable_undo", (DL_FUNC) &R_gtk_editable_get_enable_undo, 1},
    {"R_gtk_editable_get_max_width_chars", (DL_FUNC) &R_gtk_editable_get_max_width_chars, 1},
    {"R_gtk_editable_get_position", (DL_FUNC) &R_gtk_editable_get_position, 1},
    {"R_gtk_editable_get_selection_bounds", (DL_FUNC) &R_gtk_editable_get_selection_bounds, 1},
    {"R_gtk_editable_get_text", (DL_FUNC) &R_gtk_editable_get_text, 1},
    {"R_gtk_editable_get_width_chars", (DL_FUNC) &R_gtk_editable_get_width_chars, 1},
    {"R_gtk_editable_init_delegate", (DL_FUNC) &R_gtk_editable_init_delegate, 1},
    {"R_gtk_editable_insert_text", (DL_FUNC) &R_gtk_editable_insert_text, 3},
    {"R_gtk_editable_select_region", (DL_FUNC) &R_gtk_editable_select_region, 3},
    {"R_gtk_editable_set_alignment", (DL_FUNC) &R_gtk_editable_set_alignment, 2},
    {"R_gtk_editable_set_editable", (DL_FUNC) &R_gtk_editable_set_editable, 2},
    {"R_gtk_editable_set_enable_undo", (DL_FUNC) &R_gtk_editable_set_enable_undo, 2},
    {"R_gtk_editable_set_max_width_chars", (DL_FUNC) &R_gtk_editable_set_max_width_chars, 2},
    {"R_gtk_editable_set_position", (DL_FUNC) &R_gtk_editable_set_position, 2},
    {"R_gtk_editable_set_text", (DL_FUNC) &R_gtk_editable_set_text, 2},
    {"R_gtk_editable_set_width_chars", (DL_FUNC) &R_gtk_editable_set_width_chars, 2},
    {"R_gtk_editable_label_new", (DL_FUNC) &R_gtk_editable_label_new, 1},
    {"R_gtk_editable_label_get_editing", (DL_FUNC) &R_gtk_editable_label_get_editing, 1},
    {"R_gtk_editable_label_start_editing", (DL_FUNC) &R_gtk_editable_label_start_editing, 1},
    {"R_gtk_editable_label_stop_editing", (DL_FUNC) &R_gtk_editable_label_stop_editing, 2},
    {"R_gtk_emoji_chooser_new", (DL_FUNC) &R_gtk_emoji_chooser_new, 0},
    {"R_gtk_entry_new", (DL_FUNC) &R_gtk_entry_new, 0},
    {"R_gtk_entry_new_with_buffer", (DL_FUNC) &R_gtk_entry_new_with_buffer, 1},
    {"R_gtk_entry_get_activates_default", (DL_FUNC) &R_gtk_entry_get_activates_default, 1},
    {"R_gtk_entry_get_alignment", (DL_FUNC) &R_gtk_entry_get_alignment, 1},
    {"R_gtk_entry_get_attributes", (DL_FUNC) &R_gtk_entry_get_attributes, 1},
    {"R_gtk_entry_get_buffer", (DL_FUNC) &R_gtk_entry_get_buffer, 1},
    {"R_gtk_entry_get_completion", (DL_FUNC) &R_gtk_entry_get_completion, 1},
    {"R_gtk_entry_get_current_icon_drag_source", (DL_FUNC) &R_gtk_entry_get_current_icon_drag_source, 1},
    {"R_gtk_entry_get_extra_menu", (DL_FUNC) &R_gtk_entry_get_extra_menu, 1},
    {"R_gtk_entry_get_has_frame", (DL_FUNC) &R_gtk_entry_get_has_frame, 1},
    {"R_gtk_entry_get_icon_activatable", (DL_FUNC) &R_gtk_entry_get_icon_activatable, 2},
    {"R_gtk_entry_get_icon_area", (DL_FUNC) &R_gtk_entry_get_icon_area, 2},
    {"R_gtk_entry_get_icon_at_pos", (DL_FUNC) &R_gtk_entry_get_icon_at_pos, 3},
    {"R_gtk_entry_get_icon_gicon", (DL_FUNC) &R_gtk_entry_get_icon_gicon, 2},
    {"R_gtk_entry_get_icon_name", (DL_FUNC) &R_gtk_entry_get_icon_name, 2},
    {"R_gtk_entry_get_icon_paintable", (DL_FUNC) &R_gtk_entry_get_icon_paintable, 2},
    {"R_gtk_entry_get_icon_sensitive", (DL_FUNC) &R_gtk_entry_get_icon_sensitive, 2},
    {"R_gtk_entry_get_icon_storage_type", (DL_FUNC) &R_gtk_entry_get_icon_storage_type, 2},
    {"R_gtk_entry_get_icon_tooltip_markup", (DL_FUNC) &R_gtk_entry_get_icon_tooltip_markup, 2},
    {"R_gtk_entry_get_icon_tooltip_text", (DL_FUNC) &R_gtk_entry_get_icon_tooltip_text, 2},
    {"R_gtk_entry_get_input_hints", (DL_FUNC) &R_gtk_entry_get_input_hints, 1},
    {"R_gtk_entry_get_input_purpose", (DL_FUNC) &R_gtk_entry_get_input_purpose, 1},
    {"R_gtk_entry_get_invisible_char", (DL_FUNC) &R_gtk_entry_get_invisible_char, 1},
    {"R_gtk_entry_get_max_length", (DL_FUNC) &R_gtk_entry_get_max_length, 1},
    {"R_gtk_entry_get_overwrite_mode", (DL_FUNC) &R_gtk_entry_get_overwrite_mode, 1},
    {"R_gtk_entry_get_placeholder_text", (DL_FUNC) &R_gtk_entry_get_placeholder_text, 1},
    {"R_gtk_entry_get_progress_fraction", (DL_FUNC) &R_gtk_entry_get_progress_fraction, 1},
    {"R_gtk_entry_get_progress_pulse_step", (DL_FUNC) &R_gtk_entry_get_progress_pulse_step, 1},
    {"R_gtk_entry_get_tabs", (DL_FUNC) &R_gtk_entry_get_tabs, 1},
    {"R_gtk_entry_get_text_length", (DL_FUNC) &R_gtk_entry_get_text_length, 1},
    {"R_gtk_entry_get_visibility", (DL_FUNC) &R_gtk_entry_get_visibility, 1},
    {"R_gtk_entry_grab_focus_without_selecting", (DL_FUNC) &R_gtk_entry_grab_focus_without_selecting, 1},
    {"R_gtk_entry_progress_pulse", (DL_FUNC) &R_gtk_entry_progress_pulse, 1},
    {"R_gtk_entry_reset_im_context", (DL_FUNC) &R_gtk_entry_reset_im_context, 1},
    {"R_gtk_entry_set_activates_default", (DL_FUNC) &R_gtk_entry_set_activates_default, 2},
    {"R_gtk_entry_set_alignment", (DL_FUNC) &R_gtk_entry_set_alignment, 2},
    {"R_gtk_entry_set_attributes", (DL_FUNC) &R_gtk_entry_set_attributes, 2},
    {"R_gtk_entry_set_buffer", (DL_FUNC) &R_gtk_entry_set_buffer, 2},
    {"R_gtk_entry_set_completion", (DL_FUNC) &R_gtk_entry_set_completion, 2},
    {"R_gtk_entry_set_extra_menu", (DL_FUNC) &R_gtk_entry_set_extra_menu, 2},
    {"R_gtk_entry_set_has_frame", (DL_FUNC) &R_gtk_entry_set_has_frame, 2},
    {"R_gtk_entry_set_icon_activatable", (DL_FUNC) &R_gtk_entry_set_icon_activatable, 3},
    {"R_gtk_entry_set_icon_drag_source", (DL_FUNC) &R_gtk_entry_set_icon_drag_source, 4},
    {"R_gtk_entry_set_icon_from_gicon", (DL_FUNC) &R_gtk_entry_set_icon_from_gicon, 3},
    {"R_gtk_entry_set_icon_from_icon_name", (DL_FUNC) &R_gtk_entry_set_icon_from_icon_name, 3},
    {"R_gtk_entry_set_icon_from_paintable", (DL_FUNC) &R_gtk_entry_set_icon_from_paintable, 3},
    {"R_gtk_entry_set_icon_sensitive", (DL_FUNC) &R_gtk_entry_set_icon_sensitive, 3},
    {"R_gtk_entry_set_icon_tooltip_markup", (DL_FUNC) &R_gtk_entry_set_icon_tooltip_markup, 3},
    {"R_gtk_entry_set_icon_tooltip_text", (DL_FUNC) &R_gtk_entry_set_icon_tooltip_text, 3},
    {"R_gtk_entry_set_input_hints", (DL_FUNC) &R_gtk_entry_set_input_hints, 2},
    {"R_gtk_entry_set_input_purpose", (DL_FUNC) &R_gtk_entry_set_input_purpose, 2},
    {"R_gtk_entry_set_invisible_char", (DL_FUNC) &R_gtk_entry_set_invisible_char, 2},
    {"R_gtk_entry_set_max_length", (DL_FUNC) &R_gtk_entry_set_max_length, 2},
    {"R_gtk_entry_set_overwrite_mode", (DL_FUNC) &R_gtk_entry_set_overwrite_mode, 2},
    {"R_gtk_entry_set_placeholder_text", (DL_FUNC) &R_gtk_entry_set_placeholder_text, 2},
    {"R_gtk_entry_set_progress_fraction", (DL_FUNC) &R_gtk_entry_set_progress_fraction, 2},
    {"R_gtk_entry_set_progress_pulse_step", (DL_FUNC) &R_gtk_entry_set_progress_pulse_step, 2},
    {"R_gtk_entry_set_tabs", (DL_FUNC) &R_gtk_entry_set_tabs, 2},
    {"R_gtk_entry_set_visibility", (DL_FUNC) &R_gtk_entry_set_visibility, 2},
    {"R_gtk_entry_unset_invisible_char", (DL_FUNC) &R_gtk_entry_unset_invisible_char, 1},
    {"R_gtk_entry_buffer_new", (DL_FUNC) &R_gtk_entry_buffer_new, 2},
    {"R_gtk_entry_buffer_delete_text", (DL_FUNC) &R_gtk_entry_buffer_delete_text, 3},
    {"R_gtk_entry_buffer_emit_deleted_text", (DL_FUNC) &R_gtk_entry_buffer_emit_deleted_text, 3},
    {"R_gtk_entry_buffer_emit_inserted_text", (DL_FUNC) &R_gtk_entry_buffer_emit_inserted_text, 4},
    {"R_gtk_entry_buffer_get_bytes", (DL_FUNC) &R_gtk_entry_buffer_get_bytes, 1},
    {"R_gtk_entry_buffer_get_length", (DL_FUNC) &R_gtk_entry_buffer_get_length, 1},
    {"R_gtk_entry_buffer_get_max_length", (DL_FUNC) &R_gtk_entry_buffer_get_max_length, 1},
    {"R_gtk_entry_buffer_get_text", (DL_FUNC) &R_gtk_entry_buffer_get_text, 1},
    {"R_gtk_entry_buffer_insert_text", (DL_FUNC) &R_gtk_entry_buffer_insert_text, 4},
    {"R_gtk_entry_buffer_set_max_length", (DL_FUNC) &R_gtk_entry_buffer_set_max_length, 2},
    {"R_gtk_entry_buffer_set_text", (DL_FUNC) &R_gtk_entry_buffer_set_text, 3},
    {"R_gtk_entry_completion_new", (DL_FUNC) &R_gtk_entry_completion_new, 0},
    {"R_gtk_entry_completion_new_with_area", (DL_FUNC) &R_gtk_entry_completion_new_with_area, 1},
    {"R_gtk_entry_completion_complete", (DL_FUNC) &R_gtk_entry_completion_complete, 1},
    {"R_gtk_entry_completion_compute_prefix", (DL_FUNC) &R_gtk_entry_completion_compute_prefix, 2},
    {"R_gtk_entry_completion_get_completion_prefix", (DL_FUNC) &R_gtk_entry_completion_get_completion_prefix, 1},
    {"R_gtk_entry_completion_get_entry", (DL_FUNC) &R_gtk_entry_completion_get_entry, 1},
    {"R_gtk_entry_completion_get_inline_completion", (DL_FUNC) &R_gtk_entry_completion_get_inline_completion, 1},
    {"R_gtk_entry_completion_get_inline_selection", (DL_FUNC) &R_gtk_entry_completion_get_inline_selection, 1},
    {"R_gtk_entry_completion_get_minimum_key_length", (DL_FUNC) &R_gtk_entry_completion_get_minimum_key_length, 1},
    {"R_gtk_entry_completion_get_model", (DL_FUNC) &R_gtk_entry_completion_get_model, 1},
    {"R_gtk_entry_completion_get_popup_completion", (DL_FUNC) &R_gtk_entry_completion_get_popup_completion, 1},
    {"R_gtk_entry_completion_get_popup_set_width", (DL_FUNC) &R_gtk_entry_completion_get_popup_set_width, 1},
    {"R_gtk_entry_completion_get_popup_single_match", (DL_FUNC) &R_gtk_entry_completion_get_popup_single_match, 1},
    {"R_gtk_entry_completion_get_text_column", (DL_FUNC) &R_gtk_entry_completion_get_text_column, 1},
    {"R_gtk_entry_completion_insert_prefix", (DL_FUNC) &R_gtk_entry_completion_insert_prefix, 1},
    {"R_gtk_entry_completion_set_inline_completion", (DL_FUNC) &R_gtk_entry_completion_set_inline_completion, 2},
    {"R_gtk_entry_completion_set_inline_selection", (DL_FUNC) &R_gtk_entry_completion_set_inline_selection, 2},
    {"R_gtk_entry_completion_set_match_func", (DL_FUNC) &R_gtk_entry_completion_set_match_func, 4},
    {"R_gtk_entry_completion_set_minimum_key_length", (DL_FUNC) &R_gtk_entry_completion_set_minimum_key_length, 2},
    {"R_gtk_entry_completion_set_model", (DL_FUNC) &R_gtk_entry_completion_set_model, 2},
    {"R_gtk_entry_completion_set_popup_completion", (DL_FUNC) &R_gtk_entry_completion_set_popup_completion, 2},
    {"R_gtk_entry_completion_set_popup_set_width", (DL_FUNC) &R_gtk_entry_completion_set_popup_set_width, 2},
    {"R_gtk_entry_completion_set_popup_single_match", (DL_FUNC) &R_gtk_entry_completion_set_popup_single_match, 2},
    {"R_gtk_entry_completion_set_text_column", (DL_FUNC) &R_gtk_entry_completion_set_text_column, 2},
    {"R_gtk_event_controller_get_current_event", (DL_FUNC) &R_gtk_event_controller_get_current_event, 1},
    {"R_gtk_event_controller_get_current_event_device", (DL_FUNC) &R_gtk_event_controller_get_current_event_device, 1},
    {"R_gtk_event_controller_get_current_event_state", (DL_FUNC) &R_gtk_event_controller_get_current_event_state, 1},
    {"R_gtk_event_controller_get_current_event_time", (DL_FUNC) &R_gtk_event_controller_get_current_event_time, 1},
    {"R_gtk_event_controller_get_name", (DL_FUNC) &R_gtk_event_controller_get_name, 1},
    {"R_gtk_event_controller_get_propagation_limit", (DL_FUNC) &R_gtk_event_controller_get_propagation_limit, 1},
    {"R_gtk_event_controller_get_propagation_phase", (DL_FUNC) &R_gtk_event_controller_get_propagation_phase, 1},
    {"R_gtk_event_controller_get_widget", (DL_FUNC) &R_gtk_event_controller_get_widget, 1},
    {"R_gtk_event_controller_reset", (DL_FUNC) &R_gtk_event_controller_reset, 1},
    {"R_gtk_event_controller_set_name", (DL_FUNC) &R_gtk_event_controller_set_name, 2},
    {"R_gtk_event_controller_set_propagation_limit", (DL_FUNC) &R_gtk_event_controller_set_propagation_limit, 2},
    {"R_gtk_event_controller_set_propagation_phase", (DL_FUNC) &R_gtk_event_controller_set_propagation_phase, 2},
    {"R_gtk_event_controller_set_static_name", (DL_FUNC) &R_gtk_event_controller_set_static_name, 2},
    {"R_gtk_event_controller_focus_new", (DL_FUNC) &R_gtk_event_controller_focus_new, 0},
    {"R_gtk_event_controller_focus_contains_focus", (DL_FUNC) &R_gtk_event_controller_focus_contains_focus, 1},
    {"R_gtk_event_controller_focus_is_focus", (DL_FUNC) &R_gtk_event_controller_focus_is_focus, 1},
    {"R_gtk_event_controller_key_new", (DL_FUNC) &R_gtk_event_controller_key_new, 0},
    {"R_gtk_event_controller_key_forward", (DL_FUNC) &R_gtk_event_controller_key_forward, 2},
    {"R_gtk_event_controller_key_get_group", (DL_FUNC) &R_gtk_event_controller_key_get_group, 1},
    {"R_gtk_event_controller_key_get_im_context", (DL_FUNC) &R_gtk_event_controller_key_get_im_context, 1},
    {"R_gtk_event_controller_key_set_im_context", (DL_FUNC) &R_gtk_event_controller_key_set_im_context, 2},
    {"R_gtk_event_controller_legacy_new", (DL_FUNC) &R_gtk_event_controller_legacy_new, 0},
    {"R_gtk_event_controller_motion_new", (DL_FUNC) &R_gtk_event_controller_motion_new, 0},
    {"R_gtk_event_controller_motion_contains_pointer", (DL_FUNC) &R_gtk_event_controller_motion_contains_pointer, 1},
    {"R_gtk_event_controller_motion_is_pointer", (DL_FUNC) &R_gtk_event_controller_motion_is_pointer, 1},
    {"R_gtk_event_controller_scroll_new", (DL_FUNC) &R_gtk_event_controller_scroll_new, 1},
    {"R_gtk_event_controller_scroll_get_flags", (DL_FUNC) &R_gtk_event_controller_scroll_get_flags, 1},
    {"R_gtk_event_controller_scroll_get_unit", (DL_FUNC) &R_gtk_event_controller_scroll_get_unit, 1},
    {"R_gtk_event_controller_scroll_set_flags", (DL_FUNC) &R_gtk_event_controller_scroll_set_flags, 2},
    {"R_gtk_every_filter_new", (DL_FUNC) &R_gtk_every_filter_new, 0},
    {"R_gtk_expander_new", (DL_FUNC) &R_gtk_expander_new, 1},
    {"R_gtk_expander_new_with_mnemonic", (DL_FUNC) &R_gtk_expander_new_with_mnemonic, 1},
    {"R_gtk_expander_get_child", (DL_FUNC) &R_gtk_expander_get_child, 1},
    {"R_gtk_expander_get_expanded", (DL_FUNC) &R_gtk_expander_get_expanded, 1},
    {"R_gtk_expander_get_label", (DL_FUNC) &R_gtk_expander_get_label, 1},
    {"R_gtk_expander_get_label_widget", (DL_FUNC) &R_gtk_expander_get_label_widget, 1},
    {"R_gtk_expander_get_resize_toplevel", (DL_FUNC) &R_gtk_expander_get_resize_toplevel, 1},
    {"R_gtk_expander_get_use_markup", (DL_FUNC) &R_gtk_expander_get_use_markup, 1},
    {"R_gtk_expander_get_use_underline", (DL_FUNC) &R_gtk_expander_get_use_underline, 1},
    {"R_gtk_expander_set_child", (DL_FUNC) &R_gtk_expander_set_child, 2},
    {"R_gtk_expander_set_expanded", (DL_FUNC) &R_gtk_expander_set_expanded, 2},
    {"R_gtk_expander_set_label", (DL_FUNC) &R_gtk_expander_set_label, 2},
    {"R_gtk_expander_set_label_widget", (DL_FUNC) &R_gtk_expander_set_label_widget, 2},
    {"R_gtk_expander_set_resize_toplevel", (DL_FUNC) &R_gtk_expander_set_resize_toplevel, 2},
    {"R_gtk_expander_set_use_markup", (DL_FUNC) &R_gtk_expander_set_use_markup, 2},
    {"R_gtk_expander_set_use_underline", (DL_FUNC) &R_gtk_expander_set_use_underline, 2},
    {"R_gtk_expression_bind", (DL_FUNC) &R_gtk_expression_bind, 4},
    {"R_gtk_expression_evaluate", (DL_FUNC) &R_gtk_expression_evaluate, 3},
    {"R_gtk_expression_get_value_type", (DL_FUNC) &R_gtk_expression_get_value_type, 1},
    {"R_gtk_expression_is_static", (DL_FUNC) &R_gtk_expression_is_static, 1},
    {"R_gtk_expression_ref", (DL_FUNC) &R_gtk_expression_ref, 1},
    {"R_gtk_expression_unref", (DL_FUNC) &R_gtk_expression_unref, 1},
    {"R_gtk_expression_watch", (DL_FUNC) &R_gtk_expression_watch, 5},
    {"R_gtk_expression_watch_evaluate", (DL_FUNC) &R_gtk_expression_watch_evaluate, 2},
    {"R_gtk_expression_watch_ref", (DL_FUNC) &R_gtk_expression_watch_ref, 1},
    {"R_gtk_expression_watch_unref", (DL_FUNC) &R_gtk_expression_watch_unref, 1},
    {"R_gtk_expression_watch_unwatch", (DL_FUNC) &R_gtk_expression_watch_unwatch, 1},
    {"R_gtk_file_chooser_add_choice", (DL_FUNC) &R_gtk_file_chooser_add_choice, 5},
    {"R_gtk_file_chooser_add_filter", (DL_FUNC) &R_gtk_file_chooser_add_filter, 2},
    {"R_gtk_file_chooser_add_shortcut_folder", (DL_FUNC) &R_gtk_file_chooser_add_shortcut_folder, 2},
    {"R_gtk_file_chooser_get_action", (DL_FUNC) &R_gtk_file_chooser_get_action, 1},
    {"R_gtk_file_chooser_get_choice", (DL_FUNC) &R_gtk_file_chooser_get_choice, 2},
    {"R_gtk_file_chooser_get_create_folders", (DL_FUNC) &R_gtk_file_chooser_get_create_folders, 1},
    {"R_gtk_file_chooser_get_current_folder", (DL_FUNC) &R_gtk_file_chooser_get_current_folder, 1},
    {"R_gtk_file_chooser_get_current_name", (DL_FUNC) &R_gtk_file_chooser_get_current_name, 1},
    {"R_gtk_file_chooser_get_file", (DL_FUNC) &R_gtk_file_chooser_get_file, 1},
    {"R_gtk_file_chooser_get_files", (DL_FUNC) &R_gtk_file_chooser_get_files, 1},
    {"R_gtk_file_chooser_get_filter", (DL_FUNC) &R_gtk_file_chooser_get_filter, 1},
    {"R_gtk_file_chooser_get_filters", (DL_FUNC) &R_gtk_file_chooser_get_filters, 1},
    {"R_gtk_file_chooser_get_select_multiple", (DL_FUNC) &R_gtk_file_chooser_get_select_multiple, 1},
    {"R_gtk_file_chooser_get_shortcut_folders", (DL_FUNC) &R_gtk_file_chooser_get_shortcut_folders, 1},
    {"R_gtk_file_chooser_remove_choice", (DL_FUNC) &R_gtk_file_chooser_remove_choice, 2},
    {"R_gtk_file_chooser_remove_filter", (DL_FUNC) &R_gtk_file_chooser_remove_filter, 2},
    {"R_gtk_file_chooser_remove_shortcut_folder", (DL_FUNC) &R_gtk_file_chooser_remove_shortcut_folder, 2},
    {"R_gtk_file_chooser_set_action", (DL_FUNC) &R_gtk_file_chooser_set_action, 2},
    {"R_gtk_file_chooser_set_choice", (DL_FUNC) &R_gtk_file_chooser_set_choice, 3},
    {"R_gtk_file_chooser_set_create_folders", (DL_FUNC) &R_gtk_file_chooser_set_create_folders, 2},
    {"R_gtk_file_chooser_set_current_folder", (DL_FUNC) &R_gtk_file_chooser_set_current_folder, 2},
    {"R_gtk_file_chooser_set_current_name", (DL_FUNC) &R_gtk_file_chooser_set_current_name, 2},
    {"R_gtk_file_chooser_set_file", (DL_FUNC) &R_gtk_file_chooser_set_file, 2},
    {"R_gtk_file_chooser_set_filter", (DL_FUNC) &R_gtk_file_chooser_set_filter, 2},
    {"R_gtk_file_chooser_set_select_multiple", (DL_FUNC) &R_gtk_file_chooser_set_select_multiple, 2},
    {"R_gtk_file_chooser_error_quark", (DL_FUNC) &R_gtk_file_chooser_error_quark, 0},
    {"R_gtk_file_chooser_native_new", (DL_FUNC) &R_gtk_file_chooser_native_new, 5},
    {"R_gtk_file_chooser_native_get_accept_label", (DL_FUNC) &R_gtk_file_chooser_native_get_accept_label, 1},
    {"R_gtk_file_chooser_native_get_cancel_label", (DL_FUNC) &R_gtk_file_chooser_native_get_cancel_label, 1},
    {"R_gtk_file_chooser_native_set_accept_label", (DL_FUNC) &R_gtk_file_chooser_native_set_accept_label, 2},
    {"R_gtk_file_chooser_native_set_cancel_label", (DL_FUNC) &R_gtk_file_chooser_native_set_cancel_label, 2},
    {"R_gtk_file_chooser_widget_new", (DL_FUNC) &R_gtk_file_chooser_widget_new, 1},
    {"R_gtk_file_dialog_new", (DL_FUNC) &R_gtk_file_dialog_new, 0},
    {"R_gtk_file_dialog_get_accept_label", (DL_FUNC) &R_gtk_file_dialog_get_accept_label, 1},
    {"R_gtk_file_dialog_get_default_filter", (DL_FUNC) &R_gtk_file_dialog_get_default_filter, 1},
    {"R_gtk_file_dialog_get_filters", (DL_FUNC) &R_gtk_file_dialog_get_filters, 1},
    {"R_gtk_file_dialog_get_initial_file", (DL_FUNC) &R_gtk_file_dialog_get_initial_file, 1},
    {"R_gtk_file_dialog_get_initial_folder", (DL_FUNC) &R_gtk_file_dialog_get_initial_folder, 1},
    {"R_gtk_file_dialog_get_initial_name", (DL_FUNC) &R_gtk_file_dialog_get_initial_name, 1},
    {"R_gtk_file_dialog_get_modal", (DL_FUNC) &R_gtk_file_dialog_get_modal, 1},
    {"R_gtk_file_dialog_get_title", (DL_FUNC) &R_gtk_file_dialog_get_title, 1},
    {"R_gtk_file_dialog_open", (DL_FUNC) &R_gtk_file_dialog_open, 5},
    {"R_gtk_file_dialog_open_finish", (DL_FUNC) &R_gtk_file_dialog_open_finish, 2},
    {"R_gtk_file_dialog_open_multiple", (DL_FUNC) &R_gtk_file_dialog_open_multiple, 5},
    {"R_gtk_file_dialog_open_multiple_finish", (DL_FUNC) &R_gtk_file_dialog_open_multiple_finish, 2},
    {"R_gtk_file_dialog_save", (DL_FUNC) &R_gtk_file_dialog_save, 5},
    {"R_gtk_file_dialog_save_finish", (DL_FUNC) &R_gtk_file_dialog_save_finish, 2},
    {"R_gtk_file_dialog_select_folder", (DL_FUNC) &R_gtk_file_dialog_select_folder, 5},
    {"R_gtk_file_dialog_select_folder_finish", (DL_FUNC) &R_gtk_file_dialog_select_folder_finish, 2},
    {"R_gtk_file_dialog_select_multiple_folders", (DL_FUNC) &R_gtk_file_dialog_select_multiple_folders, 5},
    {"R_gtk_file_dialog_select_multiple_folders_finish", (DL_FUNC) &R_gtk_file_dialog_select_multiple_folders_finish, 2},
    {"R_gtk_file_dialog_set_accept_label", (DL_FUNC) &R_gtk_file_dialog_set_accept_label, 2},
    {"R_gtk_file_dialog_set_default_filter", (DL_FUNC) &R_gtk_file_dialog_set_default_filter, 2},
    {"R_gtk_file_dialog_set_filters", (DL_FUNC) &R_gtk_file_dialog_set_filters, 2},
    {"R_gtk_file_dialog_set_initial_file", (DL_FUNC) &R_gtk_file_dialog_set_initial_file, 2},
    {"R_gtk_file_dialog_set_initial_folder", (DL_FUNC) &R_gtk_file_dialog_set_initial_folder, 2},
    {"R_gtk_file_dialog_set_initial_name", (DL_FUNC) &R_gtk_file_dialog_set_initial_name, 2},
    {"R_gtk_file_dialog_set_modal", (DL_FUNC) &R_gtk_file_dialog_set_modal, 2},
    {"R_gtk_file_dialog_set_title", (DL_FUNC) &R_gtk_file_dialog_set_title, 2},
    {"R_gtk_file_filter_new", (DL_FUNC) &R_gtk_file_filter_new, 0},
    {"R_gtk_file_filter_new_from_gvariant", (DL_FUNC) &R_gtk_file_filter_new_from_gvariant, 1},
    {"R_gtk_file_filter_add_mime_type", (DL_FUNC) &R_gtk_file_filter_add_mime_type, 2},
    {"R_gtk_file_filter_add_pattern", (DL_FUNC) &R_gtk_file_filter_add_pattern, 2},
    {"R_gtk_file_filter_add_pixbuf_formats", (DL_FUNC) &R_gtk_file_filter_add_pixbuf_formats, 1},
    {"R_gtk_file_filter_add_suffix", (DL_FUNC) &R_gtk_file_filter_add_suffix, 2},
    {"R_gtk_file_filter_get_attributes", (DL_FUNC) &R_gtk_file_filter_get_attributes, 1},
    {"R_gtk_file_filter_get_name", (DL_FUNC) &R_gtk_file_filter_get_name, 1},
    {"R_gtk_file_filter_set_name", (DL_FUNC) &R_gtk_file_filter_set_name, 2},
    {"R_gtk_file_filter_to_gvariant", (DL_FUNC) &R_gtk_file_filter_to_gvariant, 1},
    {"R_gtk_file_launcher_new", (DL_FUNC) &R_gtk_file_launcher_new, 1},
    {"R_gtk_file_launcher_get_always_ask", (DL_FUNC) &R_gtk_file_launcher_get_always_ask, 1},
    {"R_gtk_file_launcher_get_file", (DL_FUNC) &R_gtk_file_launcher_get_file, 1},
    {"R_gtk_file_launcher_launch", (DL_FUNC) &R_gtk_file_launcher_launch, 5},
    {"R_gtk_file_launcher_launch_finish", (DL_FUNC) &R_gtk_file_launcher_launch_finish, 2},
    {"R_gtk_file_launcher_open_containing_folder", (DL_FUNC) &R_gtk_file_launcher_open_containing_folder, 5},
    {"R_gtk_file_launcher_open_containing_folder_finish", (DL_FUNC) &R_gtk_file_launcher_open_containing_folder_finish, 2},
    {"R_gtk_file_launcher_set_always_ask", (DL_FUNC) &R_gtk_file_launcher_set_always_ask, 2},
    {"R_gtk_file_launcher_set_file", (DL_FUNC) &R_gtk_file_launcher_set_file, 2},
    {"R_gtk_filter_changed", (DL_FUNC) &R_gtk_filter_changed, 2},
    {"R_gtk_filter_get_strictness", (DL_FUNC) &R_gtk_filter_get_strictness, 1},
    {"R_gtk_filter_match", (DL_FUNC) &R_gtk_filter_match, 2},
    {"R_gtk_filter_list_model_new", (DL_FUNC) &R_gtk_filter_list_model_new, 2},
    {"R_gtk_filter_list_model_get_filter", (DL_FUNC) &R_gtk_filter_list_model_get_filter, 1},
    {"R_gtk_filter_list_model_get_incremental", (DL_FUNC) &R_gtk_filter_list_model_get_incremental, 1},
    {"R_gtk_filter_list_model_get_model", (DL_FUNC) &R_gtk_filter_list_model_get_model, 1},
    {"R_gtk_filter_list_model_get_pending", (DL_FUNC) &R_gtk_filter_list_model_get_pending, 1},
    {"R_gtk_filter_list_model_set_filter", (DL_FUNC) &R_gtk_filter_list_model_set_filter, 2},
    {"R_gtk_filter_list_model_set_incremental", (DL_FUNC) &R_gtk_filter_list_model_set_incremental, 2},
    {"R_gtk_filter_list_model_set_model", (DL_FUNC) &R_gtk_filter_list_model_set_model, 2},
    {"R_gtk_fixed_new", (DL_FUNC) &R_gtk_fixed_new, 0},
    {"R_gtk_fixed_get_child_position", (DL_FUNC) &R_gtk_fixed_get_child_position, 2},
    {"R_gtk_fixed_get_child_transform", (DL_FUNC) &R_gtk_fixed_get_child_transform, 2},
    {"R_gtk_fixed_move", (DL_FUNC) &R_gtk_fixed_move, 4},
    {"R_gtk_fixed_put", (DL_FUNC) &R_gtk_fixed_put, 4},
    {"R_gtk_fixed_remove", (DL_FUNC) &R_gtk_fixed_remove, 2},
    {"R_gtk_fixed_set_child_transform", (DL_FUNC) &R_gtk_fixed_set_child_transform, 3},
    {"R_gtk_fixed_layout_new", (DL_FUNC) &R_gtk_fixed_layout_new, 0},
    {"R_gtk_fixed_layout_child_get_transform", (DL_FUNC) &R_gtk_fixed_layout_child_get_transform, 1},
    {"R_gtk_fixed_layout_child_set_transform", (DL_FUNC) &R_gtk_fixed_layout_child_set_transform, 2},
    {"R_gtk_flatten_list_model_new", (DL_FUNC) &R_gtk_flatten_list_model_new, 1},
    {"R_gtk_flatten_list_model_get_model", (DL_FUNC) &R_gtk_flatten_list_model_get_model, 1},
    {"R_gtk_flatten_list_model_get_model_for_item", (DL_FUNC) &R_gtk_flatten_list_model_get_model_for_item, 2},
    {"R_gtk_flatten_list_model_set_model", (DL_FUNC) &R_gtk_flatten_list_model_set_model, 2},
    {"R_gtk_flow_box_new", (DL_FUNC) &R_gtk_flow_box_new, 0},
    {"R_gtk_flow_box_append", (DL_FUNC) &R_gtk_flow_box_append, 2},
    {"R_gtk_flow_box_bind_model", (DL_FUNC) &R_gtk_flow_box_bind_model, 5},
    {"R_gtk_flow_box_get_activate_on_single_click", (DL_FUNC) &R_gtk_flow_box_get_activate_on_single_click, 1},
    {"R_gtk_flow_box_get_child_at_index", (DL_FUNC) &R_gtk_flow_box_get_child_at_index, 2},
    {"R_gtk_flow_box_get_child_at_pos", (DL_FUNC) &R_gtk_flow_box_get_child_at_pos, 3},
    {"R_gtk_flow_box_get_column_spacing", (DL_FUNC) &R_gtk_flow_box_get_column_spacing, 1},
    {"R_gtk_flow_box_get_homogeneous", (DL_FUNC) &R_gtk_flow_box_get_homogeneous, 1},
    {"R_gtk_flow_box_get_max_children_per_line", (DL_FUNC) &R_gtk_flow_box_get_max_children_per_line, 1},
    {"R_gtk_flow_box_get_min_children_per_line", (DL_FUNC) &R_gtk_flow_box_get_min_children_per_line, 1},
    {"R_gtk_flow_box_get_row_spacing", (DL_FUNC) &R_gtk_flow_box_get_row_spacing, 1},
    {"R_gtk_flow_box_get_selected_children", (DL_FUNC) &R_gtk_flow_box_get_selected_children, 1},
    {"R_gtk_flow_box_get_selection_mode", (DL_FUNC) &R_gtk_flow_box_get_selection_mode, 1},
    {"R_gtk_flow_box_insert", (DL_FUNC) &R_gtk_flow_box_insert, 3},
    {"R_gtk_flow_box_invalidate_filter", (DL_FUNC) &R_gtk_flow_box_invalidate_filter, 1},
    {"R_gtk_flow_box_invalidate_sort", (DL_FUNC) &R_gtk_flow_box_invalidate_sort, 1},
    {"R_gtk_flow_box_prepend", (DL_FUNC) &R_gtk_flow_box_prepend, 2},
    {"R_gtk_flow_box_remove", (DL_FUNC) &R_gtk_flow_box_remove, 2},
    {"R_gtk_flow_box_remove_all", (DL_FUNC) &R_gtk_flow_box_remove_all, 1},
    {"R_gtk_flow_box_select_all", (DL_FUNC) &R_gtk_flow_box_select_all, 1},
    {"R_gtk_flow_box_select_child", (DL_FUNC) &R_gtk_flow_box_select_child, 2},
    {"R_gtk_flow_box_selected_foreach", (DL_FUNC) &R_gtk_flow_box_selected_foreach, 3},
    {"R_gtk_flow_box_set_activate_on_single_click", (DL_FUNC) &R_gtk_flow_box_set_activate_on_single_click, 2},
    {"R_gtk_flow_box_set_column_spacing", (DL_FUNC) &R_gtk_flow_box_set_column_spacing, 2},
    {"R_gtk_flow_box_set_filter_func", (DL_FUNC) &R_gtk_flow_box_set_filter_func, 4},
    {"R_gtk_flow_box_set_hadjustment", (DL_FUNC) &R_gtk_flow_box_set_hadjustment, 2},
    {"R_gtk_flow_box_set_homogeneous", (DL_FUNC) &R_gtk_flow_box_set_homogeneous, 2},
    {"R_gtk_flow_box_set_max_children_per_line", (DL_FUNC) &R_gtk_flow_box_set_max_children_per_line, 2},
    {"R_gtk_flow_box_set_min_children_per_line", (DL_FUNC) &R_gtk_flow_box_set_min_children_per_line, 2},
    {"R_gtk_flow_box_set_row_spacing", (DL_FUNC) &R_gtk_flow_box_set_row_spacing, 2},
    {"R_gtk_flow_box_set_selection_mode", (DL_FUNC) &R_gtk_flow_box_set_selection_mode, 2},
    {"R_gtk_flow_box_set_sort_func", (DL_FUNC) &R_gtk_flow_box_set_sort_func, 4},
    {"R_gtk_flow_box_set_vadjustment", (DL_FUNC) &R_gtk_flow_box_set_vadjustment, 2},
    {"R_gtk_flow_box_unselect_all", (DL_FUNC) &R_gtk_flow_box_unselect_all, 1},
    {"R_gtk_flow_box_unselect_child", (DL_FUNC) &R_gtk_flow_box_unselect_child, 2},
    {"R_gtk_flow_box_child_new", (DL_FUNC) &R_gtk_flow_box_child_new, 0},
    {"R_gtk_flow_box_child_changed", (DL_FUNC) &R_gtk_flow_box_child_changed, 1},
    {"R_gtk_flow_box_child_get_child", (DL_FUNC) &R_gtk_flow_box_child_get_child, 1},
    {"R_gtk_flow_box_child_get_index", (DL_FUNC) &R_gtk_flow_box_child_get_index, 1},
    {"R_gtk_flow_box_child_is_selected", (DL_FUNC) &R_gtk_flow_box_child_is_selected, 1},
    {"R_gtk_flow_box_child_set_child", (DL_FUNC) &R_gtk_flow_box_child_set_child, 2},
    {"R_gtk_font_button_new", (DL_FUNC) &R_gtk_font_button_new, 0},
    {"R_gtk_font_button_new_with_font", (DL_FUNC) &R_gtk_font_button_new_with_font, 1},
    {"R_gtk_font_button_get_modal", (DL_FUNC) &R_gtk_font_button_get_modal, 1},
    {"R_gtk_font_button_get_title", (DL_FUNC) &R_gtk_font_button_get_title, 1},
    {"R_gtk_font_button_get_use_font", (DL_FUNC) &R_gtk_font_button_get_use_font, 1},
    {"R_gtk_font_button_get_use_size", (DL_FUNC) &R_gtk_font_button_get_use_size, 1},
    {"R_gtk_font_button_set_modal", (DL_FUNC) &R_gtk_font_button_set_modal, 2},
    {"R_gtk_font_button_set_title", (DL_FUNC) &R_gtk_font_button_set_title, 2},
    {"R_gtk_font_button_set_use_font", (DL_FUNC) &R_gtk_font_button_set_use_font, 2},
    {"R_gtk_font_button_set_use_size", (DL_FUNC) &R_gtk_font_button_set_use_size, 2},
    {"R_gtk_font_chooser_get_font", (DL_FUNC) &R_gtk_font_chooser_get_font, 1},
    {"R_gtk_font_chooser_get_font_desc", (DL_FUNC) &R_gtk_font_chooser_get_font_desc, 1},
    {"R_gtk_font_chooser_get_font_face", (DL_FUNC) &R_gtk_font_chooser_get_font_face, 1},
    {"R_gtk_font_chooser_get_font_family", (DL_FUNC) &R_gtk_font_chooser_get_font_family, 1},
    {"R_gtk_font_chooser_get_font_features", (DL_FUNC) &R_gtk_font_chooser_get_font_features, 1},
    {"R_gtk_font_chooser_get_font_map", (DL_FUNC) &R_gtk_font_chooser_get_font_map, 1},
    {"R_gtk_font_chooser_get_font_size", (DL_FUNC) &R_gtk_font_chooser_get_font_size, 1},
    {"R_gtk_font_chooser_get_language", (DL_FUNC) &R_gtk_font_chooser_get_language, 1},
    {"R_gtk_font_chooser_get_level", (DL_FUNC) &R_gtk_font_chooser_get_level, 1},
    {"R_gtk_font_chooser_get_preview_text", (DL_FUNC) &R_gtk_font_chooser_get_preview_text, 1},
    {"R_gtk_font_chooser_get_show_preview_entry", (DL_FUNC) &R_gtk_font_chooser_get_show_preview_entry, 1},
    {"R_gtk_font_chooser_set_filter_func", (DL_FUNC) &R_gtk_font_chooser_set_filter_func, 4},
    {"R_gtk_font_chooser_set_font", (DL_FUNC) &R_gtk_font_chooser_set_font, 2},
    {"R_gtk_font_chooser_set_font_desc", (DL_FUNC) &R_gtk_font_chooser_set_font_desc, 2},
    {"R_gtk_font_chooser_set_font_map", (DL_FUNC) &R_gtk_font_chooser_set_font_map, 2},
    {"R_gtk_font_chooser_set_language", (DL_FUNC) &R_gtk_font_chooser_set_language, 2},
    {"R_gtk_font_chooser_set_level", (DL_FUNC) &R_gtk_font_chooser_set_level, 2},
    {"R_gtk_font_chooser_set_preview_text", (DL_FUNC) &R_gtk_font_chooser_set_preview_text, 2},
    {"R_gtk_font_chooser_set_show_preview_entry", (DL_FUNC) &R_gtk_font_chooser_set_show_preview_entry, 2},
    {"R_gtk_font_chooser_dialog_new", (DL_FUNC) &R_gtk_font_chooser_dialog_new, 2},
    {"R_gtk_font_chooser_widget_new", (DL_FUNC) &R_gtk_font_chooser_widget_new, 0},
    {"R_gtk_font_dialog_new", (DL_FUNC) &R_gtk_font_dialog_new, 0},
    {"R_gtk_font_dialog_choose_face", (DL_FUNC) &R_gtk_font_dialog_choose_face, 6},
    {"R_gtk_font_dialog_choose_face_finish", (DL_FUNC) &R_gtk_font_dialog_choose_face_finish, 2},
    {"R_gtk_font_dialog_choose_family", (DL_FUNC) &R_gtk_font_dialog_choose_family, 6},
    {"R_gtk_font_dialog_choose_family_finish", (DL_FUNC) &R_gtk_font_dialog_choose_family_finish, 2},
    {"R_gtk_font_dialog_choose_font", (DL_FUNC) &R_gtk_font_dialog_choose_font, 6},
    {"R_gtk_font_dialog_choose_font_and_features", (DL_FUNC) &R_gtk_font_dialog_choose_font_and_features, 6},
    {"R_gtk_font_dialog_choose_font_and_features_finish", (DL_FUNC) &R_gtk_font_dialog_choose_font_and_features_finish, 2},
    {"R_gtk_font_dialog_choose_font_finish", (DL_FUNC) &R_gtk_font_dialog_choose_font_finish, 2},
    {"R_gtk_font_dialog_get_filter", (DL_FUNC) &R_gtk_font_dialog_get_filter, 1},
    {"R_gtk_font_dialog_get_font_map", (DL_FUNC) &R_gtk_font_dialog_get_font_map, 1},
    {"R_gtk_font_dialog_get_language", (DL_FUNC) &R_gtk_font_dialog_get_language, 1},
    {"R_gtk_font_dialog_get_modal", (DL_FUNC) &R_gtk_font_dialog_get_modal, 1},
    {"R_gtk_font_dialog_get_title", (DL_FUNC) &R_gtk_font_dialog_get_title, 1},
    {"R_gtk_font_dialog_set_filter", (DL_FUNC) &R_gtk_font_dialog_set_filter, 2},
    {"R_gtk_font_dialog_set_font_map", (DL_FUNC) &R_gtk_font_dialog_set_font_map, 2},
    {"R_gtk_font_dialog_set_language", (DL_FUNC) &R_gtk_font_dialog_set_language, 2},
    {"R_gtk_font_dialog_set_modal", (DL_FUNC) &R_gtk_font_dialog_set_modal, 2},
    {"R_gtk_font_dialog_set_title", (DL_FUNC) &R_gtk_font_dialog_set_title, 2},
    {"R_gtk_font_dialog_button_new", (DL_FUNC) &R_gtk_font_dialog_button_new, 1},
    {"R_gtk_font_dialog_button_get_dialog", (DL_FUNC) &R_gtk_font_dialog_button_get_dialog, 1},
    {"R_gtk_font_dialog_button_get_font_desc", (DL_FUNC) &R_gtk_font_dialog_button_get_font_desc, 1},
    {"R_gtk_font_dialog_button_get_font_features", (DL_FUNC) &R_gtk_font_dialog_button_get_font_features, 1},
    {"R_gtk_font_dialog_button_get_language", (DL_FUNC) &R_gtk_font_dialog_button_get_language, 1},
    {"R_gtk_font_dialog_button_get_level", (DL_FUNC) &R_gtk_font_dialog_button_get_level, 1},
    {"R_gtk_font_dialog_button_get_use_font", (DL_FUNC) &R_gtk_font_dialog_button_get_use_font, 1},
    {"R_gtk_font_dialog_button_get_use_size", (DL_FUNC) &R_gtk_font_dialog_button_get_use_size, 1},
    {"R_gtk_font_dialog_button_set_dialog", (DL_FUNC) &R_gtk_font_dialog_button_set_dialog, 2},
    {"R_gtk_font_dialog_button_set_font_desc", (DL_FUNC) &R_gtk_font_dialog_button_set_font_desc, 2},
    {"R_gtk_font_dialog_button_set_font_features", (DL_FUNC) &R_gtk_font_dialog_button_set_font_features, 2},
    {"R_gtk_font_dialog_button_set_language", (DL_FUNC) &R_gtk_font_dialog_button_set_language, 2},
    {"R_gtk_font_dialog_button_set_level", (DL_FUNC) &R_gtk_font_dialog_button_set_level, 2},
    {"R_gtk_font_dialog_button_set_use_font", (DL_FUNC) &R_gtk_font_dialog_button_set_use_font, 2},
    {"R_gtk_font_dialog_button_set_use_size", (DL_FUNC) &R_gtk_font_dialog_button_set_use_size, 2},
    {"R_gtk_frame_new", (DL_FUNC) &R_gtk_frame_new, 1},
    {"R_gtk_frame_get_child", (DL_FUNC) &R_gtk_frame_get_child, 1},
    {"R_gtk_frame_get_label", (DL_FUNC) &R_gtk_frame_get_label, 1},
    {"R_gtk_frame_get_label_align", (DL_FUNC) &R_gtk_frame_get_label_align, 1},
    {"R_gtk_frame_get_label_widget", (DL_FUNC) &R_gtk_frame_get_label_widget, 1},
    {"R_gtk_frame_set_child", (DL_FUNC) &R_gtk_frame_set_child, 2},
    {"R_gtk_frame_set_label", (DL_FUNC) &R_gtk_frame_set_label, 2},
    {"R_gtk_frame_set_label_align", (DL_FUNC) &R_gtk_frame_set_label_align, 2},
    {"R_gtk_frame_set_label_widget", (DL_FUNC) &R_gtk_frame_set_label_widget, 2},
    {"R_gtk_gl_area_new", (DL_FUNC) &R_gtk_gl_area_new, 0},
    {"R_gtk_gl_area_attach_buffers", (DL_FUNC) &R_gtk_gl_area_attach_buffers, 1},
    {"R_gtk_gl_area_get_allowed_apis", (DL_FUNC) &R_gtk_gl_area_get_allowed_apis, 1},
    {"R_gtk_gl_area_get_api", (DL_FUNC) &R_gtk_gl_area_get_api, 1},
    {"R_gtk_gl_area_get_auto_render", (DL_FUNC) &R_gtk_gl_area_get_auto_render, 1},
    {"R_gtk_gl_area_get_context", (DL_FUNC) &R_gtk_gl_area_get_context, 1},
    {"R_gtk_gl_area_get_error", (DL_FUNC) &R_gtk_gl_area_get_error, 1},
    {"R_gtk_gl_area_get_has_depth_buffer", (DL_FUNC) &R_gtk_gl_area_get_has_depth_buffer, 1},
    {"R_gtk_gl_area_get_has_stencil_buffer", (DL_FUNC) &R_gtk_gl_area_get_has_stencil_buffer, 1},
    {"R_gtk_gl_area_get_required_version", (DL_FUNC) &R_gtk_gl_area_get_required_version, 1},
    {"R_gtk_gl_area_get_use_es", (DL_FUNC) &R_gtk_gl_area_get_use_es, 1},
    {"R_gtk_gl_area_make_current", (DL_FUNC) &R_gtk_gl_area_make_current, 1},
    {"R_gtk_gl_area_queue_render", (DL_FUNC) &R_gtk_gl_area_queue_render, 1},
    {"R_gtk_gl_area_set_allowed_apis", (DL_FUNC) &R_gtk_gl_area_set_allowed_apis, 2},
    {"R_gtk_gl_area_set_auto_render", (DL_FUNC) &R_gtk_gl_area_set_auto_render, 2},
    {"R_gtk_gl_area_set_error", (DL_FUNC) &R_gtk_gl_area_set_error, 2},
    {"R_gtk_gl_area_set_has_depth_buffer", (DL_FUNC) &R_gtk_gl_area_set_has_depth_buffer, 2},
    {"R_gtk_gl_area_set_has_stencil_buffer", (DL_FUNC) &R_gtk_gl_area_set_has_stencil_buffer, 2},
    {"R_gtk_gl_area_set_required_version", (DL_FUNC) &R_gtk_gl_area_set_required_version, 3},
    {"R_gtk_gl_area_set_use_es", (DL_FUNC) &R_gtk_gl_area_set_use_es, 2},
    {"R_gtk_gesture_get_bounding_box", (DL_FUNC) &R_gtk_gesture_get_bounding_box, 1},
    {"R_gtk_gesture_get_bounding_box_center", (DL_FUNC) &R_gtk_gesture_get_bounding_box_center, 1},
    {"R_gtk_gesture_get_device", (DL_FUNC) &R_gtk_gesture_get_device, 1},
    {"R_gtk_gesture_get_group", (DL_FUNC) &R_gtk_gesture_get_group, 1},
    {"R_gtk_gesture_get_last_event", (DL_FUNC) &R_gtk_gesture_get_last_event, 2},
    {"R_gtk_gesture_get_last_updated_sequence", (DL_FUNC) &R_gtk_gesture_get_last_updated_sequence, 1},
    {"R_gtk_gesture_get_point", (DL_FUNC) &R_gtk_gesture_get_point, 2},
    {"R_gtk_gesture_get_sequence_state", (DL_FUNC) &R_gtk_gesture_get_sequence_state, 2},
    {"R_gtk_gesture_get_sequences", (DL_FUNC) &R_gtk_gesture_get_sequences, 1},
    {"R_gtk_gesture_group", (DL_FUNC) &R_gtk_gesture_group, 2},
    {"R_gtk_gesture_handles_sequence", (DL_FUNC) &R_gtk_gesture_handles_sequence, 2},
    {"R_gtk_gesture_is_active", (DL_FUNC) &R_gtk_gesture_is_active, 1},
    {"R_gtk_gesture_is_grouped_with", (DL_FUNC) &R_gtk_gesture_is_grouped_with, 2},
    {"R_gtk_gesture_is_recognized", (DL_FUNC) &R_gtk_gesture_is_recognized, 1},
    {"R_gtk_gesture_set_sequence_state", (DL_FUNC) &R_gtk_gesture_set_sequence_state, 3},
    {"R_gtk_gesture_set_state", (DL_FUNC) &R_gtk_gesture_set_state, 2},
    {"R_gtk_gesture_ungroup", (DL_FUNC) &R_gtk_gesture_ungroup, 1},
    {"R_gtk_gesture_click_new", (DL_FUNC) &R_gtk_gesture_click_new, 0},
    {"R_gtk_gesture_drag_new", (DL_FUNC) &R_gtk_gesture_drag_new, 0},
    {"R_gtk_gesture_drag_get_offset", (DL_FUNC) &R_gtk_gesture_drag_get_offset, 1},
    {"R_gtk_gesture_drag_get_start_point", (DL_FUNC) &R_gtk_gesture_drag_get_start_point, 1},
    {"R_gtk_gesture_long_press_new", (DL_FUNC) &R_gtk_gesture_long_press_new, 0},
    {"R_gtk_gesture_long_press_get_delay_factor", (DL_FUNC) &R_gtk_gesture_long_press_get_delay_factor, 1},
    {"R_gtk_gesture_long_press_set_delay_factor", (DL_FUNC) &R_gtk_gesture_long_press_set_delay_factor, 2},
    {"R_gtk_gesture_pan_new", (DL_FUNC) &R_gtk_gesture_pan_new, 1},
    {"R_gtk_gesture_pan_get_orientation", (DL_FUNC) &R_gtk_gesture_pan_get_orientation, 1},
    {"R_gtk_gesture_pan_set_orientation", (DL_FUNC) &R_gtk_gesture_pan_set_orientation, 2},
    {"R_gtk_gesture_rotate_new", (DL_FUNC) &R_gtk_gesture_rotate_new, 0},
    {"R_gtk_gesture_rotate_get_angle_delta", (DL_FUNC) &R_gtk_gesture_rotate_get_angle_delta, 1},
    {"R_gtk_gesture_single_get_button", (DL_FUNC) &R_gtk_gesture_single_get_button, 1},
    {"R_gtk_gesture_single_get_current_button", (DL_FUNC) &R_gtk_gesture_single_get_current_button, 1},
    {"R_gtk_gesture_single_get_current_sequence", (DL_FUNC) &R_gtk_gesture_single_get_current_sequence, 1},
    {"R_gtk_gesture_single_get_exclusive", (DL_FUNC) &R_gtk_gesture_single_get_exclusive, 1},
    {"R_gtk_gesture_single_get_touch_only", (DL_FUNC) &R_gtk_gesture_single_get_touch_only, 1},
    {"R_gtk_gesture_single_set_button", (DL_FUNC) &R_gtk_gesture_single_set_button, 2},
    {"R_gtk_gesture_single_set_exclusive", (DL_FUNC) &R_gtk_gesture_single_set_exclusive, 2},
    {"R_gtk_gesture_single_set_touch_only", (DL_FUNC) &R_gtk_gesture_single_set_touch_only, 2},
    {"R_gtk_gesture_stylus_new", (DL_FUNC) &R_gtk_gesture_stylus_new, 0},
    {"R_gtk_gesture_stylus_get_axes", (DL_FUNC) &R_gtk_gesture_stylus_get_axes, 2},
    {"R_gtk_gesture_stylus_get_axis", (DL_FUNC) &R_gtk_gesture_stylus_get_axis, 2},
    {"R_gtk_gesture_stylus_get_backlog", (DL_FUNC) &R_gtk_gesture_stylus_get_backlog, 1},
    {"R_gtk_gesture_stylus_get_device_tool", (DL_FUNC) &R_gtk_gesture_stylus_get_device_tool, 1},
    {"R_gtk_gesture_stylus_get_stylus_only", (DL_FUNC) &R_gtk_gesture_stylus_get_stylus_only, 1},
    {"R_gtk_gesture_stylus_set_stylus_only", (DL_FUNC) &R_gtk_gesture_stylus_set_stylus_only, 2},
    {"R_gtk_gesture_swipe_new", (DL_FUNC) &R_gtk_gesture_swipe_new, 0},
    {"R_gtk_gesture_swipe_get_velocity", (DL_FUNC) &R_gtk_gesture_swipe_get_velocity, 1},
    {"R_gtk_gesture_zoom_new", (DL_FUNC) &R_gtk_gesture_zoom_new, 0},
    {"R_gtk_gesture_zoom_get_scale_delta", (DL_FUNC) &R_gtk_gesture_zoom_get_scale_delta, 1},
    {"R_gtk_grid_new", (DL_FUNC) &R_gtk_grid_new, 0},
    {"R_gtk_grid_attach", (DL_FUNC) &R_gtk_grid_attach, 6},
    {"R_gtk_grid_attach_next_to", (DL_FUNC) &R_gtk_grid_attach_next_to, 6},
    {"R_gtk_grid_get_baseline_row", (DL_FUNC) &R_gtk_grid_get_baseline_row, 1},
    {"R_gtk_grid_get_child_at", (DL_FUNC) &R_gtk_grid_get_child_at, 3},
    {"R_gtk_grid_get_column_homogeneous", (DL_FUNC) &R_gtk_grid_get_column_homogeneous, 1},
    {"R_gtk_grid_get_column_spacing", (DL_FUNC) &R_gtk_grid_get_column_spacing, 1},
    {"R_gtk_grid_get_row_baseline_position", (DL_FUNC) &R_gtk_grid_get_row_baseline_position, 2},
    {"R_gtk_grid_get_row_homogeneous", (DL_FUNC) &R_gtk_grid_get_row_homogeneous, 1},
    {"R_gtk_grid_get_row_spacing", (DL_FUNC) &R_gtk_grid_get_row_spacing, 1},
    {"R_gtk_grid_insert_column", (DL_FUNC) &R_gtk_grid_insert_column, 2},
    {"R_gtk_grid_insert_next_to", (DL_FUNC) &R_gtk_grid_insert_next_to, 3},
    {"R_gtk_grid_insert_row", (DL_FUNC) &R_gtk_grid_insert_row, 2},
    {"R_gtk_grid_query_child", (DL_FUNC) &R_gtk_grid_query_child, 2},
    {"R_gtk_grid_remove", (DL_FUNC) &R_gtk_grid_remove, 2},
    {"R_gtk_grid_remove_column", (DL_FUNC) &R_gtk_grid_remove_column, 2},
    {"R_gtk_grid_remove_row", (DL_FUNC) &R_gtk_grid_remove_row, 2},
    {"R_gtk_grid_set_baseline_row", (DL_FUNC) &R_gtk_grid_set_baseline_row, 2},
    {"R_gtk_grid_set_column_homogeneous", (DL_FUNC) &R_gtk_grid_set_column_homogeneous, 2},
    {"R_gtk_grid_set_column_spacing", (DL_FUNC) &R_gtk_grid_set_column_spacing, 2},
    {"R_gtk_grid_set_row_baseline_position", (DL_FUNC) &R_gtk_grid_set_row_baseline_position, 3},
    {"R_gtk_grid_set_row_homogeneous", (DL_FUNC) &R_gtk_grid_set_row_homogeneous, 2},
    {"R_gtk_grid_set_row_spacing", (DL_FUNC) &R_gtk_grid_set_row_spacing, 2},
    {"R_gtk_grid_layout_new", (DL_FUNC) &R_gtk_grid_layout_new, 0},
    {"R_gtk_grid_layout_get_baseline_row", (DL_FUNC) &R_gtk_grid_layout_get_baseline_row, 1},
    {"R_gtk_grid_layout_get_column_homogeneous", (DL_FUNC) &R_gtk_grid_layout_get_column_homogeneous, 1},
    {"R_gtk_grid_layout_get_column_spacing", (DL_FUNC) &R_gtk_grid_layout_get_column_spacing, 1},
    {"R_gtk_grid_layout_get_row_baseline_position", (DL_FUNC) &R_gtk_grid_layout_get_row_baseline_position, 2},
    {"R_gtk_grid_layout_get_row_homogeneous", (DL_FUNC) &R_gtk_grid_layout_get_row_homogeneous, 1},
    {"R_gtk_grid_layout_get_row_spacing", (DL_FUNC) &R_gtk_grid_layout_get_row_spacing, 1},
    {"R_gtk_grid_layout_set_baseline_row", (DL_FUNC) &R_gtk_grid_layout_set_baseline_row, 2},
    {"R_gtk_grid_layout_set_column_homogeneous", (DL_FUNC) &R_gtk_grid_layout_set_column_homogeneous, 2},
    {"R_gtk_grid_layout_set_column_spacing", (DL_FUNC) &R_gtk_grid_layout_set_column_spacing, 2},
    {"R_gtk_grid_layout_set_row_baseline_position", (DL_FUNC) &R_gtk_grid_layout_set_row_baseline_position, 3},
    {"R_gtk_grid_layout_set_row_homogeneous", (DL_FUNC) &R_gtk_grid_layout_set_row_homogeneous, 2},
    {"R_gtk_grid_layout_set_row_spacing", (DL_FUNC) &R_gtk_grid_layout_set_row_spacing, 2},
    {"R_gtk_grid_layout_child_get_column", (DL_FUNC) &R_gtk_grid_layout_child_get_column, 1},
    {"R_gtk_grid_layout_child_get_column_span", (DL_FUNC) &R_gtk_grid_layout_child_get_column_span, 1},
    {"R_gtk_grid_layout_child_get_row", (DL_FUNC) &R_gtk_grid_layout_child_get_row, 1},
    {"R_gtk_grid_layout_child_get_row_span", (DL_FUNC) &R_gtk_grid_layout_child_get_row_span, 1},
    {"R_gtk_grid_layout_child_set_column", (DL_FUNC) &R_gtk_grid_layout_child_set_column, 2},
    {"R_gtk_grid_layout_child_set_column_span", (DL_FUNC) &R_gtk_grid_layout_child_set_column_span, 2},
    {"R_gtk_grid_layout_child_set_row", (DL_FUNC) &R_gtk_grid_layout_child_set_row, 2},
    {"R_gtk_grid_layout_child_set_row_span", (DL_FUNC) &R_gtk_grid_layout_child_set_row_span, 2},
    {"R_gtk_grid_view_new", (DL_FUNC) &R_gtk_grid_view_new, 2},
    {"R_gtk_grid_view_get_enable_rubberband", (DL_FUNC) &R_gtk_grid_view_get_enable_rubberband, 1},
    {"R_gtk_grid_view_get_factory", (DL_FUNC) &R_gtk_grid_view_get_factory, 1},
    {"R_gtk_grid_view_get_max_columns", (DL_FUNC) &R_gtk_grid_view_get_max_columns, 1},
    {"R_gtk_grid_view_get_min_columns", (DL_FUNC) &R_gtk_grid_view_get_min_columns, 1},
    {"R_gtk_grid_view_get_model", (DL_FUNC) &R_gtk_grid_view_get_model, 1},
    {"R_gtk_grid_view_get_single_click_activate", (DL_FUNC) &R_gtk_grid_view_get_single_click_activate, 1},
    {"R_gtk_grid_view_get_tab_behavior", (DL_FUNC) &R_gtk_grid_view_get_tab_behavior, 1},
    {"R_gtk_grid_view_scroll_to", (DL_FUNC) &R_gtk_grid_view_scroll_to, 4},
    {"R_gtk_grid_view_set_enable_rubberband", (DL_FUNC) &R_gtk_grid_view_set_enable_rubberband, 2},
    {"R_gtk_grid_view_set_factory", (DL_FUNC) &R_gtk_grid_view_set_factory, 2},
    {"R_gtk_grid_view_set_max_columns", (DL_FUNC) &R_gtk_grid_view_set_max_columns, 2},
    {"R_gtk_grid_view_set_min_columns", (DL_FUNC) &R_gtk_grid_view_set_min_columns, 2},
    {"R_gtk_grid_view_set_model", (DL_FUNC) &R_gtk_grid_view_set_model, 2},
    {"R_gtk_grid_view_set_single_click_activate", (DL_FUNC) &R_gtk_grid_view_set_single_click_activate, 2},
    {"R_gtk_grid_view_set_tab_behavior", (DL_FUNC) &R_gtk_grid_view_set_tab_behavior, 2},
    {"R_gtk_header_bar_new", (DL_FUNC) &R_gtk_header_bar_new, 0},
    {"R_gtk_header_bar_get_decoration_layout", (DL_FUNC) &R_gtk_header_bar_get_decoration_layout, 1},
    {"R_gtk_header_bar_get_show_title_buttons", (DL_FUNC) &R_gtk_header_bar_get_show_title_buttons, 1},
    {"R_gtk_header_bar_get_title_widget", (DL_FUNC) &R_gtk_header_bar_get_title_widget, 1},
    {"R_gtk_header_bar_pack_end", (DL_FUNC) &R_gtk_header_bar_pack_end, 2},
    {"R_gtk_header_bar_pack_start", (DL_FUNC) &R_gtk_header_bar_pack_start, 2},
    {"R_gtk_header_bar_remove", (DL_FUNC) &R_gtk_header_bar_remove, 2},
    {"R_gtk_header_bar_set_decoration_layout", (DL_FUNC) &R_gtk_header_bar_set_decoration_layout, 2},
    {"R_gtk_header_bar_set_show_title_buttons", (DL_FUNC) &R_gtk_header_bar_set_show_title_buttons, 2},
    {"R_gtk_header_bar_set_title_widget", (DL_FUNC) &R_gtk_header_bar_set_title_widget, 2},
    {"R_gtk_im_context_delete_surrounding", (DL_FUNC) &R_gtk_im_context_delete_surrounding, 3},
    {"R_gtk_im_context_filter_key", (DL_FUNC) &R_gtk_im_context_filter_key, 8},
    {"R_gtk_im_context_filter_keypress", (DL_FUNC) &R_gtk_im_context_filter_keypress, 2},
    {"R_gtk_im_context_focus_in", (DL_FUNC) &R_gtk_im_context_focus_in, 1},
    {"R_gtk_im_context_focus_out", (DL_FUNC) &R_gtk_im_context_focus_out, 1},
    {"R_gtk_im_context_get_preedit_string", (DL_FUNC) &R_gtk_im_context_get_preedit_string, 1},
    {"R_gtk_im_context_get_surrounding", (DL_FUNC) &R_gtk_im_context_get_surrounding, 1},
    {"R_gtk_im_context_get_surrounding_with_selection", (DL_FUNC) &R_gtk_im_context_get_surrounding_with_selection, 1},
    {"R_gtk_im_context_reset", (DL_FUNC) &R_gtk_im_context_reset, 1},
    {"R_gtk_im_context_set_client_widget", (DL_FUNC) &R_gtk_im_context_set_client_widget, 2},
    {"R_gtk_im_context_set_cursor_location", (DL_FUNC) &R_gtk_im_context_set_cursor_location, 2},
    {"R_gtk_im_context_set_surrounding", (DL_FUNC) &R_gtk_im_context_set_surrounding, 4},
    {"R_gtk_im_context_set_surrounding_with_selection", (DL_FUNC) &R_gtk_im_context_set_surrounding_with_selection, 5},
    {"R_gtk_im_context_set_use_preedit", (DL_FUNC) &R_gtk_im_context_set_use_preedit, 2},
    {"R_gtk_im_context_simple_new", (DL_FUNC) &R_gtk_im_context_simple_new, 0},
    {"R_gtk_im_context_simple_add_compose_file", (DL_FUNC) &R_gtk_im_context_simple_add_compose_file, 2},
    {"R_gtk_im_multicontext_new", (DL_FUNC) &R_gtk_im_multicontext_new, 0},
    {"R_gtk_im_multicontext_get_context_id", (DL_FUNC) &R_gtk_im_multicontext_get_context_id, 1},
    {"R_gtk_im_multicontext_set_context_id", (DL_FUNC) &R_gtk_im_multicontext_set_context_id, 2},
    {"R_gtk_icon_paintable_new_for_file", (DL_FUNC) &R_gtk_icon_paintable_new_for_file, 3},
    {"R_gtk_icon_paintable_get_file", (DL_FUNC) &R_gtk_icon_paintable_get_file, 1},
    {"R_gtk_icon_paintable_get_icon_name", (DL_FUNC) &R_gtk_icon_paintable_get_icon_name, 1},
    {"R_gtk_icon_paintable_is_symbolic", (DL_FUNC) &R_gtk_icon_paintable_is_symbolic, 1},
    {"R_gtk_icon_theme_new", (DL_FUNC) &R_gtk_icon_theme_new, 0},
    {"R_gtk_icon_theme_get_for_display", (DL_FUNC) &R_gtk_icon_theme_get_for_display, 1},
    {"R_gtk_icon_theme_add_resource_path", (DL_FUNC) &R_gtk_icon_theme_add_resource_path, 2},
    {"R_gtk_icon_theme_add_search_path", (DL_FUNC) &R_gtk_icon_theme_add_search_path, 2},
    {"R_gtk_icon_theme_get_display", (DL_FUNC) &R_gtk_icon_theme_get_display, 1},
    {"R_gtk_icon_theme_get_icon_names", (DL_FUNC) &R_gtk_icon_theme_get_icon_names, 1},
    {"R_gtk_icon_theme_get_icon_sizes", (DL_FUNC) &R_gtk_icon_theme_get_icon_sizes, 2},
    {"R_gtk_icon_theme_get_resource_path", (DL_FUNC) &R_gtk_icon_theme_get_resource_path, 1},
    {"R_gtk_icon_theme_get_search_path", (DL_FUNC) &R_gtk_icon_theme_get_search_path, 1},
    {"R_gtk_icon_theme_get_theme_name", (DL_FUNC) &R_gtk_icon_theme_get_theme_name, 1},
    {"R_gtk_icon_theme_has_gicon", (DL_FUNC) &R_gtk_icon_theme_has_gicon, 2},
    {"R_gtk_icon_theme_has_icon", (DL_FUNC) &R_gtk_icon_theme_has_icon, 2},
    {"R_gtk_icon_theme_lookup_by_gicon", (DL_FUNC) &R_gtk_icon_theme_lookup_by_gicon, 6},
    {"R_gtk_icon_theme_lookup_icon", (DL_FUNC) &R_gtk_icon_theme_lookup_icon, 7},
    {"R_gtk_icon_theme_set_resource_path", (DL_FUNC) &R_gtk_icon_theme_set_resource_path, 2},
    {"R_gtk_icon_theme_set_search_path", (DL_FUNC) &R_gtk_icon_theme_set_search_path, 2},
    {"R_gtk_icon_theme_set_theme_name", (DL_FUNC) &R_gtk_icon_theme_set_theme_name, 2},
    {"R_gtk_icon_theme_error_quark", (DL_FUNC) &R_gtk_icon_theme_error_quark, 0},
    {"R_gtk_icon_view_new", (DL_FUNC) &R_gtk_icon_view_new, 0},
    {"R_gtk_icon_view_new_with_area", (DL_FUNC) &R_gtk_icon_view_new_with_area, 1},
    {"R_gtk_icon_view_new_with_model", (DL_FUNC) &R_gtk_icon_view_new_with_model, 1},
    {"R_gtk_icon_view_create_drag_icon", (DL_FUNC) &R_gtk_icon_view_create_drag_icon, 2},
    {"R_gtk_icon_view_enable_model_drag_dest", (DL_FUNC) &R_gtk_icon_view_enable_model_drag_dest, 3},
    {"R_gtk_icon_view_enable_model_drag_source", (DL_FUNC) &R_gtk_icon_view_enable_model_drag_source, 4},
    {"R_gtk_icon_view_get_activate_on_single_click", (DL_FUNC) &R_gtk_icon_view_get_activate_on_single_click, 1},
    {"R_gtk_icon_view_get_cell_rect", (DL_FUNC) &R_gtk_icon_view_get_cell_rect, 3},
    {"R_gtk_icon_view_get_column_spacing", (DL_FUNC) &R_gtk_icon_view_get_column_spacing, 1},
    {"R_gtk_icon_view_get_columns", (DL_FUNC) &R_gtk_icon_view_get_columns, 1},
    {"R_gtk_icon_view_get_cursor", (DL_FUNC) &R_gtk_icon_view_get_cursor, 1},
    {"R_gtk_icon_view_get_dest_item_at_pos", (DL_FUNC) &R_gtk_icon_view_get_dest_item_at_pos, 3},
    {"R_gtk_icon_view_get_drag_dest_item", (DL_FUNC) &R_gtk_icon_view_get_drag_dest_item, 1},
    {"R_gtk_icon_view_get_item_at_pos", (DL_FUNC) &R_gtk_icon_view_get_item_at_pos, 3},
    {"R_gtk_icon_view_get_item_column", (DL_FUNC) &R_gtk_icon_view_get_item_column, 2},
    {"R_gtk_icon_view_get_item_orientation", (DL_FUNC) &R_gtk_icon_view_get_item_orientation, 1},
    {"R_gtk_icon_view_get_item_padding", (DL_FUNC) &R_gtk_icon_view_get_item_padding, 1},
    {"R_gtk_icon_view_get_item_row", (DL_FUNC) &R_gtk_icon_view_get_item_row, 2},
    {"R_gtk_icon_view_get_item_width", (DL_FUNC) &R_gtk_icon_view_get_item_width, 1},
    {"R_gtk_icon_view_get_margin", (DL_FUNC) &R_gtk_icon_view_get_margin, 1},
    {"R_gtk_icon_view_get_markup_column", (DL_FUNC) &R_gtk_icon_view_get_markup_column, 1},
    {"R_gtk_icon_view_get_model", (DL_FUNC) &R_gtk_icon_view_get_model, 1},
    {"R_gtk_icon_view_get_path_at_pos", (DL_FUNC) &R_gtk_icon_view_get_path_at_pos, 3},
    {"R_gtk_icon_view_get_pixbuf_column", (DL_FUNC) &R_gtk_icon_view_get_pixbuf_column, 1},
    {"R_gtk_icon_view_get_reorderable", (DL_FUNC) &R_gtk_icon_view_get_reorderable, 1},
    {"R_gtk_icon_view_get_row_spacing", (DL_FUNC) &R_gtk_icon_view_get_row_spacing, 1},
    {"R_gtk_icon_view_get_selected_items", (DL_FUNC) &R_gtk_icon_view_get_selected_items, 1},
    {"R_gtk_icon_view_get_selection_mode", (DL_FUNC) &R_gtk_icon_view_get_selection_mode, 1},
    {"R_gtk_icon_view_get_spacing", (DL_FUNC) &R_gtk_icon_view_get_spacing, 1},
    {"R_gtk_icon_view_get_text_column", (DL_FUNC) &R_gtk_icon_view_get_text_column, 1},
    {"R_gtk_icon_view_get_tooltip_column", (DL_FUNC) &R_gtk_icon_view_get_tooltip_column, 1},
    {"R_gtk_icon_view_get_tooltip_context", (DL_FUNC) &R_gtk_icon_view_get_tooltip_context, 4},
    {"R_gtk_icon_view_get_visible_range", (DL_FUNC) &R_gtk_icon_view_get_visible_range, 1},
    {"R_gtk_icon_view_item_activated", (DL_FUNC) &R_gtk_icon_view_item_activated, 2},
    {"R_gtk_icon_view_path_is_selected", (DL_FUNC) &R_gtk_icon_view_path_is_selected, 2},
    {"R_gtk_icon_view_scroll_to_path", (DL_FUNC) &R_gtk_icon_view_scroll_to_path, 5},
    {"R_gtk_icon_view_select_all", (DL_FUNC) &R_gtk_icon_view_select_all, 1},
    {"R_gtk_icon_view_select_path", (DL_FUNC) &R_gtk_icon_view_select_path, 2},
    {"R_gtk_icon_view_selected_foreach", (DL_FUNC) &R_gtk_icon_view_selected_foreach, 3},
    {"R_gtk_icon_view_set_activate_on_single_click", (DL_FUNC) &R_gtk_icon_view_set_activate_on_single_click, 2},
    {"R_gtk_icon_view_set_column_spacing", (DL_FUNC) &R_gtk_icon_view_set_column_spacing, 2},
    {"R_gtk_icon_view_set_columns", (DL_FUNC) &R_gtk_icon_view_set_columns, 2},
    {"R_gtk_icon_view_set_cursor", (DL_FUNC) &R_gtk_icon_view_set_cursor, 4},
    {"R_gtk_icon_view_set_drag_dest_item", (DL_FUNC) &R_gtk_icon_view_set_drag_dest_item, 3},
    {"R_gtk_icon_view_set_item_orientation", (DL_FUNC) &R_gtk_icon_view_set_item_orientation, 2},
    {"R_gtk_icon_view_set_item_padding", (DL_FUNC) &R_gtk_icon_view_set_item_padding, 2},
    {"R_gtk_icon_view_set_item_width", (DL_FUNC) &R_gtk_icon_view_set_item_width, 2},
    {"R_gtk_icon_view_set_margin", (DL_FUNC) &R_gtk_icon_view_set_margin, 2},
    {"R_gtk_icon_view_set_markup_column", (DL_FUNC) &R_gtk_icon_view_set_markup_column, 2},
    {"R_gtk_icon_view_set_model", (DL_FUNC) &R_gtk_icon_view_set_model, 2},
    {"R_gtk_icon_view_set_pixbuf_column", (DL_FUNC) &R_gtk_icon_view_set_pixbuf_column, 2},
    {"R_gtk_icon_view_set_reorderable", (DL_FUNC) &R_gtk_icon_view_set_reorderable, 2},
    {"R_gtk_icon_view_set_row_spacing", (DL_FUNC) &R_gtk_icon_view_set_row_spacing, 2},
    {"R_gtk_icon_view_set_selection_mode", (DL_FUNC) &R_gtk_icon_view_set_selection_mode, 2},
    {"R_gtk_icon_view_set_spacing", (DL_FUNC) &R_gtk_icon_view_set_spacing, 2},
    {"R_gtk_icon_view_set_text_column", (DL_FUNC) &R_gtk_icon_view_set_text_column, 2},
    {"R_gtk_icon_view_set_tooltip_cell", (DL_FUNC) &R_gtk_icon_view_set_tooltip_cell, 4},
    {"R_gtk_icon_view_set_tooltip_column", (DL_FUNC) &R_gtk_icon_view_set_tooltip_column, 2},
    {"R_gtk_icon_view_set_tooltip_item", (DL_FUNC) &R_gtk_icon_view_set_tooltip_item, 3},
    {"R_gtk_icon_view_unselect_all", (DL_FUNC) &R_gtk_icon_view_unselect_all, 1},
    {"R_gtk_icon_view_unselect_path", (DL_FUNC) &R_gtk_icon_view_unselect_path, 2},
    {"R_gtk_icon_view_unset_model_drag_dest", (DL_FUNC) &R_gtk_icon_view_unset_model_drag_dest, 1},
    {"R_gtk_icon_view_unset_model_drag_source", (DL_FUNC) &R_gtk_icon_view_unset_model_drag_source, 1},
    {"R_gtk_image_new", (DL_FUNC) &R_gtk_image_new, 0},
    {"R_gtk_image_new_from_file", (DL_FUNC) &R_gtk_image_new_from_file, 1},
    {"R_gtk_image_new_from_gicon", (DL_FUNC) &R_gtk_image_new_from_gicon, 1},
    {"R_gtk_image_new_from_icon_name", (DL_FUNC) &R_gtk_image_new_from_icon_name, 1},
    {"R_gtk_image_new_from_paintable", (DL_FUNC) &R_gtk_image_new_from_paintable, 1},
    {"R_gtk_image_new_from_pixbuf", (DL_FUNC) &R_gtk_image_new_from_pixbuf, 1},
    {"R_gtk_image_new_from_resource", (DL_FUNC) &R_gtk_image_new_from_resource, 1},
    {"R_gtk_image_clear", (DL_FUNC) &R_gtk_image_clear, 1},
    {"R_gtk_image_get_gicon", (DL_FUNC) &R_gtk_image_get_gicon, 1},
    {"R_gtk_image_get_icon_name", (DL_FUNC) &R_gtk_image_get_icon_name, 1},
    {"R_gtk_image_get_icon_size", (DL_FUNC) &R_gtk_image_get_icon_size, 1},
    {"R_gtk_image_get_paintable", (DL_FUNC) &R_gtk_image_get_paintable, 1},
    {"R_gtk_image_get_pixel_size", (DL_FUNC) &R_gtk_image_get_pixel_size, 1},
    {"R_gtk_image_get_storage_type", (DL_FUNC) &R_gtk_image_get_storage_type, 1},
    {"R_gtk_image_set_from_file", (DL_FUNC) &R_gtk_image_set_from_file, 2},
    {"R_gtk_image_set_from_gicon", (DL_FUNC) &R_gtk_image_set_from_gicon, 2},
    {"R_gtk_image_set_from_icon_name", (DL_FUNC) &R_gtk_image_set_from_icon_name, 2},
    {"R_gtk_image_set_from_paintable", (DL_FUNC) &R_gtk_image_set_from_paintable, 2},
    {"R_gtk_image_set_from_pixbuf", (DL_FUNC) &R_gtk_image_set_from_pixbuf, 2},
    {"R_gtk_image_set_from_resource", (DL_FUNC) &R_gtk_image_set_from_resource, 2},
    {"R_gtk_image_set_icon_size", (DL_FUNC) &R_gtk_image_set_icon_size, 2},
    {"R_gtk_image_set_pixel_size", (DL_FUNC) &R_gtk_image_set_pixel_size, 2},
    {"R_gtk_info_bar_new", (DL_FUNC) &R_gtk_info_bar_new, 0},
    {"R_gtk_info_bar_add_action_widget", (DL_FUNC) &R_gtk_info_bar_add_action_widget, 3},
    {"R_gtk_info_bar_add_button", (DL_FUNC) &R_gtk_info_bar_add_button, 3},
    {"R_gtk_info_bar_add_child", (DL_FUNC) &R_gtk_info_bar_add_child, 2},
    {"R_gtk_info_bar_get_message_type", (DL_FUNC) &R_gtk_info_bar_get_message_type, 1},
    {"R_gtk_info_bar_get_revealed", (DL_FUNC) &R_gtk_info_bar_get_revealed, 1},
    {"R_gtk_info_bar_get_show_close_button", (DL_FUNC) &R_gtk_info_bar_get_show_close_button, 1},
    {"R_gtk_info_bar_remove_action_widget", (DL_FUNC) &R_gtk_info_bar_remove_action_widget, 2},
    {"R_gtk_info_bar_remove_child", (DL_FUNC) &R_gtk_info_bar_remove_child, 2},
    {"R_gtk_info_bar_response", (DL_FUNC) &R_gtk_info_bar_response, 2},
    {"R_gtk_info_bar_set_default_response", (DL_FUNC) &R_gtk_info_bar_set_default_response, 2},
    {"R_gtk_info_bar_set_message_type", (DL_FUNC) &R_gtk_info_bar_set_message_type, 2},
    {"R_gtk_info_bar_set_response_sensitive", (DL_FUNC) &R_gtk_info_bar_set_response_sensitive, 3},
    {"R_gtk_info_bar_set_revealed", (DL_FUNC) &R_gtk_info_bar_set_revealed, 2},
    {"R_gtk_info_bar_set_show_close_button", (DL_FUNC) &R_gtk_info_bar_set_show_close_button, 2},
    {"R_gtk_inscription_new", (DL_FUNC) &R_gtk_inscription_new, 1},
    {"R_gtk_inscription_get_attributes", (DL_FUNC) &R_gtk_inscription_get_attributes, 1},
    {"R_gtk_inscription_get_min_chars", (DL_FUNC) &R_gtk_inscription_get_min_chars, 1},
    {"R_gtk_inscription_get_min_lines", (DL_FUNC) &R_gtk_inscription_get_min_lines, 1},
    {"R_gtk_inscription_get_nat_chars", (DL_FUNC) &R_gtk_inscription_get_nat_chars, 1},
    {"R_gtk_inscription_get_nat_lines", (DL_FUNC) &R_gtk_inscription_get_nat_lines, 1},
    {"R_gtk_inscription_get_text", (DL_FUNC) &R_gtk_inscription_get_text, 1},
    {"R_gtk_inscription_get_text_overflow", (DL_FUNC) &R_gtk_inscription_get_text_overflow, 1},
    {"R_gtk_inscription_get_wrap_mode", (DL_FUNC) &R_gtk_inscription_get_wrap_mode, 1},
    {"R_gtk_inscription_get_xalign", (DL_FUNC) &R_gtk_inscription_get_xalign, 1},
    {"R_gtk_inscription_get_yalign", (DL_FUNC) &R_gtk_inscription_get_yalign, 1},
    {"R_gtk_inscription_set_attributes", (DL_FUNC) &R_gtk_inscription_set_attributes, 2},
    {"R_gtk_inscription_set_markup", (DL_FUNC) &R_gtk_inscription_set_markup, 2},
    {"R_gtk_inscription_set_min_chars", (DL_FUNC) &R_gtk_inscription_set_min_chars, 2},
    {"R_gtk_inscription_set_min_lines", (DL_FUNC) &R_gtk_inscription_set_min_lines, 2},
    {"R_gtk_inscription_set_nat_chars", (DL_FUNC) &R_gtk_inscription_set_nat_chars, 2},
    {"R_gtk_inscription_set_nat_lines", (DL_FUNC) &R_gtk_inscription_set_nat_lines, 2},
    {"R_gtk_inscription_set_text", (DL_FUNC) &R_gtk_inscription_set_text, 2},
    {"R_gtk_inscription_set_text_overflow", (DL_FUNC) &R_gtk_inscription_set_text_overflow, 2},
    {"R_gtk_inscription_set_wrap_mode", (DL_FUNC) &R_gtk_inscription_set_wrap_mode, 2},
    {"R_gtk_inscription_set_xalign", (DL_FUNC) &R_gtk_inscription_set_xalign, 2},
    {"R_gtk_inscription_set_yalign", (DL_FUNC) &R_gtk_inscription_set_yalign, 2},
    {"R_gtk_keyval_trigger_new", (DL_FUNC) &R_gtk_keyval_trigger_new, 2},
    {"R_gtk_keyval_trigger_get_keyval", (DL_FUNC) &R_gtk_keyval_trigger_get_keyval, 1},
    {"R_gtk_keyval_trigger_get_modifiers", (DL_FUNC) &R_gtk_keyval_trigger_get_modifiers, 1},
    {"R_gtk_label_new", (DL_FUNC) &R_gtk_label_new, 1},
    {"R_gtk_label_new_with_mnemonic", (DL_FUNC) &R_gtk_label_new_with_mnemonic, 1},
    {"R_gtk_label_get_attributes", (DL_FUNC) &R_gtk_label_get_attributes, 1},
    {"R_gtk_label_get_current_uri", (DL_FUNC) &R_gtk_label_get_current_uri, 1},
    {"R_gtk_label_get_ellipsize", (DL_FUNC) &R_gtk_label_get_ellipsize, 1},
    {"R_gtk_label_get_extra_menu", (DL_FUNC) &R_gtk_label_get_extra_menu, 1},
    {"R_gtk_label_get_justify", (DL_FUNC) &R_gtk_label_get_justify, 1},
    {"R_gtk_label_get_label", (DL_FUNC) &R_gtk_label_get_label, 1},
    {"R_gtk_label_get_layout", (DL_FUNC) &R_gtk_label_get_layout, 1},
    {"R_gtk_label_get_layout_offsets", (DL_FUNC) &R_gtk_label_get_layout_offsets, 1},
    {"R_gtk_label_get_lines", (DL_FUNC) &R_gtk_label_get_lines, 1},
    {"R_gtk_label_get_max_width_chars", (DL_FUNC) &R_gtk_label_get_max_width_chars, 1},
    {"R_gtk_label_get_mnemonic_keyval", (DL_FUNC) &R_gtk_label_get_mnemonic_keyval, 1},
    {"R_gtk_label_get_mnemonic_widget", (DL_FUNC) &R_gtk_label_get_mnemonic_widget, 1},
    {"R_gtk_label_get_natural_wrap_mode", (DL_FUNC) &R_gtk_label_get_natural_wrap_mode, 1},
    {"R_gtk_label_get_selectable", (DL_FUNC) &R_gtk_label_get_selectable, 1},
    {"R_gtk_label_get_selection_bounds", (DL_FUNC) &R_gtk_label_get_selection_bounds, 1},
    {"R_gtk_label_get_single_line_mode", (DL_FUNC) &R_gtk_label_get_single_line_mode, 1},
    {"R_gtk_label_get_tabs", (DL_FUNC) &R_gtk_label_get_tabs, 1},
    {"R_gtk_label_get_text", (DL_FUNC) &R_gtk_label_get_text, 1},
    {"R_gtk_label_get_use_markup", (DL_FUNC) &R_gtk_label_get_use_markup, 1},
    {"R_gtk_label_get_use_underline", (DL_FUNC) &R_gtk_label_get_use_underline, 1},
    {"R_gtk_label_get_width_chars", (DL_FUNC) &R_gtk_label_get_width_chars, 1},
    {"R_gtk_label_get_wrap", (DL_FUNC) &R_gtk_label_get_wrap, 1},
    {"R_gtk_label_get_wrap_mode", (DL_FUNC) &R_gtk_label_get_wrap_mode, 1},
    {"R_gtk_label_get_xalign", (DL_FUNC) &R_gtk_label_get_xalign, 1},
    {"R_gtk_label_get_yalign", (DL_FUNC) &R_gtk_label_get_yalign, 1},
    {"R_gtk_label_select_region", (DL_FUNC) &R_gtk_label_select_region, 3},
    {"R_gtk_label_set_attributes", (DL_FUNC) &R_gtk_label_set_attributes, 2},
    {"R_gtk_label_set_ellipsize", (DL_FUNC) &R_gtk_label_set_ellipsize, 2},
    {"R_gtk_label_set_extra_menu", (DL_FUNC) &R_gtk_label_set_extra_menu, 2},
    {"R_gtk_label_set_justify", (DL_FUNC) &R_gtk_label_set_justify, 2},
    {"R_gtk_label_set_label", (DL_FUNC) &R_gtk_label_set_label, 2},
    {"R_gtk_label_set_lines", (DL_FUNC) &R_gtk_label_set_lines, 2},
    {"R_gtk_label_set_markup", (DL_FUNC) &R_gtk_label_set_markup, 2},
    {"R_gtk_label_set_markup_with_mnemonic", (DL_FUNC) &R_gtk_label_set_markup_with_mnemonic, 2},
    {"R_gtk_label_set_max_width_chars", (DL_FUNC) &R_gtk_label_set_max_width_chars, 2},
    {"R_gtk_label_set_mnemonic_widget", (DL_FUNC) &R_gtk_label_set_mnemonic_widget, 2},
    {"R_gtk_label_set_natural_wrap_mode", (DL_FUNC) &R_gtk_label_set_natural_wrap_mode, 2},
    {"R_gtk_label_set_selectable", (DL_FUNC) &R_gtk_label_set_selectable, 2},
    {"R_gtk_label_set_single_line_mode", (DL_FUNC) &R_gtk_label_set_single_line_mode, 2},
    {"R_gtk_label_set_tabs", (DL_FUNC) &R_gtk_label_set_tabs, 2},
    {"R_gtk_label_set_text", (DL_FUNC) &R_gtk_label_set_text, 2},
    {"R_gtk_label_set_text_with_mnemonic", (DL_FUNC) &R_gtk_label_set_text_with_mnemonic, 2},
    {"R_gtk_label_set_use_markup", (DL_FUNC) &R_gtk_label_set_use_markup, 2},
    {"R_gtk_label_set_use_underline", (DL_FUNC) &R_gtk_label_set_use_underline, 2},
    {"R_gtk_label_set_width_chars", (DL_FUNC) &R_gtk_label_set_width_chars, 2},
    {"R_gtk_label_set_wrap", (DL_FUNC) &R_gtk_label_set_wrap, 2},
    {"R_gtk_label_set_wrap_mode", (DL_FUNC) &R_gtk_label_set_wrap_mode, 2},
    {"R_gtk_label_set_xalign", (DL_FUNC) &R_gtk_label_set_xalign, 2},
    {"R_gtk_label_set_yalign", (DL_FUNC) &R_gtk_label_set_yalign, 2},
    {"R_gtk_layout_child_get_child_widget", (DL_FUNC) &R_gtk_layout_child_get_child_widget, 1},
    {"R_gtk_layout_child_get_layout_manager", (DL_FUNC) &R_gtk_layout_child_get_layout_manager, 1},
    {"R_gtk_layout_manager_allocate", (DL_FUNC) &R_gtk_layout_manager_allocate, 5},
    {"R_gtk_layout_manager_get_layout_child", (DL_FUNC) &R_gtk_layout_manager_get_layout_child, 2},
    {"R_gtk_layout_manager_get_request_mode", (DL_FUNC) &R_gtk_layout_manager_get_request_mode, 1},
    {"R_gtk_layout_manager_get_widget", (DL_FUNC) &R_gtk_layout_manager_get_widget, 1},
    {"R_gtk_layout_manager_layout_changed", (DL_FUNC) &R_gtk_layout_manager_layout_changed, 1},
    {"R_gtk_layout_manager_measure", (DL_FUNC) &R_gtk_layout_manager_measure, 4},
    {"R_gtk_level_bar_new", (DL_FUNC) &R_gtk_level_bar_new, 0},
    {"R_gtk_level_bar_new_for_interval", (DL_FUNC) &R_gtk_level_bar_new_for_interval, 2},
    {"R_gtk_level_bar_add_offset_value", (DL_FUNC) &R_gtk_level_bar_add_offset_value, 3},
    {"R_gtk_level_bar_get_inverted", (DL_FUNC) &R_gtk_level_bar_get_inverted, 1},
    {"R_gtk_level_bar_get_max_value", (DL_FUNC) &R_gtk_level_bar_get_max_value, 1},
    {"R_gtk_level_bar_get_min_value", (DL_FUNC) &R_gtk_level_bar_get_min_value, 1},
    {"R_gtk_level_bar_get_mode", (DL_FUNC) &R_gtk_level_bar_get_mode, 1},
    {"R_gtk_level_bar_get_offset_value", (DL_FUNC) &R_gtk_level_bar_get_offset_value, 2},
    {"R_gtk_level_bar_get_value", (DL_FUNC) &R_gtk_level_bar_get_value, 1},
    {"R_gtk_level_bar_remove_offset_value", (DL_FUNC) &R_gtk_level_bar_remove_offset_value, 2},
    {"R_gtk_level_bar_set_inverted", (DL_FUNC) &R_gtk_level_bar_set_inverted, 2},
    {"R_gtk_level_bar_set_max_value", (DL_FUNC) &R_gtk_level_bar_set_max_value, 2},
    {"R_gtk_level_bar_set_min_value", (DL_FUNC) &R_gtk_level_bar_set_min_value, 2},
    {"R_gtk_level_bar_set_mode", (DL_FUNC) &R_gtk_level_bar_set_mode, 2},
    {"R_gtk_level_bar_set_value", (DL_FUNC) &R_gtk_level_bar_set_value, 2},
    {"R_gtk_link_button_new", (DL_FUNC) &R_gtk_link_button_new, 1},
    {"R_gtk_link_button_new_with_label", (DL_FUNC) &R_gtk_link_button_new_with_label, 2},
    {"R_gtk_link_button_get_uri", (DL_FUNC) &R_gtk_link_button_get_uri, 1},
    {"R_gtk_link_button_get_visited", (DL_FUNC) &R_gtk_link_button_get_visited, 1},
    {"R_gtk_link_button_set_uri", (DL_FUNC) &R_gtk_link_button_set_uri, 2},
    {"R_gtk_link_button_set_visited", (DL_FUNC) &R_gtk_link_button_set_visited, 2},
    {"R_gtk_list_box_new", (DL_FUNC) &R_gtk_list_box_new, 0},
    {"R_gtk_list_box_append", (DL_FUNC) &R_gtk_list_box_append, 2},
    {"R_gtk_list_box_bind_model", (DL_FUNC) &R_gtk_list_box_bind_model, 5},
    {"R_gtk_list_box_drag_highlight_row", (DL_FUNC) &R_gtk_list_box_drag_highlight_row, 2},
    {"R_gtk_list_box_drag_unhighlight_row", (DL_FUNC) &R_gtk_list_box_drag_unhighlight_row, 1},
    {"R_gtk_list_box_get_activate_on_single_click", (DL_FUNC) &R_gtk_list_box_get_activate_on_single_click, 1},
    {"R_gtk_list_box_get_adjustment", (DL_FUNC) &R_gtk_list_box_get_adjustment, 1},
    {"R_gtk_list_box_get_row_at_index", (DL_FUNC) &R_gtk_list_box_get_row_at_index, 2},
    {"R_gtk_list_box_get_row_at_y", (DL_FUNC) &R_gtk_list_box_get_row_at_y, 2},
    {"R_gtk_list_box_get_selected_row", (DL_FUNC) &R_gtk_list_box_get_selected_row, 1},
    {"R_gtk_list_box_get_selected_rows", (DL_FUNC) &R_gtk_list_box_get_selected_rows, 1},
    {"R_gtk_list_box_get_selection_mode", (DL_FUNC) &R_gtk_list_box_get_selection_mode, 1},
    {"R_gtk_list_box_get_show_separators", (DL_FUNC) &R_gtk_list_box_get_show_separators, 1},
    {"R_gtk_list_box_insert", (DL_FUNC) &R_gtk_list_box_insert, 3},
    {"R_gtk_list_box_invalidate_filter", (DL_FUNC) &R_gtk_list_box_invalidate_filter, 1},
    {"R_gtk_list_box_invalidate_headers", (DL_FUNC) &R_gtk_list_box_invalidate_headers, 1},
    {"R_gtk_list_box_invalidate_sort", (DL_FUNC) &R_gtk_list_box_invalidate_sort, 1},
    {"R_gtk_list_box_prepend", (DL_FUNC) &R_gtk_list_box_prepend, 2},
    {"R_gtk_list_box_remove", (DL_FUNC) &R_gtk_list_box_remove, 2},
    {"R_gtk_list_box_remove_all", (DL_FUNC) &R_gtk_list_box_remove_all, 1},
    {"R_gtk_list_box_select_all", (DL_FUNC) &R_gtk_list_box_select_all, 1},
    {"R_gtk_list_box_select_row", (DL_FUNC) &R_gtk_list_box_select_row, 2},
    {"R_gtk_list_box_selected_foreach", (DL_FUNC) &R_gtk_list_box_selected_foreach, 3},
    {"R_gtk_list_box_set_activate_on_single_click", (DL_FUNC) &R_gtk_list_box_set_activate_on_single_click, 2},
    {"R_gtk_list_box_set_adjustment", (DL_FUNC) &R_gtk_list_box_set_adjustment, 2},
    {"R_gtk_list_box_set_filter_func", (DL_FUNC) &R_gtk_list_box_set_filter_func, 4},
    {"R_gtk_list_box_set_header_func", (DL_FUNC) &R_gtk_list_box_set_header_func, 4},
    {"R_gtk_list_box_set_placeholder", (DL_FUNC) &R_gtk_list_box_set_placeholder, 2},
    {"R_gtk_list_box_set_selection_mode", (DL_FUNC) &R_gtk_list_box_set_selection_mode, 2},
    {"R_gtk_list_box_set_show_separators", (DL_FUNC) &R_gtk_list_box_set_show_separators, 2},
    {"R_gtk_list_box_set_sort_func", (DL_FUNC) &R_gtk_list_box_set_sort_func, 4},
    {"R_gtk_list_box_unselect_all", (DL_FUNC) &R_gtk_list_box_unselect_all, 1},
    {"R_gtk_list_box_unselect_row", (DL_FUNC) &R_gtk_list_box_unselect_row, 2},
    {"R_gtk_list_box_row_new", (DL_FUNC) &R_gtk_list_box_row_new, 0},
    {"R_gtk_list_box_row_changed", (DL_FUNC) &R_gtk_list_box_row_changed, 1},
    {"R_gtk_list_box_row_get_activatable", (DL_FUNC) &R_gtk_list_box_row_get_activatable, 1},
    {"R_gtk_list_box_row_get_child", (DL_FUNC) &R_gtk_list_box_row_get_child, 1},
    {"R_gtk_list_box_row_get_header", (DL_FUNC) &R_gtk_list_box_row_get_header, 1},
    {"R_gtk_list_box_row_get_index", (DL_FUNC) &R_gtk_list_box_row_get_index, 1},
    {"R_gtk_list_box_row_get_selectable", (DL_FUNC) &R_gtk_list_box_row_get_selectable, 1},
    {"R_gtk_list_box_row_is_selected", (DL_FUNC) &R_gtk_list_box_row_is_selected, 1},
    {"R_gtk_list_box_row_set_activatable", (DL_FUNC) &R_gtk_list_box_row_set_activatable, 2},
    {"R_gtk_list_box_row_set_child", (DL_FUNC) &R_gtk_list_box_row_set_child, 2},
    {"R_gtk_list_box_row_set_header", (DL_FUNC) &R_gtk_list_box_row_set_header, 2},
    {"R_gtk_list_box_row_set_selectable", (DL_FUNC) &R_gtk_list_box_row_set_selectable, 2},
    {"R_gtk_list_header_get_child", (DL_FUNC) &R_gtk_list_header_get_child, 1},
    {"R_gtk_list_header_get_end", (DL_FUNC) &R_gtk_list_header_get_end, 1},
    {"R_gtk_list_header_get_item", (DL_FUNC) &R_gtk_list_header_get_item, 1},
    {"R_gtk_list_header_get_n_items", (DL_FUNC) &R_gtk_list_header_get_n_items, 1},
    {"R_gtk_list_header_get_start", (DL_FUNC) &R_gtk_list_header_get_start, 1},
    {"R_gtk_list_header_set_child", (DL_FUNC) &R_gtk_list_header_set_child, 2},
    {"R_gtk_list_item_get_accessible_description", (DL_FUNC) &R_gtk_list_item_get_accessible_description, 1},
    {"R_gtk_list_item_get_accessible_label", (DL_FUNC) &R_gtk_list_item_get_accessible_label, 1},
    {"R_gtk_list_item_get_activatable", (DL_FUNC) &R_gtk_list_item_get_activatable, 1},
    {"R_gtk_list_item_get_child", (DL_FUNC) &R_gtk_list_item_get_child, 1},
    {"R_gtk_list_item_get_focusable", (DL_FUNC) &R_gtk_list_item_get_focusable, 1},
    {"R_gtk_list_item_get_item", (DL_FUNC) &R_gtk_list_item_get_item, 1},
    {"R_gtk_list_item_get_position", (DL_FUNC) &R_gtk_list_item_get_position, 1},
    {"R_gtk_list_item_get_selectable", (DL_FUNC) &R_gtk_list_item_get_selectable, 1},
    {"R_gtk_list_item_get_selected", (DL_FUNC) &R_gtk_list_item_get_selected, 1},
    {"R_gtk_list_item_set_accessible_description", (DL_FUNC) &R_gtk_list_item_set_accessible_description, 2},
    {"R_gtk_list_item_set_accessible_label", (DL_FUNC) &R_gtk_list_item_set_accessible_label, 2},
    {"R_gtk_list_item_set_activatable", (DL_FUNC) &R_gtk_list_item_set_activatable, 2},
    {"R_gtk_list_item_set_child", (DL_FUNC) &R_gtk_list_item_set_child, 2},
    {"R_gtk_list_item_set_focusable", (DL_FUNC) &R_gtk_list_item_set_focusable, 2},
    {"R_gtk_list_item_set_selectable", (DL_FUNC) &R_gtk_list_item_set_selectable, 2},
    {"R_gtk_list_store_newv", (DL_FUNC) &R_gtk_list_store_newv, 2},
    {"R_gtk_list_store_append", (DL_FUNC) &R_gtk_list_store_append, 1},
    {"R_gtk_list_store_clear", (DL_FUNC) &R_gtk_list_store_clear, 1},
    {"R_gtk_list_store_insert", (DL_FUNC) &R_gtk_list_store_insert, 2},
    {"R_gtk_list_store_insert_after", (DL_FUNC) &R_gtk_list_store_insert_after, 2},
    {"R_gtk_list_store_insert_before", (DL_FUNC) &R_gtk_list_store_insert_before, 2},
    {"R_gtk_list_store_insert_with_valuesv", (DL_FUNC) &R_gtk_list_store_insert_with_valuesv, 5},
    {"R_gtk_list_store_iter_is_valid", (DL_FUNC) &R_gtk_list_store_iter_is_valid, 2},
    {"R_gtk_list_store_move_after", (DL_FUNC) &R_gtk_list_store_move_after, 3},
    {"R_gtk_list_store_move_before", (DL_FUNC) &R_gtk_list_store_move_before, 3},
    {"R_gtk_list_store_prepend", (DL_FUNC) &R_gtk_list_store_prepend, 1},
    {"R_gtk_list_store_remove", (DL_FUNC) &R_gtk_list_store_remove, 2},
    {"R_gtk_list_store_reorder", (DL_FUNC) &R_gtk_list_store_reorder, 2},
    {"R_gtk_list_store_set_column_types", (DL_FUNC) &R_gtk_list_store_set_column_types, 3},
    {"R_gtk_list_store_set_value", (DL_FUNC) &R_gtk_list_store_set_value, 4},
    {"R_gtk_list_store_set_valuesv", (DL_FUNC) &R_gtk_list_store_set_valuesv, 5},
    {"R_gtk_list_store_swap", (DL_FUNC) &R_gtk_list_store_swap, 3},
    {"R_gtk_list_view_new", (DL_FUNC) &R_gtk_list_view_new, 2},
    {"R_gtk_list_view_get_enable_rubberband", (DL_FUNC) &R_gtk_list_view_get_enable_rubberband, 1},
    {"R_gtk_list_view_get_factory", (DL_FUNC) &R_gtk_list_view_get_factory, 1},
    {"R_gtk_list_view_get_header_factory", (DL_FUNC) &R_gtk_list_view_get_header_factory, 1},
    {"R_gtk_list_view_get_model", (DL_FUNC) &R_gtk_list_view_get_model, 1},
    {"R_gtk_list_view_get_show_separators", (DL_FUNC) &R_gtk_list_view_get_show_separators, 1},
    {"R_gtk_list_view_get_single_click_activate", (DL_FUNC) &R_gtk_list_view_get_single_click_activate, 1},
    {"R_gtk_list_view_get_tab_behavior", (DL_FUNC) &R_gtk_list_view_get_tab_behavior, 1},
    {"R_gtk_list_view_scroll_to", (DL_FUNC) &R_gtk_list_view_scroll_to, 4},
    {"R_gtk_list_view_set_enable_rubberband", (DL_FUNC) &R_gtk_list_view_set_enable_rubberband, 2},
    {"R_gtk_list_view_set_factory", (DL_FUNC) &R_gtk_list_view_set_factory, 2},
    {"R_gtk_list_view_set_header_factory", (DL_FUNC) &R_gtk_list_view_set_header_factory, 2},
    {"R_gtk_list_view_set_model", (DL_FUNC) &R_gtk_list_view_set_model, 2},
    {"R_gtk_list_view_set_show_separators", (DL_FUNC) &R_gtk_list_view_set_show_separators, 2},
    {"R_gtk_list_view_set_single_click_activate", (DL_FUNC) &R_gtk_list_view_set_single_click_activate, 2},
    {"R_gtk_list_view_set_tab_behavior", (DL_FUNC) &R_gtk_list_view_set_tab_behavior, 2},
    {"R_gtk_lock_button_new", (DL_FUNC) &R_gtk_lock_button_new, 1},
    {"R_gtk_lock_button_get_permission", (DL_FUNC) &R_gtk_lock_button_get_permission, 1},
    {"R_gtk_lock_button_set_permission", (DL_FUNC) &R_gtk_lock_button_set_permission, 2},
    {"R_gtk_map_list_model_new", (DL_FUNC) &R_gtk_map_list_model_new, 4},
    {"R_gtk_map_list_model_get_model", (DL_FUNC) &R_gtk_map_list_model_get_model, 1},
    {"R_gtk_map_list_model_has_map", (DL_FUNC) &R_gtk_map_list_model_has_map, 1},
    {"R_gtk_map_list_model_set_map_func", (DL_FUNC) &R_gtk_map_list_model_set_map_func, 4},
    {"R_gtk_map_list_model_set_model", (DL_FUNC) &R_gtk_map_list_model_set_model, 2},
    {"R_gtk_media_controls_new", (DL_FUNC) &R_gtk_media_controls_new, 1},
    {"R_gtk_media_controls_get_media_stream", (DL_FUNC) &R_gtk_media_controls_get_media_stream, 1},
    {"R_gtk_media_controls_set_media_stream", (DL_FUNC) &R_gtk_media_controls_set_media_stream, 2},
    {"R_gtk_media_file_new", (DL_FUNC) &R_gtk_media_file_new, 0},
    {"R_gtk_media_file_new_for_file", (DL_FUNC) &R_gtk_media_file_new_for_file, 1},
    {"R_gtk_media_file_new_for_filename", (DL_FUNC) &R_gtk_media_file_new_for_filename, 1},
    {"R_gtk_media_file_new_for_input_stream", (DL_FUNC) &R_gtk_media_file_new_for_input_stream, 1},
    {"R_gtk_media_file_new_for_resource", (DL_FUNC) &R_gtk_media_file_new_for_resource, 1},
    {"R_gtk_media_file_clear", (DL_FUNC) &R_gtk_media_file_clear, 1},
    {"R_gtk_media_file_get_file", (DL_FUNC) &R_gtk_media_file_get_file, 1},
    {"R_gtk_media_file_get_input_stream", (DL_FUNC) &R_gtk_media_file_get_input_stream, 1},
    {"R_gtk_media_file_set_file", (DL_FUNC) &R_gtk_media_file_set_file, 2},
    {"R_gtk_media_file_set_filename", (DL_FUNC) &R_gtk_media_file_set_filename, 2},
    {"R_gtk_media_file_set_input_stream", (DL_FUNC) &R_gtk_media_file_set_input_stream, 2},
    {"R_gtk_media_file_set_resource", (DL_FUNC) &R_gtk_media_file_set_resource, 2},
    {"R_gtk_media_stream_gerror", (DL_FUNC) &R_gtk_media_stream_gerror, 2},
    {"R_gtk_media_stream_get_duration", (DL_FUNC) &R_gtk_media_stream_get_duration, 1},
    {"R_gtk_media_stream_get_ended", (DL_FUNC) &R_gtk_media_stream_get_ended, 1},
    {"R_gtk_media_stream_get_error", (DL_FUNC) &R_gtk_media_stream_get_error, 1},
    {"R_gtk_media_stream_get_loop", (DL_FUNC) &R_gtk_media_stream_get_loop, 1},
    {"R_gtk_media_stream_get_muted", (DL_FUNC) &R_gtk_media_stream_get_muted, 1},
    {"R_gtk_media_stream_get_playing", (DL_FUNC) &R_gtk_media_stream_get_playing, 1},
    {"R_gtk_media_stream_get_timestamp", (DL_FUNC) &R_gtk_media_stream_get_timestamp, 1},
    {"R_gtk_media_stream_get_volume", (DL_FUNC) &R_gtk_media_stream_get_volume, 1},
    {"R_gtk_media_stream_has_audio", (DL_FUNC) &R_gtk_media_stream_has_audio, 1},
    {"R_gtk_media_stream_has_video", (DL_FUNC) &R_gtk_media_stream_has_video, 1},
    {"R_gtk_media_stream_is_prepared", (DL_FUNC) &R_gtk_media_stream_is_prepared, 1},
    {"R_gtk_media_stream_is_seekable", (DL_FUNC) &R_gtk_media_stream_is_seekable, 1},
    {"R_gtk_media_stream_is_seeking", (DL_FUNC) &R_gtk_media_stream_is_seeking, 1},
    {"R_gtk_media_stream_pause", (DL_FUNC) &R_gtk_media_stream_pause, 1},
    {"R_gtk_media_stream_play", (DL_FUNC) &R_gtk_media_stream_play, 1},
    {"R_gtk_media_stream_realize", (DL_FUNC) &R_gtk_media_stream_realize, 2},
    {"R_gtk_media_stream_seek", (DL_FUNC) &R_gtk_media_stream_seek, 2},
    {"R_gtk_media_stream_seek_failed", (DL_FUNC) &R_gtk_media_stream_seek_failed, 1},
    {"R_gtk_media_stream_seek_success", (DL_FUNC) &R_gtk_media_stream_seek_success, 1},
    {"R_gtk_media_stream_set_loop", (DL_FUNC) &R_gtk_media_stream_set_loop, 2},
    {"R_gtk_media_stream_set_muted", (DL_FUNC) &R_gtk_media_stream_set_muted, 2},
    {"R_gtk_media_stream_set_playing", (DL_FUNC) &R_gtk_media_stream_set_playing, 2},
    {"R_gtk_media_stream_set_volume", (DL_FUNC) &R_gtk_media_stream_set_volume, 2},
    {"R_gtk_media_stream_stream_ended", (DL_FUNC) &R_gtk_media_stream_stream_ended, 1},
    {"R_gtk_media_stream_stream_prepared", (DL_FUNC) &R_gtk_media_stream_stream_prepared, 5},
    {"R_gtk_media_stream_stream_unprepared", (DL_FUNC) &R_gtk_media_stream_stream_unprepared, 1},
    {"R_gtk_media_stream_unrealize", (DL_FUNC) &R_gtk_media_stream_unrealize, 2},
    {"R_gtk_media_stream_update", (DL_FUNC) &R_gtk_media_stream_update, 2},
    {"R_gtk_menu_button_new", (DL_FUNC) &R_gtk_menu_button_new, 0},
    {"R_gtk_menu_button_get_active", (DL_FUNC) &R_gtk_menu_button_get_active, 1},
    {"R_gtk_menu_button_get_always_show_arrow", (DL_FUNC) &R_gtk_menu_button_get_always_show_arrow, 1},
    {"R_gtk_menu_button_get_can_shrink", (DL_FUNC) &R_gtk_menu_button_get_can_shrink, 1},
    {"R_gtk_menu_button_get_child", (DL_FUNC) &R_gtk_menu_button_get_child, 1},
    {"R_gtk_menu_button_get_direction", (DL_FUNC) &R_gtk_menu_button_get_direction, 1},
    {"R_gtk_menu_button_get_has_frame", (DL_FUNC) &R_gtk_menu_button_get_has_frame, 1},
    {"R_gtk_menu_button_get_icon_name", (DL_FUNC) &R_gtk_menu_button_get_icon_name, 1},
    {"R_gtk_menu_button_get_label", (DL_FUNC) &R_gtk_menu_button_get_label, 1},
    {"R_gtk_menu_button_get_menu_model", (DL_FUNC) &R_gtk_menu_button_get_menu_model, 1},
    {"R_gtk_menu_button_get_popover", (DL_FUNC) &R_gtk_menu_button_get_popover, 1},
    {"R_gtk_menu_button_get_primary", (DL_FUNC) &R_gtk_menu_button_get_primary, 1},
    {"R_gtk_menu_button_get_use_underline", (DL_FUNC) &R_gtk_menu_button_get_use_underline, 1},
    {"R_gtk_menu_button_popdown", (DL_FUNC) &R_gtk_menu_button_popdown, 1},
    {"R_gtk_menu_button_popup", (DL_FUNC) &R_gtk_menu_button_popup, 1},
    {"R_gtk_menu_button_set_active", (DL_FUNC) &R_gtk_menu_button_set_active, 2},
    {"R_gtk_menu_button_set_always_show_arrow", (DL_FUNC) &R_gtk_menu_button_set_always_show_arrow, 2},
    {"R_gtk_menu_button_set_can_shrink", (DL_FUNC) &R_gtk_menu_button_set_can_shrink, 2},
    {"R_gtk_menu_button_set_child", (DL_FUNC) &R_gtk_menu_button_set_child, 2},
    {"R_gtk_menu_button_set_create_popup_func", (DL_FUNC) &R_gtk_menu_button_set_create_popup_func, 4},
    {"R_gtk_menu_button_set_direction", (DL_FUNC) &R_gtk_menu_button_set_direction, 2},
    {"R_gtk_menu_button_set_has_frame", (DL_FUNC) &R_gtk_menu_button_set_has_frame, 2},
    {"R_gtk_menu_button_set_icon_name", (DL_FUNC) &R_gtk_menu_button_set_icon_name, 2},
    {"R_gtk_menu_button_set_label", (DL_FUNC) &R_gtk_menu_button_set_label, 2},
    {"R_gtk_menu_button_set_menu_model", (DL_FUNC) &R_gtk_menu_button_set_menu_model, 2},
    {"R_gtk_menu_button_set_popover", (DL_FUNC) &R_gtk_menu_button_set_popover, 2},
    {"R_gtk_menu_button_set_primary", (DL_FUNC) &R_gtk_menu_button_set_primary, 2},
    {"R_gtk_menu_button_set_use_underline", (DL_FUNC) &R_gtk_menu_button_set_use_underline, 2},
    {"R_gtk_message_dialog_get_message_area", (DL_FUNC) &R_gtk_message_dialog_get_message_area, 1},
    {"R_gtk_message_dialog_set_markup", (DL_FUNC) &R_gtk_message_dialog_set_markup, 2},
    {"R_gtk_mnemonic_action_get", (DL_FUNC) &R_gtk_mnemonic_action_get, 0},
    {"R_gtk_mnemonic_trigger_new", (DL_FUNC) &R_gtk_mnemonic_trigger_new, 1},
    {"R_gtk_mnemonic_trigger_get_keyval", (DL_FUNC) &R_gtk_mnemonic_trigger_get_keyval, 1},
    {"R_gtk_mount_operation_new", (DL_FUNC) &R_gtk_mount_operation_new, 1},
    {"R_gtk_mount_operation_get_display", (DL_FUNC) &R_gtk_mount_operation_get_display, 1},
    {"R_gtk_mount_operation_get_parent", (DL_FUNC) &R_gtk_mount_operation_get_parent, 1},
    {"R_gtk_mount_operation_is_showing", (DL_FUNC) &R_gtk_mount_operation_is_showing, 1},
    {"R_gtk_mount_operation_set_display", (DL_FUNC) &R_gtk_mount_operation_set_display, 2},
    {"R_gtk_mount_operation_set_parent", (DL_FUNC) &R_gtk_mount_operation_set_parent, 2},
    {"R_gtk_multi_filter_append", (DL_FUNC) &R_gtk_multi_filter_append, 2},
    {"R_gtk_multi_filter_remove", (DL_FUNC) &R_gtk_multi_filter_remove, 2},
    {"R_gtk_multi_selection_new", (DL_FUNC) &R_gtk_multi_selection_new, 1},
    {"R_gtk_multi_selection_get_model", (DL_FUNC) &R_gtk_multi_selection_get_model, 1},
    {"R_gtk_multi_selection_set_model", (DL_FUNC) &R_gtk_multi_selection_set_model, 2},
    {"R_gtk_multi_sorter_new", (DL_FUNC) &R_gtk_multi_sorter_new, 0},
    {"R_gtk_multi_sorter_append", (DL_FUNC) &R_gtk_multi_sorter_append, 2},
    {"R_gtk_multi_sorter_remove", (DL_FUNC) &R_gtk_multi_sorter_remove, 2},
    {"R_gtk_named_action_new", (DL_FUNC) &R_gtk_named_action_new, 1},
    {"R_gtk_named_action_get_action_name", (DL_FUNC) &R_gtk_named_action_get_action_name, 1},
    {"R_gtk_native_get_for_surface", (DL_FUNC) &R_gtk_native_get_for_surface, 1},
    {"R_gtk_native_get_renderer", (DL_FUNC) &R_gtk_native_get_renderer, 1},
    {"R_gtk_native_get_surface", (DL_FUNC) &R_gtk_native_get_surface, 1},
    {"R_gtk_native_get_surface_transform", (DL_FUNC) &R_gtk_native_get_surface_transform, 1},
    {"R_gtk_native_realize", (DL_FUNC) &R_gtk_native_realize, 1},
    {"R_gtk_native_unrealize", (DL_FUNC) &R_gtk_native_unrealize, 1},
    {"R_gtk_native_dialog_destroy", (DL_FUNC) &R_gtk_native_dialog_destroy, 1},
    {"R_gtk_native_dialog_get_modal", (DL_FUNC) &R_gtk_native_dialog_get_modal, 1},
    {"R_gtk_native_dialog_get_title", (DL_FUNC) &R_gtk_native_dialog_get_title, 1},
    {"R_gtk_native_dialog_get_transient_for", (DL_FUNC) &R_gtk_native_dialog_get_transient_for, 1},
    {"R_gtk_native_dialog_get_visible", (DL_FUNC) &R_gtk_native_dialog_get_visible, 1},
    {"R_gtk_native_dialog_hide", (DL_FUNC) &R_gtk_native_dialog_hide, 1},
    {"R_gtk_native_dialog_set_modal", (DL_FUNC) &R_gtk_native_dialog_set_modal, 2},
    {"R_gtk_native_dialog_set_title", (DL_FUNC) &R_gtk_native_dialog_set_title, 2},
    {"R_gtk_native_dialog_set_transient_for", (DL_FUNC) &R_gtk_native_dialog_set_transient_for, 2},
    {"R_gtk_native_dialog_show", (DL_FUNC) &R_gtk_native_dialog_show, 1},
    {"R_gtk_never_trigger_get", (DL_FUNC) &R_gtk_never_trigger_get, 0},
    {"R_gtk_no_selection_new", (DL_FUNC) &R_gtk_no_selection_new, 1},
    {"R_gtk_no_selection_get_model", (DL_FUNC) &R_gtk_no_selection_get_model, 1},
    {"R_gtk_no_selection_set_model", (DL_FUNC) &R_gtk_no_selection_set_model, 2},
    {"R_gtk_notebook_new", (DL_FUNC) &R_gtk_notebook_new, 0},
    {"R_gtk_notebook_append_page", (DL_FUNC) &R_gtk_notebook_append_page, 3},
    {"R_gtk_notebook_append_page_menu", (DL_FUNC) &R_gtk_notebook_append_page_menu, 4},
    {"R_gtk_notebook_detach_tab", (DL_FUNC) &R_gtk_notebook_detach_tab, 2},
    {"R_gtk_notebook_get_action_widget", (DL_FUNC) &R_gtk_notebook_get_action_widget, 2},
    {"R_gtk_notebook_get_current_page", (DL_FUNC) &R_gtk_notebook_get_current_page, 1},
    {"R_gtk_notebook_get_group_name", (DL_FUNC) &R_gtk_notebook_get_group_name, 1},
    {"R_gtk_notebook_get_menu_label", (DL_FUNC) &R_gtk_notebook_get_menu_label, 2},
    {"R_gtk_notebook_get_menu_label_text", (DL_FUNC) &R_gtk_notebook_get_menu_label_text, 2},
    {"R_gtk_notebook_get_n_pages", (DL_FUNC) &R_gtk_notebook_get_n_pages, 1},
    {"R_gtk_notebook_get_nth_page", (DL_FUNC) &R_gtk_notebook_get_nth_page, 2},
    {"R_gtk_notebook_get_page", (DL_FUNC) &R_gtk_notebook_get_page, 2},
    {"R_gtk_notebook_get_pages", (DL_FUNC) &R_gtk_notebook_get_pages, 1},
    {"R_gtk_notebook_get_scrollable", (DL_FUNC) &R_gtk_notebook_get_scrollable, 1},
    {"R_gtk_notebook_get_show_border", (DL_FUNC) &R_gtk_notebook_get_show_border, 1},
    {"R_gtk_notebook_get_show_tabs", (DL_FUNC) &R_gtk_notebook_get_show_tabs, 1},
    {"R_gtk_notebook_get_tab_detachable", (DL_FUNC) &R_gtk_notebook_get_tab_detachable, 2},
    {"R_gtk_notebook_get_tab_label", (DL_FUNC) &R_gtk_notebook_get_tab_label, 2},
    {"R_gtk_notebook_get_tab_label_text", (DL_FUNC) &R_gtk_notebook_get_tab_label_text, 2},
    {"R_gtk_notebook_get_tab_pos", (DL_FUNC) &R_gtk_notebook_get_tab_pos, 1},
    {"R_gtk_notebook_get_tab_reorderable", (DL_FUNC) &R_gtk_notebook_get_tab_reorderable, 2},
    {"R_gtk_notebook_insert_page", (DL_FUNC) &R_gtk_notebook_insert_page, 4},
    {"R_gtk_notebook_insert_page_menu", (DL_FUNC) &R_gtk_notebook_insert_page_menu, 5},
    {"R_gtk_notebook_next_page", (DL_FUNC) &R_gtk_notebook_next_page, 1},
    {"R_gtk_notebook_page_num", (DL_FUNC) &R_gtk_notebook_page_num, 2},
    {"R_gtk_notebook_popup_disable", (DL_FUNC) &R_gtk_notebook_popup_disable, 1},
    {"R_gtk_notebook_popup_enable", (DL_FUNC) &R_gtk_notebook_popup_enable, 1},
    {"R_gtk_notebook_prepend_page", (DL_FUNC) &R_gtk_notebook_prepend_page, 3},
    {"R_gtk_notebook_prepend_page_menu", (DL_FUNC) &R_gtk_notebook_prepend_page_menu, 4},
    {"R_gtk_notebook_prev_page", (DL_FUNC) &R_gtk_notebook_prev_page, 1},
    {"R_gtk_notebook_remove_page", (DL_FUNC) &R_gtk_notebook_remove_page, 2},
    {"R_gtk_notebook_reorder_child", (DL_FUNC) &R_gtk_notebook_reorder_child, 3},
    {"R_gtk_notebook_set_action_widget", (DL_FUNC) &R_gtk_notebook_set_action_widget, 3},
    {"R_gtk_notebook_set_current_page", (DL_FUNC) &R_gtk_notebook_set_current_page, 2},
    {"R_gtk_notebook_set_group_name", (DL_FUNC) &R_gtk_notebook_set_group_name, 2},
    {"R_gtk_notebook_set_menu_label", (DL_FUNC) &R_gtk_notebook_set_menu_label, 3},
    {"R_gtk_notebook_set_menu_label_text", (DL_FUNC) &R_gtk_notebook_set_menu_label_text, 3},
    {"R_gtk_notebook_set_scrollable", (DL_FUNC) &R_gtk_notebook_set_scrollable, 2},
    {"R_gtk_notebook_set_show_border", (DL_FUNC) &R_gtk_notebook_set_show_border, 2},
    {"R_gtk_notebook_set_show_tabs", (DL_FUNC) &R_gtk_notebook_set_show_tabs, 2},
    {"R_gtk_notebook_set_tab_detachable", (DL_FUNC) &R_gtk_notebook_set_tab_detachable, 3},
    {"R_gtk_notebook_set_tab_label", (DL_FUNC) &R_gtk_notebook_set_tab_label, 3},
    {"R_gtk_notebook_set_tab_label_text", (DL_FUNC) &R_gtk_notebook_set_tab_label_text, 3},
    {"R_gtk_notebook_set_tab_pos", (DL_FUNC) &R_gtk_notebook_set_tab_pos, 2},
    {"R_gtk_notebook_set_tab_reorderable", (DL_FUNC) &R_gtk_notebook_set_tab_reorderable, 3},
    {"R_gtk_notebook_page_get_child", (DL_FUNC) &R_gtk_notebook_page_get_child, 1},
    {"R_gtk_nothing_action_get", (DL_FUNC) &R_gtk_nothing_action_get, 0},
    {"R_gtk_numeric_sorter_new", (DL_FUNC) &R_gtk_numeric_sorter_new, 1},
    {"R_gtk_numeric_sorter_get_expression", (DL_FUNC) &R_gtk_numeric_sorter_get_expression, 1},
    {"R_gtk_numeric_sorter_get_sort_order", (DL_FUNC) &R_gtk_numeric_sorter_get_sort_order, 1},
    {"R_gtk_numeric_sorter_set_expression", (DL_FUNC) &R_gtk_numeric_sorter_set_expression, 2},
    {"R_gtk_numeric_sorter_set_sort_order", (DL_FUNC) &R_gtk_numeric_sorter_set_sort_order, 2},
    {"R_gtk_object_expression_new", (DL_FUNC) &R_gtk_object_expression_new, 1},
    {"R_gtk_object_expression_get_object", (DL_FUNC) &R_gtk_object_expression_get_object, 1},
    {"R_gtk_orientable_get_orientation", (DL_FUNC) &R_gtk_orientable_get_orientation, 1},
    {"R_gtk_orientable_set_orientation", (DL_FUNC) &R_gtk_orientable_set_orientation, 2},
    {"R_gtk_overlay_new", (DL_FUNC) &R_gtk_overlay_new, 0},
    {"R_gtk_overlay_add_overlay", (DL_FUNC) &R_gtk_overlay_add_overlay, 2},
    {"R_gtk_overlay_get_child", (DL_FUNC) &R_gtk_overlay_get_child, 1},
    {"R_gtk_overlay_get_clip_overlay", (DL_FUNC) &R_gtk_overlay_get_clip_overlay, 2},
    {"R_gtk_overlay_get_measure_overlay", (DL_FUNC) &R_gtk_overlay_get_measure_overlay, 2},
    {"R_gtk_overlay_remove_overlay", (DL_FUNC) &R_gtk_overlay_remove_overlay, 2},
    {"R_gtk_overlay_set_child", (DL_FUNC) &R_gtk_overlay_set_child, 2},
    {"R_gtk_overlay_set_clip_overlay", (DL_FUNC) &R_gtk_overlay_set_clip_overlay, 3},
    {"R_gtk_overlay_set_measure_overlay", (DL_FUNC) &R_gtk_overlay_set_measure_overlay, 3},
    {"R_gtk_overlay_layout_new", (DL_FUNC) &R_gtk_overlay_layout_new, 0},
    {"R_gtk_overlay_layout_child_get_clip_overlay", (DL_FUNC) &R_gtk_overlay_layout_child_get_clip_overlay, 1},
    {"R_gtk_overlay_layout_child_get_measure", (DL_FUNC) &R_gtk_overlay_layout_child_get_measure, 1},
    {"R_gtk_overlay_layout_child_set_clip_overlay", (DL_FUNC) &R_gtk_overlay_layout_child_set_clip_overlay, 2},
    {"R_gtk_overlay_layout_child_set_measure", (DL_FUNC) &R_gtk_overlay_layout_child_set_measure, 2},
    {"R_gtk_pad_controller_new", (DL_FUNC) &R_gtk_pad_controller_new, 2},
    {"R_gtk_pad_controller_set_action", (DL_FUNC) &R_gtk_pad_controller_set_action, 6},
    {"R_gtk_pad_controller_set_action_entries", (DL_FUNC) &R_gtk_pad_controller_set_action_entries, 3},
    {"R_gtk_paned_new", (DL_FUNC) &R_gtk_paned_new, 1},
    {"R_gtk_paned_get_end_child", (DL_FUNC) &R_gtk_paned_get_end_child, 1},
    {"R_gtk_paned_get_position", (DL_FUNC) &R_gtk_paned_get_position, 1},
    {"R_gtk_paned_get_resize_end_child", (DL_FUNC) &R_gtk_paned_get_resize_end_child, 1},
    {"R_gtk_paned_get_resize_start_child", (DL_FUNC) &R_gtk_paned_get_resize_start_child, 1},
    {"R_gtk_paned_get_shrink_end_child", (DL_FUNC) &R_gtk_paned_get_shrink_end_child, 1},
    {"R_gtk_paned_get_shrink_start_child", (DL_FUNC) &R_gtk_paned_get_shrink_start_child, 1},
    {"R_gtk_paned_get_start_child", (DL_FUNC) &R_gtk_paned_get_start_child, 1},
    {"R_gtk_paned_get_wide_handle", (DL_FUNC) &R_gtk_paned_get_wide_handle, 1},
    {"R_gtk_paned_set_end_child", (DL_FUNC) &R_gtk_paned_set_end_child, 2},
    {"R_gtk_paned_set_position", (DL_FUNC) &R_gtk_paned_set_position, 2},
    {"R_gtk_paned_set_resize_end_child", (DL_FUNC) &R_gtk_paned_set_resize_end_child, 2},
    {"R_gtk_paned_set_resize_start_child", (DL_FUNC) &R_gtk_paned_set_resize_start_child, 2},
    {"R_gtk_paned_set_shrink_end_child", (DL_FUNC) &R_gtk_paned_set_shrink_end_child, 2},
    {"R_gtk_paned_set_shrink_start_child", (DL_FUNC) &R_gtk_paned_set_shrink_start_child, 2},
    {"R_gtk_paned_set_start_child", (DL_FUNC) &R_gtk_paned_set_start_child, 2},
    {"R_gtk_paned_set_wide_handle", (DL_FUNC) &R_gtk_paned_set_wide_handle, 2},
    {"R_gtk_paper_size_new", (DL_FUNC) &R_gtk_paper_size_new, 1},
    {"R_gtk_paper_size_new_custom", (DL_FUNC) &R_gtk_paper_size_new_custom, 5},
    {"R_gtk_paper_size_new_from_gvariant", (DL_FUNC) &R_gtk_paper_size_new_from_gvariant, 1},
    {"R_gtk_paper_size_new_from_ipp", (DL_FUNC) &R_gtk_paper_size_new_from_ipp, 3},
    {"R_gtk_paper_size_new_from_key_file", (DL_FUNC) &R_gtk_paper_size_new_from_key_file, 2},
    {"R_gtk_paper_size_new_from_ppd", (DL_FUNC) &R_gtk_paper_size_new_from_ppd, 4},
    {"R_gtk_paper_size_copy", (DL_FUNC) &R_gtk_paper_size_copy, 1},
    {"R_gtk_paper_size_free", (DL_FUNC) &R_gtk_paper_size_free, 1},
    {"R_gtk_paper_size_get_default_bottom_margin", (DL_FUNC) &R_gtk_paper_size_get_default_bottom_margin, 2},
    {"R_gtk_paper_size_get_default_left_margin", (DL_FUNC) &R_gtk_paper_size_get_default_left_margin, 2},
    {"R_gtk_paper_size_get_default_right_margin", (DL_FUNC) &R_gtk_paper_size_get_default_right_margin, 2},
    {"R_gtk_paper_size_get_default_top_margin", (DL_FUNC) &R_gtk_paper_size_get_default_top_margin, 2},
    {"R_gtk_paper_size_get_display_name", (DL_FUNC) &R_gtk_paper_size_get_display_name, 1},
    {"R_gtk_paper_size_get_height", (DL_FUNC) &R_gtk_paper_size_get_height, 2},
    {"R_gtk_paper_size_get_name", (DL_FUNC) &R_gtk_paper_size_get_name, 1},
    {"R_gtk_paper_size_get_ppd_name", (DL_FUNC) &R_gtk_paper_size_get_ppd_name, 1},
    {"R_gtk_paper_size_get_width", (DL_FUNC) &R_gtk_paper_size_get_width, 2},
    {"R_gtk_paper_size_is_custom", (DL_FUNC) &R_gtk_paper_size_is_custom, 1},
    {"R_gtk_paper_size_is_equal", (DL_FUNC) &R_gtk_paper_size_is_equal, 2},
    {"R_gtk_paper_size_is_ipp", (DL_FUNC) &R_gtk_paper_size_is_ipp, 1},
    {"R_gtk_paper_size_set_size", (DL_FUNC) &R_gtk_paper_size_set_size, 4},
    {"R_gtk_paper_size_to_gvariant", (DL_FUNC) &R_gtk_paper_size_to_gvariant, 1},
    {"R_gtk_paper_size_to_key_file", (DL_FUNC) &R_gtk_paper_size_to_key_file, 3},
    {"R_gtk_paper_size_get_default", (DL_FUNC) &R_gtk_paper_size_get_default, 0},
    {"R_gtk_paper_size_get_paper_sizes", (DL_FUNC) &R_gtk_paper_size_get_paper_sizes, 1},
    {"R_gtk_password_entry_new", (DL_FUNC) &R_gtk_password_entry_new, 0},
    {"R_gtk_password_entry_get_extra_menu", (DL_FUNC) &R_gtk_password_entry_get_extra_menu, 1},
    {"R_gtk_password_entry_get_show_peek_icon", (DL_FUNC) &R_gtk_password_entry_get_show_peek_icon, 1},
    {"R_gtk_password_entry_set_extra_menu", (DL_FUNC) &R_gtk_password_entry_set_extra_menu, 2},
    {"R_gtk_password_entry_set_show_peek_icon", (DL_FUNC) &R_gtk_password_entry_set_show_peek_icon, 2},
    {"R_gtk_password_entry_buffer_new", (DL_FUNC) &R_gtk_password_entry_buffer_new, 0},
    {"R_gtk_picture_new", (DL_FUNC) &R_gtk_picture_new, 0},
    {"R_gtk_picture_new_for_file", (DL_FUNC) &R_gtk_picture_new_for_file, 1},
    {"R_gtk_picture_new_for_filename", (DL_FUNC) &R_gtk_picture_new_for_filename, 1},
    {"R_gtk_picture_new_for_paintable", (DL_FUNC) &R_gtk_picture_new_for_paintable, 1},
    {"R_gtk_picture_new_for_pixbuf", (DL_FUNC) &R_gtk_picture_new_for_pixbuf, 1},
    {"R_gtk_picture_new_for_resource", (DL_FUNC) &R_gtk_picture_new_for_resource, 1},
    {"R_gtk_picture_get_alternative_text", (DL_FUNC) &R_gtk_picture_get_alternative_text, 1},
    {"R_gtk_picture_get_can_shrink", (DL_FUNC) &R_gtk_picture_get_can_shrink, 1},
    {"R_gtk_picture_get_content_fit", (DL_FUNC) &R_gtk_picture_get_content_fit, 1},
    {"R_gtk_picture_get_file", (DL_FUNC) &R_gtk_picture_get_file, 1},
    {"R_gtk_picture_get_keep_aspect_ratio", (DL_FUNC) &R_gtk_picture_get_keep_aspect_ratio, 1},
    {"R_gtk_picture_get_paintable", (DL_FUNC) &R_gtk_picture_get_paintable, 1},
    {"R_gtk_picture_set_alternative_text", (DL_FUNC) &R_gtk_picture_set_alternative_text, 2},
    {"R_gtk_picture_set_can_shrink", (DL_FUNC) &R_gtk_picture_set_can_shrink, 2},
    {"R_gtk_picture_set_content_fit", (DL_FUNC) &R_gtk_picture_set_content_fit, 2},
    {"R_gtk_picture_set_file", (DL_FUNC) &R_gtk_picture_set_file, 2},
    {"R_gtk_picture_set_filename", (DL_FUNC) &R_gtk_picture_set_filename, 2},
    {"R_gtk_picture_set_keep_aspect_ratio", (DL_FUNC) &R_gtk_picture_set_keep_aspect_ratio, 2},
    {"R_gtk_picture_set_paintable", (DL_FUNC) &R_gtk_picture_set_paintable, 2},
    {"R_gtk_picture_set_pixbuf", (DL_FUNC) &R_gtk_picture_set_pixbuf, 2},
    {"R_gtk_picture_set_resource", (DL_FUNC) &R_gtk_picture_set_resource, 2},
    {"R_gtk_popover_new", (DL_FUNC) &R_gtk_popover_new, 0},
    {"R_gtk_popover_get_autohide", (DL_FUNC) &R_gtk_popover_get_autohide, 1},
    {"R_gtk_popover_get_cascade_popdown", (DL_FUNC) &R_gtk_popover_get_cascade_popdown, 1},
    {"R_gtk_popover_get_child", (DL_FUNC) &R_gtk_popover_get_child, 1},
    {"R_gtk_popover_get_has_arrow", (DL_FUNC) &R_gtk_popover_get_has_arrow, 1},
    {"R_gtk_popover_get_mnemonics_visible", (DL_FUNC) &R_gtk_popover_get_mnemonics_visible, 1},
    {"R_gtk_popover_get_offset", (DL_FUNC) &R_gtk_popover_get_offset, 1},
    {"R_gtk_popover_get_pointing_to", (DL_FUNC) &R_gtk_popover_get_pointing_to, 1},
    {"R_gtk_popover_get_position", (DL_FUNC) &R_gtk_popover_get_position, 1},
    {"R_gtk_popover_popdown", (DL_FUNC) &R_gtk_popover_popdown, 1},
    {"R_gtk_popover_popup", (DL_FUNC) &R_gtk_popover_popup, 1},
    {"R_gtk_popover_present", (DL_FUNC) &R_gtk_popover_present, 1},
    {"R_gtk_popover_set_autohide", (DL_FUNC) &R_gtk_popover_set_autohide, 2},
    {"R_gtk_popover_set_cascade_popdown", (DL_FUNC) &R_gtk_popover_set_cascade_popdown, 2},
    {"R_gtk_popover_set_child", (DL_FUNC) &R_gtk_popover_set_child, 2},
    {"R_gtk_popover_set_default_widget", (DL_FUNC) &R_gtk_popover_set_default_widget, 2},
    {"R_gtk_popover_set_has_arrow", (DL_FUNC) &R_gtk_popover_set_has_arrow, 2},
    {"R_gtk_popover_set_mnemonics_visible", (DL_FUNC) &R_gtk_popover_set_mnemonics_visible, 2},
    {"R_gtk_popover_set_offset", (DL_FUNC) &R_gtk_popover_set_offset, 3},
    {"R_gtk_popover_set_pointing_to", (DL_FUNC) &R_gtk_popover_set_pointing_to, 2},
    {"R_gtk_popover_set_position", (DL_FUNC) &R_gtk_popover_set_position, 2},
    {"R_gtk_popover_menu_new_from_model", (DL_FUNC) &R_gtk_popover_menu_new_from_model, 1},
    {"R_gtk_popover_menu_new_from_model_full", (DL_FUNC) &R_gtk_popover_menu_new_from_model_full, 2},
    {"R_gtk_popover_menu_add_child", (DL_FUNC) &R_gtk_popover_menu_add_child, 3},
    {"R_gtk_popover_menu_get_menu_model", (DL_FUNC) &R_gtk_popover_menu_get_menu_model, 1},
    {"R_gtk_popover_menu_remove_child", (DL_FUNC) &R_gtk_popover_menu_remove_child, 2},
    {"R_gtk_popover_menu_set_menu_model", (DL_FUNC) &R_gtk_popover_menu_set_menu_model, 2},
    {"R_gtk_popover_menu_bar_new_from_model", (DL_FUNC) &R_gtk_popover_menu_bar_new_from_model, 1},
    {"R_gtk_popover_menu_bar_add_child", (DL_FUNC) &R_gtk_popover_menu_bar_add_child, 3},
    {"R_gtk_popover_menu_bar_get_menu_model", (DL_FUNC) &R_gtk_popover_menu_bar_get_menu_model, 1},
    {"R_gtk_popover_menu_bar_remove_child", (DL_FUNC) &R_gtk_popover_menu_bar_remove_child, 2},
    {"R_gtk_popover_menu_bar_set_menu_model", (DL_FUNC) &R_gtk_popover_menu_bar_set_menu_model, 2},
    {"R_gtk_progress_bar_new", (DL_FUNC) &R_gtk_progress_bar_new, 0},
    {"R_gtk_progress_bar_get_ellipsize", (DL_FUNC) &R_gtk_progress_bar_get_ellipsize, 1},
    {"R_gtk_progress_bar_get_fraction", (DL_FUNC) &R_gtk_progress_bar_get_fraction, 1},
    {"R_gtk_progress_bar_get_inverted", (DL_FUNC) &R_gtk_progress_bar_get_inverted, 1},
    {"R_gtk_progress_bar_get_pulse_step", (DL_FUNC) &R_gtk_progress_bar_get_pulse_step, 1},
    {"R_gtk_progress_bar_get_show_text", (DL_FUNC) &R_gtk_progress_bar_get_show_text, 1},
    {"R_gtk_progress_bar_get_text", (DL_FUNC) &R_gtk_progress_bar_get_text, 1},
    {"R_gtk_progress_bar_pulse", (DL_FUNC) &R_gtk_progress_bar_pulse, 1},
    {"R_gtk_progress_bar_set_ellipsize", (DL_FUNC) &R_gtk_progress_bar_set_ellipsize, 2},
    {"R_gtk_progress_bar_set_fraction", (DL_FUNC) &R_gtk_progress_bar_set_fraction, 2},
    {"R_gtk_progress_bar_set_inverted", (DL_FUNC) &R_gtk_progress_bar_set_inverted, 2},
    {"R_gtk_progress_bar_set_pulse_step", (DL_FUNC) &R_gtk_progress_bar_set_pulse_step, 2},
    {"R_gtk_progress_bar_set_show_text", (DL_FUNC) &R_gtk_progress_bar_set_show_text, 2},
    {"R_gtk_progress_bar_set_text", (DL_FUNC) &R_gtk_progress_bar_set_text, 2},
    {"R_gtk_property_expression_new", (DL_FUNC) &R_gtk_property_expression_new, 3},
    {"R_gtk_property_expression_new_for_pspec", (DL_FUNC) &R_gtk_property_expression_new_for_pspec, 2},
    {"R_gtk_property_expression_get_expression", (DL_FUNC) &R_gtk_property_expression_get_expression, 1},
    {"R_gtk_property_expression_get_pspec", (DL_FUNC) &R_gtk_property_expression_get_pspec, 1},
    {"R_gtk_range_get_adjustment", (DL_FUNC) &R_gtk_range_get_adjustment, 1},
    {"R_gtk_range_get_fill_level", (DL_FUNC) &R_gtk_range_get_fill_level, 1},
    {"R_gtk_range_get_flippable", (DL_FUNC) &R_gtk_range_get_flippable, 1},
    {"R_gtk_range_get_inverted", (DL_FUNC) &R_gtk_range_get_inverted, 1},
    {"R_gtk_range_get_range_rect", (DL_FUNC) &R_gtk_range_get_range_rect, 1},
    {"R_gtk_range_get_restrict_to_fill_level", (DL_FUNC) &R_gtk_range_get_restrict_to_fill_level, 1},
    {"R_gtk_range_get_round_digits", (DL_FUNC) &R_gtk_range_get_round_digits, 1},
    {"R_gtk_range_get_show_fill_level", (DL_FUNC) &R_gtk_range_get_show_fill_level, 1},
    {"R_gtk_range_get_slider_range", (DL_FUNC) &R_gtk_range_get_slider_range, 1},
    {"R_gtk_range_get_slider_size_fixed", (DL_FUNC) &R_gtk_range_get_slider_size_fixed, 1},
    {"R_gtk_range_get_value", (DL_FUNC) &R_gtk_range_get_value, 1},
    {"R_gtk_range_set_adjustment", (DL_FUNC) &R_gtk_range_set_adjustment, 2},
    {"R_gtk_range_set_fill_level", (DL_FUNC) &R_gtk_range_set_fill_level, 2},
    {"R_gtk_range_set_flippable", (DL_FUNC) &R_gtk_range_set_flippable, 2},
    {"R_gtk_range_set_increments", (DL_FUNC) &R_gtk_range_set_increments, 3},
    {"R_gtk_range_set_inverted", (DL_FUNC) &R_gtk_range_set_inverted, 2},
    {"R_gtk_range_set_range", (DL_FUNC) &R_gtk_range_set_range, 3},
    {"R_gtk_range_set_restrict_to_fill_level", (DL_FUNC) &R_gtk_range_set_restrict_to_fill_level, 2},
    {"R_gtk_range_set_round_digits", (DL_FUNC) &R_gtk_range_set_round_digits, 2},
    {"R_gtk_range_set_show_fill_level", (DL_FUNC) &R_gtk_range_set_show_fill_level, 2},
    {"R_gtk_range_set_slider_size_fixed", (DL_FUNC) &R_gtk_range_set_slider_size_fixed, 2},
    {"R_gtk_range_set_value", (DL_FUNC) &R_gtk_range_set_value, 2},
    {"R_gtk_recent_info_create_app_info", (DL_FUNC) &R_gtk_recent_info_create_app_info, 2},
    {"R_gtk_recent_info_exists", (DL_FUNC) &R_gtk_recent_info_exists, 1},
    {"R_gtk_recent_info_get_added", (DL_FUNC) &R_gtk_recent_info_get_added, 1},
    {"R_gtk_recent_info_get_age", (DL_FUNC) &R_gtk_recent_info_get_age, 1},
    {"R_gtk_recent_info_get_application_info", (DL_FUNC) &R_gtk_recent_info_get_application_info, 2},
    {"R_gtk_recent_info_get_applications", (DL_FUNC) &R_gtk_recent_info_get_applications, 1},
    {"R_gtk_recent_info_get_description", (DL_FUNC) &R_gtk_recent_info_get_description, 1},
    {"R_gtk_recent_info_get_display_name", (DL_FUNC) &R_gtk_recent_info_get_display_name, 1},
    {"R_gtk_recent_info_get_gicon", (DL_FUNC) &R_gtk_recent_info_get_gicon, 1},
    {"R_gtk_recent_info_get_groups", (DL_FUNC) &R_gtk_recent_info_get_groups, 1},
    {"R_gtk_recent_info_get_mime_type", (DL_FUNC) &R_gtk_recent_info_get_mime_type, 1},
    {"R_gtk_recent_info_get_modified", (DL_FUNC) &R_gtk_recent_info_get_modified, 1},
    {"R_gtk_recent_info_get_private_hint", (DL_FUNC) &R_gtk_recent_info_get_private_hint, 1},
    {"R_gtk_recent_info_get_short_name", (DL_FUNC) &R_gtk_recent_info_get_short_name, 1},
    {"R_gtk_recent_info_get_uri", (DL_FUNC) &R_gtk_recent_info_get_uri, 1},
    {"R_gtk_recent_info_get_uri_display", (DL_FUNC) &R_gtk_recent_info_get_uri_display, 1},
    {"R_gtk_recent_info_get_visited", (DL_FUNC) &R_gtk_recent_info_get_visited, 1},
    {"R_gtk_recent_info_has_application", (DL_FUNC) &R_gtk_recent_info_has_application, 2},
    {"R_gtk_recent_info_has_group", (DL_FUNC) &R_gtk_recent_info_has_group, 2},
    {"R_gtk_recent_info_is_local", (DL_FUNC) &R_gtk_recent_info_is_local, 1},
    {"R_gtk_recent_info_last_application", (DL_FUNC) &R_gtk_recent_info_last_application, 1},
    {"R_gtk_recent_info_match", (DL_FUNC) &R_gtk_recent_info_match, 2},
    {"R_gtk_recent_info_ref", (DL_FUNC) &R_gtk_recent_info_ref, 1},
    {"R_gtk_recent_info_unref", (DL_FUNC) &R_gtk_recent_info_unref, 1},
    {"R_gtk_recent_manager_new", (DL_FUNC) &R_gtk_recent_manager_new, 0},
    {"R_gtk_recent_manager_get_default", (DL_FUNC) &R_gtk_recent_manager_get_default, 0},
    {"R_gtk_recent_manager_add_full", (DL_FUNC) &R_gtk_recent_manager_add_full, 3},
    {"R_gtk_recent_manager_add_item", (DL_FUNC) &R_gtk_recent_manager_add_item, 2},
    {"R_gtk_recent_manager_get_items", (DL_FUNC) &R_gtk_recent_manager_get_items, 1},
    {"R_gtk_recent_manager_has_item", (DL_FUNC) &R_gtk_recent_manager_has_item, 2},
    {"R_gtk_recent_manager_lookup_item", (DL_FUNC) &R_gtk_recent_manager_lookup_item, 2},
    {"R_gtk_recent_manager_move_item", (DL_FUNC) &R_gtk_recent_manager_move_item, 3},
    {"R_gtk_recent_manager_purge_items", (DL_FUNC) &R_gtk_recent_manager_purge_items, 1},
    {"R_gtk_recent_manager_remove_item", (DL_FUNC) &R_gtk_recent_manager_remove_item, 2},
    {"R_gtk_recent_manager_error_quark", (DL_FUNC) &R_gtk_recent_manager_error_quark, 0},
    {"R_gtk_requisition_new", (DL_FUNC) &R_gtk_requisition_new, 0},
    {"R_gtk_requisition_copy", (DL_FUNC) &R_gtk_requisition_copy, 1},
    {"R_gtk_requisition_free", (DL_FUNC) &R_gtk_requisition_free, 1},
    {"R_gtk_revealer_new", (DL_FUNC) &R_gtk_revealer_new, 0},
    {"R_gtk_revealer_get_child", (DL_FUNC) &R_gtk_revealer_get_child, 1},
    {"R_gtk_revealer_get_child_revealed", (DL_FUNC) &R_gtk_revealer_get_child_revealed, 1},
    {"R_gtk_revealer_get_reveal_child", (DL_FUNC) &R_gtk_revealer_get_reveal_child, 1},
    {"R_gtk_revealer_get_transition_duration", (DL_FUNC) &R_gtk_revealer_get_transition_duration, 1},
    {"R_gtk_revealer_get_transition_type", (DL_FUNC) &R_gtk_revealer_get_transition_type, 1},
    {"R_gtk_revealer_set_child", (DL_FUNC) &R_gtk_revealer_set_child, 2},
    {"R_gtk_revealer_set_reveal_child", (DL_FUNC) &R_gtk_revealer_set_reveal_child, 2},
    {"R_gtk_revealer_set_transition_duration", (DL_FUNC) &R_gtk_revealer_set_transition_duration, 2},
    {"R_gtk_revealer_set_transition_type", (DL_FUNC) &R_gtk_revealer_set_transition_type, 2},
    {"R_gtk_root_get_display", (DL_FUNC) &R_gtk_root_get_display, 1},
    {"R_gtk_root_get_focus", (DL_FUNC) &R_gtk_root_get_focus, 1},
    {"R_gtk_root_set_focus", (DL_FUNC) &R_gtk_root_set_focus, 2},
    {"R_gtk_scale_new", (DL_FUNC) &R_gtk_scale_new, 2},
    {"R_gtk_scale_new_with_range", (DL_FUNC) &R_gtk_scale_new_with_range, 4},
    {"R_gtk_scale_add_mark", (DL_FUNC) &R_gtk_scale_add_mark, 4},
    {"R_gtk_scale_clear_marks", (DL_FUNC) &R_gtk_scale_clear_marks, 1},
    {"R_gtk_scale_get_digits", (DL_FUNC) &R_gtk_scale_get_digits, 1},
    {"R_gtk_scale_get_draw_value", (DL_FUNC) &R_gtk_scale_get_draw_value, 1},
    {"R_gtk_scale_get_has_origin", (DL_FUNC) &R_gtk_scale_get_has_origin, 1},
    {"R_gtk_scale_get_layout", (DL_FUNC) &R_gtk_scale_get_layout, 1},
    {"R_gtk_scale_get_layout_offsets", (DL_FUNC) &R_gtk_scale_get_layout_offsets, 1},
    {"R_gtk_scale_get_value_pos", (DL_FUNC) &R_gtk_scale_get_value_pos, 1},
    {"R_gtk_scale_set_digits", (DL_FUNC) &R_gtk_scale_set_digits, 2},
    {"R_gtk_scale_set_draw_value", (DL_FUNC) &R_gtk_scale_set_draw_value, 2},
    {"R_gtk_scale_set_format_value_func", (DL_FUNC) &R_gtk_scale_set_format_value_func, 4},
    {"R_gtk_scale_set_has_origin", (DL_FUNC) &R_gtk_scale_set_has_origin, 2},
    {"R_gtk_scale_set_value_pos", (DL_FUNC) &R_gtk_scale_set_value_pos, 2},
    {"R_gtk_scale_button_new", (DL_FUNC) &R_gtk_scale_button_new, 4},
    {"R_gtk_scale_button_get_active", (DL_FUNC) &R_gtk_scale_button_get_active, 1},
    {"R_gtk_scale_button_get_adjustment", (DL_FUNC) &R_gtk_scale_button_get_adjustment, 1},
    {"R_gtk_scale_button_get_minus_button", (DL_FUNC) &R_gtk_scale_button_get_minus_button, 1},
    {"R_gtk_scale_button_get_plus_button", (DL_FUNC) &R_gtk_scale_button_get_plus_button, 1},
    {"R_gtk_scale_button_get_popup", (DL_FUNC) &R_gtk_scale_button_get_popup, 1},
    {"R_gtk_scale_button_get_value", (DL_FUNC) &R_gtk_scale_button_get_value, 1},
    {"R_gtk_scale_button_set_adjustment", (DL_FUNC) &R_gtk_scale_button_set_adjustment, 2},
    {"R_gtk_scale_button_set_icons", (DL_FUNC) &R_gtk_scale_button_set_icons, 2},
    {"R_gtk_scale_button_set_value", (DL_FUNC) &R_gtk_scale_button_set_value, 2},
    {"R_gtk_scroll_info_new", (DL_FUNC) &R_gtk_scroll_info_new, 0},
    {"R_gtk_scroll_info_get_enable_horizontal", (DL_FUNC) &R_gtk_scroll_info_get_enable_horizontal, 1},
    {"R_gtk_scroll_info_get_enable_vertical", (DL_FUNC) &R_gtk_scroll_info_get_enable_vertical, 1},
    {"R_gtk_scroll_info_ref", (DL_FUNC) &R_gtk_scroll_info_ref, 1},
    {"R_gtk_scroll_info_set_enable_horizontal", (DL_FUNC) &R_gtk_scroll_info_set_enable_horizontal, 2},
    {"R_gtk_scroll_info_set_enable_vertical", (DL_FUNC) &R_gtk_scroll_info_set_enable_vertical, 2},
    {"R_gtk_scroll_info_unref", (DL_FUNC) &R_gtk_scroll_info_unref, 1},
    {"R_gtk_scrollable_get_border", (DL_FUNC) &R_gtk_scrollable_get_border, 1},
    {"R_gtk_scrollable_get_hadjustment", (DL_FUNC) &R_gtk_scrollable_get_hadjustment, 1},
    {"R_gtk_scrollable_get_hscroll_policy", (DL_FUNC) &R_gtk_scrollable_get_hscroll_policy, 1},
    {"R_gtk_scrollable_get_vadjustment", (DL_FUNC) &R_gtk_scrollable_get_vadjustment, 1},
    {"R_gtk_scrollable_get_vscroll_policy", (DL_FUNC) &R_gtk_scrollable_get_vscroll_policy, 1},
    {"R_gtk_scrollable_set_hadjustment", (DL_FUNC) &R_gtk_scrollable_set_hadjustment, 2},
    {"R_gtk_scrollable_set_hscroll_policy", (DL_FUNC) &R_gtk_scrollable_set_hscroll_policy, 2},
    {"R_gtk_scrollable_set_vadjustment", (DL_FUNC) &R_gtk_scrollable_set_vadjustment, 2},
    {"R_gtk_scrollable_set_vscroll_policy", (DL_FUNC) &R_gtk_scrollable_set_vscroll_policy, 2},
    {"R_gtk_scrollbar_new", (DL_FUNC) &R_gtk_scrollbar_new, 2},
    {"R_gtk_scrollbar_get_adjustment", (DL_FUNC) &R_gtk_scrollbar_get_adjustment, 1},
    {"R_gtk_scrollbar_set_adjustment", (DL_FUNC) &R_gtk_scrollbar_set_adjustment, 2},
    {"R_gtk_scrolled_window_new", (DL_FUNC) &R_gtk_scrolled_window_new, 0},
    {"R_gtk_scrolled_window_get_child", (DL_FUNC) &R_gtk_scrolled_window_get_child, 1},
    {"R_gtk_scrolled_window_get_hadjustment", (DL_FUNC) &R_gtk_scrolled_window_get_hadjustment, 1},
    {"R_gtk_scrolled_window_get_has_frame", (DL_FUNC) &R_gtk_scrolled_window_get_has_frame, 1},
    {"R_gtk_scrolled_window_get_hscrollbar", (DL_FUNC) &R_gtk_scrolled_window_get_hscrollbar, 1},
    {"R_gtk_scrolled_window_get_kinetic_scrolling", (DL_FUNC) &R_gtk_scrolled_window_get_kinetic_scrolling, 1},
    {"R_gtk_scrolled_window_get_max_content_height", (DL_FUNC) &R_gtk_scrolled_window_get_max_content_height, 1},
    {"R_gtk_scrolled_window_get_max_content_width", (DL_FUNC) &R_gtk_scrolled_window_get_max_content_width, 1},
    {"R_gtk_scrolled_window_get_min_content_height", (DL_FUNC) &R_gtk_scrolled_window_get_min_content_height, 1},
    {"R_gtk_scrolled_window_get_min_content_width", (DL_FUNC) &R_gtk_scrolled_window_get_min_content_width, 1},
    {"R_gtk_scrolled_window_get_overlay_scrolling", (DL_FUNC) &R_gtk_scrolled_window_get_overlay_scrolling, 1},
    {"R_gtk_scrolled_window_get_placement", (DL_FUNC) &R_gtk_scrolled_window_get_placement, 1},
    {"R_gtk_scrolled_window_get_policy", (DL_FUNC) &R_gtk_scrolled_window_get_policy, 1},
    {"R_gtk_scrolled_window_get_propagate_natural_height", (DL_FUNC) &R_gtk_scrolled_window_get_propagate_natural_height, 1},
    {"R_gtk_scrolled_window_get_propagate_natural_width", (DL_FUNC) &R_gtk_scrolled_window_get_propagate_natural_width, 1},
    {"R_gtk_scrolled_window_get_vadjustment", (DL_FUNC) &R_gtk_scrolled_window_get_vadjustment, 1},
    {"R_gtk_scrolled_window_get_vscrollbar", (DL_FUNC) &R_gtk_scrolled_window_get_vscrollbar, 1},
    {"R_gtk_scrolled_window_set_child", (DL_FUNC) &R_gtk_scrolled_window_set_child, 2},
    {"R_gtk_scrolled_window_set_hadjustment", (DL_FUNC) &R_gtk_scrolled_window_set_hadjustment, 2},
    {"R_gtk_scrolled_window_set_has_frame", (DL_FUNC) &R_gtk_scrolled_window_set_has_frame, 2},
    {"R_gtk_scrolled_window_set_kinetic_scrolling", (DL_FUNC) &R_gtk_scrolled_window_set_kinetic_scrolling, 2},
    {"R_gtk_scrolled_window_set_max_content_height", (DL_FUNC) &R_gtk_scrolled_window_set_max_content_height, 2},
    {"R_gtk_scrolled_window_set_max_content_width", (DL_FUNC) &R_gtk_scrolled_window_set_max_content_width, 2},
    {"R_gtk_scrolled_window_set_min_content_height", (DL_FUNC) &R_gtk_scrolled_window_set_min_content_height, 2},
    {"R_gtk_scrolled_window_set_min_content_width", (DL_FUNC) &R_gtk_scrolled_window_set_min_content_width, 2},
    {"R_gtk_scrolled_window_set_overlay_scrolling", (DL_FUNC) &R_gtk_scrolled_window_set_overlay_scrolling, 2},
    {"R_gtk_scrolled_window_set_placement", (DL_FUNC) &R_gtk_scrolled_window_set_placement, 2},
    {"R_gtk_scrolled_window_set_policy", (DL_FUNC) &R_gtk_scrolled_window_set_policy, 3},
    {"R_gtk_scrolled_window_set_propagate_natural_height", (DL_FUNC) &R_gtk_scrolled_window_set_propagate_natural_height, 2},
    {"R_gtk_scrolled_window_set_propagate_natural_width", (DL_FUNC) &R_gtk_scrolled_window_set_propagate_natural_width, 2},
    {"R_gtk_scrolled_window_set_vadjustment", (DL_FUNC) &R_gtk_scrolled_window_set_vadjustment, 2},
    {"R_gtk_scrolled_window_unset_placement", (DL_FUNC) &R_gtk_scrolled_window_unset_placement, 1},
    {"R_gtk_search_bar_new", (DL_FUNC) &R_gtk_search_bar_new, 0},
    {"R_gtk_search_bar_connect_entry", (DL_FUNC) &R_gtk_search_bar_connect_entry, 2},
    {"R_gtk_search_bar_get_child", (DL_FUNC) &R_gtk_search_bar_get_child, 1},
    {"R_gtk_search_bar_get_key_capture_widget", (DL_FUNC) &R_gtk_search_bar_get_key_capture_widget, 1},
    {"R_gtk_search_bar_get_search_mode", (DL_FUNC) &R_gtk_search_bar_get_search_mode, 1},
    {"R_gtk_search_bar_get_show_close_button", (DL_FUNC) &R_gtk_search_bar_get_show_close_button, 1},
    {"R_gtk_search_bar_set_child", (DL_FUNC) &R_gtk_search_bar_set_child, 2},
    {"R_gtk_search_bar_set_key_capture_widget", (DL_FUNC) &R_gtk_search_bar_set_key_capture_widget, 2},
    {"R_gtk_search_bar_set_search_mode", (DL_FUNC) &R_gtk_search_bar_set_search_mode, 2},
    {"R_gtk_search_bar_set_show_close_button", (DL_FUNC) &R_gtk_search_bar_set_show_close_button, 2},
    {"R_gtk_search_entry_new", (DL_FUNC) &R_gtk_search_entry_new, 0},
    {"R_gtk_search_entry_get_key_capture_widget", (DL_FUNC) &R_gtk_search_entry_get_key_capture_widget, 1},
    {"R_gtk_search_entry_get_placeholder_text", (DL_FUNC) &R_gtk_search_entry_get_placeholder_text, 1},
    {"R_gtk_search_entry_get_search_delay", (DL_FUNC) &R_gtk_search_entry_get_search_delay, 1},
    {"R_gtk_search_entry_set_key_capture_widget", (DL_FUNC) &R_gtk_search_entry_set_key_capture_widget, 2},
    {"R_gtk_search_entry_set_placeholder_text", (DL_FUNC) &R_gtk_search_entry_set_placeholder_text, 2},
    {"R_gtk_search_entry_set_search_delay", (DL_FUNC) &R_gtk_search_entry_set_search_delay, 2},
    {"R_gtk_section_model_get_section", (DL_FUNC) &R_gtk_section_model_get_section, 2},
    {"R_gtk_section_model_sections_changed", (DL_FUNC) &R_gtk_section_model_sections_changed, 3},
    {"R_gtk_selection_filter_model_new", (DL_FUNC) &R_gtk_selection_filter_model_new, 1},
    {"R_gtk_selection_filter_model_get_model", (DL_FUNC) &R_gtk_selection_filter_model_get_model, 1},
    {"R_gtk_selection_filter_model_set_model", (DL_FUNC) &R_gtk_selection_filter_model_set_model, 2},
    {"R_gtk_selection_model_get_selection", (DL_FUNC) &R_gtk_selection_model_get_selection, 1},
    {"R_gtk_selection_model_get_selection_in_range", (DL_FUNC) &R_gtk_selection_model_get_selection_in_range, 3},
    {"R_gtk_selection_model_is_selected", (DL_FUNC) &R_gtk_selection_model_is_selected, 2},
    {"R_gtk_selection_model_select_all", (DL_FUNC) &R_gtk_selection_model_select_all, 1},
    {"R_gtk_selection_model_select_item", (DL_FUNC) &R_gtk_selection_model_select_item, 3},
    {"R_gtk_selection_model_select_range", (DL_FUNC) &R_gtk_selection_model_select_range, 4},
    {"R_gtk_selection_model_selection_changed", (DL_FUNC) &R_gtk_selection_model_selection_changed, 3},
    {"R_gtk_selection_model_set_selection", (DL_FUNC) &R_gtk_selection_model_set_selection, 3},
    {"R_gtk_selection_model_unselect_all", (DL_FUNC) &R_gtk_selection_model_unselect_all, 1},
    {"R_gtk_selection_model_unselect_item", (DL_FUNC) &R_gtk_selection_model_unselect_item, 2},
    {"R_gtk_selection_model_unselect_range", (DL_FUNC) &R_gtk_selection_model_unselect_range, 3},
    {"R_gtk_separator_new", (DL_FUNC) &R_gtk_separator_new, 1},
    {"R_gtk_settings_get_default", (DL_FUNC) &R_gtk_settings_get_default, 0},
    {"R_gtk_settings_get_for_display", (DL_FUNC) &R_gtk_settings_get_for_display, 1},
    {"R_gtk_settings_reset_property", (DL_FUNC) &R_gtk_settings_reset_property, 2},
    {"R_gtk_shortcut_new", (DL_FUNC) &R_gtk_shortcut_new, 2},
    {"R_gtk_shortcut_get_action", (DL_FUNC) &R_gtk_shortcut_get_action, 1},
    {"R_gtk_shortcut_get_arguments", (DL_FUNC) &R_gtk_shortcut_get_arguments, 1},
    {"R_gtk_shortcut_get_trigger", (DL_FUNC) &R_gtk_shortcut_get_trigger, 1},
    {"R_gtk_shortcut_set_action", (DL_FUNC) &R_gtk_shortcut_set_action, 2},
    {"R_gtk_shortcut_set_arguments", (DL_FUNC) &R_gtk_shortcut_set_arguments, 2},
    {"R_gtk_shortcut_set_trigger", (DL_FUNC) &R_gtk_shortcut_set_trigger, 2},
    {"R_gtk_shortcut_action_parse_string", (DL_FUNC) &R_gtk_shortcut_action_parse_string, 1},
    {"R_gtk_shortcut_action_activate", (DL_FUNC) &R_gtk_shortcut_action_activate, 4},
    {"R_gtk_shortcut_action_print", (DL_FUNC) &R_gtk_shortcut_action_print, 2},
    {"R_gtk_shortcut_action_to_string", (DL_FUNC) &R_gtk_shortcut_action_to_string, 1},
    {"R_gtk_shortcut_controller_new", (DL_FUNC) &R_gtk_shortcut_controller_new, 0},
    {"R_gtk_shortcut_controller_new_for_model", (DL_FUNC) &R_gtk_shortcut_controller_new_for_model, 1},
    {"R_gtk_shortcut_controller_add_shortcut", (DL_FUNC) &R_gtk_shortcut_controller_add_shortcut, 2},
    {"R_gtk_shortcut_controller_get_mnemonics_modifiers", (DL_FUNC) &R_gtk_shortcut_controller_get_mnemonics_modifiers, 1},
    {"R_gtk_shortcut_controller_get_scope", (DL_FUNC) &R_gtk_shortcut_controller_get_scope, 1},
    {"R_gtk_shortcut_controller_remove_shortcut", (DL_FUNC) &R_gtk_shortcut_controller_remove_shortcut, 2},
    {"R_gtk_shortcut_controller_set_mnemonics_modifiers", (DL_FUNC) &R_gtk_shortcut_controller_set_mnemonics_modifiers, 2},
    {"R_gtk_shortcut_controller_set_scope", (DL_FUNC) &R_gtk_shortcut_controller_set_scope, 2},
    {"R_gtk_shortcut_label_new", (DL_FUNC) &R_gtk_shortcut_label_new, 1},
    {"R_gtk_shortcut_label_get_accelerator", (DL_FUNC) &R_gtk_shortcut_label_get_accelerator, 1},
    {"R_gtk_shortcut_label_get_disabled_text", (DL_FUNC) &R_gtk_shortcut_label_get_disabled_text, 1},
    {"R_gtk_shortcut_label_set_accelerator", (DL_FUNC) &R_gtk_shortcut_label_set_accelerator, 2},
    {"R_gtk_shortcut_label_set_disabled_text", (DL_FUNC) &R_gtk_shortcut_label_set_disabled_text, 2},
    {"R_gtk_shortcut_trigger_parse_string", (DL_FUNC) &R_gtk_shortcut_trigger_parse_string, 1},
    {"R_gtk_shortcut_trigger_compare", (DL_FUNC) &R_gtk_shortcut_trigger_compare, 2},
    {"R_gtk_shortcut_trigger_equal", (DL_FUNC) &R_gtk_shortcut_trigger_equal, 2},
    {"R_gtk_shortcut_trigger_hash", (DL_FUNC) &R_gtk_shortcut_trigger_hash, 1},
    {"R_gtk_shortcut_trigger_print", (DL_FUNC) &R_gtk_shortcut_trigger_print, 2},
    {"R_gtk_shortcut_trigger_print_label", (DL_FUNC) &R_gtk_shortcut_trigger_print_label, 3},
    {"R_gtk_shortcut_trigger_to_label", (DL_FUNC) &R_gtk_shortcut_trigger_to_label, 2},
    {"R_gtk_shortcut_trigger_to_string", (DL_FUNC) &R_gtk_shortcut_trigger_to_string, 1},
    {"R_gtk_shortcut_trigger_trigger", (DL_FUNC) &R_gtk_shortcut_trigger_trigger, 3},
    {"R_gtk_signal_action_new", (DL_FUNC) &R_gtk_signal_action_new, 1},
    {"R_gtk_signal_action_get_signal_name", (DL_FUNC) &R_gtk_signal_action_get_signal_name, 1},
    {"R_gtk_signal_list_item_factory_new", (DL_FUNC) &R_gtk_signal_list_item_factory_new, 0},
    {"R_gtk_single_selection_new", (DL_FUNC) &R_gtk_single_selection_new, 1},
    {"R_gtk_single_selection_get_autoselect", (DL_FUNC) &R_gtk_single_selection_get_autoselect, 1},
    {"R_gtk_single_selection_get_can_unselect", (DL_FUNC) &R_gtk_single_selection_get_can_unselect, 1},
    {"R_gtk_single_selection_get_model", (DL_FUNC) &R_gtk_single_selection_get_model, 1},
    {"R_gtk_single_selection_get_selected", (DL_FUNC) &R_gtk_single_selection_get_selected, 1},
    {"R_gtk_single_selection_get_selected_item", (DL_FUNC) &R_gtk_single_selection_get_selected_item, 1},
    {"R_gtk_single_selection_set_autoselect", (DL_FUNC) &R_gtk_single_selection_set_autoselect, 2},
    {"R_gtk_single_selection_set_can_unselect", (DL_FUNC) &R_gtk_single_selection_set_can_unselect, 2},
    {"R_gtk_single_selection_set_model", (DL_FUNC) &R_gtk_single_selection_set_model, 2},
    {"R_gtk_single_selection_set_selected", (DL_FUNC) &R_gtk_single_selection_set_selected, 2},
    {"R_gtk_size_group_new", (DL_FUNC) &R_gtk_size_group_new, 1},
    {"R_gtk_size_group_add_widget", (DL_FUNC) &R_gtk_size_group_add_widget, 2},
    {"R_gtk_size_group_get_mode", (DL_FUNC) &R_gtk_size_group_get_mode, 1},
    {"R_gtk_size_group_get_widgets", (DL_FUNC) &R_gtk_size_group_get_widgets, 1},
    {"R_gtk_size_group_remove_widget", (DL_FUNC) &R_gtk_size_group_remove_widget, 2},
    {"R_gtk_size_group_set_mode", (DL_FUNC) &R_gtk_size_group_set_mode, 2},
    {"R_gtk_slice_list_model_new", (DL_FUNC) &R_gtk_slice_list_model_new, 3},
    {"R_gtk_slice_list_model_get_model", (DL_FUNC) &R_gtk_slice_list_model_get_model, 1},
    {"R_gtk_slice_list_model_get_offset", (DL_FUNC) &R_gtk_slice_list_model_get_offset, 1},
    {"R_gtk_slice_list_model_get_size", (DL_FUNC) &R_gtk_slice_list_model_get_size, 1},
    {"R_gtk_slice_list_model_set_model", (DL_FUNC) &R_gtk_slice_list_model_set_model, 2},
    {"R_gtk_slice_list_model_set_offset", (DL_FUNC) &R_gtk_slice_list_model_set_offset, 2},
    {"R_gtk_slice_list_model_set_size", (DL_FUNC) &R_gtk_slice_list_model_set_size, 2},
    {"R_gtk_snapshot_new", (DL_FUNC) &R_gtk_snapshot_new, 0},
    {"R_gtk_snapshot_append_border", (DL_FUNC) &R_gtk_snapshot_append_border, 4},
    {"R_gtk_snapshot_append_cairo", (DL_FUNC) &R_gtk_snapshot_append_cairo, 2},
    {"R_gtk_snapshot_append_color", (DL_FUNC) &R_gtk_snapshot_append_color, 3},
    {"R_gtk_snapshot_append_conic_gradient", (DL_FUNC) &R_gtk_snapshot_append_conic_gradient, 6},
    {"R_gtk_snapshot_append_inset_shadow", (DL_FUNC) &R_gtk_snapshot_append_inset_shadow, 7},
    {"R_gtk_snapshot_append_layout", (DL_FUNC) &R_gtk_snapshot_append_layout, 3},
    {"R_gtk_snapshot_append_linear_gradient", (DL_FUNC) &R_gtk_snapshot_append_linear_gradient, 6},
    {"R_gtk_snapshot_append_node", (DL_FUNC) &R_gtk_snapshot_append_node, 2},
    {"R_gtk_snapshot_append_outset_shadow", (DL_FUNC) &R_gtk_snapshot_append_outset_shadow, 7},
    {"R_gtk_snapshot_append_radial_gradient", (DL_FUNC) &R_gtk_snapshot_append_radial_gradient, 9},
    {"R_gtk_snapshot_append_repeating_linear_gradient", (DL_FUNC) &R_gtk_snapshot_append_repeating_linear_gradient, 6},
    {"R_gtk_snapshot_append_repeating_radial_gradient", (DL_FUNC) &R_gtk_snapshot_append_repeating_radial_gradient, 9},
    {"R_gtk_snapshot_append_scaled_texture", (DL_FUNC) &R_gtk_snapshot_append_scaled_texture, 4},
    {"R_gtk_snapshot_append_texture", (DL_FUNC) &R_gtk_snapshot_append_texture, 3},
    {"R_gtk_snapshot_gl_shader_pop_texture", (DL_FUNC) &R_gtk_snapshot_gl_shader_pop_texture, 1},
    {"R_gtk_snapshot_perspective", (DL_FUNC) &R_gtk_snapshot_perspective, 2},
    {"R_gtk_snapshot_pop", (DL_FUNC) &R_gtk_snapshot_pop, 1},
    {"R_gtk_snapshot_push_blend", (DL_FUNC) &R_gtk_snapshot_push_blend, 2},
    {"R_gtk_snapshot_push_blur", (DL_FUNC) &R_gtk_snapshot_push_blur, 2},
    {"R_gtk_snapshot_push_clip", (DL_FUNC) &R_gtk_snapshot_push_clip, 2},
    {"R_gtk_snapshot_push_color_matrix", (DL_FUNC) &R_gtk_snapshot_push_color_matrix, 3},
    {"R_gtk_snapshot_push_cross_fade", (DL_FUNC) &R_gtk_snapshot_push_cross_fade, 2},
    {"R_gtk_snapshot_push_gl_shader", (DL_FUNC) &R_gtk_snapshot_push_gl_shader, 4},
    {"R_gtk_snapshot_push_mask", (DL_FUNC) &R_gtk_snapshot_push_mask, 2},
    {"R_gtk_snapshot_push_opacity", (DL_FUNC) &R_gtk_snapshot_push_opacity, 2},
    {"R_gtk_snapshot_push_repeat", (DL_FUNC) &R_gtk_snapshot_push_repeat, 3},
    {"R_gtk_snapshot_push_rounded_clip", (DL_FUNC) &R_gtk_snapshot_push_rounded_clip, 2},
    {"R_gtk_snapshot_push_shadow", (DL_FUNC) &R_gtk_snapshot_push_shadow, 3},
    {"R_gtk_snapshot_render_background", (DL_FUNC) &R_gtk_snapshot_render_background, 6},
    {"R_gtk_snapshot_render_focus", (DL_FUNC) &R_gtk_snapshot_render_focus, 6},
    {"R_gtk_snapshot_render_frame", (DL_FUNC) &R_gtk_snapshot_render_frame, 6},
    {"R_gtk_snapshot_render_insertion_cursor", (DL_FUNC) &R_gtk_snapshot_render_insertion_cursor, 7},
    {"R_gtk_snapshot_render_layout", (DL_FUNC) &R_gtk_snapshot_render_layout, 5},
    {"R_gtk_snapshot_restore", (DL_FUNC) &R_gtk_snapshot_restore, 1},
    {"R_gtk_snapshot_rotate", (DL_FUNC) &R_gtk_snapshot_rotate, 2},
    {"R_gtk_snapshot_rotate_3d", (DL_FUNC) &R_gtk_snapshot_rotate_3d, 3},
    {"R_gtk_snapshot_save", (DL_FUNC) &R_gtk_snapshot_save, 1},
    {"R_gtk_snapshot_scale", (DL_FUNC) &R_gtk_snapshot_scale, 3},
    {"R_gtk_snapshot_scale_3d", (DL_FUNC) &R_gtk_snapshot_scale_3d, 4},
    {"R_gtk_snapshot_to_node", (DL_FUNC) &R_gtk_snapshot_to_node, 1},
    {"R_gtk_snapshot_to_paintable", (DL_FUNC) &R_gtk_snapshot_to_paintable, 2},
    {"R_gtk_snapshot_transform", (DL_FUNC) &R_gtk_snapshot_transform, 2},
    {"R_gtk_snapshot_transform_matrix", (DL_FUNC) &R_gtk_snapshot_transform_matrix, 2},
    {"R_gtk_snapshot_translate", (DL_FUNC) &R_gtk_snapshot_translate, 2},
    {"R_gtk_snapshot_translate_3d", (DL_FUNC) &R_gtk_snapshot_translate_3d, 2},
    {"R_gtk_sort_list_model_new", (DL_FUNC) &R_gtk_sort_list_model_new, 2},
    {"R_gtk_sort_list_model_get_incremental", (DL_FUNC) &R_gtk_sort_list_model_get_incremental, 1},
    {"R_gtk_sort_list_model_get_model", (DL_FUNC) &R_gtk_sort_list_model_get_model, 1},
    {"R_gtk_sort_list_model_get_pending", (DL_FUNC) &R_gtk_sort_list_model_get_pending, 1},
    {"R_gtk_sort_list_model_get_section_sorter", (DL_FUNC) &R_gtk_sort_list_model_get_section_sorter, 1},
    {"R_gtk_sort_list_model_get_sorter", (DL_FUNC) &R_gtk_sort_list_model_get_sorter, 1},
    {"R_gtk_sort_list_model_set_incremental", (DL_FUNC) &R_gtk_sort_list_model_set_incremental, 2},
    {"R_gtk_sort_list_model_set_model", (DL_FUNC) &R_gtk_sort_list_model_set_model, 2},
    {"R_gtk_sort_list_model_set_section_sorter", (DL_FUNC) &R_gtk_sort_list_model_set_section_sorter, 2},
    {"R_gtk_sort_list_model_set_sorter", (DL_FUNC) &R_gtk_sort_list_model_set_sorter, 2},
    {"R_gtk_sorter_changed", (DL_FUNC) &R_gtk_sorter_changed, 2},
    {"R_gtk_sorter_compare", (DL_FUNC) &R_gtk_sorter_compare, 3},
    {"R_gtk_sorter_get_order", (DL_FUNC) &R_gtk_sorter_get_order, 1},
    {"R_gtk_spin_button_new", (DL_FUNC) &R_gtk_spin_button_new, 3},
    {"R_gtk_spin_button_new_with_range", (DL_FUNC) &R_gtk_spin_button_new_with_range, 3},
    {"R_gtk_spin_button_configure", (DL_FUNC) &R_gtk_spin_button_configure, 4},
    {"R_gtk_spin_button_get_adjustment", (DL_FUNC) &R_gtk_spin_button_get_adjustment, 1},
    {"R_gtk_spin_button_get_climb_rate", (DL_FUNC) &R_gtk_spin_button_get_climb_rate, 1},
    {"R_gtk_spin_button_get_digits", (DL_FUNC) &R_gtk_spin_button_get_digits, 1},
    {"R_gtk_spin_button_get_increments", (DL_FUNC) &R_gtk_spin_button_get_increments, 1},
    {"R_gtk_spin_button_get_numeric", (DL_FUNC) &R_gtk_spin_button_get_numeric, 1},
    {"R_gtk_spin_button_get_range", (DL_FUNC) &R_gtk_spin_button_get_range, 1},
    {"R_gtk_spin_button_get_snap_to_ticks", (DL_FUNC) &R_gtk_spin_button_get_snap_to_ticks, 1},
    {"R_gtk_spin_button_get_update_policy", (DL_FUNC) &R_gtk_spin_button_get_update_policy, 1},
    {"R_gtk_spin_button_get_value", (DL_FUNC) &R_gtk_spin_button_get_value, 1},
    {"R_gtk_spin_button_get_value_as_int", (DL_FUNC) &R_gtk_spin_button_get_value_as_int, 1},
    {"R_gtk_spin_button_get_wrap", (DL_FUNC) &R_gtk_spin_button_get_wrap, 1},
    {"R_gtk_spin_button_set_adjustment", (DL_FUNC) &R_gtk_spin_button_set_adjustment, 2},
    {"R_gtk_spin_button_set_climb_rate", (DL_FUNC) &R_gtk_spin_button_set_climb_rate, 2},
    {"R_gtk_spin_button_set_digits", (DL_FUNC) &R_gtk_spin_button_set_digits, 2},
    {"R_gtk_spin_button_set_increments", (DL_FUNC) &R_gtk_spin_button_set_increments, 3},
    {"R_gtk_spin_button_set_numeric", (DL_FUNC) &R_gtk_spin_button_set_numeric, 2},
    {"R_gtk_spin_button_set_range", (DL_FUNC) &R_gtk_spin_button_set_range, 3},
    {"R_gtk_spin_button_set_snap_to_ticks", (DL_FUNC) &R_gtk_spin_button_set_snap_to_ticks, 2},
    {"R_gtk_spin_button_set_update_policy", (DL_FUNC) &R_gtk_spin_button_set_update_policy, 2},
    {"R_gtk_spin_button_set_value", (DL_FUNC) &R_gtk_spin_button_set_value, 2},
    {"R_gtk_spin_button_set_wrap", (DL_FUNC) &R_gtk_spin_button_set_wrap, 2},
    {"R_gtk_spin_button_spin", (DL_FUNC) &R_gtk_spin_button_spin, 3},
    {"R_gtk_spin_button_update", (DL_FUNC) &R_gtk_spin_button_update, 1},
    {"R_gtk_spinner_new", (DL_FUNC) &R_gtk_spinner_new, 0},
    {"R_gtk_spinner_get_spinning", (DL_FUNC) &R_gtk_spinner_get_spinning, 1},
    {"R_gtk_spinner_set_spinning", (DL_FUNC) &R_gtk_spinner_set_spinning, 2},
    {"R_gtk_spinner_start", (DL_FUNC) &R_gtk_spinner_start, 1},
    {"R_gtk_spinner_stop", (DL_FUNC) &R_gtk_spinner_stop, 1},
    {"R_gtk_stack_new", (DL_FUNC) &R_gtk_stack_new, 0},
    {"R_gtk_stack_add_child", (DL_FUNC) &R_gtk_stack_add_child, 2},
    {"R_gtk_stack_add_named", (DL_FUNC) &R_gtk_stack_add_named, 3},
    {"R_gtk_stack_add_titled", (DL_FUNC) &R_gtk_stack_add_titled, 4},
    {"R_gtk_stack_get_child_by_name", (DL_FUNC) &R_gtk_stack_get_child_by_name, 2},
    {"R_gtk_stack_get_hhomogeneous", (DL_FUNC) &R_gtk_stack_get_hhomogeneous, 1},
    {"R_gtk_stack_get_interpolate_size", (DL_FUNC) &R_gtk_stack_get_interpolate_size, 1},
    {"R_gtk_stack_get_page", (DL_FUNC) &R_gtk_stack_get_page, 2},
    {"R_gtk_stack_get_pages", (DL_FUNC) &R_gtk_stack_get_pages, 1},
    {"R_gtk_stack_get_transition_duration", (DL_FUNC) &R_gtk_stack_get_transition_duration, 1},
    {"R_gtk_stack_get_transition_running", (DL_FUNC) &R_gtk_stack_get_transition_running, 1},
    {"R_gtk_stack_get_transition_type", (DL_FUNC) &R_gtk_stack_get_transition_type, 1},
    {"R_gtk_stack_get_vhomogeneous", (DL_FUNC) &R_gtk_stack_get_vhomogeneous, 1},
    {"R_gtk_stack_get_visible_child", (DL_FUNC) &R_gtk_stack_get_visible_child, 1},
    {"R_gtk_stack_get_visible_child_name", (DL_FUNC) &R_gtk_stack_get_visible_child_name, 1},
    {"R_gtk_stack_remove", (DL_FUNC) &R_gtk_stack_remove, 2},
    {"R_gtk_stack_set_hhomogeneous", (DL_FUNC) &R_gtk_stack_set_hhomogeneous, 2},
    {"R_gtk_stack_set_interpolate_size", (DL_FUNC) &R_gtk_stack_set_interpolate_size, 2},
    {"R_gtk_stack_set_transition_duration", (DL_FUNC) &R_gtk_stack_set_transition_duration, 2},
    {"R_gtk_stack_set_transition_type", (DL_FUNC) &R_gtk_stack_set_transition_type, 2},
    {"R_gtk_stack_set_vhomogeneous", (DL_FUNC) &R_gtk_stack_set_vhomogeneous, 2},
    {"R_gtk_stack_set_visible_child", (DL_FUNC) &R_gtk_stack_set_visible_child, 2},
    {"R_gtk_stack_set_visible_child_full", (DL_FUNC) &R_gtk_stack_set_visible_child_full, 3},
    {"R_gtk_stack_set_visible_child_name", (DL_FUNC) &R_gtk_stack_set_visible_child_name, 2},
    {"R_gtk_stack_page_get_child", (DL_FUNC) &R_gtk_stack_page_get_child, 1},
    {"R_gtk_stack_page_get_icon_name", (DL_FUNC) &R_gtk_stack_page_get_icon_name, 1},
    {"R_gtk_stack_page_get_name", (DL_FUNC) &R_gtk_stack_page_get_name, 1},
    {"R_gtk_stack_page_get_needs_attention", (DL_FUNC) &R_gtk_stack_page_get_needs_attention, 1},
    {"R_gtk_stack_page_get_title", (DL_FUNC) &R_gtk_stack_page_get_title, 1},
    {"R_gtk_stack_page_get_use_underline", (DL_FUNC) &R_gtk_stack_page_get_use_underline, 1},
    {"R_gtk_stack_page_get_visible", (DL_FUNC) &R_gtk_stack_page_get_visible, 1},
    {"R_gtk_stack_page_set_icon_name", (DL_FUNC) &R_gtk_stack_page_set_icon_name, 2},
    {"R_gtk_stack_page_set_name", (DL_FUNC) &R_gtk_stack_page_set_name, 2},
    {"R_gtk_stack_page_set_needs_attention", (DL_FUNC) &R_gtk_stack_page_set_needs_attention, 2},
    {"R_gtk_stack_page_set_title", (DL_FUNC) &R_gtk_stack_page_set_title, 2},
    {"R_gtk_stack_page_set_use_underline", (DL_FUNC) &R_gtk_stack_page_set_use_underline, 2},
    {"R_gtk_stack_page_set_visible", (DL_FUNC) &R_gtk_stack_page_set_visible, 2},
    {"R_gtk_stack_sidebar_new", (DL_FUNC) &R_gtk_stack_sidebar_new, 0},
    {"R_gtk_stack_sidebar_get_stack", (DL_FUNC) &R_gtk_stack_sidebar_get_stack, 1},
    {"R_gtk_stack_sidebar_set_stack", (DL_FUNC) &R_gtk_stack_sidebar_set_stack, 2},
    {"R_gtk_stack_switcher_new", (DL_FUNC) &R_gtk_stack_switcher_new, 0},
    {"R_gtk_stack_switcher_get_stack", (DL_FUNC) &R_gtk_stack_switcher_get_stack, 1},
    {"R_gtk_stack_switcher_set_stack", (DL_FUNC) &R_gtk_stack_switcher_set_stack, 2},
    {"R_gtk_statusbar_new", (DL_FUNC) &R_gtk_statusbar_new, 0},
    {"R_gtk_statusbar_get_context_id", (DL_FUNC) &R_gtk_statusbar_get_context_id, 2},
    {"R_gtk_statusbar_pop", (DL_FUNC) &R_gtk_statusbar_pop, 2},
    {"R_gtk_statusbar_push", (DL_FUNC) &R_gtk_statusbar_push, 3},
    {"R_gtk_statusbar_remove", (DL_FUNC) &R_gtk_statusbar_remove, 3},
    {"R_gtk_statusbar_remove_all", (DL_FUNC) &R_gtk_statusbar_remove_all, 2},
    {"R_gtk_string_filter_new", (DL_FUNC) &R_gtk_string_filter_new, 1},
    {"R_gtk_string_filter_get_expression", (DL_FUNC) &R_gtk_string_filter_get_expression, 1},
    {"R_gtk_string_filter_get_ignore_case", (DL_FUNC) &R_gtk_string_filter_get_ignore_case, 1},
    {"R_gtk_string_filter_get_match_mode", (DL_FUNC) &R_gtk_string_filter_get_match_mode, 1},
    {"R_gtk_string_filter_get_search", (DL_FUNC) &R_gtk_string_filter_get_search, 1},
    {"R_gtk_string_filter_set_expression", (DL_FUNC) &R_gtk_string_filter_set_expression, 2},
    {"R_gtk_string_filter_set_ignore_case", (DL_FUNC) &R_gtk_string_filter_set_ignore_case, 2},
    {"R_gtk_string_filter_set_match_mode", (DL_FUNC) &R_gtk_string_filter_set_match_mode, 2},
    {"R_gtk_string_filter_set_search", (DL_FUNC) &R_gtk_string_filter_set_search, 2},
    {"R_gtk_string_list_new", (DL_FUNC) &R_gtk_string_list_new, 1},
    {"R_gtk_string_list_append", (DL_FUNC) &R_gtk_string_list_append, 2},
    {"R_gtk_string_list_get_string", (DL_FUNC) &R_gtk_string_list_get_string, 2},
    {"R_gtk_string_list_remove", (DL_FUNC) &R_gtk_string_list_remove, 2},
    {"R_gtk_string_list_splice", (DL_FUNC) &R_gtk_string_list_splice, 4},
    {"R_gtk_string_list_take", (DL_FUNC) &R_gtk_string_list_take, 2},
    {"R_gtk_string_object_new", (DL_FUNC) &R_gtk_string_object_new, 1},
    {"R_gtk_string_object_get_string", (DL_FUNC) &R_gtk_string_object_get_string, 1},
    {"R_gtk_string_sorter_new", (DL_FUNC) &R_gtk_string_sorter_new, 1},
    {"R_gtk_string_sorter_get_collation", (DL_FUNC) &R_gtk_string_sorter_get_collation, 1},
    {"R_gtk_string_sorter_get_expression", (DL_FUNC) &R_gtk_string_sorter_get_expression, 1},
    {"R_gtk_string_sorter_get_ignore_case", (DL_FUNC) &R_gtk_string_sorter_get_ignore_case, 1},
    {"R_gtk_string_sorter_set_collation", (DL_FUNC) &R_gtk_string_sorter_set_collation, 2},
    {"R_gtk_string_sorter_set_expression", (DL_FUNC) &R_gtk_string_sorter_set_expression, 2},
    {"R_gtk_string_sorter_set_ignore_case", (DL_FUNC) &R_gtk_string_sorter_set_ignore_case, 2},
    {"R_gtk_style_context_add_provider_for_display", (DL_FUNC) &R_gtk_style_context_add_provider_for_display, 3},
    {"R_gtk_style_context_remove_provider_for_display", (DL_FUNC) &R_gtk_style_context_remove_provider_for_display, 2},
    {"R_gtk_style_context_add_class", (DL_FUNC) &R_gtk_style_context_add_class, 2},
    {"R_gtk_style_context_add_provider", (DL_FUNC) &R_gtk_style_context_add_provider, 3},
    {"R_gtk_style_context_get_border", (DL_FUNC) &R_gtk_style_context_get_border, 1},
    {"R_gtk_style_context_get_color", (DL_FUNC) &R_gtk_style_context_get_color, 1},
    {"R_gtk_style_context_get_display", (DL_FUNC) &R_gtk_style_context_get_display, 1},
    {"R_gtk_style_context_get_margin", (DL_FUNC) &R_gtk_style_context_get_margin, 1},
    {"R_gtk_style_context_get_padding", (DL_FUNC) &R_gtk_style_context_get_padding, 1},
    {"R_gtk_style_context_get_scale", (DL_FUNC) &R_gtk_style_context_get_scale, 1},
    {"R_gtk_style_context_get_state", (DL_FUNC) &R_gtk_style_context_get_state, 1},
    {"R_gtk_style_context_has_class", (DL_FUNC) &R_gtk_style_context_has_class, 2},
    {"R_gtk_style_context_lookup_color", (DL_FUNC) &R_gtk_style_context_lookup_color, 2},
    {"R_gtk_style_context_remove_class", (DL_FUNC) &R_gtk_style_context_remove_class, 2},
    {"R_gtk_style_context_remove_provider", (DL_FUNC) &R_gtk_style_context_remove_provider, 2},
    {"R_gtk_style_context_restore", (DL_FUNC) &R_gtk_style_context_restore, 1},
    {"R_gtk_style_context_save", (DL_FUNC) &R_gtk_style_context_save, 1},
    {"R_gtk_style_context_set_display", (DL_FUNC) &R_gtk_style_context_set_display, 2},
    {"R_gtk_style_context_set_scale", (DL_FUNC) &R_gtk_style_context_set_scale, 2},
    {"R_gtk_style_context_set_state", (DL_FUNC) &R_gtk_style_context_set_state, 2},
    {"R_gtk_style_context_to_string", (DL_FUNC) &R_gtk_style_context_to_string, 2},
    {"R_gtk_switch_new", (DL_FUNC) &R_gtk_switch_new, 0},
    {"R_gtk_switch_get_active", (DL_FUNC) &R_gtk_switch_get_active, 1},
    {"R_gtk_switch_get_state", (DL_FUNC) &R_gtk_switch_get_state, 1},
    {"R_gtk_switch_set_active", (DL_FUNC) &R_gtk_switch_set_active, 2},
    {"R_gtk_switch_set_state", (DL_FUNC) &R_gtk_switch_set_state, 2},
    {"R_gtk_text_new", (DL_FUNC) &R_gtk_text_new, 0},
    {"R_gtk_text_new_with_buffer", (DL_FUNC) &R_gtk_text_new_with_buffer, 1},
    {"R_gtk_text_compute_cursor_extents", (DL_FUNC) &R_gtk_text_compute_cursor_extents, 2},
    {"R_gtk_text_get_activates_default", (DL_FUNC) &R_gtk_text_get_activates_default, 1},
    {"R_gtk_text_get_attributes", (DL_FUNC) &R_gtk_text_get_attributes, 1},
    {"R_gtk_text_get_buffer", (DL_FUNC) &R_gtk_text_get_buffer, 1},
    {"R_gtk_text_get_enable_emoji_completion", (DL_FUNC) &R_gtk_text_get_enable_emoji_completion, 1},
    {"R_gtk_text_get_extra_menu", (DL_FUNC) &R_gtk_text_get_extra_menu, 1},
    {"R_gtk_text_get_input_hints", (DL_FUNC) &R_gtk_text_get_input_hints, 1},
    {"R_gtk_text_get_input_purpose", (DL_FUNC) &R_gtk_text_get_input_purpose, 1},
    {"R_gtk_text_get_invisible_char", (DL_FUNC) &R_gtk_text_get_invisible_char, 1},
    {"R_gtk_text_get_max_length", (DL_FUNC) &R_gtk_text_get_max_length, 1},
    {"R_gtk_text_get_overwrite_mode", (DL_FUNC) &R_gtk_text_get_overwrite_mode, 1},
    {"R_gtk_text_get_placeholder_text", (DL_FUNC) &R_gtk_text_get_placeholder_text, 1},
    {"R_gtk_text_get_propagate_text_width", (DL_FUNC) &R_gtk_text_get_propagate_text_width, 1},
    {"R_gtk_text_get_tabs", (DL_FUNC) &R_gtk_text_get_tabs, 1},
    {"R_gtk_text_get_text_length", (DL_FUNC) &R_gtk_text_get_text_length, 1},
    {"R_gtk_text_get_truncate_multiline", (DL_FUNC) &R_gtk_text_get_truncate_multiline, 1},
    {"R_gtk_text_get_visibility", (DL_FUNC) &R_gtk_text_get_visibility, 1},
    {"R_gtk_text_grab_focus_without_selecting", (DL_FUNC) &R_gtk_text_grab_focus_without_selecting, 1},
    {"R_gtk_text_set_activates_default", (DL_FUNC) &R_gtk_text_set_activates_default, 2},
    {"R_gtk_text_set_attributes", (DL_FUNC) &R_gtk_text_set_attributes, 2},
    {"R_gtk_text_set_buffer", (DL_FUNC) &R_gtk_text_set_buffer, 2},
    {"R_gtk_text_set_enable_emoji_completion", (DL_FUNC) &R_gtk_text_set_enable_emoji_completion, 2},
    {"R_gtk_text_set_extra_menu", (DL_FUNC) &R_gtk_text_set_extra_menu, 2},
    {"R_gtk_text_set_input_hints", (DL_FUNC) &R_gtk_text_set_input_hints, 2},
    {"R_gtk_text_set_input_purpose", (DL_FUNC) &R_gtk_text_set_input_purpose, 2},
    {"R_gtk_text_set_invisible_char", (DL_FUNC) &R_gtk_text_set_invisible_char, 2},
    {"R_gtk_text_set_max_length", (DL_FUNC) &R_gtk_text_set_max_length, 2},
    {"R_gtk_text_set_overwrite_mode", (DL_FUNC) &R_gtk_text_set_overwrite_mode, 2},
    {"R_gtk_text_set_placeholder_text", (DL_FUNC) &R_gtk_text_set_placeholder_text, 2},
    {"R_gtk_text_set_propagate_text_width", (DL_FUNC) &R_gtk_text_set_propagate_text_width, 2},
    {"R_gtk_text_set_tabs", (DL_FUNC) &R_gtk_text_set_tabs, 2},
    {"R_gtk_text_set_truncate_multiline", (DL_FUNC) &R_gtk_text_set_truncate_multiline, 2},
    {"R_gtk_text_set_visibility", (DL_FUNC) &R_gtk_text_set_visibility, 2},
    {"R_gtk_text_unset_invisible_char", (DL_FUNC) &R_gtk_text_unset_invisible_char, 1},
    {"R_gtk_text_buffer_new", (DL_FUNC) &R_gtk_text_buffer_new, 1},
    {"R_gtk_text_buffer_add_mark", (DL_FUNC) &R_gtk_text_buffer_add_mark, 3},
    {"R_gtk_text_buffer_add_selection_clipboard", (DL_FUNC) &R_gtk_text_buffer_add_selection_clipboard, 2},
    {"R_gtk_text_buffer_apply_tag", (DL_FUNC) &R_gtk_text_buffer_apply_tag, 4},
    {"R_gtk_text_buffer_apply_tag_by_name", (DL_FUNC) &R_gtk_text_buffer_apply_tag_by_name, 4},
    {"R_gtk_text_buffer_backspace", (DL_FUNC) &R_gtk_text_buffer_backspace, 4},
    {"R_gtk_text_buffer_begin_irreversible_action", (DL_FUNC) &R_gtk_text_buffer_begin_irreversible_action, 1},
    {"R_gtk_text_buffer_begin_user_action", (DL_FUNC) &R_gtk_text_buffer_begin_user_action, 1},
    {"R_gtk_text_buffer_copy_clipboard", (DL_FUNC) &R_gtk_text_buffer_copy_clipboard, 2},
    {"R_gtk_text_buffer_create_child_anchor", (DL_FUNC) &R_gtk_text_buffer_create_child_anchor, 2},
    {"R_gtk_text_buffer_create_mark", (DL_FUNC) &R_gtk_text_buffer_create_mark, 4},
    {"R_gtk_text_buffer_cut_clipboard", (DL_FUNC) &R_gtk_text_buffer_cut_clipboard, 3},
    {"R_gtk_text_buffer_delete", (DL_FUNC) &R_gtk_text_buffer_delete, 3},
    {"R_gtk_text_buffer_delete_interactive", (DL_FUNC) &R_gtk_text_buffer_delete_interactive, 4},
    {"R_gtk_text_buffer_delete_mark", (DL_FUNC) &R_gtk_text_buffer_delete_mark, 2},
    {"R_gtk_text_buffer_delete_mark_by_name", (DL_FUNC) &R_gtk_text_buffer_delete_mark_by_name, 2},
    {"R_gtk_text_buffer_delete_selection", (DL_FUNC) &R_gtk_text_buffer_delete_selection, 3},
    {"R_gtk_text_buffer_end_irreversible_action", (DL_FUNC) &R_gtk_text_buffer_end_irreversible_action, 1},
    {"R_gtk_text_buffer_end_user_action", (DL_FUNC) &R_gtk_text_buffer_end_user_action, 1},
    {"R_gtk_text_buffer_get_bounds", (DL_FUNC) &R_gtk_text_buffer_get_bounds, 1},
    {"R_gtk_text_buffer_get_can_redo", (DL_FUNC) &R_gtk_text_buffer_get_can_redo, 1},
    {"R_gtk_text_buffer_get_can_undo", (DL_FUNC) &R_gtk_text_buffer_get_can_undo, 1},
    {"R_gtk_text_buffer_get_char_count", (DL_FUNC) &R_gtk_text_buffer_get_char_count, 1},
    {"R_gtk_text_buffer_get_enable_undo", (DL_FUNC) &R_gtk_text_buffer_get_enable_undo, 1},
    {"R_gtk_text_buffer_get_end_iter", (DL_FUNC) &R_gtk_text_buffer_get_end_iter, 1},
    {"R_gtk_text_buffer_get_has_selection", (DL_FUNC) &R_gtk_text_buffer_get_has_selection, 1},
    {"R_gtk_text_buffer_get_insert", (DL_FUNC) &R_gtk_text_buffer_get_insert, 1},
    {"R_gtk_text_buffer_get_iter_at_child_anchor", (DL_FUNC) &R_gtk_text_buffer_get_iter_at_child_anchor, 2},
    {"R_gtk_text_buffer_get_iter_at_line", (DL_FUNC) &R_gtk_text_buffer_get_iter_at_line, 2},
    {"R_gtk_text_buffer_get_iter_at_line_index", (DL_FUNC) &R_gtk_text_buffer_get_iter_at_line_index, 3},
    {"R_gtk_text_buffer_get_iter_at_line_offset", (DL_FUNC) &R_gtk_text_buffer_get_iter_at_line_offset, 3},
    {"R_gtk_text_buffer_get_iter_at_mark", (DL_FUNC) &R_gtk_text_buffer_get_iter_at_mark, 2},
    {"R_gtk_text_buffer_get_iter_at_offset", (DL_FUNC) &R_gtk_text_buffer_get_iter_at_offset, 2},
    {"R_gtk_text_buffer_get_line_count", (DL_FUNC) &R_gtk_text_buffer_get_line_count, 1},
    {"R_gtk_text_buffer_get_mark", (DL_FUNC) &R_gtk_text_buffer_get_mark, 2},
    {"R_gtk_text_buffer_get_max_undo_levels", (DL_FUNC) &R_gtk_text_buffer_get_max_undo_levels, 1},
    {"R_gtk_text_buffer_get_modified", (DL_FUNC) &R_gtk_text_buffer_get_modified, 1},
    {"R_gtk_text_buffer_get_selection_bound", (DL_FUNC) &R_gtk_text_buffer_get_selection_bound, 1},
    {"R_gtk_text_buffer_get_selection_bounds", (DL_FUNC) &R_gtk_text_buffer_get_selection_bounds, 1},
    {"R_gtk_text_buffer_get_selection_content", (DL_FUNC) &R_gtk_text_buffer_get_selection_content, 1},
    {"R_gtk_text_buffer_get_slice", (DL_FUNC) &R_gtk_text_buffer_get_slice, 4},
    {"R_gtk_text_buffer_get_start_iter", (DL_FUNC) &R_gtk_text_buffer_get_start_iter, 1},
    {"R_gtk_text_buffer_get_tag_table", (DL_FUNC) &R_gtk_text_buffer_get_tag_table, 1},
    {"R_gtk_text_buffer_get_text", (DL_FUNC) &R_gtk_text_buffer_get_text, 4},
    {"R_gtk_text_buffer_insert", (DL_FUNC) &R_gtk_text_buffer_insert, 4},
    {"R_gtk_text_buffer_insert_at_cursor", (DL_FUNC) &R_gtk_text_buffer_insert_at_cursor, 3},
    {"R_gtk_text_buffer_insert_child_anchor", (DL_FUNC) &R_gtk_text_buffer_insert_child_anchor, 3},
    {"R_gtk_text_buffer_insert_interactive", (DL_FUNC) &R_gtk_text_buffer_insert_interactive, 5},
    {"R_gtk_text_buffer_insert_interactive_at_cursor", (DL_FUNC) &R_gtk_text_buffer_insert_interactive_at_cursor, 4},
    {"R_gtk_text_buffer_insert_markup", (DL_FUNC) &R_gtk_text_buffer_insert_markup, 4},
    {"R_gtk_text_buffer_insert_paintable", (DL_FUNC) &R_gtk_text_buffer_insert_paintable, 3},
    {"R_gtk_text_buffer_insert_range", (DL_FUNC) &R_gtk_text_buffer_insert_range, 4},
    {"R_gtk_text_buffer_insert_range_interactive", (DL_FUNC) &R_gtk_text_buffer_insert_range_interactive, 5},
    {"R_gtk_text_buffer_move_mark", (DL_FUNC) &R_gtk_text_buffer_move_mark, 3},
    {"R_gtk_text_buffer_move_mark_by_name", (DL_FUNC) &R_gtk_text_buffer_move_mark_by_name, 3},
    {"R_gtk_text_buffer_paste_clipboard", (DL_FUNC) &R_gtk_text_buffer_paste_clipboard, 4},
    {"R_gtk_text_buffer_place_cursor", (DL_FUNC) &R_gtk_text_buffer_place_cursor, 2},
    {"R_gtk_text_buffer_redo", (DL_FUNC) &R_gtk_text_buffer_redo, 1},
    {"R_gtk_text_buffer_remove_all_tags", (DL_FUNC) &R_gtk_text_buffer_remove_all_tags, 3},
    {"R_gtk_text_buffer_remove_selection_clipboard", (DL_FUNC) &R_gtk_text_buffer_remove_selection_clipboard, 2},
    {"R_gtk_text_buffer_remove_tag", (DL_FUNC) &R_gtk_text_buffer_remove_tag, 4},
    {"R_gtk_text_buffer_remove_tag_by_name", (DL_FUNC) &R_gtk_text_buffer_remove_tag_by_name, 4},
    {"R_gtk_text_buffer_select_range", (DL_FUNC) &R_gtk_text_buffer_select_range, 3},
    {"R_gtk_text_buffer_set_enable_undo", (DL_FUNC) &R_gtk_text_buffer_set_enable_undo, 2},
    {"R_gtk_text_buffer_set_max_undo_levels", (DL_FUNC) &R_gtk_text_buffer_set_max_undo_levels, 2},
    {"R_gtk_text_buffer_set_modified", (DL_FUNC) &R_gtk_text_buffer_set_modified, 2},
    {"R_gtk_text_buffer_set_text", (DL_FUNC) &R_gtk_text_buffer_set_text, 3},
    {"R_gtk_text_buffer_undo", (DL_FUNC) &R_gtk_text_buffer_undo, 1},
    {"R_gtk_text_child_anchor_new", (DL_FUNC) &R_gtk_text_child_anchor_new, 0},
    {"R_gtk_text_child_anchor_new_with_replacement", (DL_FUNC) &R_gtk_text_child_anchor_new_with_replacement, 1},
    {"R_gtk_text_child_anchor_get_deleted", (DL_FUNC) &R_gtk_text_child_anchor_get_deleted, 1},
    {"R_gtk_text_child_anchor_get_widgets", (DL_FUNC) &R_gtk_text_child_anchor_get_widgets, 1},
    {"R_gtk_text_iter_assign", (DL_FUNC) &R_gtk_text_iter_assign, 2},
    {"R_gtk_text_iter_backward_char", (DL_FUNC) &R_gtk_text_iter_backward_char, 1},
    {"R_gtk_text_iter_backward_chars", (DL_FUNC) &R_gtk_text_iter_backward_chars, 2},
    {"R_gtk_text_iter_backward_cursor_position", (DL_FUNC) &R_gtk_text_iter_backward_cursor_position, 1},
    {"R_gtk_text_iter_backward_cursor_positions", (DL_FUNC) &R_gtk_text_iter_backward_cursor_positions, 2},
    {"R_gtk_text_iter_backward_find_char", (DL_FUNC) &R_gtk_text_iter_backward_find_char, 4},
    {"R_gtk_text_iter_backward_line", (DL_FUNC) &R_gtk_text_iter_backward_line, 1},
    {"R_gtk_text_iter_backward_lines", (DL_FUNC) &R_gtk_text_iter_backward_lines, 2},
    {"R_gtk_text_iter_backward_search", (DL_FUNC) &R_gtk_text_iter_backward_search, 4},
    {"R_gtk_text_iter_backward_sentence_start", (DL_FUNC) &R_gtk_text_iter_backward_sentence_start, 1},
    {"R_gtk_text_iter_backward_sentence_starts", (DL_FUNC) &R_gtk_text_iter_backward_sentence_starts, 2},
    {"R_gtk_text_iter_backward_to_tag_toggle", (DL_FUNC) &R_gtk_text_iter_backward_to_tag_toggle, 2},
    {"R_gtk_text_iter_backward_visible_cursor_position", (DL_FUNC) &R_gtk_text_iter_backward_visible_cursor_position, 1},
    {"R_gtk_text_iter_backward_visible_cursor_positions", (DL_FUNC) &R_gtk_text_iter_backward_visible_cursor_positions, 2},
    {"R_gtk_text_iter_backward_visible_line", (DL_FUNC) &R_gtk_text_iter_backward_visible_line, 1},
    {"R_gtk_text_iter_backward_visible_lines", (DL_FUNC) &R_gtk_text_iter_backward_visible_lines, 2},
    {"R_gtk_text_iter_backward_visible_word_start", (DL_FUNC) &R_gtk_text_iter_backward_visible_word_start, 1},
    {"R_gtk_text_iter_backward_visible_word_starts", (DL_FUNC) &R_gtk_text_iter_backward_visible_word_starts, 2},
    {"R_gtk_text_iter_backward_word_start", (DL_FUNC) &R_gtk_text_iter_backward_word_start, 1},
    {"R_gtk_text_iter_backward_word_starts", (DL_FUNC) &R_gtk_text_iter_backward_word_starts, 2},
    {"R_gtk_text_iter_can_insert", (DL_FUNC) &R_gtk_text_iter_can_insert, 2},
    {"R_gtk_text_iter_compare", (DL_FUNC) &R_gtk_text_iter_compare, 2},
    {"R_gtk_text_iter_copy", (DL_FUNC) &R_gtk_text_iter_copy, 1},
    {"R_gtk_text_iter_editable", (DL_FUNC) &R_gtk_text_iter_editable, 2},
    {"R_gtk_text_iter_ends_line", (DL_FUNC) &R_gtk_text_iter_ends_line, 1},
    {"R_gtk_text_iter_ends_sentence", (DL_FUNC) &R_gtk_text_iter_ends_sentence, 1},
    {"R_gtk_text_iter_ends_tag", (DL_FUNC) &R_gtk_text_iter_ends_tag, 2},
    {"R_gtk_text_iter_ends_word", (DL_FUNC) &R_gtk_text_iter_ends_word, 1},
    {"R_gtk_text_iter_equal", (DL_FUNC) &R_gtk_text_iter_equal, 2},
    {"R_gtk_text_iter_forward_char", (DL_FUNC) &R_gtk_text_iter_forward_char, 1},
    {"R_gtk_text_iter_forward_chars", (DL_FUNC) &R_gtk_text_iter_forward_chars, 2},
    {"R_gtk_text_iter_forward_cursor_position", (DL_FUNC) &R_gtk_text_iter_forward_cursor_position, 1},
    {"R_gtk_text_iter_forward_cursor_positions", (DL_FUNC) &R_gtk_text_iter_forward_cursor_positions, 2},
    {"R_gtk_text_iter_forward_find_char", (DL_FUNC) &R_gtk_text_iter_forward_find_char, 4},
    {"R_gtk_text_iter_forward_line", (DL_FUNC) &R_gtk_text_iter_forward_line, 1},
    {"R_gtk_text_iter_forward_lines", (DL_FUNC) &R_gtk_text_iter_forward_lines, 2},
    {"R_gtk_text_iter_forward_search", (DL_FUNC) &R_gtk_text_iter_forward_search, 4},
    {"R_gtk_text_iter_forward_sentence_end", (DL_FUNC) &R_gtk_text_iter_forward_sentence_end, 1},
    {"R_gtk_text_iter_forward_sentence_ends", (DL_FUNC) &R_gtk_text_iter_forward_sentence_ends, 2},
    {"R_gtk_text_iter_forward_to_end", (DL_FUNC) &R_gtk_text_iter_forward_to_end, 1},
    {"R_gtk_text_iter_forward_to_line_end", (DL_FUNC) &R_gtk_text_iter_forward_to_line_end, 1},
    {"R_gtk_text_iter_forward_to_tag_toggle", (DL_FUNC) &R_gtk_text_iter_forward_to_tag_toggle, 2},
    {"R_gtk_text_iter_forward_visible_cursor_position", (DL_FUNC) &R_gtk_text_iter_forward_visible_cursor_position, 1},
    {"R_gtk_text_iter_forward_visible_cursor_positions", (DL_FUNC) &R_gtk_text_iter_forward_visible_cursor_positions, 2},
    {"R_gtk_text_iter_forward_visible_line", (DL_FUNC) &R_gtk_text_iter_forward_visible_line, 1},
    {"R_gtk_text_iter_forward_visible_lines", (DL_FUNC) &R_gtk_text_iter_forward_visible_lines, 2},
    {"R_gtk_text_iter_forward_visible_word_end", (DL_FUNC) &R_gtk_text_iter_forward_visible_word_end, 1},
    {"R_gtk_text_iter_forward_visible_word_ends", (DL_FUNC) &R_gtk_text_iter_forward_visible_word_ends, 2},
    {"R_gtk_text_iter_forward_word_end", (DL_FUNC) &R_gtk_text_iter_forward_word_end, 1},
    {"R_gtk_text_iter_forward_word_ends", (DL_FUNC) &R_gtk_text_iter_forward_word_ends, 2},
    {"R_gtk_text_iter_free", (DL_FUNC) &R_gtk_text_iter_free, 1},
    {"R_gtk_text_iter_get_buffer", (DL_FUNC) &R_gtk_text_iter_get_buffer, 1},
    {"R_gtk_text_iter_get_bytes_in_line", (DL_FUNC) &R_gtk_text_iter_get_bytes_in_line, 1},
    {"R_gtk_text_iter_get_char", (DL_FUNC) &R_gtk_text_iter_get_char, 1},
    {"R_gtk_text_iter_get_chars_in_line", (DL_FUNC) &R_gtk_text_iter_get_chars_in_line, 1},
    {"R_gtk_text_iter_get_child_anchor", (DL_FUNC) &R_gtk_text_iter_get_child_anchor, 1},
    {"R_gtk_text_iter_get_language", (DL_FUNC) &R_gtk_text_iter_get_language, 1},
    {"R_gtk_text_iter_get_line", (DL_FUNC) &R_gtk_text_iter_get_line, 1},
    {"R_gtk_text_iter_get_line_index", (DL_FUNC) &R_gtk_text_iter_get_line_index, 1},
    {"R_gtk_text_iter_get_line_offset", (DL_FUNC) &R_gtk_text_iter_get_line_offset, 1},
    {"R_gtk_text_iter_get_marks", (DL_FUNC) &R_gtk_text_iter_get_marks, 1},
    {"R_gtk_text_iter_get_offset", (DL_FUNC) &R_gtk_text_iter_get_offset, 1},
    {"R_gtk_text_iter_get_paintable", (DL_FUNC) &R_gtk_text_iter_get_paintable, 1},
    {"R_gtk_text_iter_get_slice", (DL_FUNC) &R_gtk_text_iter_get_slice, 2},
    {"R_gtk_text_iter_get_tags", (DL_FUNC) &R_gtk_text_iter_get_tags, 1},
    {"R_gtk_text_iter_get_text", (DL_FUNC) &R_gtk_text_iter_get_text, 2},
    {"R_gtk_text_iter_get_toggled_tags", (DL_FUNC) &R_gtk_text_iter_get_toggled_tags, 2},
    {"R_gtk_text_iter_get_visible_line_index", (DL_FUNC) &R_gtk_text_iter_get_visible_line_index, 1},
    {"R_gtk_text_iter_get_visible_line_offset", (DL_FUNC) &R_gtk_text_iter_get_visible_line_offset, 1},
    {"R_gtk_text_iter_get_visible_slice", (DL_FUNC) &R_gtk_text_iter_get_visible_slice, 2},
    {"R_gtk_text_iter_get_visible_text", (DL_FUNC) &R_gtk_text_iter_get_visible_text, 2},
    {"R_gtk_text_iter_has_tag", (DL_FUNC) &R_gtk_text_iter_has_tag, 2},
    {"R_gtk_text_iter_in_range", (DL_FUNC) &R_gtk_text_iter_in_range, 3},
    {"R_gtk_text_iter_inside_sentence", (DL_FUNC) &R_gtk_text_iter_inside_sentence, 1},
    {"R_gtk_text_iter_inside_word", (DL_FUNC) &R_gtk_text_iter_inside_word, 1},
    {"R_gtk_text_iter_is_cursor_position", (DL_FUNC) &R_gtk_text_iter_is_cursor_position, 1},
    {"R_gtk_text_iter_is_end", (DL_FUNC) &R_gtk_text_iter_is_end, 1},
    {"R_gtk_text_iter_is_start", (DL_FUNC) &R_gtk_text_iter_is_start, 1},
    {"R_gtk_text_iter_order", (DL_FUNC) &R_gtk_text_iter_order, 2},
    {"R_gtk_text_iter_set_line", (DL_FUNC) &R_gtk_text_iter_set_line, 2},
    {"R_gtk_text_iter_set_line_index", (DL_FUNC) &R_gtk_text_iter_set_line_index, 2},
    {"R_gtk_text_iter_set_line_offset", (DL_FUNC) &R_gtk_text_iter_set_line_offset, 2},
    {"R_gtk_text_iter_set_offset", (DL_FUNC) &R_gtk_text_iter_set_offset, 2},
    {"R_gtk_text_iter_set_visible_line_index", (DL_FUNC) &R_gtk_text_iter_set_visible_line_index, 2},
    {"R_gtk_text_iter_set_visible_line_offset", (DL_FUNC) &R_gtk_text_iter_set_visible_line_offset, 2},
    {"R_gtk_text_iter_starts_line", (DL_FUNC) &R_gtk_text_iter_starts_line, 1},
    {"R_gtk_text_iter_starts_sentence", (DL_FUNC) &R_gtk_text_iter_starts_sentence, 1},
    {"R_gtk_text_iter_starts_tag", (DL_FUNC) &R_gtk_text_iter_starts_tag, 2},
    {"R_gtk_text_iter_starts_word", (DL_FUNC) &R_gtk_text_iter_starts_word, 1},
    {"R_gtk_text_iter_toggles_tag", (DL_FUNC) &R_gtk_text_iter_toggles_tag, 2},
    {"R_gtk_text_mark_new", (DL_FUNC) &R_gtk_text_mark_new, 2},
    {"R_gtk_text_mark_get_buffer", (DL_FUNC) &R_gtk_text_mark_get_buffer, 1},
    {"R_gtk_text_mark_get_deleted", (DL_FUNC) &R_gtk_text_mark_get_deleted, 1},
    {"R_gtk_text_mark_get_left_gravity", (DL_FUNC) &R_gtk_text_mark_get_left_gravity, 1},
    {"R_gtk_text_mark_get_name", (DL_FUNC) &R_gtk_text_mark_get_name, 1},
    {"R_gtk_text_mark_get_visible", (DL_FUNC) &R_gtk_text_mark_get_visible, 1},
    {"R_gtk_text_mark_set_visible", (DL_FUNC) &R_gtk_text_mark_set_visible, 2},
    {"R_gtk_text_tag_new", (DL_FUNC) &R_gtk_text_tag_new, 1},
    {"R_gtk_text_tag_changed", (DL_FUNC) &R_gtk_text_tag_changed, 2},
    {"R_gtk_text_tag_get_priority", (DL_FUNC) &R_gtk_text_tag_get_priority, 1},
    {"R_gtk_text_tag_set_priority", (DL_FUNC) &R_gtk_text_tag_set_priority, 2},
    {"R_gtk_text_tag_table_new", (DL_FUNC) &R_gtk_text_tag_table_new, 0},
    {"R_gtk_text_tag_table_add", (DL_FUNC) &R_gtk_text_tag_table_add, 2},
    {"R_gtk_text_tag_table_foreach", (DL_FUNC) &R_gtk_text_tag_table_foreach, 3},
    {"R_gtk_text_tag_table_get_size", (DL_FUNC) &R_gtk_text_tag_table_get_size, 1},
    {"R_gtk_text_tag_table_lookup", (DL_FUNC) &R_gtk_text_tag_table_lookup, 2},
    {"R_gtk_text_tag_table_remove", (DL_FUNC) &R_gtk_text_tag_table_remove, 2},
    {"R_gtk_text_view_new", (DL_FUNC) &R_gtk_text_view_new, 0},
    {"R_gtk_text_view_new_with_buffer", (DL_FUNC) &R_gtk_text_view_new_with_buffer, 1},
    {"R_gtk_text_view_add_child_at_anchor", (DL_FUNC) &R_gtk_text_view_add_child_at_anchor, 3},
    {"R_gtk_text_view_add_overlay", (DL_FUNC) &R_gtk_text_view_add_overlay, 4},
    {"R_gtk_text_view_backward_display_line", (DL_FUNC) &R_gtk_text_view_backward_display_line, 2},
    {"R_gtk_text_view_backward_display_line_start", (DL_FUNC) &R_gtk_text_view_backward_display_line_start, 2},
    {"R_gtk_text_view_buffer_to_window_coords", (DL_FUNC) &R_gtk_text_view_buffer_to_window_coords, 4},
    {"R_gtk_text_view_forward_display_line", (DL_FUNC) &R_gtk_text_view_forward_display_line, 2},
    {"R_gtk_text_view_forward_display_line_end", (DL_FUNC) &R_gtk_text_view_forward_display_line_end, 2},
    {"R_gtk_text_view_get_accepts_tab", (DL_FUNC) &R_gtk_text_view_get_accepts_tab, 1},
    {"R_gtk_text_view_get_bottom_margin", (DL_FUNC) &R_gtk_text_view_get_bottom_margin, 1},
    {"R_gtk_text_view_get_buffer", (DL_FUNC) &R_gtk_text_view_get_buffer, 1},
    {"R_gtk_text_view_get_cursor_locations", (DL_FUNC) &R_gtk_text_view_get_cursor_locations, 2},
    {"R_gtk_text_view_get_cursor_visible", (DL_FUNC) &R_gtk_text_view_get_cursor_visible, 1},
    {"R_gtk_text_view_get_editable", (DL_FUNC) &R_gtk_text_view_get_editable, 1},
    {"R_gtk_text_view_get_extra_menu", (DL_FUNC) &R_gtk_text_view_get_extra_menu, 1},
    {"R_gtk_text_view_get_gutter", (DL_FUNC) &R_gtk_text_view_get_gutter, 2},
    {"R_gtk_text_view_get_indent", (DL_FUNC) &R_gtk_text_view_get_indent, 1},
    {"R_gtk_text_view_get_input_hints", (DL_FUNC) &R_gtk_text_view_get_input_hints, 1},
    {"R_gtk_text_view_get_input_purpose", (DL_FUNC) &R_gtk_text_view_get_input_purpose, 1},
    {"R_gtk_text_view_get_iter_at_location", (DL_FUNC) &R_gtk_text_view_get_iter_at_location, 3},
    {"R_gtk_text_view_get_iter_at_position", (DL_FUNC) &R_gtk_text_view_get_iter_at_position, 3},
    {"R_gtk_text_view_get_iter_location", (DL_FUNC) &R_gtk_text_view_get_iter_location, 2},
    {"R_gtk_text_view_get_justification", (DL_FUNC) &R_gtk_text_view_get_justification, 1},
    {"R_gtk_text_view_get_left_margin", (DL_FUNC) &R_gtk_text_view_get_left_margin, 1},
    {"R_gtk_text_view_get_line_at_y", (DL_FUNC) &R_gtk_text_view_get_line_at_y, 2},
    {"R_gtk_text_view_get_line_yrange", (DL_FUNC) &R_gtk_text_view_get_line_yrange, 2},
    {"R_gtk_text_view_get_ltr_context", (DL_FUNC) &R_gtk_text_view_get_ltr_context, 1},
    {"R_gtk_text_view_get_monospace", (DL_FUNC) &R_gtk_text_view_get_monospace, 1},
    {"R_gtk_text_view_get_overwrite", (DL_FUNC) &R_gtk_text_view_get_overwrite, 1},
    {"R_gtk_text_view_get_pixels_above_lines", (DL_FUNC) &R_gtk_text_view_get_pixels_above_lines, 1},
    {"R_gtk_text_view_get_pixels_below_lines", (DL_FUNC) &R_gtk_text_view_get_pixels_below_lines, 1},
    {"R_gtk_text_view_get_pixels_inside_wrap", (DL_FUNC) &R_gtk_text_view_get_pixels_inside_wrap, 1},
    {"R_gtk_text_view_get_right_margin", (DL_FUNC) &R_gtk_text_view_get_right_margin, 1},
    {"R_gtk_text_view_get_rtl_context", (DL_FUNC) &R_gtk_text_view_get_rtl_context, 1},
    {"R_gtk_text_view_get_tabs", (DL_FUNC) &R_gtk_text_view_get_tabs, 1},
    {"R_gtk_text_view_get_top_margin", (DL_FUNC) &R_gtk_text_view_get_top_margin, 1},
    {"R_gtk_text_view_get_visible_rect", (DL_FUNC) &R_gtk_text_view_get_visible_rect, 1},
    {"R_gtk_text_view_get_wrap_mode", (DL_FUNC) &R_gtk_text_view_get_wrap_mode, 1},
    {"R_gtk_text_view_im_context_filter_keypress", (DL_FUNC) &R_gtk_text_view_im_context_filter_keypress, 2},
    {"R_gtk_text_view_move_mark_onscreen", (DL_FUNC) &R_gtk_text_view_move_mark_onscreen, 2},
    {"R_gtk_text_view_move_overlay", (DL_FUNC) &R_gtk_text_view_move_overlay, 4},
    {"R_gtk_text_view_move_visually", (DL_FUNC) &R_gtk_text_view_move_visually, 3},
    {"R_gtk_text_view_place_cursor_onscreen", (DL_FUNC) &R_gtk_text_view_place_cursor_onscreen, 1},
    {"R_gtk_text_view_remove", (DL_FUNC) &R_gtk_text_view_remove, 2},
    {"R_gtk_text_view_reset_cursor_blink", (DL_FUNC) &R_gtk_text_view_reset_cursor_blink, 1},
    {"R_gtk_text_view_reset_im_context", (DL_FUNC) &R_gtk_text_view_reset_im_context, 1},
    {"R_gtk_text_view_scroll_mark_onscreen", (DL_FUNC) &R_gtk_text_view_scroll_mark_onscreen, 2},
    {"R_gtk_text_view_scroll_to_iter", (DL_FUNC) &R_gtk_text_view_scroll_to_iter, 6},
    {"R_gtk_text_view_scroll_to_mark", (DL_FUNC) &R_gtk_text_view_scroll_to_mark, 6},
    {"R_gtk_text_view_set_accepts_tab", (DL_FUNC) &R_gtk_text_view_set_accepts_tab, 2},
    {"R_gtk_text_view_set_bottom_margin", (DL_FUNC) &R_gtk_text_view_set_bottom_margin, 2},
    {"R_gtk_text_view_set_buffer", (DL_FUNC) &R_gtk_text_view_set_buffer, 2},
    {"R_gtk_text_view_set_cursor_visible", (DL_FUNC) &R_gtk_text_view_set_cursor_visible, 2},
    {"R_gtk_text_view_set_editable", (DL_FUNC) &R_gtk_text_view_set_editable, 2},
    {"R_gtk_text_view_set_extra_menu", (DL_FUNC) &R_gtk_text_view_set_extra_menu, 2},
    {"R_gtk_text_view_set_gutter", (DL_FUNC) &R_gtk_text_view_set_gutter, 3},
    {"R_gtk_text_view_set_indent", (DL_FUNC) &R_gtk_text_view_set_indent, 2},
    {"R_gtk_text_view_set_input_hints", (DL_FUNC) &R_gtk_text_view_set_input_hints, 2},
    {"R_gtk_text_view_set_input_purpose", (DL_FUNC) &R_gtk_text_view_set_input_purpose, 2},
    {"R_gtk_text_view_set_justification", (DL_FUNC) &R_gtk_text_view_set_justification, 2},
    {"R_gtk_text_view_set_left_margin", (DL_FUNC) &R_gtk_text_view_set_left_margin, 2},
    {"R_gtk_text_view_set_monospace", (DL_FUNC) &R_gtk_text_view_set_monospace, 2},
    {"R_gtk_text_view_set_overwrite", (DL_FUNC) &R_gtk_text_view_set_overwrite, 2},
    {"R_gtk_text_view_set_pixels_above_lines", (DL_FUNC) &R_gtk_text_view_set_pixels_above_lines, 2},
    {"R_gtk_text_view_set_pixels_below_lines", (DL_FUNC) &R_gtk_text_view_set_pixels_below_lines, 2},
    {"R_gtk_text_view_set_pixels_inside_wrap", (DL_FUNC) &R_gtk_text_view_set_pixels_inside_wrap, 2},
    {"R_gtk_text_view_set_right_margin", (DL_FUNC) &R_gtk_text_view_set_right_margin, 2},
    {"R_gtk_text_view_set_tabs", (DL_FUNC) &R_gtk_text_view_set_tabs, 2},
    {"R_gtk_text_view_set_top_margin", (DL_FUNC) &R_gtk_text_view_set_top_margin, 2},
    {"R_gtk_text_view_set_wrap_mode", (DL_FUNC) &R_gtk_text_view_set_wrap_mode, 2},
    {"R_gtk_text_view_starts_display_line", (DL_FUNC) &R_gtk_text_view_starts_display_line, 2},
    {"R_gtk_text_view_window_to_buffer_coords", (DL_FUNC) &R_gtk_text_view_window_to_buffer_coords, 4},
    {"R_gtk_toggle_button_new", (DL_FUNC) &R_gtk_toggle_button_new, 0},
    {"R_gtk_toggle_button_new_with_label", (DL_FUNC) &R_gtk_toggle_button_new_with_label, 1},
    {"R_gtk_toggle_button_new_with_mnemonic", (DL_FUNC) &R_gtk_toggle_button_new_with_mnemonic, 1},
    {"R_gtk_toggle_button_get_active", (DL_FUNC) &R_gtk_toggle_button_get_active, 1},
    {"R_gtk_toggle_button_set_active", (DL_FUNC) &R_gtk_toggle_button_set_active, 2},
    {"R_gtk_toggle_button_set_group", (DL_FUNC) &R_gtk_toggle_button_set_group, 2},
    {"R_gtk_toggle_button_toggled", (DL_FUNC) &R_gtk_toggle_button_toggled, 1},
    {"R_gtk_tooltip_set_custom", (DL_FUNC) &R_gtk_tooltip_set_custom, 2},
    {"R_gtk_tooltip_set_icon", (DL_FUNC) &R_gtk_tooltip_set_icon, 2},
    {"R_gtk_tooltip_set_icon_from_gicon", (DL_FUNC) &R_gtk_tooltip_set_icon_from_gicon, 2},
    {"R_gtk_tooltip_set_icon_from_icon_name", (DL_FUNC) &R_gtk_tooltip_set_icon_from_icon_name, 2},
    {"R_gtk_tooltip_set_markup", (DL_FUNC) &R_gtk_tooltip_set_markup, 2},
    {"R_gtk_tooltip_set_text", (DL_FUNC) &R_gtk_tooltip_set_text, 2},
    {"R_gtk_tooltip_set_tip_area", (DL_FUNC) &R_gtk_tooltip_set_tip_area, 2},
    {"R_gtk_tree_drag_dest_drag_data_received", (DL_FUNC) &R_gtk_tree_drag_dest_drag_data_received, 3},
    {"R_gtk_tree_drag_dest_row_drop_possible", (DL_FUNC) &R_gtk_tree_drag_dest_row_drop_possible, 3},
    {"R_gtk_tree_drag_source_drag_data_delete", (DL_FUNC) &R_gtk_tree_drag_source_drag_data_delete, 2},
    {"R_gtk_tree_drag_source_drag_data_get", (DL_FUNC) &R_gtk_tree_drag_source_drag_data_get, 2},
    {"R_gtk_tree_drag_source_row_draggable", (DL_FUNC) &R_gtk_tree_drag_source_row_draggable, 2},
    {"R_gtk_tree_expander_new", (DL_FUNC) &R_gtk_tree_expander_new, 0},
    {"R_gtk_tree_expander_get_child", (DL_FUNC) &R_gtk_tree_expander_get_child, 1},
    {"R_gtk_tree_expander_get_hide_expander", (DL_FUNC) &R_gtk_tree_expander_get_hide_expander, 1},
    {"R_gtk_tree_expander_get_indent_for_depth", (DL_FUNC) &R_gtk_tree_expander_get_indent_for_depth, 1},
    {"R_gtk_tree_expander_get_indent_for_icon", (DL_FUNC) &R_gtk_tree_expander_get_indent_for_icon, 1},
    {"R_gtk_tree_expander_get_item", (DL_FUNC) &R_gtk_tree_expander_get_item, 1},
    {"R_gtk_tree_expander_get_list_row", (DL_FUNC) &R_gtk_tree_expander_get_list_row, 1},
    {"R_gtk_tree_expander_set_child", (DL_FUNC) &R_gtk_tree_expander_set_child, 2},
    {"R_gtk_tree_expander_set_hide_expander", (DL_FUNC) &R_gtk_tree_expander_set_hide_expander, 2},
    {"R_gtk_tree_expander_set_indent_for_depth", (DL_FUNC) &R_gtk_tree_expander_set_indent_for_depth, 2},
    {"R_gtk_tree_expander_set_indent_for_icon", (DL_FUNC) &R_gtk_tree_expander_set_indent_for_icon, 2},
    {"R_gtk_tree_expander_set_list_row", (DL_FUNC) &R_gtk_tree_expander_set_list_row, 2},
    {"R_gtk_tree_iter_copy", (DL_FUNC) &R_gtk_tree_iter_copy, 1},
    {"R_gtk_tree_iter_free", (DL_FUNC) &R_gtk_tree_iter_free, 1},
    {"R_gtk_tree_list_model_new", (DL_FUNC) &R_gtk_tree_list_model_new, 6},
    {"R_gtk_tree_list_model_get_autoexpand", (DL_FUNC) &R_gtk_tree_list_model_get_autoexpand, 1},
    {"R_gtk_tree_list_model_get_child_row", (DL_FUNC) &R_gtk_tree_list_model_get_child_row, 2},
    {"R_gtk_tree_list_model_get_model", (DL_FUNC) &R_gtk_tree_list_model_get_model, 1},
    {"R_gtk_tree_list_model_get_passthrough", (DL_FUNC) &R_gtk_tree_list_model_get_passthrough, 1},
    {"R_gtk_tree_list_model_get_row", (DL_FUNC) &R_gtk_tree_list_model_get_row, 2},
    {"R_gtk_tree_list_model_set_autoexpand", (DL_FUNC) &R_gtk_tree_list_model_set_autoexpand, 2},
    {"R_gtk_tree_list_row_get_child_row", (DL_FUNC) &R_gtk_tree_list_row_get_child_row, 2},
    {"R_gtk_tree_list_row_get_children", (DL_FUNC) &R_gtk_tree_list_row_get_children, 1},
    {"R_gtk_tree_list_row_get_depth", (DL_FUNC) &R_gtk_tree_list_row_get_depth, 1},
    {"R_gtk_tree_list_row_get_expanded", (DL_FUNC) &R_gtk_tree_list_row_get_expanded, 1},
    {"R_gtk_tree_list_row_get_item", (DL_FUNC) &R_gtk_tree_list_row_get_item, 1},
    {"R_gtk_tree_list_row_get_parent", (DL_FUNC) &R_gtk_tree_list_row_get_parent, 1},
    {"R_gtk_tree_list_row_get_position", (DL_FUNC) &R_gtk_tree_list_row_get_position, 1},
    {"R_gtk_tree_list_row_is_expandable", (DL_FUNC) &R_gtk_tree_list_row_is_expandable, 1},
    {"R_gtk_tree_list_row_set_expanded", (DL_FUNC) &R_gtk_tree_list_row_set_expanded, 2},
    {"R_gtk_tree_list_row_sorter_new", (DL_FUNC) &R_gtk_tree_list_row_sorter_new, 1},
    {"R_gtk_tree_list_row_sorter_get_sorter", (DL_FUNC) &R_gtk_tree_list_row_sorter_get_sorter, 1},
    {"R_gtk_tree_list_row_sorter_set_sorter", (DL_FUNC) &R_gtk_tree_list_row_sorter_set_sorter, 2},
    {"R_gtk_tree_model_filter_new", (DL_FUNC) &R_gtk_tree_model_filter_new, 2},
    {"R_gtk_tree_model_foreach", (DL_FUNC) &R_gtk_tree_model_foreach, 3},
    {"R_gtk_tree_model_get_column_type", (DL_FUNC) &R_gtk_tree_model_get_column_type, 2},
    {"R_gtk_tree_model_get_flags", (DL_FUNC) &R_gtk_tree_model_get_flags, 1},
    {"R_gtk_tree_model_get_iter", (DL_FUNC) &R_gtk_tree_model_get_iter, 2},
    {"R_gtk_tree_model_get_iter_first", (DL_FUNC) &R_gtk_tree_model_get_iter_first, 1},
    {"R_gtk_tree_model_get_iter_from_string", (DL_FUNC) &R_gtk_tree_model_get_iter_from_string, 2},
    {"R_gtk_tree_model_get_n_columns", (DL_FUNC) &R_gtk_tree_model_get_n_columns, 1},
    {"R_gtk_tree_model_get_path", (DL_FUNC) &R_gtk_tree_model_get_path, 2},
    {"R_gtk_tree_model_get_string_from_iter", (DL_FUNC) &R_gtk_tree_model_get_string_from_iter, 2},
    {"R_gtk_tree_model_get_value", (DL_FUNC) &R_gtk_tree_model_get_value, 3},
    {"R_gtk_tree_model_iter_children", (DL_FUNC) &R_gtk_tree_model_iter_children, 2},
    {"R_gtk_tree_model_iter_has_child", (DL_FUNC) &R_gtk_tree_model_iter_has_child, 2},
    {"R_gtk_tree_model_iter_n_children", (DL_FUNC) &R_gtk_tree_model_iter_n_children, 2},
    {"R_gtk_tree_model_iter_next", (DL_FUNC) &R_gtk_tree_model_iter_next, 2},
    {"R_gtk_tree_model_iter_nth_child", (DL_FUNC) &R_gtk_tree_model_iter_nth_child, 3},
    {"R_gtk_tree_model_iter_parent", (DL_FUNC) &R_gtk_tree_model_iter_parent, 2},
    {"R_gtk_tree_model_iter_previous", (DL_FUNC) &R_gtk_tree_model_iter_previous, 2},
    {"R_gtk_tree_model_ref_node", (DL_FUNC) &R_gtk_tree_model_ref_node, 2},
    {"R_gtk_tree_model_row_changed", (DL_FUNC) &R_gtk_tree_model_row_changed, 3},
    {"R_gtk_tree_model_row_deleted", (DL_FUNC) &R_gtk_tree_model_row_deleted, 2},
    {"R_gtk_tree_model_row_has_child_toggled", (DL_FUNC) &R_gtk_tree_model_row_has_child_toggled, 3},
    {"R_gtk_tree_model_row_inserted", (DL_FUNC) &R_gtk_tree_model_row_inserted, 3},
    {"R_gtk_tree_model_rows_reordered_with_length", (DL_FUNC) &R_gtk_tree_model_rows_reordered_with_length, 5},
    {"R_gtk_tree_model_unref_node", (DL_FUNC) &R_gtk_tree_model_unref_node, 2},
    {"R_gtk_tree_model_filter_clear_cache", (DL_FUNC) &R_gtk_tree_model_filter_clear_cache, 1},
    {"R_gtk_tree_model_filter_convert_child_iter_to_iter", (DL_FUNC) &R_gtk_tree_model_filter_convert_child_iter_to_iter, 2},
    {"R_gtk_tree_model_filter_convert_child_path_to_path", (DL_FUNC) &R_gtk_tree_model_filter_convert_child_path_to_path, 2},
    {"R_gtk_tree_model_filter_convert_iter_to_child_iter", (DL_FUNC) &R_gtk_tree_model_filter_convert_iter_to_child_iter, 2},
    {"R_gtk_tree_model_filter_convert_path_to_child_path", (DL_FUNC) &R_gtk_tree_model_filter_convert_path_to_child_path, 2},
    {"R_gtk_tree_model_filter_get_model", (DL_FUNC) &R_gtk_tree_model_filter_get_model, 1},
    {"R_gtk_tree_model_filter_refilter", (DL_FUNC) &R_gtk_tree_model_filter_refilter, 1},
    {"R_gtk_tree_model_filter_set_modify_func", (DL_FUNC) &R_gtk_tree_model_filter_set_modify_func, 6},
    {"R_gtk_tree_model_filter_set_visible_column", (DL_FUNC) &R_gtk_tree_model_filter_set_visible_column, 2},
    {"R_gtk_tree_model_filter_set_visible_func", (DL_FUNC) &R_gtk_tree_model_filter_set_visible_func, 4},
    {"R_gtk_tree_model_sort_new_with_model", (DL_FUNC) &R_gtk_tree_model_sort_new_with_model, 1},
    {"R_gtk_tree_model_sort_clear_cache", (DL_FUNC) &R_gtk_tree_model_sort_clear_cache, 1},
    {"R_gtk_tree_model_sort_convert_child_iter_to_iter", (DL_FUNC) &R_gtk_tree_model_sort_convert_child_iter_to_iter, 2},
    {"R_gtk_tree_model_sort_convert_child_path_to_path", (DL_FUNC) &R_gtk_tree_model_sort_convert_child_path_to_path, 2},
    {"R_gtk_tree_model_sort_convert_iter_to_child_iter", (DL_FUNC) &R_gtk_tree_model_sort_convert_iter_to_child_iter, 2},
    {"R_gtk_tree_model_sort_convert_path_to_child_path", (DL_FUNC) &R_gtk_tree_model_sort_convert_path_to_child_path, 2},
    {"R_gtk_tree_model_sort_get_model", (DL_FUNC) &R_gtk_tree_model_sort_get_model, 1},
    {"R_gtk_tree_model_sort_iter_is_valid", (DL_FUNC) &R_gtk_tree_model_sort_iter_is_valid, 2},
    {"R_gtk_tree_model_sort_reset_default_sort_func", (DL_FUNC) &R_gtk_tree_model_sort_reset_default_sort_func, 1},
    {"R_gtk_tree_path_new", (DL_FUNC) &R_gtk_tree_path_new, 0},
    {"R_gtk_tree_path_new_first", (DL_FUNC) &R_gtk_tree_path_new_first, 0},
    {"R_gtk_tree_path_new_from_indicesv", (DL_FUNC) &R_gtk_tree_path_new_from_indicesv, 2},
    {"R_gtk_tree_path_new_from_string", (DL_FUNC) &R_gtk_tree_path_new_from_string, 1},
    {"R_gtk_tree_path_append_index", (DL_FUNC) &R_gtk_tree_path_append_index, 2},
    {"R_gtk_tree_path_compare", (DL_FUNC) &R_gtk_tree_path_compare, 2},
    {"R_gtk_tree_path_copy", (DL_FUNC) &R_gtk_tree_path_copy, 1},
    {"R_gtk_tree_path_down", (DL_FUNC) &R_gtk_tree_path_down, 1},
    {"R_gtk_tree_path_free", (DL_FUNC) &R_gtk_tree_path_free, 1},
    {"R_gtk_tree_path_get_depth", (DL_FUNC) &R_gtk_tree_path_get_depth, 1},
    {"R_gtk_tree_path_get_indices_with_depth", (DL_FUNC) &R_gtk_tree_path_get_indices_with_depth, 1},
    {"R_gtk_tree_path_is_ancestor", (DL_FUNC) &R_gtk_tree_path_is_ancestor, 2},
    {"R_gtk_tree_path_is_descendant", (DL_FUNC) &R_gtk_tree_path_is_descendant, 2},
    {"R_gtk_tree_path_next", (DL_FUNC) &R_gtk_tree_path_next, 1},
    {"R_gtk_tree_path_prepend_index", (DL_FUNC) &R_gtk_tree_path_prepend_index, 2},
    {"R_gtk_tree_path_prev", (DL_FUNC) &R_gtk_tree_path_prev, 1},
    {"R_gtk_tree_path_to_string", (DL_FUNC) &R_gtk_tree_path_to_string, 1},
    {"R_gtk_tree_path_up", (DL_FUNC) &R_gtk_tree_path_up, 1},
    {"R_gtk_tree_row_reference_new", (DL_FUNC) &R_gtk_tree_row_reference_new, 2},
    {"R_gtk_tree_row_reference_new_proxy", (DL_FUNC) &R_gtk_tree_row_reference_new_proxy, 3},
    {"R_gtk_tree_row_reference_copy", (DL_FUNC) &R_gtk_tree_row_reference_copy, 1},
    {"R_gtk_tree_row_reference_free", (DL_FUNC) &R_gtk_tree_row_reference_free, 1},
    {"R_gtk_tree_row_reference_get_model", (DL_FUNC) &R_gtk_tree_row_reference_get_model, 1},
    {"R_gtk_tree_row_reference_get_path", (DL_FUNC) &R_gtk_tree_row_reference_get_path, 1},
    {"R_gtk_tree_row_reference_valid", (DL_FUNC) &R_gtk_tree_row_reference_valid, 1},
    {"R_gtk_tree_row_reference_deleted", (DL_FUNC) &R_gtk_tree_row_reference_deleted, 2},
    {"R_gtk_tree_row_reference_inserted", (DL_FUNC) &R_gtk_tree_row_reference_inserted, 2},
    {"R_gtk_tree_selection_count_selected_rows", (DL_FUNC) &R_gtk_tree_selection_count_selected_rows, 1},
    {"R_gtk_tree_selection_get_mode", (DL_FUNC) &R_gtk_tree_selection_get_mode, 1},
    {"R_gtk_tree_selection_get_selected", (DL_FUNC) &R_gtk_tree_selection_get_selected, 1},
    {"R_gtk_tree_selection_get_selected_rows", (DL_FUNC) &R_gtk_tree_selection_get_selected_rows, 1},
    {"R_gtk_tree_selection_get_tree_view", (DL_FUNC) &R_gtk_tree_selection_get_tree_view, 1},
    {"R_gtk_tree_selection_iter_is_selected", (DL_FUNC) &R_gtk_tree_selection_iter_is_selected, 2},
    {"R_gtk_tree_selection_path_is_selected", (DL_FUNC) &R_gtk_tree_selection_path_is_selected, 2},
    {"R_gtk_tree_selection_select_all", (DL_FUNC) &R_gtk_tree_selection_select_all, 1},
    {"R_gtk_tree_selection_select_iter", (DL_FUNC) &R_gtk_tree_selection_select_iter, 2},
    {"R_gtk_tree_selection_select_path", (DL_FUNC) &R_gtk_tree_selection_select_path, 2},
    {"R_gtk_tree_selection_select_range", (DL_FUNC) &R_gtk_tree_selection_select_range, 3},
    {"R_gtk_tree_selection_selected_foreach", (DL_FUNC) &R_gtk_tree_selection_selected_foreach, 3},
    {"R_gtk_tree_selection_set_mode", (DL_FUNC) &R_gtk_tree_selection_set_mode, 2},
    {"R_gtk_tree_selection_set_select_function", (DL_FUNC) &R_gtk_tree_selection_set_select_function, 4},
    {"R_gtk_tree_selection_unselect_all", (DL_FUNC) &R_gtk_tree_selection_unselect_all, 1},
    {"R_gtk_tree_selection_unselect_iter", (DL_FUNC) &R_gtk_tree_selection_unselect_iter, 2},
    {"R_gtk_tree_selection_unselect_path", (DL_FUNC) &R_gtk_tree_selection_unselect_path, 2},
    {"R_gtk_tree_selection_unselect_range", (DL_FUNC) &R_gtk_tree_selection_unselect_range, 3},
    {"R_gtk_tree_sortable_get_sort_column_id", (DL_FUNC) &R_gtk_tree_sortable_get_sort_column_id, 1},
    {"R_gtk_tree_sortable_has_default_sort_func", (DL_FUNC) &R_gtk_tree_sortable_has_default_sort_func, 1},
    {"R_gtk_tree_sortable_set_default_sort_func", (DL_FUNC) &R_gtk_tree_sortable_set_default_sort_func, 4},
    {"R_gtk_tree_sortable_set_sort_column_id", (DL_FUNC) &R_gtk_tree_sortable_set_sort_column_id, 3},
    {"R_gtk_tree_sortable_set_sort_func", (DL_FUNC) &R_gtk_tree_sortable_set_sort_func, 5},
    {"R_gtk_tree_sortable_sort_column_changed", (DL_FUNC) &R_gtk_tree_sortable_sort_column_changed, 1},
    {"R_gtk_tree_store_newv", (DL_FUNC) &R_gtk_tree_store_newv, 2},
    {"R_gtk_tree_store_append", (DL_FUNC) &R_gtk_tree_store_append, 2},
    {"R_gtk_tree_store_clear", (DL_FUNC) &R_gtk_tree_store_clear, 1},
    {"R_gtk_tree_store_insert", (DL_FUNC) &R_gtk_tree_store_insert, 3},
    {"R_gtk_tree_store_insert_after", (DL_FUNC) &R_gtk_tree_store_insert_after, 3},
    {"R_gtk_tree_store_insert_before", (DL_FUNC) &R_gtk_tree_store_insert_before, 3},
    {"R_gtk_tree_store_insert_with_valuesv", (DL_FUNC) &R_gtk_tree_store_insert_with_valuesv, 6},
    {"R_gtk_tree_store_is_ancestor", (DL_FUNC) &R_gtk_tree_store_is_ancestor, 3},
    {"R_gtk_tree_store_iter_depth", (DL_FUNC) &R_gtk_tree_store_iter_depth, 2},
    {"R_gtk_tree_store_iter_is_valid", (DL_FUNC) &R_gtk_tree_store_iter_is_valid, 2},
    {"R_gtk_tree_store_move_after", (DL_FUNC) &R_gtk_tree_store_move_after, 3},
    {"R_gtk_tree_store_move_before", (DL_FUNC) &R_gtk_tree_store_move_before, 3},
    {"R_gtk_tree_store_prepend", (DL_FUNC) &R_gtk_tree_store_prepend, 2},
    {"R_gtk_tree_store_remove", (DL_FUNC) &R_gtk_tree_store_remove, 2},
    {"R_gtk_tree_store_set_column_types", (DL_FUNC) &R_gtk_tree_store_set_column_types, 3},
    {"R_gtk_tree_store_set_value", (DL_FUNC) &R_gtk_tree_store_set_value, 4},
    {"R_gtk_tree_store_set_valuesv", (DL_FUNC) &R_gtk_tree_store_set_valuesv, 5},
    {"R_gtk_tree_store_swap", (DL_FUNC) &R_gtk_tree_store_swap, 3},
    {"R_gtk_tree_view_new", (DL_FUNC) &R_gtk_tree_view_new, 0},
    {"R_gtk_tree_view_new_with_model", (DL_FUNC) &R_gtk_tree_view_new_with_model, 1},
    {"R_gtk_tree_view_append_column", (DL_FUNC) &R_gtk_tree_view_append_column, 2},
    {"R_gtk_tree_view_collapse_all", (DL_FUNC) &R_gtk_tree_view_collapse_all, 1},
    {"R_gtk_tree_view_collapse_row", (DL_FUNC) &R_gtk_tree_view_collapse_row, 2},
    {"R_gtk_tree_view_columns_autosize", (DL_FUNC) &R_gtk_tree_view_columns_autosize, 1},
    {"R_gtk_tree_view_convert_bin_window_to_tree_coords", (DL_FUNC) &R_gtk_tree_view_convert_bin_window_to_tree_coords, 3},
    {"R_gtk_tree_view_convert_bin_window_to_widget_coords", (DL_FUNC) &R_gtk_tree_view_convert_bin_window_to_widget_coords, 3},
    {"R_gtk_tree_view_convert_tree_to_bin_window_coords", (DL_FUNC) &R_gtk_tree_view_convert_tree_to_bin_window_coords, 3},
    {"R_gtk_tree_view_convert_tree_to_widget_coords", (DL_FUNC) &R_gtk_tree_view_convert_tree_to_widget_coords, 3},
    {"R_gtk_tree_view_convert_widget_to_bin_window_coords", (DL_FUNC) &R_gtk_tree_view_convert_widget_to_bin_window_coords, 3},
    {"R_gtk_tree_view_convert_widget_to_tree_coords", (DL_FUNC) &R_gtk_tree_view_convert_widget_to_tree_coords, 3},
    {"R_gtk_tree_view_create_row_drag_icon", (DL_FUNC) &R_gtk_tree_view_create_row_drag_icon, 2},
    {"R_gtk_tree_view_enable_model_drag_dest", (DL_FUNC) &R_gtk_tree_view_enable_model_drag_dest, 3},
    {"R_gtk_tree_view_enable_model_drag_source", (DL_FUNC) &R_gtk_tree_view_enable_model_drag_source, 4},
    {"R_gtk_tree_view_expand_all", (DL_FUNC) &R_gtk_tree_view_expand_all, 1},
    {"R_gtk_tree_view_expand_row", (DL_FUNC) &R_gtk_tree_view_expand_row, 3},
    {"R_gtk_tree_view_expand_to_path", (DL_FUNC) &R_gtk_tree_view_expand_to_path, 2},
    {"R_gtk_tree_view_get_activate_on_single_click", (DL_FUNC) &R_gtk_tree_view_get_activate_on_single_click, 1},
    {"R_gtk_tree_view_get_background_area", (DL_FUNC) &R_gtk_tree_view_get_background_area, 3},
    {"R_gtk_tree_view_get_cell_area", (DL_FUNC) &R_gtk_tree_view_get_cell_area, 3},
    {"R_gtk_tree_view_get_column", (DL_FUNC) &R_gtk_tree_view_get_column, 2},
    {"R_gtk_tree_view_get_columns", (DL_FUNC) &R_gtk_tree_view_get_columns, 1},
    {"R_gtk_tree_view_get_cursor", (DL_FUNC) &R_gtk_tree_view_get_cursor, 1},
    {"R_gtk_tree_view_get_dest_row_at_pos", (DL_FUNC) &R_gtk_tree_view_get_dest_row_at_pos, 3},
    {"R_gtk_tree_view_get_drag_dest_row", (DL_FUNC) &R_gtk_tree_view_get_drag_dest_row, 1},
    {"R_gtk_tree_view_get_enable_search", (DL_FUNC) &R_gtk_tree_view_get_enable_search, 1},
    {"R_gtk_tree_view_get_enable_tree_lines", (DL_FUNC) &R_gtk_tree_view_get_enable_tree_lines, 1},
    {"R_gtk_tree_view_get_expander_column", (DL_FUNC) &R_gtk_tree_view_get_expander_column, 1},
    {"R_gtk_tree_view_get_fixed_height_mode", (DL_FUNC) &R_gtk_tree_view_get_fixed_height_mode, 1},
    {"R_gtk_tree_view_get_grid_lines", (DL_FUNC) &R_gtk_tree_view_get_grid_lines, 1},
    {"R_gtk_tree_view_get_headers_clickable", (DL_FUNC) &R_gtk_tree_view_get_headers_clickable, 1},
    {"R_gtk_tree_view_get_headers_visible", (DL_FUNC) &R_gtk_tree_view_get_headers_visible, 1},
    {"R_gtk_tree_view_get_hover_expand", (DL_FUNC) &R_gtk_tree_view_get_hover_expand, 1},
    {"R_gtk_tree_view_get_hover_selection", (DL_FUNC) &R_gtk_tree_view_get_hover_selection, 1},
    {"R_gtk_tree_view_get_level_indentation", (DL_FUNC) &R_gtk_tree_view_get_level_indentation, 1},
    {"R_gtk_tree_view_get_model", (DL_FUNC) &R_gtk_tree_view_get_model, 1},
    {"R_gtk_tree_view_get_n_columns", (DL_FUNC) &R_gtk_tree_view_get_n_columns, 1},
    {"R_gtk_tree_view_get_path_at_pos", (DL_FUNC) &R_gtk_tree_view_get_path_at_pos, 3},
    {"R_gtk_tree_view_get_reorderable", (DL_FUNC) &R_gtk_tree_view_get_reorderable, 1},
    {"R_gtk_tree_view_get_rubber_banding", (DL_FUNC) &R_gtk_tree_view_get_rubber_banding, 1},
    {"R_gtk_tree_view_get_search_column", (DL_FUNC) &R_gtk_tree_view_get_search_column, 1},
    {"R_gtk_tree_view_get_search_entry", (DL_FUNC) &R_gtk_tree_view_get_search_entry, 1},
    {"R_gtk_tree_view_get_selection", (DL_FUNC) &R_gtk_tree_view_get_selection, 1},
    {"R_gtk_tree_view_get_show_expanders", (DL_FUNC) &R_gtk_tree_view_get_show_expanders, 1},
    {"R_gtk_tree_view_get_tooltip_column", (DL_FUNC) &R_gtk_tree_view_get_tooltip_column, 1},
    {"R_gtk_tree_view_get_tooltip_context", (DL_FUNC) &R_gtk_tree_view_get_tooltip_context, 4},
    {"R_gtk_tree_view_get_visible_range", (DL_FUNC) &R_gtk_tree_view_get_visible_range, 1},
    {"R_gtk_tree_view_get_visible_rect", (DL_FUNC) &R_gtk_tree_view_get_visible_rect, 1},
    {"R_gtk_tree_view_insert_column", (DL_FUNC) &R_gtk_tree_view_insert_column, 3},
    {"R_gtk_tree_view_insert_column_with_data_func", (DL_FUNC) &R_gtk_tree_view_insert_column_with_data_func, 7},
    {"R_gtk_tree_view_is_blank_at_pos", (DL_FUNC) &R_gtk_tree_view_is_blank_at_pos, 3},
    {"R_gtk_tree_view_is_rubber_banding_active", (DL_FUNC) &R_gtk_tree_view_is_rubber_banding_active, 1},
    {"R_gtk_tree_view_map_expanded_rows", (DL_FUNC) &R_gtk_tree_view_map_expanded_rows, 3},
    {"R_gtk_tree_view_move_column_after", (DL_FUNC) &R_gtk_tree_view_move_column_after, 3},
    {"R_gtk_tree_view_remove_column", (DL_FUNC) &R_gtk_tree_view_remove_column, 2},
    {"R_gtk_tree_view_row_activated", (DL_FUNC) &R_gtk_tree_view_row_activated, 3},
    {"R_gtk_tree_view_row_expanded", (DL_FUNC) &R_gtk_tree_view_row_expanded, 2},
    {"R_gtk_tree_view_scroll_to_cell", (DL_FUNC) &R_gtk_tree_view_scroll_to_cell, 6},
    {"R_gtk_tree_view_scroll_to_point", (DL_FUNC) &R_gtk_tree_view_scroll_to_point, 3},
    {"R_gtk_tree_view_set_activate_on_single_click", (DL_FUNC) &R_gtk_tree_view_set_activate_on_single_click, 2},
    {"R_gtk_tree_view_set_column_drag_function", (DL_FUNC) &R_gtk_tree_view_set_column_drag_function, 4},
    {"R_gtk_tree_view_set_cursor", (DL_FUNC) &R_gtk_tree_view_set_cursor, 4},
    {"R_gtk_tree_view_set_cursor_on_cell", (DL_FUNC) &R_gtk_tree_view_set_cursor_on_cell, 5},
    {"R_gtk_tree_view_set_drag_dest_row", (DL_FUNC) &R_gtk_tree_view_set_drag_dest_row, 3},
    {"R_gtk_tree_view_set_enable_search", (DL_FUNC) &R_gtk_tree_view_set_enable_search, 2},
    {"R_gtk_tree_view_set_enable_tree_lines", (DL_FUNC) &R_gtk_tree_view_set_enable_tree_lines, 2},
    {"R_gtk_tree_view_set_expander_column", (DL_FUNC) &R_gtk_tree_view_set_expander_column, 2},
    {"R_gtk_tree_view_set_fixed_height_mode", (DL_FUNC) &R_gtk_tree_view_set_fixed_height_mode, 2},
    {"R_gtk_tree_view_set_grid_lines", (DL_FUNC) &R_gtk_tree_view_set_grid_lines, 2},
    {"R_gtk_tree_view_set_headers_clickable", (DL_FUNC) &R_gtk_tree_view_set_headers_clickable, 2},
    {"R_gtk_tree_view_set_headers_visible", (DL_FUNC) &R_gtk_tree_view_set_headers_visible, 2},
    {"R_gtk_tree_view_set_hover_expand", (DL_FUNC) &R_gtk_tree_view_set_hover_expand, 2},
    {"R_gtk_tree_view_set_hover_selection", (DL_FUNC) &R_gtk_tree_view_set_hover_selection, 2},
    {"R_gtk_tree_view_set_level_indentation", (DL_FUNC) &R_gtk_tree_view_set_level_indentation, 2},
    {"R_gtk_tree_view_set_model", (DL_FUNC) &R_gtk_tree_view_set_model, 2},
    {"R_gtk_tree_view_set_reorderable", (DL_FUNC) &R_gtk_tree_view_set_reorderable, 2},
    {"R_gtk_tree_view_set_row_separator_func", (DL_FUNC) &R_gtk_tree_view_set_row_separator_func, 4},
    {"R_gtk_tree_view_set_rubber_banding", (DL_FUNC) &R_gtk_tree_view_set_rubber_banding, 2},
    {"R_gtk_tree_view_set_search_column", (DL_FUNC) &R_gtk_tree_view_set_search_column, 2},
    {"R_gtk_tree_view_set_search_entry", (DL_FUNC) &R_gtk_tree_view_set_search_entry, 2},
    {"R_gtk_tree_view_set_search_equal_func", (DL_FUNC) &R_gtk_tree_view_set_search_equal_func, 4},
    {"R_gtk_tree_view_set_show_expanders", (DL_FUNC) &R_gtk_tree_view_set_show_expanders, 2},
    {"R_gtk_tree_view_set_tooltip_cell", (DL_FUNC) &R_gtk_tree_view_set_tooltip_cell, 5},
    {"R_gtk_tree_view_set_tooltip_column", (DL_FUNC) &R_gtk_tree_view_set_tooltip_column, 2},
    {"R_gtk_tree_view_set_tooltip_row", (DL_FUNC) &R_gtk_tree_view_set_tooltip_row, 3},
    {"R_gtk_tree_view_unset_rows_drag_dest", (DL_FUNC) &R_gtk_tree_view_unset_rows_drag_dest, 1},
    {"R_gtk_tree_view_unset_rows_drag_source", (DL_FUNC) &R_gtk_tree_view_unset_rows_drag_source, 1},
    {"R_gtk_tree_view_column_new", (DL_FUNC) &R_gtk_tree_view_column_new, 0},
    {"R_gtk_tree_view_column_new_with_area", (DL_FUNC) &R_gtk_tree_view_column_new_with_area, 1},
    {"R_gtk_tree_view_column_add_attribute", (DL_FUNC) &R_gtk_tree_view_column_add_attribute, 4},
    {"R_gtk_tree_view_column_cell_get_position", (DL_FUNC) &R_gtk_tree_view_column_cell_get_position, 2},
    {"R_gtk_tree_view_column_cell_get_size", (DL_FUNC) &R_gtk_tree_view_column_cell_get_size, 1},
    {"R_gtk_tree_view_column_cell_is_visible", (DL_FUNC) &R_gtk_tree_view_column_cell_is_visible, 1},
    {"R_gtk_tree_view_column_cell_set_cell_data", (DL_FUNC) &R_gtk_tree_view_column_cell_set_cell_data, 5},
    {"R_gtk_tree_view_column_clear", (DL_FUNC) &R_gtk_tree_view_column_clear, 1},
    {"R_gtk_tree_view_column_clear_attributes", (DL_FUNC) &R_gtk_tree_view_column_clear_attributes, 2},
    {"R_gtk_tree_view_column_clicked", (DL_FUNC) &R_gtk_tree_view_column_clicked, 1},
    {"R_gtk_tree_view_column_focus_cell", (DL_FUNC) &R_gtk_tree_view_column_focus_cell, 2},
    {"R_gtk_tree_view_column_get_alignment", (DL_FUNC) &R_gtk_tree_view_column_get_alignment, 1},
    {"R_gtk_tree_view_column_get_button", (DL_FUNC) &R_gtk_tree_view_column_get_button, 1},
    {"R_gtk_tree_view_column_get_clickable", (DL_FUNC) &R_gtk_tree_view_column_get_clickable, 1},
    {"R_gtk_tree_view_column_get_expand", (DL_FUNC) &R_gtk_tree_view_column_get_expand, 1},
    {"R_gtk_tree_view_column_get_fixed_width", (DL_FUNC) &R_gtk_tree_view_column_get_fixed_width, 1},
    {"R_gtk_tree_view_column_get_max_width", (DL_FUNC) &R_gtk_tree_view_column_get_max_width, 1},
    {"R_gtk_tree_view_column_get_min_width", (DL_FUNC) &R_gtk_tree_view_column_get_min_width, 1},
    {"R_gtk_tree_view_column_get_reorderable", (DL_FUNC) &R_gtk_tree_view_column_get_reorderable, 1},
    {"R_gtk_tree_view_column_get_resizable", (DL_FUNC) &R_gtk_tree_view_column_get_resizable, 1},
    {"R_gtk_tree_view_column_get_sizing", (DL_FUNC) &R_gtk_tree_view_column_get_sizing, 1},
    {"R_gtk_tree_view_column_get_sort_column_id", (DL_FUNC) &R_gtk_tree_view_column_get_sort_column_id, 1},
    {"R_gtk_tree_view_column_get_sort_indicator", (DL_FUNC) &R_gtk_tree_view_column_get_sort_indicator, 1},
    {"R_gtk_tree_view_column_get_sort_order", (DL_FUNC) &R_gtk_tree_view_column_get_sort_order, 1},
    {"R_gtk_tree_view_column_get_spacing", (DL_FUNC) &R_gtk_tree_view_column_get_spacing, 1},
    {"R_gtk_tree_view_column_get_title", (DL_FUNC) &R_gtk_tree_view_column_get_title, 1},
    {"R_gtk_tree_view_column_get_tree_view", (DL_FUNC) &R_gtk_tree_view_column_get_tree_view, 1},
    {"R_gtk_tree_view_column_get_visible", (DL_FUNC) &R_gtk_tree_view_column_get_visible, 1},
    {"R_gtk_tree_view_column_get_widget", (DL_FUNC) &R_gtk_tree_view_column_get_widget, 1},
    {"R_gtk_tree_view_column_get_width", (DL_FUNC) &R_gtk_tree_view_column_get_width, 1},
    {"R_gtk_tree_view_column_get_x_offset", (DL_FUNC) &R_gtk_tree_view_column_get_x_offset, 1},
    {"R_gtk_tree_view_column_pack_end", (DL_FUNC) &R_gtk_tree_view_column_pack_end, 3},
    {"R_gtk_tree_view_column_pack_start", (DL_FUNC) &R_gtk_tree_view_column_pack_start, 3},
    {"R_gtk_tree_view_column_queue_resize", (DL_FUNC) &R_gtk_tree_view_column_queue_resize, 1},
    {"R_gtk_tree_view_column_set_alignment", (DL_FUNC) &R_gtk_tree_view_column_set_alignment, 2},
    {"R_gtk_tree_view_column_set_cell_data_func", (DL_FUNC) &R_gtk_tree_view_column_set_cell_data_func, 5},
    {"R_gtk_tree_view_column_set_clickable", (DL_FUNC) &R_gtk_tree_view_column_set_clickable, 2},
    {"R_gtk_tree_view_column_set_expand", (DL_FUNC) &R_gtk_tree_view_column_set_expand, 2},
    {"R_gtk_tree_view_column_set_fixed_width", (DL_FUNC) &R_gtk_tree_view_column_set_fixed_width, 2},
    {"R_gtk_tree_view_column_set_max_width", (DL_FUNC) &R_gtk_tree_view_column_set_max_width, 2},
    {"R_gtk_tree_view_column_set_min_width", (DL_FUNC) &R_gtk_tree_view_column_set_min_width, 2},
    {"R_gtk_tree_view_column_set_reorderable", (DL_FUNC) &R_gtk_tree_view_column_set_reorderable, 2},
    {"R_gtk_tree_view_column_set_resizable", (DL_FUNC) &R_gtk_tree_view_column_set_resizable, 2},
    {"R_gtk_tree_view_column_set_sizing", (DL_FUNC) &R_gtk_tree_view_column_set_sizing, 2},
    {"R_gtk_tree_view_column_set_sort_column_id", (DL_FUNC) &R_gtk_tree_view_column_set_sort_column_id, 2},
    {"R_gtk_tree_view_column_set_sort_indicator", (DL_FUNC) &R_gtk_tree_view_column_set_sort_indicator, 2},
    {"R_gtk_tree_view_column_set_sort_order", (DL_FUNC) &R_gtk_tree_view_column_set_sort_order, 2},
    {"R_gtk_tree_view_column_set_spacing", (DL_FUNC) &R_gtk_tree_view_column_set_spacing, 2},
    {"R_gtk_tree_view_column_set_title", (DL_FUNC) &R_gtk_tree_view_column_set_title, 2},
    {"R_gtk_tree_view_column_set_visible", (DL_FUNC) &R_gtk_tree_view_column_set_visible, 2},
    {"R_gtk_tree_view_column_set_widget", (DL_FUNC) &R_gtk_tree_view_column_set_widget, 2},
    {"R_gtk_uri_launcher_new", (DL_FUNC) &R_gtk_uri_launcher_new, 1},
    {"R_gtk_uri_launcher_get_uri", (DL_FUNC) &R_gtk_uri_launcher_get_uri, 1},
    {"R_gtk_uri_launcher_launch", (DL_FUNC) &R_gtk_uri_launcher_launch, 5},
    {"R_gtk_uri_launcher_launch_finish", (DL_FUNC) &R_gtk_uri_launcher_launch_finish, 2},
    {"R_gtk_uri_launcher_set_uri", (DL_FUNC) &R_gtk_uri_launcher_set_uri, 2},
    {"R_gtk_video_new", (DL_FUNC) &R_gtk_video_new, 0},
    {"R_gtk_video_new_for_file", (DL_FUNC) &R_gtk_video_new_for_file, 1},
    {"R_gtk_video_new_for_filename", (DL_FUNC) &R_gtk_video_new_for_filename, 1},
    {"R_gtk_video_new_for_media_stream", (DL_FUNC) &R_gtk_video_new_for_media_stream, 1},
    {"R_gtk_video_new_for_resource", (DL_FUNC) &R_gtk_video_new_for_resource, 1},
    {"R_gtk_video_get_autoplay", (DL_FUNC) &R_gtk_video_get_autoplay, 1},
    {"R_gtk_video_get_file", (DL_FUNC) &R_gtk_video_get_file, 1},
    {"R_gtk_video_get_loop", (DL_FUNC) &R_gtk_video_get_loop, 1},
    {"R_gtk_video_get_media_stream", (DL_FUNC) &R_gtk_video_get_media_stream, 1},
    {"R_gtk_video_set_autoplay", (DL_FUNC) &R_gtk_video_set_autoplay, 2},
    {"R_gtk_video_set_file", (DL_FUNC) &R_gtk_video_set_file, 2},
    {"R_gtk_video_set_filename", (DL_FUNC) &R_gtk_video_set_filename, 2},
    {"R_gtk_video_set_loop", (DL_FUNC) &R_gtk_video_set_loop, 2},
    {"R_gtk_video_set_media_stream", (DL_FUNC) &R_gtk_video_set_media_stream, 2},
    {"R_gtk_video_set_resource", (DL_FUNC) &R_gtk_video_set_resource, 2},
    {"R_gtk_viewport_new", (DL_FUNC) &R_gtk_viewport_new, 2},
    {"R_gtk_viewport_get_child", (DL_FUNC) &R_gtk_viewport_get_child, 1},
    {"R_gtk_viewport_get_scroll_to_focus", (DL_FUNC) &R_gtk_viewport_get_scroll_to_focus, 1},
    {"R_gtk_viewport_scroll_to", (DL_FUNC) &R_gtk_viewport_scroll_to, 3},
    {"R_gtk_viewport_set_child", (DL_FUNC) &R_gtk_viewport_set_child, 2},
    {"R_gtk_viewport_set_scroll_to_focus", (DL_FUNC) &R_gtk_viewport_set_scroll_to_focus, 2},
    {"R_gtk_volume_button_new", (DL_FUNC) &R_gtk_volume_button_new, 0},
    {"R_gtk_widget_get_default_direction", (DL_FUNC) &R_gtk_widget_get_default_direction, 0},
    {"R_gtk_widget_set_default_direction", (DL_FUNC) &R_gtk_widget_set_default_direction, 1},
    {"R_gtk_widget_action_set_enabled", (DL_FUNC) &R_gtk_widget_action_set_enabled, 3},
    {"R_gtk_widget_activate", (DL_FUNC) &R_gtk_widget_activate, 1},
    {"R_gtk_widget_activate_action_variant", (DL_FUNC) &R_gtk_widget_activate_action_variant, 3},
    {"R_gtk_widget_activate_default", (DL_FUNC) &R_gtk_widget_activate_default, 1},
    {"R_gtk_widget_add_controller", (DL_FUNC) &R_gtk_widget_add_controller, 2},
    {"R_gtk_widget_add_css_class", (DL_FUNC) &R_gtk_widget_add_css_class, 2},
    {"R_gtk_widget_add_mnemonic_label", (DL_FUNC) &R_gtk_widget_add_mnemonic_label, 2},
    {"R_gtk_widget_add_tick_callback", (DL_FUNC) &R_gtk_widget_add_tick_callback, 4},
    {"R_gtk_widget_allocate", (DL_FUNC) &R_gtk_widget_allocate, 5},
    {"R_gtk_widget_child_focus", (DL_FUNC) &R_gtk_widget_child_focus, 2},
    {"R_gtk_widget_compute_bounds", (DL_FUNC) &R_gtk_widget_compute_bounds, 2},
    {"R_gtk_widget_compute_expand", (DL_FUNC) &R_gtk_widget_compute_expand, 2},
    {"R_gtk_widget_compute_point", (DL_FUNC) &R_gtk_widget_compute_point, 3},
    {"R_gtk_widget_compute_transform", (DL_FUNC) &R_gtk_widget_compute_transform, 2},
    {"R_gtk_widget_contains", (DL_FUNC) &R_gtk_widget_contains, 3},
    {"R_gtk_widget_create_pango_context", (DL_FUNC) &R_gtk_widget_create_pango_context, 1},
    {"R_gtk_widget_create_pango_layout", (DL_FUNC) &R_gtk_widget_create_pango_layout, 2},
    {"R_gtk_widget_dispose_template", (DL_FUNC) &R_gtk_widget_dispose_template, 2},
    {"R_gtk_drag_check_threshold", (DL_FUNC) &R_gtk_drag_check_threshold, 5},
    {"R_gtk_widget_error_bell", (DL_FUNC) &R_gtk_widget_error_bell, 1},
    {"R_gtk_widget_get_allocated_baseline", (DL_FUNC) &R_gtk_widget_get_allocated_baseline, 1},
    {"R_gtk_widget_get_allocated_height", (DL_FUNC) &R_gtk_widget_get_allocated_height, 1},
    {"R_gtk_widget_get_allocated_width", (DL_FUNC) &R_gtk_widget_get_allocated_width, 1},
    {"R_gtk_widget_get_allocation", (DL_FUNC) &R_gtk_widget_get_allocation, 1},
    {"R_gtk_widget_get_ancestor", (DL_FUNC) &R_gtk_widget_get_ancestor, 2},
    {"R_gtk_widget_get_baseline", (DL_FUNC) &R_gtk_widget_get_baseline, 1},
    {"R_gtk_widget_get_can_focus", (DL_FUNC) &R_gtk_widget_get_can_focus, 1},
    {"R_gtk_widget_get_can_target", (DL_FUNC) &R_gtk_widget_get_can_target, 1},
    {"R_gtk_widget_get_child_visible", (DL_FUNC) &R_gtk_widget_get_child_visible, 1},
    {"R_gtk_widget_get_clipboard", (DL_FUNC) &R_gtk_widget_get_clipboard, 1},
    {"R_gtk_widget_get_color", (DL_FUNC) &R_gtk_widget_get_color, 1},
    {"R_gtk_widget_get_css_classes", (DL_FUNC) &R_gtk_widget_get_css_classes, 1},
    {"R_gtk_widget_get_css_name", (DL_FUNC) &R_gtk_widget_get_css_name, 1},
    {"R_gtk_widget_get_cursor", (DL_FUNC) &R_gtk_widget_get_cursor, 1},
    {"R_gtk_widget_get_direction", (DL_FUNC) &R_gtk_widget_get_direction, 1},
    {"R_gtk_widget_get_display", (DL_FUNC) &R_gtk_widget_get_display, 1},
    {"R_gtk_widget_get_first_child", (DL_FUNC) &R_gtk_widget_get_first_child, 1},
    {"R_gtk_widget_get_focus_child", (DL_FUNC) &R_gtk_widget_get_focus_child, 1},
    {"R_gtk_widget_get_focus_on_click", (DL_FUNC) &R_gtk_widget_get_focus_on_click, 1},
    {"R_gtk_widget_get_focusable", (DL_FUNC) &R_gtk_widget_get_focusable, 1},
    {"R_gtk_widget_get_font_map", (DL_FUNC) &R_gtk_widget_get_font_map, 1},
    {"R_gtk_widget_get_font_options", (DL_FUNC) &R_gtk_widget_get_font_options, 1},
    {"R_gtk_widget_get_frame_clock", (DL_FUNC) &R_gtk_widget_get_frame_clock, 1},
    {"R_gtk_widget_get_halign", (DL_FUNC) &R_gtk_widget_get_halign, 1},
    {"R_gtk_widget_get_has_tooltip", (DL_FUNC) &R_gtk_widget_get_has_tooltip, 1},
    {"R_gtk_widget_get_height", (DL_FUNC) &R_gtk_widget_get_height, 1},
    {"R_gtk_widget_get_hexpand", (DL_FUNC) &R_gtk_widget_get_hexpand, 1},
    {"R_gtk_widget_get_hexpand_set", (DL_FUNC) &R_gtk_widget_get_hexpand_set, 1},
    {"R_gtk_widget_get_last_child", (DL_FUNC) &R_gtk_widget_get_last_child, 1},
    {"R_gtk_widget_get_layout_manager", (DL_FUNC) &R_gtk_widget_get_layout_manager, 1},
    {"R_gtk_widget_get_mapped", (DL_FUNC) &R_gtk_widget_get_mapped, 1},
    {"R_gtk_widget_get_margin_bottom", (DL_FUNC) &R_gtk_widget_get_margin_bottom, 1},
    {"R_gtk_widget_get_margin_end", (DL_FUNC) &R_gtk_widget_get_margin_end, 1},
    {"R_gtk_widget_get_margin_start", (DL_FUNC) &R_gtk_widget_get_margin_start, 1},
    {"R_gtk_widget_get_margin_top", (DL_FUNC) &R_gtk_widget_get_margin_top, 1},
    {"R_gtk_widget_get_name", (DL_FUNC) &R_gtk_widget_get_name, 1},
    {"R_gtk_widget_get_native", (DL_FUNC) &R_gtk_widget_get_native, 1},
    {"R_gtk_widget_get_next_sibling", (DL_FUNC) &R_gtk_widget_get_next_sibling, 1},
    {"R_gtk_widget_get_opacity", (DL_FUNC) &R_gtk_widget_get_opacity, 1},
    {"R_gtk_widget_get_overflow", (DL_FUNC) &R_gtk_widget_get_overflow, 1},
    {"R_gtk_widget_get_pango_context", (DL_FUNC) &R_gtk_widget_get_pango_context, 1},
    {"R_gtk_widget_get_parent", (DL_FUNC) &R_gtk_widget_get_parent, 1},
    {"R_gtk_widget_get_preferred_size", (DL_FUNC) &R_gtk_widget_get_preferred_size, 1},
    {"R_gtk_widget_get_prev_sibling", (DL_FUNC) &R_gtk_widget_get_prev_sibling, 1},
    {"R_gtk_widget_get_primary_clipboard", (DL_FUNC) &R_gtk_widget_get_primary_clipboard, 1},
    {"R_gtk_widget_get_realized", (DL_FUNC) &R_gtk_widget_get_realized, 1},
    {"R_gtk_widget_get_receives_default", (DL_FUNC) &R_gtk_widget_get_receives_default, 1},
    {"R_gtk_widget_get_request_mode", (DL_FUNC) &R_gtk_widget_get_request_mode, 1},
    {"R_gtk_widget_get_root", (DL_FUNC) &R_gtk_widget_get_root, 1},
    {"R_gtk_widget_get_scale_factor", (DL_FUNC) &R_gtk_widget_get_scale_factor, 1},
    {"R_gtk_widget_get_sensitive", (DL_FUNC) &R_gtk_widget_get_sensitive, 1},
    {"R_gtk_widget_get_settings", (DL_FUNC) &R_gtk_widget_get_settings, 1},
    {"R_gtk_widget_get_size", (DL_FUNC) &R_gtk_widget_get_size, 2},
    {"R_gtk_widget_get_size_request", (DL_FUNC) &R_gtk_widget_get_size_request, 1},
    {"R_gtk_widget_get_state_flags", (DL_FUNC) &R_gtk_widget_get_state_flags, 1},
    {"R_gtk_widget_get_style_context", (DL_FUNC) &R_gtk_widget_get_style_context, 1},
    {"R_gtk_widget_get_template_child", (DL_FUNC) &R_gtk_widget_get_template_child, 3},
    {"R_gtk_widget_get_tooltip_markup", (DL_FUNC) &R_gtk_widget_get_tooltip_markup, 1},
    {"R_gtk_widget_get_tooltip_text", (DL_FUNC) &R_gtk_widget_get_tooltip_text, 1},
    {"R_gtk_widget_get_valign", (DL_FUNC) &R_gtk_widget_get_valign, 1},
    {"R_gtk_widget_get_vexpand", (DL_FUNC) &R_gtk_widget_get_vexpand, 1},
    {"R_gtk_widget_get_vexpand_set", (DL_FUNC) &R_gtk_widget_get_vexpand_set, 1},
    {"R_gtk_widget_get_visible", (DL_FUNC) &R_gtk_widget_get_visible, 1},
    {"R_gtk_widget_get_width", (DL_FUNC) &R_gtk_widget_get_width, 1},
    {"R_gtk_widget_grab_focus", (DL_FUNC) &R_gtk_widget_grab_focus, 1},
    {"R_gtk_widget_has_css_class", (DL_FUNC) &R_gtk_widget_has_css_class, 2},
    {"R_gtk_widget_has_default", (DL_FUNC) &R_gtk_widget_has_default, 1},
    {"R_gtk_widget_has_focus", (DL_FUNC) &R_gtk_widget_has_focus, 1},
    {"R_gtk_widget_has_visible_focus", (DL_FUNC) &R_gtk_widget_has_visible_focus, 1},
    {"R_gtk_widget_hide", (DL_FUNC) &R_gtk_widget_hide, 1},
    {"R_gtk_widget_in_destruction", (DL_FUNC) &R_gtk_widget_in_destruction, 1},
    {"R_gtk_widget_init_template", (DL_FUNC) &R_gtk_widget_init_template, 1},
    {"R_gtk_widget_insert_action_group", (DL_FUNC) &R_gtk_widget_insert_action_group, 3},
    {"R_gtk_widget_insert_after", (DL_FUNC) &R_gtk_widget_insert_after, 3},
    {"R_gtk_widget_insert_before", (DL_FUNC) &R_gtk_widget_insert_before, 3},
    {"R_gtk_widget_is_ancestor", (DL_FUNC) &R_gtk_widget_is_ancestor, 2},
    {"R_gtk_widget_is_drawable", (DL_FUNC) &R_gtk_widget_is_drawable, 1},
    {"R_gtk_widget_is_focus", (DL_FUNC) &R_gtk_widget_is_focus, 1},
    {"R_gtk_widget_is_sensitive", (DL_FUNC) &R_gtk_widget_is_sensitive, 1},
    {"R_gtk_widget_is_visible", (DL_FUNC) &R_gtk_widget_is_visible, 1},
    {"R_gtk_widget_keynav_failed", (DL_FUNC) &R_gtk_widget_keynav_failed, 2},
    {"R_gtk_widget_list_mnemonic_labels", (DL_FUNC) &R_gtk_widget_list_mnemonic_labels, 1},
    {"R_gtk_widget_map", (DL_FUNC) &R_gtk_widget_map, 1},
    {"R_gtk_widget_measure", (DL_FUNC) &R_gtk_widget_measure, 3},
    {"R_gtk_widget_mnemonic_activate", (DL_FUNC) &R_gtk_widget_mnemonic_activate, 2},
    {"R_gtk_widget_observe_children", (DL_FUNC) &R_gtk_widget_observe_children, 1},
    {"R_gtk_widget_observe_controllers", (DL_FUNC) &R_gtk_widget_observe_controllers, 1},
    {"R_gtk_widget_pick", (DL_FUNC) &R_gtk_widget_pick, 4},
    {"R_gtk_widget_queue_allocate", (DL_FUNC) &R_gtk_widget_queue_allocate, 1},
    {"R_gtk_widget_queue_draw", (DL_FUNC) &R_gtk_widget_queue_draw, 1},
    {"R_gtk_widget_queue_resize", (DL_FUNC) &R_gtk_widget_queue_resize, 1},
    {"R_gtk_widget_realize", (DL_FUNC) &R_gtk_widget_realize, 1},
    {"R_gtk_widget_remove_controller", (DL_FUNC) &R_gtk_widget_remove_controller, 2},
    {"R_gtk_widget_remove_css_class", (DL_FUNC) &R_gtk_widget_remove_css_class, 2},
    {"R_gtk_widget_remove_mnemonic_label", (DL_FUNC) &R_gtk_widget_remove_mnemonic_label, 2},
    {"R_gtk_widget_remove_tick_callback", (DL_FUNC) &R_gtk_widget_remove_tick_callback, 2},
    {"R_gtk_widget_set_can_focus", (DL_FUNC) &R_gtk_widget_set_can_focus, 2},
    {"R_gtk_widget_set_can_target", (DL_FUNC) &R_gtk_widget_set_can_target, 2},
    {"R_gtk_widget_set_child_visible", (DL_FUNC) &R_gtk_widget_set_child_visible, 2},
    {"R_gtk_widget_set_css_classes", (DL_FUNC) &R_gtk_widget_set_css_classes, 2},
    {"R_gtk_widget_set_cursor", (DL_FUNC) &R_gtk_widget_set_cursor, 2},
    {"R_gtk_widget_set_cursor_from_name", (DL_FUNC) &R_gtk_widget_set_cursor_from_name, 2},
    {"R_gtk_widget_set_direction", (DL_FUNC) &R_gtk_widget_set_direction, 2},
    {"R_gtk_widget_set_focus_child", (DL_FUNC) &R_gtk_widget_set_focus_child, 2},
    {"R_gtk_widget_set_focus_on_click", (DL_FUNC) &R_gtk_widget_set_focus_on_click, 2},
    {"R_gtk_widget_set_focusable", (DL_FUNC) &R_gtk_widget_set_focusable, 2},
    {"R_gtk_widget_set_font_map", (DL_FUNC) &R_gtk_widget_set_font_map, 2},
    {"R_gtk_widget_set_font_options", (DL_FUNC) &R_gtk_widget_set_font_options, 2},
    {"R_gtk_widget_set_halign", (DL_FUNC) &R_gtk_widget_set_halign, 2},
    {"R_gtk_widget_set_has_tooltip", (DL_FUNC) &R_gtk_widget_set_has_tooltip, 2},
    {"R_gtk_widget_set_hexpand", (DL_FUNC) &R_gtk_widget_set_hexpand, 2},
    {"R_gtk_widget_set_hexpand_set", (DL_FUNC) &R_gtk_widget_set_hexpand_set, 2},
    {"R_gtk_widget_set_layout_manager", (DL_FUNC) &R_gtk_widget_set_layout_manager, 2},
    {"R_gtk_widget_set_margin_bottom", (DL_FUNC) &R_gtk_widget_set_margin_bottom, 2},
    {"R_gtk_widget_set_margin_end", (DL_FUNC) &R_gtk_widget_set_margin_end, 2},
    {"R_gtk_widget_set_margin_start", (DL_FUNC) &R_gtk_widget_set_margin_start, 2},
    {"R_gtk_widget_set_margin_top", (DL_FUNC) &R_gtk_widget_set_margin_top, 2},
    {"R_gtk_widget_set_name", (DL_FUNC) &R_gtk_widget_set_name, 2},
    {"R_gtk_widget_set_opacity", (DL_FUNC) &R_gtk_widget_set_opacity, 2},
    {"R_gtk_widget_set_overflow", (DL_FUNC) &R_gtk_widget_set_overflow, 2},
    {"R_gtk_widget_set_parent", (DL_FUNC) &R_gtk_widget_set_parent, 2},
    {"R_gtk_widget_set_receives_default", (DL_FUNC) &R_gtk_widget_set_receives_default, 2},
    {"R_gtk_widget_set_sensitive", (DL_FUNC) &R_gtk_widget_set_sensitive, 2},
    {"R_gtk_widget_set_size_request", (DL_FUNC) &R_gtk_widget_set_size_request, 3},
    {"R_gtk_widget_set_state_flags", (DL_FUNC) &R_gtk_widget_set_state_flags, 3},
    {"R_gtk_widget_set_tooltip_markup", (DL_FUNC) &R_gtk_widget_set_tooltip_markup, 2},
    {"R_gtk_widget_set_tooltip_text", (DL_FUNC) &R_gtk_widget_set_tooltip_text, 2},
    {"R_gtk_widget_set_valign", (DL_FUNC) &R_gtk_widget_set_valign, 2},
    {"R_gtk_widget_set_vexpand", (DL_FUNC) &R_gtk_widget_set_vexpand, 2},
    {"R_gtk_widget_set_vexpand_set", (DL_FUNC) &R_gtk_widget_set_vexpand_set, 2},
    {"R_gtk_widget_set_visible", (DL_FUNC) &R_gtk_widget_set_visible, 2},
    {"R_gtk_widget_should_layout", (DL_FUNC) &R_gtk_widget_should_layout, 1},
    {"R_gtk_widget_show", (DL_FUNC) &R_gtk_widget_show, 1},
    {"R_gtk_widget_size_allocate", (DL_FUNC) &R_gtk_widget_size_allocate, 3},
    {"R_gtk_widget_snapshot_child", (DL_FUNC) &R_gtk_widget_snapshot_child, 3},
    {"R_gtk_widget_translate_coordinates", (DL_FUNC) &R_gtk_widget_translate_coordinates, 4},
    {"R_gtk_widget_trigger_tooltip_query", (DL_FUNC) &R_gtk_widget_trigger_tooltip_query, 1},
    {"R_gtk_widget_unmap", (DL_FUNC) &R_gtk_widget_unmap, 1},
    {"R_gtk_widget_unparent", (DL_FUNC) &R_gtk_widget_unparent, 1},
    {"R_gtk_widget_unrealize", (DL_FUNC) &R_gtk_widget_unrealize, 1},
    {"R_gtk_widget_unset_state_flags", (DL_FUNC) &R_gtk_widget_unset_state_flags, 2},
    {"R_gtk_widget_class_add_shortcut", (DL_FUNC) &R_gtk_widget_class_add_shortcut, 2},
    {"R_gtk_widget_class_bind_template_callback_full", (DL_FUNC) &R_gtk_widget_class_bind_template_callback_full, 3},
    {"R_gtk_widget_class_bind_template_child_full", (DL_FUNC) &R_gtk_widget_class_bind_template_child_full, 4},
    {"R_gtk_widget_class_get_accessible_role", (DL_FUNC) &R_gtk_widget_class_get_accessible_role, 1},
    {"R_gtk_widget_class_get_activate_signal", (DL_FUNC) &R_gtk_widget_class_get_activate_signal, 1},
    {"R_gtk_widget_class_get_css_name", (DL_FUNC) &R_gtk_widget_class_get_css_name, 1},
    {"R_gtk_widget_class_get_layout_manager_type", (DL_FUNC) &R_gtk_widget_class_get_layout_manager_type, 1},
    {"R_gtk_widget_class_install_action", (DL_FUNC) &R_gtk_widget_class_install_action, 4},
    {"R_gtk_widget_class_install_property_action", (DL_FUNC) &R_gtk_widget_class_install_property_action, 3},
    {"R_gtk_widget_class_query_action", (DL_FUNC) &R_gtk_widget_class_query_action, 2},
    {"R_gtk_widget_class_set_accessible_role", (DL_FUNC) &R_gtk_widget_class_set_accessible_role, 2},
    {"R_gtk_widget_class_set_activate_signal", (DL_FUNC) &R_gtk_widget_class_set_activate_signal, 2},
    {"R_gtk_widget_class_set_activate_signal_from_name", (DL_FUNC) &R_gtk_widget_class_set_activate_signal_from_name, 2},
    {"R_gtk_widget_class_set_css_name", (DL_FUNC) &R_gtk_widget_class_set_css_name, 2},
    {"R_gtk_widget_class_set_layout_manager_type", (DL_FUNC) &R_gtk_widget_class_set_layout_manager_type, 2},
    {"R_gtk_widget_class_set_template", (DL_FUNC) &R_gtk_widget_class_set_template, 2},
    {"R_gtk_widget_class_set_template_from_resource", (DL_FUNC) &R_gtk_widget_class_set_template_from_resource, 2},
    {"R_gtk_widget_class_set_template_scope", (DL_FUNC) &R_gtk_widget_class_set_template_scope, 2},
    {"R_gtk_widget_paintable_new", (DL_FUNC) &R_gtk_widget_paintable_new, 1},
    {"R_gtk_widget_paintable_get_widget", (DL_FUNC) &R_gtk_widget_paintable_get_widget, 1},
    {"R_gtk_widget_paintable_set_widget", (DL_FUNC) &R_gtk_widget_paintable_set_widget, 2},
    {"R_gtk_window_new", (DL_FUNC) &R_gtk_window_new, 0},
    {"R_gtk_window_get_default_icon_name", (DL_FUNC) &R_gtk_window_get_default_icon_name, 0},
    {"R_gtk_window_get_toplevels", (DL_FUNC) &R_gtk_window_get_toplevels, 0},
    {"R_gtk_window_list_toplevels", (DL_FUNC) &R_gtk_window_list_toplevels, 0},
    {"R_gtk_window_set_auto_startup_notification", (DL_FUNC) &R_gtk_window_set_auto_startup_notification, 1},
    {"R_gtk_window_set_default_icon_name", (DL_FUNC) &R_gtk_window_set_default_icon_name, 1},
    {"R_gtk_window_set_interactive_debugging", (DL_FUNC) &R_gtk_window_set_interactive_debugging, 1},
    {"R_gtk_window_close", (DL_FUNC) &R_gtk_window_close, 1},
    {"R_gtk_window_destroy", (DL_FUNC) &R_gtk_window_destroy, 1},
    {"R_gtk_window_fullscreen", (DL_FUNC) &R_gtk_window_fullscreen, 1},
    {"R_gtk_window_fullscreen_on_monitor", (DL_FUNC) &R_gtk_window_fullscreen_on_monitor, 2},
    {"R_gtk_window_get_application", (DL_FUNC) &R_gtk_window_get_application, 1},
    {"R_gtk_window_get_child", (DL_FUNC) &R_gtk_window_get_child, 1},
    {"R_gtk_window_get_decorated", (DL_FUNC) &R_gtk_window_get_decorated, 1},
    {"R_gtk_window_get_default_size", (DL_FUNC) &R_gtk_window_get_default_size, 1},
    {"R_gtk_window_get_default_widget", (DL_FUNC) &R_gtk_window_get_default_widget, 1},
    {"R_gtk_window_get_deletable", (DL_FUNC) &R_gtk_window_get_deletable, 1},
    {"R_gtk_window_get_destroy_with_parent", (DL_FUNC) &R_gtk_window_get_destroy_with_parent, 1},
    {"R_gtk_window_get_focus", (DL_FUNC) &R_gtk_window_get_focus, 1},
    {"R_gtk_window_get_focus_visible", (DL_FUNC) &R_gtk_window_get_focus_visible, 1},
    {"R_gtk_window_get_group", (DL_FUNC) &R_gtk_window_get_group, 1},
    {"R_gtk_window_get_handle_menubar_accel", (DL_FUNC) &R_gtk_window_get_handle_menubar_accel, 1},
    {"R_gtk_window_get_hide_on_close", (DL_FUNC) &R_gtk_window_get_hide_on_close, 1},
    {"R_gtk_window_get_icon_name", (DL_FUNC) &R_gtk_window_get_icon_name, 1},
    {"R_gtk_window_get_mnemonics_visible", (DL_FUNC) &R_gtk_window_get_mnemonics_visible, 1},
    {"R_gtk_window_get_modal", (DL_FUNC) &R_gtk_window_get_modal, 1},
    {"R_gtk_window_get_resizable", (DL_FUNC) &R_gtk_window_get_resizable, 1},
    {"R_gtk_window_get_title", (DL_FUNC) &R_gtk_window_get_title, 1},
    {"R_gtk_window_get_titlebar", (DL_FUNC) &R_gtk_window_get_titlebar, 1},
    {"R_gtk_window_get_transient_for", (DL_FUNC) &R_gtk_window_get_transient_for, 1},
    {"R_gtk_window_has_group", (DL_FUNC) &R_gtk_window_has_group, 1},
    {"R_gtk_window_is_active", (DL_FUNC) &R_gtk_window_is_active, 1},
    {"R_gtk_window_is_fullscreen", (DL_FUNC) &R_gtk_window_is_fullscreen, 1},
    {"R_gtk_window_is_maximized", (DL_FUNC) &R_gtk_window_is_maximized, 1},
    {"R_gtk_window_is_suspended", (DL_FUNC) &R_gtk_window_is_suspended, 1},
    {"R_gtk_window_maximize", (DL_FUNC) &R_gtk_window_maximize, 1},
    {"R_gtk_window_minimize", (DL_FUNC) &R_gtk_window_minimize, 1},
    {"R_gtk_window_present", (DL_FUNC) &R_gtk_window_present, 1},
    {"R_gtk_window_present_with_time", (DL_FUNC) &R_gtk_window_present_with_time, 2},
    {"R_gtk_window_set_application", (DL_FUNC) &R_gtk_window_set_application, 2},
    {"R_gtk_window_set_child", (DL_FUNC) &R_gtk_window_set_child, 2},
    {"R_gtk_window_set_decorated", (DL_FUNC) &R_gtk_window_set_decorated, 2},
    {"R_gtk_window_set_default_size", (DL_FUNC) &R_gtk_window_set_default_size, 3},
    {"R_gtk_window_set_default_widget", (DL_FUNC) &R_gtk_window_set_default_widget, 2},
    {"R_gtk_window_set_deletable", (DL_FUNC) &R_gtk_window_set_deletable, 2},
    {"R_gtk_window_set_destroy_with_parent", (DL_FUNC) &R_gtk_window_set_destroy_with_parent, 2},
    {"R_gtk_window_set_display", (DL_FUNC) &R_gtk_window_set_display, 2},
    {"R_gtk_window_set_focus", (DL_FUNC) &R_gtk_window_set_focus, 2},
    {"R_gtk_window_set_focus_visible", (DL_FUNC) &R_gtk_window_set_focus_visible, 2},
    {"R_gtk_window_set_handle_menubar_accel", (DL_FUNC) &R_gtk_window_set_handle_menubar_accel, 2},
    {"R_gtk_window_set_hide_on_close", (DL_FUNC) &R_gtk_window_set_hide_on_close, 2},
    {"R_gtk_window_set_icon_name", (DL_FUNC) &R_gtk_window_set_icon_name, 2},
    {"R_gtk_window_set_mnemonics_visible", (DL_FUNC) &R_gtk_window_set_mnemonics_visible, 2},
    {"R_gtk_window_set_modal", (DL_FUNC) &R_gtk_window_set_modal, 2},
    {"R_gtk_window_set_resizable", (DL_FUNC) &R_gtk_window_set_resizable, 2},
    {"R_gtk_window_set_startup_id", (DL_FUNC) &R_gtk_window_set_startup_id, 2},
    {"R_gtk_window_set_title", (DL_FUNC) &R_gtk_window_set_title, 2},
    {"R_gtk_window_set_titlebar", (DL_FUNC) &R_gtk_window_set_titlebar, 2},
    {"R_gtk_window_set_transient_for", (DL_FUNC) &R_gtk_window_set_transient_for, 2},
    {"R_gtk_window_unfullscreen", (DL_FUNC) &R_gtk_window_unfullscreen, 1},
    {"R_gtk_window_unmaximize", (DL_FUNC) &R_gtk_window_unmaximize, 1},
    {"R_gtk_window_unminimize", (DL_FUNC) &R_gtk_window_unminimize, 1},
    {"R_gtk_window_controls_new", (DL_FUNC) &R_gtk_window_controls_new, 1},
    {"R_gtk_window_controls_get_decoration_layout", (DL_FUNC) &R_gtk_window_controls_get_decoration_layout, 1},
    {"R_gtk_window_controls_get_empty", (DL_FUNC) &R_gtk_window_controls_get_empty, 1},
    {"R_gtk_window_controls_get_side", (DL_FUNC) &R_gtk_window_controls_get_side, 1},
    {"R_gtk_window_controls_set_decoration_layout", (DL_FUNC) &R_gtk_window_controls_set_decoration_layout, 2},
    {"R_gtk_window_controls_set_side", (DL_FUNC) &R_gtk_window_controls_set_side, 2},
    {"R_gtk_window_group_new", (DL_FUNC) &R_gtk_window_group_new, 0},
    {"R_gtk_window_group_add_window", (DL_FUNC) &R_gtk_window_group_add_window, 2},
    {"R_gtk_window_group_list_windows", (DL_FUNC) &R_gtk_window_group_list_windows, 1},
    {"R_gtk_window_group_remove_window", (DL_FUNC) &R_gtk_window_group_remove_window, 2},
    {"R_gtk_window_handle_new", (DL_FUNC) &R_gtk_window_handle_new, 0},
    {"R_gtk_window_handle_get_child", (DL_FUNC) &R_gtk_window_handle_get_child, 1},
    {"R_gtk_window_handle_set_child", (DL_FUNC) &R_gtk_window_handle_set_child, 2},
    {"R_gtk_accelerator_get_default_mod_mask", (DL_FUNC) &R_gtk_accelerator_get_default_mod_mask, 0},
    {"R_gtk_accelerator_get_label", (DL_FUNC) &R_gtk_accelerator_get_label, 2},
    {"R_gtk_accelerator_get_label_with_keycode", (DL_FUNC) &R_gtk_accelerator_get_label_with_keycode, 4},
    {"R_gtk_accelerator_name", (DL_FUNC) &R_gtk_accelerator_name, 2},
    {"R_gtk_accelerator_name_with_keycode", (DL_FUNC) &R_gtk_accelerator_name_with_keycode, 4},
    {"R_gtk_accelerator_parse", (DL_FUNC) &R_gtk_accelerator_parse, 1},
    {"R_gtk_accelerator_parse_with_keycode", (DL_FUNC) &R_gtk_accelerator_parse_with_keycode, 2},
    {"R_gtk_accelerator_valid", (DL_FUNC) &R_gtk_accelerator_valid, 2},
    {"R_gtk_check_version", (DL_FUNC) &R_gtk_check_version, 3},
    {"R_gtk_css_parser_error_quark", (DL_FUNC) &R_gtk_css_parser_error_quark, 0},
    {"R_gtk_css_parser_warning_quark", (DL_FUNC) &R_gtk_css_parser_warning_quark, 0},
    {"R_gtk_disable_setlocale", (DL_FUNC) &R_gtk_disable_setlocale, 0},
    {"R_gtk_distribute_natural_allocation", (DL_FUNC) &R_gtk_distribute_natural_allocation, 3},
    {"R_gtk_get_binary_age", (DL_FUNC) &R_gtk_get_binary_age, 0},
    {"R_gtk_get_debug_flags", (DL_FUNC) &R_gtk_get_debug_flags, 0},
    {"R_gtk_get_default_language", (DL_FUNC) &R_gtk_get_default_language, 0},
    {"R_gtk_get_interface_age", (DL_FUNC) &R_gtk_get_interface_age, 0},
    {"R_gtk_get_locale_direction", (DL_FUNC) &R_gtk_get_locale_direction, 0},
    {"R_gtk_get_major_version", (DL_FUNC) &R_gtk_get_major_version, 0},
    {"R_gtk_get_micro_version", (DL_FUNC) &R_gtk_get_micro_version, 0},
    {"R_gtk_get_minor_version", (DL_FUNC) &R_gtk_get_minor_version, 0},
    {"R_gtk_hsv_to_rgb", (DL_FUNC) &R_gtk_hsv_to_rgb, 3},
    {"R_gtk_init", (DL_FUNC) &R_gtk_init, 0},
    {"R_gtk_init_check", (DL_FUNC) &R_gtk_init_check, 0},
    {"R_gtk_is_initialized", (DL_FUNC) &R_gtk_is_initialized, 0},
    {"R_gtk_param_spec_expression", (DL_FUNC) &R_gtk_param_spec_expression, 4},
    {"R_gtk_render_activity", (DL_FUNC) &R_gtk_render_activity, 6},
    {"R_gtk_render_arrow", (DL_FUNC) &R_gtk_render_arrow, 6},
    {"R_gtk_render_background", (DL_FUNC) &R_gtk_render_background, 6},
    {"R_gtk_render_check", (DL_FUNC) &R_gtk_render_check, 6},
    {"R_gtk_render_expander", (DL_FUNC) &R_gtk_render_expander, 6},
    {"R_gtk_render_focus", (DL_FUNC) &R_gtk_render_focus, 6},
    {"R_gtk_render_frame", (DL_FUNC) &R_gtk_render_frame, 6},
    {"R_gtk_render_handle", (DL_FUNC) &R_gtk_render_handle, 6},
    {"R_gtk_render_icon", (DL_FUNC) &R_gtk_render_icon, 5},
    {"R_gtk_render_layout", (DL_FUNC) &R_gtk_render_layout, 5},
    {"R_gtk_render_line", (DL_FUNC) &R_gtk_render_line, 6},
    {"R_gtk_render_option", (DL_FUNC) &R_gtk_render_option, 6},
    {"R_gtk_rgb_to_hsv", (DL_FUNC) &R_gtk_rgb_to_hsv, 3},
    {"R_gtk_set_debug_flags", (DL_FUNC) &R_gtk_set_debug_flags, 1},
    {"R_gtk_show_uri", (DL_FUNC) &R_gtk_show_uri, 3},
    {"R_gtk_show_uri_full", (DL_FUNC) &R_gtk_show_uri_full, 6},
    {"R_gtk_show_uri_full_finish", (DL_FUNC) &R_gtk_show_uri_full_finish, 2},
    {"R_gtk_test_accessible_assertion_message_role", (DL_FUNC) &R_gtk_test_accessible_assertion_message_role, 8},
    {"R_gtk_test_accessible_has_property", (DL_FUNC) &R_gtk_test_accessible_has_property, 2},
    {"R_gtk_test_accessible_has_relation", (DL_FUNC) &R_gtk_test_accessible_has_relation, 2},
    {"R_gtk_test_accessible_has_role", (DL_FUNC) &R_gtk_test_accessible_has_role, 2},
    {"R_gtk_test_accessible_has_state", (DL_FUNC) &R_gtk_test_accessible_has_state, 2},
    {"R_gtk_test_list_all_types", (DL_FUNC) &R_gtk_test_list_all_types, 0},
    {"R_gtk_test_register_all_types", (DL_FUNC) &R_gtk_test_register_all_types, 0},
    {"R_gtk_test_widget_wait_for_draw", (DL_FUNC) &R_gtk_test_widget_wait_for_draw, 1},
    {"R_gtk_tree_create_row_drag_content", (DL_FUNC) &R_gtk_tree_create_row_drag_content, 2},
    {"R_gtk_tree_get_row_drag_data", (DL_FUNC) &R_gtk_tree_get_row_drag_data, 1},
    {"R_gtk_value_dup_expression", (DL_FUNC) &R_gtk_value_dup_expression, 1},
    {"R_gtk_value_get_expression", (DL_FUNC) &R_gtk_value_get_expression, 1},
    {"R_gtk_value_set_expression", (DL_FUNC) &R_gtk_value_set_expression, 2},
    {"R_gtk_value_take_expression", (DL_FUNC) &R_gtk_value_take_expression, 2},
    {"R_g_timeout_add", (DL_FUNC) &R_g_timeout_add, 2},
    {"R_g_idle_add", (DL_FUNC) &R_g_idle_add, 1},
    {"R_gtk_dialog_run", (DL_FUNC) &R_gtk_dialog_run, 1},
    {"R_gtk_file_chooser_dialog_run", (DL_FUNC) &R_gtk_file_chooser_dialog_run, 3},
    {"R_gtk_start_event_loop", (DL_FUNC) &R_gtk_start_event_loop, 0},
    {"R_gtk_stop_event_loop", (DL_FUNC) &R_gtk_stop_event_loop, 0},
    {"R_gtk_force_foreground", (DL_FUNC) &R_gtk_force_foreground, 0},
    {"R_gtk_hide_from_dock", (DL_FUNC) &R_gtk_hide_from_dock, 0},
    {"R_gtk_window_track", (DL_FUNC) &R_gtk_window_track, 1},
    {"R_gtk_main_iteration", (DL_FUNC) &R_gtk_main_iteration, 0},
    {"R_gtk_main_iteration_do", (DL_FUNC) &R_gtk_main_iteration_do, 1},
    {"R_macos_set_app_icon", (DL_FUNC) &R_macos_set_app_icon, 1},
    {"R_extptr_address", (DL_FUNC) &R_extptr_address, 1},
    {"R_gtk_window_add_close_shortcut", (DL_FUNC) &R_gtk_window_add_close_shortcut, 1},
    {"R_gtk_get_ui_state", (DL_FUNC) &R_gtk_get_ui_state, 1},
    {"R_gtk_string_list_new_from_vector", (DL_FUNC) &R_gtk_string_list_new_from_vector, 1},
    {"R_gtk_text_buffer_create_tag_simple", (DL_FUNC) &R_gtk_text_buffer_create_tag_simple, 2},
    {"R_g_object_set_string", (DL_FUNC) &R_g_object_set_string, 3},
    {"R_gtk_message_dialog_new_safe", (DL_FUNC) &R_gtk_message_dialog_new_safe, 5},
    {"R_g_signal_connect_r", (DL_FUNC) &R_g_signal_connect_r, 3},
    {"R_g_signal_connect_r_boolean", (DL_FUNC) &R_g_signal_connect_r_boolean, 3},
    {NULL, NULL, 0}
};

void R_init_Rgtk4(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
