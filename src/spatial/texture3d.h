#ifndef TEXTURE3D_H
#define TEXTURE3D_H

#include <godot_cpp/classes/texture3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTexture3D godot::Texture3D

#include "../core/texture.h"
#include "../core/image.h"

using namespace godot;
using namespace lucidware::core;


namespace lucidware::spatial {
    void bindTexture3D(sol::state_view& lua);

    class Texture3D : public lucidware::core::Texture {
    private:
        GodotTexture3D* texture = nullptr;
    public:
        Texture3D() {
            setTexture3D(memnew(GodotTexture3D));
        }

        Texture3D(GodotTexture3D* t) {
            setTexture3D(t);
        }

        GodotTexture3D* getTexture3D() {
            return texture;
        }

        void setTexture3D(GodotTexture3D* t) {
            texture = t;
            texture->reference();
            setTexture(texture);
        }

        lucidware::core::Resource* createPlaceholder() {
            return new lucidware::core::Resource(
                texture->create_placeholder().ptr()
            );
        }

        std::vector<lucidware::core::Image> getData() {
            std::vector<lucidware::core::Image> images;
            TypedArray<GodotImage> arr = texture->get_data();
            for (int i = 0; i < arr.size(); i++) {
                Ref<GodotImage> img = arr[i];
                if (img.is_valid()) {
                    images.push_back(lucidware::core::Image(img.ptr()));
                }
            }
            return images;
        }

        int getDepth() {
            return texture->get_depth();
        }

        int getFormat() {
            return texture->get_format();
        }

        int getHeight() {
            return texture->get_height();
        }

        int getWidth() {
            return texture->get_width();
        }

        bool hasMipmaps() {
            return texture->has_mipmaps();
        }
    };
}

#endif // TEXTURE3D_H