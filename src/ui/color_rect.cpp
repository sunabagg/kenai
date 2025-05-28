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
}