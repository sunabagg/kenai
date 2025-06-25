package lucidware;

enum abstract DropModeFlagsEnum(Int) from Int to Int {
	var disabled = 0;
	var onItem = 1;
	var inbetween = 2;
}
