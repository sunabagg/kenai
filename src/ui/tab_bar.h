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
                SignalFunc activeTabRearrangedFunc = 
                [this] (std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); i++)
                    {
                        args.append(av[i]);
                    }
                    if (activeTabRearrangedEvent != nullptr) {
                        activeTabRearrangedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable activeTabRearrangedCallable = StlFunctionWrapper::create_callable_from_cpp_function(activeTabRearrangedFunc);
                container->connect("active_tab_rearranged", activeTabRearrangedCallable);
                SignalFunc tabButtonPressedFunc =
                [this] (std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); i++)
                    {
                        args.append(av[i]);
                    }
                    if (tabButtonPressedEvent != nullptr) {
                        tabButtonPressedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable tabButtonPressedCallable = StlFunctionWrapper::create_callable_from_cpp_function(tabButtonPressedFunc);
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

            bool getSelectWithRmb() {
                return container->get_select_with_rmb();
            }

            void setSelectWithRmb(bool enabled) {
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

            void setTabCloseDisplayPolicy(int policy) {
                container->set_tab_close_display_policy(static_cast<godot::TabBar::CloseButtonDisplayPolicy>(policy));
            }

            int getTabCount() {
                return container->get_tab_count();
            }

            void setTabCount(int count) {
                container->set_tab_count(count);
            }

            int getTabsRearrangeGroup() {
                return container->get_tabs_rearrange_group();
            }

            void setTabsRearrangeGroup(int group) {
                container->set_tabs_rearrange_group(group);
            }

            Event* activeTabRearrangedEvent;
            Event* getActiveTabRearrangedEvent() {
                return activeTabRearrangedEvent;
            }
            void setActiveTabRearrangedEvent(Event* event) {
                activeTabRearrangedEvent = event;
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
            Event* tabClosePressedEvent;
            Event* getTabClosePressedEvent() {
                return tabClosePressedEvent;
            }
            void setTabClosePressedEvent(Event* event) {
                tabClosePressedEvent = event;
            }
            Event* tabHoveredEvent;
            Event* getTabHoveredEvent() {
                return tabHoveredEvent;
            }
            void setTabHoveredEvent(Event* event) {
                tabHoveredEvent = event;
            }
            Event* tabRmbClickedEvent;
            Event* getTabRmbClickedEvent() {
                return tabRmbClickedEvent;
            }
            void setTabRmbClickedEvent(Event* event) {
                tabRmbClickedEvent = event;
            }
            Event* tabSelectedEvent;
            Event* getTabSelectedEvent() {
                return tabSelectedEvent;
            }
            void setTabSelectedEvent(Event* event) {
                tabSelectedEvent = event;
            }
    };
}

#endif // TAB_BAR_H