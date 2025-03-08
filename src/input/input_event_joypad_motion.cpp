#include "input_event_joypad_motion.h"

void sunaba::input::bindInputEventJoypadMotion(sol::state_view& lua) {
    lua.new_usertype<InputEventJoypadMotion>("InputEventJoypadMotion",
        sol::constructors<InputEventJoypadMotion(), InputEventJoypadMotion(GodotInputEventJoypadMotion*)>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::input::InputEvent>(),
        "axis", sol::property(&InputEventJoypadMotion::getAxis, &InputEventJoypadMotion::setAxis),
        "axisValue", sol::property(&InputEventJoypadMotion::getAxisValue, &InputEventJoypadMotion::setAxisValue),
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventJoypadMotion(Object::cast_to<GodotInputEventJoypadMotion*>(instance->getResource()));
        }
    );
}