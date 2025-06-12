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

#include "desktop/window.h"
#include "desktop/popup.h"
#include "desktop/popup_menu.h"
#include "desktop/popup_panel.h"

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
        godot::ClassDB::register_class<sunaba::core::EventBridge>();
        godot::ClassDB::register_class<sunaba::core::BaseObjectProxy>();
        godot::ClassDB::register_class<sunaba::core::StlFunctionWrapper>();

        godot::ClassDB::register_class<sunaba::core::NodeSignalWrapper>();
        godot::ClassDB::register_class<sunaba::core::CanvasItemSignalWrapper>();
        godot::ClassDB::register_class<sunaba::core::ViewportSignalWrapper>();

        godot::ClassDB::register_class<sunaba::desktop::WindowSignalWrapper>();
        godot::ClassDB::register_class<sunaba::desktop::PopupSignalWrapper>();
        godot::ClassDB::register_class<sunaba::desktop::PopupMenuSignalWrapper>();

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

        godot::ClassDB::register_class<sunaba::core::NodeProxy>();
        godot::ClassDB::register_class<sunaba::core::CanvasItemProxy>();
        godot::ClassDB::register_class<sunaba::core::ViewportProxy>();

        godot::ClassDB::register_class<sunaba::desktop::WindowProxy>();
        godot::ClassDB::register_class<sunaba::desktop::PopupProxy>();
        godot::ClassDB::register_class<sunaba::desktop::PopupMenuProxy>();
        godot::ClassDB::register_class<sunaba::desktop::PopupPanelProxy>();

        godot::ClassDB::register_class<sunaba::ui::ControlProxy>();
        godot::ClassDB::register_class<sunaba::ui::BaseButtonProxy>();
        godot::ClassDB::register_class<sunaba::ui::ContainerProxy>();
        godot::ClassDB::register_class<sunaba::ui::ItemListProxy>();
        godot::ClassDB::register_class<sunaba::ui::LineEditProxy>();
        godot::ClassDB::register_class<sunaba::ui::MenuButtonProxy>();
        godot::ClassDB::register_class<sunaba::ui::OptionButtonProxy>();
        godot::ClassDB::register_class<sunaba::ui::RangeProxy>();
        godot::ClassDB::register_class<sunaba::ui::SliderProxy>();
        godot::ClassDB::register_class<sunaba::ui::TabBarProxy>();
        godot::ClassDB::register_class<sunaba::ui::TabContainerProxy>();
        godot::ClassDB::register_class<sunaba::ui::TextEditProxy>();
        godot::ClassDB::register_class<sunaba::ui::CodeEditProxy>();
        godot::ClassDB::register_class<sunaba::ui::TreeProxy>();
        godot::ClassDB::register_class<sunaba::ui::RichTextLabelProxy>();
        godot::ClassDB::register_class<sunaba::ui::AspectRatioContainerProxy>();
        godot::ClassDB::register_class<sunaba::ui::BoxContainerProxy>();
        godot::ClassDB::register_class<sunaba::ui::ButtonProxy>();
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
