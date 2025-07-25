package sunaba.core.io;

class CommandParser {

    public static function parseCommand(cmdstr: String): Command {
        var cmdname = "";
        var cmdargs: Array<String> = [];
        var current = "";
        var inQuotes = false;
        var escapeNext = false;

        for (i in 0...cmdstr.length) {
            var c = cmdstr.charAt(i);

            if (escapeNext) {
                current += c;
                escapeNext = false;
                continue;
            }

            if (c == "\\") {
                escapeNext = true;
                continue;
            }

            if (c == "\"") {
                inQuotes = !inQuotes;
                continue;
            }

            if (!inQuotes && (c == " " || c == "\t" || c == "\n")) {
                if (current != "") {
                    if (cmdname == "") {
                        cmdname = current;
                    } else {
                        cmdargs.push(current);
                    }
                    current = "";
                }
            } else {
                current += c;
            }
        }

        if (current != "") {
            if (cmdname == "") {
                cmdname = current;
            } else {
                cmdargs.push(current);
            }
        }

        return { name: cmdname, args: cmdargs };
    }
}
