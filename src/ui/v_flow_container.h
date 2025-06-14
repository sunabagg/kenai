#ifndef V_FLOW_CONTAINER_H
#define V_FLOW_CONTAINER_H

#include <godot_cpp/classes/v_flow_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define VFlowContainerNode godot::VFlowContainer

#include "flow_container.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindVFlowContainer(sol::state &lua);

    class VFlowContainer;

    class VFlowContainerProxy : public VFlowContainerNode {
        GDCLASS(VFlowContainerProxy, VFlowContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to VFlowContainerProxy
            }
        public:
            sunaba::ui::VFlowContainer* element = nullptr;

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

    class VFlowContainer : public FlowContainer {
        private:
            VFlowContainerNode* vflow_container = nullptr; // Pointer to the VFlowContainer instance

            void connectVFlowContainerSignals() {
                // Connect signals from the container to the element
                // Example: vflow_container->connect("signal_name", this, "method_name");
            }
        public:
            VFlowContainer() {
                setVFlowContainer(memnew(VFlowContainerNode));
                onInit();
            }

            VFlowContainer(VFlowContainerNode* container) {
                setVFlowContainer(container);
            }

            VFlowContainerNode* getContainer() {
                return vflow_container;
            }

            void setVFlowContainer(VFlowContainerNode* container) {
                this->vflow_container = container;
                connectVFlowContainerSignals();
                setContainer(container);
            }

            void setVFlowContainer(VFlowContainerProxy* container) {
                this->vflow_container = container;
                container->element = this;
                connectVFlowContainerSignals();
                setContainer(container);
            }
    };
} // namespace sunaba::ui

#endif // V_FLOW_CONTAINER_H