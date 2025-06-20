#include "animated_texture.h"

void sunaba::core::bindAnimatedTexture(sol::state &lua) {
    lua.new_usertype<sunaba::core::AnimatedTexture>("AnimatedTexture",
        sol::constructors< sunaba::core::AnimatedTexture()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::Texture2D>(),
        "currentFrame", sol::property(
            &sunaba::core::AnimatedTexture::getCurrentFrame, 
            &sunaba::core::AnimatedTexture::setCurrentFrame
        ),
        "frames", sol::property(
            &sunaba::core::AnimatedTexture::getFrames, 
            &sunaba::core::AnimatedTexture::setFrames
        ),
        "oneShot", sol::property(
            &sunaba::core::AnimatedTexture::getOneShot, 
            &sunaba::core::AnimatedTexture::setOneShot
        ),
        "frames", sol::property(
            &sunaba::core::AnimatedTexture::getFrames, 
            &sunaba::core::AnimatedTexture::setFrames
        ),
        "pause", sol::property(
            &sunaba::core::AnimatedTexture::getPause,
            &sunaba::core::AnimatedTexture::setPause
        ),
        "speedScale", sol::property(
            &sunaba::core::AnimatedTexture::getSpeedScale, 
            &sunaba::core::AnimatedTexture::setSpeedScale
        ),
        "getFrameDuration", &sunaba::core::AnimatedTexture::getFrameDuration,
        "getFrameTexture", &sunaba::core::AnimatedTexture::getFrameTexture,
        "setFrameDuration", &sunaba::core::AnimatedTexture::setFrameDuration,
        "setFrameTexture", &sunaba::core::AnimatedTexture::setFrameTexture,
        "cast", [](Resource* instance) {
            return new AnimatedTexture(godot::Object::cast_to<GodotAnimatedTexture>(instance->getResource()));
        }
    );
}