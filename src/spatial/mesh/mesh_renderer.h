#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include <godot_cpp/classes/mesh_instance3d.hpp>

#include "../transform.h"
#include "../i_geometry_instance.h"
#include "../../core/scene_system.h"

using namespace godot;
using namespace lucidfx::core;
using namespace lucidfx::spatial;

namespace lucidfx::spatial::mesh
{
    void bindMeshRenderer(sol::state& lua);

    class MeshRenderer : public IGeometryInstance
    {
    protected:
        MeshInstance3D* node;
    public:
        void createConvexCollision(bool clean = true, bool simpilify = true) {
            node->create_convex_collision(clean, simpilify);
        }

        void createDebugTangents() {
            node->create_debug_tangents();
        }

        void createTrimeshCollision() {
            node->create_trimesh_collision();
        }

        int findBlendShapeByName(std::string name) {
            return node->find_blend_shape_by_name(name.c_str());
        }

        int getBlendShapeCount() {
            return node->get_blend_shape_count();
        }

        float getBlendShapeValue(int index) {
            return node->get_blend_shape_value(index);
        }

        int getSurfaceOverideMaterialCount() {
            return node->get_surface_override_material_count();
        }

        void setBlendShapeValue(int index, float value) {
            node->set_blend_shape_value(index, value);
        }

        MeshInstance3D* getNode() {
            return node;
        }

        void setNode(MeshInstance3D* n) {
            if (node != nullptr) {
                SpatialTransform* transform = entity->getComponentByT<SpatialTransform>();
                if (transform) {
                    transform->getNode()->remove_child(node);
                }
                node->queue_free();
            }
            node = n;
            SpatialTransform* transform = entity->getComponentByT<SpatialTransform>();
            if (transform) {
                transform->getNode()->add_child(node);
            }
        }

        void onInit() override {
            node = memnew(MeshInstance3D);
            SpatialTransform* transform = entity->getComponentByT<SpatialTransform>();
            if (transform) {
                transform->getNode()->add_child(node);
            }
        }

        void onFree() override {
            Component::onFree();
            if (node != nullptr) {
                node->queue_free();
            }
        }
    };
}


#endif