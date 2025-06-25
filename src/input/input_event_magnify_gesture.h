#ifndef INPUT_EVENT_MAGNIFY_GESTURE_H
#define INPUT_EVENT_MAGNIFY_GESTURE_H

#include <godot_cpp/classes/input_event_magnify_gesture.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventMagnifyGesture godot::InputEventMagnifyGesture

#include "input_event_gesture.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::input {
    void bindInputEventMagnifyGesture(sol::state_view& lua);

    class InputEventMagnifyGesture : public lucidware::input::InputEventGesture {
    private:
        GodotInputEventMagnifyGesture* event;
    public:
        InputEventMagnifyGesture(GodotInputEventMagnifyGesture* e) {
            setInputEventMagnifyGesture(e);
        }

        InputEventMagnifyGesture() {
            setInputEventMagnifyGesture(memnew(GodotInputEventMagnifyGesture));
        }

        GodotInputEventMagnifyGesture* getInputEventMagnifyGesture() const {
            return event;
        }

        void setInputEventMagnifyGesture(GodotInputEventMagnifyGesture* e) {
            event = e;
            event->reference();
            setInputEventGesture(e);
        }

        float getFactor() {
            return event->get_factor();
        }

        void setFactor(float factor) {
            event->set_factor(factor);
        }
    };
}

#endif // INPUT_EVENT_MAGNIFY_GESTURE_H