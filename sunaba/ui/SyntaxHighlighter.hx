package sunaba.ui;

import sunaba.core.Resource;
import sunaba.core.Dictionary;

@:native("SyntaxHighlighter")
extern class SyntaxHighlighter extends Resource {
    public function clearHighlightingCache(): Void;
    public function getLineSyntaxHighlighting(line: Int): Dictionary;
    public function getTextEdit(): TextEdit;
    public function updateCache(): Void;
    @:native("cast")
    public static function castFrom(type: Dynamic): SyntaxHighlighter;
}

abstract SyntaxHighlighterAbstract(SyntaxHighlighter) from SyntaxHighlighter to SyntaxHighlighter {
    @:from
    public static function fromResource(resource: Resource): SyntaxHighlighterAbstract {
        var sh = SyntaxHighlighter.castFrom(resource);
        if (sh.isNull()) {
            return null;
        }
        return sh;
    }
}