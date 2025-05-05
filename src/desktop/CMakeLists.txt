target_sources(${PROJECT_NAME} PRIVATE
        window.h
        window.cpp
        popup.h
        popup.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "desktop"
)