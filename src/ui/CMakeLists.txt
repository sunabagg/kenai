target_sources(${PROJECT_NAME} PRIVATE
        style_box.h
        style_box.cpp
        style_box_empty.h
        style_box_empty.cpp
        style_box_flat.h
        style_box_flat.cpp
        style_box_line.h
        style_box_line.cpp
        style_box_texture.h
        style_box_texture.cpp
        theme.h
        theme.cpp
        control.h
        control.cpp
        base_button.h
        base_button.cpp
        button_group.h
        button_group.cpp
        bind_ui_classes.h
        bind_ui_classes.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "ui"
)