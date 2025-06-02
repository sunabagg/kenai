package sunaba.ui;

@:native("ProgressBar")
extern class ProgressBar extends Range {
    public var editorPreviewIndeterminate: Bool;
    public var fillMode: Int;
    public var indeterminate: Bool;
    public var showPercentage: Bool;
    @:native("cast")
    public static function toProgressBar(obj: Dynamic): sunaba.ui.ProgressBar;
}