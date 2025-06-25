#ifndef LUCIDWARE_IMAGE_TEXTURE_H
#define LUCIDWARE_IMAGE_TEXTURE_H

#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotImageTexture godot::ImageTexture

#include "texture2d.h"

#include "io/binary_data.h"
#include "io/io_index.h"

using namespace godot;
using namespace lucidware::core::io;

namespace lucidware::core {
    void bindImageTexture(sol::state &lua);

    class ImageTexture : public Texture2D {
    private:
        GodotImageTexture* imageTexture = nullptr; // Pointer to the ImageTexture instance
    public:
        // Constructor with Ref<GodotImageTexture> parameter
        ImageTexture(GodotImageTexture* imgTex) {
            setImageTexture(imgTex);
        }

        // Constructor with no parameters
        ImageTexture() {
            setImageTexture(memnew(GodotImageTexture));
        }

        // Getter for the ImageTexture node
        GodotImageTexture* getImageTexture() {
            return imageTexture;
        }

        // Setter for the ImageTexture node
        void setImageTexture(GodotImageTexture* imgTex) {
            imageTexture = imgTex;
            imageTexture->reference();
            setTexture2D(imageTexture);
        }

        Image* getImage() {
            return new Image(imageTexture->get_image().ptr());
        }

        void setImage(Image* image) {
            imageTexture->set_image(image->getImage());
        }

        static ImageTexture* createFromImage(Image* image) {
            auto imgtxt = GodotImageTexture::create_from_image(Ref<GodotImage>(image->getImage()));
            return new ImageTexture(imgtxt.ptr());
        }

        int getFormat() {
            return imageTexture->get_format();
        }

        void setSizeOverride(Vector2 size) {
            imageTexture->set_size_override(size);
        }

        void update(Image* Image) {
            imageTexture->update(Image->getImage());
        }
    };
}

#endif // LUCIDWARE_IMAGE_TEXTURE_H