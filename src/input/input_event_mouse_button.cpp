#include "input_event_mouse_button.h"

void sunaba::input::bindInputEventMouseButton(sol::state_view& lua) {
    lua.new_usertype<InputEventMouseButton>("InputEventMouseButton",
        "new", sol::factories(
            []() { return new InputEventMouseButton(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::input::InputEvent, sunaba::input::InputEventFromWindow, sunaba::input::InputEventWithModifiers, sunaba::input::InputEventMouse>(),
        "buttonIndex", sol::property(&InputEventMouseButton::getButtonIndex, &InputEventMouseButton::setButtonIndex),
        "canceled", sol::property(&InputEventMouseButton::isCanceled, &InputEventMouseButton::setCanceled),
        "doubleclick", sol::property(&InputEventMouseButton::isDoubleclick, &InputEventMouseButton::setDoubleclick),
        "factor", sol::property(&InputEventMouseButton::getFactor, &InputEventMouseButton::setFactor),
        "pressed", sol::property(&InputEventMouseButton::isPressed, &InputEventMouseButton::setPressed),
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventMouseButton(godot::Object::cast_to<GodotInputEventMouseButton>(instance->getResource()));
        }
    );
}