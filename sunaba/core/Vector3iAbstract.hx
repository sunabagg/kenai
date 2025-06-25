package lucidfx.core;

abstract Vector3iAbstract(Vector3i) from Vector3i to Vector3i {
    public function new(x : Int = 0, y : Int = 0, z : Int = 0) {
        this = new Vector3i(x, y, z);
    }

    @:op(a.b) public function fieldRead(name:String) : Dynamic
    {
        if (name == "toString") {
            return function() : String {
                var v = this;
                return "(" + v.x + ", " + v.y + ", " + v.z + ")";
            }
        } else if (name == "native") {
            return this;
        } else if (name == "x") {
            return this.x;
        } else if (name == "y") {
            return this.y;
        } else if (name == "z") {
            return this.z;
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
        if (n == 2) return this.z;
        if (n == "x") return this.x;
        if (n == "y") return this.y;
        if (n == "z") return this.z;
        throw "Invalid index";
    }

    @:op([]) public function arrayWrite(n:Dynamic, value:Int) {
        if (n == 0) this.x = value;
        else if (n == 1) this.y = value;
        else if (n == 2) this.z = value;
        else if (n == "x") this.x = value;
        else if (n == "y") this.y = value;
        else if (n == "z") this.z = value;
        else throw "Invalid index";
    }

    @:op(A + B)
    public function add(rhs: Any) : Vector3i {
        var lhs = this;
        return untyped __lua__('lhs + rhs');
    }
    
    @:op(A - B)
    public function sub(rhs: Any) : Vector3i {
        var lhs = this;
        return untyped __lua__('lhs - rhs');
    }
    
    @:op(A * B)
    public function mul(rhs: Any) : Vector3i {
        var lhs = this;
        return untyped __lua__('lhs * rhs');
    }
    
    @:op(A / B)
    public function div(rhs: Any) : Vector3i {
        var lhs = this;
        return untyped __lua__('lhs / rhs');
    }
    
    @:op(A % B)
    public function mod(rhs: Any) : Vector3i {
        var lhs = this;
        return untyped __lua__('lhs % rhs');
    }
    
    @:op(A == B)
    public function eq(rhs: Vector3i) : Bool {
        var lhs = this;
        return untyped __lua__('lhs == rhs');
    }
    
    @:op(A != B)
    public function neq(rhs: Vector3i) : Bool {
        var lhs = this;
        return untyped __lua__('lhs ~= rhs');
    }
    
    @:op(A < B)
    public function lt(rhs: Vector3i) : Bool {
        var lhs = this;
        return untyped __lua__('lhs < rhs');
    }
    
    @:op(A <= B)
    public function lte(rhs: Vector3i) : Bool {
        var lhs = this;
        return untyped __lua__('lhs <= rhs');
    }
    
    @:op(A > B)
    public function gt(rhs: Vector3i) : Bool {
        var lhs = this;
        return untyped __lua__('lhs > rhs');
    }
    
    @:op(A >= B)
    public function gte(rhs: Vector3i) : Bool {
        var lhs = this;
        return untyped __lua__('lhs >= rhs');
    }

    @:op(A += B)
    public function addAssign(rhs: Any) : Vector3i {
        var lhs = this;
        return untyped __lua__('lhs += rhs');
    }

    @:op(A -= B)
    public function subAssign(rhs: Any) : Vector3i {
        var lhs = this;
        return untyped __lua__('lhs -= rhs');
    }

    @:op(A *= B)
    public function mulAssign(rhs: Any) : Vector3i {
        var lhs = this;
        return untyped __lua__('lhs *= rhs');
    }

    @:op(A /= B)
    public function divAssign(rhs: Any) : Vector3i {
        var lhs = this;
        return untyped __lua__('lhs /= rhs');
    }

    public static function toString(v:Vector3i) {
        return untyped __lua__('v.tostring()');
    }
}

