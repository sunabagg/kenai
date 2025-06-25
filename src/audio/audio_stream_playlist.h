#ifndef AUDIO_STREAM_PLAYLIST_H
#define AUDIO_STREAM_PLAYLIST_H

#include <godot_cpp/classes/audio_stream_playlist.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotAudioStreamPlaylist godot::AudioStreamPlaylist

#include "audio_stream.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::audio {
    void bindAudioStreamPlaylist(sol::state_view& lua);

    class AudioStreamPlaylist : public AudioStream {
    private:
        GodotAudioStreamPlaylist* audioStreamPlaylist;
    public:
        AudioStreamPlaylist() {
            setAudioStreamPlaylist(memnew(GodotAudioStreamPlaylist));
        }

        AudioStreamPlaylist(GodotAudioStreamPlaylist* a) {
            setAudioStreamPlaylist(a);
        }

        GodotAudioStreamPlaylist* getAudioStreamPlaylist() {
            return audioStreamPlaylist;
        }

        void setAudioStreamPlaylist(GodotAudioStreamPlaylist* a) {
            audioStreamPlaylist = a;
            audioStreamPlaylist->reference();
            setAudioStream(audioStreamPlaylist);
        }

        float getFadeTime() {
            return audioStreamPlaylist->get_fade_time();
        }

        void setFadeTime(float fadeTime) {
            audioStreamPlaylist->set_fade_time(fadeTime);
        }

        bool getLoop() {
            return audioStreamPlaylist->has_loop();
        }

        void setLoop(bool loop) {
            audioStreamPlaylist->set_loop(loop);
        }

        bool getShuffle() {
            return audioStreamPlaylist->get_shuffle();
        }

        void setShuffle(bool shuffle) {
            audioStreamPlaylist->set_shuffle(shuffle);
        }

        int getStreamCount() {
            return audioStreamPlaylist->get_stream_count();
        }

        void setStreamCount(int streamCount) {
            audioStreamPlaylist->set_stream_count(streamCount);
        }

        float getBpm() {
            return audioStreamPlaylist->get_bpm();
        }

        AudioStream* getListStream(int index) {
            return new AudioStream(audioStreamPlaylist->get_list_stream(index).ptr());
        }

        void setListStream(int index, AudioStream* stream) {
            audioStreamPlaylist->set_list_stream(index, stream->getAudioStream());
        }
    };
}

#endif // AUDIO_STREAM_PLAYLIST_H