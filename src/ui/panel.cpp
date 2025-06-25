#include "panel.h"

namespace lucidware::ui {
    void PanelProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void PanelProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void PanelProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void PanelProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void PanelProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void PanelProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void PanelProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void PanelProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void PanelProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void PanelProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool PanelProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void PanelProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant PanelProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 PanelProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String PanelProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void PanelProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool PanelProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> PanelProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void bindPanel(sol::state& lua) {
        lua.new_usertype<Panel>("Panel",
            "new", sol::factories(
                []() { return new Panel(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidware::core::CanvasItem, Control>(),
            "cast", [] (Element* element) {
                PanelNode* node = Object::cast_to<PanelNode>(element->getNode());
                return new Panel(node);
            }
        );
    }
}