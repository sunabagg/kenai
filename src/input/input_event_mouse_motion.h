#ifndef INPUT_EVENT_MOUSE_MOTION_H
#define INPUT_EVENT_MOUSE_MOTION_H

#include <godot_cpp/classes/input_event_mouse_motion.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventMouseMotion godot::InputEventMouseMotion

#include "input_event_mouse.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::input {
    void bindInputEventMouseMotion(sol::state_view& lua);

    class InputEventMouseMotion : public lucidware::input::InputEventMouse {
    private:
        GodotInputEventMouseMotion* event;
    public:
        InputEventMouseMotion(GodotInputEventMouseMotion* e) {
            setInputEventMouseMotion(e);
        }

        InputEventMouseMotion() {
            setInputEventMouseMotion(memnew(GodotInputEventMouseMotion));
        }

        GodotInputEventMouseMotion* getInputEventMouseMotion() const {
            return event;
        }

        void setInputEventMouseMotion(GodotInputEventMouseMotion* e) {
            event = e;
            event->reference();
            setInputEventMouse(e);
        }

        bool getPenInverted() {
            return event->get_pen_inverted();
        }

        void setPenInverted(bool inverted) {
            event->set_pen_inverted(inverted);
        }

        float getPressure() {
            return event->get_pressure();
        }

        void setPressure(float pressure) {
            event->set_pressure(pressure);
        }

        Vector2 getRelative() {
            return event->get_relative();
        }

        void setRelative(Vector2 relative) {
            event->set_relative(relative);
        }

        Vector2 getScreenRelative() {
            return event->get_screen_relative();
        }

        void setScreenRelative(Vector2 relative) {
            event->set_screen_relative(relative);
        }

        Vector2 getScreenVelocity() {
            return event->get_screen_velocity();
        }

        void setScreenVelocity(Vector2 velocity) {
            event->set_screen_velocity(velocity);
        }

        Vector2 getTilt() {
            return event->get_tilt();
        }

        void setTilt(Vector2 tilt) {
            event->set_tilt(tilt);
        }

        Vector2 getVelocity() {
            return event->get_velocity();
        }

        void setVelocity(Vector2 velocity) {
            event->set_velocity(velocity);
        }
    };
}

#endif // INPUT_EVENT_MOUSE_MOTION_H