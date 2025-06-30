package sunaba.input;

import sunaba.core.Service;

@:native("InputService")
extern class InputService extends Service {
    public var emulateMouseFromTouch: Bool;
    public var emulateTouchFromMouse: Bool;
    public var mouseMode: Int;
    public var useAccumulatedInput: Bool;
}