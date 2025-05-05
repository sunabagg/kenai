#include "window.h"

namespace sunaba::desktop {
    void WindowProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
}