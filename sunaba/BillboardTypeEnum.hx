package lucidware;

enum abstract BillboardTypeEnum(Int) from Int to Int {
	var disabled = 0;
	var enabled = 1;
	var fixedY = 2;
	var particles = 3;
	var max = 4;
}
