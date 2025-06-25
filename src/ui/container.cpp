#include "container.h"

namespace lucidfx::ui {
    void ContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
    
    void ContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }
    
    void ContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
    
    void ContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }
    void ContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }
    void ContainerProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }
    void ContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }
    void ContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }
    void ContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }
    void ContainerProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }
    bool ContainerProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }
    void ContainerProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }
    Variant ContainerProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }
    Vector2 ContainerProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }
    String ContainerProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }
    void ContainerProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }
    bool ContainerProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }
    //Object* ContainerProxy::_make_custom_tooltip(const String &for_text) const {
    //    if (element != nullptr) {
    //        return element->makeCustomTooltip(for_text);
    //    }
    //    return nullptr;
    //}
    TypedArray<Vector3i> ContainerProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }
    PackedInt32Array ContainerProxy::_get_allowed_size_flags_horizontal() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsHorizontal();
        }
        return PackedInt32Array();
    }
    PackedInt32Array ContainerProxy::_get_allowed_size_flags_vertical() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsVertical();
        }
        return PackedInt32Array();
    }

    void ContainerSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("pre_sort_children"), &ContainerSignalWrapper::pre_sort_children);
        ClassDB::bind_method(D_METHOD("sort_children"), &ContainerSignalWrapper::sort_children);
    }

    void ContainerSignalWrapper::pre_sort_children() {
        if (element != nullptr && element->getPreSortChildrenEvent() != nullptr) {
            Array args;
            element->getPreSortChildrenEvent()->emit(args);
        }
    }

    void ContainerSignalWrapper::sort_children() {
        if (element != nullptr && element->getSortChildrenEvent() != nullptr) {
            Array args;
            element->getSortChildrenEvent()->emit(args);
        }
    }

    void bindContainer(sol::state& lua) {
        auto ut = lua.new_usertype<Container>("Container",
            "new", sol::factories(
                []() { return new Container(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidfx::core::CanvasItem, Control>(),
            "mouseFilter", sol::property(
                &Container::getMouseFilter,
                &Container::setMouseFilter
            ),
            "fitChildInRect", &Container::fitChildInRect,
            "queueSort", &Container::queueSort,
            "cast", [](Element* e) {
                ContainerNode* container = Object::cast_to<ContainerNode>(e->getNode());
                return new Container(container);
            }
        );
    }
}
