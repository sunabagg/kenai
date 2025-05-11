#include "panel.h"

namespace sunaba::ui {
    void PanelProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void PanelProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void PanelProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void PanelProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }
}