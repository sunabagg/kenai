package lucidware;

enum abstract CollisionModeEnum(Int) from Int to Int {
	var disabled = 0;
	var rigid = 1;
	var hideOnContact = 2;
	var max = 3;
}
