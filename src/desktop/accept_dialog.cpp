#include "accept_dialog.h"

namespace sunaba::desktop {
    void AcceptDialogSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("canceled"), &AcceptDialogSignalWrapper::canceled);
        ClassDB::bind_method(D_METHOD("confirmed"), &AcceptDialogSignalWrapper::confirmed);
        ClassDB::bind_method(D_METHOD("custom_action", "action"))
    }
}