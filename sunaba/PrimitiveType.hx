package sunaba;

enum abstract PrimitiveType(Int) from Int to Int {
	var points = 0;
	var lines = 1;
	var lineStrip = 2;
	var triangles = 3;
	var triangleStrip = 4;
	var max = 5;
}
