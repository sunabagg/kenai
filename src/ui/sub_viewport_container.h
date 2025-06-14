#ifndef SUB_VIEWPORT_CONTAINER_H
#define SUB_VIEWPORT_CONTAINER_H

#include <godot_cpp/classes/sub_viewport_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define SubViewportContainerNode godot::SubViewportContainer

#include "container.h"
#include "../input/input_event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindSubViewportContainer(sol::state &lua);

    class SubViewportContainer;
    
    class SubViewportContainerProxy : public SubViewportContainerNode {
        GDCLASS(SubViewportContainerProxy, SubViewportContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to SubViewportContainerProxy
            }
        public:
            sunaba::ui::SubViewportContainer* element = nullptr;

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
            bool _propagate_input_event(const Ref<InputEvent> &event) const override;

            bool propagateInputEvent(const Ref<InputEvent>& event) {
                return SubViewportContainerNode::_propagate_input_event(event);
            }
    };

    class SubViewportContainer : public Container {
        private:
            SubViewportContainerNode* container = nullptr; // Pointer to the SubViewportContainer instance
            void connectContainerSignals() {
                // Connect signals specific to SubViewportContainer
            }

        public:
            SubViewportContainer() {
                setContainer(memnew(SubViewportContainerNode));
                onInit();
            }

            SubViewportContainer(SubViewportContainerNode* container) {
                setContainer(container);
            }

            SubViewportContainerNode* getContainer() {
                return container;
            }

            void setContainer(SubViewportContainerNode* container) {
                this->container = container;
                connectContainerSignals();
                setControl(container);
            }

            void setContainer(SubViewportContainerProxy* container) {
                this->container = container;
                container->element = this;
                connectContainerSignals();
                setControl(container);
            }

            int getFocusMode() {
                return container->get_focus_mode();
            }

            void setFocusMode(int mode) {
                container->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            bool getMouseTarget() {
                return container->is_mouse_target_enabled();
            }

            void setMouseTarget(bool enabled) {
                container->set_mouse_target(enabled);
            }

            bool getStretch() {
                return container->is_stretch_enabled();
            }

            void setStretch(bool enabled) {
                container->set_stretch(enabled);
            }

            int getStretchShrink() {
                return container->get_stretch_shrink();
            }

            void setStretchShrink(int shrink) {
                container->set_stretch_shrink(shrink);
            }

            bool propagateInputEvent(const Ref<InputEvent>& event) {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["propagateInputEvent"].get<sol::function>();
                    if (func) {
                        sunaba::input::InputEvent* inputEvent = new sunaba::input::InputEvent(event.ptr());
                        auto result = func(scriptInstance, inputEvent);
                        return result.get<bool>();
                    }
                }
                SubViewportContainerProxy* proxy = Object::cast_to<SubViewportContainerProxy>(container);
                if (proxy != nullptr) {
                    return proxy->propagateInputEvent(event);
                }
                return false;
            }
    };
}

#endif // SUB_VIEWPORT_CONTAINER_H