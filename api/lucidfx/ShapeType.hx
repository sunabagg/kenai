package lucidfx;

enum abstract ShapeType(Int) from Int to Int {
	var worldBoundary = 0;
	var separationRay = 1;
	var sphere = 2;
	var box = 3;
	var capsule = 4;
	var cylinder = 5;
	var convexPolygon = 6;
	var concavePolygon = 7;
	var heightmap = 8;
	var softBody = 9;
	var custom = 10;
}
