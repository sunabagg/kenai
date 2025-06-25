package lucidware;

enum abstract BlendOperation(Int) from Int to Int {
	var add = 0;
	var subtract = 1;
	var reverseSubtract = 2;
	var minimum = 3;
	var maximum = 4;
	var max = 5;
}
