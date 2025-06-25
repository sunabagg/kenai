#ifndef AUDIO_STREAM_MICROPHONE_H
#define AUDIO_STREAM_MICROPHONE_H

#include <godot_cpp/classes/audio_stream_microphone.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotAudioStreamMicrophone godot::AudioStreamMicrophone

#include "audio_stream.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::audio {
    void bindAudioStreamMicrophone(sol::state_view& lua);

    class AudioStreamMicrophone : public AudioStream {
    private:
        GodotAudioStreamMicrophone* audioStreamMicrophone;
    public:
        AudioStreamMicrophone() {
            setAudioStreamMicrophone(memnew(GodotAudioStreamMicrophone));
        }

        AudioStreamMicrophone(GodotAudioStreamMicrophone* a) {
            setAudioStreamMicrophone(a);
        }

        GodotAudioStreamMicrophone* getAudioStreamMicrophone() {
            return audioStreamMicrophone;
        }

        void setAudioStreamMicrophone(GodotAudioStreamMicrophone* a) {
            audioStreamMicrophone = a;
            audioStreamMicrophone->reference();
            setAudioStream(audioStreamMicrophone);
        }
    };
}

#endif // AUDIO_STREAM_MICROPHONE_H