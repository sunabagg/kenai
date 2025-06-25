#include "canvas_item_material.h"

void lucidfx::core::bindCanvasItemMaterial(sol::state_view &lua) {
    lua.new_usertype<CanvasItemMaterial>("CanvasItemMaterial",
        "new", sol::factories(
            []() { return new CanvasItemMaterial(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Material>(),
        "blendMode", sol::property(&CanvasItemMaterial::getBlendMode, &CanvasItemMaterial::setBlendMode),
        "lightMode", sol::property(&CanvasItemMaterial::getLightMode, &CanvasItemMaterial::setLightMode),
        "particlesAnimHFrames", sol::property(&CanvasItemMaterial::getParticlesAnimHFrames, &CanvasItemMaterial::setParticlesAnimHFrames));
}