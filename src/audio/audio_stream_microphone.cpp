#include "audio_stream_microphone.h"

void sunaba::audio::bindAudioStreamMicrophone(sol::state_view& lua) {
    lua.new_usertype<AudioStreamMicrophone>("AudioStreamMicrophone",
        "new", sol::factories([]() {
            return new AudioStreamMicrophone();
        }),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, AudioStream>(),
        "cast", [](sunaba::core::Resource* resource) { 
            return new AudioStreamMicrophone(
                Object::cast_to<GodotAudioStreamMicrophone>(
                    resource->getResource()
                )
            ); 
        });
}