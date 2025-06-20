#include "input_event_mouse_motion.h"

void sunaba::input::bindInputEventMouseMotion(sol::state_view& lua) {
    lua.new_usertype<InputEventMouseMotion>("InputEventMouseMotion",
        "new", sol::factories(
            []() { return new InputEventMouseMotion(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::input::InputEvent, sunaba::input::InputEventFromWindow, sunaba::input::InputEventWithModifiers, sunaba::input::InputEventMouse>(),
        "penInverted", sol::property(&InputEventMouseMotion::getPenInverted, &InputEventMouseMotion::setPenInverted),
        "pressure", sol::property(&InputEventMouseMotion::getPressure, &InputEventMouseMotion::setPressure),
        "relative", sol::property(&InputEventMouseMotion::getRelative, &InputEventMouseMotion::setRelative),
        "screenRelative", sol::property(&InputEventMouseMotion::getScreenRelative, &InputEventMouseMotion::setScreenRelative),
        "screenVelocity", sol::property(&InputEventMouseMotion::getScreenVelocity, &InputEventMouseMotion::setScreenVelocity),
        "tilt", sol::property(&InputEventMouseMotion::getTilt, &InputEventMouseMotion::setTilt),
        "velocity", sol::property(&InputEventMouseMotion::getVelocity, &InputEventMouseMotion::setVelocity),
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventMouseMotion(godot::Object::cast_to<GodotInputEventMouseMotion>(instance->getResource()));
        }
    );
}