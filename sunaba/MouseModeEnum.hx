package sunaba;

enum abstract MouseModeEnum(Int) {
	var Visible = 0;
	var Hidden = 1;
	var Captured = 2;
	var Confined = 3;
	var ConfinedHidden = 4;
	var Max = 5;
}
