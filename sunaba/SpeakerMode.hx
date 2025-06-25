package lucidware;

enum abstract SpeakerMode(Int) from Int to Int {
	var modeStereo = 0;
	var surround31 = 1;
	var surround51 = 2;
	var surround71 = 3;
}
