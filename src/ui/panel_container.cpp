#include "panel_container.h"

namespace sunaba::ui {
    void PanelContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
    
    void PanelContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }
    
    void PanelContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
    
    void PanelContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void PanelContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }
}