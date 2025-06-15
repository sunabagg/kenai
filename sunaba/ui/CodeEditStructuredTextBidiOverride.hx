package sunaba..ui;

enum abstract CodeEditStructuredTextBidiOverride(Int) from Int to Int {
	var default = 0;
	var uri = 1;
	var file = 2;
	var email = 3;
	var list = 4;
	var gdscript = 5;
	var custom = 6;
}
