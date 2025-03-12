target_sources(${PROJECT_NAME} PRIVATE
        audio_stream.h
        audio_stream.cpp
        audio_stream_microphone.h
        audio_stream_microphone.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "audio"
)