#ifndef POPUP_PANEL_H
#define POPUP_PANEL_H

#include <godot_cpp/classes/popup_panel.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define PopupPanelNode godot::PopupPanel

#include "popup.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::desktop {
    void bindPopupPanel(sol::state& lua);

    class PopupPanel;

    class PopupPanelProxy : public PopupPanelNode {
        GDCLASS(PopupPanelProxy, PopupPanelNode)
        protected:
            static void _bind_methods() {}
        public:
            sunaba::desktop::PopupPanel* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;

            Vector2 _get_contents_minimum_size() const override;
    };

    class PopupPanel : public sunaba::desktop::Popup {
        private:
            PopupPanelNode* popup = nullptr; // Pointer to the Popup instance
            void connectPopupSignals() {
                // Connect signals specific to Popup
            }

        public:
            PopupPanel() {
                setPopupPanel(memnew(PopupPanelProxy));
                onInit();
            }

            PopupPanel(PopupPanelNode* popup) {
                setPopupPanel(popup);
                onInit();
            }

            PopupPanelNode* getPopup() const {
                return popup;
            }

            void setPopupPanel(PopupPanelNode* popup) {
                this->popup = popup;
                connectPopupSignals();
                setPopup(popup);
            }

            void setPopupPanel(PopupPanelProxy* popup) {
                this->popup = popup;
                popup->element = this;
                connectPopupSignals();
                setPopup(popup);
            }

            bool getTransparent() const {
                return popup->get_flag(godot::PopupPanel::Flags::FLAG_TRANSPARENT);
            }

            void setTransparent(bool transparent) {
                popup->set_flag(godot::PopupPanel::Flags::FLAG_TRANSPARENT, transparent);
            }

            bool getTransparaentBg() const {
                return popup->has_transparent_background();
            }

            void setTransparentBg(bool transparent) {
                popup->set_transparent_background(transparent);
            }
        };
} // namespace sunaba::desktop

#endif // POPUP_PANEL_H