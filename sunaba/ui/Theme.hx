package sunaba.ui;

import sunaba.core.Resource;
import sunaba.core.Font;

@:native("Theme")
extern class Theme extends Resource {
    public var defaultBaseScale: Float;
    public var defaultFont: Font;
    public var defaultFontSize: Float;
    public function addType(themeType: String): Void;
    public function clear(): Void;
    public function clearColor(name: String, type: String): Void;
    public function clearConstant(name: String, type: String): Void;
    public function clearFont(name: String, type: String): Void;
    public function clearFontSize(name: String, type: String): Void;
    public function clearIcon(name: String, type: String): Void;
    public function clearStyleBox(name: String, type: String): Void;
    public function clearThemeItem(name: String, type: String): Void;
    public function clearTypeVariation(themeType: String): Void;
    public function getColor(name: String, type: String): Color;
    public function getColorList(type: String): Array<String>;
    public function getColorTypeList(type: String): Array<String>;
    public function getConstant(name: String, type: String): Float;
    public function getConstantList(type: String): Array<String>;
    public function getConstantTypeList(type: String): Array<String>;
    public function getFont(name: String, type: String): Font;
    public function getFontList(type: String): Array<String>;
    public function getFontTypeList(type: String): Array<String>;
    public function getFontSize(name: String, type: String): Float;
    public function getFontSizeList(type: String): Array<String>;
    public function getFontSizeTypeList(type: String): Array<String>;
    public function getIcon(name: String, type: String): Texture2D;
    public function getIconList(type: String): Array<String>;
    public function getIconTypeList(type: String): Array<String>;
    public function getStyleBox(name: String, type: String): StyleBox;
    public function getStyleBoxList(type: String): Array<String>;
    public function getStyleBoxTypeList(type: String): Array<String>;
    public function getThemeItem(name: String, type: String): Resource;
    public function getThemeItemList(type: String): Array<String>;
    public function getThemeItemTypeList(type: String): Array<String>;
    public function getTypeList(): Array<String>;
    public function getTypeVariationBase(themeType: String): String;
    public function getTypeVariationList(themeType: String): Array<String>;
    public function hasColor(name: String, type: String): Bool;
    public function hasConstant(name: String, type: String): Bool;
    public function hasDefaultBaseScale(): Bool;
    public function hasDefaultFont(): Bool;
    public function hasDefaultFontSize(): Bool;
    public function hasFont(name: String, type: String): Bool;
    public function hasFontSize(name: String, type: String): Bool;
    public function hasIcon(name: String, type: String): Bool;
    public function hasStyleBox(name: String, type: String): Bool;
    public function hasThemeItem(name: String, type: String): Bool;
    public function isTypeVariation(themeType: String, baseType: String): Bool;
    public function mergeWith(theme: Theme): Void;
    public function removeType(themeType: String): Void;
    public function renameColor(name: String, type: String, newName: String): Void;
    public function renameConstant(name: String, type: String, newName: String): Void;
    public function renameFont(name: String, type: String, newName: String): Void;
    public function renameFontSize(name: String, type: String, newName: String): Void;
    public function renameIcon(name: String, type: String, newName: String): Void;
    public function renameStyleBox(name: String, type: String, newName: String): Void;
    public function renameThemeItem(name: String, type: String, newName: String): Void;
    public function setColor(name: String, type: String, color: Color): Void;
    public function setConstant(name: String, type: String, value: Float): Void;
    public function setDefaultBaseScale(scale: Float): Void;
    public function setDefaultFont(font: Font): Void;
    public function setDefaultFontSize(size: Float): Void;
    public function setFont(name: String, type: String, font: Font): Void;
    public function setFontSize(name: String, type: String, size: Float): Void;
    public function setIcon(name: String, type: String, icon: Texture2D): Void;
    public function setStyleBox(name: String, type: String, styleBox: StyleBox): Void;
    public function setThemeItem(name: String, type: String, item: Resource): Void;
    public function setTypeVariation(themeType: String, baseType: String): Void;
    @:native("cast")
    public function castFrom(res: Dynamic): Theme;
}

abstract ThemeAbstract(Theme) from Theme to Theme {
    @:from
    public static function fromResource(resource: Resource): ThemeAbstract {
        var theme = Theme.castFrom(resource);
        if (theme.isNull()) {
            return null;
        }
        return theme;
    }
} // end package sunaba.ui