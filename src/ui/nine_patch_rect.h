#ifndef NINE_PATCH_RECT_H
#define NINE_PATCH_RECT_H

#include <godot_cpp/classes/nine_patch_rect.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define NinePatchRectNode godot::NinePatchRect

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindNinePatchRect(sol::state& lua);

    class NinePatchRect;

    class NinePatchRectProxy : public NinePatchRectNode {
        GDCLASS(NinePatchRectProxy, NinePatchRectNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to NinePatchRectProxy
            }
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
                SignalFunc textureChangedFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.push_back(av[i]);
                    }
                    if (this->textureChangedEvent != nullptr) {
                        this->textureChangedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable textureChangedCallable = StlFunctionWrapper::create_callable_from_cpp_function(textureChangedFunc);
                ninePatchRect->connect("texture_changed", textureChangedCallable);
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

            void setAxisStretchHorizontal() {
                ninePatchRect->set_h_axis_stretch_mode(static_cast<godot::NinePatchRect::AxisStretchMode>(1));
            }

            int getAxisStretchVertical() {
                return ninePatchRect->get_v_axis_stretch_mode();
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

            int getMouseFilter() {
                return ninePatchRect->get_mouse_filter();
            }

            void setMouseFilter(int filter) {
                ninePatchRect->set_mouse_filter(static_cast<godot::Control::MouseFilter>(filter));
            }

            int getPatchMarginBottom() {
                return ninePatchRect->get_patch_margin(SIDE_BOTTOM);
            }

            void setPatchMarginBottom(int value) {
                ninePatchRect->set_patch_margin(SIDE_BOTTOM, value);
            }

            int getPatchMarginLeft() {
                return ninePatchRect->get_patch_margin(SIDE_LEFT);
            }

            void setPatchMarginLeft(int value) {
                ninePatchRect->set_patch_margin(SIDE_LEFT, value);
            }

            int getPatchMarginRight() {
                return ninePatchRect->get_patch_margin(SIDE_RIGHT);
            }

            void setPatchMarginRight(int value) {
                ninePatchRect->set_patch_margin(SIDE_RIGHT, value);
            }

            int getPatchMarginTop() {
                return ninePatchRect->get_patch_margin(SIDE_TOP);
            }

            void setPatchMarginTop(int value) {
                ninePatchRect->set_patch_margin(SIDE_TOP, value);
            }

            Rect2 getRegionRect() {
                return ninePatchRect->get_region_rect();
            }

            void setRegionRect(Rect2 rect) {
                ninePatchRect->set_region_rect(rect);
            }

            sunaba::core::Texture2D* getTexture() {
                return new sunaba::core::Texture2D(ninePatchRect->get_texture().ptr());
            }

            void setTexture(sunaba::core::Texture2D* texture) {
                ninePatchRect->set_texture(Ref<godot::Texture2D>(texture->getTexture()));
            }

            Event* textureChangedEvent;
            Event* getTextureChangedEvent() {
                return textureChangedEvent;
            }
            void setTextureChangedEvent(Event* event) {
                textureChangedEvent = event;
            }

            int getPatchMargin(int side) {
                return ninePatchRect->get_patch_margin(static_cast<godot::Side>(side));
            }

            void setPatchMargin(int side, int value) {
                ninePatchRect->set_patch_margin(static_cast<godot::Side>(side), value);
            }
    };
}

#endif