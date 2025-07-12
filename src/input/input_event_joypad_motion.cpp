#include "input_event_joypad_motion.h"

void kenai::input::bindInputEventJoypadMotion(sol::state_view& lua) {
    lua.new_usertype<InputEventJoypadMotion>("InputEventJoypadMotion",
        "new", sol::factories(
            []() { return new InputEventJoypadMotion(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::input::InputEvent>(),
        "axis", sol::property(&InputEventJoypadMotion::getAxis, &InputEventJoypadMotion::setAxis),
        "axisValue", sol::property(&InputEventJoypadMotion::getAxisValue, &InputEventJoypadMotion::setAxisValue),
        "cast", [](kenai::core::Resource* instance) {
            return new InputEventJoypadMotion(godot::Object::cast_to<GodotInputEventJoypadMotion>(instance->getResource()));
        }
    );
}