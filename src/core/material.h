#ifndef MATERIAL_H
#define MATERIAL_H

#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotMaterial godot::Material

#include "resource.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidware::core {
    void bindMaterial(sol::state_view& lua);

    class Material : public Resource {
    private:
        GodotMaterial* material;
    public:

        Material(GodotMaterial* material) {
            setMaterial(material);
        }

        Material() {
            setMaterial(memnew(GodotMaterial));
        }

        GodotMaterial* getMaterial() {
            return material;
        }

        void setMaterial(GodotMaterial* m) {
            material = m;
            material->reference();
            setResource(material);
        }

        Material* getNextPass() {
            return new Material(material->get_next_pass().ptr());
        }

        void setNextPass(Material* next) {
            material->set_next_pass(next->getMaterial());
        }

        int getRenderPriority() {
            return material->get_render_priority();
        }

        void setRenderPriority(int priority) {
            material->set_render_priority(priority);
        }

        Resource* createPlaceholder() {
            return new Resource(material->create_placeholder().ptr());
        }
    };
}

#endif // MATERIAL_H