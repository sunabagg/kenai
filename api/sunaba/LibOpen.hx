package sunaba;

function LibOpen(path: String) {
    untyped __lua__("_G.libopen(path)");
}