#include "shortcut.h"

void kenai::input::bindShortcut(sol::state& lua) {
    lua.new_usertype<Shortcut>("Shortcut",
        "new", sol::factories(
            []() { return new Shortcut(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource>(),
        "events", sol::property(&Shortcut::getEvents, &Shortcut::setEvents),
        "getAsText", &Shortcut::getAsText,
        "hasValidEvent", &Shortcut::hasValidEvent,
        "matchesEvent", &Shortcut::matchesEvent,
        "cast", [](kenai::core::Resource* instance) {
            return new Shortcut(godot::Object::cast_to<GodotShortcut>(instance->getResource()));
        }
    );
}