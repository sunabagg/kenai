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

            void _value_changed(double value) override;
    };

    class RangeSignalWrapper : public Object {
        GDCLASS(RangeSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            sunaba::ui::Range* element = nullptr;

            RangeSignalWrapper() = default;
            ~RangeSignalWrapper() = default;

            void changed();
            void value_changed(double value);
    };

    class Range : public sunaba::ui::Control {
        private:
            RangeNode* range = nullptr; // Pointer to the Range instance

            RangeSignalWrapper* rangeSignalWrapper = nullptr;
            void connectRangeSignals() {
                // Connect signals specific to Range
                SignalFunc changedFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.push_back(av[i]);
                    }
                    if (changedEvent != nullptr) {
                        changedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable changedCallable = to_callable(changedFunc);
                range->connect("changed", changedCallable);
                SignalFunc valueChangedFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.push_back(av[i]);
                    }
                    if (valueChangedEvent != nullptr) {
                        valueChangedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable valueChangedCallable = to_callable(valueChangedFunc);
                range->connect("value_changed", valueChangedCallable);
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

            bool getExpEdit() {
                return range->is_ratio_exp();
            }

            void setExpEdit(bool exp) {
                range->set_exp_ratio(exp);
            }

            float getMaxValue() {
                return range->get_max();
            }

            void setMaxValue(float value) {
                range->set_max(value);
            }

            float getMinValue() {
                return range->get_min();
            }

            void setMinValue(float value) {
                range->set_min(value);
            }

            float getPage() {
                return range->get_page();
            }

            void setPage(float value) {
                range->set_page(value);
            }

            float getRatio() {
                return range->get_as_ratio();
            }

            void setRatio(float value) {
                range->set_as_ratio(value);
            }

            bool getRounded() {
                return range->is_using_rounded_values();
            }

            void setRounded(bool rounded) {
                range->set_use_rounded_values(rounded);
            }

            int getSizeFlagsVertical() {
                return range->get_v_size_flags();
            }

            void setSizeFlagsVertical(int flags) {
                range->set_v_size_flags(static_cast<godot::Control::SizeFlags>(flags));
            }

            float getStep() {
                return range->get_step();
            }

            void setStep(float value) {
                range->set_step(value);
            }

            float getValue() {
                return range->get_value();
            }

            void setValue(float value) {
                range->set_value(value);
            }

            Event* changedEvent;
            Event* getChangedEvent() {
                return changedEvent;
            }
            void setChangedEvent(Event* event) {
                changedEvent = event;
            }
            Event* valueChangedEvent;
            Event* getValueChangedEvent() {
                return valueChangedEvent;
            }
            void setValueChangedEvent(Event* event) {
                valueChangedEvent = event;
            }

            void valueChanged(double value) {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["valueChanged"].get<sol::function>();
                    if (func) {
                        func(scriptInstance, value);
                    }
                }
            }

            void setValueNoSignal(double value) {
                range->set_value_no_signal(value);
            }

            void share(Element* with) {
                range->share(with->getNode());
            }

            void unshare() {
                range->unshare();
            }
    };
}

#endif // RANGE_H