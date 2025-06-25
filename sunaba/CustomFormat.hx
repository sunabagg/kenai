package lucidware;

enum abstract CustomFormat(Int) from Int to Int {
	var rgba8Unorm = 0;
	var rgba8Snorm = 1;
	var rgHalf = 2;
	var rgbaHalf = 3;
	var rFloat = 4;
	var rgFloat = 5;
	var rgbFloat = 6;
	var rgbaFloat = 7;
	var max = 8;
}
