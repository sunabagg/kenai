#include "audio_stream.h"

void lucidware::audio::bindAudioStream(sol::state_view& lua) {
    lua.new_usertype<AudioStream>("AudioStream",
        "new", sol::factories([]() {
            return new AudioStream();
        }),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "canBeSampled", &AudioStream::canBeSampled,
        "getLength", &AudioStream::getLength,
        "isMetaStream", &AudioStream::isMetaStream,
        "isMonophonic", &AudioStream::isMonophonic,
        "cast", [](lucidware::core::Resource* resource) { 
            return new AudioStream(
                Object::cast_to<GodotAudioStream>(
                    resource->getResource()
                )
            ); 
        });
}