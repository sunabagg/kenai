package sunaba.ui;

@:native("CheckBox")
extern class CheckBox extends Button {
    @:native("cast")
    public function toCheckBox(type: Dynamic): CheckBox;
}