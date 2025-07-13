target_sources(${PROJECT_NAME} PRIVATE
        packet_peer.h
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "networking"
)