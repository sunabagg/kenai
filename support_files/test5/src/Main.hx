package support_files.test5.src;

import sunaba.App;

class Main extends App {
    public static function main() {
        new Main();
    }

    override function init() {
        Sys.println("Hello, World!");

        var clickerCounter = new ClickerCounter();
        Sys.println("ClickerCounter.rootElement.isNull: " + clickerCounter.rootElement.isNull());
        rootElement.addChild(clickerCounter.rootElement);
    }
}