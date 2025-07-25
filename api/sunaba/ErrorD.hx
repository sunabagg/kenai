package sunaba;

function ErrorD(err: String, title: String = "Error"): Void {
    untyped __lua__("_G.__errord(err, title)");
}