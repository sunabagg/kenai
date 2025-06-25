package lucidware;

enum abstract PickerShapeType(Int) from Int to Int {
	var hsvRectangle = 0;
	var hsvWheel = 1;
	var vhsCircle = 2;
	var okhslCircle = 3;
	var none = 4;
}
