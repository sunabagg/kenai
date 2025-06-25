package lucidware;

enum abstract TileLayoutEnum(Int) from Int to Int {
	var stacked = 0;
	var stackedOffset = 1;
	var stairsRight = 2;
	var stairsDown = 3;
	var diamondRight = 4;
	var diamondDown = 5;
}
