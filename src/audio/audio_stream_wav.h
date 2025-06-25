#ifndef AUDIO_STREAM_WAV_H
#define AUDIO_STREAM_WAV_H

#include <godot_cpp/classes/audio_stream_wav.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotAudioStreamWav godot::AudioStreamWAV

#include "audio_stream.h"
#include "../core/io/binary_data.h"
#include "../core/io/io_index.h"
#include "../core/convert_godot_lua.h"

using namespace godot;
using namespace lucidfx::core;
using namespace lucidfx::core::io;

namespace lucidfx::audio {
    void bindAudioStreamWav(sol::state_view& lua);

    class AudioStreamWav : public AudioStream {
    private:
    AudioStreamWAV* audioStreamWav;
    public:
        AudioStreamWav() {
            setAudioStreamWav(memnew(AudioStreamWAV));
        }

        AudioStreamWav(AudioStreamWAV* a) {
            setAudioStreamWav(a);
        }

        AudioStreamWAV* getAudioStreamWav() {
            return audioStreamWav;
        }

        void setAudioStreamWav(AudioStreamWAV* a) {
            audioStreamWav = a;
            audioStreamWav->reference();
            setAudioStream(audioStreamWav);
        }

        BinaryData* getData() {
            return new BinaryData(audioStreamWav->get_data());
        }

        void setData(BinaryData* data) {
            audioStreamWav->set_data(data->toPackedByteArray());
        }

        int getFormat() {
            return audioStreamWav->get_format();
        }

        void setFormat(int format) {
            audioStreamWav->set_format(static_cast<AudioStreamWAV::Format>(format));
        }

        int getLoopBegin() {
            return audioStreamWav->get_loop_begin();
        }

        void setLoopBegin(int loopBegin) {
            audioStreamWav->set_loop_begin(loopBegin);
        }

        int getLoopEnd() {
            return audioStreamWav->get_loop_end();
        }

        void setLoopEnd(int loopEnd) {
            audioStreamWav->set_loop_end(loopEnd);
        }

        int getLoopMode() {
            return audioStreamWav->get_loop_mode();
        }

        void setLoopMode(int loopMode) {
            audioStreamWav->set_loop_mode(static_cast<AudioStreamWAV::LoopMode>(loopMode));
        }

        int getMixRate() {
            return audioStreamWav->get_mix_rate();
        }

        void setMixRate(int mixRate) {
            audioStreamWav->set_mix_rate(mixRate);
        }

        bool isStereo() {
            return audioStreamWav->is_stereo();
        }

        void setStereo(bool stereo) {
            audioStreamWav->set_stereo(stereo);
        }

        static AudioStreamWav* loadFromBuffer(const BinaryData& buffer, const sol::table& table) {
            return new AudioStreamWav(
                GodotAudioStreamWav::load_from_buffer(buffer.toPackedByteArray(), to_dictionary(table)).ptr()
            );
        }

        static AudioStreamWav* loadFromFile(lua_State* L, const std::string& path, const sol::table& table) {
            sol::state_view lua(L);
            IoManager* ioManager = IoIndex::getIoManager(lua);
            BinaryData buffer = ioManager->loadBinary(path);
            return loadFromBuffer(buffer, table);
        }

        static AudioStreamWav* loadFromIoInterfacePath(IoInterface* ioInterface, const std::string& path, const sol::table& table) {
            BinaryData buffer = ioInterface->loadBinary(path);
            return loadFromBuffer(buffer, table);
        }
    };
}

#endif // AUDIO_STREAM_WAV_H