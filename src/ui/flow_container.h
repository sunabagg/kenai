#ifndef FLOW_CONTAINER_H
#define FLOW_CONTAINER_H

#include <godot_cpp/classes/flow_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define FlowContainerNode godot::FlowContainer

#include "container.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindFlowContainer(sol::state& lua);

    class FlowContainer;

    class FlowContainerProxy : public FlowContainerNode {
        GDCLASS(FlowContainerProxy, FlowContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to FlowContainerProxy
            }
        public:
            lucidware::ui::FlowContainer* element = nullptr;

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

    class FlowContainer : public Container {
        private:
            FlowContainerNode* flowContainer = nullptr; // Pointer to the FlowContainer instance
            void connectContainerSignals() {
                // Connect signals specific to FlowContainer
            }

        public:
            FlowContainer() {
                setFlowContainer(memnew(FlowContainerNode));
                onInit();
            }

            FlowContainer(FlowContainerNode* container) {
                setFlowContainer(container); 
            }

            FlowContainerNode* getContainer() {
                return flowContainer;
            }

            void setFlowContainer(FlowContainerNode* container) {
                this->flowContainer = container;
                connectContainerSignals();
                setContainer(container);
            }

            void setFlowContainer(FlowContainerProxy* container) {
                this->flowContainer = container;
                container->element = this;
                connectContainerSignals();
                setContainer(container);
            }

            int getAlignment() {
                return flowContainer->get_alignment();
            }

            void setAlignment(int alignment) {
                flowContainer->set_alignment(static_cast<godot::FlowContainer::AlignmentMode>(alignment));
            }

            int getLastWrapAlignment() {
                return flowContainer->get_last_wrap_alignment();
            }

            void setLastWrapAlignment(int alignment) {
                flowContainer->set_last_wrap_alignment(static_cast<godot::FlowContainer::LastWrapAlignmentMode>(alignment));
            }

            bool getReverseFill() {
                return flowContainer->is_reverse_fill();
            }

            void setReverseFill(bool reverse_fill) {
                flowContainer->set_reverse_fill(reverse_fill);
            }

            bool getVertical() {
                return flowContainer->is_vertical();
            }

            void setVertical(bool vertical) {
                flowContainer->set_vertical(vertical);
            }

            int getLineCount() {
                return flowContainer->get_line_count();
            }
    };
}

#endif // !FLOW_CONTAINER_H