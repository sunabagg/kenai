package sunaba.core.io;

@:native("CustomIoInterface")
extern class CustomIoInterface extends IoInterface {
    public var object: Any;
    public function getFileUri(path: String, base_uri: String): String;
}