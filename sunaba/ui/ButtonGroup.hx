package sunaba.ui;

import sunaba.core.Resource;
import sunaba.core.Event;

@:native("ButtonGroup")
extern class ButtonGroup extends Resource {
    public var allowUnpress: Bool;
    public var pressed: Event;
    public function getButtons(): lua.Table<Int, BaseButton>;
    public function getPressedButton(): BaseButton;
    @:native("cast")
    public function castFrom(type: Dynamic): ButtonGroup;
}

abstract ButtonGroupAbstract(ButtonGroup) from ButtonGroup to ButtonGroup {
    @:from
    public static function fromResource(resource: Resource): ButtonGroupAbstract {
        var bg = ButtonGroup.castFrom(resource);
        if (bg.isNull()) {
            return null;
        }
        return bg;
    }
}