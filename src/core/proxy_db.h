#ifndef PROXY_DB_H
#define PROXY_DB_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>
#include <map>

#include "element.h"

namespace lucidware::core
{
    class ProxyDb
    {
    private:
        static std::map<Node*, Element*> elements;
    public:
        static void addElement(Node* node, Element* element) {
            elements[node] = element;
        }
 
        static Element* getElement(Node* node) {
            if (elements.find(node) != elements.end()) {
                return elements[node];
            }
            return nullptr;
        }
 
        static void removeElement(Node* node) {
            elements.erase(node);
        }
 
        static void clear() {
            elements.clear();
        }

    };
}

#endif // PROXY_DB_H