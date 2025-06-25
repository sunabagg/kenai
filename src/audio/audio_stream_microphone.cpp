#include "audio_stream_microphone.h"

void lucidware::audio::bindAudioStreamMicrophone(sol::state_view& lua) {
    lua.new_usertype<AudioStreamMicrophone>("AudioStreamMicrophone",
        "new", sol::factories([]() {
            return new AudioStreamMicrophone();
        }),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, AudioStream>(),
        "cast", [](lucidware::core::Resource* resource) { 
            return new AudioStreamMicrophone(
                Object::cast_to<GodotAudioStreamMicrophone>(
                    resource->getResource()
                )
            ); 
        });
}