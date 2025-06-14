package sunaba;

enum abstract TransitionFromTime(Int) {
	var Immediate = 0;
	var NextBeat = 1;
	var NextBar = 2;
	var End = 3;
}
