#include "input_event_key.h"

void sunaba::input::bindInputEventKey(sol::state_view& lua) {
    lua.new_usertype<InputEventKey>("InputEventKey",
        "new", sol::factories(
            []() { return new InputEventKey(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::input::InputEvent, sunaba::input::InputEventFromWindow, sunaba::input::InputEventWithModifiers>(),
        "echo", sol::property(&InputEventKey::isEcho, &InputEventKey::setEcho),
        "keyLabel", sol::property(&InputEventKey::getKeyLabel, &InputEventKey::setKeyLabel),
        "location", sol::property(&InputEventKey::getLocation, &InputEventKey::setLocation),
        "physicalKeycode", sol::property(&InputEventKey::getPhysicalKeycode, &InputEventKey::setPhysicalKeycode),
        "unicode", sol::property(&InputEventKey::getUnicode, &InputEventKey::setUnicode),
        "asTextKeyLabel", &InputEventKey::asTextKeyLabel,
        "asTextKeycode", &InputEventKey::asTextKeycode,
        "asTextLocation", &InputEventKey::asTextLocation,
        "asTextPhysicalKeycode", &InputEventKey::asTextPhysicalKeycode,
        "getKeyLabelWithModifiers", &InputEventKey::getKeyLabelWithModifiers,
        "getKeycodeWithModifiers", &InputEventKey::getKeycodeWithModifiers,
        "getPhysicalKeycodeWithModifiers", &InputEventKey::getPhysicalKeycodeWithModifiers,
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventKey(godot::Object::cast_to<GodotInputEventKey>(instance->getResource()));
        }
    );
}