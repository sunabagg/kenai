#include "transform.h"

using namespace lucidware::core;
using namespace godot;

namespace lucidware::spatial {

    void bindSpatialTransform(sol::state& lua) {
        lua.new_usertype<SpatialTransform>("SpatialTransform",  
            "new", sol::factories(
                []() { return new SpatialTransform(); }
            ),
            sol::base_classes, sol::bases<Component>(),
            sol::meta_function::garbage_collect, sol::destructor([](SpatialTransform* t) {  }),
            "basis", sol::property(&SpatialTransform::getBasis, &SpatialTransform::setBasis),
            "position", sol::property(&SpatialTransform::getPosition, &SpatialTransform::setPosition),
            "rotation", sol::property(&SpatialTransform::getRotation, &SpatialTransform::setRotation),
            "rotationDegrees", sol::property(&SpatialTransform::getRotationDegrees, &SpatialTransform::setRotationDegrees),
            "scale", sol::property(&SpatialTransform::getScale, &SpatialTransform::setScale),
            "quaternion", sol::property(&SpatialTransform::getQuaternion, &SpatialTransform::setQuaternion),
            "rotationOrder", sol::property(&SpatialTransform::getRotationOrder, &SpatialTransform::setRotationOrder),
            "globalPosition", sol::property(&SpatialTransform::getGlobalPosition, &SpatialTransform::setGlobalPosition),
            "globalRotation", sol::property(&SpatialTransform::getGlobalRotation, &SpatialTransform::setGlobalRotation),
            "globalRotationDegrees", sol::property(&SpatialTransform::getGlobalRotationDegrees, &SpatialTransform::setGlobalRotationDegrees),
            "globalBasis", sol::property(&SpatialTransform::getGlobalBasis, &SpatialTransform::setGlobalBasis),
            "global", sol::property(&SpatialTransform::getGlobalTransform, &SpatialTransform::setGlobalTransform),
            "local", sol::property(&SpatialTransform::getTransform, &SpatialTransform::setTransform),
            "isTopLevel", &SpatialTransform::isTopLevel,
            "forceUpdate", &SpatialTransform::forceUpdate,
            "getParent", &SpatialTransform::getParentTransform,
            "globalRotate", &SpatialTransform::GlobalRotate,
            "globalTranslate", &SpatialTransform::GlobalTranslate,
            "globalScale", &SpatialTransform::globalScale,
            "hide", &SpatialTransform::hide,
            "isScaleDisabled", &SpatialTransform::isScaleDisabled,
            "isVisible", &SpatialTransform::isVisibleInTree,
            "lookAt", &SpatialTransform::lookAt,
            "lookAtFromPosition", &SpatialTransform::lookAtFromPosition,
            "orthonormalize", &SpatialTransform::orthonormalize,
            "rotate", &SpatialTransform::rotate,
            "rotateObjectLocal", &SpatialTransform::rotateObjectLocal,
            "rotateX", &SpatialTransform::rotateX,
            "rotateY", &SpatialTransform::rotateY,
            "rotateZ", &SpatialTransform::rotateZ,
            "scaleObjectLocal", &SpatialTransform::scaleObjectLocal,
            "setDisableScale", &SpatialTransform::setDisableScale,
            "setIdentity", &SpatialTransform::setIdentity,
            "show", &SpatialTransform::show,
            "toGlobal", &SpatialTransform::toGlobal,
            "toLocal", &SpatialTransform::toLocal,
            "translate", &SpatialTransform::translate,
            "translateObjectLocal", &SpatialTransform::translateObjectLocal,
            "getFromEntity", [](Entity* entity) { 
                return entity->getComponentByT<SpatialTransform>();
             },
             "cast", [](Component* component) { 
                return dynamic_cast<SpatialTransform*>(component); 
             }
        );

    }
}

