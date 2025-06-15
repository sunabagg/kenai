#include "console.h"

using namespace sunaba;

void Console::_bind_methods() {
    ClassDB::bind_method(D_METHOD("start_shell", "path"), &Console::start_shell);
    ClassDB::bind_method(D_METHOD("run_command", "command"), &Console::run_command);
}

Console::Console() {
    ioManager = new sunaba::core::io::IoManager();
    
    default_output_handler = memnew(DefaultOutputHandler);
    default_output_handler->set_console(this);
    add_child(default_output_handler);
}