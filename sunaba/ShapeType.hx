package sunaba;

enum abstract ShapeType(Int) {
	var WorldBoundary = 0;
	var SeparationRay = 1;
	var Sphere = 2;
	var Box = 3;
	var Capsule = 4;
	var Cylinder = 5;
	var ConvexPolygon = 6;
	var ConcavePolygon = 7;
	var Heightmap = 8;
	var SoftBody = 9;
	var Custom = 10;
}
