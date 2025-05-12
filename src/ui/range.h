#ifndef RANGE_H
#define RANGE_H

#include <godot_cpp/classes/range.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define RangeNode godot::Range

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindRange(sol::state& lua);

    class Range;
    class RangeProxy : public RangeNode {
        public:
            sunaba::ui::Range* element = nullptr;

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

    class Range : public sunaba::ui::Control {
        private:
            RangeNode* range = nullptr; // Pointer to the Range instance
            void connectRangeSignals() {
                // Connect signals specific to Range
            }

        public:
            Range() {
                setRange(memnew(RangeProxy));
                onInit();
            }

            Range(RangeNode* r_node) {
                setRange(r_node);
                onInit();
            }

            RangeNode* getRange() {
                return range;
            }

            void setRange(RangeNode* r_node) {
                range = r_node;
                connectRangeSignals();
                setControl(r_node);
            }

            void setRange(RangeProxy* r_node) {
                range = r_node;
                r_node->element = this;
                connectRangeSignals();
                setControl(r_node);
            }

            bool getAllowGreater() {
                return range->is_greater_allowed();
            }

            void setAllowGreater(bool allow) {
                range->set_allow_greater(allow);
            }

            bool getAllowLesser() {
                return range->is_lesser_allowed();
            }

            void setAllowLesser(bool allow) {
                range->set_allow_lesser(allow);
            }
    };
}

#endif // RANGE_H