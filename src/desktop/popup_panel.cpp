#include "popup_panel.h"

namespace sunaba::desktop {
    void PopupPanelProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
}