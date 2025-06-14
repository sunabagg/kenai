#ifndef SUNABA_FONT_FILE_H
#define SUNABA_FONT_FILE_H

#include <godot_cpp/classes/font_file.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/dir_access.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <sol/sol.hpp>

#define GodotFontFile godot::FontFile

#include "font.h"
#include "image.h"
#include "convert_godot_lua.h"
#include "io/io_index.h"
#include "io/binary_data.h"

using namespace godot;
using namespace sunaba::core::io;

namespace sunaba::core {
    void bindFontFile(sol::state &lua);

    class FontFile : public Font {
    private:
        GodotFontFile* fontFile = nullptr; // Pointer to the FontFile instance
    public:
        // Constructor with Ref<GodotFontFile> parameter
        FontFile(GodotFontFile* fontFile) {
            setFontFile(fontFile);
        }

        // Constructor with no parameters
        FontFile() {
            setFontFile(memnew(GodotFontFile));
        }

        // Getter for the FontFile node
        GodotFontFile* getFontFile() {
            return fontFile;
        }

        // Setter for the FontFile node
        void setFontFile(GodotFontFile* fontFile) {
            this->fontFile = fontFile;
            fontFile->reference();
            setFont(fontFile);
        } 

        bool getAllowSystemFallback() {
            return fontFile->is_allow_system_fallback();
        }

        void setAllowSystemFallback(bool allow) {
            fontFile->set_allow_system_fallback(allow);
        }

        int getAntialiasing() {
            return fontFile->get_antialiasing();
        }

        void setAntialiasing(int antialiasing) {
            fontFile->set_antialiasing(static_cast<TextServer::FontAntialiasing>(antialiasing));
        }

        BinaryData* getData() {
            return new BinaryData(fontFile->get_data());
        }

        void setData(BinaryData* data) {
            fontFile->set_data(data->toPackedByteArray());
        }

        bool getDisableEmbeddedBitmaps() {
            return fontFile->get_disable_embedded_bitmaps();
        }

        void setDisableEmbeddedBitmaps(bool disable) {
            fontFile->set_disable_embedded_bitmaps(disable);
        }

        int getFixedSize() {
            return fontFile->get_fixed_size();
        }

        void setFixedSize(int size) {
            fontFile->set_fixed_size(size);
        }

        int getFixedSizeScaleMode() {
            return fontFile->get_fixed_size_scale_mode();
        }

        void setFixedSizeScaleMode(int mode) {
            fontFile->set_fixed_size_scale_mode(static_cast<TextServer::FixedSizeScaleMode>(mode));
        }

        std::string getFontName() {
            return fontFile->get_font_name().utf8().get_data();
        }

        void setFontName(const std::string& name) {
            fontFile->set_font_name(name.c_str());
        }

        int getFontStretch() {
            return fontFile->get_font_stretch();
        }

        void setFontStretch(int stretch) {
            fontFile->set_font_stretch(stretch);
        }

        int getFontStyle() {
            return fontFile->get_font_style();
        }

        void setFontStyle(int style) {
            fontFile->set_font_style(style);
        }

        int getFontWeight() {
            return fontFile->get_font_weight();
        }

        void setFontWeight(int weight) {
            fontFile->set_font_weight(weight);
        }

        bool getForceAutohinter() {
            return fontFile->is_force_autohinter();
        }

        void setForceAutohinter(bool force) {
            fontFile->set_force_autohinter(force);
        }

        bool getGenerateMipmaps() {
            return fontFile->get_generate_mipmaps();
        }

        void setGenerateMipmaps(bool generate) {
            fontFile->set_generate_mipmaps(generate);
        }

        int getHinting() {
            return fontFile->get_hinting();
        }

        void setHinting(int hinting) {
            fontFile->set_hinting(static_cast<TextServer::Hinting>(hinting));
        }

        int getMsdfPixelRange() {
            return fontFile->get_msdf_pixel_range();
        }

        void setMsdfPixelRange(int range) {
            fontFile->set_msdf_pixel_range(range);
        }

        int getMsdfSize() {
            return fontFile->get_msdf_size();
        }

        void setMsdfSize(int size) {
            fontFile->set_msdf_size(size);
        }

        bool getMultichannelSignedDistanceField() {
            return fontFile->is_multichannel_signed_distance_field();
        }

        void setMultichannelSignedDistanceField(bool multichannel) {
            fontFile->set_multichannel_signed_distance_field(multichannel);
        }

        Dictionary getOpentypeFeatureOverrides() {
            return fontFile->get_opentype_feature_overrides();
        }

        void setOpentypeFeatureOverrides(Dictionary features) {
            fontFile->set_opentype_feature_overrides(features);
        }

