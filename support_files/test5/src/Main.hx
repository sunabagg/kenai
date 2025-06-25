package;

import lucidware.App;

class Main extends App {
    public static function main() {
        new Main();
    }

    override function init() {
        try {
            var clickerCounter = new ClickerCounter();
            rootElement.addChild(clickerCounter.rootElement);
        } catch (e:Dynamic) {
            trace("Error initializing ClickerCounter: " + e);
        }
    }
}