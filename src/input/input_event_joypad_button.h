#ifndef INPUT_EVENT_JOYPAD_BUTTON_H
#define INPUT_EVENT_JOYPAD_BUTTON_H

#include <godot_cpp/classes/input_event_joypad_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventJoypadButton godot::InputEventJoypadButton

#include "input_event.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::input {
    void bindInputEventJoypadButton(sol::state_view& lua);

    class InputEventJoypadButton : public lucidware::input::InputEvent {
    private:
        GodotInputEventJoypadButton* event;
    public:
        InputEventJoypadButton(GodotInputEventJoypadButton* e) {
            setInputEventJoypadButton(e);
        }

        InputEventJoypadButton() {
            setInputEventJoypadButton(memnew(GodotInputEventJoypadButton));
        }

        GodotInputEventJoypadButton* getInputEventJoypadButton() const {
            return event;
        }

        void setInputEventJoypadButton(GodotInputEventJoypadButton* e) {
            event = e;
            event->reference();
            setInputEvent(e);
        }

        int getButtonIndex() {
            return event->get_button_index();
        }

        void setButtonIndex(int index) {
            event->set_button_index(static_cast<JoyButton>(index));
        }

        bool isPressed() {
            return event->is_pressed();
        }

        void setPressed(bool pressed) {
            event->set_pressed(pressed);
        }

        float getPressure() {
            return event->get_pressure();
        }

        void setPressure(float pressure) {
            event->set_pressure(pressure);
        }
    };
}

#endif // INPUT_EVENT_JOYPAD_BUTTON_H