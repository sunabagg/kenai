package sunaba.core.io;

class CommandParser {

    public static function parseCommand(cmdstr: String): Command {
        var cmdname = "";
        var cmdargs : Array<String> = [];
        var cmdstrarr = cmdstr.split(" ");
        for (str in cmdstrarr) {
            if (str != "" && str != "\t" && str != "\n") {
                if (cmdname == "") {
                    cmdname = str;
                    continue;
                }
                cmdargs.push(str);
            }
        }

        var command : Command = { name: cmdname, args: cmdargs };
        return command;
    }
}