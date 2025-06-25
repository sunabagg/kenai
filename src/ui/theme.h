#ifndef THEME_H
#define THEME_H

#include <godot_cpp/classes/theme.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/display_server.hpp>
#include <sol/sol.hpp>

#define GodotTheme godot::Theme

#include "../core/resource.h"
#include "../core/font.h"
#include "../core/texture2d.h"
#include "../core/convert_godot_lua.h"
#include "style_box.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindTheme(sol::state_view& lua);

    class Theme : public lucidware::core::Resource {
    private:
        GodotTheme* theme;
    public:
        Theme() {
            setTheme(memnew(GodotTheme));
        }

        Theme(GodotTheme* t) {
            setTheme(t);
        }

        GodotTheme* getTheme() {
            return theme;
        }

        static Theme* getLightTheme() {
            auto res = ResourceLoader::get_singleton()->load("res://addons/lite/light.tres");
            Ref<GodotTheme> lightTheme = res;
            if (lightTheme.is_valid()) {
                return new Theme(lightTheme.ptr());
            }
            return nullptr;
        }

        static Theme* getDarkTheme() {
            auto res = ResourceLoader::get_singleton()->load("res://addons/lite/dark.tres");
            Ref<GodotTheme> darkTheme = res;
            if (darkTheme.is_valid()) {
                return new Theme(darkTheme.ptr());
            }
            return nullptr;
        }

        static Theme* getDefaultTheme() {
            if (DisplayServer::get_singleton()->is_dark_mode()) {
                return getDarkTheme();
            } else {
                return getLightTheme();
            }
        }

        void setTheme(GodotTheme* t) {
            theme = t;
            theme->reference();
            setResource(theme);
        }

        float getDefaultBaseScale() {
            return theme->get_default_base_scale();
        }

        void setDefaultBaseScale(float scale) {
            theme->set_default_base_scale(scale);
        }

        lucidware::core::Font* getDefaultFont() {
            return new lucidware::core::Font(theme->get_default_font().ptr());
        }

        void setDefaultFont(lucidware::core::Font* font) {
            theme->set_default_font(font->getFont());
        }

        int getDefaultFontSize() {
            return theme->get_default_font_size();
        }

        void setDefaultFontSize(int size) {
            theme->set_default_font_size(size);
        }

        void addType(const std::string& themeType) {
            theme->add_type(themeType.c_str());
        }

        void clear() {
            theme->clear();
        }

        void clearColor(const std::string& name, const std::string& type) {
            theme->clear_color(name.c_str(), type.c_str());
        }

        void clearConstant(const std::string& name, const std::string& type) {
            theme->clear_constant(name.c_str(), type.c_str());
        }

        void clearFont(const std::string& name, const std::string& type) {
            theme->clear_font(name.c_str(), type.c_str());
        }

        void clearFontSize(const std::string& name, const std::string& type) {
            theme->clear_font_size(name.c_str(), type.c_str());
        }

        void clearIcon(const std::string& name, const std::string& type) {
            theme->clear_icon(name.c_str(), type.c_str());
        }

        void clearStyleBox(const std::string& name, const std::string& type) {
            theme->clear_stylebox(name.c_str(), type.c_str());
        }

        void clearThemeItem(int dataType, const std::string& name, const std::string& type) {
            theme->clear_theme_item(static_cast<GodotTheme::DataType>(dataType), name.c_str(), type.c_str());
        }

        void clearTypeVariation(const std::string& themeType) {
            theme->clear_type_variation(themeType.c_str());
        }

        Color getColor(const std::string& name, const std::string& type) {
            return theme->get_color(name.c_str(), type.c_str());
        }

        std::vector<std::string> getColorList(const std::string& type) {
            std::vector<std::string> list;
            godot::Array arr = theme->get_color_list(type.c_str());
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        std::vector<std::string> getColorTypeList() {
            std::vector<std::string> list;
            godot::Array arr = theme->get_color_type_list();
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        int getConstant(const std::string& name, const std::string& type) {
            return theme->get_constant(name.c_str(), type.c_str());
        }

        std::vector<std::string> getConstantList(const std::string& type) {
            std::vector<std::string> list;
            godot::Array arr = theme->get_constant_list(type.c_str());
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        std::vector<std::string> getConstantTypeList() {
            std::vector<std::string> list;
            godot::Array arr = theme->get_constant_type_list();
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        lucidware::core::Font* getFont(const std::string& name, const std::string& type) {
            return new lucidware::core::Font(theme->get_font(name.c_str(), type.c_str()).ptr());
        }

        std::vector<std::string> getFontList(const std::string& type) {
            std::vector<std::string> list;
            godot::Array arr = theme->get_font_list(type.c_str());
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        std::vector<std::string> getFontTypeList() {
            std::vector<std::string> list;
            godot::Array arr = theme->get_font_type_list();
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        int getFontSize(const std::string& name, const std::string& type) {
            return theme->get_font_size(name.c_str(), type.c_str());
        }

        std::vector<std::string> getFontSizeList(const std::string& type) {
            std::vector<std::string> list;
            godot::Array arr = theme->get_font_size_list(type.c_str());
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        std::vector<std::string> getFontSizeTypeList() {
            std::vector<std::string> list;
            godot::Array arr = theme->get_font_size_type_list();
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        lucidware::core::Texture2D* getIcon(const std::string& name, const std::string& type) {
            return new lucidware::core::Texture2D(theme->get_icon(name.c_str(), type.c_str()).ptr());
        }

        std::vector<std::string> getIconList(const std::string& type) {
            std::vector<std::string> list;
            godot::Array arr = theme->get_icon_list(type.c_str());
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        std::vector<std::string> getIconTypeList() {
            std::vector<std::string> list;
            godot::Array arr = theme->get_icon_type_list();
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        lucidware::ui::StyleBox* getStyleBox(const std::string& name, const std::string& type) {
            return new lucidware::ui::StyleBox(theme->get_stylebox(name.c_str(), type.c_str()).ptr());
        }

        std::vector<std::string> getStyleBoxList(const std::string& type) {
            std::vector<std::string> list;
            godot::Array arr = theme->get_stylebox_list(type.c_str());
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        std::vector<std::string> getStyleBoxTypeList() {
            std::vector<std::string> list;
            godot::Array arr = theme->get_stylebox_type_list();
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        sol::stack_object getThemeItem(lua_State* L, int dataType, const std::string& name, const std::string& type) {
            return lucidware::core::to_lua(L, theme->get_theme_item(static_cast<GodotTheme::DataType>(dataType), name.c_str(), type.c_str()));
        }

        std::vector<std::string> getThemeItemList(int dataType, const std::string& type) {
            std::vector<std::string> list;
            godot::Array arr = theme->get_theme_item_list(static_cast<GodotTheme::DataType>(dataType), type.c_str());
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        std::vector<std::string> getThemeItemTypeList(int dataType) {
            std::vector<std::string> list;
            godot::Array arr = theme->get_theme_item_type_list(static_cast<GodotTheme::DataType>(dataType));
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        std::vector<std::string> getTypeList() {
            std::vector<std::string> list;
            godot::Array arr = theme->get_type_list();
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        std::string getTypeVariationBase(const std::string& themeType) {
            return String(theme->get_type_variation_base(themeType.c_str())).utf8().get_data();
        }

        std::vector<std::string> getTypeVariationList(const std::string& themeType) {
            std::vector<std::string> list;
            godot::Array arr = theme->get_type_variation_list(themeType.c_str());
            for (int i = 0; i < arr.size(); i++) {
                list.push_back(String(arr[i]).utf8().get_data());
            }
            return list;
        }

        bool hasColor(const std::string& name, const std::string& type) {
            return theme->has_color(name.c_str(), type.c_str());
        }

        bool hasConstant(const std::string& name, const std::string& type) {
            return theme->has_constant(name.c_str(), type.c_str());
        }

        bool hasDefaultBaseScale() {
            return theme->has_default_base_scale();
        }

        bool hasDefaultFont() {
            return theme->has_default_font();
        }

        bool hasDefaultFontSize() {
            return theme->has_default_font_size();
        }

        bool hasFont(const std::string& name, const std::string& type) {
            return theme->has_font(name.c_str(), type.c_str());
        }

        bool hasFontSize(const std::string& name, const std::string& type) {
            return theme->has_font_size(name.c_str(), type.c_str());
        }

        bool hasIcon(const std::string& name, const std::string& type) {
            return theme->has_icon(name.c_str(), type.c_str());
        }

        bool hasStyleBox(const std::string& name, const std::string& type) {
            return theme->has_stylebox(name.c_str(), type.c_str());
        }

        bool hasThemeItem(int dataType, const std::string& name, const std::string& type) {
            return theme->has_theme_item(static_cast<GodotTheme::DataType>(dataType), name.c_str(), type.c_str());
        }

        bool isTypeVariation(const std::string& themeType, const std::string* baseType) {
            return theme->is_type_variation(themeType.c_str(), baseType->c_str());
        }

        void mergeWith(Theme* other) {
            theme->merge_with(other->getTheme());
        }

        void removeType(const std::string& themeType) {
            theme->remove_type(themeType.c_str());
        }

        void renameColor(const std::string& oldName, const std::string& name, const std::string& type) {
            theme->rename_color(oldName.c_str(), name.c_str(), type.c_str());
        }

        void renameConstant(const std::string& oldName, const std::string& name, const std::string& type) {
            theme->rename_constant(oldName.c_str(), name.c_str(), type.c_str());
        }

        void renameFont(const std::string& oldName, const std::string& name, const std::string& type) {
            theme->rename_font(oldName.c_str(), name.c_str(), type.c_str());
        }

        void renameFontSize(const std::string& oldName, const std::string& name, const std::string& type) {
            theme->rename_font_size(oldName.c_str(), name.c_str(), type.c_str());
        }

        void renameIcon(const std::string& oldName, const std::string& name, const std::string& type) {
            theme->rename_icon(oldName.c_str(), name.c_str(), type.c_str());
        }

        void renameStyleBox(const std::string& oldName, const std::string& name, const std::string& type) {
            theme->rename_stylebox(oldName.c_str(), name.c_str(), type.c_str());
        }

        void renameThemeItem(int dataType, const std::string& oldName, const std::string& name, const std::string& type) {
            theme->rename_theme_item(static_cast<GodotTheme::DataType>(dataType), oldName.c_str(), name.c_str(), type.c_str());
        }

        void setColor(const std::string& name, const std::string& type, const Color& color) {
            theme->set_color(name.c_str(), type.c_str(), color);
        }

        void setConstant(const std::string& name, const std::string& type, int constant) {
            theme->set_constant(name.c_str(), type.c_str(), constant);
        }

        void setFont(const std::string& name, const std::string& type, lucidware::core::Font* font) {
            theme->set_font(name.c_str(), type.c_str(), font->getFont());
        }

        void setFontSize(const std::string& name, const std::string& type, int size) {
            theme->set_font_size(name.c_str(), type.c_str(), size);
        }

        void setIcon(const std::string& name, const std::string& type, lucidware::core::Texture2D* icon) {
            theme->set_icon(name.c_str(), type.c_str(), godot::Ref<GodotTexture2D>(icon->getTexture()));
        }

        void setStyleBox(const std::string& name, const std::string& type, lucidware::ui::StyleBox* styleBox) {
            theme->set_stylebox(name.c_str(), type.c_str(), godot::Ref<GodotStyleBox>(styleBox->getStyleBox()));
        }

        void setThemeItem(int dataType, const std::string& name, const std::string& type, const Variant& value) {
            theme->set_theme_item(static_cast<GodotTheme::DataType>(dataType), name.c_str(), type.c_str(), value);
        }

        void setTypeVariation(const std::string& themeType, const std::string* baseType) {
            theme->set_type_variation(themeType.c_str(), baseType->c_str());
        }
    };
}

#endif // THEME_H