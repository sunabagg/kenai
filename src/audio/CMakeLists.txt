target_sources(${PROJECT_NAME} PRIVATE
        audio_stream.cpp
        audio_stream_microphone.cpp
        audio_stream_ogg_vorbis.cpp
        audio_stream_playlist.cpp
        audio_stream_polyphonic.cpp
        audio_stream_randomizer.cpp
        audio_stream_synchronized.cpp
        audio_stream_wav.cpp
        audio_stream.cpp
        audio_stream_microphone.cpp
        audio_stream_ogg_vorbis.cpp
        audio_stream_playlist.cpp
        audio_stream_polyphonic.cpp
        audio_stream_randomizer.cpp
        audio_stream_synchronized.cpp
        audio_stream_wav.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "audio"
)