#include "input_event_screen_drag.h"

void lucidware::input::bindInputEventScreenDrag(sol::state_view& lua) {
    lua.new_usertype<InputEventScreenDrag>("InputEventScreenDrag",
        "new", sol::factories(
            []() { return new InputEventScreenDrag(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::input::InputEvent, lucidware::input::InputEventFromWindow>(),
        "index", sol::property(&InputEventScreenDrag::getIndex, &InputEventScreenDrag::setIndex),
        "penInverted", sol::property(&InputEventScreenDrag::getPenInverted, &InputEventScreenDrag::setPenInverted),
        "position", sol::property(&InputEventScreenDrag::getPosition, &InputEventScreenDrag::setPosition),
        "cast", [](lucidware::core::Resource* instance) {
            return new InputEventScreenDrag(godot::Object::cast_to<GodotInputEventScreenDrag>(instance->getResource()));
        }
    );
}