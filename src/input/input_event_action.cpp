#include "input_event_action.h"

void sunaba::input::bindInputEventAction(sol::state_view& lua) {
    lua.new_usertype<InputEventAction>("InputEventAction",
        "new", sol::factories(
            []() { return new InputEventAction(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::input::InputEvent>(),
        "action", sol::property(&InputEventAction::getAction, &InputEventAction::setAction),
        "eventIndex", sol::property(&InputEventAction::getEventIndex, &InputEventAction::setEventIndex),
        "pressed", sol::property(&InputEventAction::isPressed, &InputEventAction::setPressed),
        "strength", sol::property(&InputEventAction::getStrength, &InputEventAction::setStrength),
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventAction(godot::Object::cast_to<GodotInputEventAction>(instance->getResource()));
        }
    );
}