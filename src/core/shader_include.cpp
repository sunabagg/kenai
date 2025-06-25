#include "shader_include.h"

void lucidware::core::bindShaderInclude(sol::state &lua) {
    lua.new_usertype<lucidware::core::ShaderInclude>("ShaderInclude",
        "new", sol::factories(
            []() { return new lucidware::core::ShaderInclude(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "code", sol::property(
            &lucidware::core::ShaderInclude::getCode, 
            &lucidware::core::ShaderInclude::setCode
        ),
        "cast", [](Resource* instance) {
            return new ShaderInclude(godot::Object::cast_to<GodotShaderInclude>(instance->getResource()));
        }
    );
}