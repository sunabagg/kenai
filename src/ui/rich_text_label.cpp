#include "rich_text_label.h"

namespace sunaba::ui {
    void RichTextLabelProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }

    void RichTextLabelProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }

    void RichTextLabelProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void RichTextLabelProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void RichTextLabelProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void RichTextLabelProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void RichTextLabelProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void RichTextLabelProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void RichTextLabelProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void RichTextLabelProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool RichTextLabelProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void RichTextLabelProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant RichTextLabelProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }
} // namespace sunaba::ui