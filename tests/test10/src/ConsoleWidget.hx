package;

import sunaba.Error;
import sunaba.core.io.ConsoleCmd;
import sunaba.core.Color;
import sunaba.core.Font;
import sunaba.core.FontFile;
import sunaba.core.Vector;
import sunaba.core.ArrayList;
import sunaba.core.io.Console;
import sunaba.ui.Widget;
import sunaba.ui.RichTextLabel;
import sunaba.ui.LineEdit;
import sunaba.ui.ColorRect;

class ConsoleWidget extends Widget {
    private var output:RichTextLabel;
    private var input:LineEdit;

    private var console: Console;

    override function init() {
        load("app://Console.suml");
        var txt : String = "";

        output = RichTextLabel.toRichTextLabel(rootElement.find("vbox/control/output"));
        output.fitContent = true;
        output.selectionEnabled = true;
        output.contextMenuEnabled = true;
        output.bbcodeEnabled = true;
        var outputColor = output.getThemeColor('default_color');
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
            trace(log);
            txt += log + "\n";
            output.parseBBCode('[code]' + txt + '[/code]');
            output.scrollFollowing = true; // Automatically scroll to the bottom
        };
        input.textSubmitted.connect((args: ArrayList) -> {
            var textvar = args.get(0);
            var text = textvar.toString();
            if (text != "") {
                try {
                    console.eval(text);
                }
                catch(e) {
                    txt = txt + '[color=red]Error: ' + e + '[/color]\n';
                    output.parseBBCode('[code]' + txt + '[/code]');
                }
                input.clear();
            }
        });
        console.addCommand("hello-world", (args: Vector<String>) -> {
            console.eval('print("Hello, World!")');
            return Error.ok;
        });
        console.addCommand("echo", (args: Vector<String>) -> {
            var arr = args.toArray();
            if (arr.length > 0) {
                var text = arr.join(" ");
                txt += text + "\n";
                output.parseBBCode('[code]' + txt + '[/code]');
                output.scrollFollowing = true; // Automatically scroll to the bottom
            } else {
                txt += "Usage: echo <text>\n";
                output.parseBBCode('[code]' + txt + '[/code]');
                output.scrollFollowing = true; // Automatically scroll to the bottom
            }
            return Error.ok;
        });
        console.addCommand("com", (args: Vector<String>) -> {
            try {
                var arr = args.toArray();
                if (arr.length == 1) {
                    var command = arr[0];
                    ConsoleCmd(command, console);
                    return Error.ok;
                } else {
                    txt += "Usage: com <command>\n";
                    output.parseBBCode('[code]' + txt + '[/code]');
                    output.scrollFollowing = true; // Automatically scroll to the bottom
                    return Error.ok;
                }
            }
            catch (e:Dynamic) {
                trace("Command parse error");
                txt += '[color=red]Error: ' + e + '[/color]\n';
                //output.parseBBCode('[code]' + txt + '[/code]');
                output.scrollFollowing = true; // Automatically scroll to the bottom
            }

            return Error.failed;
        });
        console.eval("_G.com = function(command) _G.cmd('com', A(command)) end");
        console.eval("cd('app://')"); // Set the initial working directory
        console.eval("print('Welcome to the Sunaba Console!')");
    }
}