target_sources(${PROJECT_NAME} PRIVATE
        window.cpp
        popup.cpp
        popup_panel.cpp
        popup_menu.cpp
        accept_dialog.cpp
        confirmation_dialog.cpp
        file_dialog.cpp
        status_indicator.cpp
        bind_desktop_classes.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "desktop"
)