package lucidware;

enum abstract TtsUtteranceEvent(Int) from Int to Int {
	var started = 0;
	var ended = 1;
	var canceled = 2;
	var boundary = 3;
}
