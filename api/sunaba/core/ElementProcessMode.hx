package sunaba.core;

enum abstract ElementProcessMode(Int) from Int to Int {
    public var Inherit = 0;
    public var Pausable = 1;
    public var WhenPaused = 2;
    public var Always = 3;
    public var Disabled = 4;
}