#ifndef H_BOX_CONTAINER_H
#define H_BOX_CONTAINER_H

#include <godot_cpp/classes/h_box_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define HBoxContainerNode godot::HBoxContainer

#include "box_container.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindHBoxContainer(sol::state &lua);

    class HBoxContainer;

    class HBoxContainerProxy : public HBoxContainerNode {
        GDCLASS(HBoxContainerProxy, HBoxContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to HBoxContainerProxy
            }
        public:
            sunaba::ui::HBoxContainer* element = nullptr;

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

    class HBoxContainer : public BoxContainer {
        private:
            HBoxContainerNode* hbox_container = nullptr; // Pointer to the HBoxContainer instance

            void connectHBoxContainerSignals() {
                // Connect signals from the container to the element
                // Example: hbox_container->connect("signal_name", this, "method_name");
            }

        public:
            HBoxContainer() {
                setHBoxContainer(memnew(HBoxContainerNode));
                onInit();
            }

            HBoxContainer(HBoxContainerNode* container) {
                setHBoxContainer(container);
            }

            HBoxContainerNode* getContainer() {
                return hbox_container;
            }

            void setHBoxContainer(HBoxContainerNode* container) {
                hbox_container = container;
                connectHBoxContainerSignals();
                setBoxContainer(container);
            }
                
            void setHBoxContainer(HBoxContainerProxy* container) {
                hbox_container = container;
                container->element = this;
                connectHBoxContainerSignals();
                setBoxContainer(container);
            }
    };
}

#endif // H_BOX_CONTAINER_H