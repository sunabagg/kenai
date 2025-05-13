#include "v_slider.h"

namespace sunaba::ui {
    void VSliderProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void VSliderProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void VSliderProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void VSliderProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void VSliderProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void VSliderProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void VSliderProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void VSliderProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void VSliderProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void VSliderProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool VSliderProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void VSliderProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }
}