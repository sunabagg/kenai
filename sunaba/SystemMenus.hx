package lucidware;

enum abstract SystemMenus(Int) from Int to Int {
	var invalidMenuId = 0;
	var mainMenuId = 1;
	var applicationMenuId = 2;
	var windowMenuId = 3;
	var helpMenuId = 4;
	var dockMenuId = 5;
}
