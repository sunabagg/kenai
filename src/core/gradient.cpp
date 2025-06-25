#include "gradient.h"

void lucidfx::core::bindGradient(sol::state_view& lua) {
        lua.new_usertype<Gradient>("Gradient",
            "new", sol::factories(
                []() { return new Gradient(); }
            ),
            sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
            "colors", sol::property(&Gradient::getColors, &Gradient::setColors),
            "interpolationColorSpace", sol::property(&Gradient::getInterpolationColorSpace, &Gradient::setInterpolationColorSpace),
            "interpolationMode", sol::property(&Gradient::getInterpolationMode, &Gradient::setInterpolationMode),
            "offsets", sol::property(&Gradient::getOffsets, &Gradient::setOffsets),
            "addPoint", &Gradient::addPoint,
            "getColor", &Gradient::getColor,
            "getOffset", &Gradient::getOffset,
            "getPointCount", &Gradient::getPointCount,
            "removePoint", &Gradient::removePoint,
            "reverse", &Gradient::reverse,
            "sample", &Gradient::sample,
            "setColor", &Gradient::setColor,
            "setOffset", &Gradient::setOffset,
            "cast", [](Resource* instance) {
                return new Gradient(godot::Object::cast_to<GodotGradient>(instance->getResource()));
            }
    );
}