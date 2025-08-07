#ifndef SUNABA_RESOURCE_H
#define SUNABA_RESOURCE_H

#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <sol/sol.hpp>

#include "base_object.h"

namespace sunaba::core {
    void bindResource(sol::state &lua);

    class Resource : public BaseObject {
    private:
    godot::Resource* resource = nullptr; // Pointer to the Resource instance
    public:
        // Constructor with Ref<GodotResource> parameter
        Resource(godot::Resource* res) {
            setResource(res);
        }

        // Constructor with no parameters
        Resource() {
            resource  = memnew(godot::Resource);
            //resource = godot::Ref<GodotResource>(r);
        }

        // Getter for the Resource node
        godot::Resource* getResource() const {
            return resource;
        }

        // Setter for the Resource node
        void setResource(godot::Resource* res) {
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

        std::string getPath() {
            return resource->get_path().utf8().get_data();
        }

        void setPath(const std::string& path) {
            resource->set_path(path.c_str());
        }
    };
}

#endif // SUNABA_RESOURCE_H