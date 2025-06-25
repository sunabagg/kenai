#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEvent godot::InputEvent

#include "../core/resource.h"
#include "../core/convert_godot_lua.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::input {
    void bindInputEvent(sol::state_view& lua);

    class InputEvent : public lucidware::core::Resource {
    private:
        GodotInputEvent* event;
    public:
        InputEvent(GodotInputEvent* e) {
            setInputEvent(e);
        }

        InputEvent() {
            setInputEvent(memnew(GodotInputEvent));
        }

        GodotInputEvent* getInputEvent() const {
            return event;
        }

        void setInputEvent(GodotInputEvent* e) {
            event = e;
            event->reference();
            setResource(e);
        }

        int getDevice() {
            return event->get_device();
        }

        void setDevice(int device) {
            event->set_device(device);
        }

        bool accumulate(InputEvent* event) {
            return this->event->accumulate(event->getInputEvent());
        }

        std::string asText() {
            return this->event->as_text().utf8().get_data();
        }

        float getActionStrength(const std::string& action) {
            return this->event->get_action_strength(action.c_str());
        }

        bool isAction(const std::string& action, bool exactMatch = false) {
            return this->event->is_action(action.c_str(), exactMatch);
        }

        bool isActionPressed(const std::string& action, bool allowEcho = false, bool exactMatch = false) {
            return this->event->is_action_pressed(action.c_str(), allowEcho, exactMatch);
        }

        bool isActionReleased(const std::string& action, bool exactMatch = false) {
            return this->event->is_action_released(action.c_str(), exactMatch);
        }

        bool isActionType() {
            return this->event->is_action_type();
        }

        bool isCanceled() {
            return this->event->is_canceled();
        }

        bool isEcho() {
            return this->event->is_echo();
        }

        bool isMatch(InputEvent* event, bool exactMatch = true) {
            return this->event->is_match(event->getInputEvent(), exactMatch);
        }

        bool isPressed() {
            return this->event->is_pressed();
        }

        bool isReleased() {
            return this->event->is_released();
        }

        InputEvent* xformedBy(Transform2D xform, Vector2 localOfs) {
            auto e = this->event->xformed_by(xform, localOfs);
            if (e == nullptr) {
                return nullptr;
            }
            return new InputEvent(e.ptr());
        } 
    };
}

#endif