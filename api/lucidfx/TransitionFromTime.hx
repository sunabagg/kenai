package lucidfx;

enum abstract TransitionFromTime(Int) from Int to Int {
	var immediate = 0;
	var nextBeat = 1;
	var nextBar = 2;
	var end = 3;
}
