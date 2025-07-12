#ifndef OPTION_BUTTON_H
#define OPTION_BUTTON_H

#include <godot_cpp/classes/option_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define OptionButtonNode godot::OptionButton

#include "button.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"
#include "../core/texture2d.h"
#include "../desktop/popup_menu.h"

using namespace godot;
using namespace kenai::core;

namespace kenai::ui {
    void bindOptionButton(sol::state& lua);

    class OptionButton;

    class OptionButtonProxy : public OptionButtonNode {
        GDCLASS(OptionButtonProxy, OptionButtonNode)
        protected:
            static void _bind_methods() {
                // Binding methods for OptionButtonProxy
            }
        public:
            kenai::ui::OptionButton* element = nullptr;

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override ;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;

            void _draw() override;

            bool _can_drop_data(const Vector2& at_position, const Variant &data) const override;

            void _drop_data(const Vector2 &at_position, const Variant &data) override;

            Variant _get_drag_data(const Vector2 &at_position) override;

            Vector2 _get_minimum_size() const override;

            String _get_tooltip(const Vector2 &at_position) const override;

            void _gui_input(const Ref<InputEvent> &event) override;

            bool _has_point(const Vector2 &point) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;

            void _pressed() override;

            void _toggled(bool p_toggled_on) override;
    };

    class OptionButtonSignalWrapper : public Object {
        GDCLASS(OptionButtonSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            kenai::ui::OptionButton* element = nullptr;

            OptionButtonSignalWrapper() = default;
            ~OptionButtonSignalWrapper() = default;

            void item_focused(int index);
            void item_selected(int index);
    };

    class OptionButton : public kenai::ui::Button {
        private:
            OptionButtonNode* optionButton = nullptr;

            OptionButtonSignalWrapper* optionButtonSignalWrapper = nullptr;
            void connectOptionButtonSignals() {
                // Connect signals specific to OptionButton
                if (this->optionButtonSignalWrapper == nullptr) {
                    this->optionButtonSignalWrapper = memnew(OptionButtonSignalWrapper);
                    this->optionButtonSignalWrapper->element = this;
                }
                this->optionButton->connect("item_focused", Callable(this->optionButtonSignalWrapper, "item_focused"));
                this->optionButton->connect("item_selected", Callable(this->optionButtonSignalWrapper, "item_selected"));
            }

        public:
            // Constructor with Node* parameter
            OptionButton() {
                setOptionButton(memnew(OptionButtonNode));
                onInit();
            }

            OptionButton(OptionButtonNode* p_node) {
                setOptionButton(p_node);
            }

            OptionButtonNode* getOptionButton() {
                return optionButton;
            }

            void setOptionButton(OptionButtonNode* optionButton) {
                this->optionButton = optionButton;
                connectOptionButtonSignals();
                setButton(optionButton);
            }

            void setOptionButton(OptionButtonProxy* optionButton) {
                this->optionButton = optionButton;
                optionButton->element = this;
                connectOptionButtonSignals();
                setButton(optionButton);
            }

            int getActionMode() {
                return optionButton->get_action_mode();
            }

            void setActionMode(int mode) {
                optionButton->set_action_mode(static_cast<godot::OptionButton::ActionMode>(mode));
            }

            int getAlignment() {
                return optionButton->get_text_alignment();
            }

            void setAlignment(int alignment) {
                optionButton->set_text_alignment(static_cast<godot::HorizontalAlignment>(alignment));
            }

            bool getAllowReselect() {
                return optionButton->get_allow_reselect();
            }

            void setAllowReselect(bool enabled) {
                optionButton->set_allow_reselect(enabled);
            }

            bool isFitToLongestItem() {
                return optionButton->is_fit_to_longest_item();
            }

            void setFitToLongestItem(bool enabled) {
                optionButton->set_fit_to_longest_item(enabled);
            }

            int getItemCount() const {
                return optionButton->get_item_count();
            }

            void setItemCount(int32_t p_count) {
                optionButton->set_item_count(p_count);
            }

            int getSelected() const {
                return optionButton->get_selected();
            }

            void setSelected(int32_t p_idx) {
                optionButton->select(p_idx);
            }

