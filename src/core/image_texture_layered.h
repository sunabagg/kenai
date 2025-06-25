#ifndef IMAGE_TEXTURE_LAYERED_H
#define IMAGE_TEXTURE_LAYERED_H

#include <godot_cpp/classes/image_texture_layered.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotImageTextureLayered godot::ImageTextureLayered

#include "texture_layered.h"
#include "image.h"

using namespace godot;

namespace lucidfx::core {
    void bindImageTextureLayered(sol::state_view& lua);

    class ImageTextureLayered : public lucidfx::core::TextureLayered {
    private:
        GodotImageTextureLayered* texture = nullptr;
    public:
        ImageTextureLayered() {
            setImageTextureLayered(memnew(GodotImageTextureLayered));
        }

        ImageTextureLayered(GodotImageTextureLayered* t) {
            setImageTextureLayered(t);
        }

        GodotImageTextureLayered* getImageTextureLayered() {
            return texture;
        }

        void setImageTextureLayered(GodotImageTextureLayered* t) {
            texture = t;
            texture->reference();
            setTextureLayered(texture);
        }

        int createFromImages(std::vector<Image> images) {
            TypedArray<GodotImage> refsArr;
            for (int i = 0; i < images.size(); i++) {
                refsArr.push_back(images[i].getImage());
            }
            return texture->create_from_images(refsArr);
        }

        void updateLayer(Image* image, int layer) {
            texture->update_layer(image->getImage(), layer);
        }
    };
}

#endif