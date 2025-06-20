#include "shortcut.h"

void sunaba::input::bindShortcut(sol::state& lua) {
    lua.new_usertype<Shortcut>("Shortcut",
        "new", sol::factories(
            []() { return new Shortcut(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "events", sol::property(&Shortcut::getEvents, &Shortcut::setEvents),
        "getAsText", &Shortcut::getAsText,
        "hasValidEvent", &Shortcut::hasValidEvent,
        "matchesEvent", &Shortcut::matchesEvent,
        "cast", [](sunaba::core::Resource* instance) {
            return new Shortcut(godot::Object::cast_to<GodotShortcut>(instance->getResource()));
        }
    );
}