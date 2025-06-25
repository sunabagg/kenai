#ifndef INPUT_EVENT_MOUSE_BUTTON_H
#define INPUT_EVENT_MOUSE_BUTTON_H

#include <godot_cpp/classes/input_event_mouse_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventMouseButton godot::InputEventMouseButton

#include "input_event_mouse.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::input {
    void bindInputEventMouseButton(sol::state_view& lua);

    class InputEventMouseButton : public lucidfx::input::InputEventMouse {
    private:
        GodotInputEventMouseButton* event;
    public:
        InputEventMouseButton(GodotInputEventMouseButton* e) {
            setInputEventMouseButton(e);
        }

        InputEventMouseButton() {
            setInputEventMouseButton(memnew(GodotInputEventMouseButton));
        }

        GodotInputEventMouseButton* getInputEventMouseButton() const {
            return event;
        }

        void setInputEventMouseButton(GodotInputEventMouseButton* e) {
            event = e;
            event->reference();
            setInputEventMouse(e);
        }

        int getButtonIndex() {
            return event->get_button_index();
        }

        void setButtonIndex(int index) {
            event->set_button_index(static_cast<MouseButton>(index));
        }

        bool isCanceled() {
            return event->is_canceled();
        }

        void setCanceled(bool cancel) {
            event->set_canceled(cancel);
        }

        bool isDoubleclick() {
            return event->is_double_click();
        }

        void setDoubleclick(bool doubleclick) {
            event->set_double_click(doubleclick);
        }

        float getFactor() {
            return event->get_factor();
        }

        void setFactor(float factor) {
            event->set_factor(factor);
        }

        bool isPressed() {
            return event->is_pressed();
        }

        void setPressed(bool pressed) {
            event->set_pressed(pressed);
        }
    };
}

#endif // INPUT_EVENT_MOUSE_BUTTON_H