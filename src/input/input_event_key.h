#ifndef INPUT_EVENT_KEY_H
#define INPUT_EVENT_KEY_H

#include <godot_cpp/classes/input_event_key.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>
#include <string>

#define GodotInputEventKey godot::InputEventKey

#include "input_event_with_modifiers.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::input {
    void bindInputEventKey(sol::state_view& lua);

    class InputEventKey : public lucidware::input::InputEventWithModifiers {
    private:
        GodotInputEventKey* event;
    public:
        InputEventKey(GodotInputEventKey* e) {
            setInputEventKey(e);
        }

        InputEventKey() {
            setInputEventKey(memnew(GodotInputEventKey));
        }

        GodotInputEventKey* getInputEventKey() const {
            return event;
        }

        void setInputEventKey(GodotInputEventKey* e) {
            event = e;
            event->reference();
            setInputEventWithModifiers(e);
        }

        bool isEcho() {
            return event->is_echo();
        }

        void setEcho(bool echo) {
            event->set_echo(echo);
        }

        int getKeyLabel() {
            return event->get_key_label();
        }

        void setKeyLabel(int key) {
            event->set_key_label(static_cast<Key>(key));
        }

        int getLocation() {
            return event->get_location();
        }

        void setLocation(int location) {
            event->set_location(static_cast<KeyLocation>(location));
        }

        int getPhysicalKeycode() {
            return event->get_physical_keycode();
        }

        void setPhysicalKeycode(int key) {
            event->set_physical_keycode(static_cast<Key>(key));
        }

        bool isPressed() {
            return event->is_pressed();
        }

        void setPressed(bool pressed) {
            event->set_pressed(pressed);
        }

        int getUnicode() {
            return event->get_unicode();
        }

        void setUnicode(int unicode) {
            event->set_unicode(unicode);
        }

        std::string asTextKeyLabel() {
            return event->as_text_key_label().utf8().get_data();
        }

        std::string asTextKeycode() {
            return event->as_text_keycode().utf8().get_data();
        }

        std::string asTextLocation() {
            return event->as_text_location().utf8().get_data();
        }

        std::string asTextPhysicalKeycode() {
            return event->as_text_physical_keycode().utf8().get_data();
        }

        int getKeyLabelWithModifiers() {
            return event->get_key_label_with_modifiers();
        }

        int getKeycodeWithModifiers() {
            return event->get_keycode_with_modifiers();
        }

        int getPhysicalKeycodeWithModifiers() {
            return event->get_physical_keycode_with_modifiers();
        }
    };
}

#endif // INPUT_EVENT_KEY_H