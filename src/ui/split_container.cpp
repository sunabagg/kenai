#include "split_container.h"

namespace sunaba::ui {
    void SplitContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void SplitContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void SplitContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void SplitContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void SplitContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void SplitContainerProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void SplitContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void SplitContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void SplitContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void SplitContainerProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool SplitContainerProxy::_can_drop_data(const Vector2& at_position, const Variant& data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void SplitContainerProxy::_drop_data(const Vector2& at_position, const Variant& data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant SplitContainerProxy::_get_drag_data(const Vector2& at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 SplitContainerProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String SplitContainerProxy::_get_tooltip(const Vector2& at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    TypedArray<Vector3i> SplitContainerProxy::_structured_text_parser(const Array& args, const String& text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    PackedInt32Array SplitContainerProxy::_get_allowed_size_flags_horizontal() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsHorizontal();
        }
        return PackedInt32Array();
    }

    PackedInt32Array SplitContainerProxy::_get_allowed_size_flags_vertical() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsVertical();
        }
        return PackedInt32Array();
    }

    void bindSplitContainer(sol::state& lua) {
        lua.new_usertype<SplitContainer>("SplitContainer",
            sol::constructors<SplitContainer()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control, Container>(),
            "collapsed", sol::property(&SplitContainer::getCollapsed, &SplitContainer::setCollapsed),
            "dragAreaHighlightInEditor", sol::property(&SplitContainer::getDragAreaHighlightInEditor, &SplitContainer::setDragAreaHighlightInEditor),
            "dragAreaMarginBegin", sol::property(&SplitContainer::getDragAreaMarginBegin, &SplitContainer::setDragAreaMarginBegin),
        );
    }
}