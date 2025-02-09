#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include <godot_cpp/classes/mesh_instance3d.hpp>

#include "../transform.h"
#include "../../core/scene_system.h"

using namespace godot;
using namespace newhaven_core;
using namespace newhaven_spatial;

namespace newhaven_spatial_mesh
{
    void bindMeshRenderer(sol::state& lua);

    class MeshRenderer : public Component
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
                SpatialTransform* transform = static_cast<SpatialTransform*>(entity->getComponent("SpatialTransform"));
                if (transform) {
                    transform->getNode()->remove_child(node);
                }
                node->queue_free();
            }
            node = n;
            SpatialTransform* transform = static_cast<SpatialTransform*>(entity->getComponent("SpatialTransform"));
            if (transform) {
                transform->getNode()->add_child(node);
            }
        }

        void onInit() override {
            node = memnew(MeshInstance3D);
            SpatialTransform* transform = static_cast<SpatialTransform*>(entity->getComponent("SpatialTransform"));
            if (transform) {
                transform->getNode()->add_child(node);
            }
        }
    };
}


#endif