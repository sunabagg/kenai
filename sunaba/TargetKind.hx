package lucidware;

enum abstract TargetKind(Int) from Int to Int {
	var static = 0;
	var godotObject = 1;
	var compilerGenerated = 2;
}
