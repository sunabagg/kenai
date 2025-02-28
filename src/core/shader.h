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

namespace sunaba::core {
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

        String getCode() const {
            return shader->get_code();
        }
        
        void setCode(const String &code) {
            shader->set_code(code);
        }

        Texture2D* getDefaultTextureParameter(const StringName &name, int32_t index = 0) {
            return new Texture2D(shader->get_default_texture_parameter(name, index).ptr());
        }

        int getMode() const {
            return shader->get_mode();
        }

        sol::table getShaderUniformList() {
            auto list = shader->get_shader_uniform_list();
            sol::table table;
            for (int i = 0; i < list.size(); ++i) {
                table[i + 1] = list[i];
            }
            return table;
        }

        void setDefaultTextureParameter(const StringName &name, Texture2D* texture, int32_t index = 0) {
            shader->set_default_texture_parameter(name, texture->getTexture2D(), index);
        }
    };
}


#endif