#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <godot_cpp/classes/translation.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTranslation godot::Translation

#include "resource.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace sunaba::core {
    void bindTranslation(sol::state &lua);

    class Translation : public Resource {
    private:
        GodotTranslation* translation = nullptr; // Pointer to the Translation instance
    public:
        // Constructor with Ref<GodotTranslation> parameter
        Translation(GodotTranslation* translation) {
            setTranslation(translation);
        }

        // Constructor with no parameters
        Translation() {
            setTranslation(memnew(GodotTranslation));
        }

        // Getter for the Translation node
        GodotTranslation* getTranslation() {
            return translation;
        }

        // Setter for the Translation node
        void setTranslation(GodotTranslation* translation) {
            this->translation = translation;
            translation->reference();
            setResource(translation);
        }

        std::string getLocale() {
            return translation->get_locale().utf8().get_data();
        }

        void setLocale(std::string locale) {
            translation->set_locale(String(locale.c_str()));
        }

        void addMessage(std::string srcMessage, std::string xlatedMessage, int n, std::string context = "") {
            translation->add_message(String(srcMessage.c_str()), String(xlatedMessage.c_str()), String(context.c_str()));
        }

        void addPluralMessage(std::string srcMessage, std::vector<std::string> xlatedMessages, int n, std::string context = "") {
            PackedStringArray xlatedMessagesPSA;
            for (const auto& msg : xlatedMessages) {
                xlatedMessagesPSA.push_back(String(msg.c_str()));
            }
            translation->add_plural_message(String(srcMessage.c_str()), xlatedMessagesPSA, String(context.c_str()));
        }

        void eraseMessage(std::string srcMessage, std::string context) {
            translation->erase_message(String(srcMessage.c_str()), String(context.c_str()));
        }

        std::string getMessage(std::string srcMessage, std::string context) {
            return String(translation->get_message(String(srcMessage.c_str()), String(context.c_str()))).utf8().get_data();
        }

        int getMessageCount() {
            return translation->get_message_count();
        }

        std::vector<std::string> getMessageList() {
            std::vector<std::string> messageList;
            PackedStringArray psa = translation->get_message_list();
            for (int i = 0; i < psa.size(); i++) {
                messageList.push_back(String(psa[i]).utf8().get_data());
            }
            return messageList;
        }
    };
}

#endif // TRANSLATION_H