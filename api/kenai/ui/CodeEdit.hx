package kenai.ui;

import kenai.core.Dictionary;
import kenai.core.Event;
import kenai.core.Color;
import kenai.core.Resource;
import kenai.core.Variant;
import kenai.core.Vector2;
import kenai.core.Element;

@:native("CodeEdit")
extern class CodeEdit extends TextEdit {
    public var autoBraceCompletionEnabled: Bool;
    public var autoBraceCompletionHighlightMatching: Bool;
    public var autoBraceCompletionPairs: Dictionary;
    public var codeCompletionEnabled: Bool;
    public var codeCompletionPrefixes: lua.Table<Int,String>;
    public var delimiterComments: lua.Table<Int,String>;
    public var delimiterStrings: lua.Table<Int,String>;
    public var guttersDrawBookmarks: Bool;
    public var guttersDrawBreakpointsGutter: Bool;
    public var guttersDrawExecutingLines: Bool;
    public var guttersDrawFoldGutter: Bool;
    public var guttersDrawLineNumbers: Bool;
    public var guttersZeroPadLineNumbers: Bool;
    public var indentAutomatic: Bool;
    public var indentAutomaticPrefixes: lua.Table<Int,String>;
    public var indentSize: Int;
    public var indentUseSpaces: Bool;
    public var lineFolding: Bool;
    public var lineLengthGuidelines: lua.Table<Int,Int>;
    public var symbolLookupOnClick: Bool;
    public var symbolTooltipOnHover: Bool;
    public var breakpointToggled: Event;
    public var codeCompletionRequested: Event;
    public var symbolHovered: Event;
    public var symbolLookup: Event;
    public var symbolValidate: Event;
    public function addAutoBraceCompletionPair(startKey: String, endKey: String): Void;
    public function addCodeCompletionOption(type: Int, displayText: String, insertText: String, textColor: Color, ?icon: Resource, ?value: Variant, ?location: Int): Void;
    public function addCommentDelimiter(startKey: String, endKey: String, ?lineOnly: Bool): Void;
    public function addStringDelimiter(startKey: String, endKey: String, ?lineOnly: Bool): Void;
    public function canFoldLine(line: Int): Bool;
    public function cancelCodeCompletion(): Void;
    public function clearBookmarkedLines(): Void;
    public function clearBreakpointedLines(): Void;
    public function clearCommentDelimiters(): Void;
    public function clearExecutingLines(): Void;
    public function clearStringDelimiters(): Void;
    public function confirmCodeCompletion(): Void;
    public function convertIndent(?fromLine: Int, ?toLine: Int): Void;
    public function createCodeRegion(): Void;
    public function deleteLines(): Void;
    public function doIndent(): Void;
    public function duplicateLines(): Void;
    public function duplicateSelection(): Void;
    public function foldAllLines(): Void;
    public function foldLine(line: Int): Void;
    public function getAutoBraceCompletionCloseKey(opneKey: String): String;
    public function getBookmarkedLines(): lua.Table<Int,Int>;
    public function getBreakpointedLines(): lua.Table<Int,Int>;
    public function getCodeCompletionOption(index: Int): Dictionary;
    public function getCodeCompletionOptions(): lua.Table<Int,Dictionary>;
    public function getCodeCompletionSelectedIndex(): Int;
    public function getCodeRegionEndTag(): String;
    public function getCodeRegionStartTag(): String;
    public function getDelimiterEndKey(delimiterIndex: Int): String;
    public function getDelimiterEndPosition(line: Int, column: Int): Vector2;
    public function getDelimiterStartKey(delimiterIndex: Int): String;
    public function getDelimiterStartPosition(line: Int, column: Int): Vector2;
    public function getExecutingLines(): lua.Table<Int,Int>;
    public function getFoldedLines(): lua.Table<Int,Int>;
    public function getTextForCodeCompletion(): String;
    public function getTextForSymbolLookup(): String;
    public function getTextWithCursorChar(line: Int, column: Int): String;
    public function hasAutoBraceCompletionCloseKey(openKey: String): Bool;
    public function hasAutoBraceCompletionOpenKey(openKey: String): Bool;
    public function hasCommentDelimiter(startKey: String): Bool;
    public function hasStringDelimiter(startKey: String): Bool;
    public function indentLines(): Void;
    public function isInComment(line: Int, ?column: Int): Bool;
    public function isInString(line: Int, ?column: Int): Bool;
    public function isLineBookmarked(line: Int): Bool;
    public function isLineBreakpointed(line: Int): Bool;
    public function isLineCodeRegionEnd(line: Int): Bool;
    public function isLineCodeRegionStart(line: Int): Bool;
    public function isLineExecuting(line: Int): Bool;
    public function isLineFolded(line: Int): Bool;
    public function moveLinesDown(): Void;
    public function moveLinesUp(): Void;
    public function removeCommentDelimiter(startKey: String): Void;
    public function removeStringDelimiter(startKey: String): Void;
    public function requestCodeCompletion(): Void;
    public function setCodeCompletionSelectedIndex(index: Int): Void;
    public function setCodeHint(hint: String): Void;
    public function setCodeHintDrawBelow(drawBelow: Bool): Void;
    public function setCodeRegionTags(?startTag: String, ?endTag: String): Void;
    public function setLineAsBookmarked(line: Int, bookmarked: Bool): Void;
    public function setLineAsBreakpoint(line: Int, breakpointed: Bool): Void;
    public function setLineAsExecuting(line: Int, executing: Bool): Void;
    public function setSymbolLookupWordAsValid(valid: Bool): Void;
    public function toggleFoldableLine(line: Int): Void;
    public function toggleFoldableLinesAtCarets(): Void;
    public function unfoldAllLines(): Void;
    public function unfoldLine(line: Int): Void;
    public function unindentLines(): Void;
    public function updateCodeCompletionOptions(force: Bool): Void;
    @:native("cast")
    public static function toCodeEdit(obj: Dynamic): CodeEdit;
}

abstract CodeEditAbstract(CodeEdit) from CodeEdit to CodeEdit {
    @:from
    public static function fromElement(element: Element): CodeEditAbstract {
        var cItem = CodeEdit.toCodeEdit(element);
        if (cItem.isNull()) {
            return null;
        }
        return cItem;
    }
}