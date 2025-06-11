package support_files.test4.src;

import sunaba.App;

class Main extends App{
    override function init() {
        Sys.println("Hello, World!");

        var panel = new sunaba.ui.Panel();

        rootElement.addChild(panel);
        panel.setAnchorsAndOffsetsPreset(15, 3, 0);
        panel.sizeFlagsHorizontal = 3;
        panel.sizeFlagsVertical = 3;
    }
}