target_sources(${PROJECT_NAME} PRIVATE
        input_event.h
        input_event.cpp
        input_event_action.h
        input_event_action.cpp
        input_event_from_window.h
        input_event_from_window.cpp
        input_event_gesture.h
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "input"
)