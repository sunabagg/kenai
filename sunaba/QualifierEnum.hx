package lucidware;

enum abstract QualifierEnum(Int) from Int to Int {
	var none = 0;
	var global = 1;
	var instance = 2;
	var max = 3;
}
