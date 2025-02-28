#include "shader.h"

void sunaba::core::bindShader(sol::state& lua) {
    lua.new_usertype<sunaba::core::Shader>("Shader",
        sol::constructors<sunaba::core::Shader()>(),
        sol::base_classes, sol::bases<sunaba::core::Resource>(),
        "code", sol::property(
            &sunaba::core::Shader::getCode,
            &sunaba::core::Shader::setCode
        ),
        "defaultTextureParameter", &sunaba::core::Shader::getDefaultTextureParameter,
        "getMode", &sunaba::core::Shader::getMode,
        "getShaderUniformList", &sunaba::core::Shader::getShaderUniformList,
        "cast", [](Resource* instance) {
            return new Shader(static_cast<GodotShader*>(instance->getResource()));
        }
    );
}