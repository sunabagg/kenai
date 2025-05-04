#ifndef WINDOW_H
#define WINDOW_H

#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define WindowNode godot::Window

#include "../core/viewport.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::desktop {
    void bindWindow(sol::state &lua);

    class Window;

    class WindowProxy : public WindowNode {
        public:
            sunaba::desktop::Window* element = nullptr;

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

            Vector2 _get_contents_minimum_size() const override;
    };

    class Window : public sunaba::core::Viewport {
        private:
            WindowNode* window = nullptr; // Pointer to the Window instance
            void connectWindowSignals() {
                // Connect signals specific to Window
            }

        public:
            Window() {
                setWindow(memnew(WindowProxy));
                onInit();
            }

            Window(WindowNode* window) {
                setWindow(window);
                onInit();
            }

            WindowNode* getWindow() {
                return window;
            }

            void setWindow(WindowNode* window) {
                this->window = window;
                connectWindowSignals();
                setViewport(window);
            }

            void setWindow(WindowProxy* window) {
                this->window = window;
                window->element = this;
                connectWindowSignals();
                setViewport(window);
            }

            bool getAlwaysOnTop() const {
                return window->get_flag(godot::Window::Flags::FLAG_ALWAYS_ON_TOP);
            }

            void setAlwaysOnTop(bool always_on_top) {
                window->set_flag(godot::Window::Flags::FLAG_ALWAYS_ON_TOP, always_on_top);
            }
    };
}

#endif // WINDOW_H