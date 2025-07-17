target_sources(${PROJECT_NAME} PRIVATE
        packet_peer.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "networking"
)