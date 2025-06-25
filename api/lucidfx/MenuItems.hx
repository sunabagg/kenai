package lucidfx;

enum abstract MenuItems(Int) from Int to Int {
	var cut = 0;
	var copy = 1;
	var paste = 2;
	var clear = 3;
	var selectAll = 4;
	var undo = 5;
	var redo = 6;
	var submenuTextDir = 7;
	var dirInherited = 8;
	var dirAuto = 9;
	var dirLtr = 10;
	var dirRtl = 11;
	var displayUcc = 12;
	var submenuInsertUcc = 13;
	var insertLrm = 14;
	var insertRlm = 15;
	var insertLre = 16;
	var insertRle = 17;
	var insertLro = 18;
	var insertRlo = 19;
	var insertPdf = 20;
	var insertAlm = 21;
	var insertLri = 22;
	var insertRli = 23;
	var insertFsi = 24;
	var insertPdi = 25;
	var insertZwj = 26;
	var insertZwnj = 27;
	var insertWj = 28;
	var insertShy = 29;
	var emojiAndSymbol = 30;
	var max = 31;
}
