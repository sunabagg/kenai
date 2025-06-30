package sunaba.input;

import sunaba.core.Vector2;
import sunaba.core.Dictionary;
import sunaba.core.Vector;
import sunaba.core.Vector3;
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
    public static function getAccelerometer(): Vector3;
    public static function getActionRawStrength(action: String, ?exactMatch: Bool): Float;
    public static function getActionStrength(action: String, ?exactMatch: Bool): Float;
    public static function getAxis(negativeAction: String, positiveAction: String): Float;
    public static function getConnectedJoypads(): Vector<Int>;
    public static function getCurrentCursorShape(): Int;
    public static function getGravity(): Vector3;
    public static function getGyroscope(): Vector3;
    public static function getJoyAxis(device: Int, axis: Int): Float;
    public static function getJoyGuid(device: Int): String;
    public static function getJoyInfo(device: Int): Dictionary;
    public static function getJoyName(device: Int): String;
    public static function getJoyVibrationDuration(device: Int): Float;
    public static function getJoyVibrationStrength(device: Int): Vector2;
    public static function getLastMouseScreenVelocity(): Vector2;
    public static function getLastMouseVelocity(): Vector2;
    public static function getMagnetometer(): Vector3;
    public static function getMouseButtonMask(): Int;
    public static function getVector(negativeX: String, positiveX: String, negativeY: String, positiveY: String): Vector2;
    public static function isActionJustPressed(action: String, ?exactMatch: Bool): Bool;
    public static function isActionJustReleased(action: String, ?exactMatch: Bool): Bool;
    public static function isActionPressed(action: String, ?exactMatch: Bool): Bool;
    public static function isAnythingPressed(): Bool;
    public static function isJoyButtonPressed(device: Int, button: Int): Bool;
    public static function isJoyKnown(device: Int): Bool;
    public static function isKeyLabelPressed(keycode: Int): Bool;
}