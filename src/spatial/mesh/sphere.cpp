#include "sphere.h"

void sunaba::spatial::mesh::bindSphere(sol::state& lua) {
    lua.new_usertype<SphereReference>(
        "Sphere",
        sol::constructors<SphereReference()>(),
        sol::base_classes, sol::bases<ComponentReference>(),
        "height", sol::property([](SphereReference& s) {
            return NativeReference<Sphere>(s)->getHeight();
        }, [](SphereReference& s, float height) {
            NativeReference<Sphere>(s)->setHeight(height);
        }),
        "isHemisphere", sol::property([](SphereReference& s) {
            return NativeReference<Sphere>(s)->getIsHemisphere();
        }, [](SphereReference& s, bool isHemisphere) {
            NativeReference<Sphere>(s)->setIsHemisphere(isHemisphere);
        }),
        "radialSegments", sol::property([](SphereReference& s) {
            return NativeReference<Sphere>(s)->getRadialSegments();
        }, [](SphereReference& s, int radialSegments) {
            NativeReference<Sphere>(s)->setRadialSegments(radialSegments);
        }),
        "rings", sol::property([](SphereReference& s) {
            return NativeReference<Sphere>(s)->getRings();
        }, [](SphereReference& s, int rings) {
            NativeReference<Sphere>(s)->setRings(rings);
        }),
        "radius", sol::property([](SphereReference& s) {
            return NativeReference<Sphere>(s)->getRadius();
        }, [](SphereReference& s, float radius) {
            NativeReference<Sphere>(s)->setRadius(radius);
        }),
        "onInit", [](SphereReference& s) {
            NativeReference<Sphere>(s)->onInit();
        },
        "onFree", [](SphereReference& s) {
            NativeReference<Sphere>(s)->onFree();
        },
        "getFromEntity", [](EntityReference& e) {
            return new SphereReference(
                NativeReference<Entity>(e)->getComponentByT<Sphere>()
            );
        },
        "cast", [](ComponentReference& cr) {
            return SphereReference(
                static_cast<Sphere*>(NativeReference<Component>(cr).ptr)
            );
        }
    );
}