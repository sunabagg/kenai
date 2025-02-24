#include "camera.h"
#include "../core/scene_system.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::spatial
{
    void bindCamera(sol::state& lua){
        lua.new_usertype<CameraReference>(
            "Camera",
            sol::constructors<CameraReference()>(),
            sol::base_classes, sol::bases<ComponentReference>(),
            "cullMask", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getCullMask();
            }, [](CameraReference& c, int mask) {
                NativeReference<Camera>(c)->setCullMask(mask);
            }),
            "current", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getCurrent();
            }, [](CameraReference& c, bool current) {
                NativeReference<Camera>(c)->setCurrent(current);
            }),
            "dopplerTracking", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getDopplerTracking();
            }, [](CameraReference& c, int tracking) {
                NativeReference<Camera>(c)->setDopplerTracking(tracking);
            }),
            "far", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getFar();
            }, [](CameraReference& c, float far) {
                NativeReference<Camera>(c)->setFar(far);
            }),
            "fov", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getFov();
            }, [](CameraReference& c, float fov) {
                NativeReference<Camera>(c)->setFov(fov);
            }),
            "frustumOffset", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getFrustumOffset();
            }, [](CameraReference& c, Vector2 offset) {
                NativeReference<Camera>(c)->setFrustumOffset(offset);
            }),
            "hOffset", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getHOffset();
            }, [](CameraReference& c, float offset) {
                NativeReference<Camera>(c)->setHOffset(offset);
            }),
            "keepAspect", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getKeepAspect();
            }, [](CameraReference& c, bool keep) {
                NativeReference<Camera>(c)->setKeepAspect(keep);
            }),
            "near", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getNear();
            }, [](CameraReference& c, float near) {
                NativeReference<Camera>(c)->setNear(near);
            }),
            "projection", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getProjection();
            }, [](CameraReference& c, int projection) {
                NativeReference<Camera>(c)->setProjection(projection);
            }),
            "size", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getSize();
            }, [](CameraReference& c, float size) {
                NativeReference<Camera>(c)->setSize(size);
            }),
            "vOffset", sol::property([](CameraReference& c) {
                return NativeReference<Camera>(c)->getVOffset();
            }, [](CameraReference& c, float offset) {
                NativeReference<Camera>(c)->setVOffset(offset);
            }),
            "clearCurrent", [](CameraReference& c) {
                NativeReference<Camera>(c)->clearCurrent();
            },
            "getCullMaskValue", [](CameraReference& c, int index) {
                return NativeReference<Camera>(c)->getCullMaskValue(index);
            },
            "getFrustum", [](CameraReference& c) {
                return NativeReference<Camera>(c)->getFrustum();
            },
            "isPositionBehind", [](CameraReference& c, Vector3 position) {
                return NativeReference<Camera>(c)->isPositionBehind(position);
            },
            "makeCurrent", [](CameraReference& c) {
                NativeReference<Camera>(c)->makeCurrent();
            },
            "projectLocalRayNormal", [](CameraReference& c, Vector2 screenPoint) {
                return NativeReference<Camera>(c)->projectLocalRayNormal(screenPoint);
            },
            "projectPosition", [](CameraReference& c, Vector2 screenPoint, float zDepth) {
                return NativeReference<Camera>(c)->projectPosition(screenPoint, zDepth);
            },
            "projectRayNormal", [](CameraReference& c, Vector2 screenPoint) {
                return NativeReference<Camera>(c)->projectRayNormal(screenPoint);
            },
            "projectRayOrigin", [](CameraReference& c, Vector2 screenPoint) {
                return NativeReference<Camera>(c)->projectRayOrigin(screenPoint);
            },
            "setCullMaskValue", [](CameraReference& c, int index, bool value) {
                NativeReference<Camera>(c)->setCullMaskValue(index, value);
            },
            "setFrustum", [](CameraReference& c, float size, Vector2 offset, float zNear, float zFar) {
                NativeReference<Camera>(c)->setFrustum(size, offset, zNear, zFar);
            },
            "setOrthogonal", [](CameraReference& c, float size, float zNear, float zFar) {
                NativeReference<Camera>(c)->setOrthogonal(size, zNear, zFar);
            },
            "setPerspective", [](CameraReference& c, float fov, float zNear, float zFar) {
                NativeReference<Camera>(c)->setPerspective(fov, zNear, zFar);
            },
            "unprojectPosition", [](CameraReference& c, Vector3 position) {
                return NativeReference<Camera>(c)->unprojectPosition(position);
            },
            "onInit", [](CameraReference& c) {
                NativeReference<Camera>(c)->onInit();
            },
            "onReady", [](CameraReference& c) {
                NativeReference<Camera>(c)->onReady();
            },
            "getFromEntity", [](EntityReference& e) {
                return new CameraReference(
                    NativeReference<Entity>(e)->getComponentByT<Camera>()
                );
            },
            "cast", [](ComponentReference& cr) {
                return CameraReference(
                    static_cast<Camera*>(NativeReference<Component>(cr).ptr)
                );
            }
        );

    }
}