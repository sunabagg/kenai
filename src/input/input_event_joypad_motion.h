#ifndef INPUT_EVENT_JOYPAD_MOTION_H
#define INPUT_EVENT_JOYPAD_MOTION_H

#include <godot_cpp/classes/input_event_joypad_motion.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventJoypadMotion godot::InputEventJoypadMotion

#include "input_event.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::input {
    void bindInputEventJoypadMotion(sol::state_view& lua);

    class InputEventJoypadMotion : public lucidware::input::InputEvent {
    private:
        GodotInputEventJoypadMotion* event;
    public:
        InputEventJoypadMotion(GodotInputEventJoypadMotion* e) {
            setInputEventJoypadMotion(e);
        }

        InputEventJoypadMotion() {
            setInputEventJoypadMotion(memnew(GodotInputEventJoypadMotion));
        }

        GodotInputEventJoypadMotion* getInputEventJoypadMotion() const {
            return event;
        }

        void setInputEventJoypadMotion(GodotInputEventJoypadMotion* e) {
            event = e;
            event->reference();
            setInputEvent(e);
        }

        int getAxis() {
            return event->get_axis();
        }

        void setAxis(int axis) {
            event->set_axis(static_cast<JoyAxis>(axis));
        }

        float getAxisValue() {
            return event->get_axis_value();
        }

        void setAxisValue(float value) {
            event->set_axis_value(value);
        }
    };
}

#endif // INPUT_EVENT_JOYPAD_MOTION_H