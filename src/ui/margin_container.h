#ifndef MARGIN_CONTAINER_H
#define MARGIN_CONTAINER_H

#include <godot_cpp/classes/margin_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define MarginContainerNode godot::MarginContainer

#include "container.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindMarginContainer(sol::state &lua);

    class MarginContainer;

    class MarginContainerProxy : public MarginContainerNode {
        GDCLASS(MarginContainerProxy, MarginContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to MarginContainerProxy
            }
        public:
            sunaba::ui::MarginContainer* element = nullptr;

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

    class MarginContainer : public Container {
        private:
            MarginContainerNode* margin_container = nullptr; // Pointer to the MarginContainer instance
            void connectMarginContainerSignals() {
                // Connect signals specific to MarginContainer
            }

        public:
            MarginContainer() {
                setMarginContainer(memnew(MarginContainerProxy));
                onInit();
            }

            MarginContainer(MarginContainerNode* margin_container) {
                setMarginContainer(margin_container);
            }

            MarginContainerNode* getMarginContainer() {
                return margin_container;
            }

            void setMarginContainer(MarginContainerNode* margin_container) {
                this->margin_container = margin_container;
                connectMarginContainerSignals();
                setContainer(margin_container);
            }

            void setMarginContainer(MarginContainerProxy* margin_container) {
                this->margin_container = margin_container;
                margin_container->element = this;
                connectMarginContainerSignals();
                setContainer(margin_container);
            }
    };
}

#endif // MARGIN_CONTAINER_H