#include "transform.h"

using namespace sunaba::core;
using namespace godot;

namespace sunaba::spatial {

    void bindSpatialTransform(sol::state& lua) {
        lua.new_usertype<SpatialTransformReference>("SpatialTransform",  
            sol::constructors<SpatialTransformReference()>(), 
            sol::base_classes, sol::bases<ComponentReference>(),
            "basis", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getBasis();
            }, [](SpatialTransformReference& s, Basis b) {
                NativeReference<SpatialTransform>(s)->setBasis(b);
            }),
            "position", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getPosition();
            }, [](SpatialTransformReference& s, Vector3 p) {
                NativeReference<SpatialTransform>(s)->setPosition(p);
            }),
            "rotation", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getRotation();
            }, [](SpatialTransformReference& s, Vector3 r) {
                NativeReference<SpatialTransform>(s)->setRotation(r);
            }),
            "rotationDegrees", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getRotationDegrees();
            }, [](SpatialTransformReference& s, Vector3 r) {
                NativeReference<SpatialTransform>(s)->setRotationDegrees(r);
            }),
            "scale", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getScale();
            }, [](SpatialTransformReference& st, Vector3 s) {
                NativeReference<SpatialTransform>(st)->setScale(s);
            }),
            "quaternion", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getQuaternion();
            }, [](SpatialTransformReference& s, Quaternion q) {
                NativeReference<SpatialTransform>(s)->setQuaternion(q);
            }),
            "rotationOrder", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getRotationOrder();
            }, [](SpatialTransformReference& s, int order) {
                NativeReference<SpatialTransform>(s)->setRotationOrder(order);
            }),
            "globalPosition", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getGlobalPosition();
            }, [](SpatialTransformReference& s, Vector3 p) {
                NativeReference<SpatialTransform>(s)->setGlobalPosition(p);
            }),
            "globalRotation", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getGlobalRotation();
            }, [](SpatialTransformReference& s, Vector3 r) {
                NativeReference<SpatialTransform>(s)->setGlobalRotation(r);
            }),
            "globalRotationDegrees", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getGlobalRotationDegrees();
            }, [](SpatialTransformReference& s, Vector3 r) {
                NativeReference<SpatialTransform>(s)->setGlobalRotationDegrees(r);
            }),
            "globalBasis", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getGlobalBasis();
            }, [](SpatialTransformReference& s, Basis b) {
                NativeReference<SpatialTransform>(s)->setGlobalBasis(b);
            }),
            "global", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getGlobalTransform();
            }, [](SpatialTransformReference& s, Transform3D t) {
                NativeReference<SpatialTransform>(s)->setGlobalTransform(t);
            }),
            "local", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getTransform();
            }, [](SpatialTransformReference& s, Transform3D t) {
                NativeReference<SpatialTransform>(s)->setTransform(t);
            }),
            "isTopLevel", sol::property([](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->isTopLevel();
            }),
            "forceUpdate", [](SpatialTransformReference& s) {
                NativeReference<SpatialTransform>(s)->forceUpdate(); 
            },
            "getParent", [](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->getParentTransform();
            },
            "globalRotate", [](SpatialTransformReference& s, Vector3 axis, float angle) {
                NativeReference<SpatialTransform>(s)->GlobalRotate(axis, angle);
            },
            "globalTranslate", [](SpatialTransformReference& s, Vector3 offset) {
                NativeReference<SpatialTransform>(s)->GlobalTranslate(offset);
            },
            "globalScale", [](SpatialTransformReference& s, Vector3 scale) {
                NativeReference<SpatialTransform>(s)->globalScale(scale);
            },
            "hide", [](SpatialTransformReference& s) {
                NativeReference<SpatialTransform>(s)->hide();
            },
            "isScaleDisabled", [](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->isScaleDisabled();
            },
            "isVisible", [](SpatialTransformReference& s) {
                return NativeReference<SpatialTransform>(s)->isVisibleInTree();
            },
            "lookAt", [](SpatialTransformReference& s, Vector3 target, Vector3 up = Vector3(0, 1, 0), bool useModelFront = false) {
                NativeReference<SpatialTransform>(s)->lookAt(target, up, useModelFront);
            },
            "lookAtFromPosition", [](SpatialTransformReference& s, Vector3 position, Vector3 target, Vector3 up = Vector3(0, 1, 0), bool useModelFront = false) {
                NativeReference<SpatialTransform>(s)->lookAtFromPosition(position, target, up, useModelFront);
            },
            "orthonormalize", [](SpatialTransformReference& s) {
                NativeReference<SpatialTransform>(s)->orthonormalize();
            },
            "rotate", [](SpatialTransformReference& s, Vector3 axis, float angle) {
                NativeReference<SpatialTransform>(s)->rotate(axis, angle);
            },
            "rotateObjectLocal", [](SpatialTransformReference& s, Vector3 axis, float angle) {
                NativeReference<SpatialTransform>(s)->rotateObjectLocal(axis, angle);
            },
            "rotateX", [](SpatialTransformReference& s, float angle) {
                NativeReference<SpatialTransform>(s)->rotateX(angle);
            },
            "rotateY", [](SpatialTransformReference& s, float angle) {
                NativeReference<SpatialTransform>(s)->rotateY(angle);
            },
            "rotateZ", [](SpatialTransformReference& s, float angle) {
                NativeReference<SpatialTransform>(s)->rotateZ(angle);
            },
            "scaleObjectLocal", [](SpatialTransformReference& s, Vector3 scale) {
                NativeReference<SpatialTransform>(s)->scaleObjectLocal(scale);
            },
            "setDisableScale", [](SpatialTransformReference& s, bool disable) {
                NativeReference<SpatialTransform>(s)->setDisableScale(disable);
            },
            "setIdentity", [](SpatialTransformReference& s) {
                NativeReference<SpatialTransform>(s)->setIdentity();
            },
            "show", [](SpatialTransformReference& s) {
                NativeReference<SpatialTransform>(s)->show();
            },
            "toGlobal", [](SpatialTransformReference& s, Vector3 offset) {
                return NativeReference<SpatialTransform>(s)->toGlobal(offset);
            },
            "toLocal", [](SpatialTransformReference& s, Vector3 offset) {
                return NativeReference<SpatialTransform>(s)->toLocal(offset);
            },
            "translate", [](SpatialTransformReference& s, Vector3 offset) {
                NativeReference<SpatialTransform>(s)->translate(offset);
            },
            "translateObjectLocal", [](SpatialTransformReference& s, Vector3 offset) {
                NativeReference<SpatialTransform>(s)->translateObjectLocal(offset);
            },
            "getFromEntity", [](EntityReference& entity) { 
                return new SpatialTransformReference(
                    NativeReference<Entity>(entity)->getComponentByT<SpatialTransform>()
                );
             },
             "onInit", [](SpatialTransformReference& s) { 
                NativeReference<SpatialTransform>(s)->onInit(); 
             },
            "onFree", [](SpatialTransformReference& s) { 
                NativeReference<SpatialTransform>(s)->onFree(); 
            },
             "cast", [](ComponentReference component) { 
                return SpatialTransformReference(
                    static_cast<SpatialTransform*>(NativeReference<Component>(component).ptr)
                ); 
             });
    }
}

