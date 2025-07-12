#ifndef KENAI_RESOURCE_H
#define KENAI_RESOURCE_H

#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <sol/sol.hpp>

#define GodotResource godot::Resource

#include "base_object.h"

namespace kenai::core {
    void bindResource(sol::state &lua);

    class Resource : public BaseObject {
    private:
    GodotResource* resource = nullptr; // Pointer to the Resource instance
    public:
        // Constructor with Ref<GodotResource> parameter
        Resource(GodotResource* res) {
            setResource(res);
        }

        // Constructor with no parameters
        Resource() {
            resource  = memnew(GodotResource);
            //resource = godot::Ref<GodotResource>(r);
        }

        // Getter for the Resource node
        GodotResource* getResource() const {
            return resource;
        }

        // Setter for the Resource node
        void setResource(GodotResource* res) {
            resource = res;
            if (resource != nullptr) {
                resource->reference();
            }
        }

        Resource* duplicate(const bool subresources = false) {
            return new Resource(resource->duplicate(subresources).ptr());
        }

        void emitChanged() {
            resource->emit_changed();
        }

        bool isNull() {
            return resource == nullptr;
        }
    };
}

#endif // KENAI_RESOURCE_H