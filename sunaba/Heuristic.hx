package lucidware;

enum abstract Heuristic(Int) from Int to Int {
	var euclidean = 0;
	var manhattan = 1;
	var octile = 2;
	var chebyshev = 3;
	var max = 4;
}
