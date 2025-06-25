package sunaba;

enum abstract LoaderFlags(Int) from Int to Int {
	var none = 0;
	var forceLinear = 1;
	var convertColors = 2;
}
