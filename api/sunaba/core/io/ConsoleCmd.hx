package sunaba.core.io;

import haxe.Json;

function ConsoleCmd(cmd: String, console: Console) : Void {
    var parsedCommand = CommandParser.parseCommand(cmd);
    if (parsedCommand == null) {
        throw "Invalid command format";
        return;
    }

    //var commandJson = Json.stringify(parsedCommand);
    //console.print(commandJson);

    var luastr = "cmd('" + parsedCommand.name + "', A(";
    for (i in 0...parsedCommand.args.length) {
        var arg = parsedCommand.args[i];
        luastr += "'" + arg + "'";
        if (i != parsedCommand.args.length - 1) {
            luastr += ",";
        }
    }
    luastr += ("))");
    //console.print(luastr);
    console.eval(luastr);
}