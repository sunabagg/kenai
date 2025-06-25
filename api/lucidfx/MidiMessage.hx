package lucidfx;

enum abstract MidiMessage(Int) from Int to Int {
	var none = 0;
	var noteOff = 8;
	var noteOn = 9;
	var aftertouch = 10;
	var controlChange = 11;
	var programChange = 12;
	var channelPressure = 13;
	var pitchBend = 14;
	var systemExclusive = 240;
	var quarterFrame = 241;
	var songPositionPointer = 242;
	var songSelect = 243;
	var tuneRequest = 246;
	var timingClock = 248;
	var start = 250;
	var continue = 251;
	var stop = 252;
	var activeSensing = 254;
	var systemReset = 255;
}
