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
        GDCLASS(SplitContainerProxy, SplitContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to SplitContainerProxy
            }
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
                SignalFunc dragEndedFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->dragEndedEvent != nullptr) {
                        this->dragEndedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable dragEndedCallable = StlFunctionWrapper::create_callable_from_cpp_function(dragEndedFunc);
                container->connect("drag_ended", dragEndedCallable);
                SignalFunc dragStartedFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->dragStartedEvent != nullptr) {
                        this->dragStartedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable dragStartedCallable = StlFunctionWrapper::create_callable_from_cpp_function(dragStartedFunc);
                container->connect("drag_started", dragStartedCallable);
                SignalFunc draggedFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->draggedEvent != nullptr) {
                        this->draggedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable draggedCallable = StlFunctionWrapper::create_callable_from_cpp_function(draggedFunc);
                container->connect("dragged", draggedCallable);
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
            void setDragEndedEvent(Event* event) {
                dragEndedEvent = event;
            }
            Event* dragStartedEvent;
            Event* getDragStartedEvent() {
                return dragStartedEvent;
            }
            void setDragStartedEvent(Event* event) {
                dragStartedEvent = event;
            }
            Event* draggedEvent;
            Event* getDraggedEvent() {
                return draggedEvent;
            }
            void setDraggedEvent(Event* event) {
                draggedEvent = event;
            }

            void clampSplitOffset() {
                container->clamp_split_offset();
            }

            Control* getDragAreaControl() {
                return new Control(container->get_drag_area_control());
            }
    };
}

#endif // SPLIT_CONTAINER_H