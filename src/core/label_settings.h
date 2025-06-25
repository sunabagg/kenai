#ifndef LABEL_SETTINGS_H
#define LABEL_SETTINGS_H

#include <godot_cpp/classes/label_settings.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotLabelSettings godot::LabelSettings

#include "resource.h"
#include "convert_godot_lua.h"
#include "font.h"

using namespace godot;

namespace lucidfx::core {
    void bindLabelSettings(sol::state &lua);

    class LabelSettings : public Resource {
    private:
        GodotLabelSettings* labelSettings = nullptr; // Pointer to the LabelSettings instance
    public:
        // Constructor with Ref<GodotLabelSettings> parameter
        LabelSettings(GodotLabelSettings* labelSettings) {
            setLabelSettings(labelSettings);
        }

        // Constructor with no parameters
        LabelSettings() {
            setLabelSettings(memnew(GodotLabelSettings));
        }

        // Getter for the LabelSettings node
        GodotLabelSettings* getLabelSettings() {
            return labelSettings;
        }

        // Setter for the LabelSettings node
        void setLabelSettings(GodotLabelSettings* labelSettings) {
            this->labelSettings = labelSettings;
            labelSettings->reference();
            setResource(labelSettings);
        }

        Font* getFont() {
            return new Font(labelSettings->get_font().ptr());
        }

        void setFont(Font* font) {
            labelSettings->set_font(Ref<GodotFont>(font->getFont()));
        }

        Color getFontColor() {
            return labelSettings->get_font_color();
        }

        void setFontColor(Color color) {
            labelSettings->set_font_color(color);
        }

        int getFontSize() {
            return labelSettings->get_font_size();
        }

        void setFontSize(int size) {
            labelSettings->set_font_size(size);
        }

        float getLineSpacing() {
            return labelSettings->get_line_spacing();
        }

        void setLineSpacing(float spacing) {
            labelSettings->set_line_spacing(spacing);
        }

        Color getOutlineColor() {
            return labelSettings->get_outline_color();
        }

        void setOutlineColor(Color color) {
            labelSettings->set_outline_color(color);
        }

        int getOutlineSize() {
            return labelSettings->get_outline_size();
        }

        void setOutlineSize(int size) {
            labelSettings->set_outline_size(size);
        }

        Color getShadowColor() {
            return labelSettings->get_shadow_color();
        }

        void setShadowColor(Color color) {
            labelSettings->set_shadow_color(color);
        }

        Vector2 getShadowOffset() {
            return labelSettings->get_shadow_offset();
        }

        void setShadowOffset(Vector2 offset) {
            labelSettings->set_shadow_offset(offset);
        }

        int getShadowSize() {
            return labelSettings->get_shadow_size();
        }

        void setShadowSize(int size) {
            labelSettings->set_shadow_size(size);
        }
    };
}

#endif // LABEL_SETTINGS_H