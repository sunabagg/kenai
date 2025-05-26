target_sources(${PROJECT_NAME} PRIVATE
        window.h
        window.cpp
        popup.h
        popup.cpp
        popup_panel.h
        popup_panel.cpp
        popup_menu.h
        popup_menu.cpp
        bind_desktop_classes.h
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "desktop"
)