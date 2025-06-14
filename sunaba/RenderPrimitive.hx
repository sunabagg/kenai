package sunaba;

enum abstract RenderPrimitive(Int) {
	var Points = 0;
	var Lines = 1;
	var LinesWithAdjacency = 2;
	var Linestrips = 3;
	var LinestripsWithAdjacency = 4;
	var Triangles = 5;
	var TrianglesWithAdjacency = 6;
	var TriangleStrips = 7;
	var TriangleStripsWithAjacency = 8;
	var TriangleStripsWithRestartIndex = 9;
	var TesselationPatch = 10;
	var Max = 11;
}
