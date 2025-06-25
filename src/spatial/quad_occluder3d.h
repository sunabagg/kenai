#ifndef QUAD_OCCLUDER3D_H
#define QUAD_OCCLUDER3D_H

#include <godot_cpp/classes/quad_occluder3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotQuadOccluder3D godot::QuadOccluder3D

#include "occluder3d.h"

using namespace godot;

namespace lucidfx::spatial {
    void bindQuadOccluder3D(sol::state_view& lua);

    class QuadOccluder3D : public Occluder3D {
    private:
        GodotQuadOccluder3D* quadOccluder = nullptr;
    public:
    QuadOccluder3D() {
            setQuadOccluder3D(memnew(GodotQuadOccluder3D));
        }

        QuadOccluder3D(GodotQuadOccluder3D* qo) {
            setQuadOccluder3D(qo);
        }

        GodotQuadOccluder3D* getQuadOccluder3D() {
            return quadOccluder;
        }

        void setQuadOccluder3D(GodotQuadOccluder3D* qo) {
            quadOccluder = qo;
            quadOccluder->reference();
            setOccluder3D(quadOccluder);
        }

        Vector2 getSize() {
            return quadOccluder->get_size();
        }
        
        void setSize(Vector2 size) {
            quadOccluder->set_size(size);
        }
    };
}

#endif // QUAD_OCCLUDER3D_H