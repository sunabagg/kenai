#ifndef PLACEHOLDER_TEXTURE2D_H
#define PLACEHOLDER_TEXTURE2D_H

#include <godot_cpp/classes/placeholder_texture2d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotPlaceholderTexture2D godot::PlaceholderTexture2D

#include "texture2d.h"

using namespace godot;

namespace lucidware::core {
    void bindPlaceholderTexture2D(sol::state &lua);

    class PlaceholderTexture2D : public Texture2D {
    private:
        GodotPlaceholderTexture2D* placeholderTexture2D = nullptr; // Pointer to the PlaceholderTexture2D instance
    public:
        // Constructor with Ref<GodotPlaceholderTexture2D> parameter
        PlaceholderTexture2D(GodotPlaceholderTexture2D* placeholderTexture2D) {
            setPlaceholderTexture2D(placeholderTexture2D);
        }

        // Constructor with no parameters
        PlaceholderTexture2D() {
            setPlaceholderTexture2D(memnew(GodotPlaceholderTexture2D));
        }

        // Getter for the PlaceholderTexture2D node
        GodotPlaceholderTexture2D* getPlaceholderTexture2D() {
            return placeholderTexture2D;
        }

        // Setter for the PlaceholderTexture2D node
        void setPlaceholderTexture2D(GodotPlaceholderTexture2D* placeholderTexture2D) {
            this->placeholderTexture2D = placeholderTexture2D;
            placeholderTexture2D->reference();
            setTexture(placeholderTexture2D);
        }

        Vector2 getSize() {
            return placeholderTexture2D->get_size();
        }

        void setSize(Vector2 size) {
            placeholderTexture2D->set_size(size);
        }
    };
}

#endif // PLACEHOLDER_TEXTURE2D_H