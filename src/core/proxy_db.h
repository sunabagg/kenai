#ifndef PROXY_DB_H
#define PROXY_DB_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>
#include <map>

#include "element.h"

namespace sunaba::core
{

    class ProxyDb
    {
    private:
        static std::map<Node*, Element*> elements;
    public:
        static void addElement(Node* node, Element* element) {
            elements[node] = element;
        }
 
        template <typename A, typename B>
        static A* getElement(B* node) {
            if (elements.find(node) != elements.end()) {
                return static_cast<A>(elements[node]);
            }
            return new A(node);
        }

        template <typename A, typename B>
        static A* cast(Element* e) {
            B* node = Object::cast_to<B>(e->getNode());
            return getElement<A, B>(node);
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