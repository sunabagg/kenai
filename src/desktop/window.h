#ifndef WINDOW_H
#define WINDOW_H

#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define WindowNode godot::Window

#include "../core/viewport.h"
#include "../ui/theme.h"
#include "../core/font.h"

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
                std::function<Variant(std::vector<Variant>)> aboutToPopupFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->aboutToPopupEvent != nullptr) {
                        this->aboutToPopupEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable aboutToPopupCallable = StlFunctionWrapper::create_callable_from_cpp_function(aboutToPopupFunc);
                this->window->connect("about_to_popup", aboutToPopupCallable);
                std::function<Variant(std::vector<Variant>)> closeRequestedFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->closeRequestedEvent != nullptr) {
                        this->closeRequestedEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable closeRequestedCallable = StlFunctionWrapper::create_callable_from_cpp_function(closeRequestedFunc);
                this->window->connect("close_requested", closeRequestedCallable);
                std::function<Variant(std::vector<Variant>)> dpiChangedFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->dpiChangedEvent != nullptr) {
                        this->dpiChangedEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable dpiChangedCallable = StlFunctionWrapper::create_callable_from_cpp_function(dpiChangedFunc);
                this->window->connect("dpi_changed", dpiChangedCallable);
                std::function<Variant(std::vector<Variant>)> filesDroppedFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->filesDroppedEvent != nullptr) {
                        this->filesDroppedEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable filesDroppedCallable = StlFunctionWrapper::create_callable_from_cpp_function(filesDroppedFunc);
                this->window->connect("files_dropped", filesDroppedCallable);
                std::function<Variant(std::vector<Variant>)> focusEnteredFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->focusEnteredEvent != nullptr) {
                        this->focusEnteredEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable focusEnteredCallable = StlFunctionWrapper::create_callable_from_cpp_function(focusEnteredFunc);
                this->window->connect("focus_entered", focusEnteredCallable);
                std::function<Variant(std::vector<Variant>)> focusExitedFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->focusExitedEvent != nullptr) {
                        this->focusExitedEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable focusExitedCallable = StlFunctionWrapper::create_callable_from_cpp_function(focusExitedFunc);
                this->window->connect("focus_exited", focusExitedCallable);
                std::function<Variant(std::vector<Variant>)> goBackRequestedFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->goBackRequestedEvent != nullptr) {
                        this->goBackRequestedEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable goBackRequestedCallable = StlFunctionWrapper::create_callable_from_cpp_function(goBackRequestedFunc);
                this->window->connect("go_back_requested", goBackRequestedCallable);
                std::function<Variant(std::vector<Variant>)> mouseEnteredFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->mouseEnteredEvent != nullptr) {
                        this->mouseEnteredEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable mouseEnteredCallable = StlFunctionWrapper::create_callable_from_cpp_function(mouseEnteredFunc);
                this->window->connect("mouse_entered", mouseEnteredCallable);
                std::function<Variant(std::vector<Variant>)> mouseExitedFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->mouseExitedEvent != nullptr) {
                        this->mouseExitedEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable mouseExitedCallable = StlFunctionWrapper::create_callable_from_cpp_function(mouseExitedFunc);
                this->window->connect("mouse_exited", mouseExitedCallable);
                std::function<Variant(std::vector<Variant>)> themeChangedFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->themeChangedEvent != nullptr) {
                        this->themeChangedEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable themeChangedCallable = StlFunctionWrapper::create_callable_from_cpp_function(themeChangedFunc);
                this->window->connect("theme_changed", themeChangedCallable);
                std::function<Variant(std::vector<Variant>)> titleChangedFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->titleChangedEvent != nullptr) {
                        this->titleChangedEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable titleChangedCallable = StlFunctionWrapper::create_callable_from_cpp_function(titleChangedFunc);
                this->window->connect("title_changed", titleChangedCallable);
                std::function<Variant(std::vector<Variant>)> titlebarChangedFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->titlebarChangedEvent != nullptr) {
                        this->titlebarChangedEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable titlebarChangedCallable = StlFunctionWrapper::create_callable_from_cpp_function(titlebarChangedFunc);
                this->window->connect("titlebar_changed", titlebarChangedCallable);
                std::function<Variant(std::vector<Variant>)> visibilityChangedFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->visibilityChangedEvent != nullptr) {
                        this->visibilityChangedEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable visibilityChangedCallable = StlFunctionWrapper::create_callable_from_cpp_function(visibilityChangedFunc);
                this->window->connect("visibility_changed", visibilityChangedCallable);
                std::function<Variant(std::vector<Variant>)> windowInputFunc =
                [this](std::vector<Variant> args) {
                    Array argsArray;
                    if (this->windowInputEvent != nullptr) {
                        this->windowInputEvent->emit(argsArray);
                    }
                    return Variant();
                };
                Callable windowInputCallable = StlFunctionWrapper::create_callable_from_cpp_function(windowInputFunc);
                this->window->connect("window_input", windowInputCallable);
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

            int getMode() {
                return window->get_mode();
            }

            void setMode(int mode) {
                window->set_mode(static_cast<godot::Window::Mode>(mode));
            }

            bool getMousePassthrough() {
                return window->get_flag(godot::Window::Flags::FLAG_MOUSE_PASSTHROUGH);
            }

            void setMousePassthrough(bool passthrough) {
                window->set_flag(godot::Window::Flags::FLAG_MOUSE_PASSTHROUGH, passthrough);
            }

            std::vector<Vector2> getMousePassthroughPolygon() {
                PackedVector2Array polygon = window->get_mouse_passthrough_polygon();
                std::vector<Vector2> result;
                for (int i = 0; i < polygon.size(); i++) {
                    result.push_back(polygon[i]);
                }
                return result;
            }
            
            void setMousePassthroughPolygon(std::vector<Vector2> polygon) {
                PackedVector2Array passtrough_polygon;
                for (size_t i = 0; i < polygon.size(); i++) {
                    passtrough_polygon.push_back(polygon[i]);
                }
                window->set_mouse_passthrough_polygon(passtrough_polygon);
            }

            void getPopupWindow() {
                window->get_flag(godot::Window::Flags::FLAG_POPUP);
            }

            void setPopupWindow(bool popup) {
                window->set_flag(godot::Window::Flags::FLAG_POPUP, popup);
            }

            Vector2i getPosition() {
                return window->get_position();
            }

            void setPosition(Vector2i position) {
                window->set_position(position);
            }

            bool getSharpCorners() {
                return window->get_flag(godot::Window::Flags::FLAG_SHARP_CORNERS);
            }

            void setSharpCorners(bool sharp) {
                window->set_flag(godot::Window::Flags::FLAG_SHARP_CORNERS, sharp);
            }

            Vector2i getSize() {
                return window->get_size();
            }

            void setSize(Vector2i size) {
                window->set_size(size);
            }

            sunaba::ui::Theme* getTheme() {
                return new sunaba::ui::Theme(window->get_theme().ptr());
            }

            void setTheme(sunaba::ui::Theme* theme) {
                window->set_theme(Ref<godot::Theme>(theme->getTheme()));
            }

            std::string getThemeTypeVariation() {
                return String(window->get_theme_type_variation()).utf8().get_data();
            }

            void setThemeTypeVariation(std::string variation) {
                window->set_theme_type_variation(String(variation.c_str()));
            }

            std::string getTitle() {
                return String(window->get_title()).utf8().get_data();
            }

            void setTitle(std::string title) {
                window->set_title(String(title.c_str()));
            }

            bool getTransient() {
                return window->is_transient();
            }

            void setTransient(bool transient) {
                window->set_transient(transient);
            }

            bool getTransientToFocused() {
                return window->is_transient_to_focused();
            }

            void setTransientToFocused(bool transient) {
                window->set_transient_to_focused(transient);
            }

            bool getTransparent() {
                return window->get_flag(godot::Window::Flags::FLAG_TRANSPARENT);
            }

            void setTransparent(bool transparent) {
                window->set_flag(godot::Window::Flags::FLAG_TRANSPARENT, transparent);
            }

            bool getUnfocusable() {
                return window->get_flag(godot::Window::Flags::FLAG_NO_FOCUS);
            }

            void setUnfocusable(bool unfocusable) {
                window->set_flag(godot::Window::Flags::FLAG_NO_FOCUS, unfocusable);
            }

            bool getUnresizable() {
                return window->get_flag(godot::Window::Flags::FLAG_RESIZE_DISABLED);
            }

            void setUnresizable(bool unresizable) {
                window->set_flag(godot::Window::Flags::FLAG_RESIZE_DISABLED, unresizable);
            }

            bool getVisible() {
                return window->is_visible();
            }

            void setVisible(bool visible) {
                window->set_visible(visible);
            }

            bool getWrapControls() {
                return window->is_wrapping_controls();
            }

            void setWrapControls(bool wrap) {
                window->set_wrap_controls(wrap);
            }

            Event* aboutToPopupEvent;
            Event* getAboutToPopupEvent() {
                return aboutToPopupEvent;
            }
            void setAboutToPopupEvent(Event* event) {
                aboutToPopupEvent = event;
            }
            Event* closeRequestedEvent;
            Event* getCloseRequestedEvent() {
                return closeRequestedEvent;
            }
            void setCloseRequestedEvent(Event* event) {
                closeRequestedEvent = event;
            }
            Event* dpiChangedEvent;
            Event* getDpiChangedEvent() {
                return dpiChangedEvent;
            }
            void setDpiChangedEvent(Event* event) {
                dpiChangedEvent = event;
            }
            Event* filesDroppedEvent;
            Event* getFilesDroppedEvent() {
                return filesDroppedEvent;
            }
            void setFilesDroppedEvent(Event* event) {
                filesDroppedEvent = event;
            }
            Event* focusEnteredEvent;
            Event* getFocusEnteredEvent() {
                return focusEnteredEvent;
            }
            void setFocusEnteredEvent(Event* event) {
                focusEnteredEvent = event;
            }
            Event* focusExitedEvent;
            Event* getFocusExitedEvent() {
                return focusExitedEvent;
            }
            void setFocusExitedEvent(Event* event) {
                focusExitedEvent = event;
            }
            Event* goBackRequestedEvent;
            Event* getGoBackRequestedEvent() {
                return goBackRequestedEvent;
            }
            void setGoBackRequestedEvent(Event* event) {
                goBackRequestedEvent = event;
            }
            Event* mouseEnteredEvent;
            Event* getMouseEnteredEvent() {
                return mouseEnteredEvent;
            }
            void setMouseEnteredEvent(Event* event) {
                mouseEnteredEvent = event;
            }
            Event* mouseExitedEvent;
            Event* getMouseExitedEvent() {
                return mouseExitedEvent;
            }
            void setMouseExitedEvent(Event* event) {
                mouseExitedEvent = event;
            }
            Event* themeChangedEvent;
            Event* getThemeChangedEvent() {
                return themeChangedEvent;
            }
            void setThemeChangedEvent(Event* event) {
                themeChangedEvent = event;
            }
            Event* titleChangedEvent;
            Event* getTitleChangedEvent() {
                return titleChangedEvent;
            }
            void setTitleChangedEvent(Event* event) {
                titleChangedEvent = event;
            }
            Event* titlebarChangedEvent;
            Event* getTitlebarChangedEvent() {
                return titlebarChangedEvent;
            }
            void setTitlebarChangedEvent(Event* event) {
                titlebarChangedEvent = event;
            }
            Event* visibilityChangedEvent;
            Event* getVisibilityChangedEvent() {
                return visibilityChangedEvent;
            }
            void setVisibilityChangedEvent(Event* event) {
                visibilityChangedEvent = event;
            }
            Event* windowInputEvent;
            Event* getWindowInputEvent() {
                return windowInputEvent;
            }
            void setWindowInputEvent(Event* event) {
                windowInputEvent = event;
            }


            Vector2 getContentsMinimumSize() {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["getContentsMinimumSize"].get<sol::function>();
                    if (func) {
                        return window->get_contents_minimum_size();
                    }
                }
                return Vector2(0, 0);
            }

            void addThemeColorOverride(std::string name, Color Color) {
                window->add_theme_color_override(name.c_str(), Color);
            }

            void addThemeConstantOverride(std::string name, int constant) {
                window->add_theme_constant_override(name.c_str(), constant);
            }

            void addThemeFontOverride(std::string name, sunaba::core::Font* font) {
                window->add_theme_font_override(name.c_str(), font->getFont());
            }

            void addThemeFontSizeOverride(std::string name, int size) {
                window->add_theme_font_size_override(name.c_str(), size);
            }
    };
}

#endif // WINDOW_H