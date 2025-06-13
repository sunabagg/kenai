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

        var label = new Label();
        var labelControl = new Control();
        
        vboxContainer.addChild(labelControl);

        labelControl.addChild(label);
        label.setAnchorsAndOffsetsPreset(8, 0, 0);
        label.text = "Hello, World!";
        label.verticalAlignment = 1;
        label.horizontalAlignment = 1;
    }
}