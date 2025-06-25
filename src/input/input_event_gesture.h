#ifndef INPUT_EVENT_GESTURE_H
#define INPUT_EVENT_GESTURE_H

#include <godot_cpp/classes/input_event_gesture.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventGesture godot::InputEventGesture

#include "input_event_with_modifiers.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::input {
    void bindInputEventGesture(sol::state_view& lua);

    class InputEventGesture : public lucidfx::input::InputEventWithModifiers {
    private:
        GodotInputEventGesture* event;
    public:
        InputEventGesture(GodotInputEventGesture* e) {
            setInputEventGesture(e);
        }

        InputEventGesture() {
            setInputEventGesture(memnew(GodotInputEventGesture));
        }

        GodotInputEventGesture* getInputEventGesture() const {
            return event;
        }

        void setInputEventGesture(GodotInputEventGesture* e) {
            event = e;
            event->reference();
            setInputEventWithModifiers(e);
        }

        Vector2 getPosition() {
            return event->get_position();
        }

        void setPosition(const Vector2& position) {
            event->set_position(position);
        }
    };
}

#endif // INPUT_EVENT_GESTURE_H