package sunaba.ui;

import sunaba.core.LabelSettings;
import sunaba.core.ArrayList;
import sunaba.core.Rect2;

@:native("Label")
extern class Label extends Control {
    public var autowrapMode: Int;
    public var clipText: Bool;
    public var ellipsisChar: String;
    public var horizontalAlignment: Int;
    public var justificationFlags: Int;
    public var labelSettings: LabelSettings;
    public var language: String;
    public var linesSkipped: Int;
    public var maxLinesSkipped: Int;
    public var paragraphSeparator: String;
    public var structuredTextBidiOverride: Int;
    public var structuredTextBidiOverrideOptions: ArrayList;
    public var tabStops: lua.Table<Int,Float>;
    public var text: String;
    public var textDirection: Int;
    public var textOverrunBehavior: Int;
    public var uppercase: Bool;
    public var verticalAlignment: Int;
    public var visibleCharacters: Int;
    public var visibleCharactersBehavior: Int;
    public var visibleRatio: Float;
    public function getCharacterBounds(index: Int): Rect2;
    public function getTotalCharacterCount(): Int;
    public function getVisibleLineCount(): Int;
    @:native("cast")
    public static function toLabel(obj: Dynamic): Label;
}

abstract LabelAbstract(Label) from Label to Label {
    @:from
    public static function fromElement(element: sunaba.core.Element): LabelAbstract {
        var label = Label.toLabel(element);
        if (label.isNull()){
            return null;
        }
        return label;
    }
}