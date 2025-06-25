package sunaba..desktop;

enum abstract WindowAnisotropicFilteringLevel(Int) from Int to Int {
	var disabled = 0;
	var anisotropy2x = 1;
	var anisotropy4x = 2;
	var anisotropy8x = 3;
	var anisotropy16x = 4;
	var max = 5;
}
