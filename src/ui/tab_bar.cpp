#include "tab_bar.h"

namespace sunaba::ui {
    void TabBarProxy::_enter_tree() {
        if (element) {
            element->onEnterTree();
        }
    }
} // namespace sunaba::ui