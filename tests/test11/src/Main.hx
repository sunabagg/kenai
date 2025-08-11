package;

import sunaba.core.io.IoManager;
import sunaba.ui.StyleBoxFlat;
import sunaba.App;
import sunaba.core.SceneFile;


class Main extends App {
    public static function main() {
        new Main();
    }

    override function init() {
        var sceneFile = new SceneFile();
        var scenejson = io.loadVariant("app://TestScene.scnj");
        sceneFile.setData(scenejson);
    }
}