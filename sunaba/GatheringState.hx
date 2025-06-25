package lucidware;

enum abstract GatheringState(Int) from Int to Int {
	var new = 0;
	var gathering = 1;
	var complete = 2;
}
