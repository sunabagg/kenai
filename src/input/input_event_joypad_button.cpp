#include "input_event_joypad_button.h"

void lucidfx::input::bindInputEventJoypadButton(sol::state_view& lua) {
    lua.new_usertype<InputEventJoypadButton>("InputEventJoypadButton",
        "new", sol::factories(
            []() { return new InputEventJoypadButton(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::input::InputEvent>(),
        "buttonIndex", sol::property(&InputEventJoypadButton::getButtonIndex, &InputEventJoypadButton::setButtonIndex),
        "pressed", sol::property(&InputEventJoypadButton::isPressed, &InputEventJoypadButton::setPressed),
        "pressure", sol::property(&InputEventJoypadButton::getPressure, &InputEventJoypadButton::setPressure),
        "cast", [](lucidfx::core::Resource* instance) {
            return new InputEventJoypadButton(godot::Object::cast_to<GodotInputEventJoypadButton>(instance->getResource()));
        }
    );
}