        float getOversampling() {
            return fontFile->get_oversampling();
        }

        void setOversampling(float oversampling) {
            fontFile->set_oversampling(oversampling);
        }

        std::string getStyleName() {
            return fontFile->get_font_style_name().utf8().get_data();
        }

        void setStyleName(std::string name) {
            fontFile->set_font_style_name(name.c_str());
        }

        int getSubpixelPositioning() {
            return fontFile->get_subpixel_positioning();
        }

        void setSubpixelPositioning(int positioning) {
            fontFile->set_subpixel_positioning(static_cast<TextServer::SubpixelPositioning>(positioning));
        }

        void clearCache() {
            fontFile->clear_cache();
        }

        void clearGlyphs(int cacheIndex, Vector2i size) {
            fontFile->clear_glyphs(cacheIndex, size);
        }

        void clearKerningMap(int cacheIndex, int size) {
            fontFile->clear_kerning_map(cacheIndex, size);
        }

        void clearSizeCache(int cacheIndex) {
            fontFile->clear_size_cache(cacheIndex);
        }

        void clearTextures(int cacheIndex, Vector2i size) {
            fontFile->clear_textures(cacheIndex, size);
        }

        float getCacheAscent(int cacheIndex, int size) {
            return fontFile->get_cache_ascent(cacheIndex, size);
        }

        int getCacheCount() {
            return fontFile->get_cache_count();
        }

        float getCacheDescent(int cacheIndex, int size) {
            return fontFile->get_cache_descent(cacheIndex, size);
        }

        float getCacheScale(int cacheIndex, int size) {
            return fontFile->get_cache_scale(cacheIndex, size);
        }

        float getCacheUnderlinePosition(int cacheIndex, int size) {
            return fontFile->get_cache_underline_position(cacheIndex, size);
        }

        float getCacheUnderlineThickness(int cacheIndex, int size) {
            return fontFile->get_cache_underline_thickness(cacheIndex, size);
        }

        int getCharFromGlyphIndex(int size, int glyphIndex) {
            return fontFile->get_char_from_glyph_index(size, glyphIndex);
        }

        float getEmbolden(int cacheIndex) {
            return fontFile->get_embolden(cacheIndex);
        }

        float getExtraBaselineOffset(int cacheIndex) {
            return fontFile->get_extra_baseline_offset(cacheIndex);
        }

        int getExtraSpacing(int cacheIndex, int spacing) {
            return fontFile->get_extra_spacing(cacheIndex, static_cast<TextServer::SpacingType>(spacing));
        }

        int getFaceIndex(int cacheIndex) {
            return fontFile->get_face_index(cacheIndex);
        }

        Vector2 getGlyphAdvance(int cacheIndex, int size, int glyphIndex) {
            return fontFile->get_glyph_advance(cacheIndex, size, glyphIndex);
        }

        int getGlyphIndex(int size, int charIndex, int variationSelector) {
            return fontFile->get_glyph_index(size, charIndex, variationSelector);
        }

        std::vector<int> getGlyphList(int cacheIndex, Vector2i size) {
            auto glyphListPIA = fontFile->get_glyph_list(cacheIndex, size);
            std::vector<int> glyphList(glyphListPIA.size());
            for (int i = 0; i < glyphListPIA.size(); ++i) {
                glyphList[i] = glyphListPIA[i];
            }
            return glyphList;
        }

        Vector2 getGlyphOffset(int cacheIndex, Vector2i size, int glyphIndex) {
            return fontFile->get_glyph_offset(cacheIndex, size, glyphIndex);
        }

        Vector2 getGlyphSize(int cacheIndex, Vector2i size, int glyphIndex) {
            return fontFile->get_glyph_size(cacheIndex, size, glyphIndex);
        }

        int getGlyphTextureIndex(int cacheIndex, Vector2i size, int glyphIndex) {
            return fontFile->get_glyph_texture_idx(cacheIndex, size, glyphIndex);
        }

        Rect2 getGlyphUvRect(int cacheIndex, Vector2i size, int glyphIndex) {
            return fontFile->get_glyph_uv_rect(cacheIndex, size, glyphIndex);
        }

        Vector2 getKerning(int cacheIndex, int size, Vector2i glyphPair) {
            return fontFile->get_kerning(cacheIndex, size, glyphPair);
        }

        std::vector<Vector2i> getKerningList(int cacheIndex, int size) {
            auto kerningListV2A = fontFile->get_kerning_list(cacheIndex, size);
            std::vector<Vector2i> kerningList(kerningListV2A.size());
            for (int i = 0; i < kerningListV2A.size(); ++i) {
                kerningList[i] = kerningListV2A[i];
            }
            return kerningList;
        }

