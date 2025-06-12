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
#include "../desktop/popup.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTabContainer(sol::state &lua);

    class TabContainer;

    class TabContainerProxy : public TabContainerNode {
        GDCLASS(TabContainerProxy, TabContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to TabContainerProxy
            }
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

            PackedInt32Array _get_allowed_size_flags_horizontal() const override;

            PackedInt32Array _get_allowed_size_flags_vertical() const override;
    };

    class TabContainerSignalWrapper : public Object {
        GDCLASS(TabContainerSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            sunaba::ui::TabContainer* element = nullptr;

            TabContainerSignalWrapper() = default;
            ~TabContainerSignalWrapper() = default;

            void active_tab_rearranged(int tab);
            void pre_popup_pressed();
            void tab_button_pressed(int tab);
            void tab_changed(int tab);
            void tab_clicked(int tab);
            void tab_hovered(int tab);
            void tab_selected(int tab);
    };

    class TabContainer : public Container {
        private:
            TabContainerNode* container = nullptr; // Pointer to the TabContainer instance

            TabContainerSignalWrapper* containerSignalWrapper = nullptr;
            void connectContainerSignals() {
                // Connect signals from the container to the element
                // Example: container->connect("signal_name", this, "method_name");
                if (this->containerSignalWrapper == nullptr) {
                    this->containerSignalWrapper = memnew(TabContainerSignalWrapper);
                    this->containerSignalWrapper->element = this;
                }

                this->container->connect("active_tab_rearranged", Callable(this->containerSignalWrapper, "active_tab_rearranged"));
                this->container->connect("pre_popup_pressed", Callable(this->containerSignalWrapper, "pre_popup_pressed"));
                this->container->connect("tab_button_pressed", Callable(this->containerSignalWrapper, "tab_button_pressed"));
                this->container->connect("tab_changed", Callable(this->containerSignalWrapper, "tab_changed"));
                this->container->connect("tab_clicked", Callable(this->containerSignalWrapper, "tab_clicked"));
                this->container->connect("tab_hovered", Callable(this->containerSignalWrapper, "tab_hovered"));
                this->container->connect("tab_selected", Callable(this->containerSignalWrapper, "tab_selected"));
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

            sunaba::desktop::Popup* getPopup() {
                return new sunaba::desktop::Popup(container->get_popup());
            }

            int getPreviousTab() {
                return container->get_previous_tab();
            }

            TabBar* getTabBar() {
                return new TabBar(container->get_tab_bar());
            }

            sunaba::core::Texture2D* getTabButtonIcon(int tab) {
                return new sunaba::core::Texture2D(container->get_tab_button_icon(tab).ptr());
            }

            Control* getTabControl(int tab) {
                return new Control(container->get_tab_control(tab));
            }

            int getTabCount() {
                return container->get_tab_count();
            }

            sunaba::core::Texture2D* getTabIcon(int tab) {
                return new sunaba::core::Texture2D(container->get_tab_icon(tab).ptr());
            }

            int getTabIconMaxWidth(int tab) {
                return container->get_tab_icon_max_width(tab);
            }

            int getTabIdxAtPoint(const Vector2& point) {
                return container->get_tab_idx_at_point(point);
            }

            int getTabIdxFromControl(Control* control) {
                return container->get_tab_idx_from_control(control->getControl());
            }

            Variant getTabMetadata(int tab) {
                return container->get_tab_metadata(tab);
            }

            std::string getTabTitle(int tab) {
                return String(container->get_tab_title(tab)).utf8().get_data();
            }

            std::string getTabTooltip(int tab) {
                return String(container->get_tab_tooltip(tab)).utf8().get_data();
            }

            bool isTabDisabled(int tab) {
                return container->is_tab_disabled(tab);
            }

            bool isTabHidden(int tab) {
                return container->is_tab_hidden(tab);
            }

            bool selectNextAvailable() {
                return container->select_next_available();
            }

            bool selectPreviousAvailable() {
                return container->select_previous_available();
            }

            void setPopup(Element* popup) {
                container->set_popup(popup->getNode());
            }

            void setTabButtonIcon(int tab, sunaba::core::Texture2D* icon) {
                godot::Texture2D* iconTexture = 
                    icon != nullptr 
                        ? icon->getTexture2D() 
                        : nullptr;
                Ref<godot::Texture2D> iconRef = 
                    iconTexture != nullptr 
                        ? Ref<godot::Texture2D>(iconTexture) 
                        : Ref<godot::Texture2D>();
                container->set_tab_button_icon(tab, iconRef);
            }

            void setTabDisabled(int tab, bool disabled) {
                container->set_tab_disabled(tab, disabled);
            }

            void setTabHidden(int tab, bool hidden) {
                container->set_tab_hidden(tab, hidden);
            }

            void setTabIcon(int tab, sunaba::core::Texture2D* icon) {
                godot::Texture2D* iconTexture = 
                    icon != nullptr 
                        ? icon->getTexture2D() 
                        : nullptr;
                Ref<godot::Texture2D> iconRef = 
                    iconTexture != nullptr 
                        ? Ref<godot::Texture2D>(iconTexture) 
                        : Ref<godot::Texture2D>();
                container->set_tab_icon(tab, iconRef);
            }

            void setTabIconMaxWidth(int tab, int width) {
                container->set_tab_icon_max_width(tab, width);
            }

            void setTabMetadata(int tab, Variant metadata) {
                container->set_tab_metadata(tab, metadata);
            }

            void setTabTitle(int tab, const std::string& title) {
                container->set_tab_title(tab, String(title.c_str()));
            }

            void setTabTooltip(int tab, const std::string& tooltip) {
                container->set_tab_tooltip(tab, String(tooltip.c_str()));
            }

            void onFree() override {
                if (containerSignalWrapper) {
                    memdelete(containerSignalWrapper);
                    containerSignalWrapper = nullptr;
                }
                Container::onFree();
            }
    };
}

#endif // !TAB_CONTAINER_H
