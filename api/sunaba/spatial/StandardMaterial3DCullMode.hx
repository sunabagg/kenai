package sunaba..spatial;

enum abstract StandardMaterial3DCullMode(Int) from Int to Int {
	var back = 0;
	var front = 1;
	var disabled = 2;
}
