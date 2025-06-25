package;

import sys.io.File;
import sys.FileSystem;
import sunaba.App;

class Main extends App {
    static function main() {
        new Main();
    }

    override function init() {
        try {
            var testTextPath = execDir + "/test.txt";
            if (FileSystem.exists(testTextPath)){
                var contents = File.getContent(testTextPath);
                Sys.println(contents);
            }
            else {
                trace("File not found: " + testTextPath);
            }
        }
        catch(e) {
            trace(e);
        }
    }
}
