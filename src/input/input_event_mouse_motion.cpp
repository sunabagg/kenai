#include "input_event_mouse_motion.h"

void lucidware::input::bindInputEventMouseMotion(sol::state_view& lua) {
    lua.new_usertype<InputEventMouseMotion>("InputEventMouseMotion",
        "new", sol::factories(
            []() { return new InputEventMouseMotion(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::input::InputEvent, lucidware::input::InputEventFromWindow, lucidware::input::InputEventWithModifiers, lucidware::input::InputEventMouse>(),
        "penInverted", sol::property(&InputEventMouseMotion::getPenInverted, &InputEventMouseMotion::setPenInverted),
        "pressure", sol::property(&InputEventMouseMotion::getPressure, &InputEventMouseMotion::setPressure),
        "relative", sol::property(&InputEventMouseMotion::getRelative, &InputEventMouseMotion::setRelative),
        "screenRelative", sol::property(&InputEventMouseMotion::getScreenRelative, &InputEventMouseMotion::setScreenRelative),
        "screenVelocity", sol::property(&InputEventMouseMotion::getScreenVelocity, &InputEventMouseMotion::setScreenVelocity),
        "tilt", sol::property(&InputEventMouseMotion::getTilt, &InputEventMouseMotion::setTilt),
        "velocity", sol::property(&InputEventMouseMotion::getVelocity, &InputEventMouseMotion::setVelocity),
        "cast", [](lucidware::core::Resource* instance) {
            return new InputEventMouseMotion(godot::Object::cast_to<GodotInputEventMouseMotion>(instance->getResource()));
        }
    );
}