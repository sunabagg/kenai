#include "console.h"

using namespace sunaba;

void Console::_bind_methods() {
    ClassDB::bind_method(D_METHOD("start_shell", "path"), &Console::start_shell);
    ClassDB::bind_method(D_METHOD("run_command", "command"), &Console::run_command);
}

Console::Console() {
    global_state.open_libraries( 
        sol::lib::base, sol::lib::count, 
        sol::lib::math, sol::lib::string,
        sol::lib::table, sol::lib::utf8
    );
    
    ioManager = new sunaba::core::io::IoManager();
    sunaba::core::io::bindByte(global_state);
    sunaba::core::io::bindBinaryData(global_state);
    sunaba::core::io::bindIoInterface(global_state);
    sunaba::core::io::bindIoManger(global_state);

    default_output_handler = memnew(DefaultOutputHandler);
    default_output_handler->set_console(this);
    add_child(default_output_handler);
    default_output_handler->hide();

    global_state["print"] = [this]( sol::variadic_args args ) {
        String msg;
        for ( const auto &arg : args )
        {
            if ( arg.is<std::string>() )
            {
                std::string str = arg.as<std::string>();
                msg += str.c_str();
            }
            else if (arg.is<sol::table>())
            {
                msg += "table";
            }
            else if (arg.is<Vector3>())
            {
                Vector3 vec = arg.as<Vector3>();
                msg += String(vec);
            }
            else if (arg.is<Vector2>())
            {
                Vector2 vec = arg.as<Vector2>();
                msg += String(vec);
            }
            else if (arg.is<float>())
            {
                float f = arg.as<float>();
                Variant v = f;
                msg += String(v);
            }
            else if (arg.is<bool>())
            {
                bool b = arg.as<bool>();
                Variant v = b;
                msg += String(v);
            }
            else if (arg.is<int>())
            {
                int i = arg.as<int>();
                Variant v = i;
                msg += String(v);
            }
            else if (arg.is<Vector4>())
            {
                Vector4 vec = arg.as<Vector4>();
                msg += String(vec);
            }
            else if (arg.is<Vector4i>())
            {
                Vector4i vec = arg.as<Vector4i>();
                msg += String(vec);
            }
            else if (arg.is<Vector2i>())
            {
                Vector2i vec = arg.as<Vector2i>();
                msg += String(vec);
            }
            else if (arg.is<Vector3i>())
            {
                Vector3i vec = arg.as<Vector3i>();
                msg += String(vec);
            }
        }
        print(msg.utf8().get_data());
    };

    global_state["run"] = [this](const sol::variadic_args & args) {
        std::vector<std::string> arguments;
        for (size_t i = 1; i < args.size(); ++i) {
            if (args[i].is<std::string>()) {
                arguments.push_back(args[i].as<std::string>());
            } else {
                print("run() expects string arguments");
                return;
            }
        }
        
        std::string command = args[0].as<std::string>();
        if (command.empty()) {
            print("run() expects a command as the first argument");
            return;
        }

        run_executable(command, arguments);
    };
}

void Console::print(const std::string &message) {
    if (default_output_handler) {
        default_output_handler->output_label->append_text(String(message.c_str()));
    }
    for (const auto &callback : output_callbacks) {
        callback(message);
    }
}