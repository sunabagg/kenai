package lucidware;

enum abstract RenderPrimitive(Int) from Int to Int {
	var points = 0;
	var lines = 1;
	var linesWithAdjacency = 2;
	var linestrips = 3;
	var linestripsWithAdjacency = 4;
	var triangles = 5;
	var trianglesWithAdjacency = 6;
	var triangleStrips = 7;
	var triangleStripsWithAjacency = 8;
	var triangleStripsWithRestartIndex = 9;
	var tesselationPatch = 10;
	var max = 11;
}
