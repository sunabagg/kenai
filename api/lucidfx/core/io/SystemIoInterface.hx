package lucidfx.core.io;

@:native("SystemIoInterface")
extern class SystemIoInterface extends IoInterface {
    public function getFileUri(path: String, base_uri: String): String;
}