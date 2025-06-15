#ifndef CONSOLE_H
#define CONSOLE_H

#include <godot_cpp/classes/node.hpp>
#include <sol/state.hpp>

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

        void _ready() override;

        void start_shell(const String &path);
    };
}

#endif //CONSOLE_H