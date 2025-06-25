#ifndef SEPARATOR_H
#define SEPARATOR_H

#include <godot_cpp/classes/separator.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define SeparatorNode godot::Separator

#include "control.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::ui {
    void bindSeparator(sol::state& lua);

    class Separator;
    
    class SeparatorProxy : public SeparatorNode {
        GDCLASS(SeparatorProxy, SeparatorNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to SeparatorProxy
            }
        public:
            lucidfx::ui::Separator* element = nullptr;

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

    class Separator : public lucidfx::ui::Control {
        private:
            SeparatorNode* separator = nullptr; // Pointer to the Separator instance

            void connectSeparatorSignals() {
                // Connect signals specific to Separator
            }

        public:
            Separator() {
                setSeparator(memnew(SeparatorNode));
                onInit();
            }

            Separator(SeparatorNode* separator) {
                this->separator = separator;
                setControl(separator);
            }

            SeparatorNode* getSeparator() {
                return separator;
            }

            void setSeparator(SeparatorNode* separator) {
                this->separator = separator;
                setControl(separator);
            }

            void setSeparator(SeparatorProxy* separator) {
                this->separator = separator;
                separator->element = this;
                setControl(separator);
            }
    };
}

#endif // SEPARATOR_H