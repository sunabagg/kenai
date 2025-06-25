package lucidfx;

enum abstract State(Int) from Int to Int {
	var connecting = 0;
	var open = 1;
	var closing = 2;
	var closed = 3;
}
