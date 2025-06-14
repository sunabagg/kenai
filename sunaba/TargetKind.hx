package sunaba;

enum abstract TargetKind(Int) {
	var Static = 0;
	var GodotObject = 1;
	var CompilerGenerated = 2;
}
