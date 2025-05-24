#include "texture_button.h"

namespace sunaba::ui {

    void TextureButtonProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TextureButtonProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TextureButtonProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void TextureButtonProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void TextureButtonProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void TextureButtonProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void TextureButtonProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void TextureButtonProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void TextureButtonProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void TextureButtonProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool TextureButtonProxy::_can_drop_data(const Vector2& at_position, const Variant& data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void TextureButtonProxy::_drop_data(const Vector2& at_position, const Variant& data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant TextureButtonProxy::_get_drag_data(const Vector2& at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

} // namespace sunaba::ui