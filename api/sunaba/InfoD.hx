package sunaba;

function InfoD(msg: String, title: String = "Information"): Void {
    untyped __lua__("_G.__infod(msg, title)");
}