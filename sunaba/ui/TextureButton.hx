package sunaba.ui;

import sunaba.core.BitMap;

@Native("TextureButton")
extern class TextureButton extends BaseButton {
    public var flipH: Bool;
    public var flipV: Bool;
    public var ignoreTextureSize: Bool;
    public var stretchMode: Int;
    public var textureClickMask: BitMap;
}