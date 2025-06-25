#ifndef AUDIO_STREAM_RANDOMIZER_H
#define AUDIO_STREAM_RANDOMIZER_H

#include <godot_cpp/classes/audio_stream_randomizer.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotAudioStreamRandomizer godot::AudioStreamRandomizer

#include "audio_stream.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::audio {
    void bindAudioStreamRandomizer(sol::state_view& lua);

    class AudioStreamRandomizer : public AudioStream {
    private:
        GodotAudioStreamRandomizer* audioStreamRandomizer;
    public:
        AudioStreamRandomizer() {
            setAudioStreamRandomizer(memnew(GodotAudioStreamRandomizer));
        }

        AudioStreamRandomizer(GodotAudioStreamRandomizer* a) {
            setAudioStreamRandomizer(a);
        }

        GodotAudioStreamRandomizer* getAudioStreamRandomizer() {
            return audioStreamRandomizer;
        }

        void setAudioStreamRandomizer(GodotAudioStreamRandomizer* a) {
            audioStreamRandomizer = a;
            audioStreamRandomizer->reference();
            setAudioStream(audioStreamRandomizer);
        }

        int getPlaybackMode() {
            return audioStreamRandomizer->get_playback_mode();
        }

        void setPlaybackMode(int playbackMode) {
            audioStreamRandomizer->set_playback_mode(static_cast<GodotAudioStreamRandomizer::PlaybackMode>(playbackMode));
        }

        float getRandomPitch() {
            return audioStreamRandomizer->get_random_pitch();
        }

        void setRandomPitch(float randomPitch) {
            audioStreamRandomizer->set_random_pitch(randomPitch);
        }

        float getRandomVolumeOffsetDb() {
            return audioStreamRandomizer->get_random_volume_offset_db();
        }

        void setRandomVolumeOffsetDb(float randomVolumeOffsetDb) {
            audioStreamRandomizer->set_random_volume_offset_db(randomVolumeOffsetDb);
        }

        int getStreamsCount() {
            return audioStreamRandomizer->get_streams_count();
        }

        void setStreamsCount(int streamsCount) {
            audioStreamRandomizer->set_streams_count(streamsCount);
        }

        void addStream(int index, AudioStream* stream, float weight) {
            audioStreamRandomizer->add_stream(index, stream->getAudioStream(), weight);
        }

        AudioStream* getStream(int index) {
            return new AudioStream(audioStreamRandomizer->get_stream(index).ptr());
        }

        float getStreamProbabilityWeight(int index) {
            return audioStreamRandomizer->get_stream_probability_weight(index);
        }

        void moveStream(int fromIndex, int toIndex) {
            audioStreamRandomizer->move_stream(fromIndex, toIndex);
        }

        void removeStream(int index) {
            audioStreamRandomizer->remove_stream(index);
        }

        void setStream(int index, AudioStream* stream) {
            audioStreamRandomizer->set_stream(index, stream->getAudioStream());
        }

        void setStreamProbabilityWeight(int index, float weight) {
            audioStreamRandomizer->set_stream_probability_weight(index, weight);
        }
    };
}

#endif // AUDIO_STREAM_RANDOMIZER_H