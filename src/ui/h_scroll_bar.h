#ifndef H_SCROLL_BAR_H
#define H_SCROLL_BAR_H

#include <godot_cpp/classes/h_scroll_bar.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define HScrollBarNode godot::HScrollBar

#include "scroll_bar.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindHScrollBar(sol::state& lua);

    class HScrollBar;
    
    class HScrollBarProxy : public HScrollBarNode {
        GDCLASS(HScrollBarProxy, HScrollBarNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to HScrollBarProxy
            }
        public:
            lucidware::ui::HScrollBar* element = nullptr;

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

    class HScrollBar : public lucidware::ui::ScrollBar {
        private:
            HScrollBarNode* hScrollBar = nullptr; // Pointer to the HScrollBar instance

            void connectHScrollBarSignals() {
                // Connect signals specific to HScrollBar
            }

        public:
            HScrollBar() {
                setHScrollBar(memnew(HScrollBarNode));
                onInit();
            }

            HScrollBar(HScrollBarNode* p_node) {
                setHScrollBar(p_node);
            }

            HScrollBarNode* getHScrollBar() {
                return hScrollBar;
            }

            void setHScrollBar(HScrollBarNode* p_node) {
                hScrollBar = p_node;
                connectHScrollBarSignals();
                setScrollBar(p_node);
            }

            void setHScrollBar(HScrollBarProxy* p_node) {
                hScrollBar = p_node;
                p_node->element = this;
                connectHScrollBarSignals();
                setScrollBar(p_node);
            }
    };
}

#endif // H_SCROLL_BAR_H