package lucidware;

enum abstract ClipChildrenMode(Int) from Int to Int {
	var disabled = 0;
	var only = 1;
	var andDraw = 2;
	var max = 3;
}
