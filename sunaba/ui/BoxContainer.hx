package sunaba.ui;

@:native("BoxContainer")
extern class BoxContainer extends Container {
    public var alignment: Int;
    public var vertical: Bool;
    public function addSpacer(begin: Bool): Void;
}