#ifndef DICT_ENCODING_H
#define DICT_ENCODING_H

#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/object.hpp>

using namespace godot;

namespace sunaba::core {
    class DictEncoding : public Object {
        GDCLASS(DictEncoding, Object)
        protected:
            static void _bind_methods() {}
        public:
            static bool _glob_filters(const String& value, Array list) {
                for (int i = 0; i < list.size(); i++) {
                    String expr = list[i];
                    if (value.match(expr))
                        return true; 
                }
                return false;
            }
    };
}

#endif