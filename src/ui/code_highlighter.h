#ifndef CODE_HIGHLIGHTER_H
#define CODE_HIGHLIGHTER_H

#include <godot_cpp/classes/code_highlighter.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotCodeHighlighter godot::CodeHighlighter

#include "syntax_highlighter.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindCodeHighlighter(sol::state &lua);

    class CodeEdit;

    class CodeHighlighter : public SyntaxHighlighter {
    private:
        GodotCodeHighlighter* code_highlighter = nullptr; // Pointer to the CodeHighlighter instance
    public:
        // Constructor with Node* parameter
        CodeHighlighter(GodotCodeHighlighter* p_node) {
            setCodeHighlighter(p_node);
        }

        // Constructor with no parameters
        CodeHighlighter() {
            setCodeHighlighter(memnew(GodotCodeHighlighter));
        }

        // Getter for the CodeHighlighter node
        GodotCodeHighlighter* getCodeHighlighter() const {
            return code_highlighter;
        }

        // Setter for the CodeHighlighter node
        void setCodeHighlighter(GodotCodeHighlighter* p_node) {
            code_highlighter = p_node;
            set(code_highlighter);
        }

        Dictionary getColorRegions() const {
            return code_highlighter->get_color_regions();
        }

        void setColorRegions(const Dictionary &p_color_regions) {
            code_highlighter->set_color_regions(p_color_regions);
        }
        
        Color getFunctionColor() const {
            return code_highlighter->get_function_color();
        }
        
        void setFunctionColor(const Color &p_color) {
            code_highlighter->set_function_color(p_color);
        }

        Dictionary getKeywordColors() const {
            return code_highlighter->get_keyword_colors();
        }

        void setKeywordColors(const Dictionary &p_keywords) {
            code_highlighter->set_keyword_colors(p_keywords);
        }

        Dictionary getMemberKeywordColors() const {
            return code_highlighter->get_member_keyword_colors();
        }

        void setMemberKeywordColors(const Dictionary &p_member_keyword) {
            code_highlighter->set_member_keyword_colors(p_member_keyword);
        }

        Color getMemberVariableColor() const {
            return code_highlighter->get_member_variable_color();
        }

        void setMemberVariableColor(const Color &p_color) {
            code_highlighter->set_member_variable_color(p_color);
        }

        Color getNumberColor() const {
            return code_highlighter->get_number_color();
        }

        void setNumberColor(const Color &p_color) {
            code_highlighter->set_number_color(p_color);
        }

        Color getSymbolColor() const {
            return code_highlighter->get_symbol_color();
        }

        void setSymbolColor(const Color &p_color) {
            code_highlighter->set_symbol_color(p_color);
        }

        void addColorRegion(const std::string &p_start_key, const std::string &p_end_key, const Color &p_color, bool p_line_only = false) {
            code_highlighter->add_color_region(p_start_key.c_str(), p_end_key.c_str(), p_color, p_line_only);
        }

        void addKeywordColor(const std::string &p_keyword, const Color &p_color) {
            code_highlighter->add_keyword_color(p_keyword.c_str(), p_color);
        }

        void addMemberKeywordColor(const std::string &p_member_keyword, const Color &p_color) {
            code_highlighter->add_member_keyword_color(p_member_keyword.c_str(), p_color);
        }

        void clearColorRegions() {
            code_highlighter->clear_color_regions();
        }

        void clearKeywordColors() {
            code_highlighter->clear_keyword_colors();
        }

        void clearMemberKeywordColors() {
            code_highlighter->clear_member_keyword_colors();
        }

        Color getKeywordColor(const std::string &p_keyword) const {
            return code_highlighter->get_keyword_color(p_keyword.c_str());
        }

        Color getMemberKeywordColor(const std::string &p_member_keyword) const {
            return code_highlighter->get_member_keyword_color(p_member_keyword.c_str());
        }

        bool hasColorRegion(const std::string &p_start_key) const {
            return code_highlighter->has_color_region(p_start_key.c_str());
        }

        bool hasKeywordColor(const std::string &p_keyword) const {
            return code_highlighter->has_keyword_color(p_keyword.c_str());
        }

        bool hasMemberKeywordColor(const std::string &p_member_keyword) const {
            return code_highlighter->has_member_keyword_color(p_member_keyword.c_str());
        }

        void removeColorRegion(const std::string &p_start_key) {
            code_highlighter->remove_color_region(p_start_key.c_str());
        }

        void removeKeywordColor(const std::string &p_keyword) {
            code_highlighter->remove_keyword_color(p_keyword.c_str());
        }

        void removeMemberKeywordColor(const std::string &p_member_keyword) {
            code_highlighter->remove_member_keyword_color(p_member_keyword.c_str());
        }
    };
}

#endif // CODE_HIGHLIGHTER_H