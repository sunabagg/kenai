package lucidfx.ui;

@:native("ProgressBar")
extern class ProgressBar extends Range {
    public var editorPreviewIndeterminate: Bool;
    public var fillMode: Int;
    public var indeterminate: Bool;
    public var showPercentage: Bool;
    @:native("cast")
    public static function toProgressBar(obj: Dynamic): lucidfx.ui.ProgressBar;
}

abstract ProgressBarAbstract(ProgressBar) from ProgressBar to ProgressBar {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.ProgressBar {
        var progressBar = lucidfx.ui.ProgressBar.toProgressBar(element);
        if (progressBar.isNull()) {
            return null;
        }
        return progressBar;
    }
}