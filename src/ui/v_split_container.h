#ifndef V_SPLIT_CONTAINER_H
#define V_SPLIT_CONTAINER_H

#include <godot_cpp/classes/v_split_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define VSplitContainerNode godot::VSplitContainer

#include "split_container.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindVSplitContainer(sol::state &lua);

    class VSplitContainer;

    class VSplitContainerProxy : public VSplitContainerNode {
        GDCLASS(VSplitContainerProxy, VSplitContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to VSplitContainerProxy
            }
        public:
            sunaba::ui::VSplitContainer* element = nullptr;

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

    class VSplitContainer : public SplitContainer {
        private:
            VSplitContainerNode* container = nullptr; // Pointer to the VSplitContainer instance

            void connectContainerSignals() {
                // Connect signals from the container to the element
                // Example: container->connect("signal_name", this, "method_name");
            }
        public:
            VSplitContainer() {
                setSplitContainer(memnew(VSplitContainerNode));
                onInit();
            }

            VSplitContainer(VSplitContainerNode* container) {
                setSplitContainer(container);
            }

            VSplitContainerNode* getContainer() {
                return container;
            }
            void setVSplitContainer(VSplitContainerNode* container) {
                this->container = container;
                connectContainerSignals();
                setSplitContainer(container);
            }

            void setVSplitContainer(VSplitContainerProxy* container) {
                this->container = container;
                container->element = this;
                connectContainerSignals();
                setSplitContainer(container);
            }
    };
}

#endif // V_SPLIT_CONTAINER_H