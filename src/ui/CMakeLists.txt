target_sources(${PROJECT_NAME} PRIVATE
        element.h
        element.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "ui"
)