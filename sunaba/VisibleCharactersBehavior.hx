package lucidware;

enum abstract VisibleCharactersBehavior(Int) from Int to Int {
	var charsBeforeShaping = 0;
	var charsAfterShaping = 1;
	var glyphsAuto = 2;
	var glyphsLtr = 3;
	var glyphsRtl = 4;
}
