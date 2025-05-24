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

} // namespace sunaba::ui