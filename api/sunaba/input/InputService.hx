package sunaba.input;

import sunaba.core.Event;
import sunaba.core.Service;

@:native("InputService")
extern class InputService extends Service {
    public static var emulateMouseFromTouch: Bool;
    public static var emulateTouchFromMouse: Bool;
    public static var mouseMode: Int;
    public static var useAccumulatedInput: Bool;
    public static var joyConnectionChanged: Event;
    public static function actionPress(action: String, ?strength: Float): Void;
    public static function actionRelease(action: String): Void;
    public static function addJoyMapping(mapping: String, ?updateExisting: Bool): Void;
    public static function flushBufferedEvents(): Void;
}