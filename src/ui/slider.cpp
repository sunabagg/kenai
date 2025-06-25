#include "slider.h"

namespace lucidfx::ui {
    void SliderProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void SliderProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void SliderProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void SliderProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void SliderProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void SliderProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void SliderProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void SliderProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void SliderProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void SliderProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool SliderProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void SliderProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant SliderProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 SliderProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String SliderProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void SliderProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool SliderProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> SliderProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void SliderProxy::_value_changed(double value) {
        if (element != nullptr) {
            element->valueChanged(value);
        }
    }

    void SliderSignalWrapper::_bind_methods() {
        // Bind the methods for Slider signals
        ClassDB::bind_method(D_METHOD("drag_ended", "value_changed"), &SliderSignalWrapper::drag_ended);
        ClassDB::bind_method(D_METHOD("drag_started"), &SliderSignalWrapper::drag_started);
    }

    void SliderSignalWrapper::drag_ended(bool value_changed) {
        if (element != nullptr) {
            Array args;
            args.append(value_changed);
            element->dragEndedEvent->emit(args);
        }
    }

    void SliderSignalWrapper::drag_started() {
        if (element != nullptr) {
            Array args;
            element->dragStartedEvent->emit(args);
        }
    }

    void bindSlider(sol::state& lua) {
        lua.new_usertype<Slider>("Slider",
            "new", sol::factories(
                []() { return new Slider(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidfx::core::CanvasItem, Control, Range>(),
            "editable", sol::property(&Slider::isEditable, &Slider::setEditable),
            "focusMode", sol::property(&Slider::getFocusMode, &Slider::setFocusMode),
            "scrollable", sol::property(&Slider::getScrollable, &Slider::setScrollable),
            "step", sol::property(&Slider::getStep, &Slider::setStep),
            "tickCount", sol::property(&Slider::getTickCount, &Slider::setTickCount),
            "ticksOnBorders", sol::property(&Slider::getTicksOnBorders, &Slider::setTicksOnBorders),
            "dragEnded", sol::property(&Slider::getDragEndedEvent, &Slider::setDragEndedEvent),
            "dragStarted", sol::property(&Slider::getDragStartedEvent, &Slider::setDragStartedEvent),
            "cast", [] (Element* element) {
                SliderNode* slider = Object::cast_to<SliderNode>(element->getNode());
                return new Slider(slider);
            }
        );
    }
}