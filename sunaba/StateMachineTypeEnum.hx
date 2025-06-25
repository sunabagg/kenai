package lucidware;

enum abstract StateMachineTypeEnum(Int) from Int to Int {
	var root = 0;
	var nested = 1;
	var grouped = 2;
}
