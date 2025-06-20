#include "v_split_container.h"

namespace sunaba::ui {
    void VSplitContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void VSplitContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void VSplitContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void VSplitContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void VSplitContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void VSplitContainerProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void VSplitContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void VSplitContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void VSplitContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void VSplitContainerProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool VSplitContainerProxy::_can_drop_data(const Vector2& at_position, const Variant& data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void VSplitContainerProxy::_drop_data(const Vector2& at_position, const Variant& data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant VSplitContainerProxy::_get_drag_data(const Vector2& at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 VSplitContainerProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String VSplitContainerProxy::_get_tooltip(const Vector2& at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void VSplitContainerProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool VSplitContainerProxy::_has_point(const Vector2& point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> VSplitContainerProxy::_structured_text_parser(const Array& args, const String& text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    PackedInt32Array VSplitContainerProxy::_get_allowed_size_flags_horizontal() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsHorizontal();
        }
        return PackedInt32Array();
    }

    PackedInt32Array VSplitContainerProxy::_get_allowed_size_flags_vertical() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsVertical();
        }
        return PackedInt32Array();
    }

    void bindVSplitContainer(sol::state& lua) {
        lua.new_usertype<VSplitContainer>("VSplitContainer",
            "new", sol::factories(
                []() { return new VSplitContainer(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control, Container, SplitContainer>(),
            "cast", [](Element* element) {
                VSplitContainerNode* node = Object::cast_to<VSplitContainerNode>(element->getNode());
                return new VSplitContainer(node);
            }
        );
    }
}