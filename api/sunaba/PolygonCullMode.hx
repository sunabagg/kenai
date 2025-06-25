package sunaba;

enum abstract PolygonCullMode(Int) from Int to Int {
	var disabled = 0;
	var front = 1;
	var back = 2;
}
