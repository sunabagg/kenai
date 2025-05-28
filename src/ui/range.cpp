#include "range.h"

namespace sunaba::ui {
    void RangeProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void RangeProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void RangeProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void RangeProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void RangeProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void RangeProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void RangeProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void RangeProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void RangeProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void RangeProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool RangeProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void RangeProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant RangeProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 RangeProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String RangeProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void RangeProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool RangeProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> RangeProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void RangeProxy::_value_changed(double value) {
        if (element != nullptr) {
            element->valueChanged(value);
        }
    }

    void RangeSignalWrapper::_bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("changed"), &RangeSignalWrapper::changed);
        godot::ClassDB::bind_method(godot::D_METHOD("value_changed", "value"), &RangeSignalWrapper::value_changed);
    }

    void RangeSignalWrapper::changed() {
        if (element != nullptr) {
            Array args;
            element->getChangedEvent()->emit(args);
        }
    }

    void bindRange(sol::state &lua) {
        lua.new_usertype<Range>("Range",
            sol::constructors<Range()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control>(),
            "allowGreater", sol::property(&Range::getAllowGreater, &Range::setAllowGreater),
            "allowLesser", sol::property(&Range::getAllowLesser, &Range::setAllowLesser),
            "expEdit", sol::property(&Range::getExpEdit, &Range::setExpEdit),
            "maxValue", sol::property(&Range::getMaxValue, &Range::setMaxValue),
            "minValue", sol::property(&Range::getMinValue, &Range::setMinValue),
            "page", sol::property(&Range::getPage, &Range::setPage),
            "ratio", sol::property(&Range::getRatio, &Range::setRatio),
            "rounded", sol::property(&Range::getRounded, &Range::setRounded),
            "sizeFlagsVertical", sol::property(&Range::getSizeFlagsVertical, &Range::setSizeFlagsVertical),
            "step", sol::property(&Range::getStep, &Range::setStep),
            "value", sol::property(&Range::getValue, &Range::setValue),
            "changed", sol::property(&Range::getChangedEvent, &Range::setChangedEvent),
            "valueChanged", sol::property(&Range::getValueChangedEvent, &Range::setValueChangedEvent),
            "setValueNoSignal", &Range::setValueNoSignal,
            "share", &Range::share,
            "unshare", &Range::unshare,
            "cast", [] (Element* element) {
                RangeNode* range = godot::Object::cast_to<RangeNode>(element->getNode());
                return new Range(range);
            }
        );
    }
}