#ifndef WINDOW_H
#define WINDOW_H

#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define WindowNode godot::Window

#include "../core/viewport.h"
#include "../ui/theme.h"
#include "../core/font.h"
#include "../core/texture2d.h"
#include "../ui/style_box.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::desktop {
    void bindWindow(sol::state &lua);

    class Window;

    class WindowProxy : public WindowNode {
        GDCLASS(WindowProxy, WindowNode)
        protected:
            static void _bind_methods() {}
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

    class WindowSignalWrapper : public Object {
        GDCLASS(WindowSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            sunaba::desktop::Window* element = nullptr;

            WindowSignalWrapper() = default;
            ~WindowSignalWrapper() = default;

            void about_to_popup();
            void close_requested();
            void dpi_changed();
            void files_dropped(const PackedStringArray& files);
            void focus_entered();
            void focus_exited();
            void go_back_requested();
            void mouse_entered();
            void mouse_exited();
            void theme_changed();
            void title_changed();
    };

    class Window : public sunaba::core::Viewport {
        private:
            WindowNode* window = nullptr; // Pointer to the Window instance
            WindowSignalWrapper* windowSignalWrapper = nullptr;
            void connectWindowSignals() {
                if (this->windowSignalWrapper == nullptr) {
                    this->windowSignalWrapper = memnew(WindowSignalWrapper);
                    this->windowSignalWrapper->element = this;
                }

                this->window->connect("about_to_popup", Callable(this->windowSignalWrapper, "about_to_popup"));
                this->window->connect("close_requested", Callable(this->windowSignalWrapper, "close_requested"));
                this->window->connect("dpi_changed", Callable(this->windowSignalWrapper, "dpi_changed"));
                this->window->connect("files_dropped", Callable(this->windowSignalWrapper, "files_dropped"));
                this->window->connect("focus_entered", Callable(this->windowSignalWrapper, "focus_entered"));
                this->window->connect("focus_exited", Callable(this->windowSignalWrapper, "focus_exited"));
                this->window->connect("go_back_requested", Callable(this->windowSignalWrapper, "go_back_requested"));
                this->window->connect("mouse_entered", Callable(this->windowSignalWrapper, "mouse_entered"));
                this->window->connect("mouse_exited", Callable(this->windowSignalWrapper, "mouse_exited"));
                this->window->connect("theme_changed", Callable(this->windowSignalWrapper, "theme_changed"));
                this->window->connect("title_changed", Callable(this->windowSignalWrapper, "title_changed"));
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

            void setContentScaleStretch(int stretch) {
                window->set_content_scale_stretch(static_cast<godot::Window::ContentScaleStretch>(stretch));
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

            void setInitialPosition(int position) {
                window->set_initial_position(static_cast<godot::Window::WindowInitialPosition>(position));
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

            bool getPopupWindow() {
                return window->get_flag(godot::Window::Flags::FLAG_POPUP);
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

            Event* aboutToPopupEvent = new Event();
            Event* getAboutToPopupEvent() {
                return aboutToPopupEvent;
            }
            void setAboutToPopupEvent(Event* event) {
                aboutToPopupEvent = event;
            }
            Event* closeRequestedEvent = new Event();
            Event* getCloseRequestedEvent() {
                return closeRequestedEvent;
            }
            void setCloseRequestedEvent(Event* event) {
                closeRequestedEvent = event;
            }
            Event* dpiChangedEvent = new Event();
            Event* getDpiChangedEvent() {
                return dpiChangedEvent;
            }
            void setDpiChangedEvent(Event* event) {
                dpiChangedEvent = event;
            }
            Event* filesDroppedEvent = new Event();
            Event* getFilesDroppedEvent() {
                return filesDroppedEvent;
            }
            void setFilesDroppedEvent(Event* event) {
                filesDroppedEvent = event;
            }
            Event* focusEnteredEvent = new Event();
            Event* getFocusEnteredEvent() {
                return focusEnteredEvent;
            }
            void setFocusEnteredEvent(Event* event) {
                focusEnteredEvent = event;
            }
            Event* focusExitedEvent = new Event();
            Event* getFocusExitedEvent() {
                return focusExitedEvent;
            }
            void setFocusExitedEvent(Event* event) {
                focusExitedEvent = event;
            }
            Event* goBackRequestedEvent = new Event();
            Event* getGoBackRequestedEvent() {
                return goBackRequestedEvent;
            }
            void setGoBackRequestedEvent(Event* event) {
                goBackRequestedEvent = event;
            }
            Event* mouseEnteredEvent = new Event();
            Event* getMouseEnteredEvent() {
                return mouseEnteredEvent;
            }
            void setMouseEnteredEvent(Event* event) {
                mouseEnteredEvent = event;
            }
            Event* mouseExitedEvent = new Event();
            Event* getMouseExitedEvent() {
                return mouseExitedEvent;
            }
            void setMouseExitedEvent(Event* event) {
                mouseExitedEvent = event;
            }
            Event* themeChangedEvent = new Event();
            Event* getThemeChangedEvent() {
                return themeChangedEvent;
            }
            void setThemeChangedEvent(Event* event) {
                themeChangedEvent = event;
            }
            Event* titleChangedEvent = new Event();
            Event* getTitleChangedEvent() {
                return titleChangedEvent;
            }
            void setTitleChangedEvent(Event* event) {
                titleChangedEvent = event;
            }
            Event* titlebarChangedEvent = new Event();
            Event* getTitlebarChangedEvent() {
                return titlebarChangedEvent;
            }
            void setTitlebarChangedEvent(Event* event) {
                titlebarChangedEvent = event;
            }
            Event* visibilityChangedEvent = new Event();
            Event* getVisibilityChangedEvent() {
                return visibilityChangedEvent;
            }
            void setVisibilityChangedEvent(Event* event) {
                visibilityChangedEvent = event;
            }
            Event* windowInputEvent = new Event();
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
                return window->get_contents_minimum_size();
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

            void addThemeIconOverride(std::string name, sunaba::core::Texture2D* icon) {
                window->add_theme_icon_override(name.c_str(), Ref<godot::Texture2D>(icon->getTexture()));
            }

            void addThemeStyleBoxOverride(std::string name, sunaba::ui::StyleBox* stylebox) {
                window->add_theme_stylebox_override(name.c_str(), Ref<godot::StyleBox>(stylebox->getStyleBox()));
            }

            void beginBulkThemeOverride() {
                window->begin_bulk_theme_override();
            }

            bool canDraw() {
                return window->can_draw();
            }

            void childControlsChanged() {
                window->child_controls_changed();
            }

            void endBulkThemeOverride() {
                window->end_bulk_theme_override();
            }

            bool getFlag(int flag) {
                return window->get_flag(static_cast<godot::Window::Flags>(flag));
            }

            int getLayoutDirection() {
                return window->get_layout_direction();
            }

            Vector2i getPositionWithDecorations() {
                return window->get_position_with_decorations();
            }

            Vector2i getSizeWithDecorations() {
                return window->get_size_with_decorations();
            }

            Color getThemeColor(std::string name, std::string type = "&") {
                return window->get_theme_color(name.c_str(), type.c_str());
            }

            int getThemeConstant(std::string name, std::string type = "&") {
                return window->get_theme_constant(name.c_str(), type.c_str());
            }

            float getThemeDefaultBaseScale() {
                return window->get_theme_default_base_scale();
            }

            sunaba::core::Font* getThemeDefaultFont() {
                return new sunaba::core::Font(window->get_theme_default_font().ptr());
            }

            int getThemeDefaultFontSize() {
                return window->get_theme_default_font_size();
            }

            sunaba::core::Font* getThemeFont(std::string name, std::string type = "&") {
                return new sunaba::core::Font(window->get_theme_font(name.c_str(), type.c_str()).ptr());
            }

            int getThemeFontSize(std::string name, std::string type = "&") {
                return window->get_theme_font_size(name.c_str(), type.c_str());
            }

            sunaba::core::Texture2D* getThemeIcon(std::string name, std::string type = "&") {
                return new sunaba::core::Texture2D(window->get_theme_icon(name.c_str(), type.c_str()).ptr());
            }

            sunaba::ui::StyleBox* getThemeStyleBox(std::string name, std::string type = "&") {
                return new sunaba::ui::StyleBox(window->get_theme_stylebox(name.c_str(), type.c_str()).ptr());
            }

            int getWindowId() {
                return window->get_window_id();
            }

            void grabFocus() {
                window->grab_focus();
            }

            bool hasFocus() {
                return window->has_focus();
            }

            bool hasThemeColor(std::string name, std::string type = "&") {
                return window->has_theme_color(name.c_str(), type.c_str());
            }

            bool hasThemeColorOverride(std::string name) {
                return window->has_theme_color_override(name.c_str());
            }

            bool hasThemeConstant(std::string name, std::string type = "&") {
                return window->has_theme_constant(name.c_str(), type.c_str());
            }

            bool hasThemeConstantOverride(std::string name) {
                return window->has_theme_constant_override(name.c_str());
            }

            bool hasThemeFont(std::string name, std::string type = "&") {
                return window->has_theme_font(name.c_str(), type.c_str());
            }

            bool hasThemeFontOverride(std::string name) {
                return window->has_theme_font_override(name.c_str());
            }

            bool hasThemeFontSize(std::string name, std::string type = "&") {
                return window->has_theme_font_size(name.c_str(), type.c_str());
            }

            bool hasThemeFontSizeOverride(std::string name) {
                return window->has_theme_font_size_override(name.c_str());
            }

            bool hasThemeIcon(std::string name, std::string type = "&") {
                return window->has_theme_icon(name.c_str(), type.c_str());
            }

            bool hasThemeIconOverride(std::string name) {
                return window->has_theme_icon_override(name.c_str());
            }

            bool hasThemeStyleBox(std::string name, std::string type = "&") {
                return window->has_theme_stylebox(name.c_str(), type.c_str());
            }

            bool hasThemeStyleBoxOverride(std::string name) {
                return window->has_theme_stylebox_override(name.c_str());
            }

            void hide() {
                window->hide();
            }

            bool isEmbedded() {
                return window->is_embedded();
            }

            bool isLayoutRtl() {
                return window->is_layout_rtl();
            }

            bool isMaximizeAllowed() {
                return window->is_maximize_allowed();
            }

            bool isUsingFontOversampling() {
                return window->is_using_font_oversampling();
            }

            void moveToCenter() {
                window->move_to_center();
            }

            void moveToForeground() {
                window->move_to_foreground();
            }

            void popup(Rect2i rect = Rect2i(0, 0, 0, 0)) {
                window->popup(rect);
            }

            void popupCentered(Vector2i minsize = Vector2i(0, 0)) {
                window->popup_centered(minsize);
            }

            void popupCenteredClamped(Vector2i minsize = Vector2i(0, 0), float fallbackRatio = 0.75f) {
                window->popup_centered_clamped(minsize, fallbackRatio);
            }

            void popupCenteredRatio(float ratio = 0.8f) {
                window->popup_centered_ratio(ratio);
            }

            void popupExclusive(Element* fromElement, Rect2i rect = Rect2i(0, 0, 0, 0)) {
                window->popup_exclusive(fromElement->getNode(), rect);
            }

            void popupExclusiveCentered(Element* fromElement, Vector2i minsize = Vector2i(0, 0)) {
                window->popup_exclusive_centered(fromElement->getNode(), minsize);
            }

            void popupExclusiveCenteredClamped(Element* fromElement, Vector2i minsize = Vector2i(0, 0), float fallbackRatio = 0.75f) {
                window->popup_exclusive_centered_clamped(fromElement->getNode(), minsize, fallbackRatio);
            }

            void popupExclusiveCenteredRatio(Element* fromElement, float ratio = 0.8f) {
                window->popup_exclusive_centered_ratio(fromElement->getNode(), ratio);
            }

            void popupExclusiveOnParent(Element* fromElement, Rect2i parentRect) {
                window->popup_exclusive_on_parent(fromElement->getNode(), parentRect);
            }

            void popupOnParent(Rect2i parentRect) {
                window->popup_on_parent(parentRect);
            }

            void removeThemeColorOverride(std::string name) {
                window->remove_theme_color_override(name.c_str());
            }

            void removeThemeConstantOverride(std::string name) {
                window->remove_theme_constant_override(name.c_str());
            }

            void removeThemeFontOverride(std::string name) {
                window->remove_theme_font_override(name.c_str());
            }

            void removeThemeFontSizeOverride(std::string name) {
                window->remove_theme_font_size_override(name.c_str());
            }

            void removeThemeIconOverride(std::string name) {
                window->remove_theme_icon_override(name.c_str());
            }

            void removeThemeStyleBoxOverride(std::string name) {
                window->remove_theme_stylebox_override(name.c_str());
            }

            void requestAttention() {
                window->request_attention();
            }

            void resetSize() {
                window->reset_size();
            }

            void setImeActive(bool active) {
                window->set_ime_active(active);
            }

            void setFlag(int flag, bool value) {
                window->set_flag(static_cast<godot::Window::Flags>(flag), value);
            }

            void setImePosition(Vector2i position) {
                window->set_ime_position(position);
            }

            void setLayoutDirection(int direction) {
                window->set_layout_direction(static_cast<godot::Window::LayoutDirection>(direction));
            }

            void setUnparentWhenInvisible(bool unparent) {
                window->set_unparent_when_invisible(unparent);
            }

            void setUseFontOversampling(bool use) {
                window->set_use_font_oversampling(use);
            }

            void show() {
                window->show();
            }

            void startDrag() {
                window->start_drag();
            }

            void startResize(int edge) {
                window->start_resize(static_cast<godot::DisplayServer::WindowResizeEdge>(edge));
            }

            void onFree() override {
                if (windowSignalWrapper) {
                    memdelete(windowSignalWrapper);
                    windowSignalWrapper = nullptr;
                }
                Viewport::onFree();
            }
    };
}

#endif // WINDOW_H
