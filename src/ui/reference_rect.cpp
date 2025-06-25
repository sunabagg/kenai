#include "reference_rect.h"

namespace lucidware::ui {
    void ReferenceRectProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void ReferenceRectProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void ReferenceRectProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void ReferenceRectProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void ReferenceRectProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void ReferenceRectProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void ReferenceRectProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void ReferenceRectProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void ReferenceRectProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void ReferenceRectProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool ReferenceRectProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void ReferenceRectProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant ReferenceRectProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 ReferenceRectProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String ReferenceRectProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void ReferenceRectProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool ReferenceRectProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> ReferenceRectProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void bindReferenceRect(sol::state& lua) {
        lua.new_usertype<ReferenceRect>("ReferenceRect",
            "new", sol::factories(
                []() { return new ReferenceRect(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidware::core::CanvasItem, Control>(),
            "borderColor", sol::property(&ReferenceRect::getBorderColor, &ReferenceRect::setBorderColor),
            "borderWidth", sol::property(&ReferenceRect::getBorderWidth, &ReferenceRect::setBorderWidth),
            "cast", [] (Element* element) {
                ReferenceRectNode* referenceRect = Object::cast_to<ReferenceRectNode>(element->getNode());
                return new ReferenceRect(referenceRect);
            }
        );
    }
}