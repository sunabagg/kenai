package lucidware;

enum abstract RadianceSizeEnum(Int) from Int to Int {
	var size32 = 0;
	var size64 = 1;
	var size128 = 2;
	var size256 = 3;
	var size512 = 4;
	var size1024 = 5;
	var size2048 = 6;
	var max = 7;
}
