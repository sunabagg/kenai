#ifndef SYSTEM_FONT_H
#define SYSTEM_FONT_H

#include <godot_cpp/classes/system_font.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>
#include <vector>
#include <string>

#define GodotSystemFont godot::SystemFont

#include "font.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidfx::core {
    void bindSystemFont(sol::state_view& lua);

    class SystemFont : public Font {
    private:
        GodotSystemFont* font;
    public:
        SystemFont(GodotSystemFont* f) {
            setSystemFont(f);
        }

        SystemFont() {
            setSystemFont(memnew(GodotSystemFont));
        }

        GodotSystemFont* getSystemFont() const {
            return font;
        }

        void setSystemFont(GodotSystemFont* f) {
            font = f;
            font->reference();
            setFont(f);
        }

        bool getAllowSystemFallback() const {
            return font->is_allow_system_fallback();
        }

        void setAllowSystemFallback(bool allow) {
            font->set_allow_system_fallback(allow);
        }

        int getAntialiasing() const {
            return font->get_antialiasing();
        }

        void setAntialiasing(int antialiasing) {
            font->set_antialiasing(static_cast<TextServer::FontAntialiasing>(antialiasing));
        }

        bool getDisableEmbeddedBitmaps() const {
            return font->get_disable_embedded_bitmaps();
        }

        void setDisableEmbeddedBitmaps(bool disable) {
            font->set_disable_embedded_bitmaps(disable);
        }

        bool GetFontItalic() const {
            return font->get_font_italic();
        }

        void SetFontItalic(bool italic) {
            font->set_font_italic(italic);
        }

        std::vector<std::string> getFontNames() const {
            std::vector<std::string> names;
            PackedStringArray arr = font->get_font_names();
            for (int i = 0; i < arr.size(); i++) {
                names.push_back(arr[i].utf8().get_data());
            }
            return names;
        }

        void setFontNames(const std::vector<std::string>& names) {
            PackedStringArray arr;
            for (const std::string& name : names) {
                arr.push_back(name.c_str());
            }
            font->set_font_names(arr);
        }

        int getFontStretch() const {
            return font->get_font_stretch();
        }

        void setFontStretch(int stretch) {
            font->set_font_stretch(stretch);
        }

        int getFontWeight() const {
            return font->get_font_weight();
        }

        void setFontWeight(int weight) {
            font->set_font_weight(weight);
        }

        bool getForceAutohinter() const {
            return font->is_force_autohinter();
        }

        void setForceAutohinter(bool force) {
            font->set_force_autohinter(force);
        }

        bool getGenerateMipmaps() const {
            return font->get_generate_mipmaps();
        }

        void setGenerateMipmaps(bool generate) {
            font->set_generate_mipmaps(generate);
        }

        int getHinting() const {
            return font->get_hinting();
        }

        void setHinting(int hinting) {
            font->set_hinting(static_cast<TextServer::Hinting>(hinting));
        }

        bool getKeepRoundingRemainders() const {
            return font->get_keep_rounding_remainders();
        }

        void setKeepRoundingRemainders(bool keep) {
            font->set_keep_rounding_remainders(keep);
        }

        int getMsdfPixelRange() const {
            return font->get_msdf_pixel_range();
        }

        void setMsdfPixelRange(int range) {
            font->set_msdf_pixel_range(range);
        }

        int getMsdfSize() const {
            return font->get_msdf_size();
        }

        bool getMultichannelSignedDistanceField() const {
            return font->is_multichannel_signed_distance_field();
        }

        void setMultichannelSignedDistanceField(bool multichannel) {
            font->set_multichannel_signed_distance_field(multichannel);
        }

        float getOversampling() const {
            return font->get_oversampling();
        }

        void setOversampling(float oversampling) {
            font->set_oversampling(oversampling);
        }

        int getSubpixelPositioning() const {
            return font->get_subpixel_positioning();
        }

        void setSubpixelPositioning(int positioning) {
            font->set_subpixel_positioning(static_cast<TextServer::SubpixelPositioning>(positioning));
        }
    };
}

#endif // SYSTEM_FONT_H