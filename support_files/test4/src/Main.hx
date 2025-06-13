package support_files.test4.src;

import sunaba.App;
import sunaba.ui.Control;
import sunaba.ui.Panel;
import sunaba.ui.Label;
import sunaba.ui.VBoxContainer;

class Main extends App{
    public static function main() {
        new Main();
    }

    public var count: Int = 0;
    public var label: Label;
    
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

        var vboxContainer = new VBoxContainer();

        control.addChild(vboxContainer);
        vboxContainer.setAnchorsAndOffsetsPreset(8, 0, 0);

        label = new Label();

        vboxContainer.addChild(label);
        label.text = "Hello, World!";
        label.verticalAlignment = 1;
        label.horizontalAlignment = 1;

        var button = new sunaba.ui.Button();
        vboxContainer.addChild(button);
        button.text = "Click Me!";

        label.text = "You clicked me! " + count + " times";


        button.pressed.connect(() -> {
            incrementCounter();
        });
    }

    public function incrementCounter() {
        count++;
        label.text = "You clicked me! " + count + " times";
    }
}