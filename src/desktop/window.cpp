#include "window.h"

namespace sunaba::desktop {
    void WindowProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void WindowProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void WindowProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void WindowProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void WindowProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void WindowProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void WindowProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void WindowProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void WindowProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void bindWindow(sol::state_view& lua) {
        lua.new_usertype<Window>("Window",
            sol::constructors<Window()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::Viewport>(),
            "alwaysOnTop", sol::property(
                &Window::getAlwaysOnTop,
                &Window::setAlwaysOnTop
            ),
            "autoTranslate", sol::property(
                &Window::getAutoTranslate,
                &Window::setAutoTranslate
            ),
            "borderless", sol::property(
                &Window::getBorderless,
                &Window::setBorderless
            ),
            "contentScaleAspect", sol::property(
                &Window::getContentScaleAspect,
                &Window::setContentScaleAspect
            ),
            "contentScaleFactor", sol::property(
                &Window::getContentScaleFactor,
                &Window::setContentScaleFactor
            ),
            "contentScaleMode", sol::property(
                &Window::getContentScaleMode,
                &Window::setContentScaleMode
            ),
            "contentScaleSize", sol::property(
                &Window::getContentScaleSize,
                &Window::setContentScaleSize
            ),
            "contentScaleStretch", sol::property(
                &Window::getContentScaleStretch,
                &Window::setContentScaleStretch
            ),
            "currentScreen", sol::property(
                &Window::getCurrentScreen,
                &Window::setCurrentScreen
            ),
            "excludeFromCapture", sol::property(
                &Window::getExcludeFromCapture,
                &Window::setExcludeFromCapture
            ),
            "exclusive", sol::property(
                &Window::getExclusive,
                &Window::setExclusive
            ),
            "extendToTitle", sol::property(
                &Window::getExtendToTitle,
                &Window::setExtendToTitle
            ),
            "forceNative", sol::property(
                &Window::getForceNative,
                &Window::setForceNative
            ),
            "initialPosition", sol::property(
                &Window::getInitialPosition,
                &Window::setInitialPosition
            ),
            "keepTitleVisible", sol::property(
                &Window::getKeepTitleVisible,
                &Window::setKeepTitleVisible
            ),
            "maxSize", sol::property(
                &Window::getMaxSize,
                &Window::setMaxSize
            ),
            "minSize", sol::property(
                &Window::getMinSize,
                &Window::setMinSize
            ),
            "mode", sol::property(
                &Window::getMode,
                &Window::setMode
            ),
            "mousePassthrough", sol::property(
                &Window::getMousePassthrough,
                &Window::setMousePassthrough
            ),
            "mousePassthroughPolygon", sol::property(
                &Window::getMousePassthroughPolygon,
                &Window::setMousePassthroughPolygon
            ),
        );
    }
}