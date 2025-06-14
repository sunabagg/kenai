#ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H

#include <godot_cpp/classes/box_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define BoxContainerNode godot::BoxContainer

#include "container.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindBoxContainer(sol::state &lua);

    class BoxContainer;

    class BoxContainerProxy : public BoxContainerNode {
        GDCLASS(BoxContainerProxy, BoxContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to BoxContainerProxy
            }
        public:
            sunaba::ui::BoxContainer* element = nullptr;

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

    class BoxContainer : public Container {
        private:
            BoxContainerNode* container = nullptr; // Pointer to the BoxContainer instance

            void connectContainerSignals() {
                // Connect signals from the container to the element
                // Example: container->connect("signal_name", this, "method_name");
            }
        public:
            BoxContainer() {
                setBoxContainer(memnew(BoxContainerNode));
                onInit();
            }

            BoxContainer(BoxContainerNode* container) {
                setBoxContainer(container);
            }

            BoxContainerNode* getContainer() {
                return container;
            }

            void setBoxContainer(BoxContainerNode* container) {
                this->container = container;
                connectContainerSignals();
                setContainer(container);
            }
            
            void setBoxContainer(BoxContainerProxy* container) {
                this->container = container;
                container->element = this;
                connectContainerSignals();
                setContainer(container);
            }

            int getAlignment() const {
                return container->get_alignment();
            }

            void setAlignment(int alignment) {
                container->set_alignment(static_cast<BoxContainerNode::AlignmentMode>(alignment));
            }

            bool isVertical() const {
                return container->is_vertical();
            }

            void setVertical(bool vertical) {
                container->set_vertical(vertical);
            }

            Control* addSpacer(bool begin) {
                return new Control(container->add_spacer(begin));
            }
    };
}

#endif // !BOX_CONTAINER_H