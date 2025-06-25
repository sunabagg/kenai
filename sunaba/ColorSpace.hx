package lucidware;

enum abstract ColorSpace(Int) from Int to Int {
	var srgb = 0;
	var linearSrgb = 1;
	var oklab = 2;
}
