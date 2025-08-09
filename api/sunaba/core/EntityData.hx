package sunaba.core;

import sunaba.core.Dictionary;

class EntityData {
    var name: String;
    var components: Array<Dictionary>;
    var children: Array<EntityData>;

    public function new() {}
}