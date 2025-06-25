package lucidware;

enum abstract ShadingModeEnum(Int) from Int to Int {
	var unshaded = 0;
	var perPixel = 1;
	var perVertex = 2;
	var max = 3;
}
