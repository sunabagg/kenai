#ifndef SKIN_H
#define SKIN_H

#include <godot_cpp/classes/skin.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotSkin godot::Skin

#include "../core/resource.h"

using namespace godot;

namespace lucidfx::spatial {
    void bindSkin(sol::state_view& lua);

    class Skin : public lucidfx::core::Resource {
    private:
        GodotSkin* skin = nullptr;
    public:
        Skin() {
            setSkin(memnew(GodotSkin));
        }

        Skin(GodotSkin* s) {
            setSkin(s);
        }

        GodotSkin* getSkin() {
            return skin;
        }

        void setSkin(GodotSkin* s) {
            skin = s;
            skin->reference();
            setResource(skin);
        }

        void addBind(int bone, Transform3D pose) {
            skin->add_bind(bone, pose);
        }

        void addNamedBind(std::string name, Transform3D pose) {
            skin->add_named_bind(name.c_str(), pose);
        }

        void clearBinds() {
            skin->clear_binds();
        }

        int getBindBone(int bindIndex) {
            return skin->get_bind_bone(bindIndex);
        }

        int getBindCount() {
            return skin->get_bind_count();
        }

        std::string getBindName(int bindIndex) {
            return String(skin->get_bind_name(bindIndex)).utf8().get_data();
        }

        Transform3D getBindPose(int bindIndex) {
            return skin->get_bind_pose(bindIndex);
        }

        void setBindBone(int bindIndex, int bone) {
            skin->set_bind_bone(bindIndex, bone);
        }

        void setBindCount(int bindCount) {
            skin->set_bind_count(bindCount);
        }

        void setBindName(int bindIndex, std::string name) {
            skin->set_bind_name(bindIndex, name.c_str());
        }

        void setBindPose(int bindIndex, Transform3D pose) {
            skin->set_bind_pose(bindIndex, pose);
        }
    };
}

#endif // SKIN_H