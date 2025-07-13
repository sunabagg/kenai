// Copied from godot-cpp/test/src and modified.

#include "gdextension_interface.h"

#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/defs.hpp"
#include "godot_cpp/godot.hpp"

#include "core/scene_node.h"
#include "core/event.h"
#include "core/stl_function_wrapper.h"
#include "core/base_object_proxy.h"
#include "tests/scene_test.h"
#include "app.h"

#include "core/element.h"
#include "core/canvas_item.h"
#include "core/viewport.h"

#include "core/io/moon_console.h"

#include "desktop/window.h"
#include "desktop/popup.h"
#include "desktop/popup_menu.h"
#include "desktop/popup_panel.h"
#include "desktop/accept_dialog.h"
#include "desktop/file_dialog.h"
#include "desktop/status_indicator.h"

#include "input/input_service.h"

#include "ui/control.h"
#include "ui/base_button.h"
#include "ui/container.h"
#include "ui/item_list.h"
#include "ui/line_edit.h"
#include "ui/menu_button.h"
#include "ui/option_button.h"
#include "ui/range.h"
#include "ui/slider.h"
#include "ui/tab_bar.h"
#include "ui/tab_container.h"
#include "ui/text_edit.h"
#include "ui/code_edit.h"
#include "ui/tree.h"
#include "ui/rich_text_label.h"
#include "ui/aspect_ratio_container.h"
#include "ui/box_container.h"
#include "ui/button.h"
#include "ui/center_container.h"
#include "ui/check_box.h"
#include "ui/check_button.h"
#include "ui/color_rect.h"
#include "ui/flow_container.h"
#include "ui/grid_container.h"
#include "ui/h_box_container.h"
#include "ui/h_flow_container.h"
#include "ui/h_scroll_bar.h"
#include "ui/h_separator.h"
#include "ui/h_slider.h"
#include "ui/h_split_container.h"
#include "ui/label.h"
#include "ui/link_button.h"
#include "ui/margin_container.h"
#include "ui/menu_bar.h"
#include "ui/menu_button.h"
#include "ui/nine_patch_rect.h"
#include "ui/panel_container.h"
#include "ui/panel.h"
#include "ui/progress_bar.h"
#include "ui/reference_rect.h"
#include "ui/scroll_bar.h"
#include "ui/scroll_container.h"
#include "ui/separator.h"
#include "ui/spin_box.h"
#include "ui/split_container.h"
#include "ui/sub_viewport_container.h"
#include "ui/texture_button.h"
#include "ui/texture_progress_bar.h"
#include "ui/texture_rect.h"
#include "ui/v_box_container.h"
#include "ui/v_flow_container.h"
#include "ui/v_scroll_bar.h"
#include "ui/v_separator.h"
#include "ui/v_slider.h"
#include "ui/v_split_container.h"

/// @file
/// Register our classes with Godot.

namespace
{
    /// @brief Called by Godot to let us register our classes with Godot.
    ///
    /// @param p_level the level being initialized by Godot
    ///
    /// @see GDExtensionInit
    void initializeExtension( godot::ModuleInitializationLevel p_level )
    {
        if ( p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE )
        {
            return;
        }

        godot::ClassDB::register_class<sunaba::App>();
        godot::ClassDB::register_class<sunaba::tests::SceneTest>();
        godot::ClassDB::register_class<sunaba::core::SceneNode>();
        godot::ClassDB::register_class<sunaba::core::NodeProxy>();
        //godot::ClassDB::register_class<sunaba::core::EventBridge>();
        godot::ClassDB::register_class<sunaba::core::BaseObjectProxy>();
        godot::ClassDB::register_class<sunaba::core::StlFunctionWrapper>();

        godot::ClassDB::register_class<sunaba::core::NodeSignalWrapper>();
        godot::ClassDB::register_class<sunaba::core::CanvasItemSignalWrapper>();
        godot::ClassDB::register_class<sunaba::core::ViewportSignalWrapper>();

        godot::ClassDB::register_class<sunaba::desktop::WindowSignalWrapper>();
        godot::ClassDB::register_class<sunaba::desktop::PopupSignalWrapper>();
        godot::ClassDB::register_class<sunaba::desktop::PopupMenuSignalWrapper>();
        godot::ClassDB::register_class<sunaba::desktop::AcceptDialogSignalWrapper>();
        godot::ClassDB::register_class<sunaba::desktop::FileDialogSignalWrapper>();
        godot::ClassDB::register_class<sunaba::desktop::StatusIndicatorSignalWrapper>();

        godot::ClassDB::register_class<sunaba::input::InputServiceSignalWrapper>();

        godot::ClassDB::register_class<sunaba::ui::ControlSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::BaseButtonSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::ContainerSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::ItemListSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::LineEditSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::MenuButtonSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::OptionButtonSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::RangeSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::SliderSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::TabBarSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::TabContainerSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::TextEditSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::CodeEditSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::TreeSignalWrapper>();
        godot::ClassDB::register_class<sunaba::ui::RichTextLabelSignalWrapper>();

        godot::ClassDB::register_class<sunaba::core::io::MoonConsole>();
    }

    /// @brief Called by Godot to let us do any cleanup.
    ///
    /// @see GDExtensionInit
    void uninitializeExtension( godot::ModuleInitializationLevel p_level )
    {
        if ( p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE )
        {
            return;
        }
    }
}

extern "C"
{
    /// @brief This is the entry point for the shared library.
    ///
    /// @note The name of this function must match the "entry_symbol" in
    /// templates/template.*.gdextension.in
    ///
    /// @param p_get_proc_address the interface (need more info)
    /// @param p_library the library (need more info)
    /// @param r_initialization the intialization (need more info)
    ///
    /// @returns GDExtensionBool
    GDExtensionBool GDE_EXPORT GDExtensionInit(
        GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library,
        GDExtensionInitialization *r_initialization )
    {
        {
            godot::GDExtensionBinding::InitObject init_obj( p_get_proc_address, p_library,
                                                            r_initialization );

            init_obj.register_initializer( initializeExtension );
            init_obj.register_terminator( uninitializeExtension );
            init_obj.set_minimum_library_initialization_level(
                godot::MODULE_INITIALIZATION_LEVEL_SCENE );

            return init_obj.init();
        }
    }
}
