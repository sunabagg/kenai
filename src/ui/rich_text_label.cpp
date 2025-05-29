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
} // namespace sunaba::ui