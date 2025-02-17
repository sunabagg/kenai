#include "mesh_renderer.h"

using namespace godot;
using namespace sunaba::core;

void sunaba::spatial::mesh::bindMeshRenderer(sol::state& lua) {
    sunaba::spatial::bindGeometryInstance(lua);
    lua.new_usertype<MeshRenderer>(
        "MeshRenderer",
        sol::constructors<MeshRenderer()>(),
        sol::base_classes, sol::bases<IGeometryInstance, IVisualInstance, Component>(),
        "create_convex_collision", &MeshRenderer::createConvexCollision,
        "create_debug_tangents", &MeshRenderer::createDebugTangents,
        "create_trimesh_collision", &MeshRenderer::createTrimeshCollision,
        "find_blend_shape_by_name", &MeshRenderer::findBlendShapeByName,
        "get_blend_shape_count", &MeshRenderer::getBlendShapeCount,
        "get_blend_shape_value", &MeshRenderer::getBlendShapeValue,
        "get_surface_override_material_count", &MeshRenderer::getSurfaceOverideMaterialCount,
        "set_blend_shape_value", &MeshRenderer::setBlendShapeValue,
        "getFromEntity", [](Entity* entity) {
            return entity->getComponentByT<MeshRenderer>();
        }
    );
}