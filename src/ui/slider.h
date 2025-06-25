#ifndef SLIDER_H
#define SLIDER_H

#include <godot_cpp/classes/slider.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define SliderNode godot::Slider

#include "range.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindSlider(sol::state &lua);

    class Slider;

    class SliderProxy : public SliderNode {
        GDCLASS(SliderProxy, SliderNode)
        protected:
            static void _bind_methods() {}
        public:
            lucidware::ui::Slider* element = nullptr;

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

    class SliderSignalWrapper : public Object {
        GDCLASS(SliderSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            lucidware::ui::Slider* element = nullptr;

            SliderSignalWrapper() = default;
            ~SliderSignalWrapper() = default;

            void drag_ended(bool value_changed);
            void drag_started();
    };

    class Slider : public lucidware::ui::Range {
        private:
            SliderNode* slider = nullptr; // Pointer to the Slider instance
            SliderSignalWrapper* sliderSignalWrapper = nullptr;
            void connectSliderSignals() {
                // Connect signals specific to Slider
                if (this->sliderSignalWrapper == nullptr) {
                    this->sliderSignalWrapper = memnew(SliderSignalWrapper);
                    this->sliderSignalWrapper->element = this;
                }

                this->slider->connect("drag_ended", Callable(this->sliderSignalWrapper, "drag_ended"));
                this->slider->connect("drag_started", Callable(this->sliderSignalWrapper, "drag_started"));
            }

        public:
            Slider() {
                setRange(memnew(SliderNode));
                onInit();
            }

            Slider(SliderNode* slider) {
                setRange(slider);
            }

            SliderNode* getSlider() {
                return slider;
            }

            void setSlider(SliderNode* node) {
                slider = node;
                connectSliderSignals();
                setControl(slider);
            }

            void setSlider(SliderProxy* node) {
                slider = node;
                node->element = this;
                connectSliderSignals();
                setControl(node);
            }

            bool isEditable() {
                return slider->is_editable();
            }

            void setEditable(bool editable) {
                slider->set_editable(editable);
            }

            int getFocusMode() {
                return slider->get_focus_mode();
            }

            void setFocusMode(int mode) {
                slider->set_focus_mode(static_cast<ControlNode::FocusMode>(mode));
            }

            bool getScrollable() {
                return slider->is_scrollable();
            }

            void setScrollable(bool scrollable) {
                slider->set_scrollable(scrollable);
            }

            float getStep() {
                return slider->get_step();
            }

            void setStep(float value) {
                slider->set_step(value);
            }

            int getTickCount() {
                return slider->get_ticks();
            }

            void setTickCount(int count) {
                slider->set_ticks(count);
            }

            bool getTicksOnBorders() {
                return slider->get_ticks_on_borders();
            }

            void setTicksOnBorders(bool ticks_on_borders) {
                slider->set_ticks_on_borders(ticks_on_borders);
            }

            Event* dragEndedEvent = new Event();
            Event* getDragEndedEvent() {
                return dragEndedEvent;
            }
            void setDragEndedEvent(Event* event) {
                dragEndedEvent = event;
            }

            Event* dragStartedEvent = new Event();
            Event* getDragStartedEvent() {
                return dragStartedEvent;
            }
            void setDragStartedEvent(Event* event) {
                dragStartedEvent = event;
            }

            void onFree() override {
                if (sliderSignalWrapper) {
                    sliderSignalWrapper->element = nullptr;
                    memdelete(sliderSignalWrapper);
                    sliderSignalWrapper = nullptr;
                }
                Range::onFree();
            }
    };
}

#endif // SLIDER_H