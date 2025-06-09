package sunaba.ui;

@Native("TextureButton")
extern class TextureButton extends BaseButton {
    public var flipH: Bool;
    public var flipV: Bool;
    public var ignoreTextureSize: Bool;
}