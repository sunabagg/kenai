#ifndef TAB_BAR_H
#define TAB_BAR_H

#include <godot_cpp/classes/tab_bar.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define TabBarNode godot::TabBar

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTabBar(sol::state &lua);

    class TabBar;

    class TabBarProxy : public TabBarNode {
        public:
            sunaba::ui::TabBar* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override ;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;

            void _draw() override;

            bool _can_drop_data(const Vector2& at_position, const Variant &data) const override;

            void _drop_data(const Vector2 &at_position, const Variant &data) override;

            Variant _get_drag_data(const Vector2 &at_position) override;

            Vector2 _get_minimum_size() const override;

            String _get_tooltip(const Vector2 &at_position) const override;

            void _gui_input(const Ref<InputEvent> &event) override;

            bool _has_point(const Vector2 &point) const override;

            //Object* _make_custom_tooltip(const String &for_text) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
    };

    class TabBar : public Control {
        private:
            TabBarNode* container = nullptr; // Pointer to the TabBar instance
            void connectContainerSignals() {
                // Connect signals specific to TabBar
            }

        public:
            TabBar() {
                setContainer(memnew(TabBarProxy));
                onInit();
            }

            TabBar(TabBarNode* container) {
                setContainer(container);
            }

            TabBarNode* getContainer() {
                return container;
            }

            void setContainer(TabBarNode* container) {
                this->container = container;
                connectContainerSignals();
                setControl(container);
            }

            void setContainer(TabBarProxy* container) {
                this->container = container;
                container->element = this;
                connectContainerSignals();
                setControl(container);
            }

            bool getClipTabs() {
                return container->get_clip_tabs();
            }

            void setClipTabs(bool clip) {
                container->set_clip_tabs(clip);
            }

            int getCurrentTab() {
                return container->get_current_tab();
            }

            void setCurrentTab(int tab) {
                container->set_current_tab(tab);
            }

            bool getDeselectEnabled() {
                return container->get_deselect_enabled();
            }

            void setDeselectEnabled(bool enabled) {
                container->set_deselect_enabled(enabled);
            }

            bool getDragToRearrangeEnabled() {
                return container->get_drag_to_rearrange_enabled();
            }

            void setDragToRearrangeEnabled(bool enabled) {
                container->set_drag_to_rearrange_enabled(enabled);
            }

            int getFocusMode() {
                return container->get_focus_mode();
            }

            void setFocusMode(int mode) {
                container->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            int getMaxTabWidth() {
                return container->get_max_tab_width();
            }

            void setMaxTabWidth(int width) {
                container->set_max_tab_width(width);
            }

            bool getScrollToSelected() {
                return container->get_scroll_to_selected();
            }

            void setScrollToSelected(bool enabled) {
                container->set_scroll_to_selected(enabled);
            }

            bool getScrollingEnabled() {
                return container->get_scrolling_enabled();
            }

            void setScrollingEnabled(bool enabled) {
                container->set_scrolling_enabled(enabled);
            }

            bool getSelectWithRMB() {
                return container->get_select_with_rmb();
            }

            void setSelectWithRMB(bool enabled) {
                container->set_select_with_rmb(enabled);
            }

            int getTabAlignment() {
                return container->get_tab_alignment();
            }

            void setTabAlignment(int alignment) {
                container->set_tab_alignment(static_cast<godot::TabBar::AlignmentMode>(alignment));
            }

            int getTabCloseDisplayPolicy() {
                return container->get_tab_close_display_policy();
            }
    };
}

#endif // TAB_BAR_H