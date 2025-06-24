package;

class Main {
    static function main() {
        try {
            var url = "http://httpbin.org/post";
            var http = new haxe.Http(url);

            // Add form parameters
            http.setParameter("username", "haxeuser");
            http.setParameter("password", "secret");

            http.onData = function(data:String) {
                trace("Response from POST:");
                trace(data);
            }

            http.onError = function(error:String) {
                trace("POST Error: " + error);
            }

            http.request(true); // true for POST
        }
        catch(e) {
            trace(e);
        }
    }
}
