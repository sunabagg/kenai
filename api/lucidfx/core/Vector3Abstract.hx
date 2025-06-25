package lucidfx.core;

abstract Vector3Abstract(Vector3) from Vector3 to Vector3 {
    public function new(x : Float = 0, y : Float = 0, z : Float = 0) {
        this = new Vector3(x, y, z);
    }

    @:op(a.b) 
    public function fieldRead(name:String) {
        if (name == 'toString') {
            return function() : String {
                var v = this;
                return "(" + v.x + ", " + v.y + ", " + v.z + ")";
            }
        } else if (Reflect.hasField(this, name)) {
            return Reflect.field(this, name);
        } else {
            throw 'Invalid field';
        }
    }
        
    @:op(a.b) 
    public function fieldWrite(name:String, value:String) {
        if (Reflect.hasField(this, name)) {
            Reflect.setField(this, name, value);
        } else {
            throw 'Invalid field';
        }
    }
    
    @:op([]) 
    public function arrayRead(n:Dynamic) {
        if (n == 0) return this.x;
        if (n == 1) return this.y;
        if (n == 2) return this.z;
        if (n == 'x') return this.x;
        if (n == 'y') return this.y;
        if (n == 'z') return this.z; 
        throw 'Invalid index';
    }
        
    @:op([]) 
    public function arrayWrite(n:Dynamic, value:Float) {
        if (n == 0) this.x = value;
        else if (n == 1) this.y = value;
        else if (n == 2) this.z = value;
        else if (n == 'x') this.x = value;
        else if (n == 'y') this.y = value;
        else if (n == 'z') this.z = value;
        else throw 'Invalid index';
    }
    
    @:op(A + B)
    public function add(rhs: Any) : Vector3 {
        var lhs = this;
        return untyped __lua__('lhs + rhs');
    }
    
    @:op(A - B)
    public function sub(rhs: Any) : Vector3 {
        var lhs = this;
        return untyped __lua__('lhs - rhs');
    }
    
    @:op(A * B)
    public function mul(rhs: Any) : Vector3 {
        var lhs = this;
        return untyped __lua__('lhs * rhs');
    }
    
    @:op(A / B)
    public function div(rhs: Any) : Vector3 {
        var lhs = this;
        return untyped __lua__('lhs / rhs');
    }
    
    @:op(A % B)
    public function mod(rhs: Any) : Vector3 {
        var lhs = this;
        return untyped __lua__('lhs % rhs');
    }
    
    @:op(A == B)
    public function eq(rhs: Vector3) : Bool {
        var lhs = this;
        return untyped __lua__('lhs == rhs');
    }
    
    @:op(A != B)
    public function neq(rhs: Vector3) : Bool {
        var lhs = this;
        return untyped __lua__('lhs ~= rhs');
    }
    
    @:op(A < B)
    public function lt(rhs: Vector3) : Bool {
        var lhs = this;
        return untyped __lua__('lhs < rhs');
    }
    
    @:op(A <= B)
    public function lte(rhs: Vector3) : Bool {
        var lhs = this;
        return untyped __lua__('lhs <= rhs');
    }
    
    @:op(A > B)
    public function gt(rhs: Vector3) : Bool {
        var lhs = this;
        return untyped __lua__('lhs > rhs');
    }
    
    @:op(A >= B)
    public function gte(rhs: Vector3) : Bool {
        var lhs = this;
        return untyped __lua__('lhs >= rhs');
    }

    @:op(A += B)
    public function addAssign(rhs: Any) : Vector3 {
        var lhs = this;
        return untyped __lua__('lhs += rhs');
    }

    @:op(A -= B)
    public function subAssign(rhs: Any) : Vector3 {
        var lhs = this;
        return untyped __lua__('lhs -= rhs');
    }

    @:op(A *= B)
    public function mulAssign(rhs: Any) : Vector3 {
        var lhs = this;
        return untyped __lua__('lhs *= rhs');
    }

    @:op(A /= B)
    public function divAssign(rhs: Any) : Vector3 {
        var lhs = this;
        return untyped __lua__('lhs /= rhs');
    }

    public static function toString(v:Vector3) {
        return untyped __lua__('v.tostring()');
    }
}