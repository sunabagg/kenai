#include "nine_patch_rect.h"

namespace sunaba::ui {
    void NinePatchRectProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void NinePatchRectProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void NinePatchRectProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void NinePatchRectProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }
}