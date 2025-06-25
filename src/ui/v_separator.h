#ifndef V_SEPARATOR_H
#define V_SEPARATOR_H

#include <godot_cpp/classes/v_separator.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define VSeparatorNode godot::VSeparator

#include "separator.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::ui {
    void bindVSeparator(sol::state& lua);

    class VSeparator;

    class VSeparatorProxy : public VSeparatorNode {
        GDCLASS(VSeparatorProxy, VSeparatorNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to VSeparatorProxy
            }
        public:
            lucidfx::ui::VSeparator* element = nullptr;

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

    class VSeparator : public lucidfx::ui::Separator {
        private:
            VSeparatorNode* vSeparator = nullptr; // Pointer to the VSeparator instance

            void connectVSeparatorSignals() {
                // Connect signals specific to VSeparator
            }

        public:
            VSeparator() {
                setVSeparator(memnew(VSeparatorNode));
                onInit();
            }

            VSeparator(VSeparatorNode* vSeparator) {
                this->vSeparator = vSeparator;
            }

            VSeparatorNode* getVSeparator() {
                return vSeparator;
            }

            void setVSeparator(VSeparatorNode* vSeparator) {
                this->vSeparator = vSeparator;
                setSeparator(vSeparator);
            }

            void setVSeparator(VSeparatorProxy* vSeparator) {
                this->vSeparator = vSeparator;
                vSeparator->element = this;
                setSeparator(vSeparator);
            }
    };
}

#endif // V_SEPARATOR_H