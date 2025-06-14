package sunaba.core.io;

import sunaba.core.BaseObject;

@:native("IoInterface")
extern class IoInterface extends BaseObject {
    public var pathUri: String;
    public function getFilePath(path: String): String;
}