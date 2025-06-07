package sunaba.ui;

@:native("TextEdit")
extern class TextEdit extends Control {
    public var autowrapMode: Int;
    public var caretBlink: Bool;
    public var caretBlinkInterval: Float;
    public var caretDrawWhenEditableDisabled: Bool;
    public var caretMidGrapheme: Bool;
    public var caretMoveOnRightClick: Bool;
    public var caretMultiple: Bool;
    public var caretType: Int;
    public var clipContents: Bool;
    public var contextMenuEnabled: Bool;
    public var customWordSeparators: String;
    public var deselectOnFocusLost: Bool;
    public var dragAndDropSelectionEnabled: Bool;
    public var drawControlChars: Bool;
    public var drawSpaces: Bool;
    public var editable: Bool;
    public var emojuMenuEnabled: Bool;
    public var emptySelectionClipboardEnabled: Bool;
    public var highlightAllOccurrences: Bool;
    public var highlightCurrentLine: Bool;
    public var indentWrappedLines: Bool;
    public var language: String;
    public var middleMousePasteEnabled: Bool;
    public var minimapDraw: Bool;
    public var minimapWidth: Int;
    public var mouseDefaultCursorShape: Int;
    public var placeholderText: String;
    public var scrollFitContentHeight: Bool;
    public var scrollFitContentWidth: Bool;
    public var scrollHorizontal: Int;
}