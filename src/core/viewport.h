#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ViewportNode godot::Viewport

#include "element.h"

using namespace godot;

namespace sunaba::core {
    void bindViewport(sol::state &lua);

    class Viewport;

    class ViewportProxy : public ViewportNode {
        public:
            sunaba::core::Viewport* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override ;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;
    };

    class Viewport : public Element {
        private:
            ViewportNode* viewport = nullptr; // Pointer to the Viewport instance
            void connectViewportSignals() {
                // Connect signals specific to Viewport
            }

        public:
            Viewport() {
                setViewport(memnew(ViewportProxy));
                onInit();
            }

            ViewportNode* getViewport() {
                return viewport;
            }

            void setViewport(ViewportNode* viewport) {
                this->viewport = viewport;
                connectViewportSignals();
                setNode(viewport);
            }

            void setViewport(ViewportProxy* viewport) {
                this->viewport = viewport;
                viewport->element = this;
                connectViewportSignals();
                setNode(viewport);
            }

            int getAnisotropicFilteringLevel() {
                return viewport->get_anisotropic_filtering_level();
            }

            void setAnisotropicFilteringLevel(int level) {
                viewport->set_anisotropic_filtering_level(static_cast<godot::Viewport::AnisotropicFiltering>(level));
            }

            bool getAudioListenerEnable2D() {
                return viewport->is_audio_listener_2d();
            }

            void setAudioListenerEnable2D(bool enable) {
                viewport->set_as_audio_listener_2d(enable);
            }

            bool getAudioListenerEnable3D() {
                return viewport->is_audio_listener_3d();
            }

            void setAudioListenerEnable3D(bool enable) {
                viewport->set_as_audio_listener_3d(enable);
            }

            int getCanvasCullMask() {
                return viewport->get_canvas_cull_mask();
            }

            void setCanvasCullMask(int mask) {
                viewport->set_canvas_cull_mask(mask);
            }

            int getCanvasItemDefaultTextureFilter() {
                return viewport->get_default_canvas_item_texture_filter();
            }

            void setCanvasItemDefaultTextureFilter(int filter) {
                viewport->set_default_canvas_item_texture_filter(static_cast<godot::Viewport::DefaultCanvasItemTextureFilter>(filter));
            }

            int getCanvasItemDefaultTextureRepeat() {
                return viewport->get_default_canvas_item_texture_repeat();
            }

            void setCanvasItemDefaultTextureRepeat(int repeat) {
                viewport->set_default_canvas_item_texture_repeat(static_cast<godot::Viewport::DefaultCanvasItemTextureRepeat>(repeat));
            }

            Transform2D getCanvasTransform() {
                return viewport->get_canvas_transform();
            }

            void setCanvasTransform(const Transform2D& transform) {
                viewport->set_canvas_transform(transform);
            }

            int getDebugDraw() {
                return viewport->get_debug_draw();
            }

            void setDebugDraw(int mode) {
                viewport->set_debug_draw(static_cast<godot::Viewport::DebugDraw>(mode));
            }

            bool getDisable3D() {
                return viewport->is_3d_disabled();
            }

            void setDisable3D(bool disable) {
                viewport->set_disable_3d(disable);
            }

            float getFSRSharpness() {
                return viewport->get_fsr_sharpness();
            }

            void setFSRSharpness(float sharpness) {
                viewport->set_fsr_sharpness(sharpness);
            }

            Transform2D getGlobalCanvasTransform() {
                return viewport->get_global_canvas_transform();
            }

            void setGlobalCanvasTransform(const Transform2D& transform) {
                viewport->set_global_canvas_transform(transform);
            }

            bool getGuiDisableInput() {
                return viewport->is_input_disabled();
            }

            void setGuiDisableInput(bool disable) {
                viewport->set_disable_input(disable);
            }

            bool getGuiEmbedSubwindows() {
                return viewport->is_embedding_subwindows();
            }

            void setGuiEmbedSubwindows(bool enable) {
                viewport->set_embedding_subwindows(enable);
            }

            bool getGuiSnapControlsToPixels() {
                return viewport->is_snap_controls_to_pixels_enabled();
            }

            void setGuiSnapControlsToPixels(bool enable) {
                viewport->set_snap_controls_to_pixels(enable);
            }

            bool getHandleInputLocally() {
                return viewport->is_handling_input_locally();
            }

            void setHandleInputLocally(bool enable) {
                viewport->set_handle_input_locally(enable);
            }

            float getMeshLodThreshold() {
                return viewport->get_mesh_lod_threshold();
            }

            void setMeshLodThreshold(float threshold) {
                viewport->set_mesh_lod_threshold(threshold);
            }

            int getMsaa2D() {
                return viewport->get_msaa_2d();
            }

            void setMsaa2D(int level) {
                viewport->set_msaa_2d(static_cast<godot::Viewport::MSAA>(level));
            }

            int getMsaa3D() {
                return viewport->get_msaa_3d();
            }

            void setMsaa3D(int level) {
                viewport->set_msaa_3d(static_cast<godot::Viewport::MSAA>(level));
            }

            bool getOwnWorld3D() {
                return viewport->is_using_own_world_3d();
            }
    };
}

#endif // VIEWPORT_H