#include "flow_container.h"

namespace lucidware::ui {
    void FlowContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void FlowContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void FlowContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void FlowContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void FlowContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void FlowContainerProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void FlowContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void FlowContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void FlowContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void FlowContainerProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool FlowContainerProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void FlowContainerProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant FlowContainerProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 FlowContainerProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String FlowContainerProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void FlowContainerProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool FlowContainerProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> FlowContainerProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    PackedInt32Array FlowContainerProxy::_get_allowed_size_flags_horizontal() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsHorizontal();
        }
        return PackedInt32Array();
    }

    PackedInt32Array FlowContainerProxy::_get_allowed_size_flags_vertical() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsVertical();
        }
        return PackedInt32Array();
    }

    void bindFlowContainer(sol::state& lua) {
        lua.new_usertype<FlowContainer>("FlowContainer",
            "new", sol::factories(
                []() { return new FlowContainer(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidware::core::CanvasItem, Control, Container>(),
            "alignment", sol::property(
                &FlowContainer::getAlignment,
                &FlowContainer::setAlignment
            ),
            "lastWrapAlignment", sol::property(
                &FlowContainer::getLastWrapAlignment,
                &FlowContainer::setLastWrapAlignment
            ),
            "reverseFill", sol::property(
                &FlowContainer::getReverseFill,
                &FlowContainer::setReverseFill
            ),
            "vertical", sol::property(
                &FlowContainer::getVertical,
                &FlowContainer::setVertical
            ),
            "getLineCount", &FlowContainer::getLineCount,
            "cast", [](Element* element) {
                FlowContainerNode* node = Object::cast_to<FlowContainerNode>(element->getNode());
                return new FlowContainer(node);
            }
        );
    }
}