        bool getLanguageSupportOverride(std::string lang) {
            return fontFile->get_language_support_override(lang.c_str());
        }

        std::vector<std::string> getLanguageSupportOverrides() {
            auto langList = fontFile->get_language_support_overrides();
            std::vector<std::string> langListStr(langList.size());
            for (int i = 0; i < langList.size(); ++i) {
                langListStr[i] = langList[i].utf8().get_data();
            }
            return langListStr;
        }

        bool getScriptSupportOverride(std::string script) {
            return fontFile->get_script_support_override(script.c_str());
        }

        std::vector<std::string> getScriptSupportOverrides() {
            auto scriptList = fontFile->get_script_support_overrides();
            std::vector<std::string> scriptListStr(scriptList.size());
            for (int i = 0; i < scriptList.size(); ++i) {
                scriptListStr[i] = scriptList[i].utf8().get_data();
            }
            return scriptListStr;
        }

        std::vector<Vector2i> getSizeCacheList(int cacheIndex) {
            auto sizeCacheListV2A = fontFile->get_size_cache_list(cacheIndex);
            std::vector<Vector2i> sizeCacheList(sizeCacheListV2A.size());
            for (int i = 0; i < sizeCacheListV2A.size(); ++i) {
                sizeCacheList[i] = sizeCacheListV2A[i];
            }
            return sizeCacheList;
        }

        int getTextureCount(int cacheIndex, Vector2i size) {
            return fontFile->get_texture_count(cacheIndex, size);
        }

        Image* getTextureImage(int cacheIndex, Vector2i size, int textureIndex) {
            return new Image(fontFile->get_texture_image(cacheIndex, size, textureIndex).ptr());
        }

        std::vector<int> getTextureOffsets(int cacheIndex, Vector2i size, int textureIndex) {
            auto offsets = fontFile->get_texture_offsets(cacheIndex, size, textureIndex);
            std::vector<int> offsetsList(offsets.size());
            for (int i = 0; i < offsets.size(); ++i) {
                offsetsList[i] = offsets[i];
            }
            return offsetsList;
        }

        Transform2D getTransform(int cacheIndex) {
            return fontFile->get_transform(cacheIndex);
        }

        Dictionary getVariationCoordinates(int cacheIndex) {
            return fontFile->get_variation_coordinates(cacheIndex);
        }

        int loadBitmapFont(sol::state_view lua_state, std::string path) {
            auto ioManager = IoIndex::getIoManager(lua_state);
            BinaryData f = ioManager->loadBinary(path);
            if (f.size() == 0) {
                return Error::FAILED; // Error loading font
            }
            String pathGdString = String(path.c_str());
            if (!DirAccess::dir_exists_absolute("user://temp/")) {
                DirAccess::make_dir_absolute("user://temp/");
            }
            String tempFontPath = "user://temp/" + pathGdString.get_file();
            Ref<FileAccess> fileAccess = FileAccess::open(tempFontPath, FileAccess::WRITE);
            if (!fileAccess.is_null()) {
                fileAccess->store_buffer(f.toPackedByteArray());
                fileAccess->close();
            } else {
                return Error::FAILED; // Error opening file
            }
            return fontFile->load_bitmap_font(tempFontPath);
        }

        int loadDynamicFont(sol::state_view lua_state, std::string path) {
            auto ioManager = IoIndex::getIoManager(lua_state);
            BinaryData f = ioManager->loadBinary(path);
            if (f.size() == 0) {
                return Error::FAILED; // Error loading font
            }
            String pathGdString = String(path.c_str());
            if (!DirAccess::dir_exists_absolute("user://temp/")) {
                DirAccess::make_dir_absolute("user://temp/");
            }
            String tempFontPath = "user://temp/" + pathGdString.get_file();
            Ref<FileAccess> fileAccess = FileAccess::open(tempFontPath, FileAccess::WRITE);
            if (!fileAccess.is_null()) {
                fileAccess->store_buffer(f.toPackedByteArray());
                fileAccess->close();
            } else {
                return Error::FAILED; // Error opening file
            }
            return fontFile->load_dynamic_font(tempFontPath);
        }

        void removeCache(int cacheIndex) {
            fontFile->remove_cache(cacheIndex);
        }

        void removeGlyph(int cacheIndex, Vector2i size, int glyphIndex) {
            fontFile->remove_glyph(cacheIndex, size, glyphIndex);
        }

        void removeKerning(int cacheIndex, int size, Vector2i glyphPair) {
            fontFile->remove_kerning(cacheIndex, size, glyphPair);
        }

