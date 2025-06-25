package lucidfx;

enum abstract GraphemeFlag(Int) from Int to Int {
	var valid = 1;
	var rtl = 2;
	var virtual = 4;
	var space = 8;
	var breakHard = 16;
	var breakSoft = 32;
	var tab = 64;
	var elongation = 128;
	var punctuation = 256;
	var underscore = 512;
	var connected = 1024;
	var safeToInsertTatweel = 2048;
	var embeddedObject = 4096;
	var softHyphen = 8192;
}
