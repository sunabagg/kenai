#ifndef CPP_FUNC_WRAPPER_H
#define CPP_FUNC_WRAPPER_H

#include <godot_cpp/core/method_bind.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/signal.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/object.hpp>
#include <sol/sol.hpp>

using namespace godot;

namespace lucidfx::core {
    class StlFunctionWrapper : public Object {
        GDCLASS(StlFunctionWrapper, Object);
    private:
        std::function<Variant(std::vector<Variant>)> cpp_function;
    public:
        void set_cpp_function(std::function<Variant(std::vector<Variant>)> func) {
            cpp_function = func;
        }
        Variant invoke_cpp_function(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error) {
            if (cpp_function) {
                std::vector<Variant> args_vector;
                for (int i = 0; i < arg_count; ++i) {
                    args_vector.push_back(args[i]);
                }
                return cpp_function(args_vector);
            } else {
                error.error = GDEXTENSION_CALL_ERROR_INVALID_METHOD;
                return Variant();
            }
        }
        static void _bind_methods() {
            ClassDB::bind_vararg_method(
                METHOD_FLAGS_DEFAULT,
                "invoke_cpp_function",
                &StlFunctionWrapper::invoke_cpp_function,
                MethodInfo(Variant::Type::NIL, "invoke_cpp_function") // Add method info for clarity
            );
        }

        static Callable create_callable_from_cpp_function(std::function<Variant(std::vector<Variant>)> func) {
            StlFunctionWrapper* wrapper = memnew(StlFunctionWrapper);
            wrapper->set_cpp_function(func);
            Callable callable(wrapper, "invoke_cpp_function");
            return callable;
        }
    };
}

#define SignalFunc std::function<Variant(std::vector<Variant>)>
#define to_callable StlFunctionWrapper::create_callable_from_cpp_function

#endif // CPP_FUNC_WRAPPER_H