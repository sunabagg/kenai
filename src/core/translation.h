#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <godot_cpp/classes/translation.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTranslation godot::Translation

#include "resource.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidfx::core {
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

        void setLocale(const std::string& locale) {
            translation->set_locale(String(locale.c_str()));
        }

        void addMessage(const std::string& srcMessage, const std::string& xlatedMessage, const int n, const std::string& context = "") {
            translation->add_message(String(srcMessage.c_str()), String(xlatedMessage.c_str()), String(context.c_str()));
        }

        void addPluralMessage(const std::string& srcMessage, const std::vector<std::string> xlatedMessages, const int n, const std::string& context = "") {
            PackedStringArray xlatedMessagesPSA;
            for (const auto& msg : xlatedMessages) {
                xlatedMessagesPSA.push_back(String(msg.c_str()));
            }
            translation->add_plural_message(String(srcMessage.c_str()), xlatedMessagesPSA, String(context.c_str()));
        }

        void eraseMessage(const std::string& srcMessage, const std::string& context) {
            translation->erase_message(String(srcMessage.c_str()), String(context.c_str()));
        }

        std::string getMessage(const std::string& srcMessage, const std::string& context) {
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

        std::string getPluralMessage(const std::string& srcMessage, const std::string& srcPluralMessage, const int n, const std::string& context) {
            return String(translation->get_plural_message(String(srcMessage.c_str()), String(srcPluralMessage.c_str()), n, String(context.c_str()))).utf8().get_data();
        }

        std::vector<std::string> getTranslatedMessageList() {
            std::vector<std::string> translatedMessageList;
            PackedStringArray psa = translation->get_translated_message_list();
            for (int i = 0; i < psa.size(); i++) {
                translatedMessageList.push_back(String(psa[i]).utf8().get_data());
            }
            return translatedMessageList;
        }
    };
}

#endif // TRANSLATION_H