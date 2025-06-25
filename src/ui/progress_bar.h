#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <godot_cpp/classes/progress_bar.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ProgressBarNode godot::ProgressBar

#include "range.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::ui {
    void bindProgressBar(sol::state& lua);

    class ProgressBar;

    class ProgressBarProxy : public ProgressBarNode {
        GDCLASS(ProgressBarProxy, ProgressBarNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to ProgressBarProxy
            }
        public:
            lucidfx::ui::ProgressBar* element = nullptr;

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

            void _value_changed(double value) override;
    };

    class ProgressBar : public lucidfx::ui::Range {
        private:
            ProgressBarNode* progressBar = nullptr; // Pointer to the ProgressBar instance
            void connectProgressBarSignals() {
                // Connect signals specific to ProgressBar
            }

        public:
            ProgressBar() {
                setProgressBar(memnew(ProgressBarNode));
                onInit();
            }

            ProgressBar(ProgressBarNode* p_node) {
                setProgressBar(p_node);
                onInit();
            }

            ProgressBarNode* getProgressBar() {
                return progressBar;
            }

            void setProgressBar(ProgressBarNode* p_node) {
                progressBar = p_node;
                connectProgressBarSignals();
                setRange(p_node);
            }

            void setProgressBar(ProgressBarProxy* p_node) {
                progressBar = p_node;
                p_node->element = this;
                connectProgressBarSignals();
                setRange(p_node);
            }

            bool isEditorPreviewIndeterminate() {
                return progressBar->is_editor_preview_indeterminate_enabled();
            }

            void setEditorPreviewIndeterminate(bool enabled) {
                progressBar->set_editor_preview_indeterminate(enabled);
            }

            int getFillMode() {
                return progressBar->get_fill_mode();
            }

            void setFillMode(int mode) {
                progressBar->set_fill_mode(static_cast<ProgressBarNode::FillMode>(mode));
            }

            bool getIndeterminate() {
                return progressBar->is_indeterminate();
            }

            void setIndeterminate(bool indeterminate) {
                progressBar->set_indeterminate(indeterminate);
            }

            bool getShowPercentage() {
                return progressBar->is_percentage_shown();
            }

            void setShowPercentage(bool show) {
                progressBar->set_show_percentage(show);
            }
    };
}

#endif // PROGRESS_BAR_H