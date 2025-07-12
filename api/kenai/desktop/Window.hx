package kenai.desktop;

import kenai.core.Viewport;
import kenai.core.Vector2i;
import kenai.core.Vector2;
import kenai.ui.Theme;
import kenai.core.Color;
import kenai.core.Event;
import kenai.core.Font;
import kenai.core.Texture2D;
import kenai.ui.StyleBox;
import kenai.core.Rect2i;
import kenai.core.Element;

@:native("Window")
extern class Window extends Viewport {
    public var alwaysOnTop: Bool;
    public var autoTranslate: Bool;
    public var borderless: Bool;
    public var contentScaleAspect: Int;
    public var contentScaleFactor: Float;
    public var contentScaleMode: Int;
    public var contentScaleSize: Vector2i;
    public var contentScaleStretch: Int;
    public var currentScreen: Int;
    public var excludeFromCapture: Bool;
    public var exclusive: Bool;
    public var extendToTitle: Bool;
    public var forceNative: Bool;
    public var initialPosition: Int;
    public var keepTitleVisible: Bool;
    public var maxSize: Vector2i;
    public var minSize: Vector2i;
    public var mode: Int;
    public var mousePassthrough: Bool;
    public var mousePassthroughPolygon: lua.Table<Int,Vector2>;
    public var popupWindow: Bool;
    public var position: Vector2i;
    public var sharpCorners: Bool;
    public var size: Vector2i;
    public var theme: Theme;
    public var themeTypeVariation: String;
    public var title: String;
    public var transient: Bool;
    public var transientToFocused: Bool;
    public var transparent: Bool;
    public var unfocusable: Bool;
    public var unresizable: Bool;
    public var visible: Bool;
    public var wrapControls: Bool;
    public var aboutToPopup: Event;
    public var closeRequested: Event;
    public var dpiChanged: Event;
    public var filesDropped: Event;
    public var focusEntered: Event;
    public var focusExited: Event;
    public var goBackRequested: Event;
    public var mouseEntered: Event;
    public var mouseExited: Event;
    public var themeChanged: Event;
    public var titleChanged: Event;
    public var titlebarChanged: Event;
    public var visibilityChanged: Event;
    public function addThemeColorOverride(name: String, color: Color): Void;
    public function addThemeConstantOverride(name: String, value: Int): Void;
    public function addThemeFontOverride(name: String, font: Font): Void;
    public function addThemeFontSizeOverride(name: String, size: Int): Void;
    public function addThemeIconOverride(name: String, icon: Texture2D): Void;
    public function addThemeStyleboxOverride(name: String, stylebox: StyleBox): Void;
    public function beginBulkThemeOverride(): Void;
    public function canDraw(): Bool;
    public function childControlsChanged(): Void;
    public function endBulkThemeOverride(): Void;
    public function getFlag(flag: Int): Bool;
    public function getLayoutDirection(): Int;
    public function getPositionWithDecorations(): Vector2i;
    public function getSizeWithDecorations(): Vector2i;
    public function getThemeColor(name: String, ?type: String): Color;
    public function getThemeConstant(name: String, ?type: String): Int;
    public function getThemeDefaultBaseScale(): Float;
    public function getThemeDefaultFont(): Font;
    public function getThemeDefaultFontSize(): Int;
    public function getThemeFont(name: String, ?type: String): Font;
    public function getThemeFontSize(name: String, ?type: String): Int;
    public function getThemeIcon(name: String, ?type: String): Texture2D;
    public function getThemeStylebox(name: String, ?type: String): StyleBox;
    public function getWindowId(): Int;
    public function grabFocus(): Void;
    public function hasFocus(): Bool;
    public function hasThemeColor(name: String, ?type: String): Bool;
    public function hasThemeColorOverride(name: String): Bool;
    public function hasThemeConstant(name: String, ?type: String): Bool;
    public function hasThemeConstantOverride(name: String): Bool;
    public function hasThemeFont(name: String, ?type: String): Bool;
    public function hasThemeFontOverride(name: String): Bool;
    public function hasThemeFontSize(name: String, ?type: String): Bool;
    public function hasThemeFontSizeOverride(name: String): Bool;
    public function hasThemeIcon(name: String, ?type: String): Bool;
    public function hasThemeIconOverride(name: String): Bool;
    public function hasThemeStylebox(name: String, ?type: String): Bool;
    public function hasThemeStyleboxOverride(name: String): Bool;
    public function hide(): Void;
    public function isEmbedded(): Bool;
    public function isLayoutRtl(): Bool;
    public function isMaximizeAllowed(): Bool;
    public function isUsingFontOversampling(): Bool;
    public function moveToCenter(): Void;
    public function moveToForeground(): Void;
    public function popup(?rect: Rect2i): Void;
    public function popupCentered(?minsize: Vector2i): Void;
    public function popupCenteredClamped(?minsize: Vector2i, ?fallbackRatio: Float): Void;
    public function popupCenteredRatio(?ratio: Float): Void;
    public function popupExclusive(fromElement: Element, ?rect: Rect2i): Void;
    public function popupExclusiveCentered(fromElement: Element, ?minsize: Vector2i): Void;
    public function popupExclusiveCenteredClamped(fromElement: Element, ?minsize: Vector2i, ?fallbackRatio: Float): Void;
    public function popupExclusiveCenteredRatio(fromElement: Element, ?ratio: Float): Void;
    public function popupExclusiveOnParent(fromElement: Element, parentRect: Rect2i): Void;
    public function popupOnParent(parentRect: Rect2i): Void;
    public function removeThemeColorOverride(name: String): Void;
    public function removeThemeConstantOverride(name: String): Void;
    public function removeThemeFontOverride(name: String): Void;
    public function removeThemeFontSizeOverride(name: String): Void;
    public function removeThemeIconOverride(name: String): Void;
    public function removeThemeStyleboxOverride(name: String): Void;
    public function requestAttention(): Void;
    public function resetSize(): Void;
    public function setImeActive(active: Bool): Void;
    public function setFlag(flag: Int, value: Bool): Void;
    public function setImePosition(position: Vector2i): Void;
    public function setLayoutDirection(direction: Int): Void;
    public function setUnparentWhenInvisible(unparent: Bool): Void;
    public function setUseFontOversampling(use: Bool): Void;
    public function show(): Void;
    public function startDrag(): Void;
    public function startResize(edge: Int): Void;
    @:native("cast")
    public static function toWindow(type: Dynamic): Window;
}

abstract WindowAbstract(Window) from Window to Window {
    @:from
    public static function fromElement(element: kenai.core.Element): WindowAbstract {
        var win = Window.toWindow(element);
        if (win.isNull()) {
            return null;
        }
        return win;
    }
}