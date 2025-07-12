#include "bit_map.h"

void kenai::core::bindBitMap(sol::state &lua) {
    lua.new_usertype<kenai::core::BitMap>("BitMap",
        "new", sol::factories(
            []() { return new kenai::core::BitMap(); }),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource>(),
        "convertToImage", &kenai::core::BitMap::convertToImage,
        "create", &kenai::core::BitMap::create,
        "createFromImageAlpha", &kenai::core::BitMap::createFromImageAlpha,
        "getBit", &kenai::core::BitMap::getBit,
        "getBitv", &kenai::core::BitMap::getBitv,
        "getSize", &kenai::core::BitMap::getSize,
        "getTrueBitCount", &kenai::core::BitMap::getTrueBitCount,
        "growMask", &kenai::core::BitMap::growMask,
        "opaqueToPolygons", &kenai::core::BitMap::opaqueToPolygons,
        "resize", &kenai::core::BitMap::resize,
        "setBit", &kenai::core::BitMap::setBit,
        "setBitRect", &kenai::core::BitMap::setBitRect,
        "setBitv", &kenai::core::BitMap::setBitv,
        "cast", [](Resource* instance) {
            return new BitMap(godot::Object::cast_to<GodotBitMap>(instance->getResource()));
        }
    );
}
