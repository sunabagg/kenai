#ifndef SPLIT_CONTAINER_H
#define SPLIT_CONTAINER_H

#include <godot_cpp/classes/split_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define SplitContainerNode godot::SplitContainer

#include "container.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindSplitContainer(sol::state& lua);

    class SplitContainer;

    class SplitContainerProxy : public SplitContainerNode {
        public:
            sunaba::ui::SplitContainer* element = nullptr;

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

            bool _can_drop_data(const Vector2& at_position, const Variant& data) const override;

            void _drop_data(const Vector2& at_position, const Variant& data) override;

            Variant _get_drag_data(const Vector2& at_position) override;

            Vector2 _get_minimum_size() const override;

            String _get_tooltip(const Vector2& at_position) const override;

            void _gui_input(const Ref<InputEvent>& event) override;

            bool _has_point(const Vector2& point) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array& args, const String& text) const override;

            PackedInt32Array _get_allowed_size_flags_horizontal() const override;

            PackedInt32Array _get_allowed_size_flags_vertical() const override;
    };

    class SplitContainer : public Container {
        private:
            SplitContainerNode* container = nullptr; // Pointer to the SplitContainer instance

            void connectContainerSignals() {
                // Connect signals from the container to the element
                // Example: container->connect("signal_name", this, "method_name");
            }
        public:
            SplitContainer() {
                setSplitContainer(memnew(SplitContainerProxy));
                onInit();
            }

            SplitContainer(SplitContainerNode* container) {
                setSplitContainer(container);
            }

            SplitContainerNode* getContainer() {
                return container;
            }

            void setSplitContainer(SplitContainerNode* container) {
                this->container = container;
                connectContainerSignals();
                setContainer(container);
            }
            
            void setSplitContainer(SplitContainerProxy* container) {
                this->container = container;
                container->element = this;
                connectContainerSignals();
                setContainer(container);
            }

            bool getCollapsed() const {
                return container->is_collapsed();
            }

            void setCollapsed(bool collapsed) {
                container->set_collapsed(collapsed);
            }

            bool getDragAreaHighlightInEditor() const {
                return container->is_drag_area_highlight_in_editor_enabled();
            }

            void setDragAreaHighlightInEditor(bool highlight) {
                container->set_drag_area_highlight_in_editor(highlight);
            }

            int getDragAreaMarginBegin() const {
                return container->get_drag_area_margin_begin();
            }

            void setDragAreaMarginBegin(int margin) {
                container->set_drag_area_margin_begin(margin);
            }

            int getDragAreaMarginEnd() const {
                return container->get_drag_area_margin_end();
            }

            void setDragAreaMarginEnd(int margin) {
                container->set_drag_area_margin_end(margin);
            }

            int getDragAreaOffset() const {
                return container->get_drag_area_offset();
            }

            void setDragAreaOffset(int offset) {
                container->set_drag_area_offset(offset);
            }

            int getDraggerVisibility() const {
                return container->get_dragger_visibility();
            }

            void setDraggerVisibility(int visibility) {
                container->set_dragger_visibility(static_cast<SplitContainerNode::DraggerVisibility>(visibility));
            }

            bool getDraggingEnabled() const {
                return container->is_dragging_enabled();
            }

            void setDraggingEnabled(bool enabled) {
                container->set_dragging_enabled(enabled);
            }

            int getSplitOffset() const {
                return container->get_split_offset();
            }

            void setSplitOffset(int offset) {
                container->set_split_offset(offset);
            }

            bool isVertical() const {
                return container->is_vertical();
            }

            void setVertical(bool vertical) {
                container->set_vertical(vertical);
            }

            Event* dragEndedEvent;
            Event* getDragEndedEvent() {
                return dragEndedEvent;
            }
    };
}

#endif // SPLIT_CONTAINER_H