package support_files.test5.src;

import sunaba.App;

class Main extends App {
    public static function main() {
        new Main();
    }

    override function init() {
        var clickerCounter = new ClickerCounter();
        rootElement.addChild(clickerCounter.rootElement);
    }
}