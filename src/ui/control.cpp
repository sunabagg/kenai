#include "control.h"
namespace sunaba::ui {

    void sunaba::ui::ControlProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
    
    void sunaba::ui::ControlProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }
    
    void sunaba::ui::ControlProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
    
    void sunaba::ui::ControlProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }
    
    void sunaba::ui::ControlProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }
    
    void sunaba::ui::ControlProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }
    
    void sunaba::ui::ControlProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }
    
    void sunaba::ui::ControlProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }
    
    void sunaba::ui::ControlProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void ControlProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool ControlProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void ControlProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant ControlProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 ControlProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String ControlProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void ControlProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool ControlProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    //Object* ControlProxy::_make_custom_tooltip(const String &for_text) const {
    //    if (control_element != nullptr) {
    //        return control_element->makeCustomTooltip(for_text);
    //    }
    //    return nullptr;
    //}

    TypedArray<Vector3i> ControlProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void ControlSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("focus_entered"), &ControlSignalWrapper::focus_entered);
        ClassDB::bind_method(D_METHOD("focus_exited"), &ControlSignalWrapper::focus_exited);
        ClassDB::bind_method(D_METHOD("gui_input", "event"), &ControlSignalWrapper::gui_input);
        ClassDB::bind_method(D_METHOD("minimum_size_changed"), &ControlSignalWrapper::minimum_size_changed);
        ClassDB::bind_method(D_METHOD("mouse_entered"), &ControlSignalWrapper::mouse_entered);
        ClassDB::bind_method(D_METHOD("mouse_exited"), &ControlSignalWrapper::mouse_exited);
        ClassDB::bind_method(D_METHOD("resized"), &ControlSignalWrapper::resized);
        ClassDB::bind_method(D_METHOD("size_flags_changed"), &ControlSignalWrapper::size_flags_changed);
        ClassDB::bind_method(D_METHOD("theme_changed"), &ControlSignalWrapper::theme_changed);
    }

    void bindControl(sol::state& lua) {
        auto ut = lua.new_usertype<Control>("Control",
            sol::constructors<Control()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem>(),
            /*"anchorBottonm", sol::property(
                &Control::getAnchorBottom,
                &Control::setAnchorBottom
            ),
            "anchorLeft", sol::property(
                &Control::getAnchorLeft,
                &Control::setAnchorLeft
            ),
            "anchorRight", sol::property(
                &Control::getAnchorRight,
                &Control::setAnchorRight
            ),
            "anchorTop", sol::property(
                &Control::getAnchorTop,
                &Control::setAnchorTop
            ),*/
            "autoTranslate", sol::property(
                &Control::isAutoTranslating,
                &Control::setAutoTranslate
            ),
            "clippingContents", sol::property(
                &Control::isClippingContents,
                &Control::setClipContents
            ),
            "customMinimumSize", sol::property(
                &Control::getCustomMinimumSize,
                &Control::setCustomMinimumSize
            ),
            "focusMode", sol::property(
                &Control::getFocusMode,
                &Control::setFocusMode
            ),
            "focusNeighborBottom", sol::property(
                &Control::getFocusNeighborBottom,
                &Control::setFocusNeighborBottom
            ),
            "focusNeighborLeft", sol::property(
                &Control::getFocusNeighborLeft,
                &Control::setFocusNeighborLeft
            ),
            "focusNeighborRight", sol::property(
                &Control::getFocusNeighborRight,
                &Control::setFocusNeighborRight
            ),
            "focusNeighborTop", sol::property(
                &Control::getFocusNeighborTop,
                &Control::setFocusNeighborTop
            ),
            "focusNext", sol::property(
                &Control::getFocusNext,
                &Control::setFocusNext
            ),
            "focusPrevious", sol::property(
                &Control::getFocusPrevious,
                &Control::setFocusPrevious
            ),
            "globalPosition", sol::property(
                &Control::getGlobalPosition,
                &Control::setGlobalPosition
            ),
            "growHorizontal", sol::property(
                &Control::getGrowHorizontal,
                &Control::setGrowHorizontal
            ),
            "growVertical", sol::property(
                &Control::getGrowVertical,
                &Control::setGrowVertical
            ),
            "layoutDirection", sol::property(
                &Control::getLayoutDirection,
                &Control::setLayoutDirection
            ),
            "localizeNumeralSystem", sol::property(
                &Control::isLocalizingNumeralSystem,
                &Control::setLocalizeNumeralSystem
            ),
            "mouseDefaultCursorShape", sol::property(
                &Control::getMouseDefaultCursorShape,
                &Control::setMouseDefaultCursorShape
            ),
            "mouseFilter", sol::property(
                &Control::getMouseFilter,
                &Control::setMouseFilter
            ),
            "mouseForcePassScrollEvents", sol::property(
                &Control::getMouseForcePassScrollEvents,
                &Control::setMouseForcePassScrollEvents
            ),/*
            "offsetBottom", sol::property(
                &Control::getOffsetBottom,
                &Control::setOffsetBottom
            ),
            "offsetLeft", sol::property(
                &Control::getOffsetLeft,
                &Control::setOffsetLeft
            ),
            "offsetRight", sol::property(
                &Control::getOffsetRight,
                &Control::setOffsetRight
            ),
            "offsetTop", sol::property(
                &Control::getOffsetTop,
                &Control::setOffsetTop
            ),*/
            "physicsInterpolationMode", sol::property(
                &Control::getPhysicsInterpolationMode,
                &Control::setPhysicsInterpolationMode
            ),
            "pivotOffset", sol::property(
                &Control::getPivotOffset,
                &Control::setPivotOffset
            ),
            "position", sol::property(
                &Control::getPosition,
                &Control::setPosition
            ),
            "rotation", sol::property(
                &Control::getRotation,
                &Control::setRotation
            ),
            "rotationDegrees", sol::property(
                &Control::getRotationDegrees,
                &Control::setRotationDegrees
            ),
            "scale", sol::property(
                &Control::getScale,
                &Control::setScale
            ),
            "shortcutContext", sol::property(
                &Control::getShortcutContext,
                &Control::setShortcutContext
            ),
            "size", sol::property(
                &Control::getSize,
                &Control::setSize
            ),
            "sizeFlagsHorizontal", sol::property(
                &Control::getSizeFlagsHorizontal,
                &Control::setSizeFlagsHorizontal
            ),
            "sizeFlagsStretchRatio", sol::property(
                &Control::getSizeFlagsStretchRatio,
                &Control::setSizeFlagsStretchRatio
            ),
            "sizeFlagsVertical", sol::property(
                &Control::getSizeFlagsVertical,
                &Control::setSizeFlagsVertical
            ),
            "theme", sol::property(
                &Control::getTheme,
                &Control::setTheme
            ),
            "themeTypeVariation", sol::property(
                &Control::getThemeTypeVariation,
                &Control::setThemeTypeVariation
            ),
            "toolTipAutoTranslateMode", sol::property(
                &Control::getToolTipAutoTranslateMode,
                &Control::setToolTipAutoTranslateMode
            ),
            "toolTipText", sol::property(
                &Control::getToolTipText,
                &Control::setToolTipText
            ),
            "focusEntered", sol::property(
                [](Control* c) { return c->focusEnteredEvent; },
                [](Control* c, Event* e) { c->focusEnteredEvent = e; }
            ),
            "focusExited", sol::property(
                [](Control* c) { return c->focusExitedEvent; },
                [](Control* c, Event* e) { c->focusExitedEvent = e; }
            ),
            "guiInput", sol::property(
                [](Control* c) { return c->guiInputEvent; },
                [](Control* c, Event* e) { c->guiInputEvent = e; }
            ),
            "minimumSizeChanged", sol::property(
                [](Control* c) { return c->minimumSizeChangedEvent; },
                [](Control* c, Event* e) { c->minimumSizeChangedEvent = e; }
            ),
            "mouseEntered", sol::property(
                [](Control* c) { return c->mouseEnteredEvent; },
                [](Control* c, Event* e) { c->mouseEnteredEvent = e; }
            ),
            "mouseExited", sol::property(
                [](Control* c) { return c->mouseExitedEvent; },
                [](Control* c, Event* e) { c->mouseExitedEvent = e; }
            ),
            "resized", sol::property(
                [](Control* c) { return c->resizedEvent; },
                [](Control* c, Event* e) { c->resizedEvent = e; }
            ),
            "sizeFlagsChanged", sol::property(
                [](Control* c) { return c->sizeFlagsChangedEvent; },
                [](Control* c, Event* e) { c->sizeFlagsChangedEvent = e; }
            ),
            "themeChanged", sol::property(
                [](Control* c) { return c->themeChangedEvent; },
                [](Control* c, Event* e) { c->themeChangedEvent = e; }
            ),
            "acceptEvent", &Control::acceptEvent,
            "addThemeColorOverride", &Control::addThemeColorOverride,
            "addThemeConstantOverride", &Control::addThemeConstantOverride,
            "addThemeFontOverride", &Control::addThemeFontOverride,
            "addThemeFontSizeOverride", &Control::addThemeFontSizeOverride,
            "addThemeStyleboxOverride", &Control::addThemeStyleboxOverride,
            "addThemeIconOverride", &Control::addThemeIconOverride,
            "beginBulkThemeOveride", &Control::beginBulkThemeOveride,
            "endBulkThemeOveride", &Control::endBulkThemeOveride,
            "findNextValidFocus", &Control::findNextValidFocus,
            "findPrevValidFocus", &Control::findPrevValidFocus,
            "findValidFocusNeighbor", &Control::findValidFocusNeighbor,
            "forceDrag", &Control::forceDrag,
            "getAnchor", &Control::getAnchor,
            "getBegin", &Control::getBegin,
            "getCombinedMinimumSize", &Control::getCombinedMinimumSize,
            "getCursorShape", &Control::getCursorShape,
            "getEnd", &Control::getEnd,
            "getFocusNeighbor", &Control::getFocusNeighbor,
            "getGlobalRect", &Control::getGlobalRect,
            "getMinimumSize", &Control::getMinimumSize,
            "getOffset", &Control::getOffset,
            "getParentAreaSize", &Control::getParentAreaSize,
            "getParentControl", &Control::getParentControl,
            "getRect", &Control::getRect,
            "getScreenPosition", &Control::getScreenPosition,
            "getThemeColor", &Control::getThemeColor,
            "getThemeConstant", &Control::getThemeConstant,
            "getThemeDefaultBaseScale", &Control::getThemeDefaultBaseScale,
            "getThemeDefaultFont", &Control::getThemeDefaultFont,
            "getThemeDefaultFontSize", &Control::getThemeDefaultFontSize,
            "getThemeFont", &Control::getThemeFont,
            "getThemeFontSize", &Control::getThemeFontSize,
            "getThemeIcon", &Control::getThemeIcon,
            "getThemeStylebox", &Control::getThemeStylebox,
            "getTooltip", &Control::getTooltip,
            "grabClickFocus", &Control::grabClickFocus,
            "grabFocus", &Control::grabFocus,
            "hasFocus", &Control::hasFocus,
            "hasThemeColor", &Control::hasThemeColor,
            "hasThemeColorOverride", &Control::hasThemeColorOverride,
            "hasThemeConstant", &Control::hasThemeConstant,
            "hasThemeConstantOverride", &Control::hasThemeConstantOverride,
            "hasThemeFont", &Control::hasThemeFont,
            "hasThemeFontOverride", &Control::hasThemeFontOverride,
            "hasThemeIcon", &Control::hasThemeIcon,
            "hasThemeIconOverride", &Control::hasThemeIconOverride,
            "hasThemeStylebox", &Control::hasThemeStylebox,
            "hasThemeStyleboxOverride", &Control::hasThemeStyleboxOverride,
            "isDragSuccessful", &Control::isDragSuccessful,
            "isLayoutRtl", &Control::isLayoutRtl,
            "releaseFocus", &Control::releaseFocus,
            "removeThemeColorOverride", &Control::removeThemeColorOverride,
            "removeThemeConstantOverride", &Control::removeThemeConstantOverride,
            "removeThemeFontOverride", &Control::removeThemeFontOverride,
            "removeThemeFontSizeOverride", &Control::removeThemeFontSizeOverride,
            "removeThemeIconOverride", &Control::removeThemeIconOverride,
            "removeThemeStyleboxOverride", &Control::removeThemeStyleboxOverride,
            "resetSize", &Control::resetSize,
            "setAnchor", &Control::setAnchor,
            "setAnchorAndOffset", &Control::setAnchorAndOffset,
            "setAnchorsAndOffsetsPreset", &Control::setAnchorsAndOffsetsPreset,
            "setAnchorsPreset", &Control::setAnchorsPreset,
            "setBegin", &Control::setBegin,
            "setDragPreview", &Control::setDragPreview,
            "setEnd", &Control::setEnd,
            "setFocusNeighbor", &Control::setFocusNeighbor,
            "setGlobalPosition", &Control::setGlobalPosition,
            "setOffset", &Control::setOffset,
            "setOffsetsPreset", &Control::setOffsetsPreset,
            "setPosition", &Control::setPosition,
            "setSize", &Control::setSize,
            "updateMinimumSize", &Control::updateMinimumSize,
            "warpMouse", &Control::warpMouse,
            "cast", [](Element* e) {
                ControlNode* control = Object::cast_to<ControlNode>(e->getNode());
                return new Control(control);
            }
        );

        // stupid hack fix
        ut["anchorTop"] = sol::property(
            &Control::getAnchorBottom,
            &Control::setAnchorBottom
        );
        ut["anchorBottom"] = sol::property(
            &Control::getAnchorTop,
            &Control::setAnchorTop
        );
        ut["anchorLeft"] = sol::property(
            &Control::getAnchorLeft,
            &Control::setAnchorLeft
        );
        ut["anchorRight"] = sol::property(
            &Control::getAnchorRight,
            &Control::setAnchorRight
        );
        ut["offsetTop"] = sol::property(
            &Control::getOffsetBottom,
            &Control::setOffsetBottom
        );
        ut["offsetBottom"] = sol::property(
            &Control::getOffsetTop,
            &Control::setOffsetTop
        );
        ut["offsetLeft"] = sol::property(
            &Control::getOffsetLeft,
            &Control::setOffsetLeft
        );
        ut["offsetRight"] = sol::property(
            &Control::getOffsetRight,
            &Control::setOffsetRight
        );
    }
}