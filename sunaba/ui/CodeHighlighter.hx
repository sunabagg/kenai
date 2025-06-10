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
}