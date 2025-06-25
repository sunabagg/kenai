package lucidware;

enum abstract AutoAdvanceMode(Int) from Int to Int {
	var disabled = 0;
	var enabled = 1;
	var returnToHold = 2;
}
