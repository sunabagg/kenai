#ifndef NOISE_H
#define NOISE_H

#include <godot_cpp/classes/noise.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotNoise godot::Noise
#define GodotResource godot::Resource

#include "resource.h"
#include "image.h"

using namespace godot;

namespace lucidware::core {
    void bindNoise(sol::state_view& lua);

    class Noise : public lucidware::core::Resource {
    private:
        GodotNoise* noise;
    public:
        Noise(GodotNoise* n) {
            setNoise(n);
        }

        Noise() {
            setNoise(memnew(GodotNoise));
        }

        GodotNoise* getNoise() const {
            return noise;
        }
        
        void setNoise(GodotNoise* n) {
            noise = n;
            noise->reference();
            setResource(n);
        }

        Image* getImage(int width, int height, bool invert = false, bool in3dSpace = false, bool normalize = true){
            auto img = noise->get_image(width, height, invert, in3dSpace, normalize).ptr();
            if (img == nullptr) {
                return nullptr;
            }
            return new Image(img);
        }

        std::vector<Image*> getImage3d(int width, int height, int depth, bool invert = false, bool normalize = true){
            auto img = noise->get_image_3d(width, height, depth, invert, normalize);
            std::vector<Image*> images;
            for (auto i = 0; i < img.size(); i++) {
                Ref<GodotImage> image = img[i];
                images.push_back(new Image(image.ptr()));
            }
            return images;
        }

        float getNoise1d(float x) {
            return noise->get_noise_1d(x);
        }

        float getNoise2d(float x, float y) {
            return noise->get_noise_2d(x, y);
        }

        float getNoise2dv(const Vector2& v) {
            return noise->get_noise_2dv(v);
        }

        float getNoise3d(float x, float y, float z) {
            return noise->get_noise_3d(x, y, z);
        }

        float getNoise3dv(const Vector3& v) {
            return noise->get_noise_3dv(v);
        }

        Image* getSeamlessImage(int width, int height, bool invert = false, bool in3dSpace = false, float skirt = 0.1, bool normalize = true) {
            auto img = noise->get_seamless_image(width, height, invert, in3dSpace, skirt, normalize).ptr();
            if (img == nullptr) {
                return nullptr;
            }
            return new Image(img);
        }

        std::vector<Image*> getSeamlessImage3d(int width, int height, int depth, bool invert = false, float skirt = 0.1, bool normalize = true) {
            auto img = noise->get_seamless_image_3d(width, height, depth, invert, skirt, normalize);
            std::vector<Image*> images;
            for (auto i = 0; i < img.size(); i++) {
                Ref<GodotImage> image = img[i];
                images.push_back(new Image(image.ptr()));
            }
            return images;
        }
    };
}

#endif // NOISE_H