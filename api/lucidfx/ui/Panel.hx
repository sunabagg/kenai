package lucidfx.ui;

@:native("Panel")
extern class Panel extends Control {
    @:native("cast")
    public static function toPanel(obj: Dynamic): lucidfx.ui.Panel;
}

abstract PanelAbstract(Panel) from Panel to Panel {
    @:from
    public static function fromElement(element: lucidfx.core.Element): PanelAbstract {
        var panel = lucidfx.ui.Panel.toPanel(element);
        if (panel.isNull()) {
            return null;
        }
        return panel;
    }
}