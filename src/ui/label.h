#ifndef LABEL_H
#define LABEL_H

#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define LabelNode godot::Label

#include "control.h"

namespace sunaba::ui {
    void bindLabel(sol::state &lua);

    class LabelProxy : public LabelNode {
        public:
            sunaba::ui::Label* element = nullptr;

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
    };

    class Label : public Control {
        private:
            LabelNode* label_node = nullptr;

        public:
            Label() {
                setLabelNode(memnew(LabelProxy));
                onInit();
            }

            Label(LabelNode* label) {
                setLabelNode(label);
            }

            LabelNode* getLabelNode() {
                return label_node;
            }

            void setLabelNode(LabelNode* node) {
                label_node = node;
                setControl(label_node);
            }

            void setLabelNode(LabelProxy* node) {
                label_node = node;
                node->element = this;
                setControl(label_node);
            }


    };
}

#endif // LABEL_H