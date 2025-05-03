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
    };
}

#endif // VIEWPORT_H