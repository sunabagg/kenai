#include "bind_io_classes.h"

#include "io_interface.h"
#include "system_io_interface.h"
#include "file_system_io.h"
#include "io_manager.h"
#include "zip_io.h"


void kenai::core::io::bindIoClasses(sol::state& lua) {
    bindIoInterface(lua);
    bindSystemIoInterface(lua);
    bindFileSystemIo(lua);
    bindIoManager(lua);
    bindZipIo(lua);
}
