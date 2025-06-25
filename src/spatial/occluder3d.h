#ifndef OCCLUDER3D_H
#define OCCLUDER3D_H

#include <godot_cpp/classes/occluder3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotOccluder3D godot::Occluder3D

#include "../core/resource.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::spatial {
    void bindOccluder3D(sol::state_view& lua);

    class Occluder3D : public lucidfx::core::Resource {
    private:
        GodotOccluder3D* occluder = nullptr;
    public:
        Occluder3D() {
            setOccluder3D(memnew(GodotOccluder3D));
        }

        Occluder3D(GodotOccluder3D* o) {
            setOccluder3D(o);
        }

        GodotOccluder3D* getOccluder3D() {
            return occluder;
        }

        void setOccluder3D(GodotOccluder3D* o) {
            occluder = o;
            occluder->reference();
            setResource(occluder);
        }

        std::vector<int> getIndices() {
            std::vector<int> indices;
            PackedInt32Array arr = occluder->get_indices();
            for (int i = 0; i < arr.size(); i++) {
                indices.push_back(arr[i]);
            }
            return indices;
        }

        std::vector<Vector3> getVertices() {
            std::vector<Vector3> vertices;
            PackedVector3Array arr = occluder->get_vertices();
            for (int i = 0; i < arr.size(); i++) {
                vertices.push_back(arr[i]);
            }
            return vertices;
        }
    };
}

#endif // OCCLUDER3D_H