#ifndef ANIMATED_TEXTURE_H
#define ANIMATED_TEXTURE_H

#include <godot_cpp/classes/animated_texture.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotAnimatedTexture godot::AnimatedTexture

#include "texture2d.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidware::core {
    void bindAnimatedTexture(sol::state &lua);

    class AnimatedTexture : public Texture2D {
    private:
        GodotAnimatedTexture* animatedTexture = nullptr; // Pointer to the AnimatedTexture instance
    public:
        // Constructor with Ref<GodotAnimatedTexture> parameter
        AnimatedTexture(GodotAnimatedTexture* animatedTexture) {
            setAnimatedTexture(animatedTexture);
        }

        // Constructor with no parameters
        AnimatedTexture() {
            setAnimatedTexture(memnew(GodotAnimatedTexture));
        }

        // Getter for the AnimatedTexture node
        GodotAnimatedTexture* getAnimatedTexture() {
            return animatedTexture;
        }

        // Setter for the AnimatedTexture node
        void setAnimatedTexture(GodotAnimatedTexture* animatedTexture) {
            this->animatedTexture = animatedTexture;
            animatedTexture->reference();
            setTexture(animatedTexture);
        }

        int getCurrentFrame() {
            return animatedTexture->get_current_frame();
        }

        void setCurrentFrame(int frame) {
            animatedTexture->set_current_frame(frame);
        }

        int getFrames() {
            return animatedTexture->get_frames();
        }

        void setFrames(int frames) {
            animatedTexture->set_frames(frames);
        }

        bool getOneShot() {
            return animatedTexture->get_one_shot();
        }

        void setOneShot(bool oneShot) {
            animatedTexture->set_one_shot(oneShot);
        }

        bool getPause() {
            return animatedTexture->get_pause();
        }

        void setPause(bool paused) {
            animatedTexture->set_pause(paused);
        }

        float getSpeedScale() {
            return animatedTexture->get_speed_scale();
        }

        void setSpeedScale(float speedScale) {
            animatedTexture->set_speed_scale(speedScale);
        }

        float getFrameDuration(int frame) {
            return animatedTexture->get_frame_duration(frame);
        }

        Texture2D* getFrameTexture(int frame) {
            return new Texture2D(animatedTexture->get_frame_texture(frame).ptr());
        }

        void setFrameDuration(int frame, float duration) {
            animatedTexture->set_frame_duration(frame, duration);
        }

        void setFrameTexture(int frame, Texture2D* texture) {
            animatedTexture->set_frame_texture(frame, texture->getTexture2D());
        }
    };
}

#endif // ANIMATED_TEXTURE_H