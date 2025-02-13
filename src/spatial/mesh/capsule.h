#ifndef CAPSULE_H
#define CAPSULE_H

#include <godot_cpp/classes/capsule_mesh.hpp>

#include "../../core/scene_system.h"
#include "mesh_renderer.h"

using namespace godot;
using namespace newhaven_core;

namespace newhaven_spatial_mesh {
    void bindCapsule(sol::state& lua);

    class Capsule : public Component {
    private:
        CapsuleMesh* capsuleMesh;
    public:
        float getHeight() {
            return capsuleMesh->get_height();
        }
        void setHeight(float height) {
            capsuleMesh->set_height(height);
        }

        int getRadialSegments() {
            return capsuleMesh->get_radial_segments();
        }
        void setRadialSegments(int radialSegments) {
            capsuleMesh->set_radial_segments(radialSegments);
        }

        float getRadius() {
            return capsuleMesh->get_radius();
        }
        void setRadius(float radius) {
            capsuleMesh->set_radius(radius);
        }

        int getRings() {
            return capsuleMesh->get_rings();
        }
        void setRings(int rings) {
            capsuleMesh->set_rings(rings);
        }

        void onInit() override {
            capsuleMesh = memnew(CapsuleMesh);
            MeshRenderer* meshRenderer = static_cast<MeshRenderer*>(entity->getComponent("MeshRenderer"));
            meshRenderer->getNode()->set_mesh(capsuleMesh);
        }
    };
}
#endif // CAPSULE_H