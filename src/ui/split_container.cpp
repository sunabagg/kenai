#include "split_container.h"

namespace lucidfx::ui {
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

    bool SplitContainerProxy::_has_point(const Vector2& point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }
    
    void SplitContainerProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
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
            "new", sol::factories(
                []() { return new SplitContainer(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidfx::core::CanvasItem, Control, Container>(),
            "collapsed", sol::property(&SplitContainer::getCollapsed, &SplitContainer::setCollapsed),
            "dragAreaHighlightInEditor", sol::property(&SplitContainer::getDragAreaHighlightInEditor, &SplitContainer::setDragAreaHighlightInEditor),
            "dragAreaMarginBegin", sol::property(&SplitContainer::getDragAreaMarginBegin, &SplitContainer::setDragAreaMarginBegin),
            "dragAreaMarginEnd", sol::property(&SplitContainer::getDragAreaMarginEnd, &SplitContainer::setDragAreaMarginEnd),
            "dragAreaOffset", sol::property(&SplitContainer::getDragAreaOffset, &SplitContainer::setDragAreaOffset),
            "draggerVisibility", sol::property(&SplitContainer::getDraggerVisibility, &SplitContainer::setDraggerVisibility),
            "draggingEnabled", sol::property(&SplitContainer::getDraggingEnabled, &SplitContainer::setDraggingEnabled),
            "splitOffset", sol::property(&SplitContainer::getSplitOffset, &SplitContainer::setSplitOffset),
            "vertical", sol::property(&SplitContainer::isVertical, &SplitContainer::setVertical),
            "dragEnded", sol::property(&SplitContainer::getDragEndedEvent, &SplitContainer::setDragEndedEvent),
            "dragStarted", sol::property(&SplitContainer::getDragStartedEvent, &SplitContainer::setDragStartedEvent),
            "dragged", sol::property(&SplitContainer::getDraggedEvent, &SplitContainer::setDraggedEvent),
            "clampSplitOffset", &SplitContainer::clampSplitOffset,
            "getDragAreaControl", &SplitContainer::getDragAreaControl,
            "cast", [](Element* element) {
                SplitContainerNode* node = Object::cast_to<SplitContainerNode>(element->getNode());
                return new SplitContainer(node);
            }
        );
    }
}