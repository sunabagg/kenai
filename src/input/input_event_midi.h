#ifndef INPUT_EVENT_MIDI_H
#define INPUT_EVENT_MIDI_H

#include <godot_cpp/classes/input_event_midi.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotInputEventMidi godot::InputEventMIDI

#include "input_event.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::input {
    void bindInputEventMidi(sol::state_view& lua);

    class InputEventMidi : public lucidware::input::InputEvent {
    private:
        GodotInputEventMidi* event;
    public:
        InputEventMidi(GodotInputEventMidi* e) {
            setInputEventMidi(e);
        }

        InputEventMidi() {
            setInputEventMidi(memnew(GodotInputEventMidi));
        }

        GodotInputEventMidi* getInputEventMidi() const {
            return event;
        }

        void setInputEventMidi(GodotInputEventMidi* e) {
            event = e;
            event->reference();
            setInputEvent(e);
        }

        int getChannel() {
            return event->get_channel();
        }

        void setChannel(int channel) {
            event->set_channel(channel);
        }

        int getControllerNumber() {
            return event->get_controller_number();
        }

        void setControllerNumber(int number) {
            event->set_controller_number(number);
        }

        int getControllerValue() {
            return event->get_controller_value();
        }

        void setControllerValue(int value) {
            event->set_controller_value(value);
        }

        int getInstrument() {
            return event->get_instrument();
        }

        void setInstrument(int instrument) {
            event->set_instrument(instrument);
        }

        int getMessage() {
            return event->get_message();
        }

        void setMessage(int message) {
            event->set_message(static_cast<MIDIMessage>(message));
        }

        int getPitch() {
            return event->get_pitch();
        }

        void setPitch(int pitch) {
            event->set_pitch(pitch);
        }

        int getPressure() {
            return event->get_pressure();
        }

        void setPressure(int pressure) {
            event->set_pressure(pressure);
        }

        int getVelocity() {
            return event->get_velocity();
        }

        void setVelocity(int velocity) {
            event->set_velocity(velocity);
        }
    };
}

#endif // INPUT_EVENT_MIDI_H