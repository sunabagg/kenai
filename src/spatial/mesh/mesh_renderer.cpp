#include "mesh_renderer.h"

using namespace godot;
using namespace sunaba::core;

void sunaba::spatial::mesh::bindMeshRenderer(sol::state& lua) {
    lua.new_usertype<MeshRendererReference>(
        "MeshRenderer",
        sol::constructors<MeshRendererReference()>(),
        sol::base_classes, sol::bases<IGeometryInstanceReference, IVisualInstanceReference, ComponentReference>(),
        "createConvexCollision", [](MeshRendererReference& m) {
            return NativeReference<MeshRenderer>(m)->createConvexCollision();
        },
        "createDebugTangents", [](MeshRendererReference& m) {
            return NativeReference<MeshRenderer>(m)->createDebugTangents();
        },
        "createTrimeshCollision", [](MeshRendererReference& m) {
            return NativeReference<MeshRenderer>(m)->createTrimeshCollision();
        },
        "findBlendShapeByName", [](MeshRendererReference& m, std::string name) {
            return NativeReference<MeshRenderer>(m)->findBlendShapeByName(name);
        },
        "getBlendShapeCount", [](MeshRendererReference& m) {
            return NativeReference<MeshRenderer>(m)->getBlendShapeCount();
        },
        "getBlendShapeValue", [](MeshRendererReference& m, int index) {
            return NativeReference<MeshRenderer>(m)->getBlendShapeValue(index);
        },
        "getSurfaceOverrideMaterialCount", [](MeshRendererReference& m) {
            return NativeReference<MeshRenderer>(m)->getSurfaceOverideMaterialCount();
        },
        "setBlendShapeValue", [](MeshRendererReference& m, int index, float value) {
            return NativeReference<MeshRenderer>(m)->setBlendShapeValue(index, value);
        },
        "onInit", [](MeshRendererReference& m) {
            return NativeReference<MeshRenderer>(m)->onInit();
        },
        "onFree", [](MeshRendererReference& m) {
            return NativeReference<MeshRenderer>(m)->onFree();
        },
        "getFromEntity", [](EntityReference& e) {
            return new MeshRendererReference(
                NativeReference<Entity>(e)->getComponentByT<MeshRenderer>()
            );
        },
        "cast", [](ComponentReference& cr) {
            return MeshRendererReference(
                static_cast<MeshRenderer*>(NativeReference<Component>(cr).ptr)
            );
        }
    );
}