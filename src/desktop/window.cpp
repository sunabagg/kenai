#include "window.h"

namespace lucidfx::desktop {
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

    Vector2 WindowProxy::_get_contents_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->getContentsMinimumSize();
        }
        return WindowNode::_get_contents_minimum_size();
    }

    void WindowSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("about_to_popup"), &WindowSignalWrapper::about_to_popup);
        ClassDB::bind_method(D_METHOD("close_requested"), &WindowSignalWrapper::close_requested);
        ClassDB::bind_method(D_METHOD("dpi_changed"), &WindowSignalWrapper::dpi_changed);
        ClassDB::bind_method(D_METHOD("files_dropped"), &WindowSignalWrapper::files_dropped);
        ClassDB::bind_method(D_METHOD("focus_entered"), &WindowSignalWrapper::focus_entered);
        ClassDB::bind_method(D_METHOD("focus_exited"), &WindowSignalWrapper::focus_exited);
        ClassDB::bind_method(D_METHOD("go_back_requested"), &WindowSignalWrapper::go_back_requested);
        ClassDB::bind_method(D_METHOD("mouse_entered"), &WindowSignalWrapper::mouse_entered);
        ClassDB::bind_method(D_METHOD("mouse_exited"), &WindowSignalWrapper::mouse_exited);
        ClassDB::bind_method(D_METHOD("theme_changed"), &WindowSignalWrapper::theme_changed);
        ClassDB::bind_method(D_METHOD("title_changed"), &WindowSignalWrapper::title_changed);
    }

    void WindowSignalWrapper::about_to_popup() {
        if (element != nullptr) {
            Array args;
            element->aboutToPopupEvent->emit(args);
        }
    }

    void WindowSignalWrapper::close_requested() {
        if (element != nullptr) {
            Array args;
            element->closeRequestedEvent->emit(args);
        }
    }

    void WindowSignalWrapper::dpi_changed() {
        if (element != nullptr) {
            Array args;
            element->dpiChangedEvent->emit(args);
        }
    }

    void WindowSignalWrapper::files_dropped(const PackedStringArray& files) {
        if (element != nullptr) {
            Array args;
            args.append(files);
            element->filesDroppedEvent->emit(args);
        }
    }

    void WindowSignalWrapper::focus_entered() {
        if (element != nullptr) {
            Array args;
            element->focusEnteredEvent->emit(args);
        }
    }

    void WindowSignalWrapper::focus_exited() {
        if (element != nullptr) {
            Array args;
            element->focusExitedEvent->emit(args);
        }
    }

    void WindowSignalWrapper::go_back_requested() {
        if (element != nullptr) {
            Array args;
            element->goBackRequestedEvent->emit(args);
        }
    }

    void WindowSignalWrapper::mouse_entered() {
        if (element != nullptr) {
            Array args;
            element->mouseEnteredEvent->emit(args);
        }
    }

    void WindowSignalWrapper::mouse_exited() {
        if (element != nullptr) {
            Array args;
            element->mouseExitedEvent->emit(args);
        }
    }

    void WindowSignalWrapper::theme_changed() {
        if (element != nullptr) {
            Array args;
            element->themeChangedEvent->emit(args);
        }
    }

    void WindowSignalWrapper::title_changed() {
        if (element != nullptr) {
            Array args;
            element->titleChangedEvent->emit(args);
        }
    }

    void bindWindow(sol::state& lua) {
        lua.new_usertype<Window>("Window",
            "new", sol::factories(
                []() { return new Window(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidfx::core::Viewport>(),
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
            "popupWindow", sol::property(
                &Window::getPopupWindow,
                &Window::setPopupWindow
            ),
            "position", sol::property(
                &Window::getPosition,
                &Window::setPosition
            ),
            "sharpCorners", sol::property(
                &Window::getSharpCorners,
                &Window::setSharpCorners
            ),
            "size", sol::property(
                &Window::getSize,
                &Window::setSize
            ),
            "theme", sol::property(
                &Window::getTheme,
                &Window::setTheme
            ),
            "themeTypeVariation", sol::property(
                &Window::getThemeTypeVariation,
                &Window::setThemeTypeVariation
            ),
            "title", sol::property(
                &Window::getTitle,
                &Window::setTitle
            ),
            "transient", sol::property(
                &Window::getTransient,
                &Window::setTransient
            ),
            "transientToFocused", sol::property(
                &Window::getTransientToFocused,
                &Window::setTransientToFocused
            ),
            "transparent", sol::property(
                &Window::getTransparent,
                &Window::setTransparent
            ),
            "unfocusable", sol::property(
                &Window::getUnfocusable,
                &Window::setUnfocusable
            ),
            "unresizable", sol::property(
                &Window::getUnresizable,
                &Window::setUnresizable
            ),
            "visible", sol::property(
                &Window::getVisible,
                &Window::setVisible
            ),
            "wrapControls", sol::property(
                &Window::getWrapControls,
                &Window::setWrapControls
            ),
            "aboutToPopup", sol::property(
                &Window::getAboutToPopupEvent,
                &Window::setAboutToPopupEvent
            ),
            "closeRequested", sol::property(
                &Window::getCloseRequestedEvent,
                &Window::setCloseRequestedEvent
            ),
            "dpiChanged", sol::property(
                &Window::getDpiChangedEvent,
                &Window::setDpiChangedEvent
            ),
            "filesDropped", sol::property(
                &Window::getFilesDroppedEvent,
                &Window::setFilesDroppedEvent
            ),
            "focusEntered", sol::property(
                &Window::getFocusEnteredEvent,
                &Window::setFocusEnteredEvent
            ),
            "focusExited", sol::property(
                &Window::getFocusExitedEvent,
                &Window::setFocusExitedEvent
            ),
            "goBackRequested", sol::property(
                &Window::getGoBackRequestedEvent,
                &Window::setGoBackRequestedEvent
            ),
            "mouseEntered", sol::property(
                &Window::getMouseEnteredEvent,
                &Window::setMouseEnteredEvent
            ),
            "mouseExited", sol::property(
                &Window::getMouseExitedEvent,
                &Window::setMouseExitedEvent
            ),
            "themeChanged", sol::property(
                &Window::getThemeChangedEvent,
                &Window::setThemeChangedEvent
            ),
            "titleChanged", sol::property(
                &Window::getTitleChangedEvent,
                &Window::setTitleChangedEvent
            ),
            "titlebarChanged", sol::property(
                &Window::getTitlebarChangedEvent,
                &Window::setTitlebarChangedEvent
            ),
            "visibilityChanged", sol::property(
                &Window::getVisibilityChangedEvent,
                &Window::setVisibilityChangedEvent
            ),
            "windowInput", sol::property(
                &Window::getWindowInputEvent,
                &Window::setWindowInputEvent
            ),
            "getContentsMinimumSize", &Window::getContentsMinimumSize,
            "addThemeColorOverride", &Window::addThemeColorOverride,
            "addThemeConstantOverride", &Window::addThemeConstantOverride,
            "addThemeFontOverride", &Window::addThemeFontOverride,
            "addTHemeFontSizeOverride", &Window::addThemeFontSizeOverride,
            "addThemeIconOverride", &Window::addThemeIconOverride,
            "addThemeStyleBoxOverride", &Window::addThemeStyleBoxOverride,
            "beginBulkThemeOverride", &Window::beginBulkThemeOverride,
            "canDraw", &Window::canDraw,
            "childControlsChanged", &Window::childControlsChanged,
            "endBulkThemeOverride", &Window::endBulkThemeOverride,
            "getFlag", &Window::getFlag,
            "getLayoutDirection", &Window::getLayoutDirection,
            "getPositionWithDecorations", &Window::getPositionWithDecorations,
            "getSizeWithDecorations", &Window::getSizeWithDecorations,
            "getThemeColor", &Window::getThemeColor,
            "getThemeConstant", &Window::getThemeConstant,
            "getThemeDefaultBaseScale", &Window::getThemeDefaultBaseScale, 
            "getThemeDefaultFont", &Window::getThemeDefaultFont,
            "getThemeDefaultFontSize", &Window::getThemeDefaultFontSize,
            "getThemeFont", &Window::getThemeFont,
            "getThemeFontSize", &Window::getThemeFontSize,
            "getThemeIcon", &Window::getThemeIcon,
            "getThemeStyleBox", &Window::getThemeStyleBox,
            "getWindowId", &Window::getWindowId,
            "grabFocus", &Window::grabFocus,
            "hasFocus", &Window::hasFocus,
            "hasThemeColor", &Window::hasThemeColor,
            "hasThemeColorOverride", &Window::hasThemeColorOverride,
            "hasThemeConstant", &Window::hasThemeConstant,
            "hasThemeConstantOverride", &Window::hasThemeConstantOverride,
            "hasThemeFont", &Window::hasThemeFont,
            "hasThemeFontOverride", &Window::hasThemeFontOverride,
            "hasThemeFontSize", &Window::hasThemeFontSize,
            "hasThemeFontSizeOverride", &Window::hasThemeFontSizeOverride,
            "hasThemeIcon", &Window::hasThemeIcon,
            "hasThemeIconOverride", &Window::hasThemeIconOverride,
            "hasThemeStyleBox", &Window::hasThemeStyleBox,
            "hasThemeStyleBoxOverride", &Window::hasThemeStyleBoxOverride,
            "hide", &Window::hide,
            "isEmbedded", &Window::isEmbedded,
            "isLayoutRtl", &Window::isLayoutRtl,
            "isMaximizeAllowed", &Window::isMaximizeAllowed,
            "isUsingFontOversampling", &Window::isUsingFontOversampling,
            "moveToCenter", &Window::moveToCenter,
            "moveToForeground", &Window::moveToForeground,
            "popup", &Window::popup,
            "popupCentered", &Window::popupCentered,
            "popupCenteredClamped", &Window::popupCenteredClamped,
            "popupCenteredRatio", &Window::popupCenteredRatio,
            "popupExclusive", &Window::popupExclusive,
            "popupExclusiveCentered", &Window::popupExclusiveCentered,
            "popupExclusiveCenteredClamped", &Window::popupExclusiveCenteredClamped,
            "popupExclusiveCenteredRatio", &Window::popupExclusiveCenteredRatio,
            "popupExclusiveOnParent", &Window::popupExclusiveOnParent,
            "popupOnParent", &Window::popupOnParent,
            "removeThemeColorOverride", &Window::removeThemeColorOverride,
            "removeThemeConstantOverride", &Window::removeThemeConstantOverride,
            "removeThemeFontOverride", &Window::removeThemeFontOverride,
            "removeThemeFontSizeOverride", &Window::removeThemeFontSizeOverride,
            "removeThemeIconOverride", &Window::removeThemeIconOverride,
            "removeThemeStyleBoxOverride", &Window::removeThemeStyleBoxOverride,
            "requestAttention", &Window::requestAttention,
            "resetSize", &Window::resetSize,
            "setFlag", &Window::setFlag,
            "setImeActive", &Window::setImeActive,
            "setImePosition", &Window::setImePosition,
            "setLayoutDirection", &Window::setLayoutDirection,
            "setUnparentWhenInvisible", &Window::setUnparentWhenInvisible,
            "setUseFontOversampling", &Window::setUseFontOversampling,
            "show", &Window::show,
            "startDrag", &Window::startDrag,
            "startResize", &Window::startResize,
            "cast", [](Element* e) {
                WindowNode* window = Object::cast_to<WindowNode>(e->getNode());
                return new Window(window);
            }
        );
    }
}