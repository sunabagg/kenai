#include "tab_bar.h"

namespace sunaba::ui {
    void TabBarProxy::_enter_tree() {
        if (element) {
            element->enterTree();
        }
    }

    void TabBarProxy::_exit_tree() {
        if (element) {
            element->exitTree();
        }
    }

    void TabBarProxy::_ready() {
        if (element) {
            element->ready();
        }
    }

    void TabBarProxy::_process(double delta) {
        if (element) {
            element->process(delta);
        }
    }

    void TabBarProxy::_physics_process(double delta) {
        if (element) {
            element->physicsProcess(delta);
        }
    }

    void TabBarProxy::_input(const Ref<InputEvent>& event) {
        if (element) {
            element->input(event);
        }
    }

    void TabBarProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element) {
            element->unhandledInput(event);
        }
    }

    void TabBarProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element) {
            element->unhandledKeyInput(event);
        }
    }

    void TabBarProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element) {
            element->shortcutInput(event);
        }
    }

    void TabBarProxy::_draw() {
        if (element) {
            element->_draw();
        }
    }

    bool TabBarProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void TabBarProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element) {
            element->dropData(at_position, data);
        }
    }
} // namespace sunaba::ui