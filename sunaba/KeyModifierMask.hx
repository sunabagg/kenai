package sunaba;

enum abstract KeyModifierMask(Int) {
	var CodeMask = 8388607;
	var MaskCmdOrCtrl = 16777216;
	var MaskShift = 33554432;
	var MaskAlt = 67108864;
	var MaskMeta = 134217728;
	var MaskCtrl = 268435456;
	var MaskKpad = 536870912;
	var MaskGroupSwitch = 1073741824;
	var ModifierMask = 2130706432;
}
