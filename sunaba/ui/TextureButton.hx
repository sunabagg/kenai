package lucidware.ui;

import lucidware.core.BitMap;
import lucidware.core.Texture2D;
import lucidware.core.Element;

@Native("TextureButton")
extern class TextureButton extends BaseButton {
    public var flipH: Bool;
    public var flipV: Bool;
    public var ignoreTextureSize: Bool;
    public var stretchMode: Int;
    public var textureClickMask: BitMap;
    public var textureDisabled: Texture2D;
    public var textureFocused: Texture2D;
    public var textureHover: Texture2D;
    public var textureNormal: Texture2D;
    public var texturePressed: Texture2D;
    @:native("cast")
    public static function toTextureButton(obj: Dynamic): TextureButton;
}

abstract TextureButtonAbstract(TextureButton) from TextureButton to TextureButton {
    @:from
    public static function fromElement(e: Element): TextureButtonAbstract {
        var tButton = TextureButton.toTextureButton(e);
        if (tButton.isNull()) {
            return null;
        }
        return tButton;
    }
}