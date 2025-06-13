package support_files.test4.src;

import sunaba.App;
import sunaba.ui.Control;
import sunaba.ui.Panel;
import sunaba.ui.Label;

class Main extends App{
    public static function main() {
        new Main();
    }
    
    override function init() {
        Sys.println("Hello, World!");

        var control = new Control();

        rootElement.addChild(control);
        control.setAnchorsAndOffsetsPreset(15, 3, 0);
        control.sizeFlagsHorizontal = 3;
        control.sizeFlagsVertical = 3;
        

        var panel = new Panel();
        control.addChild(panel);
        panel.setAnchorsAndOffsetsPreset(15, 3, 0);
        panel.sizeFlagsHorizontal = 3;
        panel.sizeFlagsVertical = 3;
        panel.offsetBottom = -10;
        panel.offsetTop = 10;
        panel.offsetLeft = -10;
        panel.offsetRight = 10;

        var label = new Label();

        label.anchorTop = 0.5;
        label.anchorBottom = 1;
        label.anchorLeft = 0.5;
        label.anchorRight = 1;
        label.offsetTop = -75;
        label.offsetBottom = 0;
        label.offsetLeft = -85;
        label.offsetRight = 0;
        label.text = "Hello, World!";

        control.addChild(label);
    }
}