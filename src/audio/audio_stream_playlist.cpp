#include "audio_stream_playlist.h"

void kenai::audio::bindAudioStreamPlaylist(sol::state_view& lua) {
    lua.new_usertype<AudioStreamPlaylist>("AudioStreamPlaylist",
        "new", sol::factories([]() {
            return new AudioStreamPlaylist();
        }),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, AudioStream>(),
        "cast", [](kenai::core::Resource* resource) { 
            return new AudioStreamPlaylist(
                Object::cast_to<GodotAudioStreamPlaylist>(
                    resource->getResource()
                )
            ); 
        },
        "fadeTime", sol::property(&AudioStreamPlaylist::getFadeTime, &AudioStreamPlaylist::setFadeTime),
        "loop", sol::property(&AudioStreamPlaylist::getLoop, &AudioStreamPlaylist::setLoop),
        "shuffle", sol::property(&AudioStreamPlaylist::getShuffle, &AudioStreamPlaylist::setShuffle),
        "streamCount", sol::property(&AudioStreamPlaylist::getStreamCount),
        "getListStream", &AudioStreamPlaylist::getListStream,
        "setListStream", &AudioStreamPlaylist::setListStream
    );
}