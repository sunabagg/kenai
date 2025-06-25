#ifndef ATLAS_TEXTURE_H
#define ATLAS_TEXTURE_H

#include <godot_cpp/classes/atlas_texture.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotAtlasTexture godot::AtlasTexture

#include "texture2d.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidfx::core {
    void bindAtlasTexture(sol::state &lua);

    class AtlasTexture : public Texture2D {
    private:
        GodotAtlasTexture* atlasTexture = nullptr; // Pointer to the AtlasTexture instance
    public:
        // Constructor with Ref<GodotAtlasTexture> parameter
        AtlasTexture(GodotAtlasTexture* atlasTexture) {
            setAtlasTexture(atlasTexture);
        }

        // Constructor with no parameters
        AtlasTexture() {
            setAtlasTexture(memnew(GodotAtlasTexture));
        }

        // Getter for the AtlasTexture node
        GodotAtlasTexture* getAtlasTexture() {
            return atlasTexture;
        }

        // Setter for the AtlasTexture node
        void setAtlasTexture(GodotAtlasTexture* atlasTexture) {
            this->atlasTexture = atlasTexture;
            atlasTexture->reference();
            setTexture(atlasTexture);
        }

        Texture2D* getAtlas() {
            return new Texture2D(atlasTexture->get_atlas().ptr());
        }

        void setAtlas(Texture2D* atlas) {
            atlasTexture->set_atlas(Ref<GodotTexture2D>(atlas->getTexture2D()));
        }

        bool getFilterClip() {
            return atlasTexture->has_filter_clip();
        }

        void setFilterClip(bool filter) {
            atlasTexture->set_filter_clip(filter);
        }

        Rect2 getMargin() {
            return atlasTexture->get_margin();
        }

        void setMargin(Rect2 margin) {
            atlasTexture->set_margin(margin);
        }

        Rect2 getRegion() {
            return atlasTexture->get_region();
        }

        void setRegion(Rect2 region) {
            atlasTexture->set_region(region);
        }
    };
}

#endif // ATLAS_TEXTURE_H