#include "spin_box.h"

namespace lucidfx::ui {
    void SpinBoxProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void SpinBoxProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void SpinBoxProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void SpinBoxProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void SpinBoxProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void SpinBoxProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void SpinBoxProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void SpinBoxProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void SpinBoxProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void SpinBoxProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool SpinBoxProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void SpinBoxProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant SpinBoxProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 SpinBoxProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String SpinBoxProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void SpinBoxProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool SpinBoxProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> SpinBoxProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void SpinBoxProxy::_value_changed(double value) {
        if (element != nullptr) {
            element->valueChanged(value);
        }
    }

    void bindSpinBox(sol::state &lua) {
        lua.new_usertype<SpinBox>("SpinBox",
            "new", sol::factories(
                []() { return new SpinBox(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidfx::core::CanvasItem, Control, Range>(),
            "alignment", sol::property(&SpinBox::getAlignment, &SpinBox::setAlignment),
            "customArrowStep", sol::property(&SpinBox::getCustomArrowStep, &SpinBox::setCustomArrowStep),
            "editable", sol::property(&SpinBox::isEditable, &SpinBox::setEditable),
            "prefix", sol::property(&SpinBox::getPrefix, &SpinBox::setPrefix),
            "selectAllOnFocus", sol::property(&SpinBox::isSelectAllOnFocus, &SpinBox::setSelectAllOnFocus),
            "step", sol::property(&SpinBox::getStep, &SpinBox::setStep),
            "suffix", sol::property(&SpinBox::getSuffix, &SpinBox::setSuffix),
            "updateOnTextChanged", sol::property(&SpinBox::getUpdateOnTextChanged, &SpinBox::setUpdateOnTextChanged),
            "cast", [] (Element* element) {
                SpinBoxNode* spinBox = Object::cast_to<SpinBoxNode>(element->getNode());
                return new SpinBox(spinBox);
            }
        );
    }
}