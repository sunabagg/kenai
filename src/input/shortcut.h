#ifndef SHORTCUT_H
#define SHORTCUT_H

#include <godot_cpp/classes/shortcut.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotShortcut godot::Shortcut

#include "../core/resource.h"
#include "../core/convert_godot_lua.h"
#include "input_event.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::input {
    void bindShortcut(sol::state& lua);

    class Shortcut : public lucidfx::core::Resource {
    private:
        GodotShortcut* _godotShortcut;
    public:
        Shortcut() {
            setShortcut(memnew(GodotShortcut));
        }

        Shortcut(GodotShortcut* godotShortcut) {
            setShortcut(godotShortcut);
        }

        GodotShortcut* getShortcut() {
            return _godotShortcut;
        }

        void setShortcut(GodotShortcut* godotShortcut) {
            _godotShortcut = godotShortcut;
            _godotShortcut->reference();
            setResource(_godotShortcut);
        }

        std::vector<InputEvent*> getEvents() {
            std::vector<InputEvent*> events;
            Array godotEvents = _godotShortcut->get_events();
            for (int i = 0; i < godotEvents.size(); i++) {
                InputEvent* event = new InputEvent(
                    godot::Object::cast_to<GodotInputEvent>(
                        godotEvents[i]
                    )
                );
                if (event->isNull()) {
                    delete event;
                    continue;
                }
                events.push_back(event);
            }
            return events;
        }

        void setEvents(std::vector<InputEvent*> events) {
            Array godotEvents;
            for (int i = 0; i < events.size(); i++) {
                godotEvents.push_back(events[i]->getInputEvent());
            }
            _godotShortcut->set_events(godotEvents);
        }

        std::string getAsText() {
            return _godotShortcut->get_as_text().utf8().get_data();
        }

        bool hasValidEvent() {
            return _godotShortcut->has_valid_event();
        }

        bool matchesEvent(InputEvent* event) {
            return _godotShortcut->matches_event(event->getInputEvent());
        }
    };
}

#endif // SHORTCUT_H