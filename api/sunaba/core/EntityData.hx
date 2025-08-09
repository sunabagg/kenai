package sunaba.core;

import sunaba.core.Dictionary;

typedef EntityData = {
    var name: String;
    var components: Array<Dictionary>;
    var children: Array<EntityData>;
}