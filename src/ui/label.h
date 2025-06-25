#ifndef LABEL_H
#define LABEL_H

#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define LabelNode godot::Label

#include "control.h"
#include "../core/label_settings.h"

namespace lucidfx::ui {
    void bindLabel(sol::state &lua);

    class Label;

    class LabelProxy : public LabelNode {
        GDCLASS(LabelProxy, LabelNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to LabelProxy
            }
        public:
            lucidfx::ui::Label* element = nullptr;

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
    };

    class Label : public Control {
        private:
            LabelNode* label_node = nullptr;

        public:
            Label() {
                setLabelNode(memnew(LabelNode));
                onInit();
            }

            Label(LabelNode* label) {
                setLabelNode(label);
            }

            LabelNode* getLabelNode() {
                return label_node;
            }

            void setLabelNode(LabelNode* node) {
                label_node = node;
                setControl(label_node);
            }

            void setLabelNode(LabelProxy* node) {
                label_node = node;
                node->element = this;
                setControl(label_node);
            }

            int getAutowrapMode() {
                return label_node->get_autowrap_mode();
            }

            void setAutowrapMode(int mode) {
                label_node->set_autowrap_mode(static_cast<godot::TextServer::AutowrapMode>(mode));
            }

            bool getClipText() {
                return label_node->is_clipping_text();
            }

            void setClipText(bool enable) {
                label_node->set_clip_text(enable);
            }

            std::string getEllipsisChar() {
                return label_node->get_ellipsis_char().utf8().get_data();
            }

            void setEllipsisChar(std::string character) {
                label_node->set_ellipsis_char(String(character.c_str()));
            }

            int getHorizontalAlignment() {
                return label_node->get_horizontal_alignment();
            }

            void setHorizontalAlignment(int alignment) {
                label_node->set_horizontal_alignment(static_cast<godot::HorizontalAlignment>(alignment));
            }

            int getJustificationFlags() {
                return label_node->get_justification_flags();
            }

            void setJustificationFlags(int flags) {
                label_node->set_justification_flags(static_cast<godot::BitField<godot::TextServer::JustificationFlag>>(flags));
            }

            lucidfx::core::LabelSettings* getLabelSettings() {
                Ref<godot::LabelSettings> settings = label_node->get_label_settings();
                return new lucidfx::core::LabelSettings(settings.ptr());
            }

            void setLabelSettings(lucidfx::core::LabelSettings* settings) {
                Ref<godot::LabelSettings> settingsRef = Ref<godot::LabelSettings>(settings->getLabelSettings());
                label_node->set_label_settings(settingsRef);
            }

            std::string getLanguage() {
                return label_node->get_language().utf8().get_data();
            }

            void setLanguage(std::string language) {
                label_node->set_language(String(language.c_str()));
            }

            int getLinesSkipped() {
                return label_node->get_lines_skipped();
            }

            void setLinesSkipped(int lines) {
                label_node->set_lines_skipped(lines);
            }

            int getMaxLinesVisible() {
                return label_node->get_max_lines_visible();
            }

            void setMaxLinesVisible(int lines) {
                label_node->set_max_lines_visible(lines);
            }

            int getMouseFilter() {
                return label_node->get_mouse_filter();
            }

            void setMouseFilter(int filter) {
                label_node->set_mouse_filter(static_cast<godot::Control::MouseFilter>(filter));
            }

            std::string getParagraphSeparator() {
                return label_node->get_paragraph_separator().utf8().get_data();
            }

            void setParagraphSeparator(std::string separator) {
                label_node->set_paragraph_separator(String(separator.c_str()));
            }

            int getSizeFlagsVertical() {
                return label_node->get_v_size_flags();
            }

            void setSizeFlagsVertical(int flags) {
                label_node->set_v_size_flags(static_cast<godot::Control::SizeFlags>(flags));
            }

            int getStructuredTextBidiOverride() {
                return label_node->get_structured_text_bidi_override();
            }

            void setStructuredTextBidiOverride(int override) {
                label_node->set_structured_text_bidi_override(static_cast<godot::TextServer::StructuredTextParser>(override));
            }

            Array getStructuredTextBidiOverrideOptions() {
                return label_node->get_structured_text_bidi_override_options();
            }

            void setStructuredTextBidiOverrideOptions(Array options) {
                label_node->set_structured_text_bidi_override_options(options);
            } 

            std::vector<float> getTabStops() {
                PackedFloat32Array tabStops = label_node->get_tab_stops();
                std::vector<float> result;
                for (int i = 0; i < tabStops.size(); i++) {
                    result.push_back(tabStops[i]);
                }
                return result;
            }

            void setTabStops(std::vector<float> stops) {
                PackedFloat32Array tabStops;
                for (size_t i = 0; i < stops.size(); i++) {
                    tabStops.push_back(stops[i]);
                }
                label_node->set_tab_stops(tabStops);
            }

            std::string getText() {
                return label_node->get_text().utf8().get_data();
            }

            void setText(std::string text) {
                label_node->set_text(String(text.c_str()));
            }

            int getTextDirection() {
                return label_node->get_text_direction();
            }

            void setTextDirection(int direction) {
                label_node->set_text_direction(static_cast<godot::Control::TextDirection>(direction));
            }

            int getTextOverrunBehavior() {
                return label_node->get_text_overrun_behavior();
            }

            void setTextOverrunBehavior(int behavior) {
                label_node->set_text_overrun_behavior(static_cast<godot::TextServer::OverrunBehavior>(behavior));
            }

            bool getUppercase() {
                return label_node->is_uppercase();
            }

            void setUppercase(bool enable) {
                label_node->set_uppercase(enable);
            }

            int getVerticalAlignment() {
                return label_node->get_vertical_alignment();
            }

            void setVerticalAlignment(int alignment) {
                label_node->set_vertical_alignment(static_cast<godot::VerticalAlignment>(alignment));
            }

            int getVisibleCharacters() {
                return label_node->get_visible_characters();
            }

            void setVisibleCharacters(int characters) {
                label_node->set_visible_characters(characters);
            }

            int getVisibleCharactersBehavior() {
                return label_node->get_visible_characters_behavior();
            }

            void setVisibleCharactersBehavior(int behavior) {
                label_node->set_visible_characters_behavior(static_cast<godot::TextServer::VisibleCharactersBehavior>(behavior));
            }

            float getVisibleRatio() {
                return label_node->get_visible_ratio();
            }

            void setVisibleRatio(float ratio) {
                label_node->set_visible_ratio(ratio);
            }

            Rect2 getCharacterBounds(int position) {
                return label_node->get_character_bounds(position);
            }

            int getLineCount() {
                return label_node->get_line_count();
            }

            int getLineHeight(int line = -1) {
                return label_node->get_line_height(line);
            }

            int getTotalCharacterCount() {
                return label_node->get_total_character_count();
            }

            int getVisibleLineCount() {
                return label_node->get_visible_line_count();
            }
    };
}

#endif // LABEL_H