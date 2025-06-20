#include "grid_container.h"

namespace sunaba::ui {
    void GridContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void GridContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void GridContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void GridContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void GridContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void GridContainerProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void GridContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void GridContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void GridContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void GridContainerProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool GridContainerProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void GridContainerProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant GridContainerProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 GridContainerProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String GridContainerProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void GridContainerProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool GridContainerProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> GridContainerProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    PackedInt32Array GridContainerProxy::_get_allowed_size_flags_horizontal() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsHorizontal();
        }
        return PackedInt32Array();
    }

    PackedInt32Array GridContainerProxy::_get_allowed_size_flags_vertical() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsVertical();
        }
        return PackedInt32Array();
    }

    void bindGridContainer(sol::state& lua) {
        lua.new_usertype<GridContainer>("GridContainer",
            "new", sol::factories(
                []() { return new GridContainer(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control, Container>(),
            "columns", sol::property(&GridContainer::getColumns, &GridContainer::setColumns),
            "cast", [](Element* element) {
                GridContainerNode* node = Object::cast_to<GridContainerNode>(element->getNode());
                return new GridContainer(node);
            }
        );
    }
}