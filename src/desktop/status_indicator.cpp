#include "status_indicator.h"

namespace sunaba::desktop {
    void StatusIndicatorSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("pressed", "mouse_button", "mouse_position"), &StatusIndicatorSignalWrapper::pressed);
    }
}