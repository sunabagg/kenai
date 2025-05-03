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
    };
}

#endif // VIEWPORT_H