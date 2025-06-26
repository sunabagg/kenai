#ifndef CONFIRMATION_DIALOG_H
#define CONFIRMATION_DIALOG_H   

#include <godot_cpp/classes/confirmation_dialog.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ConfirmationDialogNode godot::ConfirmationDialog

#include "accept_dialog.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::desktop {
    void bindConfirmationDialog(sol::state& lua);

    class ConfirmationDialog : public AcceptDialog {
        private:
            ConfirmationDialogNode* confirmDialog = nullptr;
        public:
            ConfirmationDialog() {
                setConfirmationDialog(memnew(ConfirmationDialogNode));
                onInit();
            }

            ConfirmationDialog(ConfirmationDialogNode* node) {
                setConfirmationDialog(node);
            }

            ConfirmationDialogNode* getConfirmationDialog() {
                return confirmDialog;
            }

            void setConfirmationDialog(ConfirmationDialogNode* node) {
                confirmDialog = node;
                setAcceptDialog(node);
            }
    };
}

#endif