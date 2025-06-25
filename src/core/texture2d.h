#ifndef LUCIDWARE_TEXTURE2D_H
#define LUCIDWARE_TEXTURE2D_H

#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTexture2D godot::Texture2D

#include "texture.h"
#include "image.h"

using namespace godot;

namespace lucidware::core {
    void bindTexture2D(sol::state &lua);

    class Texture2D : public Texture {
    private:
        GodotTexture2D* texture2D = nullptr; // Pointer to the Texture2D instance
    public:
        // Constructor with Ref<GodotTexture2D> parameter
        Texture2D(GodotTexture2D* tex) {
            setTexture2D(tex);
        }

        // Constructor with no parameters
        Texture2D() {
            setTexture2D(memnew(GodotTexture2D));
        }

        // Getter for the Texture2D node
        GodotTexture2D* getTexture2D() {
            return texture2D;
        }

        // Setter for the Texture2D node
        void setTexture2D(GodotTexture2D* tex) {
            texture2D = tex;
            texture2D->reference();
            setTexture(texture2D);
        }

        Resource* createPlaceholder() {
            return new Resource(texture2D->create_placeholder().ptr());
        }

        int getHeight() {
            return texture2D->get_height();
        }

        Image* getImage()
        {
            return new Image(texture2D->get_image().ptr());
        }

        Vector2 getSize() {
            return texture2D->get_size();
        }

        int getWidth() {
            return texture2D->get_width();
        }

        bool hasAlpha() {
            return texture2D->has_alpha();
        }
    };
}

#endif // LUCIDWARE_TEXTURE2D_H