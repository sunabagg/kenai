package sunaba.core;

abstract BasisAbstract(Basis) from Basis {
    public function new(x : Vector3, y : Vector3, z : Vector3) {
        this = new Basis(x, y, z);
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
        var rowsTable = this.rows;
        if (n == 0) return rowsTable[0];
        else if (n == 1) return rowsTable[1];
        else if (n == 2) return rowsTable[2];
        else if (n == 'x') return rowsTable[0];
        else if (n == 'y') return rowsTable[1];
        else if (n == 'z') return rowsTable[2];
        else
        throw 'Invalid index';
    }
        
    @:op([]) 
    public function arrayWrite(n:Dynamic, value:Vector3) {
        var rowsTable = this.rows;
        if (n == 0) rowsTable[0] = value;
        else if (n == 1) rowsTable[1] = value;
        else if (n == 2) rowsTable[2] = value;
        else if (n == 'x') rowsTable[0] = value;
        else if (n == 'y') rowsTable[1] = value;
        else if (n == 'z') rowsTable[2] = value;
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
    public function eq(rhs: Basis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs == rhs');
    }
    
    @:op(A != B)
    public function neq(rhs: Basis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs ~= rhs');
    }
    
    @:op(A < B)
    public function lt(rhs: Basis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs < rhs');
    }
    
    @:op(A <= B)
    public function lte(rhs: Basis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs <= rhs');
    }
    
    @:op(A > B)
    public function gt(rhs: Basis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs > rhs');
    }
    
    @:op(A >= B)
    public function gte(rhs: Basis) : Bool {
        var lhs = this;
        return untyped __lua__('lhs >= rhs');
    }

    @:op(A += B)
    public function addAssign(rhs: Basis) : Basis {
        var lhs = this;
        return untyped __lua__('lhs += rhs');
    }

    @:op(A -= B)
    public function subAssign(rhs: Basis) : Basis {
        var lhs = this;
        return untyped __lua__('lhs -= rhs');
    }

    @:op(A *= B)
    public function mulAssign(rhs: Basis) : Basis {
        var lhs = this;
        return untyped __lua__('lhs *= rhs');
    }

    @:op(A /= B)
    public function divAssign(rhs: Basis) : Basis {
        var lhs = this;
        return untyped __lua__('lhs /= rhs');
    }

    public static function toString(v:Basis) {
        return untyped __lua__('v.tostring()');
    }
}