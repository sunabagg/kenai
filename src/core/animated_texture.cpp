#include "animated_texture.h"

void lucidware::core::bindAnimatedTexture(sol::state &lua) {
    lua.new_usertype<lucidware::core::AnimatedTexture>("AnimatedTexture",
        "new", sol::factories(
            []() { return new lucidware::core::AnimatedTexture(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::Texture2D>(),
        "currentFrame", sol::property(
            &lucidware::core::AnimatedTexture::getCurrentFrame, 
            &lucidware::core::AnimatedTexture::setCurrentFrame
        ),
        "frames", sol::property(
            &lucidware::core::AnimatedTexture::getFrames, 
            &lucidware::core::AnimatedTexture::setFrames
        ),
        "oneShot", sol::property(
            &lucidware::core::AnimatedTexture::getOneShot, 
            &lucidware::core::AnimatedTexture::setOneShot
        ),
        "frames", sol::property(
            &lucidware::core::AnimatedTexture::getFrames, 
            &lucidware::core::AnimatedTexture::setFrames
        ),
        "pause", sol::property(
            &lucidware::core::AnimatedTexture::getPause,
            &lucidware::core::AnimatedTexture::setPause
        ),
        "speedScale", sol::property(
            &lucidware::core::AnimatedTexture::getSpeedScale, 
            &lucidware::core::AnimatedTexture::setSpeedScale
        ),
        "getFrameDuration", &lucidware::core::AnimatedTexture::getFrameDuration,
        "getFrameTexture", &lucidware::core::AnimatedTexture::getFrameTexture,
        "setFrameDuration", &lucidware::core::AnimatedTexture::setFrameDuration,
        "setFrameTexture", &lucidware::core::AnimatedTexture::setFrameTexture,
        "cast", [](Resource* instance) {
            return new AnimatedTexture(godot::Object::cast_to<GodotAnimatedTexture>(instance->getResource()));
        }
    );
}