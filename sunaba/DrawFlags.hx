package lucidware;

enum abstract DrawFlags(Int) from Int to Int {
	var transparent = 0;
	var shaded = 1;
	var doubleSided = 2;
	var disableDepthTest = 3;
	var fixedSize = 4;
	var max = 5;
}
