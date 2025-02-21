package sunaba.core;

abstract Vector2i(NativeVector2i) from NativeVector2i {
    public function new(x : Int = 0, y : Int = 0) {
        this = new NativeVector2i(x, y);
    }

    @:op(a.b) public function fieldRead(name:String) : Dynamic
    {
        if (name == "toString") {
            return function() : String {
                var v = this;
                return untyped __lua__("v.tostring()");
            }
        } else if (name == "native") {
            return this;
        } else if (name == "x") {
            return this.x;
        } else if (name == "y") {
            return this.y;
        } else if (Reflect.hasField(this, name)) {
            return Reflect.field(this, name);
        } else {
            throw "Invalid field";
        }
    }

    @:op(a.b) public function fieldWrite(name:String, value:String){
        if (Reflect.hasField(this, name)) {
            Reflect.setField(this, name, value);
        } else {
            throw "Invalid field";
        }
    }

    @:op([]) public function arrayRead(n:Dynamic) {
        if (n == 0) return this.x;
        if (n == 1) return this.y;
        if (n == "x") return this.x;
        if (n == "y") return this.y;
        throw "Invalid index";
    }

    @:op([]) public function arrayWrite(n:Dynamic, value:Int) {
        if (n == 0) this.x = value;
        else if (n == 1) this.y = value;
        else if (n == "x") this.x = value;
        else if (n == "y") this.y = value;
        else throw "Invalid index";
    }

    @:op(A + B)
    public function add(rhs: Any) : Vector2i {
        var lhs = this;
        return untyped __lua__("lhs + rhs");
    }

    @:op(A - B)
    public function sub(rhs: Any) : Vector2i {
        var lhs = this;
        return untyped __lua__("lhs - rhs");
    }

    @:op(A * B)
    public function mul(rhs: Any) : Vector2i {
        var lhs = this;
        return untyped __lua__("lhs * rhs");
    }

    @:op(A / B)
    public function div(rhs: Any) : Vector2i {
        var lhs = this;
        return untyped __lua__("lhs / rhs");
    }

    @:op(A % B)
    public function mod(rhs: Any) : Vector2i {
        var lhs = this;
        return untyped __lua__("lhs % rhs");
    }

    @:op(A == B)
    public function eq(rhs: NativeVector2i) : Bool {
        var lhs = this;
        return untyped __lua__("lhs == rhs");
    }

    @:op(A != B)
    public function neq(rhs: NativeVector2i) : Bool {
        var lhs = this;
        return untyped __lua__("lhs != rhs");
    }

    @:op(A < B)
    public function lt(rhs: NativeVector2i) : Bool {
        var lhs = this;
        return untyped __lua__('lhs < rhs');
    }
    
    @:op(A <= B)
    public function lte(rhs: NativeVector2i) : Bool {
        var lhs = this;
        return untyped __lua__('lhs <= rhs');
    }
    
    @:op(A > B)
    public function gt(rhs: NativeVector2i) : Bool {
        var lhs = this;
        return untyped __lua__('lhs > rhs');
    }
    
    @:op(A >= B)
    public function gte(rhs: NativeVector2i) : Bool {
        var lhs = this;
        return untyped __lua__('lhs >= rhs');
    }

    public static function toString(v:NativeVector2i) {
        return untyped __lua__("v.tostring()");
    }
}