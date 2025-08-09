package sunaba.core;

typedef EntityData = {
    var name: String;
    var components: Array<Map<String, Any>>;
    var children: Array<EntityData>;
}