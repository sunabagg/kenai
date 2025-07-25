package sunaba;

function WarnD(msg: String, title: String = "Warning"): Void {
    untyped __lua__("_G.__warnd(msg, title)");
}