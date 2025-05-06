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

    void PopupPanelProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void PopupPanelProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }
}