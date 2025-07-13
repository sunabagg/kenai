package;

import sunaba.ui.Widget;
import sunaba.ui.RichTextLabel;
import sunaba.ui.LineEdit;

class ConsoleWidget extends Widget {
    private var output:RichTextLabel;
    private var input:LineEdit;

    override function init() {
        load("app://Console.suml");
        output = RichTextLabel.toRichTextLabel(rootElement.find("vbox/control/output"));
        input = LineEdit.toLineEdit(rootElement.find("vbox/input"));
    }
}