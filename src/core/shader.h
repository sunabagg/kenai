#ifndef SHADER_H
#define SHADER_H

#include <godot_cpp/classes/shader.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotShader godot::Shader

#include "resource.h"
#include "texture2d.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidware::core {
    void bindShader(sol::state &lua);

    class Shader : public Resource {
    private:
        GodotShader* shader = nullptr; // Pointer to the Shader instance
    public:
        // Constructor with Ref<GodotShader> parameter
        Shader(GodotShader* shader) {
            setShader(shader);
        }

        // Constructor with no parameters
        Shader() {
            setShader(memnew(GodotShader));
        }

        // Getter for the Shader node
        GodotShader* getShader() {
            return shader;
        }

        // Setter for the Shader node
        void setShader(GodotShader* shader) {
            this->shader = shader;
            shader->reference();
            setResource(shader);
        }

        std::string getCode() const {
            return shader->get_code().utf8().get_data();
        }
        
        void setCode(const std::string& code) {
            shader->set_code(code.c_str());
        }

        Texture2D* getDefaultTextureParameter(const std::string &name, int32_t index = 0) {
            Ref<godot::Texture2D> gdtxt2d = shader->get_default_texture_parameter(name.c_str(), index);
            return new Texture2D(gdtxt2d.ptr());
        }

        int getMode() const {
            return shader->get_mode();
        }

        Array getShaderUniformList() {
            return shader->get_shader_uniform_list();
        }

        void setDefaultTextureParameter(const std::string &name, Texture2D* texture, int32_t index = 0) {
            shader->set_default_texture_parameter(name.c_str(), texture->getTexture2D(), index);
        }
    };
}


#endif