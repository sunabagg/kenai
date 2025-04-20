#include "control.h"
namespace sunaba::ui {
    bool ControlProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (control_element != nullptr) {
            return control_element->canDropData(at_position, data);
        }
        return false;
    }

    void ControlProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (control_element != nullptr) {
            control_element->dropData(at_position, data);
        }
    }

    Variant ControlProxy::_get_drag_data(const Vector2 &at_position) {
        if (control_element != nullptr) {
            return control_element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 ControlProxy::_get_minimum_size() const {
        if (control_element != nullptr) {
            return control_element->getMinimumSize();
        }
        return Vector2();
    }

    String ControlProxy::_get_tooltip(const Vector2 &at_position) const {
        if (control_element != nullptr) {
            return control_element->getTooltip(at_position).c_str();
        }
        return String();
    }

    void ControlProxy::_gui_input(const Ref<InputEvent> &event) {
        if (control_element != nullptr) {
            control_element->guiInput(event);
        }
    }

    bool ControlProxy::_has_point(const Vector2 &point) const {
        if (control_element != nullptr) {
            return control_element->hasPoint(point);
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
        if (control_element != nullptr) {
            return control_element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void bind_control(sol::state& lua) {
        lua.new_usertype<Control>("Control",
            sol::constructors<Control()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem>(),
            "anchorBottonm", sol::property(
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
            ),
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
            ),
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
            ),
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
        );
    }
}