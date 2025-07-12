#include "animated_texture.h"

void kenai::core::bindAnimatedTexture(sol::state &lua) {
    lua.new_usertype<kenai::core::AnimatedTexture>("AnimatedTexture",
        "new", sol::factories(
            []() { return new kenai::core::AnimatedTexture(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::Texture2D>(),
        "currentFrame", sol::property(
            &kenai::core::AnimatedTexture::getCurrentFrame, 
            &kenai::core::AnimatedTexture::setCurrentFrame
        ),
        "frames", sol::property(
            &kenai::core::AnimatedTexture::getFrames, 
            &kenai::core::AnimatedTexture::setFrames
        ),
        "oneShot", sol::property(
            &kenai::core::AnimatedTexture::getOneShot, 
            &kenai::core::AnimatedTexture::setOneShot
        ),
        "frames", sol::property(
            &kenai::core::AnimatedTexture::getFrames, 
            &kenai::core::AnimatedTexture::setFrames
        ),
        "pause", sol::property(
            &kenai::core::AnimatedTexture::getPause,
            &kenai::core::AnimatedTexture::setPause
        ),
        "speedScale", sol::property(
            &kenai::core::AnimatedTexture::getSpeedScale, 
            &kenai::core::AnimatedTexture::setSpeedScale
        ),
        "getFrameDuration", &kenai::core::AnimatedTexture::getFrameDuration,
        "getFrameTexture", &kenai::core::AnimatedTexture::getFrameTexture,
        "setFrameDuration", &kenai::core::AnimatedTexture::setFrameDuration,
        "setFrameTexture", &kenai::core::AnimatedTexture::setFrameTexture,
        "cast", [](Resource* instance) {
            return new AnimatedTexture(godot::Object::cast_to<GodotAnimatedTexture>(instance->getResource()));
        }
    );
}