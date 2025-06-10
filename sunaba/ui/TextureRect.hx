package sunaba.ui;

@:native("TextureRect")
extern class TextureRect extends Control {
    public var expandMode: Int;
    public var flipH: Bool;
    public var flipV: Bool;
    public var texture: Texture2D;
    @:native("cast")
    public static function toTextureRect(obj: Dynamic): TextureRect;
}