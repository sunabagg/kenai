package sunaba;

enum abstract NodeType(Int) {
	var None = 0;
	var Element = 1;
	var ElementEnd = 2;
	var Text = 3;
	var Comment = 4;
	var Cdata = 5;
	var Unknown = 6;
}
