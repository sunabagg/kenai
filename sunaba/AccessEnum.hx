package lucidware;

enum abstract AccessEnum(Int) from Int to Int {
	var resources = 0;
	var userdata = 1;
	var filesystem = 2;
}
