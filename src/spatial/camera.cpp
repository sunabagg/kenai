#include "camera.h"
#include "../core/scene_system.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::spatial
{
    void bindCamera(sol::state& lua){
        lua.new_usertype<Camera>(
            "Camera",
            "new", sol::factories(
                []() { return new Camera(); }
            ),
            sol::base_classes, sol::bases<Component>(),
            sol::meta_function::garbage_collect, sol::destructor([](Camera* c) {  }),
            "cullMask", sol::property(&Camera::getCullMask, &Camera::setCullMask),
            "current", sol::property(&Camera::getCurrent, &Camera::setCurrent),
            "dopplerTracking", sol::property(&Camera::getDopplerTracking, &Camera::setDopplerTracking),
            "far", sol::property(&Camera::getFar, &Camera::setFar),
            "fov", sol::property(&Camera::getFov, &Camera::setFov),
            "frustumOffset", sol::property(&Camera::getFrustumOffset, &Camera::setFrustumOffset),
            "hOffset", sol::property(&Camera::getHOffset, &Camera::setHOffset),
            "keepAspect", sol::property(&Camera::getKeepAspect, &Camera::setKeepAspect),
            "near", sol::property(&Camera::getNear, &Camera::setNear),
            "projection", sol::property(&Camera::getProjection, &Camera::setProjection),
            "size", sol::property(&Camera::getSize, &Camera::setSize),
            "vOffset", sol::property(&Camera::getVOffset, &Camera::setVOffset),
            "clearCurrent", &Camera::clearCurrent,
            "getCullMaskValue", &Camera::getCullMaskValue,
            "getFrustum", &Camera::getFrustum,
            "isPositionBehind", &Camera::isPositionBehind,
            "makeCurrent", &Camera::makeCurrent,
            "projectLocalRayNormal", &Camera::projectLocalRayNormal,
            "projectPosition", &Camera::projectPosition,
            "projectRayNormal", &Camera::projectRayNormal,
            "projectRayOrigin", &Camera::projectRayOrigin,
            "setCullMaskValue", &Camera::setCullMaskValue,
            "setFrustum", &Camera::setFrustum,
            "setOrthogonal", &Camera::setOrthogonal,
            "setPerspective", &Camera::setPerspective,
            "unprojectPosition", &Camera::unprojectPosition,
            "getFromEntity", [](Entity* entity) {
                return entity->getComponentByT<Camera>();
            },
            "cast", [](Component* component) { 
                return dynamic_cast<Camera*>(component); 
            }
        );

    }
}