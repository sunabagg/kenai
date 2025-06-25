#ifndef BOX_OCCLUDER3D_H
#define BOX_OCCLUDER3D_H

#include <godot_cpp/classes/box_occluder3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotBoxOccluder3D godot::BoxOccluder3D

#include "occluder3d.h"

using namespace godot;

namespace lucidfx::spatial {
    void bindBoxOccluder3D(sol::state_view& lua);

    class BoxOccluder : public Occluder3D {
    private:
        GodotBoxOccluder3D* boxOccluder = nullptr;
    public:
        BoxOccluder() {
            setBoxOccluder3D(memnew(GodotBoxOccluder3D));
        }

        BoxOccluder(GodotBoxOccluder3D* bo) {
            setBoxOccluder3D(bo);
        }

        GodotBoxOccluder3D* getBoxOccluder3D() {
            return boxOccluder;
        }

        void setBoxOccluder3D(GodotBoxOccluder3D* bo) {
            boxOccluder = bo;
            boxOccluder->reference();
            setOccluder3D(boxOccluder);
        }

        Vector3 getSize() {
            return boxOccluder->get_size();
        }

        void setSize(Vector3 size) {
            boxOccluder->set_size(size);
        }
    };
}

#endif // BOX_OCCLUDER3D_H