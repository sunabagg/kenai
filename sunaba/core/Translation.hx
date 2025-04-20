package sunaba.core;

@:native("Translation")
extern class Translation extends Resource {
    public var locale: String;
    public function addMessage(srcMsg: String, xlatedMsg: String, n: Int, context: String = ""): Void;
    public function addPluralMessage(srcMsg: String, xlatedMsg: String, n: Int, context: String = ""): Void;
    public function eraseMessage(srcMsg: String, context: String): Void;
    public function getMessage(srcMsg: String, context: String = ""): String;
    public function getMessageCount(): Int;
    public function getMessageList(): lua.Table<Int, String>;
    public function getPluralMessage(srcMsg: String, srcPluralMsg: String, n: Int, context: String): String;
    public function getTRanslatedMessageList(): lua.Table<Int, String>;
    @:native("cast")
    public static function castFrom(type: Dynamic) : Translation;
}

abstract TranslationAbstract(Translation) from Translation to Translation {
    @:from
    public static function fromResource(resource: Resource) : TranslationAbstract {
        var translation = Translation.castFrom(resource);
        if (translation.isNull()) {
            return null;
        }
        return translation;
    } 
} // end package sunaba.core