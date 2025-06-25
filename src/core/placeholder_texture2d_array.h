#ifndef PLACEHOLDER_TEXTURE2D_ARRAY_H
#define PLACEHOLDER_TEXTURE2D_ARRAY_H

#include <godot_cpp/classes/placeholder_texture2d_array.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotPlaceholderTexture2DArray godot::PlaceholderTexture2DArray

#include "placeholder_texture_layered.h"

using namespace godot;

namespace lucidware::core {
    void bindPlaceholderTexture2DArray(sol::state &lua);

    class PlaceholderTexture2DArray : public PlaceholderTextureLayered {
    private:
        GodotPlaceholderTexture2DArray* placeholderTexture2DArray = nullptr; // Pointer to the PlaceholderTexture2DArray instance
    public:
        // Constructor with Ref<GodotPlaceholderTexture2DArray> parameter
        PlaceholderTexture2DArray(GodotPlaceholderTexture2DArray* placeholderTexture2DArray) {
            setPlaceholderTexture2DArray(placeholderTexture2DArray);
        }

        // Constructor with no parameters
        PlaceholderTexture2DArray() {
            setPlaceholderTexture2DArray(memnew(GodotPlaceholderTexture2DArray));
        }

        // Getter for the PlaceholderTexture2DArray node
        GodotPlaceholderTexture2DArray* getPlaceholderTexture2DArray() {
            return placeholderTexture2DArray;
        }

        // Setter for the PlaceholderTexture2DArray node
        void setPlaceholderTexture2DArray(GodotPlaceholderTexture2DArray* placeholderTexture2DArray) {
            this->placeholderTexture2DArray = placeholderTexture2DArray;
            placeholderTexture2DArray->reference();
            setTexture(placeholderTexture2DArray);
        }
    };
}

#endif // PLACEHOLDER_TEXTURE2D_ARRAY_H