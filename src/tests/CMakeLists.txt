target_sources(${PROJECT_NAME} PRIVATE
        scene_test.h
        scene_test.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "tests"
)