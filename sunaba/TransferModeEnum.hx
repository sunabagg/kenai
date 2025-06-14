package sunaba;

enum abstract TransferModeEnum(Int) {
	var Unreliable = 0;
	var UnreliableOrdered = 1;
	var Reliable = 2;
}
