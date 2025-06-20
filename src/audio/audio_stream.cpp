#include "audio_stream.h"

void sunaba::audio::bindAudioStream(sol::state_view& lua) {
    lua.new_usertype<AudioStream>("AudioStream",
        "new", sol::factories([]() {
            return new AudioStream();
        }),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "canBeSampled", &AudioStream::canBeSampled,
        "getLength", &AudioStream::getLength,
        "isMetaStream", &AudioStream::isMetaStream,
        "isMonophonic", &AudioStream::isMonophonic,
        "cast", [](sunaba::core::Resource* resource) { 
            return new AudioStream(
                Object::cast_to<GodotAudioStream>(
                    resource->getResource()
                )
            ); 
        });
}