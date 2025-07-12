package kenai.ui;

@:native("Vseparator")
extern class Vseparator extends Control {
    @:native("cast")
    public static function toVSeparator(obj: Dynamic): kenai.ui.Vseparator;
}

abstract VseparatorAbstract(Vseparator) from Vseparator to Vseparator {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.Vseparator {
        var vSeparator = kenai.ui.Vseparator.toVSeparator(element);
        if (vSeparator.isNull()) {
            return null;
        }
        return vSeparator;
    }
}