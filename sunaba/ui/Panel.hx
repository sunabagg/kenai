package sunaba.ui;

@:native("Panel")
extern class Panel extends Control {
    @:native("cast")
    public static function toPanel(obj: Dynamic): sunaba.ui.Panel;
}

abstract PanelAbstract(Panel) from Panel to Panel {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.Panel {
        var panel = sunaba.ui.Panel.toPanel(element);
        if (panel.isNull()) {
            return null;
        }
        return panel;
    }
}