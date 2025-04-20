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
        );
    }
}