package lucidware;

enum abstract CellNeighbor(Int) from Int to Int {
	var rightSide = 0;
	var rightCorner = 1;
	var bottomRightSide = 2;
	var bottomRightCorner = 3;
	var bottomSide = 4;
	var bottomCorner = 5;
	var bottomLeftSide = 6;
	var bottomLeftCorner = 7;
	var leftSide = 8;
	var leftCorner = 9;
	var topLeftSide = 10;
	var topLeftCorner = 11;
	var topSide = 12;
	var topCorner = 13;
	var topRightSide = 14;
	var topRightCorner = 15;
}
