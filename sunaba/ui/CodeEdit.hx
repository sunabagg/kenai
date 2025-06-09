package sunaba.ui;

import sunaba.core.Dictionary;
import sunaba.core.Event;

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
    public var guttersDrawLineNumbers: Bool;
    public var guttersZeroPadLineNumbers: Bool;
    public var indentAutomatic: Bool;
    public var indentAutomaticPrefixes: Array<String>;
    public var indentSize: Int;
    public var indentUseSpaces: Bool;
    public var layoutDirection: Float;
    public var lineFolding: Bool;
    public var lineLengthGuidelines: Array<Int>;
    public var symbolLookupOnClick: Bool;
    public var symbolTooltipOnHover: Bool;
    public var textDirection: Int;
    public var breakpointToggled: Event;
    public var codeCompletionRequested: Event;
    public var symbolHovered: Event;
    public var symbolLookup: Event;
    public var symbolValidate: Event;
    public function addAutoBraceCompletionPair(startKey: String, endKey: String): Void;
}