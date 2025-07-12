package;

import kenai.Key;
import kenai.core.Behavior;
import kenai.input.InputService;

class InputTest extends Behavior{
    override function onUpdate(deltaTime: Float) : Void {
        if (InputService.isKeyPressed(Key.space)) {
            trace(deltaTime);
        }
    }

    override function onInit() {
    }
}