#include "input_event_with_modifiers.h"

void kenai::input::bindInputEventWithModifiers(sol::state_view& lua) {
    lua.new_usertype<InputEventWithModifiers>("InputEventWithModifiers",
        "new", sol::factories(
            []() { return new InputEventWithModifiers(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::input::InputEvent, kenai::input::InputEventFromWindow>(),
        "altPressed", sol::property(&InputEventWithModifiers::getAltPressed, &InputEventWithModifiers::setAltPressed),
        "commandOrControlAutoremap", sol::property(&InputEventWithModifiers::getCommandOrControlAutoremap, &InputEventWithModifiers::setCommandOrControlAutoremap),
        "ctrlPressed", sol::property(&InputEventWithModifiers::isCtrlPressed, &InputEventWithModifiers::setCtrlPressed),
        "metaPressed", sol::property(&InputEventWithModifiers::isMetaPressed, &InputEventWithModifiers::setMetaPressed),
        "shiftPressed", sol::property(&InputEventWithModifiers::isShiftPressed, &InputEventWithModifiers::setShiftPressed),
        "cast", [](kenai::core::Resource* instance) {
            return new InputEventWithModifiers(godot::Object::cast_to<GodotInputEventWithModifiers>(instance->getResource()));
        }
    );
}