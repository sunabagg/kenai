package;

import sunaba.core.Vector;
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
        console.ioInterface = io;
        rootElement.addChild(console);
        console.logHandler = (log: String) -> {
            output.pushMono();
            output.appendText(log + "\n");
                output.scrollFollowing = true; // Automatically scroll to the bottom
        };
        input.textSubmitted.connect((args: ArrayList) -> {
            var textvar = args.get(0);
            var text = textvar.toString();
            if (text != "") {
                console.eval(text);
                input.clear();
            }
        });
        console.addCommand("echo", (args: Vector<String>) -> {
            var arr = args.toArray();
            if (arr.length > 0) {
                var text = arr.join(" ");
                output.pushMono();
                output.appendText(text + "\n");
                output.scrollFollowing = true; // Automatically scroll to the bottom
            } else {
                output.pushMono();
                output.appendText("Usage: echo <text>\n");
                output.scrollFollowing = true; // Automatically scroll to the bottom
            }
        });
        console.eval("cd('app://')"); // Set the initial working directory
        console.eval("print('Welcome to the Sunaba Console!')");
    }
}