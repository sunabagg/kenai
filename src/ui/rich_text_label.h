#ifndef RICH_TEXT_LABEL_H
#define RICH_TEXT_LABEL_H

#include <godot_cpp/classes/rich_text_label.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define RichTextLabelNode godot::RichTextLabel

#include "control.h"
#include "../core/texture2d.h"
#include "../core/font.h"
#include "../desktop/popup_menu.h"
#include "v_scroll_bar.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindRichTextLabel(sol::state &lua);

    class RichTextLabel;

    class RichTextLabelProxy : public RichTextLabelNode {
        GDCLASS(RichTextLabelProxy, RichTextLabelNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to RichTextLabelProxy
            }
        public:
            lucidware::ui::RichTextLabel* element = nullptr;

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

    class RichTextLabelSignalWrapper : public Object {
        GDCLASS(RichTextLabelSignalWrapper, Object);
        protected:
            static void _bind_methods();
        public:
            lucidware::ui::RichTextLabel* element = nullptr;

            RichTextLabelSignalWrapper() = default;
            ~RichTextLabelSignalWrapper() = default;

            void finished();
            void meta_clicked(const Variant& meta);
            void meta_hover_ended(const Variant& meta);
            void meta_hover_started(const Variant& meta);
    };

    class RichTextLabel : public Control {
        private:
            RichTextLabelNode* rich_text_label = nullptr; // Pointer to the RichTextLabel instance
            RichTextLabelSignalWrapper* richTextLabelSignalWrapper = nullptr;

            void connectRichTextLabelSignals() {
                if (this->richTextLabelSignalWrapper == nullptr) {
                    this->richTextLabelSignalWrapper = memnew(RichTextLabelSignalWrapper);
                    this->richTextLabelSignalWrapper->element = this;
                }
                this->rich_text_label->connect("finished", Callable(this->richTextLabelSignalWrapper, "finished"));
                this->rich_text_label->connect("meta_clicked", Callable(this->richTextLabelSignalWrapper, "meta_clicked"));
                this->rich_text_label->connect("meta_hover_ended", Callable(this->richTextLabelSignalWrapper, "meta_hover_ended"));
                this->rich_text_label->connect("meta_hover_started", Callable(this->richTextLabelSignalWrapper, "meta_hover_started"));
            }
        public:
            // Constructor with Node* parameter
            RichTextLabel(RichTextLabelNode* p_node) {
                setRichTextLabel(p_node);
            }
        
            // Constructor with no parameters
            RichTextLabel() {
                setRichTextLabel(memnew(RichTextLabelNode));
                onInit();
            }

            // Getter for the RichTextLabel node
            RichTextLabelNode* getRichTextLabel() {
                return rich_text_label;
            }

            // Setter for the RichTextLabel node
            void setRichTextLabel(RichTextLabelNode* p_node) {
                rich_text_label = p_node;
                connectRichTextLabelSignals();
                setControl(rich_text_label);
            }

            void setRichTextLabel(RichTextLabelProxy* p_node) {
                rich_text_label = p_node;
                p_node->element = this;
                connectRichTextLabelSignals();
                setControl(p_node);
            }

            int getAutowrapMode() const {
                return rich_text_label->get_autowrap_mode();
            }

            void setAutowrapMode(int mode) {
                rich_text_label->set_autowrap_mode(static_cast<TextServer::AutowrapMode>(mode));
            }

            bool getBbcodeEnabled() const {
                return rich_text_label->is_using_bbcode();
            }

            void setBbcodeEnabled(bool enabled) {
                rich_text_label->set_use_bbcode(enabled);
            }

            bool getClipContents() const {
                return rich_text_label->is_clipping_contents();
            }

            void setClipContents(bool enabled) {
                rich_text_label->set_clip_contents(enabled);
            }

            bool getContextMenuEnabled() const {
                return rich_text_label->is_context_menu_enabled();
            }

            void setContextMenuEnabled(bool enabled) {
                rich_text_label->set_context_menu_enabled(enabled);
            }

            Array getCustomEffects() const {
                return rich_text_label->get_effects();
            }

            void setCustomEffects(const Array& effects) {
                rich_text_label->set_effects(effects);
            }

            bool getDeselectOnFocusLossEnabled() const {
                return rich_text_label->is_deselect_on_focus_loss_enabled();
            }

            void setDeselectOnFocusLossEnabled(bool enabled) {
                rich_text_label->set_deselect_on_focus_loss_enabled(enabled);
            }

            bool getDragAndDropSelectionEnabled() const {
                return rich_text_label->is_drag_and_drop_selection_enabled();
            }

            void setDragAndDropSelectionEnabled(bool enabled) {
                rich_text_label->set_drag_and_drop_selection_enabled(enabled);
            }

            bool getFitContent() const {
                return rich_text_label->is_fit_content_enabled();
            }

            void setFitContent(bool enabled) {
                rich_text_label->set_fit_content(enabled);
            }

            bool getHintUnderlined() const {
                return rich_text_label->is_hint_underlined();
            }

            void setHintUnderlined(bool enabled) {
                rich_text_label->set_hint_underline(enabled);
            }

            int getHorizontalAlignment() const {
                return rich_text_label->get_horizontal_alignment();
            }

            void setHorizontalAlignment(int alignment) {
                rich_text_label->set_horizontal_alignment(static_cast<HorizontalAlignment>(alignment));
            }

            int getJustificationFlags() const {
                return rich_text_label->get_justification_flags();
            }

            void setJustificationFlags(int flags) {
                rich_text_label->set_justification_flags(static_cast<BitField<TextServer::JustificationFlag>>(flags));
            }

            std::string getLanguage() const {
                return rich_text_label->get_language().utf8().get_data();
            }

            void setLanguage(const std::string& language) {
                rich_text_label->set_language(String(language.c_str()));
            }

            bool getMetaUnderlined() const {
                return rich_text_label->is_meta_underlined();
            }

            void setMetaUnderlined(bool enabled) {
                rich_text_label->set_meta_underline(enabled);
            }

            int getProgressBarDelay() const {
                return rich_text_label->get_progress_bar_delay();
            }

            void setProgressBarDelay(int delay) {
                rich_text_label->set_progress_bar_delay(delay);
            }

            bool getScrollActive() const {
                return rich_text_label->is_scroll_active();
            }

            void setScrollActive(bool active) {
                rich_text_label->set_scroll_active(active);
            }

            bool getScrollFollowing() const {
                return rich_text_label->is_scroll_following();
            }

            void setScrollFollowing(bool following) {
                rich_text_label->set_scroll_follow(following);
            }

            bool getSelectionEnabled() const {
                return rich_text_label->is_selection_enabled();
            }

            void setSelectionEnabled(bool enabled) {
                rich_text_label->set_selection_enabled(enabled);
            }

            bool getShortcutKeysEnabled() const {
                return rich_text_label->is_shortcut_keys_enabled();
            }

            void setShortcutKeysEnabled(bool enabled) {
                rich_text_label->set_shortcut_keys_enabled(enabled);
            }

            int getStructuredTextBidiOverride() const {
                return rich_text_label->get_structured_text_bidi_override();
            }

            void setStructuredTextBidiOverride(int override) {
                rich_text_label->set_structured_text_bidi_override(static_cast<TextServer::StructuredTextParser>(override));
            }

            Array getStructuredTextBidiOverrideOptions() const {
                return rich_text_label->get_structured_text_bidi_override_options();
            }

            void setStructuredTextBidiOverrideOptions(const Array& options) {
                rich_text_label->set_structured_text_bidi_override_options(options);
            }

            int getTabSize() const {
                return rich_text_label->get_tab_size();
            }

            void setTabSize(int size) {
                rich_text_label->set_tab_size(size);
            }

            std::vector<float> getTabStops() const {
                PackedFloat32Array stops_pf32a = rich_text_label->get_tab_stops();
                std::vector<float> stops;
                for (int i = 0; i < stops_pf32a.size(); ++i) {
                    stops.push_back(stops_pf32a[i]);
                }
                return stops;
            }

            void setTabStops(const std::vector<float>& stops) {
                PackedFloat32Array stops_pf32a;
                for (const float& stop : stops) {
                    stops_pf32a.push_back(stop);
                }
                rich_text_label->set_tab_stops(stops_pf32a);
            }

            std::string getText() const {
                return rich_text_label->get_text().utf8().get_data();
            }

            void setText(const std::string& text) {
                rich_text_label->set_text(String(text.c_str()));
            }

            int getTextDirection() const {
                return rich_text_label->get_text_direction();
            }

            void setTextDirection(int direction) {
                rich_text_label->set_text_direction(static_cast<ControlNode::TextDirection>(direction));
            }

            bool getThreaded() {
                return rich_text_label->is_threaded();
            }

            void setThreaded(bool threaded) {
                rich_text_label->set_threaded(threaded);
            }

            int getVerticalAlignment() const {
                return rich_text_label->get_vertical_alignment();
            }

            void setVerticalAlignment(int alignment) {
                rich_text_label->set_vertical_alignment(static_cast<VerticalAlignment>(alignment));
            }

            int getVisibleCharacters() const {
                return rich_text_label->get_visible_characters();
            }

            void setVisibleCharacters(int count) {
                rich_text_label->set_visible_characters(count);
            }

            int getVisibleCharactersBehavior() const {
                return rich_text_label->get_visible_characters_behavior();
            }

            void setVisibleCharactersBehavior(int behavior) {
                rich_text_label->set_visible_characters_behavior(static_cast<TextServer::VisibleCharactersBehavior>(behavior));
            }

            float getVisibleRatio() const {
                return rich_text_label->get_visible_ratio();
            }

            void setVisibleRatio(float ratio) {
                rich_text_label->set_visible_ratio(ratio);
            }

            Event* finishedEvent = new Event();
            Event* getFinishedEvent() {
                return finishedEvent;
            }
            void setFinishedEvent(Event* event) {
                finishedEvent = event;
            }

            Event* metaClickedEvent = new Event();
            Event* getMetaClickedEvent() {
                return metaClickedEvent;
            }
            void setMetaClickedEvent(Event* event) {
                metaClickedEvent = event;
            }

            Event* metaHoverEndedEvent = new Event();
            Event* getMetaHoverEndedEvent() {
                return metaHoverEndedEvent;
            }
            void setMetaHoverEndedEvent(Event* event) {
                metaHoverEndedEvent = event;
            }

            Event* metaHoverStartedEvent = new Event();
            Event* getMetaHoverStartedEvent() {
                return metaHoverStartedEvent;
            }
            void setMetaHoverStartedEvent(Event* event) {
                metaHoverStartedEvent = event;
            }

            void addImage(lucidware::core::Texture2D* image, int width = 0, int height = 0, Color color = Color(1, 1, 1, 1), int inlineAlign = 5, Rect2 region = Rect2(0, 0, 0, 0), Variant key = Variant(), bool pad = false, std::string tooltip = "''", bool sizeInPercent = false) {
                rich_text_label->add_image(image->getTexture2D(), width, height, color, static_cast<InlineAlignment>(inlineAlign), region, key, pad, String(tooltip.c_str()), sizeInPercent);
            }

            void addText(const std::string& text) {
                rich_text_label->add_text(String(text.c_str()));
            }

            void appendText(const std::string& bbcode) {
                rich_text_label->add_text(String(bbcode.c_str()));
            }

            void clear() {
                rich_text_label->clear();
            }

            void deselect() {
                rich_text_label->deselect();
            }

            int getCharacterLine(int character) const {
                return rich_text_label->get_character_line(character);
            }

            int getCharacterParagraph(int character) const {
                return rich_text_label->get_character_paragraph(character);
            }

            int getContentHeight() const {
                return rich_text_label->get_content_height();
            }

            int getContentWidth() const {
                return rich_text_label->get_content_width();
            }

            int getLineCount() const {
                return rich_text_label->get_line_count();
            }

            float getLineOffset(int line) const {
                return rich_text_label->get_line_offset(line);
            }

            Vector2i getLineRange(int line) const {
                return rich_text_label->get_line_range(line);
            }

            lucidware::desktop::PopupMenu* getMenu() {
                return new lucidware::desktop::PopupMenu(rich_text_label->get_menu());
            }

            int getParagraphCount() const {
                return rich_text_label->get_paragraph_count();
            }

            float getParagraphOffset(int paragraph) const {
                return rich_text_label->get_paragraph_offset(paragraph);
            }

            std::string getParsedText() const {
                return rich_text_label->get_parsed_text().utf8().get_data();
            }

            std::string getSelectedText() const {
                return rich_text_label->get_selected_text().utf8().get_data();
            }

            int getSelectionFrom() const {
                return rich_text_label->get_selection_from();
            }

            float getSelectionLineOffset() const {
                return rich_text_label->get_selection_line_offset();
            }

            int getSelectionTo() const {
                return rich_text_label->get_selection_to();
            }

            int getTotalCharacterCount() const {
                return rich_text_label->get_total_character_count();
            }

            VScrollBar* getVScrollBar() {
                return new VScrollBar(rich_text_label->get_v_scroll_bar());
            }

            int getVisibleLineCount() const {
                return rich_text_label->get_visible_line_count();
            }

            int getVisibleParagraphCount() const {
                return rich_text_label->get_visible_paragraph_count();
            }

            void installEffect(Variant effect) {
                rich_text_label->install_effect(effect);
            }

            bool invalidateParagraph(int paragraph) {
                return rich_text_label->invalidate_paragraph(paragraph);
            }

            bool isFinished() const {
                return rich_text_label->is_finished();
            }

            bool isMenuVisible() const {
                return rich_text_label->is_menu_visible();
            }

            bool isReady() const {
                return rich_text_label->is_ready();
            }

            void menuOption(int option) {
                rich_text_label->menu_option(option);
            }

            void newline() {
                rich_text_label->newline();
            }

            void parseBBCode(const std::string& bbcode) {
                rich_text_label->parse_bbcode(String(bbcode.c_str()));
            }

            Dictionary parseExpressionsForValues(std::vector<std::string> expressions) {
                PackedStringArray expressions_psa;
                for (const std::string& expr : expressions) {
                    expressions_psa.push_back(String(expr.c_str()));
                }
                return rich_text_label->parse_expressions_for_values(expressions_psa);
            }

            void pop() {
                rich_text_label->pop();
            }

            void popAll() {
                rich_text_label->pop_all();
            }

            void popContext() {
                rich_text_label->pop_context();
            }

            void pushBgcolor(const Color& bgcolor) {
                rich_text_label->push_bgcolor(bgcolor);
            }

            void pushBold() {
                rich_text_label->push_bold();
            }

            void pushBoldItalics() {
                rich_text_label->push_bold_italics();
            }

            void pushCell() {
                rich_text_label->push_cell();
            }

            void pushColor(const Color& color) {
                rich_text_label->push_color(color);
            }

            void pushContext() {
                rich_text_label->push_context();
            }

            //void pushCustomfx

            void pushDropcap(std::string string, lucidware::core::Font* font, int size, Rect2 dropcapMargins = Rect2(0, 0, 0, 0), Color color = Color(1, 1, 1, 1), int outlineSize = 0, Color outlineColor = Color(0, 0, 0, 0)) {
                rich_text_label->push_dropcap(String(string.c_str()), font->getFont(), size, dropcapMargins, color, outlineSize, outlineColor);
            }

            void pushFgcolor(const Color& fgcolor) {
                rich_text_label->push_fgcolor(fgcolor);
            }

            void pushFont(lucidware::core::Font* font, int fontSize = 0) {
                rich_text_label->push_font(font->getFont(), fontSize);
            }

            void pushFontSize(int fontSize) {
                rich_text_label->push_font_size(fontSize);
            }

            void pushHint(const std::string& description) {
                rich_text_label->push_hint(String(description.c_str()));
            }

            void pushIndent(int level) {
                rich_text_label->push_indent(level);
            }

            void pushItalics() {
                rich_text_label->push_italics();
            }

            void pushLanguage(const std::string& language) {
                rich_text_label->push_language(String(language.c_str()));
            }

            void pushList(int level, int type, bool capitalize, const std::string& bullet = "•") {
                rich_text_label->push_list(level, static_cast<RichTextLabelNode::ListType>(type), capitalize, String(bullet.c_str()));
            }

            void pushMeta(const Variant& data, int underlineMode = 1, const std::string& tooltip = "") {
                rich_text_label->push_meta(data, static_cast<RichTextLabelNode::MetaUnderline>(underlineMode), String(tooltip.c_str()));
            }

            void pushMono() {
                rich_text_label->push_mono();
            }

            void pushNormal() {
                rich_text_label->push_normal();
            }

            void pushOutlineColor(const Color& color) {
                rich_text_label->push_outline_color(color);
            }

            void pushOutlineSize(int outlineSize) {
                rich_text_label->push_outline_size(outlineSize);
            }

            void pushParagraph(int alignment, int baseDirection = 0, const std::string& language = "", int structuredTextParser = 0, int justificationFlags = 163, const std::vector<float>& tabStops = {}) {
                PackedFloat32Array tabStops_pf32a;
                for (const float& stop : tabStops) {
                    tabStops_pf32a.push_back(stop);
                }
                rich_text_label->push_paragraph(static_cast<HorizontalAlignment>(alignment), static_cast<ControlNode::TextDirection>(baseDirection), String(language.c_str()), static_cast<TextServer::StructuredTextParser>(structuredTextParser), static_cast<BitField<TextServer::JustificationFlag>>(justificationFlags), tabStops_pf32a);
            }

            void pushStrikethrough() {
                rich_text_label->push_strikethrough();
            }

            void pushTable(int columns, int inlineAlign = 0, int alignToRow = -1) {
                rich_text_label->push_table(columns, static_cast<InlineAlignment>(inlineAlign), alignToRow);
            }

            void pushUnderline() {
                rich_text_label->push_underline();
            }

            bool removeParagraph(int paragraph, bool noInvalidate = false) {
                return rich_text_label->remove_paragraph(paragraph, noInvalidate);
            }

            void scrollToLine(int line) {
                rich_text_label->scroll_to_line(line);
            }

            void scrollToParagraph(int paragraph) {
                rich_text_label->scroll_to_paragraph(paragraph);
            }

            void scrollToSelection() {
                rich_text_label->scroll_to_selection();
            }

            void selectAll() {
                rich_text_label->select_all();
            }

            void setCellBorderColor(const Color& color) {
                rich_text_label->set_cell_border_color(color);
            }

            void setCellPadding(Rect2 padding) {
                rich_text_label->set_cell_padding(padding);
            }

            void setCellRowBackgroundColor(const Color& oddRowBg, const Color& evenRowBg) {
                rich_text_label->set_cell_row_background_color(oddRowBg, evenRowBg);
            }

            void setCellSizeOverride(Vector2 minSize, Vector2 maxSize) {
                rich_text_label->set_cell_size_override(minSize, maxSize);
            }

            void setTableColumnExpand(int column, bool expand, int ratio = 1, bool shrink = true) {
                rich_text_label->set_table_column_expand(column, expand, ratio, shrink);
            }

            void updateImage(Variant key, int mask, lucidware::core::Texture2D* image, int width = 0, int height = 0, Color color = Color(1, 1, 1, 1), int inlineAlign = 5, Rect2 region = Rect2(0, 0, 0, 0), bool pad = false, std::string tooltip = "", bool sizeInPercent = false) {
                rich_text_label->update_image(key, mask, image->getTexture2D(), width, height, color, static_cast<InlineAlignment>(inlineAlign), region, pad, String(tooltip.c_str()), sizeInPercent);
            }

            void onFree() override {
                if (richTextLabelSignalWrapper) {
                    memdelete(richTextLabelSignalWrapper);
                    richTextLabelSignalWrapper = nullptr;
                }
                Control::onFree();
            }
    };
}

#endif // RICH_TEXT_LABEL_H