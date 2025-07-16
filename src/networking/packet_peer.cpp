#include "packet_peer.h"

namespace sunaba::networking {
    void bindPacketPeer(sol::state& lua) {
        lua.new_usertype<PacketPeer>("PacketPeer",
            "new", sol::factories(
                []() { return new PacketPeer(); }
            ),
            sol::base_classes, sol::bases<BaseObject>(),
            "isNull", &PacketPeer::isNull,
            "isValid", &PacketPeer::isValid,
            "encodeBufferMaxSize", sol::property(
                &PacketPeer::getEncodeBufferMaxSize,
                &PacketPeer::setEncodeBufferMaxSize
            ),
            "getAvailablePacketCount", &PacketPeer::getAvailablePacketCount,
            "getPacket", &PacketPeer::getPacket,
            "getPacketError", &PacketPeer::getPacketError
        );
    }
}