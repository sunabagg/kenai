package sunaba;

enum abstract TtsUtteranceEvent(Int) {
	var Started = 0;
	var Ended = 1;
	var Canceled = 2;
	var Boundary = 3;
}
