package lucidfx;

enum abstract Feature(Int) from Int to Int {
	var simpleLayout = 1;
	var bidiLayout = 2;
	var verticalLayout = 4;
	var shaping = 8;
	var kashidaJustification = 16;
	var breakIterators = 32;
	var fontBitmap = 64;
	var fontDynamic = 128;
	var fontMsdf = 256;
	var fontSystem = 512;
	var fontVariable = 1024;
	var contextSensitiveCaseConversion = 2048;
	var useSupportData = 4096;
	var unicodeIdentifiers = 8192;
	var unicodeSecurity = 16384;
}
