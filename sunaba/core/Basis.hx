package sunaba.core;

abstract Basis(NativeBasis) from NativeBasis {
    public function new(x : NativeVector3, y : NativeVector3, z : NativeVector3) {
        this = new NativeBasis(x, y, z);
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
        throw 'Invalid index';
    }
        
    @:op([]) 
    public function arrayWrite(n:Dynamic, value:GdVector3) {
        if (n == 0) this.x = value;
        else if (n == 1) this.y = value;
        else if (n == 2) this.z = value;
        else if (n == 'x') this.x = value;
        else if (n == 'y') this.y = value;
        else if (n == 'z') this.z = value;
        else throw 'Invalid index';
    }
    
    @:op(A + B)
    public function add(rhs: Any) : Basis {
        var lhs = this;
        return untyped __lua__('lhs + rhs');
    }
    
    @:op(A - B)
    public function sub(rhs: Any) : Basis {
        var lhs = this;
        return untyped __lua__('lhs - rhs');
    }
    
    @:op(A * B)
    public function mul(rhs: Any) : Basis {
        var lhs = this;
        return untyped __lua__('lhs * rhs');
    }
    
    @:op(A / B)
    public function div(rhs: Any) : Basis {
        var lhs = this;
        return untyped __lua__('lhs / rhs');
    }
    
    @:op(A % B)
    public function mod(rhs: Any) : Basis {
        var lhs = this;
        return untyped __lua__('lhs % rhs');
    }
    
    @:op(A == B)
    public function eq(rhs: NativeBasis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs == rhs');
    }
    
    @:op(A != B)
    public function neq(rhs: NativeBasis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs ~= rhs');
    }
    
    @:op(A < B)
    public function lt(rhs: NativeBasis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs < rhs');
    }
    
    @:op(A <= B)
    public function lte(rhs: NativeBasis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs <= rhs');
    }
    
    @:op(A > B)
    public function gt(rhs: NativeBasis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs > rhs');
    }
    
    @:op(A >= B)
    public function gte(rhs: NativeBasis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs >= rhs');
    }

    public static function toString(v:NativeBasis) {
        return untyped __lua__('v.tostring()');
    }
}