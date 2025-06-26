package sunaba.desktop;

import sunaba.ui.Button;

@:native("ConfirmationDialog")
extern class ConfirmationDialog extends AcceptDialog {
    public var cancelButtonText: String;
    public function getCancelButton(): Button;
}