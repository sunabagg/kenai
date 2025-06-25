package lucidfx.core;

import lucidfx.core.Color;

abstract ColorAbstract(Color) from Color to Color {
    @:op(a.b) public function fieldRead(name:String) {
        if (name == 'toString') {
            return function() : String {
                var v = this;
                return "(" + v.r + ", " + v.g + ", " + v.b + ", " + v.a + ")";
            }
        } else if (Reflect.hasField(this, name)) {
            return Reflect.field(this, name);
        } else {
            throw 'Invalid field';
        }
    }

    @:op(a.b) public function fieldWrite(name:String, value:Float) {
        if (Reflect.hasField(this, name)) {
            Reflect.setField(this, name, value);
        } else {
            throw 'Invalid field';
        }
    }

    @:op([]) public function arrayRead(n:Dynamic) {
        if (n == 0) return this.r;
        if (n == 1) return this.g;
        if (n == 2) return this.b;
        if (n == 3) return this.a;
        if (n == 'r') return this.r;
        if (n == 'g') return this.g;
        if (n == 'b') return this.b;
        if (n == 'a') return this.a;
        throw 'Invalid index';
    }

    @:op([]) public function arrayWrite(n:Dynamic, value:Float) {
        if (n == 0) this.r = value;
        else if (n == 1) this.g = value;
        else if (n == 2) this.b = value;
        else if (n == 3) this.a = value;
        else if (n == 'r') this.r = value;
        else if (n == 'g') this.g = value;
        else if (n == 'b') this.b = value;
        else if (n == 'a') this.a = value;
        else throw 'Invalid index';
    }

    @:op(A + B) public function add(rhs: Any) : Color {
        var lhs = this;
        return untyped __lua__('lhs + rhs');
    }

    @:op(A - B) public function sub(rhs: Any) : Color {
        var lhs = this;
        return untyped __lua__('lhs - rhs');
    }

    @:op(A * B) public function mul(rhs: Any) : Color {
        var lhs = this;
        return untyped __lua__('lhs * rhs');
    }

    @:op(A / B) public function div(rhs: Any) : Color {
        var lhs = this;
        return untyped __lua__('lhs / rhs');
    }

    @:op(A == B) public function eq(rhs: Any) : Bool {
        var lhs = this;
        return untyped __lua__('lhs == rhs');
    }

    @:op(A != B) public function ne(rhs: Any) : Bool {
        var lhs = this;
        return untyped __lua__('lhs != rhs');
    }

    @:op(A < B) public function lt(rhs: Any) : Bool {
        var lhs = this;
        return untyped __lua__('lhs < rhs');
    }

    @:op(A <= B) public function le(rhs: Any) : Bool {
        var lhs = this;
        return untyped __lua__('lhs <= rhs');
    }

    @:op(A > B) public function gt(rhs: Any) : Bool {
        var lhs = this;
        return untyped __lua__('lhs > rhs');
    }

    @:op(A >= B) public function ge(rhs: Any) : Bool {
        var lhs = this;
        return untyped __lua__('lhs >= rhs');
    }

    @:op(A += B) public function addAssign(rhs: Any) : Color {
        var lhs = this;
        return untyped __lua__('lhs += rhs');
    }

    @:op(A -= B) public function subAssign(rhs: Any) : Color {
        var lhs = this;
        return untyped __lua__('lhs -= rhs');
    }

    @:op(A *= B) public function mulAssign(rhs: Any) : Color {
        var lhs = this;
        return untyped __lua__('lhs *= rhs');
    }

    @:op(A /= B) public function divAssign(rhs: Any) : Color {
        var lhs = this;
        return untyped __lua__('lhs /= rhs');
    }
    
}