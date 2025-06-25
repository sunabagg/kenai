#ifndef CANVAS_ITEM_MATERIAL_H
#define CANVAS_ITEM_MATERIAL_H

#include <godot_cpp/classes/canvas_item_material.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotCanvasItemMaterial godot::CanvasItemMaterial

#include "material.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidfx::core {
    void bindCanvasItemMaterial(sol::state_view& lua);

    class CanvasItemMaterial : public Material {
    private:
        GodotCanvasItemMaterial* canvasItemMaterial;
    public:
        
        CanvasItemMaterial(GodotCanvasItemMaterial* material) {
            setCanvasItemMaterial(material);
        }

        CanvasItemMaterial() {
            setCanvasItemMaterial(memnew(GodotCanvasItemMaterial));
        }

        GodotCanvasItemMaterial* getCanvasItemMaterial() {
            return canvasItemMaterial;
        }

        void setCanvasItemMaterial(GodotCanvasItemMaterial* m) {
            canvasItemMaterial = m;
            canvasItemMaterial->reference();
            setMaterial(canvasItemMaterial);
        }

        int getBlendMode() {
            return canvasItemMaterial->get_blend_mode();
        }

        void setBlendMode(int mode) {
            canvasItemMaterial->set_blend_mode(static_cast<GodotCanvasItemMaterial::BlendMode>(mode));
        }

        int getLightMode() {
            return canvasItemMaterial->get_light_mode();
        }

        void setLightMode(int mode) {
            canvasItemMaterial->set_light_mode(static_cast<GodotCanvasItemMaterial::LightMode>(mode));
        }

        int getParticlesAnimHFrames() {
            return canvasItemMaterial->get_particles_anim_h_frames();
        }

        void setParticlesAnimHFrames(int frames) {
            canvasItemMaterial->set_particles_anim_h_frames(frames);
        }

        bool getParticlesAnimLoop() {
            return canvasItemMaterial->get_particles_anim_loop();
        }

        void setParticlesAnimLoop(bool loop) {
            canvasItemMaterial->set_particles_anim_loop(loop);
        }

        int getParticlesAnimVFrames() {
            return canvasItemMaterial->get_particles_anim_v_frames();
        }

        void setParticlesAnimVFrames(int frames) {
            canvasItemMaterial->set_particles_anim_v_frames(frames);
        }

        bool getPaticlesAnimation() {
            return canvasItemMaterial->get_particles_animation();
        }

        void setParticlesAnimation(bool animation) {
            canvasItemMaterial->set_particles_animation(animation);
        }
    };
}

#endif