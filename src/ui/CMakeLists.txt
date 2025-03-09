target_sources(${PROJECT_NAME} PRIVATE
        element.h
        element.cpp
        style_box.h
        style_box.cpp
        style_box_empty.h
        style_box_empty.cpp
        canvas_item.h
        control.h
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "ui"
)