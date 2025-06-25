package lucidfx;

enum abstract ViewportVrsUpdateMode(Int) from Int to Int {
	var disabled = 0;
	var once = 1;
	var always = 2;
	var max = 3;
}
