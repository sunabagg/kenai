#include "sub_viewport_container.h"

namespace sunaba::ui {
    void SubViewportContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void SubViewportContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void SubViewportContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void SubViewportContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void SubViewportContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void SubViewportContainerProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void SubViewportContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void SubViewportContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void SubViewportContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void SubViewportContainerProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool SubViewportContainerProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void SubViewportContainerProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant SubViewportContainerProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 SubViewportContainerProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String SubViewportContainerProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void SubViewportContainerProxy::_gui_input(const Ref<InputEvent> &event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool SubViewportContainerProxy::_has_point(const Vector2 &point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> SubViewportContainerProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    PackedInt32Array SubViewportContainerProxy::_get_allowed_size_flags_horizontal() const {
        if (this->element != nullptr) {
            return this->element->getAllowedSizeFlagsHorizontal();
        }
        return PackedInt32Array();
    }

    PackedInt32Array SubViewportContainerProxy::_get_allowed_size_flags_vertical() const {
        if (this->element != nullptr) {
            return this->element->getAllowedSizeFlagsVertical();
        }
        return PackedInt32Array();
    }

    bool SubViewportContainerProxy::_propagate_input_event(const Ref<InputEvent> &event) const {
        if (this->element != nullptr) {
            return this->element->propagateInputEvent(event);
        }
        return false;
    }

    void bindSubViewportContainer(sol::state& lua) {
        lua.new_usertype<SubViewportContainer>("SubViewportContainer",
            sol::constructors<SubViewportContainer()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control, Container>(),
            "focusMode", sol::property(&SubViewportContainer::getFocusMode, &SubViewportContainer::setFocusMode),
            "mouseTarget", sol::property(&SubViewportContainer::getMouseTarget, &SubViewportContainer::setMouseTarget),
            "stretch", sol::property(
                &SubViewportContainer::getStretch,
                &SubViewportContainer::setStretch
            ),
            "stretchShrink", sol::property(
                &SubViewportContainer::getStretchShrink,
                &SubViewportContainer::setStretchShrink
            ),
            "cast", [](Element* element) {
                SubViewportContainerNode* container = Object::cast_to<SubViewportContainerNode>(element->getNode());
                return new SubViewportContainer(container);
            }
        );
    }
}