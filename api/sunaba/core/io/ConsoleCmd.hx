package sunaba.core.io;

import haxe.Json;

function ConsoleCmd(cmd: String, console: Console) : Void {
    var parsedCommand = CommandParser.parseCommand(cmd);
    if (parsedCommand == null) {
        throw "Invalid command format";
        return;
    }

    var commandJson = Json.stringify(parsedCommand);
    trace(commandJson);
}