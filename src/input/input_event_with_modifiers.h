#ifndef INPUT_EVENT_WITH_MODIFIERS_H
#define INPUT_EVENT_WITH_MODIFIERS_H

#include <godot_cpp/classes/input_event_with_modifiers.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventWithModifiers godot::InputEventWithModifiers

#include "input_event_from_window.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::input {
    void bindInputEventWithModifiers(sol::state_view& lua);

    class InputEventWithModifiers : public lucidfx::input::InputEventFromWindow {
    private:
        GodotInputEventWithModifiers* event;
    public:
        InputEventWithModifiers(GodotInputEventWithModifiers* e) {
            setInputEventWithModifiers(e);
        }

        InputEventWithModifiers() {
            setInputEventWithModifiers(memnew(GodotInputEventWithModifiers));
        }

        GodotInputEventWithModifiers* getInputEventWithModifiers() const {
            return event;
        }

        void setInputEventWithModifiers(GodotInputEventWithModifiers* e) {
            event = e;
            event->reference();
            setInputEventFromWindow(e);
        }

        bool getAltPressed() {
            return event->is_alt_pressed();
        }

        void setAltPressed(bool pressed) {
            event->set_alt_pressed(pressed);
        }

        bool getCommandOrControlAutoremap() {
            return event->is_command_or_control_autoremap();
        }

        void setCommandOrControlAutoremap(bool autoremap) {
            event->set_command_or_control_autoremap(autoremap);
        }

        bool isCtrlPressed() {
            return event->is_ctrl_pressed();
        }

        void setCtrlPressed(bool pressed) {
            event->set_ctrl_pressed(pressed);
        }

        bool isMetaPressed() {
            return event->is_meta_pressed();
        }

        void setMetaPressed(bool pressed) {
            event->set_meta_pressed(pressed);
        }

        bool isShiftPressed() {
            return event->is_shift_pressed();
        }

        void setShiftPressed(bool pressed) {
            event->set_shift_pressed(pressed);
        }

        int getModifiersMask() {
            return event->get_modifiers_mask();
        }

        bool isCommandOrControlPressed() {
            return event->is_command_or_control_pressed();
        }
    };
}

#endif // INPUT_EVENT_WITH_MODIFIERS_H