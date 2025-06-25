package lucidfx;

enum abstract ScriptNameCasing(Int) from Int to Int {
	var auto = 0;
	var pascalCase = 1;
	var snakeCase = 2;
	var kebabCase = 3;
}
