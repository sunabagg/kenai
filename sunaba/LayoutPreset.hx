package sunaba;

enum abstract LayoutPreset(Int) from Int to Int {
	var topLeft = 0;
	var topRight = 1;
	var bottomLeft = 2;
	var bottomRight = 3;
	var centerLeft = 4;
	var centerTop = 5;
	var centerRight = 6;
	var centerBottom = 7;
	var center = 8;
	var leftWide = 9;
	var topWide = 10;
	var rightWide = 11;
	var bottomWide = 12;
	var vcenterWide = 13;
	var hcenterWide = 14;
	var fullRect = 15;
}
