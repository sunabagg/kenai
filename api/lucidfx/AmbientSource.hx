package lucidfx;

enum abstract AmbientSource(Int) from Int to Int {
	var bg = 0;
	var disabled = 1;
	var color = 2;
	var sky = 3;
}
