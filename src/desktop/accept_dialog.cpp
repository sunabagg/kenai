#include "accept_dialog.h"

namespace sunaba::desktop {
    void AcceptDialogSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("canceled"), &AcceptDialogSignalWrapper::canceled);
        ClassDB::bind_method(D_METHOD("confirmed"), &AcceptDialogSignalWrapper::confirmed);
        ClassDB::bind_method(D_METHOD("custom_action", "action"), &AcceptDialogSignalWrapper::custom_action);
    }

    void AcceptDialogSignalWrapper::canceled() {
        if (element != nullptr) {
            Array args;
            element->canceledEvent->emit(args);
        }
    }

    void AcceptDialogSignalWrapper::confirmed() {
        if (element != nullptr) {
            Array args;
            element->confirmedEvent->emit(args);
        }
    }
}