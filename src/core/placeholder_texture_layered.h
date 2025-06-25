#ifndef PLACEHOLDER_TEXTURE_LAYERED_H
#define PLACEHOLDER_TEXTURE_LAYERED_H

#include <godot_cpp/classes/placeholder_texture_layered.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotPlaceholderTextureLayered godot::PlaceholderTextureLayered

#include "texture_layered.h"

using namespace godot;

namespace lucidfx::core {
    void bindPlaceholderTextureLayered(sol::state &lua);

    class PlaceholderTextureLayered : public TextureLayered {
    private:
        GodotPlaceholderTextureLayered* placeholderTextureLayered = nullptr; // Pointer to the PlaceholderTextureLayered instance
    public:
        // Constructor with Ref<GodotPlaceholderTextureLayered> parameter
        PlaceholderTextureLayered(GodotPlaceholderTextureLayered* placeholderTextureLayered) {
            setPlaceholderTextureLayered(placeholderTextureLayered);
        }

        // Constructor with no parameters
        PlaceholderTextureLayered() {
            setPlaceholderTextureLayered(memnew(GodotPlaceholderTextureLayered));
        }

        // Getter for the PlaceholderTextureLayered node
        GodotPlaceholderTextureLayered* getPlaceholderTextureLayered() {
            return placeholderTextureLayered;
        }

        // Setter for the PlaceholderTextureLayered node
        void setPlaceholderTextureLayered(GodotPlaceholderTextureLayered* placeholderTextureLayered) {
            this->placeholderTextureLayered = placeholderTextureLayered;
            placeholderTextureLayered->reference();
            setTexture(placeholderTextureLayered);
        }

        int getLayers() {
            return placeholderTextureLayered->get_layers();
        }

        void setLayers(int layers) {
            placeholderTextureLayered->set_layers(layers);
        }

        Vector2i getSize() {
            return placeholderTextureLayered->get_size();
        }

        void setSize(Vector2i size) {
            placeholderTextureLayered->set_size(size);
        }
    };
}

#endif // PLACEHOLDER_TEXTURE_LAYERED_H