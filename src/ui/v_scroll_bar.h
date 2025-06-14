#ifndef V_SCROLL_BAR_H
#define V_SCROLL_BAR_H

#include <godot_cpp/classes/v_scroll_bar.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define VScrollBarNode godot::VScrollBar

#include "scroll_bar.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindVScrollBar(sol::state& lua);

    class VScrollBar;
    
    class VScrollBarProxy : public VScrollBarNode {
        GDCLASS(VScrollBarProxy, VScrollBarNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to VScrollBarProxy
            }
        public:
            sunaba::ui::VScrollBar* element = nullptr;

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

    class VScrollBar : public sunaba::ui::ScrollBar {
        private:
            VScrollBarNode* vScrollBar = nullptr; // Pointer to the VScrollBar instance

            void connectVScrollBarSignals() {
                // Connect signals specific to VScrollBar
            }

        public:
            VScrollBar() {
                setVScrollBar(memnew(VScrollBarNode));
                onInit();
            }

            VScrollBar(VScrollBarNode* p_node) {
                setVScrollBar(p_node);
                onInit();
            }

            VScrollBarNode* getVScrollBar() {
                return vScrollBar;
            }

            void setVScrollBar(VScrollBarNode* p_node) {
                vScrollBar = p_node;
                connectVScrollBarSignals();
                setScrollBar(p_node);
            }

            void setVScrollBar(VScrollBarProxy* p_node) {
                vScrollBar = p_node;
                p_node->element = this;
                connectVScrollBarSignals();
                setScrollBar(p_node);
            }
    };
}

#endif // V_SCROLL_BAR_H