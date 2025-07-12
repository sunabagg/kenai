#include "accept_dialog.h"

namespace kenai::desktop {
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
                []() { return new AcceptDialog(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, kenai::core::Viewport, Window>(),
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
            ),
            "canceled", sol::property(
                &AcceptDialog::getCanceledEvent,
                &AcceptDialog::setCanceledEvent
            ),
            "confirmed", sol::property(
                &AcceptDialog::getConfirmedEvent,
                &AcceptDialog::setConfirmedEvent
            ),
            "customAction", sol::property(
                &AcceptDialog::getCustomActionEvent,
                &AcceptDialog::setCustomActionEvent
            ),
            "addButton", sol::factories(
                [](AcceptDialog* e, std::string text) {
                    return e->addButton(text);
                },
                [](AcceptDialog* e, std::string text, bool right) {
                    return e->addButton(text, right);
                },
                [](AcceptDialog* e, std::string text, bool right, std::string action) {
                    return e->addButton(text, right, action);
                }
            ),
            "addCancelButton", &AcceptDialog::addCancelButton,
            "getLabel", &AcceptDialog::getLabel,
            "getOkButton", &AcceptDialog::getOkButton,
            "registerTextEnter", &AcceptDialog::registerTextEnter,
            "removeButton", &AcceptDialog::removeButton,
            "cast", [](Element* e) {
                auto* ce = dynamic_cast<AcceptDialog*>(e);
                if (ce != nullptr) {
                    return ce;
                }
                AcceptDialogNode* ad = Object::cast_to<AcceptDialogNode>(e->getNode());
                return new AcceptDialog(ad);
            }
        );
    }
}