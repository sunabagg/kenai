#include "shader_include.h"

void kenai::core::bindShaderInclude(sol::state &lua) {
    lua.new_usertype<kenai::core::ShaderInclude>("ShaderInclude",
        "new", sol::factories(
            []() { return new kenai::core::ShaderInclude(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource>(),
        "code", sol::property(
            &kenai::core::ShaderInclude::getCode, 
            &kenai::core::ShaderInclude::setCode
        ),
        "cast", [](Resource* instance) {
            return new ShaderInclude(godot::Object::cast_to<GodotShaderInclude>(instance->getResource()));
        }
    );
}