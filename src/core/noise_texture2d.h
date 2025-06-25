#ifndef NOISE_TEXTURE2D_H
#define NOISE_TEXTURE2D_H

#include <godot_cpp/classes/noise_texture2d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotNoiseTexture2D godot::NoiseTexture2D

#include "texture2d.h"
#include "noise.h"
#include "gradient.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidfx::core {
    void bindNoiseTexture2D(sol::state_view& lua);

    class NoiseTexture2D : public Texture2D {
    private:
        GodotNoiseTexture2D* texture;
    public:
        NoiseTexture2D(GodotNoiseTexture2D* t) {
            setNoiseTexture2D(t);
        }

        NoiseTexture2D() {
            setNoiseTexture2D(memnew(GodotNoiseTexture2D));
        }

        GodotNoiseTexture2D* getNoiseTexture2D() const {
            return texture;
        }

        void setNoiseTexture2D(GodotNoiseTexture2D* t) {
            texture = t;
            texture->reference();
            setTexture2D(t);
        }

        bool isAsNormalMap() {
            return texture->is_normal_map();
        }

        void setAsNormalMap(bool normal_map) {
            texture->set_as_normal_map(normal_map);
        }

        float getBumpStrength() {
            return texture->get_bump_strength();
        }

        void setBumpStrength(float strength) {
            texture->set_bump_strength(strength);
        }
        
        Gradient* getColorRamp() {
            auto gradient = texture->get_color_ramp().ptr();
            if (gradient == nullptr) {
                return nullptr;
            }
            return new Gradient(gradient);
        }

        void setColorRamp(Gradient* gradient) {
            texture->set_color_ramp(gradient->getGradient());
        }

        bool isGenerateMipmaps() {
            return texture->is_generating_mipmaps();
        }

        void setGenerateMipmaps(bool generate_mipmaps) {
            texture->set_generate_mipmaps(generate_mipmaps);
        }

        int getHeight() {
            return texture->get_height();
        }

        void setHeight(int height) {
            texture->set_height(height);
        }

        bool isIn3dSpace() {
            return texture->is_in_3d_space();
        }

        void setIn3dSpace(bool is_3d_space) {
            texture->set_in_3d_space(is_3d_space);
        }

        bool getInvert() {
            return texture->get_invert();
        }

        void setInvert(bool invert) {
            texture->set_invert(invert);
        }

        Noise* getNoise() {
            auto noise = texture->get_noise().ptr();
            if (noise == nullptr) {
                return nullptr;
            }
            return new Noise(noise);
        }

        void setNoise(Noise* noise) {
            texture->set_noise(noise->getNoise());
        }

        bool getNormalize() {
            return texture->is_normalized();
        }

        void setNormalize(bool normalize) {
            texture->set_normalize(normalize);
        }

        bool getSeamless() {
            return texture->get_seamless();
        }

        void setSeamless(bool seamless) {
            texture->set_seamless(seamless);
        }

        float getSeamlessBlendSkirt() {
            return texture->get_seamless_blend_skirt();
        }

        void setSeamlessBlendSkirt(float skirt) {
            texture->set_seamless_blend_skirt(skirt);
        }

        int getWidth() {
            return texture->get_width();
        }

        void setWidth(int width) {
            texture->set_width(width);
        }
    };
}

#endif