package;

import sunaba.App;

class Main extends App {
    static function main() {
        new Main();
    }

    override function init() {
        try {
            var widget = new ConsoleWidget();
            rootElement.addChild(widget.rootElement);
        }
        catch (e:Dynamic) {
            trace("Error initializing ConsoleWidget: " + e);
        }
    }
}
