package support_files.test4.src;

import sunaba.SizeFlags;
import sunaba.LayoutPresetMode;
import sunaba.App;
import sunaba.ui.Control;
import sunaba.ui.Panel;
import sunaba.ui.Label;
import sunaba.ui.VBoxContainer;
import sunaba.LayoutPreset;

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
        control.setAnchorsAndOffsetsPreset(cast LayoutPreset.FullRect, cast LayoutPresetMode.KeepSize, 0);
        control.sizeFlagsHorizontal = cast SizeFlags.Fill;
        control.sizeFlagsVertical = cast SizeFlags.Fill;

        var panel = new Panel();
        control.addChild(panel);
        panel.setAnchorsAndOffsetsPreset(cast LayoutPreset.FullRect, cast LayoutPresetMode.KeepSize, 0);
        panel.sizeFlagsHorizontal = cast SizeFlags.Fill;
        panel.sizeFlagsVertical = cast SizeFlags.Fill;
        panel.offsetBottom = -10;
        panel.offsetTop = 10;
        panel.offsetLeft = -10;
        panel.offsetRight = 10;

        var vboxContainer = new VBoxContainer();

        control.addChild(vboxContainer);
        vboxContainer.setAnchorsAndOffsetsPreset(cast LayoutPreset.Center, cast LayoutPresetMode.Minsize, 0);
        vboxContainer.sizeFlagsHorizontal = cast SizeFlags.ShrinkCenter;
        vboxContainer.sizeFlagsVertical = cast SizeFlags.ShrinkCenter;

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