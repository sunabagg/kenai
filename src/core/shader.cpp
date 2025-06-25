#include "shader.h"

void lucidware::core::bindShader(sol::state& lua) {
    lua.new_usertype<lucidware::core::Shader>("Shader",
        "new", sol::factories(
            []() { return new lucidware::core::Shader(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "code", sol::property(
            &lucidware::core::Shader::getCode,
            &lucidware::core::Shader::setCode
        ),
        "defaultTextureParameter", &lucidware::core::Shader::getDefaultTextureParameter,
        "getMode", &lucidware::core::Shader::getMode,
        "getShaderUniformList", &lucidware::core::Shader::getShaderUniformList,
        "cast", [](Resource* instance) {
            return new Shader(godot::Object::cast_to<GodotShader>(instance->getResource()));
        }
    );
}