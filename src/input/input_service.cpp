#include "input_service.h"

namespace sunaba::input {
    void InputServiceSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("joy_connection_changed", "device", "connected"), &InputServiceSignalWrapper::joy_connection_changed);
    }
}