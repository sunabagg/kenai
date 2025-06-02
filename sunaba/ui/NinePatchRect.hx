package sunaba.ui;

@:native("NinePatchRect")
extern class NinePatchRect extends Control {
    public var axisStretchHorizontal: Int;
    public var axisStretchVertical: Int;
    public var drawCenter: Bool;
    public var mouseFilter: Int;
    public var patchMarginLeft: Int;
    public var patchMarginRight: Int;
}