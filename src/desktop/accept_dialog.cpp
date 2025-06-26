#include "accept_dialog.h"

namespace sunaba::desktop {
    void AcceptDialogSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("canceled"), &AcceptDialogSignalWrapper::canceled);
    }
}