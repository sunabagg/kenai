#include "scroll_container.h"

namespace sunaba::ui {
    void ScrollContainerProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void ScrollContainerProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void ScrollContainerProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void ScrollContainerProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void ScrollContainerProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void ScrollContainerProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void ScrollContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void ScrollContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void ScrollContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void ScrollContainerProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool ScrollContainerProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void ScrollContainerProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant ScrollContainerProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 ScrollContainerProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String ScrollContainerProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void ScrollContainerProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool ScrollContainerProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> ScrollContainerProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    PackedInt32Array ScrollContainerProxy::_get_allowed_size_flags_horizontal() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsHorizontal();
        }
        return PackedInt32Array();
    }

    PackedInt32Array ScrollContainerProxy::_get_allowed_size_flags_vertical() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsVertical();
        }
        return PackedInt32Array();
    }

    void bindScrollContainer(sol::state& lua) {
        lua.new_usertype<ScrollContainer>("ScrollContainer",
            "new", sol::factories(
                []() { return new ScrollContainer(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control, Container>(),
            "clipContents", sol::property(&ScrollContainer::isClippingContents, &ScrollContainer::setClipContents),
            "drawFocusBorder", sol::property(&ScrollContainer::getDrawFocusBorder, &ScrollContainer::setDrawFocusBorder),
            "followFocus", sol::property(&ScrollContainer::isFollowingFocus, &ScrollContainer::setFollowFocus),
            "horizontalScrollMode", sol::property(&ScrollContainer::getHorizontalScrollMode, &ScrollContainer::setHorizontalScrollMode),
            "scrollDeadzone", sol::property(&ScrollContainer::getScrollDeadzone, &ScrollContainer::setScrollDeadzone),
            "scrollHorizontal", sol::property(&ScrollContainer::getScrollHorizontal, &ScrollContainer::setScrollHorizontal),
            "scrollHorizontalCustomStep", sol::property(&ScrollContainer::getScrollHorizontalCustomStep, &ScrollContainer::setScrollHorizontalCustomStep),
            "scrollVertical", sol::property(&ScrollContainer::getScrollVertical, &ScrollContainer::setScrollVertical),
            "scrollVerticalCustomStep", sol::property(&ScrollContainer::getScrollVerticalCustomStep, &ScrollContainer::setScrollVerticalCustomStep),
            "verticalScrollMode", sol::property(&ScrollContainer::getVerticalScrollMode, &ScrollContainer::setVerticalScrollMode),
            "scrollEnded", sol::property(&ScrollContainer::getScrollEndedEvent, &ScrollContainer::setScrollEndedEvent),
            "scrollStarted", sol::property(&ScrollContainer::getScrollStartedEvent, &ScrollContainer::setScrollStartedEvent),
            "ensureControlVisible", &ScrollContainer::ensureControlVisible,
            "getHScrollBar", &ScrollContainer::getHScrollBar,
            "getVScrollBar", &ScrollContainer::getVScrollBar,
            "cast", [] (Element* element) {
                ScrollContainerNode* scrollContainer = Object::cast_to<ScrollContainerNode>(element->getNode());
                return new ScrollContainer(scrollContainer);
            }
        );
    }
}