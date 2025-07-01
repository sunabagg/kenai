package;

import sunaba.Key;
import sunaba.core.Behavior;
import sunaba.input.InputService;

class InputTest extends Behavior{
    override function onUpdate(deltaTime: Float) : Void {
        if (InputService.isKeyPressed(Key.space)) {
            trace(deltaTime);
        }
    }

    override function onInit() {
    }
}