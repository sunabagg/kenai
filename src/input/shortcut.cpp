#include "shortcut.h"

void lucidfx::input::bindShortcut(sol::state& lua) {
    lua.new_usertype<Shortcut>("Shortcut",
        "new", sol::factories(
            []() { return new Shortcut(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
        "events", sol::property(&Shortcut::getEvents, &Shortcut::setEvents),
        "getAsText", &Shortcut::getAsText,
        "hasValidEvent", &Shortcut::hasValidEvent,
        "matchesEvent", &Shortcut::matchesEvent,
        "cast", [](lucidfx::core::Resource* instance) {
            return new Shortcut(godot::Object::cast_to<GodotShortcut>(instance->getResource()));
        }
    );
}