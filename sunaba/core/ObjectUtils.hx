package lucidware.core;

class ObjectUtils {
    public static function getName(object : Any) {
        return untyped __lua__("object.__name");
    }
    @:generic
    public static function castObjectAs<T>(_type : Class<T>, object : Any) : T {
        var obj : Any = untyped __lua__("_type.cast(object)");
        if (obj == null) {
            throw "Object is not of type " + _type;
        }
        return cast obj;
    }

    public static function typeInheritsFrom(type1 : Class<Dynamic>, type2 : Class<Dynamic>) :
        Bool {
        var type1Name = untyped __lua__("type1.__name");
        if (type1Name == null) {
            type1Name = Type.getClassName(type1);
            if (type1Name == null) {
                return false;
            }
        }
        var type2Name = untyped __lua__("type2.__name");
        if (type2Name == null) {
            type2Name = Type.getClassName(type2);
            if (type2Name == null) {
                return false;
            }
        }
        if (type1Name == type2Name) {
            return true;
        }
        var type1Super = Type.getSuperClass(type1);
        while (type1Super != null) {
            if (type1Super == type2) {
                return true;
                break;
            }
            type1Super = Type.getSuperClass(type1Super);
            if (type1Super == null) {
                break;
            }
        }
        return false;
        
    }
}