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

        godot::ClassDB::register_class<lucidfx::App>();
        godot::ClassDB::register_class<lucidfx::tests::SceneTest>();
        godot::ClassDB::register_class<lucidfx::core::SceneNode>();
        //godot::ClassDB::register_class<lucidfx::core::EventBridge>();
        godot::ClassDB::register_class<lucidfx::core::BaseObjectProxy>();
        godot::ClassDB::register_class<lucidfx::core::StlFunctionWrapper>();

        godot::ClassDB::register_class<lucidfx::core::NodeSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::core::CanvasItemSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::core::ViewportSignalWrapper>();

        godot::ClassDB::register_class<lucidfx::desktop::WindowSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::desktop::PopupSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::desktop::PopupMenuSignalWrapper>();

        godot::ClassDB::register_class<lucidfx::ui::ControlSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::BaseButtonSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::ContainerSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::ItemListSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::LineEditSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::MenuButtonSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::OptionButtonSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::RangeSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::SliderSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::TabBarSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::TabContainerSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::TextEditSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::CodeEditSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::TreeSignalWrapper>();
        godot::ClassDB::register_class<lucidfx::ui::RichTextLabelSignalWrapper>();

        godot::ClassDB::register_class<lucidfx::core::NodeProxy>();
        //godot::ClassDB::register_class<lucidfx::core::CanvasItemProxy>();
        //godot::ClassDB::register_class<lucidfx::core::ViewportProxy>();

        godot::ClassDB::register_class<lucidfx::desktop::WindowProxy>();
        godot::ClassDB::register_class<lucidfx::desktop::PopupProxy>();
        godot::ClassDB::register_class<lucidfx::desktop::PopupMenuProxy>();
        godot::ClassDB::register_class<lucidfx::desktop::PopupPanelProxy>();

        godot::ClassDB::register_class<lucidfx::ui::ControlProxy>();
        godot::ClassDB::register_class<lucidfx::ui::BaseButtonProxy>();
        godot::ClassDB::register_class<lucidfx::ui::ContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::ItemListProxy>();
        godot::ClassDB::register_class<lucidfx::ui::LineEditProxy>();
        godot::ClassDB::register_class<lucidfx::ui::MenuButtonProxy>();
        godot::ClassDB::register_class<lucidfx::ui::OptionButtonProxy>();
        godot::ClassDB::register_class<lucidfx::ui::RangeProxy>();
        //godot::ClassDB::register_class<lucidfx::ui::SliderProxy>();
        godot::ClassDB::register_class<lucidfx::ui::TabBarProxy>();
        godot::ClassDB::register_class<lucidfx::ui::TabContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::TextEditProxy>();
        godot::ClassDB::register_class<lucidfx::ui::CodeEditProxy>();
        godot::ClassDB::register_class<lucidfx::ui::TreeProxy>();
        godot::ClassDB::register_class<lucidfx::ui::RichTextLabelProxy>();
        godot::ClassDB::register_class<lucidfx::ui::AspectRatioContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::BoxContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::ButtonProxy>();
        godot::ClassDB::register_class<lucidfx::ui::CenterContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::CheckBoxProxy>();
        godot::ClassDB::register_class<lucidfx::ui::CheckButtonProxy>();
        godot::ClassDB::register_class<lucidfx::ui::ColorRectProxy>();
        godot::ClassDB::register_class<lucidfx::ui::FlowContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::GridContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::HBoxContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::HFlowContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::HScrollBarProxy>();
        godot::ClassDB::register_class<lucidfx::ui::HSeparatorProxy>();
        godot::ClassDB::register_class<lucidfx::ui::HSliderProxy>();
        godot::ClassDB::register_class<lucidfx::ui::HSplitContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::LabelProxy>();
        godot::ClassDB::register_class<lucidfx::ui::LinkButtonProxy>();
        godot::ClassDB::register_class<lucidfx::ui::MarginContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::MenuBarProxy>();
        godot::ClassDB::register_class<lucidfx::ui::NinePatchRectProxy>();
        godot::ClassDB::register_class<lucidfx::ui::PanelContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::PanelProxy>();
        godot::ClassDB::register_class<lucidfx::ui::ProgressBarProxy>();
        godot::ClassDB::register_class<lucidfx::ui::ReferenceRectProxy>();
        //godot::ClassDB::register_class<lucidfx::ui::ScrollBarProxy>();
        godot::ClassDB::register_class<lucidfx::ui::ScrollContainerProxy>();
        //godot::ClassDB::register_class<lucidfx::ui::SeparatorProxy>();
        godot::ClassDB::register_class<lucidfx::ui::SpinBoxProxy>();
        godot::ClassDB::register_class<lucidfx::ui::SplitContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::SubViewportContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::TextureButtonProxy>();
        godot::ClassDB::register_class<lucidfx::ui::TextureProgressBarProxy>();
        godot::ClassDB::register_class<lucidfx::ui::TextureRectProxy>();
        godot::ClassDB::register_class<lucidfx::ui::VBoxContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::VFlowContainerProxy>();
        godot::ClassDB::register_class<lucidfx::ui::VScrollBarProxy>();
        godot::ClassDB::register_class<lucidfx::ui::VSeparatorProxy>();
        godot::ClassDB::register_class<lucidfx::ui::VSliderProxy>();
        godot::ClassDB::register_class<lucidfx::ui::VSplitContainerProxy>();
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
