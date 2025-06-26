#ifndef ACCEPT_DIALOG_H
#define ACCEPT_DIALOG_H

#include <godot_cpp/classes/accept_dialog.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define AcceptDialogNode godot::AcceptDialog

#include "window.h"

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
    };
}

#endif