            bool isToggleMode() {
                return optionButton->is_toggle_mode();
            }

            void setToggleMode(bool enabled) {
                optionButton->set_toggle_mode(enabled);
            }

            Event* itemFocusedEvent = new Event();
            Event* getItemFocusedEvent() {
                return itemFocusedEvent;
            }
            void setItemFocusedEvent(Event* event) {
                itemFocusedEvent = event;
            }

            Event* itemSelectedEvent = new Event();
            Event* getItemSelectedEvent() {
                return itemSelectedEvent;
            }
            void setItemSelectedEvent(Event* event) {
                itemSelectedEvent = event;
            }

            void addIconItem(kenai::core::Texture2D* texture, std::string label, int32_t id = -1) {
                Ref<godot::Texture2D> textureRef = Ref<godot::Texture2D>(texture->getTexture());
                optionButton->add_icon_item(textureRef, String(label.c_str()), id);
            }

            void addItem(std::string label, int32_t id = -1) {
                optionButton->add_item(String(label.c_str()), id);
            }

            void addSeparator(std::string text = "") {
                optionButton->add_separator(String(text.c_str()));
            }

            void clear() {
                optionButton->clear();
            }

            kenai::core::Texture2D* getItemIcon(int32_t p_idx) const {
                return new kenai::core::Texture2D(optionButton->get_item_icon(p_idx).ptr());
            }

            int getItemId(int32_t p_idx) const {
                return optionButton->get_item_id(p_idx);
            }

            int getItemIndex(int32_t p_id) const {
                return optionButton->get_item_index(p_id);
            }

            Variant getItemMetadata(int32_t p_idx) const {
                return optionButton->get_item_metadata(p_idx);
            }

            std::string getItemText(int32_t p_idx) const {
                return String(optionButton->get_item_text(p_idx)).utf8().get_data();
            }

            std::string getItemTooltip(int32_t p_idx) const {
                return String(optionButton->get_item_tooltip(p_idx)).utf8().get_data();
            }

            kenai::desktop::PopupMenu* getPopup() const {
                return new kenai::desktop::PopupMenu(optionButton->get_popup());
            }

            int getSelectableItem(bool p_from_last = false) const {
                return optionButton->get_selectable_item(p_from_last);
            }

            int getSelectedId() const {
                return optionButton->get_selected_id();
            }

            Variant getSelectedMetadata() const {
                return optionButton->get_selected_metadata();
            }

            bool hasSelectableItems() const {
                return optionButton->has_selectable_items();
            }

            bool isItemDisabled(int32_t p_idx) const {
                return optionButton->is_item_disabled(p_idx);
            }

            void removeItem(int32_t p_idx) {
                optionButton->remove_item(p_idx);
            }

            void select(int32_t p_idx) {
                optionButton->select(p_idx);
            }

            void setDisableShortcuts(bool p_disabled) {
                optionButton->set_disable_shortcuts(p_disabled);
            }

            void setItemDisabled(int32_t p_idx, bool p_disabled) {
                optionButton->set_item_disabled(p_idx, p_disabled);
            }

            void setItemIcon(int32_t p_idx, kenai::core::Texture2D* texture) {
                Ref<godot::Texture2D> textureRef = Ref<godot::Texture2D>(texture->getTexture());
                optionButton->set_item_icon(p_idx, textureRef);
            }

            void setItemId(int32_t p_idx, int32_t p_id) {
                optionButton->set_item_id(p_idx, p_id);
            }

            void setItemMetadata(int32_t p_idx, const Variant &p_metadata) {
                optionButton->set_item_metadata(p_idx, p_metadata);
            }

            void setItemText(int32_t p_idx, std::string text) {
                optionButton->set_item_text(p_idx, String(text.c_str()));
            }

            void setItemTooltip(int32_t p_idx, std::string text) {
                optionButton->set_item_tooltip(p_idx, String(text.c_str()));
            }

            void showPopup() {
                optionButton->show_popup();
            }

            void onFree() override {
                if (optionButtonSignalWrapper) {
                    memdelete(optionButtonSignalWrapper);
                    optionButtonSignalWrapper = nullptr;
                }
                BaseButton::onFree();
            }
    };
}

#endif // OPTION_BUTTON_H