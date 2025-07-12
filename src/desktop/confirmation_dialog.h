#ifndef CONFIRMATION_DIALOG_H
#define CONFIRMATION_DIALOG_H   

#include <godot_cpp/classes/confirmation_dialog.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ConfirmationDialogNode godot::ConfirmationDialog

#include "accept_dialog.h"

using namespace godot;
using namespace kenai::core;

namespace kenai::desktop {
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

            std::string getCancelButtonText() {
                return confirmDialog->get_cancel_button_text().utf8().get_data();
            }

            void setCancelButtonText(std::string value) {
                confirmDialog->set_cancel_button_text(value.c_str());
            }

            kenai::ui::Button* getCancelButton() {
                return new kenai::ui::Button(confirmDialog->get_cancel_button());
            }
    };
}

#endif