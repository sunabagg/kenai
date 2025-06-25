#ifndef FONT_VARIATION_H
#define FONT_VARIATION_H

#include <godot_cpp/classes/font_variation.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotFontVariation godot::FontVariation

#include "font.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidfx::core {
    void bindFontVariation(sol::state &lua);

    class FontVariation : public Font {
    private:
        GodotFontVariation* fontVariation = nullptr; // Pointer to the FontVariation instance
    public:
        // Constructor with Ref<GodotFontVariation> parameter
        FontVariation(GodotFontVariation* fontVariation) {
            setFontVariation(fontVariation);
        }

        // Constructor with no parameters
        FontVariation() {
            setFontVariation(memnew(GodotFontVariation));
        }

        // Getter for the FontVariation node
        GodotFontVariation* getFontVariation() {
            return fontVariation;
        }

        // Setter for the FontVariation node
        void setFontVariation(GodotFontVariation* fontVariation) {
            this->fontVariation = fontVariation;
            fontVariation->reference();
            setFont(fontVariation);
        } 
        
        Font* getBaseFont() {
            return new Font(fontVariation->get_base_font().ptr());
        }

        void setBaseFont(Font* baseFont) {
            fontVariation->set_base_font(baseFont->getFont());
        }

        float getBaselineOffset() {
            return fontVariation->get_baseline_offset();
        }

        void setBaselineOffset(float offset) {
            fontVariation->set_baseline_offset(offset);
        }

        Dictionary getOpentypeFeatures() {
            return fontVariation->get_opentype_features();
        }

        void setOpentypeFeatures(Dictionary features) {
            fontVariation->set_opentype_features(features);
        }

        int getSpacingBottom() {
            return fontVariation->get_spacing(TextServer::SpacingType::SPACING_BOTTOM);
        }

        void setSpacingBottom(int spacing) {
            fontVariation->set_spacing(TextServer::SpacingType::SPACING_BOTTOM, spacing);
        }

        int getSpacingGlyph() {
            return fontVariation->get_spacing(TextServer::SpacingType::SPACING_GLYPH);
        }

        void setSpacingGlyph(int spacing) {
            fontVariation->set_spacing(TextServer::SpacingType::SPACING_GLYPH, spacing);
        }

        int getSpacingSpace() {
            return fontVariation->get_spacing(TextServer::SpacingType::SPACING_SPACE);
        }

        void setSpacingSpace(int spacing) {
            fontVariation->set_spacing(TextServer::SpacingType::SPACING_SPACE, spacing);
        }

        int getSpacingTop() {
            return fontVariation->get_spacing(TextServer::SpacingType::SPACING_TOP);
        }

        void setSpacingTop(int spacing) {
            fontVariation->set_spacing(TextServer::SpacingType::SPACING_TOP, spacing);
        }

        float getVariationEmbolden() {
            return fontVariation->get_variation_embolden();
        }

        void setVariationEmbolden(float embolden) {
            fontVariation->set_variation_embolden(embolden);
        }

        float getVariationFaceIndex() {
            return fontVariation->get_variation_face_index();
        }

        void setVariationFaceIndex(float faceIndex) {
            fontVariation->set_variation_face_index(faceIndex);
        }

        Dictionary getVariationOpentype() {
            return fontVariation->get_variation_opentype();
        }

        void setVariationOpentype(Dictionary variationOpentype) {
            fontVariation->set_variation_opentype(variationOpentype);
        }

        Transform2D getVariationTransform() {
            return fontVariation->get_variation_transform();
        }

        void setVariationTransform(Transform2D transform) {
            fontVariation->set_variation_transform(transform);
        }

        void setSpacing(int spacing, int value) {
            fontVariation->set_spacing(static_cast<TextServer::SpacingType>(spacing), value);
        }
    };
}

#endif