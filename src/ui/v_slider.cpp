#include "v_slider.h"

namespace sunaba::ui {
    void VSliderProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void VSliderProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void VSliderProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
}