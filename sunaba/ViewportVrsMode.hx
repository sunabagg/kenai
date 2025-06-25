package lucidware;

enum abstract ViewportVrsMode(Int) from Int to Int {
	var disabled = 0;
	var texture = 1;
	var xr = 2;
	var max = 3;
}
