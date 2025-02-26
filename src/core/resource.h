#ifndef SUNABA_RESOURCE_H
#define SUNABA_RESOURCE_H

#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <sol/sol.hpp>

#define GodotResource godot::Resource

#include "base_object.h"

namespace sunaba::core {
    void bindResource(sol::state &lua);

    class Resource : public BaseObject {
    private:
        godot::Ref<GodotResource> resource = nullptr; // Pointer to the Resource instance
    public:
        // Constructor with Ref<GodotResource> parameter
        Resource(godot::Ref<GodotResource> res) : resource(res) {
        }

        // Constructor with no parameters
        Resource() {
            auto r  = memnew(GodotResource);
            resource = godot::Ref<GodotResource>(r);
        }

        // Getter for the Resource node
        godot::Ref<GodotResource> getResource() {
            return resource;
        }

        // Setter for the Resource node
        void setResource(godot::Ref<GodotResource> res) {
            resource = res;
            resource->reference();
        }

        Resource* duplicate(bool subresources = false) {
            return new Resource(resource->duplicate(subresources));
        }

        void emitChanged() {
            resource->emit_changed();
        }
    };
}

#endif // SUNABA_RESOURCE_H