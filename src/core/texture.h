#ifndef LUCIDWARE_TEXTURE_H
#define LUCIDWARE_TEXTURE_H

#include <godot_cpp/classes/texture.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTexture godot::Texture

#include "resource.h"

using namespace godot;

namespace lucidware::core {
    void bindTexture(sol::state &lua);

    class Texture : public Resource {
    private:
        GodotTexture* texture = nullptr; // Pointer to the Texture instance
    public:
        // Constructor with Ref<GodotTexture> parameter
        Texture(GodotTexture* tex){
            setTexture(tex);
        }

        // Constructor with no parameters
        Texture() {
            setTexture(memnew(GodotTexture));
        }

        // Getter for the Texture node
        GodotTexture* getTexture() {
            return texture;
        }

        // Setter for the Texture node
        void setTexture(GodotTexture* tex) {
            texture = tex;
            texture->reference();
            setResource(texture);
        }
    };
}

#endif // LUCIDWARE_TEXTURE_H