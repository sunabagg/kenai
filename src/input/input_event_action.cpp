#include "input_event_action.h"

void sunaba::input::bindInputEventAction(sol::state_view& lua) {
    lua.new_usertype<InputEventAction>("InputEventAction",
        sol::constructors<InputEventAction(), InputEventAction(GodotInputEventAction*)>(),
        sol::base_classes, sol::bases<sunaba::input::InputEvent>(),
        "action", sol::property(&InputEventAction::getAction, &InputEventAction::setAction),
        "eventIndex", sol::property(&InputEventAction::getEventIndex, &InputEventAction::setEventIndex),
        "pressed", sol::property(&InputEventAction::isPressed, &InputEventAction::setPressed),
        "strength", sol::property(&InputEventAction::getStrength, &InputEventAction::setStrength),
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventAction(static_cast<GodotInputEventAction*>(instance->getResource()));
        }
    );
}