#ifndef SCROLL_CONTAINER_H
#define SCROLL_CONTAINER_H

#include <godot_cpp/classes/scroll_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ScrollContainerNode godot::ScrollContainer

#include "container.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"
#include "h_scroll_bar.h"
#include "v_scroll_bar.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindScrollContainer(sol::state& lua);

    class ScrollContainer;
    class ScrollContainerProxy : public ScrollContainerNode {
        GDCLASS(ScrollContainerProxy, ScrollContainerNode)
        protected:
            static void _bind_methods() {
            }
        public:
            lucidware::ui::ScrollContainer* element = nullptr;

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

    class ScrollContainer : public lucidware::ui::Container {
        private:
            ScrollContainerNode* scrollContainer = nullptr; // Pointer to the ScrollContainer instance

            void connectScrollContainerSignals() {
                SignalFunc scrollEndedFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->scrollEndedEvent != nullptr) {
                        this->scrollEndedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable scrollEndedCallable = StlFunctionWrapper::create_callable_from_cpp_function(scrollEndedFunc);
                scrollContainer->connect("scroll_ended", scrollEndedCallable);
                SignalFunc scrollStartedFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->scrollStartedEvent != nullptr) {
                        this->scrollStartedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable scrollStartedCallable = StlFunctionWrapper::create_callable_from_cpp_function(scrollStartedFunc);
                scrollContainer->connect("scroll_started", scrollStartedCallable);
            }

        public:
            ScrollContainer() {
                setScrollContainer(memnew(ScrollContainerNode));
                onInit();
            }

            ScrollContainer(ScrollContainerNode* p_node) {
                setScrollContainer(p_node);
            }

            ScrollContainerNode* getScrollContainer() {
                return scrollContainer;
            }

            void setScrollContainer(ScrollContainerNode* p_node) {
                scrollContainer = p_node;
                connectScrollContainerSignals();
                setContainer(p_node);
            }

            void setScrollContainer(ScrollContainerProxy* p_node) {
                scrollContainer = p_node;
                p_node->element = this;
                connectScrollContainerSignals();
                setContainer(p_node);
            }

            bool isClippingContents() {
                return scrollContainer->is_clipping_contents();
            }

            void setClipContents(bool value) {
                scrollContainer->set_clip_contents(value);
            }

            bool getDrawFocusBorder() {
                return scrollContainer->get_draw_focus_border();
            }
            
            void setDrawFocusBorder(bool value) {
                scrollContainer->set_draw_focus_border(value);
            }

            bool isFollowingFocus() {
                return scrollContainer->is_following_focus();
            }

            void setFollowFocus(bool value) {
                scrollContainer->set_follow_focus(value);
            }

            int getHorizontalScrollMode() {
                return scrollContainer->get_horizontal_scroll_mode();
            }

            void setHorizontalScrollMode(int mode) {
                scrollContainer->set_horizontal_scroll_mode(static_cast<godot::ScrollContainer::ScrollMode>(mode));
            }

            int getScrollDeadzone() {
                return scrollContainer->get_deadzone();
            }

            void setScrollDeadzone(int value) {
                scrollContainer->set_deadzone(value);
            }

            int getScrollHorizontal() {
                return scrollContainer->get_h_scroll();
            }

            void setScrollHorizontal(int value) {
                scrollContainer->set_h_scroll(value);
            }

            float getScrollHorizontalCustomStep() {
                return scrollContainer->get_horizontal_custom_step();
            }

            void setScrollHorizontalCustomStep(float value) {
                scrollContainer->set_horizontal_custom_step(value);
            }

            int getScrollVertical() {
                return scrollContainer->get_v_scroll();
            }

            void setScrollVertical(int value) {
                scrollContainer->set_v_scroll(value);
            }

            float getScrollVerticalCustomStep() {
                return scrollContainer->get_vertical_custom_step();
            }

            void setScrollVerticalCustomStep(float value) {
                scrollContainer->set_vertical_custom_step(value);
            }

            int getVerticalScrollMode() {
                return scrollContainer->get_vertical_scroll_mode();
            }

            void setVerticalScrollMode(int mode) {
                scrollContainer->set_vertical_scroll_mode(static_cast<godot::ScrollContainer::ScrollMode>(mode));
            }

            Event* scrollEndedEvent;
            Event* getScrollEndedEvent() {
                return scrollEndedEvent;
            }
            void setScrollEndedEvent(Event* event) {
                scrollEndedEvent = event;
            }

            Event* scrollStartedEvent;
            Event* getScrollStartedEvent() {
                return scrollStartedEvent;
            }
            void setScrollStartedEvent(Event* event) {
                scrollStartedEvent = event;
            }

            void ensureControlVisible(Control* control) {
                scrollContainer->ensure_control_visible(control->getControl());
            }

            HScrollBar* getHScrollBar() {
                return new HScrollBar(scrollContainer->get_h_scroll_bar());
            }

            VScrollBar* getVScrollBar() {
                return new VScrollBar(scrollContainer->get_v_scroll_bar());
            }
    };
}

#endif // SCROLL_CONTAINER_H