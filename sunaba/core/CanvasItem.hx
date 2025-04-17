package sunaba.core;

@:native("Element")
extern class CanvasItem extends Element {
    public var clipChildren: Int;
    public var lightMask: Int;
    public var material: Material;
    public var modulate: Color;
    public var selfModulate: Color;
    public var showBehindParent: Bool;
    public var textureFilter: Int;
    public var textureRepeat: Bool;
    public var topLevel: Bool;
    public var useParentMaterial: Bool;
    public var visibilityLayer: Int;
    public var visible: Bool;
    public var ySortEnabled: Bool;
    public var zAsRelative: Bool;
    public var zIndex: Int;
}
