#ifndef LUCIDWARE_FONT_H
#define LUCIDWARE_FONT_H

#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotFont godot::Font

#include "resource.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidware::core {
    void bindFont(sol::state &lua);

    class Font : public Resource {
    private:
        GodotFont* font = nullptr; // Pointer to the Font instance
    public:
        // Constructor with Ref<GodotFont> parameter
        Font(GodotFont* fnt) {
            setFont(fnt);
        }

        // Constructor with no parameters
        Font() {
            setFont(memnew(GodotFont));
        }

        // Getter for the Font node
        GodotFont* getFont() {
            return font;
        }

        // Setter for the Font node
        void setFont(GodotFont* fnt) {
            font = fnt;
            font->reference();
            setResource(font);
        }

        std::vector<Font*> getFallbacks() {
            auto fontList = font->get_fallbacks();
            std::vector<Font*> fonts;
            for (int i = 0; i < fontList.size(); ++i) {
                auto fVar = fontList[i];
                auto f = (Ref<GodotFont>)fVar;
                fonts.push_back(new Font(f.ptr()));
            }
            return fonts;
        }

        void setFallbacks(const std::vector<Font*>& fallbacks) {
            Array fontList;
            for (const auto& f : fallbacks) {
                fontList.append(f->getFont());
            }
            font->set_fallbacks(fontList);
        }

        float getAscent(int fontSize = 16) {
            return font->get_ascent(fontSize);
        }

        Vector2 getCharSize(int chr, int fontSize) {
            return font->get_char_size(chr, fontSize);
        }

        float getDescent(int fontSize = 16) {
            return font->get_descent(fontSize);
        }

        int getFaceCount() {
            return font->get_face_count();
        }

        std::string getFontName() {
            return String(font->get_font_name()).utf8().get_data();
        }

        int getFontStyle() {
            return font->get_font_style();
        }

        int getFontWeight() {
            return font->get_font_weight();
        }

        float getHeight(int fontSize = 16) {
            return font->get_height(fontSize);
        }

        Vector2 getMultilineStringSize(const std::string &text, int alignment= 0.0f, float width = -1.0f, int fontSize = 16, int maxLines = -1, int brkFlags = 3, int justificationFlags = 3, int direction = 0, int orientation = 0) {
            return font->get_multiline_string_size(text.c_str(), static_cast<HorizontalAlignment>(alignment), width, fontSize, maxLines, brkFlags, justificationFlags, static_cast<TextServer::Direction>(direction), static_cast<TextServer::Orientation>(orientation));
        }

        Dictionary getOpentypeFeatures() {
            return font->get_opentype_features();
        }

        Dictionary getOtNameStrings() {
            return font->get_ot_name_strings();
        }

        int getSpacing(int spacing) {
            return font->get_spacing(static_cast<TextServer::SpacingType>(spacing));
        }

        Vector2 getStringSize(const std::string& text, int alignment = 0, float width = 0, int fontSize = 16, int justificationFlags = 3, int direction = 0, int orientation = 0) {
            return font->get_string_size(text.c_str(), static_cast<HorizontalAlignment>(alignment), width, fontSize, justificationFlags, static_cast<TextServer::Direction>(direction), static_cast<TextServer::Orientation>(orientation));
        }

        std::string getSupportedChars() {
            return String(font->get_supported_chars()).utf8().get_data();
        }

        Dictionary getSupportedFeatureList() {
            return font->get_supported_feature_list();
        }

        Dictionary getSupportedVariationList() {
            return font->get_supported_variation_list();
        }

        float getUnderlinePosition(int fontSize = 16) {
            return font->get_underline_position(fontSize);
        }

        float getUnderlineThickness(int fontSize = 16) {
            return font->get_underline_thickness(fontSize);
        }

        bool hasChar(int chr) {
            return font->has_char(chr);
        }

        bool isLanguageSupported(const std::string& lang) {
            return font->is_language_supported(lang.c_str());
        }

        bool isScriptSupported(const std::string& script) {
            return font->is_script_supported(script.c_str());
        }

        void setCacheCapacity(int singleLine, int multiLine) {
            font->set_cache_capacity(singleLine, multiLine);
        }
    };
}

#endif // LUCIDWARE_FONT_H