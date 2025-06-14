package sunaba;

enum abstract VisibleCharactersBehavior(Int) {
	var CharsBeforeShaping = 0;
	var CharsAfterShaping = 1;
	var GlyphsAuto = 2;
	var GlyphsLtr = 3;
	var GlyphsRtl = 4;
}
