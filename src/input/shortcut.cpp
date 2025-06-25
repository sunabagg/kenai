#include "shortcut.h"

void lucidware::input::bindShortcut(sol::state& lua) {
    lua.new_usertype<Shortcut>("Shortcut",
        "new", sol::factories(
            []() { return new Shortcut(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "events", sol::property(&Shortcut::getEvents, &Shortcut::setEvents),
        "getAsText", &Shortcut::getAsText,
        "hasValidEvent", &Shortcut::hasValidEvent,
        "matchesEvent", &Shortcut::matchesEvent,
        "cast", [](lucidware::core::Resource* instance) {
            return new Shortcut(godot::Object::cast_to<GodotShortcut>(instance->getResource()));
        }
    );
}