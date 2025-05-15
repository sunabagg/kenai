#include "h_split_container.h"

namespace sunaba::ui {
    void HSplitContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
    
    void HSplitContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }
    
    void HSplitContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
    
    void HSplitContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void HSplitContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }
}