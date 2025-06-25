package sunaba;

enum abstract LightType(Int) from Int to Int {
	var directional = 0;
	var omni = 1;
	var spot = 2;
}
