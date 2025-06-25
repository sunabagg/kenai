package lucidware;

enum abstract FftSizeEnum(Int) from Int to Int {
	var size256 = 0;
	var size512 = 1;
	var size1024 = 2;
	var size2048 = 3;
	var size4096 = 4;
	var max = 5;
}
