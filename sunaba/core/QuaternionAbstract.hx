package sunaba.core;

abstract QuaternionAbstract(Quaternion) from Quaternion to Quaternion {
    public function new(x : Float = 0, y : Float = 0, z : Float = 0, w : Float = 0) {
        this = new Quaternion(x, y, z, w);
    }

    @:op(a.b) 
    public function fieldRead(name:String) {
        if (name == 'toString') {
            return function() : String {
                var v = this;
                return untyped __lua__('v.tostring()');
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
        if (n == 'w') return this.w; 
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
        else if (n == 'w') this.w = value;
        else throw 'Invalid index';
    }
    
    @:op(A + B)
    public function add(rhs: Any) : Quaternion {
        var lhs = this;
        return untyped __lua__('lhs + rhs');
    }
    
    @:op(A - B)
    public function sub(rhs: Any) : Quaternion {
        var lhs = this;
        return untyped __lua__('lhs - rhs');
    }
    
    @:op(A * B)
    public function mul(rhs: Any) : Quaternion {
        var lhs = this;
        return untyped __lua__('lhs * rhs');
    }
    
    @:op(A / B)
    public function div(rhs: Any) : Quaternion {
        var lhs = this;
        return untyped __lua__('lhs / rhs');
    }
    
    @:op(A % B)
    public function mod(rhs: Any) : Quaternion {
        var lhs = this;
        return untyped __lua__('lhs % rhs');
    }
    
    @:op(A == B)
    public function eq(rhs: Quaternion) : Bool {
        var lhs = this;
        return untyped __lua__('lhs == rhs');
    }
    
    @:op(A != B)
    public function neq(rhs: Quaternion) : Bool {
        var lhs = this;
        return untyped __lua__('lhs ~= rhs');
    }
    
    @:op(A < B)
    public function lt(rhs: Quaternion) : Bool {
        var lhs = this;
        return untyped __lua__('lhs < rhs');
    }
    
    @:op(A <= B)
    public function lte(rhs: Quaternion) : Bool {
        var lhs = this;
        return untyped __lua__('lhs <= rhs');
    }
    
    @:op(A > B)
    public function gt(rhs: Quaternion) : Bool {
        var lhs = this;
        return untyped __lua__('lhs > rhs');
    }
    
    @:op(A >= B)
    public function gte(rhs: Quaternion) : Bool {
        var lhs = this;
        return untyped __lua__('lhs >= rhs');
    }

    @:op(A += B)
    public function addAssign(rhs: Any) : Quaternion {
        var lhs = this;
        return untyped __lua__('lhs += rhs');
    }

    @:op(A -= B)
    public function subAssign(rhs: Any) : Quaternion {
        var lhs = this;
        return untyped __lua__('lhs -= rhs');
    }

    @:op(A *= B)
    public function mulAssign(rhs: Any) : Quaternion {
        var lhs = this;
        return untyped __lua__('lhs *= rhs');
    }

    @:op(A /= B)
    public function divAssign(rhs: Any) : Quaternion {
        var lhs = this;
        return untyped __lua__('lhs /= rhs');
    }

    public static function toString(v:Quaternion) {
        return untyped __lua__('v.tostring()');
    }
}