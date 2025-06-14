package sunaba;

enum abstract StructuredTextParser(Int) {
	var Default = 0;
	var Uri = 1;
	var File = 2;
	var Email = 3;
	var List = 4;
	var Gdscript = 5;
	var Custom = 6;
}
