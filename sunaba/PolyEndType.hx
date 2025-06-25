package lucidware;

enum abstract PolyEndType(Int) from Int to Int {
	var polygon = 0;
	var joined = 1;
	var butt = 2;
	var square = 3;
	var round = 4;
}
