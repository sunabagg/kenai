#ifndef POPUP_H
#define POPUP_H

#include <godot_cpp/classes/popup.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define PopupNode godot::Popup

#include "window.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::desktop {
    void bindPopup(sol::state &lua);

    class Popup;

    class PopupProxy : public PopupNode {
        GDCLASS(PopupProxy, PopupNode)
        protected:
            static void _bind_methods() {}
        public:
            sunaba::desktop::Popup* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override ;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;

            Vector2 _get_contents_minimum_size() const override;
    };

    class PopupSignalWrapper : public Object {
        GDCLASS(PopupSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            sunaba::desktop::Popup* element = nullptr;

            PopupSignalWrapper() = default;
            ~PopupSignalWrapper() = default;

            void popup_hide();
    };

    class Popup : public sunaba::desktop::Window {
        private:
            PopupNode* popup = nullptr; // Pointer to the Popup instance
            PopupSignalWrapper* popupSignalWrapper = nullptr;
            void connectPopupSignals() {
                // Connect signals specific to Popup
                if (this->popupSignalWrapper == nullptr) {
                    this->popupSignalWrapper = memnew(PopupSignalWrapper);
                    this->popupSignalWrapper->element = this;
                }

                this->popup->connect("popup_hide", Callable(this->popupSignalWrapper, "popup_hide"));
            }

        public:
            Popup() {
                setPopup(memnew(PopupNode));
                onInit();
            }

            Popup(PopupNode* popup) {
                setPopup(popup);
                onInit();
            }

            PopupNode* getPopup() {
                return popup;
            }

            void setPopup(PopupNode* popup) {
                this->popup = popup;
                connectPopupSignals();
                setViewport(popup);
            }

            bool getBorderless() const {
                return popup->get_flag(godot::Popup::Flags::FLAG_BORDERLESS);
            }

            void setBorderless(bool borderless) {
                popup->set_flag(godot::Popup::Flags::FLAG_BORDERLESS, borderless);
            }

            bool getPopupWindow() const {
                return popup->get_flag(godot::Popup::Flags::FLAG_POPUP);
            }

            void setPopupWindow(bool p_popup) {
                popup->set_flag(godot::Popup::Flags::FLAG_POPUP, p_popup);
            }

            bool getTransient() const {
                return popup->is_transient();
            }

            void setTransient(bool transient) {
                popup->set_transient(transient);
            }

            bool getUnresizable() const {
                return popup->get_flag(godot::Popup::Flags::FLAG_RESIZE_DISABLED);
            }

            void setUnresizable(bool unresizable) {
                popup->set_flag(godot::Popup::Flags::FLAG_RESIZE_DISABLED, unresizable);
            }

            bool getWrapControls() const {
                return popup->is_wrapping_controls();
            }

            void setWrapControls(bool wrap) {
                popup->set_wrap_controls(wrap);
            }

            Event* popupHideEvent = new Event();
            Event* getPopupHideEvent() {
                return popupHideEvent;
            }
            void setPopupHideEvent(Event* event) {
                popupHideEvent = event;
            }

            void onFree() override {
                if (popupSignalWrapper) {
                    memdelete(popupSignalWrapper);
                    popupSignalWrapper = nullptr;
                }
                popup = nullptr;
                sunaba::desktop::Window::onFree();
            }
    };
}

#endif // POPUP_H