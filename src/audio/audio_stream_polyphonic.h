#ifndef AUDIO_STREAM_POLYPHONIC_H
#define AUDIO_STREAM_POLYPHONIC_H

#include <godot_cpp/classes/audio_stream_polyphonic.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotAudioStreamPolyphonic godot::AudioStreamPolyphonic

#include "audio_stream.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::audio {
    void bindAudioStreamPolyphonic(sol::state_view& lua);

    class AudioStreamPolyphonic : public AudioStream {
    private:
        GodotAudioStreamPolyphonic* audioStreamPolyphonic;
    public:
        AudioStreamPolyphonic() {
            setAudioStreamPolyphonic(memnew(GodotAudioStreamPolyphonic));
        }

        AudioStreamPolyphonic(GodotAudioStreamPolyphonic* a) {
            setAudioStreamPolyphonic(a);
        }

        GodotAudioStreamPolyphonic* getAudioStreamPolyphonic() {
            return audioStreamPolyphonic;
        }

        void setAudioStreamPolyphonic(GodotAudioStreamPolyphonic* a) {
            audioStreamPolyphonic = a;
            audioStreamPolyphonic->reference();
            setAudioStream(audioStreamPolyphonic);
        }

        int getPolyphony() {
            return audioStreamPolyphonic->get_polyphony();
        }

        void setPolyphony(int polyphony) {
            audioStreamPolyphonic->set_polyphony(polyphony);
        }
    };
}

#endif // AUDIO_STREAM_POLYPHONIC_H