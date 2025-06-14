package sunaba;

enum abstract MidiMessage(Int) {
	var None = 0;
	var NoteOff = 8;
	var NoteOn = 9;
	var Aftertouch = 10;
	var ControlChange = 11;
	var ProgramChange = 12;
	var ChannelPressure = 13;
	var PitchBend = 14;
	var SystemExclusive = 240;
	var QuarterFrame = 241;
	var SongPositionPointer = 242;
	var SongSelect = 243;
	var TuneRequest = 246;
	var TimingClock = 248;
	var Start = 250;
	var Continue = 251;
	var Stop = 252;
	var ActiveSensing = 254;
	var SystemReset = 255;
}
