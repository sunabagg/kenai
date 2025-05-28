#include "color_rect.h"

namespace sunaba::ui {
    void sunaba::ui::ColorRectProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void sunaba::ui::ColorRectProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void sunaba::ui::ColorRectProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void sunaba::ui::ColorRectProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void sunaba::ui::ColorRectProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }
}