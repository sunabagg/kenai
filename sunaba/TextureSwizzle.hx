package lucidware;

enum abstract TextureSwizzle(Int) from Int to Int {
	var identity = 0;
	var zero = 1;
	var one = 2;
	var r = 3;
	var g = 4;
	var b = 5;
	var a = 6;
	var max = 7;
}
