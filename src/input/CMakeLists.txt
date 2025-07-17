target_sources(${PROJECT_NAME} PRIVATE
        input_event.cpp
        input_event_with_modifiers.cpp
        input_event_action.cpp
        input_event_from_window.cpp
        input_event_gesture.cpp
        input_event_joypad_button.cpp
        input_event_joypad_motion.cpp
        input_event_key.cpp
        input_event_magnify_gesture.cpp
        input_event_midi.cpp
        input_event_mouse.cpp
        input_event_mouse_button.cpp
        input_event_mouse_motion.cpp
        input_event_pan_gesture.cpp
        input_event_screen_drag.cpp
        input_event_screen_touch.cpp
        input_service.cpp
        shortcut.cpp
        bind_input_classes.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "input"
)