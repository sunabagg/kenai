#ifndef CENTER_CONTAINER_H
#define CENTER_CONTAINER_H

#include <godot_cpp/classes/center_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define CenterContainerNode godot::CenterContainer

#include "container.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindCenterContainer(sol::state &lua);

    class CenterContainer;

    class CenterContainerProxy : public CenterContainerNode {
        GDCLASS(CenterContainerProxy, CenterContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to CenterContainerProxy
            }
        public:
            sunaba::ui::CenterContainer* element = nullptr;

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

            PackedInt32Array _get_allowed_size_flags_horizontal() const override;

            PackedInt32Array _get_allowed_size_flags_vertical() const override;
    };

    class CenterContainer : public Container {
        private:
            CenterContainerNode* centerContainer = nullptr; // Pointer to the CenterContainer instance

            void connectCenterContainerSignals() {
                // Connect signals from the control node to the element
                // Example: control->connect("signal_name", this, "method_name");
            } 
        public:
            CenterContainer(CenterContainerNode* p_node) {
                setCenterContainer(p_node);
            }

            CenterContainer(CenterContainerProxy* p_node) {
                setCenterContainer(p_node);
            }

            CenterContainer() {
                setCenterContainer(memnew(CenterContainerNode));
                onInit();
            }

            CenterContainerNode* getCenterContainer() {
                return centerContainer;
            }

            void setCenterContainer(CenterContainerNode* p_node) {
                centerContainer = p_node;
                connectCenterContainerSignals();
                setContainer(p_node);
            }

            void setCenterContainer(CenterContainerProxy* p_node) {
                centerContainer = p_node;
                p_node->element = this;
                connectCenterContainerSignals();
                setContainer(p_node);
            }

            bool isUsingTopLeft() const {
                return centerContainer->is_using_top_left();
            }

            void setUseTopLeft(bool p_enable) {
                centerContainer->set_use_top_left(p_enable);
            }
    };
}
#endif // !CENTER_CONTAINER_H