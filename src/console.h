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

        std::vector<std::function<void(const String &output)>> output_callbacks;

        void _ready() override;

        void start_shell(const String &path);

        void run_command(const String &command);

        void register_command(const String &name, const std::function<void(const std::vector<std::string> &args)> &callback);
        
        void unregister_command(const String &name);

        void run_executable(const String &path, const std::vector<String> &args);
    };
}

#endif //CONSOLE_H