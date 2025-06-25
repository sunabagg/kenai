package sunaba;

enum abstract TransferModeEnum(Int) from Int to Int {
	var unreliable = 0;
	var unreliableOrdered = 1;
	var reliable = 2;
}
