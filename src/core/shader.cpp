#include "shader.h"

void kenai::core::bindShader(sol::state& lua) {
    lua.new_usertype<kenai::core::Shader>("Shader",
        "new", sol::factories(
            []() { return new kenai::core::Shader(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource>(),
        "code", sol::property(
            &kenai::core::Shader::getCode,
            &kenai::core::Shader::setCode
        ),
        "defaultTextureParameter", &kenai::core::Shader::getDefaultTextureParameter,
        "getMode", &kenai::core::Shader::getMode,
        "getShaderUniformList", &kenai::core::Shader::getShaderUniformList,
        "cast", [](Resource* instance) {
            return new Shader(godot::Object::cast_to<GodotShader>(instance->getResource()));
        }
    );
}