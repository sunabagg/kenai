package lucidfx;

enum abstract ReplicationMode(Int) from Int to Int {
	var never = 0;
	var always = 1;
	var onChange = 2;
}
