#include "material.h"

void lucidfx::core::bindMaterial(sol::state_view& lua) {
    lua.new_usertype<Material>("Material",
        "new", sol::factories(
            []() { return new Material(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
        "nextPass", sol::property(&Material::getNextPass, &Material::setNextPass),
        "renderPriority", sol::property(&Material::getRenderPriority, &Material::setRenderPriority),
        "createPlaceholder", &Material::createPlaceholder
    );
}