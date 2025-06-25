#ifndef INPUT_EVENT_PAN_GESTURE_H
#define INPUT_EVENT_PAN_GESTURE_H

#include <godot_cpp/classes/input_event_pan_gesture.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventPanGesture godot::InputEventPanGesture

#include "input_event_gesture.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::input {
    void bindInputEventPanGesture(sol::state_view& lua);

    class InputEventPanGesture : public lucidfx::input::InputEventGesture {
    private:
        GodotInputEventPanGesture* event;
    public:
        InputEventPanGesture(GodotInputEventPanGesture* e) {
            setInputEventPanGesture(e);
        }

        InputEventPanGesture() {
            setInputEventPanGesture(memnew(GodotInputEventPanGesture));
        }

        GodotInputEventPanGesture* getInputEventPanGesture() const {
            return event;
        }

        void setInputEventPanGesture(GodotInputEventPanGesture* e) {
            event = e;
            event->reference();
            setInputEventGesture(e);
        }

        Vector2 getDelta() {
            return event->get_delta();
        }

        void setDelta(Vector2 delta) {
            event->set_delta(delta);
        }
    };
}

#endif // INPUT_EVENT_PAN_GESTURE_H