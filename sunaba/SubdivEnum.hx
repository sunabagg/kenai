package sunaba;

enum abstract SubdivEnum(Int) from Int to Int {
	var subdiv64 = 0;
	var subdiv128 = 1;
	var subdiv256 = 2;
	var subdiv512 = 3;
	var max = 4;
}
