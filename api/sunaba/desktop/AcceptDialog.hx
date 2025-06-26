package sunaba.desktop;

import sunaba.ui.LineEdit;
import sunaba.ui.Label;
import sunaba.ui.Button;
import sunaba.core.Event;

@:native("AcceptDialog")
extern class AcceptDialog extends Window {
    public var dialogAutowrap: Bool;
    public var dialogCloseOnEscape: Bool;
    public var dialogHideOnOk: Bool;
    public var dialogText: String;
    public var okButtonText: String;
    public var canceled: Event;
    public var confirmed: Event;
    public var customAction: Event;
    public function addButton(text: String, ?right: Bool, ?action: String): Button;
    public function addCancelButton(name: String): Button;
    public function getLabel(): Label;
    public function getOkButton(): Button;
    public function registerTextEnter(lineEdit: LineEdit): Void;
    public function removeButton(button: Button): Void;
    @:native("cast")
    public static function toAcceptDialog(obj: Any): AcceptDialog;
}