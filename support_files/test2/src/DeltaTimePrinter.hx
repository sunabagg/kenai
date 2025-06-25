package support_files.test2.src;

import lucidfx.core.Behavior;

class DeltaTimePrinter extends Behavior{
    override function onUpdate(deltaTime: Float) : Void {
        Sys.println("DeltaTimePrinter.onUpdate: " + deltaTime);
        //trace();
    }

    override function onInit() {
        Sys.println("DeltaTimePrinter.onInit");
    }
}