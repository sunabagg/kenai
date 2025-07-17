target_sources(${PROJECT_NAME} PRIVATE
        byte.cpp
        binary_data.cpp
        bind_binary_classes.cpp
        io_interface.cpp
        system_io_interface.cpp
        file_system_io.cpp
        io_manager.cpp
        custom_io_interface.h
        custom_io_interface.cpp
        bind_io_classes.cpp
        io_index.cpp
        zip_io.cpp
        moon_console.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "io"
)