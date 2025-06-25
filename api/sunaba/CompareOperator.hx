package sunaba;

enum abstract CompareOperator(Int) from Int to Int {
	var never = 0;
	var less = 1;
	var equal = 2;
	var lessOrEqual = 3;
	var greater = 4;
	var notEqual = 5;
	var greaterOrEqual = 6;
	var always = 7;
	var max = 8;
}
