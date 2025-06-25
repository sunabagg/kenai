#ifndef REFERENCE_RECT_H
#define REFERENCE_RECT_H

#include <godot_cpp/classes/reference_rect.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ReferenceRectNode godot::ReferenceRect

#include "control.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindReferenceRect(sol::state& lua);

    class ReferenceRect;
    
    class ReferenceRectProxy : public ReferenceRectNode {
        GDCLASS(ReferenceRectProxy, ReferenceRectNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to ReferenceRectProxy
            }
        public:
            lucidware::ui::ReferenceRect* element = nullptr;

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

    class ReferenceRect : public lucidware::ui::Control {
        private:
            ReferenceRectNode* referenceRect = nullptr; // Pointer to the ReferenceRect instance

            void connectReferenceRectSignals() {
                // Connect signals specific to ReferenceRect
            }

        public:
            ReferenceRect() {
                setReferenceRect(memnew(ReferenceRectNode));
                onInit();
            }

            ReferenceRect(ReferenceRectNode* p_node) {
                setReferenceRect(p_node);
            }

            ReferenceRectNode* getReferenceRect() {
                return referenceRect;
            }

            void setReferenceRect(ReferenceRectNode* p_node) {
                referenceRect = p_node;
                connectReferenceRectSignals();
                setControl(p_node);
            }

            void setReferenceRect(ReferenceRectProxy* p_node) {
                referenceRect = p_node;
                p_node->element = this;
                connectReferenceRectSignals();
                setControl(p_node);
            }

            Color getBorderColor() {
                return referenceRect->get_border_color();
            }

            void setBorderColor(Color color) {
                referenceRect->set_border_color(color);
            }

            float getBorderWidth() {
                return referenceRect->get_border_width();
            }

            void setBorderWidth(float width) {
                referenceRect->set_border_width(width);
            }
    };
}
#endif