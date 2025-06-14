package sunaba;

enum abstract GraphemeFlag(Int) {
	var Valid = 1;
	var Rtl = 2;
	var Virtual = 4;
	var Space = 8;
	var BreakHard = 16;
	var BreakSoft = 32;
	var Tab = 64;
	var Elongation = 128;
	var Punctuation = 256;
	var Underscore = 512;
	var Connected = 1024;
	var SafeToInsertTatweel = 2048;
	var EmbeddedObject = 4096;
	var SoftHyphen = 8192;
}
