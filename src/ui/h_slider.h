#ifndef H_SLIDER_H
#define H_SLIDER_H

#include <godot_cpp/classes/h_slider.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define HSliderNode godot::HSlider

#include "slider.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindHSlider(sol::state &lua);

    class HSlider;

    class HSliderProxy : public HSliderNode {
        GDCLASS(HSliderProxy, HSliderNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to HSliderProxy
            }
        public:
            sunaba::ui::HSlider* element = nullptr;

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

    class HSlider : public sunaba::ui::Slider {
        private:
            HSliderNode* hSlider = nullptr; // Pointer to the HSlider instance
            void connectHSliderSignals() {
                // Connect signals specific to HSlider
            }

        public:
            HSlider() {
                setHSlider(memnew(HSliderProxy));
                onInit();
            }

            HSlider(HSliderNode* p_node) {
                setHSlider(p_node);
            }

            HSliderNode* getHSlider() const {
                return hSlider;
            }

            void setHSlider(HSliderNode* hSlider) {
                this->hSlider = hSlider;
                setSlider(hSlider);
            }

            void setHSlider(HSliderProxy* hSlider) {
                this->hSlider = hSlider;
                hSlider->element = this;
                setSlider(hSlider);
            }
    };
}

#endif // H_SLIDER_H