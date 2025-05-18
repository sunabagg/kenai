#ifndef TAB_CONTAINER_H
#define TAB_CONTAINER_H

#include <godot_cpp/classes/tab_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define TabContainerNode godot::TabContainer

#include "container.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"
#include "tab_bar.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTabContainer(sol::state &lua);

    class TabContainer;

    class TabContainerProxy : public TabContainerNode {
        public:
            sunaba::ui::TabContainer* element = nullptr;

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

        private:
            sunaba::ui::TabBar* tab_bar = nullptr;
    };

    class TabContainer : public Container {
        private:
            TabContainerNode* container = nullptr; // Pointer to the TabContainer instance

            void connectContainerSignals() {
                // Connect signals from the container to the element
                // Example: container->connect("signal_name", this, "method_name");
            }
        public:
            TabContainer() {
                setTabContainer(memnew(TabContainerProxy));
                onInit();
            }

            TabContainer(TabContainerNode* container) {
                setTabContainer(container);
            }

            TabContainerNode* getContainer() {
                return container;
            }

            void setTabContainer(TabContainerNode* container) {
                this->container = container;
                connectContainerSignals();
                setContainer(container);
            }
            
            void setTabContainer(TabContainerProxy* container) {
                this->container = container;
                container->element = this;
                connectContainerSignals();
                setContainer(container);
            }

            bool getAllTabsInFront() {
                return container->is_all_tabs_in_front();
            }

            void setAllTabsInFront(bool is_front) {
                container->set_all_tabs_in_front(is_front);
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

            int getTabAlignment() {
                return container->get_tab_alignment();
            }

            void setTabAlignment(int alignment) {
                container->set_tab_alignment(static_cast<godot::TabBar::AlignmentMode>(alignment));
            }

            int getTabFocusMode() {
                return container->get_tab_focus_mode();
            }

            void setTabFocusMode(int mode) {
                container->set_tab_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            int getTabsPosition() {
                return container->get_tabs_position();
            }

            void setTabsPosition(int position) {
                container->set_tabs_position(static_cast<godot::TabContainer::TabPosition>(position));
            }

            int getTabsRearrangeGroup() {
                return container->get_tabs_rearrange_group();
            }

            void setTabsRearrangeGroup(int group) {
                container->set_tabs_rearrange_group(group);
            }

            bool getTabsVisible() {
                return container->are_tabs_visible();
            }

            void setTabsVisible(bool visible) {
                container->set_tabs_visible(visible);
            }

            bool getUseHiddenTabsForMinSize() {
                return container->get_use_hidden_tabs_for_min_size();
            }

            void setUseHiddenTabsForMinSize(bool enabled) {
                container->set_use_hidden_tabs_for_min_size(enabled);
            }

            Event* activeTabRearrangedEvent;
            Event* getActiveTabRearrangedEvent() {
                return activeTabRearrangedEvent;
            }
            void setActiveTabRearrangedEvent(Event* event) {
                activeTabRearrangedEvent = event;
            }

            Event* prePopupPressedEvent;
            Event* getPrePopupPressedEvent() {
                return prePopupPressedEvent;
            }
            void setPrePopupPressedEvent(Event* event) {
                prePopupPressedEvent = event;
            }

            Event* tabButtonPressedEvent;
            Event* getTabButtonPressedEvent() {
                return tabButtonPressedEvent;
            }
            void setTabButtonPressedEvent(Event* event) {
                tabButtonPressedEvent = event;
            }

            Event* tabChangedEvent;
            Event* getTabChangedEvent() {
                return tabChangedEvent;
            }
            void setTabChangedEvent(Event* event) {
                tabChangedEvent = event;
            }

            Event* tabClickedEvent;
            Event* getTabClickedEvent() {
                return tabClickedEvent;
            }
            void setTabClickedEvent(Event* event) {
                tabClickedEvent = event;
            }

            Event* tabHoveredEvent;
            Event* getTabHoveredEvent() {
                return tabHoveredEvent;
            }
            void setTabHoveredEvent(Event* event) {
                tabHoveredEvent = event;
            }

            Event* tabSelectedEvent;
            Event* getTabSelectedEvent() {
                return tabSelectedEvent;
            }
            void setTabSelectedEvent(Event* event) {
                tabSelectedEvent = event;
            }

            Control* getCurrentTabControl() {
                return new Control(container->get_current_tab_control());
            }
    };
}

#endif // !TAB_CONTAINER_H
