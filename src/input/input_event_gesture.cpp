#include "input_event_gesture.h"

void sunaba::input::bindInputEventGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventGesture>("InputEventGesture",
        sol::constructors<InputEventGesture(), InputEventGesture(GodotInputEventGesture*)>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::input::InputEvent>(),
        "position", sol::property(&InputEventGesture::getPosition, &InputEventGesture::setPosition),
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventGesture(Object::cast_to<GodotInputEventGesture*>(instance->getResource()));
        }
    );
}