        void removeLanguageSupportOverride(std::string lang) {
            fontFile->remove_language_support_override(lang.c_str());
        }

        void removeScriptSupportOverride(std::string script) {
            fontFile->remove_script_support_override(script.c_str());
        }

        void removeSizeCache(int cacheIndex, Vector2i size) {
            fontFile->remove_size_cache(cacheIndex, size);
        }

        void removeTexture(int cacheIndex, Vector2i size, int textureIndex) {
            fontFile->remove_texture(cacheIndex, size, textureIndex);
        }

        void renderGlyph(int cacheIndex, Vector2i size, int glyphIndex) {
            fontFile->render_glyph(cacheIndex, size, glyphIndex);
        }

        void renderRange(int cacheIndex, Vector2i size, int start, int end) {
            fontFile->render_range(cacheIndex, size, start, end);
        }

        void setCacheAscent(int cacheIndex, int size, float ascent) {
            fontFile->set_cache_ascent(cacheIndex, size, ascent);
        }

        void setCacheDescent(int cacheIndex, int size, float descent) {
            fontFile->set_cache_descent(cacheIndex, size, descent);
        }

        void setCacheScale(int cacheIndex, int size, float scale) {
            fontFile->set_cache_scale(cacheIndex, size, scale);
        }

        void setCacheUnderlinePosition(int cacheIndex, int size, float position) {
            fontFile->set_cache_underline_position(cacheIndex, size, position);
        }

        void setCacheUnderlineThickness(int cacheIndex, int size, float thickness) {
            fontFile->set_cache_underline_thickness(cacheIndex, size, thickness);
        }
        
        void setEmbolden(int cacheIndex, float embolden) {
            fontFile->set_embolden(cacheIndex, embolden);
        }
        
        void setExtraBaselineOffset(int cacheIndex, float offset) {
            fontFile->set_extra_baseline_offset(cacheIndex, offset);
        }

        void setExtraSpacing(int cacheIndex, int spacing, int value) {
            fontFile->set_extra_spacing(cacheIndex, static_cast<TextServer::SpacingType>(spacing), value);
        }

        void setFaceIndex(int cacheIndex, int faceIndex) {
            fontFile->set_face_index(cacheIndex, faceIndex);
        }

        void setGlyphAdvance(int cacheIndex, int size, int glyphIndex, Vector2 advance) {
            fontFile->set_glyph_advance(cacheIndex, size, glyphIndex, advance);
        }

        void setGlyphOffset(int cacheIndex, Vector2i size, int glyph, Vector2 offset) {
            fontFile->set_glyph_offset(cacheIndex, size, glyph, offset);
        }

        void setGlyphSize(int cacheIndex, Vector2i size, int glyph, Vector2 glSize) {
            fontFile->set_glyph_size(cacheIndex, size, glyph, glSize);
        }

        void setGlyphTextureIndex(int cacheIndex, Vector2i size, int glyph, int textureIndex) {
            fontFile->set_glyph_texture_idx(cacheIndex, size, glyph, textureIndex);
        }

        void setGlyphUvRect(int cacheIndex, Vector2i size, int glyph, Rect2 uvRect) {
            fontFile->set_glyph_uv_rect(cacheIndex, size, glyph, uvRect);
        }

        void setKerning(int cacheIndex, int size, Vector2i glyphPair, Vector2 kerning) {
            fontFile->set_kerning(cacheIndex, size, glyphPair, kerning);
        }

        void setLanguageSupportOverride(std::string lang, bool support) {
            fontFile->set_language_support_override(lang.c_str(), support);
        }

        void setScriptSupportOverride(std::string script, bool support) {
            fontFile->set_script_support_override(script.c_str(), support);
        }

        void setTextureImage(int cacheIndex, Vector2i size, int textureIndex, Image* image) {
            fontFile->set_texture_image(cacheIndex, size, textureIndex, image->getImage());
        }

        void setTextureOffsets(int cacheIndex, Vector2i size, int textureIndex, std::vector<int> offsets) {
            PackedInt32Array poolOffsets;
            for (int i = 0; i < offsets.size(); ++i) {
                poolOffsets.append(offsets[i]);
            }
            fontFile->set_texture_offsets(cacheIndex, size, textureIndex, poolOffsets);
        }

        void setTransform(int cacheIndex, Transform2D transform) {
            fontFile->set_transform(cacheIndex, transform);
        }

        void setVariationCoordinates(int cacheIndex, Dictionary coordinates) {
            fontFile->set_variation_coordinates(cacheIndex, coordinates);
        }
    };
}

#endif // SUNABA_FONT_FILE_H