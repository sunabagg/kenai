#include "bit_map.h"

void lucidfx::core::bindBitMap(sol::state &lua) {
    lua.new_usertype<lucidfx::core::BitMap>("BitMap",
        "new", sol::factories(
            []() { return new lucidfx::core::BitMap(); }),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
        "convertToImage", &lucidfx::core::BitMap::convertToImage,
        "create", &lucidfx::core::BitMap::create,
        "createFromImageAlpha", &lucidfx::core::BitMap::createFromImageAlpha,
        "getBit", &lucidfx::core::BitMap::getBit,
        "getBitv", &lucidfx::core::BitMap::getBitv,
        "getSize", &lucidfx::core::BitMap::getSize,
        "getTrueBitCount", &lucidfx::core::BitMap::getTrueBitCount,
        "growMask", &lucidfx::core::BitMap::growMask,
        "opaqueToPolygons", &lucidfx::core::BitMap::opaqueToPolygons,
        "resize", &lucidfx::core::BitMap::resize,
        "setBit", &lucidfx::core::BitMap::setBit,
        "setBitRect", &lucidfx::core::BitMap::setBitRect,
        "setBitv", &lucidfx::core::BitMap::setBitv,
        "cast", [](Resource* instance) {
            return new BitMap(godot::Object::cast_to<GodotBitMap>(instance->getResource()));
        }
    );
}
