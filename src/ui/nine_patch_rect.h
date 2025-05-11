#ifndef NINE_PATCH_RECT_H
#define NINE_PATCH_RECT_H

#include <godot_cpp/classes/nine_patch_rect.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define NinePatchRectNode godot::NinePatchRect

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindNinePatchRect(sol::state& lua);

    class NinePatchRect;

    class NinePatchRectProxy : public NinePatchRectNode {
        public:
            sunaba::ui::NinePatchRect* element = nullptr;

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

    class NinePatchRect : public Control {
        private:
            NinePatchRectNode* ninePatchRect = nullptr;

            void connectNinePatchRectSignals() {
                // Connect signals specific to NinePatchRect
            }

        public:
            NinePatchRect() {
                setNinePatchRect(memnew(NinePatchRectProxy));
                onInit();
            }

            NinePatchRect(NinePatchRectNode* ninePatchRect) {
                setNinePatchRect(ninePatchRect);
            }

            NinePatchRectNode* getNinePatchRect() {
                return ninePatchRect;
            }

            void setNinePatchRect(NinePatchRectNode* ninePatchRect) {
                this->ninePatchRect = ninePatchRect;
                connectNinePatchRectSignals();
                setControl(ninePatchRect);
            }

            void setNinePatchRect(NinePatchRectProxy* ninePatchRect) {
                this->ninePatchRect = ninePatchRect;
                ninePatchRect->element = this;
                connectNinePatchRectSignals();
                setControl(ninePatchRect);
            }

            int getAxisStretchHorizontal() {
                return ninePatchRect->get_h_axis_stretch_mode();
            }

            void setAxisStretchVertical() {
                ninePatchRect->set_v_axis_stretch_mode(static_cast<godot::NinePatchRect::AxisStretchMode>(1));
            }

            bool isDrawCenterEnabled() {
                return ninePatchRect->is_draw_center_enabled();
            }

            void setDrawCenter(bool enabled) {
                ninePatchRect->set_draw_center(enabled);
            }
    };
}

#endif