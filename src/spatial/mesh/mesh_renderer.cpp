#include "mesh_renderer.h"

using namespace godot;
using namespace sunaba::core;

void sunaba::spatial::mesh::bindMeshRenderer(sol::state& lua) {
    lua.new_usertype<MeshRenderer>(
        "MeshRenderer",
        sol::constructors<MeshRenderer()>(),
        sol::base_classes, sol::bases<IGeometryInstance, IVisualInstance, Component>(),
        "createConvexCollision", &MeshRenderer::createConvexCollision,
        "createDebugTangents", &MeshRenderer::createDebugTangents,
        "createTrimeshCollision", &MeshRenderer::createTrimeshCollision,
        "findBlendShapeByName", &MeshRenderer::findBlendShapeByName,
        "getBlendShapeCount", &MeshRenderer::getBlendShapeCount,
        "getBlendShapeValue", &MeshRenderer::getBlendShapeValue,
        "getSurfaceOverrideMaterialCount", &MeshRenderer::getSurfaceOverideMaterialCount,
        "setBlendShapeValue", &MeshRenderer::setBlendShapeValue,
        "getFromEntity", [](Entity* entity) {
            return entity->getComponentByT<MeshRenderer>();
        }
    );
}