#ifndef CONTAINER_H
#define CONTAINER_H

#include <godot_cpp/classes/container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ContainerNode godot::Container

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindContainer(sol::state &lua);

    class Container;

    class ContainerProxy : public ContainerNode {
        public:
            sunaba::ui::Container* element = nullptr;

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

    class ContainerSignalWrapper : public NodeSignalWrapper {
        GDCLASS(ContainerSignalWrapper, NodeSignalWrapper)
        protected:
            static void _bind_methods();
        public:
            sunaba::ui::Container* element = nullptr;

            ContainerSignalWrapper() = default;
            ~ContainerSignalWrapper() = default;

            void pre_sort_children();
            void sort_children();
    };

    class Container : public Control {
        private:
            ContainerNode* container = nullptr; // Pointer to the Container instance
            void connectContainerSignals() {
                // Connect signals specific to Container
            }

        public:
            Container() {
                setContainer(memnew(ContainerProxy));
                onInit();
            }

            Container(ContainerNode* container) {
                setContainer(container);
            }

            ContainerNode* getContainer() {
                return container;
            }

            void setContainer(ContainerNode* container) {
                this->container = container;
                connectContainerSignals();
                setControl(container);
            }

            void setContainer(ContainerProxy* container) {
                this->container = container;
                container->element = this;
                connectContainerSignals();
                setControl(container);
            }

            int getMouseFilter() {
                return container->get_mouse_filter();
            }

            void setMouseFilter(int filter) {
                container->set_mouse_filter(static_cast<godot::Control::MouseFilter>(filter));
            }

            Event* preSortChildrenEvent;
            
            Event* getPreSortChildrenEvent() {
                return preSortChildrenEvent;
            }
            void setPreSortChildrenEvent(Event* event) {
                preSortChildrenEvent = event;
            }
            
            Event* sortChildrenEvent;

            Event* getSortChildrenEvent() {
                return sortChildrenEvent;
            }

            void setSortChildrenEvent(Event* event) {
                sortChildrenEvent = event;
            }

            void fitChildInRect(Control* child, const Rect2& rect) {
                container->fit_child_in_rect(child->getControl(), rect);
            }

            void queueSort() {
                container->queue_sort();
            }
            PackedInt32Array getAllowedSizeFlagsHorizontal() const {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["getAllowedSizeFlagsHorizontal"].get<sol::function>();
                    if (func) {
                        auto result = func(scriptInstance);
                        std::vector<int> vec = result.get<std::vector<int>>();
                        PackedInt32Array arr;
                        for (int i = 0; i < vec.size(); ++i) {
                            arr.push_back(vec[i]);
                        }
                        return arr;
                    }
                }
            }

            PackedInt32Array getAllowedSizeFlagsVertical() const {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["getAllowedSizeFlagsVertical"].get<sol::function>();
                    if (func) {
                        auto result = func(scriptInstance);
                        std::vector<int> vec = result.get<std::vector<int>>();
                        PackedInt32Array arr;
                        for (int i = 0; i < vec.size(); ++i) {
                            arr.push_back(vec[i]);
                        }
                        return arr;
                    }
                }
            }
    };
}

#endif // CONTAINER_H
