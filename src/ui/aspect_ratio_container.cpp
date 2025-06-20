#include "aspect_ratio_container.h"

namespace sunaba::ui {
    void AspectRatioContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
    
    void AspectRatioContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }
    
    void AspectRatioContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
    
    void AspectRatioContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void AspectRatioContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void AspectRatioContainerProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void AspectRatioContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void AspectRatioContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void AspectRatioContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void AspectRatioContainerProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool AspectRatioContainerProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void AspectRatioContainerProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant AspectRatioContainerProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 AspectRatioContainerProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String AspectRatioContainerProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void AspectRatioContainerProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool AspectRatioContainerProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> AspectRatioContainerProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    PackedInt32Array AspectRatioContainerProxy::_get_allowed_size_flags_horizontal() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsHorizontal();
        }
        return PackedInt32Array();
    }

    PackedInt32Array AspectRatioContainerProxy::_get_allowed_size_flags_vertical() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsVertical();
        }
        return PackedInt32Array();
    }

    void bindAspectRatioContainer(sol::state& lua) {
        auto ut = lua.new_usertype<AspectRatioContainer>("AspectRatioContainer",
            "new", sol::factories(
                []() { return new AspectRatioContainer(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control, Container>(),
            "alignmentHorizontal", sol::property(
                &AspectRatioContainer::getAlignmentHorizontal,
                &AspectRatioContainer::setAlignmentHorizontal
            ),
            "alignmentVertical", sol::property(
                &AspectRatioContainer::getAlignmentVertical,
                &AspectRatioContainer::setAlignmentVertical
            ),
            "ratio", sol::property(
                &AspectRatioContainer::getRatio,
                &AspectRatioContainer::setRatio
            ),
            "stretchMode", sol::property(
                &AspectRatioContainer::getStretchMode,
                &AspectRatioContainer::setStretchMode
            ),
            "cast", [](Element* e) {
                AspectRatioContainerNode* control = Object::cast_to<AspectRatioContainerNode>(e->getNode());
                return new AspectRatioContainer(control);
            }
        );
    }
}