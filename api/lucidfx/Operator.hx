package lucidfx;

enum abstract Operator(Int) from Int to Int {
	var equal = 0;
	var notEqual = 1;
	var less = 2;
	var lessEqual = 3;
	var greater = 4;
	var greaterEqual = 5;
	var add = 6;
	var subtract = 7;
	var multiply = 8;
	var divide = 9;
	var negate = 10;
	var positive = 11;
	var module = 12;
	var power = 13;
	var shiftLeft = 14;
	var shiftRight = 15;
	var bitAnd = 16;
	var bitOr = 17;
	var bitXor = 18;
	var bitNegate = 19;
	var and = 20;
	var or = 21;
	var xor = 22;
	var not = 23;
	var in = 24;
	var max = 25;
}
