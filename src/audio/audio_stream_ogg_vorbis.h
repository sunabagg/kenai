#ifndef AUDIO_STREAM_OGG_VORBIS_H
#define AUDIO_STREAM_OGG_VORBIS_H

#include <godot_cpp/classes/audio_stream_ogg_vorbis.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotAudioStreamOggVorbis godot::AudioStreamOggVorbis

#include "audio_stream.h"
#include "../core/io/binary_data.h"
#include "../core/io/io_index.h"

using namespace godot;
using namespace lucidfx::core;
using namespace lucidfx::core::io;

namespace lucidfx::audio {
    void bindAudioStreamOggVorbis(sol::state_view& lua);

    class AudioStreamOggVorbis : public AudioStream {
    private:
        GodotAudioStreamOggVorbis* audioStreamOggVorbis;
    public:
        AudioStreamOggVorbis() {
            setAudioStreamOggVorbis(memnew(GodotAudioStreamOggVorbis));
        }

        AudioStreamOggVorbis(GodotAudioStreamOggVorbis* a) {
            setAudioStreamOggVorbis(a);
        }

        GodotAudioStreamOggVorbis* getAudioStreamOggVorbis() {
            return audioStreamOggVorbis;
        }

        void setAudioStreamOggVorbis(GodotAudioStreamOggVorbis* a) {
            audioStreamOggVorbis = a;
            audioStreamOggVorbis->reference();
            setAudioStream(audioStreamOggVorbis);
        }

        int getBarBeats() {
            return audioStreamOggVorbis->get_bar_beats();
        }

        void setBarBeats(int barBeats) {
            audioStreamOggVorbis->set_bar_beats(barBeats);
        }

        int getBeatCount() {
            return audioStreamOggVorbis->get_beat_count();
        }

        void setBeatCount(int beatCount) {
            audioStreamOggVorbis->set_beat_count(beatCount);
        }

        float getBpm() {
            return audioStreamOggVorbis->get_bpm();
        }

        void setBpm(float bpm) {
            audioStreamOggVorbis->set_bpm(bpm);
        }

        bool getLoop() {
            return audioStreamOggVorbis->has_loop();
        }

        void setLoop(bool loop) {
            audioStreamOggVorbis->set_loop(loop);
        }

        float getLoopOffset() {
            return audioStreamOggVorbis->get_loop_offset();
        }

        void setLoopOffset(float loopOffset) {
            audioStreamOggVorbis->set_loop_offset(loopOffset);
        }

        static AudioStreamOggVorbis* loadFromBuffer(const BinaryData& buffer) {
            return new AudioStreamOggVorbis(
                GodotAudioStreamOggVorbis::load_from_buffer(buffer.toPackedByteArray()).ptr()
            );
        }

        static AudioStreamOggVorbis* loadFromFile(lua_State* L, const std::string& path) {
            sol::state_view lua(L);
            auto ioManager = IoIndex::getIoManager(lua);
            BinaryData buffer = ioManager->loadBinary(path);
            return loadFromBuffer(buffer);
        }

        static AudioStreamOggVorbis* loadFromIoInterfacePath(IoInterface* ioInterface, const std::string& path) {
            BinaryData buffer = ioInterface->loadBinary(path);
            return loadFromBuffer(buffer);
        }
    };
}

#endif // AUDIO_STREAM_OGG_VORBIS_H