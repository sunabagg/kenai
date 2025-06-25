package lucidware;

enum abstract ResolutionEnum(Int) from Int to Int {
	var resolution16 = 0;
	var resolution32 = 1;
	var resolution64 = 2;
	var resolution128 = 3;
	var resolution256 = 4;
	var resolution512 = 5;
	var max = 6;
}
