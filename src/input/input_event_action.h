#ifndef INPUT_EVENT_ACTION_H
#define INPUT_EVENT_ACTION_H

#include <godot_cpp/classes/input_event_action.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventAction godot::InputEventAction

#include "input_event.h"
#include "../core/convert_godot_lua.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::input {
    void bindInputEventAction(sol::state_view& lua);

    class InputEventAction : public lucidware::input::InputEvent {
    private:
        GodotInputEventAction* event;
    public:
        InputEventAction(GodotInputEventAction* e) {
            setInputEventAction(e);
        }

        InputEventAction() {
            setInputEventAction(memnew(GodotInputEventAction));
        }

        GodotInputEventAction* getInputEventAction() const {
            return event;
        }

        void setInputEventAction(GodotInputEventAction* e) {
            event = e;
            event->reference();
            setInputEvent(e);
        }

        std::string getAction() {
            return String(event->get_action()).utf8().get_data();
        }

        void setAction(const std::string& action) {
            event->set_action(action.c_str());
        }

        int getEventIndex() {
            return event->get_event_index();
        }

        void setEventIndex(int index) {
            event->set_event_index(index);
        }

        bool isPressed() {
            return event->is_pressed();
        }

        void setPressed(bool pressed) {
            event->set_pressed(pressed);
        }

        float getStrength() {
            return event->get_strength();
        }

        void setStrength(float strength) {
            event->set_strength(strength);
        }
    };
}

#endif