package lucidfx.core;

@:native("LabelSettings")
extern class LabelSettings extends Resource {
    public var font : Font;
    public var fontColor : Color;
    public var fontSize : Float;
    public var lineSpacing : Float;
    public var outlineColor : Color;
    public var outlineSize : Float;
    public var shadowColor : Color;
    public var shadowOffset : Float;
    public var shadowSize : Float;
    @:native("cast")
    public static function castFrom(type: Dynamic) : LabelSettings;
}

abstract LabelSettingsAbstract(LabelSettings) from LabelSettings to LabelSettings {
    @:from
    public static function fromResource(resource: Resource) : LabelSettingsAbstract {
        var labelsettings = LabelSettings.castFrom(resource);
        if (labelsettings.isNull()) {
            return null;
        }
        return labelsettings;
    } 
}