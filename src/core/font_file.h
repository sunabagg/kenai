#ifndef SUNABA_FONT_FILE_H
#define SUNABA_FONT_FILE_H

#include <godot_cpp/classes/font_file.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotFontFile godot::FontFile

#include "font.h"
#include "convert_godot_lua.h"
#include "io/io_index.h"
#include "io/binary_data.h"

using namespace godot;
using namespace sunaba::core::io;

namespace sunaba::core {
    
}

#endif // SUNABA_FONT_FILE_H