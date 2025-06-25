package lucidfx;

enum abstract ProcessInfo(Int) from Int to Int {
	var activeObjects = 0;
	var collisionPairs = 1;
	var islandCount = 2;
}
