target_sources(${PROJECT_NAME} PRIVATE
        byte.h
        byte.cpp
        binary_data.h
        binary_data.cpp
        bind_binary_classes.h
        bind_binary_classes.cpp
        io_interface.h
        io_interface.cpp
        system_io_interface.h
        system_io_interface.cpp
        file_system_io.h
        file_system_io.cpp
        io_manager.h 
        io_manager.cpp
        bind_io_classes.h
        bind_io_classes.cpp
        io_index.h
        io_index.cpp
        zip_io.h
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "io"
)