target_sources(${PROJECT_NAME} PRIVATE
        transform.h
        transform.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "spatial"
)