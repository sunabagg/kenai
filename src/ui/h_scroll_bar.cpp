#include "h_scroll_bar.h"

namespace sunaba::ui {
    void HScrollBarProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void HScrollBarProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void HScrollBarProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void HScrollBarProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void HScrollBarProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void HScrollBarProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void HScrollBarProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void HScrollBarProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void HScrollBarProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void HScrollBarProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool HScrollBarProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void HScrollBarProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant HScrollBarProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 HScrollBarProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String HScrollBarProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void HScrollBarProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool HScrollBarProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> HScrollBarProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void HScrollBarProxy::_value_changed(double value) {
        if (element != nullptr) {
            element->valueChanged(value);
        }
    }

    void bindHScrollBar(sol::state &lua) {
        lua.new_usertype<HScrollBar>("HScrollBar",
            "new", sol::factories(
                []() { return new HScrollBar(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control, Range, ScrollBar>(),
            "cast", [] (Element* element) {
                HScrollBarNode* hScrollBarNode = Object::cast_to<HScrollBarNode>(element->getNode());
                return new HScrollBar(hScrollBarNode);
            }
        );
    }
}