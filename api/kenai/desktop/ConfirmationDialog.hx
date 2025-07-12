package kenai.desktop;

import kenai.core.Element;
import kenai.ui.Button;

@:native("ConfirmationDialog")
extern class ConfirmationDialog extends AcceptDialog {
    public var cancelButtonText: String;
    public function getCancelButton(): Button;
    @:native("cast")
    public static function toConfirmationDialog(obj:Any): ConfirmationDialog;
}

abstract ConfirmationDialogAbstract(ConfirmationDialog) from ConfirmationDialog to ConfirmationDialog {
    @:from
    public static function fromElement(e: Element): ConfirmationDialogAbstract {
        var cd = ConfirmationDialog.toConfirmationDialog(e);
        if (cd.isNull())
            return null;
        return cd;
    }
}