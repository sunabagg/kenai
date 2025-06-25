#ifndef SHADER_INCLUDE_H
#define SHADER_INCLUDE_H

#include <godot_cpp/classes/shader_include.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotShaderInclude godot::ShaderInclude

#include "resource.h"

using namespace godot;

namespace lucidfx::core {
    void bindShaderInclude(sol::state &lua);

    class ShaderInclude : public Resource {
    private:
        GodotShaderInclude* shaderInclude = nullptr; // Pointer to the Shader instance
    public:
        // Constructor with Ref<GodotShader> parameter
        ShaderInclude(GodotShaderInclude* shaderInclude) {
            setShader(shaderInclude);
        }

        // Constructor with no parameters
        ShaderInclude() {
            setShader(memnew(GodotShaderInclude));
        }

        // Getter for the Shader node
        GodotShaderInclude* getShader() {
            return shaderInclude;
        }

        // Setter for the Shader node
        void setShader(GodotShaderInclude* shaderInclude) {
            this->shaderInclude = shaderInclude;
            shaderInclude->reference();
            setResource(shaderInclude);
        }

        void setCode(const std::string& code) {
            shaderInclude->set_code(code.c_str());
        }

        std::string getCode() const {
            return shaderInclude->get_code().utf8().get_data();
        }
    };
}

#endif