package lucidware.ui;

@:native("ProgressBar")
extern class ProgressBar extends Range {
    public var editorPreviewIndeterminate: Bool;
    public var fillMode: Int;
    public var indeterminate: Bool;
    public var showPercentage: Bool;
    @:native("cast")
    public static function toProgressBar(obj: Dynamic): lucidware.ui.ProgressBar;
}

abstract ProgressBarAbstract(ProgressBar) from ProgressBar to ProgressBar {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.ProgressBar {
        var progressBar = lucidware.ui.ProgressBar.toProgressBar(element);
        if (progressBar.isNull()) {
            return null;
        }
        return progressBar;
    }
}