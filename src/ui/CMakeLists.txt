target_sources(${PROJECT_NAME} PRIVATE
        element.h
        element.cpp
        canvas_item.h
        control.h
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "ui"
)