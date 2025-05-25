#ifndef TREE_H
#define TREE_H

#include <godot_cpp/classes/tree.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTree godot::Tree

#include "control.h"
#include "tree_item.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTree(sol::state& lua);

    class Tree;

    class TreeProxy : public GodotTree {
        public:
            sunaba::ui::Tree* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override;
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
    };

    class Tree : public Control {
        private:
            GodotTree* tree = nullptr; // Pointer to the Tree instance

            void connectSignals() {
            }
        public:
            // Constructor with GodotTree parameter
            Tree(GodotTree* t) {
                setTree(t);
            }

            // Constructor with no parameters
            Tree() {
                setTree(memnew(TreeProxy));
                onInit();
            }

            // Getter for the Tree node
            GodotTree* getTree() const {
                return tree;
            }

            // Setter for the Tree node
            void setTree(GodotTree* t) {
                tree = t;
                connectSignals();
                setControl(t);
            }

            bool getAllowReselect() const {
                return tree->get_allow_reselect();
            }

            void setAllowReselect(bool allow) {
                tree->set_allow_reselect(allow);
            }

            bool getAllowRmbSelect() const {
                return tree->get_allow_rmb_select();
            }

            void setAllowRmbSelect(bool allow) {
                tree->set_allow_rmb_select(allow);
            }

            bool getAllowSearch() const {
                return tree->get_allow_search();
            }

            void setAllowSearch(bool allow) {
                tree->set_allow_search(allow);
            }
    };
}

#endif // TREE_H