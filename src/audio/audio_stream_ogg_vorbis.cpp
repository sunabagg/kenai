#include "audio_stream_ogg_vorbis.h"

void lucidfx::audio::bindAudioStreamOggVorbis(sol::state_view& lua) {
    lua.new_usertype<AudioStreamOggVorbis>("AudioStreamOggVorbis",
       "new", sol::factories([]() {
            return new AudioStreamOggVorbis();
        }),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, AudioStream>(),
        "cast", [](lucidfx::core::Resource* resource) { 
            return new AudioStreamOggVorbis(
                Object::cast_to<GodotAudioStreamOggVorbis>(
                    resource->getResource()
                )
            ); 
        },
        "barBeats", sol::property(&AudioStreamOggVorbis::getBarBeats, &AudioStreamOggVorbis::setBarBeats),
        "beatCount", sol::property(&AudioStreamOggVorbis::getBeatCount, &AudioStreamOggVorbis::setBeatCount),
        "bpm", sol::property(&AudioStreamOggVorbis::getBpm),
        "loop", sol::property(&AudioStreamOggVorbis::getLoop, &AudioStreamOggVorbis::setLoop),
        "loopOffset", sol::property(&AudioStreamOggVorbis::getLoopOffset, &AudioStreamOggVorbis::setLoopOffset),
        "loadFromBuffer", &AudioStreamOggVorbis::loadFromBuffer,
        "loadFromFile", &AudioStreamOggVorbis::loadFromFile,
        "loadFromIoInterfacePath", &AudioStreamOggVorbis::loadFromIoInterfacePath
    );
}