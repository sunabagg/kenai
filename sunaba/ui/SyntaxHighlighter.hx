package sunaba.ui;

import sunaba.core.Resource;

@:native("SyntaxHighlighter")
extern class SyntaxHighlighter extends Resource {
    public function clearHighlightingCache(): Void;
}