package;

import sunaba.core.io.IoManager;
import sunaba.ui.StyleBoxFlat;
import sunaba.App;

class Main extends App {
    public static function main() {
        new Main();
    }

    override function init() {
        var stylebox = new StyleBoxFlat();
        stylebox.ExpandMarginBottom - 0.56;
        stylebox.borderWidthLeft = 3;
        stylebox.cornerRadiusTopRight = 1;
        var io : IoManager = untyped __lua__("_G.ioManager");
        //io.saveResource("user://test.sres", stylebox);
    }
}