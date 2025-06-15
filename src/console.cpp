#include "console.h"

#include "core/io/file_system_io.h"

#include "app.h"

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
    sunaba::core::io::bindIoManager(global_state);
    global_state.set("io", ioManager);

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

void Console::start_shell(const String &path) {
    shell_path = "sys://";

    sunaba::core::io::FileSystemIo *fs_io = sunaba::core::io::FileSystemIo::create(
        path.utf8().get_data(), "sys://"
    );

    if (fs_io) {
        ioManager->add(fs_io);
    } else {
        print(String("Failed to create FileSystemIo for path: " + path).utf8().get_data());
        return;
    }

    this->path.push_back(shell_path.utf8().get_data());
    
    display_default_output();
}

void Console::run_command(const String &command) {
    if (!prompt_available) {
        print("Prompt is not available. Please wait for the shell to be ready.");
        return;
    }
    prompt_available = false;
    default_output_handler->input_line_edit->set_editable(false);
    sol::protected_function_result result = global_state.safe_script(command.utf8().get_data(), sol::script_pass_on_error);
    if (!result.valid()) {
        sol::error err = result;
        print(String("Error executing command: " + String(err.what())).utf8().get_data());
    }
    prompt_available = true;
    default_output_handler->input_line_edit->set_editable(true);
}

void Console::register_command(const std::string &name, const std::function<void(const std::vector<std::string> &args)> &callback) {
    global_state[name] = [callback](const sol::variadic_args &args) {
        std::vector<std::string> arguments;
        for (size_t i = 0; i < args.size(); ++i) {
            if (args[i].is<std::string>()) {
                arguments.push_back(args[i].as<std::string>());
            } else {
                UtilityFunctions::print("Command expects string arguments");
                return;
            }
        }
        callback(arguments);
    };
}

void Console::display_default_output() {
    if (default_output_handler) {
        default_output_handler->show();
        default_output_handler->input_line_edit->set_editable(true);
        default_output_handler->input_line_edit->grab_focus();
    }
}

void Console::unregister_command(const std::string &name) {
    global_state[name] = sol::nil;
}

void Console::run_executable(std::string &path, const std::vector<std::string> &args) {
    if (path.empty()) {
        print("Executable path is empty.");
        return;
    }

    if (!String(path.c_str()).ends_with(".sbx")) {
        path = String(String(path.c_str()) + ".sbx").utf8().get_data();
    }

    if (ioManager) {
        auto local_path = String(shell_path + path.c_str()).utf8().get_data();

        if (ioManager->fileExists(local_path)) {
            path = local_path;
        }

        if (!ioManager->fileExists(path)) {
            print(String("Executable not found: " + String(path.c_str())).utf8().get_data());
            return;
        }

        sunaba::core::io::BinaryData binary_data = ioManager->loadBinary(path);
        if (binary_data.size() == 0) {
            print(String("Failed to load executable: " + String(path.c_str())).utf8().get_data());
            return;
        }

        // TODO: implement the logic to run the executable
    }
}