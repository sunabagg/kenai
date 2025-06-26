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

    void AcceptDialogSignalWrapper::custom_action(const StringName& action) {
        if (element != nullptr) {
            Array args;
            String actionGdStr = action;
            args.append(action);
            element->customActionEvent->emit(args);
        }
    }

    void bindAcceptDialog(sol::state& lua) {
        lua.new_usertype<AcceptDialog>("AcceptDialog",
            "new", sol::factories(
                []() { return new Window(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::Viewport, Window>(),
            "dialogAutowrap", sol::property(
                &AcceptDialog::getDialogAutowrap,
                &AcceptDialog::setDialogAutowrap
            ),
            "dialogCloseOnEscape", sol::property(
                &AcceptDialog::getDialogCloseOnEscape,
                &AcceptDialog::setDialogCloseOnEscape
            ),
            "dialogHideOnOk", sol::property(
                &AcceptDialog::getDialogHideOnOk,
                &AcceptDialog::setDialogHideOnOk
            ),
            "dialogText", sol::property(
                &AcceptDialog::getDialogText,
                &AcceptDialog::setDialogText
            ),
            "okButtonText", sol::property(
                &AcceptDialog::getOkButtonText,
                &AcceptDialog::setOkButtonText
            )
        );
    }
}