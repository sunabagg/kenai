package lucidware;

enum abstract SdfOversizeEnum(Int) from Int to Int {
	var oversize100Percent = 0;
	var oversize120Percent = 1;
	var oversize150Percent = 2;
	var oversize200Percent = 3;
	var max = 4;
}
