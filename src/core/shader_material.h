#ifndef SHADER_MATERIAL_H
#define SHADER_MATERIAL_H

#include <godot_cpp/classes/shader_material.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotShaderMaterial godot::ShaderMaterial

#include "material.h"
#include "shader.h"
#include "convert_godot_lua.h"
#include "texture.h"

using namespace godot;

namespace lucidfx::core {
    void bindShaderMaterial(sol::state_view& lua);

    class ShaderMaterial : public Material {
    private:
        GodotShaderMaterial* material;
    public:
        ShaderMaterial(GodotShaderMaterial* m) {
            setShaderMaterial(m);
        }

        ShaderMaterial() {
            setShaderMaterial(memnew(GodotShaderMaterial));
        }

        GodotShaderMaterial* getShaderMaterial() const {
            return material;
        }

        void setShaderMaterial(GodotShaderMaterial* m) {
            material = m;
            material->reference();
            setMaterial(m);
        }

        Shader* getShader() {
            auto shader = material->get_shader().ptr();
            if (shader == nullptr) {
                return nullptr;
            }
            return new Shader(shader);
        }

        void setShader(Shader* shader) {
            material->set_shader(shader->getShader());
        }

        int getShaderIntParam(const std::string& name) {
            Variant v = material->get_shader_parameter(name.c_str());
            return v.operator int();
        }

        void setShaderIntParam(const std::string& name, int value) {
            material->set_shader_parameter(name.c_str(), value);
        }

        float getShaderFloatParam(const std::string& name) {
            Variant v = material->get_shader_parameter(name.c_str());
            return v.operator float();
        }

        void setShaderFloatParam(const std::string& name, float value) {
            material->set_shader_parameter(name.c_str(), value);
        }

        Color getShaderColorParam(const std::string& name) {
            Variant v = material->get_shader_parameter(name.c_str());
            return v.operator Color();
        }

        std::string getShaderStringParam(const std::string& name) {
            Variant v = material->get_shader_parameter(name.c_str());
            return v.operator String().utf8().get_data();
        }

        void setShaderStringParam(const std::string& name, const std::string& value) {
            material->set_shader_parameter(name.c_str(), value.c_str());
        }

        void setShaderColorParam(const std::string& name, const Color& value) {
            material->set_shader_parameter(name.c_str(), value);
        }

        Vector2 getShaderVector2Param(const std::string& name) {
            Variant v = material->get_shader_parameter(name.c_str());
            return v.operator Vector2();
        }

        void setShaderVector2Param(const std::string& name, const Vector2& value) {
            material->set_shader_parameter(name.c_str(), value);
        }

        Vector3 getShaderVector3Param(const std::string& name) {
            Variant v = material->get_shader_parameter(name.c_str());
            return v.operator Vector3();
        }

        void setShaderVector3Param(const std::string& name, const Vector3& value) {
            material->set_shader_parameter(name.c_str(), value);
        }

        Transform2D getShaderTransform2DParam(const std::string& name) {
            Variant v = material->get_shader_parameter(name.c_str());
            return v.operator Transform2D();
        }

        void setShaderTransform2DParam(const std::string& name, const Transform2D& value) {
            material->set_shader_parameter(name.c_str(), value);
        }

        Transform3D getShaderTransformParam(const std::string& name) {
            Variant v = material->get_shader_parameter(name.c_str());
            return v.operator Transform3D();
        }

        void setShaderTransformParam(const std::string& name, const Transform3D& value) {
            material->set_shader_parameter(name.c_str(), value);
        }

        Texture* getShaderTextureParam(const std::string& name) {
            Variant v = material->get_shader_parameter(name.c_str());
            Object* obj = v;
            if (obj == nullptr) {
                return nullptr;
            }

            GodotTexture* tex = godot::Object::cast_to<GodotTexture>(obj);
            if (tex == nullptr) {
                return nullptr;
            }
            return new Texture(tex);
        }

        void setShaderTextureParam(const std::string& name, Texture* value) {
            material->set_shader_parameter(name.c_str(), value->getTexture());
        }
    };
}

#endif // SHADER_MATERIAL_H