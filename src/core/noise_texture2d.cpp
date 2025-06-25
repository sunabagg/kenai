#include "noise_texture2d.h"

void lucidware::core::bindNoiseTexture2D(sol::state_view& lua) {
    lua.new_usertype<NoiseTexture2D>("NoiseTexture2D",
        "new", sol::factories(
            []() { return new NoiseTexture2D(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::Texture2D>(),
        "normalMap", sol::property(&NoiseTexture2D::isAsNormalMap, &NoiseTexture2D::setAsNormalMap),
        "bumpStrength", sol::property(&NoiseTexture2D::getBumpStrength, &NoiseTexture2D::setBumpStrength),
        "colorRamp", sol::property(&NoiseTexture2D::getColorRamp, &NoiseTexture2D::setColorRamp),
        "in3dSpace", sol::property(&NoiseTexture2D::isIn3dSpace, &NoiseTexture2D::setIn3dSpace),
        "generateMipmaps", sol::property(&NoiseTexture2D::isGenerateMipmaps, &NoiseTexture2D::setGenerateMipmaps),
        "height", sol::property(&NoiseTexture2D::getHeight, &NoiseTexture2D::setHeight),
        "invert", sol::property(&NoiseTexture2D::getInvert, &NoiseTexture2D::setInvert),
        "noise", sol::property(&NoiseTexture2D::getNoise, &NoiseTexture2D::setNoise),
        "normalize", sol::property(&NoiseTexture2D::getNormalize, &NoiseTexture2D::setNormalize),
        "seamless", sol::property(&NoiseTexture2D::getSeamless, &NoiseTexture2D::setSeamless),
        "seamlessBlendSkirt", sol::property(&NoiseTexture2D::getSeamlessBlendSkirt, &NoiseTexture2D::setSeamlessBlendSkirt),
        "width", sol::property(&NoiseTexture2D::getWidth, &NoiseTexture2D::setWidth),
        "cast", [](Resource* instance) {
            return new NoiseTexture2D(godot::Object::cast_to<GodotNoiseTexture2D>(instance->getResource()));
        }
    );
}