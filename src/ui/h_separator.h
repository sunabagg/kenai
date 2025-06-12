#ifndef H_SEPARATOR_H
#define H_SEPARATOR_H

#include <godot_cpp/classes/h_separator.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define HSeparatorNode godot::HSeparator

#include "separator.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindHSeparator(sol::state& lua);

    class HSeparator;

    class HSeparatorProxy : public HSeparatorNode {
        GDCLASS(HSeparatorProxy, HSeparatorNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to HSeparatorProxy
            }
        public:
            sunaba::ui::HSeparator* element = nullptr;

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

    class HSeparator : public sunaba::ui::Separator {
        private:
            HSeparatorNode* hSeparator = nullptr; // Pointer to the HSeparator instance

        public:
            HSeparator() {
                setHSeparator(memnew(HSeparatorProxy));
                onInit();
            }

            HSeparator(HSeparatorNode* hSeparator) {
                this->hSeparator = hSeparator;
            }

            HSeparatorNode* getHSeparator() {
                return hSeparator;
            }

            void setHSeparator(HSeparatorNode* hSeparator) {
                this->hSeparator = hSeparator;
                setSeparator(hSeparator);
            }

            void setHSeparator(HSeparatorProxy* hSeparator) {
                this->hSeparator = hSeparator;
                hSeparator->element = this;
                setSeparator(hSeparator);
            }
    };
}

#endif