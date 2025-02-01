target_sources(${PROJECT_NAME} PRIVATE
        base_object.h
        base_object.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "core"
)