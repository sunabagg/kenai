#include "box.h"

void sunaba::spatial::mesh::bindBox(sol::state& lua) {
    lua.new_usertype<BoxReference>(
        "Box",
        sol::constructors<BoxReference()>(),
        sol::base_classes, sol::bases<ComponentReference>(),
        "size", sol::property([](BoxReference& b) {
            return NativeReference<Box>(b)->getSize();
        }, [](BoxReference& b, Vector3 size) {
            NativeReference<Box>(b)->setSize(size);
        }),
        "subdivideDepth", sol::property([](BoxReference& b) {
            return NativeReference<Box>(b)->getSubdivideDepth();
        }, [](BoxReference& b, int depth) {
            NativeReference<Box>(b)->setSubdivideDepth(depth);
        }),
        "subdivideHeight", sol::property([](BoxReference& b) {
            return NativeReference<Box>(b)->getSubdivideHeight();
        }, [](BoxReference& b, int height) {
            NativeReference<Box>(b)->setSubdivideHeight(height);
        }),
        "subdivideWidth", sol::property([](BoxReference& b) {
            return NativeReference<Box>(b)->getSubdivideWidth();
        }, [](BoxReference& b, int width) {
            NativeReference<Box>(b)->setSubdivideWidth(width);
        }),
        "getFromEntity", [](EntityReference& e) {
            return new BoxReference(
                NativeReference<Entity>(e)->getComponentByT<Box>()
            );
        },
        "cast", [](ComponentReference& cr) {
            return BoxReference(
                static_cast<Box*>(NativeReference<Component>(cr).ptr)
            );
        }
    );
}