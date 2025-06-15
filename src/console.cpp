#include "console.h"

using namespace sunaba;

void Console::_bind_methods() {
    ClassDB::bind_method(D_METHOD("start_shell", "path"), &Console::start_shell);
    ClassDB::bind_method(D_METHOD("run_command", "command"), &Console::run_command);
    ClassDB::bind_method(D_METHOD("run_executable", "path", "args"), &Console::run_executable);
    ClassDB::bind_method(D_METHOD("run_executable_dir", "path", "args"), &Console::run_executable_dir);
}