package kenai.ui;

@:native("Panel")
extern class Panel extends Control {
    @:native("cast")
    public static function toPanel(obj: Dynamic): kenai.ui.Panel;
}

abstract PanelAbstract(Panel) from Panel to Panel {
    @:from
    public static function fromElement(element: kenai.core.Element): PanelAbstract {
        var panel = kenai.ui.Panel.toPanel(element);
        if (panel.isNull()) {
            return null;
        }
        return panel;
    }
}