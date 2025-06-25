#include "audio_stream.h"

void lucidfx::audio::bindAudioStream(sol::state_view& lua) {
    lua.new_usertype<AudioStream>("AudioStream",
        "new", sol::factories([]() {
            return new AudioStream();
        }),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
        "canBeSampled", &AudioStream::canBeSampled,
        "getLength", &AudioStream::getLength,
        "isMetaStream", &AudioStream::isMetaStream,
        "isMonophonic", &AudioStream::isMonophonic,
        "cast", [](lucidfx::core::Resource* resource) { 
            return new AudioStream(
                Object::cast_to<GodotAudioStream>(
                    resource->getResource()
                )
            ); 
        });
}