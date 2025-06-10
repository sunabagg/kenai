package sunaba.ui;

import sunaba.core.Dictionary;

@:native("CodeHighlighter")
extern class CodeHighlighter extends SyntaxHighlighter {
    public var colorRegions: Dictionary;
    public var functionColor: Color;
    public var keywordColor: Color;
    public var memberKeywordColors: Dictionary;
    public var memberVariableColor: Color;
    
}