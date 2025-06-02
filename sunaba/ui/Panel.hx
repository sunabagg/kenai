package sunaba.ui;

@:native("Panel")
extern class Panel extends Control {
    @:native("cast")
    public static function toPanel(obj: Dynamic): sunaba.ui.Panel;
}