target_sources(${PROJECT_NAME} PRIVATE
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
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "io"
)