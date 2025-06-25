package;

import sunaba.App;

class Main extends App{
    public static function main() {
        new Main();
    }

    override function init() {
        try {
            var aWidget = new AdvancedWidget();
            rootElement.addChild(aWidget.rootElement);
        }
        catch( e: Dynamic) {
            trace(e);
        }
    }
}