package lucidfx;

enum abstract DraggerVisibilityEnum(Int) from Int to Int {
	var visible = 0;
	var hidden = 1;
	var hiddenCollapsed = 2;
}
