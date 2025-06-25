#ifndef V_BOX_CONTAINER_H
#define V_BOX_CONTAINER_H

#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define VBoxContainerNode godot::VBoxContainer

#include "box_container.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindVBoxContainer(sol::state &lua);

    class VBoxContainer;

    class VBoxContainerProxy : public VBoxContainerNode {
        GDCLASS(VBoxContainerProxy, VBoxContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to VBoxContainerProxy
            }
        public:
            lucidware::ui::VBoxContainer* element = nullptr;

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

    class VBoxContainer : public BoxContainer {
        private:
            VBoxContainerNode* vbox_container = nullptr; // Pointer to the VBoxContainer instance

            void connectVBoxContainerSignals() {
                // Connect signals from the container to the element
                // Example: vbox_container->connect("signal_name", this, "method_name");
            }

        public:
            VBoxContainer() {
                setVBoxContainer(memnew(VBoxContainerNode));
                onInit();
            }

            VBoxContainer(VBoxContainerNode* container) {
                setVBoxContainer(container);
            }

            VBoxContainerNode* getContainer() {
                return vbox_container;
            }

            void setVBoxContainer(VBoxContainerNode* container) {
                vbox_container = container;
                connectVBoxContainerSignals();
                setBoxContainer(container);
            }

            void setVBoxContainer(VBoxContainerProxy* container) {
                vbox_container = container;
                container->element = this;
                connectVBoxContainerSignals();
                setBoxContainer(container);
            }
    };
}

#endif // V_BOX_CONTAINER_H