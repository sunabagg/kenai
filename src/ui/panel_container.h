#ifndef PANEL_CONTAINER_H
#define PANEL_CONTAINER_H

#include <godot_cpp/classes/panel_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define PanelContainerNode godot::PanelContainer

#include "container.h"

using namespace godot;
using namespace lucidfx::ui;

namespace lucidfx::ui {
    void bindPanelContainer(sol::state& lua);

    class PanelContainer;

    class PanelContainerProxy : public PanelContainerNode {
        GDCLASS(PanelContainerProxy, PanelContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to PanelContainerProxy
            }
        public:
            lucidfx::ui::PanelContainer* element = nullptr;

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

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;

            PackedInt32Array _get_allowed_size_flags_horizontal() const override;

            PackedInt32Array _get_allowed_size_flags_vertical() const override;
    };

    class PanelContainer : public Container {
        private:
            PanelContainerNode* panel_container = nullptr; // Pointer to the PanelContainer instance
            void connectPanelContainerSignals() {
                // Connect signals specific to PanelContainer
            }

        public:
            PanelContainer() {
                setPanelContainer(memnew(PanelContainerNode));
                onInit();
            }

            PanelContainer(PanelContainerNode* panel_container) {
                setPanelContainer(panel_container);
            }

            PanelContainerNode* getPanelContainer() {
                return panel_container;
            }

            void setPanelContainer(PanelContainerNode* panel_container) {
                this->panel_container = panel_container;
                connectPanelContainerSignals();
                setControl(panel_container);
            }

            void setPanelContainer(PanelContainerProxy* panel_container) {
                this->panel_container = panel_container;
                panel_container->element = this;
                connectPanelContainerSignals();
                setControl(panel_container);
            }

            int getMouseFilter() const {
                return panel_container->get_mouse_filter();
            }

            void setMouseFilter(int filter) {
                panel_container->set_mouse_filter(static_cast<godot::Control::MouseFilter>(filter));
            }
    };
}

#endif // PANEL_CONTAINER_H