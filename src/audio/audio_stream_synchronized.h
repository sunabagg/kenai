#ifndef AUDIO_STREAM_SYNCHRONIZED_H
#define AUDIO_STREAM_SYNCHRONIZED_H

#include <godot_cpp/classes/audio_stream_synchronized.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotAudioStreamSynchronized godot::AudioStreamSynchronized

#include "audio_stream.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::audio {
    void bindAudioStreamSynchronized(sol::state_view& lua);

    class AudioStreamSynchronized : public AudioStream {
    private:
        GodotAudioStreamSynchronized* audioStreamSynchronized;
    public:
        AudioStreamSynchronized() {
            setAudioStreamSynchronized(memnew(GodotAudioStreamSynchronized));
        }

        AudioStreamSynchronized(GodotAudioStreamSynchronized* a) {
            setAudioStreamSynchronized(a);
        }

        GodotAudioStreamSynchronized* getAudioStreamSynchronized() {
            return audioStreamSynchronized;
        }

        void setAudioStreamSynchronized(GodotAudioStreamSynchronized* a) {
            audioStreamSynchronized = a;
            audioStreamSynchronized->reference();
            setAudioStream(audioStreamSynchronized);
        }

        int getStreamCount() {
            return audioStreamSynchronized->get_stream_count();
        }

        void setStreamCount(int streamCount) {
            audioStreamSynchronized->set_stream_count(streamCount);
        }

        AudioStream* getSyncStream(int index) {
            return new AudioStream(audioStreamSynchronized->get_sync_stream(index).ptr());
        }

        float getSyncStreamVolume(int index) {
            return audioStreamSynchronized->get_sync_stream_volume(index);
        }

        void setSyncStream(int index, AudioStream* stream) {
            audioStreamSynchronized->set_sync_stream(index, stream->getAudioStream());
        }

        void setSyncStreamVolume(int index, float volume) {
            audioStreamSynchronized->set_sync_stream_volume(index, volume);
        }
    };
}
#endif // AUDIO_STREAM_SYNCHRONIZED_H