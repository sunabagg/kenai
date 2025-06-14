package sunaba.core.io;

import sunaba.core.BaseObject;

@:native("IoInterface")
extern class IoInterface extends BaseObject {
    public var pathUri: String;
    public function getFilePath(path: String): String;
    public function loadText(path: String): String;
    public function saveText(path: String, text: String): Void;
    public function loadBinary(path: String): BinaryData;
    public function saveBinary(path: String, data: BinaryData): Void;
}