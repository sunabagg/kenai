#include "popup_panel.h"

namespace sunaba::desktop {
    void PopupPanelProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void PopupPanelProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void PopupPanelProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void PopupPanelProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }
}