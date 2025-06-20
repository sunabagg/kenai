#include "bit_map.h"

void sunaba::core::bindBitMap(sol::state &lua) {
    lua.new_usertype<sunaba::core::BitMap>("BitMap",
        "new", sol::factories(
            []() { return new sunaba::core::BitMap(); }),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "convertToImage", &sunaba::core::BitMap::convertToImage,
        "create", &sunaba::core::BitMap::create,
        "createFromImageAlpha", &sunaba::core::BitMap::createFromImageAlpha,
        "getBit", &sunaba::core::BitMap::getBit,
        "getBitv", &sunaba::core::BitMap::getBitv,
        "getSize", &sunaba::core::BitMap::getSize,
        "getTrueBitCount", &sunaba::core::BitMap::getTrueBitCount,
        "growMask", &sunaba::core::BitMap::growMask,
        "opaqueToPolygons", &sunaba::core::BitMap::opaqueToPolygons,
        "resize", &sunaba::core::BitMap::resize,
        "setBit", &sunaba::core::BitMap::setBit,
        "setBitRect", &sunaba::core::BitMap::setBitRect,
        "setBitv", &sunaba::core::BitMap::setBitv,
        "cast", [](Resource* instance) {
            return new BitMap(godot::Object::cast_to<GodotBitMap>(instance->getResource()));
        }
    );
}
