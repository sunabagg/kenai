#ifndef SPIN_BOX_H
#define SPIN_BOX_H

#include <godot_cpp/classes/spin_box.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define SpinBoxNode godot::SpinBox

#include "range.h"
#include "line_edit.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindSpinBox(sol::state& lua);

    class SpinBox;

    class SpinBoxProxy : public SpinBoxNode {
        GDCLASS(SpinBoxProxy, SpinBoxNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to SpinBoxProxy
            }
        public:
            lucidware::ui::SpinBox* element = nullptr;

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
            void _draw() override;
            bool _can_drop_data(const Vector2& at_position, const Variant &data) const override;
            void _drop_data(const Vector2 &at_position, const Variant &data) override;
            Variant _get_drag_data(const Vector2 &at_position) override;
            Vector2 _get_minimum_size() const override;
            String _get_tooltip(const Vector2 &at_position) const override;
            void _gui_input(const Ref<InputEvent> &event) override;
            bool _has_point(const Vector2 &point) const override;
            //Object* _make_custom_tooltip(const String &for_text) const override;
            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
            void _value_changed(double value) override;
    };

    class SpinBox : public lucidware::ui::Range {
        private:
            SpinBoxNode* spinBox = nullptr; // Pointer to the SpinBox instance
            void connectSpinBoxSignals() {
                // Connect signals specific to SpinBox
            }

        public:
            SpinBox() {
                setSpinBox(memnew(SpinBoxNode));
                onInit();
            }

            SpinBox(SpinBoxNode* spinBox) {
                setSpinBox(spinBox);
            }

            SpinBoxNode* getSpinBox() {
                return spinBox;
            }
            
            void setSpinBox(SpinBoxNode* spinBox) {
                this->spinBox = spinBox;
                setRange(spinBox);
            }

            void setSpinBox(SpinBoxProxy* spinBox) {
                this->spinBox = spinBox;
                spinBox->element = this;
                setRange(spinBox);
            }

            int getAlignment() const {
                return spinBox->get_horizontal_alignment();
            }

            void setAlignment(int alignment) {
                spinBox->set_horizontal_alignment(static_cast<HorizontalAlignment>(alignment));
            }

            float getCustomArrowStep() const {
                return spinBox->get_custom_arrow_step();
            }

            void setCustomArrowStep(float step) {
                spinBox->set_custom_arrow_step(step);
            }

            bool isEditable() const {
                return spinBox->is_editable();
            }

            void setEditable(bool editable) {
                spinBox->set_editable(editable);
            }

            std::string getPrefix() const {
                return spinBox->get_prefix().utf8().get_data();
            }

            void setPrefix(const std::string& prefix) {
                spinBox->set_prefix(String(prefix.c_str()));
            }

            bool isSelectAllOnFocus() const {
                return spinBox->is_select_all_on_focus();
            }

            void setSelectAllOnFocus(bool select) {
                spinBox->set_select_all_on_focus(select);
            }

            int getSizeFlagsVertical() const {
                return spinBox->get_v_size_flags();
            }

            void setSizeFlagsVertical(int flags) {
                spinBox->set_v_size_flags(static_cast<ControlNode::SizeFlags>(flags));
            }

            float getStep() const {
                return spinBox->get_step();
            }

            void setStep(float step) {
                spinBox->set_step(step);
            }

            std::string getSuffix() const {
                return spinBox->get_suffix().utf8().get_data();
            }

            void setSuffix(const std::string& suffix) {
                spinBox->set_suffix(String(suffix.c_str()));
            }

            bool getUpdateOnTextChanged() const {
                return spinBox->get_update_on_text_changed();
            }

            void setUpdateOnTextChanged(bool update) {
                spinBox->set_update_on_text_changed(update);
            }

            void apply() {
                spinBox->apply();
            }

            LineEdit* getLineEdit() {
                return new LineEdit(spinBox->get_line_edit());
            }
    };
}

#endif // SPIN_BOX_H