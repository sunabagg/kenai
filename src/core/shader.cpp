#include "shader.h"

void sunaba::core::bindShader(sol::state& lua) {
    lua.new_usertype<sunaba::core::Shader>("Shader",
        "new", sol::factories(
            []() { return new sunaba::core::Shader(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "code", sol::property(
            &sunaba::core::Shader::getCode,
            &sunaba::core::Shader::setCode
        ),
        "defaultTextureParameter", &sunaba::core::Shader::getDefaultTextureParameter,
        "getMode", &sunaba::core::Shader::getMode,
        "getShaderUniformList", &sunaba::core::Shader::getShaderUniformList,
        "cast", [](Resource* instance) {
            return new Shader(godot::Object::cast_to<GodotShader>(instance->getResource()));
        }
    );
}