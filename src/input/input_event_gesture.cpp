#include "input_event_gesture.h"

void lucidware::input::bindInputEventGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventGesture>("InputEventGesture",
        "new", sol::factories(
            []() { return new InputEventGesture(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::input::InputEvent>(),
        "position", sol::property(&InputEventGesture::getPosition, &InputEventGesture::setPosition),
        "cast", [](lucidware::core::Resource* instance) {
            return new InputEventGesture(godot::Object::cast_to<GodotInputEventGesture>(instance->getResource()));
        }
    );
}