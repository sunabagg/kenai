#ifndef GRID_CONTAINER_H
#define GRID_CONTAINER_H

#include <godot_cpp/classes/grid_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GridContainerNode godot::GridContainer

#include "container.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::ui {
    void bindGridContainer(sol::state &lua);

    class GridContainer;

    class GridContainerProxy : public GridContainerNode {
        GDCLASS(GridContainerProxy, GridContainerNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to GridContainerProxy
            }
        public:
            lucidfx::ui::GridContainer* element = nullptr;

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

    class GridContainer : public Container {
        private:
            GridContainerNode* grid_container = nullptr; // Pointer to the GridContainer instance

            void connectGridContainerSignals() {
                // Connect signals specific to GridContainer
            }

        public:
            GridContainer() {
                setGridContainer(memnew(GridContainerNode));
                onInit();
            }

            GridContainer(GridContainerNode* grid_container) {
                setGridContainer(grid_container);
            }

            GridContainerNode* getGridContainer() {
                return grid_container;
            }

            void setGridContainer(GridContainerNode* grid_container) {
                this->grid_container = grid_container;
                connectGridContainerSignals();
                setControl(grid_container);
            }

            void setGridContainer(GridContainerProxy* grid_container) {
                this->grid_container = grid_container;
                grid_container->element = this;
                connectGridContainerSignals();
                setControl(grid_container);
            }

            int getColumns() {
                return grid_container->get_columns();
            }

            void setColumns(int columns) {
                grid_container->set_columns(columns);
            }
    };
}

#endif // GRID_CONTAINER_H