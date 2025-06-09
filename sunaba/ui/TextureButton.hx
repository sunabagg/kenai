package sunaba.ui;

import sunaba.core.BitMap;
import sunaba.core.Texture2D;

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
}