#ifndef INPUT_EVENT_MOUSE_H
#define INPUT_EVENT_MOUSE_H

#include <godot_cpp/classes/input_event_mouse.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventMouse godot::InputEventMouse

#include "input_event_with_modifiers.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::input {
    void bindInputEventMouse(sol::state_view& lua);

    class InputEventMouse : public lucidfx::input::InputEventWithModifiers {
    private:
        GodotInputEventMouse* event;
    public:
        InputEventMouse(GodotInputEventMouse* e) {
            setInputEventMouse(e);
        }

        InputEventMouse() {
            setInputEventMouse(memnew(GodotInputEventMouse));
        }

        GodotInputEventMouse* getInputEventMouse() const {
            return event;
        }

        void setInputEventMouse(GodotInputEventMouse* e) {
            event = e;
            event->reference();
            setInputEventWithModifiers(e);
        }

        int getButtonMask() {
            return event->get_button_mask();
        }

        void setButtonMask(int mask) {
            event->set_button_mask(mask);
        }

        Vector2 getGlobalPosition() {
            return event->get_global_position();
        }

        void setGlobalPosition(Vector2 position) {
            event->set_global_position(position);
        }

        Vector2 getPosition() {
            return event->get_position();
        }

        void setPosition(Vector2 position) {
            event->set_position(position);
        }
    };
}

#endif // INPUT_EVENT_MOUSE_H