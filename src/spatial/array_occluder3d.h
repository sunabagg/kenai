#ifndef ARRAY_OCCLUDER3D_H
#define ARRAY_OCCLUDER3D_H

#include <godot_cpp/classes/array_occluder3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotArrayOccluder3D godot::ArrayOccluder3D

#include "occluder3d.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::spatial {
    void bindArrayOccluder3D(sol::state_view& lua);

    class ArrayOccluder3D : public Occluder3D {
    private:
        GodotArrayOccluder3D* arrayOccluder = nullptr;
    public:
        ArrayOccluder3D() {
            setArrayOccluder3D(memnew(GodotArrayOccluder3D));
        }

        ArrayOccluder3D(GodotArrayOccluder3D* ao) {
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

        std::vector<Vector2> getPolygon() {
            std::vector<Vector2> polygon;
            PackedVector2Array arr = arrayOccluder->get("polygon");
            for (int i = 0; i < arr.size(); i++) {
                polygon.push_back(arr[i]);
            }
            return polygon;
        }

        void setPolygon(std::vector<Vector2> polygon) {
            PackedVector2Array arr;
            for (int i = 0; i < polygon.size(); i++) {
                arr.push_back(polygon[i]);
            }
            arrayOccluder->set("polygon", arr);
        }
    };
}

#endif // ARRAY_OCCLUDER3D_H