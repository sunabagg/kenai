#ifndef POLYGON_OCCLUDER3D_H
#define POLYGON_OCCLUDER3D_H

#include <godot_cpp/classes/polygon_occluder3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotPolygonOccluder3D godot::PolygonOccluder3D

#include "occluder3d.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::spatial {
    void bindPolygonOccluder3D(sol::state_view& lua);

    class PolygonOccluder3D : public Occluder3D {
    private:
        GodotPolygonOccluder3D* arrayOccluder = nullptr;
    public:
    PolygonOccluder3D() {
            setPolygonOccluder3D(memnew(GodotPolygonOccluder3D));
        }

        PolygonOccluder3D(GodotPolygonOccluder3D* ao) {
            setPolygonOccluder3D(ao);
        }

        GodotPolygonOccluder3D* getPolygonOccluder3D() {
            return arrayOccluder;
        }

        void setPolygonOccluder3D(GodotPolygonOccluder3D* ao) {
            arrayOccluder = ao;
            arrayOccluder->reference();
            setOccluder3D(arrayOccluder);
        }

        std::vector<Vector2> getPolygon() {
            std::vector<Vector2> polygon;
            PackedVector2Array arr = arrayOccluder->get_polygon();
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
            arrayOccluder->set_polygon(arr);
        }
    };
}

#endif // POLYGON_OCCLUDER3D_H