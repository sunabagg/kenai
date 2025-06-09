package sunaba.ui;

import sunaba.core.Dictionary;

@:native("CodeEdit")
extern class CodeEdit extends TextEdit {
    public var autoBraceCompletionEnabled: Bool;
    public var autoBraceCompletionHighlightMatching: Bool;
    public var autoBraceCompletionPairs: Dictionary;
    public var codeCompletionEnabled: Bool;
    public var codeCompletionPrefixes: Array<String>;
    public var delimiterComments: Array<String>;
    public var delimiterStrings: Array<String>;
    public var guttersDrawBookmarks: Bool;
    public var guttersDrawBreakpointsGutter: Bool;
    public var guttersDrawExecutingLines: Bool;
    public var guttersDrawFoldGutter: Bool;
}