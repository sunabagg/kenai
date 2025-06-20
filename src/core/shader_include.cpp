#include "shader_include.h"

void sunaba::core::bindShaderInclude(sol::state &lua) {
    lua.new_usertype<sunaba::core::ShaderInclude>("ShaderInclude",
        "new", sol::factories(
            []() { return new sunaba::core::ShaderInclude(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "code", sol::property(
            &sunaba::core::ShaderInclude::getCode, 
            &sunaba::core::ShaderInclude::setCode
        ),
        "cast", [](Resource* instance) {
            return new ShaderInclude(godot::Object::cast_to<GodotShaderInclude>(instance->getResource()));
        }
    );
}