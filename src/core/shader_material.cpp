#include "shader_material.h"

void sunaba::core::bindShaderMaterial(sol::state_view& lua) {
        lua.new_usertype<ShaderMaterial>("ShaderMaterial",
            sol::constructors<ShaderMaterial(), ShaderMaterial(GodotShaderMaterial*)>(),
            sol::base_classes, sol::bases<sunaba::core::Material>(),
            "getShader", &ShaderMaterial::getShader,
            "setShader", &ShaderMaterial::setShader,
            "getShaderIntParam", &ShaderMaterial::getShaderIntParam,
            "setShaderIntParam", &ShaderMaterial::setShaderIntParam,
            "getShaderFloatParam", &ShaderMaterial::getShaderFloatParam,
            "setShaderFloatParam", &ShaderMaterial::setShaderFloatParam,
            "getShaderStringParam", &ShaderMaterial::getShaderStringParam,
            "setShaderStringParam", &ShaderMaterial::setShaderStringParam,
            "getShaderColorParam", &ShaderMaterial::getShaderColorParam,
            "setShaderColorParam", &ShaderMaterial::setShaderColorParam,
            "getShaderVector2Param", &ShaderMaterial::getShaderVector2Param,
            "setShaderVector2Param", &ShaderMaterial::setShaderVector2Param,
            "getShaderVector3Param", &ShaderMaterial::getShaderVector3Param,
            "setShaderVector3Param", &ShaderMaterial::setShaderVector3Param,
            "getShaderTransform2DParam", &ShaderMaterial::getShaderTransform2DParam,
            "setShaderTransform2DParam", &ShaderMaterial::setShaderTransform2DParam,
            "getShaderTransformParam", &ShaderMaterial::getShaderTransformParam,
            "setShaderTransformParam", &ShaderMaterial::setShaderTransformParam,
            "getShaderTextureParam", &ShaderMaterial::getShaderTextureParam,
            "setShaderTextureParam", &ShaderMaterial::setShaderTextureParam
    );
}

