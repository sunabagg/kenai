#ifndef LINE_EDIT_H
#define LINE_EDIT_H

#include <godot_cpp/classes/line_edit.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define LineEditNode godot::LineEdit

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindLineEdit(sol::state &lua);

    class LineEdit;

    class LineEditProxy : public LineEditNode {
        public:
            sunaba::ui::LineEdit* element = nullptr;

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

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
    };

    class LineEdit : public Control {
        private:
            LineEditNode* line_edit_node = nullptr;

            void connectLineEditSignals() {
                // Connect signals specific to LineEdit
            }

        public:
            LineEdit() {
                setLineEditNode(memnew(LineEditProxy));
                onInit();
            }

            LineEdit(LineEditNode* line_edit) {
                setLineEditNode(line_edit);
                onInit();
            }

            void setLineEditNode(LineEditNode* line_edit) {
                line_edit_node = line_edit;
                connectLineEditSignals();
                setControl(line_edit_node);
            }

            void setLineEditNode(LineEditProxy* line_edit) {
                line_edit_node = line_edit;
                line_edit->element = this;
                connectLineEditSignals();
                setControl(line_edit_node);
            }

            LineEditNode* getLineEditNode() {
                return line_edit_node;
            }
    };
}

#endif // LINE_EDIT_H