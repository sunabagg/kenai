package sunaba.input;

import sunaba.core.Resource;

@:native("InputEventShortcut")
extern class Shortcut extends Resource {
    public var events: sunaba.core.Vector<InputEvent>;
    public function getAsText(): String;
    public function hasValidEvent(): Bool;
    public function matchesEvent(event: InputEvent): Bool;
    @:native("cast")
    public static function castFrom(res: Dynamic): Shortcut;
}

abstract ShortcutAbstract(Shortcut) from Shortcut to Shortcut {
    @:from
    public static function fromResource(resource: Resource) : ShortcutAbstract {
        var shortcut = Shortcut.castFrom(resource);
        if (shortcut.isNull()) {
            return null;
        }
        return shortcut;
    }
} // end package sunaba.input