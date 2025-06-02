package sunaba.ui;

@:native("PanelContainer")
extern class PanelContainer extends Container {
    @:native("cast")
    public static function toPanelContainer(obj: Dynamic): sunaba.ui.PanelContainer;
}