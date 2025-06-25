#ifndef SPHERE_H
#define SPHERE_H

#include <godot_cpp/classes/sphere_mesh.hpp>

#include "../../core/scene_system.h"
#include "mesh_renderer.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::spatial::mesh {
    void bindSphere(sol::state& lua);

    class Sphere : public Component {
    private:
        SphereMesh* sphereMesh;
    public:
        float getHeight() {
            return sphereMesh->get_height();
        }    
        void setHeight(float height) {
            sphereMesh->set_height(height);
        }

        bool getIsHemisphere() {
            return sphereMesh->get_is_hemisphere();
        }
        void setIsHemisphere(bool isHemisphere) {
            sphereMesh->set_is_hemisphere(isHemisphere);
        }

        int getRadialSegments() {
            return sphereMesh->get_radial_segments();
        }
        void setRadialSegments(int radialSegments) {
            sphereMesh->set_radial_segments(radialSegments);
        }

        float getRadius() {
            return sphereMesh->get_radius();
        }
        void setRadius(float radius) {
            sphereMesh->set_radius(radius);
        }

        int getRings() {
            return sphereMesh->get_rings();
        }
        void setRings(int rings) {
            sphereMesh->set_rings(rings);
        }

        void onInit() override {
            sphereMesh = memnew(SphereMesh);
            MeshRenderer* meshRenderer = entity->getComponentByT<MeshRenderer>();
            meshRenderer->getNode()->set_mesh(sphereMesh);
        }

        void onFree() override {
            Component::onFree();
            if (sphereMesh == nullptr) return;
            MeshRenderer* meshRenderer = entity->getComponentByT<MeshRenderer>();
            meshRenderer->getNode()->set_mesh(nullptr);
            sphereMesh->unreference();
            sphereMesh = nullptr;
        }
    };
}

#endif