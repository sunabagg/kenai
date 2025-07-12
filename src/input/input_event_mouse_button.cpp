#include "input_event_mouse_button.h"

void kenai::input::bindInputEventMouseButton(sol::state_view& lua) {
    lua.new_usertype<InputEventMouseButton>("InputEventMouseButton",
        "new", sol::factories(
            []() { return new InputEventMouseButton(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::input::InputEvent, kenai::input::InputEventFromWindow, kenai::input::InputEventWithModifiers, kenai::input::InputEventMouse>(),
        "buttonIndex", sol::property(&InputEventMouseButton::getButtonIndex, &InputEventMouseButton::setButtonIndex),
        "canceled", sol::property(&InputEventMouseButton::isCanceled, &InputEventMouseButton::setCanceled),
        "doubleclick", sol::property(&InputEventMouseButton::isDoubleclick, &InputEventMouseButton::setDoubleclick),
        "factor", sol::property(&InputEventMouseButton::getFactor, &InputEventMouseButton::setFactor),
        "pressed", sol::property(&InputEventMouseButton::isPressed, &InputEventMouseButton::setPressed),
        "cast", [](kenai::core::Resource* instance) {
            return new InputEventMouseButton(godot::Object::cast_to<GodotInputEventMouseButton>(instance->getResource()));
        }
    );
}