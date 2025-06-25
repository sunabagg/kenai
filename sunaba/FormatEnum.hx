package lucidware;

enum abstract FormatEnum(Int) from Int to Int {
	var format8Bits = 0;
	var format16Bits = 1;
	var imaAdpcm = 2;
	var qoa = 3;
}
