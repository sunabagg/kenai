#ifndef INPUT_EVENT_SCREEN_DRAG_H
#define INPUT_EVENT_SCREEN_DRAG_H

#include <godot_cpp/classes/input_event_screen_drag.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventScreenDrag godot::InputEventScreenDrag

#include "input_event_from_window.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::input {
    void bindInputEventScreenDrag(sol::state_view& lua);

    class InputEventScreenDrag : public lucidware::input::InputEventFromWindow {
    private:
        GodotInputEventScreenDrag* event;
    public:
        InputEventScreenDrag(GodotInputEventScreenDrag* e) {
            setInputEventScreenDrag(e);
        }

        InputEventScreenDrag() {
            setInputEventScreenDrag(memnew(GodotInputEventScreenDrag));
        }

        GodotInputEventScreenDrag* getInputEventScreenDrag() const {
            return event;
        }

        void setInputEventScreenDrag(GodotInputEventScreenDrag* e) {
            event = e;
            event->reference();
            setInputEventFromWindow(e);
        }

        int getIndex() {
            return event->get_index();
        }

        void setIndex(int index) {
            event->set_index(index);
        }
        

        bool getPenInverted() {
            return event->get_pen_inverted();
        }

        void setPenInverted(bool inverted) {
            event->set_pen_inverted(inverted);
        }

        Vector2 getPosition() {
            return event->get_position();
        }

        void setPosition(Vector2 position) {
            event->set_position(position);
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

#endif // INPUT_EVENT_SCREEN_DRAG_H