#include "audio_stream_microphone.h"

void lucidfx::audio::bindAudioStreamMicrophone(sol::state_view& lua) {
    lua.new_usertype<AudioStreamMicrophone>("AudioStreamMicrophone",
        "new", sol::factories([]() {
            return new AudioStreamMicrophone();
        }),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, AudioStream>(),
        "cast", [](lucidfx::core::Resource* resource) { 
            return new AudioStreamMicrophone(
                Object::cast_to<GodotAudioStreamMicrophone>(
                    resource->getResource()
                )
            ); 
        });
}