package;

import sunaba.core.ArrayList;
import sunaba.core.io.Console;
import sunaba.ui.Widget;
import sunaba.ui.RichTextLabel;
import sunaba.ui.LineEdit;

class ConsoleWidget extends Widget {
    private var output:RichTextLabel;
    private var input:LineEdit;

    private var console: Console;

    override function init() {
        load("app://Console.suml");
        output = RichTextLabel.toRichTextLabel(rootElement.find("vbox/control/output"));
        var i = rootElement.find("vbox/input");
        if (i == null) {
            trace("Input element not found in ConsoleWidget");
            return;
        }
        input = LineEdit.toLineEdit(rootElement.find("vbox/input"));
        console = new Console();
        rootElement.addChild(console);
        console.logHandler = (log: String) -> {
            try {
                trace("Console log: " + log);
                output.appendText(log + "\n");
                output.scrollFollowing = true; // Automatically scroll to the bottom
            } catch (e: Dynamic) {
                trace("Error appending log to output: " + e);
            }
        };
        input.textSubmitted.connect((args: ArrayList) -> {
            var textvar = args.get(0);
            var text = textvar.toString();
            if (text != "") {
                trace("Console input: " + text);
            }
        });
        console.eval("print('Welcome to the Sunaba Console!')");
    }
}