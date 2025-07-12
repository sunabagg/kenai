#include "audio_stream_microphone.h"

void kenai::audio::bindAudioStreamMicrophone(sol::state_view& lua) {
    lua.new_usertype<AudioStreamMicrophone>("AudioStreamMicrophone",
        "new", sol::factories([]() {
            return new AudioStreamMicrophone();
        }),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, AudioStream>(),
        "cast", [](kenai::core::Resource* resource) { 
            return new AudioStreamMicrophone(
                Object::cast_to<GodotAudioStreamMicrophone>(
                    resource->getResource()
                )
            ); 
        });
}