#ifndef PANEL_H
#define PANEL_H

#include <godot_cpp/classes/panel.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define PanelNode godot::Panel

#include "control.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindPanel(sol::state& lua);

    class Panel;

    class PanelProxy : public PanelNode {
        GDCLASS(PanelProxy, PanelNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to PanelProxy
            }
        public:
            sunaba::ui::Panel* element = nullptr;

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

    class Panel : public sunaba::ui::Control {
        private:
            PanelNode* panel = nullptr; // Pointer to the Panel instance
            void connectPanelSignals() {
                // Connect signals specific to Panel
            }

        public:
        Panel() {
            setPanel(memnew(PanelProxy));
            onInit();
        }
        Panel(PanelNode* p_node) {
            setPanel(p_node);
        }
        PanelNode* getPanel() {
            return panel;
        }

        void setPanel(PanelNode* p_node) {
            panel = p_node;
            connectPanelSignals();
            setControl(p_node);
        }

        void setPanel(PanelProxy* p_node) {
            panel = p_node;
            p_node->element = this;
            connectPanelSignals();
            setControl(p_node);
        }
    };
}

#endif // PANEL_H