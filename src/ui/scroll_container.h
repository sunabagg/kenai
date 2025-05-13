#ifndef SCROLL_CONTAINER_H
#define SCROLL_CONTAINER_H

#include <godot_cpp/classes/scroll_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ScrollContainerNode godot::ScrollContainer

#include "container.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindScrollContainer(sol::state& lua);

    class ScrollContainer;
    class ScrollContainerProxy : public ScrollContainerNode {
        public:
            sunaba::ui::ScrollContainer* element = nullptr;

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

    class ScrollContainer : public sunaba::ui::Container {
        private:
            ScrollContainerNode* scrollContainer = nullptr; // Pointer to the ScrollContainer instance

            void connectScrollContainerSignals() {
                // Connect signals specific to ScrollContainer
            }

        public:
            ScrollContainer() {
                setScrollContainer(memnew(ScrollContainerProxy));
                onInit();
            }

            ScrollContainer(ScrollContainerNode* p_node) {
                setScrollContainer(p_node);
            }

            ScrollContainerNode* getScrollContainer() {
                return scrollContainer;
            }

            void setScrollContainer(ScrollContainerNode* p_node) {
                scrollContainer = p_node;
                connectScrollContainerSignals();
                setContainer(p_node);
            }

            void setScrollContainer(ScrollContainerProxy* p_node) {
                scrollContainer = p_node;
                p_node->element = this;
                connectScrollContainerSignals();
                setContainer(p_node);
            }

            bool isClippingContents() {
                return scrollContainer->is_clipping_contents();
            }

            void setClipContents(bool value) {
                scrollContainer->set_clip_contents(value);
            }

            bool getDrawFocusBorder() {
                return scrollContainer->get_draw_focus_border();
            }
            
            void setDrawFocusBorder(bool value) {
                scrollContainer->set_draw_focus_border(value);
            }

            bool isFollowingFocus() {
                return scrollContainer->is_following_focus();
            }
    };
}

#endif // SCROLL_CONTAINER_H