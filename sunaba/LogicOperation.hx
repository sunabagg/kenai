package sunaba;

enum abstract LogicOperation(Int) {
	var Clear = 0;
	var And = 1;
	var AndReverse = 2;
	var Copy = 3;
	var AndInverted = 4;
	var NoOp = 5;
	var Xor = 6;
	var Or = 7;
	var Nor = 8;
	var Equivalent = 9;
	var Invert = 10;
	var OrReverse = 11;
	var CopyInverted = 12;
	var OrInverted = 13;
	var Nand = 14;
	var Set = 15;
	var Max = 16;
}
