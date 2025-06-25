package lucidfx.ui;

@:native("Vseparator")
extern class Vseparator extends Control {
    @:native("cast")
    public static function toVSeparator(obj: Dynamic): lucidfx.ui.Vseparator;
}

abstract VseparatorAbstract(Vseparator) from Vseparator to Vseparator {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.Vseparator {
        var vSeparator = lucidfx.ui.Vseparator.toVSeparator(element);
        if (vSeparator.isNull()) {
            return null;
        }
        return vSeparator;
    }
}