#include "audio_stream_polyphonic.h"

void sunaba::audio::bindAudioStreamPolyphonic(sol::state_view& lua) {
    lua.new_usertype<AudioStreamPolyphonic>("AudioStreamPolyphonic",
        "new", sol::factories([]() {
            return new AudioStreamPolyphonic();
        }),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, AudioStream>(),
        "cast", [](sunaba::core::Resource* resource) { 
            return new AudioStreamPolyphonic(
                Object::cast_to<GodotAudioStreamPolyphonic>(
                    resource->getResource()
                )
            ); 
        },
        "polyphony", sol::property(&AudioStreamPolyphonic::getPolyphony, &AudioStreamPolyphonic::setPolyphony)
    );
}