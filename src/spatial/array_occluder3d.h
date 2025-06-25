#ifndef ARRAY_OCCLUDER3D_H
#define ARRAY_OCCLUDER3D_H

#include <godot_cpp/classes/array_occluder3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotArrayOccluder3D godot::ArrayOccluder3D

#include "occluder3d.h"

using namespace godot;

namespace lucidware::spatial {
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

        void setIndices(std::vector<int> indices) {
            PackedInt32Array arr;
            for (int i = 0; i < indices.size(); i++) {
                arr.push_back(indices[i]);
            }
            arrayOccluder->set_indices(arr);
        }

        void setVertices(std::vector<Vector3> vertices) {
            PackedVector3Array arr;
            for (int i = 0; i < vertices.size(); i++) {
                arr.push_back(vertices[i]);
            }
            arrayOccluder->set_vertices(arr);
        }

        void setArrays(std::vector<Vector3> vertices, std::vector<int> indices) {
            PackedInt32Array indicesArr;
            for (int i = 0; i < indices.size(); i++) {
                indicesArr.push_back(indices[i]);
            }
            PackedVector3Array verticesArr;
            for (int i = 0; i < vertices.size(); i++) {
                verticesArr.push_back(vertices[i]);
            }
            arrayOccluder->set_arrays(verticesArr, indicesArr);
        }
    };
}

#endif // ARRAY_OCCLUDER3D_H