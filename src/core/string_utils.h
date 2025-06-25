#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

namespace lucidfx::core {
    class StringUtils
    {
    public:
        static std::string replace(const std::string &str, const std::string &from, const std::string &to)
        {
            String s = str.c_str();
            String f = from.c_str();
            String t = to.c_str();
            return s.replace(f, t).utf8().get_data();
        }

        static bool beginsWith(const std::string &str, const std::string &prefix)
        {
            String s = str.c_str();
            String p = prefix.c_str();
            return s.begins_with(p);
        }

        static bool endsWith(const std::string &str, const std::string &suffix)
        {
            String s = str.c_str();
            String p = suffix.c_str();
            return s.ends_with(p);
        }

        static bool contains(const std::string &str, const std::string &substr)
        {
            String s = str.c_str();
            String p = substr.c_str();
            return s.contains(p);
        }
    };
    
}

#endif