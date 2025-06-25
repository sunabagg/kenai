package sunaba;

enum abstract CanvasOccluderPolygonCullMode(Int) from Int to Int {
	var disabled = 0;
	var clockwise = 1;
	var counterClockwise = 2;
}
