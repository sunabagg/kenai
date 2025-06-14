package sunaba;

enum abstract ViewportUpdateMode(Int) {
	var Disabled = 0;
	var Once = 1;
	var WhenVisible = 2;
	var WhenParentVisible = 3;
	var Always = 4;
}
