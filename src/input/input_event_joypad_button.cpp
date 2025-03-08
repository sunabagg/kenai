#include "input_event_joypad_button.h"

void sunaba::input::bindInputEventJoypadButton(sol::state_view& lua) {
    lua.new_usertype<InputEventJoypadButton>("InputEventJoypadButton",
        sol::constructors<InputEventJoypadButton(), InputEventJoypadButton(GodotInputEventJoypadButton*)>(),
        sol::base_classes, sol::bases<sunaba::input::InputEvent>(),
        "buttonIndex", sol::property(&InputEventJoypadButton::getButtonIndex, &InputEventJoypadButton::setButtonIndex),
        "pressed", sol::property(&InputEventJoypadButton::isPressed, &InputEventJoypadButton::setPressed),
        "pressure", sol::property(&InputEventJoypadButton::getPressure, &InputEventJoypadButton::setPressure),
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventJoypadButton(static_cast<GodotInputEventJoypadButton*>(instance->getResource()));
        }
    );
}