#ifndef ARRAY_OCCLUDER3D_H
#define ARRAY_OCCLUDER3D_H

#include <godot_cpp/classes/array_occluder3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotArrayOccluder3D godot::ArrayOccluder3D

#include "occluder3d.h"

using namespace godot;

namespace sunaba::spatial {
    void bindArrayOccluder3D(sol::state_view& lua);

    class ArrayOccluder : public Occluder3D {
    private:
        GodotArrayOccluder3D* arrayOccluder = nullptr;
    public:
        ArrayOccluder() {
            setArrayOccluder3D(memnew(GodotArrayOccluder3D));
        }

        ArrayOccluder(GodotArrayOccluder3D* ao) {
            setArrayOccluder3D(ao);
        }

        GodotArrayOccluder3D* getArrayOccluder3D() {
            return arrayOccluder;
        }

        void setArrayOccluder3D(GodotArrayOccluder3D* ao) {
            arrayOccluder = ao;
            arrayOccluder->reference();
            setOccluder3D(arrayOccluder);
        }

        void setIndices(PackedInt32Array indices) {
            arrayOccluder->set_indices(indices);
        }

        void setVertices(PackedVector3Array vertices) {
            arrayOccluder->set_vertices(vertices);
        }

        void setArrays(PackedVector3Array vertices, PackedInt32Array indices) {
            arrayOccluder->set_arrays(vertices, indices);
        }
    };
}

#endif // ARRAY_OCCLUDER3D_H