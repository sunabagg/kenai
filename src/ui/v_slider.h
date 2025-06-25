#ifndef V_SLIDER_H
#define V_SLIDER_H

#include <godot_cpp/classes/v_slider.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define VSliderNode godot::VSlider

#include "slider.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::ui {
    void bindVSlider(sol::state &lua);

    class VSlider;

    class VSliderProxy : public VSliderNode {
        GDCLASS(VSliderProxy, VSliderNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to VSliderProxy
            }
        public:
            lucidfx::ui::VSlider* element = nullptr;

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

    class VSlider : public lucidfx::ui::Slider {
        private:
            VSliderNode* vSlider = nullptr; // Pointer to the VSlider instance
            void connectVSliderSignals() {
                // Connect signals specific to VSlider
            }

        public:
            VSlider() {
                setVSlider(memnew(VSliderNode));
                onInit();
            }

            VSlider(VSliderNode* p_node) {
                setVSlider(p_node);
            }

            VSliderNode* getVSlider() {
                return vSlider;
            }

            void setVSlider(VSliderNode* vSlider) {
                this->vSlider = vSlider;
                setSlider(vSlider);
            }

            void setVSlider(VSliderProxy* vSlider) {
                this->vSlider = vSlider;
                vSlider->element = this;
                setSlider(vSlider);
            }
    };
}

#endif // V_SLIDER_H