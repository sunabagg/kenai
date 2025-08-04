#ifndef DICT_ENCODING_H
#define DICT_ENCODING_H

#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>

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

            static Error _filter_class(const String& cname) {
                //if (!_glob_filters(cname))
                if (!ClassDBSingleton::get_singleton()->class_exists(cname)) {
                    return Error::ERR_UNAVAILABLE;
                }
                if (!ClassDBSingleton::get_singleton()->can_instantiate(cname)) {
                    return Error::ERR_UNAVAILABLE;
                }
                return Error::OK;
            }
    };
}

#endif