#include "audio_stream_wav.h"

void lucidfx::audio::bindAudioStreamWav(sol::state_view& lua) {
    lua.new_usertype<AudioStreamWav>("AudioStreamWav",
        "new", sol::factories([]() {
            return new AudioStreamWav();
        }),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, AudioStream>(),
        "cast", [](lucidfx::core::Resource* resource) { 
            return new AudioStreamWav(
                Object::cast_to<AudioStreamWAV>(
                    resource->getResource()
                )
            ); 
        },
        "data", sol::property(&AudioStreamWav::getData, &AudioStreamWav::setData),
        "format", sol::property(&AudioStreamWav::getFormat, &AudioStreamWav::setFormat),
        "loopBegin", sol::property(&AudioStreamWav::getLoopBegin, &AudioStreamWav::setLoopBegin),
        "loopEnd", sol::property(&AudioStreamWav::getLoopEnd, &AudioStreamWav::setLoopEnd),
        "loopMode", sol::property(&AudioStreamWav::getLoopMode, &AudioStreamWav::setLoopMode),
        "mixRate", sol::property(&AudioStreamWav::getMixRate, &AudioStreamWav::setMixRate),
        "stereo", sol::property(&AudioStreamWav::isStereo, &AudioStreamWav::setStereo),
        "loadFromBuffer", &AudioStreamWav::loadFromBuffer,
        "loadFromFile", &AudioStreamWav::loadFromFile,
        "loadFromIoInterfacePath", &AudioStreamWav::loadFromIoInterfacePath
    );
}