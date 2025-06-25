#ifndef INPUT_EVENT_SCREEN_TOUCH_H
#define INPUT_EVENT_SCREEN_TOUCH_H

#include <godot_cpp/classes/input_event_screen_touch.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventScreenTouch godot::InputEventScreenTouch

#include "input_event_from_window.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::input {
    void bindInputEventScreenTouch(sol::state_view& lua);

    class InputEventScreenTouch : public lucidware::input::InputEventFromWindow {
    private:
        GodotInputEventScreenTouch* event;
    public:
        InputEventScreenTouch(GodotInputEventScreenTouch* e) {
            setInputEventScreenTouch(e);
        }

        InputEventScreenTouch() {
            setInputEventScreenTouch(memnew(GodotInputEventScreenTouch));
        }

        GodotInputEventScreenTouch* getInputEventScreenTouch() const {
            return event;
        }

        void setInputEventScreenTouch(GodotInputEventScreenTouch* e) {
            event = e;
            event->reference();
            setInputEventFromWindow(e);
        }

        bool isCanceled() {
            return event->is_canceled();
        }

        void setCanceled(bool cancel) {
            event->set_canceled(cancel);
        }

        bool isDoubleTap() {
            return event->is_double_tap();
        }

        void setDoubleTap(bool doubletap) {
            event->set_double_tap(doubletap);
        }

        int getIndex() {
            return event->get_index();
        }

        void setIndex(int index) {
            event->set_index(index);
        }

        Vector2 getPosition() {
            return event->get_position();
        }

        void setPosition(Vector2 position) {
            event->set_position(position);
        }

        bool isPressed() {
            return event->is_pressed();
        }

        void setPressed(bool pressed) {
            event->set_pressed(pressed);
        }
    };
}

#endif // INPUT_EVENT_SCREEN_TOUCH_H