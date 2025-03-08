#include "shader_include.h"

void sunaba::core::bindShaderInclude(sol::state &lua) {
    lua.new_usertype<sunaba::core::ShaderInclude>("ShaderInclude",
        sol::constructors<sunaba::core::ShaderInclude()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "code", sol::property(
            &sunaba::core::ShaderInclude::getCode, 
            &sunaba::core::ShaderInclude::setCode
        ),
        "cast", [](Resource* instance) {
            return new ShaderInclude(dynamic_cast<GodotShaderInclude*>(instance->getResource()));
        }
    );
}