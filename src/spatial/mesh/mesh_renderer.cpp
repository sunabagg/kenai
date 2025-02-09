#include "mesh_renderer.h"

using namespace godot;
using namespace newhaven_core;

namespace newhaven_spatial_mesh {
    void bindMeshRenderer(sol::state& lua) {
        lua.new_usertype<MeshRenderer>(
            "MeshRenderer",
            sol::constructors<MeshRenderer()>(),
            "onInit", &MeshRenderer::onInit, 
            "onReady", &MeshRenderer::onReady, 
            "onUpdate", &MeshRenderer::onUpdate,    
            "onPhysicsUpdate", &MeshRenderer::onPhysicsUpdate,
            "onFree", &MeshRenderer::onFree,
            "create_convex_collision", &MeshRenderer::createConvexCollision,
            "create_debug_tangents", &MeshRenderer::createDebugTangents,
            "create_trimesh_collision", &MeshRenderer::createTrimeshCollision,
            "find_blend_shape_by_name", &MeshRenderer::findBlendShapeByName,
            "get_blend_shape_count", &MeshRenderer::getBlendShapeCount,
            "get_blend_shape_value", &MeshRenderer::getBlendShapeValue,
            "get_surface_override_material_count", &MeshRenderer::getSurfaceOverideMaterialCount,
            "set_blend_shape_value", &MeshRenderer::setBlendShapeValue);
    }
}