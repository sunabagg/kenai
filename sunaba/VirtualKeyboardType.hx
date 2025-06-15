package sunaba;

enum abstract VirtualKeyboardType(Int) from Int to Int {
	var default = 0;
	var multiline = 1;
	var number = 2;
	var numberDecimal = 3;
	var phone = 4;
	var emailAddress = 5;
	var password = 6;
	var url = 7;
}
