package lucidware.ui;

import lucidware.core.ArrayList;
import lucidware.core.Variant;
import lucidware.core.Rect2;
import lucidware.core.Color;
import lucidware.core.Vector2i;
import lucidware.core.Vector2;
import lucidware.desktop.PopupMenu;
import lucidware.core.Dictionary;
import lucidware.core.Font;

@:native("PanelContainer")
extern class RichTextLabel extends Control {
    public var autowrapMode: Int;
    public var bbcodeEnabled: Bool;
    public var clipContents: Bool;
    public var contextMenuEnabled: Bool;
    public var customEffects: ArrayList;
    public var deselectOnFocusLossEnabled: Bool;
    public var dragAndDropSelectionEnabled: Bool;
    public var fitContent: Bool;
    public var hintUnderlined: Bool;
    public var horizontalAlignment: Int;
    public var justificationFlags: Int;
    public var language: String;
    public var metaUnderlined: Bool;
    public var progressBarDelay: Int;
    public var scrollActive: Bool;
    public var scrollFollowing: Bool;
    public var selectionEnabled: Bool;
    public var shortcutKeysEnabled: Bool;
    public var structuredTextBidiOverride: Int;
    public var structuredTextBidiOverrideOptions: ArrayList;
    public var tabSize: Int;
    public var tabStops: lua.Table<Int,Float>;
    public var text: String;
    public var textDirection: Int;
    public var threaded: Bool;
    public var verticalAlignment: Int;
    public var visibleCharacters: Int;
    public var visibleCharactersBehavior: Int;
    public var visibleRatio: Float;
    public var finished: lucidware.core.Event;
    public var metaClicked: lucidware.core.Event;
    public var metaHoverEnded: lucidware.core.Event;
    public var metaHoverStarted: lucidware.core.Event;
    public function addImage(image: lucidware.core.Texture2D, ?width: Int, ?height: Int, ?color: Color, ?inlineAlign: Int, ?region: Rect2, ?key: Variant, ?pad: Bool, ?tooltip: String, ?sizeInPercent: Bool ): Void;
    public function addText(text: String): Void;
    public function appendText(bbcode: String): Void;
    public function clear(): Void;
    public function deselect(): Void;
    public function getCharacterLine(character: Int): Int;
    public function getCharacterParagraph(character: Int): Int;
    public function getContentHeight(): Float;
    public function getContentWidth(): Float;
    public function getLineCount(): Int;
    public function getLineOffset(line: Int): Float;
    public function getLineRange(line: Int): Vector2i;
    public function getMenu(): PopupMenu;
    public function getParagraphCount(): Int;
    public function getParagraphOffset(paragraph: Int): Float;
    public function getParsedText(): String;
    public function getSelectedText(): String;
    public function getSelectionFrom(): Int;
    public function getSelectionLineOffset(): Float;
    public function getSelectionTo(): Int;
    public function getTotalCharacterCount(): Int;
    public function getVScrollBar(): ScrollBar;
    public function getVisibleLineCount(): Int;
    public function getVisibleParagraphCount(): Int;
    public function installEffect(effect: Variant): Void;
    public function invalidateParagraph(paragraph: Int): Bool;
    public function isFinished(): Bool;
    public function isMenuVisible(): Bool;
    public function isReady(): Bool;
    public function menuOption(option: Int): Void;
    public function newline(): Void;
    public function parseBBCode(bbcode: String): Void;
    public function parseExpressionsForValues(expressions: lua.Table<Int,String>): Dictionary;
    public function pop(): Void;
    public function popAll(): Void;
    public function popContent(): Void;
    public function pushBgcolor(bgcolor: Color): Void;
    public function pushBold(): Void;
    public function pushBoldItalics(): Void;
    public function pushCell(): Void;
    public function pushColor(color: Color): Void;
    public function pushContext(): Void;
    public function pushDropcap(string: String, font: Font, size: Int, ?dropcapMargins: Rect2, ?color: Color, ?outlineSize: Int, ?outlineColor: Color): Void;
    public function pushFgcolor(fgcolor: Color): Void;
    public function pushFont(font: Font): Void;
    public function pushFontSize(size: Int): Void;
    public function pushHint(description: String): Void;
    public function pushIndent(level: Int): Void;
    public function pushItalics(): Void;
    public function pushLanguage(language: String): Void;
    public function pushList(level: Int, type: Int, capitalize: Bool, ?bullet: String): Void;
    public function pushMeta(data: Variant, ?underlineMode: Int, ?tooltip: String): Void;
    public function pushMono(): Void;
    public function pushNormal(): Void;
    public function pushOutlineColor(color: Color): Void;
    public function pushOutlineSize(size: Int): Void;
    public function pushParagraph(alignment: Int, ?baseDirection: Int, ?language: String, ?structureTextParser: String, ?justificationFlags: Int, ?flags: lua.Table<Int,Float>): Void;
    public function pushStrikethrough(): Void;
    public function pushTable(columns: Int, ?inlineAlign: Int, ?alignToRow: Int) : Void;
    public function pushUnderline(): Void;
    public function removeParagraph(paragraph: Int, ?noInvalidate: Bool): Void;
    public function scrollToLine(line: Int): Void;
    public function scrollToParagraph(paragraph: Int): Void;
    public function scrollToSelection(): Void;
    public function selectAll(): Void;
    public function setCellBorderColor(color: Color): Void;
    public function setCellSizeOverride(minSize: Vector2, maxSize: Vector2): Void;
    public function setTableColumnExpand(column: Int, expand: Bool, ?ratio: Int, ?shrink: Bool): Void;
    public function updateImage(key: Variant, mask: Int, image: lucidware.core.Texture2D, ?width: Int, ?height: Int, ?color: Color, ?inlineAlign: Int, ?region: Rect2, ?pad: Bool, ?tooltip: String, ?sizeInPercent: Bool): Void;
    @:native("cast")
    public static function toRichTextLabel(obj: Dynamic): lucidware.ui.RichTextLabel;
}

abstract RichTextLabelAbstract(RichTextLabel) from RichTextLabel to RichTextLabel {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.RichTextLabel {
        var richTextLabel = lucidware.ui.RichTextLabel.toRichTextLabel(element);
        if (richTextLabel.isNull()) {
            return null;
        }
        return richTextLabel;
    }
}