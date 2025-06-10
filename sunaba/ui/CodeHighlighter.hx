package sunaba.ui;

import sunaba.core.Dictionary;
import sunaba.core.Color;

@:native("CodeHighlighter")
extern class CodeHighlighter extends SyntaxHighlighter {
    public var colorRegions: Dictionary;
    public var functionColor: Color;
    public var keywordColor: Color;
    public var memberKeywordColors: Dictionary;
    public var memberVariableColor: Color;
    public var numberColor: Color;
    public var symbolColor: Color;
    public function addColorRegion(startKey: String, endKey: String, color: Color, ?lineOnly: Bool): Void;
    public function addKeywordColor(keyword: String, color: Color): Void;
    public function addMemberKeywordColor(memberType: String, color: Color): Void;
    public function clearColorRegions(): Void;
    public function clearKeywordColors(): Void;
    public function clearMemberKeywordColors(): Void;
    public function getKeywordColor(keyword: String): Color;
    public function getMemberKeywordColor(memberType: String): Color;
    public function hasColorRegion(startKey: String): Bool;
    public function hasKeywordColor(keyword: String): Bool;
    public function hasMemberKeywordColor(memberType: String): Bool;
    public function removeColorRegion(startKey: String): Void;
    public function removeKeywordColor(keyword: String): Void;
    public function removeMemberKeywordColor(memberType: String): Void;
    @:native("cast")
    public static function toCodeHighlighter(obj: Dynamic): CodeHighlighter;
}