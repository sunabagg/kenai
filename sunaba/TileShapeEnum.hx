package lucidware;

enum abstract TileShapeEnum(Int) from Int to Int {
	var square = 0;
	var isometric = 1;
	var halfOffsetSquare = 2;
	var hexagon = 3;
}
