#include "shader_include.h"

void lucidfx::core::bindShaderInclude(sol::state &lua) {
    lua.new_usertype<lucidfx::core::ShaderInclude>("ShaderInclude",
        "new", sol::factories(
            []() { return new lucidfx::core::ShaderInclude(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
        "code", sol::property(
            &lucidfx::core::ShaderInclude::getCode, 
            &lucidfx::core::ShaderInclude::setCode
        ),
        "cast", [](Resource* instance) {
            return new ShaderInclude(godot::Object::cast_to<GodotShaderInclude>(instance->getResource()));
        }
    );
}