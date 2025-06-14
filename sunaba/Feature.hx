package sunaba;

enum abstract Feature(Int) {
	var SimpleLayout = 1;
	var BidiLayout = 2;
	var VerticalLayout = 4;
	var Shaping = 8;
	var KashidaJustification = 16;
	var BreakIterators = 32;
	var FontBitmap = 64;
	var FontDynamic = 128;
	var FontMsdf = 256;
	var FontSystem = 512;
	var FontVariable = 1024;
	var ContextSensitiveCaseConversion = 2048;
	var UseSupportData = 4096;
	var UnicodeIdentifiers = 8192;
	var UnicodeSecurity = 16384;
}
