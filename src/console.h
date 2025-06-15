#ifndef CONSOLE_H
#define CONSOLE_H

#include <godot_cpp/classes/node.hpp>
#include <sol/state.hpp>
#include <map>

#include "core/io/io_manager.h"

using namespace godot;

namespace sunaba
{
    class Console : public Node {
        GDCLASS(Console, Node)
    protected:
        static void _bind_methods();
    public:
        Console();
        ~Console();

        sol::state global_state;

        sunaba::core::io::IoManager* ioManager;

        String shell_path;

        std::map<std::string, std::function<void(const std::vector<std::string> &args)>> commands;

        void _ready() override;

        void start_shell(const String &path);

        void run_command(const String &command);
    };
}

#endif //CONSOLE_H