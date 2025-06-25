#include "h_slider.h"

namespace lucidfx::ui {
    void HSliderProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void HSliderProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void HSliderProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void HSliderProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void HSliderProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void HSliderProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void HSliderProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void HSliderProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void HSliderProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void HSliderProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool HSliderProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void HSliderProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant HSliderProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 HSliderProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String HSliderProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void HSliderProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool HSliderProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> HSliderProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void HSliderProxy::_value_changed(double value) {
        if (element != nullptr) {
            element->valueChanged(value);
        }
    }

    void bindHSlider(sol::state& lua) {
        // Bindings for HSlider
        lua.new_usertype<HSlider>("Hslider",
            "new", sol::factories(
                []() { return new HSlider(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidfx::core::CanvasItem, Range, Slider>(),
            "cast", [] (Element* element) {
                HSliderNode* hSlider = Object::cast_to<HSliderNode>(element->getNode());
                return new HSlider(hSlider);
            }
        );
    }
}