#include "io_interface.h"
#include "../string_utils.h"
#include "../dict_encoding.h"
#include "../shader.h"

using namespace godot;

void sunaba::core::io::bindIoInterface(sol::state& lua) {
    lua.new_usertype<IoInterface>(
        "IoInterface",
        sol::no_constructor,
        sol::base_classes, sol::bases<BaseObject>(),
        "pathUri", sol::property(
            [](IoInterface& self) { return self.pathUri; },
            [](IoInterface& self, const std::string &value) { self.pathUri = value; }
        ),
        "getFilePath", &IoInterface::getFilePath,
        "loadText", &IoInterface::loadText,
        "saveText", &IoInterface::saveText,
        "loadBinary", &IoInterface::loadBinary,
        "saveBinary", &IoInterface::saveBinary,
        "getFileListAll", &IoInterface::getFileListAll,
        "getFileList", &IoInterface::getFileList,
        "fileExists", &IoInterface::fileExists,
        "deleteFile", &IoInterface::deleteFile,
        "moveFile", &IoInterface::moveFile,
        "createDirectory", &IoInterface::createDirectory,
        "deleteDirectory", &IoInterface::deleteDirectory,
        "directoryExists", &IoInterface::directoryExists
    );
}

std::string sunaba::core::io::IoInterface::getLuaRequirePath(const std::string &path) const {
        // Convert a file path to a Lua require path
        // This is typically done by replacing slashes with dots and removing the file extension
        std::string requirePath = StringUtils::replace(StringUtils::replace(path, "://", "."), "/", ".");
        if (StringUtils::endsWith(requirePath,".lua")) {
            requirePath = requirePath.substr(0, requirePath.size() - 4);
        }
        return requirePath;
}

std::string sunaba::core::io::IoInterface::getFilePathFromLuaRequirePath(const std::string &path) const {
    // Convert a Lua require path back to a file path
    // This is typically done by replacing dots with slashes and adding the .lua extension
    auto filePathArray = String(path.c_str()).split(".");

    String newFilePath = filePathArray[0];
    newFilePath += "://";
    for (size_t i = 1; i < filePathArray.size(); ++i) {
        newFilePath += filePathArray[i];
        if (i < filePathArray.size() - 1) {
            newFilePath += "/";
        }
    }
        
    if(fileExists(String(newFilePath + ".lua").utf8().get_data())) {
        newFilePath += ".lua";
    }

    return newFilePath.utf8().get_data();
}

sunaba::core::Resource* sunaba::core::io::IoInterface::loadResource(const std::string& path) {
    if (DictEncoding::isImagePath(path.c_str())) {
        Image* image = new Image();
        Error err = static_cast<Error>(image->load(this, path));
        if (err != Error::OK) {
            throw new sol::error("Invalid Image");
        }
        return image;
    }
    std::string resstr = loadText(path);
    if (StringUtils::endsWith(path, ".shdr")) {
        Shader* shader = new Shader();
        shader->setCode(resstr);
        return shader;
    }
    Variant resjson = JSON::parse_string(resstr.c_str());
    Object* resobj = DictEncoding::decode_dict(resjson, this);
    godot::Resource* res = Object::cast_to<godot::Resource>(resobj);
    return new sunaba::core::Resource(res);
}

void sunaba::core::io::IoInterface::saveResource(const std::string& path, Resource* res) {
    if (StringUtils::endsWith(path, ".shdr")) {
        if (!res->getResource()->is_class("Shader")) {
            throw new sol::error("shdr file must be a shader");
        }
        Shader* shader = new Shader(Object::cast_to<godot::Shader>(res->getResource()));
        std::string code = shader->getCode();
        saveText(path, code);
        return;
    }
    godot::Resource* gdres = res->getResource();
    Dictionary dict = DictEncoding::encode_dict(gdres, this);
    String json = JSON::stringify(dict, "   ");
    saveText(path, json.utf8().get_data());
}