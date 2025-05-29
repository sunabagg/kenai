#ifndef RICH_TEXT_LABEL_H
#define RICH_TEXT_LABEL_H

#include <godot_cpp/classes/rich_text_label.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define RichTextLabelNode godot::RichTextLabel

#include "control.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindRichTextLabel(sol::state &lua);

    class RichTextLabel;

    class RichTextLabelProxy : public RichTextLabelNode {
        public:
            sunaba::ui::RichTextLabel* element = nullptr;

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
            sunaba::ui::RichTextLabel* element = nullptr;

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
                setRichTextLabel(memnew(RichTextLabelProxy));
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
    };
}    

#endif // RICH_TEXT_LABEL_H