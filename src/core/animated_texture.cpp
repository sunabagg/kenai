#include "animated_texture.h"

void lucidfx::core::bindAnimatedTexture(sol::state &lua) {
    lua.new_usertype<lucidfx::core::AnimatedTexture>("AnimatedTexture",
        "new", sol::factories(
            []() { return new lucidfx::core::AnimatedTexture(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::Texture2D>(),
        "currentFrame", sol::property(
            &lucidfx::core::AnimatedTexture::getCurrentFrame, 
            &lucidfx::core::AnimatedTexture::setCurrentFrame
        ),
        "frames", sol::property(
            &lucidfx::core::AnimatedTexture::getFrames, 
            &lucidfx::core::AnimatedTexture::setFrames
        ),
        "oneShot", sol::property(
            &lucidfx::core::AnimatedTexture::getOneShot, 
            &lucidfx::core::AnimatedTexture::setOneShot
        ),
        "frames", sol::property(
            &lucidfx::core::AnimatedTexture::getFrames, 
            &lucidfx::core::AnimatedTexture::setFrames
        ),
        "pause", sol::property(
            &lucidfx::core::AnimatedTexture::getPause,
            &lucidfx::core::AnimatedTexture::setPause
        ),
        "speedScale", sol::property(
            &lucidfx::core::AnimatedTexture::getSpeedScale, 
            &lucidfx::core::AnimatedTexture::setSpeedScale
        ),
        "getFrameDuration", &lucidfx::core::AnimatedTexture::getFrameDuration,
        "getFrameTexture", &lucidfx::core::AnimatedTexture::getFrameTexture,
        "setFrameDuration", &lucidfx::core::AnimatedTexture::setFrameDuration,
        "setFrameTexture", &lucidfx::core::AnimatedTexture::setFrameTexture,
        "cast", [](Resource* instance) {
            return new AnimatedTexture(godot::Object::cast_to<GodotAnimatedTexture>(instance->getResource()));
        }
    );
}