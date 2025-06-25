#include "curve3d.h"

void lucidware::spatial::bindCurve3D(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::Curve3D>("Curve3D",
        "new", sol::factories(
            []() { return new lucidware::spatial::Curve3D(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "bakeInterval", sol::property(&Curve3D::getBakeInterval, &Curve3D::setBakeInterval),
        "closed", sol::property(&Curve3D::getClosed, &Curve3D::setClosed),
        "pointCount", sol::property(&Curve3D::getPointCount, &Curve3D::setPointCount),
        "upVectorEnabled", sol::property(&Curve3D::getUpVectorEnabled, &Curve3D::setUpVectorEnabled),
        "addPoint", &Curve3D::addPoint,
        "clearPoints", &Curve3D::clearPoints,
        "getBakedLength", &Curve3D::getBakedLength,
        "getBakedPoints", &Curve3D::getBakedPoints,
        "getBakedTilts", &Curve3D::getBakedTilts,
        "getBakedUpVectors", &Curve3D::getBakedUpVectors,
        "getClosestOffset", &Curve3D::getClosestOffset,
        "getClosestPoint", &Curve3D::getClosestPoint,
        "getPointIn", &Curve3D::getPointIn,
        "getPointOut", &Curve3D::getPointOut,
        "getPointPosition", &Curve3D::getPointPosition,
        "getPointTilt", &Curve3D::getPointTilt,
        "removePoint", &Curve3D::removePoint,
        "sample", &Curve3D::sample,
        "sampleBaked", &Curve3D::sampleBaked,
        "sampleBakedUpVector", &Curve3D::sampleBakedUpVector,
        "sampleBakedWithRotation", &Curve3D::sampleBakedWithRotation,
        "samplef", &Curve3D::samplef,
        "setPointIn", &Curve3D::setPointIn,
        "setPointOut", &Curve3D::setPointOut,
        "setPointPosition", &Curve3D::setPointPosition,
        "setPointTilt", &Curve3D::setPointTilt,
        "tessellate", &Curve3D::tessellate,
        "tessellateEvenLength", &Curve3D::tessellateEvenLength,
        "cast", [](lucidware::core::Resource* instance) {
            return new Curve3D(godot::Object::cast_to<GodotCurve3D>(instance->getResource()));
        }
    );
}