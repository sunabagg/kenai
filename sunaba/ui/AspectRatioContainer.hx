package sunaba.ui;

@:native("AspectRatioContainer")
extern class AspectRatioContainer extends Container {
    public var alignmentHorizontal: Int;
    public var alignmentVertical: Int;
    public var ratio: Float;
    public var stretchMode: Int;
}