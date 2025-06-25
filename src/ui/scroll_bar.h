#ifndef SCROLL_BAR_H
#define SCROLL_BAR_H

#include <godot_cpp/classes/scroll_bar.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ScrollBarNode godot::ScrollBar

#include "range.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindScrollBar(sol::state& lua);

    class ScrollBar;
    
    class ScrollBarProxy : public ScrollBarNode {
        GDCLASS(ScrollBarProxy, ScrollBarNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to ScrollBarProxy
                BIND_VIRTUAL_METHOD(ScrollBarProxy, _value_changed, 373806689);
            }
        public:
            lucidware::ui::ScrollBar* element = nullptr;

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

            void _value_changed(double value) override;
    };

    class ScrollBar : public lucidware::ui::Range {
        private:
            ScrollBarNode* scrollBar = nullptr; // Pointer to the ScrollBar instance

            void connectScrollBarSignals() {
                // Connect signals specific to ScrollBar
                SignalFunc scrollingFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->scrollingEvent != nullptr) {
                        this->scrollingEvent->emit(args);
                    }
                    return Variant();
                };
                Callable scrollingCallable = StlFunctionWrapper::create_callable_from_cpp_function(scrollingFunc);
                scrollBar->connect("scrolling", scrollingCallable);
            }

        public:
            ScrollBar() {
                setScrollBar(memnew(ScrollBarNode));
                onInit();
                connectScrollBarSignals();
            }

            ScrollBar(ScrollBarNode* p_node) {
                setScrollBar(p_node);
                onInit();
                connectScrollBarSignals();
            }

            ScrollBarNode* getScrollBar() {
                return scrollBar;
            }

            void setScrollBar(ScrollBarNode* p_node) {
                scrollBar = p_node;
                connectScrollBarSignals();
                setRange(p_node);
            }

            void setScrollBar(ScrollBarProxy* p_node) {
                scrollBar = p_node;
                connectScrollBarSignals();
                setRange(p_node);
            }

            float getCustomStep() {
                return scrollBar->get_custom_step();
            }
            
            void setCustomStep(float value) {
                scrollBar->set_custom_step(value);
            }

            float getStep() {
                return scrollBar->get_step();
            }

            void setStep(float value) {
                scrollBar->set_step(value);
            }

            Event* scrollingEvent;
            Event* getScrollingEvent() {
                return scrollingEvent;
            }
            void setScrollingEvent(Event* event) {
                scrollingEvent = event;
            }
    };
}

#endif // SCROLL_BAR_H