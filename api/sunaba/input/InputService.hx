package sunaba.input;

import sunaba.core.Service;

@:native("InputService")
extern class InputService extends Service {
    public static var emulateMouseFromTouch: Bool;
    public static var emulateTouchFromMouse: Bool;
    public static var mouseMode: Int;
    public static var useAccumulatedInput: Bool;
}