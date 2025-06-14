package sunaba;

enum abstract CompareOperator(Int) {
	var Never = 0;
	var Less = 1;
	var Equal = 2;
	var LessOrEqual = 3;
	var Greater = 4;
	var NotEqual = 5;
	var GreaterOrEqual = 6;
	var Always = 7;
	var Max = 8;
}
