#ifndef ASPECT_RATIO_CONTAINER_H
#define ASPECT_RATIO_CONTAINER_H

#include <godot_cpp/classes/aspect_ratio_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define AspectRatioContainerNode godot::AspectRatioContainer

#include "container.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindAspectRatioContainer(sol::state &lua);

    class AspectRatioConatiner;

    class AspectRatioContainerProxy : public AspectRatioContainerNode {
        public:
            sunaba::ui::AspectRatioConatiner* element = nullptr;

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

    class AspectRatioContainer : public Container {
        private:
            AspectRatioContainerNode* container = nullptr; // Pointer to the AspectRatioContainer instance

            void connectContainerSignals() {
                // Connect signals from the container to the element
                // Example: container->connect("signal_name", this, "method_name");
            }
        public:
            AspectRatioContainer() {
                setContainer(memnew(AspectRatioContainerProxy));
            }

            AspectRatioContainer(AspectRatioContainerNode* container) {
                setContainer(container);
            }

            AspectRatioContainerNode* getContainer() {
                return container;
            }

            void setContainer(AspectRatioContainerNode* container) {
                this->container = container;
                connectContainerSignals();
                setControl(container);
            }
            void setContainer(AspectRatioContainerProxy* container) {
                this->container = container;
                container->element = this;
                connectContainerSignals();
                setControl(container);
            }

            int getAlignmentHorizontal() {
                return container->get_alignment_horizontal();
            }

            void setAlignmentHorizontal(int alignment) {
                container->set_alignment_horizontal(static_cast<AspectRatioContainer::AlignmentMode>(alignment));
            }
    };
}

#endif // !ASPECT_RATIO_CONTAINER_H
