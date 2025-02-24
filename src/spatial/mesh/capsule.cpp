#include "capsule.h"

void sunaba::spatial::mesh::bindCapsule(sol::state& lua) {
    lua.new_usertype<CapsuleReference>(
        "Capsule",
        sol::constructors<CapsuleReference()>(),
        sol::base_classes, sol::bases<ComponentReference>(),
        "height", sol::property([](CapsuleReference& c) {
            return NativeReference<Capsule>(c)->getHeight();
        }, [](CapsuleReference& c, float height) {
            NativeReference<Capsule>(c)->setHeight(height);
        }),
        "radialSegments", sol::property([](CapsuleReference& c) {
            return NativeReference<Capsule>(c)->getRadialSegments();
        }, [](CapsuleReference& c, int radialSegments) {
            NativeReference<Capsule>(c)->setRadialSegments(radialSegments);
        }),
        "rings", sol::property([](CapsuleReference& c) {
            return NativeReference<Capsule>(c)->getRings();
        }, [](CapsuleReference& c, int rings) {
            NativeReference<Capsule>(c)->setRings(rings);
        }),
        "radius", sol::property([](CapsuleReference& c) {
            return NativeReference<Capsule>(c)->getRadius();
        }, [](CapsuleReference& c, float radius) {
            NativeReference<Capsule>(c)->setRadius(radius);
        }),
        "onInit", [](CapsuleReference& c) {
            return NativeReference<Capsule>(c)->onInit();
        },
        "onFree", [](CapsuleReference& c) {
            return NativeReference<Capsule>(c)->onFree();
        },
        "getFromEntity", [](EntityReference& e) {
            return new CapsuleReference(
                NativeReference<Entity>(e)->getComponentByT<Capsule>()
            );
        },
        "cast", [](ComponentReference& cr) {
            return CapsuleReference(
                static_cast<Capsule*>(NativeReference<Component>(cr).ptr)
            );
        }
    );
}