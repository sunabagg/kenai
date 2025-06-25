#include "v_flow_container.h"

namespace lucidfx::ui {

    void VFlowContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void VFlowContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void VFlowContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void VFlowContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void VFlowContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void VFlowContainerProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void VFlowContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void VFlowContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void VFlowContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void VFlowContainerProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool VFlowContainerProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void VFlowContainerProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant VFlowContainerProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 VFlowContainerProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String VFlowContainerProxy::_get_tooltip(const Vector2 &at_position) const {
        if (this->element != nullptr) {
            return this->element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void VFlowContainerProxy::_gui_input(const Ref<InputEvent> &event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool VFlowContainerProxy::_has_point(const Vector2 &point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> VFlowContainerProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    PackedInt32Array VFlowContainerProxy::_get_allowed_size_flags_horizontal() const {
        if (this->element != nullptr) {
            return this->element->getAllowedSizeFlagsHorizontal();
        }
        return PackedInt32Array();
    }

    PackedInt32Array VFlowContainerProxy::_get_allowed_size_flags_vertical() const {
        if (this->element != nullptr) {
            return this->element->getAllowedSizeFlagsVertical();
        }
        return PackedInt32Array();
    }

    void bindVFlowContainer(sol::state &lua) {
        lua.new_usertype<VFlowContainer>("VflowContainer",
            "new", sol::factories(
                []() { return new VFlowContainer(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidfx::core::CanvasItem, Control, Container, FlowContainer>(),
            "cast", [](Element* element) {
                VFlowContainerNode* vflowContainerNode = Object::cast_to<VFlowContainerNode>(element->getNode());
                return new VFlowContainer(vflowContainerNode);
            }
        );
    }
} // namespace lucidfx::ui