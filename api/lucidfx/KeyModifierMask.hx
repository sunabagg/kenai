package lucidfx;

enum abstract KeyModifierMask(Int) from Int to Int {
	var codeMask = 8388607;
	var maskCmdOrCtrl = 16777216;
	var maskShift = 33554432;
	var maskAlt = 67108864;
	var maskMeta = 134217728;
	var maskCtrl = 268435456;
	var maskKpad = 536870912;
	var maskGroupSwitch = 1073741824;
	var modifierMask = 2130706432;
}
