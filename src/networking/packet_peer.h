#ifndef PACKET_PEER_H
#define PACKET_PEER_H

#include <godot_cpp/classes/packet_peer.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotPacketPeer godot::PacketPeer

#include "../core/base_object.h"
#include "../core/io/binary_data.h"

using namespace godot;
using namespace sunaba::core;
using namespace sunaba::core::io;

namespace sunaba::networking {
    void bindPacketPeer(sol::state& lua);

    class PacketPeer : public BaseObject {
        private:
            Ref<GodotPacketPeer> packetPeer;
        public:
            PacketPeer() {
                setPacketPeer(
                    Ref<GodotPacketPeer>(memnew(GodotPacketPeer))
                );
            }

            PacketPeer(Ref<GodotPacketPeer> peer) {
                setPacketPeer(peer);
            }

            Ref<GodotPacketPeer> getPacketPeer() {
                return packetPeer;
            }

            void setPacketPeer(Ref<GodotPacketPeer> peer) {
                packetPeer = peer;
            }

            bool isNull() {
                return packetPeer.is_null();
            }

            bool isValid() {
                return packetPeer.is_valid();
            }

            int getEncodeBufferMaxSize() {
                return packetPeer->get_encode_buffer_max_size();
            }

            void setEncodeBufferMaxSize(int val) {
                packetPeer->set_encode_buffer_max_size(val);
            }

            int getAvailablePacketCount() {
                return packetPeer->get_available_packet_count();
            }

            BinaryData* getPacket() {
                return new BinaryData(packetPeer->get_packet());
            }
    };
}

#endif //PACKET_PEER_H