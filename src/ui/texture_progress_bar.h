#ifndef TEXTURE_PROGRESS_BAR_H
#define TEXTURE_PROGRESS_BAR_H

#include <godot_cpp/classes/texture_progress_bar.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define TextureProgressBarNode godot::TextureProgressBar

#include "range.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace kenai::core;

namespace kenai::ui {
    void bindTextureProgressBar(sol::state &lua);

    class TextureProgressBar;

    class TextureProgressBarProxy : public TextureProgressBarNode {
        GDCLASS(TextureProgressBarProxy, TextureProgressBarNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to TextureProgressBarProxy
            }
        public:
            kenai::ui::TextureProgressBar* element = nullptr;

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
                setTextureProgressBar(memnew(TextureProgressBarNode));
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

            int getFillMode() const {
                return proxy->get_fill_mode();
            }

            void setFillMode(int mode) {
                proxy->set_fill_mode(mode);
            }

            int getMouseFilter() const {
                return proxy->get_mouse_filter();
            }

            void setMouseFilter(int filter) {
                proxy->set_mouse_filter(static_cast<TextureProgressBarNode::MouseFilter>(filter));
            }

            bool getNinePatchStretch() const {
                return proxy->get_nine_patch_stretch();
            }

            void setNinePatchStretch(bool stretch) {
                proxy->set_nine_patch_stretch(stretch);
            }

            Vector2 getRadialCenterOffset() const {
                return proxy->get_radial_center_offset();
            }
            void setRadialCenterOffset(const Vector2 &offset) {
                proxy->set_radial_center_offset(offset);
            }

            float getRadialFillDegrees() const {
                return proxy->get_fill_degrees();
            }
            
            void setRadialFillDegrees(float degrees) {
                proxy->set_fill_degrees(degrees);
            }

            float getRadialInitialAngle() const {
                return proxy->get_radial_initial_angle();
            }

            void setRadialInitialAngle(float angle) {
                proxy->set_radial_initial_angle(angle);
            }

            int getSizeFlagsVertical() const {
                return proxy->get_v_size_flags();
            }

            void setSizeFlagsVertical(int flags) {
                proxy->set_v_size_flags(static_cast<ControlNode::SizeFlags>(flags));
            }

            float getStep() const {
                return proxy->get_step();
            }

            void setStep(float value) {
                proxy->set_step(value);
            }

            int getStretchMarginBottom() const {
                return proxy->get_stretch_margin(Side::SIDE_BOTTOM);
            }

            void setStretchMarginBottom(int value) {
                proxy->set_stretch_margin(Side::SIDE_BOTTOM, value);
            }

            int getStretchMarginLeft() const {
                return proxy->get_stretch_margin(Side::SIDE_LEFT);
            }

            void setStretchMarginLeft(int value) {
                proxy->set_stretch_margin(Side::SIDE_LEFT, value);
            }

            int getStretchMarginRight() const {
                return proxy->get_stretch_margin(Side::SIDE_RIGHT);
            }

            void setStretchMarginRight(int value) {
                proxy->set_stretch_margin(Side::SIDE_RIGHT, value);
            }

            int getStretchMarginTop() const {
                return proxy->get_stretch_margin(Side::SIDE_TOP);
            }

            void setStretchMarginTop(int value) {
                proxy->set_stretch_margin(Side::SIDE_TOP, value);
            }
            
            kenai::core::Texture2D* getTextureOver() {
                return new kenai::core::Texture2D(proxy->get_over_texture().ptr());
            }

            void setTextureOver(kenai::core::Texture2D* texture) {
                proxy->set_over_texture(texture->getTexture2D());
            }

            kenai::core::Texture2D* getTextureProgress() {
                return new kenai::core::Texture2D(proxy->get_progress_texture().ptr());
            }

            void setTextureProgress(kenai::core::Texture2D* texture) {
                proxy->set_progress_texture(texture->getTexture2D());
            }

            Vector2 getTextureProgressOffset() const {
                return proxy->get_texture_progress_offset();
            }

            void setTextureProgressOffset(const Vector2 &offset) {
                proxy->set_texture_progress_offset(offset);
            }

            kenai::core::Texture2D* getTextureUnder() {
                return new kenai::core::Texture2D(proxy->get_under_texture().ptr());
            }

            void setTextureUnder(kenai::core::Texture2D* texture) {
                proxy->set_under_texture(texture->getTexture2D());
            }

            Color getTintOver() const {
                return proxy->get_tint_over();
            }

            void setTintOver(const Color &tint) {
                proxy->set_tint_over(tint);
            }

            Color getTintProgress() const {
                return proxy->get_tint_progress();
            }

            void setTintProgress(const Color &tint) {
                proxy->set_tint_progress(tint);
            }

            Color getTintUnder() const {
                return proxy->get_tint_under();
            }

            void setTintUnder(const Color &tint) {
                proxy->set_tint_under(tint);
            }

            int getStretchMargin(int side) {
                return proxy->get_stretch_margin(static_cast<Side>(side));
            }

            void setStretchMargin(int side, int value) {
                proxy->set_stretch_margin(static_cast<Side>(side), value);
            }
    };
}

#endif // TEXTURE_PROGRESS_BAR_H