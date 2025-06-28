#include "confirmation_dialog.h"

namespace sunaba::desktop {
    void bindConfirmationDialog(sol::state& lua) {
        lua.new_usertype<ConfirmationDialog>("ConfirmationDialog",
            "new", sol::factories(
                [](){ return new ConfirmationDialog; }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::Viewport, Window, AcceptDialog>(),
            "cancelButtonText", sol::property(
                &ConfirmationDialog::getCancelButtonText,
                &ConfirmationDialog::setCancelButtonText
            ),
            "getCancelButton", &ConfirmationDialog::getCancelButton,
            "cast", [](Element* e) {
                auto* ce = dynamic_cast<ConfirmationDialog*>(e);
                if (ce != nullptr) {
                    return ce;
                }
                ConfirmationDialogNode* node = Object::cast_to<ConfirmationDialogNode>(e->getNode());
                return new ConfirmationDialog(node);
            }
        );
    }
}