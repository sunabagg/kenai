package sunaba..desktop;

enum abstract WindowAnisotropicFilteringLevel(Int) {
	var Disabled = 0;
	var Anisotropy2X = 1;
	var Anisotropy4X = 2;
	var Anisotropy8X = 3;
	var Anisotropy16X = 4;
	var Max = 5;
}
