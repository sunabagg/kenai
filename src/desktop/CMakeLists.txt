target_sources(${PROJECT_NAME} PRIVATE
        window.h
        window.cpp
        popup.h
        popup.cpp
        popup_panel.h
        popup_panel.cpp
        popup_menu.h
        popup_menu.cpp
        accept_dialog.h
        bind_desktop_classes.h
        bind_desktop_classes.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "desktop"
)