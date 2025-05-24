#ifndef TEXTURE_PROGRESS_BAR_H
#define TEXTURE_PROGRESS_BAR_H

#include <godot_cpp/classes/texture_progress_bar.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define TextureProgressBarNode godot::TextureProgressBar

#include "range.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTextureProgressBar(sol::state &lua);

    class TextureProgressBar;

    class TextureProgressBarProxy : public TextureProgressBarNode {
        public:
            sunaba::ui::TextureProgressBar* element = nullptr;

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

            void _value_changed(double p_new_value) override;
    };

    class TextureProgressBar : public Range {
        private:
            TextureProgressBarNode* proxy = nullptr;

        public:
            TextureProgressBar() {
                setTextureProgressBar(memnew(TextureProgressBarProxy));
                onInit();
            }

            TextureProgressBar(TextureProgressBarNode* p_node) {
                setTextureProgressBar(p_node);
            }

            void setTextureProgressBar(TextureProgressBarNode* p_node) {
                proxy = p_node;
                setRange(p_node);
            }

            TextureProgressBar(TextureProgressBarProxy* p_node) {
                proxy = p_node;
                p_node->element = this;
                setRange(p_node);
            }
    };
}

#endif // TEXTURE_PROGRESS_BAR_H