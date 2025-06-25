#ifndef AUDIO_STREAM_H
#define AUDIO_STREAM_H

#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotAudioStream godot::AudioStream

#include "../core/resource.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::audio {
    void bindAudioStream(sol::state_view& lua);

    class AudioStream : public lucidfx::core::Resource {
    private:
        GodotAudioStream* audioStream;
    public:
        AudioStream() {
            setAudioStream(memnew(GodotAudioStream));
        }

        AudioStream(GodotAudioStream* a) {
            setAudioStream(a);
        }

        GodotAudioStream* getAudioStream() {
            return audioStream;
        }

        void setAudioStream(GodotAudioStream* a) {
            audioStream = a;
            audioStream->reference();
            setResource(audioStream);
        }

        bool canBeSampled() {
            return audioStream->can_be_sampled();
        }

        float getLength() {
            return audioStream->get_length();
        }

        bool isMetaStream() {
            return audioStream->is_meta_stream();
        }

        bool isMonophonic() {
            return audioStream->is_monophonic();
        }
    };
}

#endif // AUDIO_STREAM_H