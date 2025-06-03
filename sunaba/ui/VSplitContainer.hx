package sunaba.ui;

@:native("VSplitContainer")
extern class VSplitContainer extends SplitContainer {
    @:native("cast")
    public static function toVSplitContainer(obj: Dynamic): sunaba.ui.VSplitContainer;
}