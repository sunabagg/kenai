package sunaba.core;

class ComponentBinder {
    public var component: Component;

    public function new(c : Component) {
        component = c;
    }

    public function onInit() {
        component.onInit();
    }

    public function onEnterTree() {
        component.onEnterTree();
    }

    public function onReady() {
        component.onReady();
    }

    public function onUpdate(deltaTime: Float) {
        component.onUpdate(deltaTime);
    }

    public function onPhysicsUpdate(deltaTime: Float) {
        component.onPhysicsUpdate(deltaTime);
    }

    public function onExitTree() {
        component.onExitTree();
    }
}