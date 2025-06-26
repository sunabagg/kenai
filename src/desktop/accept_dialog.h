#ifndef ACCEPT_DIALOG_H
#define ACCEPT_DIALOG_H

#include <godot_cpp/classes/accept_dialog.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define AcceptDialogNode godot::AcceptDialog

#include "window.h"
#include "../ui/button.h"
#include "../ui/label.h"
#include "../ui/line_edit.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::desktop {
    void bindAcceptDialog(sol::state& lua);
    
    class AcceptDialog;

    class AcceptDialogSignalWrapper : public Object {
        GDCLASS(AcceptDialogSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            sunaba::desktop::AcceptDialog* element = nullptr;

            AcceptDialogSignalWrapper() = default;
            ~AcceptDialogSignalWrapper() = default;

            void canceled();
            void confirmed();
            void custom_action(const StringName& action);
    };

    class AcceptDialog : public Window {
        private:
            AcceptDialogNode* acceptDialog = nullptr;
            AcceptDialogSignalWrapper* signalWrapper = nullptr;
        
            void connectAcceptDialogSignals() {
                if (this->signalWrapper == nullptr) {
                    signalWrapper == memnew(AcceptDialogSignalWrapper);
                    signalWrapper->element = this;
                }

                acceptDialog->connect("canceled", Callable(signalWrapper, "canceled"));
                acceptDialog->connect("confirmed", Callable(signalWrapper, "confirmed"));
                acceptDialog->connect("custom_action", Callable(signalWrapper, "custom_action"));
            }
        public:

            AcceptDialog() {
                setAcceptDialog(memnew(AcceptDialogNode));
                onInit();
            }

            AcceptDialog(AcceptDialogNode* node) {
                setAcceptDialog(node);
            }

            AcceptDialogNode* getAcceptDialog() {
                return acceptDialog;
            }

            void setAcceptDialog(AcceptDialogNode* aDialog) {
                acceptDialog = aDialog;
                connectAcceptDialogSignals();
                setWindow(aDialog);
            }

            bool getDialogAutowrap() {
                return acceptDialog->has_autowrap();
            }

            void setDialogAutowrap(bool value) {
                acceptDialog->set_autowrap(value);
            } 

            bool getDialogCloseOnEscape() {
                return acceptDialog->get_close_on_escape();
            }

            void setDialogCLoseOnEscape(bool value) {
                acceptDialog->set_close_on_escape(value);
            }

            bool getDialogHideOnOk() {
                return acceptDialog->get_hide_on_ok();
            }

            void setDialogHideOnOk(bool value) {
                acceptDialog->set_hide_on_ok(value);
            }

            std::string getDialogText() {
                return acceptDialog->get_text().utf8().get_data();
            }

            void setDialogText(std::string value) {
                acceptDialog->set_text(value.c_str());
            }

            std::string getOkButtonText() {
                return acceptDialog->get_ok_button_text().utf8().get_data();
            }

            void setOkButtonText(std::string value) {
                acceptDialog->set_ok_button_text(value.c_str());
            }

            Event* canceledEvent = new Event();
            Event* getCanceledEvent() {
                return canceledEvent;
            }
            void setCanceledEvent(Event* event) {
                canceledEvent = event;
            }

            Event* confirmedEvent = new Event();
            Event* getConfirmedEvent() {
                return confirmedEvent;
            }
            void setConfirmedEvent(Event* event) {
                confirmedEvent = event;
            }

            Event* customActionEvent = new Event();
            Event* getCustomActionEvent() {
                return customActionEvent;
            }
            void setCustomActionEvent(Event* event) {
                customActionEvent = event;
            }

            sunaba::ui::Button* addButton(std::string text, bool right = false, std::string action = "") {
                return new sunaba::ui::Button(acceptDialog->add_button(text.c_str(), right, action.c_str()));
            }

            sunaba::ui::Button* addCancelButton(std::string name) {
                return new sunaba::ui::Button(acceptDialog->add_cancel_button(name.c_str()));
            }

            sunaba::ui::Label* getLabel() {
                return new sunaba::ui::Label(acceptDialog->get_label());
            }

            sunaba::ui::Button* getOkButton() {
                return new sunaba::ui::Button(acceptDialog->get_ok_button());
            }

            void registerTextEnter(sunaba::ui::LineEdit* lineEdit) {
                acceptDialog->register_text_enter(lineEdit->getLineEditNode());
            }

            void removeButton(sunaba::ui::Button* button) {
                acceptDialog->remove_button(button->getButton());
            }
    };
}

#endif