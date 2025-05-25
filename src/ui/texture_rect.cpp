#include "texture_rect.h"

namespace sunaba::ui {

    void TextureRectProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TextureRectProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TextureRectProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void TextureRectProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void TextureRectProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void TextureRectProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void TextureRectProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void TextureRectProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void TextureRectProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void TextureRectProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }
    
    bool TextureRectProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (this->element != nullptr) {
            return this->element->_can_drop_data(at_position, data);
        }
        return false;
    }
}