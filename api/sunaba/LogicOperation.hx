package sunaba;

enum abstract LogicOperation(Int) from Int to Int {
	var clear = 0;
	var and = 1;
	var andReverse = 2;
	var copy = 3;
	var andInverted = 4;
	var noOp = 5;
	var xor = 6;
	var or = 7;
	var nor = 8;
	var equivalent = 9;
	var invert = 10;
	var orReverse = 11;
	var copyInverted = 12;
	var orInverted = 13;
	var nand = 14;
	var set = 15;
	var max = 16;
}
