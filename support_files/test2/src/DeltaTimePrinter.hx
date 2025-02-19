package support_files.test2.src;

import sunaba.core.Behavior;

class DeltaTimePrinter extends Behavior{
    override function onUpdate(deltaTime: Float) : Void {
        trace("DeltaTimePrinter.onUpdate: " + deltaTime);
    }

    override function onInit() {
        Sys.println("DeltaTimePrinter.onInit");
    }
}