package sunaba.ui;

@:native("CheckButton")
extern class CheckButton extends Button {
    @:native("cast")
    public function toCheckButton(type: Dynamic): CheckButton;
}