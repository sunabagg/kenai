#ifndef H_FLOW_CONTAINER_H
#define H_FLOW_CONTAINER_H

#include <godot_cpp/classes/h_flow_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define HFlowContainerNode godot::HFlowContainer

#include "flow_container.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindHFlowContainer(sol::state &lua);

    class HFlowContainer;

    class HFlowContainerProxy : public HFlowContainerNode {
        GDCLASS(HFlowContainerProxy, HFlowContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to HFlowContainerProxy
            }
        public:
            sunaba::ui::HFlowContainer* element = nullptr;

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

    class HFlowContainer : public FlowContainer {
        private:
            HFlowContainerNode* hflow_container = nullptr; // Pointer to the HFlowContainer instance

            void connectHFlowContainerSignals() {
                // Connect signals from the container to the element
                // Example: hflow_container->connect("signal_name", this, "method_name");
            }
        public:
            HFlowContainer() {
                setHFlowContainer(memnew(HFlowContainerProxy));
                onInit();
            }

            HFlowContainer(HFlowContainerNode* container) {
                setHFlowContainer(container);
            }

            HFlowContainer(HFlowContainerProxy* container) {
                setHFlowContainer(container);
            }

            HFlowContainerNode* getContainer() {
                return hflow_container;
            }

            void setHFlowContainer(HFlowContainerNode* container) {
                this->hflow_container = container;
                connectHFlowContainerSignals();
                setFlowContainer(container);
            }

            void setHFlowContainer(HFlowContainerProxy* container) {
                this->hflow_container = container;
                container->element = this;
                connectHFlowContainerSignals();
                setFlowContainer(container);
            }
    };
}

#endif // H_FLOW_CONTAINER_H