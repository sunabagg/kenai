#include "scroll_bar.h"

namespace lucidware::ui {
    void ScrollBarProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void ScrollBarProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void ScrollBarProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void ScrollBarProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void ScrollBarProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void ScrollBarProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void ScrollBarProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void ScrollBarProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void ScrollBarProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void ScrollBarProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool ScrollBarProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void ScrollBarProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant ScrollBarProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 ScrollBarProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String ScrollBarProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void ScrollBarProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool ScrollBarProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> ScrollBarProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void ScrollBarProxy::_value_changed(double value) {
        if (element != nullptr) {
            element->valueChanged(value);
        }
    }

    void bindScrollBar(sol::state &lua) {
        lua.new_usertype<ScrollBar>("ScrollBar",
            "new", sol::factories(
                []() { return new ScrollBar(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidware::core::CanvasItem, Control, Range>(),
            "customStep", sol::property(&ScrollBar::getCustomStep, &ScrollBar::setCustomStep),
            "step", sol::property(&ScrollBar::getStep, &ScrollBar::setStep),
            "scrolling", sol::property(&ScrollBar::getScrollingEvent, &ScrollBar::setScrollingEvent),
            "cast", [] (Element* element) {
                ScrollBarNode* scrollBar = Object::cast_to<ScrollBarNode>(element->getNode());
                return new ScrollBar(scrollBar);
            }
        );
    }
}