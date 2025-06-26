#include "confirmation_dialog.h"

namespace sunaba::desktop {
    void bindConfirmationDialog(sol::state& lua) {
        lua.new_usertype<ConfirmationDialog>("ConfirmationDialog",
            "new", sol::factories(
                [](){ return new ConfirmationDialog; }
            ),
            "cancelButtonText", sol::property(
                &ConfirmationDialog::getCancelButtonText,
                &ConfirmationDialog::setCancelButtonText
            )
        );
    }
}