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

namespace sunaba::core {
    class StlFunctionWrapper : public Object {
        GDCLASS(StlFunctionWrapper, Object);
    private:
        std::function<Variant(const godot::Variant**, GDExtensionInt, GDExtensionCallError)> cpp_function;
    public:
        void set_cpp_function(std::function<Variant(const Variant**, GDExtensionInt, GDExtensionCallError)> func) {
            cpp_function = func;
        }
        Variant invoke_cpp_function(const godot::Variant** args, GDExtensionInt& arg_count, GDExtensionCallError &error) {
            if (cpp_function) {
                return cpp_function(args, arg_count, error);
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
                MethodInfo(Variant::Type::NIL, "callEvent") // Add method info for clarity
            );
        }
    };
}

#endif // CPP_FUNC_WRAPPER_H