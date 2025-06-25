#include "input_event_midi.h"

void lucidfx::input::bindInputEventMidi(sol::state_view& lua) {
    lua.new_usertype<InputEventMidi>("InputEventMidi",
        "new", sol::factories(
            []() { return new InputEventMidi(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::input::InputEvent>(),
        "channel", sol::property(&InputEventMidi::getChannel, &InputEventMidi::setChannel),
        "controllerNumber", sol::property(&InputEventMidi::getControllerNumber, &InputEventMidi::setControllerNumber),
        "controllerValue", sol::property(&InputEventMidi::getControllerValue, &InputEventMidi::setControllerValue),
        "instrument", sol::property(&InputEventMidi::getInstrument, &InputEventMidi::setInstrument),
        "message", sol::property(&InputEventMidi::getMessage, &InputEventMidi::setMessage),
        "pitch", sol::property(&InputEventMidi::getPitch, &InputEventMidi::setPitch),
        "pressure", sol::property(&InputEventMidi::getPressure, &InputEventMidi::setPressure),
        "velocity", sol::property(&InputEventMidi::getVelocity, &InputEventMidi::setVelocity),
        "cast", [](lucidfx::core::Resource* instance) {
            return new InputEventMidi(godot::Object::cast_to<GodotInputEventMidi>(instance->getResource()));
        }
    );
}