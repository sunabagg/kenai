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

            bool  getAutoTranslate() {
                return window->is_auto_translating();
            }

            void setAutoTranslate(bool auto_translate) {
                window->set_auto_translate(auto_translate);
            }

            bool getBorderless() {
                return window->get_flag(godot::Window::Flags::FLAG_BORDERLESS);
            }

            void setBorderless(bool borderless) {
                window->set_flag(godot::Window::Flags::FLAG_BORDERLESS, borderless);
            }

            int getContentScaleAspect() {
                return window->get_content_scale_aspect();
            }

            void setContentScaleAspect(int aspect) {
                window->set_content_scale_aspect(static_cast<godot::Window::ContentScaleAspect>(aspect));
            }

            float getContentScaleFactor() {
                return window->get_content_scale_factor();
            }

            void setContentScaleFactor(float scale) {
                window->set_content_scale_factor(scale);
            }

            int getContentScaleMode() {
                return window->get_content_scale_mode();
            }

            void setContentScaleMode(int mode) {
                window->set_content_scale_mode(static_cast<godot::Window::ContentScaleMode>(mode));
            }

            Vector2i getContentScaleSize() {
                return window->get_content_scale_size();
            }

            void setContentScaleSize(Vector2i size) {
                window->set_content_scale_size(size);
            }

            int getContentScaleStretch() {
                return window->get_content_scale_stretch();
            }

            int getCurrentScreen() {
                return window->get_current_screen();
            }

            void setCurrentScreen(int screen) {
                window->set_current_screen(screen);
            }

            bool getExcludeFromCapture() {
                return window->get_flag(godot::Window::Flags::FLAG_EXCLUDE_FROM_CAPTURE);
            }

            void setExcludeFromCapture(bool exclude) {
                window->set_flag(godot::Window::Flags::FLAG_EXCLUDE_FROM_CAPTURE, exclude);
            }

            bool getExclusive() {
                return window->is_exclusive();
            }

            void setExclusive(bool exclusive) {
                window->set_exclusive(exclusive);
            }

            bool getExtendToTitle() {
                return window->get_flag(godot::Window::Flags::FLAG_EXTEND_TO_TITLE);
            }

            void setExtendToTitle(bool extend) {
                window->set_flag(godot::Window::Flags::FLAG_EXTEND_TO_TITLE, extend);
            }

            bool getForceNative() {
                return window->get_force_native();
            }
            
            void setForceNative(bool force) {
                window->set_force_native(force);
            }

            int getInitialPosition() {
                return window->get_initial_position();
            }

            bool getKeepTitleVisible() {
                return window->get_keep_title_visible();
            }

            void setKeepTitleVisible(bool keep) {
                window->set_keep_title_visible(keep);
            }

            Vector2i getMaxSize() {
                return window->get_max_size();
            }

            void setMaxSize(Vector2i size) {
                window->set_max_size(size);
            }

            Vector2i getMinSize() {
                return window->get_min_size();
            }

            void setMinSize(Vector2i size) {
                window->set_min_size(size);
            }
    };
}

#endif // WINDOW_H