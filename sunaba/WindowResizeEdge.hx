package lucidware;

enum abstract WindowResizeEdge(Int) from Int to Int {
	var topLeft = 0;
	var top = 1;
	var topRight = 2;
	var left = 3;
	var right = 4;
	var bottomLeft = 5;
	var bottom = 6;
	var bottomRight = 7;
	var max = 8;
}
