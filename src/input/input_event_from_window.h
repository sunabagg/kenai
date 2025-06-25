#ifndef INPUT_EVENT_FROM_WINDOW_H
#define INPUT_EVENT_FROM_WINDOW_H

#include <godot_cpp/classes/input_event_from_window.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventFromWindow godot::InputEventFromWindow

#include "input_event.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::input {
    void bindInputEventFromWindow(sol::state_view& lua);

    class InputEventFromWindow : public lucidfx::input::InputEvent {
    private:
        GodotInputEventFromWindow* event;
    public:
        InputEventFromWindow(GodotInputEventFromWindow* e) {
            setInputEventFromWindow(e);
        }

        InputEventFromWindow() {
            setInputEventFromWindow(memnew(GodotInputEventFromWindow));
        }

        GodotInputEventFromWindow* getInputEventFromWindow() const {
            return event;
        }

        void setInputEventFromWindow(GodotInputEventFromWindow* e) {
            event = e;
            event->reference();
            setInputEvent(e);
        }

        int getWindowId() {
            return event->get_window_id();
        }

        void setWindowId(int id) {
            event->set_window_id(id);
        }

    };
}

#endif // INPUT_EVENT_FROM_WINDOW_H