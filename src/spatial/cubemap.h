#ifndef CUBEMAP_H
#define CUBEMAP_H

#include <godot_cpp/classes/cubemap.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotCubemap godot::Cubemap

#include "../core/image_texture_layered.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::spatial {
    void bindCubemap(sol::state_view& lua);

    class Cubemap : public sunaba::core::ImageTextureLayered {
    private:
        GodotCubemap* cubemap = nullptr;
    public:
        Cubemap() {
            setCubemap(memnew(GodotCubemap));
        }

        Cubemap(GodotCubemap* c) {
            setCubemap(c);
        }

        GodotCubemap* getCubemap() {
            return cubemap;
        }

        void setCubemap(GodotCubemap* c) {
            cubemap = c;
            //cubemap->reference();
            setImageTextureLayered(cubemap);
        }

        sunaba::core::Resource* createPlaceholder() {
            return new sunaba::core::Resource(
                cubemap->create_placeholder().ptr()
            );
        }
    };
}

#endif