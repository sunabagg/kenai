package sunaba;

enum abstract DrawFlags(Int) {
	var Transparent = 0;
	var Shaded = 1;
	var DoubleSided = 2;
	var DisableDepthTest = 3;
	var FixedSize = 4;
	var Max = 5;
}
