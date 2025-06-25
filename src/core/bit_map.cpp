#include "bit_map.h"

void lucidware::core::bindBitMap(sol::state &lua) {
    lua.new_usertype<lucidware::core::BitMap>("BitMap",
        "new", sol::factories(
            []() { return new lucidware::core::BitMap(); }),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "convertToImage", &lucidware::core::BitMap::convertToImage,
        "create", &lucidware::core::BitMap::create,
        "createFromImageAlpha", &lucidware::core::BitMap::createFromImageAlpha,
        "getBit", &lucidware::core::BitMap::getBit,
        "getBitv", &lucidware::core::BitMap::getBitv,
        "getSize", &lucidware::core::BitMap::getSize,
        "getTrueBitCount", &lucidware::core::BitMap::getTrueBitCount,
        "growMask", &lucidware::core::BitMap::growMask,
        "opaqueToPolygons", &lucidware::core::BitMap::opaqueToPolygons,
        "resize", &lucidware::core::BitMap::resize,
        "setBit", &lucidware::core::BitMap::setBit,
        "setBitRect", &lucidware::core::BitMap::setBitRect,
        "setBitv", &lucidware::core::BitMap::setBitv,
        "cast", [](Resource* instance) {
            return new BitMap(godot::Object::cast_to<GodotBitMap>(instance->getResource()));
        }
    );
}
