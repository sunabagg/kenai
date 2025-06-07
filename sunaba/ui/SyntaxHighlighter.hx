package sunaba.ui;

import sunaba.core.Resource;
import sunaba.core.Dictionary;

@:native("SyntaxHighlighter")
extern class SyntaxHighlighter extends Resource {
    public function clearHighlightingCache(): Void;
    public function getLineSyntaxHighlighting(line: Int): Dictionary;
    //public function getTextEdit(): TextEdit;
}