#include "shader.h"

void lucidfx::core::bindShader(sol::state& lua) {
    lua.new_usertype<lucidfx::core::Shader>("Shader",
        "new", sol::factories(
            []() { return new lucidfx::core::Shader(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
        "code", sol::property(
            &lucidfx::core::Shader::getCode,
            &lucidfx::core::Shader::setCode
        ),
        "defaultTextureParameter", &lucidfx::core::Shader::getDefaultTextureParameter,
        "getMode", &lucidfx::core::Shader::getMode,
        "getShaderUniformList", &lucidfx::core::Shader::getShaderUniformList,
        "cast", [](Resource* instance) {
            return new Shader(godot::Object::cast_to<GodotShader>(instance->getResource()));
        }
    );
}