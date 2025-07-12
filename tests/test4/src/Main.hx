package support_files.test4.src;

import kenai.SizeFlags;
import kenai.LayoutPresetMode;
import kenai.App;
import kenai.ui.Control;
import kenai.ui.CenterContainer;
import kenai.ui.Panel;
import kenai.ui.Label;
import kenai.ui.VboxContainer;
import kenai.LayoutPreset;

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
        control.setAnchorsAndOffsetsPreset(LayoutPreset.fullRect, LayoutPresetMode.keepSize, 0);
        control.sizeFlagsHorizontal = SizeFlags.fill;
        control.sizeFlagsVertical = SizeFlags.fill;

        var panel = new Panel();
        control.addChild(panel);
        panel.setAnchorsAndOffsetsPreset(LayoutPreset.fullRect, LayoutPresetMode.keepSize, 0);
        panel.sizeFlagsHorizontal = SizeFlags.fill;
        panel.sizeFlagsVertical = SizeFlags.fill;
        panel.offsetBottom = -10;
        panel.offsetTop = 10;
        panel.offsetLeft = -10;
        panel.offsetRight = 10;

        var centerContainer = new CenterContainer();
        panel.addChild(centerContainer);
        centerContainer.setAnchorsAndOffsetsPreset(LayoutPreset.fullRect, LayoutPresetMode.keepSize, 0);
        centerContainer.sizeFlagsHorizontal = SizeFlags.fill;
        centerContainer.sizeFlagsVertical = SizeFlags.fill;

        var vboxContainer = new VboxContainer();

        centerContainer.addChild(vboxContainer);
        vboxContainer.setAnchorsAndOffsetsPreset(LayoutPreset.center, LayoutPresetMode.minsize, 0);
        vboxContainer.sizeFlagsHorizontal = SizeFlags.shrinkBegin;
        vboxContainer.sizeFlagsVertical = SizeFlags.shrinkBegin;

        label = new Label();

        vboxContainer.addChild(label);
        label.text = "Hello, World!";
        label.verticalAlignment = 1;
        label.horizontalAlignment = 1;

        var button = new kenai.ui.Button();
        vboxContainer.addChild(button);
        button.text = "Click Me!";

        label.text = "You clicked me! " + count + " times";


        button.pressed.connect(() -> {
            incrementCounter();
        });

        var size = vboxContainer.size;
        var parentSize = control.size;
        vboxContainer.position.x = (parentSize.x - size.x) / 2;
        vboxContainer.position.y = (parentSize.y - size.y) / 2;
    }

    public function incrementCounter() {
        count++;
        label.text = "You clicked me! " + count + " times";
    }
}