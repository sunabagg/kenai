#ifndef SPIN_BOX_H
#define SPIN_BOX_H

#include <godot_cpp/classes/spin_box.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define SpinBoxNode godot::SpinBox

#include "range.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindSpinBox(sol::state& lua);

    class SpinBox;

    class SpinBoxProxy : public SpinBoxNode {
        public:
            sunaba::ui::SpinBox* element = nullptr;

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

    class SpinBox : public sunaba::ui::Range {
        private:
            SpinBoxNode* spinBox = nullptr; // Pointer to the SpinBox instance
            void connectSpinBoxSignals() {
                // Connect signals specific to SpinBox
            }

        public:
            SpinBox() {
                setSpinBox(memnew(SpinBoxProxy));
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
    };
}

#endif // SPIN_BOX_H