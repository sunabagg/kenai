target_sources(${PROJECT_NAME} PRIVATE
        audio_stream.h
        audio_stream.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "audio"
)