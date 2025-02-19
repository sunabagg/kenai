target_sources(${PROJECT_NAME} PRIVATE
        io_interface.h
        system_io_interface.h
        system_io_interface.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "io"
)